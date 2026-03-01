/*
 * Copyright (c) 2025, Yao Yuan <yeaya@163.com>. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  This file as subject to the
 * "Classpath" exception in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <java/lang/interpreter/ByteCodeInterpreter.h>

#include <java/lang/ClassCastException.h>
#include <java/lang/RuntimeException.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/lang/ArithmeticException.h>
#include <java/lang/NegativeArraySizeException.h>
#include <java/lang/StackTraceElement.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/util/ArrayList.h>
#include <jdk/internal/reflect/ConstantPool.h>
#include <jdk/internal/reflect/ConstantBase.h>
#include <jdk/internal/reflect/ConstantClass.h>
#include <jdk/internal/reflect/ConstantDouble.h>
#include <jdk/internal/reflect/ConstantDynamic.h>
#include <jdk/internal/reflect/ConstantFieldRef.h>
#include <jdk/internal/reflect/ConstantFloat.h>
#include <jdk/internal/reflect/ConstantInt.h>
#include <jdk/internal/reflect/ConstantInterfaceMethodRef.h>
#include <jdk/internal/reflect/ConstantInvokeDynamic.h>
#include <jdk/internal/reflect/ConstantLong.h>
#include <jdk/internal/reflect/ConstantMethodHandle.h>
#include <jdk/internal/reflect/ConstantMethodRef.h>
#include <jdk/internal/reflect/ConstantMethodType.h>
#include <jdk/internal/reflect/ConstantModule.h>
#include <jdk/internal/reflect/ConstantNameAndType.h>
#include <jdk/internal/reflect/ConstantPackage.h>
#include <jdk/internal/reflect/ConstantString.h>
#include <jdk/internal/reflect/ConstantUTF8.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/interpreter/opcodes.h>

#include <jcpp.h>
#include <cmath>

using namespace ::java::lang;
using _Array = ::java::lang::reflect::Array;
using namespace ::java::lang::reflect;
using namespace ::java::lang::invoke;
using namespace ::java::util;
using namespace ::jdk::internal::reflect;

namespace java {
	namespace lang {
		namespace interpreter {

int32_t calcCategory0(Class* type);

static inline int32_t addOverflow(int32_t a, int32_t b) {
	return (int32_t)((uint32_t)a + (uint32_t)b);
}

static inline int64_t addOverflow(int64_t a, int64_t b) {
	return (int64_t)((uint64_t)a + (uint64_t)b);
}

static inline int32_t subOverflow(int32_t a, int32_t b) {
	return (int32_t)((uint32_t)a - (uint32_t)b);
}

static inline int64_t subOverflow(int64_t a, int64_t b) {
	return (int64_t)((uint64_t)a - (uint64_t)b);
}

static inline int32_t mulOverflow(int32_t a, int32_t b) {
	return (int32_t)((uint32_t)a * (uint32_t)b);
}

static inline int64_t mulOverflow(int64_t a, int64_t b) {
	return (int64_t)((uint64_t)a * (uint64_t)b);
}

template<typename T>
static inline T divOverflow(T dividend, T divisor) {
	if (dividend == std::numeric_limits<T>::min() && divisor == -1) {
		return dividend;
	}
	// TODO test rounding
	return dividend / divisor;
}

template<typename F, typename I>
static inline I floatingToInteger(F f) {
	if (std::isnan(f)) {
		return 0;
	} else if (f > static_cast<F>(std::numeric_limits<I>::max())) {
		return std::numeric_limits<I>::max();
	} else if (f < static_cast<F>(std::numeric_limits<I>::min())) {
		return std::numeric_limits<I>::min();
	} else {
		return static_cast<I>(f);
	}
}

// Table 6.5.newarray-A. Array type codes
enum class ArrayPrimitiveTypes {
	T_BOOLEAN = 4,
	T_CHAR = 5,
	T_FLOAT = 6,
	T_DOUBLE = 7,
	T_BYTE = 8,
	T_SHORT = 9,
	T_INT = 10,
	T_LONG = 11,
};

ThreadLocal* ByteCodeInterpreter::currentInterpreters = nullptr;
Class* ByteCodeInterpreter::class$ = nullptr;
Class* ByteCodeInterpreter::load$(String* name, bool initialize) {
	static ClassInfo _ClassInfo_ = {
		$PUBLIC,
		"java.lang.interpreter.ByteCodeInterpreter",
		"java.lang.Object"
	};
	$loadClass(ByteCodeInterpreter, name, initialize, &_ClassInfo_, [](Class* clazz)->void {
		$assignStatic(currentInterpreters, $new(ThreadLocal));
	});
	return class$;
}

ByteCodeInterpreter::ByteCodeInterpreter() {
}

void ByteCodeInterpreter::init$(ByteCodeClass* clazz) {
	$set(this, memory, $new($longs, 128));
	$set(this, memoryObject, $new($ObjectArray, 128));
}

bool ByteCodeInterpreter::existsStackTraceElement() {
	if (currentInterpreters != nullptr) {
		ByteCodeInterpreter* iterpreter = (ByteCodeInterpreter*)currentInterpreters->get();
		return iterpreter != nullptr;
	}
	return false;
}

void ByteCodeInterpreter::initStackTraceElements($Array<StackTraceElement>* elements) {
	ByteCodeInterpreter* iterpreter = (ByteCodeInterpreter*)currentInterpreters->get();
	int32_t elementsIndex = 0;
	while (iterpreter != nullptr) {
		initStackTraceElements(iterpreter->frame, elements, elementsIndex);
		Frame* frame = iterpreter->frameStack;
		while (frame != nullptr) {
			initStackTraceElements(frame, elements, elementsIndex);
			frame = frame->next;
		}
		iterpreter = iterpreter->next;
		elementsIndex++;
	}
}

void ByteCodeInterpreter::initStackTraceElements(Frame* frame, $Array<StackTraceElement>* elements, int32_t& elementsIndex) {
	if (elementsIndex >= elements->length) {
		return;
	}
	if (frame->byteCodeMethod != nullptr) {
		ByteCodeClass* byteCodeClass = frame->byteCodeMethod->clazz;
		if (byteCodeClass->name != nullptr && frame->byteCodeMethod->name != nullptr) {
			$var(StackTraceElement, ste, $allocOrNull(StackTraceElement));
			if (ste != nullptr) {
				$set(ste, declaringClass, byteCodeClass->name);
				$set(ste, methodName, frame->byteCodeMethod->name);
				$var(ByteCodeClassData, bccd, byteCodeClass->getByteCodeClassData(false));
				if (bccd != nullptr && bccd->sourceFile != nullptr) {
					$set(ste, fileName, bccd->sourceFile);
					ste->lineNumber = frame->byteCodeMethod->findLineNumber(static_cast<uint16_t>(frame->pc));
				} else {
					$set(ste, fileName, ""_s);
					ste->lineNumber = -1;
				}
				$set(ste, declaringClassObject, byteCodeClass);
				elements->set(elementsIndex++, ste);
			}
		}
	}
}

//int iii = 0;
$Value ByteCodeInterpreter::interpret(ByteCodeMethod* byteCodeMethod, Object$* instance, Class* returnType,
		$ClassArray* parameterTypes, $Value* argv) {
	$set(this, frame, $new(Frame, this, byteCodeMethod, byteCodeMethod->stackSlotsForParameters));
	this->prepareArgs(instance, parameterTypes, argv);
	//iii++;
	//if (byteCodeMethod->clazz->name->equals("java.lang.invoke.LambdaForm$MH") && byteCodeMethod->name->equals("collector"_s)) {
	//	iii++;
	//}
	//int ii = iii;
	//if (ii == 78) {
	//	int i = 0;
	//	i++;
	//}
	ByteCodeInterpreter* last = (ByteCodeInterpreter*)currentInterpreters->get();
	if (last != nullptr) {
		$set(this, next, last);
	}
	currentInterpreters->set(this);
	try {
		while (!shouldExit) {
			if (currentException != nullptr) {
				handleThrow();
			} else {
				executeInstruction();
			}
		}
	} catch (Throwable& e) {
		currentInterpreters->set(last);
		$throw(e);
	}
	currentInterpreters->set(last);
	if (byteCodeMethod->returnCategory != 0 && returnType != nullptr) {
		return frame->getReturn(returnType);
	}
	return $of();
}

Object$* getParameter(Class* type, Frame* frame, int32_t localIndex);

inline uint8_t readUint8(ByteArray* code, int32_t pos) {
	uint8_t u1 = code->get(pos) & (uint8_t)255;
	return u1;
}

inline uint8_t consumeUint8(ByteArray* code, int32_t& pos) {
	uint8_t u1 = readUint8(code, pos);
	pos++;
	return u1;
}

inline uint16_t readUint16(ByteArray* code, int32_t pos) {
	uint8_t u0 = readUint8(code, pos);
	uint8_t u1 = readUint8(code, pos + 1);
	return static_cast<uint16_t>(u0 << 8) | u1;
}

inline uint16_t consumeUint16(ByteArray* code, int32_t& pos) {
	uint16_t u2 = readUint16(code, pos);
	pos += 2;
	return u2;
}

inline uint32_t readUint32(ByteArray* code, int32_t pos) {
	uint8_t u0 = readUint8(code, pos);
	uint8_t u1 = readUint8(code, pos + 1);
	uint8_t u2 = readUint8(code, pos + 2);
	uint8_t u3 = readUint8(code, pos + 3);
	return static_cast<uint32_t>(u0 << 24) | static_cast<uint32_t>(u1 << 16) | static_cast<uint32_t>(u2 << 8) | u3;
}

inline uint32_t consumeUint32(ByteArray* code, int32_t& pos) {
	uint32_t u4 = readUint32(code, pos);
	pos += 4;
	return u4;
}

inline void align4(int32_t& pos) {
	pos = (pos + 3) & -4ul;
}

inline void ByteCodeInterpreter::executeInstruction() {
	ByteArray* code = frame->byteCodeMethod->code;
	int32_t startPc = frame->pc;
	int32_t pos = startPc;
	try {
		uint8_t opcode = consumeUint8(code, pos);
		switch (static_cast<OpCodes>(opcode)) {
			case OpCodes::nop:
				break;
			case OpCodes::aconst_null:
				frame->pushObject(nullptr);
				break;
			case OpCodes::iconst_m1:
			case OpCodes::iconst_0:
			case OpCodes::iconst_1:
			case OpCodes::iconst_2:
			case OpCodes::iconst_3:
			case OpCodes::iconst_4:
			case OpCodes::iconst_5:
				frame->pushInt32(opcode - static_cast<uint8_t>(OpCodes::iconst_0));
				break;
			case OpCodes::lconst_0:
			case OpCodes::lconst_1:
				frame->pushInt64(opcode - static_cast<uint8_t>(OpCodes::lconst_0));
				break;
			case OpCodes::fconst_0:
			case OpCodes::fconst_1:
			case OpCodes::fconst_2:
				frame->pushFloat(static_cast<float>(opcode - static_cast<uint8_t>(OpCodes::fconst_0)));
				break;
			case OpCodes::dconst_0:
			case OpCodes::dconst_1:
				frame->pushDouble(static_cast<double>(opcode - static_cast<uint8_t>(OpCodes::dconst_0)));
				break;
			case OpCodes::bipush: {
				int8_t v = consumeUint8(code, pos);
				frame->pushInt8(static_cast<int32_t>(v));
				break;
			}
			case OpCodes::sipush: {
				int16_t value = consumeUint16(code, pos);
				frame->pushInt16(static_cast<int32_t>(value));
				break;
			}
			case OpCodes::ldc: {
				uint8_t index = consumeUint8(code, pos);
				ConstantPool* constantPool = frame->byteCodeMethod->clazz->getConstantPool();
				int8_t tag = constantPool->getTag(index);
				switch (tag) {
				case ConstantBase::Tag_Integer:
					frame->pushInt32(constantPool->getInt(index));
					break;
				case ConstantBase::Tag_Float:
					frame->pushFloat(constantPool->getFloat(index));
					break;
				case ConstantBase::Tag_Class: {
					ConstantClass* constantClass = constantPool->getClass(index);
					Class* clazz = loadClass($nc(constantClass)->utf8);
					frame->pushObject(clazz);
					break;
				}
				case ConstantBase::Tag_String: {
					ConstantString* str = constantPool->getString(index);
					frame->pushObject(str->utf8);
					break;
				}
				case ConstantBase::Tag_Dynamic: {
					// TODO
					ConstantDynamic* constantDynamic = constantPool->getDynamic(index);
					frame->pushObject(constantDynamic);
					break;
				}
				default:
					$throwNew(RuntimeException, "ldc refers to invalid/unimplemented type"_s);
					break;
				}
				break;
			}
			case OpCodes::ldc_w: {
				int32_t index = consumeUint16(code, pos);
				ConstantPool* constantPool = getConstantPool();
				int8_t tag = constantPool->getTag(index);
				switch (tag) {
				case ConstantBase::Tag_Integer:
					frame->pushInt32(constantPool->getInt(index));
					break;
				case ConstantBase::Tag_Float:
					frame->pushFloat(constantPool->getFloat(index));
					break;
				case ConstantBase::Tag_Class: {
					ConstantClass* constantClass = constantPool->getClass(index);
					Class* clazz = loadClass($nc(constantClass)->utf8);
					frame->pushObject(clazz);
					break;
				}
				case ConstantBase::Tag_String: {
					ConstantString* str = constantPool->getString(index);
					frame->pushObject($nc(str)->utf8);
					break;
				}
				default:
					$throwNew(RuntimeException, "ldc_w refers to invalid/unimplemented type"_s);
					break;
				}
				break;
			}
			case OpCodes::ldc2_w: {
				int32_t index = consumeUint16(code, pos);
				ConstantPool* constantPool = getConstantPool();
				int8_t tag = constantPool->getTag(index);
				if (tag == ConstantBase::Tag_Long) {
					frame->pushInt64(constantPool->getLong(index));
				} else if (tag == ConstantBase::Tag_Double) {
					frame->pushDouble(constantPool->getDouble(index));
				} else {
					$throwNew(RuntimeException, "ldc2_w refers to invalid/unimplemented type"_s);
					break;
				}
				break;
			}
			case OpCodes::iload:
				frame->pushInt32(frame->getLocalInt(consumeUint8(code, pos)));
				break;
			case OpCodes::lload:
				frame->pushInt64(frame->getLocalLong(consumeUint8(code, pos)));
				break;
			case OpCodes::fload:
				frame->pushFloat(frame->getLocalFloat(consumeUint8(code, pos)));
				break;
			case OpCodes::dload:
				frame->pushDouble(frame->getLocalDouble(consumeUint8(code, pos)));
				break;
			case OpCodes::aload: {
				$var(Object, obj, frame->getLocalPointer(consumeUint8(code, pos)));
				frame->pushObject(obj);
				break;
			}
			case OpCodes::iload_0:
			case OpCodes::iload_1:
			case OpCodes::iload_2:
			case OpCodes::iload_3:
				frame->pushInt32(frame->getLocalInt(opcode - static_cast<uint8_t>(OpCodes::iload_0)));
				break;
			case OpCodes::lload_0:
			case OpCodes::lload_1:
			case OpCodes::lload_2:
			case OpCodes::lload_3:
				frame->pushInt64(frame->getLocalLong(static_cast<uint8_t>(opcode - static_cast<uint8_t>(OpCodes::lload_0))));
				break;
			case OpCodes::fload_0:
			case OpCodes::fload_1:
			case OpCodes::fload_2:
			case OpCodes::fload_3:
				frame->pushFloat(frame->getLocalFloat(opcode - static_cast<uint8_t>(OpCodes::fload_0)));
				break;
			case OpCodes::dload_0:
			case OpCodes::dload_1:
			case OpCodes::dload_2:
			case OpCodes::dload_3:
				frame->pushDouble(frame->getLocalDouble(static_cast<uint8_t>(opcode - static_cast<uint8_t>(OpCodes::dload_0))));
				break;
			case OpCodes::aload_0:
			case OpCodes::aload_1:
			case OpCodes::aload_2:
			case OpCodes::aload_3: {
				$var(Object, obj, frame->getLocalPointer(opcode - static_cast<uint8_t>(OpCodes::aload_0)));
				frame->pushObject(obj);
				break;
			}
			case OpCodes::iaload:
				frame->arrayLoadInt();
				break;
			case OpCodes::laload:
				frame->arrayLoadLong();
				break;
			case OpCodes::faload:
				frame->arrayLoadFloat();
				break;
			case OpCodes::daload:
				frame->arrayLoadDouble();
				break;
			case OpCodes::aaload:
				frame->arrayLoadPointer();
				break;
			case OpCodes::baload:
				frame->arrayLoadByte();
				break;
			case OpCodes::caload:
				frame->arrayLoadChar();
				break;
			case OpCodes::saload:
				frame->arrayLoadShort();
				break;
			case OpCodes::istore: {
				int32_t value = frame->popInt32();
				frame->setLocalInt(consumeUint8(code, pos), value);
				break;
			}
			case OpCodes::lstore: {
				int64_t value = frame->popInt64();
				frame->setLocalLong(consumeUint8(code, pos), value);
				break;
			}
			case OpCodes::fstore: {
				float value = frame->popFloat();
				frame->setLocalFloat(consumeUint8(code, pos), value);
				break;
			}
			case OpCodes::dstore: {
				double value = frame->popDouble();
				frame->setLocalDouble(consumeUint8(code, pos), value);
				break;
			}
			case OpCodes::astore: {
				$var(Object, value, frame->popObject());
				frame->setLocalPointer(consumeUint8(code, pos), value);
				break;
			}
			case OpCodes::istore_0:
			case OpCodes::istore_1:
			case OpCodes::istore_2:
			case OpCodes::istore_3: {
				int32_t value = frame->popInt32();
				frame->setLocalInt(opcode - static_cast<uint8_t>(OpCodes::istore_0), value);
				break;
			}
			case OpCodes::lstore_0:
			case OpCodes::lstore_1:
			case OpCodes::lstore_2:
			case OpCodes::lstore_3: {
				int64_t value = frame->popInt64();
				frame->setLocalLong(opcode - static_cast<uint8_t>(OpCodes::lstore_0), value);
				break;
			}
			case OpCodes::fstore_0:
			case OpCodes::fstore_1:
			case OpCodes::fstore_2:
			case OpCodes::fstore_3: {
				float value = frame->popFloat();
				frame->setLocalFloat(opcode - static_cast<uint8_t>(OpCodes::fstore_0), value);
				break;
			}
			case OpCodes::dstore_0:
			case OpCodes::dstore_1:
			case OpCodes::dstore_2:
			case OpCodes::dstore_3: {
				double value = frame->popDouble();
				frame->setLocalDouble(opcode - static_cast<uint8_t>(OpCodes::dstore_0), value);
				break;
			}
			case OpCodes::astore_0:
			case OpCodes::astore_1:
			case OpCodes::astore_2:
			case OpCodes::astore_3: {
				$var(Object, value, frame->popObject());
				frame->setLocalPointer(opcode - static_cast<uint8_t>(OpCodes::astore_0), value);
				break;
			}
			case OpCodes::iastore:
				frame->arrayStoreInt();
				break;
			case OpCodes::lastore:
				frame->arrayStoreLong();
				break;
			case OpCodes::fastore:
				frame->arrayStoreFloat();
				break;
			case OpCodes::dastore:
				frame->arrayStoreDouble();
				break;
			case OpCodes::aastore:
				frame->arrayStorePointer();
				break;
			case OpCodes::bastore:
				frame->arrayStoreByte();
				break;
			case OpCodes::castore:
				frame->arrayStoreChar();
				break;
			case OpCodes::sastore:
				frame->arrayStoreShort();
				break;
			case OpCodes::pop: {
				frame->popInt32();
				break;
			}
			case OpCodes::pop2:
				frame->popInt64();
				break;
			case OpCodes::dup: {
				MemoryItem value = frame->pop();
				frame->push(value);
				frame->push(value);
				break;
			}
			case OpCodes::dup_x1: {
				MemoryItem value1 = frame->pop();
				MemoryItem value2 = frame->pop();
				frame->push(value1);
				frame->push(value2);
				frame->push(value1);
				break;
			}
			case OpCodes::dup_x2: {
				MemoryItem value1 = frame->pop();
				MemoryItem value2 = frame->pop();
				MemoryItem value3 = frame->pop();
				frame->push(value1);
				frame->push(value3);
				frame->push(value2);
				frame->push(value1);
				break;
			}
			case OpCodes::dup2: {
				MemoryItem value1 = frame->pop();
				MemoryItem value2 = frame->pop();
				frame->push(value2);
				frame->push(value1);
				frame->push(value2);
				frame->push(value1);
				break;
			}
			case OpCodes::dup2_x1: {
				MemoryItem value1 = frame->pop();
				MemoryItem value2 = frame->pop();
				MemoryItem value3 = frame->pop();
				frame->push(value2);
				frame->push(value1);
				frame->push(value3);
				frame->push(value2);
				frame->push(value1);
				break;
			}
			case OpCodes::dup2_x2: {
				MemoryItem value1 = frame->pop();
				MemoryItem value2 = frame->pop();
				MemoryItem value3 = frame->pop();
				MemoryItem value4 = frame->pop();
				frame->push(value2);
				frame->push(value1);
				frame->push(value4);
				frame->push(value3);
				frame->push(value2);
				frame->push(value1);
				break;
			}
			case OpCodes::swap: {
				MemoryItem value1 = frame->pop();
				MemoryItem value2 = frame->pop();
				frame->push(value1);
				frame->push(value2);
				break;
			}
			case OpCodes::iadd: {
				int32_t b = frame->popInt32();
				int32_t a = frame->popInt32();
				int32_t result = addOverflow(a, b);
				frame->pushInt32(result);
				break;
			}
			case OpCodes::ladd: {
				int64_t b = frame->popInt64();
				int64_t a = frame->popInt64();
				int64_t result = addOverflow(a, b);
				frame->pushInt64(result);
				break;
			}
			case OpCodes::fadd: {
				float b = frame->popFloat();
				float a = frame->popFloat();
				frame->pushFloat(a + b);
				break;
			}
			case OpCodes::dadd: {
				double b = frame->popDouble();
				double a = frame->popDouble();
				frame->pushDouble(a + b);
				break;
			}
			case OpCodes::isub: {
				int32_t b = frame->popInt32();
				int32_t a = frame->popInt32();
				int32_t result = subOverflow(a, b);
				frame->pushInt32(result);
				break;
			}
			case OpCodes::lsub: {
				int64_t b = frame->popInt64();
				int64_t a = frame->popInt64();
				frame->pushInt64(subOverflow(a, b));
				break;
			}
			case OpCodes::fsub: {
				float b = frame->popFloat();
				float a = frame->popFloat();
				frame->pushFloat(a - b);
				break;
			}
			case OpCodes::dsub: {
				double b = frame->popDouble();
				double a = frame->popDouble();
				frame->pushDouble(a - b);
				break;
			}
			case OpCodes::imul: {
				int32_t a = frame->popInt32();
				int32_t b = frame->popInt32();
				frame->pushInt32(mulOverflow(a, b));
				break;
			}
			case OpCodes::lmul: {
				int64_t a = frame->popInt64();
				int64_t b = frame->popInt64();
				frame->pushInt64(mulOverflow(a, b));
				break;
			}
			case OpCodes::fmul: {
				float a = frame->popFloat();
				float b = frame->popFloat();
				frame->pushFloat(a * b);
				break;
			}
			case OpCodes::dmul: {
				double a = frame->popDouble();
				double b = frame->popDouble();
				frame->pushDouble(a * b);
				break;
			}
			case OpCodes::idiv: {
				int32_t divisor = frame->popInt32();
				int32_t dividend = frame->popInt32();
				if (divisor == 0) {
					throwNewArithmeticExceptionDivisionByZero();
					break;
				}
				frame->pushInt32(divOverflow(dividend, divisor));
				break;
			}
			case OpCodes::ldiv: {
				int64_t divisor = frame->popInt64();
				int64_t dividend = frame->popInt64();
				if (divisor == 0) {
					throwNewArithmeticExceptionDivisionByZero();
					break;
				}
				frame->pushInt64(divOverflow(dividend, divisor));
				break;
			}
			case OpCodes::fdiv: {
				float divisor = frame->popFloat();
				float dividend = frame->popFloat();
				frame->pushFloat(dividend / divisor);
				break;
			}
			case OpCodes::ddiv: {
				double divisor = frame->popDouble();
				double dividend = frame->popDouble();
				frame->pushDouble(dividend / divisor);
				break;
			}
			case OpCodes::irem: {
				int32_t divisor = frame->popInt32();
				int32_t dividend = frame->popInt32();
				if (divisor == 0) {
					throwNewArithmeticExceptionDivisionByZero();
					break;
				}
				int32_t result = dividend - mulOverflow(divOverflow(dividend, divisor), divisor);
				frame->pushInt32(result);
				break;
			}
			case OpCodes::lrem: {
				int64_t divisor = frame->popInt64();
				int64_t dividend = frame->popInt64();
				if (divisor == 0) {
					throwNewArithmeticExceptionDivisionByZero();
					break;
				}
				int64_t result = dividend - mulOverflow(divOverflow(dividend, divisor), divisor);
				frame->pushInt64(result);
				break;
			}
			case OpCodes::frem: {
				float divisor = frame->popFloat();
				float dividend = frame->popFloat();
				float result = std::fmod(dividend, divisor);
				frame->pushFloat(result);
				break;
			}
			case OpCodes::drem: {
				double divisor = frame->popDouble();
				double dividend = frame->popDouble();
				double result = std::fmod(dividend, divisor);
				frame->pushDouble(result);
				break;
			}
			case OpCodes::ineg: {
				int32_t a = frame->popInt32();
				frame->pushInt32(subOverflow(static_cast<int32_t>(0), a));
				break;
			}
			case OpCodes::lneg: {
				int64_t a = frame->popInt64();
				frame->pushInt64(subOverflow(static_cast<int64_t>(0), a));
				break;
			}
			case OpCodes::fneg: {
				float a = frame->popFloat();
				frame->pushFloat(-a);
				break;
			}
			case OpCodes::dneg: {
				double a = frame->popDouble();
				frame->pushDouble(-a);
				break;
			}
			case OpCodes::ishl: {
				int32_t shift = frame->popInt32();
				int32_t value = frame->popInt32();
				int32_t result = $sl(value, shift);
				frame->pushInt32(result);
				break;
			}
			case OpCodes::lshl: {
				int32_t shift = frame->popInt32();
				int64_t value = frame->popInt64();
				int64_t result = $sl(value, shift);
				frame->pushInt64(result);
				break;
			}
			case OpCodes::ishr: {
				int32_t shift = frame->popInt32();
				int32_t value = frame->popInt32();
				int32_t result = $sr(value, shift);
				frame->pushInt32(result);
				break;
			}
			case OpCodes::lshr: {
				int32_t shift = frame->popInt32();
				int64_t value = frame->popInt64();
				int64_t result = $sr(value, shift);
				frame->pushInt64(result);
				break;
			}
			case OpCodes::iushr: {
				int32_t shift = frame->popInt32();
				int32_t value = frame->popInt32();
				int32_t result = $usr(value, shift);
				frame->pushInt32(result);
				break;
			}
			case OpCodes::lushr: {
				int32_t shift = frame->popInt32();
				int64_t value = frame->popInt64();
				int64_t result = $usr(value, shift);
				frame->pushInt64(result);
				break;
			}
			case OpCodes::iand:
				frame->pushInt32(frame->popInt32() & frame->popInt32());
				break;
			case OpCodes::land:
				frame->pushInt64(frame->popInt64() & frame->popInt64());
				break;
			case OpCodes::ior:
				frame->pushInt32(frame->popInt32() | frame->popInt32());
				break;
			case OpCodes::lor:
				frame->pushInt64(frame->popInt64() | frame->popInt64());
				break;
			case OpCodes::ixor:
				frame->pushInt32(frame->popInt32() ^ frame->popInt32());
				break;
			case OpCodes::lxor:
				frame->pushInt64(frame->popInt64() ^ frame->popInt64());
				break;
			case OpCodes::iinc: {
				int32_t local = consumeUint8(code, pos);
				int8_t value = consumeUint8(code, pos);
				int32_t result = addOverflow(frame->getLocalInt(local), value);
				frame->setLocalInt(local, result);
				break;
			}
			case OpCodes::i2l:
				frame->pushInt64(static_cast<int64_t>(frame->popInt32()));
				break;
			case OpCodes::i2f:
				frame->pushFloat(static_cast<float>(frame->popInt32()));
				break;
			case OpCodes::i2d:
				frame->pushDouble(static_cast<double>(frame->popInt32()));
				break;
			case OpCodes::l2i:
				frame->pushInt32(static_cast<int32_t>(frame->popInt64()));
				break;
			case OpCodes::l2f:
				frame->pushFloat(static_cast<float>(frame->popInt64()));
				break;
			case OpCodes::l2d:
				frame->pushDouble(static_cast<double>(frame->popInt64()));
				break;
			case OpCodes::f2i:
				frame->pushInt32(floatingToInteger<float, int32_t>(frame->popFloat()));
				break;
			case OpCodes::f2l:
				frame->pushInt64(floatingToInteger<float, int64_t>(frame->popFloat()));
				break;
			case OpCodes::f2d:
				frame->pushDouble(static_cast<double>(frame->popFloat()));
				break;
			case OpCodes::d2i:
				frame->pushInt32(floatingToInteger<double, int32_t>(frame->popDouble()));
				break;
			case OpCodes::d2l:
				frame->pushInt64(floatingToInteger<double, int64_t>(frame->popDouble()));
				break;
			case OpCodes::d2f:
				frame->pushFloat(static_cast<float>(frame->popDouble()));
				break;
			case OpCodes::i2b:
				frame->pushInt8(static_cast<int8_t>(frame->popInt32()));
				break;
			case OpCodes::i2c:
				frame->pushChar16(static_cast<char16_t>(frame->popInt32()));
				break;
			case OpCodes::i2s:
				frame->pushInt16(static_cast<int16_t>(frame->popInt32()));
				break;
			case OpCodes::lcmp: {
				int64_t b = frame->popInt64();
				int64_t a = frame->popInt64();
				if (a > b) {
					frame->pushInt32(1);
				} else if (a == b) {
					frame->pushInt32(0);
				} else {
					frame->pushInt32(-1);
				}
				break;
			}
			case OpCodes::fcmpl:
			case OpCodes::fcmpg: {
				// TODO "value set conversion" ?
				float b = frame->popFloat();
				float a = frame->popFloat();
				if (a > b) {
					frame->pushInt32(1);
				} else if (a == b) {
					frame->pushInt32(0);
				} else if (a < b) {
					frame->pushInt32(-1);
				} else {
					// at least one of a' or b' is NaN
					frame->pushInt32(static_cast<OpCodes>(opcode) == OpCodes::fcmpg ? -1 : 1);
				}
				break;
			}
			case OpCodes::dcmpl:
			case OpCodes::dcmpg: {
				// TODO "value set conversion" ?
				double b = frame->popDouble();
				double a = frame->popDouble();
				if (a > b) {
					frame->pushInt32(1);
				} else if (a == b) {
					frame->pushInt32(0);
				} else if (a < b) {
					frame->pushInt32(-1);
				} else {
					// at least one of a' or b' is NaN
					frame->pushInt32(static_cast<OpCodes>(opcode) == OpCodes::dcmpl ? -1 : 1);
				}
				break;
			}
			case OpCodes::ifeq:
				executeComparison(frame->popInt32() == 0, code, pos, startPc);
				return;
			case OpCodes::ifne:
				executeComparison(frame->popInt32() != 0, code, pos, startPc);
				return;
			case OpCodes::iflt:
				executeComparison(frame->popInt32() < 0, code, pos, startPc);
				return;
			case OpCodes::ifge:
				executeComparison(frame->popInt32() >= 0, code, pos, startPc);
				return;
			case OpCodes::ifgt:
				executeComparison(frame->popInt32() > 0, code, pos, startPc);
				return;
			case OpCodes::ifle:
				executeComparison(frame->popInt32() <= 0, code, pos, startPc);
				return;
			case OpCodes::if_icmpeq:
				executeComparison(frame->popInt32() == frame->popInt32(), code, pos, startPc);
				return;
			case OpCodes::if_icmpne:
				executeComparison(frame->popInt32() != frame->popInt32(), code, pos, startPc);
				return;
			case OpCodes::if_icmplt: {
				int32_t r = frame->popInt32();
				int32_t l = frame->popInt32();
				executeComparison(l < r, code, pos, startPc);
				return;
			}
			case OpCodes::if_icmpge: {
				int32_t r = frame->popInt32();
				int32_t l = frame->popInt32();
				executeComparison(l >= r, code, pos, startPc);
				return;
			}
			case OpCodes::if_icmpgt: {
				int32_t r = frame->popInt32();
				int32_t l = frame->popInt32();
				executeComparison(l > r, code, pos, startPc);
				return;
			}
			case OpCodes::if_icmple: {
				int32_t r = frame->popInt32();
				int32_t l = frame->popInt32();
				executeComparison(l <= r, code, pos, startPc);
				return;
			}
			case OpCodes::if_acmpeq:
				executeComparison($equals($ref(frame->popObject()), $ref(frame->popObject())), code, pos, startPc);
				return;
			case OpCodes::if_acmpne:
				executeComparison(!$equals($ref(frame->popObject()), $ref(frame->popObject())), code, pos, startPc);
				return;
			case OpCodes::goto_: {
				int16_t offset = readUint16(code, pos);
				frame->pc = startPc + offset;
				return;
			}
			case OpCodes::jsr: {
				$throwNew(RuntimeException, "jsr is unsupported"_s);
				break;
			}
			case OpCodes::ret: {
				$throwNew(RuntimeException, "ret is unsupported"_s);
				break;
			}
			case OpCodes::tableswitch: {
				// skip opcode + 0-3 bytes of padding
				align4(pos);
				int32_t default_ = consumeUint32(code, pos);
				int32_t low = consumeUint32(code, pos);
				int32_t high = consumeUint32(code, pos);
				int32_t index = frame->popInt32();
				int32_t offset;
				if (index < low || index > high) {
					offset = default_;
				} else {
					pos += 4 * static_cast<uint32_t>(index - low);
					offset = readUint32(code, pos);
				}
				pos = startPc + offset;
				break;
			}
			case OpCodes::lookupswitch: {
				// skip opcode + 0-3 bytes of padding
				align4(pos);
				int32_t default_ = consumeUint32(code, pos);
				int32_t npairs = consumeUint32(code, pos);
				int32_t key = frame->popInt32();
				int32_t offset = default_;
				for (int32_t i = 0; i < npairs; ++i) {
					int32_t match = consumeUint32(code, pos);
					if (key == match) {
						offset = consumeUint32(code, pos);
						break;
					}
					pos += 4;
				}
				pos = startPc + offset;
				break;
			}
			case OpCodes::ireturn:
				frame->setLocalInt(0, frame->popInt32());
				popFrame();
				return;
			case OpCodes::lreturn:
				frame->setLocalLong(0, frame->popInt64());
				popFrame();
				return;
			case OpCodes::freturn:
				frame->setLocalFloat(0, frame->popFloat());
				popFrame();
				return;
			case OpCodes::dreturn:
				frame->setLocalDouble(0, frame->popDouble());
				popFrame();
				return;
			case OpCodes::areturn:
				frame->setLocalPointer(0, $ref(frame->popObject()));
				popFrame();
				return;
			case OpCodes::return_: {
				popFrame();
				return;
			}
			case OpCodes::getstatic:
			case OpCodes::putstatic:
			case OpCodes::getfield:
			case OpCodes::putfield: {
				uint16_t index = consumeUint16(code, pos);
				$var(Field, field0, resolveField(index));
				switch (static_cast<OpCodes>(opcode)) {
					case OpCodes::getstatic: {
						getStatic(field0);
						break;
					}
					case OpCodes::putstatic: {
						putStatic(field0);
						break;
					}
					case OpCodes::getfield: {
						getField(field0);
						break;
					}
					case OpCodes::putfield: {
						putField(field0);
						break;
					}
					default:
						assert(false);
				}
				break;
			}
			case OpCodes::invokevirtual: {
				uint16_t methodIndex = readUint16(code, pos);
				frame->invokeLength = 3;
				$var(MethodCache, methodCache, getCurrentClass()->findMethodCache(methodIndex));
				if (methodCache->method->getClass() == Method::class$) {
					nativeCall(methodCache, false);
				} else {
					virtualCall(methodCache);
				}
				return;
			}
			case OpCodes::invokespecial: {
				uint16_t methodIndex = readUint16(code, pos);
				frame->invokeLength = 3;
				$var(MethodCache, methodCache, getCurrentClass()->findMethodCache(methodIndex));
				if (methodCache->method->getClass() == Method::class$) {
					nativeCall(methodCache, true);
				} else if (methodCache->method->getClass() == Constructor::class$) {
					nativeCall(methodCache, true);
				} else {
					ByteCodeMethod* method0 = $fcast<ByteCodeMethod>(methodCache->method);
					pushAndCreateFrame(method0);
				}
				return;
			}
			case OpCodes::invokestatic: {
				uint16_t methodIndex = readUint16(code, pos);
				frame->invokeLength = 3;
				$var(MethodCache, methodCache, getCurrentClass()->findMethodCache(methodIndex));
				if (methodCache->method->getClass() == Method::class$) {
					nativeCall(methodCache, false);
				} else {
					ByteCodeMethod* method0 = $fcast<ByteCodeMethod>(methodCache->method);
					pushAndCreateFrame(method0);
				}
				return;
			}
			case OpCodes::invokeinterface: {
				uint16_t methodIndex = readUint16(code, pos);
				frame->invokeLength = 5;
				$var(MethodCache, methodCache, getCurrentClass()->findMethodCache(methodIndex));
				if (methodCache->method->getClass() == Method::class$) {
					nativeCall(methodCache, false);
				} else {
					virtualCall(methodCache);
				}
				return;
			}
			case OpCodes::invokedynamic: {
				uint16_t methodIndex = readUint16(code, pos);
				frame->invokeLength = 5;
				invokeDynamic(methodIndex);
				return;
			}
			case OpCodes::new_: {
				uint16_t index = consumeUint16(code, pos);
				ConstantPool* constantPool = getConstantPool();
				ConstantClass* constantClass = constantPool->getClass(index);
				Class* clazz = loadClass($nc(constantClass)->utf8);
				$var(Object, instance, clazz->allocateInstance());
				frame->pushObject(instance);
				break;
			}
			case OpCodes::newarray: {
				int32_t count = frame->popInt32();
				if (count < 0) {
					$throwNew(NegativeArraySizeException, $$str(count));
					break;
				}
				int32_t type = consumeUint8(code, pos);
				switch (static_cast<ArrayPrimitiveTypes>(type)) {
					case ArrayPrimitiveTypes::T_INT: {
						$var(Object, obj, $new($ints, count));
						frame->pushObject(obj);
						break;
					}
					case ArrayPrimitiveTypes::T_BOOLEAN: {
						$var(Object, obj, $new($booleans, count));
						frame->pushObject(obj);
						break;
					}
					case ArrayPrimitiveTypes::T_CHAR: {
						$var(Object, obj, $new($chars, count));
						frame->pushObject(obj);
						break;
					}
					case ArrayPrimitiveTypes::T_FLOAT: {
						$var(Object, obj, $new($floats, count));
						frame->pushObject(obj);
						break;
					}
					case ArrayPrimitiveTypes::T_DOUBLE: {
						$var(Object, obj, $new($doubles, count));
						frame->pushObject(obj);
						break;
					}
					case ArrayPrimitiveTypes::T_BYTE: {
						$var(Object, obj, $new($bytes, count));
						frame->pushObject(obj);
						break;
					}
					case ArrayPrimitiveTypes::T_SHORT: {
						$var(Object, obj, $new($shorts, count));
						frame->pushObject(obj);
						break;
					}
					case ArrayPrimitiveTypes::T_LONG: {
						$var(Object, obj, $new($longs, count));
						frame->pushObject(obj);
						break;
					}
				}
				break;
			}
			case OpCodes::anewarray: {
				uint16_t index = consumeUint16(code, pos);
				ConstantPool* constantPool = getConstantPool();
				ConstantClass* constClass = constantPool->getClass(index);
				int32_t count = frame->popInt32();
				if (count < 0) {
					$throwNew(NegativeArraySizeException, $$str(count));
					break;
				}
				Class* clazz0 = loadClass(constClass->utf8);
				$var(Object, array, _Array::newArray(clazz0, count));
				frame->pushObject(array);
				break;
			}
			case OpCodes::arraylength: {
				$var(Object, array, frame->popObject());
				int32_t length = _Array::getLength(array);
				frame->pushInt32(length);
				break;
			}
			case OpCodes::athrow: {
				$var(Object, value, frame->popObject());
				throwIt($sure(Throwable, value));
				break;
			}
			case OpCodes::checkcast: {
				uint16_t index = consumeUint16(code, pos);
				ConstantPool* constantPool = getConstantPool();
				ConstantClass* constantClass = constantPool->getClass(index);
				Class* clazz = this->loadClass($nc(constantClass)->utf8);;
				$var(Object, objectref, frame->popObject());
				frame->pushObject(objectref);
				if (objectref != nullptr) {
					if (!clazz->isInstance(objectref)) {
						$throwNew(ClassCastException, constantClass->utf8);
						break;
					}
				}
				break;
			}
			case OpCodes::instanceof: {
				uint16_t index = consumeUint16(code, pos);
				ConstantPool* constantPool = getConstantPool();
				ConstantClass* constantClass = constantPool->getClass(index);
				Class* clazz = this->loadClass($nc(constantClass)->utf8);;
				$var(Object, obj, frame->popObject());
				if (obj == nullptr) {
					frame->pushBool(false);
				} else {
					bool ret = clazz->isInstance(obj);
					frame->pushBool(ret);
				}
				break;
			}
			case OpCodes::monitorenter: {
				$var(Object, obj, frame->popObject());
				$sureObject0(obj)->lock();
				break;
			}
			case OpCodes::monitorexit: {
				$var(Object, obj, frame->popObject());
				$sureObject0(obj)->unlock();
				break;
			}
			case OpCodes::wide: {
				uint8_t type = consumeUint8(code, pos);
				uint16_t index = consumeUint16(code, pos);
				switch (static_cast<OpCodes>(type)) {
				case OpCodes::iload:
					frame->pushInt32(frame->getLocalInt(index));
					break;
				case OpCodes::lload:
					frame->pushInt64(frame->getLocalLong(index));
					break;
				case OpCodes::fload:
					frame->pushFloat(frame->getLocalFloat(index));
					break;
				case OpCodes::dload:
					frame->pushDouble(frame->getLocalDouble(index));
					break;
				case OpCodes::aload: {
					$var(Object, local, frame->getLocalPointer(index));
					frame->pushObject(local);
					break;
				}
				case OpCodes::istore:
					frame->setLocalInt(index, frame->popInt32());
					break;
				case OpCodes::lstore:
					frame->setLocalLong(index, frame->popInt64());
					break;
				case OpCodes::fstore:
					frame->setLocalFloat(index, frame->popFloat());
					break;
				case OpCodes::dstore:
					frame->setLocalDouble(index, frame->popDouble());
					break;
				case OpCodes::astore: {
					$var(Object, local, frame->popObject());
					frame->setLocalPointer(index, local);
					break;
				}
				case OpCodes::iinc: {
					int32_t local = frame->getLocalInt(index);
					int16_t constant = consumeUint16(code, pos);
					frame->setLocalInt(index, local + constant);
					break;
				}
				case OpCodes::ret:
					$throwNew(RuntimeException, "wide_ret is unsupported"_s);
				default:
					$throwNew(RuntimeException, $$str({ "wide type:"_s, $$str(type), " is unsupported"_s }));
				}
				break;
			}
			case OpCodes::multianewarray: {
				uint16_t index = consumeUint16(code, pos);
				ConstantPool* constantPool = getConstantPool();
				ConstantClass* constantClass = constantPool->getClass(index);
				Class* componentType = this->loadClass($nc(constantClass)->utf8);
				uint8_t dimensions = consumeUint8(code, pos);
				assert(dimensions >= 1);
				$var($ints, dims, $new($ints, dimensions));
				for (int32_t i = 0; i < dimensions; i++) {
					int32_t count = frame->popInt32();
					dims->set(i, count);
				}
				frame->pushObject($(_Array::multiNewArray(componentType, dims)));
				break;
			}
			case OpCodes::ifnull:
				executeComparison(frame->popObject() == nullptr, code, pos, startPc);
				return;
			case OpCodes::ifnonnull:
				executeComparison(frame->popObject() != nullptr, code, pos, startPc);
				return;
			case OpCodes::goto_w: {
				int32_t offset = consumeUint32(code, pos);
				pos = startPc + offset;
				break;
			}
			case OpCodes::jsr_w:
				$throwNew(RuntimeException, "jsr_w is unsupported"_s);
				return;
			default:
				$throwNew(RuntimeException, $ref(String::valueOf({ "Unimplemented/unknown opcode "_s, $$str(opcode), " at "_s, $$str(frame->pc) })));
				return;
		}
	} catch(Throwable& e) {
		$set(this, currentException, e);
		return;
	}
	if (currentException == nullptr) {
		frame->pc = pos;
	}
}

void ByteCodeInterpreter::executeComparison(bool condition, ByteArray* code, int32_t pos, int32_t startPc) {
	if (condition) {
		int16_t offset = readUint16(code, pos);
		frame->pc = startPc + offset;
	} else {
		frame->pc = startPc + 3;
	}
}

void ByteCodeInterpreter::handleThrow() {
	while (true) {
		std::vector<ExceptionTableEntry>& exceptionTable = frame->byteCodeMethod->exceptionTable;
		int32_t index = 0;
		bool matched = false;
		for (; index < exceptionTable.size(); index++) {
			ExceptionTableEntry& e = exceptionTable[index];
			if (e.startPc <= frame->pc && frame->pc < e.endPc) {
				if (e.catchType == 0) {
					matched = true;
					break;
				} else {
					ConstantPool* constantPool = getConstantPool();
					ConstantClass* constantClass = constantPool->getClass(e.catchType);
					$var(String, className, $nc(constantClass)->utf8->replace('/', '.'));
					Class* c = currentException->getClass();
					while (c != nullptr) {
						if (className->equals(c->getName())) {
							matched = true;
							break;
						}
						c = c->getSuperclass();
					}
					if (matched) {
						break;
					}
				}
			}
			if (matched) {
				break;
			}
		}
		if (!matched) {
			popFrame();
			$throw(this->currentException);
		} else {
			frame->clear();
			frame->pushObject(currentException);
			frame->pc = exceptionTable[index].handlerPc;
			$set(this, currentException, nullptr);
			return;
		}
	}
}

void ByteCodeInterpreter::popFrame() {
	if (frameStack != nullptr) {
		$set(this, frame, frameStack);
		$set(this, frameStack, frameStack->next);
		if (currentException == nullptr) {
			frame->pc += frame->invokeLength;
		}
	} else {
		shouldExit = true;
	}
}

Class* Frame::class$ = nullptr;
Class* Frame::load$(String* name, bool initialize) {
	static ClassInfo _ClassInfo_ = {
		$PUBLIC,
		"java.lang.interpreter.Frame",
		"java.lang.Object"
	};
	$loadClass(Frame, name, initialize, &_ClassInfo_);
	return class$;
}

Frame::Frame() {
}

void Frame::init$(ByteCodeInterpreter* interpreter, ByteCodeMethod* byteCodeMethod, int32_t operandStackTop) {
	Object::init$();
	this->interpreter = interpreter;
	this->byteCodeMethod = byteCodeMethod;
	this->operandsTop = 0;
	this->pc = 0;
	this->invokeLength = 0;
	firstLocalIndex = operandStackTop - byteCodeMethod->stackSlotsForParameters;

	if (byteCodeMethod->code != nullptr && byteCodeMethod->code->length > 0) {
		firstOperandIndex = firstLocalIndex + byteCodeMethod->maxLocals;
	} else {
		firstOperandIndex = operandStackTop;
	}
}

void Frame::init$(ByteCodeInterpreter* interpreter, int32_t operandStackTop, int32_t stackSlotsForParameters) {
	Object::init$();
	this->interpreter = interpreter;
	this->byteCodeMethod = nullptr;
	this->operandsTop = 0;
	this->pc = 0;
	this->invokeLength = 0;
	this->stackSlotsForParameters = stackSlotsForParameters;
	firstLocalIndex = operandStackTop - stackSlotsForParameters;
	firstOperandIndex = operandStackTop;
}

inline MemoryItem Frame::getLocal(int32_t index) {
	int32_t index0 = firstLocalIndex + index;
	MemoryItem mi = interpreter->getMemoryItem(index0);
	return mi;
}

void Frame::setLocal(int32_t index, Class* type, Object* value) {
	if (type->isPrimitive()) {
		Class* valueClazz = $nc(value)->getClass();
		if (valueClazz == Boolean::class$) {
			setLocalInt(index, $cast<Boolean>(value)->booleanValue());
		} else if (valueClazz == Byte::class$) {
			setLocalInt(index, $cast<Byte>(value)->byteValue());
		} else if (valueClazz == Short::class$) {
			setLocalInt(index, $cast<Short>(value)->shortValue());
		} else if (valueClazz == Integer::class$) {
			setLocalInt(index, $cast<Integer>(value)->intValue());
		} else if (valueClazz == Long::class$) {
			setLocalLong(index, $cast<Long>(value)->longValue());
		} else if (valueClazz == Float::class$) {
			setLocalFloat(index, $cast<Float>(value)->floatValue());
		} else if (valueClazz == Double::class$) {
			setLocalDouble(index, $cast<Double>(value)->doubleValue());
		} else if (valueClazz == Character::class$) {
			setLocalInt(index, $cast<Character>(value)->charValue());
		} else {
			$shouldNotReachHere();
		}
	} else {
		setLocalPointer(index, value);
	}
}

inline Object$* Frame::getLocal(int32_t index, Class* type) {
	if (type->isPrimitive()) {
		if (type == Boolean::TYPE) {
			return Byte::valueOf((int8_t)getLocalInt(index));
		}
		if (type == Byte::TYPE) {
			return Byte::valueOf((int8_t)getLocalInt(index));
		}
		if (type == Short::TYPE) {
			return Short::valueOf((int16_t)getLocalInt(index));
		}
		if (type == Integer::TYPE) {
			return Integer::valueOf((int32_t)getLocalInt(index));
		}
		if (type == Long::TYPE) {
			return Long::valueOf((int64_t)getLocalLong(index));
		}
		if (type == Float::TYPE) {
			return Float::valueOf(getLocalFloat(index));
		}
		if (type == Double::TYPE) {
			return Double::valueOf(getLocalDouble(index));
		}
		if (type == Character::TYPE) {
			return Character::valueOf(getLocalInt(index));
		}
		$shouldNotReachHere();
	} else {
		return type->cast(getLocalPointer(index));
	}
}

inline MemoryItem Frame::markMemoryItem(int32_t value, MemoryItemType type) {
	MemoryItem mv = value;
	mv = (mv << 32) | type | PRIMITIVE_TYPE_PADDING;
	return mv;
}

inline MemoryItemType Frame::getMemoryItemType(MemoryItem item) {
	if ((item & PRIMITIVE_TYPE_PADDING) == PRIMITIVE_TYPE_PADDING) {
		return (MemoryItemType)(item & PRIMITIVE_TYPE_MASK);
	} else {
		return OBJECT_TYPE;
	}
}

inline int32_t Frame::getMemoryItemValue(MemoryItem item) {
	return (int32_t)((item >> 32) & (uint32_t)0xFFFFFFFF);
}

inline Object* Frame::getObjectFromMemoryItem(MemoryItem item) {
	return (Object*)item;
}

inline MemoryItem Frame::markObjectMemoryItem(Object$* value) {
	return (MemoryItem)value;
}

inline int32_t Frame::getLocalInt(int32_t index) {
	int32_t index0 = firstLocalIndex + index;
	MemoryItem mi = interpreter->getMemoryItem(index0);
	return getMemoryItemValue(mi);
}

inline void Frame::setLocalInt(int32_t index, int32_t value) {
	int32_t index0 = firstLocalIndex + index;
	MemoryItem mi = markMemoryItem(value, INT_TYPE);
	interpreter->setMemoryItem(index0, mi);	
}

inline int64_t Frame::getLocalLong(int32_t index) {
	int32_t high32 = getLocalInt(index);
	int32_t low32 = getLocalInt(index + 1);
	int64_t ret = high32;
	ret = (ret << 32);
	ret = ret | (low32 & (uint32_t)0xFFFFFFFF);
	return ret;
}

inline void Frame::setLocalLong(int32_t index, int64_t value) {
	uint64_t u64 = value;
	int32_t low32 = (int32_t)(u64 & (uint32_t)0xFFFFFFFF);
	int32_t high32 = (int32_t)((u64 >> 32) & (uint32_t)0xFFFFFFFF);
	int32_t index0 = firstLocalIndex + index;
	MemoryItem mi0 = markMemoryItem(high32, LONG_TYPE);
	MemoryItem mi1 = markMemoryItem(low32, INT_TYPE);
	interpreter->setMemoryItem(index0, mi0, mi1);
}

inline float Frame::getLocalFloat(int32_t index) {
	int32_t value = getLocalInt(index);
	float result = Float::intBitsToFloat(value);
	return result;
}

inline void Frame::setLocalFloat(int32_t index, float value) {
	int32_t index0 = firstLocalIndex + index;
	int32_t result = Float::floatToRawIntBits(value);
	MemoryItem mi = markMemoryItem(result, FLOAT_TYPE);
	interpreter->setMemoryItem(index0, mi);
}

inline double Frame::getLocalDouble(int32_t index) {
	int64_t value = getLocalLong(index);
	double result = Double::longBitsToDouble(value);
	return result;
}

inline void Frame::setLocalDouble(int32_t index, double value) {
	uint64_t u64 = Double::doubleToRawLongBits(value);
	int32_t low32 = (int32_t)(u64 & (uint32_t)0xFFFFFFFF);
	int32_t high32 = (int32_t)((u64 >> 32) & (uint32_t)0xFFFFFFFF);
	int32_t index0 = firstLocalIndex + index;
	MemoryItem mi0 = markMemoryItem(high32, DOUBLE_TYPE);
	MemoryItem mi1 = markMemoryItem(low32, INT_TYPE);
	interpreter->setMemoryItem(index0, mi0, mi1);
}

inline Object* Frame::getLocalPointer(int32_t index) {
	int32_t index0 = firstLocalIndex + index;
	MemoryItem mi = interpreter->getMemoryItem(index0);
	return getObjectFromMemoryItem(mi);
}

inline void Frame::setLocalPointer(int32_t index, Object$* value) {
	int32_t index0 = firstLocalIndex + index;
	MemoryItem mi = markObjectMemoryItem(value);
	interpreter->setMemoryItem(index0, mi);
	interpreter->saveMemoryObject(index0, value);
}

inline MemoryItem Frame::pop() {
	int32_t index0 = firstOperandIndex + (--operandsTop);
	MemoryItem mi = interpreter->getMemoryItem(index0);
	MemoryItemType oldType = getMemoryItemType(mi);
	if (oldType == MemoryItemType::OBJECT_TYPE) {
		$var(Object, saved, getObjectFromMemoryItem(mi));
		interpreter->clearMemoryObject(index0);
	}
	return mi;
}

inline void Frame::push(MemoryItem item) {
	int32_t index0 = firstOperandIndex + operandsTop;
	interpreter->setMemoryItem(index0, item);
	MemoryItemType type = getMemoryItemType(item);
	if (type == MemoryItemType::OBJECT_TYPE) {
		interpreter->saveMemoryObject(index0, getObjectFromMemoryItem(item));
	}
	operandsTop++;
}

inline int64_t Frame::popInt64() {
	int32_t low32 = popInt32();
	int64_t high32 = popInt32();
	int64_t i64 = (high32 << 32) | (low32 & (uint32_t)0xFFFFFFFF);
	return i64;
}

inline void Frame::pushObject(Object$* operand) {
	int32_t index0 = firstOperandIndex + operandsTop;
	MemoryItem mi = markObjectMemoryItem(operand);
	interpreter->setMemoryItem(index0, mi);
	interpreter->saveMemoryObject(index0, operand);
	operandsTop++;
}

inline void Frame::push(int32_t value, MemoryItemType type) {
	int32_t index0 = firstOperandIndex + operandsTop;
	MemoryItem mi = markMemoryItem(value, type);
	interpreter->setMemoryItem(index0, mi);
	operandsTop++;
}

inline void Frame::pushBool(bool value) {
	push(value, BOOL_TYPE);
}

inline void Frame::pushInt8(int8_t value) {
	push(value, BYTE_TYPE);
}

inline void Frame::pushInt16(int16_t value) {
	push(value, SHORT_TYPE);
}

void Frame::pushInt32(int32_t value) {
	push(value, INT_TYPE);
}

inline void Frame::pushChar16(char16_t value) {
	push(value, CHAR_TYPE);
}

inline void Frame::pushFloat(float value) {
	int32_t result = Float::floatToRawIntBits(value);
	push(result, FLOAT_TYPE);
}

inline int32_t Frame::popInt32() {
	int32_t index0 = firstOperandIndex + (--operandsTop);
	MemoryItem mi = interpreter->getMemoryItem(index0);
	return getMemoryItemValue(mi);
}

inline bool Frame::popBool() {
	return popInt32() != 0;
}

inline int8_t Frame::popInt8() {
	return static_cast<int8_t>(popInt32());
}

inline int16_t Frame::popInt16() {
	return static_cast<int16_t>(popInt32());
}

inline char16_t Frame::popChar16() {
	return static_cast<char16_t>(popInt32());
}

inline float Frame::popFloat() {
	int32_t s4 = popInt32();
	float result = Float::intBitsToFloat(s4);
	return result;
}

inline Object* Frame::popObject() {
	int32_t index0 = firstOperandIndex + (--operandsTop);
	MemoryItem mi = interpreter->getMemoryItem(index0);
	$var(Object, obj, getObjectFromMemoryItem(mi));
	interpreter->clearMemoryObject(index0);
	return obj;
}

inline void Frame::pushInt64(int64_t value) {
	uint64_t u64 = value;
	int32_t low32 = (int32_t)(u64 & (uint32_t)0xFFFFFFFF);
	int32_t high32 = (int32_t)((u64 >> 32) & (uint32_t)0xFFFFFFFF);
	push(high32, LONG_TYPE);
	push(low32, LONG_TYPE);
}

inline void Frame::pushDouble(double value) {
	uint64_t u64 = Double::doubleToRawLongBits(value);
	int32_t low32 = (int32_t)(u64 & (uint32_t)0xFFFFFFFF);
	int32_t high32 = (int32_t)((u64 >> 32) & (uint32_t)0xFFFFFFFF);
	push(high32, DOUBLE_TYPE);
	push(low32, DOUBLE_TYPE);
}

inline double Frame::popDouble() {
	int64_t value = popInt64();
	double result = Double::longBitsToDouble(value);
	return result;
}

inline void Frame::arrayStoreByte() {
	int8_t value = popInt8();
	int32_t index = popInt32();
	$var(ByteArray, array, (ByteArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	array->set(index, value);
}

inline void Frame::arrayStoreShort() {
	int16_t value = popInt16();
	int32_t index = popInt32();
	$var(ShortArray, array, (ShortArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	array->set(index, value);
}

inline void Frame::arrayStoreInt() {
	int32_t value = popInt32();
	int32_t index = popInt32();
	$var(IntArray, array, (IntArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	array->set(index, value);
}

inline void Frame::arrayStoreLong() {
	int64_t value = popInt64();
	int32_t index = popInt32();
	$var(LongArray, array, (LongArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	array->set(index, value);
}

inline void Frame::arrayStoreFloat() {
	float value = popFloat();
	int32_t index = popInt32();
	$var(FloatArray, array, (FloatArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	array->set(index, value);
}

inline void Frame::arrayStoreDouble() {
	double value = popDouble();
	int32_t index = popInt32();
	$var(DoubleArray, array, (DoubleArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	array->set(index, value);
}

inline void Frame::arrayStoreChar() {
	char16_t value = popChar16();
	int32_t index = popInt32();
	$var(CharArray, array, (CharArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	array->set(index, value);
}

inline void Frame::arrayStorePointer() {
	$var(Object, value, popObject());
	int32_t index = popInt32();
	$var($ObjectArray, array, ($ObjectArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	array->set(index, value);
}

inline void Frame::arrayLoadByte() {
	int32_t index = popInt32();
	$var(ByteArray, array, (ByteArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	pushInt8(array->get(index));
}

inline void Frame::arrayLoadShort() {
	int32_t index = popInt32();
	$var(ShortArray, array, (ShortArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	pushInt16(array->get(index));
}

inline void Frame::arrayLoadInt() {
	int32_t index = popInt32();
	$var(IntArray, array, (IntArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	pushInt32(array->get(index));
}

inline void Frame::arrayLoadLong() {
	int32_t index = popInt32();
	$var(LongArray, array, (LongArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	pushInt64(array->get(index));
}

inline void Frame::arrayLoadFloat() {
	int32_t index = popInt32();
	$var(FloatArray, array, (FloatArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	pushFloat(array->get(index));
}

inline void Frame::arrayLoadDouble() {
	int32_t index = popInt32();
	$var(DoubleArray, array, (DoubleArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	pushDouble(array->get(index));
}

inline void Frame::arrayLoadChar() {
	int32_t index = popInt32();
	$var(CharArray, array, (CharArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	pushChar16(array->get(index));
}

inline void Frame::arrayLoadPointer() {
	int32_t index = popInt32();
	$var($ObjectArray, array, ($ObjectArray*)popObject());
	if (array == nullptr) {
		interpreter->throwIt($$new(NullPointerException));
		return;
	}
	if (index < 0 || index >= array->length) {
		interpreter->throwIt($$new(ArrayIndexOutOfBoundsException));
		return;
	}
	pushObject(array->get(index));
}

Object$* getParameter(Class* type, Frame* frame, int32_t localIndex) {
	if (type->isArray()) {
		return frame->getLocalPointer(localIndex);
	}
	MemoryItem item = frame->getLocal(localIndex);
	MemoryItemType localType = Frame::getMemoryItemType(item);
	if (type->isPrimitive()) {
		if (type == Boolean::TYPE) {
			return Boolean::valueOf(frame->getLocalInt(localIndex) != 0);
		}
		if (type == Byte::TYPE) {
			return Byte::valueOf((int8_t)frame->getLocalInt(localIndex));
		}
		if (type == Short::TYPE) {
			return Short::valueOf((int16_t)frame->getLocalInt(localIndex));
		}
		if (type == Integer::TYPE) {
			return Integer::valueOf((int32_t)frame->getLocalInt(localIndex));
		}
		if (type == Long::TYPE) {
			return Long::valueOf((int64_t)frame->getLocalLong(localIndex));
		}
		if (type == Float::TYPE) {
			return Float::valueOf(frame->getLocalFloat(localIndex));
		}
		if (type == Double::TYPE) {
			return Double::valueOf(frame->getLocalDouble(localIndex));
		}
		if (type == Character::TYPE) {
			return Character::valueOf(frame->getLocalInt(localIndex));
		}
		$shouldNotReachHere();
	} else {
		if (localType == OBJECT_TYPE) {
			return frame->getLocalPointer(localIndex);
		}
		switch (localType) {
		case BOOL_TYPE:
			return Boolean::valueOf(frame->getLocalInt(localIndex) != 0);
		case BYTE_TYPE:
			return Byte::valueOf((int8_t)frame->getLocalInt(localIndex));
		case SHORT_TYPE:
			return Short::valueOf((int16_t)frame->getLocalInt(localIndex));
		case INT_TYPE:
			return Integer::valueOf((int32_t)frame->getLocalInt(localIndex));
		case LONG_TYPE:
			return Long::valueOf((int64_t)frame->getLocalLong(localIndex));
		case FLOAT_TYPE:
			return Float::valueOf(frame->getLocalFloat(localIndex));
		case DOUBLE_TYPE:
			return Double::valueOf(frame->getLocalDouble(localIndex));
		case CHAR_TYPE:
			return Character::valueOf(frame->getLocalInt(localIndex));
		//case OBJECT_TYPE:
		//	break;
		default:
			break;
		}
	}
	$throwNew(IllegalArgumentException);
}

Class* ByteCodeInterpreter::loadClass(String* name) {
	//return getCurrentClass()->loadClass(name);
	$var(String, name0, name->replace('/', '.'));
	if (frame->byteCodeMethod != nullptr) {
		ByteCodeClass* currentClass = frame->byteCodeMethod->clazz;
		if (name0->equals($(currentClass->getName()))) {
			return currentClass;
		}
		return currentClass->loadClass(name0);
	} else {
		return Class::forName(name0);
	}
}

Field* ByteCodeInterpreter::resolveField(int16_t constIndex) {
	ConstantPool* constantPool = getConstantPool();
	$var(ConstantFieldRef, fieldRef, constantPool->getFieldRef(constIndex));
	Class* clazz = this->loadClass($nc(fieldRef)->clazz);
	return clazz->refField(fieldRef->name);
}

$ObjectArray* ByteCodeInterpreter::makeArgs(bool isVarArgs, int32_t localIndex, int32_t slots, $ClassArray* parameterTypes) {
	$var($ObjectArray, args, nullptr);
	if (isVarArgs) {
		$var(ArrayList, arrayList, $new(ArrayList));
		Class* varType = parameterTypes->get(parameterTypes->length - 1);
		$var(Object, arg, nullptr);
		for (int32_t i = 0; i < parameterTypes->length - 1; i++) {
			Class* type = parameterTypes->get(i);
			$assign(arg, getParameter(type, frame, localIndex));
			arrayList->add(arg);
			int32_t category = calcCategory0(type);
			slots += category;
			localIndex += category;
		}

		if (slots == frame->stackSlotsForParameters) {
			$assign(args, arrayList->toArray());
		} else if (slots < this->frame->stackSlotsForParameters) {
			Class* type = parameterTypes->get(parameterTypes->length - 1);
			type = type->getComponentType();
			$var(Object, arg, getParameter(Object::class$, frame, localIndex));
			int32_t category = 1; // calcCategory0(Object::class$);
			slots += category;
			localIndex += category;
			if (slots == frame->stackSlotsForParameters && arg->getClass() == varType) {
				arrayList->add(arg);
				$assign(args, arrayList->toArray());
			} else {
				$var(ArrayList, arrayList2, $new(ArrayList));
				arrayList2->add(arg);
				while (slots < frame->stackSlotsForParameters) {
					$var(Object, arg, getParameter(type, frame, localIndex));
					arrayList2->add(arg);
					category = calcCategory0(type);
					slots += category;
					localIndex += category;
				}
				arrayList->add($ref(arrayList2->toArray()));
				$assign(args, arrayList->toArray());
			}
		}
	} else {
		$assign(args, $new($ObjectArray, parameterTypes->length));
		for (int32_t i = 0; i < parameterTypes->length; i++) {
			Class* type = parameterTypes->get(i);
			$var(Object, arg, getParameter(type, frame, localIndex));
			args->set(i, arg);
			int32_t category = calcCategory0(type);
			localIndex += category;
		}
	}
	return args;
}

void ByteCodeInterpreter::nativeCall(MethodCache* methodCache, bool special) {
	ByteCodeClass* clazz = getCurrentClass();
	WillCallCallerSensitive wccs(clazz);
	pushAndCreateFrame4Native(methodCache->stackSlotsForArgs, methodCache->realReturnCategory);
	try {
		$var(Object, this_obj, nullptr);
		int32_t localIndex = 0;
		if (methodCache->hasThisArg()) {
			$assign(this_obj, frame->getLocalPointer(localIndex));
			localIndex++;
		}
		$var($ObjectArray, args, $new($ObjectArray, methodCache->argsTypes->length));
		for (int32_t i = 0; i < methodCache->argsTypes->length; i++) {
			Class* type = methodCache->argsTypes->get(i);
			$var(Object, arg, getParameter(type, frame, localIndex));
			args->set(i, arg);
			int32_t category = calcCategory0(type);
			localIndex += category;
		}
		if (methodCache->method->getClass() == Method::class$) {
			$var(Object, returnValue, nullptr);
			Method* method = $fcast<Method>(methodCache->method);
			if (special) {
				$assign(returnValue, method->invokeSpecial(this_obj, args));
			} else {
				$assign(returnValue, method->invoke(this_obj, args));
			}
			if (methodCache->realReturnType != Void::TYPE) {
				frame->setReturn(methodCache->realReturnType, returnValue); // TODO
			}
		} else {
			Constructor* constructor = $fcast<Constructor>(methodCache->method);
			constructor->initInstance(this_obj, args);
			frame->setLocalPointer(0, this_obj);
		}
	} catch (InvocationTargetException& ite) {
		$set(this, currentException, ite->target);
	} catch (Throwable& e) {
		$set(this, currentException, e);
	}
	popFrame();
}

void ByteCodeInterpreter::virtualCall(MethodCache* methodCache) {
	ByteCodeMethod* method = $fcast<ByteCodeMethod>(methodCache->method);

	int32_t stackSlotsForParameters = 0;
	if ((method->accessFlags & Modifier::VARARGS) != 0) {
		stackSlotsForParameters = frame->operandsTop;
	} else {
		stackSlotsForParameters = method->stackSlotsForParameters;
	}
	int32_t localIndex = frame->firstOperandIndex + frame->operandsTop - stackSlotsForParameters - frame->firstLocalIndex;
	$var(Object, this_obj, frame->getLocalPointer(localIndex));
	Class* clazz = $toObject0(this_obj)->getClass();
	if (method->clazz != clazz) {
		ByteCodeMethod* bcMethod = nullptr;
		if (clazz->byteCodeClass) {
			ByteCodeClass* byteCodeClass = (ByteCodeClass*)clazz;
			bcMethod = byteCodeClass->findByteCodeMethod(method->name, method->descriptor);
		}
		if (bcMethod != nullptr) {
			pushAndCreateFrame(bcMethod);
		} else {
			pushAndCreateFrame4Native(methodCache->stackSlotsForArgs, methodCache->realReturnCategory);
			try {
				$var(Method, m, clazz->getMethodEx(method->name, method->descriptor));
				$var($ObjectArray, args, $new($ObjectArray, methodCache->argsTypes->length));
				localIndex = 1;
				for (int32_t i = 0; i < methodCache->argsTypes->length; i++) {
					Class* type = methodCache->argsTypes->get(i);
					$var(Object, arg, getParameter(type, frame, localIndex));
					args->set(i, arg);
					int32_t category = calcCategory0(type);
					localIndex += category;
				}
				$var(Object, returnValue, nullptr);
				$assign(returnValue, m->invoke(this_obj, args));
				if (methodCache->realReturnType != Void::TYPE) {
					frame->setReturn(methodCache->realReturnType, returnValue); // TODO
				}
			} catch (InvocationTargetException& ite) {
				$set(this, currentException, ite->target);
			} catch(Throwable& e) {
				$set(this, currentException, e);
			}
			popFrame();
		}
	} else {
		pushAndCreateFrame(method);
	}
}

void ByteCodeInterpreter::invokeDynamic(uint16_t methodIndex) {
	ByteCodeClass* clazz = getCurrentClass();
	WillCallCallerSensitive wccs(clazz);
	$var(ConstantPool, constantPool, clazz->getConstantPool());
	ConstantBase* base = constantPool->getBase(methodIndex);
	ConstantInvokeDynamic* constantInvokeDynamic = (ConstantInvokeDynamic*)$nc(base);
	String* descriptor = constantInvokeDynamic->descriptor;
	$var(ArrayList, list, ByteCodeClass::parseMethodDescriptor(descriptor));
	$var($ClassArray, ptypes, $new($ClassArray, list->size() - 1));
	for (int32_t i = 0; i < list->size() - 1; i++) {
		$var(String, type, $fcast<String>(list->get(i)));
		Class* clazz = loadClass(type);
		ptypes->set(i, clazz);
	}
	pushAndCreateFrame4Invokedynamic(ptypes);

	try {
		String* methodName = constantInvokeDynamic->name;
		$var($Array<BootstrapMethod>, bootstrapMethods, clazz->getByteCodeClassData(false)->bootstrapMethods);
		BootstrapMethod* bootstrapMethod = bootstrapMethods->get(constantInvokeDynamic->bootstrapMethodAttrIndex);
		$nc(bootstrapMethod);
		ConstantMethodHandle* methodHandle = (ConstantMethodHandle*)bootstrapMethod->methodHandle;
		ConstantMethodType* cmt0 = (ConstantMethodType*)bootstrapMethod->bootstrapArguments->get(0);
		$var(MethodType, mt0, MethodType::fromMethodDescriptorString(cmt0->descriptor, clazz->classLoader));
		ConstantMethodHandle* cmh1 = (ConstantMethodHandle*)bootstrapMethod->bootstrapArguments->get(1);
		ConstantMethodRef* cmref = constantPool->getMethodRef(cmh1->referenceIndex);
		Class* methodClazz = Class::forName($(cmref->clazz->replace('/', '.')), false, clazz->classLoader);
		$var(Method, method, methodClazz->getMethodEx(cmref->name, cmref->descriptor));
		$var(MethodHandles$Lookup, lookup, MethodHandles::lookup());
		$var(MethodHandle, mh, nullptr);
		$var(MethodType, mt1, MethodType::fromMethodDescriptorString(cmref->descriptor, clazz->classLoader));
		if (method->isStatic()) {
			$assign(mh, lookup->findStatic(methodClazz, cmref->name, mt1));
		} else {
			$assign(mh, lookup->findVirtual(methodClazz, cmref->name, mt1));
		}
		ConstantMethodType* cmt2 = (ConstantMethodType*)bootstrapMethod->bootstrapArguments->get(2);
		$var(MethodType, mt2, MethodType::fromMethodDescriptorString(cmt2->descriptor, clazz->classLoader));
		$var(String, returnType, $fcast<String>(list->get(list->size() - 1)));
		$var(MethodType, mt, MethodType::methodType(loadClass(returnType), ptypes));
		$var(CallSite, cs, LambdaMetafactory::metafactory(lookup, methodName, mt, mt0, mh, mt2));
		$var(MethodHandle, target, cs->getTarget());
		int32_t localIndex = 0;
		$var($ObjectArray, args, $new($ObjectArray, ptypes->length));
		for (int32_t i = 0; i < ptypes->length; i++) {
			Class* type = ptypes->get(i);
			$var(Object, arg, getParameter(type, frame, localIndex));
			args->set(i, arg);
			int32_t category = calcCategory0(type);
			localIndex += category;
		}
		$var(Object, ret, target->invokeExact(args));
		frame->setReturn(Object::class$, ret);
	} catch (InvocationTargetException& ite) {
		$set(this, currentException, ite->target);
	} catch (Throwable& e) {
		$set(this, currentException, e);
	}
	popFrame();
}

void ByteCodeInterpreter::prepareArgs(Object$* instance, $ClassArray* parameterTypes, $Value* argv) {
	int32_t argIndex = 0;
	if (instance != nullptr) {
		frame->setLocalPointer(argIndex++, instance);
	}
	if (parameterTypes != nullptr) {
		for (int32_t i = 0; i < parameterTypes->length; i++) {
			Class* type = parameterTypes->get(i);
			if (type->isPrimitive()) {
				if (type == Integer::TYPE) {
					frame->setLocalInt(argIndex++, argv[i].intValue());
				} else if (type == Boolean::TYPE) {
					frame->setLocalInt(argIndex++, argv[i].booleanValue());
				} else if (type == Byte::TYPE) {
					frame->setLocalInt(argIndex++, argv[i].byteValue());
				} else if (type == Short::TYPE) {
					frame->setLocalInt(argIndex++, argv[i].shortValue());
				} else if (type == Character::TYPE) {
					frame->setLocalInt(argIndex++, argv[i].charValue());
				} else if (type == Long::TYPE) {
					frame->setLocalLong(argIndex, argv[i].longValue());
					argIndex += 2;
				} else if (type == Float::TYPE) {
					frame->setLocalFloat(argIndex++, argv[i].floatValue());
				} else if (type == Double::TYPE) {
					frame->setLocalDouble(argIndex, argv[i].doubleValue());
					argIndex += 2;
				} else {
					$shouldNotReachHere();
				}
			} else {
				frame->setLocalPointer(argIndex++, argv[i].is<$Object>());
			}
		}
	}
}

void ByteCodeInterpreter::pushFrame(Frame* frame) {
	$set(frame, next, frameStack);
	$set(this, frameStack, frame);
}

void ByteCodeInterpreter::pushAndCreateFrame(ByteCodeMethod* method) {
	int32_t stackSlotsForParameters = 0;
	if ((method->accessFlags & Modifier::VARARGS) != 0) {
		stackSlotsForParameters = frame->operandsTop;
	} else {
		stackSlotsForParameters = method->stackSlotsForParameters;
	}
	int32_t operandStackTop = frame->firstOperandIndex + frame->operandsTop;
	$var(Frame, newFrame, $new(Frame, this, method, operandStackTop));

	frame->operandsTop += -stackSlotsForParameters + method->returnCategory;
	pushFrame(frame);
	$set(this, frame, newFrame);
}

void ByteCodeInterpreter::pushAndCreateFrame4Native(int32_t stackSlotsForArgs, int32_t realReturnCategory) {
	int32_t operandStackTop = frame->firstOperandIndex + frame->operandsTop;
	$var(Frame, newFrame, $new(Frame, this, operandStackTop, stackSlotsForArgs));

	frame->operandsTop += -stackSlotsForArgs + realReturnCategory;
	pushFrame(frame);
	$set(this, frame, newFrame);
}

void ByteCodeInterpreter::pushAndCreateFrame4Invokedynamic($ClassArray* ptypes) {
	int stackSlotsForArgs = 0;
	int realReturnCategory = 1;
	for (int32_t i = 0; i < ptypes->length; i++) {
		Class* argType = ptypes->get(i);
		stackSlotsForArgs += calcCategory0(argType);
	}
	int32_t operandStackTop = frame->firstOperandIndex + frame->operandsTop;
	$var(Frame, newFrame, $new(Frame, this, operandStackTop, stackSlotsForArgs));

	frame->operandsTop += -stackSlotsForArgs + realReturnCategory;
	pushFrame(frame);
	$set(this, frame, newFrame);
}

void ByteCodeInterpreter::getStatic(Field* field) {
	if (!field->override$) {
		field->override$ = true;
	}
	if (field->type->isPrimitive()) {
		if (field->type == Boolean::TYPE) {
			frame->pushBool(field->getBoolean(nullptr));
		} else if (field->type == Byte::TYPE) {
			frame->pushInt8(field->getByte(nullptr));
		} else if (field->type == Short::TYPE) {
			frame->pushInt16(field->getShort(nullptr));
		} else if (field->type == Integer::TYPE) {
			frame->pushInt32(field->getInt(nullptr));
		} else if (field->type == Long::TYPE) {
			frame->pushInt64(field->getLong(nullptr));
		} else if (field->type == Float::TYPE) {
			frame->pushFloat(field->getFloat(nullptr));
		} else if (field->type == Double::TYPE) {
			frame->pushDouble(field->getDouble(nullptr));
		} else if (field->type == Character::TYPE) {
			frame->pushChar16(field->getChar(nullptr));
		} else {
			$shouldNotReachHere();
		}
	} else {
		frame->pushObject($(field->get(nullptr)));
	}
}

void ByteCodeInterpreter::putStatic(Field* field) {
	if (!field->override$) {
		field->override$ = true;
	}
	if (field->type->isPrimitive()) {
		if (field->type == Boolean::TYPE) {
			field->setBoolean(nullptr, frame->popBool());
		} else if (field->type == Byte::TYPE) {
			field->setByte(nullptr, frame->popInt8());
		} else if (field->type == Short::TYPE) {
			field->setShort(nullptr, frame->popInt16());
		} else if (field->type == Integer::TYPE) {
			field->setInt(nullptr, frame->popInt32());
		} else if (field->type == Long::TYPE) {
			field->setLong(nullptr, frame->popInt64());
		} else if (field->type == Float::TYPE) {
			field->setFloat(nullptr, frame->popFloat());
		} else if (field->type == Double::TYPE) {
			field->setDouble(nullptr, frame->popDouble());
		} else if (field->type == Character::TYPE) {
			field->setChar(nullptr, frame->popChar16());
		} else {
			$shouldNotReachHere();
		}
	} else {
		// TODO
		if (field->root != nullptr && Modifier::isFinal(field->root->modifiers)) {
			field->root->modifiers &= ~Modifier::FINAL;
		}
		$var(Object, obj, frame->popObject());
		field->set(nullptr, obj);
	}
}

void ByteCodeInterpreter::getField(Field* field) {
	if (!field->override$) {
		field->override$ = true;
	}
	$var(Object, obj, frame->popObject());
	if (field->type->isPrimitive()) {
		if (field->type == Boolean::TYPE) {
			frame->pushBool(field->getBoolean(obj));
		} else if (field->type == Byte::TYPE) {
			frame->pushInt8(field->getByte(obj));
		} else if (field->type == Short::TYPE) {
			frame->pushInt16(field->getShort(obj));
		} else if (field->type == Integer::TYPE) {
			frame->pushInt32(field->getInt(obj));
		} else if (field->type == Long::TYPE) {
			frame->pushInt64(field->getLong(obj));
		} else if (field->type == Float::TYPE) {
			frame->pushFloat(field->getFloat(obj));
		} else if (field->type == Double::TYPE) {
			frame->pushDouble(field->getDouble(obj));
		} else if (field->type == Character::TYPE) {
			frame->pushChar16(field->getChar(obj));
		} else {
			$shouldNotReachHere();
		}
	} else {
		frame->pushObject($(field->get(obj)));
	}
}

void ByteCodeInterpreter::putField(Field* field) {
	// TODO
   // if (field->root != nullptr && Modifier::isFinal(field->root->modifiers)) {
		if (!field->override$) {
	   //	 field->acquireFieldAccessor(true);
			field->override$ = true;
		}
	 //   field->root->modifiers &= ~Modifier::FINAL;
   // }
	if (field->type->isPrimitive()) {
		if (field->type == Boolean::TYPE) {
			bool value = frame->popBool();
			$var(Object, obj, frame->popObject());
			field->setBoolean(obj, value);
		} else if (field->type == Byte::TYPE) {
			int8_t value = frame->popInt8();
			$var(Object, obj, frame->popObject());
			field->setByte(obj, value);
		} else if (field->type == Short::TYPE) {
			int16_t value = frame->popInt16();
			$var(Object, obj, frame->popObject());
			field->setShort(obj, value);
		} else if (field->type == Integer::TYPE) {
			int32_t value = frame->popInt32();
			$var(Object, obj, frame->popObject());
			field->setInt(obj, value);
		} else if (field->type == Long::TYPE) {
			int64_t value = frame->popInt64();
			$var(Object, obj, frame->popObject());
			field->setLong(obj, value);
		} else if (field->type == Float::TYPE) {
			float value = frame->popFloat();
			$var(Object, obj, frame->popObject());
			field->setFloat(obj, value);
		} else if (field->type == Double::TYPE) {
			double value = frame->popDouble();
			$var(Object, obj, frame->popObject());
			field->setDouble(obj, value);
		} else if (field->type == Character::TYPE) {
			char16_t value = frame->popChar16();
			$var(Object, obj, frame->popObject());
			field->setChar(obj, value);
		} else {
			$shouldNotReachHere();
		}
	} else {
		$var(Object, value, frame->popObject());
		$var(Object, obj, frame->popObject());
		field->set(obj, value);
	}
}

void ByteCodeInterpreter::throwNewArithmeticExceptionDivisionByZero() {
	$throwNew(ArithmeticException, "division by zero"_s);
	//$set(this, currentException, $new(ArithmeticException, "division by zero"_s));
}

inline ByteCodeClass* ByteCodeInterpreter::getCurrentClass() {
	return frame->byteCodeMethod->clazz;
}

inline ConstantPool* ByteCodeInterpreter::getConstantPool() {
	return frame->byteCodeMethod->clazz->getConstantPool();
}

inline void ByteCodeInterpreter::setMemoryItem(int32_t index, MemoryItem value) {
	if ((uint32_t)index >= (uint32_t)memory->length) {
		if (index < 0) {
			memory->check(index);
		}
		if (index >= memory->length) {
			$var($longs, newMemory, $new($longs, index + 128));
			newMemory->setArray(0, memory, 0, memory->length);
			$set(this, memory, newMemory);
		}
	}
	int64_t* begin = memory->begin() + index;
	begin[0] = value;
}

inline void ByteCodeInterpreter::setMemoryItem(int32_t index, MemoryItem value0, MemoryItem value1) {
	if ((uint32_t)index >= (uint32_t)memory->length - 1) {
		setMemoryItem(index, value0);
		setMemoryItem(index + 1, value1);
	} else {
		int64_t* begin = memory->begin() + index;
		begin[0] = value0;
		begin[1] = value1;
	}
}

inline MemoryItem ByteCodeInterpreter::getMemoryItem(int32_t index) {
	return memory->get(index);
}

inline void ByteCodeInterpreter::saveMemoryObject(int32_t index, Object$* obj) {
	if ((uint32_t)index >= (uint32_t)memoryObject->length) {
		if (index < 0) {
			memoryObject->check(index);
		}
		if (index >= memoryObject->length) {
			$var($ObjectArray, newMemoryObject, $new($ObjectArray, index + 128));
			newMemoryObject->setArray(0, memoryObject, 0, memoryObject->length);
			$set(this, memoryObject, newMemoryObject);
		}
	}
	memoryObject->set(index, obj);
}

inline void ByteCodeInterpreter::clearMemoryObject(int32_t index) {
	saveMemoryObject(index, nullptr);
}

		} // interpreter
	} // lang
} // java
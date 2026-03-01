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

#include <java/lang/Util.h>

#include <java/lang/Class.h>
#include <java/lang/String.h>
#include <java/lang/Byte.h>
#include <java/lang/Short.h>
#include <java/lang/Integer.h>
#include <java/lang/Long.h>
#include <java/lang/Float.h>
#include <java/lang/Double.h>
#include <java/lang/Boolean.h>
#include <java/lang/Character.h>
#include <java/lang/ByteArray.h>
#include <java/lang/LongArray.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/nio/ByteBuffer.h>
#include <java/lang/reflect/Array.h>
#include <jcpp.h>

#include <atomic>

using ::java::nio::ByteBuffer;

namespace java {
	namespace lang {

$StringArray* Util::split(const char* s, char separatorChar) {
	int32_t count = 1;
	for (int32_t i = 0; s[i] != '\0'; i++) {
		if (s[i] == separatorChar) {
			count++;
		}
	}
	$var($StringArray, sa, $new<$StringArray>(count));
	int32_t offset = 0;
	for (int32_t i = 0; i < sa->length; i++) {
		char buffer[512] = {};
		int32_t bufferIndex = 0;
		for (; s[offset] != '\0' && bufferIndex < sizeof(buffer);) {
			char c = s[offset];
			offset++;
			if (c == ' ') {
				continue;
			}
			if (c == separatorChar) {
				break;
			}
			buffer[bufferIndex] = c;
			bufferIndex++;
		}
		buffer[bufferIndex] = 0;
		$var(String, s, $str(buffer));
		sa->set(i, s);
	}
	return sa;
}

bool Util::needConvert(Class* type, Object0* arg) {
	if (arg == nullptr) {
		if (type->isPrimitive()) {
			$throwNew(IllegalArgumentException);
		}
		return false;
	}
	if (type->isPrimitive()) {
		Class* argClass = arg->getClass();
		if (type == Integer::TYPE) {
			return argClass != Integer::class$;
		}
		if (type == Long::TYPE) {
			return argClass != Long::class$;
		}
		if (type == Byte::TYPE) {
			return argClass != Byte::class$;
		}
		if (type == Short::TYPE) {
			return argClass != Short::class$;
		}
		if (type == Character::TYPE) {
			return argClass != Character::class$;
		}
		if (type == Float::TYPE) {
			return argClass != Float::class$;
		}
		if (type == Double::TYPE) {
			return argClass != Double::class$;
		}
		if (type == Boolean::TYPE) {
			return argClass != Boolean::class$;
		}
	}
	return !type->isInstance(arg);
}

Object0* Util::convert(Class* type, Object0* arg) {
	if (arg == nullptr) {
		return nullptr;
	}
	if (type->isPrimitive()) {
		Class* argClass = arg->getClass();
		if (type == Integer::TYPE) {
			int32_t value = 0;
			if (argClass == Byte::class$) {
				value = $byteValue(arg);
			} else if (argClass == Short::class$) {
				value = $shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = $booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = $charValue(arg);
			} else if (argClass == Float::class$) {
				value = (int32_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (int32_t)$doubleValue(arg);
			} else if (argClass == Long::class$) {
				value = (int32_t)$longValue(arg);
			} else if (argClass == Integer::class$) {
				return arg;
			} else {
				$throwNew(IllegalArgumentException);
			}
			return $fcast<Object0>(Integer::valueOf(value));
		}
		if (type == Long::TYPE) {
			int64_t value = 0;
			if (argClass == Integer::class$) {
				value = $intValue(arg);
			} else if (argClass == Byte::class$) {
				value = $byteValue(arg);
			} else if (argClass == Short::class$) {
				value = $shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = $booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = $charValue(arg);
			} else if (argClass == Float::class$) {
				value = (int64_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (int64_t)$doubleValue(arg);
			} else if (argClass == Long::class$) {
				return arg;
			} else {
				$throwNew(IllegalArgumentException);
			}
			return $fcast<Object0>(Long::valueOf(value));
		}
		if (type == Byte::TYPE) {
			int8_t value = 0;
			if (argClass == Integer::class$) {
				value = (int8_t)$intValue(arg);
			} else if (argClass == Long::class$) {
				value = (int8_t)$longValue(arg);
			} else if (argClass == Short::class$) {
				value = (int8_t)$shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = (int8_t)$booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = (int8_t)$charValue(arg);
			} else if (argClass == Float::class$) {
				value = (int8_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (int8_t)$doubleValue(arg);
			} else if (argClass == Byte::class$) {
				return arg;
			} else {
				$throwNew(IllegalArgumentException);
			}
			return $fcast<Object0>(Byte::valueOf(value));
		}
		if (type == Short::TYPE) {
			int16_t value = 0;
			if (argClass == Integer::class$) {
				value = (int16_t)$intValue(arg);
			} else if (argClass == Long::class$) {
				value = (int16_t)$longValue(arg);
			} else if (argClass == Byte::class$) {
				value = (int16_t)$byteValue(arg);
			} else if (argClass == Boolean::class$) {
				value = (int16_t)$booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = (int16_t)$charValue(arg);
			} else if (argClass == Float::class$) {
				value = (int16_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (int16_t)$doubleValue(arg);
			} else if (argClass == Short::class$) {
				return arg;
			} else {
				$throwNew(IllegalArgumentException);
			}
			return $fcast<Object0>(Short::valueOf(value));
		}
		if (type == Character::TYPE) {
			char16_t value = 0;
			if (argClass == Integer::class$) {
				value = (char16_t)$intValue(arg);
			} else if (argClass == Long::class$) {
				value = (char16_t)$longValue(arg);
			} else if (argClass == Byte::class$) {
				value = (char16_t)$byteValue(arg);
			} else if (argClass == Boolean::class$) {
				value = (char16_t)$booleanValue(arg) ? 1 : 0;
			} else if (argClass == Short::class$) {
				value = (char16_t)$shortValue(arg);
			} else if (argClass == Float::class$) {
				value = (char16_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (char16_t)$doubleValue(arg);
			} else if (argClass == Character::class$) {
				return arg;
			} else {
				$throwNew(IllegalArgumentException);
			}
			return $fcast<Object0>(Character::valueOf(value));
		}
		if (type == Float::TYPE) {
			float value = 0;
			if (argClass == Double::class$) {
				value = (float)$doubleValue(arg);
			} else if (argClass == Integer::class$) {
				value = (float)$intValue(arg);
			} else if (argClass == Long::class$) {
				value = (float)$longValue(arg);
			} else if (argClass == Byte::class$) {
				value = $byteValue(arg);
			} else if (argClass == Short::class$) {
				value = $shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = $booleanValue(arg) ? 1.0f : 0.0f;
			} else if (argClass == Character::class$) {
				value = $charValue(arg);
			} else if (argClass == Float::class$) {
				return arg;
			} else {
				$throwNew(IllegalArgumentException);
			}
			return $fcast<Object0>(Float::valueOf(value));
		}
		if (type == Double::TYPE) {
			double value = 0;
			if (argClass == Float::class$) {
				value = $floatValue(arg);
			} else if (argClass == Integer::class$) {
				value = $intValue(arg);
			} else if (argClass == Long::class$) {
				value = (double)$longValue(arg);
			} else if (argClass == Byte::class$) {
				value = $byteValue(arg);
			} else if (argClass == Short::class$) {
				value = $shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = $booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = $charValue(arg);
			} else if (argClass == Double::class$) {
				return arg;
			} else {
				$throwNew(IllegalArgumentException);
			}
			return $fcast<Object0>(Double::valueOf(value));
		}
		if (type == Boolean::TYPE) {
			bool value = false;
			if (argClass == Integer::class$) {
				value = $intValue(arg) != 0;
			} else if (argClass == Byte::class$) {
				value = $byteValue(arg) != 0;
			} else if (argClass == Short::class$) {
				value = $shortValue(arg) != 0;
			} else if (argClass == Long::class$) {
				value = $longValue(arg) != 0;
			} else if (argClass == Character::class$) {
				value = $charValue(arg) != 0;
			} else if (argClass == Float::class$) {
				value = $floatValue(arg) != 0;
			} else if (argClass == Double::class$) {
				value = $doubleValue(arg) != 0;
			} else if (argClass == Boolean::class$) {
				return arg;
			} else {
				$throwNew(IllegalArgumentException);
			}
			return $fcast<Object0>(Boolean::valueOf(value));
		}
		$throwNew(IllegalArgumentException);
	} else {
		if (!type->isInstance(arg)) {
		//	type->isInstance(arg); // TODO for test
			$throwNew(IllegalArgumentException);
		}
		return arg;
	}
}

$Value Util::prepareArg(Class* type, Object0* arg) {
	if (arg == nullptr) {
		return nullptr;
	}
	if (type->isPrimitive()) {
		Class* argClass = arg->getClass();
		if (type == Integer::TYPE) {
			int32_t value = 0;
			if (argClass == Byte::class$) {
				value = $byteValue(arg);
			} else if (argClass == Short::class$) {
				value = $shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = $booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = $charValue(arg);
			} else if (argClass == Float::class$) {
				value = (int32_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (int32_t)$doubleValue(arg);
			} else if (argClass == Long::class$) {
				value = (int32_t)$longValue(arg);
			} else if (argClass == Integer::class$) {
				value = $intValue(arg);
			} else {
				$throwNew(IllegalArgumentException);
			}
			return value;
		}
		if (type == Long::TYPE) {
			int64_t value = 0;
			if (argClass == Integer::class$) {
				value = $intValue(arg);
			} else if (argClass == Byte::class$) {
				value = $byteValue(arg);
			} else if (argClass == Short::class$) {
				value = $shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = $booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = $charValue(arg);
			} else if (argClass == Float::class$) {
				value = (int64_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (int64_t)$doubleValue(arg);
			} else if (argClass == Long::class$) {
				value = $longValue(arg);
			} else {
				$throwNew(IllegalArgumentException);
			}
			return value;
		}
		if (type == Byte::TYPE) {
			int8_t value = 0;
			if (argClass == Integer::class$) {
				value = (int8_t)$intValue(arg);
			} else if (argClass == Long::class$) {
				value = (int8_t)$longValue(arg);
			} else if (argClass == Short::class$) {
				value = (int8_t)$shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = (int8_t)$booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = (int8_t)$charValue(arg);
			} else if (argClass == Float::class$) {
				value = (int8_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (int8_t)$doubleValue(arg);
			} else if (argClass == Byte::class$) {
				value = $byteValue(arg);
			} else {
				$throwNew(IllegalArgumentException);
			}
			return value;
		}
		if (type == Short::TYPE) {
			int16_t value = 0;
			if (argClass == Integer::class$) {
				value = (int16_t)$intValue(arg);
			} else if (argClass == Long::class$) {
				value = (int16_t)$longValue(arg);
			} else if (argClass == Byte::class$) {
				value = (int16_t)$byteValue(arg);
			} else if (argClass == Boolean::class$) {
				value = (int16_t)$booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = (int16_t)$charValue(arg);
			} else if (argClass == Float::class$) {
				value = (int16_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (int16_t)$doubleValue(arg);
			} else if (argClass == Short::class$) {
				value = $shortValue(arg);
			} else {
				$throwNew(IllegalArgumentException);
			}
			return value;
		}
		if (type == Character::TYPE) {
			char16_t value = 0;
			if (argClass == Integer::class$) {
				value = (char16_t)$intValue(arg);
			} else if (argClass == Long::class$) {
				value = (char16_t)$longValue(arg);
			} else if (argClass == Byte::class$) {
				value = (char16_t)$byteValue(arg);
			} else if (argClass == Boolean::class$) {
				value = (char16_t)$booleanValue(arg) ? 1 : 0;
			} else if (argClass == Short::class$) {
				value = (char16_t)$shortValue(arg);
			} else if (argClass == Float::class$) {
				value = (char16_t)$floatValue(arg);
			} else if (argClass == Double::class$) {
				value = (char16_t)$doubleValue(arg);
			} else if (argClass == Character::class$) {
				value = $charValue(arg);
			} else {
				$throwNew(IllegalArgumentException);
			}
			return value;
		}
		if (type == Float::TYPE) {
			float value = 0;
			if (argClass == Double::class$) {
				value = (float)$doubleValue(arg);
			} else if (argClass == Integer::class$) {
				value = (float)$intValue(arg);
			} else if (argClass == Long::class$) {
				value = (float)$longValue(arg);
			} else if (argClass == Byte::class$) {
				value = $byteValue(arg);
			} else if (argClass == Short::class$) {
				value = $shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = $booleanValue(arg) ? 1.0f : 0.0f;
			} else if (argClass == Character::class$) {
				value = $charValue(arg);
			} else if (argClass == Float::class$) {
				value = $floatValue(arg);
			} else {
				$throwNew(IllegalArgumentException);
			}
			return value;
		}
		if (type == Double::TYPE) {
			double value = 0;
			if (argClass == Float::class$) {
				value = $floatValue(arg);
			} else if (argClass == Integer::class$) {
				value = $intValue(arg);
			} else if (argClass == Long::class$) {
				value = (double)$longValue(arg);
			} else if (argClass == Byte::class$) {
				value = $byteValue(arg);
			} else if (argClass == Short::class$) {
				value = $shortValue(arg);
			} else if (argClass == Boolean::class$) {
				value = $booleanValue(arg) ? 1 : 0;
			} else if (argClass == Character::class$) {
				value = $charValue(arg);
			} else if (argClass == Double::class$) {
				value = $doubleValue(arg);
			} else {
				$throwNew(IllegalArgumentException);
			}
			return value;
		}
		if (type == Boolean::TYPE) {
			bool value = false;
			if (argClass == Integer::class$) {
				value = $intValue(arg) != 0;
			} else if (argClass == Byte::class$) {
				value = $byteValue(arg) != 0;
			} else if (argClass == Short::class$) {
				value = $shortValue(arg) != 0;
			} else if (argClass == Long::class$) {
				value = $longValue(arg) != 0;
			} else if (argClass == Character::class$) {
				value = $charValue(arg) != 0;
			} else if (argClass == Float::class$) {
				value = $floatValue(arg) != 0;
			} else if (argClass == Double::class$) {
				value = $doubleValue(arg) != 0;
			} else if (argClass == Boolean::class$) {
				value = $booleanValue(arg) != 0;
			} else {
				$throwNew(IllegalArgumentException);
			}
			return value;
		}
		$throwNew(IllegalArgumentException);
	} else {
		//if (!type->isInstance(arg)) {
		//	type->isInstance(arg); // TODO for test
		//	$throwNew(IllegalArgumentException);
	//	}
		return type->cast(arg);
	}
}

Object* Util::toObject(Class* type, $Value var) {
	if (type == Void::TYPE) {
		return Void::VOID$;
	}
	if (type == Integer::TYPE) {
		return $of(var.intValue());
	}
	if (type == Long::TYPE) {
		return $of(var.longValue());
	}
	if (type == Byte::TYPE) {
		return $of(var.byteValue());
	}
	if (type == Short::TYPE) {
		return $of(var.shortValue());
	}
	if (type == Character::TYPE) {
		return $of(var.charValue());
	}
	if (type == Float::TYPE) {
		return $of(var.floatValue());
	}
	if (type == Double::TYPE) {
		return $of(var.doubleValue());
	}
	if (type == Boolean::TYPE) {
		return $of(var.booleanValue());
	}
	return var.is<$Object>();
}

void Util::prepareArgs($Array<Class>* types, $ObjectArray* args, $Value* output) {
	if (args == nullptr) {
		if (types->length == 0) {
			return;
		}
		$throwNew(IllegalArgumentException);
	} else if (types->length > args->length) {
		$throwNew(IllegalArgumentException);
	}
	int32_t fixArgCount = types->length;
	for (int32_t i = 0; i < fixArgCount; i++) {
		Class* type = types->get(i);
		Object0* arg = args->get(i);
		output[i] = prepareArg(type, arg);
	}
}

Object* Util::prepareArgsWithVarArgs($Array<Class>* types, $ObjectArray* args, $Value* output) {
	int32_t fixArgCount = types->length - 1;
	Class* varArgClazz = types->get(fixArgCount);
	Class* componentType = varArgClazz->getComponentType();
	if (args == nullptr) {
		if (types->length == 1) {
			$var($ObjectArray, args0, $new<$ObjectArray>(1));
			args0->set(0, ::java::lang::reflect::Array::newArray(componentType, 0));
			output[0] = args0;
			return args0;
		}
		$throwNew(IllegalArgumentException);
	}
	if (args->length < fixArgCount) {
		$throwNew(IllegalArgumentException);
	}
	for (int32_t i = 0; i < fixArgCount; i++) {
		Class* type = types->get(i);
		Object0* arg = args->get(i);
		output[i] = prepareArg(type, arg);
	}
	int32_t varArgsCount = args->length - fixArgCount;
	if (varArgsCount == 0) {
		if (fixArgCount == 0) {
			if (varArgClazz->isInstance(args)) {
				output[0] = args;
				return nullptr;
			}
		}
	} else if (varArgsCount == 1) {
		if (fixArgCount == 0) {
			if (varArgClazz->isInstance(args)) {
				output[0] = args;
				return nullptr;
			}
		}
		Object0* arg = args->get(fixArgCount);
		if (varArgClazz->isInstance(arg)) {
			output[fixArgCount] = arg;
			return nullptr;
		}
	}
	$var($ObjectArray, varArgs, $ObjectArray::create(componentType, varArgsCount));
	for (int32_t i = 0; i < varArgs->length; i++) {
		Object0* arg = args->get(i + fixArgCount);
		if (needConvert(componentType, arg)) {
			varArgs->set(i, convert(componentType, arg));
		} else {
			varArgs->set(i, arg);
		}
	}
	output[fixArgCount] = varArgs;
	return varArgs;
}

String* Util::subStr(::java::lang::String* origin, ::java::lang::String* start, ::java::lang::String* end) {
	int32_t index = $nullcheck(origin)->indexOf(start);
	if (index == -1) {
		return nullptr;
	}
	index += start->length();
	int32_t endIndex = origin->indexOf(end, index);
	if (endIndex == -1) {
		return nullptr;
	}
	return origin->substring(index, endIndex);
}

	}
}
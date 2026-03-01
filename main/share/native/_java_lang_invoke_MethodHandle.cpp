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

#include <java/lang/Class.h>
#include <java/lang/String.h>
#include <java/lang/Boolean.h>
#include <java/lang/Byte.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/DirectMethodHandle.h>
#include <java/lang/invoke/BoundMethodHandle.h>
#include <java/lang/invoke/DelegatingMethodHandle.h>
#include <java/lang/invoke/DirectMethodHandle$Accessor.h>
#include <java/lang/invoke/DirectMethodHandle$StaticAccessor.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/Invokers.h>
#include <java/lang/invoke/LambdaForm.h>
#include <java/lang/invoke/MethodHandleNatives$Constants.h>

#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/ResolvedMethodName.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/IncompatibleClassChangeError.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jcpp.h>

using namespace ::java::lang;
using namespace ::java::lang::invoke;
using namespace ::java::lang::reflect;
using ::jdk::internal::misc::Unsafe;

#include <stdlib.h>
#include <string.h>

#include "jni.h"
#include "jni_util.h"
#include "jvm.h"
#include "TimeZone_md.h"

Object* unsafeGet(Object$* inst, int64_t offset, $Class* type) {
	if (type->isPrimitive()) {
		if (type == Integer::TYPE) {
			return $of(Unsafe::theUnsafe->getInt(inst, offset));
		} else if (type == Boolean::TYPE) {
			return $of(Unsafe::theUnsafe->getBoolean(inst, offset));
		} else if (type == Byte::TYPE) {
			return $of(Unsafe::theUnsafe->getByte(inst, offset));
		} else if (type == Short::TYPE) {
			return $of(Unsafe::theUnsafe->getShort(inst, offset));
		} else if (type == Character::TYPE) {
			return $of(Unsafe::theUnsafe->getChar(inst, offset));
		} else if (type == Long::TYPE) {
			return $of(Unsafe::theUnsafe->getLong(inst, offset));
		} else if (type == Float::TYPE) {
			return $of(Unsafe::theUnsafe->getFloat(inst, offset));
		} else if (type == Double::TYPE) {
			return $of(Unsafe::theUnsafe->getDouble(inst, offset));
		}
		$shouldNotReachHere();
	} else {
		return Unsafe::theUnsafe->getObject(inst, offset);
	}
}

inline Object* invokeBasic0(MemberName* mn, $ObjectArray* args) {
	int8_t refKind = mn->getReferenceKind();
	::java::lang::reflect::Executable* exe = mn->method->vmtarget;
	Class* exeClazz = $of(exe)->getClass();
	if (exeClazz == Method::class$) {
		Method* method = static_cast<Method*>(exe);
		if (!method->override$) {
			method->override$ = true;
		}
		if (method->isStatic()) {
			return (Object*)method->invoke(nullptr, args);
		} else {
			$var($ObjectArray, args0, $new<$ObjectArray>(args->length - 1));
		//	args0->setRegion(0, args0->length, args->begin() + 1);
			args0->setArray(0, args, 1, args0->length);
			if (refKind == MethodHandleNatives$Constants::REF_invokeSpecial || refKind == MethodHandleNatives$Constants::REF_newInvokeSpecial) {
				return (Object*)method->invokeSpecial(args->get(0), args0);
			} else {
				return (Object*)method->invoke(args->get(0), args0);
			}
		}
	}
	if (exeClazz == Constructor::class$) {
		Constructor* constructor = static_cast<Constructor*>(exe);
		constructor->override$ = true;
		return (Object*)constructor->newInstance(args);
	}
	$throwNew(UnsupportedOperationException, "invoke0"_s);
}

$ObjectArray* makeArgs(::java::lang::invoke::MethodHandle* this__, $ObjectArray* args) {
	$var($ObjectArray, args2, nullptr);
	if (args != nullptr) {
		$assign(args2, $new<$ObjectArray>(args->length + 1));
		args2->setArray(1, args, 0, args->length);
	} else {
		$assign(args2, $new<$ObjectArray>(1));
	}
	args2->set(0, this__);
	return args2;
}

Object* _Java_java_lang_invoke_MethodHandle_invoke(::java::lang::invoke::MethodHandle* this__, $ObjectArray* args) {
	Class* thisClazz = $of(this__)->getClass();
	if (thisClazz == DirectMethodHandle$Accessor::class$) {
		DirectMethodHandle$Accessor* dmha = $cast(DirectMethodHandle$Accessor, this__);
		return unsafeGet(args->get(0), dmha->fieldOffset, dmha->fieldType);
	}
	if (thisClazz == DirectMethodHandle$StaticAccessor::class$) {
		DirectMethodHandle$StaticAccessor* dmhsa = $cast(DirectMethodHandle$StaticAccessor, this__);
		return unsafeGet(nullptr, dmhsa->staticOffset, dmhsa->fieldType);
	}
	if ($instanceOf<DirectMethodHandle>(this__)) {
		DirectMethodHandle* dmh = $cast(DirectMethodHandle, this__);
		return invokeBasic0(dmh->member, args);

		//$var(DirectMethodHandle, dmh, $cast<DirectMethodHandle>(this__));
		//if (dmh->member__->method__->vmtarget->getClass() == Method::class$) {
		//	Method* method = _scast<Method>(dmh->member__->method__->vmtarget);
		//	method->override__ = true;
		//	if (method->isStatic()) {
		//		$return (method->invoke(nullptr, args));
		//	} else {
		//		$var(ObjectArray, args0, $new< ObjectArray>(args->length - 1));
		//		args0->setRegion(0, args0->length, args->begin() + 1);
		//		$return (method->invoke(args->get(0), args0));
		//	}
		//}
		//if (dmh->member__->method__->vmtarget->getClass() == Constructor::class$) {
		//	Constructor* constructor = _scast<Constructor>(dmh->member__->method__->vmtarget);
		//	constructor->override__ = true;
		//	$return (constructor->newInstance(args));
		//}
	}
	if ($instanceOf<BoundMethodHandle>(this__)) {
		$var($ObjectArray, args2, makeArgs(this__, args));
		// if (args != nullptr) {
		// 	$assign(args2, $new<$ObjectArray>(args->length + 1));
		// 	args2->setArray(1, args, 0, args->length);
		// } else {
		// 	$assign(args2, $new<$ObjectArray>(1));
		// }
		// args2->set(0, this__);

		return invokeBasic0(this__->form->vmentry, args2);

		//$var(BoundMethodHandle, bmh, $cast<BoundMethodHandle>(this__));
		//$var(Object, arg0, bmh->arg(0));
		//$var(::java::lang::invoke::MethodHandle, mh, $cast<::java::lang::invoke::MethodHandle>(arg0));
		//if (mh != nullptr) {
		//	int32_t count = bmh->fieldCount();
		//	$var(ObjectArray, args2, $new<ObjectArray>(count - 1 + args->length));
		//	for (int32_t i = 1; i < count; i++) {
		//		$var(Object, arg, bmh->arg(i));
		//		args2->set(i - 1, arg);
		//		//	arg->toString();
		//	}
		//	for (int32_t i = 0; i < args->length; i++) {
		//		$var(Object, arg, args->get(i));
		//		args2->set(i + count - 1, arg);
		//	}
		//	$return (_Java_java_lang_invoke_MethodHandle_invoke(mh, args2));
		//}
		//else {
		////	Class* clazz = arg0->getClass();
		//	$return (arg0);
		//}

	}
	$throwNew(UnsupportedOperationException, "_Java_java_lang_invoke_MethodHandle_invoke"_s);
//	return nullptr;
}

Object* _Java_java_lang_invoke_MethodHandle_invokeBasic(::java::lang::invoke::MethodHandle* this__, $ObjectArray* args) {
	Class* thisClazz = $of(this__)->getClass();
	if (thisClazz == DirectMethodHandle$Accessor::class$) {
		DirectMethodHandle$Accessor* dmha = $cast(DirectMethodHandle$Accessor, this__);
		return unsafeGet(args->get(0), dmha->fieldOffset, dmha->fieldType);
	}
	if (thisClazz == DirectMethodHandle$StaticAccessor::class$) {
		DirectMethodHandle$StaticAccessor* dmhsa = $cast(DirectMethodHandle$StaticAccessor, this__);
		return unsafeGet(nullptr, dmhsa->staticOffset, dmhsa->fieldType);
	}
	if ($instanceOf<DirectMethodHandle>(this__)) {
		DirectMethodHandle* dmh = $cast(DirectMethodHandle, this__);
		return invokeBasic0(dmh->member, args);
		//if (dmh->member__->method__->vmtarget->getClass() == Method::class$) {
		//	Method* method = _scast<Method>(dmh->member__->method__->vmtarget);
		//	if (!method->override__) {
		//		method->override__ = true;
		//	}
		//	if (method->isStatic()) {
		//		$return (method->invoke(nullptr, args));
		//	} else {
		//		$var(ObjectArray, args0, $new< ObjectArray>(args->length - 1));
		//		args0->setRegion(0, args0->length, args->begin() + 1);
		//		$return (method->invoke(args->get(0), args0));
		//	}
		//}
		//if (dmh->member__->method__->vmtarget->getClass() == Constructor::class$) {
		//	Constructor* constructor = _scast<Constructor>(dmh->member__->method__->vmtarget);
		//	constructor->override__ = true;
		//	$return (constructor->newInstance(args));
		//}
	}
	if ($instanceOf<BoundMethodHandle>(this__)) {
		// $var($ObjectArray, args2, $new<$ObjectArray>(args->length + 1));
		// args2->set(0, this__);
		// args2->setArray(1, args, 0, args->length);

		$var($ObjectArray, args2, makeArgs(this__, args));

		return invokeBasic0(this__->form->vmentry, args2);

		//$var(Method, method, this__->form->vmentry__->method__->vmtarget);

		////bmh->form->interpretWithArguments(args);
		//method->override__ = true;
		//$var(ObjectArray, args, $new<ObjectArray>(args->length + 1));
		//args->set(0, this__);//->speciesData());
		//for (int32_t i = 0; i < args->length; i++) {
		//	args->set(i + 1, args->get(i));
		//}
		//return method->invoke(nullptr, args);

		//$var(BoundMethodHandle, bmh, $cast<BoundMethodHandle>(this__));
		//$var(::java::lang::invoke::MethodHandle, mh, bmh->arg(0));
		//int32_t count = bmh->fieldCount();
		//$var(ObjectArray, args2, $new<ObjectArray>(count - 1 + args->length));
		//for (int32_t i = 1; i < count; i++) {
		//	$var(Object, arg, bmh->arg(i));
		//	args2->set(i - 1, arg);
		//	//	arg->toString();
		//}
		//for (int32_t i = 0; i < args->length; i++) {
		//	$var(Object, arg, args->get(i));
		//	args2->set(i + count - 1, arg);
		//}
		//$return (_Java_java_lang_invoke_MethodHandle_invokeBasic(mh, args2));
	}
	if ($instanceOf<DelegatingMethodHandle>(this__)) {
		DelegatingMethodHandle* dmh = $cast(DelegatingMethodHandle, this__);
		MethodHandle* target = dmh->getTarget();
		return ($Object*)target->invokeBasic(args);
	}
	$throwNew(UnsupportedOperationException, "_Java_java_lang_invoke_MethodHandle_invokeBasic"_s);
}

void checkArgsType(::java::lang::invoke::MethodType* mt, $ObjectArray* args) {

}

bool needConvertArgs(::java::lang::invoke::MethodType* mt, $ObjectArray* args) {
	for (int32_t i = 0; i < mt->ptypes$->length; i++) {
		Class* ptype = $fcast<Class>(mt->ptypes$->get(i));
		Object* arg = args->get(i);
		if (ptype->isPrimitive()) {
			if (arg == nullptr) {
				// TODO
				// throw exception
			}
			if (ptype == Byte::TYPE) {
				ptype = Byte::class$;
			} else if (ptype == Boolean::TYPE) {
				ptype = Boolean::class$;
			}
		}
		if (arg == nullptr) {
			continue;
		}
		if (arg->getClass() != ptype) {
			return true;
		}
	}
	return false;
}

Object$* convertArg(Class* ptype, Object* arg) {
	if (ptype->isPrimitive()) {
		Class* argType = arg->getClass();
		if (ptype == Boolean::TYPE) {
			if (argType == Boolean::class$) {
				return arg;
			}
			if (argType == Byte::class$) {
				return $fcast<Object>(Boolean::valueOf($fcast<Byte>(arg)->byteValue() != 0));
			}
		}
		if (ptype == Byte::TYPE) {
			if (argType == Byte::class$) {
				return arg;
			}
			if (argType == Boolean::class$) {
				return $fcast<Object>(Byte::valueOf($fcast<Boolean>(arg)->booleanValue() ? 1 : 0));
			}
		}
	}
	return ptype->cast($toObject0(arg));
//	return static_cast<Object*>(ptype->cast0(arg));
}

$ObjectArray* convertArgs(::java::lang::invoke::MethodType* mt, $ObjectArray* args) {
	$var($ObjectArray, args2, $new<$ObjectArray>(args != nullptr ? args->length : 0));
	for (int32_t i = 0; i < mt->ptypes$->length; i++) {
		Class* ptype = $fcast<Class>(mt->ptypes$->get(i));
		Object* arg = $nc(args)->get(i);
		$var(Object, newArg, convertArg(ptype, arg));
		args2->set(i, newArg);
	}
	return args2;
}

Object* _Java_java_lang_invoke_MethodHandle_invokeExact(::java::lang::invoke::MethodHandle* this__, $ObjectArray* args) {
	Class* thisClazz = $of(this__)->getClass();
	checkArgsType(this__->type$, args);
	if (thisClazz == DirectMethodHandle$Accessor::class$) {
		DirectMethodHandle$Accessor* dmha = $cast(DirectMethodHandle$Accessor, this__);
		return unsafeGet(args->get(0), dmha->fieldOffset, dmha->fieldType);
	}
	if (thisClazz == DirectMethodHandle$StaticAccessor::class$) {
		DirectMethodHandle$StaticAccessor* dmhsa = $cast(DirectMethodHandle$StaticAccessor, this__);
		return unsafeGet(nullptr, dmhsa->staticOffset, dmhsa->fieldType);
	}
	if ($instanceOf<DirectMethodHandle>(this__)) {
		DirectMethodHandle* dmh = $cast(DirectMethodHandle, this__);
		$var($ObjectArray, args2, args);
		//if (needConvertArgs($fcast<MethodType>(dmh->member__->type), args)) {
		//	$assign(args, convertArgs($fcast<MethodType>(dmh->member__->type), args));
		//}
		return invokeBasic0(dmh->member, args2);
	}
	if ($instanceOf<BoundMethodHandle>(this__)) {
		// $var($ObjectArray, args2, $new<$ObjectArray>(args->length + 1));
		// args2->set(0, this__);
		// args2->setArray(1, args, 0, args->length);
		$var($ObjectArray, args2, makeArgs(this__, args));
		return invokeBasic0(this__->form->vmentry, args2);
	}
	if ($instanceOf<DelegatingMethodHandle>(this__)) {
		DelegatingMethodHandle* dmh = $cast<DelegatingMethodHandle>(this__);
	//	$var(::java::lang::invoke::MethodHandle, mh, dmh->getTarget());
		//$var(::java::lang::invoke::MethodHandle, mh, dmh->viewAsType(dmh->type(), true));
		$var(::java::lang::invoke::MemberName, mn, dmh->internalMemberName());
		$var(Class, clazz, mn->getDeclaringClass());
		$var($Array<Class>, ptypes, mn->getParameterTypes());
		$var(String, name, mn->getName());
		$var(Method, method, clazz->getMethodEx(name, ptypes));
		if (method->isStatic()) {
			return (Object*)method->invoke(nullptr, args);
		} else {
			$var(Object, obj, args->get(0));
			$var($ObjectArray, args2, ($ObjectArray*)args->get(1));
			return (Object*)method->invoke(obj, args2);
		}
	//	return mh->invokeExact(obj, args2);
	//	return _Java_java_lang_invoke_MethodHandle_invokeExact(mh, args);
	}
	$throwNew(UnsupportedOperationException, "_Java_java_lang_invoke_MethodHandle_invokeExact"_s);
}

Object* _Java_java_lang_invoke_MethodHandle_linkToInterface($ObjectArray* args) {
	$throwNew(UnsupportedOperationException, "_Java_java_lang_invoke_MethodHandle_linkToInterface"_s);
}

Object* _Java_java_lang_invoke_MethodHandle_linkToNative($ObjectArray* args) {
	$throwNew(UnsupportedOperationException, "_Java_java_lang_invoke_MethodHandle_linkToNative"_s);
}

Object* _Java_java_lang_invoke_MethodHandle_linkToSpecial($ObjectArray* args) {
	$throwNew(UnsupportedOperationException, "_Java_java_lang_invoke_MethodHandle_linkToSpecial"_s);
}

Object* _Java_java_lang_invoke_MethodHandle_linkToStatic($ObjectArray* args) {
	$throwNew(UnsupportedOperationException, "_Java_java_lang_invoke_MethodHandle_linkToStatic"_s);
}

Object* _Java_java_lang_invoke_MethodHandle_linkToVirtual($ObjectArray* args) {
	$throwNew(UnsupportedOperationException, "_Java_java_lang_invoke_MethodHandle_linkToVirtual"_s);
}

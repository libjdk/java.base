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

#ifndef _java_lang_interpreter_ByteCodeClass_h_
#define _java_lang_interpreter_ByteCodeClass_h_

#include <bitset>
#include <condition_variable>
#include <vector>
#include <cassert>
#include <string>

#include <java/lang/Array.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/Class.h>
#include <java/io/InputStream.h>
#include <java/util/ArrayList.h>
#include <java/lang/ClassInfo.h>

#include <jcpp.h>

namespace java {
	namespace lang {
		class ClassLoader;
		class ClassInfo;
		class FieldInfo;
		class InnerClassInfo;
		class EnclosingMethodInfo;
		class CompoundAttribute;
		class TypeAnnotation;
		class NamedAttribute;
		class Attribute;
	}
}
namespace java {
	namespace io {
		class DataInputStream;
	}
}
namespace java {
	namespace util {
		class HashMap;
	}
}

namespace java {
	namespace lang {
		namespace interpreter {

enum class MethodInfoAccessFlags : uint16_t {
    ACC_PUBLIC = 0x0001,
    ACC_PRIVATE = 0x0002,
    ACC_PROTECTED = 0x0004,
    ACC_STATIC = 0x0008,
    ACC_FINAL = 0x0010,
    ACC_SYNCHRONIZED = 0x0020,
    ACC_BRIDGE = 0x0040,
    ACC_VARARGS = 0x0080,
    ACC_NATIVE = 0x0100,
    ACC_ABSTRACT = 0x0400,
    ACC_STRICT = 0x0800,
    ACC_SYNTHETIC = 0x1000,
};

class ExceptionTableEntry {
public:
	uint16_t start_pc;
	uint16_t end_pc;
	uint16_t handler_pc;
	uint16_t catch_type;
};

class ByteCodeMethod : public ::java::lang::Object {
public:
	ByteCodeMethod() {

	}
	void init$() {
		::java::lang::Object::init$();
	}

	::java::lang::String* name = nullptr;
	::java::lang::String* descriptor = nullptr;
	::java::lang::String* signature = nullptr;
	uint16_t accessFlags = 0;

    // Code_attribute begin
	uint16_t max_stack;
	uint16_t max_locals;
	$bytes* code = nullptr;
    std::vector<ExceptionTableEntry> exception_table;
    // Code_attribute end

	// This is called nargs in the invoke* descriptions: https://docs.oracle.com/javase/specs/jvms/se16/html/jvms-6.html#jvms-6.5.invokestatic
	uint8_t parameter_count;
	// Some parameters require 2 local variable slots
	uint16_t stack_slots_for_parameters;

	uint8_t return_category; // 0, 1, 2

	inline bool is_static() const {
		return (accessFlags & static_cast<uint16_t>(MethodInfoAccessFlags::ACC_STATIC)) != 0;
	}
};

class ByteCodeClass;

class VfptrInfo : public ::java::lang::Object {
public:
	VfptrInfo();
	void init$() {}
	void init();
	static bool methodEquals(::java::lang::reflect::Method* m0, ::java::lang::reflect::Method* m1);

	int32_t offset = 0;
	$bytes* vfTableData = nullptr;
	ByteCodeClass* clazz = nullptr;
	$Array<::java::lang::reflect::Method>* forwardMethods = nullptr;
};

class ByteCodeClassData : public ::java::lang::Object {
public:
	void init$();
	void parse($bytes* b, ClassInfo* classInfo);
	void parseFieldAttributes(::java::io::DataInputStream* is, ::java::lang::FieldInfo* fieldInfo);
	void parseMethodAttributes(::java::io::DataInputStream* is, ::java::lang::MethodInfo* methodInfo, ByteCodeMethod* byteCodeMethod);
	void parseMethodCodeAttributes(::java::io::DataInputStream* is, ::java::lang::MethodInfo* methodInfo);
	void parseClassAttributes(::java::io::DataInputStream* is, ClassInfo* classInfo);
	void parseCompoundAttribute(::java::io::DataInputStream* is, CompoundAttribute* compoundAttribute);
	void parseNamedAttribute(::java::io::DataInputStream* is, NamedAttribute* namedAttribute);
	void parseAttribute(::java::io::DataInputStream* is, Attribute* attribute);

	const char* makeCharPtrForClassInfo(::java::lang::String* str);
	FieldInfo* makeFieldInfosForClassInfo(int32_t count);
	MethodInfo* makeMethodInfosForClassInfo(int32_t count);
	InnerClassInfo* makeInnerClassInfosForClassInfo(int32_t count);
	EnclosingMethodInfo* makeEnclosingMethodInfoForClassInfo();
	CompoundAttribute* makeCompoundAttributesForClassInfo(int32_t count);
	CompoundAttribute* makeCompoundAttributeForClassInfo();
	TypeAnnotation* makeAnnotationsForClassInfo(int32_t count);
	NamedAttribute* makeNamedAttributesForClassInfo(int32_t count);
	Attribute* makeAttributesForClassInfo(int32_t count);

	bool overridedFinalize = false;
	bool cloneable = false;
    int clinitIndex = -1;
	::java::util::ArrayList* byteCodeMethods = nullptr;
	::jdk::internal::reflect::ConstantPool* constantPool = nullptr;
	::java::util::HashMap* methodCacheMap = nullptr;
	::java::util::ArrayList* classInfoStore = nullptr;
};

class MethodCache : public ::java::lang::Object {
public:
	::java::lang::Object* method = nullptr;
	$ClassArray* argsTypes = nullptr;
	$Class* realReturnType = nullptr;
	bool hasThisArg();
	void init();

	int32_t realReturnCategory = 0;
	int32_t stackSlotsForArgs = 0;
};

class ByteCodeClass : public ::java::lang::Class {
    $class(ByteCodeClass, $NO_CLASS_INIT, ::java::lang::Class)
public:
	ByteCodeClass();
	void init$();
	static ByteCodeClass* create($bytes* b, int32_t off, int32_t len);

	void init($String* name, ::java::lang::ClassLoader* loader);

	virtual void ensureClassInitialized() override;
	virtual ::jdk::internal::reflect::ConstantPool* getConstantPool0() override;

	void initMethods();
	void initVfTab();

	void assembleVfTab(::java::lang::Object* obj);

	ClassInfo classInfo0;
	::java::util::ArrayList* classInfoStore = nullptr;

	::java::lang::Class* loadClass(::java::lang::String* name);
	ByteCodeClassData* getByteCodeClassData(bool genClassInfo);
	MethodCache* findMethodCache(int32_t methodIndex);

	$ObjectArray* vfptrs = nullptr;
	$volatile(::java::lang::ref::SoftReference*) byteCodeClassData = nullptr;
	$bytes* bytes = nullptr;
	$bytes* staticFieldBuffer = nullptr;
	static ::java::util::ArrayList* parseMethodDescriptor(::java::lang::String* descriptor);

	bool inited = false;
	int32_t classIndex = 0;
	static int32_t lastClassIndex;
};

        } // interpreter
    } // lang
} // java

#endif //_java_lang_interpreter_ByteCodeClass_h_
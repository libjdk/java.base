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

#ifndef _java_lang_Machine_h_
#define _java_lang_Machine_h_

#include <java/lang/Array.h>
#include <java/lang/ClassEntry.h>

namespace java {
	namespace lang {
		class AssertionStatusDirectives;
		class Class;
		class ClassLoader;
		class String;
		class Module;
		class ClassEntry;
		class ClassInfo;
		class MethodInfo;
		class ModuleInfo;
		class ResourceEntry;
		class Library;
		class ThreadGroup;
	}
}
namespace java {
	namespace lang {
		namespace invoke {
			class MethodHandle;
		}
	}
}
namespace java {
	namespace lang {
		namespace module {
			class ModuleFinder;
		}
	}
}
namespace java {
	namespace net {
		class URL;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		class HashMap;
		class Enumeration;
	}
}
namespace java {
	namespace security {
		class ProtectionDomain;
	}
}
namespace jdk {
	namespace internal {
		namespace jimage {
			class RuntimeImageLocation;
		}
	}
}

typedef void (*$LaunchDoInitFunction)();
typedef void (*$LaunchDoMainFunction)($StringArray* args);

namespace java {
    namespace lang {

class Machine {
public:
	static Class* load$(String* name, int32_t flag);

	static bool isInited();
	static void init1();
	static void init2();
	static void init3();
	static void deinit();
	static int launch(int argc, char** argv, int jargc, char** jargv, const char* javaArgPrefix, $LaunchDoInitFunction doInit, $LaunchDoMainFunction doMain);
#ifdef _WIN32
	static int launchw(int jargc, char** jargv, const char* javaArgPrefix, $LaunchDoInitFunction doInit, $LaunchDoMainFunction doMain);
#endif
	static void run(String* mainClass, $StringArray* args);
	static String* getSystemClassPath();

	static bool isObject0(const char* descriptor);

	static ThreadGroup* getMainThreadGroup();

	static void* loadNativeMethod(Class* clazz, MethodInfo* methodInfo);
	static ClassEntry* getClassEntry(String* name);

	static void addLibrary(Library* lib);

	static bool isBuildinLibraryHandle(void* handle);
	static void* findLibraryEntry(void* handle, const char* name, bool force);

	//static void notifyThreadStart();

	static ::java::lang::module::ModuleFinder* getSystemModuleFinder();

	static Class* createPrimitiveClass(const char* name);
	static void initPrimitiveClass(Class* clazz, const char* name);
	static Class* getPrimitiveClass(String* name);

	static Class* tryLoadClass(String* name, bool initialize, ClassLoader* loader);
	static Class* forName0(String* name, bool initialize, ClassLoader* loader, Class* caller);
	static Class* findBootstrapClass(ClassLoader* loader, String* name);
	static Class* findLoadedClass0(ClassLoader* loader, String* name);
	static AssertionStatusDirectives* retrieveDirectives();

	static Class* findArrayClass(Class* componentType);

	static Class* findClass(ClassLoader* loader, String* name);
	static Class* findClass(ClassLoader* loader, String* moduleName, String* className);
	static ::java::net::URL* findResource($String* name);
	static $bytes* findResource($String* libName, $String* name);
	static ::java::util::Enumeration* findResources($String* name);
	static ::jdk::internal::jimage::RuntimeImageLocation* findLocation($String* name);
	static $bytes* getResource0(::jdk::internal::jimage::RuntimeImageLocation* loc);

	static Class* loadClass(String* name, bool initialize, Class** pClazz, int64_t size, int32_t mark, ClassInfo* classInfo, $InitClassFunction initClassFunction, $AllocateInstanceFunction allocateInstanceFunction, $InitInstanceFunction initInstanceFunction, $InvokeSpecialFunction invokeSpecialFunction, $InvokeFunction invokefunction);
	static Class* loadClass(Class** pClazz, int64_t arrayBaseSize, int32_t mark, ClassInfo* classInfo);
	// for simple class that no load$/class$
	static Class* loadClass(String* name, int64_t size, int32_t mark, bool isBaseOfObject);
	static Class* createSubObjectArrayClass(String* name, Class* componentType);
	static Module* createModule(ModuleInfo* moduleInfo, $Array<String>* packageArray);

	static void registerClass(Class* clazz);
	static void ensureInitialized(Class* clazz);

	static Class* defineClass1(ClassLoader* loader, String* name,
		$bytes* b, int32_t off, int32_t len, ::java::security::ProtectionDomain* pd, String* source);

	static Class* defineClass2(ClassLoader* loader, String* name,
		::java::nio::ByteBuffer* b, int32_t off, int32_t len, ::java::security::ProtectionDomain* pd, String* source);

	static Class* defineClass0(ClassLoader* loader, Class* lookup, String* name,
		$bytes* b, int32_t off, int32_t len, ::java::security::ProtectionDomain* pd, bool initialize, int32_t flags, Object$* classData);

	static int32_t arrayDim(String* s);

	static bool isLambdaClass(String* name);
	static String* getLambdaHoder(String* name);
	static bool isLambdaMethod(String* name);

	static ::java::lang::invoke::MethodHandle* makeBootstrapMethodHandle(Class* recordClass, String* methodName);

	static Class* voidClass;
	static Class* booleanClass;
	static Class* byteClass;
	static Class* charClass;
	static Class* shortClass;
	static Class* intClass;
	static Class* longClass;
	static Class* floatClass;
	static Class* doubleClass;

protected:
	static Class* loadClassInternal(String* name, ClassLoader* loader);
	static Class* loadArrayClassInternal(String* name, ClassLoader* loader);
	static Module* findModule(Class* clazz);

private:
	static bool inited;

	static Object0* lockObject;
	static ::java::util::HashMap* registerClasses;
	static ::java::util::HashMap* simpleClasses;
};

    } // lang
} // java

#endif // _java_lang_Machine_h_
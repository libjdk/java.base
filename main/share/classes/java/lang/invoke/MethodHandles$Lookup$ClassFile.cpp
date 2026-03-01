#include <java/lang/invoke/MethodHandles$Lookup$ClassFile.h>

#include <java/lang/ClassFormatError.h>
#include <java/lang/UnsupportedClassVersionError.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/org/objectweb/asm/ClassReader.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <jcpp.h>

#undef ACC_MODULE

using $ClassFormatError = ::java::lang::ClassFormatError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedClassVersionError = ::java::lang::UnsupportedClassVersionError;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $VM = ::jdk::internal::misc::VM;
using $ClassReader = ::jdk::internal::org::objectweb::asm$::ClassReader;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;

namespace java {
	namespace lang {
		namespace invoke {

$FieldInfo _MethodHandles$Lookup$ClassFile_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $FINAL, $field(MethodHandles$Lookup$ClassFile, name)},
	{"accessFlags", "I", nullptr, $FINAL, $field(MethodHandles$Lookup$ClassFile, accessFlags)},
	{"bytes", "[B", nullptr, $FINAL, $field(MethodHandles$Lookup$ClassFile, bytes)},
	{}
};

$MethodInfo _MethodHandles$Lookup$ClassFile_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I[B)V", nullptr, 0, $method(MethodHandles$Lookup$ClassFile, init$, void, $String*, int32_t, $bytes*)},
	{"newInstance", "([BLjava/lang/String;)Ljava/lang/invoke/MethodHandles$Lookup$ClassFile;", nullptr, $STATIC, $staticMethod(MethodHandles$Lookup$ClassFile, newInstance, MethodHandles$Lookup$ClassFile*, $bytes*, $String*)},
	{"newInstanceNoCheck", "(Ljava/lang/String;[B)Ljava/lang/invoke/MethodHandles$Lookup$ClassFile;", nullptr, $STATIC, $staticMethod(MethodHandles$Lookup$ClassFile, newInstanceNoCheck, MethodHandles$Lookup$ClassFile*, $String*, $bytes*)},
	{"readInt", "([BI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandles$Lookup$ClassFile, readInt, int32_t, $bytes*, int32_t)},
	{"readUnsignedShort", "([BI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(MethodHandles$Lookup$ClassFile, readUnsignedShort, int32_t, $bytes*, int32_t)},
	{}
};

$InnerClassInfo _MethodHandles$Lookup$ClassFile_InnerClassesInfo_[] = {
	{"java.lang.invoke.MethodHandles$Lookup", "java.lang.invoke.MethodHandles", "Lookup", $PUBLIC | $STATIC | $FINAL},
	{"java.lang.invoke.MethodHandles$Lookup$ClassFile", "java.lang.invoke.MethodHandles$Lookup", "ClassFile", $STATIC},
	{}
};

$ClassInfo _MethodHandles$Lookup$ClassFile_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.invoke.MethodHandles$Lookup$ClassFile",
	"java.lang.Object",
	nullptr,
	_MethodHandles$Lookup$ClassFile_FieldInfo_,
	_MethodHandles$Lookup$ClassFile_MethodInfo_,
	nullptr,
	nullptr,
	_MethodHandles$Lookup$ClassFile_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.invoke.MethodHandles"
};

$Object* allocate$MethodHandles$Lookup$ClassFile($Class* clazz) {
	return $of($alloc(MethodHandles$Lookup$ClassFile));
}

void MethodHandles$Lookup$ClassFile::init$($String* name, int32_t accessFlags, $bytes* bytes) {
	$set(this, name, name);
	this->accessFlags = accessFlags;
	$set(this, bytes, bytes);
}

MethodHandles$Lookup$ClassFile* MethodHandles$Lookup$ClassFile::newInstanceNoCheck($String* name, $bytes* bytes) {
	return $new(MethodHandles$Lookup$ClassFile, name, 0, bytes);
}

MethodHandles$Lookup$ClassFile* MethodHandles$Lookup$ClassFile::newInstance($bytes* bytes, $String* pkgName) {
	$useLocalCurrentObjectStackCache();
	int32_t magic = readInt(bytes, 0);
	if (magic != (int32_t)0xCAFEBABE) {
		$throwNew($ClassFormatError, $$str({"Incompatible magic value: "_s, $$str(magic)}));
	}
	int32_t minor = readUnsignedShort(bytes, 4);
	int32_t major = readUnsignedShort(bytes, 6);
	if (!$VM::isSupportedClassFileVersion(major, minor)) {
		$throwNew($UnsupportedClassVersionError, $$str({"Unsupported class file version "_s, $$str(major), "."_s, $$str(minor)}));
	}
	$var($String, name, nullptr);
	int32_t accessFlags = 0;
	try {
		$var($ClassReader, reader, $new($ClassReader, bytes));
		int32_t thisClass = reader->readUnsignedShort(reader->header + 2);
		$var($Object, constant, reader->readConst(thisClass, $$new($chars, reader->getMaxStringLength())));
		$var($Type, type, nullptr);
		bool var$0 = $instanceOf($Type, constant);
		if (var$0) {
			$assign(type, $cast($Type, constant));
			var$0 = true;
		}
		if (!(var$0)) {
			$throwNew($ClassFormatError, $$str({"this_class item: #"_s, $$str(thisClass), " not a CONSTANT_Class_info"_s}));
		}
		if (!$nc($($nc(type)->getDescriptor()))->startsWith("L"_s)) {
			$throwNew($ClassFormatError, $$str({"this_class item: #"_s, $$str(thisClass), " not a CONSTANT_Class_info"_s}));
		}
		$assign(name, $nc(type)->getClassName());
		accessFlags = reader->readUnsignedShort(reader->header);
	} catch ($RuntimeException& e) {
		$var($ClassFormatError, cfe, $new($ClassFormatError));
		cfe->initCause(e);
		$throw(cfe);
	}
	if (((int32_t)(accessFlags & (uint32_t)$Opcodes::ACC_MODULE)) != 0) {
		$throw($($MethodHandleStatics::newIllegalArgumentException("Not a class or interface: ACC_MODULE flag is set"_s)));
	}
	int32_t index = $nc(name)->lastIndexOf((int32_t)u'.');
	$var($String, pn, (index == -1) ? ""_s : name->substring(0, index));
	if (!$nc(pn)->equals(pkgName)) {
		$throw($($MethodHandleStatics::newIllegalArgumentException($$str({name, " not in same package as lookup class"_s}))));
	}
	return $new(MethodHandles$Lookup$ClassFile, name, accessFlags, bytes);
}

int32_t MethodHandles$Lookup$ClassFile::readInt($bytes* bytes, int32_t offset) {
	if ((offset + 4) > $nc(bytes)->length) {
		$throwNew($ClassFormatError, "Invalid ClassFile structure"_s);
	}
	return (((((int32_t)($nc(bytes)->get(offset) & (uint32_t)255)) << 24) | (((int32_t)(bytes->get(offset + 1) & (uint32_t)255)) << 16)) | (((int32_t)(bytes->get(offset + 2) & (uint32_t)255)) << 8)) | ((int32_t)(bytes->get(offset + 3) & (uint32_t)255));
}

int32_t MethodHandles$Lookup$ClassFile::readUnsignedShort($bytes* bytes, int32_t offset) {
	if ((offset + 2) > $nc(bytes)->length) {
		$throwNew($ClassFormatError, "Invalid ClassFile structure"_s);
	}
	return (((int32_t)($nc(bytes)->get(offset) & (uint32_t)255)) << 8) | ((int32_t)(bytes->get(offset + 1) & (uint32_t)255));
}

MethodHandles$Lookup$ClassFile::MethodHandles$Lookup$ClassFile() {
}

$Class* MethodHandles$Lookup$ClassFile::load$($String* name, bool initialize) {
	$loadClass(MethodHandles$Lookup$ClassFile, name, initialize, &_MethodHandles$Lookup$ClassFile_ClassInfo_, allocate$MethodHandles$Lookup$ClassFile);
	return class$;
}

$Class* MethodHandles$Lookup$ClassFile::class$ = nullptr;

		} // invoke
	} // lang
} // java
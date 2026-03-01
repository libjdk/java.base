#include <jdk/internal/org/objectweb/asm/commons/ModuleHashesAttribute.h>

#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jdk/internal/org/objectweb/asm/Attribute.h>
#include <jdk/internal/org/objectweb/asm/ByteVector.h>
#include <jdk/internal/org/objectweb/asm/ClassReader.h>
#include <jdk/internal/org/objectweb/asm/ClassWriter.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jcpp.h>

using $LabelArray = $Array<::jdk::internal::org::objectweb::asm$::Label>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Attribute = ::jdk::internal::org::objectweb::asm$::Attribute;
using $ByteVector = ::jdk::internal::org::objectweb::asm$::ByteVector;
using $ClassReader = ::jdk::internal::org::objectweb::asm$::ClassReader;
using $ClassWriter = ::jdk::internal::org::objectweb::asm$::ClassWriter;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace commons {

$FieldInfo _ModuleHashesAttribute_FieldInfo_[] = {
	{"algorithm", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ModuleHashesAttribute, algorithm)},
	{"modules", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $field(ModuleHashesAttribute, modules)},
	{"hashes", "Ljava/util/List;", "Ljava/util/List<[B>;", $PUBLIC, $field(ModuleHashesAttribute, hashes)},
	{}
};

$MethodInfo _ModuleHashesAttribute_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/List;Ljava/util/List;)V", "(Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;Ljava/util/List<[B>;)V", $PUBLIC, $method(ModuleHashesAttribute, init$, void, $String*, $List*, $List*)},
	{"<init>", "()V", nullptr, $PUBLIC, $method(ModuleHashesAttribute, init$, void)},
	{"read", "(Ljdk/internal/org/objectweb/asm/ClassReader;II[CI[Ljdk/internal/org/objectweb/asm/Label;)Ljdk/internal/org/objectweb/asm/Attribute;", nullptr, $PROTECTED, $virtualMethod(ModuleHashesAttribute, read, $Attribute*, $ClassReader*, int32_t, int32_t, $chars*, int32_t, $LabelArray*)},
	{"write", "(Ljdk/internal/org/objectweb/asm/ClassWriter;[BIII)Ljdk/internal/org/objectweb/asm/ByteVector;", nullptr, $PROTECTED, $virtualMethod(ModuleHashesAttribute, write, $ByteVector*, $ClassWriter*, $bytes*, int32_t, int32_t, int32_t)},
	{}
};

$ClassInfo _ModuleHashesAttribute_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.commons.ModuleHashesAttribute",
	"jdk.internal.org.objectweb.asm.Attribute",
	nullptr,
	_ModuleHashesAttribute_FieldInfo_,
	_ModuleHashesAttribute_MethodInfo_
};

$Object* allocate$ModuleHashesAttribute($Class* clazz) {
	return $of($alloc(ModuleHashesAttribute));
}

void ModuleHashesAttribute::init$($String* algorithm, $List* modules, $List* hashes) {
	$Attribute::init$("ModuleHashes"_s);
	$set(this, algorithm, algorithm);
	$set(this, modules, modules);
	$set(this, hashes, hashes);
}

void ModuleHashesAttribute::init$() {
	ModuleHashesAttribute::init$(nullptr, nullptr, nullptr);
}

$Attribute* ModuleHashesAttribute::read($ClassReader* classReader, int32_t offset, int32_t length, $chars* charBuffer, int32_t codeAttributeOffset, $LabelArray* labels) {
	$useLocalCurrentObjectStackCache();
	int32_t currentOffset = offset;
	$var($String, hashAlgorithm, $nc(classReader)->readUTF8(currentOffset, charBuffer));
	currentOffset += 2;
	int32_t numModules = classReader->readUnsignedShort(currentOffset);
	currentOffset += 2;
	$var($ArrayList, moduleList, $new($ArrayList, numModules));
	$var($ArrayList, hashList, $new($ArrayList, numModules));
	for (int32_t i = 0; i < numModules; ++i) {
		$var($String, module, classReader->readModule(currentOffset, charBuffer));
		currentOffset += 2;
		moduleList->add(module);
		int32_t hashLength = classReader->readUnsignedShort(currentOffset);
		currentOffset += 2;
		$var($bytes, hash, $new($bytes, hashLength));
		for (int32_t j = 0; j < hashLength; ++j) {
			hash->set(j, (int8_t)((int32_t)(classReader->readByte(currentOffset) & (uint32_t)255)));
			currentOffset += 1;
		}
		hashList->add(hash);
	}
	return $new(ModuleHashesAttribute, hashAlgorithm, moduleList, hashList);
}

$ByteVector* ModuleHashesAttribute::write($ClassWriter* classWriter, $bytes* code, int32_t codeLength, int32_t maxStack, int32_t maxLocals) {
	$useLocalCurrentObjectStackCache();
	$var($ByteVector, byteVector, $new($ByteVector));
	byteVector->putShort($nc(classWriter)->newUTF8(this->algorithm));
	if (this->modules == nullptr) {
		byteVector->putShort(0);
	} else {
		int32_t numModules = $nc(this->modules)->size();
		byteVector->putShort(numModules);
		for (int32_t i = 0; i < numModules; ++i) {
			$var($String, module, $cast($String, $nc(this->modules)->get(i)));
			$var($bytes, hash, $cast($bytes, $nc(this->hashes)->get(i)));
			$nc($($nc($(byteVector->putShort($nc(classWriter)->newModule(module))))->putShort($nc(hash)->length)))->putByteArray(hash, 0, $nc(hash)->length);
		}
	}
	return byteVector;
}

ModuleHashesAttribute::ModuleHashesAttribute() {
}

$Class* ModuleHashesAttribute::load$($String* name, bool initialize) {
	$loadClass(ModuleHashesAttribute, name, initialize, &_ModuleHashesAttribute_ClassInfo_, allocate$ModuleHashesAttribute);
	return class$;
}

$Class* ModuleHashesAttribute::class$ = nullptr;

					} // commons
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk
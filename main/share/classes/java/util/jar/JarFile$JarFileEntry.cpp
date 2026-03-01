#include <java/util/jar/JarFile$JarFileEntry.h>

#include <java/io/IOException.h>
#include <java/security/CodeSigner.h>
#include <java/security/cert/Certificate.h>
#include <java/util/jar/Attributes.h>
#include <java/util/jar/JarEntry.h>
#include <java/util/jar/JarFile.h>
#include <java/util/jar/JarVerifier.h>
#include <java/util/jar/Manifest.h>
#include <java/util/zip/ZipEntry.h>
#include <jcpp.h>

#undef BASE_VERSION_FEATURE

using $CodeSignerArray = $Array<::java::security::CodeSigner>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Attributes = ::java::util::jar::Attributes;
using $JarEntry = ::java::util::jar::JarEntry;
using $JarFile = ::java::util::jar::JarFile;
using $JarVerifier = ::java::util::jar::JarVerifier;
using $Manifest = ::java::util::jar::Manifest;
using $ZipEntry = ::java::util::zip::ZipEntry;

namespace java {
	namespace util {
		namespace jar {

$FieldInfo _JarFile$JarFileEntry_FieldInfo_[] = {
	{"this$0", "Ljava/util/jar/JarFile;", nullptr, $FINAL | $SYNTHETIC, $field(JarFile$JarFileEntry, this$0)},
	{"basename", "Ljava/lang/String;", nullptr, $PRIVATE, $field(JarFile$JarFileEntry, basename)},
	{}
};

$MethodInfo _JarFile$JarFileEntry_MethodInfo_[] = {
	{"<init>", "(Ljava/util/jar/JarFile;Ljava/lang/String;)V", nullptr, 0, $method(JarFile$JarFileEntry, init$, void, $JarFile*, $String*)},
	{"<init>", "(Ljava/util/jar/JarFile;Ljava/lang/String;Ljava/util/zip/ZipEntry;)V", nullptr, 0, $method(JarFile$JarFileEntry, init$, void, $JarFile*, $String*, $ZipEntry*)},
	{"getAttributes", "()Ljava/util/jar/Attributes;", nullptr, $PUBLIC, $virtualMethod(JarFile$JarFileEntry, getAttributes, $Attributes*), "java.io.IOException"},
	{"getCertificates", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, $virtualMethod(JarFile$JarFileEntry, getCertificates, $CertificateArray*)},
	{"getCodeSigners", "()[Ljava/security/CodeSigner;", nullptr, $PUBLIC, $virtualMethod(JarFile$JarFileEntry, getCodeSigners, $CodeSignerArray*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JarFile$JarFileEntry, getName, $String*)},
	{"getRealName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JarFile$JarFileEntry, getRealName, $String*)},
	{"realEntry", "()Ljava/util/jar/JarFile$JarFileEntry;", nullptr, 0, $virtualMethod(JarFile$JarFileEntry, realEntry, JarFile$JarFileEntry*)},
	{"withBasename", "(Ljava/lang/String;)Ljava/util/jar/JarFile$JarFileEntry;", nullptr, 0, $virtualMethod(JarFile$JarFileEntry, withBasename, JarFile$JarFileEntry*, $String*)},
	{}
};

$InnerClassInfo _JarFile$JarFileEntry_InnerClassesInfo_[] = {
	{"java.util.jar.JarFile$JarFileEntry", "java.util.jar.JarFile", "JarFileEntry", $PRIVATE},
	{}
};

$ClassInfo _JarFile$JarFileEntry_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.jar.JarFile$JarFileEntry",
	"java.util.jar.JarEntry",
	nullptr,
	_JarFile$JarFileEntry_FieldInfo_,
	_JarFile$JarFileEntry_MethodInfo_,
	nullptr,
	nullptr,
	_JarFile$JarFileEntry_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.jar.JarFile"
};

$Object* allocate$JarFile$JarFileEntry($Class* clazz) {
	return $of($alloc(JarFile$JarFileEntry));
}

void JarFile$JarFileEntry::init$($JarFile* this$0, $String* name) {
	$set(this, this$0, this$0);
	$JarEntry::init$(name);
	$set(this, basename, name);
}

void JarFile$JarFileEntry::init$($JarFile* this$0, $String* name, $ZipEntry* vze) {
	$set(this, this$0, this$0);
	$JarEntry::init$(vze);
	$set(this, basename, name);
}

$Attributes* JarFile$JarFileEntry::getAttributes() {
	$useLocalCurrentObjectStackCache();
	$var($Manifest, man, this->this$0->getManifest());
	if (man != nullptr) {
		return man->getAttributes($($JarEntry::getName()));
	} else {
		return nullptr;
	}
}

$CertificateArray* JarFile$JarFileEntry::getCertificates() {
	try {
		this->this$0->maybeInstantiateVerifier();
	} catch ($IOException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	if (this->certs == nullptr && this->this$0->jv != nullptr) {
		$set(this, certs, $nc(this->this$0->jv)->getCerts(this->this$0, $(realEntry())));
	}
	return this->certs == nullptr ? ($CertificateArray*)nullptr : $cast($CertificateArray, $nc(this->certs)->clone());
}

$CodeSignerArray* JarFile$JarFileEntry::getCodeSigners() {
	try {
		this->this$0->maybeInstantiateVerifier();
	} catch ($IOException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	if (this->signers == nullptr && this->this$0->jv != nullptr) {
		$set(this, signers, $nc(this->this$0->jv)->getCodeSigners(this->this$0, $(realEntry())));
	}
	return this->signers == nullptr ? ($CodeSignerArray*)nullptr : $cast($CodeSignerArray, $nc(this->signers)->clone());
}

$String* JarFile$JarFileEntry::getRealName() {
	return $JarEntry::getName();
}

$String* JarFile$JarFileEntry::getName() {
	return this->basename;
}

JarFile$JarFileEntry* JarFile$JarFileEntry::realEntry() {
	$init($JarFile);
	if (this->this$0->isMultiRelease() && this->this$0->versionFeature != $JarFile::BASE_VERSION_FEATURE) {
		$var($String, entryName, $JarEntry::getName());
		return entryName == this->basename || $nc(entryName)->equals(this->basename) ? this : $new(JarFile$JarFileEntry, this->this$0, entryName, this);
	}
	return this;
}

JarFile$JarFileEntry* JarFile$JarFileEntry::withBasename($String* name) {
	$set(this, basename, name);
	return this;
}

JarFile$JarFileEntry::JarFile$JarFileEntry() {
}

$Class* JarFile$JarFileEntry::load$($String* name, bool initialize) {
	$loadClass(JarFile$JarFileEntry, name, initialize, &_JarFile$JarFileEntry_ClassInfo_, allocate$JarFile$JarFileEntry);
	return class$;
}

$Class* JarFile$JarFileEntry::class$ = nullptr;

		} // jar
	} // util
} // java
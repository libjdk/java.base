#include <java/util/jar/JarOutputStream.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/util/jar/JarFile.h>
#include <java/util/jar/Manifest.h>
#include <java/util/zip/ZipEntry.h>
#include <java/util/zip/ZipOutputStream.h>
#include <jcpp.h>

#undef JAR_MAGIC
#undef MANIFEST_NAME

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $JarFile = ::java::util::jar::JarFile;
using $Manifest = ::java::util::jar::Manifest;
using $ZipEntry = ::java::util::zip::ZipEntry;
using $ZipOutputStream = ::java::util::zip::ZipOutputStream;

namespace java {
	namespace util {
		namespace jar {

$FieldInfo _JarOutputStream_FieldInfo_[] = {
	{"JAR_MAGIC", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(JarOutputStream, JAR_MAGIC)},
	{"firstEntry", "Z", nullptr, $PRIVATE, $field(JarOutputStream, firstEntry)},
	{}
};

$MethodInfo _JarOutputStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;Ljava/util/jar/Manifest;)V", nullptr, $PUBLIC, $method(JarOutputStream, init$, void, $OutputStream*, $Manifest*), "java.io.IOException"},
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(JarOutputStream, init$, void, $OutputStream*), "java.io.IOException"},
	{"get16", "([BI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(JarOutputStream, get16, int32_t, $bytes*, int32_t)},
	{"hasMagic", "([B)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(JarOutputStream, hasMagic, bool, $bytes*)},
	{"putNextEntry", "(Ljava/util/zip/ZipEntry;)V", nullptr, $PUBLIC, $virtualMethod(JarOutputStream, putNextEntry, void, $ZipEntry*), "java.io.IOException"},
	{"set16", "([BII)V", nullptr, $PRIVATE | $STATIC, $staticMethod(JarOutputStream, set16, void, $bytes*, int32_t, int32_t)},
	{}
};

$ClassInfo _JarOutputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.jar.JarOutputStream",
	"java.util.zip.ZipOutputStream",
	nullptr,
	_JarOutputStream_FieldInfo_,
	_JarOutputStream_MethodInfo_
};

$Object* allocate$JarOutputStream($Class* clazz) {
	return $of($alloc(JarOutputStream));
}

void JarOutputStream::init$($OutputStream* out, $Manifest* man) {
	$useLocalCurrentObjectStackCache();
	$ZipOutputStream::init$(out);
	this->firstEntry = true;
	if (man == nullptr) {
		$throwNew($NullPointerException, "man"_s);
	}
	$init($JarFile);
	$var($ZipEntry, e, $new($ZipEntry, $JarFile::MANIFEST_NAME));
	putNextEntry(e);
	$nc(man)->write($$new($BufferedOutputStream, this));
	closeEntry();
}

void JarOutputStream::init$($OutputStream* out) {
	$ZipOutputStream::init$(out);
	this->firstEntry = true;
}

void JarOutputStream::putNextEntry($ZipEntry* ze) {
	$useLocalCurrentObjectStackCache();
	if (this->firstEntry) {
		$var($bytes, edata, $nc(ze)->getExtra());
		if (edata == nullptr || !hasMagic(edata)) {
			if (edata == nullptr) {
				$assign(edata, $new($bytes, 4));
			} else {
				$var($bytes, tmp, $new($bytes, $nc(edata)->length + 4));
				$System::arraycopy(edata, 0, tmp, 4, edata->length);
				$assign(edata, tmp);
			}
			set16(edata, 0, JarOutputStream::JAR_MAGIC);
			set16(edata, 2, 0);
			ze->setExtra(edata);
		}
		this->firstEntry = false;
	}
	$ZipOutputStream::putNextEntry(ze);
}

bool JarOutputStream::hasMagic($bytes* edata) {
	$init(JarOutputStream);
	try {
		int32_t i = 0;
		while (i < $nc(edata)->length) {
			if (get16(edata, i) == JarOutputStream::JAR_MAGIC) {
				return true;
			}
			i += get16(edata, i + 2) + 4;
		}
	} catch ($ArrayIndexOutOfBoundsException& e) {
	}
	return false;
}

int32_t JarOutputStream::get16($bytes* b, int32_t off) {
	$init(JarOutputStream);
	int32_t var$0 = $Byte::toUnsignedInt($nc(b)->get(off));
	return var$0 | ($Byte::toUnsignedInt($nc(b)->get(off + 1)) << 8);
}

void JarOutputStream::set16($bytes* b, int32_t off, int32_t value) {
	$init(JarOutputStream);
	$nc(b)->set(off + 0, (int8_t)value);
	b->set(off + 1, (int8_t)(value >> 8));
}

JarOutputStream::JarOutputStream() {
}

$Class* JarOutputStream::load$($String* name, bool initialize) {
	$loadClass(JarOutputStream, name, initialize, &_JarOutputStream_ClassInfo_, allocate$JarOutputStream);
	return class$;
}

$Class* JarOutputStream::class$ = nullptr;

		} // jar
	} // util
} // java
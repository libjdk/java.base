#include <java/util/zip/ZipFile$Source.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/RandomAccessFile.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Math.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/InvalidPathException.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Locale.h>
#include <java/util/Set.h>
#include <java/util/TreeSet.h>
#include <java/util/zip/ZipCoder$UTF8ZipCoder.h>
#include <java/util/zip/ZipCoder.h>
#include <java/util/zip/ZipException.h>
#include <java/util/zip/ZipFile$Source$End.h>
#include <java/util/zip/ZipFile$Source$Key.h>
#include <java/util/zip/ZipFile.h>
#include <java/util/zip/ZipUtils.h>
#include <jdk/internal/access/JavaIORandomAccessFileAccess.h>
#include <jdk/internal/access/JavaUtilJarAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <sun/nio/cs/UTF_8.h>
#include <sun/security/util/SignatureFileVerifier.h>
#include <jcpp.h>

#undef BUF_SIZE
#undef EMPTY_META_VERSIONS
#undef ENGLISH
#undef INSTANCE
#undef JUJA
#undef META_INF_LEN
#undef N
#undef UTF8
#undef ZIP_ENDCHAIN

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $RandomAccessFile = ::java::io::RandomAccessFile;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $Files = ::java::nio::file::Files;
using $InvalidPathException = ::java::nio::file::InvalidPathException;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $Set = ::java::util::Set;
using $TreeSet = ::java::util::TreeSet;
using $ZipCoder = ::java::util::zip::ZipCoder;
using $ZipException = ::java::util::zip::ZipException;
using $ZipFile = ::java::util::zip::ZipFile;
using $ZipFile$Source$End = ::java::util::zip::ZipFile$Source$End;
using $ZipFile$Source$Key = ::java::util::zip::ZipFile$Source$Key;
using $ZipUtils = ::java::util::zip::ZipUtils;
using $JavaIORandomAccessFileAccess = ::jdk::internal::access::JavaIORandomAccessFileAccess;
using $JavaUtilJarAccess = ::jdk::internal::access::JavaUtilJarAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $UTF_8 = ::sun::nio::cs::UTF_8;
using $SignatureFileVerifier = ::sun::security::util::SignatureFileVerifier;

namespace java {
	namespace util {
		namespace zip {

$CompoundAttribute _ZipFile$Source_FieldAnnotations_zc[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _ZipFile$Source_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ZipFile$Source, $assertionsDisabled)},
	{"JUJA", "Ljdk/internal/access/JavaUtilJarAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZipFile$Source, JUJA)},
	{"META_INF_LEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZipFile$Source, META_INF_LEN)},
	{"EMPTY_META_VERSIONS", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ZipFile$Source, EMPTY_META_VERSIONS)},
	{"key", "Ljava/util/zip/ZipFile$Source$Key;", nullptr, $PRIVATE | $FINAL, $field(ZipFile$Source, key)},
	{"zc", "Ljava/util/zip/ZipCoder;", nullptr, $PRIVATE | $FINAL, $field(ZipFile$Source, zc), _ZipFile$Source_FieldAnnotations_zc},
	{"refs", "I", nullptr, $PRIVATE, $field(ZipFile$Source, refs)},
	{"zfile", "Ljava/io/RandomAccessFile;", nullptr, $PRIVATE, $field(ZipFile$Source, zfile)},
	{"cen", "[B", nullptr, $PRIVATE, $field(ZipFile$Source, cen)},
	{"locpos", "J", nullptr, $PRIVATE, $field(ZipFile$Source, locpos)},
	{"comment", "[B", nullptr, $PRIVATE, $field(ZipFile$Source, comment)},
	{"manifestPos", "I", nullptr, $PRIVATE, $field(ZipFile$Source, manifestPos)},
	{"manifestNum", "I", nullptr, $PRIVATE, $field(ZipFile$Source, manifestNum)},
	{"signatureMetaNames", "[I", nullptr, $PRIVATE, $field(ZipFile$Source, signatureMetaNames)},
	{"metaVersions", "[I", nullptr, $PRIVATE, $field(ZipFile$Source, metaVersions)},
	{"startsWithLoc", "Z", nullptr, $PRIVATE | $FINAL, $field(ZipFile$Source, startsWithLoc)},
	{"entries", "[I", nullptr, $PRIVATE, $field(ZipFile$Source, entries)},
	{"ZIP_ENDCHAIN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZipFile$Source, ZIP_ENDCHAIN)},
	{"total", "I", nullptr, $PRIVATE, $field(ZipFile$Source, total)},
	{"table", "[I", nullptr, $PRIVATE, $field(ZipFile$Source, table)},
	{"tablelen", "I", nullptr, $PRIVATE, $field(ZipFile$Source, tablelen)},
	{"files", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/util/zip/ZipFile$Source$Key;Ljava/util/zip/ZipFile$Source;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ZipFile$Source, files)},
	{"BUF_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZipFile$Source, BUF_SIZE)},
	{}
};

$MethodInfo _ZipFile$Source_MethodInfo_[] = {
	{"<init>", "(Ljava/util/zip/ZipFile$Source$Key;ZLjava/util/zip/ZipCoder;)V", nullptr, $PRIVATE, $method(ZipFile$Source, init$, void, $ZipFile$Source$Key*, bool, $ZipCoder*), "java.io.IOException"},
	{"checkAndAddEntry", "(II)I", nullptr, $PRIVATE, $method(ZipFile$Source, checkAndAddEntry, int32_t, int32_t, int32_t), "java.util.zip.ZipException"},
	{"close", "()V", nullptr, $PRIVATE, $method(ZipFile$Source, close, void), "java.io.IOException"},
	{"countCENHeaders", "([BI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(ZipFile$Source, countCENHeaders, int32_t, $bytes*, int32_t)},
	{"findEND", "()Ljava/util/zip/ZipFile$Source$End;", nullptr, $PRIVATE, $method(ZipFile$Source, findEND, $ZipFile$Source$End*), "java.io.IOException"},
	{"get", "(Ljava/io/File;ZLjava/util/zip/ZipCoder;)Ljava/util/zip/ZipFile$Source;", nullptr, $STATIC, $staticMethod(ZipFile$Source, get, ZipFile$Source*, $File*, bool, $ZipCoder*), "java.io.IOException"},
	{"getEntryHash", "(I)I", nullptr, $PRIVATE, $method(ZipFile$Source, getEntryHash, int32_t, int32_t)},
	{"getEntryNext", "(I)I", nullptr, $PRIVATE, $method(ZipFile$Source, getEntryNext, int32_t, int32_t)},
	{"getEntryPos", "(I)I", nullptr, $PRIVATE, $method(ZipFile$Source, getEntryPos, int32_t, int32_t)},
	{"getEntryPos", "(Ljava/lang/String;Z)I", nullptr, $PRIVATE, $method(ZipFile$Source, getEntryPos, int32_t, $String*, bool)},
	{"getMetaVersion", "(II)I", nullptr, $PRIVATE, $method(ZipFile$Source, getMetaVersion, int32_t, int32_t, int32_t)},
	{"initCEN", "(I)V", nullptr, $PRIVATE, $method(ZipFile$Source, initCEN, void, int32_t), "java.io.IOException"},
	{"isManifestName", "(II)Z", nullptr, $PRIVATE, $method(ZipFile$Source, isManifestName, bool, int32_t, int32_t)},
	{"isMetaName", "([BII)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ZipFile$Source, isMetaName, bool, $bytes*, int32_t, int32_t)},
	{"isSignatureRelated", "(II)Z", nullptr, $PRIVATE, $method(ZipFile$Source, isSignatureRelated, bool, int32_t, int32_t)},
	{"nextEntryPos", "(III)I", nullptr, $PRIVATE, $method(ZipFile$Source, nextEntryPos, int32_t, int32_t, int32_t, int32_t)},
	{"readAt", "([BIIJ)I", nullptr, $PRIVATE | $FINAL, $method(ZipFile$Source, readAt, int32_t, $bytes*, int32_t, int32_t, int64_t), "java.io.IOException"},
	{"readFullyAt", "([BIIJ)I", nullptr, $PRIVATE | $FINAL, $method(ZipFile$Source, readFullyAt, int32_t, $bytes*, int32_t, int32_t, int64_t), "java.io.IOException"},
	{"release", "(Ljava/util/zip/ZipFile$Source;)V", nullptr, $STATIC, $staticMethod(ZipFile$Source, release, void, ZipFile$Source*), "java.io.IOException"},
	{"zerror", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(ZipFile$Source, zerror, void, $String*), "java.util.zip.ZipException"},
	{"zipCoderForPos", "(I)Ljava/util/zip/ZipCoder;", nullptr, $PRIVATE, $method(ZipFile$Source, zipCoderForPos, $ZipCoder*, int32_t)},
	{}
};

$InnerClassInfo _ZipFile$Source_InnerClassesInfo_[] = {
	{"java.util.zip.ZipFile$Source", "java.util.zip.ZipFile", "Source", $PRIVATE | $STATIC},
	{"java.util.zip.ZipFile$Source$End", "java.util.zip.ZipFile$Source", "End", $PRIVATE | $STATIC},
	{"java.util.zip.ZipFile$Source$Key", "java.util.zip.ZipFile$Source", "Key", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ZipFile$Source_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.zip.ZipFile$Source",
	"java.lang.Object",
	nullptr,
	_ZipFile$Source_FieldInfo_,
	_ZipFile$Source_MethodInfo_,
	nullptr,
	nullptr,
	_ZipFile$Source_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.zip.ZipFile"
};

$Object* allocate$ZipFile$Source($Class* clazz) {
	return $of($alloc(ZipFile$Source));
}

bool ZipFile$Source::$assertionsDisabled = false;
$JavaUtilJarAccess* ZipFile$Source::JUJA = nullptr;
$ints* ZipFile$Source::EMPTY_META_VERSIONS = nullptr;
$HashMap* ZipFile$Source::files = nullptr;

int32_t ZipFile$Source::checkAndAddEntry(int32_t pos, int32_t index) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, cen, this->cen);
	if ($ZipUtils::CENSIG(cen, pos) != (int64_t)33639248) {
		zerror("invalid CEN header (bad signature)"_s);
	}
	int32_t method = $ZipUtils::CENHOW(cen, pos);
	int32_t flag = $ZipUtils::CENFLG(cen, pos);
	if (((int32_t)(flag & (uint32_t)1)) != 0) {
		zerror("invalid CEN header (encrypted entry)"_s);
	}
	if (method != 0 && method != 8) {
		zerror($$str({"invalid CEN header (bad compression method: "_s, $$str(method), ")"_s}));
	}
	int32_t entryPos = pos + 46;
	int32_t nlen = $ZipUtils::CENNAM(cen, pos);
	if (entryPos + nlen > $nc(cen)->length - 22) {
		zerror("invalid CEN header (bad header size)"_s);
	}
	try {
		$var($ZipCoder, zcp, zipCoderForPos(pos));
		int32_t hash = $nc(zcp)->checkedHash(cen, entryPos, nlen);
		int32_t hsh = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), this->tablelen);
		int32_t next = $nc(this->table)->get(hsh);
		$nc(this->table)->set(hsh, index);
		$nc(this->entries)->set(index++, hash);
		$nc(this->entries)->set(index++, next);
		$nc(this->entries)->set(index, pos);
	} catch ($Exception& e) {
		zerror("invalid CEN header (bad entry name)"_s);
	}
	return nlen;
}

int32_t ZipFile$Source::getEntryHash(int32_t index) {
	return $nc(this->entries)->get(index);
}

int32_t ZipFile$Source::getEntryNext(int32_t index) {
	return $nc(this->entries)->get(index + 1);
}

int32_t ZipFile$Source::getEntryPos(int32_t index) {
	return $nc(this->entries)->get(index + 2);
}

ZipFile$Source* ZipFile$Source::get($File* file, bool toDelete, $ZipCoder* zc) {
	$init(ZipFile$Source);
	$useLocalCurrentObjectStackCache();
	$var($ZipFile$Source$Key, key, nullptr);
	try {
		$load($BasicFileAttributes);
		$assign(key, $new($ZipFile$Source$Key, file, $($Files::readAttributes($($nc(file)->toPath()), $BasicFileAttributes::class$, $$new($LinkOptionArray, 0))), zc));
	} catch ($InvalidPathException& ipe) {
		$throwNew($IOException, static_cast<$Throwable*>(ipe));
	}
	$var(ZipFile$Source, src, nullptr);
	$synchronized(ZipFile$Source::files) {
		$assign(src, $cast(ZipFile$Source, $nc(ZipFile$Source::files)->get(key)));
		if (src != nullptr) {
			++src->refs;
			return src;
		}
	}
	$assign(src, $new(ZipFile$Source, key, toDelete, zc));
	$synchronized(ZipFile$Source::files) {
		if ($nc(ZipFile$Source::files)->containsKey(key)) {
			src->close();
			$assign(src, $cast(ZipFile$Source, $nc(ZipFile$Source::files)->get(key)));
			++$nc(src)->refs;
			return src;
		}
		$nc(ZipFile$Source::files)->put(key, src);
		return src;
	}
}

void ZipFile$Source::release(ZipFile$Source* src) {
	$init(ZipFile$Source);
	$synchronized(ZipFile$Source::files) {
		bool var$0 = src != nullptr;
		if (var$0 && --src->refs == 0) {
			$nc(ZipFile$Source::files)->remove(src->key);
			src->close();
		}
	}
}

void ZipFile$Source::init$($ZipFile$Source$Key* key, bool toDelete, $ZipCoder* zc) {
	$useLocalCurrentObjectStackCache();
	this->refs = 1;
	this->manifestPos = -1;
	this->manifestNum = 0;
	$set(this, zc, zc);
	$set(this, key, key);
	if (toDelete) {
		$init($ZipFile);
		if ($ZipFile::isWindows) {
			$set(this, zfile, $nc($($SharedSecrets::getJavaIORandomAccessFileAccess()))->openAndDelete($nc(key)->file, "r"_s));
		} else {
			$set(this, zfile, $new($RandomAccessFile, $nc(key)->file, "r"_s));
			$nc($nc(key)->file)->delete$();
		}
	} else {
		$set(this, zfile, $new($RandomAccessFile, $nc(key)->file, "r"_s));
	}
	try {
		initCEN(-1);
		$var($bytes, buf, $new($bytes, 4));
		readFullyAt(buf, 0, 4, 0);
		this->startsWithLoc = ($ZipUtils::LOCSIG(buf) == (int64_t)67324752);
	} catch ($IOException& x) {
		try {
			$nc(this->zfile)->close();
		} catch ($IOException& xx) {
		}
		$throw(x);
	}
}

void ZipFile$Source::close() {
	$nc(this->zfile)->close();
	$set(this, zfile, nullptr);
	$set(this, cen, nullptr);
	$set(this, entries, nullptr);
	$set(this, table, nullptr);
	this->manifestPos = -1;
	this->manifestNum = 0;
	$set(this, signatureMetaNames, nullptr);
	$set(this, metaVersions, ZipFile$Source::EMPTY_META_VERSIONS);
}

int32_t ZipFile$Source::readFullyAt($bytes* buf, int32_t off, int32_t len, int64_t pos) {
	$synchronized(this->zfile) {
		$nc(this->zfile)->seek(pos);
		int32_t N = len;
		while (N > 0) {
			int32_t n = $Math::min(ZipFile$Source::BUF_SIZE, N);
			$nc(this->zfile)->readFully(buf, off, n);
			off += n;
			N -= n;
		}
		return len;
	}
}

int32_t ZipFile$Source::readAt($bytes* buf, int32_t off, int32_t len, int64_t pos) {
	$synchronized(this->zfile) {
		$nc(this->zfile)->seek(pos);
		return $nc(this->zfile)->read(buf, off, len);
	}
}

$ZipFile$Source$End* ZipFile$Source::findEND() {
	$useLocalCurrentObjectStackCache();
	int64_t ziplen = $nc(this->zfile)->length();
	if (ziplen <= 0) {
		zerror("zip file is empty"_s);
	}
	$var($ZipFile$Source$End, end, $new($ZipFile$Source$End));
	$var($bytes, buf, $new($bytes, 128));
	int64_t minHDR = (ziplen - (int64_t)65557) > 0 ? ziplen - (int64_t)65557 : (int64_t)0;
	int64_t minPos = minHDR - (buf->length - 22);
	for (int64_t pos = ziplen - buf->length; pos >= minPos; pos -= (buf->length - 22)) {
		int32_t off = 0;
		if (pos < 0) {
			off = (int32_t)-pos;
			$Arrays::fill(buf, 0, off, (int8_t)0);
		}
		int32_t len = buf->length - off;
		if (readFullyAt(buf, off, len, pos + off) != len) {
			zerror("zip END header not found"_s);
		}
		for (int32_t i = buf->length - 22; i >= 0; --i) {
			if (buf->get(i + 0) == (int8_t)u'P' && buf->get(i + 1) == (int8_t)u'K' && buf->get(i + 2) == (int8_t)(char16_t)0x5 && buf->get(i + 3) == (int8_t)(char16_t)0x6) {
				$var($bytes, endbuf, $Arrays::copyOfRange(buf, i, i + 22));
				end->centot = $ZipUtils::ENDTOT(endbuf);
				end->cenlen = $ZipUtils::ENDSIZ(endbuf);
				end->cenoff = $ZipUtils::ENDOFF(endbuf);
				end->endpos = pos + i;
				int32_t comlen = $ZipUtils::ENDCOM(endbuf);
				if (end->endpos + 22 + comlen != ziplen) {
					$var($bytes, sbuf, $new($bytes, 4));
					int64_t cenpos = end->endpos - end->cenlen;
					int64_t locpos = cenpos - end->cenoff;
					bool var$2 = cenpos < 0 || locpos < 0 || readFullyAt(sbuf, 0, sbuf->length, cenpos) != 4;
					bool var$1 = var$2 || $ZipUtils::GETSIG(sbuf) != (int64_t)33639248;
					bool var$0 = var$1 || readFullyAt(sbuf, 0, sbuf->length, locpos) != 4;
					if (var$0 || $ZipUtils::GETSIG(sbuf) != (int64_t)67324752) {
						continue;
					}
				}
				if (comlen > 0) {
					$set(this, comment, $new($bytes, comlen));
					if (readFullyAt(this->comment, 0, comlen, end->endpos + 22) != comlen) {
						zerror("zip comment read failed"_s);
					}
				}
				try {
					$var($bytes, loc64, $new($bytes, 20));
					bool var$3 = end->endpos < 20 || readFullyAt(loc64, 0, loc64->length, end->endpos - 20) != loc64->length;
					if (var$3 || $ZipUtils::GETSIG(loc64) != (int64_t)117853008) {
						return end;
					}
					int64_t end64pos = $ZipUtils::ZIP64_LOCOFF(loc64);
					$var($bytes, end64buf, $new($bytes, 56));
					bool var$4 = readFullyAt(end64buf, 0, end64buf->length, end64pos) != end64buf->length;
					if (var$4 || $ZipUtils::GETSIG(end64buf) != (int64_t)101075792) {
						return end;
					}
					int64_t cenlen64 = $ZipUtils::ZIP64_ENDSIZ(end64buf);
					int64_t cenoff64 = $ZipUtils::ZIP64_ENDOFF(end64buf);
					int64_t centot64 = $ZipUtils::ZIP64_ENDTOT(end64buf);
					if (cenlen64 != end->cenlen && end->cenlen != (int64_t)0x00000000FFFFFFFF || cenoff64 != end->cenoff && end->cenoff != (int64_t)0x00000000FFFFFFFF || centot64 != end->centot && end->centot != 0x0000FFFF) {
						return end;
					}
					end->cenlen = cenlen64;
					end->cenoff = cenoff64;
					end->centot = (int32_t)centot64;
					end->endpos = end64pos;
				} catch ($IOException& x) {
				}
				return end;
			}
		}
	}
	$throwNew($ZipException, "zip END header not found"_s);
}

void ZipFile$Source::initCEN(int32_t knownTotal) {
	$useLocalCurrentObjectStackCache();
	$var($bytes, cen, nullptr);
	if (knownTotal == -1) {
		$var($ZipFile$Source$End, end, findEND());
		if ($nc(end)->endpos == 0) {
			this->locpos = 0;
			this->total = 0;
			$set(this, entries, $new($ints, 0));
			$set(this, cen, nullptr);
			return;
		}
		if ($nc(end)->cenlen > end->endpos) {
			zerror("invalid END header (bad central directory size)"_s);
		}
		int64_t cenpos = $nc(end)->endpos - end->cenlen;
		this->locpos = cenpos - end->cenoff;
		if (this->locpos < 0) {
			zerror("invalid END header (bad central directory offset)"_s);
		}
		$assign(cen, ($set(this, cen, $new($bytes, (int32_t)(end->cenlen + 22)))));
		if (readFullyAt(cen, 0, $nc(cen)->length, cenpos) != end->cenlen + 22) {
			zerror("read CEN tables failed"_s);
		}
		this->total = end->centot;
	} else {
		$assign(cen, this->cen);
		this->total = knownTotal;
	}
	int32_t entriesLength = this->total * 3;
	$set(this, entries, $new($ints, entriesLength));
	int32_t tablelen = ((this->total / 2) | 1);
	this->tablelen = tablelen;
	$var($ints, table, $new($ints, tablelen));
	$set(this, table, table);
	$Arrays::fill(table, ZipFile$Source::ZIP_ENDCHAIN);
	$var($ArrayList, signatureNames, nullptr);
	$var($Set, metaVersionsSet, nullptr);
	int32_t idx = 0;
	int32_t pos = 0;
	int32_t entryPos = 46;
	int32_t limit = $nc(cen)->length - 22;
	this->manifestNum = 0;
	while (entryPos <= limit) {
		if (idx >= entriesLength) {
			initCEN(countCENHeaders(cen, limit));
			return;
		}
		int32_t nlen = checkAndAddEntry(pos, idx);
		idx += 3;
		if (isMetaName(cen, entryPos, nlen)) {
			if (isManifestName(entryPos + ZipFile$Source::META_INF_LEN, nlen - ZipFile$Source::META_INF_LEN)) {
				this->manifestPos = pos;
				++this->manifestNum;
			} else {
				if (isSignatureRelated(entryPos, nlen)) {
					if (signatureNames == nullptr) {
						$assign(signatureNames, $new($ArrayList, 4));
					}
					$nc(signatureNames)->add($($Integer::valueOf(pos)));
				}
				int32_t version = getMetaVersion(entryPos + ZipFile$Source::META_INF_LEN, nlen - ZipFile$Source::META_INF_LEN);
				if (version > 0) {
					if (metaVersionsSet == nullptr) {
						$assign(metaVersionsSet, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet))));
					}
					$nc(metaVersionsSet)->add($($Integer::valueOf(version)));
				}
			}
		}
		pos = nextEntryPos(pos, entryPos, nlen);
		entryPos = pos + 46;
	}
	this->total = idx / 3;
	if (signatureNames != nullptr) {
		int32_t len = signatureNames->size();
		$set(this, signatureMetaNames, $new($ints, len));
		for (int32_t j = 0; j < len; ++j) {
			$nc(this->signatureMetaNames)->set(j, $nc(($cast($Integer, $(signatureNames->get(j)))))->intValue());
		}
	}
	if (metaVersionsSet != nullptr) {
		$set(this, metaVersions, $new($ints, metaVersionsSet->size()));
		int32_t c = 0;
		{
			$var($Iterator, i$, metaVersionsSet->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Integer, version, $cast($Integer, i$->next()));
				{
					$nc(this->metaVersions)->set(c++, $nc(version)->intValue());
				}
			}
		}
	} else {
		$set(this, metaVersions, ZipFile$Source::EMPTY_META_VERSIONS);
	}
	if (pos + 22 != cen->length) {
		zerror("invalid CEN header (bad header size)"_s);
	}
}

int32_t ZipFile$Source::nextEntryPos(int32_t pos, int32_t entryPos, int32_t nlen) {
	int32_t var$0 = entryPos + nlen + $ZipUtils::CENCOM(this->cen, pos);
	return var$0 + $ZipUtils::CENEXT(this->cen, pos);
}

void ZipFile$Source::zerror($String* msg) {
	$init(ZipFile$Source);
	$throwNew($ZipException, msg);
}

int32_t ZipFile$Source::getEntryPos($String* name, bool addSlash) {
	$useLocalCurrentObjectStackCache();
	if (this->total == 0) {
		return -1;
	}
	int32_t hsh = $ZipCoder::hash(name);
	int32_t idx = $nc(this->table)->get($mod(((int32_t)(hsh & (uint32_t)0x7FFFFFFF)), this->tablelen));
	while (idx != ZipFile$Source::ZIP_ENDCHAIN) {
		if (getEntryHash(idx) == hsh) {
			int32_t pos = getEntryPos(idx);
			try {
				$var($ZipCoder, zc, zipCoderForPos(pos));
				$var($String, entry, $nc(zc)->toString(this->cen, pos + 46, $ZipUtils::CENNAM(this->cen, pos)));
				int32_t entryLen = $nc(entry)->length();
				int32_t nameLen = $nc(name)->length();
				bool var$0 = (entryLen == nameLen && entry->equals(name));
				if (!var$0) {
					bool var$1 = addSlash && nameLen + 1 == entryLen && entry->startsWith(name);
					var$0 = (var$1 && entry->charAt(entryLen - 1) == u'/');
				}
				if (var$0) {
					return pos;
				}
			} catch ($IllegalArgumentException& iae) {
			}
		}
		idx = getEntryNext(idx);
	}
	return -1;
}

$ZipCoder* ZipFile$Source::zipCoderForPos(int32_t pos) {
	if ($nc(this->zc)->isUTF8()) {
		return this->zc;
	}
	if (((int32_t)($ZipUtils::CENFLG(this->cen, pos) & (uint32_t)2048)) != 0) {
		return $ZipCoder::UTF8;
	}
	return this->zc;
}

bool ZipFile$Source::isMetaName($bytes* name, int32_t off, int32_t len) {
	$init(ZipFile$Source);
	bool var$8 = len > ZipFile$Source::META_INF_LEN && $nc(name)->get(off + len - 1) != u'/';
	bool var$7 = var$8 && (name->get(off++) | 32) == u'm';
	bool var$6 = var$7 && (name->get(off++) | 32) == u'e';
	bool var$5 = var$6 && (name->get(off++) | 32) == u't';
	bool var$4 = var$5 && (name->get(off++) | 32) == u'a';
	bool var$3 = var$4 && (name->get(off++)) == u'-';
	bool var$2 = var$3 && (name->get(off++) | 32) == u'i';
	bool var$1 = var$2 && (name->get(off++) | 32) == u'n';
	bool var$0 = var$1 && (name->get(off++) | 32) == u'f';
	return var$0 && (name->get(off)) == u'/';
}

bool ZipFile$Source::isManifestName(int32_t off, int32_t len) {
	$var($bytes, name, this->cen);
	bool var$9 = len == 11 && ($nc(name)->get(off++) | 32) == u'm';
	bool var$8 = var$9 && (name->get(off++) | 32) == u'a';
	bool var$7 = var$8 && (name->get(off++) | 32) == u'n';
	bool var$6 = var$7 && (name->get(off++) | 32) == u'i';
	bool var$5 = var$6 && (name->get(off++) | 32) == u'f';
	bool var$4 = var$5 && (name->get(off++) | 32) == u'e';
	bool var$3 = var$4 && (name->get(off++) | 32) == u's';
	bool var$2 = var$3 && (name->get(off++) | 32) == u't';
	bool var$1 = var$2 && (name->get(off++)) == u'.';
	bool var$0 = var$1 && (name->get(off++) | 32) == u'm';
	return (var$0 && (name->get(off) | 32) == u'f');
}

bool ZipFile$Source::isSignatureRelated(int32_t off, int32_t len) {
	$useLocalCurrentObjectStackCache();
	bool signatureRelated = false;
	$var($bytes, name, this->cen);
	if ($nc(name)->get(off + len - 3) == u'.') {
		int32_t b1 = name->get(off + len - 2) | 32;
		int32_t b2 = name->get(off + len - 1) | 32;
		if ((b1 == u'e' && b2 == u'c') || (b1 == u's' && b2 == u'f')) {
			signatureRelated = true;
		}
	} else if (name->get(off + len - 4) == u'.') {
		int32_t b1 = name->get(off + len - 3) | 32;
		int32_t b2 = name->get(off + len - 2) | 32;
		int32_t b3 = name->get(off + len - 1) | 32;
		if ((b1 == u'r' || b1 == u'd') && b2 == u's' && b3 == u'a') {
			signatureRelated = true;
		}
	}
	$init($UTF_8);
	$init($Locale);
	if (!ZipFile$Source::$assertionsDisabled && !(signatureRelated == $SignatureFileVerifier::isBlockOrSF($($$new($String, name, off, len, static_cast<$Charset*>($UTF_8::INSTANCE))->toUpperCase($Locale::ENGLISH))))) {
		$throwNew($AssertionError);
	}
	return signatureRelated;
}

int32_t ZipFile$Source::getMetaVersion(int32_t off, int32_t len) {
	$var($bytes, name, this->cen);
	int32_t nend = off + len;
	bool var$8 = len > 10 && $nc(name)->get(off + len - 1) != u'/';
	bool var$7 = var$8 && (name->get(off++) | 32) == u'v';
	bool var$6 = var$7 && (name->get(off++) | 32) == u'e';
	bool var$5 = var$6 && (name->get(off++) | 32) == u'r';
	bool var$4 = var$5 && (name->get(off++) | 32) == u's';
	bool var$3 = var$4 && (name->get(off++) | 32) == u'i';
	bool var$2 = var$3 && (name->get(off++) | 32) == u'o';
	bool var$1 = var$2 && (name->get(off++) | 32) == u'n';
	bool var$0 = var$1 && (name->get(off++) | 32) == u's';
	if (!(var$0 && (name->get(off++)) == u'/')) {
		return 0;
	}
	int32_t version = 0;
	while (off < nend) {
		int8_t c = $nc(name)->get(off++);
		if (c == u'/') {
			return version;
		}
		if (c < u'0' || c > u'9') {
			return 0;
		}
		version = version * 10 + c - u'0';
		if (version <= 0) {
			return 0;
		}
	}
	return 0;
}

int32_t ZipFile$Source::countCENHeaders($bytes* cen, int32_t size) {
	$init(ZipFile$Source);
	int32_t count = 0;
	{
		int32_t p = 0;
		bool var$0 = false;
		for (; p + 46 <= size;) {
			if (var$0) {
				int32_t var$2 = 46 + $ZipUtils::CENNAM(cen, p);
				int32_t var$1 = var$2 + $ZipUtils::CENEXT(cen, p);
				p += var$1 + $ZipUtils::CENCOM(cen, p);
			}
			var$0 = true;
			{
				++count;
			}
		}
	}
	return count;
}

void clinit$ZipFile$Source($Class* class$) {
	$load($ZipFile);
	ZipFile$Source::$assertionsDisabled = !$ZipFile::class$->desiredAssertionStatus();
	$assignStatic(ZipFile$Source::JUJA, $SharedSecrets::javaUtilJarAccess());
	$assignStatic(ZipFile$Source::EMPTY_META_VERSIONS, $new($ints, 0));
	$assignStatic(ZipFile$Source::files, $new($HashMap));
}

ZipFile$Source::ZipFile$Source() {
}

$Class* ZipFile$Source::load$($String* name, bool initialize) {
	$loadClass(ZipFile$Source, name, initialize, &_ZipFile$Source_ClassInfo_, clinit$ZipFile$Source, allocate$ZipFile$Source);
	return class$;
}

$Class* ZipFile$Source::class$ = nullptr;

		} // zip
	} // util
} // java
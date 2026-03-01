#include <java/lang/CharacterName.h>

#include <java/io/DataInputStream.h>
#include <java/io/InputStream.h>
#include <java/lang/CharacterName$1.h>
#include <java/lang/InternalError.h>
#include <java/lang/ref/SoftReference.h>
#include <java/nio/charset/Charset.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Arrays.h>
#include <java/util/zip/InflaterInputStream.h>
#include <sun/nio/cs/ISO_8859_1.h>
#include <jcpp.h>

#undef INSTANCE
#undef MAX_CODE_POINT

using $DataInputStream = ::java::io::DataInputStream;
using $InputStream = ::java::io::InputStream;
using $Character = ::java::lang::Character;
using $CharacterName$1 = ::java::lang::CharacterName$1;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $SoftReference = ::java::lang::ref::SoftReference;
using $Charset = ::java::nio::charset::Charset;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Arrays = ::java::util::Arrays;
using $InflaterInputStream = ::java::util::zip::InflaterInputStream;
using $ISO_8859_1 = ::sun::nio::cs::ISO_8859_1;

namespace java {
	namespace lang {

$FieldInfo _CharacterName_FieldInfo_[] = {
	{"refCharName", "Ljava/lang/ref/SoftReference;", "Ljava/lang/ref/SoftReference<Ljava/lang/CharacterName;>;", $PRIVATE | $STATIC, $staticField(CharacterName, refCharName)},
	{"strPool", "[B", nullptr, $PRIVATE | $FINAL, $field(CharacterName, strPool)},
	{"lookup", "[I", nullptr, $PRIVATE | $FINAL, $field(CharacterName, lookup)},
	{"bkIndices", "[I", nullptr, $PRIVATE | $FINAL, $field(CharacterName, bkIndices)},
	{"cpEntries", "[I", nullptr, $PRIVATE | $FINAL, $field(CharacterName, cpEntries)},
	{"hsIndices", "[I", nullptr, $PRIVATE | $FINAL, $field(CharacterName, hsIndices)},
	{}
};

$MethodInfo _CharacterName_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(CharacterName, init$, void)},
	{"addCp", "(IIII)I", nullptr, $PRIVATE, $method(CharacterName, addCp, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"getCodePoint", "(Ljava/lang/String;)I", nullptr, $PUBLIC, $virtualMethod(CharacterName, getCodePoint, int32_t, $String*)},
	{"getCp", "(I)I", nullptr, $PRIVATE, $method(CharacterName, getCp, int32_t, int32_t)},
	{"getCpHash", "(I)I", nullptr, $PRIVATE, $method(CharacterName, getCpHash, int32_t, int32_t)},
	{"getCpNext", "(I)I", nullptr, $PRIVATE, $method(CharacterName, getCpNext, int32_t, int32_t)},
	{"getInstance", "()Ljava/lang/CharacterName;", nullptr, $PUBLIC | $STATIC, $staticMethod(CharacterName, getInstance, CharacterName*)},
	{"getName", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(CharacterName, getName, $String*, int32_t)},
	{"hashN", "([BII)I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(CharacterName, hashN, int32_t, $bytes*, int32_t, int32_t)},
	{}
};

$InnerClassInfo _CharacterName_InnerClassesInfo_[] = {
	{"java.lang.CharacterName$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _CharacterName_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.CharacterName",
	"java.lang.Object",
	nullptr,
	_CharacterName_FieldInfo_,
	_CharacterName_MethodInfo_,
	nullptr,
	nullptr,
	_CharacterName_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.CharacterName$1"
};

$Object* allocate$CharacterName($Class* clazz) {
	return $of($alloc(CharacterName));
}

$SoftReference* CharacterName::refCharName = nullptr;

void CharacterName::init$() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$var($DataInputStream, dis, $new($DataInputStream, $$new($InflaterInputStream, $cast($InputStream, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($CharacterName$1, this))))))));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					int32_t total = dis->readInt();
					int32_t bkNum = dis->readInt();
					int32_t cpNum = dis->readInt();
					int32_t cpEnd = dis->readInt();
					$var($bytes, ba, $new($bytes, cpEnd));
					$set(this, lookup, $new($ints, bkNum * 256));
					$set(this, bkIndices, $new($ints, ($Character::MAX_CODE_POINT + 1) >> 8));
					$set(this, strPool, $new($bytes, total - cpEnd));
					$set(this, cpEntries, $new($ints, cpNum * 3));
					$set(this, hsIndices, $new($ints, (cpNum / 2) | 1));
					$Arrays::fill(this->bkIndices, -1);
					$Arrays::fill(this->hsIndices, -1);
					dis->readFully(ba);
					dis->readFully(this->strPool);
					int32_t nameOff = 0;
					int32_t cpOff = 0;
					int32_t cp = 0;
					int32_t bk = -1;
					int32_t prevBk = -1;
					int32_t idx = 0;
					int32_t next = -1;
					int32_t hash = 0;
					int32_t hsh = 0;
					do {
						int32_t len = (int32_t)(ba->get(cpOff++) & (uint32_t)255);
						if (len == 0) {
							len = (int32_t)(ba->get(cpOff++) & (uint32_t)255);
							int32_t var$2 = (((int32_t)(ba->get(cpOff++) & (uint32_t)255)) << 16);
							int32_t var$1 = var$2 | (((int32_t)(ba->get(cpOff++) & (uint32_t)255)) << 8);
							cp = var$1 | ((int32_t)(ba->get(cpOff++) & (uint32_t)255));
						} else {
							++cp;
						}
						int32_t hi = cp >> 8;
						if (prevBk != hi) {
							++bk;
							$nc(this->bkIndices)->set(hi, bk);
							prevBk = hi;
						}
						$nc(this->lookup)->set((bk << 8) + ((int32_t)(cp & (uint32_t)255)), (nameOff << 8) | len);
						hash = hashN(this->strPool, nameOff, len);
						hsh = $mod(((int32_t)(hash & (uint32_t)0x7FFFFFFF)), $nc(this->hsIndices)->length);
						next = $nc(this->hsIndices)->get(hsh);
						$nc(this->hsIndices)->set(hsh, idx);
						idx = addCp(idx, hash, next, cp);
						nameOff += len;
					} while (cpOff < cpEnd);
				} catch ($Throwable& t$) {
					try {
						dis->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				dis->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($Exception& x) {
		$throwNew($InternalError, $(x->getMessage()), x);
	}
}

int32_t CharacterName::hashN($bytes* a, int32_t off, int32_t len) {
	int32_t h = 1;
	while (len-- > 0) {
		h = 31 * h + $nc(a)->get(off++);
	}
	return h;
}

int32_t CharacterName::addCp(int32_t idx, int32_t hash, int32_t next, int32_t cp) {
	$nc(this->cpEntries)->set(idx++, hash);
	$nc(this->cpEntries)->set(idx++, next);
	$nc(this->cpEntries)->set(idx++, cp);
	return idx;
}

int32_t CharacterName::getCpHash(int32_t idx) {
	return $nc(this->cpEntries)->get(idx);
}

int32_t CharacterName::getCpNext(int32_t idx) {
	return $nc(this->cpEntries)->get(idx + 1);
}

int32_t CharacterName::getCp(int32_t idx) {
	return $nc(this->cpEntries)->get(idx + 2);
}

CharacterName* CharacterName::getInstance() {
	$useLocalCurrentObjectStackCache();
	$init(CharacterName);
	$var($SoftReference, ref, CharacterName::refCharName);
	$var(CharacterName, cname, nullptr);
	if (ref == nullptr || ($assign(cname, $cast(CharacterName, $nc(ref)->get()))) == nullptr) {
		$assign(cname, $new(CharacterName));
		$assignStatic(CharacterName::refCharName, $new($SoftReference, cname));
	}
	return cname;
}

$String* CharacterName::getName(int32_t cp) {
	int32_t off = 0;
	int32_t bk = $nc(this->bkIndices)->get(cp >> 8);
	if (bk == -1 || (off = $nc(this->lookup)->get((bk << 8) + ((int32_t)(cp & (uint32_t)255)))) == 0) {
		return nullptr;
	}
	$var($String, result, $new($String, this->strPool, 0, (int32_t)((uint32_t)off >> 8), (int32_t)(off & (uint32_t)255)));
	return result;
}

int32_t CharacterName::getCodePoint($String* name) {
	$init($ISO_8859_1);
	$var($bytes, bname, $nc(name)->getBytes(static_cast<$Charset*>($ISO_8859_1::INSTANCE)));
	int32_t hsh = hashN(bname, 0, bname->length);
	int32_t idx = $nc(this->hsIndices)->get($mod(((int32_t)(hsh & (uint32_t)0x7FFFFFFF)), $nc(this->hsIndices)->length));
	while (idx != -1) {
		if (getCpHash(idx) == hsh) {
			int32_t cp = getCp(idx);
			int32_t off = -1;
			int32_t bk = $nc(this->bkIndices)->get(cp >> 8);
			if (bk != -1 && (off = $nc(this->lookup)->get((bk << 8) + ((int32_t)(cp & (uint32_t)255)))) != 0) {
				int32_t len = (int32_t)(off & (uint32_t)255);
				off = (int32_t)((uint32_t)off >> 8);
				if (bname->length == len) {
					int32_t i = 0;
					while (i < len && bname->get(i) == $nc(this->strPool)->get(off++)) {
						++i;
					}
					if (i == len) {
						return cp;
					}
				}
			}
		}
		idx = getCpNext(idx);
	}
	return -1;
}

CharacterName::CharacterName() {
}

$Class* CharacterName::load$($String* name, bool initialize) {
	$loadClass(CharacterName, name, initialize, &_CharacterName_ClassInfo_, allocate$CharacterName);
	return class$;
}

$Class* CharacterName::class$ = nullptr;

	} // lang
} // java
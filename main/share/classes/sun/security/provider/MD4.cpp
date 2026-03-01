#include <sun/security/provider/MD4.h>

#include <java/lang/invoke/VarHandle.h>
#include <java/security/AccessController.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/Provider.h>
#include <java/security/ProviderException.h>
#include <sun/security/provider/ByteArrayAccess$LE.h>
#include <sun/security/provider/ByteArrayAccess.h>
#include <sun/security/provider/DigestBase.h>
#include <sun/security/provider/MD4$1.h>
#include <sun/security/provider/MD4$2.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef FF
#undef GG
#undef HH
#undef INT_ARRAY
#undef MD4
#undef PROVIDER_VER

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $VarHandle = ::java::lang::invoke::VarHandle;
using $AccessController = ::java::security::AccessController;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Provider = ::java::security::Provider;
using $ProviderException = ::java::security::ProviderException;
using $ByteArrayAccess = ::sun::security::provider::ByteArrayAccess;
using $ByteArrayAccess$LE = ::sun::security::provider::ByteArrayAccess$LE;
using $DigestBase = ::sun::security::provider::DigestBase;
using $MD4$1 = ::sun::security::provider::MD4$1;
using $MD4$2 = ::sun::security::provider::MD4$2;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _MD4_FieldInfo_[] = {
	{"state", "[I", nullptr, $PRIVATE, $field(MD4, state)},
	{"S11", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S11)},
	{"S12", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S12)},
	{"S13", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S13)},
	{"S14", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S14)},
	{"S21", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S21)},
	{"S22", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S22)},
	{"S23", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S23)},
	{"S24", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S24)},
	{"S31", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S31)},
	{"S32", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S32)},
	{"S33", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S33)},
	{"S34", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MD4, S34)},
	{"md4Provider", "Ljava/security/Provider;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MD4, md4Provider)},
	{}
};

$MethodInfo _MD4_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MD4, init$, void)},
	{"FF", "(IIIIII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(MD4, FF, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"GG", "(IIIIII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(MD4, GG, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"HH", "(IIIIII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(MD4, HH, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(MD4, clone, $Object*), "java.lang.CloneNotSupportedException"},
	{"getInstance", "()Ljava/security/MessageDigest;", nullptr, $PUBLIC | $STATIC, $staticMethod(MD4, getInstance, $MessageDigest*)},
	{"implCompress", "([BI)V", nullptr, 0, $virtualMethod(MD4, implCompress, void, $bytes*, int32_t)},
	{"implDigest", "([BI)V", nullptr, 0, $virtualMethod(MD4, implDigest, void, $bytes*, int32_t)},
	{"implReset", "()V", nullptr, 0, $virtualMethod(MD4, implReset, void)},
	{"resetHashes", "()V", nullptr, $PRIVATE, $method(MD4, resetHashes, void)},
	{}
};

$InnerClassInfo _MD4_InnerClassesInfo_[] = {
	{"sun.security.provider.MD4$2", nullptr, nullptr, 0},
	{"sun.security.provider.MD4$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MD4_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.MD4",
	"sun.security.provider.DigestBase",
	nullptr,
	_MD4_FieldInfo_,
	_MD4_MethodInfo_,
	nullptr,
	nullptr,
	_MD4_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.MD4$2,sun.security.provider.MD4$1"
};

$Object* allocate$MD4($Class* clazz) {
	return $of($alloc(MD4));
}

$Provider* MD4::md4Provider = nullptr;

$MessageDigest* MD4::getInstance() {
	$init(MD4);
	try {
		return $MessageDigest::getInstance("MD4"_s, MD4::md4Provider);
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($ProviderException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void MD4::init$() {
	$DigestBase::init$("MD4"_s, 16, 64);
	$set(this, state, $new($ints, 4));
	resetHashes();
}

$Object* MD4::clone() {
	$var(MD4, copy, $cast(MD4, $DigestBase::clone()));
	$set($nc(copy), state, $cast($ints, $nc(copy->state)->clone()));
	return $of(copy);
}

void MD4::implReset() {
	resetHashes();
}

void MD4::resetHashes() {
	$nc(this->state)->set(0, 0x67452301);
	$nc(this->state)->set(1, (int32_t)0xEFCDAB89);
	$nc(this->state)->set(2, (int32_t)0x98BADCFE);
	$nc(this->state)->set(3, 0x10325476);
}

void MD4::implDigest($bytes* out, int32_t ofs) {
	int64_t bitsProcessed = this->bytesProcessed << 3;
	int32_t index = (int32_t)((int32_t)this->bytesProcessed & (uint32_t)63);
	int32_t padLen = (index < 56) ? (56 - index) : (120 - index);
	$init($DigestBase);
	engineUpdate($DigestBase::padding, 0, padLen);
	$ByteArrayAccess::i2bLittle4((int32_t)bitsProcessed, this->buffer, 56);
	$ByteArrayAccess::i2bLittle4((int32_t)((int64_t)((uint64_t)bitsProcessed >> 32)), this->buffer, 60);
	implCompress(this->buffer, 0);
	$ByteArrayAccess::i2bLittle(this->state, 0, out, ofs, 16);
}

int32_t MD4::FF(int32_t a, int32_t b, int32_t c, int32_t d, int32_t x, int32_t s) {
	$init(MD4);
	a += (((int32_t)(b & (uint32_t)c)) | ((int32_t)((~b) & (uint32_t)d))) + x;
	return (($sl(a, s)) | ($usr(a, 32 - s)));
}

int32_t MD4::GG(int32_t a, int32_t b, int32_t c, int32_t d, int32_t x, int32_t s) {
	$init(MD4);
	a += ((((int32_t)(b & (uint32_t)c)) | ((int32_t)(b & (uint32_t)d))) | ((int32_t)(c & (uint32_t)d))) + x + 0x5A827999;
	return (($sl(a, s)) | ($usr(a, 32 - s)));
}

int32_t MD4::HH(int32_t a, int32_t b, int32_t c, int32_t d, int32_t x, int32_t s) {
	$init(MD4);
	a += ((b ^ c) ^ d) + x + 0x6ED9EBA1;
	return (($sl(a, s)) | ($usr(a, 32 - s)));
}

void MD4::implCompress($bytes* buf, int32_t ofs) {
	$useLocalCurrentObjectStackCache();
	$init($ByteArrayAccess$LE);
	int32_t x0 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of(ofs)})));
	int32_t x1 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 4))})));
	int32_t x2 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 8))})));
	int32_t x3 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 12))})));
	int32_t x4 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 16))})));
	int32_t x5 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 20))})));
	int32_t x6 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 24))})));
	int32_t x7 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 28))})));
	int32_t x8 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 32))})));
	int32_t x9 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 36))})));
	int32_t x10 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 40))})));
	int32_t x11 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 44))})));
	int32_t x12 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 48))})));
	int32_t x13 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 52))})));
	int32_t x14 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 56))})));
	int32_t x15 = $intValue($nc($ByteArrayAccess$LE::INT_ARRAY)->get($$new($ObjectArray, {$of(buf), $$of((ofs + 60))})));
	int32_t a = $nc(this->state)->get(0);
	int32_t b = $nc(this->state)->get(1);
	int32_t c = $nc(this->state)->get(2);
	int32_t d = $nc(this->state)->get(3);
	a = FF(a, b, c, d, x0, MD4::S11);
	d = FF(d, a, b, c, x1, MD4::S12);
	c = FF(c, d, a, b, x2, MD4::S13);
	b = FF(b, c, d, a, x3, MD4::S14);
	a = FF(a, b, c, d, x4, MD4::S11);
	d = FF(d, a, b, c, x5, MD4::S12);
	c = FF(c, d, a, b, x6, MD4::S13);
	b = FF(b, c, d, a, x7, MD4::S14);
	a = FF(a, b, c, d, x8, MD4::S11);
	d = FF(d, a, b, c, x9, MD4::S12);
	c = FF(c, d, a, b, x10, MD4::S13);
	b = FF(b, c, d, a, x11, MD4::S14);
	a = FF(a, b, c, d, x12, MD4::S11);
	d = FF(d, a, b, c, x13, MD4::S12);
	c = FF(c, d, a, b, x14, MD4::S13);
	b = FF(b, c, d, a, x15, MD4::S14);
	a = GG(a, b, c, d, x0, MD4::S21);
	d = GG(d, a, b, c, x4, MD4::S22);
	c = GG(c, d, a, b, x8, MD4::S23);
	b = GG(b, c, d, a, x12, MD4::S24);
	a = GG(a, b, c, d, x1, MD4::S21);
	d = GG(d, a, b, c, x5, MD4::S22);
	c = GG(c, d, a, b, x9, MD4::S23);
	b = GG(b, c, d, a, x13, MD4::S24);
	a = GG(a, b, c, d, x2, MD4::S21);
	d = GG(d, a, b, c, x6, MD4::S22);
	c = GG(c, d, a, b, x10, MD4::S23);
	b = GG(b, c, d, a, x14, MD4::S24);
	a = GG(a, b, c, d, x3, MD4::S21);
	d = GG(d, a, b, c, x7, MD4::S22);
	c = GG(c, d, a, b, x11, MD4::S23);
	b = GG(b, c, d, a, x15, MD4::S24);
	a = HH(a, b, c, d, x0, MD4::S31);
	d = HH(d, a, b, c, x8, MD4::S32);
	c = HH(c, d, a, b, x4, MD4::S33);
	b = HH(b, c, d, a, x12, MD4::S34);
	a = HH(a, b, c, d, x2, MD4::S31);
	d = HH(d, a, b, c, x10, MD4::S32);
	c = HH(c, d, a, b, x6, MD4::S33);
	b = HH(b, c, d, a, x14, MD4::S34);
	a = HH(a, b, c, d, x1, MD4::S31);
	d = HH(d, a, b, c, x9, MD4::S32);
	c = HH(c, d, a, b, x5, MD4::S33);
	b = HH(b, c, d, a, x13, MD4::S34);
	a = HH(a, b, c, d, x3, MD4::S31);
	d = HH(d, a, b, c, x11, MD4::S32);
	c = HH(c, d, a, b, x7, MD4::S33);
	b = HH(b, c, d, a, x15, MD4::S34);
	(*$nc(this->state))[0] += a;
	(*$nc(this->state))[1] += b;
	(*$nc(this->state))[2] += c;
	(*$nc(this->state))[3] += d;
}

void clinit$MD4($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$init($SecurityConstants);
		$assignStatic(MD4::md4Provider, $new($MD4$1, "MD4Provider"_s, $SecurityConstants::PROVIDER_VER, "MD4 MessageDigest"_s));
		$var($Void, dummy, $cast($Void, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($MD4$2)))));
	}
}

MD4::MD4() {
}

$Class* MD4::load$($String* name, bool initialize) {
	$loadClass(MD4, name, initialize, &_MD4_ClassInfo_, clinit$MD4, allocate$MD4);
	return class$;
}

$Class* MD4::class$ = nullptr;

		} // provider
	} // security
} // sun
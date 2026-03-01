#include <java/nio/charset/StandardCharsets.h>

#include <java/lang/AssertionError.h>
#include <java/nio/charset/Charset.h>
#include <sun/nio/cs/ISO_8859_1.h>
#include <sun/nio/cs/US_ASCII.h>
#include <sun/nio/cs/UTF_16.h>
#include <sun/nio/cs/UTF_16BE.h>
#include <sun/nio/cs/UTF_16LE.h>
#include <sun/nio/cs/UTF_8.h>
#include <jcpp.h>

#undef INSTANCE
#undef US_ASCII
#undef UTF_16
#undef UTF_16BE
#undef UTF_16LE
#undef UTF_8

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $ISO_8859_1 = ::sun::nio::cs::ISO_8859_1;
using $US_ASCII = ::sun::nio::cs::US_ASCII;
using $UTF_16 = ::sun::nio::cs::UTF_16;
using $UTF_16BE = ::sun::nio::cs::UTF_16BE;
using $UTF_16LE = ::sun::nio::cs::UTF_16LE;
using $UTF_8 = ::sun::nio::cs::UTF_8;

namespace java {
	namespace nio {
		namespace charset {

$FieldInfo _StandardCharsets_FieldInfo_[] = {
	{"US_ASCII", "Ljava/nio/charset/Charset;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(StandardCharsets, US_ASCII)},
	{"ISO_8859_1", "Ljava/nio/charset/Charset;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(StandardCharsets, ISO_8859_1)},
	{"UTF_8", "Ljava/nio/charset/Charset;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(StandardCharsets, UTF_8)},
	{"UTF_16BE", "Ljava/nio/charset/Charset;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(StandardCharsets, UTF_16BE)},
	{"UTF_16LE", "Ljava/nio/charset/Charset;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(StandardCharsets, UTF_16LE)},
	{"UTF_16", "Ljava/nio/charset/Charset;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(StandardCharsets, UTF_16)},
	{}
};

$MethodInfo _StandardCharsets_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(StandardCharsets, init$, void)},
	{}
};

$ClassInfo _StandardCharsets_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.nio.charset.StandardCharsets",
	"java.lang.Object",
	nullptr,
	_StandardCharsets_FieldInfo_,
	_StandardCharsets_MethodInfo_
};

$Object* allocate$StandardCharsets($Class* clazz) {
	return $of($alloc(StandardCharsets));
}

$Charset* StandardCharsets::US_ASCII = nullptr;
$Charset* StandardCharsets::ISO_8859_1 = nullptr;
$Charset* StandardCharsets::UTF_8 = nullptr;
$Charset* StandardCharsets::UTF_16BE = nullptr;
$Charset* StandardCharsets::UTF_16LE = nullptr;
$Charset* StandardCharsets::UTF_16 = nullptr;

void StandardCharsets::init$() {
	$throwNew($AssertionError, $of("No java.nio.charset.StandardCharsets instances for you!"_s));
}

void clinit$StandardCharsets($Class* class$) {
	$init($US_ASCII);
	$assignStatic(StandardCharsets::US_ASCII, $US_ASCII::INSTANCE);
	$init($ISO_8859_1);
	$assignStatic(StandardCharsets::ISO_8859_1, $ISO_8859_1::INSTANCE);
	$init($UTF_8);
	$assignStatic(StandardCharsets::UTF_8, $UTF_8::INSTANCE);
	$assignStatic(StandardCharsets::UTF_16BE, $new($UTF_16BE));
	$assignStatic(StandardCharsets::UTF_16LE, $new($UTF_16LE));
	$assignStatic(StandardCharsets::UTF_16, $new($UTF_16));
}

StandardCharsets::StandardCharsets() {
}

$Class* StandardCharsets::load$($String* name, bool initialize) {
	$loadClass(StandardCharsets, name, initialize, &_StandardCharsets_ClassInfo_, clinit$StandardCharsets, allocate$StandardCharsets);
	return class$;
}

$Class* StandardCharsets::class$ = nullptr;

		} // charset
	} // nio
} // java
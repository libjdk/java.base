#include <sun/nio/cs/MS950_HKSCS_XP.h>

#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <sun/nio/cs/MS950.h>
#include <sun/nio/cs/MS950_HKSCS_XP$Decoder.h>
#include <sun/nio/cs/MS950_HKSCS_XP$Encoder.h>
#include <sun/nio/cs/StandardCharsets.h>
#include <jcpp.h>

#undef MS950_HKSCS_XP

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $MS950 = ::sun::nio::cs::MS950;
using $MS950_HKSCS_XP$Decoder = ::sun::nio::cs::MS950_HKSCS_XP$Decoder;
using $MS950_HKSCS_XP$Encoder = ::sun::nio::cs::MS950_HKSCS_XP$Encoder;
using $StandardCharsets = ::sun::nio::cs::StandardCharsets;

namespace sun {
	namespace nio {
		namespace cs {

$MethodInfo _MS950_HKSCS_XP_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MS950_HKSCS_XP, init$, void)},
	{"contains", "(Ljava/nio/charset/Charset;)Z", nullptr, $PUBLIC, $virtualMethod(MS950_HKSCS_XP, contains, bool, $Charset*)},
	{"newDecoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PUBLIC, $virtualMethod(MS950_HKSCS_XP, newDecoder, $CharsetDecoder*)},
	{"newEncoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PUBLIC, $virtualMethod(MS950_HKSCS_XP, newEncoder, $CharsetEncoder*)},
	{}
};

$InnerClassInfo _MS950_HKSCS_XP_InnerClassesInfo_[] = {
	{"sun.nio.cs.MS950_HKSCS_XP$Encoder", "sun.nio.cs.MS950_HKSCS_XP", "Encoder", $PRIVATE | $STATIC},
	{"sun.nio.cs.MS950_HKSCS_XP$Decoder", "sun.nio.cs.MS950_HKSCS_XP", "Decoder", $STATIC},
	{}
};

$ClassInfo _MS950_HKSCS_XP_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.MS950_HKSCS_XP",
	"java.nio.charset.Charset",
	nullptr,
	nullptr,
	_MS950_HKSCS_XP_MethodInfo_,
	nullptr,
	nullptr,
	_MS950_HKSCS_XP_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.cs.MS950_HKSCS_XP$Encoder,sun.nio.cs.MS950_HKSCS_XP$Decoder"
};

$Object* allocate$MS950_HKSCS_XP($Class* clazz) {
	return $of($alloc(MS950_HKSCS_XP));
}

void MS950_HKSCS_XP::init$() {
	$Charset::init$("x-MS950-HKSCS-XP"_s, $($StandardCharsets::aliases_MS950_HKSCS_XP()));
}

bool MS950_HKSCS_XP::contains($Charset* cs) {
	return (($nc($($nc(cs)->name()))->equals("US-ASCII"_s)) || ($instanceOf($MS950, cs)) || ($instanceOf(MS950_HKSCS_XP, cs)));
}

$CharsetDecoder* MS950_HKSCS_XP::newDecoder() {
	return $new($MS950_HKSCS_XP$Decoder, this);
}

$CharsetEncoder* MS950_HKSCS_XP::newEncoder() {
	return $new($MS950_HKSCS_XP$Encoder, this);
}

MS950_HKSCS_XP::MS950_HKSCS_XP() {
}

$Class* MS950_HKSCS_XP::load$($String* name, bool initialize) {
	$loadClass(MS950_HKSCS_XP, name, initialize, &_MS950_HKSCS_XP_ClassInfo_, allocate$MS950_HKSCS_XP);
	return class$;
}

$Class* MS950_HKSCS_XP::class$ = nullptr;

		} // cs
	} // nio
} // sun
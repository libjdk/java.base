#include <sun/nio/cs/UTF_16.h>

#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <sun/nio/cs/StandardCharsets.h>
#include <sun/nio/cs/UTF_16$Decoder.h>
#include <sun/nio/cs/UTF_16$Encoder.h>
#include <sun/nio/cs/Unicode.h>
#include <jcpp.h>

#undef UTF_16

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $StandardCharsets = ::sun::nio::cs::StandardCharsets;
using $UTF_16$Decoder = ::sun::nio::cs::UTF_16$Decoder;
using $UTF_16$Encoder = ::sun::nio::cs::UTF_16$Encoder;
using $Unicode = ::sun::nio::cs::Unicode;

namespace sun {
	namespace nio {
		namespace cs {

$MethodInfo _UTF_16_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(UTF_16, init$, void)},
	{"contains", "(Ljava/nio/charset/Charset;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(UTF_16, contains, bool, $Charset*)},
	{"historicalName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UTF_16, historicalName, $String*)},
	{"newDecoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PUBLIC, $virtualMethod(UTF_16, newDecoder, $CharsetDecoder*)},
	{"newEncoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PUBLIC, $virtualMethod(UTF_16, newEncoder, $CharsetEncoder*)},
	{}
};

$InnerClassInfo _UTF_16_InnerClassesInfo_[] = {
	{"sun.nio.cs.UTF_16$Encoder", "sun.nio.cs.UTF_16", "Encoder", $PRIVATE | $STATIC},
	{"sun.nio.cs.UTF_16$Decoder", "sun.nio.cs.UTF_16", "Decoder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _UTF_16_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.UTF_16",
	"sun.nio.cs.Unicode",
	nullptr,
	nullptr,
	_UTF_16_MethodInfo_,
	nullptr,
	nullptr,
	_UTF_16_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.cs.UTF_16$Encoder,sun.nio.cs.UTF_16$Decoder"
};

$Object* allocate$UTF_16($Class* clazz) {
	return $of($alloc(UTF_16));
}

void UTF_16::init$() {
	$Unicode::init$("UTF-16"_s, $($StandardCharsets::aliases_UTF_16()));
}

$String* UTF_16::historicalName() {
	return "UTF-16"_s;
}

$CharsetDecoder* UTF_16::newDecoder() {
	return $new($UTF_16$Decoder, this);
}

$CharsetEncoder* UTF_16::newEncoder() {
	return $new($UTF_16$Encoder, this);
}

bool UTF_16::contains($Charset* cs) {
	return $Unicode::contains(cs);
}

UTF_16::UTF_16() {
}

$Class* UTF_16::load$($String* name, bool initialize) {
	$loadClass(UTF_16, name, initialize, &_UTF_16_ClassInfo_, allocate$UTF_16);
	return class$;
}

$Class* UTF_16::class$ = nullptr;

		} // cs
	} // nio
} // sun
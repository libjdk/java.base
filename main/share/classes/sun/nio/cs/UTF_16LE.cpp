#include <sun/nio/cs/UTF_16LE.h>

#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <sun/nio/cs/StandardCharsets.h>
#include <sun/nio/cs/UTF_16LE$Decoder.h>
#include <sun/nio/cs/UTF_16LE$Encoder.h>
#include <sun/nio/cs/Unicode.h>
#include <jcpp.h>

#undef UTF_16LE

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $StandardCharsets = ::sun::nio::cs::StandardCharsets;
using $UTF_16LE$Decoder = ::sun::nio::cs::UTF_16LE$Decoder;
using $UTF_16LE$Encoder = ::sun::nio::cs::UTF_16LE$Encoder;
using $Unicode = ::sun::nio::cs::Unicode;

namespace sun {
	namespace nio {
		namespace cs {

$MethodInfo _UTF_16LE_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(UTF_16LE, init$, void)},
	{"contains", "(Ljava/nio/charset/Charset;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(UTF_16LE, contains, bool, $Charset*)},
	{"historicalName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UTF_16LE, historicalName, $String*)},
	{"newDecoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PUBLIC, $virtualMethod(UTF_16LE, newDecoder, $CharsetDecoder*)},
	{"newEncoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PUBLIC, $virtualMethod(UTF_16LE, newEncoder, $CharsetEncoder*)},
	{}
};

$InnerClassInfo _UTF_16LE_InnerClassesInfo_[] = {
	{"sun.nio.cs.UTF_16LE$Encoder", "sun.nio.cs.UTF_16LE", "Encoder", $PRIVATE | $STATIC},
	{"sun.nio.cs.UTF_16LE$Decoder", "sun.nio.cs.UTF_16LE", "Decoder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _UTF_16LE_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.UTF_16LE",
	"sun.nio.cs.Unicode",
	nullptr,
	nullptr,
	_UTF_16LE_MethodInfo_,
	nullptr,
	nullptr,
	_UTF_16LE_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.cs.UTF_16LE$Encoder,sun.nio.cs.UTF_16LE$Decoder"
};

$Object* allocate$UTF_16LE($Class* clazz) {
	return $of($alloc(UTF_16LE));
}

void UTF_16LE::init$() {
	$Unicode::init$("UTF-16LE"_s, $($StandardCharsets::aliases_UTF_16LE()));
}

$String* UTF_16LE::historicalName() {
	return "UnicodeLittleUnmarked"_s;
}

$CharsetDecoder* UTF_16LE::newDecoder() {
	return $new($UTF_16LE$Decoder, this);
}

$CharsetEncoder* UTF_16LE::newEncoder() {
	return $new($UTF_16LE$Encoder, this);
}

bool UTF_16LE::contains($Charset* cs) {
	return $Unicode::contains(cs);
}

UTF_16LE::UTF_16LE() {
}

$Class* UTF_16LE::load$($String* name, bool initialize) {
	$loadClass(UTF_16LE, name, initialize, &_UTF_16LE_ClassInfo_, allocate$UTF_16LE);
	return class$;
}

$Class* UTF_16LE::class$ = nullptr;

		} // cs
	} // nio
} // sun
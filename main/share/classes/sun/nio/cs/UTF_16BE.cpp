#include <sun/nio/cs/UTF_16BE.h>

#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <sun/nio/cs/StandardCharsets.h>
#include <sun/nio/cs/UTF_16BE$Decoder.h>
#include <sun/nio/cs/UTF_16BE$Encoder.h>
#include <sun/nio/cs/Unicode.h>
#include <jcpp.h>

#undef UTF_16BE

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $StandardCharsets = ::sun::nio::cs::StandardCharsets;
using $UTF_16BE$Decoder = ::sun::nio::cs::UTF_16BE$Decoder;
using $UTF_16BE$Encoder = ::sun::nio::cs::UTF_16BE$Encoder;
using $Unicode = ::sun::nio::cs::Unicode;

namespace sun {
	namespace nio {
		namespace cs {

$MethodInfo _UTF_16BE_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(UTF_16BE, init$, void)},
	{"contains", "(Ljava/nio/charset/Charset;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(UTF_16BE, contains, bool, $Charset*)},
	{"historicalName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(UTF_16BE, historicalName, $String*)},
	{"newDecoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PUBLIC, $virtualMethod(UTF_16BE, newDecoder, $CharsetDecoder*)},
	{"newEncoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PUBLIC, $virtualMethod(UTF_16BE, newEncoder, $CharsetEncoder*)},
	{}
};

$InnerClassInfo _UTF_16BE_InnerClassesInfo_[] = {
	{"sun.nio.cs.UTF_16BE$Encoder", "sun.nio.cs.UTF_16BE", "Encoder", $PRIVATE | $STATIC},
	{"sun.nio.cs.UTF_16BE$Decoder", "sun.nio.cs.UTF_16BE", "Decoder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _UTF_16BE_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.UTF_16BE",
	"sun.nio.cs.Unicode",
	nullptr,
	nullptr,
	_UTF_16BE_MethodInfo_,
	nullptr,
	nullptr,
	_UTF_16BE_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.cs.UTF_16BE$Encoder,sun.nio.cs.UTF_16BE$Decoder"
};

$Object* allocate$UTF_16BE($Class* clazz) {
	return $of($alloc(UTF_16BE));
}

void UTF_16BE::init$() {
	$Unicode::init$("UTF-16BE"_s, $($StandardCharsets::aliases_UTF_16BE()));
}

$String* UTF_16BE::historicalName() {
	return "UnicodeBigUnmarked"_s;
}

$CharsetDecoder* UTF_16BE::newDecoder() {
	return $new($UTF_16BE$Decoder, this);
}

$CharsetEncoder* UTF_16BE::newEncoder() {
	return $new($UTF_16BE$Encoder, this);
}

bool UTF_16BE::contains($Charset* cs) {
	return $Unicode::contains(cs);
}

UTF_16BE::UTF_16BE() {
}

$Class* UTF_16BE::load$($String* name, bool initialize) {
	$loadClass(UTF_16BE, name, initialize, &_UTF_16BE_ClassInfo_, allocate$UTF_16BE);
	return class$;
}

$Class* UTF_16BE::class$ = nullptr;

		} // cs
	} // nio
} // sun
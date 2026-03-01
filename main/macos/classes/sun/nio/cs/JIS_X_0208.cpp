#include <sun/nio/cs/JIS_X_0208.h>

#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <sun/nio/cs/DoubleByte$Decoder_DBCSONLY.h>
#include <sun/nio/cs/DoubleByte$Encoder_DBCSONLY.h>
#include <sun/nio/cs/JIS_X_0208$DecodeHolder.h>
#include <sun/nio/cs/JIS_X_0208$EncodeHolder.h>
#include <sun/nio/cs/StandardCharsets.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $DoubleByte$Decoder_DBCSONLY = ::sun::nio::cs::DoubleByte$Decoder_DBCSONLY;
using $DoubleByte$Encoder_DBCSONLY = ::sun::nio::cs::DoubleByte$Encoder_DBCSONLY;
using $JIS_X_0208$DecodeHolder = ::sun::nio::cs::JIS_X_0208$DecodeHolder;
using $JIS_X_0208$EncodeHolder = ::sun::nio::cs::JIS_X_0208$EncodeHolder;
using $StandardCharsets = ::sun::nio::cs::StandardCharsets;

namespace sun {
	namespace nio {
		namespace cs {

$MethodInfo _JIS_X_0208_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "()V", nullptr, $PUBLIC, $method(JIS_X_0208, init$, void)},
	{"contains", "(Ljava/nio/charset/Charset;)Z", nullptr, $PUBLIC, $virtualMethod(JIS_X_0208, contains, bool, $Charset*)},
	{"historicalName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JIS_X_0208, historicalName, $String*)},
	{"newDecoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PUBLIC, $virtualMethod(JIS_X_0208, newDecoder, $CharsetDecoder*)},
	{"newEncoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PUBLIC, $virtualMethod(JIS_X_0208, newEncoder, $CharsetEncoder*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _JIS_X_0208_InnerClassesInfo_[] = {
	{"sun.nio.cs.JIS_X_0208$EncodeHolder", "sun.nio.cs.JIS_X_0208", "EncodeHolder", $STATIC},
	{"sun.nio.cs.JIS_X_0208$DecodeHolder", "sun.nio.cs.JIS_X_0208", "DecodeHolder", $STATIC},
	{}
};

$ClassInfo _JIS_X_0208_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.JIS_X_0208",
	"java.nio.charset.Charset",
	"sun.nio.cs.HistoricallyNamedCharset",
	nullptr,
	_JIS_X_0208_MethodInfo_,
	nullptr,
	nullptr,
	_JIS_X_0208_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.cs.JIS_X_0208$EncodeHolder,sun.nio.cs.JIS_X_0208$DecodeHolder"
};

$Object* allocate$JIS_X_0208($Class* clazz) {
	return $of($alloc(JIS_X_0208));
}

int32_t JIS_X_0208::hashCode() {
	 return this->$Charset::hashCode();
}

bool JIS_X_0208::equals(Object$* ob) {
	 return this->$Charset::equals(ob);
}

$String* JIS_X_0208::toString() {
	 return this->$Charset::toString();
}

$Object* JIS_X_0208::clone() {
	 return this->$Charset::clone();
}

void JIS_X_0208::finalize() {
	this->$Charset::finalize();
}

void JIS_X_0208::init$() {
	$Charset::init$("x-JIS0208"_s, $($StandardCharsets::aliases_JIS_X_0208()));
}

$String* JIS_X_0208::historicalName() {
	return "JIS0208"_s;
}

bool JIS_X_0208::contains($Charset* cs) {
	return ($instanceOf(JIS_X_0208, cs));
}

$CharsetDecoder* JIS_X_0208::newDecoder() {
	$init($JIS_X_0208$DecodeHolder);
	return $new($DoubleByte$Decoder_DBCSONLY, this, $JIS_X_0208$DecodeHolder::b2c, $JIS_X_0208$DecodeHolder::b2cSB, 33, 126, false);
}

$CharsetEncoder* JIS_X_0208::newEncoder() {
	$init($JIS_X_0208$EncodeHolder);
	return $new($DoubleByte$Encoder_DBCSONLY, this, $$new($bytes, {
		(int8_t)33,
		(int8_t)41
	}), $JIS_X_0208$EncodeHolder::c2b, $JIS_X_0208$EncodeHolder::c2bIndex, false);
}

JIS_X_0208::JIS_X_0208() {
}

$Class* JIS_X_0208::load$($String* name, bool initialize) {
	$loadClass(JIS_X_0208, name, initialize, &_JIS_X_0208_ClassInfo_, allocate$JIS_X_0208);
	return class$;
}

$Class* JIS_X_0208::class$ = nullptr;

		} // cs
	} // nio
} // sun
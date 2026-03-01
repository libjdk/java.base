#include <sun/nio/cs/JIS_X_0212_Solaris.h>

#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <sun/nio/cs/DoubleByte$Decoder_DBCSONLY.h>
#include <sun/nio/cs/DoubleByte$Encoder_DBCSONLY.h>
#include <sun/nio/cs/JIS_X_0212_Solaris$DecodeHolder.h>
#include <sun/nio/cs/JIS_X_0212_Solaris$EncodeHolder.h>
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
using $JIS_X_0212_Solaris$DecodeHolder = ::sun::nio::cs::JIS_X_0212_Solaris$DecodeHolder;
using $JIS_X_0212_Solaris$EncodeHolder = ::sun::nio::cs::JIS_X_0212_Solaris$EncodeHolder;
using $StandardCharsets = ::sun::nio::cs::StandardCharsets;

namespace sun {
	namespace nio {
		namespace cs {

$MethodInfo _JIS_X_0212_Solaris_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "()V", nullptr, $PUBLIC, $method(JIS_X_0212_Solaris, init$, void)},
	{"contains", "(Ljava/nio/charset/Charset;)Z", nullptr, $PUBLIC, $virtualMethod(JIS_X_0212_Solaris, contains, bool, $Charset*)},
	{"historicalName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JIS_X_0212_Solaris, historicalName, $String*)},
	{"newDecoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PUBLIC, $virtualMethod(JIS_X_0212_Solaris, newDecoder, $CharsetDecoder*)},
	{"newEncoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PUBLIC, $virtualMethod(JIS_X_0212_Solaris, newEncoder, $CharsetEncoder*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _JIS_X_0212_Solaris_InnerClassesInfo_[] = {
	{"sun.nio.cs.JIS_X_0212_Solaris$EncodeHolder", "sun.nio.cs.JIS_X_0212_Solaris", "EncodeHolder", $STATIC},
	{"sun.nio.cs.JIS_X_0212_Solaris$DecodeHolder", "sun.nio.cs.JIS_X_0212_Solaris", "DecodeHolder", $STATIC},
	{}
};

$ClassInfo _JIS_X_0212_Solaris_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.JIS_X_0212_Solaris",
	"java.nio.charset.Charset",
	"sun.nio.cs.HistoricallyNamedCharset",
	nullptr,
	_JIS_X_0212_Solaris_MethodInfo_,
	nullptr,
	nullptr,
	_JIS_X_0212_Solaris_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.cs.JIS_X_0212_Solaris$EncodeHolder,sun.nio.cs.JIS_X_0212_Solaris$DecodeHolder"
};

$Object* allocate$JIS_X_0212_Solaris($Class* clazz) {
	return $of($alloc(JIS_X_0212_Solaris));
}

int32_t JIS_X_0212_Solaris::hashCode() {
	 return this->$Charset::hashCode();
}

bool JIS_X_0212_Solaris::equals(Object$* ob) {
	 return this->$Charset::equals(ob);
}

$String* JIS_X_0212_Solaris::toString() {
	 return this->$Charset::toString();
}

$Object* JIS_X_0212_Solaris::clone() {
	 return this->$Charset::clone();
}

void JIS_X_0212_Solaris::finalize() {
	this->$Charset::finalize();
}

void JIS_X_0212_Solaris::init$() {
	$Charset::init$("x-JIS0212_Solaris"_s, $($StandardCharsets::aliases_JIS_X_0212_Solaris()));
}

$String* JIS_X_0212_Solaris::historicalName() {
	return "JIS_X_0212_Solaris"_s;
}

bool JIS_X_0212_Solaris::contains($Charset* cs) {
	return ($instanceOf(JIS_X_0212_Solaris, cs));
}

$CharsetDecoder* JIS_X_0212_Solaris::newDecoder() {
	$init($JIS_X_0212_Solaris$DecodeHolder);
	return $new($DoubleByte$Decoder_DBCSONLY, this, $JIS_X_0212_Solaris$DecodeHolder::b2c, $JIS_X_0212_Solaris$DecodeHolder::b2cSB, 33, 126, false);
}

$CharsetEncoder* JIS_X_0212_Solaris::newEncoder() {
	$init($JIS_X_0212_Solaris$EncodeHolder);
	return $new($DoubleByte$Encoder_DBCSONLY, this, $$new($bytes, {
		(int8_t)34,
		(int8_t)68
	}), $JIS_X_0212_Solaris$EncodeHolder::c2b, $JIS_X_0212_Solaris$EncodeHolder::c2bIndex, false);
}

JIS_X_0212_Solaris::JIS_X_0212_Solaris() {
}

$Class* JIS_X_0212_Solaris::load$($String* name, bool initialize) {
	$loadClass(JIS_X_0212_Solaris, name, initialize, &_JIS_X_0212_Solaris_ClassInfo_, allocate$JIS_X_0212_Solaris);
	return class$;
}

$Class* JIS_X_0212_Solaris::class$ = nullptr;

		} // cs
	} // nio
} // sun
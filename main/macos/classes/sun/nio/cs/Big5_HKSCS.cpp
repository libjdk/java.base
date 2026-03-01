#include <sun/nio/cs/Big5_HKSCS.h>

#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <sun/nio/cs/Big5.h>
#include <sun/nio/cs/Big5_HKSCS$Decoder.h>
#include <sun/nio/cs/Big5_HKSCS$Encoder.h>
#include <sun/nio/cs/StandardCharsets.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $Big5 = ::sun::nio::cs::Big5;
using $Big5_HKSCS$Decoder = ::sun::nio::cs::Big5_HKSCS$Decoder;
using $Big5_HKSCS$Encoder = ::sun::nio::cs::Big5_HKSCS$Encoder;
using $StandardCharsets = ::sun::nio::cs::StandardCharsets;

namespace sun {
	namespace nio {
		namespace cs {

$MethodInfo _Big5_HKSCS_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "()V", nullptr, $PUBLIC, $method(Big5_HKSCS, init$, void)},
	{"contains", "(Ljava/nio/charset/Charset;)Z", nullptr, $PUBLIC, $virtualMethod(Big5_HKSCS, contains, bool, $Charset*)},
	{"historicalName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Big5_HKSCS, historicalName, $String*)},
	{"newDecoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PUBLIC, $virtualMethod(Big5_HKSCS, newDecoder, $CharsetDecoder*)},
	{"newEncoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PUBLIC, $virtualMethod(Big5_HKSCS, newEncoder, $CharsetEncoder*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _Big5_HKSCS_InnerClassesInfo_[] = {
	{"sun.nio.cs.Big5_HKSCS$Encoder", "sun.nio.cs.Big5_HKSCS", "Encoder", $STATIC},
	{"sun.nio.cs.Big5_HKSCS$Decoder", "sun.nio.cs.Big5_HKSCS", "Decoder", $STATIC},
	{}
};

$ClassInfo _Big5_HKSCS_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.Big5_HKSCS",
	"java.nio.charset.Charset",
	"sun.nio.cs.HistoricallyNamedCharset",
	nullptr,
	_Big5_HKSCS_MethodInfo_,
	nullptr,
	nullptr,
	_Big5_HKSCS_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.cs.Big5_HKSCS$Encoder,sun.nio.cs.Big5_HKSCS$Decoder"
};

$Object* allocate$Big5_HKSCS($Class* clazz) {
	return $of($alloc(Big5_HKSCS));
}

int32_t Big5_HKSCS::hashCode() {
	 return this->$Charset::hashCode();
}

bool Big5_HKSCS::equals(Object$* ob) {
	 return this->$Charset::equals(ob);
}

$String* Big5_HKSCS::toString() {
	 return this->$Charset::toString();
}

$Object* Big5_HKSCS::clone() {
	 return this->$Charset::clone();
}

void Big5_HKSCS::finalize() {
	this->$Charset::finalize();
}

void Big5_HKSCS::init$() {
	$Charset::init$("Big5-HKSCS"_s, $($StandardCharsets::aliases_Big5_HKSCS()));
}

$String* Big5_HKSCS::historicalName() {
	return "Big5_HKSCS"_s;
}

bool Big5_HKSCS::contains($Charset* cs) {
	return (($nc($($nc(cs)->name()))->equals("US-ASCII"_s)) || ($instanceOf($Big5, cs)) || ($instanceOf(Big5_HKSCS, cs)));
}

$CharsetDecoder* Big5_HKSCS::newDecoder() {
	return $new($Big5_HKSCS$Decoder, this);
}

$CharsetEncoder* Big5_HKSCS::newEncoder() {
	return $new($Big5_HKSCS$Encoder, this);
}

Big5_HKSCS::Big5_HKSCS() {
}

$Class* Big5_HKSCS::load$($String* name, bool initialize) {
	$loadClass(Big5_HKSCS, name, initialize, &_Big5_HKSCS_ClassInfo_, allocate$Big5_HKSCS);
	return class$;
}

$Class* Big5_HKSCS::class$ = nullptr;

		} // cs
	} // nio
} // sun
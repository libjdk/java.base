#include <sun/nio/cs/EUC_JP_LINUX.h>

#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetDecoder.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <sun/nio/cs/EUC_JP_LINUX$Decoder.h>
#include <sun/nio/cs/EUC_JP_LINUX$Encoder.h>
#include <sun/nio/cs/JIS_X_0201.h>
#include <sun/nio/cs/StandardCharsets.h>
#include <jcpp.h>

#undef EUC_JP_LINUX

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $CharsetDecoder = ::java::nio::charset::CharsetDecoder;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $EUC_JP_LINUX$Decoder = ::sun::nio::cs::EUC_JP_LINUX$Decoder;
using $EUC_JP_LINUX$Encoder = ::sun::nio::cs::EUC_JP_LINUX$Encoder;
using $JIS_X_0201 = ::sun::nio::cs::JIS_X_0201;
using $StandardCharsets = ::sun::nio::cs::StandardCharsets;

namespace sun {
	namespace nio {
		namespace cs {

$MethodInfo _EUC_JP_LINUX_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"<init>", "()V", nullptr, $PUBLIC, $method(EUC_JP_LINUX, init$, void)},
	{"contains", "(Ljava/nio/charset/Charset;)Z", nullptr, $PUBLIC, $virtualMethod(EUC_JP_LINUX, contains, bool, $Charset*)},
	{"historicalName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(EUC_JP_LINUX, historicalName, $String*)},
	{"newDecoder", "()Ljava/nio/charset/CharsetDecoder;", nullptr, $PUBLIC, $virtualMethod(EUC_JP_LINUX, newDecoder, $CharsetDecoder*)},
	{"newEncoder", "()Ljava/nio/charset/CharsetEncoder;", nullptr, $PUBLIC, $virtualMethod(EUC_JP_LINUX, newEncoder, $CharsetEncoder*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _EUC_JP_LINUX_InnerClassesInfo_[] = {
	{"sun.nio.cs.EUC_JP_LINUX$Encoder", "sun.nio.cs.EUC_JP_LINUX", "Encoder", $PRIVATE | $STATIC},
	{"sun.nio.cs.EUC_JP_LINUX$Decoder", "sun.nio.cs.EUC_JP_LINUX", "Decoder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _EUC_JP_LINUX_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.nio.cs.EUC_JP_LINUX",
	"java.nio.charset.Charset",
	"sun.nio.cs.HistoricallyNamedCharset",
	nullptr,
	_EUC_JP_LINUX_MethodInfo_,
	nullptr,
	nullptr,
	_EUC_JP_LINUX_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.cs.EUC_JP_LINUX$Encoder,sun.nio.cs.EUC_JP_LINUX$Decoder"
};

$Object* allocate$EUC_JP_LINUX($Class* clazz) {
	return $of($alloc(EUC_JP_LINUX));
}

int32_t EUC_JP_LINUX::hashCode() {
	 return this->$Charset::hashCode();
}

bool EUC_JP_LINUX::equals(Object$* ob) {
	 return this->$Charset::equals(ob);
}

$String* EUC_JP_LINUX::toString() {
	 return this->$Charset::toString();
}

$Object* EUC_JP_LINUX::clone() {
	 return this->$Charset::clone();
}

void EUC_JP_LINUX::finalize() {
	this->$Charset::finalize();
}

void EUC_JP_LINUX::init$() {
	$Charset::init$("x-euc-jp-linux"_s, $($StandardCharsets::aliases_EUC_JP_LINUX()));
}

$String* EUC_JP_LINUX::historicalName() {
	return "EUC_JP_LINUX"_s;
}

bool EUC_JP_LINUX::contains($Charset* cs) {
	return (($instanceOf($JIS_X_0201, cs)) || ($nc($($nc(cs)->name()))->equals("US-ASCII"_s)) || ($instanceOf(EUC_JP_LINUX, cs)));
}

$CharsetDecoder* EUC_JP_LINUX::newDecoder() {
	return $new($EUC_JP_LINUX$Decoder, this);
}

$CharsetEncoder* EUC_JP_LINUX::newEncoder() {
	return $new($EUC_JP_LINUX$Encoder, this);
}

EUC_JP_LINUX::EUC_JP_LINUX() {
}

$Class* EUC_JP_LINUX::load$($String* name, bool initialize) {
	$loadClass(EUC_JP_LINUX, name, initialize, &_EUC_JP_LINUX_ClassInfo_, allocate$EUC_JP_LINUX);
	return class$;
}

$Class* EUC_JP_LINUX::class$ = nullptr;

		} // cs
	} // nio
} // sun
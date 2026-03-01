#include <sun/security/ssl/PskKeyExchangeModesExtension$PskKeyExchangeModesSpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/PskKeyExchangeModesExtension$PskKeyExchangeMode.h>
#include <sun/security/ssl/PskKeyExchangeModesExtension.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef DEFAULT
#undef ENGLISH
#undef PSK_DHE_KE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageFormat = ::java::text::MessageFormat;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $PskKeyExchangeModesExtension$PskKeyExchangeMode = ::sun::security::ssl::PskKeyExchangeModesExtension$PskKeyExchangeMode;
using $Record = ::sun::security::ssl::Record;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _PskKeyExchangeModesExtension$PskKeyExchangeModesSpec_FieldInfo_[] = {
	{"DEFAULT", "Lsun/security/ssl/PskKeyExchangeModesExtension$PskKeyExchangeModesSpec;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec, DEFAULT)},
	{"modes", "[B", nullptr, $FINAL, $field(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec, modes)},
	{}
};

$MethodInfo _PskKeyExchangeModesExtension$PskKeyExchangeModesSpec_MethodInfo_[] = {
	{"<init>", "([B)V", nullptr, 0, $method(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec, init$, void, $bytes*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"contains", "(Lsun/security/ssl/PskKeyExchangeModesExtension$PskKeyExchangeMode;)Z", nullptr, 0, $method(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec, contains, bool, $PskKeyExchangeModesExtension$PskKeyExchangeMode*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec, toString, $String*)},
	{}
};

$InnerClassInfo _PskKeyExchangeModesExtension$PskKeyExchangeModesSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.PskKeyExchangeModesExtension$PskKeyExchangeModesSpec", "sun.security.ssl.PskKeyExchangeModesExtension", "PskKeyExchangeModesSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PskKeyExchangeModesExtension$PskKeyExchangeModesSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.PskKeyExchangeModesExtension$PskKeyExchangeModesSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_PskKeyExchangeModesExtension$PskKeyExchangeModesSpec_FieldInfo_,
	_PskKeyExchangeModesExtension$PskKeyExchangeModesSpec_MethodInfo_,
	nullptr,
	nullptr,
	_PskKeyExchangeModesExtension$PskKeyExchangeModesSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.PskKeyExchangeModesExtension"
};

$Object* allocate$PskKeyExchangeModesExtension$PskKeyExchangeModesSpec($Class* clazz) {
	return $of($alloc(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec));
}

PskKeyExchangeModesExtension$PskKeyExchangeModesSpec* PskKeyExchangeModesExtension$PskKeyExchangeModesSpec::DEFAULT = nullptr;

void PskKeyExchangeModesExtension$PskKeyExchangeModesSpec::init$($bytes* modes) {
	$set(this, modes, modes);
}

void PskKeyExchangeModesExtension$PskKeyExchangeModesSpec::init$($HandshakeContext* hc, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	if ($nc(m)->remaining() < 2) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid psk_key_exchange_modes extension: insufficient data"_s)))));
	}
	$set(this, modes, $Record::getBytes8(m));
}

bool PskKeyExchangeModesExtension$PskKeyExchangeModesSpec::contains($PskKeyExchangeModesExtension$PskKeyExchangeMode* mode) {
	if (this->modes != nullptr) {
		{
			$var($bytes, arr$, this->modes);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				int8_t m = arr$->get(i$);
				{
					if ($nc(mode)->id == m) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

$String* PskKeyExchangeModesExtension$PskKeyExchangeModesSpec::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"ke_modes\": \'[\'{0}\']\'"_s, $Locale::ENGLISH));
	if (this->modes == nullptr || $nc(this->modes)->length == 0) {
		$var($ObjectArray, messageFields, $new($ObjectArray, {$of("<no PSK key exchange modes specified>"_s)}));
		return messageFormat->format(messageFields);
	} else {
		$var($StringBuilder, builder, $new($StringBuilder, 64));
		bool isFirst = true;
		{
			$var($bytes, arr$, this->modes);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				int8_t mode = arr$->get(i$);
				{
					if (isFirst) {
						isFirst = false;
					} else {
						builder->append(", "_s);
					}
					builder->append($($PskKeyExchangeModesExtension$PskKeyExchangeMode::nameOf(mode)));
				}
			}
		}
		$var($ObjectArray, messageFields, $new($ObjectArray, {$($of(builder->toString()))}));
		return messageFormat->format(messageFields);
	}
}

void clinit$PskKeyExchangeModesExtension$PskKeyExchangeModesSpec($Class* class$) {
	$init($PskKeyExchangeModesExtension$PskKeyExchangeMode);
	$assignStatic(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec::DEFAULT, $new(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec, $$new($bytes, {$PskKeyExchangeModesExtension$PskKeyExchangeMode::PSK_DHE_KE->id})));
}

PskKeyExchangeModesExtension$PskKeyExchangeModesSpec::PskKeyExchangeModesExtension$PskKeyExchangeModesSpec() {
}

$Class* PskKeyExchangeModesExtension$PskKeyExchangeModesSpec::load$($String* name, bool initialize) {
	$loadClass(PskKeyExchangeModesExtension$PskKeyExchangeModesSpec, name, initialize, &_PskKeyExchangeModesExtension$PskKeyExchangeModesSpec_ClassInfo_, clinit$PskKeyExchangeModesExtension$PskKeyExchangeModesSpec, allocate$PskKeyExchangeModesExtension$PskKeyExchangeModesSpec);
	return class$;
}

$Class* PskKeyExchangeModesExtension$PskKeyExchangeModesSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun
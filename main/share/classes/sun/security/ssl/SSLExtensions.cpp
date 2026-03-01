#include <sun/security/ssl/SSLExtensions.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/ConnectionContext.h>
#include <sun/security/ssl/HandshakeAbsence.h>
#include <sun/security/ssl/HandshakeConsumer.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/HandshakeOutStream.h>
#include <sun/security/ssl/HandshakeProducer.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SSLExtension$ExtensionConsumer.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLHandshake$HandshakeMessage.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef CH_SUPPORTED_GROUPS
#undef DECODE_ERROR
#undef ENGLISH
#undef SERVER_HELLO
#undef UNSUPPORTED_EXTENSION

using $SSLExtensionArray = $Array<::sun::security::ssl::SSLExtension>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageFormat = ::java::text::MessageFormat;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Alert = ::sun::security::ssl::Alert;
using $ConnectionContext = ::sun::security::ssl::ConnectionContext;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $HandshakeOutStream = ::sun::security::ssl::HandshakeOutStream;
using $Record = ::sun::security::ssl::Record;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLHandshake$HandshakeMessage = ::sun::security::ssl::SSLHandshake$HandshakeMessage;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLExtensions_FieldInfo_[] = {
	{"handshakeMessage", "Lsun/security/ssl/SSLHandshake$HandshakeMessage;", nullptr, $PRIVATE | $FINAL, $field(SSLExtensions, handshakeMessage)},
	{"extMap", "Ljava/util/Map;", "Ljava/util/Map<Lsun/security/ssl/SSLExtension;[B>;", $PRIVATE | $FINAL, $field(SSLExtensions, extMap)},
	{"encodedLength", "I", nullptr, $PRIVATE, $field(SSLExtensions, encodedLength)},
	{"logMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;[B>;", $PRIVATE | $FINAL, $field(SSLExtensions, logMap)},
	{}
};

$MethodInfo _SSLExtensions_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/SSLHandshake$HandshakeMessage;)V", nullptr, 0, $method(SSLExtensions, init$, void, $SSLHandshake$HandshakeMessage*)},
	{"<init>", "(Lsun/security/ssl/SSLHandshake$HandshakeMessage;Ljava/nio/ByteBuffer;[Lsun/security/ssl/SSLExtension;)V", nullptr, 0, $method(SSLExtensions, init$, void, $SSLHandshake$HandshakeMessage*, $ByteBuffer*, $SSLExtensionArray*), "java.io.IOException"},
	{"consumeOnLoad", "(Lsun/security/ssl/HandshakeContext;[Lsun/security/ssl/SSLExtension;)V", nullptr, 0, $method(SSLExtensions, consumeOnLoad, void, $HandshakeContext*, $SSLExtensionArray*), "java.io.IOException"},
	{"consumeOnTrade", "(Lsun/security/ssl/HandshakeContext;[Lsun/security/ssl/SSLExtension;)V", nullptr, 0, $method(SSLExtensions, consumeOnTrade, void, $HandshakeContext*, $SSLExtensionArray*), "java.io.IOException"},
	{"get", "(Lsun/security/ssl/SSLExtension;)[B", nullptr, 0, $method(SSLExtensions, get, $bytes*, $SSLExtension*)},
	{"length", "()I", nullptr, 0, $method(SSLExtensions, length, int32_t)},
	{"produce", "(Lsun/security/ssl/HandshakeContext;[Lsun/security/ssl/SSLExtension;)V", nullptr, 0, $method(SSLExtensions, produce, void, $HandshakeContext*, $SSLExtensionArray*), "java.io.IOException"},
	{"reproduce", "(Lsun/security/ssl/HandshakeContext;[Lsun/security/ssl/SSLExtension;)V", nullptr, 0, $method(SSLExtensions, reproduce, void, $HandshakeContext*, $SSLExtensionArray*), "java.io.IOException"},
	{"send", "(Lsun/security/ssl/HandshakeOutStream;)V", nullptr, 0, $method(SSLExtensions, send, void, $HandshakeOutStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SSLExtensions, toString, $String*)},
	{"toString", "(I[B)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(SSLExtensions, toString, $String*, int32_t, $bytes*)},
	{}
};

$ClassInfo _SSLExtensions_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SSLExtensions",
	"java.lang.Object",
	nullptr,
	_SSLExtensions_FieldInfo_,
	_SSLExtensions_MethodInfo_
};

$Object* allocate$SSLExtensions($Class* clazz) {
	return $of($alloc(SSLExtensions));
}

void SSLExtensions::init$($SSLHandshake$HandshakeMessage* handshakeMessage) {
	$set(this, extMap, $new($LinkedHashMap));
	$init($SSLLogger);
	$set(this, logMap, $SSLLogger::isOn$ ? static_cast<$Map*>($new($LinkedHashMap)) : ($Map*)nullptr);
	$set(this, handshakeMessage, handshakeMessage);
	this->encodedLength = 2;
}

void SSLExtensions::init$($SSLHandshake$HandshakeMessage* hm, $ByteBuffer* m, $SSLExtensionArray* extensions) {
	$useLocalCurrentObjectStackCache();
	$set(this, extMap, $new($LinkedHashMap));
	$init($SSLLogger);
	$set(this, logMap, $SSLLogger::isOn$ ? static_cast<$Map*>($new($LinkedHashMap)) : ($Map*)nullptr);
	$set(this, handshakeMessage, hm);
	if ($nc(m)->remaining() < 2) {
		$init($Alert);
		$throw($($nc($nc($nc(hm)->handshakeContext)->conContext)->fatal($Alert::DECODE_ERROR, "Incorrect extensions: no length field"_s)));
	}
	int32_t len = $Record::getInt16(m);
	if (len > $nc(m)->remaining()) {
		$init($Alert);
		$throw($($nc($nc($nc(hm)->handshakeContext)->conContext)->fatal($Alert::DECODE_ERROR, "Insufficient extensions data"_s)));
	}
	this->encodedLength = len + 2;
	while (len > 0) {
		int32_t extId = $Record::getInt16(m);
		int32_t extLen = $Record::getInt16(m);
		if (extLen > $nc(m)->remaining()) {
			$init($Alert);
			$throw($($nc($nc($nc(hm)->handshakeContext)->conContext)->fatal($Alert::DECODE_ERROR, $$str({"Error parsing extension ("_s, $$str(extId), "): no sufficient data"_s}))));
		}
		bool isSupported = true;
		$SSLHandshake* handshakeType = $nc(hm)->handshakeType();
		bool var$0 = $SSLExtension::isConsumable(extId);
		if (var$0 && $SSLExtension::valueOf(handshakeType, extId) == nullptr) {
			$init($SSLHandshake);
			if (extId == $SSLExtension::CH_SUPPORTED_GROUPS->id && handshakeType == $SSLHandshake::SERVER_HELLO) {
				isSupported = false;
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::warning("Received buggy supported_groups extension in the ServerHello handshake message"_s, $$new($ObjectArray, 0));
				}
			} else {
				if (handshakeType == $SSLHandshake::SERVER_HELLO) {
					$init($Alert);
					$throw($($nc($nc(hm->handshakeContext)->conContext)->fatal($Alert::UNSUPPORTED_EXTENSION, $$str({"extension ("_s, $$str(extId), ") should not be presented in "_s, handshakeType->name$}))));
				} else {
					isSupported = false;
				}
			}
		}
		if (isSupported) {
			isSupported = false;
			{
				$var($SSLExtensionArray, arr$, extensions);
				int32_t len$ = $nc(arr$)->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$SSLExtension* extension = arr$->get(i$);
					{
						if (($nc(extension)->id != extId) || ($nc(extension)->onLoadConsumer == nullptr)) {
							continue;
						}
						if ($nc(extension)->handshakeType != handshakeType) {
							$init($Alert);
							$throw($($nc($nc(hm->handshakeContext)->conContext)->fatal($Alert::UNSUPPORTED_EXTENSION, $$str({"extension ("_s, $$str(extId), ") should not be presented in "_s, $nc(handshakeType)->name$}))));
						}
						$var($bytes, extData, $new($bytes, extLen));
						$nc(m)->get(extData);
						$nc(this->extMap)->put(extension, extData);
						if (this->logMap != nullptr) {
							$nc(this->logMap)->put($($Integer::valueOf(extId)), extData);
						}
						isSupported = true;
						break;
					}
				}
			}
		}
		if (!isSupported) {
			if (this->logMap != nullptr) {
				$var($bytes, extData, $new($bytes, extLen));
				$nc(m)->get(extData);
				$nc(this->logMap)->put($($Integer::valueOf(extId)), extData);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::fine("Ignore unknown or unsupported extension"_s, $$new($ObjectArray, {$($of(toString(extId, extData)))}));
				}
			} else {
				int32_t pos = $nc(m)->position() + extLen;
				m->position(pos);
			}
		}
		len -= extLen + 4;
	}
}

$bytes* SSLExtensions::get($SSLExtension* ext) {
	return $cast($bytes, $nc(this->extMap)->get(ext));
}

void SSLExtensions::consumeOnLoad($HandshakeContext* context, $SSLExtensionArray* extensions) {
	$useLocalCurrentObjectStackCache();
	{
		$var($SSLExtensionArray, arr$, extensions);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$SSLExtension* extension = arr$->get(i$);
			{
				if ($nc(context)->negotiatedProtocol != nullptr && !$nc(extension)->isAvailable(context->negotiatedProtocol)) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::fine($$str({"Ignore unsupported extension: "_s, extension->name$}), $$new($ObjectArray, 0));
					}
					continue;
				}
				if (!$nc(this->extMap)->containsKey(extension)) {
					if ($nc(extension)->onLoadAbsence != nullptr) {
						extension->absentOnLoad(context, this->handshakeMessage);
					} else {
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
							$SSLLogger::fine($$str({"Ignore unavailable extension: "_s, extension->name$}), $$new($ObjectArray, 0));
						}
					}
					continue;
				}
				if ($nc(extension)->onLoadConsumer == nullptr) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"Ignore unsupported extension: "_s, extension->name$}), $$new($ObjectArray, 0));
					}
					continue;
				}
				$var($ByteBuffer, m, $ByteBuffer::wrap($cast($bytes, $($nc(this->extMap)->get(extension)))));
				$nc(extension)->consumeOnLoad(context, this->handshakeMessage, m);
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::fine($$str({"Consumed extension: "_s, extension->name$}), $$new($ObjectArray, 0));
				}
			}
		}
	}
}

void SSLExtensions::consumeOnTrade($HandshakeContext* context, $SSLExtensionArray* extensions) {
	$useLocalCurrentObjectStackCache();
	{
		$var($SSLExtensionArray, arr$, extensions);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$SSLExtension* extension = arr$->get(i$);
			{
				if (!$nc(this->extMap)->containsKey(extension)) {
					if ($nc(extension)->onTradeAbsence != nullptr) {
						extension->absentOnTrade(context, this->handshakeMessage);
					} else {
						$init($SSLLogger);
						if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
							$SSLLogger::fine($$str({"Ignore unavailable extension: "_s, extension->name$}), $$new($ObjectArray, 0));
						}
					}
					continue;
				}
				if ($nc(extension)->onTradeConsumer == nullptr) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"Ignore impact of unsupported extension: "_s, extension->name$}), $$new($ObjectArray, 0));
					}
					continue;
				}
				$nc(extension)->consumeOnTrade(context, this->handshakeMessage);
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::fine($$str({"Populated with extension: "_s, extension->name$}), $$new($ObjectArray, 0));
				}
			}
		}
	}
}

void SSLExtensions::produce($HandshakeContext* context, $SSLExtensionArray* extensions) {
	$useLocalCurrentObjectStackCache();
	{
		$var($SSLExtensionArray, arr$, extensions);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$SSLExtension* extension = arr$->get(i$);
			{
				if ($nc(this->extMap)->containsKey(extension)) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::fine($$str({"Ignore, duplicated extension: "_s, $nc(extension)->name$}), $$new($ObjectArray, 0));
					}
					continue;
				}
				if ($nc(extension)->networkProducer == nullptr) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"Ignore, no extension producer defined: "_s, extension->name$}), $$new($ObjectArray, 0));
					}
					continue;
				}
				$var($bytes, encoded, $nc(extension)->produce(context, this->handshakeMessage));
				if (encoded != nullptr) {
					$nc(this->extMap)->put(extension, encoded);
					this->encodedLength += encoded->length + 4;
				} else {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::fine($$str({"Ignore, context unavailable extension: "_s, extension->name$}), $$new($ObjectArray, 0));
					}
				}
			}
		}
	}
}

void SSLExtensions::reproduce($HandshakeContext* context, $SSLExtensionArray* extensions) {
	$useLocalCurrentObjectStackCache();
	{
		$var($SSLExtensionArray, arr$, extensions);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$SSLExtension* extension = arr$->get(i$);
			{
				if ($nc(extension)->networkProducer == nullptr) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::warning($$str({"Ignore, no extension producer defined: "_s, extension->name$}), $$new($ObjectArray, 0));
					}
					continue;
				}
				$var($bytes, encoded, $nc(extension)->produce(context, this->handshakeMessage));
				if (encoded != nullptr) {
					if ($nc(this->extMap)->containsKey(extension)) {
						$var($bytes, old, $cast($bytes, $nc(this->extMap)->replace(extension, encoded)));
						if (old != nullptr) {
							this->encodedLength -= old->length + 4;
						}
						this->encodedLength += encoded->length + 4;
					} else {
						$nc(this->extMap)->put(extension, encoded);
						this->encodedLength += encoded->length + 4;
					}
				} else {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::fine($$str({"Ignore, context unavailable extension: "_s, extension->name$}), $$new($ObjectArray, 0));
					}
				}
			}
		}
	}
}

int32_t SSLExtensions::length() {
	if ($nc(this->extMap)->isEmpty()) {
		return 0;
	} else {
		return this->encodedLength;
	}
}

void SSLExtensions::send($HandshakeOutStream* hos) {
	$useLocalCurrentObjectStackCache();
	int32_t extsLen = length();
	if (extsLen == 0) {
		return;
	}
	$nc(hos)->putInt16(extsLen - 2);
	{
		$var($SSLExtensionArray, arr$, $SSLExtension::values());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$SSLExtension* ext = arr$->get(i$);
			{
				$var($bytes, extData, $cast($bytes, $nc(this->extMap)->get(ext)));
				if (extData != nullptr) {
					hos->putInt16($nc(ext)->id);
					hos->putBytes16(extData);
				}
			}
		}
	}
}

$String* SSLExtensions::toString() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(this->extMap)->isEmpty();
	if (var$0 && (this->logMap == nullptr || $nc(this->logMap)->isEmpty())) {
		return "<no extension>"_s;
	} else {
		$var($StringBuilder, builder, $new($StringBuilder, 512));
		if (this->logMap != nullptr && !$nc(this->logMap)->isEmpty()) {
			{
				$var($Iterator, i$, $nc($($nc(this->logMap)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, en, $cast($Map$Entry, i$->next()));
					{
						$var($SSLHandshake, var$1, $nc(this->handshakeMessage)->handshakeType());
						$SSLExtension* ext = $SSLExtension::valueOf(var$1, $nc(($cast($Integer, $($nc(en)->getKey()))))->intValue());
						if (builder->length() != 0) {
							builder->append(",\n"_s);
						}
						if (ext != nullptr) {
							builder->append($(ext->toString($nc(this->handshakeMessage)->handshakeContext, $($ByteBuffer::wrap($cast($bytes, $($nc(en)->getValue())))))));
						} else {
							int32_t var$2 = $nc(($cast($Integer, $($nc(en)->getKey()))))->intValue();
							builder->append($(toString(var$2, $cast($bytes, $(en->getValue())))));
						}
					}
				}
			}
			return builder->toString();
		} else {
			{
				$var($Iterator, i$, $nc($($nc(this->extMap)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, en, $cast($Map$Entry, i$->next()));
					{
						if (builder->length() != 0) {
							builder->append(",\n"_s);
						}
						builder->append($($nc(($cast($SSLExtension, $($nc(en)->getKey()))))->toString($nc(this->handshakeMessage)->handshakeContext, $($ByteBuffer::wrap($cast($bytes, $(en->getValue())))))));
					}
				}
			}
			return builder->toString();
		}
	}
}

$String* SSLExtensions::toString(int32_t extId, $bytes* extData) {
	$useLocalCurrentObjectStackCache();
	$var($String, extName, $SSLExtension::nameOf(extId));
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"{0} ({1})\": \'{\'\n{2}\n\'}\'"_s, $Locale::ENGLISH));
	$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
	$var($String, encoded, hexEncoder->encodeBuffer(extData));
	$var($ObjectArray, messageFields, $new($ObjectArray, {
		$of(extName),
		$($of($Integer::valueOf(extId))),
		$($of($Utilities::indent(encoded)))
	}));
	return messageFormat->format(messageFields);
}

SSLExtensions::SSLExtensions() {
}

$Class* SSLExtensions::load$($String* name, bool initialize) {
	$loadClass(SSLExtensions, name, initialize, &_SSLExtensions_ClassInfo_, allocate$SSLExtensions);
	return class$;
}

$Class* SSLExtensions::class$ = nullptr;

		} // ssl
	} // security
} // sun
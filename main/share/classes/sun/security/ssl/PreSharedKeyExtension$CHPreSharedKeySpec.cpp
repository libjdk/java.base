#include <sun/security/ssl/PreSharedKeyExtension$CHPreSharedKeySpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/PreSharedKeyExtension$PskIdentity.h>
#include <sun/security/ssl/PreSharedKeyExtension.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/TransportContext.h>
#include <sun/security/ssl/Utilities.h>
#include <sun/security/util/HexDumpEncoder.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef ENGLISH

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageFormat = ::java::text::MessageFormat;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $PreSharedKeyExtension$PskIdentity = ::sun::security::ssl::PreSharedKeyExtension$PskIdentity;
using $Record = ::sun::security::ssl::Record;
using $TransportContext = ::sun::security::ssl::TransportContext;
using $Utilities = ::sun::security::ssl::Utilities;
using $HexDumpEncoder = ::sun::security::util::HexDumpEncoder;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _PreSharedKeyExtension$CHPreSharedKeySpec_FieldInfo_[] = {
	{"identities", "Ljava/util/List;", "Ljava/util/List<Lsun/security/ssl/PreSharedKeyExtension$PskIdentity;>;", $FINAL, $field(PreSharedKeyExtension$CHPreSharedKeySpec, identities)},
	{"binders", "Ljava/util/List;", "Ljava/util/List<[B>;", $FINAL, $field(PreSharedKeyExtension$CHPreSharedKeySpec, binders)},
	{}
};

$MethodInfo _PreSharedKeyExtension$CHPreSharedKeySpec_MethodInfo_[] = {
	{"<init>", "(Ljava/util/List;Ljava/util/List;)V", "(Ljava/util/List<Lsun/security/ssl/PreSharedKeyExtension$PskIdentity;>;Ljava/util/List<[B>;)V", 0, $method(PreSharedKeyExtension$CHPreSharedKeySpec, init$, void, $List*, $List*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(PreSharedKeyExtension$CHPreSharedKeySpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"bindersString", "()Ljava/lang/String;", nullptr, 0, $method(PreSharedKeyExtension$CHPreSharedKeySpec, bindersString, $String*)},
	{"getBindersEncodedLength", "()I", nullptr, 0, $method(PreSharedKeyExtension$CHPreSharedKeySpec, getBindersEncodedLength, int32_t)},
	{"getEncoded", "()[B", nullptr, 0, $method(PreSharedKeyExtension$CHPreSharedKeySpec, getEncoded, $bytes*), "java.io.IOException"},
	{"getIdsEncodedLength", "()I", nullptr, 0, $method(PreSharedKeyExtension$CHPreSharedKeySpec, getIdsEncodedLength, int32_t)},
	{"identitiesString", "()Ljava/lang/String;", nullptr, 0, $method(PreSharedKeyExtension$CHPreSharedKeySpec, identitiesString, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PreSharedKeyExtension$CHPreSharedKeySpec, toString, $String*)},
	{}
};

$InnerClassInfo _PreSharedKeyExtension$CHPreSharedKeySpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeySpec", "sun.security.ssl.PreSharedKeyExtension", "CHPreSharedKeySpec", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _PreSharedKeyExtension$CHPreSharedKeySpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.PreSharedKeyExtension$CHPreSharedKeySpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_PreSharedKeyExtension$CHPreSharedKeySpec_FieldInfo_,
	_PreSharedKeyExtension$CHPreSharedKeySpec_MethodInfo_,
	nullptr,
	nullptr,
	_PreSharedKeyExtension$CHPreSharedKeySpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.PreSharedKeyExtension"
};

$Object* allocate$PreSharedKeyExtension$CHPreSharedKeySpec($Class* clazz) {
	return $of($alloc(PreSharedKeyExtension$CHPreSharedKeySpec));
}

void PreSharedKeyExtension$CHPreSharedKeySpec::init$($List* identities, $List* binders) {
	$set(this, identities, identities);
	$set(this, binders, binders);
}

void PreSharedKeyExtension$CHPreSharedKeySpec::init$($HandshakeContext* hc, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	if ($nc(m)->remaining() < 44) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid pre_shared_key extension: insufficient data (length="_s, $$str(m->remaining()), ")"_s}))))));
	}
	int32_t idEncodedLength = $Record::getInt16(m);
	if (idEncodedLength < 7) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid pre_shared_key extension: insufficient identities (length="_s, $$str(idEncodedLength), ")"_s}))))));
	}
	$set(this, identities, $new($ArrayList));
	int32_t idReadLength = 0;
	while (idReadLength < idEncodedLength) {
		$var($bytes, id, $Record::getBytes16(m));
		if ($nc(id)->length < 1) {
			$init($Alert);
			$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid pre_shared_key extension: insufficient identity (length="_s, $$str(id->length), ")"_s}))))));
		}
		int32_t obfuscatedTicketAge = $Record::getInt32(m);
		$var($PreSharedKeyExtension$PskIdentity, pskId, $new($PreSharedKeyExtension$PskIdentity, id, obfuscatedTicketAge));
		$nc(this->identities)->add(pskId);
		idReadLength += pskId->getEncodedLength();
	}
	if ($nc(m)->remaining() < 35) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid pre_shared_key extension: insufficient binders data (length="_s, $$str(m->remaining()), ")"_s}))))));
	}
	int32_t bindersEncodedLen = $Record::getInt16(m);
	if (bindersEncodedLen < 33) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid pre_shared_key extension: insufficient binders (length="_s, $$str(bindersEncodedLen), ")"_s}))))));
	}
	$set(this, binders, $new($ArrayList));
	int32_t bindersReadLength = 0;
	while (bindersReadLength < bindersEncodedLen) {
		$var($bytes, binder, $Record::getBytes8(m));
		if ($nc(binder)->length < 32) {
			$init($Alert);
			$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, $$str({"Invalid pre_shared_key extension: insufficient binder entry (length="_s, $$str(binder->length), ")"_s}))))));
		}
		$nc(this->binders)->add(binder);
		bindersReadLength += 1 + $nc(binder)->length;
	}
}

int32_t PreSharedKeyExtension$CHPreSharedKeySpec::getIdsEncodedLength() {
	$useLocalCurrentObjectStackCache();
	int32_t idEncodedLength = 0;
	{
		$var($Iterator, i$, $nc(this->identities)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PreSharedKeyExtension$PskIdentity, curId, $cast($PreSharedKeyExtension$PskIdentity, i$->next()));
			{
				idEncodedLength += $nc(curId)->getEncodedLength();
			}
		}
	}
	return idEncodedLength;
}

int32_t PreSharedKeyExtension$CHPreSharedKeySpec::getBindersEncodedLength() {
	$useLocalCurrentObjectStackCache();
	int32_t binderEncodedLength = 0;
	{
		$var($Iterator, i$, $nc(this->binders)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, curBinder, $cast($bytes, i$->next()));
			{
				binderEncodedLength += 1 + $nc(curBinder)->length;
			}
		}
	}
	return binderEncodedLength;
}

$bytes* PreSharedKeyExtension$CHPreSharedKeySpec::getEncoded() {
	$useLocalCurrentObjectStackCache();
	int32_t idsEncodedLength = getIdsEncodedLength();
	int32_t bindersEncodedLength = getBindersEncodedLength();
	int32_t encodedLength = 4 + idsEncodedLength + bindersEncodedLength;
	$var($bytes, buffer, $new($bytes, encodedLength));
	$var($ByteBuffer, m, $ByteBuffer::wrap(buffer));
	$Record::putInt16(m, idsEncodedLength);
	{
		$var($Iterator, i$, $nc(this->identities)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PreSharedKeyExtension$PskIdentity, curId, $cast($PreSharedKeyExtension$PskIdentity, i$->next()));
			{
				$nc(curId)->writeEncoded(m);
			}
		}
	}
	$Record::putInt16(m, bindersEncodedLength);
	{
		$var($Iterator, i$, $nc(this->binders)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, curBinder, $cast($bytes, i$->next()));
			{
				$Record::putBytes8(m, curBinder);
			}
		}
	}
	return buffer;
}

$String* PreSharedKeyExtension$CHPreSharedKeySpec::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"PreSharedKey\": \'{\'\n  \"identities\": \'{\'\n{0}\n  \'}\'  \"binders\": \"{1}\",\n\'}\'"_s, $Locale::ENGLISH));
	$var($ObjectArray, messageFields, $new($ObjectArray, {
		$($of($Utilities::indent($(identitiesString())))),
		$($of($Utilities::indent($(bindersString()))))
	}));
	return messageFormat->format(messageFields);
}

$String* PreSharedKeyExtension$CHPreSharedKeySpec::identitiesString() {
	$useLocalCurrentObjectStackCache();
	$var($HexDumpEncoder, hexEncoder, $new($HexDumpEncoder));
	$var($StringBuilder, result, $new($StringBuilder));
	{
		$var($Iterator, i$, $nc(this->identities)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PreSharedKeyExtension$PskIdentity, curId, $cast($PreSharedKeyExtension$PskIdentity, i$->next()));
			{
				result->append($$str({"  {\n"_s, $($Utilities::indent($(hexEncoder->encode($nc(curId)->identity)), "    "_s)), "\n  }\n"_s}));
			}
		}
	}
	return result->toString();
}

$String* PreSharedKeyExtension$CHPreSharedKeySpec::bindersString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, result, $new($StringBuilder));
	{
		$var($Iterator, i$, $nc(this->binders)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, curBinder, $cast($bytes, i$->next()));
			{
				result->append($$str({"{"_s, $($Utilities::toHexString(curBinder)), "}\n"_s}));
			}
		}
	}
	return result->toString();
}

PreSharedKeyExtension$CHPreSharedKeySpec::PreSharedKeyExtension$CHPreSharedKeySpec() {
}

$Class* PreSharedKeyExtension$CHPreSharedKeySpec::load$($String* name, bool initialize) {
	$loadClass(PreSharedKeyExtension$CHPreSharedKeySpec, name, initialize, &_PreSharedKeyExtension$CHPreSharedKeySpec_ClassInfo_, allocate$PreSharedKeyExtension$CHPreSharedKeySpec);
	return class$;
}

$Class* PreSharedKeyExtension$CHPreSharedKeySpec::class$ = nullptr;

		} // ssl
	} // security
} // sun
#include <sun/security/ssl/SupportedGroupsExtension$SupportedGroupsSpec.h>

#include <java/nio/ByteBuffer.h>
#include <java/text/MessageFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLProtocolException.h>
#include <sun/security/ssl/Alert.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/NamedGroup.h>
#include <sun/security/ssl/Record.h>
#include <sun/security/ssl/SupportedGroupsExtension.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

#undef DECODE_ERROR
#undef ENGLISH

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $MessageFormat = ::java::text::MessageFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $SSLProtocolException = ::javax::net::ssl::SSLProtocolException;
using $Alert = ::sun::security::ssl::Alert;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $NamedGroup = ::sun::security::ssl::NamedGroup;
using $Record = ::sun::security::ssl::Record;
using $TransportContext = ::sun::security::ssl::TransportContext;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SupportedGroupsExtension$SupportedGroupsSpec_FieldInfo_[] = {
	{"namedGroupsIds", "[I", nullptr, $FINAL, $field(SupportedGroupsExtension$SupportedGroupsSpec, namedGroupsIds)},
	{}
};

$MethodInfo _SupportedGroupsExtension$SupportedGroupsSpec_MethodInfo_[] = {
	{"<init>", "([I)V", nullptr, $PRIVATE, $method(SupportedGroupsExtension$SupportedGroupsSpec, init$, void, $ints*)},
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Lsun/security/ssl/NamedGroup;>;)V", $PRIVATE, $method(SupportedGroupsExtension$SupportedGroupsSpec, init$, void, $List*)},
	{"<init>", "(Lsun/security/ssl/HandshakeContext;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(SupportedGroupsExtension$SupportedGroupsSpec, init$, void, $HandshakeContext*, $ByteBuffer*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SupportedGroupsExtension$SupportedGroupsSpec, toString, $String*)},
	{}
};

$InnerClassInfo _SupportedGroupsExtension$SupportedGroupsSpec_InnerClassesInfo_[] = {
	{"sun.security.ssl.SupportedGroupsExtension$SupportedGroupsSpec", "sun.security.ssl.SupportedGroupsExtension", "SupportedGroupsSpec", $STATIC | $FINAL},
	{"sun.security.ssl.SSLExtension$SSLExtensionSpec", "sun.security.ssl.SSLExtension", "SSLExtensionSpec", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SupportedGroupsExtension$SupportedGroupsSpec_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.SupportedGroupsExtension$SupportedGroupsSpec",
	"java.lang.Object",
	"sun.security.ssl.SSLExtension$SSLExtensionSpec",
	_SupportedGroupsExtension$SupportedGroupsSpec_FieldInfo_,
	_SupportedGroupsExtension$SupportedGroupsSpec_MethodInfo_,
	nullptr,
	nullptr,
	_SupportedGroupsExtension$SupportedGroupsSpec_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SupportedGroupsExtension"
};

$Object* allocate$SupportedGroupsExtension$SupportedGroupsSpec($Class* clazz) {
	return $of($alloc(SupportedGroupsExtension$SupportedGroupsSpec));
}

void SupportedGroupsExtension$SupportedGroupsSpec::init$($ints* namedGroupsIds) {
	$set(this, namedGroupsIds, namedGroupsIds);
}

void SupportedGroupsExtension$SupportedGroupsSpec::init$($List* namedGroups) {
	$set(this, namedGroupsIds, $new($ints, $nc(namedGroups)->size()));
	int32_t i = 0;
	{
		$var($Iterator, i$, namedGroups->iterator());
		for (; $nc(i$)->hasNext();) {
			$NamedGroup* ng = $cast($NamedGroup, i$->next());
			{
				$nc(this->namedGroupsIds)->set(i++, $nc(ng)->id);
			}
		}
	}
}

void SupportedGroupsExtension$SupportedGroupsSpec::init$($HandshakeContext* hc, $ByteBuffer* m) {
	$useLocalCurrentObjectStackCache();
	if ($nc(m)->remaining() < 2) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid supported_groups extension: insufficient data"_s)))));
	}
	$var($bytes, ngs, $Record::getBytes16(m));
	if ($nc(m)->hasRemaining()) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid supported_groups extension: unknown extra data"_s)))));
	}
	if ((ngs == nullptr) || ($nc(ngs)->length == 0) || ($nc(ngs)->length % 2 != 0)) {
		$init($Alert);
		$throw($($nc($nc(hc)->conContext)->fatal($Alert::DECODE_ERROR, static_cast<$Throwable*>($$new($SSLProtocolException, "Invalid supported_groups extension: incomplete data"_s)))));
	}
	$var($ints, ids, $new($ints, $nc(ngs)->length / 2));
	{
		int32_t i = 0;
		int32_t j = 0;
		for (; i < ngs->length;) {
			int32_t var$0 = (((int32_t)(ngs->get(i++) & (uint32_t)255)) << 8);
			ids->set(j++, var$0 | ((int32_t)(ngs->get(i++) & (uint32_t)255)));
		}
	}
	$set(this, namedGroupsIds, ids);
}

$String* SupportedGroupsExtension$SupportedGroupsSpec::toString() {
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var($MessageFormat, messageFormat, $new($MessageFormat, "\"versions\": \'[\'{0}\']\'"_s, $Locale::ENGLISH));
	if (this->namedGroupsIds == nullptr || $nc(this->namedGroupsIds)->length == 0) {
		$var($ObjectArray, messageFields, $new($ObjectArray, {$of("<no supported named group specified>"_s)}));
		return messageFormat->format(messageFields);
	} else {
		$var($StringBuilder, builder, $new($StringBuilder, 512));
		bool isFirst = true;
		{
			$var($ints, arr$, this->namedGroupsIds);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				int32_t ngid = arr$->get(i$);
				{
					if (isFirst) {
						isFirst = false;
					} else {
						builder->append(", "_s);
					}
					builder->append($($NamedGroup::nameOf(ngid)));
				}
			}
		}
		$var($ObjectArray, messageFields, $new($ObjectArray, {$($of(builder->toString()))}));
		return messageFormat->format(messageFields);
	}
}

SupportedGroupsExtension$SupportedGroupsSpec::SupportedGroupsExtension$SupportedGroupsSpec() {
}

$Class* SupportedGroupsExtension$SupportedGroupsSpec::load$($String* name, bool initialize) {
	$loadClass(SupportedGroupsExtension$SupportedGroupsSpec, name, initialize, &_SupportedGroupsExtension$SupportedGroupsSpec_ClassInfo_, allocate$SupportedGroupsExtension$SupportedGroupsSpec);
	return class$;
}

$Class* SupportedGroupsExtension$SupportedGroupsSpec::class$ = nullptr;

		} // ssl
	} // security
} // sun
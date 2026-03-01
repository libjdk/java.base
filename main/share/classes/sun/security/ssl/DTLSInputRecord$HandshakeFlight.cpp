#include <sun/security/ssl/DTLSInputRecord$HandshakeFlight.h>

#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <sun/security/ssl/DTLSInputRecord.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <jcpp.h>

#undef HF_UNKNOWN
#undef NOT_APPLICABLE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _DTLSInputRecord$HandshakeFlight_FieldInfo_[] = {
	{"HF_UNKNOWN", "B", nullptr, $STATIC | $FINAL, $staticField(DTLSInputRecord$HandshakeFlight, HF_UNKNOWN)},
	{"handshakeType", "B", nullptr, 0, $field(DTLSInputRecord$HandshakeFlight, handshakeType)},
	{"flightEpoch", "I", nullptr, 0, $field(DTLSInputRecord$HandshakeFlight, flightEpoch)},
	{"minMessageSeq", "I", nullptr, 0, $field(DTLSInputRecord$HandshakeFlight, minMessageSeq)},
	{"maxMessageSeq", "I", nullptr, 0, $field(DTLSInputRecord$HandshakeFlight, maxMessageSeq)},
	{"maxRecordEpoch", "I", nullptr, 0, $field(DTLSInputRecord$HandshakeFlight, maxRecordEpoch)},
	{"maxRecordSeq", "J", nullptr, 0, $field(DTLSInputRecord$HandshakeFlight, maxRecordSeq)},
	{"holesMap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/Byte;Ljava/util/List<Lsun/security/ssl/DTLSInputRecord$HoleDescriptor;>;>;", 0, $field(DTLSInputRecord$HandshakeFlight, holesMap)},
	{}
};

$MethodInfo _DTLSInputRecord$HandshakeFlight_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(DTLSInputRecord$HandshakeFlight, init$, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DTLSInputRecord$HandshakeFlight, clone, $Object*)},
	{"isRetransmitOf", "(Lsun/security/ssl/DTLSInputRecord$HandshakeFlight;)Z", nullptr, 0, $method(DTLSInputRecord$HandshakeFlight, isRetransmitOf, bool, DTLSInputRecord$HandshakeFlight*)},
	{}
};

$InnerClassInfo _DTLSInputRecord$HandshakeFlight_InnerClassesInfo_[] = {
	{"sun.security.ssl.DTLSInputRecord$HandshakeFlight", "sun.security.ssl.DTLSInputRecord", "HandshakeFlight", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _DTLSInputRecord$HandshakeFlight_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.DTLSInputRecord$HandshakeFlight",
	"java.lang.Object",
	"java.lang.Cloneable",
	_DTLSInputRecord$HandshakeFlight_FieldInfo_,
	_DTLSInputRecord$HandshakeFlight_MethodInfo_,
	nullptr,
	nullptr,
	_DTLSInputRecord$HandshakeFlight_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.DTLSInputRecord"
};

$Object* allocate$DTLSInputRecord$HandshakeFlight($Class* clazz) {
	return $of($alloc(DTLSInputRecord$HandshakeFlight));
}

int8_t DTLSInputRecord$HandshakeFlight::HF_UNKNOWN = 0;

void DTLSInputRecord$HandshakeFlight::init$() {
	this->handshakeType = DTLSInputRecord$HandshakeFlight::HF_UNKNOWN;
	this->flightEpoch = 0;
	this->minMessageSeq = 0;
	this->maxMessageSeq = 0;
	this->maxRecordEpoch = 0;
	this->maxRecordSeq = -1;
	$set(this, holesMap, $new($HashMap, 5));
}

bool DTLSInputRecord$HandshakeFlight::isRetransmitOf(DTLSInputRecord$HandshakeFlight* hs) {
	return (hs != nullptr) && (this->handshakeType == hs->handshakeType) && (this->minMessageSeq == hs->minMessageSeq);
}

$Object* DTLSInputRecord$HandshakeFlight::clone() {
	$var(DTLSInputRecord$HandshakeFlight, hf, $new(DTLSInputRecord$HandshakeFlight));
	hf->handshakeType = this->handshakeType;
	hf->flightEpoch = this->flightEpoch;
	hf->minMessageSeq = this->minMessageSeq;
	hf->maxMessageSeq = this->maxMessageSeq;
	hf->maxRecordEpoch = this->maxRecordEpoch;
	hf->maxRecordSeq = this->maxRecordSeq;
	$set(hf, holesMap, $new($HashMap, static_cast<$Map*>(this->holesMap)));
	return $of(hf);
}

void clinit$DTLSInputRecord$HandshakeFlight($Class* class$) {
	$init($SSLHandshake);
	DTLSInputRecord$HandshakeFlight::HF_UNKNOWN = $SSLHandshake::NOT_APPLICABLE->id;
}

DTLSInputRecord$HandshakeFlight::DTLSInputRecord$HandshakeFlight() {
}

$Class* DTLSInputRecord$HandshakeFlight::load$($String* name, bool initialize) {
	$loadClass(DTLSInputRecord$HandshakeFlight, name, initialize, &_DTLSInputRecord$HandshakeFlight_ClassInfo_, clinit$DTLSInputRecord$HandshakeFlight, allocate$DTLSInputRecord$HandshakeFlight);
	return class$;
}

$Class* DTLSInputRecord$HandshakeFlight::class$ = nullptr;

		} // ssl
	} // security
} // sun
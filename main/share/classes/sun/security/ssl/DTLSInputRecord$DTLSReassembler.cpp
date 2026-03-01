#include <sun/security/ssl/DTLSInputRecord$DTLSReassembler.h>

#include <java/nio/ByteBuffer.h>
#include <java/security/GeneralSecurityException.h>
#include <java/util/AbstractSet.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/TreeSet.h>
#include <sun/security/ssl/Authenticator.h>
#include <sun/security/ssl/ContentType.h>
#include <sun/security/ssl/DTLSInputRecord$HandshakeFlight.h>
#include <sun/security/ssl/DTLSInputRecord$HandshakeFragment.h>
#include <sun/security/ssl/DTLSInputRecord$HoleDescriptor.h>
#include <sun/security/ssl/DTLSInputRecord$RecordFragment.h>
#include <sun/security/ssl/DTLSInputRecord.h>
#include <sun/security/ssl/DTLSRecord.h>
#include <sun/security/ssl/HandshakeHash.h>
#include <sun/security/ssl/Plaintext.h>
#include <sun/security/ssl/SSLCipher$SSLReadCipher.h>
#include <sun/security/ssl/SSLHandshake.h>
#include <sun/security/ssl/SSLLogger.h>
#include <jcpp.h>

#undef CERTIFICATE
#undef CERTIFICATE_VERIFY
#undef CHANGE_CIPHER_SPEC
#undef CLIENT_HELLO
#undef CLIENT_KEY_EXCHANGE
#undef FINISHED
#undef HANDSHAKE
#undef HELLO_REQUEST
#undef HELLO_VERIFY_REQUEST
#undef HF_UNKNOWN
#undef PLAINTEXT_NULL
#undef SERVER_HELLO
#undef SERVER_HELLO_DONE

using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $GeneralSecurityException = ::java::security::GeneralSecurityException;
using $AbstractSet = ::java::util::AbstractSet;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $TreeSet = ::java::util::TreeSet;
using $Authenticator = ::sun::security::ssl::Authenticator;
using $ContentType = ::sun::security::ssl::ContentType;
using $DTLSInputRecord = ::sun::security::ssl::DTLSInputRecord;
using $DTLSInputRecord$HandshakeFlight = ::sun::security::ssl::DTLSInputRecord$HandshakeFlight;
using $DTLSInputRecord$HandshakeFragment = ::sun::security::ssl::DTLSInputRecord$HandshakeFragment;
using $DTLSInputRecord$HoleDescriptor = ::sun::security::ssl::DTLSInputRecord$HoleDescriptor;
using $DTLSInputRecord$RecordFragment = ::sun::security::ssl::DTLSInputRecord$RecordFragment;
using $DTLSRecord = ::sun::security::ssl::DTLSRecord;
using $HandshakeHash = ::sun::security::ssl::HandshakeHash;
using $Plaintext = ::sun::security::ssl::Plaintext;
using $SSLCipher$SSLReadCipher = ::sun::security::ssl::SSLCipher$SSLReadCipher;
using $SSLHandshake = ::sun::security::ssl::SSLHandshake;
using $SSLLogger = ::sun::security::ssl::SSLLogger;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _DTLSInputRecord$DTLSReassembler_FieldInfo_[] = {
	{"this$0", "Lsun/security/ssl/DTLSInputRecord;", nullptr, $FINAL | $SYNTHETIC, $field(DTLSInputRecord$DTLSReassembler, this$0)},
	{"handshakeEpoch", "I", nullptr, $FINAL, $field(DTLSInputRecord$DTLSReassembler, handshakeEpoch)},
	{"bufferedFragments", "Ljava/util/TreeSet;", "Ljava/util/TreeSet<Lsun/security/ssl/DTLSInputRecord$RecordFragment;>;", 0, $field(DTLSInputRecord$DTLSReassembler, bufferedFragments)},
	{"handshakeFlight", "Lsun/security/ssl/DTLSInputRecord$HandshakeFlight;", nullptr, 0, $field(DTLSInputRecord$DTLSReassembler, handshakeFlight)},
	{"precedingFlight", "Lsun/security/ssl/DTLSInputRecord$HandshakeFlight;", nullptr, 0, $field(DTLSInputRecord$DTLSReassembler, precedingFlight)},
	{"nextRecordEpoch", "I", nullptr, 0, $field(DTLSInputRecord$DTLSReassembler, nextRecordEpoch)},
	{"nextRecordSeq", "J", nullptr, 0, $field(DTLSInputRecord$DTLSReassembler, nextRecordSeq)},
	{"expectCCSFlight", "Z", nullptr, 0, $field(DTLSInputRecord$DTLSReassembler, expectCCSFlight)},
	{"flightIsReady", "Z", nullptr, 0, $field(DTLSInputRecord$DTLSReassembler, flightIsReady$)},
	{"needToCheckFlight", "Z", nullptr, 0, $field(DTLSInputRecord$DTLSReassembler, needToCheckFlight)},
	{}
};

$MethodInfo _DTLSInputRecord$DTLSReassembler_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/DTLSInputRecord;I)V", nullptr, 0, $method(DTLSInputRecord$DTLSReassembler, init$, void, $DTLSInputRecord*, int32_t)},
	{"acquireCachedMessage", "()Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, acquireCachedMessage, $Plaintext*), "javax.net.ssl.SSLProtocolException"},
	{"acquireHandshakeMessage", "()Lsun/security/ssl/Plaintext;", nullptr, $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, acquireHandshakeMessage, $Plaintext*)},
	{"acquirePlaintext", "()Lsun/security/ssl/Plaintext;", nullptr, 0, $method(DTLSInputRecord$DTLSReassembler, acquirePlaintext, $Plaintext*), "javax.net.ssl.SSLProtocolException"},
	{"bufferFragment", "(Lsun/security/ssl/DTLSInputRecord$RecordFragment;)V", nullptr, $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, bufferFragment, void, $DTLSInputRecord$RecordFragment*)},
	{"cleanUpRetransmit", "(Lsun/security/ssl/DTLSInputRecord$RecordFragment;)V", nullptr, $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, cleanUpRetransmit, void, $DTLSInputRecord$RecordFragment*)},
	{"expectingFinishFlight", "()V", nullptr, 0, $method(DTLSInputRecord$DTLSReassembler, expectingFinishFlight, void)},
	{"flightIsReady", "()Z", nullptr, 0, $method(DTLSInputRecord$DTLSReassembler, flightIsReady, bool)},
	{"handshakeHashing", "(Lsun/security/ssl/DTLSInputRecord$HandshakeFragment;Lsun/security/ssl/Plaintext;)V", nullptr, $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, handshakeHashing, void, $DTLSInputRecord$HandshakeFragment*, $Plaintext*)},
	{"hasCompleted", "(B)Z", nullptr, $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, hasCompleted, bool, int8_t)},
	{"hasCompleted", "(Ljava/util/Set;II)Z", "(Ljava/util/Set<Lsun/security/ssl/DTLSInputRecord$RecordFragment;>;II)Z", $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, hasCompleted, bool, $Set*, int32_t, int32_t)},
	{"hasFinishedMessage", "(Ljava/util/Set;)Z", "(Ljava/util/Set<Lsun/security/ssl/DTLSInputRecord$RecordFragment;>;)Z", $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, hasFinishedMessage, bool, $Set*)},
	{"isDesirable", "(Lsun/security/ssl/DTLSInputRecord$RecordFragment;)Z", nullptr, $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, isDesirable, bool, $DTLSInputRecord$RecordFragment*)},
	{"isEmpty", "()Z", nullptr, $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, isEmpty, bool)},
	{"needClientVerify", "(Ljava/util/Set;)Z", "(Ljava/util/Set<Lsun/security/ssl/DTLSInputRecord$RecordFragment;>;)Z", $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, needClientVerify, bool, $Set*)},
	{"queueUpChangeCipherSpec", "(Lsun/security/ssl/DTLSInputRecord$RecordFragment;)V", nullptr, 0, $method(DTLSInputRecord$DTLSReassembler, queueUpChangeCipherSpec, void, $DTLSInputRecord$RecordFragment*)},
	{"queueUpFragment", "(Lsun/security/ssl/DTLSInputRecord$RecordFragment;)V", nullptr, 0, $method(DTLSInputRecord$DTLSReassembler, queueUpFragment, void, $DTLSInputRecord$RecordFragment*)},
	{"queueUpHandshake", "(Lsun/security/ssl/DTLSInputRecord$HandshakeFragment;)V", nullptr, 0, $method(DTLSInputRecord$DTLSReassembler, queueUpHandshake, void, $DTLSInputRecord$HandshakeFragment*)},
	{"resetHandshakeFlight", "(Lsun/security/ssl/DTLSInputRecord$HandshakeFlight;)V", nullptr, $PRIVATE, $method(DTLSInputRecord$DTLSReassembler, resetHandshakeFlight, void, $DTLSInputRecord$HandshakeFlight*)},
	{}
};

$InnerClassInfo _DTLSInputRecord$DTLSReassembler_InnerClassesInfo_[] = {
	{"sun.security.ssl.DTLSInputRecord$DTLSReassembler", "sun.security.ssl.DTLSInputRecord", "DTLSReassembler", $FINAL},
	{}
};

$ClassInfo _DTLSInputRecord$DTLSReassembler_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.DTLSInputRecord$DTLSReassembler",
	"java.lang.Object",
	nullptr,
	_DTLSInputRecord$DTLSReassembler_FieldInfo_,
	_DTLSInputRecord$DTLSReassembler_MethodInfo_,
	nullptr,
	nullptr,
	_DTLSInputRecord$DTLSReassembler_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.DTLSInputRecord"
};

$Object* allocate$DTLSInputRecord$DTLSReassembler($Class* clazz) {
	return $of($alloc(DTLSInputRecord$DTLSReassembler));
}

void DTLSInputRecord$DTLSReassembler::init$($DTLSInputRecord* this$0, int32_t handshakeEpoch) {
	$set(this, this$0, this$0);
	$set(this, bufferedFragments, $new($TreeSet));
	$set(this, handshakeFlight, $new($DTLSInputRecord$HandshakeFlight));
	$set(this, precedingFlight, nullptr);
	this->nextRecordSeq = 0;
	this->expectCCSFlight = false;
	this->flightIsReady$ = false;
	this->needToCheckFlight = false;
	this->handshakeEpoch = handshakeEpoch;
	this->nextRecordEpoch = handshakeEpoch;
	$nc(this->handshakeFlight)->flightEpoch = handshakeEpoch;
}

void DTLSInputRecord$DTLSReassembler::expectingFinishFlight() {
	this->expectCCSFlight = true;
}

void DTLSInputRecord$DTLSReassembler::queueUpHandshake($DTLSInputRecord$HandshakeFragment* hsf) {
	$useLocalCurrentObjectStackCache();
	if (!isDesirable(hsf)) {
		return;
	}
	cleanUpRetransmit(hsf);
	bool isMinimalFlightMessage = false;
	if ($nc(this->handshakeFlight)->minMessageSeq == $nc(hsf)->messageSeq) {
		isMinimalFlightMessage = true;
	} else if ((this->precedingFlight != nullptr) && ($nc(this->precedingFlight)->minMessageSeq == hsf->messageSeq)) {
		isMinimalFlightMessage = true;
	}
	$init($SSLHandshake);
	if (isMinimalFlightMessage && ($nc(hsf)->fragmentOffset == 0) && (hsf->handshakeType != $SSLHandshake::FINISHED->id)) {
		$nc(this->handshakeFlight)->handshakeType = hsf->handshakeType;
		$nc(this->handshakeFlight)->flightEpoch = hsf->recordEpoch;
		$nc(this->handshakeFlight)->minMessageSeq = hsf->messageSeq;
	}
	if ($nc(hsf)->handshakeType == $SSLHandshake::FINISHED->id) {
		$nc(this->handshakeFlight)->maxMessageSeq = hsf->messageSeq;
		$nc(this->handshakeFlight)->maxRecordEpoch = hsf->recordEpoch;
		$nc(this->handshakeFlight)->maxRecordSeq = hsf->recordSeq;
	} else {
		if ($nc(this->handshakeFlight)->maxMessageSeq < hsf->messageSeq) {
			$nc(this->handshakeFlight)->maxMessageSeq = hsf->messageSeq;
		}
		int32_t n = (hsf->recordEpoch - $nc(this->handshakeFlight)->maxRecordEpoch);
		if (n > 0) {
			$nc(this->handshakeFlight)->maxRecordEpoch = hsf->recordEpoch;
			$nc(this->handshakeFlight)->maxRecordSeq = hsf->recordSeq;
		} else if (n == 0) {
			if ($nc(this->handshakeFlight)->maxRecordSeq < hsf->recordSeq) {
				$nc(this->handshakeFlight)->maxRecordSeq = hsf->recordSeq;
			}
		}
	}
	bool fragmented = false;
	if (($nc(hsf)->fragmentOffset) != 0 || ($nc(hsf)->fragmentLength != hsf->messageLength)) {
		fragmented = true;
	}
	$var($List, holes, $cast($List, $nc($nc(this->handshakeFlight)->holesMap)->get($($Byte::valueOf($nc(hsf)->handshakeType)))));
	if (holes == nullptr) {
		if (!fragmented) {
			$assign(holes, $Collections::emptyList());
		} else {
			$assign(holes, $new($LinkedList));
			holes->add($$new($DTLSInputRecord$HoleDescriptor, 0, $nc(hsf)->messageLength));
		}
		$nc($nc(this->handshakeFlight)->holesMap)->put($($Byte::valueOf($nc(hsf)->handshakeType)), holes);
	} else if ($nc(holes)->isEmpty()) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine("Have got the full message, discard it."_s, $$new($ObjectArray, 0));
		}
		return;
	}
	if (fragmented) {
		int32_t fragmentLimit = $nc(hsf)->fragmentOffset + hsf->fragmentLength;
		for (int32_t i = 0; i < $nc(holes)->size(); ++i) {
			$var($DTLSInputRecord$HoleDescriptor, hole, $cast($DTLSInputRecord$HoleDescriptor, holes->get(i)));
			if (($nc(hole)->limit <= hsf->fragmentOffset) || ($nc(hole)->offset >= fragmentLimit)) {
				continue;
			}
			if ((($nc(hole)->offset > hsf->fragmentOffset) && (hole->offset < fragmentLimit)) || (($nc(hole)->limit > hsf->fragmentOffset) && (hole->limit < fragmentLimit))) {
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
					$SSLLogger::fine("Discard invalid record: handshake fragment ranges are overlapping"_s, $$new($ObjectArray, 0));
				}
				return;
			}
			holes->remove(i);
			if (hsf->fragmentOffset > $nc(hole)->offset) {
				holes->add($$new($DTLSInputRecord$HoleDescriptor, hole->offset, hsf->fragmentOffset));
			}
			if (fragmentLimit < $nc(hole)->limit) {
				holes->add($$new($DTLSInputRecord$HoleDescriptor, fragmentLimit, hole->limit));
			}
			break;
		}
	}
	if ($nc(hsf)->handshakeType == $SSLHandshake::FINISHED->id) {
		$nc(this->bufferedFragments)->add(hsf);
	} else {
		bufferFragment(hsf);
	}
}

void DTLSInputRecord$DTLSReassembler::queueUpChangeCipherSpec($DTLSInputRecord$RecordFragment* rf) {
	if (!isDesirable(rf)) {
		return;
	}
	cleanUpRetransmit(rf);
	if (this->expectCCSFlight) {
		$init($DTLSInputRecord$HandshakeFlight);
		$nc(this->handshakeFlight)->handshakeType = $DTLSInputRecord$HandshakeFlight::HF_UNKNOWN;
		$nc(this->handshakeFlight)->flightEpoch = $nc(rf)->recordEpoch;
	}
	if ($nc(this->handshakeFlight)->maxRecordSeq < $nc(rf)->recordSeq) {
		$nc(this->handshakeFlight)->maxRecordSeq = rf->recordSeq;
	}
	bufferFragment(rf);
}

void DTLSInputRecord$DTLSReassembler::queueUpFragment($DTLSInputRecord$RecordFragment* rf) {
	if (!isDesirable(rf)) {
		return;
	}
	cleanUpRetransmit(rf);
	bufferFragment(rf);
}

void DTLSInputRecord$DTLSReassembler::bufferFragment($DTLSInputRecord$RecordFragment* rf) {
	$nc(this->bufferedFragments)->add(rf);
	if (this->flightIsReady$) {
		this->flightIsReady$ = false;
	}
	if (!this->needToCheckFlight) {
		this->needToCheckFlight = true;
	}
}

void DTLSInputRecord$DTLSReassembler::cleanUpRetransmit($DTLSInputRecord$RecordFragment* rf) {
	$useLocalCurrentObjectStackCache();
	bool isNewFlight = false;
	if (this->precedingFlight != nullptr) {
		if ($nc(this->precedingFlight)->flightEpoch < $nc(rf)->recordEpoch) {
			isNewFlight = true;
		} else if ($instanceOf($DTLSInputRecord$HandshakeFragment, rf)) {
			$var($DTLSInputRecord$HandshakeFragment, hsf, $cast($DTLSInputRecord$HandshakeFragment, rf));
			if ($nc(this->precedingFlight)->maxMessageSeq < hsf->messageSeq) {
				isNewFlight = true;
			}
		} else {
			$init($ContentType);
			if (rf->contentType != $ContentType::CHANGE_CIPHER_SPEC->id) {
				if ($nc(this->precedingFlight)->maxRecordEpoch < rf->recordEpoch) {
					isNewFlight = true;
				}
			}
		}
	}
	if (!isNewFlight) {
		return;
	}
	{
		$var($Iterator, it, $nc(this->bufferedFragments)->iterator());
		for (; $nc(it)->hasNext();) {
			$var($DTLSInputRecord$RecordFragment, frag, $cast($DTLSInputRecord$RecordFragment, it->next()));
			bool isOld = false;
			if ($nc(frag)->recordEpoch < $nc(this->precedingFlight)->maxRecordEpoch) {
				isOld = true;
			} else if (frag->recordEpoch == $nc(this->precedingFlight)->maxRecordEpoch) {
				if (frag->recordSeq <= $nc(this->precedingFlight)->maxRecordSeq) {
					isOld = true;
				}
			}
			if (!isOld && ($instanceOf($DTLSInputRecord$HandshakeFragment, frag))) {
				$var($DTLSInputRecord$HandshakeFragment, hsf, $cast($DTLSInputRecord$HandshakeFragment, frag));
				isOld = ($nc(hsf)->messageSeq <= $nc(this->precedingFlight)->maxMessageSeq);
			}
			if (isOld) {
				it->remove();
			} else {
				break;
			}
		}
	}
	$set(this, precedingFlight, nullptr);
}

bool DTLSInputRecord$DTLSReassembler::isDesirable($DTLSInputRecord$RecordFragment* rf) {
	$useLocalCurrentObjectStackCache();
	int32_t previousEpoch = this->nextRecordEpoch - 1;
	if ($nc(rf)->recordEpoch < previousEpoch) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine("Too old epoch to use this record, discard it."_s, $$new($ObjectArray, 0));
		}
		return false;
	}
	if ($nc(rf)->recordEpoch == previousEpoch) {
		bool isDesired = true;
		if (this->precedingFlight == nullptr) {
			isDesired = false;
		} else if ($instanceOf($DTLSInputRecord$HandshakeFragment, rf)) {
			$var($DTLSInputRecord$HandshakeFragment, hsf, $cast($DTLSInputRecord$HandshakeFragment, rf));
			if ($nc(this->precedingFlight)->minMessageSeq > hsf->messageSeq) {
				isDesired = false;
			}
		} else {
			$init($ContentType);
			if (rf->contentType == $ContentType::CHANGE_CIPHER_SPEC->id) {
				if ($nc(this->precedingFlight)->flightEpoch != rf->recordEpoch) {
					isDesired = false;
				}
			} else if ((rf->recordEpoch < $nc(this->precedingFlight)->maxRecordEpoch) || (rf->recordEpoch == $nc(this->precedingFlight)->maxRecordEpoch && rf->recordSeq <= $nc(this->precedingFlight)->maxRecordSeq)) {
				isDesired = false;
			}
		}
		if (!isDesired) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
				$SSLLogger::fine("Too old retransmission to use, discard it."_s, $$new($ObjectArray, 0));
			}
			return false;
		}
	} else if ((rf->recordEpoch == this->nextRecordEpoch) && (this->nextRecordSeq > rf->recordSeq)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine("Lagging behind record (sequence), discard it."_s, $$new($ObjectArray, 0));
		}
		return false;
	}
	return true;
}

bool DTLSInputRecord$DTLSReassembler::isEmpty() {
	bool var$0 = $nc(this->bufferedFragments)->isEmpty() || (!this->flightIsReady$ && !this->needToCheckFlight);
	return (var$0 || (this->needToCheckFlight && !flightIsReady()));
}

$Plaintext* DTLSInputRecord$DTLSReassembler::acquirePlaintext() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->bufferedFragments)->isEmpty()) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine("No received handshake messages"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	if (!this->flightIsReady$ && this->needToCheckFlight) {
		this->flightIsReady$ = flightIsReady();
		if (this->flightIsReady$) {
			if ($nc(this->handshakeFlight)->isRetransmitOf(this->precedingFlight)) {
				$nc(this->bufferedFragments)->clear();
				resetHandshakeFlight(this->precedingFlight);
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
					$SSLLogger::fine("Received a retransmission flight."_s, $$new($ObjectArray, 0));
				}
				$init($Plaintext);
				return $Plaintext::PLAINTEXT_NULL;
			}
		}
		this->needToCheckFlight = false;
	}
	if (!this->flightIsReady$) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine($$str({"The handshake flight is not ready to use: "_s, $$str($nc(this->handshakeFlight)->handshakeType)}), $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$var($DTLSInputRecord$RecordFragment, rFrag, $cast($DTLSInputRecord$RecordFragment, $nc(this->bufferedFragments)->first()));
	$var($Plaintext, plaintext, nullptr);
	if (!$nc(rFrag)->isCiphertext) {
		$assign(plaintext, acquireHandshakeMessage());
		if ($nc(this->bufferedFragments)->isEmpty()) {
			$nc($nc(this->handshakeFlight)->holesMap)->clear();
			$set(this, precedingFlight, $cast($DTLSInputRecord$HandshakeFlight, $nc(this->handshakeFlight)->clone()));
			resetHandshakeFlight(this->precedingFlight);
			if (this->expectCCSFlight && ($nc(this->precedingFlight)->handshakeType == $DTLSInputRecord$HandshakeFlight::HF_UNKNOWN)) {
				this->expectCCSFlight = false;
			}
		}
	} else {
		$assign(plaintext, acquireCachedMessage());
	}
	return plaintext;
}

void DTLSInputRecord$DTLSReassembler::resetHandshakeFlight($DTLSInputRecord$HandshakeFlight* prev) {
	$init($DTLSInputRecord$HandshakeFlight);
	$nc(this->handshakeFlight)->handshakeType = $DTLSInputRecord$HandshakeFlight::HF_UNKNOWN;
	$nc(this->handshakeFlight)->flightEpoch = $nc(prev)->maxRecordEpoch;
	if (prev->flightEpoch != prev->maxRecordEpoch) {
		$nc(this->handshakeFlight)->minMessageSeq = 0;
	} else {
		$nc(this->handshakeFlight)->minMessageSeq = prev->maxMessageSeq + 1;
	}
	$nc(this->handshakeFlight)->maxMessageSeq = 0;
	$nc(this->handshakeFlight)->maxRecordEpoch = $nc(this->handshakeFlight)->flightEpoch;
	$nc(this->handshakeFlight)->maxRecordSeq = prev->maxRecordSeq + 1;
	$nc($nc(this->handshakeFlight)->holesMap)->clear();
	this->flightIsReady$ = false;
	this->needToCheckFlight = false;
}

$Plaintext* DTLSInputRecord$DTLSReassembler::acquireCachedMessage() {
	$useLocalCurrentObjectStackCache();
	$var($DTLSInputRecord$RecordFragment, rFrag, $cast($DTLSInputRecord$RecordFragment, $nc(this->bufferedFragments)->first()));
	if (this->this$0->readEpoch != $nc(rFrag)->recordEpoch) {
		if (this->this$0->readEpoch > rFrag->recordEpoch) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
				$SSLLogger::fine("Discard old buffered ciphertext fragments."_s, $$new($ObjectArray, 0));
			}
			$nc(this->bufferedFragments)->remove(rFrag);
		}
		if (this->flightIsReady$) {
			this->flightIsReady$ = false;
		}
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine("Not yet ready to decrypt the cached fragments."_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$nc(this->bufferedFragments)->remove(rFrag);
	$var($ByteBuffer, fragment, $ByteBuffer::wrap($nc(rFrag)->fragment));
	$var($ByteBuffer, plaintextFragment, nullptr);
	try {
		$var($Plaintext, plaintext, $nc(this->this$0->readCipher)->decrypt($nc(rFrag)->contentType, fragment, rFrag->recordEnS));
		$assign(plaintextFragment, $nc(plaintext)->fragment);
		$nc(rFrag)->contentType = plaintext->contentType;
	} catch ($GeneralSecurityException& gse) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine("Discard invalid record: "_s, $$new($ObjectArray, {$of(gse)}));
		}
		return nullptr;
	}
	$init($ContentType);
	if ($nc(rFrag)->contentType == $ContentType::HANDSHAKE->id) {
		while ($nc(plaintextFragment)->remaining() > 0) {
			$var($DTLSInputRecord$HandshakeFragment, hsFrag, $DTLSInputRecord::parseHandshakeMessage(rFrag->contentType, rFrag->majorVersion, rFrag->minorVersion, rFrag->recordEnS, rFrag->recordEpoch, rFrag->recordSeq, plaintextFragment));
			if (hsFrag == nullptr) {
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
					$SSLLogger::fine("Invalid handshake fragment, discard it"_s, $$new($ObjectArray, {$of(plaintextFragment)}));
				}
				return nullptr;
			}
			queueUpHandshake(hsFrag);
			$init($SSLHandshake);
			if ($nc(hsFrag)->handshakeType != $SSLHandshake::FINISHED->id) {
				this->flightIsReady$ = false;
				this->needToCheckFlight = true;
			}
		}
		return acquirePlaintext();
	} else {
		return $new($Plaintext, rFrag->contentType, rFrag->majorVersion, rFrag->minorVersion, rFrag->recordEpoch, $Authenticator::toLong(rFrag->recordEnS), plaintextFragment);
	}
}

$Plaintext* DTLSInputRecord$DTLSReassembler::acquireHandshakeMessage() {
	$useLocalCurrentObjectStackCache();
	$var($DTLSInputRecord$RecordFragment, rFrag, $cast($DTLSInputRecord$RecordFragment, $nc(this->bufferedFragments)->first()));
	$init($ContentType);
	if ($nc(rFrag)->contentType == $ContentType::CHANGE_CIPHER_SPEC->id) {
		this->nextRecordEpoch = rFrag->recordEpoch + 1;
		this->nextRecordSeq = 0;
		$nc(this->bufferedFragments)->remove(rFrag);
		int8_t var$0 = rFrag->contentType;
		int8_t var$1 = rFrag->majorVersion;
		int8_t var$2 = rFrag->minorVersion;
		int32_t var$3 = rFrag->recordEpoch;
		int64_t var$4 = $Authenticator::toLong(rFrag->recordEnS);
		return $new($Plaintext, var$0, var$1, var$2, var$3, var$4, $($ByteBuffer::wrap(rFrag->fragment)));
	} else {
		$var($DTLSInputRecord$HandshakeFragment, hsFrag, $cast($DTLSInputRecord$HandshakeFragment, rFrag));
		if ((hsFrag->messageLength == hsFrag->fragmentLength) && (hsFrag->fragmentOffset == 0)) {
			$nc(this->bufferedFragments)->remove(rFrag);
			this->nextRecordSeq = hsFrag->recordSeq + 1;
			$var($bytes, recordFrag, $new($bytes, hsFrag->messageLength + 4));
			int8_t var$5 = hsFrag->contentType;
			int8_t var$6 = hsFrag->majorVersion;
			int8_t var$7 = hsFrag->minorVersion;
			int32_t var$8 = hsFrag->recordEpoch;
			int64_t var$9 = $Authenticator::toLong(hsFrag->recordEnS);
			$var($Plaintext, plaintext, $new($Plaintext, var$5, var$6, var$7, var$8, var$9, $($ByteBuffer::wrap(recordFrag))));
			recordFrag->set(0, hsFrag->handshakeType);
			recordFrag->set(1, (int8_t)((int32_t)(((int32_t)((uint32_t)hsFrag->messageLength >> 16)) & (uint32_t)255)));
			recordFrag->set(2, (int8_t)((int32_t)(((int32_t)((uint32_t)hsFrag->messageLength >> 8)) & (uint32_t)255)));
			recordFrag->set(3, (int8_t)((int32_t)(hsFrag->messageLength & (uint32_t)255)));
			$System::arraycopy(hsFrag->fragment, 0, recordFrag, 4, hsFrag->fragmentLength);
			handshakeHashing(hsFrag, plaintext);
			return plaintext;
		} else {
			$var($bytes, recordFrag, $new($bytes, hsFrag->messageLength + 4));
			int8_t var$10 = hsFrag->contentType;
			int8_t var$11 = hsFrag->majorVersion;
			int8_t var$12 = hsFrag->minorVersion;
			int32_t var$13 = hsFrag->recordEpoch;
			int64_t var$14 = $Authenticator::toLong(hsFrag->recordEnS);
			$var($Plaintext, plaintext, $new($Plaintext, var$10, var$11, var$12, var$13, var$14, $($ByteBuffer::wrap(recordFrag))));
			recordFrag->set(0, hsFrag->handshakeType);
			recordFrag->set(1, (int8_t)((int32_t)(((int32_t)((uint32_t)hsFrag->messageLength >> 16)) & (uint32_t)255)));
			recordFrag->set(2, (int8_t)((int32_t)(((int32_t)((uint32_t)hsFrag->messageLength >> 8)) & (uint32_t)255)));
			recordFrag->set(3, (int8_t)((int32_t)(hsFrag->messageLength & (uint32_t)255)));
			int32_t msgSeq = hsFrag->messageSeq;
			int64_t maxRecodeSN = hsFrag->recordSeq;
			$var($DTLSInputRecord$HandshakeFragment, hmFrag, hsFrag);
			do {
				$System::arraycopy(hmFrag->fragment, 0, recordFrag, hmFrag->fragmentOffset + 4, hmFrag->fragmentLength);
				$nc(this->bufferedFragments)->remove(rFrag);
				if (maxRecodeSN < hmFrag->recordSeq) {
					maxRecodeSN = hmFrag->recordSeq;
				}
				if (!$nc(this->bufferedFragments)->isEmpty()) {
					$assign(rFrag, $cast($DTLSInputRecord$RecordFragment, $nc(this->bufferedFragments)->first()));
					if ($nc(rFrag)->contentType != $ContentType::HANDSHAKE->id) {
						break;
					} else {
						$assign(hmFrag, $cast($DTLSInputRecord$HandshakeFragment, rFrag));
					}
				}
			} while (!$nc(this->bufferedFragments)->isEmpty() && (msgSeq == hmFrag->messageSeq));
			handshakeHashing(hsFrag, plaintext);
			this->nextRecordSeq = maxRecodeSN + 1;
			return plaintext;
		}
	}
}

bool DTLSInputRecord$DTLSReassembler::flightIsReady() {
	$useLocalCurrentObjectStackCache();
	int8_t flightType = $nc(this->handshakeFlight)->handshakeType;
	$init($DTLSInputRecord$HandshakeFlight);
	if (flightType == $DTLSInputRecord$HandshakeFlight::HF_UNKNOWN) {
		if (this->expectCCSFlight) {
			bool isReady = hasFinishedMessage(static_cast<$Set*>(static_cast<$AbstractSet*>(this->bufferedFragments)));
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
				$SSLLogger::fine($$str({"Has the final flight been received? "_s, $$str(isReady)}), $$new($ObjectArray, 0));
			}
			return isReady;
		}
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine("No flight is received yet."_s, $$new($ObjectArray, 0));
		}
		return false;
	}
	$init($SSLHandshake);
	if ((flightType == $SSLHandshake::CLIENT_HELLO->id) || (flightType == $SSLHandshake::HELLO_REQUEST->id) || (flightType == $SSLHandshake::HELLO_VERIFY_REQUEST->id)) {
		bool isReady = hasCompleted(flightType);
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine($$str({"Is the handshake message completed? "_s, $$str(isReady)}), $$new($ObjectArray, 0));
		}
		return isReady;
	}
	if (flightType == $SSLHandshake::SERVER_HELLO->id) {
		if (!hasCompleted(flightType)) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
				$SSLLogger::fine("The ServerHello message is not completed yet."_s, $$new($ObjectArray, 0));
			}
			return false;
		}
		if (hasFinishedMessage(static_cast<$Set*>(static_cast<$AbstractSet*>(this->bufferedFragments)))) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
				$SSLLogger::fine("It\'s an abbreviated handshake."_s, $$new($ObjectArray, 0));
			}
			return true;
		}
		$var($List, holes, $cast($List, $nc($nc(this->handshakeFlight)->holesMap)->get($($Byte::valueOf($SSLHandshake::SERVER_HELLO_DONE->id)))));
		if ((holes == nullptr) || !$nc(holes)->isEmpty()) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
				$SSLLogger::fine("Not yet got the ServerHelloDone message"_s, $$new($ObjectArray, 0));
			}
			return false;
		}
		bool isReady = hasCompleted(static_cast<$Set*>(static_cast<$AbstractSet*>(this->bufferedFragments)), $nc(this->handshakeFlight)->minMessageSeq, $nc(this->handshakeFlight)->maxMessageSeq);
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine($$str({"Is the ServerHello flight (message "_s, $$str($nc(this->handshakeFlight)->minMessageSeq), "-"_s, $$str($nc(this->handshakeFlight)->maxMessageSeq), ") completed? "_s, $$str(isReady)}), $$new($ObjectArray, 0));
		}
		return isReady;
	}
	if ((flightType == $SSLHandshake::CERTIFICATE->id) || (flightType == $SSLHandshake::CLIENT_KEY_EXCHANGE->id)) {
		if (!hasCompleted(flightType)) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
				$SSLLogger::fine("The ClientKeyExchange or client Certificate message is not completed yet."_s, $$new($ObjectArray, 0));
			}
			return false;
		}
		if (flightType == $SSLHandshake::CERTIFICATE->id) {
			bool var$0 = needClientVerify(static_cast<$Set*>(static_cast<$AbstractSet*>(this->bufferedFragments)));
			if (var$0 && !hasCompleted($SSLHandshake::CERTIFICATE_VERIFY->id)) {
				$init($SSLLogger);
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
					$SSLLogger::fine("Not yet have the CertificateVerify message"_s, $$new($ObjectArray, 0));
				}
				return false;
			}
		}
		if (!hasFinishedMessage(static_cast<$Set*>(static_cast<$AbstractSet*>(this->bufferedFragments)))) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
				$SSLLogger::fine("Not yet have the ChangeCipherSpec and Finished messages"_s, $$new($ObjectArray, 0));
			}
			return false;
		}
		bool isReady = hasCompleted(static_cast<$Set*>(static_cast<$AbstractSet*>(this->bufferedFragments)), $nc(this->handshakeFlight)->minMessageSeq, $nc(this->handshakeFlight)->maxMessageSeq);
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
			$SSLLogger::fine($$str({"Is the ClientKeyExchange flight (message "_s, $$str($nc(this->handshakeFlight)->minMessageSeq), "-"_s, $$str($nc(this->handshakeFlight)->maxMessageSeq), ") completed? "_s, $$str(isReady)}), $$new($ObjectArray, 0));
		}
		return isReady;
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("verbose"_s)) {
		$SSLLogger::fine("Need to receive more handshake messages"_s, $$new($ObjectArray, 0));
	}
	return false;
}

bool DTLSInputRecord$DTLSReassembler::hasFinishedMessage($Set* fragments) {
	$useLocalCurrentObjectStackCache();
	bool hasCCS = false;
	bool hasFin = false;
	{
		$var($Iterator, i$, $nc(fragments)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($DTLSInputRecord$RecordFragment, fragment, $cast($DTLSInputRecord$RecordFragment, i$->next()));
			{
				$init($ContentType);
				if ($nc(fragment)->contentType == $ContentType::CHANGE_CIPHER_SPEC->id) {
					if (hasFin) {
						return true;
					}
					hasCCS = true;
				} else {
					if (fragment->contentType == $ContentType::HANDSHAKE->id) {
						if (fragment->isCiphertext) {
							if (hasCCS) {
								return true;
							}
							hasFin = true;
						}
					}
				}
			}
		}
	}
	return hasFin && hasCCS;
}

bool DTLSInputRecord$DTLSReassembler::needClientVerify($Set* fragments) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(fragments)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($DTLSInputRecord$RecordFragment, rFrag, $cast($DTLSInputRecord$RecordFragment, i$->next()));
			{
				$init($ContentType);
				if (($nc(rFrag)->contentType != $ContentType::HANDSHAKE->id) || $nc(rFrag)->isCiphertext) {
					break;
				}
				$var($DTLSInputRecord$HandshakeFragment, hsFrag, $cast($DTLSInputRecord$HandshakeFragment, rFrag));
				$init($SSLHandshake);
				if ($nc(hsFrag)->handshakeType != $SSLHandshake::CERTIFICATE->id) {
					continue;
				}
				return ($nc(rFrag)->fragment != nullptr) && ($nc(rFrag->fragment)->length > $DTLSRecord::minCertPlaintextSize);
			}
		}
	}
	return false;
}

bool DTLSInputRecord$DTLSReassembler::hasCompleted(int8_t handshakeType) {
	$useLocalCurrentObjectStackCache();
	$var($List, holes, $cast($List, $nc($nc(this->handshakeFlight)->holesMap)->get($($Byte::valueOf(handshakeType)))));
	if (holes == nullptr) {
		return false;
	}
	return $nc(holes)->isEmpty();
}

bool DTLSInputRecord$DTLSReassembler::hasCompleted($Set* fragments, int32_t presentMsgSeq, int32_t endMsgSeq) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(fragments)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($DTLSInputRecord$RecordFragment, rFrag, $cast($DTLSInputRecord$RecordFragment, i$->next()));
			{
				$init($ContentType);
				if (($nc(rFrag)->contentType != $ContentType::HANDSHAKE->id) || $nc(rFrag)->isCiphertext) {
					break;
				}
				$var($DTLSInputRecord$HandshakeFragment, hsFrag, $cast($DTLSInputRecord$HandshakeFragment, rFrag));
				if ($nc(hsFrag)->messageSeq == presentMsgSeq) {
					continue;
				} else if (hsFrag->messageSeq == (presentMsgSeq + 1)) {
					if (!hasCompleted(hsFrag->handshakeType)) {
						return false;
					}
					presentMsgSeq = hsFrag->messageSeq;
				} else {
					break;
				}
			}
		}
	}
	return (presentMsgSeq >= endMsgSeq);
}

void DTLSInputRecord$DTLSReassembler::handshakeHashing($DTLSInputRecord$HandshakeFragment* hsFrag, $Plaintext* plaintext) {
	int8_t hsType = $nc(hsFrag)->handshakeType;
	if (!$nc(this->this$0->handshakeHash)->isHashable(hsType)) {
		return;
	}
	$nc($nc(plaintext)->fragment)->position(4);
	$var($bytes, temporary, $new($bytes, $nc(plaintext->fragment)->remaining() + 12));
	temporary->set(0, hsFrag->handshakeType);
	temporary->set(1, (int8_t)((int32_t)((hsFrag->messageLength >> 16) & (uint32_t)255)));
	temporary->set(2, (int8_t)((int32_t)((hsFrag->messageLength >> 8) & (uint32_t)255)));
	temporary->set(3, (int8_t)((int32_t)(hsFrag->messageLength & (uint32_t)255)));
	temporary->set(4, (int8_t)((int32_t)((hsFrag->messageSeq >> 8) & (uint32_t)255)));
	temporary->set(5, (int8_t)((int32_t)(hsFrag->messageSeq & (uint32_t)255)));
	temporary->set(6, (int8_t)0);
	temporary->set(7, (int8_t)0);
	temporary->set(8, (int8_t)0);
	temporary->set(9, temporary->get(1));
	temporary->set(10, temporary->get(2));
	temporary->set(11, temporary->get(3));
	$nc(plaintext->fragment)->get(temporary, 12, $nc(plaintext->fragment)->remaining());
	$nc(this->this$0->handshakeHash)->receive(temporary);
	$nc(plaintext->fragment)->position(0);
}

DTLSInputRecord$DTLSReassembler::DTLSInputRecord$DTLSReassembler() {
}

$Class* DTLSInputRecord$DTLSReassembler::load$($String* name, bool initialize) {
	$loadClass(DTLSInputRecord$DTLSReassembler, name, initialize, &_DTLSInputRecord$DTLSReassembler_ClassInfo_, allocate$DTLSInputRecord$DTLSReassembler);
	return class$;
}

$Class* DTLSInputRecord$DTLSReassembler::class$ = nullptr;

		} // ssl
	} // security
} // sun
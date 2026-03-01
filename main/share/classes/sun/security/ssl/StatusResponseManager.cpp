#include <sun/security/ssl/StatusResponseManager.h>

#include <java/io/IOException.h>
#include <java/lang/InterruptedException.h>
#include <java/math/BigInteger.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/cert/Extension.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/AbstractExecutorService.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/concurrent/Future.h>
#include <java/util/concurrent/RejectedExecutionHandler.h>
#include <java/util/concurrent/ScheduledThreadPoolExecutor.h>
#include <java/util/concurrent/ThreadFactory.h>
#include <java/util/concurrent/ThreadPoolExecutor$DiscardPolicy.h>
#include <java/util/concurrent/TimeUnit.h>
#include <sun/security/action/GetBooleanAction.h>
#include <sun/security/action/GetIntegerAction.h>
#include <sun/security/action/GetPropertyAction.h>
#include <sun/security/provider/certpath/CertId.h>
#include <sun/security/provider/certpath/OCSP.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequest.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequestSpec.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequestType.h>
#include <sun/security/ssl/CertStatusExtension$CertStatusRequestV2Spec.h>
#include <sun/security/ssl/CertStatusExtension$OCSPStatusRequest.h>
#include <sun/security/ssl/ProtocolVersion.h>
#include <sun/security/ssl/SSLContextImpl.h>
#include <sun/security/ssl/SSLExtension.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/ssl/SSLPossession.h>
#include <sun/security/ssl/ServerHandshakeContext.h>
#include <sun/security/ssl/StatusResponseManager$1.h>
#include <sun/security/ssl/StatusResponseManager$OCSPFetchCall.h>
#include <sun/security/ssl/StatusResponseManager$ResponseCacheEntry.h>
#include <sun/security/ssl/StatusResponseManager$StaplingParameters.h>
#include <sun/security/ssl/StatusResponseManager$StatusInfo.h>
#include <sun/security/ssl/X509Authentication$X509Possession.h>
#include <sun/security/util/Cache.h>
#include <sun/security/util/ObjectIdentifier.h>
#include <sun/security/x509/PKIXExtensions.h>
#include <sun/security/x509/SerialNumber.h>
#include <jcpp.h>

#undef CH_STATUS_REQUEST
#undef CH_STATUS_REQUEST_V2
#undef DEFAULT_CACHE_LIFETIME
#undef DEFAULT_CACHE_SIZE
#undef DEFAULT_CORE_THREADS
#undef MILLISECONDS
#undef OCSP
#undef OCSP_MULTI

using $X509CertificateArray = $Array<::java::security::cert::X509Certificate>;
using $CertStatusExtension$CertStatusRequestArray = $Array<::sun::security::ssl::CertStatusExtension$CertStatusRequest>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Extension = ::java::security::cert::Extension;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $Future = ::java::util::concurrent::Future;
using $RejectedExecutionHandler = ::java::util::concurrent::RejectedExecutionHandler;
using $ScheduledThreadPoolExecutor = ::java::util::concurrent::ScheduledThreadPoolExecutor;
using $ThreadFactory = ::java::util::concurrent::ThreadFactory;
using $ThreadPoolExecutor$DiscardPolicy = ::java::util::concurrent::ThreadPoolExecutor$DiscardPolicy;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;
using $GetIntegerAction = ::sun::security::action::GetIntegerAction;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;
using $CertId = ::sun::security::provider::certpath::CertId;
using $OCSP = ::sun::security::provider::certpath::OCSP;
using $CertStatusExtension$CertStatusRequest = ::sun::security::ssl::CertStatusExtension$CertStatusRequest;
using $CertStatusExtension$CertStatusRequestSpec = ::sun::security::ssl::CertStatusExtension$CertStatusRequestSpec;
using $CertStatusExtension$CertStatusRequestType = ::sun::security::ssl::CertStatusExtension$CertStatusRequestType;
using $CertStatusExtension$CertStatusRequestV2Spec = ::sun::security::ssl::CertStatusExtension$CertStatusRequestV2Spec;
using $CertStatusExtension$OCSPStatusRequest = ::sun::security::ssl::CertStatusExtension$OCSPStatusRequest;
using $ProtocolVersion = ::sun::security::ssl::ProtocolVersion;
using $SSLContextImpl = ::sun::security::ssl::SSLContextImpl;
using $SSLExtension = ::sun::security::ssl::SSLExtension;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $SSLPossession = ::sun::security::ssl::SSLPossession;
using $ServerHandshakeContext = ::sun::security::ssl::ServerHandshakeContext;
using $StatusResponseManager$1 = ::sun::security::ssl::StatusResponseManager$1;
using $StatusResponseManager$OCSPFetchCall = ::sun::security::ssl::StatusResponseManager$OCSPFetchCall;
using $StatusResponseManager$ResponseCacheEntry = ::sun::security::ssl::StatusResponseManager$ResponseCacheEntry;
using $StatusResponseManager$StaplingParameters = ::sun::security::ssl::StatusResponseManager$StaplingParameters;
using $StatusResponseManager$StatusInfo = ::sun::security::ssl::StatusResponseManager$StatusInfo;
using $X509Authentication$X509Possession = ::sun::security::ssl::X509Authentication$X509Possession;
using $Cache = ::sun::security::util::Cache;
using $ObjectIdentifier = ::sun::security::util::ObjectIdentifier;
using $PKIXExtensions = ::sun::security::x509::PKIXExtensions;
using $SerialNumber = ::sun::security::x509::SerialNumber;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _StatusResponseManager_FieldInfo_[] = {
	{"DEFAULT_CORE_THREADS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StatusResponseManager, DEFAULT_CORE_THREADS)},
	{"DEFAULT_CACHE_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StatusResponseManager, DEFAULT_CACHE_SIZE)},
	{"DEFAULT_CACHE_LIFETIME", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(StatusResponseManager, DEFAULT_CACHE_LIFETIME)},
	{"threadMgr", "Ljava/util/concurrent/ScheduledThreadPoolExecutor;", nullptr, $PRIVATE | $FINAL, $field(StatusResponseManager, threadMgr)},
	{"responseCache", "Lsun/security/util/Cache;", "Lsun/security/util/Cache<Lsun/security/provider/certpath/CertId;Lsun/security/ssl/StatusResponseManager$ResponseCacheEntry;>;", $PRIVATE | $FINAL, $field(StatusResponseManager, responseCache)},
	{"defaultResponder", "Ljava/net/URI;", nullptr, $PRIVATE | $FINAL, $field(StatusResponseManager, defaultResponder)},
	{"respOverride", "Z", nullptr, $PRIVATE | $FINAL, $field(StatusResponseManager, respOverride)},
	{"cacheCapacity", "I", nullptr, $PRIVATE | $FINAL, $field(StatusResponseManager, cacheCapacity)},
	{"cacheLifetime", "I", nullptr, $PRIVATE | $FINAL, $field(StatusResponseManager, cacheLifetime)},
	{"ignoreExtensions", "Z", nullptr, $PRIVATE | $FINAL, $field(StatusResponseManager, ignoreExtensions)},
	{}
};

$MethodInfo _StatusResponseManager_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(StatusResponseManager, init$, void)},
	{"clear", "()V", nullptr, 0, $method(StatusResponseManager, clear, void)},
	{"get", "(Lsun/security/ssl/CertStatusExtension$CertStatusRequestType;Lsun/security/ssl/CertStatusExtension$CertStatusRequest;[Ljava/security/cert/X509Certificate;JLjava/util/concurrent/TimeUnit;)Ljava/util/Map;", "(Lsun/security/ssl/CertStatusExtension$CertStatusRequestType;Lsun/security/ssl/CertStatusExtension$CertStatusRequest;[Ljava/security/cert/X509Certificate;JLjava/util/concurrent/TimeUnit;)Ljava/util/Map<Ljava/security/cert/X509Certificate;[B>;", 0, $method(StatusResponseManager, get, $Map*, $CertStatusExtension$CertStatusRequestType*, $CertStatusExtension$CertStatusRequest*, $X509CertificateArray*, int64_t, $TimeUnit*)},
	{"getCacheCapacity", "()I", nullptr, 0, $method(StatusResponseManager, getCacheCapacity, int32_t)},
	{"getCacheLifetime", "()I", nullptr, 0, $method(StatusResponseManager, getCacheLifetime, int32_t)},
	{"getDefaultResponder", "()Ljava/net/URI;", nullptr, 0, $method(StatusResponseManager, getDefaultResponder, $URI*)},
	{"getFromCache", "(Lsun/security/provider/certpath/CertId;Lsun/security/ssl/CertStatusExtension$OCSPStatusRequest;)Lsun/security/ssl/StatusResponseManager$ResponseCacheEntry;", nullptr, $PRIVATE, $method(StatusResponseManager, getFromCache, $StatusResponseManager$ResponseCacheEntry*, $CertId*, $CertStatusExtension$OCSPStatusRequest*)},
	{"getIgnoreExtensions", "()Z", nullptr, 0, $method(StatusResponseManager, getIgnoreExtensions, bool)},
	{"getURI", "(Ljava/security/cert/X509Certificate;)Ljava/net/URI;", nullptr, 0, $method(StatusResponseManager, getURI, $URI*, $X509Certificate*)},
	{"getURIOverride", "()Z", nullptr, 0, $method(StatusResponseManager, getURIOverride, bool)},
	{"processStapling", "(Lsun/security/ssl/ServerHandshakeContext;)Lsun/security/ssl/StatusResponseManager$StaplingParameters;", nullptr, $STATIC | $FINAL, $staticMethod(StatusResponseManager, processStapling, $StatusResponseManager$StaplingParameters*, $ServerHandshakeContext*)},
	{"shutdown", "()V", nullptr, 0, $method(StatusResponseManager, shutdown, void)},
	{"size", "()I", nullptr, 0, $method(StatusResponseManager, size, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(StatusResponseManager, toString, $String*)},
	{}
};

$InnerClassInfo _StatusResponseManager_InnerClassesInfo_[] = {
	{"sun.security.ssl.StatusResponseManager$StaplingParameters", "sun.security.ssl.StatusResponseManager", "StaplingParameters", $STATIC | $FINAL},
	{"sun.security.ssl.StatusResponseManager$OCSPFetchCall", "sun.security.ssl.StatusResponseManager", "OCSPFetchCall", 0},
	{"sun.security.ssl.StatusResponseManager$ResponseCacheEntry", "sun.security.ssl.StatusResponseManager", "ResponseCacheEntry", $STATIC},
	{"sun.security.ssl.StatusResponseManager$StatusInfo", "sun.security.ssl.StatusResponseManager", "StatusInfo", 0},
	{"sun.security.ssl.StatusResponseManager$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _StatusResponseManager_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.security.ssl.StatusResponseManager",
	"java.lang.Object",
	nullptr,
	_StatusResponseManager_FieldInfo_,
	_StatusResponseManager_MethodInfo_,
	nullptr,
	nullptr,
	_StatusResponseManager_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.ssl.StatusResponseManager$StaplingParameters,sun.security.ssl.StatusResponseManager$OCSPFetchCall,sun.security.ssl.StatusResponseManager$ResponseCacheEntry,sun.security.ssl.StatusResponseManager$StatusInfo,sun.security.ssl.StatusResponseManager$1"
};

$Object* allocate$StatusResponseManager($Class* clazz) {
	return $of($alloc(StatusResponseManager));
}

void StatusResponseManager::init$() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	int32_t cap = $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GetIntegerAction, "jdk.tls.stapling.cacheSize"_s, StatusResponseManager::DEFAULT_CACHE_SIZE)))))))->intValue();
	this->cacheCapacity = cap > 0 ? cap : 0;
	int32_t life = $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GetIntegerAction, "jdk.tls.stapling.cacheLifetime"_s, StatusResponseManager::DEFAULT_CACHE_LIFETIME)))))))->intValue();
	this->cacheLifetime = life > 0 ? life : 0;
	$var($String, uriStr, $GetPropertyAction::privilegedGetProperty("jdk.tls.stapling.responderURI"_s));
	$var($URI, tmpURI, nullptr);
	try {
		$assign(tmpURI, (uriStr != nullptr && !uriStr->isEmpty()) ? $new($URI, uriStr) : ($URI*)nullptr);
	} catch ($URISyntaxException& urise) {
		$assign(tmpURI, nullptr);
	}
	$set(this, defaultResponder, tmpURI);
	this->respOverride = $GetBooleanAction::privilegedGetProperty("jdk.tls.stapling.responderOverride"_s);
	this->ignoreExtensions = $GetBooleanAction::privilegedGetProperty("jdk.tls.stapling.ignoreExtensions"_s);
	int32_t var$0 = StatusResponseManager::DEFAULT_CORE_THREADS;
	$var($ThreadFactory, var$1, static_cast<$ThreadFactory*>($new($StatusResponseManager$1, this)));
	$set(this, threadMgr, $new($ScheduledThreadPoolExecutor, var$0, var$1, $$new($ThreadPoolExecutor$DiscardPolicy)));
	$nc(this->threadMgr)->setExecuteExistingDelayedTasksAfterShutdownPolicy(false);
	$nc(this->threadMgr)->setContinueExistingPeriodicTasksAfterShutdownPolicy(false);
	$init($TimeUnit);
	$nc(this->threadMgr)->setKeepAliveTime(5000, $TimeUnit::MILLISECONDS);
	$nc(this->threadMgr)->allowCoreThreadTimeOut(true);
	$set(this, responseCache, $Cache::newSoftMemoryCache(this->cacheCapacity, this->cacheLifetime));
}

int32_t StatusResponseManager::getCacheLifetime() {
	return this->cacheLifetime;
}

int32_t StatusResponseManager::getCacheCapacity() {
	return this->cacheCapacity;
}

$URI* StatusResponseManager::getDefaultResponder() {
	return this->defaultResponder;
}

bool StatusResponseManager::getURIOverride() {
	return this->respOverride;
}

bool StatusResponseManager::getIgnoreExtensions() {
	return this->ignoreExtensions;
}

void StatusResponseManager::clear() {
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
		$SSLLogger::fine("Clearing response cache"_s, $$new($ObjectArray, 0));
	}
	$nc(this->responseCache)->clear();
}

int32_t StatusResponseManager::size() {
	return $nc(this->responseCache)->size();
}

$URI* StatusResponseManager::getURI($X509Certificate* cert) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(cert);
	$init($PKIXExtensions);
	if (cert->getExtensionValue($($nc($PKIXExtensions::OCSPNoCheck_Id)->toString())) != nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
			$SSLLogger::fine("OCSP NoCheck extension found.  OCSP will be skipped"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	} else if (this->defaultResponder != nullptr && this->respOverride) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
			$SSLLogger::fine($$str({"Responder override: URI is "_s, this->defaultResponder}), $$new($ObjectArray, 0));
		}
		return this->defaultResponder;
	} else {
		$var($URI, certURI, $OCSP::getResponderURI(cert));
		return (certURI != nullptr ? certURI : this->defaultResponder);
	}
}

void StatusResponseManager::shutdown() {
	$useLocalCurrentObjectStackCache();
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
		$SSLLogger::fine($$str({"Shutting down "_s, $$str($nc(this->threadMgr)->getActiveCount()), " active threads"_s}), $$new($ObjectArray, 0));
	}
	$nc(this->threadMgr)->shutdown();
}

$Map* StatusResponseManager::get($CertStatusExtension$CertStatusRequestType* type, $CertStatusExtension$CertStatusRequest* request, $X509CertificateArray* chain, int64_t delay, $TimeUnit* unit) {
	$useLocalCurrentObjectStackCache();
	$var($Map, responseMap, $new($HashMap));
	$var($List, requestList, $new($ArrayList));
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
		$SSLLogger::fine($$str({"Beginning check: Type = "_s, type, ", Chain length = "_s, $$str($nc(chain)->length)}), $$new($ObjectArray, 0));
	}
	if ($nc(chain)->length < 2) {
		return $Collections::emptyMap();
	}
	$init($CertStatusExtension$CertStatusRequestType);
	if (type == $CertStatusExtension$CertStatusRequestType::OCSP) {
		try {
			$var($CertStatusExtension$OCSPStatusRequest, ocspReq, $cast($CertStatusExtension$OCSPStatusRequest, request));
			$var($CertId, cid, $new($CertId, $nc(chain)->get(1), $$new($SerialNumber, $($nc(chain->get(0))->getSerialNumber()))));
			$var($StatusResponseManager$ResponseCacheEntry, cacheEntry, getFromCache(cid, ocspReq));
			if (cacheEntry != nullptr) {
				responseMap->put($nc(chain)->get(0), cacheEntry->ocspBytes);
			} else {
				$var($StatusResponseManager$StatusInfo, sInfo, $new($StatusResponseManager$StatusInfo, this, $nc(chain)->get(0), cid));
				requestList->add($$new($StatusResponseManager$OCSPFetchCall, this, sInfo, ocspReq));
			}
		} catch ($IOException& exc) {
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
				$SSLLogger::fine("Exception during CertId creation: "_s, $$new($ObjectArray, {$of(exc)}));
			}
		}
	} else {
		if (type == $CertStatusExtension$CertStatusRequestType::OCSP_MULTI) {
			$var($CertStatusExtension$OCSPStatusRequest, ocspReq, $cast($CertStatusExtension$OCSPStatusRequest, request));
			int32_t ctr = 0;
			for (ctr = 0; ctr < $nc(chain)->length - 1; ++ctr) {
				try {
					$var($CertId, cid, $new($CertId, chain->get(ctr + 1), $$new($SerialNumber, $($nc(chain->get(ctr))->getSerialNumber()))));
					$var($StatusResponseManager$ResponseCacheEntry, cacheEntry, getFromCache(cid, ocspReq));
					if (cacheEntry != nullptr) {
						responseMap->put(chain->get(ctr), cacheEntry->ocspBytes);
					} else {
						$var($StatusResponseManager$StatusInfo, sInfo, $new($StatusResponseManager$StatusInfo, this, chain->get(ctr), cid));
						requestList->add($$new($StatusResponseManager$OCSPFetchCall, this, sInfo, ocspReq));
					}
				} catch ($IOException& exc) {
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
						$SSLLogger::fine("Exception during CertId creation: "_s, $$new($ObjectArray, {$of(exc)}));
					}
				}
			}
		} else {
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
				$SSLLogger::fine($$str({"Unsupported status request type: "_s, type}), $$new($ObjectArray, 0));
			}
		}
	}
	if (!requestList->isEmpty()) {
		try {
			$var($List, resultList, $nc(this->threadMgr)->invokeAll(requestList, delay, unit));
			{
				$var($Iterator, i$, $nc(resultList)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Future, task, $cast($Future, i$->next()));
					{
						if (!$nc(task)->isDone()) {
							continue;
						}
						if (!$nc(task)->isCancelled()) {
							$var($StatusResponseManager$StatusInfo, info, $cast($StatusResponseManager$StatusInfo, task->get()));
							if (info != nullptr && info->responseData != nullptr) {
								responseMap->put(info->cert, $nc(info->responseData)->ocspBytes);
							} else {
								if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
									$SSLLogger::fine("Completed task had no response data"_s, $$new($ObjectArray, 0));
								}
							}
						} else {
							if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
								$SSLLogger::fine("Found cancelled task"_s, $$new($ObjectArray, 0));
							}
						}
					}
				}
			}
		} catch ($InterruptedException& exc) {
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
				$SSLLogger::fine("Exception when getting data: "_s, $$new($ObjectArray, {$of(exc)}));
			}
		} catch ($ExecutionException& exc) {
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
				$SSLLogger::fine("Exception when getting data: "_s, $$new($ObjectArray, {$of(exc)}));
			}
		}
	}
	return $Collections::unmodifiableMap(responseMap);
}

$StatusResponseManager$ResponseCacheEntry* StatusResponseManager::getFromCache($CertId* cid, $CertStatusExtension$OCSPStatusRequest* ocspRequest) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($nc(ocspRequest)->extensions)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Extension, ext, $cast($Extension, i$->next()));
			{
				$init($PKIXExtensions);
				if ($nc($($nc(ext)->getId()))->equals($($nc($PKIXExtensions::OCSPNonce_Id)->toString()))) {
					$init($SSLLogger);
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
						$SSLLogger::fine("Nonce extension found, skipping cache check"_s, $$new($ObjectArray, 0));
					}
					return nullptr;
				}
			}
		}
	}
	$var($StatusResponseManager$ResponseCacheEntry, respEntry, $cast($StatusResponseManager$ResponseCacheEntry, $nc(this->responseCache)->get(cid)));
	if (respEntry != nullptr && respEntry->nextUpdate != nullptr && $nc(respEntry->nextUpdate)->before($$new($Date))) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
			$SSLLogger::fine("nextUpdate threshold exceeded, purging from cache"_s, $$new($ObjectArray, 0));
		}
		$assign(respEntry, nullptr);
	}
	$init($SSLLogger);
	if ($SSLLogger::isOn$ && $SSLLogger::isOn("respmgr"_s)) {
		$SSLLogger::fine($$str({"Check cache for SN"_s, $($nc(cid)->getSerialNumber()), ": "_s, (respEntry != nullptr ? "HIT"_s : "MISS"_s)}), $$new($ObjectArray, 0));
	}
	return respEntry;
}

$String* StatusResponseManager::toString() {
	$var($StringBuilder, sb, $new($StringBuilder, "StatusResponseManager: "_s));
	sb->append("Core threads: "_s)->append($nc(this->threadMgr)->getCorePoolSize());
	sb->append(", Cache timeout: "_s);
	if (this->cacheLifetime > 0) {
		sb->append(this->cacheLifetime)->append(" seconds"_s);
	} else {
		sb->append(" indefinite"_s);
	}
	sb->append(", Cache MaxSize: "_s);
	if (this->cacheCapacity > 0) {
		sb->append(this->cacheCapacity)->append(" items"_s);
	} else {
		sb->append(" unbounded"_s);
	}
	sb->append(", Default URI: "_s);
	if (this->defaultResponder != nullptr) {
		sb->append($of(this->defaultResponder));
	} else {
		sb->append("NONE"_s);
	}
	return sb->toString();
}

$StatusResponseManager$StaplingParameters* StatusResponseManager::processStapling($ServerHandshakeContext* shc) {
	$useLocalCurrentObjectStackCache();
	$var($StatusResponseManager$StaplingParameters, params, nullptr);
	$SSLExtension* ext = nullptr;
	$CertStatusExtension$CertStatusRequestType* type = nullptr;
	$var($CertStatusExtension$CertStatusRequest, req, nullptr);
	$var($Map, responses, nullptr);
	if (!$nc($nc(shc)->sslContext)->isStaplingEnabled(false) || $nc(shc)->isResumption) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("Staping disabled or is a resumed session"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$var($Map, exts, $nc(shc)->handshakeExtensions);
	$init($SSLExtension);
	$var($CertStatusExtension$CertStatusRequestSpec, statReq, $cast($CertStatusExtension$CertStatusRequestSpec, $nc(exts)->get($SSLExtension::CH_STATUS_REQUEST)));
	$var($CertStatusExtension$CertStatusRequestV2Spec, statReqV2, $cast($CertStatusExtension$CertStatusRequestV2Spec, exts->get($SSLExtension::CH_STATUS_REQUEST_V2)));
	if (statReqV2 != nullptr && !$nc(shc->negotiatedProtocol)->useTLS13PlusSpec()) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::fine("SH Processing status_request_v2 extension"_s, $$new($ObjectArray, 0));
		}
		ext = $SSLExtension::CH_STATUS_REQUEST_V2;
		int32_t ocspIdx = -1;
		int32_t ocspMultiIdx = -1;
		$var($CertStatusExtension$CertStatusRequestArray, reqItems, statReqV2->certStatusRequests);
		for (int32_t pos = 0; (pos < $nc(reqItems)->length && (ocspIdx == -1 || ocspMultiIdx == -1)); ++pos) {
			$var($CertStatusExtension$CertStatusRequest, item, $nc(reqItems)->get(pos));
			$CertStatusExtension$CertStatusRequestType* curType = $CertStatusExtension$CertStatusRequestType::valueOf($nc(item)->statusType);
			if (ocspIdx < 0 && curType == $CertStatusExtension$CertStatusRequestType::OCSP) {
				$var($CertStatusExtension$OCSPStatusRequest, ocspReq, $cast($CertStatusExtension$OCSPStatusRequest, item));
				if ($nc($nc(ocspReq)->responderIds)->isEmpty()) {
					ocspIdx = pos;
				}
			} else {
				if (ocspMultiIdx < 0 && curType == $CertStatusExtension$CertStatusRequestType::OCSP_MULTI) {
					$var($CertStatusExtension$OCSPStatusRequest, ocspReq, $cast($CertStatusExtension$OCSPStatusRequest, item));
					if ($nc($nc(ocspReq)->responderIds)->isEmpty()) {
						ocspMultiIdx = pos;
					}
				}
			}
		}
		if (ocspMultiIdx >= 0) {
			$assign(req, $nc(reqItems)->get(ocspMultiIdx));
			type = $CertStatusExtension$CertStatusRequestType::valueOf($nc(req)->statusType);
		} else if (ocspIdx >= 0) {
			$assign(req, $nc(reqItems)->get(ocspIdx));
			type = $CertStatusExtension$CertStatusRequestType::valueOf($nc(req)->statusType);
		} else {
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
				$SSLLogger::finest("Warning: No suitable request found in the status_request_v2 extension."_s, $$new($ObjectArray, 0));
			}
		}
	}
	if ((statReq != nullptr) && (ext == nullptr || type == nullptr || req == nullptr)) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake,verbose"_s)) {
			$SSLLogger::fine("SH Processing status_request extension"_s, $$new($ObjectArray, 0));
		}
		ext = $SSLExtension::CH_STATUS_REQUEST;
		type = $CertStatusExtension$CertStatusRequestType::valueOf($nc($nc(statReq)->statusRequest)->statusType);
		if (type == $CertStatusExtension$CertStatusRequestType::OCSP) {
			$var($CertStatusExtension$OCSPStatusRequest, ocspReq, $cast($CertStatusExtension$OCSPStatusRequest, $nc(statReq)->statusRequest));
			if ($nc($nc(ocspReq)->responderIds)->isEmpty()) {
				$assign(req, ocspReq);
			} else {
				if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
					$SSLLogger::finest("Warning: No suitable request found in the status_request extension."_s, $$new($ObjectArray, 0));
				}
			}
		}
	}
	if (type == nullptr || req == nullptr || ext == nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::fine("No suitable status_request or status_request_v2, stapling is disabled"_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$var($X509Authentication$X509Possession, x509Possession, nullptr);
	{
		$var($Iterator, i$, $nc(shc->handshakePossessions)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SSLPossession, possession, $cast($SSLPossession, i$->next()));
			{
				if ($instanceOf($X509Authentication$X509Possession, possession)) {
					$assign(x509Possession, $cast($X509Authentication$X509Possession, possession));
					break;
				}
			}
		}
	}
	if (x509Possession == nullptr) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::finest("Warning: no X.509 certificates found.  Stapling is disabled."_s, $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$var($X509CertificateArray, certs, $nc(x509Possession)->popCerts);
	$var(StatusResponseManager, statRespMgr, $nc(shc->sslContext)->getStatusResponseManager());
	if (statRespMgr != nullptr) {
		$init($CertStatusExtension$CertStatusRequestType);
		$CertStatusExtension$CertStatusRequestType* fetchType = $nc(shc->negotiatedProtocol)->useTLS13PlusSpec() ? $CertStatusExtension$CertStatusRequestType::OCSP_MULTI : type;
		$init($TimeUnit);
		$assign(responses, statRespMgr->get(fetchType, req, certs, shc->statusRespTimeout, $TimeUnit::MILLISECONDS));
		if (!$nc(responses)->isEmpty()) {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
				$SSLLogger::finest($$str({"Response manager returned "_s, $$str(responses->size()), " entries."_s}), $$new($ObjectArray, 0));
			}
			if (type == $CertStatusExtension$CertStatusRequestType::OCSP) {
				$var($bytes, respDER, $cast($bytes, responses->get($nc(certs)->get(0))));
				if (respDER == nullptr || $nc(respDER)->length <= 0) {
					if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
						$SSLLogger::finest("Warning: Null or zero-length response found for leaf certificate. Stapling is disabled."_s, $$new($ObjectArray, 0));
					}
					return nullptr;
				}
			}
			$assign(params, $new($StatusResponseManager$StaplingParameters, ext, type, req, responses));
		} else {
			$init($SSLLogger);
			if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
				$SSLLogger::finest("Warning: no OCSP responses obtained.  Stapling is disabled."_s, $$new($ObjectArray, 0));
			}
		}
	} else {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl,handshake"_s)) {
			$SSLLogger::finest("Warning: lazy initialization of the StatusResponseManager failed.  Stapling is disabled."_s, $$new($ObjectArray, 0));
		}
		$assign(params, nullptr);
	}
	return params;
}

StatusResponseManager::StatusResponseManager() {
}

$Class* StatusResponseManager::load$($String* name, bool initialize) {
	$loadClass(StatusResponseManager, name, initialize, &_StatusResponseManager_ClassInfo_, allocate$StatusResponseManager);
	return class$;
}

$Class* StatusResponseManager::class$ = nullptr;

		} // ssl
	} // security
} // sun
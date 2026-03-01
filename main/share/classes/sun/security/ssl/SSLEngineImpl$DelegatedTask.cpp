#include <sun/security/ssl/SSLEngineImpl$DelegatedTask.h>

#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/Collection.h>
#include <java/util/Queue.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <javax/net/ssl/SSLException.h>
#include <sun/security/ssl/HandshakeContext.h>
#include <sun/security/ssl/SSLEngineImpl$DelegatedTask$DelegatedAction.h>
#include <sun/security/ssl/SSLEngineImpl.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $AccessController = ::java::security::AccessController;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Queue = ::java::util::Queue;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $HandshakeContext = ::sun::security::ssl::HandshakeContext;
using $SSLEngineImpl = ::sun::security::ssl::SSLEngineImpl;
using $SSLEngineImpl$DelegatedTask$DelegatedAction = ::sun::security::ssl::SSLEngineImpl$DelegatedTask$DelegatedAction;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _SSLEngineImpl$DelegatedTask_FieldInfo_[] = {
	{"engine", "Lsun/security/ssl/SSLEngineImpl;", nullptr, $PRIVATE | $FINAL, $field(SSLEngineImpl$DelegatedTask, engine)},
	{}
};

$MethodInfo _SSLEngineImpl$DelegatedTask_MethodInfo_[] = {
	{"<init>", "(Lsun/security/ssl/SSLEngineImpl;)V", nullptr, 0, $method(SSLEngineImpl$DelegatedTask, init$, void, $SSLEngineImpl*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(SSLEngineImpl$DelegatedTask, run, void)},
	{}
};

$InnerClassInfo _SSLEngineImpl$DelegatedTask_InnerClassesInfo_[] = {
	{"sun.security.ssl.SSLEngineImpl$DelegatedTask", "sun.security.ssl.SSLEngineImpl", "DelegatedTask", $PRIVATE | $STATIC},
	{"sun.security.ssl.SSLEngineImpl$DelegatedTask$DelegatedAction", "sun.security.ssl.SSLEngineImpl$DelegatedTask", "DelegatedAction", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SSLEngineImpl$DelegatedTask_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.SSLEngineImpl$DelegatedTask",
	"java.lang.Object",
	"java.lang.Runnable",
	_SSLEngineImpl$DelegatedTask_FieldInfo_,
	_SSLEngineImpl$DelegatedTask_MethodInfo_,
	nullptr,
	nullptr,
	_SSLEngineImpl$DelegatedTask_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.SSLEngineImpl"
};

$Object* allocate$SSLEngineImpl$DelegatedTask($Class* clazz) {
	return $of($alloc(SSLEngineImpl$DelegatedTask));
}

void SSLEngineImpl$DelegatedTask::init$($SSLEngineImpl* engineInstance) {
	$set(this, engine, engineInstance);
}

void SSLEngineImpl$DelegatedTask::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$nc($nc(this->engine)->engineLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			$var($HandshakeContext, hc, $nc($nc(this->engine)->conContext)->handshakeContext);
			if (hc == nullptr || $nc($nc(hc)->delegatedActions)->isEmpty()) {
				return$1 = true;
				goto $finally;
			}
			try {
				$var($Void, dummy, $cast($Void, $AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($SSLEngineImpl$DelegatedTask$DelegatedAction, hc)), $nc($nc(this->engine)->conContext)->acc)));
			} catch ($PrivilegedActionException& pae) {
				$var($Exception, reportedException, pae->getException());
				if ($nc($nc(this->engine)->conContext)->delegatedThrown == nullptr) {
					$set($nc($nc(this->engine)->conContext), delegatedThrown, reportedException);
				}
				$assign(hc, $nc($nc(this->engine)->conContext)->handshakeContext);
				if (hc != nullptr) {
					$set(hc, delegatedThrown, reportedException);
				} else if ($nc($nc(this->engine)->conContext)->closeReason != nullptr) {
					$set($nc($nc(this->engine)->conContext), closeReason, $SSLEngineImpl::getTaskThrown(reportedException));
				}
			} catch ($RuntimeException& rte) {
				if ($nc($nc(this->engine)->conContext)->delegatedThrown == nullptr) {
					$set($nc($nc(this->engine)->conContext), delegatedThrown, rte);
				}
				$assign(hc, $nc($nc(this->engine)->conContext)->handshakeContext);
				if (hc != nullptr) {
					$set(hc, delegatedThrown, rte);
				} else if ($nc($nc(this->engine)->conContext)->closeReason != nullptr) {
					$set($nc($nc(this->engine)->conContext), closeReason, rte);
				}
			}
			$assign(hc, $nc($nc(this->engine)->conContext)->handshakeContext);
			if (hc != nullptr) {
				hc->taskDelegated = false;
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			$nc($nc(this->engine)->engineLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

SSLEngineImpl$DelegatedTask::SSLEngineImpl$DelegatedTask() {
}

$Class* SSLEngineImpl$DelegatedTask::load$($String* name, bool initialize) {
	$loadClass(SSLEngineImpl$DelegatedTask, name, initialize, &_SSLEngineImpl$DelegatedTask_ClassInfo_, allocate$SSLEngineImpl$DelegatedTask);
	return class$;
}

$Class* SSLEngineImpl$DelegatedTask::class$ = nullptr;

		} // ssl
	} // security
} // sun
#include <sun/security/ssl/TransportContext$NotifyHandshake.h>

#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Collection.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/net/ssl/HandshakeCompletedEvent.h>
#include <javax/net/ssl/HandshakeCompletedListener.h>
#include <sun/security/ssl/TransportContext$NotifyHandshake$1.h>
#include <sun/security/ssl/TransportContext.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $HandshakeCompletedEvent = ::javax::net::ssl::HandshakeCompletedEvent;
using $HandshakeCompletedListener = ::javax::net::ssl::HandshakeCompletedListener;
using $TransportContext$NotifyHandshake$1 = ::sun::security::ssl::TransportContext$NotifyHandshake$1;

namespace sun {
	namespace security {
		namespace ssl {

$FieldInfo _TransportContext$NotifyHandshake_FieldInfo_[] = {
	{"targets", "Ljava/util/Set;", "Ljava/util/Set<Ljava/util/Map$Entry<Ljavax/net/ssl/HandshakeCompletedListener;Ljava/security/AccessControlContext;>;>;", $PRIVATE | $FINAL, $field(TransportContext$NotifyHandshake, targets)},
	{"event", "Ljavax/net/ssl/HandshakeCompletedEvent;", nullptr, $PRIVATE | $FINAL, $field(TransportContext$NotifyHandshake, event)},
	{}
};

$MethodInfo _TransportContext$NotifyHandshake_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Map;Ljavax/net/ssl/HandshakeCompletedEvent;)V", "(Ljava/util/Map<Ljavax/net/ssl/HandshakeCompletedListener;Ljava/security/AccessControlContext;>;Ljavax/net/ssl/HandshakeCompletedEvent;)V", 0, $method(TransportContext$NotifyHandshake, init$, void, $Map*, $HandshakeCompletedEvent*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(TransportContext$NotifyHandshake, run, void)},
	{}
};

$InnerClassInfo _TransportContext$NotifyHandshake_InnerClassesInfo_[] = {
	{"sun.security.ssl.TransportContext$NotifyHandshake", "sun.security.ssl.TransportContext", "NotifyHandshake", $PRIVATE | $STATIC},
	{"sun.security.ssl.TransportContext$NotifyHandshake$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _TransportContext$NotifyHandshake_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.ssl.TransportContext$NotifyHandshake",
	"java.lang.Object",
	"java.lang.Runnable",
	_TransportContext$NotifyHandshake_FieldInfo_,
	_TransportContext$NotifyHandshake_MethodInfo_,
	nullptr,
	nullptr,
	_TransportContext$NotifyHandshake_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.ssl.TransportContext"
};

$Object* allocate$TransportContext$NotifyHandshake($Class* clazz) {
	return $of($alloc(TransportContext$NotifyHandshake));
}

void TransportContext$NotifyHandshake::init$($Map* listeners, $HandshakeCompletedEvent* event) {
	$set(this, targets, $new($HashSet, $(static_cast<$Collection*>($nc(listeners)->entrySet()))));
	$set(this, event, event);
}

void TransportContext$NotifyHandshake::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		$var($Iterator, i$, $nc(this->targets)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($HandshakeCompletedListener, listener, $cast($HandshakeCompletedListener, $nc(entry)->getKey()));
				$var($AccessControlContext, acc, $cast($AccessControlContext, entry->getValue()));
				$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($TransportContext$NotifyHandshake$1, this, listener)), acc);
			}
		}
	}
}

TransportContext$NotifyHandshake::TransportContext$NotifyHandshake() {
}

$Class* TransportContext$NotifyHandshake::load$($String* name, bool initialize) {
	$loadClass(TransportContext$NotifyHandshake, name, initialize, &_TransportContext$NotifyHandshake_ClassInfo_, allocate$TransportContext$NotifyHandshake);
	return class$;
}

$Class* TransportContext$NotifyHandshake::class$ = nullptr;

		} // ssl
	} // security
} // sun
#include <sun/nio/ch/MembershipRegistry.h>

#include <java/io/Serializable.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetAddress.h>
#include <java/net/NetworkInterface.h>
#include <java/nio/channels/MembershipKey.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <sun/nio/ch/MembershipKeyImpl.h>
#include <sun/nio/ch/MembershipRegistry$ThrowingConsumer.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $InetAddress = ::java::net::InetAddress;
using $NetworkInterface = ::java::net::NetworkInterface;
using $MembershipKey = ::java::nio::channels::MembershipKey;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $MembershipKeyImpl = ::sun::nio::ch::MembershipKeyImpl;
using $MembershipRegistry$ThrowingConsumer = ::sun::nio::ch::MembershipRegistry$ThrowingConsumer;

namespace sun {
	namespace nio {
		namespace ch {

class MembershipRegistry$$Lambda$invalidate : public $MembershipRegistry$ThrowingConsumer {
	$class(MembershipRegistry$$Lambda$invalidate, $NO_CLASS_INIT, $MembershipRegistry$ThrowingConsumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$) override {
		$sure($MembershipKeyImpl, inst$)->invalidate();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<MembershipRegistry$$Lambda$invalidate>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo MembershipRegistry$$Lambda$invalidate::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(MembershipRegistry$$Lambda$invalidate, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(MembershipRegistry$$Lambda$invalidate, accept, void, Object$*)},
	{}
};
$ClassInfo MembershipRegistry$$Lambda$invalidate::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.ch.MembershipRegistry$$Lambda$invalidate",
	"java.lang.Object",
	"sun.nio.ch.MembershipRegistry$ThrowingConsumer",
	nullptr,
	methodInfos
};
$Class* MembershipRegistry$$Lambda$invalidate::load$($String* name, bool initialize) {
	$loadClass(MembershipRegistry$$Lambda$invalidate, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* MembershipRegistry$$Lambda$invalidate::class$ = nullptr;

$FieldInfo _MembershipRegistry_FieldInfo_[] = {
	{"groups", "Ljava/util/Map;", "Ljava/util/Map<Ljava/net/InetAddress;Ljava/util/List<Lsun/nio/ch/MembershipKeyImpl;>;>;", $PRIVATE, $field(MembershipRegistry, groups)},
	{}
};

$MethodInfo _MembershipRegistry_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(MembershipRegistry, init$, void)},
	{"add", "(Lsun/nio/ch/MembershipKeyImpl;)V", nullptr, 0, $virtualMethod(MembershipRegistry, add, void, $MembershipKeyImpl*)},
	{"checkMembership", "(Ljava/net/InetAddress;Ljava/net/NetworkInterface;Ljava/net/InetAddress;)Ljava/nio/channels/MembershipKey;", nullptr, 0, $virtualMethod(MembershipRegistry, checkMembership, $MembershipKey*, $InetAddress*, $NetworkInterface*, $InetAddress*)},
	{"forEach", "(Lsun/nio/ch/MembershipRegistry$ThrowingConsumer;)V", "<X:Ljava/lang/Throwable;>(Lsun/nio/ch/MembershipRegistry$ThrowingConsumer<Lsun/nio/ch/MembershipKeyImpl;TX;>;)V^TX;", 0, $virtualMethod(MembershipRegistry, forEach, void, $MembershipRegistry$ThrowingConsumer*), "java.lang.Throwable"},
	{"invalidateAll", "()V", nullptr, 0, $virtualMethod(MembershipRegistry, invalidateAll, void)},
	{"remove", "(Lsun/nio/ch/MembershipKeyImpl;)V", nullptr, 0, $virtualMethod(MembershipRegistry, remove, void, $MembershipKeyImpl*)},
	{}
};

$InnerClassInfo _MembershipRegistry_InnerClassesInfo_[] = {
	{"sun.nio.ch.MembershipRegistry$ThrowingConsumer", "sun.nio.ch.MembershipRegistry", "ThrowingConsumer", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _MembershipRegistry_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.ch.MembershipRegistry",
	"java.lang.Object",
	nullptr,
	_MembershipRegistry_FieldInfo_,
	_MembershipRegistry_MethodInfo_,
	nullptr,
	nullptr,
	_MembershipRegistry_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.ch.MembershipRegistry$ThrowingConsumer"
};

$Object* allocate$MembershipRegistry($Class* clazz) {
	return $of($alloc(MembershipRegistry));
}

void MembershipRegistry::init$() {
}

$MembershipKey* MembershipRegistry::checkMembership($InetAddress* group, $NetworkInterface* interf, $InetAddress* source) {
	$useLocalCurrentObjectStackCache();
	if (this->groups != nullptr) {
		$var($List, keys, $cast($List, $nc(this->groups)->get(group)));
		if (keys != nullptr) {
			{
				$var($Iterator, i$, keys->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($MembershipKeyImpl, key, $cast($MembershipKeyImpl, i$->next()));
					{
						if ($nc($($nc(key)->networkInterface()))->equals(interf)) {
							if (source == nullptr) {
								if (key->sourceAddress() == nullptr) {
									return key;
								}
								$throwNew($IllegalStateException, "Already a member to receive all packets"_s);
							}
							if (key->sourceAddress() == nullptr) {
								$throwNew($IllegalStateException, "Already have source-specific membership"_s);
							}
							if ($nc(source)->equals($(key->sourceAddress()))) {
								return key;
							}
						}
					}
				}
			}
		}
	}
	return nullptr;
}

void MembershipRegistry::add($MembershipKeyImpl* key) {
	$useLocalCurrentObjectStackCache();
	$var($InetAddress, group, $nc(key)->group());
	$var($List, keys, nullptr);
	if (this->groups == nullptr) {
		$set(this, groups, $new($HashMap));
		$assign(keys, nullptr);
	} else {
		$assign(keys, $cast($List, $nc(this->groups)->get(group)));
	}
	if (keys == nullptr) {
		$assign(keys, $new($LinkedList));
		$nc(this->groups)->put(group, keys);
	}
	$nc(keys)->add(key);
}

void MembershipRegistry::remove($MembershipKeyImpl* key) {
	$useLocalCurrentObjectStackCache();
	$var($InetAddress, group, $nc(key)->group());
	$var($List, keys, $cast($List, $nc(this->groups)->get(group)));
	if (keys != nullptr) {
		$var($Iterator, i, keys->iterator());
		while ($nc(i)->hasNext()) {
			if ($equals(i->next(), key)) {
				i->remove();
				break;
			}
		}
		if (keys->isEmpty()) {
			$nc(this->groups)->remove(group);
		}
	}
}

void MembershipRegistry::forEach($MembershipRegistry$ThrowingConsumer* action) {
	$useLocalCurrentObjectStackCache();
	if (this->groups != nullptr) {
		{
			$var($Iterator, i$, $nc($($nc(this->groups)->values()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($List, keys, $cast($List, i$->next()));
				{
					{
						$var($Iterator, i$, $nc(keys)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($MembershipKeyImpl, key, $cast($MembershipKeyImpl, i$->next()));
							{
								$nc(action)->accept(key);
							}
						}
					}
				}
			}
		}
	}
}

void MembershipRegistry::invalidateAll() {
	forEach(static_cast<$MembershipRegistry$ThrowingConsumer*>($$new(MembershipRegistry$$Lambda$invalidate)));
}

MembershipRegistry::MembershipRegistry() {
}

$Class* MembershipRegistry::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(MembershipRegistry$$Lambda$invalidate::classInfo$.name)) {
			return MembershipRegistry$$Lambda$invalidate::load$(name, initialize);
		}
	}
	$loadClass(MembershipRegistry, name, initialize, &_MembershipRegistry_ClassInfo_, allocate$MembershipRegistry);
	return class$;
}

$Class* MembershipRegistry::class$ = nullptr;

		} // ch
	} // nio
} // sun
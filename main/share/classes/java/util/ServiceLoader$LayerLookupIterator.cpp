#include <java/util/ServiceLoader$LayerLookupIterator.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ModuleLayer.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Deque.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/ServiceConfigurationError.h>
#include <java/util/ServiceLoader$Provider.h>
#include <java/util/ServiceLoader.h>
#include <java/util/Set.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/module/ServicesCatalog$ServiceProvider.h>
#include <jdk/internal/module/ServicesCatalog.h>
#include <jcpp.h>

#undef LANG_ACCESS

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ModuleLayer = ::java::lang::ModuleLayer;
using $ArrayDeque = ::java::util::ArrayDeque;
using $Deque = ::java::util::Deque;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $ServiceConfigurationError = ::java::util::ServiceConfigurationError;
using $ServiceLoader = ::java::util::ServiceLoader;
using $ServiceLoader$Provider = ::java::util::ServiceLoader$Provider;
using $Set = ::java::util::Set;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $ServicesCatalog = ::jdk::internal::module::ServicesCatalog;
using $ServicesCatalog$ServiceProvider = ::jdk::internal::module::ServicesCatalog$ServiceProvider;

namespace java {
	namespace util {

$FieldInfo _ServiceLoader$LayerLookupIterator_FieldInfo_[] = {
	{"this$0", "Ljava/util/ServiceLoader;", nullptr, $FINAL | $SYNTHETIC, $field(ServiceLoader$LayerLookupIterator, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ServiceLoader$LayerLookupIterator, $assertionsDisabled)},
	{"stack", "Ljava/util/Deque;", "Ljava/util/Deque<Ljava/lang/ModuleLayer;>;", 0, $field(ServiceLoader$LayerLookupIterator, stack)},
	{"visited", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/ModuleLayer;>;", 0, $field(ServiceLoader$LayerLookupIterator, visited)},
	{"iterator", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljdk/internal/module/ServicesCatalog$ServiceProvider;>;", 0, $field(ServiceLoader$LayerLookupIterator, iterator)},
	{"nextProvider", "Ljava/util/ServiceLoader$Provider;", "Ljava/util/ServiceLoader$Provider<TT;>;", 0, $field(ServiceLoader$LayerLookupIterator, nextProvider)},
	{"nextError", "Ljava/util/ServiceConfigurationError;", nullptr, 0, $field(ServiceLoader$LayerLookupIterator, nextError)},
	{}
};

$MethodInfo _ServiceLoader$LayerLookupIterator_MethodInfo_[] = {
	{"<init>", "(Ljava/util/ServiceLoader;)V", nullptr, 0, $method(ServiceLoader$LayerLookupIterator, init$, void, $ServiceLoader*)},
	{"hasNext", "()Z", nullptr, $PUBLIC, $virtualMethod(ServiceLoader$LayerLookupIterator, hasNext, bool)},
	{"next", "()Ljava/util/ServiceLoader$Provider;", "()Ljava/util/ServiceLoader$Provider<TT;>;", $PUBLIC, $virtualMethod(ServiceLoader$LayerLookupIterator, next, $Object*)},
	{"providers", "(Ljava/lang/ModuleLayer;)Ljava/util/Iterator;", "(Ljava/lang/ModuleLayer;)Ljava/util/Iterator<Ljdk/internal/module/ServicesCatalog$ServiceProvider;>;", $PRIVATE, $method(ServiceLoader$LayerLookupIterator, providers, $Iterator*, $ModuleLayer*)},
	{}
};

$InnerClassInfo _ServiceLoader$LayerLookupIterator_InnerClassesInfo_[] = {
	{"java.util.ServiceLoader$LayerLookupIterator", "java.util.ServiceLoader", "LayerLookupIterator", $PRIVATE | $FINAL},
	{"java.util.ServiceLoader$Provider", "java.util.ServiceLoader", "Provider", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ServiceLoader$LayerLookupIterator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.ServiceLoader$LayerLookupIterator",
	"java.lang.Object",
	"java.util.Iterator",
	_ServiceLoader$LayerLookupIterator_FieldInfo_,
	_ServiceLoader$LayerLookupIterator_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljava/lang/Object;Ljava/util/Iterator<Ljava/util/ServiceLoader$Provider<TT;>;>;",
	nullptr,
	_ServiceLoader$LayerLookupIterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.ServiceLoader"
};

$Object* allocate$ServiceLoader$LayerLookupIterator($Class* clazz) {
	return $of($alloc(ServiceLoader$LayerLookupIterator));
}

bool ServiceLoader$LayerLookupIterator::$assertionsDisabled = false;

void ServiceLoader$LayerLookupIterator::init$($ServiceLoader* this$0) {
	$set(this, this$0, this$0);
	$set(this, stack, $new($ArrayDeque));
	$set(this, visited, $new($HashSet));
	$nc(this->visited)->add(this$0->layer);
	$nc(this->stack)->push(this$0->layer);
}

$Iterator* ServiceLoader$LayerLookupIterator::providers($ModuleLayer* layer) {
	$useLocalCurrentObjectStackCache();
	$init($ServiceLoader);
	$var($ServicesCatalog, catalog, $nc($ServiceLoader::LANG_ACCESS)->getServicesCatalog(layer));
	return $nc($($nc(catalog)->findServices(this->this$0->serviceName)))->iterator();
}

bool ServiceLoader$LayerLookupIterator::hasNext() {
	$useLocalCurrentObjectStackCache();
	while (this->nextProvider == nullptr && this->nextError == nullptr) {
		while (this->iterator == nullptr || !$nc(this->iterator)->hasNext()) {
			if ($nc(this->stack)->isEmpty()) {
				return false;
			}
			$var($ModuleLayer, layer, $cast($ModuleLayer, $nc(this->stack)->pop()));
			$var($List, parents, $nc(layer)->parents());
			for (int32_t i = $nc(parents)->size() - 1; i >= 0; --i) {
				$var($ModuleLayer, parent, $cast($ModuleLayer, parents->get(i)));
				if ($nc(this->visited)->add(parent)) {
					$nc(this->stack)->push(parent);
				}
			}
			$set(this, iterator, providers(layer));
		}
		$var($ServicesCatalog$ServiceProvider, provider, $cast($ServicesCatalog$ServiceProvider, $nc(this->iterator)->next()));
		try {
			$var($ServiceLoader$Provider, next, this->this$0->loadProvider(provider));
			$set(this, nextProvider, next);
		} catch ($ServiceConfigurationError& e) {
			$set(this, nextError, e);
		}
	}
	return true;
}

$Object* ServiceLoader$LayerLookupIterator::next() {
	$useLocalCurrentObjectStackCache();
	if (!hasNext()) {
		$throwNew($NoSuchElementException);
	}
	$var($ServiceLoader$Provider, provider, this->nextProvider);
	if (provider != nullptr) {
		$set(this, nextProvider, nullptr);
		return $of(provider);
	} else {
		$var($ServiceConfigurationError, e, this->nextError);
		if (!ServiceLoader$LayerLookupIterator::$assertionsDisabled && !(e != nullptr)) {
			$throwNew($AssertionError);
		}
		$set(this, nextError, nullptr);
		$throw(e);
	}
}

void clinit$ServiceLoader$LayerLookupIterator($Class* class$) {
	$load($ServiceLoader);
	ServiceLoader$LayerLookupIterator::$assertionsDisabled = !$ServiceLoader::class$->desiredAssertionStatus();
}

ServiceLoader$LayerLookupIterator::ServiceLoader$LayerLookupIterator() {
}

$Class* ServiceLoader$LayerLookupIterator::load$($String* name, bool initialize) {
	$loadClass(ServiceLoader$LayerLookupIterator, name, initialize, &_ServiceLoader$LayerLookupIterator_ClassInfo_, clinit$ServiceLoader$LayerLookupIterator, allocate$ServiceLoader$LayerLookupIterator);
	return class$;
}

$Class* ServiceLoader$LayerLookupIterator::class$ = nullptr;

	} // util
} // java
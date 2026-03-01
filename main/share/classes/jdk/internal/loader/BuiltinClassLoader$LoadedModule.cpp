#include <jdk/internal/loader/BuiltinClassLoader$LoadedModule.h>

#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleReference.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/util/Optional.h>
#include <jdk/internal/loader/BuiltinClassLoader.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $Optional = ::java::util::Optional;
using $BuiltinClassLoader = ::jdk::internal::loader::BuiltinClassLoader;

namespace jdk {
	namespace internal {
		namespace loader {

$CompoundAttribute _BuiltinClassLoader$LoadedModule_FieldAnnotations_codeSourceURL[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$FieldInfo _BuiltinClassLoader$LoadedModule_FieldInfo_[] = {
	{"loader", "Ljdk/internal/loader/BuiltinClassLoader;", nullptr, $PRIVATE | $FINAL, $field(BuiltinClassLoader$LoadedModule, loader$)},
	{"mref", "Ljava/lang/module/ModuleReference;", nullptr, $PRIVATE | $FINAL, $field(BuiltinClassLoader$LoadedModule, mref$)},
	{"uri", "Ljava/net/URI;", nullptr, $PRIVATE | $FINAL, $field(BuiltinClassLoader$LoadedModule, uri)},
	{"codeSourceURL", "Ljava/net/URL;", nullptr, $PRIVATE, $field(BuiltinClassLoader$LoadedModule, codeSourceURL$), _BuiltinClassLoader$LoadedModule_FieldAnnotations_codeSourceURL},
	{}
};

$MethodInfo _BuiltinClassLoader$LoadedModule_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/loader/BuiltinClassLoader;Ljava/lang/module/ModuleReference;)V", nullptr, 0, $method(BuiltinClassLoader$LoadedModule, init$, void, $BuiltinClassLoader*, $ModuleReference*)},
	{"codeSourceURL", "()Ljava/net/URL;", nullptr, 0, $virtualMethod(BuiltinClassLoader$LoadedModule, codeSourceURL, $URL*)},
	{"createURL", "(Ljava/net/URI;)Ljava/net/URL;", nullptr, $PRIVATE, $method(BuiltinClassLoader$LoadedModule, createURL, $URL*, $URI*)},
	{"loader", "()Ljdk/internal/loader/BuiltinClassLoader;", nullptr, 0, $virtualMethod(BuiltinClassLoader$LoadedModule, loader, $BuiltinClassLoader*)},
	{"mref", "()Ljava/lang/module/ModuleReference;", nullptr, 0, $virtualMethod(BuiltinClassLoader$LoadedModule, mref, $ModuleReference*)},
	{"name", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(BuiltinClassLoader$LoadedModule, name, $String*)},
	{}
};

$InnerClassInfo _BuiltinClassLoader$LoadedModule_InnerClassesInfo_[] = {
	{"jdk.internal.loader.BuiltinClassLoader$LoadedModule", "jdk.internal.loader.BuiltinClassLoader", "LoadedModule", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _BuiltinClassLoader$LoadedModule_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.loader.BuiltinClassLoader$LoadedModule",
	"java.lang.Object",
	nullptr,
	_BuiltinClassLoader$LoadedModule_FieldInfo_,
	_BuiltinClassLoader$LoadedModule_MethodInfo_,
	nullptr,
	nullptr,
	_BuiltinClassLoader$LoadedModule_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.loader.BuiltinClassLoader"
};

$Object* allocate$BuiltinClassLoader$LoadedModule($Class* clazz) {
	return $of($alloc(BuiltinClassLoader$LoadedModule));
}

void BuiltinClassLoader$LoadedModule::init$($BuiltinClassLoader* loader, $ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($URL, url, nullptr);
	$set(this, uri, $cast($URI, $nc($($nc(mref)->location()))->orElse(nullptr)));
	if (this->uri != nullptr && !"jrt"_s->equals($($nc(this->uri)->getScheme()))) {
		$assign(url, createURL(this->uri));
	}
	$set(this, loader$, loader);
	$set(this, mref$, mref);
	$set(this, codeSourceURL$, url);
}

$BuiltinClassLoader* BuiltinClassLoader$LoadedModule::loader() {
	return this->loader$;
}

$ModuleReference* BuiltinClassLoader$LoadedModule::mref() {
	return this->mref$;
}

$String* BuiltinClassLoader$LoadedModule::name() {
	return $nc($($nc(this->mref$)->descriptor()))->name();
}

$URL* BuiltinClassLoader$LoadedModule::codeSourceURL() {
	$var($URL, url, this->codeSourceURL$);
	if (url == nullptr && this->uri != nullptr) {
		$set(this, codeSourceURL$, ($assign(url, createURL(this->uri))));
	}
	return url;
}

$URL* BuiltinClassLoader$LoadedModule::createURL($URI* uri) {
	$var($URL, url, nullptr);
	try {
		$assign(url, $nc(uri)->toURL());
	} catch ($MalformedURLException& e) {
	} catch ($IllegalArgumentException& e) {
	}
	return url;
}

BuiltinClassLoader$LoadedModule::BuiltinClassLoader$LoadedModule() {
}

$Class* BuiltinClassLoader$LoadedModule::load$($String* name, bool initialize) {
	$loadClass(BuiltinClassLoader$LoadedModule, name, initialize, &_BuiltinClassLoader$LoadedModule_ClassInfo_, allocate$BuiltinClassLoader$LoadedModule);
	return class$;
}

$Class* BuiltinClassLoader$LoadedModule::class$ = nullptr;

		} // loader
	} // internal
} // jdk
#include <jdk/internal/loader/Loader$LoadedModule.h>

#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleReference.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/security/CodeSigner.h>
#include <java/security/CodeSource.h>
#include <java/util/Optional.h>
#include <jdk/internal/loader/Loader.h>
#include <jcpp.h>

using $CodeSignerArray = $Array<::java::security::CodeSigner>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $CodeSource = ::java::security::CodeSource;
using $Optional = ::java::util::Optional;

namespace jdk {
	namespace internal {
		namespace loader {

$FieldInfo _Loader$LoadedModule_FieldInfo_[] = {
	{"mref", "Ljava/lang/module/ModuleReference;", nullptr, $PRIVATE | $FINAL, $field(Loader$LoadedModule, mref$)},
	{"url", "Ljava/net/URL;", nullptr, $PRIVATE | $FINAL, $field(Loader$LoadedModule, url)},
	{"cs", "Ljava/security/CodeSource;", nullptr, $PRIVATE | $FINAL, $field(Loader$LoadedModule, cs)},
	{}
};

$MethodInfo _Loader$LoadedModule_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/module/ModuleReference;)V", nullptr, 0, $method(Loader$LoadedModule, init$, void, $ModuleReference*)},
	{"codeSource", "()Ljava/security/CodeSource;", nullptr, 0, $virtualMethod(Loader$LoadedModule, codeSource, $CodeSource*)},
	{"location", "()Ljava/net/URL;", nullptr, 0, $virtualMethod(Loader$LoadedModule, location, $URL*)},
	{"mref", "()Ljava/lang/module/ModuleReference;", nullptr, 0, $virtualMethod(Loader$LoadedModule, mref, $ModuleReference*)},
	{"name", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(Loader$LoadedModule, name, $String*)},
	{}
};

$InnerClassInfo _Loader$LoadedModule_InnerClassesInfo_[] = {
	{"jdk.internal.loader.Loader$LoadedModule", "jdk.internal.loader.Loader", "LoadedModule", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Loader$LoadedModule_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.loader.Loader$LoadedModule",
	"java.lang.Object",
	nullptr,
	_Loader$LoadedModule_FieldInfo_,
	_Loader$LoadedModule_MethodInfo_,
	nullptr,
	nullptr,
	_Loader$LoadedModule_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.loader.Loader"
};

$Object* allocate$Loader$LoadedModule($Class* clazz) {
	return $of($alloc(Loader$LoadedModule));
}

void Loader$LoadedModule::init$($ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($URL, url, nullptr);
	if ($nc($($nc(mref)->location()))->isPresent()) {
		try {
			$assign(url, $nc(($cast($URI, $($nc($(mref->location()))->get()))))->toURL());
		} catch ($MalformedURLException& e) {
		} catch ($IllegalArgumentException& e) {
		}
	}
	$set(this, mref$, mref);
	$set(this, url, url);
	$set(this, cs, $new($CodeSource, url, ($CodeSignerArray*)nullptr));
}

$ModuleReference* Loader$LoadedModule::mref() {
	return this->mref$;
}

$String* Loader$LoadedModule::name() {
	return $nc($($nc(this->mref$)->descriptor()))->name();
}

$URL* Loader$LoadedModule::location() {
	return this->url;
}

$CodeSource* Loader$LoadedModule::codeSource() {
	return this->cs;
}

Loader$LoadedModule::Loader$LoadedModule() {
}

$Class* Loader$LoadedModule::load$($String* name, bool initialize) {
	$loadClass(Loader$LoadedModule, name, initialize, &_Loader$LoadedModule_ClassInfo_, allocate$Loader$LoadedModule);
	return class$;
}

$Class* Loader$LoadedModule::class$ = nullptr;

		} // loader
	} // internal
} // jdk
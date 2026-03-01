#include <jdk/internal/module/ModulePatcher$PatchedModuleReader.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/module/ModuleReader.h>
#include <java/lang/module/ModuleReference.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/loader/Resource.h>
#include <jdk/internal/module/ModulePatcher$ExplodedResourceFinder.h>
#include <jdk/internal/module/ModulePatcher$JarResourceFinder.h>
#include <jdk/internal/module/ModulePatcher$PatchedModuleReader$1.h>
#include <jdk/internal/module/ModulePatcher$ResourceFinder.h>
#include <jdk/internal/module/ModulePatcher.h>
#include <jcpp.h>

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $IOException = ::java::io::IOException;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ModuleReader = ::java::lang::module::ModuleReader;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $Stream = ::java::util::stream::Stream;
using $Resource = ::jdk::internal::loader::Resource;
using $ModulePatcher = ::jdk::internal::module::ModulePatcher;
using $ModulePatcher$ExplodedResourceFinder = ::jdk::internal::module::ModulePatcher$ExplodedResourceFinder;
using $ModulePatcher$JarResourceFinder = ::jdk::internal::module::ModulePatcher$JarResourceFinder;
using $ModulePatcher$PatchedModuleReader$1 = ::jdk::internal::module::ModulePatcher$PatchedModuleReader$1;
using $ModulePatcher$ResourceFinder = ::jdk::internal::module::ModulePatcher$ResourceFinder;

namespace jdk {
	namespace internal {
		namespace module {

$FieldInfo _ModulePatcher$PatchedModuleReader_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ModulePatcher$PatchedModuleReader, $assertionsDisabled)},
	{"finders", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/module/ModulePatcher$ResourceFinder;>;", $PRIVATE | $FINAL, $field(ModulePatcher$PatchedModuleReader, finders)},
	{"mref", "Ljava/lang/module/ModuleReference;", nullptr, $PRIVATE | $FINAL, $field(ModulePatcher$PatchedModuleReader, mref)},
	{"delegateCodeSourceURL", "Ljava/net/URL;", nullptr, $PRIVATE | $FINAL, $field(ModulePatcher$PatchedModuleReader, delegateCodeSourceURL)},
	{"delegate", "Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE | $VOLATILE, $field(ModulePatcher$PatchedModuleReader, delegate$)},
	{}
};

$MethodInfo _ModulePatcher$PatchedModuleReader_MethodInfo_[] = {
	{"<init>", "(Ljava/util/List;Ljava/lang/module/ModuleReference;)V", "(Ljava/util/List<Ljava/nio/file/Path;>;Ljava/lang/module/ModuleReference;)V", 0, $method(ModulePatcher$PatchedModuleReader, init$, void, $List*, $ModuleReference*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$PatchedModuleReader, close, void), "java.io.IOException"},
	{"closeAll", "(Ljava/util/List;)V", "(Ljava/util/List<Ljdk/internal/module/ModulePatcher$ResourceFinder;>;)V", $PRIVATE | $STATIC, $staticMethod(ModulePatcher$PatchedModuleReader, closeAll, void, $List*)},
	{"codeSourceURL", "(Ljava/lang/module/ModuleReference;)Ljava/net/URL;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModulePatcher$PatchedModuleReader, codeSourceURL, $URL*, $ModuleReference*)},
	{"delegate", "()Ljava/lang/module/ModuleReader;", nullptr, $PRIVATE, $method(ModulePatcher$PatchedModuleReader, delegate, $ModuleReader*), "java.io.IOException"},
	{"find", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/net/URI;>;", $PUBLIC, $virtualMethod(ModulePatcher$PatchedModuleReader, find, $Optional*, $String*), "java.io.IOException"},
	{"findResource", "(Ljava/lang/String;)Ljdk/internal/loader/Resource;", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$PatchedModuleReader, findResource, $Resource*, $String*), "java.io.IOException"},
	{"findResourceInPatch", "(Ljava/lang/String;)Ljdk/internal/loader/Resource;", nullptr, $PRIVATE, $method(ModulePatcher$PatchedModuleReader, findResourceInPatch, $Resource*, $String*), "java.io.IOException"},
	{"list", "()Ljava/util/stream/Stream;", "()Ljava/util/stream/Stream<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(ModulePatcher$PatchedModuleReader, list, $Stream*), "java.io.IOException"},
	{"open", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/io/InputStream;>;", $PUBLIC, $virtualMethod(ModulePatcher$PatchedModuleReader, open, $Optional*, $String*), "java.io.IOException"},
	{"read", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/nio/ByteBuffer;>;", $PUBLIC, $virtualMethod(ModulePatcher$PatchedModuleReader, read, $Optional*, $String*), "java.io.IOException"},
	{"release", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $virtualMethod(ModulePatcher$PatchedModuleReader, release, void, $ByteBuffer*)},
	{}
};

$InnerClassInfo _ModulePatcher$PatchedModuleReader_InnerClassesInfo_[] = {
	{"jdk.internal.module.ModulePatcher$PatchedModuleReader", "jdk.internal.module.ModulePatcher", "PatchedModuleReader", $PUBLIC | $STATIC},
	{"jdk.internal.module.ModulePatcher$PatchedModuleReader$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ModulePatcher$PatchedModuleReader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.module.ModulePatcher$PatchedModuleReader",
	"java.lang.Object",
	"java.lang.module.ModuleReader",
	_ModulePatcher$PatchedModuleReader_FieldInfo_,
	_ModulePatcher$PatchedModuleReader_MethodInfo_,
	nullptr,
	nullptr,
	_ModulePatcher$PatchedModuleReader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.module.ModulePatcher"
};

$Object* allocate$ModulePatcher$PatchedModuleReader($Class* clazz) {
	return $of($alloc(ModulePatcher$PatchedModuleReader));
}

bool ModulePatcher$PatchedModuleReader::$assertionsDisabled = false;

void ModulePatcher$PatchedModuleReader::init$($List* patches, $ModuleReference* mref) {
	$useLocalCurrentObjectStackCache();
	$var($List, finders, $new($ArrayList));
	bool initialized = false;
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				{
					$var($Iterator, i$, $nc(patches)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Path, file, $cast($Path, i$->next()));
						{
							if ($Files::isRegularFile(file, $$new($LinkOptionArray, 0))) {
								finders->add($$new($ModulePatcher$JarResourceFinder, file));
							} else {
								finders->add($$new($ModulePatcher$ExplodedResourceFinder, file));
							}
						}
					}
				}
				initialized = true;
			} catch ($IOException& ioe) {
				$throwNew($UncheckedIOException, ioe);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (!initialized) {
				closeAll(finders);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$set(this, finders, finders);
	$set(this, mref, mref);
	$set(this, delegateCodeSourceURL, codeSourceURL(mref));
}

void ModulePatcher$PatchedModuleReader::closeAll($List* finders) {
	$init(ModulePatcher$PatchedModuleReader);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(finders)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModulePatcher$ResourceFinder, finder, $cast($ModulePatcher$ResourceFinder, i$->next()));
			{
				try {
					$nc(finder)->close();
				} catch ($IOException& ioe) {
				}
			}
		}
	}
}

$URL* ModulePatcher$PatchedModuleReader::codeSourceURL($ModuleReference* mref) {
	$init(ModulePatcher$PatchedModuleReader);
	$useLocalCurrentObjectStackCache();
	try {
		$var($Optional, ouri, $nc(mref)->location());
		if ($nc(ouri)->isPresent()) {
			return $nc(($cast($URI, $(ouri->get()))))->toURL();
		}
	} catch ($MalformedURLException& e) {
	}
	return nullptr;
}

$ModuleReader* ModulePatcher$PatchedModuleReader::delegate() {
	$var($ModuleReader, r, this->delegate$);
	if (r == nullptr) {
		$synchronized(this) {
			$assign(r, this->delegate$);
			if (r == nullptr) {
				$set(this, delegate$, ($assign(r, $nc(this->mref)->open())));
			}
		}
	}
	return r;
}

$Resource* ModulePatcher$PatchedModuleReader::findResourceInPatch($String* name) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(name)->equals("module-info.class"_s)) {
		{
			$var($Iterator, i$, $nc(this->finders)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ModulePatcher$ResourceFinder, finder, $cast($ModulePatcher$ResourceFinder, i$->next()));
				{
					$var($Resource, r, $nc(finder)->find(name));
					if (r != nullptr) {
						return r;
					}
				}
			}
		}
	}
	return nullptr;
}

$Resource* ModulePatcher$PatchedModuleReader::findResource($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Resource, r, findResourceInPatch(name));
	if (r != nullptr) {
		return r;
	}
	$var($ByteBuffer, bb, $cast($ByteBuffer, $nc($($nc($(delegate()))->read(name)))->orElse(nullptr)));
	if (bb == nullptr) {
		return nullptr;
	}
	return $new($ModulePatcher$PatchedModuleReader$1, this, bb);
}

$Optional* ModulePatcher$PatchedModuleReader::find($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Resource, r, findResourceInPatch(name));
	if (r != nullptr) {
		$var($URI, uri, $URI::create($($nc($(r->getURL()))->toString())));
		return $Optional::of(uri);
	} else {
		return $nc($(delegate()))->find(name);
	}
}

$Optional* ModulePatcher$PatchedModuleReader::open($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Resource, r, findResourceInPatch(name));
	if (r != nullptr) {
		return $Optional::of($(r->getInputStream()));
	} else {
		return $nc($(delegate()))->open(name);
	}
}

$Optional* ModulePatcher$PatchedModuleReader::read($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($Resource, r, findResourceInPatch(name));
	if (r != nullptr) {
		$var($ByteBuffer, bb, r->getByteBuffer());
		if (!ModulePatcher$PatchedModuleReader::$assertionsDisabled && ! !$nc(bb)->isDirect()) {
			$throwNew($AssertionError);
		}
		return $Optional::of(bb);
	} else {
		return $nc($(delegate()))->read(name);
	}
}

void ModulePatcher$PatchedModuleReader::release($ByteBuffer* bb) {
	if ($nc(bb)->isDirect()) {
		try {
			$nc($(delegate()))->release(bb);
		} catch ($IOException& ioe) {
			$throwNew($InternalError, static_cast<$Throwable*>(ioe));
		}
	}
}

$Stream* ModulePatcher$PatchedModuleReader::list() {
	$useLocalCurrentObjectStackCache();
	$var($Stream, s, $nc($(delegate()))->list());
	{
		$var($Iterator, i$, $nc(this->finders)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModulePatcher$ResourceFinder, finder, $cast($ModulePatcher$ResourceFinder, i$->next()));
			{
				$assign(s, $Stream::concat(s, $($nc(finder)->list())));
			}
		}
	}
	return $nc(s)->distinct();
}

void ModulePatcher$PatchedModuleReader::close() {
	closeAll(this->finders);
	$nc($(delegate()))->close();
}

void clinit$ModulePatcher$PatchedModuleReader($Class* class$) {
	$load($ModulePatcher);
	ModulePatcher$PatchedModuleReader::$assertionsDisabled = !$ModulePatcher::class$->desiredAssertionStatus();
}

ModulePatcher$PatchedModuleReader::ModulePatcher$PatchedModuleReader() {
}

$Class* ModulePatcher$PatchedModuleReader::load$($String* name, bool initialize) {
	$loadClass(ModulePatcher$PatchedModuleReader, name, initialize, &_ModulePatcher$PatchedModuleReader_ClassInfo_, clinit$ModulePatcher$PatchedModuleReader, allocate$ModulePatcher$PatchedModuleReader);
	return class$;
}

$Class* ModulePatcher$PatchedModuleReader::class$ = nullptr;

		} // module
	} // internal
} // jdk
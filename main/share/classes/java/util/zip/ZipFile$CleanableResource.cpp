#include <java/util/zip/ZipFile$CleanableResource.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/Runnable.h>
#include <java/lang/ref/Cleaner$Cleanable.h>
#include <java/lang/ref/Cleaner.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Collections.h>
#include <java/util/Deque.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/WeakHashMap.h>
#include <java/util/zip/Inflater.h>
#include <java/util/zip/ZipCoder.h>
#include <java/util/zip/ZipFile$Source.h>
#include <java/util/zip/ZipFile.h>
#include <jdk/internal/ref/CleanerFactory.h>
#include <jcpp.h>

using $InputStreamArray = $Array<::java::io::InputStream>;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Cleaner = ::java::lang::ref::Cleaner;
using $Cleaner$Cleanable = ::java::lang::ref::Cleaner$Cleanable;
using $ArrayDeque = ::java::util::ArrayDeque;
using $Collections = ::java::util::Collections;
using $Deque = ::java::util::Deque;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $WeakHashMap = ::java::util::WeakHashMap;
using $Inflater = ::java::util::zip::Inflater;
using $ZipCoder = ::java::util::zip::ZipCoder;
using $ZipFile = ::java::util::zip::ZipFile;
using $ZipFile$Source = ::java::util::zip::ZipFile$Source;
using $CleanerFactory = ::jdk::internal::ref::CleanerFactory;

namespace java {
	namespace util {
		namespace zip {

$FieldInfo _ZipFile$CleanableResource_FieldInfo_[] = {
	{"istreams", "Ljava/util/Set;", "Ljava/util/Set<Ljava/io/InputStream;>;", $FINAL, $field(ZipFile$CleanableResource, istreams)},
	{"inflaterCache", "Ljava/util/Deque;", "Ljava/util/Deque<Ljava/util/zip/Inflater;>;", 0, $field(ZipFile$CleanableResource, inflaterCache)},
	{"cleanable", "Ljava/lang/ref/Cleaner$Cleanable;", nullptr, $FINAL, $field(ZipFile$CleanableResource, cleanable)},
	{"zsrc", "Ljava/util/zip/ZipFile$Source;", nullptr, 0, $field(ZipFile$CleanableResource, zsrc)},
	{}
};

$MethodInfo _ZipFile$CleanableResource_MethodInfo_[] = {
	{"<init>", "(Ljava/util/zip/ZipFile;Ljava/util/zip/ZipCoder;Ljava/io/File;I)V", nullptr, 0, $method(ZipFile$CleanableResource, init$, void, $ZipFile*, $ZipCoder*, $File*, int32_t), "java.io.IOException"},
	{"clean", "()V", nullptr, 0, $virtualMethod(ZipFile$CleanableResource, clean, void)},
	{"getInflater", "()Ljava/util/zip/Inflater;", nullptr, 0, $virtualMethod(ZipFile$CleanableResource, getInflater, $Inflater*)},
	{"releaseInflater", "(Ljava/util/zip/Inflater;)V", nullptr, 0, $virtualMethod(ZipFile$CleanableResource, releaseInflater, void, $Inflater*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(ZipFile$CleanableResource, run, void)},
	{}
};

$InnerClassInfo _ZipFile$CleanableResource_InnerClassesInfo_[] = {
	{"java.util.zip.ZipFile$CleanableResource", "java.util.zip.ZipFile", "CleanableResource", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _ZipFile$CleanableResource_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.zip.ZipFile$CleanableResource",
	"java.lang.Object",
	"java.lang.Runnable",
	_ZipFile$CleanableResource_FieldInfo_,
	_ZipFile$CleanableResource_MethodInfo_,
	nullptr,
	nullptr,
	_ZipFile$CleanableResource_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.zip.ZipFile"
};

$Object* allocate$ZipFile$CleanableResource($Class* clazz) {
	return $of($alloc(ZipFile$CleanableResource));
}

void ZipFile$CleanableResource::init$($ZipFile* zf, $ZipCoder* zc, $File* file, int32_t mode) {
	$useLocalCurrentObjectStackCache();
	$set(this, cleanable, $nc($($CleanerFactory::cleaner()))->register$(zf, this));
	$set(this, istreams, $Collections::newSetFromMap($$new($WeakHashMap)));
	$set(this, inflaterCache, $new($ArrayDeque));
	$set(this, zsrc, $ZipFile$Source::get(file, ((int32_t)(mode & (uint32_t)4)) != 0, zc));
}

void ZipFile$CleanableResource::clean() {
	$nc(this->cleanable)->clean();
}

$Inflater* ZipFile$CleanableResource::getInflater() {
	$var($Inflater, inf, nullptr);
	$synchronized(this->inflaterCache) {
		if (($assign(inf, $cast($Inflater, $nc(this->inflaterCache)->poll()))) != nullptr) {
			return inf;
		}
	}
	return $new($Inflater, true);
}

void ZipFile$CleanableResource::releaseInflater($Inflater* inf) {
	$var($Deque, inflaters, this->inflaterCache);
	if (inflaters != nullptr) {
		$synchronized(inflaters) {
			if (inflaters == this->inflaterCache) {
				$nc(inf)->reset();
				inflaters->add(inf);
				return;
			}
		}
	}
	$nc(inf)->end();
}

void ZipFile$CleanableResource::run() {
	$useLocalCurrentObjectStackCache();
	$var($IOException, ioe, nullptr);
	$var($Deque, inflaters, this->inflaterCache);
	if (inflaters != nullptr) {
		$synchronized(inflaters) {
			$var($Inflater, inf, nullptr);
			while (($assign(inf, $cast($Inflater, inflaters->poll()))) != nullptr) {
				$nc(inf)->end();
			}
			$set(this, inflaterCache, nullptr);
		}
	}
	if (this->istreams != nullptr) {
		$synchronized(this->istreams) {
			if (!$nc(this->istreams)->isEmpty()) {
				$var($InputStreamArray, copy, $fcast($InputStreamArray, $nc(this->istreams)->toArray($$new($InputStreamArray, 0))));
				$nc(this->istreams)->clear();
				{
					$var($InputStreamArray, arr$, copy);
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($InputStream, is, arr$->get(i$));
						{
							try {
								$nc(is)->close();
							} catch ($IOException& e) {
								if (ioe == nullptr) {
									$assign(ioe, e);
								} else {
									$nc(ioe)->addSuppressed(e);
								}
							}
						}
					}
				}
			}
		}
	}
	if (this->zsrc != nullptr) {
		$synchronized(this->zsrc) {
			try {
				$ZipFile$Source::release(this->zsrc);
				$set(this, zsrc, nullptr);
			} catch ($IOException& e) {
				if (ioe == nullptr) {
					$assign(ioe, e);
				} else {
					$nc(ioe)->addSuppressed(e);
				}
			}
		}
	}
	if (ioe != nullptr) {
		$throwNew($UncheckedIOException, ioe);
	}
}

ZipFile$CleanableResource::ZipFile$CleanableResource() {
}

$Class* ZipFile$CleanableResource::load$($String* name, bool initialize) {
	$loadClass(ZipFile$CleanableResource, name, initialize, &_ZipFile$CleanableResource_ClassInfo_, allocate$ZipFile$CleanableResource);
	return class$;
}

$Class* ZipFile$CleanableResource::class$ = nullptr;

		} // zip
	} // util
} // java
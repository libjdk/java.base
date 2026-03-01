#include <sun/security/provider/FileInputStreamPool.h>

#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <sun/security/provider/FileInputStreamPool$StreamRef.h>
#include <sun/security/provider/FileInputStreamPool$UnclosableInputStream.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $FileInputStreamPool$StreamRef = ::sun::security::provider::FileInputStreamPool$StreamRef;
using $FileInputStreamPool$UnclosableInputStream = ::sun::security::provider::FileInputStreamPool$UnclosableInputStream;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _FileInputStreamPool_FieldInfo_[] = {
	{"pool", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/io/File;Lsun/security/provider/FileInputStreamPool$StreamRef;>;", $PRIVATE | $STATIC | $FINAL, $staticField(FileInputStreamPool, pool)},
	{"refQueue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Lsun/security/provider/FileInputStreamPool$UnclosableInputStream;>;", $PRIVATE | $STATIC | $FINAL, $staticField(FileInputStreamPool, refQueue)},
	{}
};

$MethodInfo _FileInputStreamPool_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(FileInputStreamPool, init$, void)},
	{"getInputStream", "(Ljava/io/File;)Ljava/io/InputStream;", nullptr, $STATIC, $staticMethod(FileInputStreamPool, getInputStream, $InputStream*, $File*), "java.io.IOException"},
	{}
};

$InnerClassInfo _FileInputStreamPool_InnerClassesInfo_[] = {
	{"sun.security.provider.FileInputStreamPool$UnclosableInputStream", "sun.security.provider.FileInputStreamPool", "UnclosableInputStream", $PRIVATE | $STATIC | $FINAL},
	{"sun.security.provider.FileInputStreamPool$StreamRef", "sun.security.provider.FileInputStreamPool", "StreamRef", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _FileInputStreamPool_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.FileInputStreamPool",
	"java.lang.Object",
	nullptr,
	_FileInputStreamPool_FieldInfo_,
	_FileInputStreamPool_MethodInfo_,
	nullptr,
	nullptr,
	_FileInputStreamPool_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.FileInputStreamPool$UnclosableInputStream,sun.security.provider.FileInputStreamPool$StreamRef"
};

$Object* allocate$FileInputStreamPool($Class* clazz) {
	return $of($alloc(FileInputStreamPool));
}

$ConcurrentMap* FileInputStreamPool::pool = nullptr;
$ReferenceQueue* FileInputStreamPool::refQueue = nullptr;

void FileInputStreamPool::init$() {
}

$InputStream* FileInputStreamPool::getInputStream($File* file) {
	$init(FileInputStreamPool);
	$useLocalCurrentObjectStackCache();
	$var($FileInputStreamPool$StreamRef, oldRref, nullptr);
	while (($assign(oldRref, $cast($FileInputStreamPool$StreamRef, $nc(FileInputStreamPool::refQueue)->poll()))) != nullptr) {
		$nc(FileInputStreamPool::pool)->remove($nc(oldRref)->file, oldRref);
	}
	$var($File, cfile, $nc(file)->getCanonicalFile());
	$assign(oldRref, $cast($FileInputStreamPool$StreamRef, $nc(FileInputStreamPool::pool)->get(cfile)));
	$var($FileInputStreamPool$UnclosableInputStream, oldStream, (oldRref == nullptr) ? ($FileInputStreamPool$UnclosableInputStream*)nullptr : $cast($FileInputStreamPool$UnclosableInputStream, $nc(oldRref)->get()));
	$var($FileInputStreamPool$StreamRef, newRef, nullptr);
	$var($FileInputStreamPool$UnclosableInputStream, newStream, nullptr);
	while (true) {
		if (oldStream != nullptr) {
			if (newStream != nullptr) {
				try {
					$nc($(newStream->getWrappedStream()))->close();
				} catch ($IOException& ignore) {
				}
			}
			return oldStream;
		} else {
			if (newStream == nullptr) {
				$assign(newStream, $new($FileInputStreamPool$UnclosableInputStream, $$new($FileInputStream, cfile)));
				$assign(newRef, $new($FileInputStreamPool$StreamRef, cfile, newStream, FileInputStreamPool::refQueue));
			}
			if (oldRref == nullptr) {
				$assign(oldRref, $cast($FileInputStreamPool$StreamRef, $nc(FileInputStreamPool::pool)->putIfAbsent(cfile, newRef)));
			} else {
				$assign(oldRref, $nc(FileInputStreamPool::pool)->replace(cfile, oldRref, newRef) ? ($FileInputStreamPool$StreamRef*)nullptr : $cast($FileInputStreamPool$StreamRef, $nc(FileInputStreamPool::pool)->get(cfile)));
			}
			if (oldRref == nullptr) {
				return newStream;
			} else {
				$assign(oldStream, $cast($FileInputStreamPool$UnclosableInputStream, oldRref->get()));
			}
		}
	}
}

void clinit$FileInputStreamPool($Class* class$) {
	$assignStatic(FileInputStreamPool::pool, $new($ConcurrentHashMap));
	$assignStatic(FileInputStreamPool::refQueue, $new($ReferenceQueue));
}

FileInputStreamPool::FileInputStreamPool() {
}

$Class* FileInputStreamPool::load$($String* name, bool initialize) {
	$loadClass(FileInputStreamPool, name, initialize, &_FileInputStreamPool_ClassInfo_, clinit$FileInputStreamPool, allocate$FileInputStreamPool);
	return class$;
}

$Class* FileInputStreamPool::class$ = nullptr;

		} // provider
	} // security
} // sun
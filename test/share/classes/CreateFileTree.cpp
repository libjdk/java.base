#include <CreateFileTree.h>

#include <java/io/IOException.h>
#include <java/lang/Math.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/FileAttribute.h>
#include <java/util/ArrayDeque.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/Queue.h>
#include <java/util/Random.h>
#include <jcpp.h>

using $FileAttributeArray = $Array<::java::nio::file::attribute::FileAttribute>;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $ArrayDeque = ::java::util::ArrayDeque;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Queue = ::java::util::Queue;
using $Random = ::java::util::Random;

$FieldInfo _CreateFileTree_FieldInfo_[] = {
	{"rand", "Ljava/util/Random;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(CreateFileTree, rand)},
	{}
};

$MethodInfo _CreateFileTree_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(CreateFileTree, init$, void)},
	{"create", "()Ljava/nio/file/Path;", nullptr, $STATIC, $staticMethod(CreateFileTree, create, $Path*), "java.io.IOException"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(CreateFileTree, main, void, $StringArray*), "java.io.IOException"},
	{"supportsLinks", "(Ljava/nio/file/Path;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(CreateFileTree, supportsLinks, bool, $Path*)},
	{}
};

$ClassInfo _CreateFileTree_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"CreateFileTree",
	"java.lang.Object",
	nullptr,
	_CreateFileTree_FieldInfo_,
	_CreateFileTree_MethodInfo_
};

$Object* allocate$CreateFileTree($Class* clazz) {
	return $of($alloc(CreateFileTree));
}

$Random* CreateFileTree::rand = nullptr;

void CreateFileTree::init$() {
}

bool CreateFileTree::supportsLinks($Path* dir) {
	$init(CreateFileTree);
	$useLocalCurrentObjectStackCache();
	$var($Path, link, $nc(dir)->resolve("testlink"_s));
	$var($Path, target, dir->resolve("testtarget"_s));
	try {
		$Files::createSymbolicLink(link, target, $$new($FileAttributeArray, 0));
		$Files::delete$(link);
		return true;
	} catch ($UnsupportedOperationException& x) {
		return false;
	} catch ($IOException& x) {
		return false;
	}
	$shouldNotReachHere();
}

$Path* CreateFileTree::create() {
	$init(CreateFileTree);
	$useLocalCurrentObjectStackCache();
	$var($Path, top, $Files::createTempDirectory("tree"_s, $$new($FileAttributeArray, 0)));
	$var($List, dirs, $new($ArrayList));
	$var($Queue, queue, $new($ArrayDeque));
	queue->add(top);
	int32_t total = 1 + $nc(CreateFileTree::rand)->nextInt(20);
	int32_t n = 0;
	$var($Path, dir, nullptr);
	while ((($assign(dir, $cast($Path, queue->poll()))) != nullptr) && (n < total)) {
		int32_t r = $Math::min((total - n), (1 + $nc(CreateFileTree::rand)->nextInt(3)));
		for (int32_t i = 0; i < r; ++i) {
			$var($String, name, $str({"dir"_s, $$str((++n))}));
			$var($Path, subdir, $Files::createDirectory($($nc(dir)->resolve(name)), $$new($FileAttributeArray, 0)));
			queue->offer(subdir);
			dirs->add(subdir);
		}
	}
	int32_t files = dirs->size() * 3;
	for (int32_t i = 0; i < files; ++i) {
		$var($String, name, $str({"file"_s, $$str((i + 1))}));
		int32_t x = $nc(CreateFileTree::rand)->nextInt(dirs->size());
		$Files::createFile($($nc(($cast($Path, $(dirs->get(x)))))->resolve(name)), $$new($FileAttributeArray, 0));
	}
	if (supportsLinks(top)) {
		int32_t links = 1 + $nc(CreateFileTree::rand)->nextInt(5);
		for (int32_t i = 0; i < links; ++i) {
			int32_t x = $nc(CreateFileTree::rand)->nextInt(dirs->size());
			int32_t y = 0;
			do {
				y = $nc(CreateFileTree::rand)->nextInt(dirs->size());
			} while (y != x);
			$var($String, name, $str({"link"_s, $$str((i + 1))}));
			$var($Path, link, $nc(($cast($Path, $(dirs->get(x)))))->resolve(name));
			$var($Path, target, $cast($Path, dirs->get(y)));
			$Files::createSymbolicLink(link, target, $$new($FileAttributeArray, 0));
		}
	}
	return top;
}

void CreateFileTree::main($StringArray* args) {
	$init(CreateFileTree);
	$var($Path, top, create());
	$nc($System::out)->println($of(top));
}

void clinit$CreateFileTree($Class* class$) {
	$assignStatic(CreateFileTree::rand, $new($Random));
}

CreateFileTree::CreateFileTree() {
}

$Class* CreateFileTree::load$($String* name, bool initialize) {
	$loadClass(CreateFileTree, name, initialize, &_CreateFileTree_ClassInfo_, clinit$CreateFileTree, allocate$CreateFileTree);
	return class$;
}

$Class* CreateFileTree::class$ = nullptr;
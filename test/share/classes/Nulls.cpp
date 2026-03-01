#include <Nulls.h>

#include <Nulls$1.h>
#include <Nulls$2.h>
#include <Nulls$3.h>
#include <Nulls$4.h>
#include <Nulls$5.h>
#include <java/io/IOException.h>
#include <java/nio/file/FileVisitOption.h>
#include <java/nio/file/FileVisitResult.h>
#include <java/nio/file/FileVisitor.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/nio/file/SimpleFileVisitor.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/util/EnumSet.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef MAX_VALUE

using $Nulls$1 = ::Nulls$1;
using $Nulls$2 = ::Nulls$2;
using $Nulls$3 = ::Nulls$3;
using $Nulls$4 = ::Nulls$4;
using $Nulls$5 = ::Nulls$5;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $FileVisitOption = ::java::nio::file::FileVisitOption;
using $FileVisitor = ::java::nio::file::FileVisitor;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $SimpleFileVisitor = ::java::nio::file::SimpleFileVisitor;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $EnumSet = ::java::util::EnumSet;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;

$MethodInfo _Nulls_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Nulls, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Nulls, main, void, $StringArray*), "java.io.IOException"},
	{"npeExpected", "()V", nullptr, $STATIC, $staticMethod(Nulls, npeExpected, void)},
	{}
};

$InnerClassInfo _Nulls_InnerClassesInfo_[] = {
	{"Nulls$5", nullptr, nullptr, 0},
	{"Nulls$4", nullptr, nullptr, 0},
	{"Nulls$3", nullptr, nullptr, 0},
	{"Nulls$2", nullptr, nullptr, 0},
	{"Nulls$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Nulls_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Nulls",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Nulls_MethodInfo_,
	nullptr,
	nullptr,
	_Nulls_InnerClassesInfo_,
	nullptr,
	nullptr,
	"Nulls$5,Nulls$4,Nulls$3,Nulls$2,Nulls$1"
};

$Object* allocate$Nulls($Class* clazz) {
	return $of($alloc(Nulls));
}

void Nulls::init$() {
}

void Nulls::npeExpected() {
	$throwNew($RuntimeException, "NullPointerException expected"_s);
}

void Nulls::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	try {
		$load($FileVisitOption);
		$var($Set, var$0, static_cast<$Set*>($EnumSet::noneOf($FileVisitOption::class$)));
		$Files::walkFileTree(nullptr, var$0, $Integer::MAX_VALUE, $$new($Nulls$1));
		npeExpected();
	} catch ($NullPointerException& e) {
	}
	try {
		$var($Path, var$1, $Paths::get("."_s, $$new($StringArray, 0)));
		$Files::walkFileTree(var$1, nullptr, $Integer::MAX_VALUE, $$new($Nulls$2));
		npeExpected();
	} catch ($NullPointerException& e) {
	}
	try {
		$var($Path, var$2, $Paths::get("."_s, $$new($StringArray, 0)));
		$load($FileVisitOption);
		$var($Set, var$3, static_cast<$Set*>($EnumSet::noneOf($FileVisitOption::class$)));
		$Files::walkFileTree(var$2, var$3, -1, $$new($Nulls$3));
		$throwNew($RuntimeException, "IllegalArgumentExpected expected"_s);
	} catch ($IllegalArgumentException& e) {
	}
	try {
		$var($Set, opts, $new($HashSet, 1));
		opts->add(nullptr);
		$var($Path, var$4, $Paths::get("."_s, $$new($StringArray, 0)));
		$var($Set, var$5, opts);
		$Files::walkFileTree(var$4, var$5, $Integer::MAX_VALUE, $$new($Nulls$4));
		npeExpected();
	} catch ($NullPointerException& e) {
	}
	try {
		$var($Path, var$6, $Paths::get("."_s, $$new($StringArray, 0)));
		$load($FileVisitOption);
		$Files::walkFileTree(var$6, $($EnumSet::noneOf($FileVisitOption::class$)), $Integer::MAX_VALUE, nullptr);
		npeExpected();
	} catch ($NullPointerException& e) {
	}
	$var($SimpleFileVisitor, visitor, $new($Nulls$5));
	bool ranTheGauntlet = false;
	$var($Path, dir, $Paths::get("."_s, $$new($StringArray, 0)));
	$load($BasicFileAttributes);
	$var($BasicFileAttributes, attrs, $Files::readAttributes(dir, $BasicFileAttributes::class$, $$new($LinkOptionArray, 0)));
	try {
		visitor->preVisitDirectory(nullptr, attrs);
	} catch ($NullPointerException& x0) {
		try {
			visitor->preVisitDirectory(dir, nullptr);
		} catch ($NullPointerException& x1) {
			try {
				visitor->visitFile(nullptr, attrs);
			} catch ($NullPointerException& x2) {
				try {
					visitor->visitFile(dir, nullptr);
				} catch ($NullPointerException& x3) {
					try {
						visitor->visitFileFailed(nullptr, $$new($IOException));
					} catch ($NullPointerException& x4) {
						try {
							visitor->visitFileFailed(dir, nullptr);
						} catch ($NullPointerException& x5) {
							try {
								visitor->postVisitDirectory(nullptr, $$new($IOException));
							} catch ($NullPointerException& x6) {
								ranTheGauntlet = true;
							}
						}
					}
				}
			}
		}
	}
	if (!ranTheGauntlet) {
		$throwNew($RuntimeException, "A visit method did not throw NPE"_s);
	}
}

Nulls::Nulls() {
}

$Class* Nulls::load$($String* name, bool initialize) {
	$loadClass(Nulls, name, initialize, &_Nulls_ClassInfo_, allocate$Nulls);
	return class$;
}

$Class* Nulls::class$ = nullptr;
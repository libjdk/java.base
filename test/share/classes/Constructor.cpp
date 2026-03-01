#include <Constructor.h>

#include <Constructor$Entry.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URL.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

using $Constructor$Entry = ::Constructor$Entry;
using $Constructor$EntryArray = $Array<Constructor$Entry>;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URL = ::java::net::URL;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$FieldInfo _Constructor_FieldInfo_[] = {
	{"fileURLs", "[LConstructor$Entry;", nullptr, $STATIC, $staticField(Constructor, fileURLs)},
	{"jarURLs", "[LConstructor$Entry;", nullptr, $STATIC, $staticField(Constructor, jarURLs)},
	{"normalHttpURLs", "[LConstructor$Entry;", nullptr, $STATIC, $staticField(Constructor, normalHttpURLs)},
	{"abnormalHttpURLs", "[LConstructor$Entry;", nullptr, $STATIC, $staticField(Constructor, abnormalHttpURLs)},
	{"ftpURLs", "[LConstructor$Entry;", nullptr, $STATIC, $staticField(Constructor, ftpURLs)},
	{}
};

$MethodInfo _Constructor_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Constructor, init$, void)},
	{"hasFtp", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Constructor, hasFtp, bool)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Constructor, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _Constructor_InnerClassesInfo_[] = {
	{"Constructor$Entry", "Constructor", "Entry", $STATIC},
	{}
};

$ClassInfo _Constructor_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Constructor",
	"java.lang.Object",
	nullptr,
	_Constructor_FieldInfo_,
	_Constructor_MethodInfo_,
	nullptr,
	nullptr,
	_Constructor_InnerClassesInfo_,
	nullptr,
	nullptr,
	"Constructor$Entry"
};

$Object* allocate$Constructor($Class* clazz) {
	return $of($alloc(Constructor));
}

$Constructor$EntryArray* Constructor::fileURLs = nullptr;
$Constructor$EntryArray* Constructor::jarURLs = nullptr;
$Constructor$EntryArray* Constructor::normalHttpURLs = nullptr;
$Constructor$EntryArray* Constructor::abnormalHttpURLs = nullptr;
$Constructor$EntryArray* Constructor::ftpURLs = nullptr;

void Constructor::init$() {
}

void Constructor::main($StringArray* args) {
	$init(Constructor);
	$useLocalCurrentObjectStackCache();
	$var($List, entries, $new($ArrayList));
	entries->addAll($($Arrays::asList(Constructor::fileURLs)));
	entries->addAll($($Arrays::asList(Constructor::jarURLs)));
	entries->addAll($($Arrays::asList(Constructor::normalHttpURLs)));
	entries->addAll($($Arrays::asList(Constructor::abnormalHttpURLs)));
	if (hasFtp()) {
		entries->addAll($($Arrays::asList(Constructor::ftpURLs)));
	}
	$var($URL, url, nullptr);
	{
		$var($Iterator, i$, entries->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Constructor$Entry, e, $cast($Constructor$Entry, i$->next()));
			{
				if ($nc(e)->context == nullptr) {
					$assign(url, $new($URL, e->spec));
				} else {
					$assign(url, $new($URL, $$new($URL, e->context), e->spec));
				}
				if (!($nc($($nc(url)->toString()))->equals($nc(e)->expected))) {
					$throwNew($RuntimeException, $$str({"error for: \n\tURL:"_s, $nc(e)->context, "\n\tspec: "_s, e->spec, "\n\texpected: "_s, e->expected, "\n\tactual: "_s, $(url->toString())}));
				} else {
				}
			}
		}
	}
}

bool Constructor::hasFtp() {
	$init(Constructor);
	try {
		return $new($URL, "ftp://"_s) != nullptr;
	} catch ($MalformedURLException& x) {
		$nc($System::out)->println("FTP not supported by this runtime."_s);
		return false;
	}
	$shouldNotReachHere();
}

void clinit$Constructor($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Constructor::fileURLs, $new($Constructor$EntryArray, {
		$$new($Constructor$Entry, nullptr, "file://JavaSoft/Test"_s, "file://JavaSoft/Test"_s),
		$$new($Constructor$Entry, nullptr, "file:///JavaSoft/Test"_s, "file:/JavaSoft/Test"_s),
		$$new($Constructor$Entry, nullptr, "file:/JavaSoft/Test"_s, "file:/JavaSoft/Test"_s),
		$$new($Constructor$Entry, nullptr, "file:/c:/JavaSoft/Test"_s, "file:/c:/JavaSoft/Test"_s),
		$$new($Constructor$Entry, nullptr, "file:/c:/JavaSoft/Test:something"_s, "file:/c:/JavaSoft/Test:something"_s),
		$$new($Constructor$Entry, nullptr, "file:/c:/JavaSoft/Test#anchor"_s, "file:/c:/JavaSoft/Test#anchor"_s),
		$$new($Constructor$Entry, "file://JavaSoft/Test"_s, "Test#bar"_s, "file://JavaSoft/Test#bar"_s),
		$$new($Constructor$Entry, "file://codrus/c:/jdk/eng/index.html"_s, "pulsar.html"_s, "file://codrus/c:/jdk/eng/pulsar.html"_s),
		$$new($Constructor$Entry, "file:///c:/jdk/eng/index.html"_s, "pulsar.html"_s, "file:/c:/jdk/eng/pulsar.html"_s),
		$$new($Constructor$Entry, "file:///jdk/eng/index.html"_s, "pulsar.html"_s, "file:/jdk/eng/pulsar.html"_s),
		$$new($Constructor$Entry, "file://JavaSoft/Test"_s, "file://radartoad.com/Test#bar"_s, "file://radartoad.com/Test#bar"_s),
		$$new($Constructor$Entry, "file://JavaSoft/Test"_s, "/c:/Test#bar"_s, "file://JavaSoft/c:/Test#bar"_s)
	}));
	$assignStatic(Constructor::jarURLs, $new($Constructor$EntryArray, {
		$$new($Constructor$Entry, nullptr, "jar:http://www.foo.com/dir1/jar.jar!/dir2/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/dir2/entry.txt"_s),
		$$new($Constructor$Entry, nullptr, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "jar:http://www.foo.com/dir1/jar.jar!/"_s),
		$$new($Constructor$Entry, nullptr, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "jar:http://www.foo.com/dir1/jar.jar!/"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "dir1/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/dir1/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "/dir1/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/dir1/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/dir1/"_s, "entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/dir1/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/dir2/dir3/entry2.txt"_s, "/dir1/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/dir1/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "/dir1/foo/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/dir1/foo/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/dir1/dir2/dir3/"_s, "dir4/foo/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/dir1/dir2/dir3/dir4/foo/entry.txt"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/"_s, "/dir1/foo/entry.txt"_s, "jar:http://www.foo.com/dir1/jar.jar!/dir1/foo/entry.txt"_s),
		$$new($Constructor$Entry, nullptr, "jar:http://www.foo.com/dir1/jar.jar!/foo.txt#anchor"_s, "jar:http://www.foo.com/dir1/jar.jar!/foo.txt#anchor"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/foo.txt"_s, "#anchor"_s, "jar:http://www.foo.com/dir1/jar.jar!/foo.txt#anchor"_s),
		$$new($Constructor$Entry, "jar:http://www.foo.com/dir1/jar.jar!/foo/bar/"_s, "baz/quux#anchor"_s, "jar:http://www.foo.com/dir1/jar.jar!/foo/bar/baz/quux#anchor"_s),
		$$new($Constructor$Entry, "jar:http://balloo.com/olle.jar!/"_s, "p2"_s, "jar:http://balloo.com/olle.jar!/p2"_s)
	}));
	$assignStatic(Constructor::normalHttpURLs, $new($Constructor$EntryArray, {
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g"_s, "http://a/b/c/g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "./g"_s, "http://a/b/c/g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g/"_s, "http://a/b/c/g/"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "/g"_s, "http://a/g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "//g"_s, "http://g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "?y"_s, "http://a/b/c/?y"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g?y"_s, "http://a/b/c/g?y"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g#s"_s, "http://a/b/c/g#s"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g?y#s"_s, "http://a/b/c/g?y#s"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, ";x"_s, "http://a/b/c/;x"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g;x"_s, "http://a/b/c/g;x"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g;x?y#s"_s, "http://a/b/c/g;x?y#s"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "."_s, "http://a/b/c/"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "./"_s, "http://a/b/c/"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, ".."_s, "http://a/b/"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "../"_s, "http://a/b/"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "../g"_s, "http://a/b/g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "../.."_s, "http://a/"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "../../"_s, "http://a/"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "../../g"_s, "http://a/g"_s),
		$$new($Constructor$Entry, nullptr, "http://www.javasoft.com/jdc/community/chat/index.html#javalive?frontpage-jdc"_s, "http://www.javasoft.com/jdc/community/chat/index.html#javalive?frontpage-jdc"_s)
	}));
	$assignStatic(Constructor::abnormalHttpURLs, $new($Constructor$EntryArray, {
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "../../../g"_s, "http://a/../g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "../../../../g"_s, "http://a/../../g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "/./g"_s, "http://a/./g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "/../g"_s, "http://a/../g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, ".g"_s, "http://a/b/c/.g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g."_s, "http://a/b/c/g."_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "./../g"_s, "http://a/b/g"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "./g/."_s, "http://a/b/c/g/"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g/./h"_s, "http://a/b/c/g/h"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g;x=1/./y"_s, "http://a/b/c/g;x=1/y"_s),
		$$new($Constructor$Entry, "http://a/b/c/d;p?q"_s, "g;x=1/../y"_s, "http://a/b/c/y"_s)
	}));
	$assignStatic(Constructor::ftpURLs, $new($Constructor$EntryArray, {
		$$new($Constructor$Entry, nullptr, "ftp://ftp.foo.com/dir1/entry.txt"_s, "ftp://ftp.foo.com/dir1/entry.txt"_s),
		$$new($Constructor$Entry, nullptr, "ftp://br:pwd@ftp.foo.com/dir1/jar.jar"_s, "ftp://br:pwd@ftp.foo.com/dir1/jar.jar"_s),
		$$new($Constructor$Entry, "ftp://ftp.foo.com/dir1/foo.txt"_s, "bar.txt"_s, "ftp://ftp.foo.com/dir1/bar.txt"_s),
		$$new($Constructor$Entry, "ftp://ftp.foo.com/dir1/jar.jar"_s, "/entry.txt"_s, "ftp://ftp.foo.com/entry.txt"_s),
		$$new($Constructor$Entry, "ftp://ftp.foo.com/dir1/jar.jar"_s, "dir1/entry.txt"_s, "ftp://ftp.foo.com/dir1/dir1/entry.txt"_s),
		$$new($Constructor$Entry, "ftp://ftp.foo.com/dir1/jar.jar"_s, "/dir1/entry.txt"_s, "ftp://ftp.foo.com/dir1/entry.txt"_s),
		$$new($Constructor$Entry, "ftp://br:pwd@ftp.foo.com/dir1/jar.jar"_s, "/dir1/entry.txt"_s, "ftp://br:pwd@ftp.foo.com/dir1/entry.txt"_s)
	}));
}

Constructor::Constructor() {
}

$Class* Constructor::load$($String* name, bool initialize) {
	$loadClass(Constructor, name, initialize, &_Constructor_ClassInfo_, clinit$Constructor, allocate$Constructor);
	return class$;
}

$Class* Constructor::class$ = nullptr;
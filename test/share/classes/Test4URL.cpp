#include <Test4URL.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/StringBuffer.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URL.h>
#include <jcpp.h>

#undef HOST
#undef PARSEFAIL
#undef PATH
#undef PORT
#undef PROTOCOL
#undef QUERY
#undef REF
#undef USERINFO

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URL = ::java::net::URL;

$FieldInfo _Test4URL_FieldInfo_[] = {
	{"out", "Ljava/io/PrintStream;", nullptr, $STATIC, $staticField(Test4URL, out)},
	{"testCount", "I", nullptr, $STATIC, $staticField(Test4URL, testCount)},
	{"PARSEFAIL", "I", nullptr, $STATIC | $FINAL, $constField(Test4URL, PARSEFAIL)},
	{"PROTOCOL", "I", nullptr, $STATIC | $FINAL, $constField(Test4URL, PROTOCOL)},
	{"USERINFO", "I", nullptr, $STATIC | $FINAL, $constField(Test4URL, USERINFO)},
	{"HOST", "I", nullptr, $STATIC | $FINAL, $constField(Test4URL, HOST)},
	{"PORT", "I", nullptr, $STATIC | $FINAL, $constField(Test4URL, PORT)},
	{"PATH", "I", nullptr, $STATIC | $FINAL, $constField(Test4URL, PATH)},
	{"QUERY", "I", nullptr, $STATIC | $FINAL, $constField(Test4URL, QUERY)},
	{"REF", "I", nullptr, $STATIC | $FINAL, $constField(Test4URL, REF)},
	{"input", "Ljava/lang/String;", nullptr, 0, $field(Test4URL, input)},
	{"url", "Ljava/net/URL;", nullptr, 0, $field(Test4URL, url$)},
	{"originalURL", "Ljava/net/URL;", nullptr, 0, $field(Test4URL, originalURL)},
	{"base", "Ljava/net/URL;", nullptr, 0, $field(Test4URL, base)},
	{"op", "Ljava/lang/String;", nullptr, 0, $field(Test4URL, op)},
	{"checked", "I", nullptr, 0, $field(Test4URL, checked)},
	{"failed", "I", nullptr, 0, $field(Test4URL, failed)},
	{"exc", "Ljava/lang/Exception;", nullptr, 0, $field(Test4URL, exc)},
	{}
};

$MethodInfo _Test4URL_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Test4URL, init$, void, $String*)},
	{"<init>", "(Ljava/lang/String;Z)V", nullptr, $PRIVATE, $method(Test4URL, init$, void, $String*, bool)},
	{"<init>", "(Ljava/net/URL;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Test4URL, init$, void, $URL*, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PRIVATE, $method(Test4URL, init$, void, $String*, $String*, int32_t, $String*)},
	{"check1", "(I)Z", nullptr, $PRIVATE, $method(Test4URL, check1, bool, int32_t)},
	{"check2", "(Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(Test4URL, check2, void, $String*, $String*, int32_t)},
	{"checkEmpty", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(Test4URL, checkEmpty, void, $String*, int32_t)},
	{"f", "(Ljava/lang/String;)LTest4URL;", nullptr, 0, $virtualMethod(Test4URL, f, Test4URL*, $String*)},
	{"h", "(Ljava/lang/String;)LTest4URL;", nullptr, 0, $virtualMethod(Test4URL, h, Test4URL*, $String*)},
	{"hasFtp", "()Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Test4URL, hasFtp, bool)},
	{"header", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(Test4URL, header, void, $String*)},
	{"ip", "()V", nullptr, $STATIC, $staticMethod(Test4URL, ip, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Test4URL, main, void, $StringArray*), "java.lang.Exception"},
	{"n", "(I)LTest4URL;", nullptr, 0, $virtualMethod(Test4URL, n, Test4URL*, int32_t)},
	{"p", "(Ljava/lang/String;)LTest4URL;", nullptr, 0, $virtualMethod(Test4URL, p, Test4URL*, $String*)},
	{"parsed", "()Z", nullptr, 0, $virtualMethod(Test4URL, parsed, bool)},
	{"q", "(Ljava/lang/String;)LTest4URL;", nullptr, 0, $virtualMethod(Test4URL, q, Test4URL*, $String*)},
	{"report", "()V", nullptr, $PRIVATE, $method(Test4URL, report, void)},
	{"resolved", "()Z", nullptr, 0, $virtualMethod(Test4URL, resolved, bool)},
	{"rfc2396", "()V", nullptr, $STATIC, $staticMethod(Test4URL, rfc2396, void)},
	{"s", "(Ljava/lang/String;)LTest4URL;", nullptr, 0, $virtualMethod(Test4URL, s, Test4URL*, $String*)},
	{"serial", "()V", nullptr, $STATIC, $staticMethod(Test4URL, serial, void), "java.io.IOException,java.net.MalformedURLException"},
	{"show", "(Ljava/lang/String;Ljava/net/MalformedURLException;)V", nullptr, $STATIC, $staticMethod(Test4URL, show, void, $String*, $MalformedURLException*)},
	{"show", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(Test4URL, show, void, $String*, $String*)},
	{"show", "(Ljava/net/URL;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Test4URL, show, void, $URL*)},
	{"summarize", "()V", nullptr, $PRIVATE, $method(Test4URL, summarize, void)},
	{"test", "(Ljava/lang/String;)LTest4URL;", nullptr, $STATIC, $staticMethod(Test4URL, test, Test4URL*, $String*)},
	{"test", "(Ljava/net/URL;Ljava/lang/String;)LTest4URL;", nullptr, $STATIC, $staticMethod(Test4URL, test, Test4URL*, $URL*, $String*)},
	{"test", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)LTest4URL;", nullptr, $STATIC, $staticMethod(Test4URL, test, Test4URL*, $String*, $String*, int32_t, $String*)},
	{"tests", "()V", nullptr, $STATIC, $staticMethod(Test4URL, tests, void), "java.io.IOException,java.net.MalformedURLException"},
	{"u", "(Ljava/lang/String;)LTest4URL;", nullptr, 0, $virtualMethod(Test4URL, u, Test4URL*, $String*)},
	{"url", "()Ljava/net/URL;", nullptr, 0, $virtualMethod(Test4URL, url, $URL*)},
	{"usage", "()V", nullptr, $STATIC, $staticMethod(Test4URL, usage, void)},
	{"x", "()LTest4URL;", nullptr, 0, $virtualMethod(Test4URL, x, Test4URL*)},
	{"z", "()LTest4URL;", nullptr, 0, $virtualMethod(Test4URL, z, Test4URL*)},
	{}
};

$ClassInfo _Test4URL_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Test4URL",
	"java.lang.Object",
	nullptr,
	_Test4URL_FieldInfo_,
	_Test4URL_MethodInfo_
};

$Object* allocate$Test4URL($Class* clazz) {
	return $of($alloc(Test4URL));
}

$PrintStream* Test4URL::out = nullptr;
int32_t Test4URL::testCount = 0;

void Test4URL::init$($String* s) {
	$set(this, url$, nullptr);
	$set(this, base, nullptr);
	$set(this, op, nullptr);
	this->checked = 0;
	this->failed = 0;
	$set(this, exc, nullptr);
	++Test4URL::testCount;
	$set(this, input, s);
	try {
		$set(this, url$, $new($URL, s));
	} catch ($MalformedURLException& x) {
		$set(this, exc, x);
	}
	$set(this, originalURL, this->url$);
}

Test4URL* Test4URL::test($String* s) {
	$init(Test4URL);
	return $new(Test4URL, s);
}

void Test4URL::init$($String* s, bool xxx) {
	$set(this, url$, nullptr);
	$set(this, base, nullptr);
	$set(this, op, nullptr);
	this->checked = 0;
	this->failed = 0;
	$set(this, exc, nullptr);
	++Test4URL::testCount;
	try {
		$set(this, url$, $new($URL, s));
	} catch ($Exception& x) {
		$set(this, exc, x);
	}
	if (this->url$ != nullptr) {
		$set(this, input, $nc(this->url$)->toString());
	}
	$set(this, originalURL, this->url$);
}

Test4URL* Test4URL::test($URL* base, $String* spec) {
	$init(Test4URL);
	return $new(Test4URL, base, spec);
}

void Test4URL::init$($URL* base, $String* spec) {
	$set(this, url$, nullptr);
	$set(this, base, nullptr);
	$set(this, op, nullptr);
	this->checked = 0;
	this->failed = 0;
	$set(this, exc, nullptr);
	++Test4URL::testCount;
	try {
		$set(this, url$, $new($URL, base, spec));
	} catch ($Exception& x) {
		$set(this, exc, x);
	}
	if (this->url$ != nullptr) {
		$set(this, input, $nc(this->url$)->toString());
	}
	$set(this, originalURL, this->url$);
}

Test4URL* Test4URL::test($String* protocol, $String* host, int32_t port, $String* file) {
	$init(Test4URL);
	return $new(Test4URL, protocol, host, port, file);
}

void Test4URL::init$($String* protocol, $String* host, int32_t port, $String* file) {
	$set(this, url$, nullptr);
	$set(this, base, nullptr);
	$set(this, op, nullptr);
	this->checked = 0;
	this->failed = 0;
	$set(this, exc, nullptr);
	++Test4URL::testCount;
	try {
		$set(this, url$, $new($URL, protocol, host, port, file));
	} catch ($Exception& x) {
		$set(this, exc, x);
	}
	if (this->url$ != nullptr) {
		$set(this, input, $nc(this->url$)->toString());
	}
	$set(this, originalURL, this->url$);
}

bool Test4URL::parsed() {
	return this->url$ != nullptr;
}

bool Test4URL::resolved() {
	return this->base != nullptr;
}

$URL* Test4URL::url() {
	return this->url$;
}

bool Test4URL::check1(int32_t prop) {
	this->checked |= prop;
	if (!parsed()) {
		this->failed |= prop;
		return false;
	}
	return true;
}

void Test4URL::check2($String* s, $String* ans, int32_t prop) {
	if (s == nullptr && ans == nullptr) {
		return;
	}
	if ((s == nullptr) || !$nc(s)->equals(ans)) {
		this->failed |= prop;
	}
}

Test4URL* Test4URL::s($String* s) {
	if (check1(Test4URL::PROTOCOL)) {
		check2($($nc(this->url$)->getProtocol()), s, Test4URL::PROTOCOL);
	}
	return this;
}

Test4URL* Test4URL::u($String* s) {
	if (check1(Test4URL::USERINFO)) {
		check2($($nc(this->url$)->getUserInfo()), s, Test4URL::USERINFO);
	}
	return this;
}

Test4URL* Test4URL::h($String* s) {
	if (check1(Test4URL::HOST)) {
		check2($($nc(this->url$)->getHost()), s, Test4URL::HOST);
	}
	return this;
}

Test4URL* Test4URL::n(int32_t n) {
	this->checked |= Test4URL::PORT;
	bool var$0 = !parsed();
	if (var$0 || ($nc(this->url$)->getPort() != n)) {
		this->failed |= Test4URL::PORT;
	}
	return this;
}

Test4URL* Test4URL::p($String* s) {
	if (check1(Test4URL::PATH)) {
		check2($($nc(this->url$)->getPath()), s, Test4URL::PATH);
	}
	return this;
}

Test4URL* Test4URL::q($String* s) {
	if (check1(Test4URL::QUERY)) {
		check2($($nc(this->url$)->getQuery()), s, Test4URL::QUERY);
	}
	return this;
}

Test4URL* Test4URL::f($String* s) {
	if (check1(Test4URL::REF)) {
		check2($($nc(this->url$)->getRef()), s, Test4URL::REF);
	}
	return this;
}

Test4URL* Test4URL::x() {
	this->checked |= Test4URL::PARSEFAIL;
	if (parsed()) {
		this->failed |= Test4URL::PARSEFAIL;
	}
	return this;
}

void Test4URL::checkEmpty($String* s, int32_t prop) {
	if ((((int32_t)(this->checked & (uint32_t)prop)) == 0) && (s != nullptr)) {
		this->failed |= prop;
	}
}

Test4URL* Test4URL::z() {
	$useLocalCurrentObjectStackCache();
	if (!parsed()) {
		report();
		return this;
	}
	checkEmpty($($nc(this->url$)->getProtocol()), Test4URL::PROTOCOL);
	checkEmpty($($nc(this->url$)->getUserInfo()), Test4URL::USERINFO);
	checkEmpty($($nc(this->url$)->getHost()), Test4URL::HOST);
	if ((((int32_t)(this->checked & (uint32_t)Test4URL::PORT)) == 0) && ($nc(this->url$)->getPort() != -1)) {
		this->failed |= Test4URL::PORT;
	}
	checkEmpty($($nc(this->url$)->getPath()), Test4URL::PATH);
	checkEmpty($($nc(this->url$)->getQuery()), Test4URL::QUERY);
	checkEmpty($($nc(this->url$)->getRef()), Test4URL::REF);
	report();
	return this;
}

void Test4URL::header($String* s) {
	$init(Test4URL);
	$nc(Test4URL::out)->println();
	$nc(Test4URL::out)->println();
	$nc(Test4URL::out)->println($$str({"-- "_s, s, " --"_s}));
}

void Test4URL::show($String* prefix, $MalformedURLException* x) {
	$init(Test4URL);
	$useLocalCurrentObjectStackCache();
	$nc(Test4URL::out)->println($$str({prefix, ": "_s, $($nc(x)->getMessage())}));
}

void Test4URL::summarize() {
	$useLocalCurrentObjectStackCache();
	$nc(Test4URL::out)->println();
	$var($StringBuffer, sb, $new($StringBuffer));
	if ($nc(this->input)->length() == 0) {
		sb->append("\"\""_s);
	} else {
		sb->append(this->input);
	}
	if (this->base != nullptr) {
		sb->append(" "_s);
		sb->append($of(this->base));
	}
	if (!parsed()) {
		$var($String, s, (((int32_t)(this->checked & (uint32_t)Test4URL::PARSEFAIL)) != 0) ? "Correct exception"_s : "UNEXPECTED EXCEPTION"_s);
		if ($instanceOf($MalformedURLException, this->exc)) {
			show(s, $cast($MalformedURLException, this->exc));
		} else {
			$nc(Test4URL::out)->println($(sb->toString()));
			$nc(Test4URL::out)->print($$str({s, ": "_s}));
			$nc(this->exc)->printStackTrace(Test4URL::out);
		}
	} else {
		if (this->url$ != this->originalURL) {
			sb->append(" "_s);
			sb->append(this->op);
			sb->append(" --> "_s);
			sb->append($of(this->url$));
		}
		$nc(Test4URL::out)->println($(sb->toString()));
	}
}

void Test4URL::show($String* n, $String* v) {
	$init(Test4URL);
	$useLocalCurrentObjectStackCache();
	$nc(Test4URL::out)->println($$str({"  "_s, n, $("          = "_s->substring($nc(n)->length())), v}));
}

void Test4URL::show($URL* u) {
	$init(Test4URL);
	$useLocalCurrentObjectStackCache();
	show("scheme"_s, $($nc(u)->getProtocol()));
	show("authority"_s, $($nc(u)->getAuthority()));
	show("userInfo"_s, $($nc(u)->getUserInfo()));
	show("host"_s, $($nc(u)->getHost()));
	show("port"_s, $$str({""_s, $$str($nc(u)->getPort())}));
	show("path"_s, $($nc(u)->getPath()));
	show("query"_s, $($nc(u)->getQuery()));
	show("ref"_s, $($nc(u)->getRef()));
}

void Test4URL::report() {
	$useLocalCurrentObjectStackCache();
	summarize();
	if (this->failed == 0) {
		return;
	}
	$var($StringBuffer, sb, $new($StringBuffer));
	sb->append("FAIL:"_s);
	if (((int32_t)(this->failed & (uint32_t)Test4URL::PARSEFAIL)) != 0) {
		sb->append(" parsefail"_s);
	}
	if (((int32_t)(this->failed & (uint32_t)Test4URL::PROTOCOL)) != 0) {
		sb->append(" scheme"_s);
	}
	if (((int32_t)(this->failed & (uint32_t)Test4URL::USERINFO)) != 0) {
		sb->append(" userinfo"_s);
	}
	if (((int32_t)(this->failed & (uint32_t)Test4URL::HOST)) != 0) {
		sb->append(" host"_s);
	}
	if (((int32_t)(this->failed & (uint32_t)Test4URL::PORT)) != 0) {
		sb->append(" port"_s);
	}
	if (((int32_t)(this->failed & (uint32_t)Test4URL::PATH)) != 0) {
		sb->append(" path"_s);
	}
	if (((int32_t)(this->failed & (uint32_t)Test4URL::QUERY)) != 0) {
		sb->append(" query"_s);
	}
	if (((int32_t)(this->failed & (uint32_t)Test4URL::REF)) != 0) {
		sb->append(" fragment"_s);
	}
	$nc(Test4URL::out)->println($(sb->toString()));
	if (this->url$ != nullptr) {
		show(this->url$);
	}
	$throwNew($RuntimeException, "Test4URL failed"_s);
}

bool Test4URL::hasFtp() {
	$init(Test4URL);
	try {
		return $new($URL, "ftp://"_s) != nullptr;
	} catch ($MalformedURLException& x) {
		$nc($System::out)->println("FTP not supported by this runtime."_s);
		return false;
	}
	$shouldNotReachHere();
}

void Test4URL::rfc2396() {
	$init(Test4URL);
	$useLocalCurrentObjectStackCache();
	header("RFC2396: Basic examples"_s);
	if (hasFtp()) {
		$nc($($nc($($nc($($nc($(test("ftp://ftp.is.co.za/rfc/rfc1808.txt"_s)))->s("ftp"_s)))->h("ftp.is.co.za"_s)))->p("/rfc/rfc1808.txt"_s)))->z();
	}
	$nc($($nc($($nc($($nc($(test("http://www.math.uio.no/faq/compression-faq/part1.html"_s)))->s("http"_s)))->h("www.math.uio.no"_s)))->p("/faq/compression-faq/part1.html"_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://www.w3.org/Addressing/"_s)))->s("http"_s)))->h("www.w3.org"_s)))->p("/Addressing/"_s)))->z();
	if (hasFtp()) {
		$nc($($nc($($nc($($nc($(test("ftp://ds.internic.net/rfc/"_s)))->s("ftp"_s)))->h("ds.internic.net"_s)))->p("/rfc/"_s)))->z();
	}
	$nc($($nc($($nc($($nc($($nc($(test("http://www.ics.uci.edu/pub/ietf/url/historical.html#WARNING"_s)))->s("http"_s)))->h("www.ics.uci.edu"_s)))->p("/pub/ietf/url/historical.html"_s)))->f("WARNING"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test("http://www.ics.uci.edu/pub/ietf/url/#Related"_s)))->s("http"_s)))->h("www.ics.uci.edu"_s)))->p("/pub/ietf/url/"_s)))->f("Related"_s)))->z();
	$nc($($nc($($nc($($nc($(test("file:/home/someone/dir1/dir2/file"_s)))->s("file"_s)))->h(""_s)))->p("/home/someone/dir1/dir2/file"_s)))->z();
	header("RFC2396: Normal relative-URL examples (appendix C)"_s);
	$var($URL, base, $nc($($nc($($nc($($nc($($nc($($nc($(test("http://a/b/c/d;p?q"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/d;p"_s)))->q("q"_s)))->z()))->url());
	$nc($($nc($($nc($($nc($(test(base, "g"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "./g"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "g/"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g/"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "/g"_s)))->s("http"_s)))->h("a"_s)))->p("/g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "//g"_s)))->s("http"_s)))->h("g"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test(base, "?y"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/"_s)))->q("y"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test(base, "g?y"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g"_s)))->q("y"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($($nc($(test(base, "#s"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/d;p"_s)))->q("q"_s)))->f("s"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test(base, "g#s"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g"_s)))->f("s"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($($nc($(test(base, "g?y#s"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g"_s)))->q("y"_s)))->f("s"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, ";x"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/;x"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "g;x"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g;x"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($($nc($(test(base, "g;x?y#s"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g;x"_s)))->q("y"_s)))->f("s"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "."_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "./"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, ".."_s)))->s("http"_s)))->h("a"_s)))->p("/b/"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "../"_s)))->s("http"_s)))->h("a"_s)))->p("/b/"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "../g"_s)))->s("http"_s)))->h("a"_s)))->p("/b/g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "../.."_s)))->s("http"_s)))->h("a"_s)))->p("/"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "../../"_s)))->s("http"_s)))->h("a"_s)))->p("/"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "../../g"_s)))->s("http"_s)))->h("a"_s)))->p("/g"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test($($nc($(test("http://u:p@s1/p1"_s)))->url()), "http://s2/p2"_s)))->s("http"_s)))->h("s2"_s)))->u(nullptr)))->p("/p2"_s)))->z();
	header("RFC2396: Abnormal relative-URL examples (appendix C)"_s);
	$nc($($nc($($nc($($nc($(test(base, "../../../g"_s)))->s("http"_s)))->h("a"_s)))->p("/../g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "../../../../g"_s)))->s("http"_s)))->h("a"_s)))->p("/../../g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "/./g"_s)))->s("http"_s)))->h("a"_s)))->p("/./g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "/../g"_s)))->s("http"_s)))->h("a"_s)))->p("/../g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "g."_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g."_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, ".g"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/.g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "g.."_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g.."_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "..g"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/..g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "./../g"_s)))->s("http"_s)))->h("a"_s)))->p("/b/g"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "./g/."_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g/"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "g/./h"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g/h"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "g/../h"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/h"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "g;x=1/./y"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g;x=1/y"_s)))->z();
	$nc($($nc($($nc($($nc($(test(base, "g;x=1/../y"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/y"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test(base, "g?y/./x"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g"_s)))->q("y/./x"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test(base, "g?y/../x"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g"_s)))->q("y/../x"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test(base, "g#s/./x"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g"_s)))->f("s/./x"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test(base, "g#s/../x"_s)))->s("http"_s)))->h("a"_s)))->p("/b/c/g"_s)))->f("s/../x"_s)))->z();
}

void Test4URL::ip() {
	$init(Test4URL);
	$useLocalCurrentObjectStackCache();
	header("IP addresses"_s);
	$nc($($nc($($nc($($nc($($nc($(test("http://1.2.3.4:5"_s)))->s("http"_s)))->h("1.2.3.4"_s)))->n(5)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test("http://[FEDC:BA98:7654:3210:FEDC:BA98:7654:3210]:80/index.html"_s)))->s("http"_s)))->h("[FEDC:BA98:7654:3210:FEDC:BA98:7654:3210]"_s)))->n(80)))->p("/index.html"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test("http://[FEDC:BA98:7654:3210:FEDC:BA98:7654:3210%12]:80/index.html"_s)))->s("http"_s)))->h("[FEDC:BA98:7654:3210:FEDC:BA98:7654:3210%12]"_s)))->n(80)))->p("/index.html"_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[1080:0:0:0:8:800:200C:417A]/index.html"_s)))->s("http"_s)))->h("[1080:0:0:0:8:800:200C:417A]"_s)))->p("/index.html"_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[1080:0:0:0:8:800:200C:417A%1]/index.html"_s)))->s("http"_s)))->h("[1080:0:0:0:8:800:200C:417A%1]"_s)))->p("/index.html"_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[3ffe:2a00:100:7031::1]"_s)))->s("http"_s)))->h("[3ffe:2a00:100:7031::1]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[1080::8:800:200C:417A]/foo"_s)))->s("http"_s)))->h("[1080::8:800:200C:417A]"_s)))->p("/foo"_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[::192.9.5.5]/ipng"_s)))->s("http"_s)))->h("[::192.9.5.5]"_s)))->p("/ipng"_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[::192.9.5.5%interface]/ipng"_s)))->s("http"_s)))->h("[::192.9.5.5%interface]"_s)))->p("/ipng"_s)))->z();
	$nc($($nc($($nc($($nc($($nc($(test("http://[::FFFF:129.144.52.38]:80/index.html"_s)))->s("http"_s)))->h("[::FFFF:129.144.52.38]"_s)))->n(80)))->p("/index.html"_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[2010:836B:4179::836B:4179]"_s)))->s("http"_s)))->h("[2010:836B:4179::836B:4179]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[FF01::101]"_s)))->s("http"_s)))->h("[FF01::101]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[::1]"_s)))->s("http"_s)))->h("[::1]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[::]"_s)))->s("http"_s)))->h("[::]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[::%hme0]"_s)))->s("http"_s)))->h("[::%hme0]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[0:0:0:0:0:0:13.1.68.3]"_s)))->s("http"_s)))->h("[0:0:0:0:0:0:13.1.68.3]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[0:0:0:0:0:FFFF:129.144.52.38]"_s)))->s("http"_s)))->h("[0:0:0:0:0:FFFF:129.144.52.38]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[0:0:0:0:0:FFFF:129.144.52.38%33]"_s)))->s("http"_s)))->h("[0:0:0:0:0:FFFF:129.144.52.38%33]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[::13.1.68.3]"_s)))->s("http"_s)))->h("[::13.1.68.3]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http://[::13.1.68.3]:"_s)))->s("http"_s)))->h("[::13.1.68.3]"_s)))->p(""_s)))->z();
	$nc($($nc($(test("http://[ff01:234/foo"_s)))->x()))->z();
	$nc($($nc($(test("http://[ff01:234:zzz]/foo"_s)))->x()))->z();
	$nc($($nc($(test("http://[foo]"_s)))->x()))->z();
	$nc($($nc($(test("http://[]"_s)))->x()))->z();
	$nc($($nc($(test("http://[129.33.44.55]"_s)))->x()))->z();
	$nc($($nc($(test("http://[ff:ee:dd::cc:bb::aa:9:8]"_s)))->x()))->z();
	$nc($($nc($(test("http://[1:2:3:4:5:6:7:8%]"_s)))->x()))->z();
	$nc($($nc($(test("http://[1:2:3:4:5:6:7:8%!/]"_s)))->x()))->z();
	$nc($($nc($(test("http://[1:2:3:4:5:6:7:8:9]"_s)))->x()))->z();
	$nc($($nc($(test("http://[::1.2.3.300]"_s)))->x()))->z();
	$nc($($nc($(test("http://[1.2.3.4:5]"_s)))->x()))->z();
	$nc($($nc($($nc($($nc($(test("http"_s, "1:2:3:4:5:6:7:8"_s, -1, ""_s)))->s("http"_s)))->h("[1:2:3:4:5:6:7:8]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http"_s, "1:2:3:4:5:6:7:8%hme0"_s, -1, ""_s)))->s("http"_s)))->h("[1:2:3:4:5:6:7:8%hme0]"_s)))->p(""_s)))->z();
	$nc($($nc($($nc($($nc($(test("http"_s, "[1:2:3:4:5:6:7:8]"_s, -1, ""_s)))->s("http"_s)))->h("[1:2:3:4:5:6:7:8]"_s)))->p(""_s)))->z();
}

void Test4URL::serial() {
	$init(Test4URL);
	$useLocalCurrentObjectStackCache();
	header("Serialization"_s);
	$var($ByteArrayOutputStream, bo, $new($ByteArrayOutputStream));
	$var($ObjectOutputStream, oo, $new($ObjectOutputStream, bo));
	$var($URL, u, $new($URL, "http://java.sun.com/jdk/1.4?release#beta"_s));
	oo->writeObject(u);
	oo->close();
	$var($ByteArrayInputStream, bi, $new($ByteArrayInputStream, $(bo->toByteArray())));
	$var($ObjectInputStream, oi, $new($ObjectInputStream, bi));
	try {
		$var($Object, o, oi->readObject());
		u->equals(o);
	} catch ($ClassNotFoundException& x) {
		x->printStackTrace();
		$throwNew($RuntimeException, $(x->toString()));
	}
}

void Test4URL::tests() {
	$init(Test4URL);
	rfc2396();
	ip();
	serial();
}

void Test4URL::usage() {
	$init(Test4URL);
	$nc(Test4URL::out)->println("Usage:"_s);
	$nc(Test4URL::out)->println("  java Test               --  Runs all tests in this file"_s);
	$nc(Test4URL::out)->println("  java Test <url>         --  Parses url, shows components"_s);
	$nc(Test4URL::out)->println("  java Test <base> <url>  --  Parses url and base, then resolves"_s);
	$nc(Test4URL::out)->println("                              url against base"_s);
}

void Test4URL::main($StringArray* args) {
	$init(Test4URL);
	$useLocalCurrentObjectStackCache();
	switch ($nc(args)->length) {
	case 0:
		{
			tests();
			$nc(Test4URL::out)->println();
			$nc(Test4URL::out)->println($$str({"Test4URL cases: "_s, $$str(Test4URL::testCount)}));
			break;
		}
	case 1:
		{
			if ($nc(args->get(0))->equals("-help"_s)) {
				usage();
				break;
			}
			break;
		}
	case 2:
		{
			break;
		}
	default:
		{
			usage();
			break;
		}
	}
}

void clinit$Test4URL($Class* class$) {
	$assignStatic(Test4URL::out, $System::out);
	Test4URL::testCount = 0;
}

Test4URL::Test4URL() {
}

$Class* Test4URL::load$($String* name, bool initialize) {
	$loadClass(Test4URL, name, initialize, &_Test4URL_ClassInfo_, clinit$Test4URL, allocate$Test4URL);
	return class$;
}

$Class* Test4URL::class$ = nullptr;
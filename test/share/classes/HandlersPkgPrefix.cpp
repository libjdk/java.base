#include <HandlersPkgPrefix.h>

#include <HandlersPkgPrefix$Result.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URL.h>
#include <java/util/function/Consumer.h>
#include <jcpp.h>

#undef KNOWN
#undef UNKNOWN

using $HandlersPkgPrefix$Result = ::HandlersPkgPrefix$Result;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URL = ::java::net::URL;
using $Consumer = ::java::util::function::Consumer;

class HandlersPkgPrefix$$Lambda$lambda$static$0 : public $Consumer {
	$class(HandlersPkgPrefix$$Lambda$lambda$static$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* r) override {
		HandlersPkgPrefix::lambda$static$0($cast($HandlersPkgPrefix$Result, r));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HandlersPkgPrefix$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HandlersPkgPrefix$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HandlersPkgPrefix$$Lambda$lambda$static$0, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(HandlersPkgPrefix$$Lambda$lambda$static$0, accept, void, Object$*)},
	{}
};
$ClassInfo HandlersPkgPrefix$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"HandlersPkgPrefix$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* HandlersPkgPrefix$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(HandlersPkgPrefix$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HandlersPkgPrefix$$Lambda$lambda$static$0::class$ = nullptr;

class HandlersPkgPrefix$$Lambda$lambda$static$1$1 : public $Consumer {
	$class(HandlersPkgPrefix$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* r) override {
		HandlersPkgPrefix::lambda$static$1($cast($HandlersPkgPrefix$Result, r));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HandlersPkgPrefix$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HandlersPkgPrefix$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HandlersPkgPrefix$$Lambda$lambda$static$1$1, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(HandlersPkgPrefix$$Lambda$lambda$static$1$1, accept, void, Object$*)},
	{}
};
$ClassInfo HandlersPkgPrefix$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"HandlersPkgPrefix$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* HandlersPkgPrefix$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(HandlersPkgPrefix$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HandlersPkgPrefix$$Lambda$lambda$static$1$1::class$ = nullptr;

$FieldInfo _HandlersPkgPrefix_FieldInfo_[] = {
	{"KNOWN", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<LHandlersPkgPrefix$Result;>;", $STATIC | $FINAL, $staticField(HandlersPkgPrefix, KNOWN)},
	{"UNKNOWN", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<LHandlersPkgPrefix$Result;>;", $STATIC | $FINAL, $staticField(HandlersPkgPrefix, UNKNOWN)},
	{}
};

$MethodInfo _HandlersPkgPrefix_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(HandlersPkgPrefix, init$, void)},
	{"lambda$static$0", "(LHandlersPkgPrefix$Result;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HandlersPkgPrefix, lambda$static$0, void, $HandlersPkgPrefix$Result*)},
	{"lambda$static$1", "(LHandlersPkgPrefix$Result;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(HandlersPkgPrefix, lambda$static$1, void, $HandlersPkgPrefix$Result*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(HandlersPkgPrefix, main, void, $StringArray*)},
	{"withPrefix", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Consumer;)V", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Consumer<LHandlersPkgPrefix$Result;>;)V", $STATIC, $staticMethod(HandlersPkgPrefix, withPrefix, void, $String*, $String*, $Consumer*)},
	{}
};

$InnerClassInfo _HandlersPkgPrefix_InnerClassesInfo_[] = {
	{"HandlersPkgPrefix$Result", "HandlersPkgPrefix", "Result", $STATIC},
	{}
};

$ClassInfo _HandlersPkgPrefix_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"HandlersPkgPrefix",
	"java.lang.Object",
	nullptr,
	_HandlersPkgPrefix_FieldInfo_,
	_HandlersPkgPrefix_MethodInfo_,
	nullptr,
	nullptr,
	_HandlersPkgPrefix_InnerClassesInfo_,
	nullptr,
	nullptr,
	"HandlersPkgPrefix$Result"
};

$Object* allocate$HandlersPkgPrefix($Class* clazz) {
	return $of($alloc(HandlersPkgPrefix));
}

$Consumer* HandlersPkgPrefix::KNOWN = nullptr;
$Consumer* HandlersPkgPrefix::UNKNOWN = nullptr;

void HandlersPkgPrefix::init$() {
}

void HandlersPkgPrefix::main($StringArray* args) {
	$init(HandlersPkgPrefix);
	withPrefix("unknown"_s, ""_s, HandlersPkgPrefix::UNKNOWN);
	withPrefix("unknown"_s, "handlers"_s, HandlersPkgPrefix::UNKNOWN);
	withPrefix("foo"_s, ""_s, HandlersPkgPrefix::UNKNOWN);
	withPrefix("foo"_s, "xxx|yyy|zzz"_s, HandlersPkgPrefix::UNKNOWN);
	withPrefix("foo"_s, "||||"_s, HandlersPkgPrefix::UNKNOWN);
	withPrefix("foo"_s, "|a|b|c|handlers"_s, HandlersPkgPrefix::KNOWN);
	withPrefix("bar"_s, ""_s, HandlersPkgPrefix::UNKNOWN);
	withPrefix("bar"_s, "x.y.z|y.y.y|z.z.z"_s, HandlersPkgPrefix::UNKNOWN);
	withPrefix("bar"_s, " x.y.z | y.y.y | z.z.z| |  "_s, HandlersPkgPrefix::UNKNOWN);
	withPrefix("bar"_s, "| a | b | c | handlers | d | e"_s, HandlersPkgPrefix::KNOWN);
}

void HandlersPkgPrefix::withPrefix($String* protocol, $String* pkgPrefix, $Consumer* resultChecker) {
	$init(HandlersPkgPrefix);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({"Testing, "_s, protocol, ", "_s, pkgPrefix}));
	$System::setProperty("java.protocol.handler.pkgs"_s, pkgPrefix);
	$var($URL, url, nullptr);
	$var($Exception, exception, nullptr);
	try {
		$assign(url, $new($URL, $$str({protocol, "://"_s})));
	} catch ($MalformedURLException& x) {
		$assign(exception, x);
	}
	$nc(resultChecker)->accept($$new($HandlersPkgPrefix$Result, protocol, url, exception));
}

void HandlersPkgPrefix::lambda$static$1($HandlersPkgPrefix$Result* r) {
	$init(HandlersPkgPrefix);
	$useLocalCurrentObjectStackCache();
	if ($nc(r)->url != nullptr) {
		$throwNew($RuntimeException, $$str({"Unexpected url:"_s, r->url}));
	}
	if (!($instanceOf($MalformedURLException, $nc(r)->exception))) {
		$throwNew($RuntimeException, $$str({"Expected MalformedURLException, got:"_s, r->exception}));
	}
}

void HandlersPkgPrefix::lambda$static$0($HandlersPkgPrefix$Result* r) {
	$init(HandlersPkgPrefix);
	$useLocalCurrentObjectStackCache();
	if ($nc(r)->exception != nullptr) {
		$throwNew($RuntimeException, $$str({"Unexpected exception "_s, r->exception}));
	}
	$var($String, p, $nc($nc(r)->url)->getProtocol());
	if (!$nc(r->protocol)->equals(p)) {
		$throwNew($RuntimeException, $$str({"Expected:"_s, r->protocol, ", got:"_s, p}));
	}
}

void clinit$HandlersPkgPrefix($Class* class$) {
	$assignStatic(HandlersPkgPrefix::KNOWN, static_cast<$Consumer*>($new(HandlersPkgPrefix$$Lambda$lambda$static$0)));
	$assignStatic(HandlersPkgPrefix::UNKNOWN, static_cast<$Consumer*>($new(HandlersPkgPrefix$$Lambda$lambda$static$1$1)));
}

HandlersPkgPrefix::HandlersPkgPrefix() {
}

$Class* HandlersPkgPrefix::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HandlersPkgPrefix$$Lambda$lambda$static$0::classInfo$.name)) {
			return HandlersPkgPrefix$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(HandlersPkgPrefix$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return HandlersPkgPrefix$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
	}
	$loadClass(HandlersPkgPrefix, name, initialize, &_HandlersPkgPrefix_ClassInfo_, clinit$HandlersPkgPrefix, allocate$HandlersPkgPrefix);
	return class$;
}

$Class* HandlersPkgPrefix::class$ = nullptr;
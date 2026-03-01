#include <java/net/URLPermission.h>

#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Iterable.h>
#include <java/net/URLPermission$Authority.h>
#include <java/security/Permission.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <jcpp.h>

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $URLPermission$Authority = ::java::net::URLPermission$Authority;
using $Permission = ::java::security::Permission;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;

namespace java {
	namespace net {

$FieldInfo _URLPermission_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(URLPermission, serialVersionUID)},
	{"scheme", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(URLPermission, scheme)},
	{"ssp", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(URLPermission, ssp)},
	{"path", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(URLPermission, path)},
	{"methods", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $TRANSIENT, $field(URLPermission, methods)},
	{"requestHeaders", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $TRANSIENT, $field(URLPermission, requestHeaders)},
	{"authority", "Ljava/net/URLPermission$Authority;", nullptr, $PRIVATE | $TRANSIENT, $field(URLPermission, authority)},
	{"actions", "Ljava/lang/String;", nullptr, $PRIVATE, $field(URLPermission, actions$)},
	{}
};

$MethodInfo _URLPermission_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(URLPermission, init$, void, $String*, $String*)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(URLPermission, init$, void, $String*)},
	{"actions", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(URLPermission, actions, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(URLPermission, equals, bool, Object$*)},
	{"getActions", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(URLPermission, getActions, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(URLPermission, hashCode, int32_t)},
	{"implies", "(Ljava/security/Permission;)Z", nullptr, $PUBLIC, $virtualMethod(URLPermission, implies, bool, $Permission*)},
	{"init", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(URLPermission, init, void, $String*)},
	{"normalize", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(URLPermission, normalize, $String*, $String*)},
	{"normalizeHeaders", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $method(URLPermission, normalizeHeaders, $List*, $String*)},
	{"normalizeMethods", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $method(URLPermission, normalizeMethods, $List*, $String*)},
	{"parseURI", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(URLPermission, parseURI, void, $String*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(URLPermission, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{}
};

$InnerClassInfo _URLPermission_InnerClassesInfo_[] = {
	{"java.net.URLPermission$Authority", "java.net.URLPermission", "Authority", $STATIC},
	{}
};

$ClassInfo _URLPermission_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.net.URLPermission",
	"java.security.Permission",
	nullptr,
	_URLPermission_FieldInfo_,
	_URLPermission_MethodInfo_,
	nullptr,
	nullptr,
	_URLPermission_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.URLPermission$Authority"
};

$Object* allocate$URLPermission($Class* clazz) {
	return $of($alloc(URLPermission));
}

void URLPermission::init$($String* url, $String* actions) {
	$Permission::init$($(normalize(url)));
	init(actions);
}

$String* URLPermission::normalize($String* url$renamed) {
	$init(URLPermission);
	$var($String, url, url$renamed);
	int32_t index = $nc(url)->indexOf((int32_t)u'?');
	if (index >= 0) {
		$assign(url, url->substring(0, index));
	} else {
		index = url->indexOf((int32_t)u'#');
		if (index >= 0) {
			$assign(url, url->substring(0, index));
		}
	}
	return url;
}

void URLPermission::init($String* actions) {
	$useLocalCurrentObjectStackCache();
	parseURI($(getName()));
	int32_t colon = $nc(actions)->indexOf((int32_t)u':');
	if (actions->lastIndexOf((int32_t)u':') != colon) {
		$throwNew($IllegalArgumentException, $$str({"Invalid actions string: \""_s, actions, "\""_s}));
	}
	$var($String, methods, nullptr);
	$var($String, headers, nullptr);
	if (colon == -1) {
		$assign(methods, actions);
		$assign(headers, ""_s);
	} else {
		$assign(methods, actions->substring(0, colon));
		$assign(headers, actions->substring(colon + 1));
	}
	$var($List, l, normalizeMethods(methods));
	$Collections::sort(l);
	$set(this, methods, $Collections::unmodifiableList(l));
	$assign(l, normalizeHeaders(headers));
	$Collections::sort(l);
	$set(this, requestHeaders, $Collections::unmodifiableList(l));
	$set(this, actions$, this->actions());
}

void URLPermission::init$($String* url) {
	URLPermission::init$(url, "*:*"_s);
}

$String* URLPermission::getActions() {
	return this->actions$;
}

bool URLPermission::implies($Permission* p) {
	$useLocalCurrentObjectStackCache();
	$var(URLPermission, that, nullptr);
	bool var$0 = $instanceOf(URLPermission, p);
	if (var$0) {
		$assign(that, $cast(URLPermission, p));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	bool var$1 = $nc(this->methods)->isEmpty();
	if (var$1 && !$nc($nc(that)->methods)->isEmpty()) {
		return false;
	}
	bool var$3 = !$nc(this->methods)->isEmpty();
	bool var$2 = var$3 && !$nc(($cast($String, $($nc(this->methods)->get(0)))))->equals("*"_s);
	if (var$2 && $Collections::indexOfSubList(this->methods, $nc(that)->methods) == -1) {
		return false;
	}
	bool var$4 = $nc(this->requestHeaders)->isEmpty();
	if (var$4 && !$nc($nc(that)->requestHeaders)->isEmpty()) {
		return false;
	}
	bool var$6 = !$nc(this->requestHeaders)->isEmpty();
	bool var$5 = var$6 && !$nc(($cast($String, $($nc(this->requestHeaders)->get(0)))))->equals("*"_s);
	if (var$5 && $Collections::indexOfSubList(this->requestHeaders, $nc(that)->requestHeaders) == -1) {
		return false;
	}
	if (!$nc(this->scheme)->equals($nc(that)->scheme)) {
		return false;
	}
	if ($nc(this->ssp)->equals("*"_s)) {
		return true;
	}
	if (!$nc(this->authority)->implies($nc(that)->authority)) {
		return false;
	}
	if (this->path == nullptr) {
		return $nc(that)->path == nullptr;
	}
	if ($nc(that)->path == nullptr) {
		return false;
	}
	if ($nc(this->path)->endsWith("/-"_s)) {
		$var($String, thisprefix, $nc(this->path)->substring(0, $nc(this->path)->length() - 1));
		return $nc($nc(that)->path)->startsWith(thisprefix);
	}
	if ($nc(this->path)->endsWith("/*"_s)) {
		$var($String, thisprefix, $nc(this->path)->substring(0, $nc(this->path)->length() - 1));
		if (!$nc($nc(that)->path)->startsWith(thisprefix)) {
			return false;
		}
		$var($String, thatsuffix, $nc($nc(that)->path)->substring(thisprefix->length()));
		if (thatsuffix->indexOf((int32_t)u'/') != -1) {
			return false;
		}
		if (thatsuffix->equals("-"_s)) {
			return false;
		}
		return true;
	}
	return $nc(this->path)->equals($nc(that)->path);
}

bool URLPermission::equals(Object$* p) {
	$useLocalCurrentObjectStackCache();
	$var(URLPermission, that, nullptr);
	bool var$0 = $instanceOf(URLPermission, p);
	if (var$0) {
		$assign(that, $cast(URLPermission, p));
		var$0 = true;
	}
	if (!(var$0)) {
		return false;
	}
	if (!$nc(this->scheme)->equals($nc(that)->scheme)) {
		return false;
	}
	if (!$nc($(this->getActions()))->equals($($nc(that)->getActions()))) {
		return false;
	}
	if (!$nc(this->authority)->equals($nc(that)->authority)) {
		return false;
	}
	if (this->path != nullptr) {
		return $nc(this->path)->equals($nc(that)->path);
	} else {
		return $nc(that)->path == nullptr;
	}
}

int32_t URLPermission::hashCode() {
	int32_t var$2 = $nc($(getActions()))->hashCode();
	int32_t var$1 = var$2 + $nc(this->scheme)->hashCode();
	int32_t var$0 = var$1 + $nc(this->authority)->hashCode();
	return var$0 + (this->path == nullptr ? 0 : $nc(this->path)->hashCode());
}

$List* URLPermission::normalizeMethods($String* methods) {
	$useLocalCurrentObjectStackCache();
	$var($List, l, $new($ArrayList));
	$var($StringBuilder, b, $new($StringBuilder));
	for (int32_t i = 0; i < $nc(methods)->length(); ++i) {
		char16_t c = methods->charAt(i);
		if (c == u',') {
			$var($String, s, b->toString());
			if (!$nc(s)->isEmpty()) {
				l->add(s);
			}
			$assign(b, $new($StringBuilder));
		} else if (c == u' ' || c == u'\t') {
			$throwNew($IllegalArgumentException, $$str({"White space not allowed in methods: \""_s, methods, "\""_s}));
		} else {
			if (c >= u'a' && c <= u'z') {
				c += u'A' - u'a';
			}
			b->append(c);
		}
	}
	$var($String, s, b->toString());
	if (!$nc(s)->isEmpty()) {
		l->add(s);
	}
	return l;
}

$List* URLPermission::normalizeHeaders($String* headers) {
	$useLocalCurrentObjectStackCache();
	$var($List, l, $new($ArrayList));
	$var($StringBuilder, b, $new($StringBuilder));
	bool capitalizeNext = true;
	for (int32_t i = 0; i < $nc(headers)->length(); ++i) {
		char16_t c = headers->charAt(i);
		if (c >= u'a' && c <= u'z') {
			if (capitalizeNext) {
				c += u'A' - u'a';
				capitalizeNext = false;
			}
			b->append(c);
		} else if (c == u' ' || c == u'\t') {
			$throwNew($IllegalArgumentException, $$str({"White space not allowed in headers: \""_s, headers, "\""_s}));
		} else if (c == u'-') {
			capitalizeNext = true;
			b->append(c);
		} else if (c == u',') {
			$var($String, s, b->toString());
			if (!$nc(s)->isEmpty()) {
				l->add(s);
			}
			$assign(b, $new($StringBuilder));
			capitalizeNext = true;
		} else {
			capitalizeNext = false;
			b->append(c);
		}
	}
	$var($String, s, b->toString());
	if (!$nc(s)->isEmpty()) {
		l->add(s);
	}
	return l;
}

void URLPermission::parseURI($String* url) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(url)->length();
	int32_t delim = url->indexOf((int32_t)u':');
	if (delim == -1 || delim + 1 == len) {
		$throwNew($IllegalArgumentException, $$str({"Invalid URL string: \""_s, url, "\""_s}));
	}
	$set(this, scheme, $(url->substring(0, delim))->toLowerCase());
	$set(this, ssp, url->substring(delim + 1));
	if (!$nc(this->ssp)->startsWith("//"_s)) {
		if (!$nc(this->ssp)->equals("*"_s)) {
			$throwNew($IllegalArgumentException, $$str({"Invalid URL string: \""_s, url, "\""_s}));
		}
		$set(this, authority, $new($URLPermission$Authority, this->scheme, "*"_s));
		return;
	}
	$var($String, authpath, $nc(this->ssp)->substring(2));
	delim = authpath->indexOf((int32_t)u'/');
	$var($String, auth, nullptr);
	if (delim == -1) {
		$set(this, path, ""_s);
		$assign(auth, authpath);
	} else {
		$assign(auth, authpath->substring(0, delim));
		$set(this, path, authpath->substring(delim));
	}
	$set(this, authority, $new($URLPermission$Authority, this->scheme, $($nc(auth)->toLowerCase())));
}

$String* URLPermission::actions() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({$($String::join(static_cast<$CharSequence*>(","_s), static_cast<$Iterable*>(this->methods))), ":"_s}));
	return $concat(var$0, $($String::join(static_cast<$CharSequence*>(","_s), static_cast<$Iterable*>(this->requestHeaders))));
}

void URLPermission::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
	$var($String, actions, $cast($String, $nc(fields)->get("actions"_s, ($Object*)nullptr)));
	init(actions);
}

URLPermission::URLPermission() {
}

$Class* URLPermission::load$($String* name, bool initialize) {
	$loadClass(URLPermission, name, initialize, &_URLPermission_ClassInfo_, allocate$URLPermission);
	return class$;
}

$Class* URLPermission::class$ = nullptr;

	} // net
} // java
#include <java/lang/module/ModuleDescriptor$Version.h>

#include <java/lang/Comparable.h>
#include <java/lang/Math.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Comparable = ::java::lang::Comparable;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

namespace java {
	namespace lang {
		namespace module {

$FieldInfo _ModuleDescriptor$Version_FieldInfo_[] = {
	{"version", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ModuleDescriptor$Version, version)},
	{"sequence", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor$Version, sequence)},
	{"pre", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor$Version, pre)},
	{"build", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Object;>;", $PRIVATE | $FINAL, $field(ModuleDescriptor$Version, build)},
	{}
};

$MethodInfo _ModuleDescriptor$Version_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(ModuleDescriptor$Version, init$, void, $String*)},
	{"cmp", "(Ljava/lang/Object;Ljava/lang/Object;)I", nullptr, $PRIVATE, $method(ModuleDescriptor$Version, cmp, int32_t, Object$*, Object$*)},
	{"compareTo", "(Ljava/lang/module/ModuleDescriptor$Version;)I", nullptr, $PUBLIC, $method(ModuleDescriptor$Version, compareTo, int32_t, ModuleDescriptor$Version*)},
	{"compareTo", "(Ljava/lang/Object;)I", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC, $virtualMethod(ModuleDescriptor$Version, compareTo, int32_t, Object$*)},
	{"compareTokens", "(Ljava/util/List;Ljava/util/List;)I", "(Ljava/util/List<Ljava/lang/Object;>;Ljava/util/List<Ljava/lang/Object;>;)I", $PRIVATE, $method(ModuleDescriptor$Version, compareTokens, int32_t, $List*, $List*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor$Version, equals, bool, Object$*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor$Version, hashCode, int32_t)},
	{"parse", "(Ljava/lang/String;)Ljava/lang/module/ModuleDescriptor$Version;", nullptr, $PUBLIC | $STATIC, $staticMethod(ModuleDescriptor$Version, parse, ModuleDescriptor$Version*, $String*)},
	{"takeNumber", "(Ljava/lang/String;ILjava/util/List;)I", "(Ljava/lang/String;ILjava/util/List<Ljava/lang/Object;>;)I", $PRIVATE | $STATIC, $staticMethod(ModuleDescriptor$Version, takeNumber, int32_t, $String*, int32_t, $List*)},
	{"takeString", "(Ljava/lang/String;ILjava/util/List;)I", "(Ljava/lang/String;ILjava/util/List<Ljava/lang/Object;>;)I", $PRIVATE | $STATIC, $staticMethod(ModuleDescriptor$Version, takeString, int32_t, $String*, int32_t, $List*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ModuleDescriptor$Version, toString, $String*)},
	{}
};

$InnerClassInfo _ModuleDescriptor$Version_InnerClassesInfo_[] = {
	{"java.lang.module.ModuleDescriptor$Version", "java.lang.module.ModuleDescriptor", "Version", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _ModuleDescriptor$Version_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.module.ModuleDescriptor$Version",
	"java.lang.Object",
	"java.lang.Comparable",
	_ModuleDescriptor$Version_FieldInfo_,
	_ModuleDescriptor$Version_MethodInfo_,
	"Ljava/lang/Object;Ljava/lang/Comparable<Ljava/lang/module/ModuleDescriptor$Version;>;",
	nullptr,
	_ModuleDescriptor$Version_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.module.ModuleDescriptor"
};

$Object* allocate$ModuleDescriptor$Version($Class* clazz) {
	return $of($alloc(ModuleDescriptor$Version));
}

int32_t ModuleDescriptor$Version::takeNumber($String* s, int32_t i, $List* acc) {
	$init(ModuleDescriptor$Version);
	char16_t c = $nc(s)->charAt(i);
	int32_t d = (c - u'0');
	int32_t n = s->length();
	while (++i < n) {
		c = s->charAt(i);
		if (c >= u'0' && c <= u'9') {
			d = d * 10 + (c - u'0');
			continue;
		}
		break;
	}
	$nc(acc)->add($($Integer::valueOf(d)));
	return i;
}

int32_t ModuleDescriptor$Version::takeString($String* s, int32_t i, $List* acc) {
	$init(ModuleDescriptor$Version);
	int32_t b = i;
	int32_t n = $nc(s)->length();
	while (++i < n) {
		char16_t c = s->charAt(i);
		if (c != u'.' && c != u'-' && c != u'+' && !(c >= u'0' && c <= u'9')) {
			continue;
		}
		break;
	}
	$nc(acc)->add($(s->substring(b, i)));
	return i;
}

void ModuleDescriptor$Version::init$($String* v) {
	$useLocalCurrentObjectStackCache();
	if (v == nullptr) {
		$throwNew($IllegalArgumentException, "Null version string"_s);
	}
	int32_t n = $nc(v)->length();
	if (n == 0) {
		$throwNew($IllegalArgumentException, "Empty version string"_s);
	}
	int32_t i = 0;
	char16_t c = v->charAt(i);
	if (!(c >= u'0' && c <= u'9')) {
		$throwNew($IllegalArgumentException, $$str({v, ": Version string does not start with a number"_s}));
	}
	$var($List, sequence, $new($ArrayList, 4));
	$var($List, pre, $new($ArrayList, 2));
	$var($List, build, $new($ArrayList, 2));
	i = takeNumber(v, i, sequence);
	while (i < n) {
		c = v->charAt(i);
		if (c == u'.') {
			++i;
			continue;
		}
		if (c == u'-' || c == u'+') {
			++i;
			break;
		}
		if (c >= u'0' && c <= u'9') {
			i = takeNumber(v, i, sequence);
		} else {
			i = takeString(v, i, sequence);
		}
	}
	if (c == u'-' && i >= n) {
		$throwNew($IllegalArgumentException, $$str({v, ": Empty pre-release"_s}));
	}
	while (i < n) {
		c = v->charAt(i);
		if (c >= u'0' && c <= u'9') {
			i = takeNumber(v, i, pre);
		} else {
			i = takeString(v, i, pre);
		}
		if (i >= n) {
			break;
		}
		c = v->charAt(i);
		if (c == u'.' || c == u'-') {
			++i;
			continue;
		}
		if (c == u'+') {
			++i;
			break;
		}
	}
	if (c == u'+' && i >= n) {
		$throwNew($IllegalArgumentException, $$str({v, ": Empty pre-release"_s}));
	}
	while (i < n) {
		c = v->charAt(i);
		if (c >= u'0' && c <= u'9') {
			i = takeNumber(v, i, build);
		} else {
			i = takeString(v, i, build);
		}
		if (i >= n) {
			break;
		}
		c = v->charAt(i);
		if (c == u'.' || c == u'-' || c == u'+') {
			++i;
			continue;
		}
	}
	$set(this, version, v);
	$set(this, sequence, sequence);
	$set(this, pre, pre);
	$set(this, build, build);
}

ModuleDescriptor$Version* ModuleDescriptor$Version::parse($String* v) {
	$init(ModuleDescriptor$Version);
	return $new(ModuleDescriptor$Version, v);
}

int32_t ModuleDescriptor$Version::cmp(Object$* o1, Object$* o2) {
	return $nc(($cast($Comparable, o1)))->compareTo(o2);
}

int32_t ModuleDescriptor$Version::compareTokens($List* ts1, $List* ts2) {
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc(ts1)->size();
	int32_t n = $Math::min(var$0, $nc(ts2)->size());
	for (int32_t i = 0; i < n; ++i) {
		$var($Object, o1, $nc(ts1)->get(i));
		$var($Object, o2, $nc(ts2)->get(i));
		if (($instanceOf($Integer, o1) && $instanceOf($Integer, o2)) || ($instanceOf($String, o1) && $instanceOf($String, o2))) {
			int32_t c = cmp(o1, o2);
			if (c == 0) {
				continue;
			}
			return c;
		}
		int32_t c = $nc($($nc($of(o1))->toString()))->compareTo($($nc($of(o2))->toString()));
		if (c == 0) {
			continue;
		}
		return c;
	}
	int32_t var$1 = $nc(ts1)->size();
	$var($List, rest, var$1 > $nc(ts2)->size() ? ts1 : ts2);
	int32_t e = $nc(rest)->size();
	for (int32_t i = n; i < e; ++i) {
		$var($Object, o, rest->get(i));
		if ($instanceOf($Integer, o) && $nc(($cast($Integer, o)))->intValue() == 0) {
			continue;
		}
		int32_t var$2 = $nc(ts1)->size();
		return var$2 - $nc(ts2)->size();
	}
	return 0;
}

int32_t ModuleDescriptor$Version::compareTo(ModuleDescriptor$Version* that) {
	int32_t c = compareTokens(this->sequence, $nc(that)->sequence);
	if (c != 0) {
		return c;
	}
	if ($nc(this->pre)->isEmpty()) {
		if (!$nc($nc(that)->pre)->isEmpty()) {
			return +1;
		}
	} else if ($nc($nc(that)->pre)->isEmpty()) {
		return -1;
	}
	c = compareTokens(this->pre, $nc(that)->pre);
	if (c != 0) {
		return c;
	}
	return compareTokens(this->build, $nc(that)->build);
}

bool ModuleDescriptor$Version::equals(Object$* ob) {
	if (!($instanceOf(ModuleDescriptor$Version, ob))) {
		return false;
	}
	return compareTo($cast(ModuleDescriptor$Version, ob)) == 0;
}

int32_t ModuleDescriptor$Version::hashCode() {
	return $nc(this->version)->hashCode();
}

$String* ModuleDescriptor$Version::toString() {
	return this->version;
}

int32_t ModuleDescriptor$Version::compareTo(Object$* that) {
	return this->compareTo($cast(ModuleDescriptor$Version, that));
}

ModuleDescriptor$Version::ModuleDescriptor$Version() {
}

$Class* ModuleDescriptor$Version::load$($String* name, bool initialize) {
	$loadClass(ModuleDescriptor$Version, name, initialize, &_ModuleDescriptor$Version_ClassInfo_, allocate$ModuleDescriptor$Version);
	return class$;
}

$Class* ModuleDescriptor$Version::class$ = nullptr;

		} // module
	} // lang
} // java
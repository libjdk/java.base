#include <sun/invoke/util/BytecodeDescriptor.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/TypeNotPresentException.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/reflect/Array.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/invoke/util/Wrapper.h>
#include <jcpp.h>

#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $TypeNotPresentException = ::java::lang::TypeNotPresentException;
using $Void = ::java::lang::Void;
using $MethodType = ::java::lang::invoke::MethodType;
using $1Array = ::java::lang::reflect::Array;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Wrapper = ::sun::invoke::util::Wrapper;

namespace sun {
	namespace invoke {
		namespace util {

$MethodInfo _BytecodeDescriptor_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(BytecodeDescriptor, init$, void)},
	{"parseError", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(BytecodeDescriptor, parseError, void, $String*, $String*)},
	{"parseMethod", "(Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/util/List;", "(Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/util/List<Ljava/lang/Class<*>;>;", $PUBLIC | $STATIC, $staticMethod(BytecodeDescriptor, parseMethod, $List*, $String*, $ClassLoader*)},
	{"parseMethod", "(Ljava/lang/String;IILjava/lang/ClassLoader;)Ljava/util/List;", "(Ljava/lang/String;IILjava/lang/ClassLoader;)Ljava/util/List<Ljava/lang/Class<*>;>;", $STATIC, $staticMethod(BytecodeDescriptor, parseMethod, $List*, $String*, int32_t, int32_t, $ClassLoader*)},
	{"parseSig", "(Ljava/lang/String;[IILjava/lang/ClassLoader;)Ljava/lang/Class;", "(Ljava/lang/String;[IILjava/lang/ClassLoader;)Ljava/lang/Class<*>;", $PRIVATE | $STATIC, $staticMethod(BytecodeDescriptor, parseSig, $Class*, $String*, $ints*, int32_t, $ClassLoader*)},
	{"unparse", "(Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;)Ljava/lang/String;", $PUBLIC | $STATIC, $staticMethod(BytecodeDescriptor, unparse, $String*, $Class*)},
	{"unparse", "(Ljava/lang/invoke/MethodType;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(BytecodeDescriptor, unparse, $String*, $MethodType*)},
	{"unparse", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(BytecodeDescriptor, unparse, $String*, Object$*)},
	{"unparseMethod", "(Ljava/lang/Class;Ljava/util/List;)Ljava/lang/String;", "(Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/lang/String;", $PUBLIC | $STATIC, $staticMethod(BytecodeDescriptor, unparseMethod, $String*, $Class*, $List*)},
	{"unparseMethod", "(Ljava/lang/Class;[Ljava/lang/Class;)Ljava/lang/String;", "(Ljava/lang/Class<*>;[Ljava/lang/Class<*>;)Ljava/lang/String;", $PUBLIC | $STATIC, $staticMethod(BytecodeDescriptor, unparseMethod, $String*, $Class*, $ClassArray*)},
	{"unparseSig", "(Ljava/lang/Class;Ljava/lang/StringBuilder;)V", "(Ljava/lang/Class<*>;Ljava/lang/StringBuilder;)V", $PRIVATE | $STATIC, $staticMethod(BytecodeDescriptor, unparseSig, void, $Class*, $StringBuilder*)},
	{}
};

$ClassInfo _BytecodeDescriptor_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.invoke.util.BytecodeDescriptor",
	"java.lang.Object",
	nullptr,
	nullptr,
	_BytecodeDescriptor_MethodInfo_
};

$Object* allocate$BytecodeDescriptor($Class* clazz) {
	return $of($alloc(BytecodeDescriptor));
}

void BytecodeDescriptor::init$() {
}

$List* BytecodeDescriptor::parseMethod($String* bytecodeSignature, $ClassLoader* loader) {
	return parseMethod(bytecodeSignature, 0, $nc(bytecodeSignature)->length(), loader);
}

$List* BytecodeDescriptor::parseMethod($String* bytecodeSignature, int32_t start, int32_t end, $ClassLoader* loader) {
	$useLocalCurrentObjectStackCache();
	$var($String, str, bytecodeSignature);
	$var($ints, i, $new($ints, {start}));
	$var($ArrayList, ptypes, $new($ArrayList));
	if (i->get(0) < end && $nc(str)->charAt(i->get(0)) == u'(') {
		++(*i)[0];
		while (i->get(0) < end && str->charAt(i->get(0)) != u')') {
			$Class* pt = parseSig(str, i, end, loader);
			$init($Void);
			if (pt == nullptr || pt == $Void::TYPE) {
				parseError(str, "bad argument type"_s);
			}
			ptypes->add(pt);
		}
		++(*i)[0];
	} else {
		parseError(str, "not a method type"_s);
	}
	$Class* rtype = parseSig(str, i, end, loader);
	if (rtype == nullptr || i->get(0) != end) {
		parseError(str, "bad return type"_s);
	}
	ptypes->add(rtype);
	return ptypes;
}

void BytecodeDescriptor::parseError($String* str, $String* msg) {
	$throwNew($IllegalArgumentException, $$str({"bad signature: "_s, str, ": "_s, msg}));
}

$Class* BytecodeDescriptor::parseSig($String* str, $ints* i, int32_t end, $ClassLoader* loader) {
	$load(BytecodeDescriptor);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(i)->get(0) == end) {
		return nullptr;
	}
	char16_t c = $nc(str)->charAt((*$nc(i))[0]++);
	if (c == u'L') {
		int32_t begc = $nc(i)->get(0);
		int32_t endc = str->indexOf((int32_t)u';', begc);
		if (endc < 0) {
			return nullptr;
		}
		i->set(0, endc + 1);
		$var($String, name, $(str->substring(begc, endc))->replace(u'/', u'.'));
		try {
			return $Class::forName(name, false, loader);
		} catch ($ClassNotFoundException& ex) {
			$throwNew($TypeNotPresentException, name, ex);
		}
	} else if (c == u'[') {
		$Class* t = parseSig(str, i, end, loader);
		if (t != nullptr) {
			t = $of($($1Array::newInstance(t, 0)))->getClass();
		}
		return t;
	} else {
		return $nc($($Wrapper::forBasicType(c)))->primitiveType();
	}
}

$String* BytecodeDescriptor::unparse($Class* type) {
	if (type == $Object::class$) {
		return "Ljava/lang/Object;"_s;
	} else {
		$init($Integer);
		if (type == $Integer::TYPE) {
			return "I"_s;
		}
	}
	return $nc(type)->descriptorString();
}

$String* BytecodeDescriptor::unparse($MethodType* type) {
	$Class* var$0 = $cast($Class, $nc(type)->returnType());
	return unparseMethod(var$0, $($fcast($ClassArray, type->parameterArray())));
}

$String* BytecodeDescriptor::unparse(Object$* type) {
	if ($instanceOf($Class, type)) {
		return unparse($cast($Class, type));
	}
	if ($instanceOf($MethodType, type)) {
		return unparse($cast($MethodType, type));
	}
	return $cast($String, type);
}

$String* BytecodeDescriptor::unparseMethod($Class* rtype, $List* ptypes) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append(u'(');
	{
		$var($Iterator, i$, $nc(ptypes)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* pt = $cast($Class, i$->next());
			unparseSig(pt, sb);
		}
	}
	sb->append(u')');
	unparseSig(rtype, sb);
	return sb->toString();
}

$String* BytecodeDescriptor::unparseMethod($Class* rtype, $ClassArray* ptypes) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append(u'(');
	{
		$var($ClassArray, arr$, ptypes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* pt = arr$->get(i$);
			unparseSig(pt, sb);
		}
	}
	sb->append(u')');
	unparseSig(rtype, sb);
	return sb->toString();
}

void BytecodeDescriptor::unparseSig($Class* t, $StringBuilder* sb) {
	$useLocalCurrentObjectStackCache();
	char16_t c = $nc($($Wrapper::forBasicType(t)))->basicTypeChar();
	if (c != u'L') {
		$nc(sb)->append(c);
	} else if (t == $Object::class$) {
		$nc(sb)->append("Ljava/lang/Object;"_s);
	} else {
		$nc(sb)->append($(t->descriptorString()));
	}
}

BytecodeDescriptor::BytecodeDescriptor() {
}

$Class* BytecodeDescriptor::load$($String* name, bool initialize) {
	$loadClass(BytecodeDescriptor, name, initialize, &_BytecodeDescriptor_ClassInfo_, allocate$BytecodeDescriptor);
	return class$;
}

$Class* BytecodeDescriptor::class$ = nullptr;

		} // util
	} // invoke
} // sun
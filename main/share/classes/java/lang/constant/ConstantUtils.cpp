#include <java/lang/constant/ConstantUtils.h>

#include <java/lang/constant/ClassDesc.h>
#include <java/lang/constant/Constable.h>
#include <java/lang/constant/ConstantDesc.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef EMPTY_CONSTABLE
#undef EMPTY_CONSTANTDESC
#undef JVM_SIGNATURE_ARRAY
#undef JVM_SIGNATURE_BOOLEAN
#undef JVM_SIGNATURE_BYTE
#undef JVM_SIGNATURE_CHAR
#undef JVM_SIGNATURE_CLASS
#undef JVM_SIGNATURE_DOUBLE
#undef JVM_SIGNATURE_ENDCLASS
#undef JVM_SIGNATURE_ENDFUNC
#undef JVM_SIGNATURE_ENUM
#undef JVM_SIGNATURE_FLOAT
#undef JVM_SIGNATURE_FUNC
#undef JVM_SIGNATURE_INT
#undef JVM_SIGNATURE_LONG
#undef JVM_SIGNATURE_SHORT
#undef JVM_SIGNATURE_VOID
#undef MAX_ARRAY_TYPE_DESC_DIMENSIONS

using $ConstableArray = $Array<::java::lang::constant::Constable>;
using $ConstantDescArray = $Array<::java::lang::constant::ConstantDesc>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ClassDesc = ::java::lang::constant::ClassDesc;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;

namespace java {
	namespace lang {
		namespace constant {

$FieldInfo _ConstantUtils_FieldInfo_[] = {
	{"EMPTY_CONSTANTDESC", "[Ljava/lang/constant/ConstantDesc;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(ConstantUtils, EMPTY_CONSTANTDESC)},
	{"EMPTY_CONSTABLE", "[Ljava/lang/constant/Constable;", nullptr, $STATIC | $FINAL, $staticField(ConstantUtils, EMPTY_CONSTABLE)},
	{"MAX_ARRAY_TYPE_DESC_DIMENSIONS", "I", nullptr, $STATIC | $FINAL, $constField(ConstantUtils, MAX_ARRAY_TYPE_DESC_DIMENSIONS)},
	{"pointyNames", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ConstantUtils, pointyNames)},
	{"JVM_SIGNATURE_ARRAY", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_ARRAY)},
	{"JVM_SIGNATURE_BYTE", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_BYTE)},
	{"JVM_SIGNATURE_CHAR", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_CHAR)},
	{"JVM_SIGNATURE_CLASS", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_CLASS)},
	{"JVM_SIGNATURE_ENDCLASS", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_ENDCLASS)},
	{"JVM_SIGNATURE_ENUM", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_ENUM)},
	{"JVM_SIGNATURE_FLOAT", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_FLOAT)},
	{"JVM_SIGNATURE_DOUBLE", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_DOUBLE)},
	{"JVM_SIGNATURE_FUNC", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_FUNC)},
	{"JVM_SIGNATURE_ENDFUNC", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_ENDFUNC)},
	{"JVM_SIGNATURE_INT", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_INT)},
	{"JVM_SIGNATURE_LONG", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_LONG)},
	{"JVM_SIGNATURE_SHORT", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_SHORT)},
	{"JVM_SIGNATURE_VOID", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_VOID)},
	{"JVM_SIGNATURE_BOOLEAN", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ConstantUtils, JVM_SIGNATURE_BOOLEAN)},
	{}
};

$MethodInfo _ConstantUtils_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(ConstantUtils, init$, void)},
	{"arrayDepth", "(Ljava/lang/String;)I", nullptr, $STATIC, $staticMethod(ConstantUtils, arrayDepth, int32_t, $String*)},
	{"binaryToInternal", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ConstantUtils, binaryToInternal, $String*, $String*)},
	{"dropFirstAndLastChar", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ConstantUtils, dropFirstAndLastChar, $String*, $String*)},
	{"dropLastChar", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ConstantUtils, dropLastChar, $String*, $String*)},
	{"internalToBinary", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ConstantUtils, internalToBinary, $String*, $String*)},
	{"parseMethodDescriptor", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $STATIC, $staticMethod(ConstantUtils, parseMethodDescriptor, $List*, $String*)},
	{"skipOverFieldSignature", "(Ljava/lang/String;IIZ)I", nullptr, $STATIC, $staticMethod(ConstantUtils, skipOverFieldSignature, int32_t, $String*, int32_t, int32_t, bool)},
	{"validateBinaryClassName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $staticMethod(ConstantUtils, validateBinaryClassName, $String*, $String*)},
	{"validateClassOrInterface", "(Ljava/lang/constant/ClassDesc;)V", nullptr, $STATIC, $staticMethod(ConstantUtils, validateClassOrInterface, void, $ClassDesc*)},
	{"validateMemberName", "(Ljava/lang/String;Z)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ConstantUtils, validateMemberName, $String*, $String*, bool)},
	{"verifyUnqualifiedClassName", "(Ljava/lang/String;)Z", nullptr, $STATIC, $staticMethod(ConstantUtils, verifyUnqualifiedClassName, bool, $String*)},
	{}
};

$ClassInfo _ConstantUtils_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.constant.ConstantUtils",
	"java.lang.Object",
	nullptr,
	_ConstantUtils_FieldInfo_,
	_ConstantUtils_MethodInfo_
};

$Object* allocate$ConstantUtils($Class* clazz) {
	return $of($alloc(ConstantUtils));
}

$ConstantDescArray* ConstantUtils::EMPTY_CONSTANTDESC = nullptr;
$ConstableArray* ConstantUtils::EMPTY_CONSTABLE = nullptr;
$Set* ConstantUtils::pointyNames = nullptr;

void ConstantUtils::init$() {
}

$String* ConstantUtils::validateBinaryClassName($String* name) {
	$init(ConstantUtils);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(name)->length(); ++i) {
		char16_t ch = name->charAt(i);
		if (ch == u';' || ch == u'[' || ch == u'/') {
			$throwNew($IllegalArgumentException, $$str({"Invalid class name: "_s, name}));
		}
	}
	return name;
}

$String* ConstantUtils::validateMemberName($String* name, bool method) {
	$init(ConstantUtils);
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	if (name->length() == 0) {
		$throwNew($IllegalArgumentException, "zero-length member name"_s);
	}
	for (int32_t i = 0; i < name->length(); ++i) {
		char16_t ch = name->charAt(i);
		if (ch == u'.' || ch == u';' || ch == u'[' || ch == u'/') {
			$throwNew($IllegalArgumentException, $$str({"Invalid member name: "_s, name}));
		}
		if (method && (ch == u'<' || ch == u'>')) {
			if (!$nc(ConstantUtils::pointyNames)->contains(name)) {
				$throwNew($IllegalArgumentException, $$str({"Invalid member name: "_s, name}));
			}
		}
	}
	return name;
}

void ConstantUtils::validateClassOrInterface($ClassDesc* classDesc) {
	$init(ConstantUtils);
	if (!$nc(classDesc)->isClassOrInterface()) {
		$throwNew($IllegalArgumentException, $$str({"not a class or interface type: "_s, classDesc}));
	}
}

int32_t ConstantUtils::arrayDepth($String* descriptorString) {
	$init(ConstantUtils);
	int32_t depth = 0;
	while ($nc(descriptorString)->charAt(depth) == u'[') {
		++depth;
	}
	return depth;
}

$String* ConstantUtils::binaryToInternal($String* name) {
	$init(ConstantUtils);
	return $nc(name)->replace(u'.', u'/');
}

$String* ConstantUtils::internalToBinary($String* name) {
	$init(ConstantUtils);
	return $nc(name)->replace(u'/', u'.');
}

$String* ConstantUtils::dropLastChar($String* s) {
	$init(ConstantUtils);
	return $nc(s)->substring(0, s->length() - 1);
}

$String* ConstantUtils::dropFirstAndLastChar($String* s) {
	$init(ConstantUtils);
	return $nc(s)->substring(1, s->length() - 1);
}

$List* ConstantUtils::parseMethodDescriptor($String* descriptor) {
	$init(ConstantUtils);
	$useLocalCurrentObjectStackCache();
	int32_t cur = 0;
	int32_t end = $nc(descriptor)->length();
	$var($ArrayList, ptypes, $new($ArrayList));
	if (cur >= end || descriptor->charAt(cur) != u'(') {
		$throwNew($IllegalArgumentException, $$str({"Bad method descriptor: "_s, descriptor}));
	}
	++cur;
	while (cur < end && descriptor->charAt(cur) != u')') {
		int32_t len = skipOverFieldSignature(descriptor, cur, end, false);
		if (len == 0) {
			$throwNew($IllegalArgumentException, $$str({"Bad method descriptor: "_s, descriptor}));
		}
		ptypes->add($(descriptor->substring(cur, cur + len)));
		cur += len;
	}
	if (cur >= end) {
		$throwNew($IllegalArgumentException, $$str({"Bad method descriptor: "_s, descriptor}));
	}
	++cur;
	int32_t rLen = skipOverFieldSignature(descriptor, cur, end, true);
	if (rLen == 0 || cur + rLen != end) {
		$throwNew($IllegalArgumentException, $$str({"Bad method descriptor: "_s, descriptor}));
	}
	ptypes->add(0, $(descriptor->substring(cur, cur + rLen)));
	return ptypes;
}

int32_t ConstantUtils::skipOverFieldSignature($String* descriptor, int32_t start, int32_t end, bool voidOK) {
	$init(ConstantUtils);
	$useLocalCurrentObjectStackCache();
	int32_t arrayDim = 0;
	int32_t index = start;
	while (index < end) {
		{
			int32_t indexOfSemi = 0;
			switch ($nc(descriptor)->charAt(index)) {
			case ConstantUtils::JVM_SIGNATURE_VOID:
				{
					if (!voidOK) {
						return index;
					}
				}
			case ConstantUtils::JVM_SIGNATURE_BOOLEAN:
				{}
			case ConstantUtils::JVM_SIGNATURE_BYTE:
				{}
			case ConstantUtils::JVM_SIGNATURE_CHAR:
				{}
			case ConstantUtils::JVM_SIGNATURE_SHORT:
				{}
			case ConstantUtils::JVM_SIGNATURE_INT:
				{}
			case ConstantUtils::JVM_SIGNATURE_FLOAT:
				{}
			case ConstantUtils::JVM_SIGNATURE_LONG:
				{}
			case ConstantUtils::JVM_SIGNATURE_DOUBLE:
				{
					return index - start + 1;
				}
			case ConstantUtils::JVM_SIGNATURE_CLASS:
				{
					++index;
					indexOfSemi = descriptor->indexOf((int32_t)u';', index);
					if (indexOfSemi != -1) {
						$var($String, unqualifiedName, descriptor->substring(index, indexOfSemi));
						bool legal = verifyUnqualifiedClassName(unqualifiedName);
						if (!legal) {
							return 0;
						}
						return index - start + unqualifiedName->length() + 1;
					}
					return 0;
				}
			case ConstantUtils::JVM_SIGNATURE_ARRAY:
				{
					++arrayDim;
					if (arrayDim > ConstantUtils::MAX_ARRAY_TYPE_DESC_DIMENSIONS) {
						$throwNew($IllegalArgumentException, $($String::format("Cannot create an array type descriptor with more than %d dimensions"_s, $$new($ObjectArray, {$($of($Integer::valueOf(ConstantUtils::MAX_ARRAY_TYPE_DESC_DIMENSIONS)))}))));
					}
					++index;
					voidOK = false;
					break;
				}
			default:
				{
					return 0;
				}
			}
		}
	}
	return 0;
}

bool ConstantUtils::verifyUnqualifiedClassName($String* name) {
	$init(ConstantUtils);
	for (int32_t index = 0; index < $nc(name)->length(); ++index) {
		char16_t ch = name->charAt(index);
		if (ch < 128) {
			if (ch == u'.' || ch == u';' || ch == u'[') {
				return false;
			}
			if (ch == u'/') {
				bool var$0 = index == 0 || index + 1 >= name->length();
				if (var$0 || name->charAt(index + 1) == u'/') {
					return false;
				}
			}
		} else {
			++index;
		}
	}
	return true;
}

void clinit$ConstantUtils($Class* class$) {
	$assignStatic(ConstantUtils::EMPTY_CONSTANTDESC, $new($ConstantDescArray, 0));
	$assignStatic(ConstantUtils::EMPTY_CONSTABLE, $new($ConstableArray, 0));
	$assignStatic(ConstantUtils::pointyNames, $Set::of("<init>"_s, "<clinit>"_s));
}

ConstantUtils::ConstantUtils() {
}

$Class* ConstantUtils::load$($String* name, bool initialize) {
	$loadClass(ConstantUtils, name, initialize, &_ConstantUtils_ClassInfo_, clinit$ConstantUtils, allocate$ConstantUtils);
	return class$;
}

$Class* ConstantUtils::class$ = nullptr;

		} // constant
	} // lang
} // java
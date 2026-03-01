#include <java/text/Format.h>

#include <java/io/Serializable.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/StringBuffer.h>
#include <java/text/AttributedCharacterIterator$Attribute.h>
#include <java/text/AttributedCharacterIterator.h>
#include <java/text/AttributedString.h>
#include <java/text/FieldPosition.h>
#include <java/text/ParseException.h>
#include <java/text/ParsePosition.h>
#include <jcpp.h>

using $AttributedCharacterIteratorArray = $Array<::java::text::AttributedCharacterIterator>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $StringBuffer = ::java::lang::StringBuffer;
using $AttributedCharacterIterator = ::java::text::AttributedCharacterIterator;
using $AttributedCharacterIterator$Attribute = ::java::text::AttributedCharacterIterator$Attribute;
using $AttributedString = ::java::text::AttributedString;
using $FieldPosition = ::java::text::FieldPosition;
using $ParseException = ::java::text::ParseException;
using $ParsePosition = ::java::text::ParsePosition;

namespace java {
	namespace text {

$FieldInfo _Format_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Format, serialVersionUID)},
	{}
};

$MethodInfo _Format_MethodInfo_[] = {
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PROTECTED, $method(Format, init$, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Format, clone, $Object*)},
	{"createAttributedCharacterIterator", "(Ljava/lang/String;)Ljava/text/AttributedCharacterIterator;", nullptr, 0, $virtualMethod(Format, createAttributedCharacterIterator, $AttributedCharacterIterator*, $String*)},
	{"createAttributedCharacterIterator", "([Ljava/text/AttributedCharacterIterator;)Ljava/text/AttributedCharacterIterator;", nullptr, 0, $virtualMethod(Format, createAttributedCharacterIterator, $AttributedCharacterIterator*, $AttributedCharacterIteratorArray*)},
	{"createAttributedCharacterIterator", "(Ljava/lang/String;Ljava/text/AttributedCharacterIterator$Attribute;Ljava/lang/Object;)Ljava/text/AttributedCharacterIterator;", nullptr, 0, $virtualMethod(Format, createAttributedCharacterIterator, $AttributedCharacterIterator*, $String*, $AttributedCharacterIterator$Attribute*, Object$*)},
	{"createAttributedCharacterIterator", "(Ljava/text/AttributedCharacterIterator;Ljava/text/AttributedCharacterIterator$Attribute;Ljava/lang/Object;)Ljava/text/AttributedCharacterIterator;", nullptr, 0, $virtualMethod(Format, createAttributedCharacterIterator, $AttributedCharacterIterator*, $AttributedCharacterIterator*, $AttributedCharacterIterator$Attribute*, Object$*)},
	{"format", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $method(Format, format, $String*, Object$*)},
	{"format", "(Ljava/lang/Object;Ljava/lang/StringBuffer;Ljava/text/FieldPosition;)Ljava/lang/StringBuffer;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Format, format, $StringBuffer*, Object$*, $StringBuffer*, $FieldPosition*)},
	{"formatToCharacterIterator", "(Ljava/lang/Object;)Ljava/text/AttributedCharacterIterator;", nullptr, $PUBLIC, $virtualMethod(Format, formatToCharacterIterator, $AttributedCharacterIterator*, Object$*)},
	{"parseObject", "(Ljava/lang/String;Ljava/text/ParsePosition;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Format, parseObject, $Object*, $String*, $ParsePosition*)},
	{"parseObject", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Format, parseObject, $Object*, $String*), "java.text.ParseException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _Format_InnerClassesInfo_[] = {
	{"java.text.Format$FieldDelegate", "java.text.Format", "FieldDelegate", $STATIC | $INTERFACE | $ABSTRACT},
	{"java.text.Format$Field", "java.text.Format", "Field", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _Format_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.text.Format",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Cloneable",
	_Format_FieldInfo_,
	_Format_MethodInfo_,
	nullptr,
	nullptr,
	_Format_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.text.Format$FieldDelegate,java.text.Format$Field"
};

$Object* allocate$Format($Class* clazz) {
	return $of($alloc(Format));
}

int32_t Format::hashCode() {
	 return this->$Serializable::hashCode();
}

bool Format::equals(Object$* obj) {
	 return this->$Serializable::equals(obj);
}

$String* Format::toString() {
	 return this->$Serializable::toString();
}

void Format::finalize() {
	this->$Serializable::finalize();
}

void Format::init$() {
}

$String* Format::format(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, obj);
	$var($StringBuffer, var$1, $new($StringBuffer));
	return $nc($(format(var$0, var$1, $$new($FieldPosition, 0))))->toString();
}

$AttributedCharacterIterator* Format::formatToCharacterIterator(Object$* obj) {
	return createAttributedCharacterIterator($(format(obj)));
}

$Object* Format::parseObject($String* source) {
	$useLocalCurrentObjectStackCache();
	$var($ParsePosition, pos, $new($ParsePosition, 0));
	$var($Object, result, parseObject(source, pos));
	if (pos->index == 0) {
		$throwNew($ParseException, "Format.parseObject(String) failed"_s, pos->errorIndex);
	}
	return $of(result);
}

$Object* Format::clone() {
	try {
		return $of($Serializable::clone());
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$AttributedCharacterIterator* Format::createAttributedCharacterIterator($String* s) {
	$var($AttributedString, as, $new($AttributedString, s));
	return as->getIterator();
}

$AttributedCharacterIterator* Format::createAttributedCharacterIterator($AttributedCharacterIteratorArray* iterators) {
	$var($AttributedString, as, $new($AttributedString, iterators));
	return as->getIterator();
}

$AttributedCharacterIterator* Format::createAttributedCharacterIterator($String* string, $AttributedCharacterIterator$Attribute* key, Object$* value) {
	$var($AttributedString, as, $new($AttributedString, string));
	as->addAttribute(key, value);
	return as->getIterator();
}

$AttributedCharacterIterator* Format::createAttributedCharacterIterator($AttributedCharacterIterator* iterator, $AttributedCharacterIterator$Attribute* key, Object$* value) {
	$var($AttributedString, as, $new($AttributedString, iterator));
	as->addAttribute(key, value);
	return as->getIterator();
}

Format::Format() {
}

$Class* Format::load$($String* name, bool initialize) {
	$loadClass(Format, name, initialize, &_Format_ClassInfo_, allocate$Format);
	return class$;
}

$Class* Format::class$ = nullptr;

	} // text
} // java
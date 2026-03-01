#include <java/text/AttributedCharacterIterator$Attribute.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/Serializable.h>
#include <java/text/AttributedCharacterIterator.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef INPUT_METHOD_SEGMENT
#undef LANGUAGE
#undef READING

using $InvalidObjectException = ::java::io::InvalidObjectException;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;

namespace java {
	namespace text {

$FieldInfo _AttributedCharacterIterator$Attribute_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(AttributedCharacterIterator$Attribute, name)},
	{"instanceMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/text/AttributedCharacterIterator$Attribute;>;", $PRIVATE | $STATIC | $FINAL, $staticField(AttributedCharacterIterator$Attribute, instanceMap)},
	{"LANGUAGE", "Ljava/text/AttributedCharacterIterator$Attribute;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AttributedCharacterIterator$Attribute, LANGUAGE)},
	{"READING", "Ljava/text/AttributedCharacterIterator$Attribute;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AttributedCharacterIterator$Attribute, READING)},
	{"INPUT_METHOD_SEGMENT", "Ljava/text/AttributedCharacterIterator$Attribute;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(AttributedCharacterIterator$Attribute, INPUT_METHOD_SEGMENT)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(AttributedCharacterIterator$Attribute, serialVersionUID)},
	{}
};

$MethodInfo _AttributedCharacterIterator$Attribute_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $method(AttributedCharacterIterator$Attribute, init$, void, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(AttributedCharacterIterator$Attribute, equals, bool, Object$*)},
	{"getName", "()Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(AttributedCharacterIterator$Attribute, getName, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $FINAL, $virtualMethod(AttributedCharacterIterator$Attribute, hashCode, int32_t)},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(AttributedCharacterIterator$Attribute, readResolve, $Object*), "java.io.InvalidObjectException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(AttributedCharacterIterator$Attribute, toString, $String*)},
	{}
};

$InnerClassInfo _AttributedCharacterIterator$Attribute_InnerClassesInfo_[] = {
	{"java.text.AttributedCharacterIterator$Attribute", "java.text.AttributedCharacterIterator", "Attribute", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _AttributedCharacterIterator$Attribute_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.text.AttributedCharacterIterator$Attribute",
	"java.lang.Object",
	"java.io.Serializable",
	_AttributedCharacterIterator$Attribute_FieldInfo_,
	_AttributedCharacterIterator$Attribute_MethodInfo_,
	nullptr,
	nullptr,
	_AttributedCharacterIterator$Attribute_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.text.AttributedCharacterIterator"
};

$Object* allocate$AttributedCharacterIterator$Attribute($Class* clazz) {
	return $of($alloc(AttributedCharacterIterator$Attribute));
}

$Map* AttributedCharacterIterator$Attribute::instanceMap = nullptr;
AttributedCharacterIterator$Attribute* AttributedCharacterIterator$Attribute::LANGUAGE = nullptr;
AttributedCharacterIterator$Attribute* AttributedCharacterIterator$Attribute::READING = nullptr;
AttributedCharacterIterator$Attribute* AttributedCharacterIterator$Attribute::INPUT_METHOD_SEGMENT = nullptr;

void AttributedCharacterIterator$Attribute::init$($String* name) {
	$set(this, name, name);
	if ($of(this)->getClass() == AttributedCharacterIterator$Attribute::class$) {
		$nc(AttributedCharacterIterator$Attribute::instanceMap)->put(name, this);
	}
}

bool AttributedCharacterIterator$Attribute::equals(Object$* obj) {
	return $Serializable::equals(obj);
}

int32_t AttributedCharacterIterator$Attribute::hashCode() {
	return $Serializable::hashCode();
}

$String* AttributedCharacterIterator$Attribute::toString() {
	return $str({$($of(this)->getClass()->getName()), "("_s, this->name, ")"_s});
}

$String* AttributedCharacterIterator$Attribute::getName() {
	return this->name;
}

$Object* AttributedCharacterIterator$Attribute::readResolve() {
	$useLocalCurrentObjectStackCache();
	if ($of(this)->getClass() != AttributedCharacterIterator$Attribute::class$) {
		$throwNew($InvalidObjectException, "subclass didn\'t correctly implement readResolve"_s);
	}
	$var(AttributedCharacterIterator$Attribute, instance, $cast(AttributedCharacterIterator$Attribute, $nc(AttributedCharacterIterator$Attribute::instanceMap)->get($(getName()))));
	if (instance != nullptr) {
		return $of(instance);
	} else {
		$throwNew($InvalidObjectException, "unknown attribute name"_s);
	}
}

void clinit$AttributedCharacterIterator$Attribute($Class* class$) {
	$assignStatic(AttributedCharacterIterator$Attribute::instanceMap, $new($HashMap, 7));
	$assignStatic(AttributedCharacterIterator$Attribute::LANGUAGE, $new(AttributedCharacterIterator$Attribute, "language"_s));
	$assignStatic(AttributedCharacterIterator$Attribute::READING, $new(AttributedCharacterIterator$Attribute, "reading"_s));
	$assignStatic(AttributedCharacterIterator$Attribute::INPUT_METHOD_SEGMENT, $new(AttributedCharacterIterator$Attribute, "input_method_segment"_s));
}

AttributedCharacterIterator$Attribute::AttributedCharacterIterator$Attribute() {
}

$Class* AttributedCharacterIterator$Attribute::load$($String* name, bool initialize) {
	$loadClass(AttributedCharacterIterator$Attribute, name, initialize, &_AttributedCharacterIterator$Attribute_ClassInfo_, clinit$AttributedCharacterIterator$Attribute, allocate$AttributedCharacterIterator$Attribute);
	return class$;
}

$Class* AttributedCharacterIterator$Attribute::class$ = nullptr;

	} // text
} // java
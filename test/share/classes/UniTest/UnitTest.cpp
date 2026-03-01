#include <UniTest/UnitTest.h>

#include <UniTest/ArrayTypes.h>
#include <UniTest/ArrayTypesWithDefault.h>
#include <UniTest/Bar.h>
#include <UniTest/Dad.h>
#include <UniTest/Foo.h>
#include <UniTest/Grandpa.h>
#include <UniTest/Marker.h>
#include <UniTest/Point.h>
#include <UniTest/ScalarTypes.h>
#include <UniTest/ScalarTypesWithDefault.h>
#include <UniTest/SingleMemberBoolean.h>
#include <UniTest/SingleMemberBooleanAcceptDefClass.h>
#include <UniTest/SingleMemberBooleanArrAcceptDefClass.h>
#include <UniTest/SingleMemberBooleanArrEmptyClass.h>
#include <UniTest/SingleMemberBooleanArrOneClass.h>
#include <UniTest/SingleMemberBooleanArrOvrdDefClass.h>
#include <UniTest/SingleMemberBooleanArrTwoClass.h>
#include <UniTest/SingleMemberBooleanArray.h>
#include <UniTest/SingleMemberBooleanArrayDef.h>
#include <UniTest/SingleMemberBooleanClass.h>
#include <UniTest/SingleMemberBooleanOvrdDefClass.h>
#include <UniTest/SingleMemberBooleanWithDef.h>
#include <UniTest/SingleMemberByte.h>
#include <UniTest/SingleMemberByteAcceptDefClass.h>
#include <UniTest/SingleMemberByteArrAcceptDefClass.h>
#include <UniTest/SingleMemberByteArrEmptyClass.h>
#include <UniTest/SingleMemberByteArrOneClass.h>
#include <UniTest/SingleMemberByteArrOvrdDefClass.h>
#include <UniTest/SingleMemberByteArrTwoClass.h>
#include <UniTest/SingleMemberByteArray.h>
#include <UniTest/SingleMemberByteArrayDef.h>
#include <UniTest/SingleMemberByteClass.h>
#include <UniTest/SingleMemberByteOvrdDefClass.h>
#include <UniTest/SingleMemberByteWithDef.h>
#include <UniTest/SingleMemberChar.h>
#include <UniTest/SingleMemberCharAcceptDefClass.h>
#include <UniTest/SingleMemberCharArrAcceptDefClass.h>
#include <UniTest/SingleMemberCharArrEmptyClass.h>
#include <UniTest/SingleMemberCharArrOneClass.h>
#include <UniTest/SingleMemberCharArrOvrdDefClass.h>
#include <UniTest/SingleMemberCharArrTwoClass.h>
#include <UniTest/SingleMemberCharArray.h>
#include <UniTest/SingleMemberCharArrayDef.h>
#include <UniTest/SingleMemberCharClass.h>
#include <UniTest/SingleMemberCharOvrdDefClass.h>
#include <UniTest/SingleMemberCharWithDef.h>
#include <UniTest/SingleMemberClass.h>
#include <UniTest/SingleMemberClassAcceptDefClass.h>
#include <UniTest/SingleMemberClassArrAcceptDefClass.h>
#include <UniTest/SingleMemberClassArrEmptyClass.h>
#include <UniTest/SingleMemberClassArrOneClass.h>
#include <UniTest/SingleMemberClassArrOvrdDefClass.h>
#include <UniTest/SingleMemberClassArrTwoClass.h>
#include <UniTest/SingleMemberClassArray.h>
#include <UniTest/SingleMemberClassArrayDef.h>
#include <UniTest/SingleMemberClassClass.h>
#include <UniTest/SingleMemberClassOvrdDefClass.h>
#include <UniTest/SingleMemberClassWithDef.h>
#include <UniTest/SingleMemberDouble.h>
#include <UniTest/SingleMemberDoubleAcceptDefClass.h>
#include <UniTest/SingleMemberDoubleArrAcceptDefClass.h>
#include <UniTest/SingleMemberDoubleArrEmptyClass.h>
#include <UniTest/SingleMemberDoubleArrOneClass.h>
#include <UniTest/SingleMemberDoubleArrOvrdDefClass.h>
#include <UniTest/SingleMemberDoubleArrTwoClass.h>
#include <UniTest/SingleMemberDoubleArray.h>
#include <UniTest/SingleMemberDoubleArrayDef.h>
#include <UniTest/SingleMemberDoubleClass.h>
#include <UniTest/SingleMemberDoubleOvrdDefClass.h>
#include <UniTest/SingleMemberDoubleWithDef.h>
#include <UniTest/SingleMemberEnum.h>
#include <UniTest/SingleMemberEnumAcceptDefClass.h>
#include <UniTest/SingleMemberEnumArrAcceptDefClass.h>
#include <UniTest/SingleMemberEnumArrEmptyClass.h>
#include <UniTest/SingleMemberEnumArrOneClass.h>
#include <UniTest/SingleMemberEnumArrOvrdDefClass.h>
#include <UniTest/SingleMemberEnumArrTwoClass.h>
#include <UniTest/SingleMemberEnumArray.h>
#include <UniTest/SingleMemberEnumArrayDef.h>
#include <UniTest/SingleMemberEnumClass.h>
#include <UniTest/SingleMemberEnumOvrdDefClass.h>
#include <UniTest/SingleMemberEnumWithDef.h>
#include <UniTest/SingleMemberFloat.h>
#include <UniTest/SingleMemberFloatAcceptDefClass.h>
#include <UniTest/SingleMemberFloatArrAcceptDefClass.h>
#include <UniTest/SingleMemberFloatArrEmptyClass.h>
#include <UniTest/SingleMemberFloatArrOneClass.h>
#include <UniTest/SingleMemberFloatArrOvrdDefClass.h>
#include <UniTest/SingleMemberFloatArrTwoClass.h>
#include <UniTest/SingleMemberFloatArray.h>
#include <UniTest/SingleMemberFloatArrayDef.h>
#include <UniTest/SingleMemberFloatClass.h>
#include <UniTest/SingleMemberFloatOvrdDefClass.h>
#include <UniTest/SingleMemberFloatWithDef.h>
#include <UniTest/SingleMemberInt.h>
#include <UniTest/SingleMemberIntAcceptDefClass.h>
#include <UniTest/SingleMemberIntArrAcceptDefClass.h>
#include <UniTest/SingleMemberIntArrEmptyClass.h>
#include <UniTest/SingleMemberIntArrOneClass.h>
#include <UniTest/SingleMemberIntArrOvrdDefClass.h>
#include <UniTest/SingleMemberIntArrTwoClass.h>
#include <UniTest/SingleMemberIntArray.h>
#include <UniTest/SingleMemberIntArrayDef.h>
#include <UniTest/SingleMemberIntClass.h>
#include <UniTest/SingleMemberIntOvrdDefClass.h>
#include <UniTest/SingleMemberIntWithDef.h>
#include <UniTest/SingleMemberLong.h>
#include <UniTest/SingleMemberLongAcceptDefClass.h>
#include <UniTest/SingleMemberLongArrAcceptDefClass.h>
#include <UniTest/SingleMemberLongArrEmptyClass.h>
#include <UniTest/SingleMemberLongArrOneClass.h>
#include <UniTest/SingleMemberLongArrOvrdDefClass.h>
#include <UniTest/SingleMemberLongArrTwoClass.h>
#include <UniTest/SingleMemberLongArray.h>
#include <UniTest/SingleMemberLongArrayDef.h>
#include <UniTest/SingleMemberLongClass.h>
#include <UniTest/SingleMemberLongOvrdDefClass.h>
#include <UniTest/SingleMemberLongWithDef.h>
#include <UniTest/SingleMemberShort.h>
#include <UniTest/SingleMemberShortAcceptDefClass.h>
#include <UniTest/SingleMemberShortArrAcceptDefClass.h>
#include <UniTest/SingleMemberShortArrEmptyClass.h>
#include <UniTest/SingleMemberShortArrOneClass.h>
#include <UniTest/SingleMemberShortArrOvrdDefClass.h>
#include <UniTest/SingleMemberShortArrTwoClass.h>
#include <UniTest/SingleMemberShortArray.h>
#include <UniTest/SingleMemberShortArrayDef.h>
#include <UniTest/SingleMemberShortClass.h>
#include <UniTest/SingleMemberShortOvrdDefClass.h>
#include <UniTest/SingleMemberShortWithDef.h>
#include <UniTest/SingleMemberString.h>
#include <UniTest/SingleMemberStringAcceptDefClass.h>
#include <UniTest/SingleMemberStringArrAcceptDefClass.h>
#include <UniTest/SingleMemberStringArrEmptyClass.h>
#include <UniTest/SingleMemberStringArrOneClass.h>
#include <UniTest/SingleMemberStringArrOvrdDefClass.h>
#include <UniTest/SingleMemberStringArrTwoClass.h>
#include <UniTest/SingleMemberStringArray.h>
#include <UniTest/SingleMemberStringArrayDef.h>
#include <UniTest/SingleMemberStringClass.h>
#include <UniTest/SingleMemberStringOvrdDefClass.h>
#include <UniTest/SingleMemberStringWithDef.h>
#include <UniTest/Son.h>
#include <UniTest/Stooge.h>
#include <UniTest/UnitTest$TestType.h>
#include <UniTest/arrayTypesAcceptDefaultClass.h>
#include <UniTest/arrayTypesOverrideDefaultClass.h>
#include <UniTest/emptyArrayTypesClass.h>
#include <UniTest/markerClass.h>
#include <UniTest/scalarTypesAcceptDefaultClass.h>
#include <UniTest/scalarTypesClass.h>
#include <UniTest/scalarTypesOverrideDefaultClass.h>
#include <UniTest/singleElementArrayTypesClass.h>
#include <UniTest/twoElementArrayTypesClass.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/Enum.h>
#include <java/lang/annotation/Annotation.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/reflect/AnnotatedElement.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Executable.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Method.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/RandomAccess.h>
#include <java/util/Set.h>
#include <java/util/SortedMap.h>
#include <java/util/SortedSet.h>
#include <jcpp.h>

#undef CURLY
#undef LARRY
#undef MOE
#undef TYPE
#undef X
#undef Y

using $ArrayTypes = ::UniTest::ArrayTypes;
using $ArrayTypesWithDefault = ::UniTest::ArrayTypesWithDefault;
using $Bar = ::UniTest::Bar;
using $Dad = ::UniTest::Dad;
using $Foo = ::UniTest::Foo;
using $Grandpa = ::UniTest::Grandpa;
using $Marker = ::UniTest::Marker;
using $Point = ::UniTest::Point;
using $ScalarTypes = ::UniTest::ScalarTypes;
using $ScalarTypesWithDefault = ::UniTest::ScalarTypesWithDefault;
using $SingleMemberBoolean = ::UniTest::SingleMemberBoolean;
using $SingleMemberBooleanAcceptDefClass = ::UniTest::SingleMemberBooleanAcceptDefClass;
using $SingleMemberBooleanArrAcceptDefClass = ::UniTest::SingleMemberBooleanArrAcceptDefClass;
using $SingleMemberBooleanArrEmptyClass = ::UniTest::SingleMemberBooleanArrEmptyClass;
using $SingleMemberBooleanArrOneClass = ::UniTest::SingleMemberBooleanArrOneClass;
using $SingleMemberBooleanArrOvrdDefClass = ::UniTest::SingleMemberBooleanArrOvrdDefClass;
using $SingleMemberBooleanArrTwoClass = ::UniTest::SingleMemberBooleanArrTwoClass;
using $SingleMemberBooleanArray = ::UniTest::SingleMemberBooleanArray;
using $SingleMemberBooleanArrayDef = ::UniTest::SingleMemberBooleanArrayDef;
using $SingleMemberBooleanClass = ::UniTest::SingleMemberBooleanClass;
using $SingleMemberBooleanOvrdDefClass = ::UniTest::SingleMemberBooleanOvrdDefClass;
using $SingleMemberBooleanWithDef = ::UniTest::SingleMemberBooleanWithDef;
using $SingleMemberByte = ::UniTest::SingleMemberByte;
using $SingleMemberByteAcceptDefClass = ::UniTest::SingleMemberByteAcceptDefClass;
using $SingleMemberByteArrAcceptDefClass = ::UniTest::SingleMemberByteArrAcceptDefClass;
using $SingleMemberByteArrEmptyClass = ::UniTest::SingleMemberByteArrEmptyClass;
using $SingleMemberByteArrOneClass = ::UniTest::SingleMemberByteArrOneClass;
using $SingleMemberByteArrOvrdDefClass = ::UniTest::SingleMemberByteArrOvrdDefClass;
using $SingleMemberByteArrTwoClass = ::UniTest::SingleMemberByteArrTwoClass;
using $SingleMemberByteArray = ::UniTest::SingleMemberByteArray;
using $SingleMemberByteArrayDef = ::UniTest::SingleMemberByteArrayDef;
using $SingleMemberByteClass = ::UniTest::SingleMemberByteClass;
using $SingleMemberByteOvrdDefClass = ::UniTest::SingleMemberByteOvrdDefClass;
using $SingleMemberByteWithDef = ::UniTest::SingleMemberByteWithDef;
using $SingleMemberChar = ::UniTest::SingleMemberChar;
using $SingleMemberCharAcceptDefClass = ::UniTest::SingleMemberCharAcceptDefClass;
using $SingleMemberCharArrAcceptDefClass = ::UniTest::SingleMemberCharArrAcceptDefClass;
using $SingleMemberCharArrEmptyClass = ::UniTest::SingleMemberCharArrEmptyClass;
using $SingleMemberCharArrOneClass = ::UniTest::SingleMemberCharArrOneClass;
using $SingleMemberCharArrOvrdDefClass = ::UniTest::SingleMemberCharArrOvrdDefClass;
using $SingleMemberCharArrTwoClass = ::UniTest::SingleMemberCharArrTwoClass;
using $SingleMemberCharArray = ::UniTest::SingleMemberCharArray;
using $SingleMemberCharArrayDef = ::UniTest::SingleMemberCharArrayDef;
using $SingleMemberCharClass = ::UniTest::SingleMemberCharClass;
using $SingleMemberCharOvrdDefClass = ::UniTest::SingleMemberCharOvrdDefClass;
using $SingleMemberCharWithDef = ::UniTest::SingleMemberCharWithDef;
using $SingleMemberClass = ::UniTest::SingleMemberClass;
using $SingleMemberClassAcceptDefClass = ::UniTest::SingleMemberClassAcceptDefClass;
using $SingleMemberClassArrAcceptDefClass = ::UniTest::SingleMemberClassArrAcceptDefClass;
using $SingleMemberClassArrEmptyClass = ::UniTest::SingleMemberClassArrEmptyClass;
using $SingleMemberClassArrOneClass = ::UniTest::SingleMemberClassArrOneClass;
using $SingleMemberClassArrOvrdDefClass = ::UniTest::SingleMemberClassArrOvrdDefClass;
using $SingleMemberClassArrTwoClass = ::UniTest::SingleMemberClassArrTwoClass;
using $SingleMemberClassArray = ::UniTest::SingleMemberClassArray;
using $SingleMemberClassArrayDef = ::UniTest::SingleMemberClassArrayDef;
using $SingleMemberClassClass = ::UniTest::SingleMemberClassClass;
using $SingleMemberClassOvrdDefClass = ::UniTest::SingleMemberClassOvrdDefClass;
using $SingleMemberClassWithDef = ::UniTest::SingleMemberClassWithDef;
using $SingleMemberDouble = ::UniTest::SingleMemberDouble;
using $SingleMemberDoubleAcceptDefClass = ::UniTest::SingleMemberDoubleAcceptDefClass;
using $SingleMemberDoubleArrAcceptDefClass = ::UniTest::SingleMemberDoubleArrAcceptDefClass;
using $SingleMemberDoubleArrEmptyClass = ::UniTest::SingleMemberDoubleArrEmptyClass;
using $SingleMemberDoubleArrOneClass = ::UniTest::SingleMemberDoubleArrOneClass;
using $SingleMemberDoubleArrOvrdDefClass = ::UniTest::SingleMemberDoubleArrOvrdDefClass;
using $SingleMemberDoubleArrTwoClass = ::UniTest::SingleMemberDoubleArrTwoClass;
using $SingleMemberDoubleArray = ::UniTest::SingleMemberDoubleArray;
using $SingleMemberDoubleArrayDef = ::UniTest::SingleMemberDoubleArrayDef;
using $SingleMemberDoubleClass = ::UniTest::SingleMemberDoubleClass;
using $SingleMemberDoubleOvrdDefClass = ::UniTest::SingleMemberDoubleOvrdDefClass;
using $SingleMemberDoubleWithDef = ::UniTest::SingleMemberDoubleWithDef;
using $SingleMemberEnum = ::UniTest::SingleMemberEnum;
using $SingleMemberEnumAcceptDefClass = ::UniTest::SingleMemberEnumAcceptDefClass;
using $SingleMemberEnumArrAcceptDefClass = ::UniTest::SingleMemberEnumArrAcceptDefClass;
using $SingleMemberEnumArrEmptyClass = ::UniTest::SingleMemberEnumArrEmptyClass;
using $SingleMemberEnumArrOneClass = ::UniTest::SingleMemberEnumArrOneClass;
using $SingleMemberEnumArrOvrdDefClass = ::UniTest::SingleMemberEnumArrOvrdDefClass;
using $SingleMemberEnumArrTwoClass = ::UniTest::SingleMemberEnumArrTwoClass;
using $SingleMemberEnumArray = ::UniTest::SingleMemberEnumArray;
using $SingleMemberEnumArrayDef = ::UniTest::SingleMemberEnumArrayDef;
using $SingleMemberEnumClass = ::UniTest::SingleMemberEnumClass;
using $SingleMemberEnumOvrdDefClass = ::UniTest::SingleMemberEnumOvrdDefClass;
using $SingleMemberEnumWithDef = ::UniTest::SingleMemberEnumWithDef;
using $SingleMemberFloat = ::UniTest::SingleMemberFloat;
using $SingleMemberFloatAcceptDefClass = ::UniTest::SingleMemberFloatAcceptDefClass;
using $SingleMemberFloatArrAcceptDefClass = ::UniTest::SingleMemberFloatArrAcceptDefClass;
using $SingleMemberFloatArrEmptyClass = ::UniTest::SingleMemberFloatArrEmptyClass;
using $SingleMemberFloatArrOneClass = ::UniTest::SingleMemberFloatArrOneClass;
using $SingleMemberFloatArrOvrdDefClass = ::UniTest::SingleMemberFloatArrOvrdDefClass;
using $SingleMemberFloatArrTwoClass = ::UniTest::SingleMemberFloatArrTwoClass;
using $SingleMemberFloatArray = ::UniTest::SingleMemberFloatArray;
using $SingleMemberFloatArrayDef = ::UniTest::SingleMemberFloatArrayDef;
using $SingleMemberFloatClass = ::UniTest::SingleMemberFloatClass;
using $SingleMemberFloatOvrdDefClass = ::UniTest::SingleMemberFloatOvrdDefClass;
using $SingleMemberFloatWithDef = ::UniTest::SingleMemberFloatWithDef;
using $SingleMemberInt = ::UniTest::SingleMemberInt;
using $SingleMemberIntAcceptDefClass = ::UniTest::SingleMemberIntAcceptDefClass;
using $SingleMemberIntArrAcceptDefClass = ::UniTest::SingleMemberIntArrAcceptDefClass;
using $SingleMemberIntArrEmptyClass = ::UniTest::SingleMemberIntArrEmptyClass;
using $SingleMemberIntArrOneClass = ::UniTest::SingleMemberIntArrOneClass;
using $SingleMemberIntArrOvrdDefClass = ::UniTest::SingleMemberIntArrOvrdDefClass;
using $SingleMemberIntArrTwoClass = ::UniTest::SingleMemberIntArrTwoClass;
using $SingleMemberIntArray = ::UniTest::SingleMemberIntArray;
using $SingleMemberIntArrayDef = ::UniTest::SingleMemberIntArrayDef;
using $SingleMemberIntClass = ::UniTest::SingleMemberIntClass;
using $SingleMemberIntOvrdDefClass = ::UniTest::SingleMemberIntOvrdDefClass;
using $SingleMemberIntWithDef = ::UniTest::SingleMemberIntWithDef;
using $SingleMemberLong = ::UniTest::SingleMemberLong;
using $SingleMemberLongAcceptDefClass = ::UniTest::SingleMemberLongAcceptDefClass;
using $SingleMemberLongArrAcceptDefClass = ::UniTest::SingleMemberLongArrAcceptDefClass;
using $SingleMemberLongArrEmptyClass = ::UniTest::SingleMemberLongArrEmptyClass;
using $SingleMemberLongArrOneClass = ::UniTest::SingleMemberLongArrOneClass;
using $SingleMemberLongArrOvrdDefClass = ::UniTest::SingleMemberLongArrOvrdDefClass;
using $SingleMemberLongArrTwoClass = ::UniTest::SingleMemberLongArrTwoClass;
using $SingleMemberLongArray = ::UniTest::SingleMemberLongArray;
using $SingleMemberLongArrayDef = ::UniTest::SingleMemberLongArrayDef;
using $SingleMemberLongClass = ::UniTest::SingleMemberLongClass;
using $SingleMemberLongOvrdDefClass = ::UniTest::SingleMemberLongOvrdDefClass;
using $SingleMemberLongWithDef = ::UniTest::SingleMemberLongWithDef;
using $SingleMemberShort = ::UniTest::SingleMemberShort;
using $SingleMemberShortAcceptDefClass = ::UniTest::SingleMemberShortAcceptDefClass;
using $SingleMemberShortArrAcceptDefClass = ::UniTest::SingleMemberShortArrAcceptDefClass;
using $SingleMemberShortArrEmptyClass = ::UniTest::SingleMemberShortArrEmptyClass;
using $SingleMemberShortArrOneClass = ::UniTest::SingleMemberShortArrOneClass;
using $SingleMemberShortArrOvrdDefClass = ::UniTest::SingleMemberShortArrOvrdDefClass;
using $SingleMemberShortArrTwoClass = ::UniTest::SingleMemberShortArrTwoClass;
using $SingleMemberShortArray = ::UniTest::SingleMemberShortArray;
using $SingleMemberShortArrayDef = ::UniTest::SingleMemberShortArrayDef;
using $SingleMemberShortClass = ::UniTest::SingleMemberShortClass;
using $SingleMemberShortOvrdDefClass = ::UniTest::SingleMemberShortOvrdDefClass;
using $SingleMemberShortWithDef = ::UniTest::SingleMemberShortWithDef;
using $SingleMemberString = ::UniTest::SingleMemberString;
using $SingleMemberStringAcceptDefClass = ::UniTest::SingleMemberStringAcceptDefClass;
using $SingleMemberStringArrAcceptDefClass = ::UniTest::SingleMemberStringArrAcceptDefClass;
using $SingleMemberStringArrEmptyClass = ::UniTest::SingleMemberStringArrEmptyClass;
using $SingleMemberStringArrOneClass = ::UniTest::SingleMemberStringArrOneClass;
using $SingleMemberStringArrOvrdDefClass = ::UniTest::SingleMemberStringArrOvrdDefClass;
using $SingleMemberStringArrTwoClass = ::UniTest::SingleMemberStringArrTwoClass;
using $SingleMemberStringArray = ::UniTest::SingleMemberStringArray;
using $SingleMemberStringArrayDef = ::UniTest::SingleMemberStringArrayDef;
using $SingleMemberStringClass = ::UniTest::SingleMemberStringClass;
using $SingleMemberStringOvrdDefClass = ::UniTest::SingleMemberStringOvrdDefClass;
using $SingleMemberStringWithDef = ::UniTest::SingleMemberStringWithDef;
using $Son = ::UniTest::Son;
using $Stooge = ::UniTest::Stooge;
using $UnitTest$TestType = ::UniTest::UnitTest$TestType;
using $arrayTypesAcceptDefaultClass = ::UniTest::arrayTypesAcceptDefaultClass;
using $arrayTypesOverrideDefaultClass = ::UniTest::arrayTypesOverrideDefaultClass;
using $emptyArrayTypesClass = ::UniTest::emptyArrayTypesClass;
using $markerClass = ::UniTest::markerClass;
using $scalarTypesAcceptDefaultClass = ::UniTest::scalarTypesAcceptDefaultClass;
using $scalarTypesClass = ::UniTest::scalarTypesClass;
using $scalarTypesOverrideDefaultClass = ::UniTest::scalarTypesOverrideDefaultClass;
using $singleElementArrayTypesClass = ::UniTest::singleElementArrayTypesClass;
using $twoElementArrayTypesClass = ::UniTest::twoElementArrayTypesClass;
using $EnumArray = $Array<::java::lang::Enum>;
using $AnnotationArray = $Array<::java::lang::annotation::Annotation>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Attribute = ::java::lang::Attribute;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $ParameterAnnotation = ::java::lang::ParameterAnnotation;
using $Short = ::java::lang::Short;
using $Annotation = ::java::lang::annotation::Annotation;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $AnnotatedElement = ::java::lang::reflect::AnnotatedElement;
using $Executable = ::java::lang::reflect::Executable;
using $Method = ::java::lang::reflect::Method;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $RandomAccess = ::java::util::RandomAccess;
using $Set = ::java::util::Set;
using $SortedMap = ::java::util::SortedMap;
using $SortedSet = ::java::util::SortedSet;

namespace UniTest {

$NamedAttribute UnitTest_Attribute_var$2[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$1 = {
"LUniTest/Point;", UnitTest_Attribute_var$2
};

$NamedAttribute UnitTest_Attribute_var$0[] = {
	{"b", 'B', "1"},
	{"s", 'S', "2"},
	{"i", 'I', "3"},
	{"l", 'J', "4"},
	{"c", 'C', "5"},
	{"f", 'F', "6.0"},
	{"d", 'D', "7.0"},
	{"bool", 'Z', "true"},
	{"str", 's', "custom"},
	{"cls", 'c', "Ljava/util/Map;"},
	{"e", 'e', "LUniTest/Stooge; MOE"},
	{"a", '@', &UnitTest_CompoundAttribute_var$1},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_scalarTypesField[] = {
	{"LUniTest/ScalarTypes;", UnitTest_Attribute_var$0},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_scalarTypesAcceptDefaultField[] = {
	{"LUniTest/ScalarTypesWithDefault;", nullptr},
	{}
};

$NamedAttribute UnitTest_Attribute_var$3[] = {
	{"b", 'B', "1"},
	{"s", 'S', "2"},
	{"i", 'I', "3"},
	{"l", 'J', "4"},
	{"c", 'C', "5"},
	{"f", 'F', "6.0"},
	{"d", 'D', "7.0"},
	{"bool", 'Z', "true"},
	{"str", 's', "custom"},
	{"cls", 'c', "Ljava/util/Map;"},
	{"e", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_scalarTypesOverrideDefaultField[] = {
	{"LUniTest/ScalarTypesWithDefault;", UnitTest_Attribute_var$3},
	{}
};

$Attribute UnitTest_Attribute_var$5[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$6[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$7[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$8[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$9[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$10[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$11[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$12[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$13[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$14[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$15[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$16[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$4[] = {
	{"b", '[', UnitTest_Attribute_var$5},
	{"s", '[', UnitTest_Attribute_var$6},
	{"i", '[', UnitTest_Attribute_var$7},
	{"l", '[', UnitTest_Attribute_var$8},
	{"c", '[', UnitTest_Attribute_var$9},
	{"f", '[', UnitTest_Attribute_var$10},
	{"d", '[', UnitTest_Attribute_var$11},
	{"bool", '[', UnitTest_Attribute_var$12},
	{"str", '[', UnitTest_Attribute_var$13},
	{"cls", '[', UnitTest_Attribute_var$14},
	{"e", '[', UnitTest_Attribute_var$15},
	{"a", '[', UnitTest_Attribute_var$16},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_emptyArrayTypesField[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$4},
	{}
};

$Attribute UnitTest_Attribute_var$18[] = {
	{'B', "1"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$19[] = {
	{'S', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$20[] = {
	{'I', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$21[] = {
	{'J', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$22[] = {
	{'C', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$23[] = {
	{'F', "6.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$24[] = {
	{'D', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$25[] = {
	{'Z', "true"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$26[] = {
	{'s', "custom"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$27[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$28[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$31[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$30 = {
"LUniTest/Point;", UnitTest_Attribute_var$31
};

$Attribute UnitTest_Attribute_var$29[] = {
	{'@', &UnitTest_CompoundAttribute_var$30},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$17[] = {
	{"b", '[', UnitTest_Attribute_var$18},
	{"s", '[', UnitTest_Attribute_var$19},
	{"i", '[', UnitTest_Attribute_var$20},
	{"l", '[', UnitTest_Attribute_var$21},
	{"c", '[', UnitTest_Attribute_var$22},
	{"f", '[', UnitTest_Attribute_var$23},
	{"d", '[', UnitTest_Attribute_var$24},
	{"bool", '[', UnitTest_Attribute_var$25},
	{"str", '[', UnitTest_Attribute_var$26},
	{"cls", '[', UnitTest_Attribute_var$27},
	{"e", '[', UnitTest_Attribute_var$28},
	{"a", '[', UnitTest_Attribute_var$29},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_singleElementArrayTypesField[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$17},
	{}
};

$Attribute UnitTest_Attribute_var$33[] = {
	{'B', "1"},
	{'B', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$34[] = {
	{'S', "2"},
	{'S', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$35[] = {
	{'I', "3"},
	{'I', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$36[] = {
	{'J', "4"},
	{'J', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$37[] = {
	{'C', "5"},
	{'C', "6"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$38[] = {
	{'F', "6.0"},
	{'F', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$39[] = {
	{'D', "7.0"},
	{'D', "8.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$40[] = {
	{'Z', "true"},
	{'Z', "false"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$41[] = {
	{'s', "custom"},
	{'s', "paint"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$42[] = {
	{'c', "Ljava/util/Map;"},
	{'c', "Ljava/util/Set;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$43[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'e', "LUniTest/Stooge; CURLY"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$46[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$45 = {
"LUniTest/Point;", UnitTest_Attribute_var$46
};

$NamedAttribute UnitTest_Attribute_var$48[] = {
	{"x", 'I', "3"},
	{"y", 'I', "4"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$47 = {
"LUniTest/Point;", UnitTest_Attribute_var$48
};

$Attribute UnitTest_Attribute_var$44[] = {
	{'@', &UnitTest_CompoundAttribute_var$45},
	{'@', &UnitTest_CompoundAttribute_var$47},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$32[] = {
	{"b", '[', UnitTest_Attribute_var$33},
	{"s", '[', UnitTest_Attribute_var$34},
	{"i", '[', UnitTest_Attribute_var$35},
	{"l", '[', UnitTest_Attribute_var$36},
	{"c", '[', UnitTest_Attribute_var$37},
	{"f", '[', UnitTest_Attribute_var$38},
	{"d", '[', UnitTest_Attribute_var$39},
	{"bool", '[', UnitTest_Attribute_var$40},
	{"str", '[', UnitTest_Attribute_var$41},
	{"cls", '[', UnitTest_Attribute_var$42},
	{"e", '[', UnitTest_Attribute_var$43},
	{"a", '[', UnitTest_Attribute_var$44},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_twoElementArrayTypesField[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$32},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_arrayTypesAcceptDefaultField[] = {
	{"LUniTest/ArrayTypesWithDefault;", nullptr},
	{}
};

$Attribute UnitTest_Attribute_var$50[] = {
	{'B', "1"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$51[] = {
	{'S', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$52[] = {
	{'I', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$53[] = {
	{'J', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$54[] = {
	{'C', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$55[] = {
	{'F', "6.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$56[] = {
	{'D', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$57[] = {
	{'Z', "true"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$58[] = {
	{'s', "custom"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$59[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$60[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$63[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$62 = {
"LUniTest/Point;", UnitTest_Attribute_var$63
};

$Attribute UnitTest_Attribute_var$61[] = {
	{'@', &UnitTest_CompoundAttribute_var$62},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$49[] = {
	{"b", '[', UnitTest_Attribute_var$50},
	{"s", '[', UnitTest_Attribute_var$51},
	{"i", '[', UnitTest_Attribute_var$52},
	{"l", '[', UnitTest_Attribute_var$53},
	{"c", '[', UnitTest_Attribute_var$54},
	{"f", '[', UnitTest_Attribute_var$55},
	{"d", '[', UnitTest_Attribute_var$56},
	{"bool", '[', UnitTest_Attribute_var$57},
	{"str", '[', UnitTest_Attribute_var$58},
	{"cls", '[', UnitTest_Attribute_var$59},
	{"e", '[', UnitTest_Attribute_var$60},
	{"a", '[', UnitTest_Attribute_var$61},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_arrayTypesOverrideDefaultField[] = {
	{"LUniTest/ArrayTypesWithDefault;", UnitTest_Attribute_var$49},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_markerField[] = {
	{"LUniTest/Marker;", nullptr},
	{}
};

$NamedAttribute UnitTest_Attribute_var$64[] = {
	{"value", 'B', "1"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberByteField[] = {
	{"LUniTest/SingleMemberByte;", UnitTest_Attribute_var$64},
	{}
};

$NamedAttribute UnitTest_Attribute_var$65[] = {
	{"value", 'S', "2"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberShortField[] = {
	{"LUniTest/SingleMemberShort;", UnitTest_Attribute_var$65},
	{}
};

$NamedAttribute UnitTest_Attribute_var$66[] = {
	{"value", 'I', "3"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberIntField[] = {
	{"LUniTest/SingleMemberInt;", UnitTest_Attribute_var$66},
	{}
};

$NamedAttribute UnitTest_Attribute_var$67[] = {
	{"value", 'J', "4"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberLongField[] = {
	{"LUniTest/SingleMemberLong;", UnitTest_Attribute_var$67},
	{}
};

$NamedAttribute UnitTest_Attribute_var$68[] = {
	{"value", 'C', "5"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberCharField[] = {
	{"LUniTest/SingleMemberChar;", UnitTest_Attribute_var$68},
	{}
};

$NamedAttribute UnitTest_Attribute_var$69[] = {
	{"value", 'F', "6.0"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberFloatField[] = {
	{"LUniTest/SingleMemberFloat;", UnitTest_Attribute_var$69},
	{}
};

$NamedAttribute UnitTest_Attribute_var$70[] = {
	{"value", 'D', "7.0"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberDoubleField[] = {
	{"LUniTest/SingleMemberDouble;", UnitTest_Attribute_var$70},
	{}
};

$NamedAttribute UnitTest_Attribute_var$71[] = {
	{"value", 'Z', "true"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberBooleanField[] = {
	{"LUniTest/SingleMemberBoolean;", UnitTest_Attribute_var$71},
	{}
};

$NamedAttribute UnitTest_Attribute_var$72[] = {
	{"value", 's', "custom"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberStringField[] = {
	{"LUniTest/SingleMemberString;", UnitTest_Attribute_var$72},
	{}
};

$NamedAttribute UnitTest_Attribute_var$73[] = {
	{"value", 'c', "Ljava/util/Map;"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberClassField[] = {
	{"LUniTest/SingleMemberClass;", UnitTest_Attribute_var$73},
	{}
};

$NamedAttribute UnitTest_Attribute_var$74[] = {
	{"value", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberEnumField[] = {
	{"LUniTest/SingleMemberEnum;", UnitTest_Attribute_var$74},
	{}
};

$NamedAttribute UnitTest_Attribute_var$75[] = {
	{"value", 'B', "1"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberByteOvrdDefField[] = {
	{"LUniTest/SingleMemberByteWithDef;", UnitTest_Attribute_var$75},
	{}
};

$NamedAttribute UnitTest_Attribute_var$76[] = {
	{"value", 'S', "2"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberShortOvrdDefField[] = {
	{"LUniTest/SingleMemberShortWithDef;", UnitTest_Attribute_var$76},
	{}
};

$NamedAttribute UnitTest_Attribute_var$77[] = {
	{"value", 'I', "3"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberIntOvrdDefField[] = {
	{"LUniTest/SingleMemberIntWithDef;", UnitTest_Attribute_var$77},
	{}
};

$NamedAttribute UnitTest_Attribute_var$78[] = {
	{"value", 'J', "4"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberLongOvrdDefField[] = {
	{"LUniTest/SingleMemberLongWithDef;", UnitTest_Attribute_var$78},
	{}
};

$NamedAttribute UnitTest_Attribute_var$79[] = {
	{"value", 'C', "5"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberCharOvrdDefField[] = {
	{"LUniTest/SingleMemberCharWithDef;", UnitTest_Attribute_var$79},
	{}
};

$NamedAttribute UnitTest_Attribute_var$80[] = {
	{"value", 'F', "6.0"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberFloatOvrdDefField[] = {
	{"LUniTest/SingleMemberFloatWithDef;", UnitTest_Attribute_var$80},
	{}
};

$NamedAttribute UnitTest_Attribute_var$81[] = {
	{"value", 'D', "7.0"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberDoubleOvrdDefField[] = {
	{"LUniTest/SingleMemberDoubleWithDef;", UnitTest_Attribute_var$81},
	{}
};

$NamedAttribute UnitTest_Attribute_var$82[] = {
	{"value", 'Z', "true"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberBooleanOvrdDefField[] = {
	{"LUniTest/SingleMemberBooleanWithDef;", UnitTest_Attribute_var$82},
	{}
};

$NamedAttribute UnitTest_Attribute_var$83[] = {
	{"value", 's', "custom"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberStringOvrdDefField[] = {
	{"LUniTest/SingleMemberStringWithDef;", UnitTest_Attribute_var$83},
	{}
};

$NamedAttribute UnitTest_Attribute_var$84[] = {
	{"value", 'c', "Ljava/util/Map;"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberClassOvrdDefField[] = {
	{"LUniTest/SingleMemberClassWithDef;", UnitTest_Attribute_var$84},
	{}
};

$NamedAttribute UnitTest_Attribute_var$85[] = {
	{"value", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberEnumOvrdDefField[] = {
	{"LUniTest/SingleMemberEnumWithDef;", UnitTest_Attribute_var$85},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberByteAcceptDefField[] = {
	{"LUniTest/SingleMemberByteWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberShortAcceptDefField[] = {
	{"LUniTest/SingleMemberShortWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberIntAcceptDefField[] = {
	{"LUniTest/SingleMemberIntWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberLongAcceptDefField[] = {
	{"LUniTest/SingleMemberLongWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberCharAcceptDefField[] = {
	{"LUniTest/SingleMemberCharWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberFloatAcceptDefField[] = {
	{"LUniTest/SingleMemberFloatWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberDoubleAcceptDefField[] = {
	{"LUniTest/SingleMemberDoubleWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberBooleanAcceptDefField[] = {
	{"LUniTest/SingleMemberBooleanWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberStringAcceptDefField[] = {
	{"LUniTest/SingleMemberStringWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberClassAcceptDefField[] = {
	{"LUniTest/SingleMemberClassWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberEnumAcceptDefField[] = {
	{"LUniTest/SingleMemberEnumWithDef;", nullptr},
	{}
};

$Attribute UnitTest_Attribute_var$87[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$86[] = {
	{"value", '[', UnitTest_Attribute_var$87},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberByteArrEmptyField[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$86},
	{}
};

$Attribute UnitTest_Attribute_var$89[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$88[] = {
	{"value", '[', UnitTest_Attribute_var$89},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberShortArrEmptyField[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$88},
	{}
};

$Attribute UnitTest_Attribute_var$91[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$90[] = {
	{"value", '[', UnitTest_Attribute_var$91},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberIntArrEmptyField[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$90},
	{}
};

$Attribute UnitTest_Attribute_var$93[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$92[] = {
	{"value", '[', UnitTest_Attribute_var$93},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberLongArrEmptyField[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$92},
	{}
};

$Attribute UnitTest_Attribute_var$95[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$94[] = {
	{"value", '[', UnitTest_Attribute_var$95},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberCharArrEmptyField[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$94},
	{}
};

$Attribute UnitTest_Attribute_var$97[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$96[] = {
	{"value", '[', UnitTest_Attribute_var$97},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberFloatArrEmptyField[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$96},
	{}
};

$Attribute UnitTest_Attribute_var$99[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$98[] = {
	{"value", '[', UnitTest_Attribute_var$99},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberDoubleArrEmptyField[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$98},
	{}
};

$Attribute UnitTest_Attribute_var$101[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$100[] = {
	{"value", '[', UnitTest_Attribute_var$101},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberBooleanArrEmptyField[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$100},
	{}
};

$Attribute UnitTest_Attribute_var$103[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$102[] = {
	{"value", '[', UnitTest_Attribute_var$103},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberStringArrEmptyField[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$102},
	{}
};

$Attribute UnitTest_Attribute_var$105[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$104[] = {
	{"value", '[', UnitTest_Attribute_var$105},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberClassArrEmptyField[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$104},
	{}
};

$Attribute UnitTest_Attribute_var$107[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$106[] = {
	{"value", '[', UnitTest_Attribute_var$107},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberEnumArrEmptyField[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$106},
	{}
};

$Attribute UnitTest_Attribute_var$109[] = {
	{'B', "1"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$108[] = {
	{"value", '[', UnitTest_Attribute_var$109},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberByteArrOneField[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$108},
	{}
};

$Attribute UnitTest_Attribute_var$111[] = {
	{'S', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$110[] = {
	{"value", '[', UnitTest_Attribute_var$111},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberShortArrOneField[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$110},
	{}
};

$Attribute UnitTest_Attribute_var$113[] = {
	{'I', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$112[] = {
	{"value", '[', UnitTest_Attribute_var$113},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberIntArrOneField[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$112},
	{}
};

$Attribute UnitTest_Attribute_var$115[] = {
	{'J', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$114[] = {
	{"value", '[', UnitTest_Attribute_var$115},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberLongArrOneField[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$114},
	{}
};

$Attribute UnitTest_Attribute_var$117[] = {
	{'C', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$116[] = {
	{"value", '[', UnitTest_Attribute_var$117},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberCharArrOneField[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$116},
	{}
};

$Attribute UnitTest_Attribute_var$119[] = {
	{'F', "6.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$118[] = {
	{"value", '[', UnitTest_Attribute_var$119},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberFloatArrOneField[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$118},
	{}
};

$Attribute UnitTest_Attribute_var$121[] = {
	{'D', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$120[] = {
	{"value", '[', UnitTest_Attribute_var$121},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberDoubleArrOneField[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$120},
	{}
};

$Attribute UnitTest_Attribute_var$123[] = {
	{'Z', "true"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$122[] = {
	{"value", '[', UnitTest_Attribute_var$123},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberBooleanArrOneField[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$122},
	{}
};

$Attribute UnitTest_Attribute_var$125[] = {
	{'s', "custom"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$124[] = {
	{"value", '[', UnitTest_Attribute_var$125},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberStringArrOneField[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$124},
	{}
};

$Attribute UnitTest_Attribute_var$127[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$126[] = {
	{"value", '[', UnitTest_Attribute_var$127},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberClassArrOneField[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$126},
	{}
};

$Attribute UnitTest_Attribute_var$129[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$128[] = {
	{"value", '[', UnitTest_Attribute_var$129},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberEnumArrOneField[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$128},
	{}
};

$Attribute UnitTest_Attribute_var$131[] = {
	{'B', "1"},
	{'B', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$130[] = {
	{"value", '[', UnitTest_Attribute_var$131},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberByteArrTwoField[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$130},
	{}
};

$Attribute UnitTest_Attribute_var$133[] = {
	{'S', "2"},
	{'S', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$132[] = {
	{"value", '[', UnitTest_Attribute_var$133},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberShortArrTwoField[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$132},
	{}
};

$Attribute UnitTest_Attribute_var$135[] = {
	{'I', "3"},
	{'I', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$134[] = {
	{"value", '[', UnitTest_Attribute_var$135},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberIntArrTwoField[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$134},
	{}
};

$Attribute UnitTest_Attribute_var$137[] = {
	{'J', "4"},
	{'J', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$136[] = {
	{"value", '[', UnitTest_Attribute_var$137},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberLongArrTwoField[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$136},
	{}
};

$Attribute UnitTest_Attribute_var$139[] = {
	{'C', "5"},
	{'C', "6"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$138[] = {
	{"value", '[', UnitTest_Attribute_var$139},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberCharArrTwoField[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$138},
	{}
};

$Attribute UnitTest_Attribute_var$141[] = {
	{'F', "6.0"},
	{'F', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$140[] = {
	{"value", '[', UnitTest_Attribute_var$141},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberFloatArrTwoField[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$140},
	{}
};

$Attribute UnitTest_Attribute_var$143[] = {
	{'D', "7.0"},
	{'D', "8.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$142[] = {
	{"value", '[', UnitTest_Attribute_var$143},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberDoubleArrTwoField[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$142},
	{}
};

$Attribute UnitTest_Attribute_var$145[] = {
	{'Z', "true"},
	{'Z', "false"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$144[] = {
	{"value", '[', UnitTest_Attribute_var$145},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberBooleanArrTwoField[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$144},
	{}
};

$Attribute UnitTest_Attribute_var$147[] = {
	{'s', "custom"},
	{'s', "paint"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$146[] = {
	{"value", '[', UnitTest_Attribute_var$147},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberStringArrTwoField[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$146},
	{}
};

$Attribute UnitTest_Attribute_var$149[] = {
	{'c', "Ljava/util/Map;"},
	{'c', "Ljava/util/Set;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$148[] = {
	{"value", '[', UnitTest_Attribute_var$149},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberClassArrTwoField[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$148},
	{}
};

$Attribute UnitTest_Attribute_var$151[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'e', "LUniTest/Stooge; CURLY"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$150[] = {
	{"value", '[', UnitTest_Attribute_var$151},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberEnumArrTwoField[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$150},
	{}
};

$Attribute UnitTest_Attribute_var$153[] = {
	{'B', "1"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$152[] = {
	{"value", '[', UnitTest_Attribute_var$153},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberByteArrOvrdDefField[] = {
	{"LUniTest/SingleMemberByteArrayDef;", UnitTest_Attribute_var$152},
	{}
};

$Attribute UnitTest_Attribute_var$155[] = {
	{'S', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$154[] = {
	{"value", '[', UnitTest_Attribute_var$155},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberShortArrOvrdDefField[] = {
	{"LUniTest/SingleMemberShortArrayDef;", UnitTest_Attribute_var$154},
	{}
};

$Attribute UnitTest_Attribute_var$157[] = {
	{'I', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$156[] = {
	{"value", '[', UnitTest_Attribute_var$157},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberIntArrOvrdDefField[] = {
	{"LUniTest/SingleMemberIntArrayDef;", UnitTest_Attribute_var$156},
	{}
};

$Attribute UnitTest_Attribute_var$159[] = {
	{'J', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$158[] = {
	{"value", '[', UnitTest_Attribute_var$159},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberLongArrOvrdDefField[] = {
	{"LUniTest/SingleMemberLongArrayDef;", UnitTest_Attribute_var$158},
	{}
};

$Attribute UnitTest_Attribute_var$161[] = {
	{'C', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$160[] = {
	{"value", '[', UnitTest_Attribute_var$161},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberCharArrOvrdDefField[] = {
	{"LUniTest/SingleMemberCharArrayDef;", UnitTest_Attribute_var$160},
	{}
};

$Attribute UnitTest_Attribute_var$163[] = {
	{'F', "6.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$162[] = {
	{"value", '[', UnitTest_Attribute_var$163},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberFloatArrOvrdDefField[] = {
	{"LUniTest/SingleMemberFloatArrayDef;", UnitTest_Attribute_var$162},
	{}
};

$Attribute UnitTest_Attribute_var$165[] = {
	{'D', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$164[] = {
	{"value", '[', UnitTest_Attribute_var$165},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberDoubleArrOvrdDefField[] = {
	{"LUniTest/SingleMemberDoubleArrayDef;", UnitTest_Attribute_var$164},
	{}
};

$Attribute UnitTest_Attribute_var$167[] = {
	{'Z', "true"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$166[] = {
	{"value", '[', UnitTest_Attribute_var$167},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberBooleanArrOvrdDefField[] = {
	{"LUniTest/SingleMemberBooleanArrayDef;", UnitTest_Attribute_var$166},
	{}
};

$Attribute UnitTest_Attribute_var$169[] = {
	{'s', "custom"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$168[] = {
	{"value", '[', UnitTest_Attribute_var$169},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberStringArrOvrdDefField[] = {
	{"LUniTest/SingleMemberStringArrayDef;", UnitTest_Attribute_var$168},
	{}
};

$Attribute UnitTest_Attribute_var$171[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$170[] = {
	{"value", '[', UnitTest_Attribute_var$171},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberClassArrOvrdDefField[] = {
	{"LUniTest/SingleMemberClassArrayDef;", UnitTest_Attribute_var$170},
	{}
};

$Attribute UnitTest_Attribute_var$173[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$172[] = {
	{"value", '[', UnitTest_Attribute_var$173},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberEnumArrOvrdDefField[] = {
	{"LUniTest/SingleMemberEnumArrayDef;", UnitTest_Attribute_var$172},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberByteArrAcceptDefField[] = {
	{"LUniTest/SingleMemberByteArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberShortArrAcceptDefField[] = {
	{"LUniTest/SingleMemberShortArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberIntArrAcceptDefField[] = {
	{"LUniTest/SingleMemberIntArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberLongArrAcceptDefField[] = {
	{"LUniTest/SingleMemberLongArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberCharArrAcceptDefField[] = {
	{"LUniTest/SingleMemberCharArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberFloatArrAcceptDefField[] = {
	{"LUniTest/SingleMemberFloatArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberDoubleArrAcceptDefField[] = {
	{"LUniTest/SingleMemberDoubleArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberBooleanArrAcceptDefField[] = {
	{"LUniTest/SingleMemberBooleanArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberStringArrAcceptDefField[] = {
	{"LUniTest/SingleMemberStringArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberClassArrAcceptDefField[] = {
	{"LUniTest/SingleMemberClassArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_FieldAnnotations_SingleMemberEnumArrAcceptDefField[] = {
	{"LUniTest/SingleMemberEnumArrayDef;", nullptr},
	{}
};

$NamedAttribute UnitTest_Attribute_var$176[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$175 = {
"LUniTest/Point;", UnitTest_Attribute_var$176
};

$NamedAttribute UnitTest_Attribute_var$174[] = {
	{"b", 'B', "1"},
	{"s", 'S', "2"},
	{"i", 'I', "3"},
	{"l", 'J', "4"},
	{"c", 'C', "5"},
	{"f", 'F', "6.0"},
	{"d", 'D', "7.0"},
	{"bool", 'Z', "true"},
	{"str", 's', "custom"},
	{"cls", 'c', "Ljava/util/Map;"},
	{"e", 'e', "LUniTest/Stooge; MOE"},
	{"a", '@', &UnitTest_CompoundAttribute_var$175},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$0[] = {
	{"LUniTest/ScalarTypes;", UnitTest_Attribute_var$174},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$1[] = {
	{"LUniTest/ScalarTypesWithDefault;", nullptr},
	{}
};

$NamedAttribute UnitTest_Attribute_var$177[] = {
	{"b", 'B', "1"},
	{"s", 'S', "2"},
	{"i", 'I', "3"},
	{"l", 'J', "4"},
	{"c", 'C', "5"},
	{"f", 'F', "6.0"},
	{"d", 'D', "7.0"},
	{"bool", 'Z', "true"},
	{"str", 's', "custom"},
	{"cls", 'c', "Ljava/util/Map;"},
	{"e", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$2[] = {
	{"LUniTest/ScalarTypesWithDefault;", UnitTest_Attribute_var$177},
	{}
};

$Attribute UnitTest_Attribute_var$179[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$180[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$181[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$182[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$183[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$184[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$185[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$186[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$187[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$188[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$189[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$190[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$178[] = {
	{"b", '[', UnitTest_Attribute_var$179},
	{"s", '[', UnitTest_Attribute_var$180},
	{"i", '[', UnitTest_Attribute_var$181},
	{"l", '[', UnitTest_Attribute_var$182},
	{"c", '[', UnitTest_Attribute_var$183},
	{"f", '[', UnitTest_Attribute_var$184},
	{"d", '[', UnitTest_Attribute_var$185},
	{"bool", '[', UnitTest_Attribute_var$186},
	{"str", '[', UnitTest_Attribute_var$187},
	{"cls", '[', UnitTest_Attribute_var$188},
	{"e", '[', UnitTest_Attribute_var$189},
	{"a", '[', UnitTest_Attribute_var$190},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$3[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$178},
	{}
};

$Attribute UnitTest_Attribute_var$192[] = {
	{'B', "1"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$193[] = {
	{'S', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$194[] = {
	{'I', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$195[] = {
	{'J', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$196[] = {
	{'C', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$197[] = {
	{'F', "6.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$198[] = {
	{'D', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$199[] = {
	{'Z', "true"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$200[] = {
	{'s', "custom"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$201[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$202[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$205[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$204 = {
"LUniTest/Point;", UnitTest_Attribute_var$205
};

$Attribute UnitTest_Attribute_var$203[] = {
	{'@', &UnitTest_CompoundAttribute_var$204},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$191[] = {
	{"b", '[', UnitTest_Attribute_var$192},
	{"s", '[', UnitTest_Attribute_var$193},
	{"i", '[', UnitTest_Attribute_var$194},
	{"l", '[', UnitTest_Attribute_var$195},
	{"c", '[', UnitTest_Attribute_var$196},
	{"f", '[', UnitTest_Attribute_var$197},
	{"d", '[', UnitTest_Attribute_var$198},
	{"bool", '[', UnitTest_Attribute_var$199},
	{"str", '[', UnitTest_Attribute_var$200},
	{"cls", '[', UnitTest_Attribute_var$201},
	{"e", '[', UnitTest_Attribute_var$202},
	{"a", '[', UnitTest_Attribute_var$203},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$4[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$191},
	{}
};

$Attribute UnitTest_Attribute_var$207[] = {
	{'B', "1"},
	{'B', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$208[] = {
	{'S', "2"},
	{'S', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$209[] = {
	{'I', "3"},
	{'I', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$210[] = {
	{'J', "4"},
	{'J', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$211[] = {
	{'C', "5"},
	{'C', "6"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$212[] = {
	{'F', "6.0"},
	{'F', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$213[] = {
	{'D', "7.0"},
	{'D', "8.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$214[] = {
	{'Z', "true"},
	{'Z', "false"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$215[] = {
	{'s', "custom"},
	{'s', "paint"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$216[] = {
	{'c', "Ljava/util/Map;"},
	{'c', "Ljava/util/Set;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$217[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'e', "LUniTest/Stooge; CURLY"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$220[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$219 = {
"LUniTest/Point;", UnitTest_Attribute_var$220
};

$NamedAttribute UnitTest_Attribute_var$222[] = {
	{"x", 'I', "3"},
	{"y", 'I', "4"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$221 = {
"LUniTest/Point;", UnitTest_Attribute_var$222
};

$Attribute UnitTest_Attribute_var$218[] = {
	{'@', &UnitTest_CompoundAttribute_var$219},
	{'@', &UnitTest_CompoundAttribute_var$221},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$206[] = {
	{"b", '[', UnitTest_Attribute_var$207},
	{"s", '[', UnitTest_Attribute_var$208},
	{"i", '[', UnitTest_Attribute_var$209},
	{"l", '[', UnitTest_Attribute_var$210},
	{"c", '[', UnitTest_Attribute_var$211},
	{"f", '[', UnitTest_Attribute_var$212},
	{"d", '[', UnitTest_Attribute_var$213},
	{"bool", '[', UnitTest_Attribute_var$214},
	{"str", '[', UnitTest_Attribute_var$215},
	{"cls", '[', UnitTest_Attribute_var$216},
	{"e", '[', UnitTest_Attribute_var$217},
	{"a", '[', UnitTest_Attribute_var$218},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$5[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$206},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$6[] = {
	{"LUniTest/ArrayTypesWithDefault;", nullptr},
	{}
};

$Attribute UnitTest_Attribute_var$224[] = {
	{'B', "1"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$225[] = {
	{'S', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$226[] = {
	{'I', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$227[] = {
	{'J', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$228[] = {
	{'C', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$229[] = {
	{'F', "6.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$230[] = {
	{'D', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$231[] = {
	{'Z', "true"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$232[] = {
	{'s', "custom"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$233[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$234[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$237[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$236 = {
"LUniTest/Point;", UnitTest_Attribute_var$237
};

$Attribute UnitTest_Attribute_var$235[] = {
	{'@', &UnitTest_CompoundAttribute_var$236},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$223[] = {
	{"b", '[', UnitTest_Attribute_var$224},
	{"s", '[', UnitTest_Attribute_var$225},
	{"i", '[', UnitTest_Attribute_var$226},
	{"l", '[', UnitTest_Attribute_var$227},
	{"c", '[', UnitTest_Attribute_var$228},
	{"f", '[', UnitTest_Attribute_var$229},
	{"d", '[', UnitTest_Attribute_var$230},
	{"bool", '[', UnitTest_Attribute_var$231},
	{"str", '[', UnitTest_Attribute_var$232},
	{"cls", '[', UnitTest_Attribute_var$233},
	{"e", '[', UnitTest_Attribute_var$234},
	{"a", '[', UnitTest_Attribute_var$235},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$7[] = {
	{"LUniTest/ArrayTypesWithDefault;", UnitTest_Attribute_var$223},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$8[] = {
	{"LUniTest/Marker;", nullptr},
	{}
};

$NamedAttribute UnitTest_Attribute_var$238[] = {
	{"value", 'B', "1"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$9[] = {
	{"LUniTest/SingleMemberByte;", UnitTest_Attribute_var$238},
	{}
};

$NamedAttribute UnitTest_Attribute_var$239[] = {
	{"value", 'S', "2"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$10[] = {
	{"LUniTest/SingleMemberShort;", UnitTest_Attribute_var$239},
	{}
};

$NamedAttribute UnitTest_Attribute_var$240[] = {
	{"value", 'I', "3"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$11[] = {
	{"LUniTest/SingleMemberInt;", UnitTest_Attribute_var$240},
	{}
};

$NamedAttribute UnitTest_Attribute_var$241[] = {
	{"value", 'J', "4"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$12[] = {
	{"LUniTest/SingleMemberLong;", UnitTest_Attribute_var$241},
	{}
};

$NamedAttribute UnitTest_Attribute_var$242[] = {
	{"value", 'C', "5"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$13[] = {
	{"LUniTest/SingleMemberChar;", UnitTest_Attribute_var$242},
	{}
};

$NamedAttribute UnitTest_Attribute_var$243[] = {
	{"value", 'F', "6.0"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$14[] = {
	{"LUniTest/SingleMemberFloat;", UnitTest_Attribute_var$243},
	{}
};

$NamedAttribute UnitTest_Attribute_var$244[] = {
	{"value", 'D', "7.0"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$15[] = {
	{"LUniTest/SingleMemberDouble;", UnitTest_Attribute_var$244},
	{}
};

$NamedAttribute UnitTest_Attribute_var$245[] = {
	{"value", 'Z', "true"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$16[] = {
	{"LUniTest/SingleMemberBoolean;", UnitTest_Attribute_var$245},
	{}
};

$NamedAttribute UnitTest_Attribute_var$246[] = {
	{"value", 's', "custom"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$17[] = {
	{"LUniTest/SingleMemberString;", UnitTest_Attribute_var$246},
	{}
};

$NamedAttribute UnitTest_Attribute_var$247[] = {
	{"value", 'c', "Ljava/util/Map;"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$18[] = {
	{"LUniTest/SingleMemberClass;", UnitTest_Attribute_var$247},
	{}
};

$NamedAttribute UnitTest_Attribute_var$248[] = {
	{"value", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$19[] = {
	{"LUniTest/SingleMemberEnum;", UnitTest_Attribute_var$248},
	{}
};

$NamedAttribute UnitTest_Attribute_var$249[] = {
	{"value", 'B', "1"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$20[] = {
	{"LUniTest/SingleMemberByteWithDef;", UnitTest_Attribute_var$249},
	{}
};

$NamedAttribute UnitTest_Attribute_var$250[] = {
	{"value", 'S', "2"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$21[] = {
	{"LUniTest/SingleMemberShortWithDef;", UnitTest_Attribute_var$250},
	{}
};

$NamedAttribute UnitTest_Attribute_var$251[] = {
	{"value", 'I', "3"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$22[] = {
	{"LUniTest/SingleMemberIntWithDef;", UnitTest_Attribute_var$251},
	{}
};

$NamedAttribute UnitTest_Attribute_var$252[] = {
	{"value", 'J', "4"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$23[] = {
	{"LUniTest/SingleMemberLongWithDef;", UnitTest_Attribute_var$252},
	{}
};

$NamedAttribute UnitTest_Attribute_var$253[] = {
	{"value", 'C', "5"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$24[] = {
	{"LUniTest/SingleMemberCharWithDef;", UnitTest_Attribute_var$253},
	{}
};

$NamedAttribute UnitTest_Attribute_var$254[] = {
	{"value", 'F', "6.0"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$25[] = {
	{"LUniTest/SingleMemberFloatWithDef;", UnitTest_Attribute_var$254},
	{}
};

$NamedAttribute UnitTest_Attribute_var$255[] = {
	{"value", 'D', "7.0"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$26[] = {
	{"LUniTest/SingleMemberDoubleWithDef;", UnitTest_Attribute_var$255},
	{}
};

$NamedAttribute UnitTest_Attribute_var$256[] = {
	{"value", 'Z', "true"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$27[] = {
	{"LUniTest/SingleMemberBooleanWithDef;", UnitTest_Attribute_var$256},
	{}
};

$NamedAttribute UnitTest_Attribute_var$257[] = {
	{"value", 's', "custom"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$28[] = {
	{"LUniTest/SingleMemberStringWithDef;", UnitTest_Attribute_var$257},
	{}
};

$NamedAttribute UnitTest_Attribute_var$258[] = {
	{"value", 'c', "Ljava/util/Map;"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$29[] = {
	{"LUniTest/SingleMemberClassWithDef;", UnitTest_Attribute_var$258},
	{}
};

$NamedAttribute UnitTest_Attribute_var$259[] = {
	{"value", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$30[] = {
	{"LUniTest/SingleMemberEnumWithDef;", UnitTest_Attribute_var$259},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$31[] = {
	{"LUniTest/SingleMemberByteWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$32[] = {
	{"LUniTest/SingleMemberShortWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$33[] = {
	{"LUniTest/SingleMemberIntWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$34[] = {
	{"LUniTest/SingleMemberLongWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$35[] = {
	{"LUniTest/SingleMemberCharWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$36[] = {
	{"LUniTest/SingleMemberFloatWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$37[] = {
	{"LUniTest/SingleMemberDoubleWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$38[] = {
	{"LUniTest/SingleMemberBooleanWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$39[] = {
	{"LUniTest/SingleMemberStringWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$40[] = {
	{"LUniTest/SingleMemberClassWithDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$41[] = {
	{"LUniTest/SingleMemberEnumWithDef;", nullptr},
	{}
};

$Attribute UnitTest_Attribute_var$261[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$260[] = {
	{"value", '[', UnitTest_Attribute_var$261},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$42[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$260},
	{}
};

$Attribute UnitTest_Attribute_var$263[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$262[] = {
	{"value", '[', UnitTest_Attribute_var$263},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$43[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$262},
	{}
};

$Attribute UnitTest_Attribute_var$265[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$264[] = {
	{"value", '[', UnitTest_Attribute_var$265},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$44[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$264},
	{}
};

$Attribute UnitTest_Attribute_var$267[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$266[] = {
	{"value", '[', UnitTest_Attribute_var$267},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$45[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$266},
	{}
};

$Attribute UnitTest_Attribute_var$269[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$268[] = {
	{"value", '[', UnitTest_Attribute_var$269},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$46[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$268},
	{}
};

$Attribute UnitTest_Attribute_var$271[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$270[] = {
	{"value", '[', UnitTest_Attribute_var$271},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$47[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$270},
	{}
};

$Attribute UnitTest_Attribute_var$273[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$272[] = {
	{"value", '[', UnitTest_Attribute_var$273},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$48[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$272},
	{}
};

$Attribute UnitTest_Attribute_var$275[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$274[] = {
	{"value", '[', UnitTest_Attribute_var$275},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$49[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$274},
	{}
};

$Attribute UnitTest_Attribute_var$277[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$276[] = {
	{"value", '[', UnitTest_Attribute_var$277},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$50[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$276},
	{}
};

$Attribute UnitTest_Attribute_var$279[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$278[] = {
	{"value", '[', UnitTest_Attribute_var$279},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$51[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$278},
	{}
};

$Attribute UnitTest_Attribute_var$281[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$280[] = {
	{"value", '[', UnitTest_Attribute_var$281},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$52[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$280},
	{}
};

$Attribute UnitTest_Attribute_var$283[] = {
	{'B', "1"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$282[] = {
	{"value", '[', UnitTest_Attribute_var$283},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$53[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$282},
	{}
};

$Attribute UnitTest_Attribute_var$285[] = {
	{'S', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$284[] = {
	{"value", '[', UnitTest_Attribute_var$285},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$54[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$284},
	{}
};

$Attribute UnitTest_Attribute_var$287[] = {
	{'I', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$286[] = {
	{"value", '[', UnitTest_Attribute_var$287},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$55[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$286},
	{}
};

$Attribute UnitTest_Attribute_var$289[] = {
	{'J', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$288[] = {
	{"value", '[', UnitTest_Attribute_var$289},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$56[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$288},
	{}
};

$Attribute UnitTest_Attribute_var$291[] = {
	{'C', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$290[] = {
	{"value", '[', UnitTest_Attribute_var$291},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$57[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$290},
	{}
};

$Attribute UnitTest_Attribute_var$293[] = {
	{'F', "6.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$292[] = {
	{"value", '[', UnitTest_Attribute_var$293},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$58[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$292},
	{}
};

$Attribute UnitTest_Attribute_var$295[] = {
	{'D', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$294[] = {
	{"value", '[', UnitTest_Attribute_var$295},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$59[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$294},
	{}
};

$Attribute UnitTest_Attribute_var$297[] = {
	{'Z', "true"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$296[] = {
	{"value", '[', UnitTest_Attribute_var$297},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$60[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$296},
	{}
};

$Attribute UnitTest_Attribute_var$299[] = {
	{'s', "custom"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$298[] = {
	{"value", '[', UnitTest_Attribute_var$299},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$61[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$298},
	{}
};

$Attribute UnitTest_Attribute_var$301[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$300[] = {
	{"value", '[', UnitTest_Attribute_var$301},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$62[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$300},
	{}
};

$Attribute UnitTest_Attribute_var$303[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$302[] = {
	{"value", '[', UnitTest_Attribute_var$303},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$63[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$302},
	{}
};

$Attribute UnitTest_Attribute_var$305[] = {
	{'B', "1"},
	{'B', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$304[] = {
	{"value", '[', UnitTest_Attribute_var$305},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$64[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$304},
	{}
};

$Attribute UnitTest_Attribute_var$307[] = {
	{'S', "2"},
	{'S', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$306[] = {
	{"value", '[', UnitTest_Attribute_var$307},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$65[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$306},
	{}
};

$Attribute UnitTest_Attribute_var$309[] = {
	{'I', "3"},
	{'I', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$308[] = {
	{"value", '[', UnitTest_Attribute_var$309},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$66[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$308},
	{}
};

$Attribute UnitTest_Attribute_var$311[] = {
	{'J', "4"},
	{'J', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$310[] = {
	{"value", '[', UnitTest_Attribute_var$311},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$67[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$310},
	{}
};

$Attribute UnitTest_Attribute_var$313[] = {
	{'C', "5"},
	{'C', "6"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$312[] = {
	{"value", '[', UnitTest_Attribute_var$313},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$68[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$312},
	{}
};

$Attribute UnitTest_Attribute_var$315[] = {
	{'F', "6.0"},
	{'F', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$314[] = {
	{"value", '[', UnitTest_Attribute_var$315},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$69[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$314},
	{}
};

$Attribute UnitTest_Attribute_var$317[] = {
	{'D', "7.0"},
	{'D', "8.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$316[] = {
	{"value", '[', UnitTest_Attribute_var$317},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$70[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$316},
	{}
};

$Attribute UnitTest_Attribute_var$319[] = {
	{'Z', "true"},
	{'Z', "false"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$318[] = {
	{"value", '[', UnitTest_Attribute_var$319},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$71[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$318},
	{}
};

$Attribute UnitTest_Attribute_var$321[] = {
	{'s', "custom"},
	{'s', "paint"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$320[] = {
	{"value", '[', UnitTest_Attribute_var$321},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$72[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$320},
	{}
};

$Attribute UnitTest_Attribute_var$323[] = {
	{'c', "Ljava/util/Map;"},
	{'c', "Ljava/util/Set;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$322[] = {
	{"value", '[', UnitTest_Attribute_var$323},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$73[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$322},
	{}
};

$Attribute UnitTest_Attribute_var$325[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'e', "LUniTest/Stooge; CURLY"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$324[] = {
	{"value", '[', UnitTest_Attribute_var$325},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$74[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$324},
	{}
};

$Attribute UnitTest_Attribute_var$327[] = {
	{'B', "1"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$326[] = {
	{"value", '[', UnitTest_Attribute_var$327},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$75[] = {
	{"LUniTest/SingleMemberByteArrayDef;", UnitTest_Attribute_var$326},
	{}
};

$Attribute UnitTest_Attribute_var$329[] = {
	{'S', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$328[] = {
	{"value", '[', UnitTest_Attribute_var$329},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$76[] = {
	{"LUniTest/SingleMemberShortArrayDef;", UnitTest_Attribute_var$328},
	{}
};

$Attribute UnitTest_Attribute_var$331[] = {
	{'I', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$330[] = {
	{"value", '[', UnitTest_Attribute_var$331},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$77[] = {
	{"LUniTest/SingleMemberIntArrayDef;", UnitTest_Attribute_var$330},
	{}
};

$Attribute UnitTest_Attribute_var$333[] = {
	{'J', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$332[] = {
	{"value", '[', UnitTest_Attribute_var$333},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$78[] = {
	{"LUniTest/SingleMemberLongArrayDef;", UnitTest_Attribute_var$332},
	{}
};

$Attribute UnitTest_Attribute_var$335[] = {
	{'C', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$334[] = {
	{"value", '[', UnitTest_Attribute_var$335},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$79[] = {
	{"LUniTest/SingleMemberCharArrayDef;", UnitTest_Attribute_var$334},
	{}
};

$Attribute UnitTest_Attribute_var$337[] = {
	{'F', "6.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$336[] = {
	{"value", '[', UnitTest_Attribute_var$337},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$80[] = {
	{"LUniTest/SingleMemberFloatArrayDef;", UnitTest_Attribute_var$336},
	{}
};

$Attribute UnitTest_Attribute_var$339[] = {
	{'D', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$338[] = {
	{"value", '[', UnitTest_Attribute_var$339},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$81[] = {
	{"LUniTest/SingleMemberDoubleArrayDef;", UnitTest_Attribute_var$338},
	{}
};

$Attribute UnitTest_Attribute_var$341[] = {
	{'Z', "true"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$340[] = {
	{"value", '[', UnitTest_Attribute_var$341},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$82[] = {
	{"LUniTest/SingleMemberBooleanArrayDef;", UnitTest_Attribute_var$340},
	{}
};

$Attribute UnitTest_Attribute_var$343[] = {
	{'s', "custom"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$342[] = {
	{"value", '[', UnitTest_Attribute_var$343},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$83[] = {
	{"LUniTest/SingleMemberStringArrayDef;", UnitTest_Attribute_var$342},
	{}
};

$Attribute UnitTest_Attribute_var$345[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$344[] = {
	{"value", '[', UnitTest_Attribute_var$345},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$84[] = {
	{"LUniTest/SingleMemberClassArrayDef;", UnitTest_Attribute_var$344},
	{}
};

$Attribute UnitTest_Attribute_var$347[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$346[] = {
	{"value", '[', UnitTest_Attribute_var$347},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$85[] = {
	{"LUniTest/SingleMemberEnumArrayDef;", UnitTest_Attribute_var$346},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$86[] = {
	{"LUniTest/SingleMemberByteArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$87[] = {
	{"LUniTest/SingleMemberShortArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$88[] = {
	{"LUniTest/SingleMemberIntArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$89[] = {
	{"LUniTest/SingleMemberLongArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$90[] = {
	{"LUniTest/SingleMemberCharArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$91[] = {
	{"LUniTest/SingleMemberFloatArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$92[] = {
	{"LUniTest/SingleMemberDoubleArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$93[] = {
	{"LUniTest/SingleMemberBooleanArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$94[] = {
	{"LUniTest/SingleMemberStringArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$95[] = {
	{"LUniTest/SingleMemberClassArrayDef;", nullptr},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_init$96[] = {
	{"LUniTest/SingleMemberEnumArrayDef;", nullptr},
	{}
};

$NamedAttribute UnitTest_Attribute_var$348[] = {
	{"value", 'Z', "true"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberBoolean97[] = {
	{"LUniTest/SingleMemberBoolean;", UnitTest_Attribute_var$348},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberBooleanAcceptDef98[] = {
	{"LUniTest/SingleMemberBooleanWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberBooleanAcceptDefParam99[] = {
	{"LUniTest/SingleMemberBooleanWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberBooleanArrAcceptDef100[] = {
	{"LUniTest/SingleMemberBooleanArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrAcceptDefParam101[] = {
	{"LUniTest/SingleMemberBooleanArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$350[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$349[] = {
	{"value", '[', UnitTest_Attribute_var$350},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberBooleanArrEmpty102[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$349},
	{}
};

$Attribute UnitTest_Attribute_var$352[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$351[] = {
	{"value", '[', UnitTest_Attribute_var$352},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrEmptyParam103[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$351, 0},
	{}
};

$Attribute UnitTest_Attribute_var$354[] = {
	{'Z', "true"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$353[] = {
	{"value", '[', UnitTest_Attribute_var$354},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberBooleanArrOne104[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$353},
	{}
};

$Attribute UnitTest_Attribute_var$356[] = {
	{'Z', "true"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$355[] = {
	{"value", '[', UnitTest_Attribute_var$356},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrOneParam105[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$355, 0},
	{}
};

$Attribute UnitTest_Attribute_var$358[] = {
	{'Z', "true"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$357[] = {
	{"value", '[', UnitTest_Attribute_var$358},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberBooleanArrOvrdDef106[] = {
	{"LUniTest/SingleMemberBooleanArrayDef;", UnitTest_Attribute_var$357},
	{}
};

$Attribute UnitTest_Attribute_var$360[] = {
	{'Z', "true"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$359[] = {
	{"value", '[', UnitTest_Attribute_var$360},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrOvrdDefParam107[] = {
	{"LUniTest/SingleMemberBooleanArrayDef;", UnitTest_Attribute_var$359, 0},
	{}
};

$Attribute UnitTest_Attribute_var$362[] = {
	{'Z', "true"},
	{'Z', "false"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$361[] = {
	{"value", '[', UnitTest_Attribute_var$362},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberBooleanArrTwo108[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$361},
	{}
};

$Attribute UnitTest_Attribute_var$364[] = {
	{'Z', "true"},
	{'Z', "false"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$363[] = {
	{"value", '[', UnitTest_Attribute_var$364},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrTwoParam109[] = {
	{"LUniTest/SingleMemberBooleanArray;", UnitTest_Attribute_var$363, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$365[] = {
	{"value", 'Z', "true"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberBooleanOvrdDef110[] = {
	{"LUniTest/SingleMemberBooleanWithDef;", UnitTest_Attribute_var$365},
	{}
};

$NamedAttribute UnitTest_Attribute_var$366[] = {
	{"value", 'Z', "true"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberBooleanOvrdDefParam111[] = {
	{"LUniTest/SingleMemberBooleanWithDef;", UnitTest_Attribute_var$366, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$367[] = {
	{"value", 'Z', "true"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberBooleanParam112[] = {
	{"LUniTest/SingleMemberBoolean;", UnitTest_Attribute_var$367, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$368[] = {
	{"value", 'B', "1"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberByte113[] = {
	{"LUniTest/SingleMemberByte;", UnitTest_Attribute_var$368},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberByteAcceptDef114[] = {
	{"LUniTest/SingleMemberByteWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberByteAcceptDefParam115[] = {
	{"LUniTest/SingleMemberByteWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberByteArrAcceptDef116[] = {
	{"LUniTest/SingleMemberByteArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberByteArrAcceptDefParam117[] = {
	{"LUniTest/SingleMemberByteArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$370[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$369[] = {
	{"value", '[', UnitTest_Attribute_var$370},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberByteArrEmpty118[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$369},
	{}
};

$Attribute UnitTest_Attribute_var$372[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$371[] = {
	{"value", '[', UnitTest_Attribute_var$372},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberByteArrEmptyParam119[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$371, 0},
	{}
};

$Attribute UnitTest_Attribute_var$374[] = {
	{'B', "1"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$373[] = {
	{"value", '[', UnitTest_Attribute_var$374},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberByteArrOne120[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$373},
	{}
};

$Attribute UnitTest_Attribute_var$376[] = {
	{'B', "1"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$375[] = {
	{"value", '[', UnitTest_Attribute_var$376},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberByteArrOneParam121[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$375, 0},
	{}
};

$Attribute UnitTest_Attribute_var$378[] = {
	{'B', "1"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$377[] = {
	{"value", '[', UnitTest_Attribute_var$378},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberByteArrOvrdDef122[] = {
	{"LUniTest/SingleMemberByteArrayDef;", UnitTest_Attribute_var$377},
	{}
};

$Attribute UnitTest_Attribute_var$380[] = {
	{'B', "1"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$379[] = {
	{"value", '[', UnitTest_Attribute_var$380},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberByteArrOvrdDefParam123[] = {
	{"LUniTest/SingleMemberByteArrayDef;", UnitTest_Attribute_var$379, 0},
	{}
};

$Attribute UnitTest_Attribute_var$382[] = {
	{'B', "1"},
	{'B', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$381[] = {
	{"value", '[', UnitTest_Attribute_var$382},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberByteArrTwo124[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$381},
	{}
};

$Attribute UnitTest_Attribute_var$384[] = {
	{'B', "1"},
	{'B', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$383[] = {
	{"value", '[', UnitTest_Attribute_var$384},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberByteArrTwoParam125[] = {
	{"LUniTest/SingleMemberByteArray;", UnitTest_Attribute_var$383, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$385[] = {
	{"value", 'B', "1"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberByteOvrdDef126[] = {
	{"LUniTest/SingleMemberByteWithDef;", UnitTest_Attribute_var$385},
	{}
};

$NamedAttribute UnitTest_Attribute_var$386[] = {
	{"value", 'B', "1"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberByteOvrdDefParam127[] = {
	{"LUniTest/SingleMemberByteWithDef;", UnitTest_Attribute_var$386, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$387[] = {
	{"value", 'B', "1"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberByteParam128[] = {
	{"LUniTest/SingleMemberByte;", UnitTest_Attribute_var$387, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$388[] = {
	{"value", 'C', "5"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberChar129[] = {
	{"LUniTest/SingleMemberChar;", UnitTest_Attribute_var$388},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberCharAcceptDef130[] = {
	{"LUniTest/SingleMemberCharWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberCharAcceptDefParam131[] = {
	{"LUniTest/SingleMemberCharWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberCharArrAcceptDef132[] = {
	{"LUniTest/SingleMemberCharArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberCharArrAcceptDefParam133[] = {
	{"LUniTest/SingleMemberCharArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$390[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$389[] = {
	{"value", '[', UnitTest_Attribute_var$390},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberCharArrEmpty134[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$389},
	{}
};

$Attribute UnitTest_Attribute_var$392[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$391[] = {
	{"value", '[', UnitTest_Attribute_var$392},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberCharArrEmptyParam135[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$391, 0},
	{}
};

$Attribute UnitTest_Attribute_var$394[] = {
	{'C', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$393[] = {
	{"value", '[', UnitTest_Attribute_var$394},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberCharArrOne136[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$393},
	{}
};

$Attribute UnitTest_Attribute_var$396[] = {
	{'C', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$395[] = {
	{"value", '[', UnitTest_Attribute_var$396},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberCharArrOneParam137[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$395, 0},
	{}
};

$Attribute UnitTest_Attribute_var$398[] = {
	{'C', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$397[] = {
	{"value", '[', UnitTest_Attribute_var$398},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberCharArrOvrdDef138[] = {
	{"LUniTest/SingleMemberCharArrayDef;", UnitTest_Attribute_var$397},
	{}
};

$Attribute UnitTest_Attribute_var$400[] = {
	{'C', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$399[] = {
	{"value", '[', UnitTest_Attribute_var$400},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberCharArrOvrdDefParam139[] = {
	{"LUniTest/SingleMemberCharArrayDef;", UnitTest_Attribute_var$399, 0},
	{}
};

$Attribute UnitTest_Attribute_var$402[] = {
	{'C', "5"},
	{'C', "6"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$401[] = {
	{"value", '[', UnitTest_Attribute_var$402},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberCharArrTwo140[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$401},
	{}
};

$Attribute UnitTest_Attribute_var$404[] = {
	{'C', "5"},
	{'C', "6"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$403[] = {
	{"value", '[', UnitTest_Attribute_var$404},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberCharArrTwoParam141[] = {
	{"LUniTest/SingleMemberCharArray;", UnitTest_Attribute_var$403, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$405[] = {
	{"value", 'C', "5"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberCharOvrdDef142[] = {
	{"LUniTest/SingleMemberCharWithDef;", UnitTest_Attribute_var$405},
	{}
};

$NamedAttribute UnitTest_Attribute_var$406[] = {
	{"value", 'C', "5"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberCharOvrdDefParam143[] = {
	{"LUniTest/SingleMemberCharWithDef;", UnitTest_Attribute_var$406, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$407[] = {
	{"value", 'C', "5"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberCharParam144[] = {
	{"LUniTest/SingleMemberChar;", UnitTest_Attribute_var$407, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$408[] = {
	{"value", 'c', "Ljava/util/Map;"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberClass145[] = {
	{"LUniTest/SingleMemberClass;", UnitTest_Attribute_var$408},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberClassAcceptDef146[] = {
	{"LUniTest/SingleMemberClassWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberClassAcceptDefParam147[] = {
	{"LUniTest/SingleMemberClassWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberClassArrAcceptDef148[] = {
	{"LUniTest/SingleMemberClassArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberClassArrAcceptDefParam149[] = {
	{"LUniTest/SingleMemberClassArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$410[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$409[] = {
	{"value", '[', UnitTest_Attribute_var$410},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberClassArrEmpty150[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$409},
	{}
};

$Attribute UnitTest_Attribute_var$412[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$411[] = {
	{"value", '[', UnitTest_Attribute_var$412},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberClassArrEmptyParam151[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$411, 0},
	{}
};

$Attribute UnitTest_Attribute_var$414[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$413[] = {
	{"value", '[', UnitTest_Attribute_var$414},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberClassArrOne152[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$413},
	{}
};

$Attribute UnitTest_Attribute_var$416[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$415[] = {
	{"value", '[', UnitTest_Attribute_var$416},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberClassArrOneParam153[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$415, 0},
	{}
};

$Attribute UnitTest_Attribute_var$418[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$417[] = {
	{"value", '[', UnitTest_Attribute_var$418},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberClassArrOvrdDef154[] = {
	{"LUniTest/SingleMemberClassArrayDef;", UnitTest_Attribute_var$417},
	{}
};

$Attribute UnitTest_Attribute_var$420[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$419[] = {
	{"value", '[', UnitTest_Attribute_var$420},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberClassArrOvrdDefParam155[] = {
	{"LUniTest/SingleMemberClassArrayDef;", UnitTest_Attribute_var$419, 0},
	{}
};

$Attribute UnitTest_Attribute_var$422[] = {
	{'c', "Ljava/util/Map;"},
	{'c', "Ljava/util/Set;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$421[] = {
	{"value", '[', UnitTest_Attribute_var$422},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberClassArrTwo156[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$421},
	{}
};

$Attribute UnitTest_Attribute_var$424[] = {
	{'c', "Ljava/util/Map;"},
	{'c', "Ljava/util/Set;"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$423[] = {
	{"value", '[', UnitTest_Attribute_var$424},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberClassArrTwoParam157[] = {
	{"LUniTest/SingleMemberClassArray;", UnitTest_Attribute_var$423, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$425[] = {
	{"value", 'c', "Ljava/util/Map;"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberClassOvrdDef158[] = {
	{"LUniTest/SingleMemberClassWithDef;", UnitTest_Attribute_var$425},
	{}
};

$NamedAttribute UnitTest_Attribute_var$426[] = {
	{"value", 'c', "Ljava/util/Map;"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberClassOvrdDefParam159[] = {
	{"LUniTest/SingleMemberClassWithDef;", UnitTest_Attribute_var$426, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$427[] = {
	{"value", 'c', "Ljava/util/Map;"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberClassParam160[] = {
	{"LUniTest/SingleMemberClass;", UnitTest_Attribute_var$427, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$428[] = {
	{"value", 'D', "7.0"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberDouble161[] = {
	{"LUniTest/SingleMemberDouble;", UnitTest_Attribute_var$428},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberDoubleAcceptDef162[] = {
	{"LUniTest/SingleMemberDoubleWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberDoubleAcceptDefParam163[] = {
	{"LUniTest/SingleMemberDoubleWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberDoubleArrAcceptDef164[] = {
	{"LUniTest/SingleMemberDoubleArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrAcceptDefParam165[] = {
	{"LUniTest/SingleMemberDoubleArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$430[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$429[] = {
	{"value", '[', UnitTest_Attribute_var$430},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberDoubleArrEmpty166[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$429},
	{}
};

$Attribute UnitTest_Attribute_var$432[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$431[] = {
	{"value", '[', UnitTest_Attribute_var$432},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrEmptyParam167[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$431, 0},
	{}
};

$Attribute UnitTest_Attribute_var$434[] = {
	{'D', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$433[] = {
	{"value", '[', UnitTest_Attribute_var$434},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberDoubleArrOne168[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$433},
	{}
};

$Attribute UnitTest_Attribute_var$436[] = {
	{'D', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$435[] = {
	{"value", '[', UnitTest_Attribute_var$436},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrOneParam169[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$435, 0},
	{}
};

$Attribute UnitTest_Attribute_var$438[] = {
	{'D', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$437[] = {
	{"value", '[', UnitTest_Attribute_var$438},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberDoubleArrOvrdDef170[] = {
	{"LUniTest/SingleMemberDoubleArrayDef;", UnitTest_Attribute_var$437},
	{}
};

$Attribute UnitTest_Attribute_var$440[] = {
	{'D', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$439[] = {
	{"value", '[', UnitTest_Attribute_var$440},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrOvrdDefParam171[] = {
	{"LUniTest/SingleMemberDoubleArrayDef;", UnitTest_Attribute_var$439, 0},
	{}
};

$Attribute UnitTest_Attribute_var$442[] = {
	{'D', "7.0"},
	{'D', "8.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$441[] = {
	{"value", '[', UnitTest_Attribute_var$442},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberDoubleArrTwo172[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$441},
	{}
};

$Attribute UnitTest_Attribute_var$444[] = {
	{'D', "7.0"},
	{'D', "8.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$443[] = {
	{"value", '[', UnitTest_Attribute_var$444},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrTwoParam173[] = {
	{"LUniTest/SingleMemberDoubleArray;", UnitTest_Attribute_var$443, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$445[] = {
	{"value", 'D', "7.0"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberDoubleOvrdDef174[] = {
	{"LUniTest/SingleMemberDoubleWithDef;", UnitTest_Attribute_var$445},
	{}
};

$NamedAttribute UnitTest_Attribute_var$446[] = {
	{"value", 'D', "7.0"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberDoubleOvrdDefParam175[] = {
	{"LUniTest/SingleMemberDoubleWithDef;", UnitTest_Attribute_var$446, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$447[] = {
	{"value", 'D', "7.0"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberDoubleParam176[] = {
	{"LUniTest/SingleMemberDouble;", UnitTest_Attribute_var$447, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$448[] = {
	{"value", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberEnum177[] = {
	{"LUniTest/SingleMemberEnum;", UnitTest_Attribute_var$448},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberEnumAcceptDef178[] = {
	{"LUniTest/SingleMemberEnumWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberEnumAcceptDefParam179[] = {
	{"LUniTest/SingleMemberEnumWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberEnumArrAcceptDef180[] = {
	{"LUniTest/SingleMemberEnumArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberEnumArrAcceptDefParam181[] = {
	{"LUniTest/SingleMemberEnumArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$450[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$449[] = {
	{"value", '[', UnitTest_Attribute_var$450},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberEnumArrEmpty182[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$449},
	{}
};

$Attribute UnitTest_Attribute_var$452[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$451[] = {
	{"value", '[', UnitTest_Attribute_var$452},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberEnumArrEmptyParam183[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$451, 0},
	{}
};

$Attribute UnitTest_Attribute_var$454[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$453[] = {
	{"value", '[', UnitTest_Attribute_var$454},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberEnumArrOne184[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$453},
	{}
};

$Attribute UnitTest_Attribute_var$456[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$455[] = {
	{"value", '[', UnitTest_Attribute_var$456},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberEnumArrOneParam185[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$455, 0},
	{}
};

$Attribute UnitTest_Attribute_var$458[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$457[] = {
	{"value", '[', UnitTest_Attribute_var$458},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberEnumArrOvrdDef186[] = {
	{"LUniTest/SingleMemberEnumArrayDef;", UnitTest_Attribute_var$457},
	{}
};

$Attribute UnitTest_Attribute_var$460[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$459[] = {
	{"value", '[', UnitTest_Attribute_var$460},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberEnumArrOvrdDefParam187[] = {
	{"LUniTest/SingleMemberEnumArrayDef;", UnitTest_Attribute_var$459, 0},
	{}
};

$Attribute UnitTest_Attribute_var$462[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'e', "LUniTest/Stooge; CURLY"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$461[] = {
	{"value", '[', UnitTest_Attribute_var$462},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberEnumArrTwo188[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$461},
	{}
};

$Attribute UnitTest_Attribute_var$464[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'e', "LUniTest/Stooge; CURLY"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$463[] = {
	{"value", '[', UnitTest_Attribute_var$464},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberEnumArrTwoParam189[] = {
	{"LUniTest/SingleMemberEnumArray;", UnitTest_Attribute_var$463, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$465[] = {
	{"value", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberEnumOvrdDef190[] = {
	{"LUniTest/SingleMemberEnumWithDef;", UnitTest_Attribute_var$465},
	{}
};

$NamedAttribute UnitTest_Attribute_var$466[] = {
	{"value", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberEnumOvrdDefParam191[] = {
	{"LUniTest/SingleMemberEnumWithDef;", UnitTest_Attribute_var$466, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$467[] = {
	{"value", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberEnumParam192[] = {
	{"LUniTest/SingleMemberEnum;", UnitTest_Attribute_var$467, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$468[] = {
	{"value", 'F', "6.0"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberFloat193[] = {
	{"LUniTest/SingleMemberFloat;", UnitTest_Attribute_var$468},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberFloatAcceptDef194[] = {
	{"LUniTest/SingleMemberFloatWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberFloatAcceptDefParam195[] = {
	{"LUniTest/SingleMemberFloatWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberFloatArrAcceptDef196[] = {
	{"LUniTest/SingleMemberFloatArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberFloatArrAcceptDefParam197[] = {
	{"LUniTest/SingleMemberFloatArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$470[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$469[] = {
	{"value", '[', UnitTest_Attribute_var$470},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberFloatArrEmpty198[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$469},
	{}
};

$Attribute UnitTest_Attribute_var$472[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$471[] = {
	{"value", '[', UnitTest_Attribute_var$472},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberFloatArrEmptyParam199[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$471, 0},
	{}
};

$Attribute UnitTest_Attribute_var$474[] = {
	{'F', "6.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$473[] = {
	{"value", '[', UnitTest_Attribute_var$474},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberFloatArrOne200[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$473},
	{}
};

$Attribute UnitTest_Attribute_var$476[] = {
	{'F', "6.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$475[] = {
	{"value", '[', UnitTest_Attribute_var$476},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberFloatArrOneParam201[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$475, 0},
	{}
};

$Attribute UnitTest_Attribute_var$478[] = {
	{'F', "6.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$477[] = {
	{"value", '[', UnitTest_Attribute_var$478},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberFloatArrOvrdDef202[] = {
	{"LUniTest/SingleMemberFloatArrayDef;", UnitTest_Attribute_var$477},
	{}
};

$Attribute UnitTest_Attribute_var$480[] = {
	{'F', "6.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$479[] = {
	{"value", '[', UnitTest_Attribute_var$480},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberFloatArrOvrdDefParam203[] = {
	{"LUniTest/SingleMemberFloatArrayDef;", UnitTest_Attribute_var$479, 0},
	{}
};

$Attribute UnitTest_Attribute_var$482[] = {
	{'F', "6.0"},
	{'F', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$481[] = {
	{"value", '[', UnitTest_Attribute_var$482},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberFloatArrTwo204[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$481},
	{}
};

$Attribute UnitTest_Attribute_var$484[] = {
	{'F', "6.0"},
	{'F', "7.0"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$483[] = {
	{"value", '[', UnitTest_Attribute_var$484},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberFloatArrTwoParam205[] = {
	{"LUniTest/SingleMemberFloatArray;", UnitTest_Attribute_var$483, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$485[] = {
	{"value", 'F', "6.0"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberFloatOvrdDef206[] = {
	{"LUniTest/SingleMemberFloatWithDef;", UnitTest_Attribute_var$485},
	{}
};

$NamedAttribute UnitTest_Attribute_var$486[] = {
	{"value", 'F', "6.0"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberFloatOvrdDefParam207[] = {
	{"LUniTest/SingleMemberFloatWithDef;", UnitTest_Attribute_var$486, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$487[] = {
	{"value", 'F', "6.0"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberFloatParam208[] = {
	{"LUniTest/SingleMemberFloat;", UnitTest_Attribute_var$487, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$488[] = {
	{"value", 'I', "3"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberInt209[] = {
	{"LUniTest/SingleMemberInt;", UnitTest_Attribute_var$488},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberIntAcceptDef210[] = {
	{"LUniTest/SingleMemberIntWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberIntAcceptDefParam211[] = {
	{"LUniTest/SingleMemberIntWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberIntArrAcceptDef212[] = {
	{"LUniTest/SingleMemberIntArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberIntArrAcceptDefParam213[] = {
	{"LUniTest/SingleMemberIntArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$490[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$489[] = {
	{"value", '[', UnitTest_Attribute_var$490},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberIntArrEmpty214[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$489},
	{}
};

$Attribute UnitTest_Attribute_var$492[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$491[] = {
	{"value", '[', UnitTest_Attribute_var$492},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberIntArrEmptyParam215[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$491, 0},
	{}
};

$Attribute UnitTest_Attribute_var$494[] = {
	{'I', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$493[] = {
	{"value", '[', UnitTest_Attribute_var$494},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberIntArrOne216[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$493},
	{}
};

$Attribute UnitTest_Attribute_var$496[] = {
	{'I', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$495[] = {
	{"value", '[', UnitTest_Attribute_var$496},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberIntArrOneParam217[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$495, 0},
	{}
};

$Attribute UnitTest_Attribute_var$498[] = {
	{'I', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$497[] = {
	{"value", '[', UnitTest_Attribute_var$498},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberIntArrOvrdDef218[] = {
	{"LUniTest/SingleMemberIntArrayDef;", UnitTest_Attribute_var$497},
	{}
};

$Attribute UnitTest_Attribute_var$500[] = {
	{'I', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$499[] = {
	{"value", '[', UnitTest_Attribute_var$500},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberIntArrOvrdDefParam219[] = {
	{"LUniTest/SingleMemberIntArrayDef;", UnitTest_Attribute_var$499, 0},
	{}
};

$Attribute UnitTest_Attribute_var$502[] = {
	{'I', "3"},
	{'I', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$501[] = {
	{"value", '[', UnitTest_Attribute_var$502},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberIntArrTwo220[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$501},
	{}
};

$Attribute UnitTest_Attribute_var$504[] = {
	{'I', "3"},
	{'I', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$503[] = {
	{"value", '[', UnitTest_Attribute_var$504},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberIntArrTwoParam221[] = {
	{"LUniTest/SingleMemberIntArray;", UnitTest_Attribute_var$503, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$505[] = {
	{"value", 'I', "3"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberIntOvrdDef222[] = {
	{"LUniTest/SingleMemberIntWithDef;", UnitTest_Attribute_var$505},
	{}
};

$NamedAttribute UnitTest_Attribute_var$506[] = {
	{"value", 'I', "3"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberIntOvrdDefParam223[] = {
	{"LUniTest/SingleMemberIntWithDef;", UnitTest_Attribute_var$506, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$507[] = {
	{"value", 'I', "3"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberIntParam224[] = {
	{"LUniTest/SingleMemberInt;", UnitTest_Attribute_var$507, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$508[] = {
	{"value", 'J', "4"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberLong225[] = {
	{"LUniTest/SingleMemberLong;", UnitTest_Attribute_var$508},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberLongAcceptDef226[] = {
	{"LUniTest/SingleMemberLongWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberLongAcceptDefParam227[] = {
	{"LUniTest/SingleMemberLongWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberLongArrAcceptDef228[] = {
	{"LUniTest/SingleMemberLongArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberLongArrAcceptDefParam229[] = {
	{"LUniTest/SingleMemberLongArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$510[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$509[] = {
	{"value", '[', UnitTest_Attribute_var$510},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberLongArrEmpty230[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$509},
	{}
};

$Attribute UnitTest_Attribute_var$512[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$511[] = {
	{"value", '[', UnitTest_Attribute_var$512},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberLongArrEmptyParam231[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$511, 0},
	{}
};

$Attribute UnitTest_Attribute_var$514[] = {
	{'J', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$513[] = {
	{"value", '[', UnitTest_Attribute_var$514},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberLongArrOne232[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$513},
	{}
};

$Attribute UnitTest_Attribute_var$516[] = {
	{'J', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$515[] = {
	{"value", '[', UnitTest_Attribute_var$516},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberLongArrOneParam233[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$515, 0},
	{}
};

$Attribute UnitTest_Attribute_var$518[] = {
	{'J', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$517[] = {
	{"value", '[', UnitTest_Attribute_var$518},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberLongArrOvrdDef234[] = {
	{"LUniTest/SingleMemberLongArrayDef;", UnitTest_Attribute_var$517},
	{}
};

$Attribute UnitTest_Attribute_var$520[] = {
	{'J', "4"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$519[] = {
	{"value", '[', UnitTest_Attribute_var$520},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberLongArrOvrdDefParam235[] = {
	{"LUniTest/SingleMemberLongArrayDef;", UnitTest_Attribute_var$519, 0},
	{}
};

$Attribute UnitTest_Attribute_var$522[] = {
	{'J', "4"},
	{'J', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$521[] = {
	{"value", '[', UnitTest_Attribute_var$522},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberLongArrTwo236[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$521},
	{}
};

$Attribute UnitTest_Attribute_var$524[] = {
	{'J', "4"},
	{'J', "5"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$523[] = {
	{"value", '[', UnitTest_Attribute_var$524},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberLongArrTwoParam237[] = {
	{"LUniTest/SingleMemberLongArray;", UnitTest_Attribute_var$523, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$525[] = {
	{"value", 'J', "4"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberLongOvrdDef238[] = {
	{"LUniTest/SingleMemberLongWithDef;", UnitTest_Attribute_var$525},
	{}
};

$NamedAttribute UnitTest_Attribute_var$526[] = {
	{"value", 'J', "4"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberLongOvrdDefParam239[] = {
	{"LUniTest/SingleMemberLongWithDef;", UnitTest_Attribute_var$526, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$527[] = {
	{"value", 'J', "4"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberLongParam240[] = {
	{"LUniTest/SingleMemberLong;", UnitTest_Attribute_var$527, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$528[] = {
	{"value", 'S', "2"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberShort241[] = {
	{"LUniTest/SingleMemberShort;", UnitTest_Attribute_var$528},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberShortAcceptDef242[] = {
	{"LUniTest/SingleMemberShortWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberShortAcceptDefParam243[] = {
	{"LUniTest/SingleMemberShortWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberShortArrAcceptDef244[] = {
	{"LUniTest/SingleMemberShortArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberShortArrAcceptDefParam245[] = {
	{"LUniTest/SingleMemberShortArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$530[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$529[] = {
	{"value", '[', UnitTest_Attribute_var$530},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberShortArrEmpty246[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$529},
	{}
};

$Attribute UnitTest_Attribute_var$532[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$531[] = {
	{"value", '[', UnitTest_Attribute_var$532},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberShortArrEmptyParam247[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$531, 0},
	{}
};

$Attribute UnitTest_Attribute_var$534[] = {
	{'S', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$533[] = {
	{"value", '[', UnitTest_Attribute_var$534},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberShortArrOne248[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$533},
	{}
};

$Attribute UnitTest_Attribute_var$536[] = {
	{'S', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$535[] = {
	{"value", '[', UnitTest_Attribute_var$536},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberShortArrOneParam249[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$535, 0},
	{}
};

$Attribute UnitTest_Attribute_var$538[] = {
	{'S', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$537[] = {
	{"value", '[', UnitTest_Attribute_var$538},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberShortArrOvrdDef250[] = {
	{"LUniTest/SingleMemberShortArrayDef;", UnitTest_Attribute_var$537},
	{}
};

$Attribute UnitTest_Attribute_var$540[] = {
	{'S', "2"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$539[] = {
	{"value", '[', UnitTest_Attribute_var$540},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberShortArrOvrdDefParam251[] = {
	{"LUniTest/SingleMemberShortArrayDef;", UnitTest_Attribute_var$539, 0},
	{}
};

$Attribute UnitTest_Attribute_var$542[] = {
	{'S', "2"},
	{'S', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$541[] = {
	{"value", '[', UnitTest_Attribute_var$542},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberShortArrTwo252[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$541},
	{}
};

$Attribute UnitTest_Attribute_var$544[] = {
	{'S', "2"},
	{'S', "3"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$543[] = {
	{"value", '[', UnitTest_Attribute_var$544},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberShortArrTwoParam253[] = {
	{"LUniTest/SingleMemberShortArray;", UnitTest_Attribute_var$543, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$545[] = {
	{"value", 'S', "2"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberShortOvrdDef254[] = {
	{"LUniTest/SingleMemberShortWithDef;", UnitTest_Attribute_var$545},
	{}
};

$NamedAttribute UnitTest_Attribute_var$546[] = {
	{"value", 'S', "2"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberShortOvrdDefParam255[] = {
	{"LUniTest/SingleMemberShortWithDef;", UnitTest_Attribute_var$546, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$547[] = {
	{"value", 'S', "2"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberShortParam256[] = {
	{"LUniTest/SingleMemberShort;", UnitTest_Attribute_var$547, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$548[] = {
	{"value", 's', "custom"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberString257[] = {
	{"LUniTest/SingleMemberString;", UnitTest_Attribute_var$548},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberStringAcceptDef258[] = {
	{"LUniTest/SingleMemberStringWithDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberStringAcceptDefParam259[] = {
	{"LUniTest/SingleMemberStringWithDef;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberStringArrAcceptDef260[] = {
	{"LUniTest/SingleMemberStringArrayDef;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberStringArrAcceptDefParam261[] = {
	{"LUniTest/SingleMemberStringArrayDef;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$550[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$549[] = {
	{"value", '[', UnitTest_Attribute_var$550},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberStringArrEmpty262[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$549},
	{}
};

$Attribute UnitTest_Attribute_var$552[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$551[] = {
	{"value", '[', UnitTest_Attribute_var$552},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberStringArrEmptyParam263[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$551, 0},
	{}
};

$Attribute UnitTest_Attribute_var$554[] = {
	{'s', "custom"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$553[] = {
	{"value", '[', UnitTest_Attribute_var$554},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberStringArrOne264[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$553},
	{}
};

$Attribute UnitTest_Attribute_var$556[] = {
	{'s', "custom"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$555[] = {
	{"value", '[', UnitTest_Attribute_var$556},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberStringArrOneParam265[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$555, 0},
	{}
};

$Attribute UnitTest_Attribute_var$558[] = {
	{'s', "custom"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$557[] = {
	{"value", '[', UnitTest_Attribute_var$558},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberStringArrOvrdDef266[] = {
	{"LUniTest/SingleMemberStringArrayDef;", UnitTest_Attribute_var$557},
	{}
};

$Attribute UnitTest_Attribute_var$560[] = {
	{'s', "custom"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$559[] = {
	{"value", '[', UnitTest_Attribute_var$560},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberStringArrOvrdDefParam267[] = {
	{"LUniTest/SingleMemberStringArrayDef;", UnitTest_Attribute_var$559, 0},
	{}
};

$Attribute UnitTest_Attribute_var$562[] = {
	{'s', "custom"},
	{'s', "paint"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$561[] = {
	{"value", '[', UnitTest_Attribute_var$562},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberStringArrTwo268[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$561},
	{}
};

$Attribute UnitTest_Attribute_var$564[] = {
	{'s', "custom"},
	{'s', "paint"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$563[] = {
	{"value", '[', UnitTest_Attribute_var$564},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberStringArrTwoParam269[] = {
	{"LUniTest/SingleMemberStringArray;", UnitTest_Attribute_var$563, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$565[] = {
	{"value", 's', "custom"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_SingleMemberStringOvrdDef270[] = {
	{"LUniTest/SingleMemberStringWithDef;", UnitTest_Attribute_var$565},
	{}
};

$NamedAttribute UnitTest_Attribute_var$566[] = {
	{"value", 's', "custom"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberStringOvrdDefParam271[] = {
	{"LUniTest/SingleMemberStringWithDef;", UnitTest_Attribute_var$566, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$567[] = {
	{"value", 's', "custom"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_SingleMemberStringParam272[] = {
	{"LUniTest/SingleMemberString;", UnitTest_Attribute_var$567, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_arrayTypesAcceptDefaultMethod273[] = {
	{"LUniTest/ArrayTypesWithDefault;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_arrayTypesAcceptDefaultParam274[] = {
	{"LUniTest/ArrayTypesWithDefault;", nullptr, 0},
	{}
};

$Attribute UnitTest_Attribute_var$569[] = {
	{'B', "1"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$570[] = {
	{'S', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$571[] = {
	{'I', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$572[] = {
	{'J', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$573[] = {
	{'C', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$574[] = {
	{'F', "6.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$575[] = {
	{'D', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$576[] = {
	{'Z', "true"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$577[] = {
	{'s', "custom"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$578[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$579[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$582[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$581 = {
"LUniTest/Point;", UnitTest_Attribute_var$582
};

$Attribute UnitTest_Attribute_var$580[] = {
	{'@', &UnitTest_CompoundAttribute_var$581},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$568[] = {
	{"b", '[', UnitTest_Attribute_var$569},
	{"s", '[', UnitTest_Attribute_var$570},
	{"i", '[', UnitTest_Attribute_var$571},
	{"l", '[', UnitTest_Attribute_var$572},
	{"c", '[', UnitTest_Attribute_var$573},
	{"f", '[', UnitTest_Attribute_var$574},
	{"d", '[', UnitTest_Attribute_var$575},
	{"bool", '[', UnitTest_Attribute_var$576},
	{"str", '[', UnitTest_Attribute_var$577},
	{"cls", '[', UnitTest_Attribute_var$578},
	{"e", '[', UnitTest_Attribute_var$579},
	{"a", '[', UnitTest_Attribute_var$580},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_arrayTypesOverrideDefaultMethod275[] = {
	{"LUniTest/ArrayTypesWithDefault;", UnitTest_Attribute_var$568},
	{}
};

$Attribute UnitTest_Attribute_var$584[] = {
	{'B', "1"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$585[] = {
	{'S', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$586[] = {
	{'I', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$587[] = {
	{'J', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$588[] = {
	{'C', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$589[] = {
	{'F', "6.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$590[] = {
	{'D', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$591[] = {
	{'Z', "true"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$592[] = {
	{'s', "custom"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$593[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$594[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$597[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$596 = {
"LUniTest/Point;", UnitTest_Attribute_var$597
};

$Attribute UnitTest_Attribute_var$595[] = {
	{'@', &UnitTest_CompoundAttribute_var$596},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$583[] = {
	{"b", '[', UnitTest_Attribute_var$584},
	{"s", '[', UnitTest_Attribute_var$585},
	{"i", '[', UnitTest_Attribute_var$586},
	{"l", '[', UnitTest_Attribute_var$587},
	{"c", '[', UnitTest_Attribute_var$588},
	{"f", '[', UnitTest_Attribute_var$589},
	{"d", '[', UnitTest_Attribute_var$590},
	{"bool", '[', UnitTest_Attribute_var$591},
	{"str", '[', UnitTest_Attribute_var$592},
	{"cls", '[', UnitTest_Attribute_var$593},
	{"e", '[', UnitTest_Attribute_var$594},
	{"a", '[', UnitTest_Attribute_var$595},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_arrayTypesOverrideDefaultParam276[] = {
	{"LUniTest/ArrayTypesWithDefault;", UnitTest_Attribute_var$583, 0},
	{}
};

$Attribute UnitTest_Attribute_var$599[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$600[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$601[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$602[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$603[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$604[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$605[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$606[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$607[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$608[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$609[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$610[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$598[] = {
	{"b", '[', UnitTest_Attribute_var$599},
	{"s", '[', UnitTest_Attribute_var$600},
	{"i", '[', UnitTest_Attribute_var$601},
	{"l", '[', UnitTest_Attribute_var$602},
	{"c", '[', UnitTest_Attribute_var$603},
	{"f", '[', UnitTest_Attribute_var$604},
	{"d", '[', UnitTest_Attribute_var$605},
	{"bool", '[', UnitTest_Attribute_var$606},
	{"str", '[', UnitTest_Attribute_var$607},
	{"cls", '[', UnitTest_Attribute_var$608},
	{"e", '[', UnitTest_Attribute_var$609},
	{"a", '[', UnitTest_Attribute_var$610},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_emptyArrayTypesMethod574[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$598},
	{}
};

$Attribute UnitTest_Attribute_var$612[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$613[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$614[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$615[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$616[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$617[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$618[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$619[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$620[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$621[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$622[] = {
	{'-'}
};

$Attribute UnitTest_Attribute_var$623[] = {
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$611[] = {
	{"b", '[', UnitTest_Attribute_var$612},
	{"s", '[', UnitTest_Attribute_var$613},
	{"i", '[', UnitTest_Attribute_var$614},
	{"l", '[', UnitTest_Attribute_var$615},
	{"c", '[', UnitTest_Attribute_var$616},
	{"f", '[', UnitTest_Attribute_var$617},
	{"d", '[', UnitTest_Attribute_var$618},
	{"bool", '[', UnitTest_Attribute_var$619},
	{"str", '[', UnitTest_Attribute_var$620},
	{"cls", '[', UnitTest_Attribute_var$621},
	{"e", '[', UnitTest_Attribute_var$622},
	{"a", '[', UnitTest_Attribute_var$623},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_emptyArrayTypesParam575[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$611, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_markerMethod578[] = {
	{"LUniTest/Marker;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_markerParam579[] = {
	{"LUniTest/Marker;", nullptr, 0},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_scalarTypesAcceptDefaultMethod580[] = {
	{"LUniTest/ScalarTypesWithDefault;", nullptr},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_scalarTypesAcceptDefaultParam581[] = {
	{"LUniTest/ScalarTypesWithDefault;", nullptr, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$626[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$625 = {
"LUniTest/Point;", UnitTest_Attribute_var$626
};

$NamedAttribute UnitTest_Attribute_var$624[] = {
	{"b", 'B', "1"},
	{"s", 'S', "2"},
	{"i", 'I', "3"},
	{"l", 'J', "4"},
	{"c", 'C', "5"},
	{"f", 'F', "6.0"},
	{"d", 'D', "7.0"},
	{"bool", 'Z', "true"},
	{"str", 's', "custom"},
	{"cls", 'c', "Ljava/util/Map;"},
	{"e", 'e', "LUniTest/Stooge; MOE"},
	{"a", '@', &UnitTest_CompoundAttribute_var$625},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_scalarTypesMethod582[] = {
	{"LUniTest/ScalarTypes;", UnitTest_Attribute_var$624},
	{}
};

$NamedAttribute UnitTest_Attribute_var$627[] = {
	{"b", 'B', "1"},
	{"s", 'S', "2"},
	{"i", 'I', "3"},
	{"l", 'J', "4"},
	{"c", 'C', "5"},
	{"f", 'F', "6.0"},
	{"d", 'D', "7.0"},
	{"bool", 'Z', "true"},
	{"str", 's', "custom"},
	{"cls", 'c', "Ljava/util/Map;"},
	{"e", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_scalarTypesOverrideDefaultMethod583[] = {
	{"LUniTest/ScalarTypesWithDefault;", UnitTest_Attribute_var$627},
	{}
};

$NamedAttribute UnitTest_Attribute_var$628[] = {
	{"b", 'B', "1"},
	{"s", 'S', "2"},
	{"i", 'I', "3"},
	{"l", 'J', "4"},
	{"c", 'C', "5"},
	{"f", 'F', "6.0"},
	{"d", 'D', "7.0"},
	{"bool", 'Z', "true"},
	{"str", 's', "custom"},
	{"cls", 'c', "Ljava/util/Map;"},
	{"e", 'e', "LUniTest/Stooge; MOE"},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_scalarTypesOverrideDefaultParam584[] = {
	{"LUniTest/ScalarTypesWithDefault;", UnitTest_Attribute_var$628, 0},
	{}
};

$NamedAttribute UnitTest_Attribute_var$631[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$630 = {
"LUniTest/Point;", UnitTest_Attribute_var$631
};

$NamedAttribute UnitTest_Attribute_var$629[] = {
	{"b", 'B', "1"},
	{"s", 'S', "2"},
	{"i", 'I', "3"},
	{"l", 'J', "4"},
	{"c", 'C', "5"},
	{"f", 'F', "6.0"},
	{"d", 'D', "7.0"},
	{"bool", 'Z', "true"},
	{"str", 's', "custom"},
	{"cls", 'c', "Ljava/util/Map;"},
	{"e", 'e', "LUniTest/Stooge; MOE"},
	{"a", '@', &UnitTest_CompoundAttribute_var$630},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_scalarTypesParam585[] = {
	{"LUniTest/ScalarTypes;", UnitTest_Attribute_var$629, 0},
	{}
};

$Attribute UnitTest_Attribute_var$633[] = {
	{'B', "1"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$634[] = {
	{'S', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$635[] = {
	{'I', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$636[] = {
	{'J', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$637[] = {
	{'C', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$638[] = {
	{'F', "6.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$639[] = {
	{'D', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$640[] = {
	{'Z', "true"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$641[] = {
	{'s', "custom"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$642[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$643[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$646[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$645 = {
"LUniTest/Point;", UnitTest_Attribute_var$646
};

$Attribute UnitTest_Attribute_var$644[] = {
	{'@', &UnitTest_CompoundAttribute_var$645},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$632[] = {
	{"b", '[', UnitTest_Attribute_var$633},
	{"s", '[', UnitTest_Attribute_var$634},
	{"i", '[', UnitTest_Attribute_var$635},
	{"l", '[', UnitTest_Attribute_var$636},
	{"c", '[', UnitTest_Attribute_var$637},
	{"f", '[', UnitTest_Attribute_var$638},
	{"d", '[', UnitTest_Attribute_var$639},
	{"bool", '[', UnitTest_Attribute_var$640},
	{"str", '[', UnitTest_Attribute_var$641},
	{"cls", '[', UnitTest_Attribute_var$642},
	{"e", '[', UnitTest_Attribute_var$643},
	{"a", '[', UnitTest_Attribute_var$644},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_singleElementArrayTypesMethod586[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$632},
	{}
};

$Attribute UnitTest_Attribute_var$648[] = {
	{'B', "1"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$649[] = {
	{'S', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$650[] = {
	{'I', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$651[] = {
	{'J', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$652[] = {
	{'C', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$653[] = {
	{'F', "6.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$654[] = {
	{'D', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$655[] = {
	{'Z', "true"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$656[] = {
	{'s', "custom"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$657[] = {
	{'c', "Ljava/util/Map;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$658[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$661[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$660 = {
"LUniTest/Point;", UnitTest_Attribute_var$661
};

$Attribute UnitTest_Attribute_var$659[] = {
	{'@', &UnitTest_CompoundAttribute_var$660},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$647[] = {
	{"b", '[', UnitTest_Attribute_var$648},
	{"s", '[', UnitTest_Attribute_var$649},
	{"i", '[', UnitTest_Attribute_var$650},
	{"l", '[', UnitTest_Attribute_var$651},
	{"c", '[', UnitTest_Attribute_var$652},
	{"f", '[', UnitTest_Attribute_var$653},
	{"d", '[', UnitTest_Attribute_var$654},
	{"bool", '[', UnitTest_Attribute_var$655},
	{"str", '[', UnitTest_Attribute_var$656},
	{"cls", '[', UnitTest_Attribute_var$657},
	{"e", '[', UnitTest_Attribute_var$658},
	{"a", '[', UnitTest_Attribute_var$659},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_singleElementArrayTypesParam587[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$647, 0},
	{}
};

$Attribute UnitTest_Attribute_var$663[] = {
	{'B', "1"},
	{'B', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$664[] = {
	{'S', "2"},
	{'S', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$665[] = {
	{'I', "3"},
	{'I', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$666[] = {
	{'J', "4"},
	{'J', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$667[] = {
	{'C', "5"},
	{'C', "6"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$668[] = {
	{'F', "6.0"},
	{'F', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$669[] = {
	{'D', "7.0"},
	{'D', "8.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$670[] = {
	{'Z', "true"},
	{'Z', "false"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$671[] = {
	{'s', "custom"},
	{'s', "paint"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$672[] = {
	{'c', "Ljava/util/Map;"},
	{'c', "Ljava/util/Set;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$673[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'e', "LUniTest/Stooge; CURLY"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$676[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$675 = {
"LUniTest/Point;", UnitTest_Attribute_var$676
};

$NamedAttribute UnitTest_Attribute_var$678[] = {
	{"x", 'I', "3"},
	{"y", 'I', "4"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$677 = {
"LUniTest/Point;", UnitTest_Attribute_var$678
};

$Attribute UnitTest_Attribute_var$674[] = {
	{'@', &UnitTest_CompoundAttribute_var$675},
	{'@', &UnitTest_CompoundAttribute_var$677},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$662[] = {
	{"b", '[', UnitTest_Attribute_var$663},
	{"s", '[', UnitTest_Attribute_var$664},
	{"i", '[', UnitTest_Attribute_var$665},
	{"l", '[', UnitTest_Attribute_var$666},
	{"c", '[', UnitTest_Attribute_var$667},
	{"f", '[', UnitTest_Attribute_var$668},
	{"d", '[', UnitTest_Attribute_var$669},
	{"bool", '[', UnitTest_Attribute_var$670},
	{"str", '[', UnitTest_Attribute_var$671},
	{"cls", '[', UnitTest_Attribute_var$672},
	{"e", '[', UnitTest_Attribute_var$673},
	{"a", '[', UnitTest_Attribute_var$674},
	{}
};

$CompoundAttribute _UnitTest_MethodAnnotations_twoElementArrayTypesMethod588[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$662},
	{}
};

$Attribute UnitTest_Attribute_var$680[] = {
	{'B', "1"},
	{'B', "2"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$681[] = {
	{'S', "2"},
	{'S', "3"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$682[] = {
	{'I', "3"},
	{'I', "4"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$683[] = {
	{'J', "4"},
	{'J', "5"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$684[] = {
	{'C', "5"},
	{'C', "6"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$685[] = {
	{'F', "6.0"},
	{'F', "7.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$686[] = {
	{'D', "7.0"},
	{'D', "8.0"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$687[] = {
	{'Z', "true"},
	{'Z', "false"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$688[] = {
	{'s', "custom"},
	{'s', "paint"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$689[] = {
	{'c', "Ljava/util/Map;"},
	{'c', "Ljava/util/Set;"},
	{'-'}
};

$Attribute UnitTest_Attribute_var$690[] = {
	{'e', "LUniTest/Stooge; MOE"},
	{'e', "LUniTest/Stooge; CURLY"},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$693[] = {
	{"x", 'I', "1"},
	{"y", 'I', "2"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$692 = {
"LUniTest/Point;", UnitTest_Attribute_var$693
};

$NamedAttribute UnitTest_Attribute_var$695[] = {
	{"x", 'I', "3"},
	{"y", 'I', "4"},
	{}
};

$CompoundAttribute UnitTest_CompoundAttribute_var$694 = {
"LUniTest/Point;", UnitTest_Attribute_var$695
};

$Attribute UnitTest_Attribute_var$691[] = {
	{'@', &UnitTest_CompoundAttribute_var$692},
	{'@', &UnitTest_CompoundAttribute_var$694},
	{'-'}
};

$NamedAttribute UnitTest_Attribute_var$679[] = {
	{"b", '[', UnitTest_Attribute_var$680},
	{"s", '[', UnitTest_Attribute_var$681},
	{"i", '[', UnitTest_Attribute_var$682},
	{"l", '[', UnitTest_Attribute_var$683},
	{"c", '[', UnitTest_Attribute_var$684},
	{"f", '[', UnitTest_Attribute_var$685},
	{"d", '[', UnitTest_Attribute_var$686},
	{"bool", '[', UnitTest_Attribute_var$687},
	{"str", '[', UnitTest_Attribute_var$688},
	{"cls", '[', UnitTest_Attribute_var$689},
	{"e", '[', UnitTest_Attribute_var$690},
	{"a", '[', UnitTest_Attribute_var$691},
	{}
};

$ParameterAnnotation _UnitTest_MethodParamAnnotations_twoElementArrayTypesParam589[] = {
	{"LUniTest/ArrayTypes;", UnitTest_Attribute_var$679, 0},
	{}
};

$FieldInfo _UnitTest_FieldInfo_[] = {
	{"X", "[Ljava/lang/Class;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnitTest, X)},
	{"Y", "[Ljava/lang/Class;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnitTest, Y)},
	{"numTests", "I", nullptr, $STATIC, $staticField(UnitTest, numTests)},
	{"failCount", "I", nullptr, $STATIC, $staticField(UnitTest, failCount)},
	{"scalarTypesField", "I", nullptr, $PUBLIC, $field(UnitTest, scalarTypesField), _UnitTest_FieldAnnotations_scalarTypesField},
	{"scalarTypesAcceptDefaultField", "I", nullptr, $PUBLIC, $field(UnitTest, scalarTypesAcceptDefaultField), _UnitTest_FieldAnnotations_scalarTypesAcceptDefaultField},
	{"scalarTypesOverrideDefaultField", "I", nullptr, $PUBLIC, $field(UnitTest, scalarTypesOverrideDefaultField), _UnitTest_FieldAnnotations_scalarTypesOverrideDefaultField},
	{"emptyArrayTypesField", "I", nullptr, $PUBLIC, $field(UnitTest, emptyArrayTypesField), _UnitTest_FieldAnnotations_emptyArrayTypesField},
	{"singleElementArrayTypesField", "I", nullptr, $PUBLIC, $field(UnitTest, singleElementArrayTypesField), _UnitTest_FieldAnnotations_singleElementArrayTypesField},
	{"twoElementArrayTypesField", "I", nullptr, $PUBLIC, $field(UnitTest, twoElementArrayTypesField), _UnitTest_FieldAnnotations_twoElementArrayTypesField},
	{"arrayTypesAcceptDefaultField", "I", nullptr, $PUBLIC, $field(UnitTest, arrayTypesAcceptDefaultField), _UnitTest_FieldAnnotations_arrayTypesAcceptDefaultField},
	{"arrayTypesOverrideDefaultField", "I", nullptr, $PUBLIC, $field(UnitTest, arrayTypesOverrideDefaultField), _UnitTest_FieldAnnotations_arrayTypesOverrideDefaultField},
	{"markerField", "I", nullptr, $PUBLIC, $field(UnitTest, markerField), _UnitTest_FieldAnnotations_markerField},
	{"SingleMemberByteField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberByteField), _UnitTest_FieldAnnotations_SingleMemberByteField},
	{"SingleMemberShortField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberShortField), _UnitTest_FieldAnnotations_SingleMemberShortField},
	{"SingleMemberIntField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberIntField), _UnitTest_FieldAnnotations_SingleMemberIntField},
	{"SingleMemberLongField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberLongField), _UnitTest_FieldAnnotations_SingleMemberLongField},
	{"SingleMemberCharField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberCharField), _UnitTest_FieldAnnotations_SingleMemberCharField},
	{"SingleMemberFloatField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberFloatField), _UnitTest_FieldAnnotations_SingleMemberFloatField},
	{"SingleMemberDoubleField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberDoubleField), _UnitTest_FieldAnnotations_SingleMemberDoubleField},
	{"SingleMemberBooleanField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberBooleanField), _UnitTest_FieldAnnotations_SingleMemberBooleanField},
	{"SingleMemberStringField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberStringField), _UnitTest_FieldAnnotations_SingleMemberStringField},
	{"SingleMemberClassField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberClassField), _UnitTest_FieldAnnotations_SingleMemberClassField},
	{"SingleMemberEnumField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberEnumField), _UnitTest_FieldAnnotations_SingleMemberEnumField},
	{"SingleMemberByteOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberByteOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberByteOvrdDefField},
	{"SingleMemberShortOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberShortOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberShortOvrdDefField},
	{"SingleMemberIntOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberIntOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberIntOvrdDefField},
	{"SingleMemberLongOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberLongOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberLongOvrdDefField},
	{"SingleMemberCharOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberCharOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberCharOvrdDefField},
	{"SingleMemberFloatOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberFloatOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberFloatOvrdDefField},
	{"SingleMemberDoubleOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberDoubleOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberDoubleOvrdDefField},
	{"SingleMemberBooleanOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberBooleanOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberBooleanOvrdDefField},
	{"SingleMemberStringOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberStringOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberStringOvrdDefField},
	{"SingleMemberClassOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberClassOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberClassOvrdDefField},
	{"SingleMemberEnumOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberEnumOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberEnumOvrdDefField},
	{"SingleMemberByteAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberByteAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberByteAcceptDefField},
	{"SingleMemberShortAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberShortAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberShortAcceptDefField},
	{"SingleMemberIntAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberIntAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberIntAcceptDefField},
	{"SingleMemberLongAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberLongAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberLongAcceptDefField},
	{"SingleMemberCharAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberCharAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberCharAcceptDefField},
	{"SingleMemberFloatAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberFloatAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberFloatAcceptDefField},
	{"SingleMemberDoubleAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberDoubleAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberDoubleAcceptDefField},
	{"SingleMemberBooleanAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberBooleanAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberBooleanAcceptDefField},
	{"SingleMemberStringAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberStringAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberStringAcceptDefField},
	{"SingleMemberClassAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberClassAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberClassAcceptDefField},
	{"SingleMemberEnumAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberEnumAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberEnumAcceptDefField},
	{"SingleMemberByteArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberByteArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberByteArrEmptyField},
	{"SingleMemberShortArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberShortArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberShortArrEmptyField},
	{"SingleMemberIntArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberIntArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberIntArrEmptyField},
	{"SingleMemberLongArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberLongArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberLongArrEmptyField},
	{"SingleMemberCharArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberCharArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberCharArrEmptyField},
	{"SingleMemberFloatArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberFloatArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberFloatArrEmptyField},
	{"SingleMemberDoubleArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberDoubleArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberDoubleArrEmptyField},
	{"SingleMemberBooleanArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberBooleanArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberBooleanArrEmptyField},
	{"SingleMemberStringArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberStringArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberStringArrEmptyField},
	{"SingleMemberClassArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberClassArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberClassArrEmptyField},
	{"SingleMemberEnumArrEmptyField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberEnumArrEmptyField), _UnitTest_FieldAnnotations_SingleMemberEnumArrEmptyField},
	{"SingleMemberByteArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberByteArrOneField), _UnitTest_FieldAnnotations_SingleMemberByteArrOneField},
	{"SingleMemberShortArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberShortArrOneField), _UnitTest_FieldAnnotations_SingleMemberShortArrOneField},
	{"SingleMemberIntArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberIntArrOneField), _UnitTest_FieldAnnotations_SingleMemberIntArrOneField},
	{"SingleMemberLongArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberLongArrOneField), _UnitTest_FieldAnnotations_SingleMemberLongArrOneField},
	{"SingleMemberCharArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberCharArrOneField), _UnitTest_FieldAnnotations_SingleMemberCharArrOneField},
	{"SingleMemberFloatArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberFloatArrOneField), _UnitTest_FieldAnnotations_SingleMemberFloatArrOneField},
	{"SingleMemberDoubleArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberDoubleArrOneField), _UnitTest_FieldAnnotations_SingleMemberDoubleArrOneField},
	{"SingleMemberBooleanArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberBooleanArrOneField), _UnitTest_FieldAnnotations_SingleMemberBooleanArrOneField},
	{"SingleMemberStringArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberStringArrOneField), _UnitTest_FieldAnnotations_SingleMemberStringArrOneField},
	{"SingleMemberClassArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberClassArrOneField), _UnitTest_FieldAnnotations_SingleMemberClassArrOneField},
	{"SingleMemberEnumArrOneField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberEnumArrOneField), _UnitTest_FieldAnnotations_SingleMemberEnumArrOneField},
	{"SingleMemberByteArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberByteArrTwoField), _UnitTest_FieldAnnotations_SingleMemberByteArrTwoField},
	{"SingleMemberShortArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberShortArrTwoField), _UnitTest_FieldAnnotations_SingleMemberShortArrTwoField},
	{"SingleMemberIntArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberIntArrTwoField), _UnitTest_FieldAnnotations_SingleMemberIntArrTwoField},
	{"SingleMemberLongArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberLongArrTwoField), _UnitTest_FieldAnnotations_SingleMemberLongArrTwoField},
	{"SingleMemberCharArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberCharArrTwoField), _UnitTest_FieldAnnotations_SingleMemberCharArrTwoField},
	{"SingleMemberFloatArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberFloatArrTwoField), _UnitTest_FieldAnnotations_SingleMemberFloatArrTwoField},
	{"SingleMemberDoubleArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberDoubleArrTwoField), _UnitTest_FieldAnnotations_SingleMemberDoubleArrTwoField},
	{"SingleMemberBooleanArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberBooleanArrTwoField), _UnitTest_FieldAnnotations_SingleMemberBooleanArrTwoField},
	{"SingleMemberStringArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberStringArrTwoField), _UnitTest_FieldAnnotations_SingleMemberStringArrTwoField},
	{"SingleMemberClassArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberClassArrTwoField), _UnitTest_FieldAnnotations_SingleMemberClassArrTwoField},
	{"SingleMemberEnumArrTwoField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberEnumArrTwoField), _UnitTest_FieldAnnotations_SingleMemberEnumArrTwoField},
	{"SingleMemberByteArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberByteArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberByteArrOvrdDefField},
	{"SingleMemberShortArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberShortArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberShortArrOvrdDefField},
	{"SingleMemberIntArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberIntArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberIntArrOvrdDefField},
	{"SingleMemberLongArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberLongArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberLongArrOvrdDefField},
	{"SingleMemberCharArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberCharArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberCharArrOvrdDefField},
	{"SingleMemberFloatArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberFloatArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberFloatArrOvrdDefField},
	{"SingleMemberDoubleArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberDoubleArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberDoubleArrOvrdDefField},
	{"SingleMemberBooleanArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberBooleanArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberBooleanArrOvrdDefField},
	{"SingleMemberStringArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberStringArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberStringArrOvrdDefField},
	{"SingleMemberClassArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberClassArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberClassArrOvrdDefField},
	{"SingleMemberEnumArrOvrdDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberEnumArrOvrdDefField), _UnitTest_FieldAnnotations_SingleMemberEnumArrOvrdDefField},
	{"SingleMemberByteArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberByteArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberByteArrAcceptDefField},
	{"SingleMemberShortArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberShortArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberShortArrAcceptDefField},
	{"SingleMemberIntArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberIntArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberIntArrAcceptDefField},
	{"SingleMemberLongArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberLongArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberLongArrAcceptDefField},
	{"SingleMemberCharArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberCharArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberCharArrAcceptDefField},
	{"SingleMemberFloatArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberFloatArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberFloatArrAcceptDefField},
	{"SingleMemberDoubleArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberDoubleArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberDoubleArrAcceptDefField},
	{"SingleMemberBooleanArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberBooleanArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberBooleanArrAcceptDefField},
	{"SingleMemberStringArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberStringArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberStringArrAcceptDefField},
	{"SingleMemberClassArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberClassArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberClassArrAcceptDefField},
	{"SingleMemberEnumArrAcceptDefField", "I", nullptr, $PUBLIC, $field(UnitTest, SingleMemberEnumArrAcceptDefField), _UnitTest_FieldAnnotations_SingleMemberEnumArrAcceptDefField},
	{}
};

$MethodInfo _UnitTest_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Iterator;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Iterator*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$0},
	{"<init>", "(Ljava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$1},
	{"<init>", "(Ljava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$2},
	{"<init>", "(Ljava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$3},
	{"<init>", "(Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$4},
	{"<init>", "(Ljava/util/SortedSet;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $SortedSet*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$5},
	{"<init>", "(Ljava/util/SortedMap;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $SortedMap*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$6},
	{"<init>", "(Ljava/util/RandomAccess;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $RandomAccess*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$7},
	{"<init>", "()V", nullptr, $PUBLIC, $method(UnitTest, init$, void), nullptr, nullptr, _UnitTest_MethodAnnotations_init$8},
	{"<init>", "(B)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int8_t), nullptr, nullptr, _UnitTest_MethodAnnotations_init$9},
	{"<init>", "(S)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int16_t), nullptr, nullptr, _UnitTest_MethodAnnotations_init$10},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int32_t), nullptr, nullptr, _UnitTest_MethodAnnotations_init$11},
	{"<init>", "(J)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int64_t), nullptr, nullptr, _UnitTest_MethodAnnotations_init$12},
	{"<init>", "(C)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, char16_t), nullptr, nullptr, _UnitTest_MethodAnnotations_init$13},
	{"<init>", "(F)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, float), nullptr, nullptr, _UnitTest_MethodAnnotations_init$14},
	{"<init>", "(D)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, double), nullptr, nullptr, _UnitTest_MethodAnnotations_init$15},
	{"<init>", "(Z)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, bool), nullptr, nullptr, _UnitTest_MethodAnnotations_init$16},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $String*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$17},
	{"<init>", "(Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Class*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$18},
	{"<init>", "(Ljava/lang/Enum;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Enum*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$19},
	{"<init>", "(BLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int8_t, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$20},
	{"<init>", "(SLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int16_t, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$21},
	{"<init>", "(ILjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int32_t, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$22},
	{"<init>", "(JLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int64_t, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$23},
	{"<init>", "(CLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, char16_t, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$24},
	{"<init>", "(FLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, float, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$25},
	{"<init>", "(DLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, double, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$26},
	{"<init>", "(ZLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, bool, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$27},
	{"<init>", "(Ljava/lang/String;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $String*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$28},
	{"<init>", "(Ljava/lang/Class;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Class*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$29},
	{"<init>", "(Ljava/lang/Enum;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Enum*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$30},
	{"<init>", "(BLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int8_t, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$31},
	{"<init>", "(SLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int16_t, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$32},
	{"<init>", "(ILjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int32_t, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$33},
	{"<init>", "(JLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, int64_t, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$34},
	{"<init>", "(CLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, char16_t, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$35},
	{"<init>", "(FLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, float, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$36},
	{"<init>", "(DLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, double, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$37},
	{"<init>", "(ZLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, bool, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$38},
	{"<init>", "(Ljava/lang/String;Ljava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $String*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$39},
	{"<init>", "(Ljava/lang/Class;Ljava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Class*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$40},
	{"<init>", "(Ljava/lang/Enum;Ljava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $Enum*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$41},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $bytes*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$42},
	{"<init>", "([S)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $shorts*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$43},
	{"<init>", "([I)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ints*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$44},
	{"<init>", "([J)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $longs*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$45},
	{"<init>", "([C)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $chars*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$46},
	{"<init>", "([F)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $floats*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$47},
	{"<init>", "([D)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $doubles*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$48},
	{"<init>", "([Z)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $booleans*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$49},
	{"<init>", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $StringArray*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$50},
	{"<init>", "([Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ClassArray*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$51},
	{"<init>", "([Ljava/lang/Enum;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $EnumArray*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$52},
	{"<init>", "([BLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $bytes*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$53},
	{"<init>", "([SLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $shorts*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$54},
	{"<init>", "([ILjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ints*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$55},
	{"<init>", "([JLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $longs*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$56},
	{"<init>", "([CLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $chars*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$57},
	{"<init>", "([FLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $floats*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$58},
	{"<init>", "([DLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $doubles*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$59},
	{"<init>", "([ZLjava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $booleans*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$60},
	{"<init>", "([Ljava/lang/String;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $StringArray*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$61},
	{"<init>", "([Ljava/lang/Class;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ClassArray*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$62},
	{"<init>", "([Ljava/lang/Enum;Ljava/util/Set;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $EnumArray*, $Set*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$63},
	{"<init>", "([BLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $bytes*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$64},
	{"<init>", "([SLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $shorts*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$65},
	{"<init>", "([ILjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ints*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$66},
	{"<init>", "([JLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $longs*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$67},
	{"<init>", "([CLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $chars*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$68},
	{"<init>", "([FLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $floats*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$69},
	{"<init>", "([DLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $doubles*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$70},
	{"<init>", "([ZLjava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $booleans*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$71},
	{"<init>", "([Ljava/lang/String;Ljava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $StringArray*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$72},
	{"<init>", "([Ljava/lang/Class;Ljava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ClassArray*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$73},
	{"<init>", "([Ljava/lang/Enum;Ljava/util/Map;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $EnumArray*, $Map*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$74},
	{"<init>", "([BLjava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $bytes*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$75},
	{"<init>", "([SLjava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $shorts*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$76},
	{"<init>", "([ILjava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ints*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$77},
	{"<init>", "([JLjava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $longs*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$78},
	{"<init>", "([CLjava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $chars*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$79},
	{"<init>", "([FLjava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $floats*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$80},
	{"<init>", "([DLjava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $doubles*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$81},
	{"<init>", "([ZLjava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $booleans*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$82},
	{"<init>", "([Ljava/lang/String;Ljava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $StringArray*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$83},
	{"<init>", "([Ljava/lang/Class;Ljava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ClassArray*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$84},
	{"<init>", "([Ljava/lang/Enum;Ljava/util/List;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $EnumArray*, $List*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$85},
	{"<init>", "([BLjava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $bytes*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$86},
	{"<init>", "([SLjava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $shorts*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$87},
	{"<init>", "([ILjava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ints*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$88},
	{"<init>", "([JLjava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $longs*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$89},
	{"<init>", "([CLjava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $chars*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$90},
	{"<init>", "([FLjava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $floats*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$91},
	{"<init>", "([DLjava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $doubles*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$92},
	{"<init>", "([ZLjava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $booleans*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$93},
	{"<init>", "([Ljava/lang/String;Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $StringArray*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$94},
	{"<init>", "([Ljava/lang/Class;Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $ClassArray*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$95},
	{"<init>", "([Ljava/lang/Enum;Ljava/util/Collection;)V", nullptr, $PUBLIC, $method(UnitTest, init$, void, $EnumArray*, $Collection*), nullptr, nullptr, _UnitTest_MethodAnnotations_init$96},
	{"SingleMemberBoolean", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBoolean, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberBoolean97},
	{"SingleMemberBooleanAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberBooleanAcceptDef98},
	{"SingleMemberBooleanAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberBooleanAcceptDefParam99},
	{"SingleMemberBooleanArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberBooleanArrAcceptDef100},
	{"SingleMemberBooleanArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrAcceptDefParam101},
	{"SingleMemberBooleanArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberBooleanArrEmpty102},
	{"SingleMemberBooleanArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrEmptyParam103},
	{"SingleMemberBooleanArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberBooleanArrOne104},
	{"SingleMemberBooleanArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrOneParam105},
	{"SingleMemberBooleanArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberBooleanArrOvrdDef106},
	{"SingleMemberBooleanArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrOvrdDefParam107},
	{"SingleMemberBooleanArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberBooleanArrTwo108},
	{"SingleMemberBooleanArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberBooleanArrTwoParam109},
	{"SingleMemberBooleanOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberBooleanOvrdDef110},
	{"SingleMemberBooleanOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberBooleanOvrdDefParam111},
	{"SingleMemberBooleanParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberBooleanParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberBooleanParam112},
	{"SingleMemberByte", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByte, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberByte113},
	{"SingleMemberByteAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberByteAcceptDef114},
	{"SingleMemberByteAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberByteAcceptDefParam115},
	{"SingleMemberByteArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberByteArrAcceptDef116},
	{"SingleMemberByteArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberByteArrAcceptDefParam117},
	{"SingleMemberByteArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberByteArrEmpty118},
	{"SingleMemberByteArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberByteArrEmptyParam119},
	{"SingleMemberByteArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberByteArrOne120},
	{"SingleMemberByteArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberByteArrOneParam121},
	{"SingleMemberByteArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberByteArrOvrdDef122},
	{"SingleMemberByteArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberByteArrOvrdDefParam123},
	{"SingleMemberByteArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberByteArrTwo124},
	{"SingleMemberByteArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberByteArrTwoParam125},
	{"SingleMemberByteOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberByteOvrdDef126},
	{"SingleMemberByteOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberByteOvrdDefParam127},
	{"SingleMemberByteParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberByteParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberByteParam128},
	{"SingleMemberChar", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberChar, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberChar129},
	{"SingleMemberCharAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberCharAcceptDef130},
	{"SingleMemberCharAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberCharAcceptDefParam131},
	{"SingleMemberCharArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberCharArrAcceptDef132},
	{"SingleMemberCharArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberCharArrAcceptDefParam133},
	{"SingleMemberCharArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberCharArrEmpty134},
	{"SingleMemberCharArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberCharArrEmptyParam135},
	{"SingleMemberCharArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberCharArrOne136},
	{"SingleMemberCharArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberCharArrOneParam137},
	{"SingleMemberCharArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberCharArrOvrdDef138},
	{"SingleMemberCharArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberCharArrOvrdDefParam139},
	{"SingleMemberCharArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberCharArrTwo140},
	{"SingleMemberCharArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberCharArrTwoParam141},
	{"SingleMemberCharOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberCharOvrdDef142},
	{"SingleMemberCharOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberCharOvrdDefParam143},
	{"SingleMemberCharParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberCharParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberCharParam144},
	{"SingleMemberClass", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClass, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberClass145},
	{"SingleMemberClassAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberClassAcceptDef146},
	{"SingleMemberClassAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberClassAcceptDefParam147},
	{"SingleMemberClassArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberClassArrAcceptDef148},
	{"SingleMemberClassArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberClassArrAcceptDefParam149},
	{"SingleMemberClassArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberClassArrEmpty150},
	{"SingleMemberClassArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberClassArrEmptyParam151},
	{"SingleMemberClassArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberClassArrOne152},
	{"SingleMemberClassArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberClassArrOneParam153},
	{"SingleMemberClassArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberClassArrOvrdDef154},
	{"SingleMemberClassArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberClassArrOvrdDefParam155},
	{"SingleMemberClassArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberClassArrTwo156},
	{"SingleMemberClassArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberClassArrTwoParam157},
	{"SingleMemberClassOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberClassOvrdDef158},
	{"SingleMemberClassOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberClassOvrdDefParam159},
	{"SingleMemberClassParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberClassParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberClassParam160},
	{"SingleMemberDouble", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDouble, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberDouble161},
	{"SingleMemberDoubleAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberDoubleAcceptDef162},
	{"SingleMemberDoubleAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberDoubleAcceptDefParam163},
	{"SingleMemberDoubleArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberDoubleArrAcceptDef164},
	{"SingleMemberDoubleArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrAcceptDefParam165},
	{"SingleMemberDoubleArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberDoubleArrEmpty166},
	{"SingleMemberDoubleArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrEmptyParam167},
	{"SingleMemberDoubleArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberDoubleArrOne168},
	{"SingleMemberDoubleArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrOneParam169},
	{"SingleMemberDoubleArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberDoubleArrOvrdDef170},
	{"SingleMemberDoubleArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrOvrdDefParam171},
	{"SingleMemberDoubleArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberDoubleArrTwo172},
	{"SingleMemberDoubleArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberDoubleArrTwoParam173},
	{"SingleMemberDoubleOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberDoubleOvrdDef174},
	{"SingleMemberDoubleOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberDoubleOvrdDefParam175},
	{"SingleMemberDoubleParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberDoubleParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberDoubleParam176},
	{"SingleMemberEnum", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnum, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberEnum177},
	{"SingleMemberEnumAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberEnumAcceptDef178},
	{"SingleMemberEnumAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberEnumAcceptDefParam179},
	{"SingleMemberEnumArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberEnumArrAcceptDef180},
	{"SingleMemberEnumArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberEnumArrAcceptDefParam181},
	{"SingleMemberEnumArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberEnumArrEmpty182},
	{"SingleMemberEnumArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberEnumArrEmptyParam183},
	{"SingleMemberEnumArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberEnumArrOne184},
	{"SingleMemberEnumArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberEnumArrOneParam185},
	{"SingleMemberEnumArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberEnumArrOvrdDef186},
	{"SingleMemberEnumArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberEnumArrOvrdDefParam187},
	{"SingleMemberEnumArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberEnumArrTwo188},
	{"SingleMemberEnumArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberEnumArrTwoParam189},
	{"SingleMemberEnumOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberEnumOvrdDef190},
	{"SingleMemberEnumOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberEnumOvrdDefParam191},
	{"SingleMemberEnumParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberEnumParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberEnumParam192},
	{"SingleMemberFloat", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloat, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberFloat193},
	{"SingleMemberFloatAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberFloatAcceptDef194},
	{"SingleMemberFloatAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberFloatAcceptDefParam195},
	{"SingleMemberFloatArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberFloatArrAcceptDef196},
	{"SingleMemberFloatArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberFloatArrAcceptDefParam197},
	{"SingleMemberFloatArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberFloatArrEmpty198},
	{"SingleMemberFloatArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberFloatArrEmptyParam199},
	{"SingleMemberFloatArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberFloatArrOne200},
	{"SingleMemberFloatArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberFloatArrOneParam201},
	{"SingleMemberFloatArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberFloatArrOvrdDef202},
	{"SingleMemberFloatArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberFloatArrOvrdDefParam203},
	{"SingleMemberFloatArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberFloatArrTwo204},
	{"SingleMemberFloatArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberFloatArrTwoParam205},
	{"SingleMemberFloatOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberFloatOvrdDef206},
	{"SingleMemberFloatOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberFloatOvrdDefParam207},
	{"SingleMemberFloatParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberFloatParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberFloatParam208},
	{"SingleMemberInt", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberInt, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberInt209},
	{"SingleMemberIntAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberIntAcceptDef210},
	{"SingleMemberIntAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberIntAcceptDefParam211},
	{"SingleMemberIntArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberIntArrAcceptDef212},
	{"SingleMemberIntArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberIntArrAcceptDefParam213},
	{"SingleMemberIntArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberIntArrEmpty214},
	{"SingleMemberIntArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberIntArrEmptyParam215},
	{"SingleMemberIntArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberIntArrOne216},
	{"SingleMemberIntArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberIntArrOneParam217},
	{"SingleMemberIntArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberIntArrOvrdDef218},
	{"SingleMemberIntArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberIntArrOvrdDefParam219},
	{"SingleMemberIntArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberIntArrTwo220},
	{"SingleMemberIntArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberIntArrTwoParam221},
	{"SingleMemberIntOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberIntOvrdDef222},
	{"SingleMemberIntOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberIntOvrdDefParam223},
	{"SingleMemberIntParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberIntParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberIntParam224},
	{"SingleMemberLong", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLong, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberLong225},
	{"SingleMemberLongAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberLongAcceptDef226},
	{"SingleMemberLongAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberLongAcceptDefParam227},
	{"SingleMemberLongArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberLongArrAcceptDef228},
	{"SingleMemberLongArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberLongArrAcceptDefParam229},
	{"SingleMemberLongArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberLongArrEmpty230},
	{"SingleMemberLongArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberLongArrEmptyParam231},
	{"SingleMemberLongArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberLongArrOne232},
	{"SingleMemberLongArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberLongArrOneParam233},
	{"SingleMemberLongArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberLongArrOvrdDef234},
	{"SingleMemberLongArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberLongArrOvrdDefParam235},
	{"SingleMemberLongArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberLongArrTwo236},
	{"SingleMemberLongArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberLongArrTwoParam237},
	{"SingleMemberLongOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberLongOvrdDef238},
	{"SingleMemberLongOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberLongOvrdDefParam239},
	{"SingleMemberLongParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberLongParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberLongParam240},
	{"SingleMemberShort", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShort, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberShort241},
	{"SingleMemberShortAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberShortAcceptDef242},
	{"SingleMemberShortAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberShortAcceptDefParam243},
	{"SingleMemberShortArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberShortArrAcceptDef244},
	{"SingleMemberShortArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberShortArrAcceptDefParam245},
	{"SingleMemberShortArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberShortArrEmpty246},
	{"SingleMemberShortArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberShortArrEmptyParam247},
	{"SingleMemberShortArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberShortArrOne248},
	{"SingleMemberShortArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberShortArrOneParam249},
	{"SingleMemberShortArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberShortArrOvrdDef250},
	{"SingleMemberShortArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberShortArrOvrdDefParam251},
	{"SingleMemberShortArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberShortArrTwo252},
	{"SingleMemberShortArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberShortArrTwoParam253},
	{"SingleMemberShortOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberShortOvrdDef254},
	{"SingleMemberShortOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberShortOvrdDefParam255},
	{"SingleMemberShortParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberShortParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberShortParam256},
	{"SingleMemberString", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberString, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberString257},
	{"SingleMemberStringAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberStringAcceptDef258},
	{"SingleMemberStringAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberStringAcceptDefParam259},
	{"SingleMemberStringArrAcceptDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrAcceptDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberStringArrAcceptDef260},
	{"SingleMemberStringArrAcceptDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrAcceptDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberStringArrAcceptDefParam261},
	{"SingleMemberStringArrEmpty", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrEmpty, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberStringArrEmpty262},
	{"SingleMemberStringArrEmptyParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrEmptyParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberStringArrEmptyParam263},
	{"SingleMemberStringArrOne", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrOne, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberStringArrOne264},
	{"SingleMemberStringArrOneParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrOneParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberStringArrOneParam265},
	{"SingleMemberStringArrOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberStringArrOvrdDef266},
	{"SingleMemberStringArrOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberStringArrOvrdDefParam267},
	{"SingleMemberStringArrTwo", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrTwo, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberStringArrTwo268},
	{"SingleMemberStringArrTwoParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringArrTwoParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberStringArrTwoParam269},
	{"SingleMemberStringOvrdDef", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringOvrdDef, void), nullptr, nullptr, _UnitTest_MethodAnnotations_SingleMemberStringOvrdDef270},
	{"SingleMemberStringOvrdDefParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringOvrdDefParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberStringOvrdDefParam271},
	{"SingleMemberStringParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, SingleMemberStringParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_SingleMemberStringParam272},
	{"arrayTypesAcceptDefaultMethod", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, arrayTypesAcceptDefaultMethod, void), nullptr, nullptr, _UnitTest_MethodAnnotations_arrayTypesAcceptDefaultMethod273},
	{"arrayTypesAcceptDefaultParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, arrayTypesAcceptDefaultParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_arrayTypesAcceptDefaultParam274},
	{"arrayTypesOverrideDefaultMethod", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, arrayTypesOverrideDefaultMethod, void), nullptr, nullptr, _UnitTest_MethodAnnotations_arrayTypesOverrideDefaultMethod275},
	{"arrayTypesOverrideDefaultParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, arrayTypesOverrideDefaultParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_arrayTypesOverrideDefaultParam276},
	{"checkArrayTypes0", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypes0, void, $AnnotatedElement*)},
	{"checkArrayTypes0", "(LUniTest/ArrayTypes;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypes0, void, $ArrayTypes*, $AnnotatedElement*)},
	{"checkArrayTypes0Param", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypes0Param, void, $Method*)},
	{"checkArrayTypes1", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypes1, void, $AnnotatedElement*)},
	{"checkArrayTypes1", "(LUniTest/ArrayTypes;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypes1, void, $ArrayTypes*, $AnnotatedElement*)},
	{"checkArrayTypes1Param", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypes1Param, void, $Method*)},
	{"checkArrayTypes2", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypes2, void, $AnnotatedElement*)},
	{"checkArrayTypes2", "(LUniTest/ArrayTypes;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypes2, void, $ArrayTypes*, $AnnotatedElement*)},
	{"checkArrayTypes2Param", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypes2Param, void, $Method*)},
	{"checkArrayTypesAcceptDefault", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypesAcceptDefault, void, $AnnotatedElement*)},
	{"checkArrayTypesAcceptDefault", "(LUniTest/ArrayTypesWithDefault;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypesAcceptDefault, void, $ArrayTypesWithDefault*, $AnnotatedElement*)},
	{"checkArrayTypesAcceptDefaultParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypesAcceptDefaultParam, void, $Method*)},
	{"checkArrayTypesOverrideDefault", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypesOverrideDefault, void, $AnnotatedElement*)},
	{"checkArrayTypesOverrideDefault", "(LUniTest/ArrayTypesWithDefault;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypesOverrideDefault, void, $ArrayTypesWithDefault*, $AnnotatedElement*)},
	{"checkArrayTypesOverrideDefaultParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkArrayTypesOverrideDefaultParam, void, $Method*)},
	{"checkDeclaredAnnotations", "(Ljava/lang/reflect/AnnotatedElement;ZZ)V", nullptr, $STATIC, $staticMethod(UnitTest, checkDeclaredAnnotations, void, $AnnotatedElement*, bool, bool)},
	{"checkEquals", "(Ljava/lang/reflect/AnnotatedElement;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class;)V", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/reflect/AnnotatedElement;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class<TT;>;)V", $STATIC, $staticMethod(UnitTest, checkEquals, void, $AnnotatedElement*, $AnnotatedElement*, $Class*)},
	{"checkInheritence", "(Ljava/lang/reflect/AnnotatedElement;ZZ)V", nullptr, $STATIC, $staticMethod(UnitTest, checkInheritence, void, $AnnotatedElement*, bool, bool)},
	{"checkMarker", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkMarker, void, $AnnotatedElement*)},
	{"checkMarker", "(LUniTest/Marker;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkMarker, void, $Marker*, $AnnotatedElement*)},
	{"checkMarkerParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkMarkerParam, void, $Method*)},
	{"checkScalarTypes", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkScalarTypes, void, $AnnotatedElement*)},
	{"checkScalarTypes", "(LUniTest/ScalarTypes;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkScalarTypes, void, $ScalarTypes*, $AnnotatedElement*), "java.lang.Exception"},
	{"checkScalarTypesAcceptDefault", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkScalarTypesAcceptDefault, void, $AnnotatedElement*)},
	{"checkScalarTypesAcceptDefault", "(LUniTest/ScalarTypesWithDefault;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkScalarTypesAcceptDefault, void, $ScalarTypesWithDefault*, $AnnotatedElement*)},
	{"checkScalarTypesAcceptDefaultParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkScalarTypesAcceptDefaultParam, void, $Method*)},
	{"checkScalarTypesOverrideDefault", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkScalarTypesOverrideDefault, void, $AnnotatedElement*)},
	{"checkScalarTypesOverrideDefault", "(LUniTest/ScalarTypesWithDefault;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkScalarTypesOverrideDefault, void, $ScalarTypesWithDefault*, $AnnotatedElement*)},
	{"checkScalarTypesOverrideDefaultParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkScalarTypesOverrideDefaultParam, void, $Method*)},
	{"checkScalarTypesParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkScalarTypesParam, void, $Method*)},
	{"checkSerialization", "(Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class;)V", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class<TT;>;)V", $STATIC, $staticMethod(UnitTest, checkSerialization, void, $AnnotatedElement*, $Class*)},
	{"checkSingleMemberBoolean", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBoolean, void, $AnnotatedElement*)},
	{"checkSingleMemberBoolean", "(LUniTest/SingleMemberBoolean;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBoolean, void, $SingleMemberBoolean*, $AnnotatedElement*)},
	{"checkSingleMemberBooleanAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberBooleanAcceptDef", "(LUniTest/SingleMemberBooleanWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanAcceptDef, void, $SingleMemberBooleanWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberBooleanAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanAcceptDefParam, void, $Method*)},
	{"checkSingleMemberBooleanArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrAcceptDef", "(LUniTest/SingleMemberBooleanArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrAcceptDef, void, $SingleMemberBooleanArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberBooleanArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrEmpty", "(LUniTest/SingleMemberBooleanArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrEmpty, void, $SingleMemberBooleanArray*, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrEmptyParam, void, $Method*)},
	{"checkSingleMemberBooleanArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrOne", "(LUniTest/SingleMemberBooleanArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrOne, void, $SingleMemberBooleanArray*, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrOneParam, void, $Method*)},
	{"checkSingleMemberBooleanArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrOvrdDef", "(LUniTest/SingleMemberBooleanArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrOvrdDef, void, $SingleMemberBooleanArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberBooleanArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrTwo", "(LUniTest/SingleMemberBooleanArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrTwo, void, $SingleMemberBooleanArray*, $AnnotatedElement*)},
	{"checkSingleMemberBooleanArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanArrTwoParam, void, $Method*)},
	{"checkSingleMemberBooleanOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberBooleanOvrdDef", "(LUniTest/SingleMemberBooleanWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanOvrdDef, void, $SingleMemberBooleanWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberBooleanOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanOvrdDefParam, void, $Method*)},
	{"checkSingleMemberBooleanParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberBooleanParam, void, $Method*)},
	{"checkSingleMemberByte", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByte, void, $AnnotatedElement*)},
	{"checkSingleMemberByte", "(LUniTest/SingleMemberByte;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByte, void, $SingleMemberByte*, $AnnotatedElement*)},
	{"checkSingleMemberByteAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberByteAcceptDef", "(LUniTest/SingleMemberByteWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteAcceptDef, void, $SingleMemberByteWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberByteAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteAcceptDefParam, void, $Method*)},
	{"checkSingleMemberByteArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberByteArrAcceptDef", "(LUniTest/SingleMemberByteArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrAcceptDef, void, $SingleMemberByteArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberByteArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberByteArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberByteArrEmpty", "(LUniTest/SingleMemberByteArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrEmpty, void, $SingleMemberByteArray*, $AnnotatedElement*)},
	{"checkSingleMemberByteArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrEmptyParam, void, $Method*)},
	{"checkSingleMemberByteArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberByteArrOne", "(LUniTest/SingleMemberByteArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrOne, void, $SingleMemberByteArray*, $AnnotatedElement*)},
	{"checkSingleMemberByteArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrOneParam, void, $Method*)},
	{"checkSingleMemberByteArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberByteArrOvrdDef", "(LUniTest/SingleMemberByteArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrOvrdDef, void, $SingleMemberByteArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberByteArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberByteArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberByteArrTwo", "(LUniTest/SingleMemberByteArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrTwo, void, $SingleMemberByteArray*, $AnnotatedElement*)},
	{"checkSingleMemberByteArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteArrTwoParam, void, $Method*)},
	{"checkSingleMemberByteOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberByteOvrdDef", "(LUniTest/SingleMemberByteWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteOvrdDef, void, $SingleMemberByteWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberByteOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteOvrdDefParam, void, $Method*)},
	{"checkSingleMemberByteParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberByteParam, void, $Method*)},
	{"checkSingleMemberChar", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberChar, void, $AnnotatedElement*)},
	{"checkSingleMemberChar", "(LUniTest/SingleMemberChar;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberChar, void, $SingleMemberChar*, $AnnotatedElement*)},
	{"checkSingleMemberCharAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberCharAcceptDef", "(LUniTest/SingleMemberCharWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharAcceptDef, void, $SingleMemberCharWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberCharAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharAcceptDefParam, void, $Method*)},
	{"checkSingleMemberCharArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberCharArrAcceptDef", "(LUniTest/SingleMemberCharArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrAcceptDef, void, $SingleMemberCharArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberCharArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberCharArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberCharArrEmpty", "(LUniTest/SingleMemberCharArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrEmpty, void, $SingleMemberCharArray*, $AnnotatedElement*)},
	{"checkSingleMemberCharArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrEmptyParam, void, $Method*)},
	{"checkSingleMemberCharArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberCharArrOne", "(LUniTest/SingleMemberCharArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrOne, void, $SingleMemberCharArray*, $AnnotatedElement*)},
	{"checkSingleMemberCharArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrOneParam, void, $Method*)},
	{"checkSingleMemberCharArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberCharArrOvrdDef", "(LUniTest/SingleMemberCharArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrOvrdDef, void, $SingleMemberCharArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberCharArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberCharArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberCharArrTwo", "(LUniTest/SingleMemberCharArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrTwo, void, $SingleMemberCharArray*, $AnnotatedElement*)},
	{"checkSingleMemberCharArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharArrTwoParam, void, $Method*)},
	{"checkSingleMemberCharOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberCharOvrdDef", "(LUniTest/SingleMemberCharWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharOvrdDef, void, $SingleMemberCharWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberCharOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharOvrdDefParam, void, $Method*)},
	{"checkSingleMemberCharParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberCharParam, void, $Method*)},
	{"checkSingleMemberClass", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClass, void, $AnnotatedElement*)},
	{"checkSingleMemberClass", "(LUniTest/SingleMemberClass;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClass, void, $SingleMemberClass*, $AnnotatedElement*)},
	{"checkSingleMemberClassAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberClassAcceptDef", "(LUniTest/SingleMemberClassWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassAcceptDef, void, $SingleMemberClassWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberClassAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassAcceptDefParam, void, $Method*)},
	{"checkSingleMemberClassArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberClassArrAcceptDef", "(LUniTest/SingleMemberClassArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrAcceptDef, void, $SingleMemberClassArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberClassArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberClassArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberClassArrEmpty", "(LUniTest/SingleMemberClassArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrEmpty, void, $SingleMemberClassArray*, $AnnotatedElement*)},
	{"checkSingleMemberClassArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrEmptyParam, void, $Method*)},
	{"checkSingleMemberClassArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberClassArrOne", "(LUniTest/SingleMemberClassArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrOne, void, $SingleMemberClassArray*, $AnnotatedElement*)},
	{"checkSingleMemberClassArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrOneParam, void, $Method*)},
	{"checkSingleMemberClassArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberClassArrOvrdDef", "(LUniTest/SingleMemberClassArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrOvrdDef, void, $SingleMemberClassArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberClassArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberClassArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberClassArrTwo", "(LUniTest/SingleMemberClassArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrTwo, void, $SingleMemberClassArray*, $AnnotatedElement*)},
	{"checkSingleMemberClassArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassArrTwoParam, void, $Method*)},
	{"checkSingleMemberClassOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberClassOvrdDef", "(LUniTest/SingleMemberClassWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassOvrdDef, void, $SingleMemberClassWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberClassOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassOvrdDefParam, void, $Method*)},
	{"checkSingleMemberClassParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberClassParam, void, $Method*)},
	{"checkSingleMemberDouble", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDouble, void, $AnnotatedElement*)},
	{"checkSingleMemberDouble", "(LUniTest/SingleMemberDouble;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDouble, void, $SingleMemberDouble*, $AnnotatedElement*)},
	{"checkSingleMemberDoubleAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberDoubleAcceptDef", "(LUniTest/SingleMemberDoubleWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleAcceptDef, void, $SingleMemberDoubleWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberDoubleAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleAcceptDefParam, void, $Method*)},
	{"checkSingleMemberDoubleArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrAcceptDef", "(LUniTest/SingleMemberDoubleArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrAcceptDef, void, $SingleMemberDoubleArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberDoubleArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrEmpty", "(LUniTest/SingleMemberDoubleArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrEmpty, void, $SingleMemberDoubleArray*, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrEmptyParam, void, $Method*)},
	{"checkSingleMemberDoubleArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrOne", "(LUniTest/SingleMemberDoubleArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrOne, void, $SingleMemberDoubleArray*, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrOneParam, void, $Method*)},
	{"checkSingleMemberDoubleArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrOvrdDef", "(LUniTest/SingleMemberDoubleArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrOvrdDef, void, $SingleMemberDoubleArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberDoubleArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrTwo", "(LUniTest/SingleMemberDoubleArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrTwo, void, $SingleMemberDoubleArray*, $AnnotatedElement*)},
	{"checkSingleMemberDoubleArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleArrTwoParam, void, $Method*)},
	{"checkSingleMemberDoubleOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberDoubleOvrdDef", "(LUniTest/SingleMemberDoubleWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleOvrdDef, void, $SingleMemberDoubleWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberDoubleOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleOvrdDefParam, void, $Method*)},
	{"checkSingleMemberDoubleParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberDoubleParam, void, $Method*)},
	{"checkSingleMemberEnum", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnum, void, $AnnotatedElement*)},
	{"checkSingleMemberEnum", "(LUniTest/SingleMemberEnum;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnum, void, $SingleMemberEnum*, $AnnotatedElement*)},
	{"checkSingleMemberEnumAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberEnumAcceptDef", "(LUniTest/SingleMemberEnumWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumAcceptDef, void, $SingleMemberEnumWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberEnumAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumAcceptDefParam, void, $Method*)},
	{"checkSingleMemberEnumArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrAcceptDef", "(LUniTest/SingleMemberEnumArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrAcceptDef, void, $SingleMemberEnumArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberEnumArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrEmpty", "(LUniTest/SingleMemberEnumArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrEmpty, void, $SingleMemberEnumArray*, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrEmptyParam, void, $Method*)},
	{"checkSingleMemberEnumArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrOne", "(LUniTest/SingleMemberEnumArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrOne, void, $SingleMemberEnumArray*, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrOneParam, void, $Method*)},
	{"checkSingleMemberEnumArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrOvrdDef", "(LUniTest/SingleMemberEnumArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrOvrdDef, void, $SingleMemberEnumArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberEnumArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrTwo", "(LUniTest/SingleMemberEnumArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrTwo, void, $SingleMemberEnumArray*, $AnnotatedElement*)},
	{"checkSingleMemberEnumArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumArrTwoParam, void, $Method*)},
	{"checkSingleMemberEnumOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberEnumOvrdDef", "(LUniTest/SingleMemberEnumWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumOvrdDef, void, $SingleMemberEnumWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberEnumOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumOvrdDefParam, void, $Method*)},
	{"checkSingleMemberEnumParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberEnumParam, void, $Method*)},
	{"checkSingleMemberFloat", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloat, void, $AnnotatedElement*)},
	{"checkSingleMemberFloat", "(LUniTest/SingleMemberFloat;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloat, void, $SingleMemberFloat*, $AnnotatedElement*)},
	{"checkSingleMemberFloatAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberFloatAcceptDef", "(LUniTest/SingleMemberFloatWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatAcceptDef, void, $SingleMemberFloatWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberFloatAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatAcceptDefParam, void, $Method*)},
	{"checkSingleMemberFloatArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrAcceptDef", "(LUniTest/SingleMemberFloatArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrAcceptDef, void, $SingleMemberFloatArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberFloatArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrEmpty", "(LUniTest/SingleMemberFloatArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrEmpty, void, $SingleMemberFloatArray*, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrEmptyParam, void, $Method*)},
	{"checkSingleMemberFloatArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrOne", "(LUniTest/SingleMemberFloatArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrOne, void, $SingleMemberFloatArray*, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrOneParam, void, $Method*)},
	{"checkSingleMemberFloatArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrOvrdDef", "(LUniTest/SingleMemberFloatArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrOvrdDef, void, $SingleMemberFloatArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberFloatArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrTwo", "(LUniTest/SingleMemberFloatArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrTwo, void, $SingleMemberFloatArray*, $AnnotatedElement*)},
	{"checkSingleMemberFloatArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatArrTwoParam, void, $Method*)},
	{"checkSingleMemberFloatOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberFloatOvrdDef", "(LUniTest/SingleMemberFloatWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatOvrdDef, void, $SingleMemberFloatWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberFloatOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatOvrdDefParam, void, $Method*)},
	{"checkSingleMemberFloatParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberFloatParam, void, $Method*)},
	{"checkSingleMemberInt", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberInt, void, $AnnotatedElement*)},
	{"checkSingleMemberInt", "(LUniTest/SingleMemberInt;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberInt, void, $SingleMemberInt*, $AnnotatedElement*)},
	{"checkSingleMemberIntAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberIntAcceptDef", "(LUniTest/SingleMemberIntWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntAcceptDef, void, $SingleMemberIntWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberIntAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntAcceptDefParam, void, $Method*)},
	{"checkSingleMemberIntArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberIntArrAcceptDef", "(LUniTest/SingleMemberIntArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrAcceptDef, void, $SingleMemberIntArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberIntArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberIntArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberIntArrEmpty", "(LUniTest/SingleMemberIntArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrEmpty, void, $SingleMemberIntArray*, $AnnotatedElement*)},
	{"checkSingleMemberIntArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrEmptyParam, void, $Method*)},
	{"checkSingleMemberIntArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberIntArrOne", "(LUniTest/SingleMemberIntArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrOne, void, $SingleMemberIntArray*, $AnnotatedElement*)},
	{"checkSingleMemberIntArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrOneParam, void, $Method*)},
	{"checkSingleMemberIntArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberIntArrOvrdDef", "(LUniTest/SingleMemberIntArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrOvrdDef, void, $SingleMemberIntArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberIntArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberIntArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberIntArrTwo", "(LUniTest/SingleMemberIntArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrTwo, void, $SingleMemberIntArray*, $AnnotatedElement*)},
	{"checkSingleMemberIntArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntArrTwoParam, void, $Method*)},
	{"checkSingleMemberIntOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberIntOvrdDef", "(LUniTest/SingleMemberIntWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntOvrdDef, void, $SingleMemberIntWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberIntOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntOvrdDefParam, void, $Method*)},
	{"checkSingleMemberIntParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberIntParam, void, $Method*)},
	{"checkSingleMemberLong", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLong, void, $AnnotatedElement*)},
	{"checkSingleMemberLong", "(LUniTest/SingleMemberLong;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLong, void, $SingleMemberLong*, $AnnotatedElement*)},
	{"checkSingleMemberLongAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberLongAcceptDef", "(LUniTest/SingleMemberLongWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongAcceptDef, void, $SingleMemberLongWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberLongAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongAcceptDefParam, void, $Method*)},
	{"checkSingleMemberLongArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberLongArrAcceptDef", "(LUniTest/SingleMemberLongArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrAcceptDef, void, $SingleMemberLongArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberLongArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberLongArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberLongArrEmpty", "(LUniTest/SingleMemberLongArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrEmpty, void, $SingleMemberLongArray*, $AnnotatedElement*)},
	{"checkSingleMemberLongArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrEmptyParam, void, $Method*)},
	{"checkSingleMemberLongArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberLongArrOne", "(LUniTest/SingleMemberLongArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrOne, void, $SingleMemberLongArray*, $AnnotatedElement*)},
	{"checkSingleMemberLongArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrOneParam, void, $Method*)},
	{"checkSingleMemberLongArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberLongArrOvrdDef", "(LUniTest/SingleMemberLongArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrOvrdDef, void, $SingleMemberLongArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberLongArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberLongArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberLongArrTwo", "(LUniTest/SingleMemberLongArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrTwo, void, $SingleMemberLongArray*, $AnnotatedElement*)},
	{"checkSingleMemberLongArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongArrTwoParam, void, $Method*)},
	{"checkSingleMemberLongOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberLongOvrdDef", "(LUniTest/SingleMemberLongWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongOvrdDef, void, $SingleMemberLongWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberLongOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongOvrdDefParam, void, $Method*)},
	{"checkSingleMemberLongParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberLongParam, void, $Method*)},
	{"checkSingleMemberShort", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShort, void, $AnnotatedElement*)},
	{"checkSingleMemberShort", "(LUniTest/SingleMemberShort;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShort, void, $SingleMemberShort*, $AnnotatedElement*)},
	{"checkSingleMemberShortAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberShortAcceptDef", "(LUniTest/SingleMemberShortWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortAcceptDef, void, $SingleMemberShortWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberShortAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortAcceptDefParam, void, $Method*)},
	{"checkSingleMemberShortArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberShortArrAcceptDef", "(LUniTest/SingleMemberShortArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrAcceptDef, void, $SingleMemberShortArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberShortArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberShortArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberShortArrEmpty", "(LUniTest/SingleMemberShortArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrEmpty, void, $SingleMemberShortArray*, $AnnotatedElement*)},
	{"checkSingleMemberShortArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrEmptyParam, void, $Method*)},
	{"checkSingleMemberShortArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberShortArrOne", "(LUniTest/SingleMemberShortArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrOne, void, $SingleMemberShortArray*, $AnnotatedElement*)},
	{"checkSingleMemberShortArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrOneParam, void, $Method*)},
	{"checkSingleMemberShortArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberShortArrOvrdDef", "(LUniTest/SingleMemberShortArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrOvrdDef, void, $SingleMemberShortArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberShortArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberShortArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberShortArrTwo", "(LUniTest/SingleMemberShortArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrTwo, void, $SingleMemberShortArray*, $AnnotatedElement*)},
	{"checkSingleMemberShortArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortArrTwoParam, void, $Method*)},
	{"checkSingleMemberShortOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberShortOvrdDef", "(LUniTest/SingleMemberShortWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortOvrdDef, void, $SingleMemberShortWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberShortOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortOvrdDefParam, void, $Method*)},
	{"checkSingleMemberShortParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberShortParam, void, $Method*)},
	{"checkSingleMemberString", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberString, void, $AnnotatedElement*)},
	{"checkSingleMemberString", "(LUniTest/SingleMemberString;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberString, void, $SingleMemberString*, $AnnotatedElement*)},
	{"checkSingleMemberStringAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberStringAcceptDef", "(LUniTest/SingleMemberStringWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringAcceptDef, void, $SingleMemberStringWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberStringAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringAcceptDefParam, void, $Method*)},
	{"checkSingleMemberStringArrAcceptDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrAcceptDef, void, $AnnotatedElement*)},
	{"checkSingleMemberStringArrAcceptDef", "(LUniTest/SingleMemberStringArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrAcceptDef, void, $SingleMemberStringArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberStringArrAcceptDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrAcceptDefParam, void, $Method*)},
	{"checkSingleMemberStringArrEmpty", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrEmpty, void, $AnnotatedElement*)},
	{"checkSingleMemberStringArrEmpty", "(LUniTest/SingleMemberStringArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrEmpty, void, $SingleMemberStringArray*, $AnnotatedElement*)},
	{"checkSingleMemberStringArrEmptyParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrEmptyParam, void, $Method*)},
	{"checkSingleMemberStringArrOne", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrOne, void, $AnnotatedElement*)},
	{"checkSingleMemberStringArrOne", "(LUniTest/SingleMemberStringArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrOne, void, $SingleMemberStringArray*, $AnnotatedElement*)},
	{"checkSingleMemberStringArrOneParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrOneParam, void, $Method*)},
	{"checkSingleMemberStringArrOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberStringArrOvrdDef", "(LUniTest/SingleMemberStringArrayDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrOvrdDef, void, $SingleMemberStringArrayDef*, $AnnotatedElement*)},
	{"checkSingleMemberStringArrOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrOvrdDefParam, void, $Method*)},
	{"checkSingleMemberStringArrTwo", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrTwo, void, $AnnotatedElement*)},
	{"checkSingleMemberStringArrTwo", "(LUniTest/SingleMemberStringArray;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrTwo, void, $SingleMemberStringArray*, $AnnotatedElement*)},
	{"checkSingleMemberStringArrTwoParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringArrTwoParam, void, $Method*)},
	{"checkSingleMemberStringOvrdDef", "(Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringOvrdDef, void, $AnnotatedElement*)},
	{"checkSingleMemberStringOvrdDef", "(LUniTest/SingleMemberStringWithDef;Ljava/lang/reflect/AnnotatedElement;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringOvrdDef, void, $SingleMemberStringWithDef*, $AnnotatedElement*)},
	{"checkSingleMemberStringOvrdDefParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringOvrdDefParam, void, $Method*)},
	{"checkSingleMemberStringParam", "(Ljava/lang/reflect/Method;)V", nullptr, $STATIC, $staticMethod(UnitTest, checkSingleMemberStringParam, void, $Method*)},
	{"checkUnequals", "(Ljava/lang/reflect/AnnotatedElement;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class;)V", "<T::Ljava/lang/annotation/Annotation;>(Ljava/lang/reflect/AnnotatedElement;Ljava/lang/reflect/AnnotatedElement;Ljava/lang/Class<TT;>;)V", $STATIC, $staticMethod(UnitTest, checkUnequals, void, $AnnotatedElement*, $AnnotatedElement*, $Class*)},
	{"deepCopy", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(UnitTest, deepCopy, $Object*, Object$*)},
	{"emptyArrayTypesMethod", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, emptyArrayTypesMethod, void), nullptr, nullptr, _UnitTest_MethodAnnotations_emptyArrayTypesMethod574},
	{"emptyArrayTypesParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, emptyArrayTypesParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_emptyArrayTypesParam575},
	{"fail", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(UnitTest, fail, void, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(UnitTest, main, void, $StringArray*), "java.lang.Exception"},
	{"markerMethod", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, markerMethod, void), nullptr, nullptr, _UnitTest_MethodAnnotations_markerMethod578},
	{"markerParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, markerParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_markerParam579},
	{"scalarTypesAcceptDefaultMethod", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, scalarTypesAcceptDefaultMethod, void), nullptr, nullptr, _UnitTest_MethodAnnotations_scalarTypesAcceptDefaultMethod580},
	{"scalarTypesAcceptDefaultParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, scalarTypesAcceptDefaultParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_scalarTypesAcceptDefaultParam581},
	{"scalarTypesMethod", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, scalarTypesMethod, void), nullptr, nullptr, _UnitTest_MethodAnnotations_scalarTypesMethod582},
	{"scalarTypesOverrideDefaultMethod", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, scalarTypesOverrideDefaultMethod, void), nullptr, nullptr, _UnitTest_MethodAnnotations_scalarTypesOverrideDefaultMethod583},
	{"scalarTypesOverrideDefaultParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, scalarTypesOverrideDefaultParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_scalarTypesOverrideDefaultParam584},
	{"scalarTypesParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, scalarTypesParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_scalarTypesParam585},
	{"singleElementArrayTypesMethod", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, singleElementArrayTypesMethod, void), nullptr, nullptr, _UnitTest_MethodAnnotations_singleElementArrayTypesMethod586},
	{"singleElementArrayTypesParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, singleElementArrayTypesParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_singleElementArrayTypesParam587},
	{"twoElementArrayTypesMethod", "()V", nullptr, $PUBLIC, $virtualMethod(UnitTest, twoElementArrayTypesMethod, void), nullptr, nullptr, _UnitTest_MethodAnnotations_twoElementArrayTypesMethod588},
	{"twoElementArrayTypesParam", "(I)V", nullptr, $PUBLIC, $virtualMethod(UnitTest, twoElementArrayTypesParam, void, int32_t), nullptr, nullptr, nullptr, nullptr, _UnitTest_MethodParamAnnotations_twoElementArrayTypesParam589},
	{}
};

$InnerClassInfo _UnitTest_InnerClassesInfo_[] = {
	{"UniTest.UnitTest$TestType", "UniTest.UnitTest", "TestType", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _UnitTest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"UniTest.UnitTest",
	"java.lang.Object",
	nullptr,
	_UnitTest_FieldInfo_,
	_UnitTest_MethodInfo_,
	nullptr,
	nullptr,
	_UnitTest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"UniTest.UnitTest$TestType"
};

$Object* allocate$UnitTest($Class* clazz) {
	return $of($alloc(UnitTest));
}

$ClassArray* UnitTest::X = nullptr;
$ClassArray* UnitTest::Y = nullptr;
int32_t UnitTest::numTests = 0;
int32_t UnitTest::failCount = 0;

void UnitTest::main($StringArray* args) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	checkScalarTypes($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("scalarTypesMethod"_s, UnitTest::X))))));
	checkScalarTypesOverrideDefault($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("scalarTypesOverrideDefaultMethod"_s, UnitTest::X))))));
	checkScalarTypesAcceptDefault($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("scalarTypesAcceptDefaultMethod"_s, UnitTest::X))))));
	checkArrayTypes0($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("emptyArrayTypesMethod"_s, UnitTest::X))))));
	checkArrayTypes1($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("singleElementArrayTypesMethod"_s, UnitTest::X))))));
	checkArrayTypes2($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("twoElementArrayTypesMethod"_s, UnitTest::X))))));
	checkArrayTypesAcceptDefault($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("arrayTypesAcceptDefaultMethod"_s, UnitTest::X))))));
	checkArrayTypesOverrideDefault($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("arrayTypesOverrideDefaultMethod"_s, UnitTest::X))))));
	checkMarker($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("markerMethod"_s, UnitTest::X))))));
	checkSingleMemberByte($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberByte"_s, UnitTest::X))))));
	checkSingleMemberShort($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberShort"_s, UnitTest::X))))));
	checkSingleMemberInt($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberInt"_s, UnitTest::X))))));
	checkSingleMemberLong($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberLong"_s, UnitTest::X))))));
	checkSingleMemberChar($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberChar"_s, UnitTest::X))))));
	checkSingleMemberFloat($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberFloat"_s, UnitTest::X))))));
	checkSingleMemberDouble($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberDouble"_s, UnitTest::X))))));
	checkSingleMemberBoolean($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberBoolean"_s, UnitTest::X))))));
	checkSingleMemberString($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberString"_s, UnitTest::X))))));
	checkSingleMemberClass($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberClass"_s, UnitTest::X))))));
	checkSingleMemberEnum($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberEnum"_s, UnitTest::X))))));
	checkSingleMemberByteOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberByteOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberShortOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberShortOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberIntOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberIntOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberLongOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberLongOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberCharOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberCharOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberFloatOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberFloatOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberDoubleOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberDoubleOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberBooleanOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberBooleanOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberStringOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberStringOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberClassOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberClassOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberEnumOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberEnumOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberByteAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberByteAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberShortAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberShortAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberIntAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberIntAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberLongAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberLongAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberCharAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberCharAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberFloatAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberFloatAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberDoubleAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberDoubleAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberBooleanAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberBooleanAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberStringAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberStringAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberClassAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberClassAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberEnumAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberEnumAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberByteArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberByteArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberShortArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberShortArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberIntArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberIntArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberLongArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberLongArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberCharArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberCharArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberFloatArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberFloatArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberDoubleArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberDoubleArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberBooleanArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberBooleanArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberStringArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberStringArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberClassArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberClassArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberEnumArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberEnumArrEmpty"_s, UnitTest::X))))));
	checkSingleMemberByteArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberByteArrOne"_s, UnitTest::X))))));
	checkSingleMemberShortArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberShortArrOne"_s, UnitTest::X))))));
	checkSingleMemberIntArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberIntArrOne"_s, UnitTest::X))))));
	checkSingleMemberLongArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberLongArrOne"_s, UnitTest::X))))));
	checkSingleMemberCharArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberCharArrOne"_s, UnitTest::X))))));
	checkSingleMemberFloatArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberFloatArrOne"_s, UnitTest::X))))));
	checkSingleMemberDoubleArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberDoubleArrOne"_s, UnitTest::X))))));
	checkSingleMemberBooleanArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberBooleanArrOne"_s, UnitTest::X))))));
	checkSingleMemberStringArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberStringArrOne"_s, UnitTest::X))))));
	checkSingleMemberClassArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberClassArrOne"_s, UnitTest::X))))));
	checkSingleMemberEnumArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberEnumArrOne"_s, UnitTest::X))))));
	checkSingleMemberByteArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberByteArrTwo"_s, UnitTest::X))))));
	checkSingleMemberShortArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberShortArrTwo"_s, UnitTest::X))))));
	checkSingleMemberIntArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberIntArrTwo"_s, UnitTest::X))))));
	checkSingleMemberLongArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberLongArrTwo"_s, UnitTest::X))))));
	checkSingleMemberCharArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberCharArrTwo"_s, UnitTest::X))))));
	checkSingleMemberFloatArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberFloatArrTwo"_s, UnitTest::X))))));
	checkSingleMemberDoubleArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberDoubleArrTwo"_s, UnitTest::X))))));
	checkSingleMemberBooleanArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberBooleanArrTwo"_s, UnitTest::X))))));
	checkSingleMemberStringArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberStringArrTwo"_s, UnitTest::X))))));
	checkSingleMemberClassArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberClassArrTwo"_s, UnitTest::X))))));
	checkSingleMemberEnumArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberEnumArrTwo"_s, UnitTest::X))))));
	checkSingleMemberByteArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberByteArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberShortArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberShortArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberIntArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberIntArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberLongArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberLongArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberCharArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberCharArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberFloatArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberFloatArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberDoubleArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberDoubleArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberBooleanArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberBooleanArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberStringArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberStringArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberClassArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberClassArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberEnumArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberEnumArrOvrdDef"_s, UnitTest::X))))));
	checkSingleMemberByteArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberByteArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberShortArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberShortArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberIntArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberIntArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberLongArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberLongArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberCharArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberCharArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberFloatArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberFloatArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberDoubleArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberDoubleArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberBooleanArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberBooleanArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberStringArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberStringArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberClassArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberClassArrAcceptDef"_s, UnitTest::X))))));
	checkSingleMemberEnumArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getMethod("SingleMemberEnumArrAcceptDef"_s, UnitTest::X))))));
	checkScalarTypes($(UnitTest::class$->getField("scalarTypesField"_s)));
	checkScalarTypesAcceptDefault($(UnitTest::class$->getField("scalarTypesAcceptDefaultField"_s)));
	checkScalarTypesOverrideDefault($(UnitTest::class$->getField("scalarTypesOverrideDefaultField"_s)));
	checkArrayTypes0($(UnitTest::class$->getField("emptyArrayTypesField"_s)));
	checkArrayTypes1($(UnitTest::class$->getField("singleElementArrayTypesField"_s)));
	checkArrayTypes2($(UnitTest::class$->getField("twoElementArrayTypesField"_s)));
	checkArrayTypesAcceptDefault($(UnitTest::class$->getField("arrayTypesAcceptDefaultField"_s)));
	checkArrayTypesOverrideDefault($(UnitTest::class$->getField("arrayTypesOverrideDefaultField"_s)));
	checkMarker($(UnitTest::class$->getField("markerField"_s)));
	checkSingleMemberByte($(UnitTest::class$->getField("SingleMemberByteField"_s)));
	checkSingleMemberShort($(UnitTest::class$->getField("SingleMemberShortField"_s)));
	checkSingleMemberInt($(UnitTest::class$->getField("SingleMemberIntField"_s)));
	checkSingleMemberLong($(UnitTest::class$->getField("SingleMemberLongField"_s)));
	checkSingleMemberChar($(UnitTest::class$->getField("SingleMemberCharField"_s)));
	checkSingleMemberFloat($(UnitTest::class$->getField("SingleMemberFloatField"_s)));
	checkSingleMemberDouble($(UnitTest::class$->getField("SingleMemberDoubleField"_s)));
	checkSingleMemberBoolean($(UnitTest::class$->getField("SingleMemberBooleanField"_s)));
	checkSingleMemberString($(UnitTest::class$->getField("SingleMemberStringField"_s)));
	checkSingleMemberClass($(UnitTest::class$->getField("SingleMemberClassField"_s)));
	checkSingleMemberEnum($(UnitTest::class$->getField("SingleMemberEnumField"_s)));
	checkSingleMemberByteOvrdDef($(UnitTest::class$->getField("SingleMemberByteOvrdDefField"_s)));
	checkSingleMemberShortOvrdDef($(UnitTest::class$->getField("SingleMemberShortOvrdDefField"_s)));
	checkSingleMemberIntOvrdDef($(UnitTest::class$->getField("SingleMemberIntOvrdDefField"_s)));
	checkSingleMemberLongOvrdDef($(UnitTest::class$->getField("SingleMemberLongOvrdDefField"_s)));
	checkSingleMemberCharOvrdDef($(UnitTest::class$->getField("SingleMemberCharOvrdDefField"_s)));
	checkSingleMemberFloatOvrdDef($(UnitTest::class$->getField("SingleMemberFloatOvrdDefField"_s)));
	checkSingleMemberDoubleOvrdDef($(UnitTest::class$->getField("SingleMemberDoubleOvrdDefField"_s)));
	checkSingleMemberBooleanOvrdDef($(UnitTest::class$->getField("SingleMemberBooleanOvrdDefField"_s)));
	checkSingleMemberStringOvrdDef($(UnitTest::class$->getField("SingleMemberStringOvrdDefField"_s)));
	checkSingleMemberClassOvrdDef($(UnitTest::class$->getField("SingleMemberClassOvrdDefField"_s)));
	checkSingleMemberEnumOvrdDef($(UnitTest::class$->getField("SingleMemberEnumOvrdDefField"_s)));
	checkSingleMemberByteAcceptDef($(UnitTest::class$->getField("SingleMemberByteAcceptDefField"_s)));
	checkSingleMemberShortAcceptDef($(UnitTest::class$->getField("SingleMemberShortAcceptDefField"_s)));
	checkSingleMemberIntAcceptDef($(UnitTest::class$->getField("SingleMemberIntAcceptDefField"_s)));
	checkSingleMemberLongAcceptDef($(UnitTest::class$->getField("SingleMemberLongAcceptDefField"_s)));
	checkSingleMemberCharAcceptDef($(UnitTest::class$->getField("SingleMemberCharAcceptDefField"_s)));
	checkSingleMemberFloatAcceptDef($(UnitTest::class$->getField("SingleMemberFloatAcceptDefField"_s)));
	checkSingleMemberDoubleAcceptDef($(UnitTest::class$->getField("SingleMemberDoubleAcceptDefField"_s)));
	checkSingleMemberBooleanAcceptDef($(UnitTest::class$->getField("SingleMemberBooleanAcceptDefField"_s)));
	checkSingleMemberStringAcceptDef($(UnitTest::class$->getField("SingleMemberStringAcceptDefField"_s)));
	checkSingleMemberClassAcceptDef($(UnitTest::class$->getField("SingleMemberClassAcceptDefField"_s)));
	checkSingleMemberEnumAcceptDef($(UnitTest::class$->getField("SingleMemberEnumAcceptDefField"_s)));
	checkSingleMemberByteArrEmpty($(UnitTest::class$->getField("SingleMemberByteArrEmptyField"_s)));
	checkSingleMemberShortArrEmpty($(UnitTest::class$->getField("SingleMemberShortArrEmptyField"_s)));
	checkSingleMemberIntArrEmpty($(UnitTest::class$->getField("SingleMemberIntArrEmptyField"_s)));
	checkSingleMemberLongArrEmpty($(UnitTest::class$->getField("SingleMemberLongArrEmptyField"_s)));
	checkSingleMemberCharArrEmpty($(UnitTest::class$->getField("SingleMemberCharArrEmptyField"_s)));
	checkSingleMemberFloatArrEmpty($(UnitTest::class$->getField("SingleMemberFloatArrEmptyField"_s)));
	checkSingleMemberDoubleArrEmpty($(UnitTest::class$->getField("SingleMemberDoubleArrEmptyField"_s)));
	checkSingleMemberBooleanArrEmpty($(UnitTest::class$->getField("SingleMemberBooleanArrEmptyField"_s)));
	checkSingleMemberStringArrEmpty($(UnitTest::class$->getField("SingleMemberStringArrEmptyField"_s)));
	checkSingleMemberClassArrEmpty($(UnitTest::class$->getField("SingleMemberClassArrEmptyField"_s)));
	checkSingleMemberEnumArrEmpty($(UnitTest::class$->getField("SingleMemberEnumArrEmptyField"_s)));
	checkSingleMemberByteArrOne($(UnitTest::class$->getField("SingleMemberByteArrOneField"_s)));
	checkSingleMemberShortArrOne($(UnitTest::class$->getField("SingleMemberShortArrOneField"_s)));
	checkSingleMemberIntArrOne($(UnitTest::class$->getField("SingleMemberIntArrOneField"_s)));
	checkSingleMemberLongArrOne($(UnitTest::class$->getField("SingleMemberLongArrOneField"_s)));
	checkSingleMemberCharArrOne($(UnitTest::class$->getField("SingleMemberCharArrOneField"_s)));
	checkSingleMemberFloatArrOne($(UnitTest::class$->getField("SingleMemberFloatArrOneField"_s)));
	checkSingleMemberDoubleArrOne($(UnitTest::class$->getField("SingleMemberDoubleArrOneField"_s)));
	checkSingleMemberBooleanArrOne($(UnitTest::class$->getField("SingleMemberBooleanArrOneField"_s)));
	checkSingleMemberStringArrOne($(UnitTest::class$->getField("SingleMemberStringArrOneField"_s)));
	checkSingleMemberClassArrOne($(UnitTest::class$->getField("SingleMemberClassArrOneField"_s)));
	checkSingleMemberEnumArrOne($(UnitTest::class$->getField("SingleMemberEnumArrOneField"_s)));
	checkSingleMemberByteArrTwo($(UnitTest::class$->getField("SingleMemberByteArrTwoField"_s)));
	checkSingleMemberShortArrTwo($(UnitTest::class$->getField("SingleMemberShortArrTwoField"_s)));
	checkSingleMemberIntArrTwo($(UnitTest::class$->getField("SingleMemberIntArrTwoField"_s)));
	checkSingleMemberLongArrTwo($(UnitTest::class$->getField("SingleMemberLongArrTwoField"_s)));
	checkSingleMemberCharArrTwo($(UnitTest::class$->getField("SingleMemberCharArrTwoField"_s)));
	checkSingleMemberFloatArrTwo($(UnitTest::class$->getField("SingleMemberFloatArrTwoField"_s)));
	checkSingleMemberDoubleArrTwo($(UnitTest::class$->getField("SingleMemberDoubleArrTwoField"_s)));
	checkSingleMemberBooleanArrTwo($(UnitTest::class$->getField("SingleMemberBooleanArrTwoField"_s)));
	checkSingleMemberStringArrTwo($(UnitTest::class$->getField("SingleMemberStringArrTwoField"_s)));
	checkSingleMemberClassArrTwo($(UnitTest::class$->getField("SingleMemberClassArrTwoField"_s)));
	checkSingleMemberEnumArrTwo($(UnitTest::class$->getField("SingleMemberEnumArrTwoField"_s)));
	checkSingleMemberByteArrOvrdDef($(UnitTest::class$->getField("SingleMemberByteArrOvrdDefField"_s)));
	checkSingleMemberShortArrOvrdDef($(UnitTest::class$->getField("SingleMemberShortArrOvrdDefField"_s)));
	checkSingleMemberIntArrOvrdDef($(UnitTest::class$->getField("SingleMemberIntArrOvrdDefField"_s)));
	checkSingleMemberLongArrOvrdDef($(UnitTest::class$->getField("SingleMemberLongArrOvrdDefField"_s)));
	checkSingleMemberCharArrOvrdDef($(UnitTest::class$->getField("SingleMemberCharArrOvrdDefField"_s)));
	checkSingleMemberFloatArrOvrdDef($(UnitTest::class$->getField("SingleMemberFloatArrOvrdDefField"_s)));
	checkSingleMemberDoubleArrOvrdDef($(UnitTest::class$->getField("SingleMemberDoubleArrOvrdDefField"_s)));
	checkSingleMemberBooleanArrOvrdDef($(UnitTest::class$->getField("SingleMemberBooleanArrOvrdDefField"_s)));
	checkSingleMemberStringArrOvrdDef($(UnitTest::class$->getField("SingleMemberStringArrOvrdDefField"_s)));
	checkSingleMemberClassArrOvrdDef($(UnitTest::class$->getField("SingleMemberClassArrOvrdDefField"_s)));
	checkSingleMemberEnumArrOvrdDef($(UnitTest::class$->getField("SingleMemberEnumArrOvrdDefField"_s)));
	checkSingleMemberByteArrAcceptDef($(UnitTest::class$->getField("SingleMemberByteArrAcceptDefField"_s)));
	checkSingleMemberShortArrAcceptDef($(UnitTest::class$->getField("SingleMemberShortArrAcceptDefField"_s)));
	checkSingleMemberIntArrAcceptDef($(UnitTest::class$->getField("SingleMemberIntArrAcceptDefField"_s)));
	checkSingleMemberLongArrAcceptDef($(UnitTest::class$->getField("SingleMemberLongArrAcceptDefField"_s)));
	checkSingleMemberCharArrAcceptDef($(UnitTest::class$->getField("SingleMemberCharArrAcceptDefField"_s)));
	checkSingleMemberFloatArrAcceptDef($(UnitTest::class$->getField("SingleMemberFloatArrAcceptDefField"_s)));
	checkSingleMemberDoubleArrAcceptDef($(UnitTest::class$->getField("SingleMemberDoubleArrAcceptDefField"_s)));
	checkSingleMemberBooleanArrAcceptDef($(UnitTest::class$->getField("SingleMemberBooleanArrAcceptDefField"_s)));
	checkSingleMemberStringArrAcceptDef($(UnitTest::class$->getField("SingleMemberStringArrAcceptDefField"_s)));
	checkSingleMemberClassArrAcceptDef($(UnitTest::class$->getField("SingleMemberClassArrAcceptDefField"_s)));
	checkSingleMemberEnumArrAcceptDef($(UnitTest::class$->getField("SingleMemberEnumArrAcceptDefField"_s)));
	$load($UnitTest$TestType);
	checkScalarTypes($($UnitTest$TestType::class$->getField("scalarTypesField"_s)));
	checkScalarTypesAcceptDefault($($UnitTest$TestType::class$->getField("scalarTypesAcceptDefaultField"_s)));
	checkScalarTypesOverrideDefault($($UnitTest$TestType::class$->getField("scalarTypesOverrideDefaultField"_s)));
	checkArrayTypes0($($UnitTest$TestType::class$->getField("emptyArrayTypesField"_s)));
	checkArrayTypes1($($UnitTest$TestType::class$->getField("singleElementArrayTypesField"_s)));
	checkArrayTypes2($($UnitTest$TestType::class$->getField("twoElementArrayTypesField"_s)));
	checkArrayTypesAcceptDefault($($UnitTest$TestType::class$->getField("arrayTypesAcceptDefaultField"_s)));
	checkArrayTypesOverrideDefault($($UnitTest$TestType::class$->getField("arrayTypesOverrideDefaultField"_s)));
	checkMarker($($UnitTest$TestType::class$->getField("marker"_s)));
	checkSingleMemberByte($($UnitTest$TestType::class$->getField("SingleMemberByte"_s)));
	checkSingleMemberShort($($UnitTest$TestType::class$->getField("SingleMemberShort"_s)));
	checkSingleMemberInt($($UnitTest$TestType::class$->getField("SingleMemberInt"_s)));
	checkSingleMemberLong($($UnitTest$TestType::class$->getField("SingleMemberLong"_s)));
	checkSingleMemberChar($($UnitTest$TestType::class$->getField("SingleMemberChar"_s)));
	checkSingleMemberFloat($($UnitTest$TestType::class$->getField("SingleMemberFloat"_s)));
	checkSingleMemberDouble($($UnitTest$TestType::class$->getField("SingleMemberDouble"_s)));
	checkSingleMemberBoolean($($UnitTest$TestType::class$->getField("SingleMemberBoolean"_s)));
	checkSingleMemberString($($UnitTest$TestType::class$->getField("SingleMemberString"_s)));
	checkSingleMemberClass($($UnitTest$TestType::class$->getField("SingleMemberClass"_s)));
	checkSingleMemberEnum($($UnitTest$TestType::class$->getField("SingleMemberEnum"_s)));
	checkSingleMemberByteOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberByteOvrdDef"_s)));
	checkSingleMemberShortOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberShortOvrdDef"_s)));
	checkSingleMemberIntOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberIntOvrdDef"_s)));
	checkSingleMemberLongOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberLongOvrdDef"_s)));
	checkSingleMemberCharOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberCharOvrdDef"_s)));
	checkSingleMemberFloatOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberFloatOvrdDef"_s)));
	checkSingleMemberDoubleOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberDoubleOvrdDef"_s)));
	checkSingleMemberBooleanOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberBooleanOvrdDef"_s)));
	checkSingleMemberStringOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberStringOvrdDef"_s)));
	checkSingleMemberClassOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberClassOvrdDef"_s)));
	checkSingleMemberEnumOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberEnumOvrdDef"_s)));
	checkSingleMemberByteAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberByteAcceptDef"_s)));
	checkSingleMemberShortAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberShortAcceptDef"_s)));
	checkSingleMemberIntAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberIntAcceptDef"_s)));
	checkSingleMemberLongAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberLongAcceptDef"_s)));
	checkSingleMemberCharAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberCharAcceptDef"_s)));
	checkSingleMemberFloatAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberFloatAcceptDef"_s)));
	checkSingleMemberDoubleAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberDoubleAcceptDef"_s)));
	checkSingleMemberBooleanAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberBooleanAcceptDef"_s)));
	checkSingleMemberStringAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberStringAcceptDef"_s)));
	checkSingleMemberClassAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberClassAcceptDef"_s)));
	checkSingleMemberEnumAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberEnumAcceptDef"_s)));
	checkSingleMemberByteArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberByteArrEmpty"_s)));
	checkSingleMemberShortArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberShortArrEmpty"_s)));
	checkSingleMemberIntArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberIntArrEmpty"_s)));
	checkSingleMemberLongArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberLongArrEmpty"_s)));
	checkSingleMemberCharArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberCharArrEmpty"_s)));
	checkSingleMemberFloatArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberFloatArrEmpty"_s)));
	checkSingleMemberDoubleArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberDoubleArrEmpty"_s)));
	checkSingleMemberBooleanArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberBooleanArrEmpty"_s)));
	checkSingleMemberStringArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberStringArrEmpty"_s)));
	checkSingleMemberClassArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberClassArrEmpty"_s)));
	checkSingleMemberEnumArrEmpty($($UnitTest$TestType::class$->getField("SingleMemberEnumArrEmpty"_s)));
	checkSingleMemberByteArrOne($($UnitTest$TestType::class$->getField("SingleMemberByteArrOne"_s)));
	checkSingleMemberShortArrOne($($UnitTest$TestType::class$->getField("SingleMemberShortArrOne"_s)));
	checkSingleMemberIntArrOne($($UnitTest$TestType::class$->getField("SingleMemberIntArrOne"_s)));
	checkSingleMemberLongArrOne($($UnitTest$TestType::class$->getField("SingleMemberLongArrOne"_s)));
	checkSingleMemberCharArrOne($($UnitTest$TestType::class$->getField("SingleMemberCharArrOne"_s)));
	checkSingleMemberFloatArrOne($($UnitTest$TestType::class$->getField("SingleMemberFloatArrOne"_s)));
	checkSingleMemberDoubleArrOne($($UnitTest$TestType::class$->getField("SingleMemberDoubleArrOne"_s)));
	checkSingleMemberBooleanArrOne($($UnitTest$TestType::class$->getField("SingleMemberBooleanArrOne"_s)));
	checkSingleMemberStringArrOne($($UnitTest$TestType::class$->getField("SingleMemberStringArrOne"_s)));
	checkSingleMemberClassArrOne($($UnitTest$TestType::class$->getField("SingleMemberClassArrOne"_s)));
	checkSingleMemberEnumArrOne($($UnitTest$TestType::class$->getField("SingleMemberEnumArrOne"_s)));
	checkSingleMemberByteArrTwo($($UnitTest$TestType::class$->getField("SingleMemberByteArrTwo"_s)));
	checkSingleMemberShortArrTwo($($UnitTest$TestType::class$->getField("SingleMemberShortArrTwo"_s)));
	checkSingleMemberIntArrTwo($($UnitTest$TestType::class$->getField("SingleMemberIntArrTwo"_s)));
	checkSingleMemberLongArrTwo($($UnitTest$TestType::class$->getField("SingleMemberLongArrTwo"_s)));
	checkSingleMemberCharArrTwo($($UnitTest$TestType::class$->getField("SingleMemberCharArrTwo"_s)));
	checkSingleMemberFloatArrTwo($($UnitTest$TestType::class$->getField("SingleMemberFloatArrTwo"_s)));
	checkSingleMemberDoubleArrTwo($($UnitTest$TestType::class$->getField("SingleMemberDoubleArrTwo"_s)));
	checkSingleMemberBooleanArrTwo($($UnitTest$TestType::class$->getField("SingleMemberBooleanArrTwo"_s)));
	checkSingleMemberStringArrTwo($($UnitTest$TestType::class$->getField("SingleMemberStringArrTwo"_s)));
	checkSingleMemberClassArrTwo($($UnitTest$TestType::class$->getField("SingleMemberClassArrTwo"_s)));
	checkSingleMemberEnumArrTwo($($UnitTest$TestType::class$->getField("SingleMemberEnumArrTwo"_s)));
	checkSingleMemberByteArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberByteArrOvrdDef"_s)));
	checkSingleMemberShortArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberShortArrOvrdDef"_s)));
	checkSingleMemberIntArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberIntArrOvrdDef"_s)));
	checkSingleMemberLongArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberLongArrOvrdDef"_s)));
	checkSingleMemberCharArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberCharArrOvrdDef"_s)));
	checkSingleMemberFloatArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberFloatArrOvrdDef"_s)));
	checkSingleMemberDoubleArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberDoubleArrOvrdDef"_s)));
	checkSingleMemberBooleanArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberBooleanArrOvrdDef"_s)));
	checkSingleMemberStringArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberStringArrOvrdDef"_s)));
	checkSingleMemberClassArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberClassArrOvrdDef"_s)));
	checkSingleMemberEnumArrOvrdDef($($UnitTest$TestType::class$->getField("SingleMemberEnumArrOvrdDef"_s)));
	checkSingleMemberByteArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberByteArrAcceptDef"_s)));
	checkSingleMemberShortArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberShortArrAcceptDef"_s)));
	checkSingleMemberIntArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberIntArrAcceptDef"_s)));
	checkSingleMemberLongArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberLongArrAcceptDef"_s)));
	checkSingleMemberCharArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberCharArrAcceptDef"_s)));
	checkSingleMemberFloatArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberFloatArrAcceptDef"_s)));
	checkSingleMemberDoubleArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberDoubleArrAcceptDef"_s)));
	checkSingleMemberBooleanArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberBooleanArrAcceptDef"_s)));
	checkSingleMemberStringArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberStringArrAcceptDef"_s)));
	checkSingleMemberClassArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberClassArrAcceptDef"_s)));
	checkSingleMemberEnumArrAcceptDef($($UnitTest$TestType::class$->getField("SingleMemberEnumArrAcceptDef"_s)));
	$load($Iterator);
	checkScalarTypes($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Iterator::class$})))))));
	$load($Map);
	checkScalarTypesOverrideDefault($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Map::class$})))))));
	$load($Set);
	checkScalarTypesAcceptDefault($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Set::class$})))))));
	$load($List);
	checkArrayTypes0($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$List::class$})))))));
	$load($Collection);
	checkArrayTypes1($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Collection::class$})))))));
	$load($SortedSet);
	checkArrayTypes2($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$SortedSet::class$})))))));
	$load($SortedMap);
	checkArrayTypesAcceptDefault($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$SortedMap::class$})))))));
	$load($RandomAccess);
	checkArrayTypesOverrideDefault($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$RandomAccess::class$})))))));
	checkMarker($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, 0)))))));
	$init($Byte);
	checkSingleMemberByte($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Byte::TYPE})))))));
	$init($Short);
	checkSingleMemberShort($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Short::TYPE})))))));
	$init($Integer);
	checkSingleMemberInt($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Integer::TYPE})))))));
	$init($Long);
	checkSingleMemberLong($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Long::TYPE})))))));
	$init($Character);
	checkSingleMemberChar($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Character::TYPE})))))));
	$init($Float);
	checkSingleMemberFloat($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Float::TYPE})))))));
	$init($Double);
	checkSingleMemberDouble($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Double::TYPE})))))));
	$init($Boolean);
	checkSingleMemberBoolean($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Boolean::TYPE})))))));
	checkSingleMemberString($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$String::class$})))))));
	checkSingleMemberClass($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Class::class$})))))));
	$load($Enum);
	checkSingleMemberEnum($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$Enum::class$})))))));
	checkSingleMemberByteOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Byte::TYPE,
		$Set::class$
	})))))));
	checkSingleMemberShortOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Short::TYPE,
		$Set::class$
	})))))));
	checkSingleMemberIntOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Integer::TYPE,
		$Set::class$
	})))))));
	checkSingleMemberLongOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Long::TYPE,
		$Set::class$
	})))))));
	checkSingleMemberCharOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Character::TYPE,
		$Set::class$
	})))))));
	checkSingleMemberFloatOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Float::TYPE,
		$Set::class$
	})))))));
	checkSingleMemberDoubleOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Double::TYPE,
		$Set::class$
	})))))));
	checkSingleMemberBooleanOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Boolean::TYPE,
		$Set::class$
	})))))));
	checkSingleMemberStringOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$String::class$,
		$Set::class$
	})))))));
	checkSingleMemberClassOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Class::class$,
		$Set::class$
	})))))));
	checkSingleMemberEnumOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Enum::class$,
		$Set::class$
	})))))));
	checkSingleMemberByteAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Byte::TYPE,
		$Map::class$
	})))))));
	checkSingleMemberShortAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Short::TYPE,
		$Map::class$
	})))))));
	checkSingleMemberIntAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Integer::TYPE,
		$Map::class$
	})))))));
	checkSingleMemberLongAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Long::TYPE,
		$Map::class$
	})))))));
	checkSingleMemberCharAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Character::TYPE,
		$Map::class$
	})))))));
	checkSingleMemberFloatAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Float::TYPE,
		$Map::class$
	})))))));
	checkSingleMemberDoubleAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Double::TYPE,
		$Map::class$
	})))))));
	checkSingleMemberBooleanAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Boolean::TYPE,
		$Map::class$
	})))))));
	checkSingleMemberStringAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$String::class$,
		$Map::class$
	})))))));
	checkSingleMemberClassAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Class::class$,
		$Map::class$
	})))))));
	checkSingleMemberEnumAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$Enum::class$,
		$Map::class$
	})))))));
	$load($bytes);
	checkSingleMemberByteArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($bytes)})))))));
	$load($shorts);
	checkSingleMemberShortArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($shorts)})))))));
	$load($ints);
	checkSingleMemberIntArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($ints)})))))));
	$load($longs);
	checkSingleMemberLongArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($longs)})))))));
	$load($chars);
	checkSingleMemberCharArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($chars)})))))));
	$load($floats);
	checkSingleMemberFloatArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($floats)})))))));
	$load($doubles);
	checkSingleMemberDoubleArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($doubles)})))))));
	$load($booleans);
	checkSingleMemberBooleanArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($booleans)})))))));
	$load($StringArray);
	checkSingleMemberStringArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($StringArray)})))))));
	$load($ClassArray);
	checkSingleMemberClassArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($ClassArray)})))))));
	$load($EnumArray);
	checkSingleMemberEnumArrEmpty($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {$getClass($EnumArray)})))))));
	checkSingleMemberByteArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($bytes),
		$Set::class$
	})))))));
	checkSingleMemberShortArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($shorts),
		$Set::class$
	})))))));
	checkSingleMemberIntArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($ints),
		$Set::class$
	})))))));
	checkSingleMemberLongArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($longs),
		$Set::class$
	})))))));
	checkSingleMemberCharArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($chars),
		$Set::class$
	})))))));
	checkSingleMemberFloatArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($floats),
		$Set::class$
	})))))));
	checkSingleMemberDoubleArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($doubles),
		$Set::class$
	})))))));
	checkSingleMemberBooleanArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($booleans),
		$Set::class$
	})))))));
	checkSingleMemberStringArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($StringArray),
		$Set::class$
	})))))));
	checkSingleMemberClassArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($ClassArray),
		$Set::class$
	})))))));
	checkSingleMemberEnumArrOne($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($EnumArray),
		$Set::class$
	})))))));
	checkSingleMemberByteArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($bytes),
		$Map::class$
	})))))));
	checkSingleMemberShortArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($shorts),
		$Map::class$
	})))))));
	checkSingleMemberIntArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($ints),
		$Map::class$
	})))))));
	checkSingleMemberLongArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($longs),
		$Map::class$
	})))))));
	checkSingleMemberCharArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($chars),
		$Map::class$
	})))))));
	checkSingleMemberFloatArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($floats),
		$Map::class$
	})))))));
	checkSingleMemberDoubleArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($doubles),
		$Map::class$
	})))))));
	checkSingleMemberBooleanArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($booleans),
		$Map::class$
	})))))));
	checkSingleMemberStringArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($StringArray),
		$Map::class$
	})))))));
	checkSingleMemberClassArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($ClassArray),
		$Map::class$
	})))))));
	checkSingleMemberEnumArrTwo($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($EnumArray),
		$Map::class$
	})))))));
	checkSingleMemberByteArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($bytes),
		$List::class$
	})))))));
	checkSingleMemberShortArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($shorts),
		$List::class$
	})))))));
	checkSingleMemberIntArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($ints),
		$List::class$
	})))))));
	checkSingleMemberLongArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($longs),
		$List::class$
	})))))));
	checkSingleMemberCharArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($chars),
		$List::class$
	})))))));
	checkSingleMemberFloatArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($floats),
		$List::class$
	})))))));
	checkSingleMemberDoubleArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($doubles),
		$List::class$
	})))))));
	checkSingleMemberBooleanArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($booleans),
		$List::class$
	})))))));
	checkSingleMemberStringArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($StringArray),
		$List::class$
	})))))));
	checkSingleMemberClassArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($ClassArray),
		$List::class$
	})))))));
	checkSingleMemberEnumArrOvrdDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($EnumArray),
		$List::class$
	})))))));
	checkSingleMemberByteArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($bytes),
		$Collection::class$
	})))))));
	checkSingleMemberShortArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($shorts),
		$Collection::class$
	})))))));
	checkSingleMemberIntArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($ints),
		$Collection::class$
	})))))));
	checkSingleMemberLongArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($longs),
		$Collection::class$
	})))))));
	checkSingleMemberCharArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($chars),
		$Collection::class$
	})))))));
	checkSingleMemberFloatArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($floats),
		$Collection::class$
	})))))));
	checkSingleMemberDoubleArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($doubles),
		$Collection::class$
	})))))));
	checkSingleMemberBooleanArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($booleans),
		$Collection::class$
	})))))));
	checkSingleMemberStringArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($StringArray),
		$Collection::class$
	})))))));
	checkSingleMemberClassArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($ClassArray),
		$Collection::class$
	})))))));
	checkSingleMemberEnumArrAcceptDef($(static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(UnitTest::class$->getConstructor($$new($ClassArray, {
		$getClass($EnumArray),
		$Collection::class$
	})))))));
	checkScalarTypesParam($(UnitTest::class$->getMethod("scalarTypesParam"_s, UnitTest::Y)));
	checkScalarTypesOverrideDefaultParam($(UnitTest::class$->getMethod("scalarTypesOverrideDefaultParam"_s, UnitTest::Y)));
	checkScalarTypesAcceptDefaultParam($(UnitTest::class$->getMethod("scalarTypesAcceptDefaultParam"_s, UnitTest::Y)));
	checkArrayTypes0Param($(UnitTest::class$->getMethod("emptyArrayTypesParam"_s, UnitTest::Y)));
	checkArrayTypes1Param($(UnitTest::class$->getMethod("singleElementArrayTypesParam"_s, UnitTest::Y)));
	checkArrayTypes2Param($(UnitTest::class$->getMethod("twoElementArrayTypesParam"_s, UnitTest::Y)));
	checkArrayTypesAcceptDefaultParam($(UnitTest::class$->getMethod("arrayTypesAcceptDefaultParam"_s, UnitTest::Y)));
	checkArrayTypesOverrideDefaultParam($(UnitTest::class$->getMethod("arrayTypesOverrideDefaultParam"_s, UnitTest::Y)));
	checkMarkerParam($(UnitTest::class$->getMethod("markerParam"_s, UnitTest::Y)));
	checkSingleMemberByteParam($(UnitTest::class$->getMethod("SingleMemberByteParam"_s, UnitTest::Y)));
	checkSingleMemberShortParam($(UnitTest::class$->getMethod("SingleMemberShortParam"_s, UnitTest::Y)));
	checkSingleMemberIntParam($(UnitTest::class$->getMethod("SingleMemberIntParam"_s, UnitTest::Y)));
	checkSingleMemberLongParam($(UnitTest::class$->getMethod("SingleMemberLongParam"_s, UnitTest::Y)));
	checkSingleMemberCharParam($(UnitTest::class$->getMethod("SingleMemberCharParam"_s, UnitTest::Y)));
	checkSingleMemberFloatParam($(UnitTest::class$->getMethod("SingleMemberFloatParam"_s, UnitTest::Y)));
	checkSingleMemberDoubleParam($(UnitTest::class$->getMethod("SingleMemberDoubleParam"_s, UnitTest::Y)));
	checkSingleMemberBooleanParam($(UnitTest::class$->getMethod("SingleMemberBooleanParam"_s, UnitTest::Y)));
	checkSingleMemberStringParam($(UnitTest::class$->getMethod("SingleMemberStringParam"_s, UnitTest::Y)));
	checkSingleMemberClassParam($(UnitTest::class$->getMethod("SingleMemberClassParam"_s, UnitTest::Y)));
	checkSingleMemberEnumParam($(UnitTest::class$->getMethod("SingleMemberEnumParam"_s, UnitTest::Y)));
	checkSingleMemberByteOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberByteOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberShortOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberShortOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberIntOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberIntOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberLongOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberLongOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberCharOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberCharOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberFloatOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberFloatOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberDoubleOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberDoubleOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberBooleanOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberBooleanOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberStringOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberStringOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberClassOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberClassOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberEnumOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberEnumOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberByteAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberByteAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberShortAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberShortAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberIntAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberIntAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberLongAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberLongAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberCharAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberCharAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberFloatAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberFloatAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberDoubleAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberDoubleAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberBooleanAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberBooleanAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberStringAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberStringAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberClassAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberClassAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberEnumAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberEnumAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberByteArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberByteArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberShortArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberShortArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberIntArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberIntArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberLongArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberLongArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberCharArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberCharArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberFloatArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberFloatArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberDoubleArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberDoubleArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberBooleanArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberBooleanArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberStringArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberStringArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberClassArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberClassArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberEnumArrEmptyParam($(UnitTest::class$->getMethod("SingleMemberEnumArrEmptyParam"_s, UnitTest::Y)));
	checkSingleMemberByteArrOneParam($(UnitTest::class$->getMethod("SingleMemberByteArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberShortArrOneParam($(UnitTest::class$->getMethod("SingleMemberShortArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberIntArrOneParam($(UnitTest::class$->getMethod("SingleMemberIntArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberLongArrOneParam($(UnitTest::class$->getMethod("SingleMemberLongArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberCharArrOneParam($(UnitTest::class$->getMethod("SingleMemberCharArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberFloatArrOneParam($(UnitTest::class$->getMethod("SingleMemberFloatArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberDoubleArrOneParam($(UnitTest::class$->getMethod("SingleMemberDoubleArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberBooleanArrOneParam($(UnitTest::class$->getMethod("SingleMemberBooleanArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberStringArrOneParam($(UnitTest::class$->getMethod("SingleMemberStringArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberClassArrOneParam($(UnitTest::class$->getMethod("SingleMemberClassArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberEnumArrOneParam($(UnitTest::class$->getMethod("SingleMemberEnumArrOneParam"_s, UnitTest::Y)));
	checkSingleMemberByteArrTwoParam($(UnitTest::class$->getMethod("SingleMemberByteArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberShortArrTwoParam($(UnitTest::class$->getMethod("SingleMemberShortArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberIntArrTwoParam($(UnitTest::class$->getMethod("SingleMemberIntArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberLongArrTwoParam($(UnitTest::class$->getMethod("SingleMemberLongArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberCharArrTwoParam($(UnitTest::class$->getMethod("SingleMemberCharArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberFloatArrTwoParam($(UnitTest::class$->getMethod("SingleMemberFloatArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberDoubleArrTwoParam($(UnitTest::class$->getMethod("SingleMemberDoubleArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberBooleanArrTwoParam($(UnitTest::class$->getMethod("SingleMemberBooleanArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberStringArrTwoParam($(UnitTest::class$->getMethod("SingleMemberStringArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberClassArrTwoParam($(UnitTest::class$->getMethod("SingleMemberClassArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberEnumArrTwoParam($(UnitTest::class$->getMethod("SingleMemberEnumArrTwoParam"_s, UnitTest::Y)));
	checkSingleMemberByteArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberByteArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberShortArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberShortArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberIntArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberIntArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberLongArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberLongArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberCharArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberCharArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberFloatArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberFloatArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberDoubleArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberDoubleArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberBooleanArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberBooleanArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberStringArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberStringArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberClassArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberClassArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberEnumArrOvrdDefParam($(UnitTest::class$->getMethod("SingleMemberEnumArrOvrdDefParam"_s, UnitTest::Y)));
	checkSingleMemberByteArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberByteArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberShortArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberShortArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberIntArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberIntArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberLongArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberLongArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberCharArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberCharArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberFloatArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberFloatArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberDoubleArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberDoubleArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberBooleanArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberBooleanArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberStringArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberStringArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberClassArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberClassArrAcceptDefParam"_s, UnitTest::Y)));
	checkSingleMemberEnumArrAcceptDefParam($(UnitTest::class$->getMethod("SingleMemberEnumArrAcceptDefParam"_s, UnitTest::Y)));
	$load($scalarTypesClass);
	checkScalarTypes($scalarTypesClass::class$);
	$load($scalarTypesOverrideDefaultClass);
	checkScalarTypesOverrideDefault($scalarTypesOverrideDefaultClass::class$);
	$load($scalarTypesAcceptDefaultClass);
	checkScalarTypesAcceptDefault($scalarTypesAcceptDefaultClass::class$);
	$load($emptyArrayTypesClass);
	checkArrayTypes0($emptyArrayTypesClass::class$);
	$load($singleElementArrayTypesClass);
	checkArrayTypes1($singleElementArrayTypesClass::class$);
	$load($twoElementArrayTypesClass);
	checkArrayTypes2($twoElementArrayTypesClass::class$);
	$load($arrayTypesOverrideDefaultClass);
	checkArrayTypesOverrideDefault($arrayTypesOverrideDefaultClass::class$);
	$load($arrayTypesAcceptDefaultClass);
	checkArrayTypesAcceptDefault($arrayTypesAcceptDefaultClass::class$);
	$load($markerClass);
	checkMarker($markerClass::class$);
	$load($SingleMemberByteClass);
	checkSingleMemberByte($SingleMemberByteClass::class$);
	$load($SingleMemberShortClass);
	checkSingleMemberShort($SingleMemberShortClass::class$);
	$load($SingleMemberIntClass);
	checkSingleMemberInt($SingleMemberIntClass::class$);
	$load($SingleMemberLongClass);
	checkSingleMemberLong($SingleMemberLongClass::class$);
	$load($SingleMemberCharClass);
	checkSingleMemberChar($SingleMemberCharClass::class$);
	$load($SingleMemberFloatClass);
	checkSingleMemberFloat($SingleMemberFloatClass::class$);
	$load($SingleMemberDoubleClass);
	checkSingleMemberDouble($SingleMemberDoubleClass::class$);
	$load($SingleMemberBooleanClass);
	checkSingleMemberBoolean($SingleMemberBooleanClass::class$);
	$load($SingleMemberStringClass);
	checkSingleMemberString($SingleMemberStringClass::class$);
	$load($SingleMemberClassClass);
	checkSingleMemberClass($SingleMemberClassClass::class$);
	$load($SingleMemberEnumClass);
	checkSingleMemberEnum($SingleMemberEnumClass::class$);
	$load($SingleMemberByteOvrdDefClass);
	checkSingleMemberByteOvrdDef($SingleMemberByteOvrdDefClass::class$);
	$load($SingleMemberShortOvrdDefClass);
	checkSingleMemberShortOvrdDef($SingleMemberShortOvrdDefClass::class$);
	$load($SingleMemberIntOvrdDefClass);
	checkSingleMemberIntOvrdDef($SingleMemberIntOvrdDefClass::class$);
	$load($SingleMemberLongOvrdDefClass);
	checkSingleMemberLongOvrdDef($SingleMemberLongOvrdDefClass::class$);
	$load($SingleMemberCharOvrdDefClass);
	checkSingleMemberCharOvrdDef($SingleMemberCharOvrdDefClass::class$);
	$load($SingleMemberFloatOvrdDefClass);
	checkSingleMemberFloatOvrdDef($SingleMemberFloatOvrdDefClass::class$);
	$load($SingleMemberDoubleOvrdDefClass);
	checkSingleMemberDoubleOvrdDef($SingleMemberDoubleOvrdDefClass::class$);
	$load($SingleMemberBooleanOvrdDefClass);
	checkSingleMemberBooleanOvrdDef($SingleMemberBooleanOvrdDefClass::class$);
	$load($SingleMemberStringOvrdDefClass);
	checkSingleMemberStringOvrdDef($SingleMemberStringOvrdDefClass::class$);
	$load($SingleMemberClassOvrdDefClass);
	checkSingleMemberClassOvrdDef($SingleMemberClassOvrdDefClass::class$);
	$load($SingleMemberEnumOvrdDefClass);
	checkSingleMemberEnumOvrdDef($SingleMemberEnumOvrdDefClass::class$);
	$load($SingleMemberByteAcceptDefClass);
	checkSingleMemberByteAcceptDef($SingleMemberByteAcceptDefClass::class$);
	$load($SingleMemberShortAcceptDefClass);
	checkSingleMemberShortAcceptDef($SingleMemberShortAcceptDefClass::class$);
	$load($SingleMemberIntAcceptDefClass);
	checkSingleMemberIntAcceptDef($SingleMemberIntAcceptDefClass::class$);
	$load($SingleMemberLongAcceptDefClass);
	checkSingleMemberLongAcceptDef($SingleMemberLongAcceptDefClass::class$);
	$load($SingleMemberCharAcceptDefClass);
	checkSingleMemberCharAcceptDef($SingleMemberCharAcceptDefClass::class$);
	$load($SingleMemberFloatAcceptDefClass);
	checkSingleMemberFloatAcceptDef($SingleMemberFloatAcceptDefClass::class$);
	$load($SingleMemberDoubleAcceptDefClass);
	checkSingleMemberDoubleAcceptDef($SingleMemberDoubleAcceptDefClass::class$);
	$load($SingleMemberBooleanAcceptDefClass);
	checkSingleMemberBooleanAcceptDef($SingleMemberBooleanAcceptDefClass::class$);
	$load($SingleMemberStringAcceptDefClass);
	checkSingleMemberStringAcceptDef($SingleMemberStringAcceptDefClass::class$);
	$load($SingleMemberClassAcceptDefClass);
	checkSingleMemberClassAcceptDef($SingleMemberClassAcceptDefClass::class$);
	$load($SingleMemberEnumAcceptDefClass);
	checkSingleMemberEnumAcceptDef($SingleMemberEnumAcceptDefClass::class$);
	$load($SingleMemberByteArrEmptyClass);
	checkSingleMemberByteArrEmpty($SingleMemberByteArrEmptyClass::class$);
	$load($SingleMemberShortArrEmptyClass);
	checkSingleMemberShortArrEmpty($SingleMemberShortArrEmptyClass::class$);
	$load($SingleMemberIntArrEmptyClass);
	checkSingleMemberIntArrEmpty($SingleMemberIntArrEmptyClass::class$);
	$load($SingleMemberLongArrEmptyClass);
	checkSingleMemberLongArrEmpty($SingleMemberLongArrEmptyClass::class$);
	$load($SingleMemberCharArrEmptyClass);
	checkSingleMemberCharArrEmpty($SingleMemberCharArrEmptyClass::class$);
	$load($SingleMemberFloatArrEmptyClass);
	checkSingleMemberFloatArrEmpty($SingleMemberFloatArrEmptyClass::class$);
	$load($SingleMemberDoubleArrEmptyClass);
	checkSingleMemberDoubleArrEmpty($SingleMemberDoubleArrEmptyClass::class$);
	$load($SingleMemberBooleanArrEmptyClass);
	checkSingleMemberBooleanArrEmpty($SingleMemberBooleanArrEmptyClass::class$);
	$load($SingleMemberStringArrEmptyClass);
	checkSingleMemberStringArrEmpty($SingleMemberStringArrEmptyClass::class$);
	$load($SingleMemberClassArrEmptyClass);
	checkSingleMemberClassArrEmpty($SingleMemberClassArrEmptyClass::class$);
	$load($SingleMemberEnumArrEmptyClass);
	checkSingleMemberEnumArrEmpty($SingleMemberEnumArrEmptyClass::class$);
	$load($SingleMemberByteArrOneClass);
	checkSingleMemberByteArrOne($SingleMemberByteArrOneClass::class$);
	$load($SingleMemberShortArrOneClass);
	checkSingleMemberShortArrOne($SingleMemberShortArrOneClass::class$);
	$load($SingleMemberIntArrOneClass);
	checkSingleMemberIntArrOne($SingleMemberIntArrOneClass::class$);
	$load($SingleMemberLongArrOneClass);
	checkSingleMemberLongArrOne($SingleMemberLongArrOneClass::class$);
	$load($SingleMemberCharArrOneClass);
	checkSingleMemberCharArrOne($SingleMemberCharArrOneClass::class$);
	$load($SingleMemberFloatArrOneClass);
	checkSingleMemberFloatArrOne($SingleMemberFloatArrOneClass::class$);
	$load($SingleMemberDoubleArrOneClass);
	checkSingleMemberDoubleArrOne($SingleMemberDoubleArrOneClass::class$);
	$load($SingleMemberBooleanArrOneClass);
	checkSingleMemberBooleanArrOne($SingleMemberBooleanArrOneClass::class$);
	$load($SingleMemberStringArrOneClass);
	checkSingleMemberStringArrOne($SingleMemberStringArrOneClass::class$);
	$load($SingleMemberClassArrOneClass);
	checkSingleMemberClassArrOne($SingleMemberClassArrOneClass::class$);
	$load($SingleMemberEnumArrOneClass);
	checkSingleMemberEnumArrOne($SingleMemberEnumArrOneClass::class$);
	$load($SingleMemberByteArrTwoClass);
	checkSingleMemberByteArrTwo($SingleMemberByteArrTwoClass::class$);
	$load($SingleMemberShortArrTwoClass);
	checkSingleMemberShortArrTwo($SingleMemberShortArrTwoClass::class$);
	$load($SingleMemberIntArrTwoClass);
	checkSingleMemberIntArrTwo($SingleMemberIntArrTwoClass::class$);
	$load($SingleMemberLongArrTwoClass);
	checkSingleMemberLongArrTwo($SingleMemberLongArrTwoClass::class$);
	$load($SingleMemberCharArrTwoClass);
	checkSingleMemberCharArrTwo($SingleMemberCharArrTwoClass::class$);
	$load($SingleMemberFloatArrTwoClass);
	checkSingleMemberFloatArrTwo($SingleMemberFloatArrTwoClass::class$);
	$load($SingleMemberDoubleArrTwoClass);
	checkSingleMemberDoubleArrTwo($SingleMemberDoubleArrTwoClass::class$);
	$load($SingleMemberBooleanArrTwoClass);
	checkSingleMemberBooleanArrTwo($SingleMemberBooleanArrTwoClass::class$);
	$load($SingleMemberStringArrTwoClass);
	checkSingleMemberStringArrTwo($SingleMemberStringArrTwoClass::class$);
	$load($SingleMemberClassArrTwoClass);
	checkSingleMemberClassArrTwo($SingleMemberClassArrTwoClass::class$);
	$load($SingleMemberEnumArrTwoClass);
	checkSingleMemberEnumArrTwo($SingleMemberEnumArrTwoClass::class$);
	$load($SingleMemberByteArrOvrdDefClass);
	checkSingleMemberByteArrOvrdDef($SingleMemberByteArrOvrdDefClass::class$);
	$load($SingleMemberShortArrOvrdDefClass);
	checkSingleMemberShortArrOvrdDef($SingleMemberShortArrOvrdDefClass::class$);
	$load($SingleMemberIntArrOvrdDefClass);
	checkSingleMemberIntArrOvrdDef($SingleMemberIntArrOvrdDefClass::class$);
	$load($SingleMemberLongArrOvrdDefClass);
	checkSingleMemberLongArrOvrdDef($SingleMemberLongArrOvrdDefClass::class$);
	$load($SingleMemberCharArrOvrdDefClass);
	checkSingleMemberCharArrOvrdDef($SingleMemberCharArrOvrdDefClass::class$);
	$load($SingleMemberFloatArrOvrdDefClass);
	checkSingleMemberFloatArrOvrdDef($SingleMemberFloatArrOvrdDefClass::class$);
	$load($SingleMemberDoubleArrOvrdDefClass);
	checkSingleMemberDoubleArrOvrdDef($SingleMemberDoubleArrOvrdDefClass::class$);
	$load($SingleMemberBooleanArrOvrdDefClass);
	checkSingleMemberBooleanArrOvrdDef($SingleMemberBooleanArrOvrdDefClass::class$);
	$load($SingleMemberStringArrOvrdDefClass);
	checkSingleMemberStringArrOvrdDef($SingleMemberStringArrOvrdDefClass::class$);
	$load($SingleMemberClassArrOvrdDefClass);
	checkSingleMemberClassArrOvrdDef($SingleMemberClassArrOvrdDefClass::class$);
	$load($SingleMemberEnumArrOvrdDefClass);
	checkSingleMemberEnumArrOvrdDef($SingleMemberEnumArrOvrdDefClass::class$);
	$load($SingleMemberByteArrAcceptDefClass);
	checkSingleMemberByteArrAcceptDef($SingleMemberByteArrAcceptDefClass::class$);
	$load($SingleMemberShortArrAcceptDefClass);
	checkSingleMemberShortArrAcceptDef($SingleMemberShortArrAcceptDefClass::class$);
	$load($SingleMemberIntArrAcceptDefClass);
	checkSingleMemberIntArrAcceptDef($SingleMemberIntArrAcceptDefClass::class$);
	$load($SingleMemberLongArrAcceptDefClass);
	checkSingleMemberLongArrAcceptDef($SingleMemberLongArrAcceptDefClass::class$);
	$load($SingleMemberCharArrAcceptDefClass);
	checkSingleMemberCharArrAcceptDef($SingleMemberCharArrAcceptDefClass::class$);
	$load($SingleMemberFloatArrAcceptDefClass);
	checkSingleMemberFloatArrAcceptDef($SingleMemberFloatArrAcceptDefClass::class$);
	$load($SingleMemberDoubleArrAcceptDefClass);
	checkSingleMemberDoubleArrAcceptDef($SingleMemberDoubleArrAcceptDefClass::class$);
	$load($SingleMemberBooleanArrAcceptDefClass);
	checkSingleMemberBooleanArrAcceptDef($SingleMemberBooleanArrAcceptDefClass::class$);
	$load($SingleMemberStringArrAcceptDefClass);
	checkSingleMemberStringArrAcceptDef($SingleMemberStringArrAcceptDefClass::class$);
	$load($SingleMemberClassArrAcceptDefClass);
	checkSingleMemberClassArrAcceptDef($SingleMemberClassArrAcceptDefClass::class$);
	$load($SingleMemberEnumArrAcceptDefClass);
	checkSingleMemberEnumArrAcceptDef($SingleMemberEnumArrAcceptDefClass::class$);
	$load($ScalarTypes);
	checkEquals($scalarTypesClass::class$, $(UnitTest::class$->getField("scalarTypesField"_s)), $ScalarTypes::class$);
	$load($ScalarTypesWithDefault);
	checkEquals($scalarTypesOverrideDefaultClass::class$, $(UnitTest::class$->getField("scalarTypesOverrideDefaultField"_s)), $ScalarTypesWithDefault::class$);
	checkEquals($scalarTypesAcceptDefaultClass::class$, $(UnitTest::class$->getField("scalarTypesAcceptDefaultField"_s)), $ScalarTypesWithDefault::class$);
	$load($ArrayTypes);
	checkEquals($emptyArrayTypesClass::class$, $(UnitTest::class$->getField("emptyArrayTypesField"_s)), $ArrayTypes::class$);
	checkEquals($singleElementArrayTypesClass::class$, $(UnitTest::class$->getField("singleElementArrayTypesField"_s)), $ArrayTypes::class$);
	checkEquals($twoElementArrayTypesClass::class$, $(UnitTest::class$->getField("twoElementArrayTypesField"_s)), $ArrayTypes::class$);
	$load($ArrayTypesWithDefault);
	checkEquals($arrayTypesOverrideDefaultClass::class$, $(UnitTest::class$->getField("arrayTypesOverrideDefaultField"_s)), $ArrayTypesWithDefault::class$);
	checkEquals($arrayTypesAcceptDefaultClass::class$, $(UnitTest::class$->getField("arrayTypesAcceptDefaultField"_s)), $ArrayTypesWithDefault::class$);
	$load($Marker);
	checkEquals($markerClass::class$, $(UnitTest::class$->getField("markerField"_s)), $Marker::class$);
	$load($SingleMemberByte);
	checkEquals($SingleMemberByteClass::class$, $(UnitTest::class$->getField("SingleMemberByteField"_s)), $SingleMemberByte::class$);
	$load($SingleMemberShort);
	checkEquals($SingleMemberShortClass::class$, $(UnitTest::class$->getField("SingleMemberShortField"_s)), $SingleMemberShort::class$);
	$load($SingleMemberInt);
	checkEquals($SingleMemberIntClass::class$, $(UnitTest::class$->getField("SingleMemberIntField"_s)), $SingleMemberInt::class$);
	$load($SingleMemberLong);
	checkEquals($SingleMemberLongClass::class$, $(UnitTest::class$->getField("SingleMemberLongField"_s)), $SingleMemberLong::class$);
	$load($SingleMemberChar);
	checkEquals($SingleMemberCharClass::class$, $(UnitTest::class$->getField("SingleMemberCharField"_s)), $SingleMemberChar::class$);
	$load($SingleMemberFloat);
	checkEquals($SingleMemberFloatClass::class$, $(UnitTest::class$->getField("SingleMemberFloatField"_s)), $SingleMemberFloat::class$);
	$load($SingleMemberDouble);
	checkEquals($SingleMemberDoubleClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleField"_s)), $SingleMemberDouble::class$);
	$load($SingleMemberBoolean);
	checkEquals($SingleMemberBooleanClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanField"_s)), $SingleMemberBoolean::class$);
	$load($SingleMemberString);
	checkEquals($SingleMemberStringClass::class$, $(UnitTest::class$->getField("SingleMemberStringField"_s)), $SingleMemberString::class$);
	$load($SingleMemberClass);
	checkEquals($SingleMemberClassClass::class$, $(UnitTest::class$->getField("SingleMemberClassField"_s)), $SingleMemberClass::class$);
	$load($SingleMemberEnum);
	checkEquals($SingleMemberEnumClass::class$, $(UnitTest::class$->getField("SingleMemberEnumField"_s)), $SingleMemberEnum::class$);
	$load($SingleMemberByteWithDef);
	checkEquals($SingleMemberByteOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberByteOvrdDefField"_s)), $SingleMemberByteWithDef::class$);
	$load($SingleMemberShortWithDef);
	checkEquals($SingleMemberShortOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberShortOvrdDefField"_s)), $SingleMemberShortWithDef::class$);
	$load($SingleMemberIntWithDef);
	checkEquals($SingleMemberIntOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberIntOvrdDefField"_s)), $SingleMemberIntWithDef::class$);
	$load($SingleMemberLongWithDef);
	checkEquals($SingleMemberLongOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberLongOvrdDefField"_s)), $SingleMemberLongWithDef::class$);
	$load($SingleMemberCharWithDef);
	checkEquals($SingleMemberCharOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberCharOvrdDefField"_s)), $SingleMemberCharWithDef::class$);
	$load($SingleMemberFloatWithDef);
	checkEquals($SingleMemberFloatOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberFloatOvrdDefField"_s)), $SingleMemberFloatWithDef::class$);
	$load($SingleMemberDoubleWithDef);
	checkEquals($SingleMemberDoubleOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleOvrdDefField"_s)), $SingleMemberDoubleWithDef::class$);
	$load($SingleMemberBooleanWithDef);
	checkEquals($SingleMemberBooleanOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanOvrdDefField"_s)), $SingleMemberBooleanWithDef::class$);
	$load($SingleMemberStringWithDef);
	checkEquals($SingleMemberStringOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberStringOvrdDefField"_s)), $SingleMemberStringWithDef::class$);
	$load($SingleMemberClassWithDef);
	checkEquals($SingleMemberClassOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberClassOvrdDefField"_s)), $SingleMemberClassWithDef::class$);
	$load($SingleMemberEnumWithDef);
	checkEquals($SingleMemberEnumOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberEnumOvrdDefField"_s)), $SingleMemberEnumWithDef::class$);
	checkEquals($SingleMemberByteAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberByteAcceptDefField"_s)), $SingleMemberByteWithDef::class$);
	checkEquals($SingleMemberShortAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberShortAcceptDefField"_s)), $SingleMemberShortWithDef::class$);
	checkEquals($SingleMemberIntAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberIntAcceptDefField"_s)), $SingleMemberIntWithDef::class$);
	checkEquals($SingleMemberLongAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberLongAcceptDefField"_s)), $SingleMemberLongWithDef::class$);
	checkEquals($SingleMemberCharAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberCharAcceptDefField"_s)), $SingleMemberCharWithDef::class$);
	checkEquals($SingleMemberFloatAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberFloatAcceptDefField"_s)), $SingleMemberFloatWithDef::class$);
	checkEquals($SingleMemberDoubleAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleAcceptDefField"_s)), $SingleMemberDoubleWithDef::class$);
	checkEquals($SingleMemberBooleanAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanAcceptDefField"_s)), $SingleMemberBooleanWithDef::class$);
	checkEquals($SingleMemberStringAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberStringAcceptDefField"_s)), $SingleMemberStringWithDef::class$);
	checkEquals($SingleMemberClassAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberClassAcceptDefField"_s)), $SingleMemberClassWithDef::class$);
	checkEquals($SingleMemberEnumAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberEnumAcceptDefField"_s)), $SingleMemberEnumWithDef::class$);
	$load($SingleMemberByteArray);
	checkEquals($SingleMemberByteArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrEmptyField"_s)), $SingleMemberByteArray::class$);
	$load($SingleMemberShortArray);
	checkEquals($SingleMemberShortArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrEmptyField"_s)), $SingleMemberShortArray::class$);
	$load($SingleMemberIntArray);
	checkEquals($SingleMemberIntArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrEmptyField"_s)), $SingleMemberIntArray::class$);
	$load($SingleMemberLongArray);
	checkEquals($SingleMemberLongArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrEmptyField"_s)), $SingleMemberLongArray::class$);
	$load($SingleMemberCharArray);
	checkEquals($SingleMemberCharArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrEmptyField"_s)), $SingleMemberCharArray::class$);
	$load($SingleMemberFloatArray);
	checkEquals($SingleMemberFloatArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrEmptyField"_s)), $SingleMemberFloatArray::class$);
	$load($SingleMemberDoubleArray);
	checkEquals($SingleMemberDoubleArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrEmptyField"_s)), $SingleMemberDoubleArray::class$);
	$load($SingleMemberBooleanArray);
	checkEquals($SingleMemberBooleanArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrEmptyField"_s)), $SingleMemberBooleanArray::class$);
	$load($SingleMemberStringArray);
	checkEquals($SingleMemberStringArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrEmptyField"_s)), $SingleMemberStringArray::class$);
	$load($SingleMemberClassArray);
	checkEquals($SingleMemberClassArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrEmptyField"_s)), $SingleMemberClassArray::class$);
	$load($SingleMemberEnumArray);
	checkEquals($SingleMemberEnumArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrEmptyField"_s)), $SingleMemberEnumArray::class$);
	checkEquals($SingleMemberByteArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrOneField"_s)), $SingleMemberByteArray::class$);
	checkEquals($SingleMemberShortArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrOneField"_s)), $SingleMemberShortArray::class$);
	checkEquals($SingleMemberIntArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrOneField"_s)), $SingleMemberIntArray::class$);
	checkEquals($SingleMemberLongArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrOneField"_s)), $SingleMemberLongArray::class$);
	checkEquals($SingleMemberCharArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrOneField"_s)), $SingleMemberCharArray::class$);
	checkEquals($SingleMemberFloatArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrOneField"_s)), $SingleMemberFloatArray::class$);
	checkEquals($SingleMemberDoubleArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrOneField"_s)), $SingleMemberDoubleArray::class$);
	checkEquals($SingleMemberBooleanArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrOneField"_s)), $SingleMemberBooleanArray::class$);
	checkEquals($SingleMemberStringArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrOneField"_s)), $SingleMemberStringArray::class$);
	checkEquals($SingleMemberClassArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrOneField"_s)), $SingleMemberClassArray::class$);
	checkEquals($SingleMemberEnumArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrOneField"_s)), $SingleMemberEnumArray::class$);
	checkEquals($SingleMemberByteArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrTwoField"_s)), $SingleMemberByteArray::class$);
	checkEquals($SingleMemberShortArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrTwoField"_s)), $SingleMemberShortArray::class$);
	checkEquals($SingleMemberIntArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrTwoField"_s)), $SingleMemberIntArray::class$);
	checkEquals($SingleMemberLongArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrTwoField"_s)), $SingleMemberLongArray::class$);
	checkEquals($SingleMemberCharArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrTwoField"_s)), $SingleMemberCharArray::class$);
	checkEquals($SingleMemberFloatArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrTwoField"_s)), $SingleMemberFloatArray::class$);
	checkEquals($SingleMemberDoubleArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrTwoField"_s)), $SingleMemberDoubleArray::class$);
	checkEquals($SingleMemberBooleanArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrTwoField"_s)), $SingleMemberBooleanArray::class$);
	checkEquals($SingleMemberStringArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrTwoField"_s)), $SingleMemberStringArray::class$);
	checkEquals($SingleMemberClassArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrTwoField"_s)), $SingleMemberClassArray::class$);
	checkEquals($SingleMemberEnumArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrTwoField"_s)), $SingleMemberEnumArray::class$);
	$load($SingleMemberByteArrayDef);
	checkEquals($SingleMemberByteArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrOvrdDefField"_s)), $SingleMemberByteArrayDef::class$);
	$load($SingleMemberShortArrayDef);
	checkEquals($SingleMemberShortArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrOvrdDefField"_s)), $SingleMemberShortArrayDef::class$);
	$load($SingleMemberIntArrayDef);
	checkEquals($SingleMemberIntArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrOvrdDefField"_s)), $SingleMemberIntArrayDef::class$);
	$load($SingleMemberLongArrayDef);
	checkEquals($SingleMemberLongArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrOvrdDefField"_s)), $SingleMemberLongArrayDef::class$);
	$load($SingleMemberCharArrayDef);
	checkEquals($SingleMemberCharArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrOvrdDefField"_s)), $SingleMemberCharArrayDef::class$);
	$load($SingleMemberFloatArrayDef);
	checkEquals($SingleMemberFloatArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrOvrdDefField"_s)), $SingleMemberFloatArrayDef::class$);
	$load($SingleMemberDoubleArrayDef);
	checkEquals($SingleMemberDoubleArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrOvrdDefField"_s)), $SingleMemberDoubleArrayDef::class$);
	$load($SingleMemberBooleanArrayDef);
	checkEquals($SingleMemberBooleanArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrOvrdDefField"_s)), $SingleMemberBooleanArrayDef::class$);
	$load($SingleMemberStringArrayDef);
	checkEquals($SingleMemberStringArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrOvrdDefField"_s)), $SingleMemberStringArrayDef::class$);
	$load($SingleMemberClassArrayDef);
	checkEquals($SingleMemberClassArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrOvrdDefField"_s)), $SingleMemberClassArrayDef::class$);
	$load($SingleMemberEnumArrayDef);
	checkEquals($SingleMemberEnumArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrOvrdDefField"_s)), $SingleMemberEnumArrayDef::class$);
	checkEquals($SingleMemberByteArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrAcceptDefField"_s)), $SingleMemberByteArrayDef::class$);
	checkEquals($SingleMemberShortArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrAcceptDefField"_s)), $SingleMemberShortArrayDef::class$);
	checkEquals($SingleMemberIntArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrAcceptDefField"_s)), $SingleMemberIntArrayDef::class$);
	checkEquals($SingleMemberLongArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrAcceptDefField"_s)), $SingleMemberLongArrayDef::class$);
	checkEquals($SingleMemberCharArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrAcceptDefField"_s)), $SingleMemberCharArrayDef::class$);
	checkEquals($SingleMemberFloatArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrAcceptDefField"_s)), $SingleMemberFloatArrayDef::class$);
	checkEquals($SingleMemberDoubleArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrAcceptDefField"_s)), $SingleMemberDoubleArrayDef::class$);
	checkEquals($SingleMemberBooleanArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrAcceptDefField"_s)), $SingleMemberBooleanArrayDef::class$);
	checkEquals($SingleMemberStringArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrAcceptDefField"_s)), $SingleMemberStringArrayDef::class$);
	checkEquals($SingleMemberClassArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrAcceptDefField"_s)), $SingleMemberClassArrayDef::class$);
	checkEquals($SingleMemberEnumArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrAcceptDefField"_s)), $SingleMemberEnumArrayDef::class$);
	checkUnequals($scalarTypesOverrideDefaultClass::class$, $(UnitTest::class$->getField("scalarTypesAcceptDefaultField"_s)), $ScalarTypesWithDefault::class$);
	checkUnequals($scalarTypesAcceptDefaultClass::class$, $(UnitTest::class$->getField("scalarTypesOverrideDefaultField"_s)), $ScalarTypesWithDefault::class$);
	checkUnequals($emptyArrayTypesClass::class$, $(UnitTest::class$->getField("singleElementArrayTypesField"_s)), $ArrayTypes::class$);
	checkUnequals($singleElementArrayTypesClass::class$, $(UnitTest::class$->getField("twoElementArrayTypesField"_s)), $ArrayTypes::class$);
	checkUnequals($twoElementArrayTypesClass::class$, $(UnitTest::class$->getField("singleElementArrayTypesField"_s)), $ArrayTypes::class$);
	checkUnequals($arrayTypesOverrideDefaultClass::class$, $(UnitTest::class$->getField("arrayTypesAcceptDefaultField"_s)), $ArrayTypesWithDefault::class$);
	checkUnequals($arrayTypesAcceptDefaultClass::class$, $(UnitTest::class$->getField("arrayTypesOverrideDefaultField"_s)), $ArrayTypesWithDefault::class$);
	checkUnequals($SingleMemberByteOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberByteAcceptDefField"_s)), $SingleMemberByteWithDef::class$);
	checkUnequals($SingleMemberShortOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberShortAcceptDefField"_s)), $SingleMemberShortWithDef::class$);
	checkUnequals($SingleMemberIntOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberIntAcceptDefField"_s)), $SingleMemberIntWithDef::class$);
	checkUnequals($SingleMemberLongOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberLongAcceptDefField"_s)), $SingleMemberLongWithDef::class$);
	checkUnequals($SingleMemberCharOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberCharAcceptDefField"_s)), $SingleMemberCharWithDef::class$);
	checkUnequals($SingleMemberFloatOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberFloatAcceptDefField"_s)), $SingleMemberFloatWithDef::class$);
	checkUnequals($SingleMemberDoubleOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleAcceptDefField"_s)), $SingleMemberDoubleWithDef::class$);
	checkUnequals($SingleMemberBooleanOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanAcceptDefField"_s)), $SingleMemberBooleanWithDef::class$);
	checkUnequals($SingleMemberStringOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberStringAcceptDefField"_s)), $SingleMemberStringWithDef::class$);
	checkUnequals($SingleMemberClassOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberClassAcceptDefField"_s)), $SingleMemberClassWithDef::class$);
	checkUnequals($SingleMemberEnumOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberEnumAcceptDefField"_s)), $SingleMemberEnumWithDef::class$);
	checkUnequals($SingleMemberByteAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberByteOvrdDefField"_s)), $SingleMemberByteWithDef::class$);
	checkUnequals($SingleMemberShortAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberShortOvrdDefField"_s)), $SingleMemberShortWithDef::class$);
	checkUnequals($SingleMemberIntAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberIntOvrdDefField"_s)), $SingleMemberIntWithDef::class$);
	checkUnequals($SingleMemberLongAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberLongOvrdDefField"_s)), $SingleMemberLongWithDef::class$);
	checkUnequals($SingleMemberCharAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberCharOvrdDefField"_s)), $SingleMemberCharWithDef::class$);
	checkUnequals($SingleMemberFloatAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberFloatOvrdDefField"_s)), $SingleMemberFloatWithDef::class$);
	checkUnequals($SingleMemberDoubleAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleOvrdDefField"_s)), $SingleMemberDoubleWithDef::class$);
	checkUnequals($SingleMemberBooleanAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanOvrdDefField"_s)), $SingleMemberBooleanWithDef::class$);
	checkUnequals($SingleMemberStringAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberStringOvrdDefField"_s)), $SingleMemberStringWithDef::class$);
	checkUnequals($SingleMemberClassAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberClassOvrdDefField"_s)), $SingleMemberClassWithDef::class$);
	checkUnequals($SingleMemberEnumAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberEnumOvrdDefField"_s)), $SingleMemberEnumWithDef::class$);
	checkUnequals($SingleMemberByteArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrOneField"_s)), $SingleMemberByteArray::class$);
	checkUnequals($SingleMemberShortArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrOneField"_s)), $SingleMemberShortArray::class$);
	checkUnequals($SingleMemberIntArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrOneField"_s)), $SingleMemberIntArray::class$);
	checkUnequals($SingleMemberLongArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrOneField"_s)), $SingleMemberLongArray::class$);
	checkUnequals($SingleMemberCharArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrOneField"_s)), $SingleMemberCharArray::class$);
	checkUnequals($SingleMemberFloatArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrOneField"_s)), $SingleMemberFloatArray::class$);
	checkUnequals($SingleMemberDoubleArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrOneField"_s)), $SingleMemberDoubleArray::class$);
	checkUnequals($SingleMemberBooleanArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrOneField"_s)), $SingleMemberBooleanArray::class$);
	checkUnequals($SingleMemberStringArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrOneField"_s)), $SingleMemberStringArray::class$);
	checkUnequals($SingleMemberClassArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrOneField"_s)), $SingleMemberClassArray::class$);
	checkUnequals($SingleMemberEnumArrEmptyClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrOneField"_s)), $SingleMemberEnumArray::class$);
	checkUnequals($SingleMemberByteArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrTwoField"_s)), $SingleMemberByteArray::class$);
	checkUnequals($SingleMemberShortArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrTwoField"_s)), $SingleMemberShortArray::class$);
	checkUnequals($SingleMemberIntArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrTwoField"_s)), $SingleMemberIntArray::class$);
	checkUnequals($SingleMemberLongArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrTwoField"_s)), $SingleMemberLongArray::class$);
	checkUnequals($SingleMemberCharArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrTwoField"_s)), $SingleMemberCharArray::class$);
	checkUnequals($SingleMemberFloatArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrTwoField"_s)), $SingleMemberFloatArray::class$);
	checkUnequals($SingleMemberDoubleArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrTwoField"_s)), $SingleMemberDoubleArray::class$);
	checkUnequals($SingleMemberBooleanArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrTwoField"_s)), $SingleMemberBooleanArray::class$);
	checkUnequals($SingleMemberStringArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrTwoField"_s)), $SingleMemberStringArray::class$);
	checkUnequals($SingleMemberClassArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrTwoField"_s)), $SingleMemberClassArray::class$);
	checkUnequals($SingleMemberEnumArrOneClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrTwoField"_s)), $SingleMemberEnumArray::class$);
	checkUnequals($SingleMemberByteArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrOneField"_s)), $SingleMemberByteArray::class$);
	checkUnequals($SingleMemberShortArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrOneField"_s)), $SingleMemberShortArray::class$);
	checkUnequals($SingleMemberIntArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrOneField"_s)), $SingleMemberIntArray::class$);
	checkUnequals($SingleMemberLongArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrOneField"_s)), $SingleMemberLongArray::class$);
	checkUnequals($SingleMemberCharArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrOneField"_s)), $SingleMemberCharArray::class$);
	checkUnequals($SingleMemberFloatArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrOneField"_s)), $SingleMemberFloatArray::class$);
	checkUnequals($SingleMemberDoubleArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrOneField"_s)), $SingleMemberDoubleArray::class$);
	checkUnequals($SingleMemberBooleanArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrOneField"_s)), $SingleMemberBooleanArray::class$);
	checkUnequals($SingleMemberStringArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrOneField"_s)), $SingleMemberStringArray::class$);
	checkUnequals($SingleMemberClassArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrOneField"_s)), $SingleMemberClassArray::class$);
	checkUnequals($SingleMemberEnumArrTwoClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrOneField"_s)), $SingleMemberEnumArray::class$);
	checkUnequals($SingleMemberByteArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrAcceptDefField"_s)), $SingleMemberByteArrayDef::class$);
	checkUnequals($SingleMemberShortArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrAcceptDefField"_s)), $SingleMemberShortArrayDef::class$);
	checkUnequals($SingleMemberIntArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrAcceptDefField"_s)), $SingleMemberIntArrayDef::class$);
	checkUnequals($SingleMemberLongArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrAcceptDefField"_s)), $SingleMemberLongArrayDef::class$);
	checkUnequals($SingleMemberCharArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrAcceptDefField"_s)), $SingleMemberCharArrayDef::class$);
	checkUnequals($SingleMemberFloatArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrAcceptDefField"_s)), $SingleMemberFloatArrayDef::class$);
	checkUnequals($SingleMemberDoubleArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrAcceptDefField"_s)), $SingleMemberDoubleArrayDef::class$);
	checkUnequals($SingleMemberBooleanArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrAcceptDefField"_s)), $SingleMemberBooleanArrayDef::class$);
	checkUnequals($SingleMemberStringArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrAcceptDefField"_s)), $SingleMemberStringArrayDef::class$);
	checkUnequals($SingleMemberClassArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrAcceptDefField"_s)), $SingleMemberClassArrayDef::class$);
	checkUnequals($SingleMemberEnumArrOvrdDefClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrAcceptDefField"_s)), $SingleMemberEnumArrayDef::class$);
	checkUnequals($SingleMemberByteArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberByteArrOvrdDefField"_s)), $SingleMemberByteArrayDef::class$);
	checkUnequals($SingleMemberShortArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberShortArrOvrdDefField"_s)), $SingleMemberShortArrayDef::class$);
	checkUnequals($SingleMemberIntArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberIntArrOvrdDefField"_s)), $SingleMemberIntArrayDef::class$);
	checkUnequals($SingleMemberLongArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberLongArrOvrdDefField"_s)), $SingleMemberLongArrayDef::class$);
	checkUnequals($SingleMemberCharArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberCharArrOvrdDefField"_s)), $SingleMemberCharArrayDef::class$);
	checkUnequals($SingleMemberFloatArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberFloatArrOvrdDefField"_s)), $SingleMemberFloatArrayDef::class$);
	checkUnequals($SingleMemberDoubleArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberDoubleArrOvrdDefField"_s)), $SingleMemberDoubleArrayDef::class$);
	checkUnequals($SingleMemberBooleanArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberBooleanArrOvrdDefField"_s)), $SingleMemberBooleanArrayDef::class$);
	checkUnequals($SingleMemberStringArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberStringArrOvrdDefField"_s)), $SingleMemberStringArrayDef::class$);
	checkUnequals($SingleMemberClassArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberClassArrOvrdDefField"_s)), $SingleMemberClassArrayDef::class$);
	checkUnequals($SingleMemberEnumArrAcceptDefClass::class$, $(UnitTest::class$->getField("SingleMemberEnumArrOvrdDefField"_s)), $SingleMemberEnumArrayDef::class$);
	checkSerialization($scalarTypesClass::class$, $ScalarTypes::class$);
	checkSerialization($scalarTypesOverrideDefaultClass::class$, $ScalarTypesWithDefault::class$);
	checkSerialization($scalarTypesAcceptDefaultClass::class$, $ScalarTypesWithDefault::class$);
	checkSerialization($emptyArrayTypesClass::class$, $ArrayTypes::class$);
	checkSerialization($singleElementArrayTypesClass::class$, $ArrayTypes::class$);
	checkSerialization($twoElementArrayTypesClass::class$, $ArrayTypes::class$);
	checkSerialization($arrayTypesOverrideDefaultClass::class$, $ArrayTypesWithDefault::class$);
	checkSerialization($arrayTypesAcceptDefaultClass::class$, $ArrayTypesWithDefault::class$);
	checkSerialization($markerClass::class$, $Marker::class$);
	checkSerialization($SingleMemberByteClass::class$, $SingleMemberByte::class$);
	checkSerialization($SingleMemberShortClass::class$, $SingleMemberShort::class$);
	checkSerialization($SingleMemberIntClass::class$, $SingleMemberInt::class$);
	checkSerialization($SingleMemberLongClass::class$, $SingleMemberLong::class$);
	checkSerialization($SingleMemberCharClass::class$, $SingleMemberChar::class$);
	checkSerialization($SingleMemberFloatClass::class$, $SingleMemberFloat::class$);
	checkSerialization($SingleMemberDoubleClass::class$, $SingleMemberDouble::class$);
	checkSerialization($SingleMemberBooleanClass::class$, $SingleMemberBoolean::class$);
	checkSerialization($SingleMemberStringClass::class$, $SingleMemberString::class$);
	checkSerialization($SingleMemberClassClass::class$, $SingleMemberClass::class$);
	checkSerialization($SingleMemberEnumClass::class$, $SingleMemberEnum::class$);
	checkSerialization($SingleMemberByteOvrdDefClass::class$, $SingleMemberByteWithDef::class$);
	checkSerialization($SingleMemberShortOvrdDefClass::class$, $SingleMemberShortWithDef::class$);
	checkSerialization($SingleMemberIntOvrdDefClass::class$, $SingleMemberIntWithDef::class$);
	checkSerialization($SingleMemberLongOvrdDefClass::class$, $SingleMemberLongWithDef::class$);
	checkSerialization($SingleMemberCharOvrdDefClass::class$, $SingleMemberCharWithDef::class$);
	checkSerialization($SingleMemberFloatOvrdDefClass::class$, $SingleMemberFloatWithDef::class$);
	checkSerialization($SingleMemberDoubleOvrdDefClass::class$, $SingleMemberDoubleWithDef::class$);
	checkSerialization($SingleMemberBooleanOvrdDefClass::class$, $SingleMemberBooleanWithDef::class$);
	checkSerialization($SingleMemberStringOvrdDefClass::class$, $SingleMemberStringWithDef::class$);
	checkSerialization($SingleMemberClassOvrdDefClass::class$, $SingleMemberClassWithDef::class$);
	checkSerialization($SingleMemberEnumOvrdDefClass::class$, $SingleMemberEnumWithDef::class$);
	checkSerialization($SingleMemberByteAcceptDefClass::class$, $SingleMemberByteWithDef::class$);
	checkSerialization($SingleMemberShortAcceptDefClass::class$, $SingleMemberShortWithDef::class$);
	checkSerialization($SingleMemberIntAcceptDefClass::class$, $SingleMemberIntWithDef::class$);
	checkSerialization($SingleMemberLongAcceptDefClass::class$, $SingleMemberLongWithDef::class$);
	checkSerialization($SingleMemberCharAcceptDefClass::class$, $SingleMemberCharWithDef::class$);
	checkSerialization($SingleMemberFloatAcceptDefClass::class$, $SingleMemberFloatWithDef::class$);
	checkSerialization($SingleMemberDoubleAcceptDefClass::class$, $SingleMemberDoubleWithDef::class$);
	checkSerialization($SingleMemberBooleanAcceptDefClass::class$, $SingleMemberBooleanWithDef::class$);
	checkSerialization($SingleMemberStringAcceptDefClass::class$, $SingleMemberStringWithDef::class$);
	checkSerialization($SingleMemberClassAcceptDefClass::class$, $SingleMemberClassWithDef::class$);
	checkSerialization($SingleMemberEnumAcceptDefClass::class$, $SingleMemberEnumWithDef::class$);
	checkSerialization($SingleMemberByteArrEmptyClass::class$, $SingleMemberByteArray::class$);
	checkSerialization($SingleMemberShortArrEmptyClass::class$, $SingleMemberShortArray::class$);
	checkSerialization($SingleMemberIntArrEmptyClass::class$, $SingleMemberIntArray::class$);
	checkSerialization($SingleMemberLongArrEmptyClass::class$, $SingleMemberLongArray::class$);
	checkSerialization($SingleMemberCharArrEmptyClass::class$, $SingleMemberCharArray::class$);
	checkSerialization($SingleMemberFloatArrEmptyClass::class$, $SingleMemberFloatArray::class$);
	checkSerialization($SingleMemberDoubleArrEmptyClass::class$, $SingleMemberDoubleArray::class$);
	checkSerialization($SingleMemberBooleanArrEmptyClass::class$, $SingleMemberBooleanArray::class$);
	checkSerialization($SingleMemberStringArrEmptyClass::class$, $SingleMemberStringArray::class$);
	checkSerialization($SingleMemberClassArrEmptyClass::class$, $SingleMemberClassArray::class$);
	checkSerialization($SingleMemberEnumArrEmptyClass::class$, $SingleMemberEnumArray::class$);
	checkSerialization($SingleMemberByteArrOneClass::class$, $SingleMemberByteArray::class$);
	checkSerialization($SingleMemberShortArrOneClass::class$, $SingleMemberShortArray::class$);
	checkSerialization($SingleMemberIntArrOneClass::class$, $SingleMemberIntArray::class$);
	checkSerialization($SingleMemberLongArrOneClass::class$, $SingleMemberLongArray::class$);
	checkSerialization($SingleMemberCharArrOneClass::class$, $SingleMemberCharArray::class$);
	checkSerialization($SingleMemberFloatArrOneClass::class$, $SingleMemberFloatArray::class$);
	checkSerialization($SingleMemberDoubleArrOneClass::class$, $SingleMemberDoubleArray::class$);
	checkSerialization($SingleMemberBooleanArrOneClass::class$, $SingleMemberBooleanArray::class$);
	checkSerialization($SingleMemberStringArrOneClass::class$, $SingleMemberStringArray::class$);
	checkSerialization($SingleMemberClassArrOneClass::class$, $SingleMemberClassArray::class$);
	checkSerialization($SingleMemberEnumArrOneClass::class$, $SingleMemberEnumArray::class$);
	checkSerialization($SingleMemberByteArrTwoClass::class$, $SingleMemberByteArray::class$);
	checkSerialization($SingleMemberShortArrTwoClass::class$, $SingleMemberShortArray::class$);
	checkSerialization($SingleMemberIntArrTwoClass::class$, $SingleMemberIntArray::class$);
	checkSerialization($SingleMemberLongArrTwoClass::class$, $SingleMemberLongArray::class$);
	checkSerialization($SingleMemberCharArrTwoClass::class$, $SingleMemberCharArray::class$);
	checkSerialization($SingleMemberFloatArrTwoClass::class$, $SingleMemberFloatArray::class$);
	checkSerialization($SingleMemberDoubleArrTwoClass::class$, $SingleMemberDoubleArray::class$);
	checkSerialization($SingleMemberBooleanArrTwoClass::class$, $SingleMemberBooleanArray::class$);
	checkSerialization($SingleMemberStringArrTwoClass::class$, $SingleMemberStringArray::class$);
	checkSerialization($SingleMemberClassArrTwoClass::class$, $SingleMemberClassArray::class$);
	checkSerialization($SingleMemberEnumArrTwoClass::class$, $SingleMemberEnumArray::class$);
	checkSerialization($SingleMemberByteArrOvrdDefClass::class$, $SingleMemberByteArrayDef::class$);
	checkSerialization($SingleMemberShortArrOvrdDefClass::class$, $SingleMemberShortArrayDef::class$);
	checkSerialization($SingleMemberIntArrOvrdDefClass::class$, $SingleMemberIntArrayDef::class$);
	checkSerialization($SingleMemberLongArrOvrdDefClass::class$, $SingleMemberLongArrayDef::class$);
	checkSerialization($SingleMemberCharArrOvrdDefClass::class$, $SingleMemberCharArrayDef::class$);
	checkSerialization($SingleMemberFloatArrOvrdDefClass::class$, $SingleMemberFloatArrayDef::class$);
	checkSerialization($SingleMemberDoubleArrOvrdDefClass::class$, $SingleMemberDoubleArrayDef::class$);
	checkSerialization($SingleMemberBooleanArrOvrdDefClass::class$, $SingleMemberBooleanArrayDef::class$);
	checkSerialization($SingleMemberStringArrOvrdDefClass::class$, $SingleMemberStringArrayDef::class$);
	checkSerialization($SingleMemberClassArrOvrdDefClass::class$, $SingleMemberClassArrayDef::class$);
	checkSerialization($SingleMemberEnumArrOvrdDefClass::class$, $SingleMemberEnumArrayDef::class$);
	checkSerialization($SingleMemberByteArrAcceptDefClass::class$, $SingleMemberByteArrayDef::class$);
	checkSerialization($SingleMemberShortArrAcceptDefClass::class$, $SingleMemberShortArrayDef::class$);
	checkSerialization($SingleMemberIntArrAcceptDefClass::class$, $SingleMemberIntArrayDef::class$);
	checkSerialization($SingleMemberLongArrAcceptDefClass::class$, $SingleMemberLongArrayDef::class$);
	checkSerialization($SingleMemberCharArrAcceptDefClass::class$, $SingleMemberCharArrayDef::class$);
	checkSerialization($SingleMemberFloatArrAcceptDefClass::class$, $SingleMemberFloatArrayDef::class$);
	checkSerialization($SingleMemberDoubleArrAcceptDefClass::class$, $SingleMemberDoubleArrayDef::class$);
	checkSerialization($SingleMemberBooleanArrAcceptDefClass::class$, $SingleMemberBooleanArrayDef::class$);
	checkSerialization($SingleMemberStringArrAcceptDefClass::class$, $SingleMemberStringArrayDef::class$);
	checkSerialization($SingleMemberClassArrAcceptDefClass::class$, $SingleMemberClassArrayDef::class$);
	checkSerialization($SingleMemberEnumArrAcceptDefClass::class$, $SingleMemberEnumArrayDef::class$);
	$load($Grandpa);
	checkInheritence($Grandpa::class$, true, true);
	$load($Dad);
	checkInheritence($Dad::class$, true, false);
	$load($Son);
	checkInheritence($Son::class$, true, true);
	checkDeclaredAnnotations($Grandpa::class$, true, true);
	checkDeclaredAnnotations($Dad::class$, false, false);
	checkDeclaredAnnotations($Son::class$, false, true);
	$nc($System::out)->println($$str({"\n"_s, $$str(UnitTest::numTests), " tests completed"_s}));
	if (UnitTest::failCount != 0) {
		$throwNew($Exception, $$str({"Failure count: "_s, $$str(UnitTest::failCount)}));
	} else {
		$nc($System::out)->println("Success."_s);
	}
}

void UnitTest::fail($String* test) {
	$init(UnitTest);
	$nc($System::out)->println($$str({"Failure: "_s, test}));
	++UnitTest::failCount;
}

void UnitTest::checkScalarTypes($AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		$load($ScalarTypes);
		checkScalarTypes($cast($ScalarTypes, $($nc(e)->getAnnotation($ScalarTypes::class$))), e);
	} catch ($Throwable& t) {
		fail($$str({"ScalarTypes "_s, e, ": "_s, t}));
		t->printStackTrace();
	}
}

void UnitTest::checkScalarTypes($ScalarTypes* st, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	bool var$11 = $nc(st)->b() == 1;
	bool var$10 = var$11 && st->s() == 2;
	bool var$9 = var$10 && st->i() == 3;
	bool var$8 = var$9 && st->l() == (int64_t)4;
	bool var$7 = var$8 && st->c() == u'5';
	bool var$6 = var$7 && st->f() == 6.0f;
	bool var$5 = var$6 && st->d() == 7.0;
	bool var$4 = var$5 && st->bool$() == true;
	bool var$3 = var$4 && $nc($(st->str()))->equals("custom"_s);
	$load($Map);
	bool var$2 = var$3 && st->cls() == $Map::class$;
	$init($Stooge);
	bool var$1 = var$2 && st->e() == $Stooge::MOE;
	bool var$0 = var$1 && $nc($(st->a()))->x() == 1;
	if (!(var$0 && $nc($(st->a()))->y() == 2)) {
		fail($$str({"ScalarTypes"_s, e}));
	}
}

void UnitTest::checkScalarTypesOverrideDefault($AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		$load($ScalarTypesWithDefault);
		checkScalarTypesOverrideDefault($cast($ScalarTypesWithDefault, $($nc(e)->getAnnotation($ScalarTypesWithDefault::class$))), e);
	} catch ($Throwable& t) {
		fail($$str({"ScalarTypesOverrideDefaults"_s, e, ": "_s, t}));
	}
}

void UnitTest::checkScalarTypesOverrideDefault($ScalarTypesWithDefault* st, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	bool var$9 = $nc(st)->b() == 1;
	bool var$8 = var$9 && st->s() == 2;
	bool var$7 = var$8 && st->i() == 3;
	bool var$6 = var$7 && st->l() == (int64_t)4;
	bool var$5 = var$6 && st->c() == u'5';
	bool var$4 = var$5 && st->f() == 6.0f;
	bool var$3 = var$4 && st->d() == 7.0;
	bool var$2 = var$3 && st->bool$() == true;
	bool var$1 = var$2 && $nc($(st->str()))->equals("custom"_s);
	$load($Map);
	bool var$0 = var$1 && st->cls() == $Map::class$;
	$init($Stooge);
	if (!(var$0 && st->e() == $Stooge::MOE)) {
		fail($$str({"ScalarTypesOverrideDefaults"_s, e}));
	}
}

void UnitTest::checkScalarTypesAcceptDefault($AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		$load($ScalarTypesWithDefault);
		checkScalarTypesAcceptDefault($cast($ScalarTypesWithDefault, $($nc(e)->getAnnotation($ScalarTypesWithDefault::class$))), e);
	} catch ($Throwable& t) {
		fail($$str({"ScalarTypesAcceptDefaults"_s, e, ": "_s, t}));
	}
}

void UnitTest::checkScalarTypesAcceptDefault($ScalarTypesWithDefault* st, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	bool var$11 = $nc(st)->b() == 11;
	bool var$10 = var$11 && st->s() == 12;
	bool var$9 = var$10 && st->i() == 13;
	bool var$8 = var$9 && st->l() == (int64_t)14;
	bool var$7 = var$8 && st->c() == u'V';
	bool var$6 = var$7 && st->f() == 16.0f;
	bool var$5 = var$6 && st->d() == 17.0;
	bool var$4 = var$5 && st->bool$() == false;
	bool var$3 = var$4 && $nc($(st->str()))->equals("default"_s);
	bool var$2 = var$3 && st->cls() == $Class::class$;
	$init($Stooge);
	bool var$1 = var$2 && st->e() == $Stooge::LARRY;
	bool var$0 = var$1 && $nc($(st->a()))->x() == 11;
	if (!(var$0 && $nc($(st->a()))->y() == 12)) {
		fail($$str({"ScalarTypesAcceptDefaults"_s, e}));
	}
}

void UnitTest::checkArrayTypes0($AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		$load($ArrayTypes);
		checkArrayTypes0($cast($ArrayTypes, $($nc(e)->getAnnotation($ArrayTypes::class$))), e);
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypes(Empty)"_s, e, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypes0($ArrayTypes* at, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	bool var$10 = $nc($($nc(at)->b()))->length == 0;
	bool var$9 = var$10 && $nc($(at->s()))->length == 0;
	bool var$8 = var$9 && $nc($(at->i()))->length == 0;
	bool var$7 = var$8 && $nc($(at->l()))->length == 0;
	bool var$6 = var$7 && $nc($(at->c()))->length == 0;
	bool var$5 = var$6 && $nc($(at->f()))->length == 0;
	bool var$4 = var$5 && $nc($(at->d()))->length == 0;
	bool var$3 = var$4 && $nc($(at->bool$()))->length == 0;
	bool var$2 = var$3 && $nc($(at->str()))->length == 0;
	bool var$1 = var$2 && $nc($(at->cls()))->length == 0;
	bool var$0 = var$1 && $nc($(at->e()))->length == 0;
	if (!(var$0 && $nc($(at->a()))->length == 0)) {
		fail($$str({"ArrayTypes(Empty)"_s, e}));
	}
}

void UnitTest::checkArrayTypes1($AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		$load($ArrayTypes);
		checkArrayTypes1($cast($ArrayTypes, $($nc(e)->getAnnotation($ArrayTypes::class$))), e);
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypes(One element)"_s, e, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypes1($ArrayTypes* at, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	bool var$22 = $nc($($nc(at)->b()))->get(0) == 1;
	bool var$21 = var$22 && $nc($(at->s()))->get(0) == 2;
	bool var$20 = var$21 && $nc($(at->i()))->get(0) == 3;
	bool var$19 = var$20 && $nc($(at->l()))->get(0) == (int64_t)4;
	bool var$18 = var$19 && $nc($(at->c()))->get(0) == u'5';
	bool var$17 = var$18 && $nc($(at->f()))->get(0) == 6.0f;
	bool var$16 = var$17 && $nc($(at->d()))->get(0) == 7.0;
	bool var$15 = var$16 && $nc($(at->bool$()))->get(0) == true;
	bool var$14 = var$15 && $nc($nc($(at->str()))->get(0))->equals("custom"_s);
	$load($Map);
	bool var$13 = var$14 && $nc($(at->cls()))->get(0) == $Map::class$;
	$init($Stooge);
	bool var$12 = var$13 && $nc($(at->e()))->get(0) == $Stooge::MOE;
	bool var$11 = var$12 && $nc($nc($(at->a()))->get(0))->x() == 1;
	bool var$10 = var$11 && $nc($nc($(at->a()))->get(0))->y() == 2;
	bool var$9 = var$10 && $nc($(at->b()))->length == 1;
	bool var$8 = var$9 && $nc($(at->s()))->length == 1;
	bool var$7 = var$8 && $nc($(at->i()))->length == 1;
	bool var$6 = var$7 && $nc($(at->l()))->length == 1;
	bool var$5 = var$6 && $nc($(at->c()))->length == 1;
	bool var$4 = var$5 && $nc($(at->d()))->length == 1;
	bool var$3 = var$4 && $nc($(at->bool$()))->length == 1;
	bool var$2 = var$3 && $nc($(at->str()))->length == 1;
	bool var$1 = var$2 && $nc($(at->cls()))->length == 1;
	bool var$0 = var$1 && $nc($(at->cls()))->length == 1;
	if (!(var$0 && $nc($(at->a()))->length == 1)) {
		fail($$str({"ArrayTypes(One element)"_s, e}));
	}
}

void UnitTest::checkArrayTypes2($AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		$load($ArrayTypes);
		checkArrayTypes2($cast($ArrayTypes, $($nc(e)->getAnnotation($ArrayTypes::class$))), e);
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypes(Two element)"_s, e, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypes2($ArrayTypes* at, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	bool var$35 = $nc($($nc(at)->b()))->get(0) == 1;
	bool var$34 = var$35 && $nc($(at->b()))->get(1) == 2;
	bool var$33 = var$34 && $nc($(at->s()))->get(0) == 2;
	bool var$32 = var$33 && $nc($(at->s()))->get(1) == 3;
	bool var$31 = var$32 && $nc($(at->i()))->get(0) == 3;
	bool var$30 = var$31 && $nc($(at->i()))->get(1) == 4;
	bool var$29 = var$30 && $nc($(at->l()))->get(0) == (int64_t)4;
	bool var$28 = var$29 && $nc($(at->l()))->get(1) == (int64_t)5;
	bool var$27 = var$28 && $nc($(at->c()))->get(0) == u'5';
	bool var$26 = var$27 && $nc($(at->c()))->get(1) == u'6';
	bool var$25 = var$26 && $nc($(at->f()))->get(0) == 6.0f;
	bool var$24 = var$25 && $nc($(at->f()))->get(1) == 7.0f;
	bool var$23 = var$24 && $nc($(at->d()))->get(0) == 7.0;
	bool var$22 = var$23 && $nc($(at->d()))->get(1) == 8.0;
	bool var$21 = var$22 && $nc($(at->bool$()))->get(0) == true;
	bool var$20 = var$21 && $nc($(at->bool$()))->get(1) == false;
	bool var$19 = var$20 && $nc($nc($(at->str()))->get(0))->equals("custom"_s);
	bool var$18 = var$19 && $nc($nc($(at->str()))->get(1))->equals("paint"_s);
	$load($Map);
	bool var$17 = var$18 && $nc($(at->cls()))->get(0) == $Map::class$;
	$load($Set);
	bool var$16 = var$17 && $nc($(at->cls()))->get(1) == $Set::class$;
	$init($Stooge);
	bool var$15 = var$16 && $nc($(at->e()))->get(0) == $Stooge::MOE;
	bool var$14 = var$15 && $nc($(at->e()))->get(1) == $Stooge::CURLY;
	bool var$13 = var$14 && $nc($nc($(at->a()))->get(0))->x() == 1;
	bool var$12 = var$13 && $nc($nc($(at->a()))->get(0))->y() == 2;
	bool var$11 = var$12 && $nc($nc($(at->a()))->get(1))->x() == 3;
	bool var$10 = var$11 && $nc($nc($(at->a()))->get(1))->y() == 4;
	bool var$9 = var$10 && $nc($(at->b()))->length == 2;
	bool var$8 = var$9 && $nc($(at->s()))->length == 2;
	bool var$7 = var$8 && $nc($(at->i()))->length == 2;
	bool var$6 = var$7 && $nc($(at->l()))->length == 2;
	bool var$5 = var$6 && $nc($(at->c()))->length == 2;
	bool var$4 = var$5 && $nc($(at->d()))->length == 2;
	bool var$3 = var$4 && $nc($(at->bool$()))->length == 2;
	bool var$2 = var$3 && $nc($(at->str()))->length == 2;
	bool var$1 = var$2 && $nc($(at->cls()))->length == 2;
	bool var$0 = var$1 && $nc($(at->cls()))->length == 2;
	if (!(var$0 && $nc($(at->a()))->length == 2)) {
		fail($$str({"ArrayTypes(Two element)"_s, e}));
	}
}

void UnitTest::checkArrayTypesOverrideDefault($AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		$load($ArrayTypesWithDefault);
		checkArrayTypesOverrideDefault($cast($ArrayTypesWithDefault, $($nc(e)->getAnnotation($ArrayTypesWithDefault::class$))), e);
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypesOverrideDefault"_s, e, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypesOverrideDefault($ArrayTypesWithDefault* at, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	bool var$21 = $nc($($nc(at)->b()))->get(0) == 1;
	bool var$20 = var$21 && $nc($(at->s()))->get(0) == 2;
	bool var$19 = var$20 && $nc($(at->i()))->get(0) == 3;
	bool var$18 = var$19 && $nc($(at->l()))->get(0) == (int64_t)4;
	bool var$17 = var$18 && $nc($(at->c()))->get(0) == u'5';
	bool var$16 = var$17 && $nc($(at->f()))->get(0) == 6.0f;
	bool var$15 = var$16 && $nc($(at->d()))->get(0) == 7.0;
	bool var$14 = var$15 && $nc($(at->bool$()))->get(0) == true;
	bool var$13 = var$14 && $nc($nc($(at->str()))->get(0))->equals("custom"_s);
	$load($Map);
	bool var$12 = var$13 && $nc($(at->cls()))->get(0) == $Map::class$;
	$init($Stooge);
	bool var$11 = var$12 && $nc($(at->e()))->get(0) == $Stooge::MOE;
	bool var$10 = var$11 && $nc($nc($(at->a()))->get(0))->x() == 1;
	bool var$9 = var$10 && $nc($nc($(at->a()))->get(0))->y() == 2;
	bool var$8 = var$9 && $nc($(at->b()))->length == 1;
	bool var$7 = var$8 && $nc($(at->s()))->length == 1;
	bool var$6 = var$7 && $nc($(at->i()))->length == 1;
	bool var$5 = var$6 && $nc($(at->l()))->length == 1;
	bool var$4 = var$5 && $nc($(at->c()))->length == 1;
	bool var$3 = var$4 && $nc($(at->d()))->length == 1;
	bool var$2 = var$3 && $nc($(at->bool$()))->length == 1;
	bool var$1 = var$2 && $nc($(at->str()))->length == 1;
	bool var$0 = var$1 && $nc($(at->cls()))->length == 1;
	if (!(var$0 && $nc($(at->cls()))->length == 1)) {
		fail($$str({"ArrayTypesOverrideDefault"_s, e}));
	}
}

void UnitTest::checkArrayTypesAcceptDefault($AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		$load($ArrayTypesWithDefault);
		checkArrayTypesAcceptDefault($cast($ArrayTypesWithDefault, $($nc(e)->getAnnotation($ArrayTypesWithDefault::class$))), e);
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypesAcceptDefault"_s, e, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypesAcceptDefault($ArrayTypesWithDefault* at, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	bool var$21 = $nc($($nc(at)->b()))->get(0) == 11;
	bool var$20 = var$21 && $nc($(at->s()))->get(0) == 12;
	bool var$19 = var$20 && $nc($(at->i()))->get(0) == 13;
	bool var$18 = var$19 && $nc($(at->l()))->get(0) == (int64_t)14;
	bool var$17 = var$18 && $nc($(at->c()))->get(0) == u'V';
	bool var$16 = var$17 && $nc($(at->f()))->get(0) == 16.0f;
	bool var$15 = var$16 && $nc($(at->d()))->get(0) == 17.0;
	bool var$14 = var$15 && $nc($(at->bool$()))->get(0) == false;
	bool var$13 = var$14 && $nc($nc($(at->str()))->get(0))->equals("default"_s);
	bool var$12 = var$13 && $nc($(at->cls()))->get(0) == $Class::class$;
	$init($Stooge);
	bool var$11 = var$12 && $nc($(at->e()))->get(0) == $Stooge::LARRY;
	bool var$10 = var$11 && $nc($nc($(at->a()))->get(0))->x() == 11;
	bool var$9 = var$10 && $nc($nc($(at->a()))->get(0))->y() == 12;
	bool var$8 = var$9 && $nc($(at->b()))->length == 1;
	bool var$7 = var$8 && $nc($(at->s()))->length == 1;
	bool var$6 = var$7 && $nc($(at->i()))->length == 1;
	bool var$5 = var$6 && $nc($(at->l()))->length == 1;
	bool var$4 = var$5 && $nc($(at->c()))->length == 1;
	bool var$3 = var$4 && $nc($(at->d()))->length == 1;
	bool var$2 = var$3 && $nc($(at->bool$()))->length == 1;
	bool var$1 = var$2 && $nc($(at->str()))->length == 1;
	bool var$0 = var$1 && $nc($(at->cls()))->length == 1;
	if (!(var$0 && $nc($(at->cls()))->length == 1)) {
		fail($$str({"ArrayTypesAcceptDefault"_s, e}));
	}
}

void UnitTest::checkScalarTypesParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkScalarTypes($cast($ScalarTypes, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"ScalarTypes"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkScalarTypesOverrideDefaultParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkScalarTypesOverrideDefault($cast($ScalarTypesWithDefault, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"ScalarTypesOverrideDefaults"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkScalarTypesAcceptDefaultParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkScalarTypesAcceptDefault($cast($ScalarTypesWithDefault, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"ScalarTypesAcceptDefaults"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypes0Param($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkArrayTypes0($cast($ArrayTypes, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypes(Empty)"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypes1Param($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkArrayTypes1($cast($ArrayTypes, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypes(One Element)"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypes2Param($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkArrayTypes2($cast($ArrayTypes, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypes(Two Elements)"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypesOverrideDefaultParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkArrayTypesOverrideDefault($cast($ArrayTypesWithDefault, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypesOverrideDefault"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkArrayTypesAcceptDefaultParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkArrayTypesAcceptDefault($cast($ArrayTypesWithDefault, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"ArrayTypesAcceptDefault"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkMarkerParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkMarker($cast($Marker, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"Marker"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberByte($cast($SingleMemberByte, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByte"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberShort($cast($SingleMemberShort, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShort"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberInt($cast($SingleMemberInt, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberInt"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberLong($cast($SingleMemberLong, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLong"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberChar($cast($SingleMemberChar, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberChar"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberFloat($cast($SingleMemberFloat, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloat"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberDouble($cast($SingleMemberDouble, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDouble"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberBoolean($cast($SingleMemberBoolean, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBoolean"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberString($cast($SingleMemberString, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberString"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberClass($cast($SingleMemberClass, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClass"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberEnum($cast($SingleMemberEnum, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnum"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberByteOvrdDef($cast($SingleMemberByteWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberShortOvrdDef($cast($SingleMemberShortWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberIntOvrdDef($cast($SingleMemberIntWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberLongOvrdDef($cast($SingleMemberLongWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberCharOvrdDef($cast($SingleMemberCharWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberFloatOvrdDef($cast($SingleMemberFloatWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberDoubleOvrdDef($cast($SingleMemberDoubleWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberBooleanOvrdDef($cast($SingleMemberBooleanWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberStringOvrdDef($cast($SingleMemberStringWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberClassOvrdDef($cast($SingleMemberClassWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberEnumOvrdDef($cast($SingleMemberEnumWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberByteAcceptDef($cast($SingleMemberByteWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberShortAcceptDef($cast($SingleMemberShortWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberIntAcceptDef($cast($SingleMemberIntWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberLongAcceptDef($cast($SingleMemberLongWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberCharAcceptDef($cast($SingleMemberCharWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberFloatAcceptDef($cast($SingleMemberFloatWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberDoubleAcceptDef($cast($SingleMemberDoubleWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberBooleanAcceptDef($cast($SingleMemberBooleanWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberStringAcceptDef($cast($SingleMemberStringWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberClassAcceptDef($cast($SingleMemberClassWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberEnumAcceptDef($cast($SingleMemberEnumWithDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberByteArrEmpty($cast($SingleMemberByteArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberShortArrEmpty($cast($SingleMemberShortArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberIntArrEmpty($cast($SingleMemberIntArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberLongArrEmpty($cast($SingleMemberLongArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberCharArrEmpty($cast($SingleMemberCharArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberFloatArrEmpty($cast($SingleMemberFloatArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberDoubleArrEmpty($cast($SingleMemberDoubleArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberBooleanArrEmpty($cast($SingleMemberBooleanArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberStringArrEmpty($cast($SingleMemberStringArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberClassArrEmpty($cast($SingleMemberClassArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrEmptyParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberEnumArrEmpty($cast($SingleMemberEnumArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrEmpty"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberByteArrOne($cast($SingleMemberByteArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberShortArrOne($cast($SingleMemberShortArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberIntArrOne($cast($SingleMemberIntArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberLongArrOne($cast($SingleMemberLongArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberCharArrOne($cast($SingleMemberCharArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberFloatArrOne($cast($SingleMemberFloatArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberDoubleArrOne($cast($SingleMemberDoubleArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberBooleanArrOne($cast($SingleMemberBooleanArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberStringArrOne($cast($SingleMemberStringArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberClassArrOne($cast($SingleMemberClassArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrOneParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberEnumArrOne($cast($SingleMemberEnumArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrOne"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberByteArrTwo($cast($SingleMemberByteArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberShortArrTwo($cast($SingleMemberShortArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberIntArrTwo($cast($SingleMemberIntArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberLongArrTwo($cast($SingleMemberLongArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberCharArrTwo($cast($SingleMemberCharArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberFloatArrTwo($cast($SingleMemberFloatArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberDoubleArrTwo($cast($SingleMemberDoubleArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberBooleanArrTwo($cast($SingleMemberBooleanArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberStringArrTwo($cast($SingleMemberStringArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberClassArrTwo($cast($SingleMemberClassArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrTwoParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberEnumArrTwo($cast($SingleMemberEnumArray, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrTwo"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberByteArrOvrdDef($cast($SingleMemberByteArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberShortArrOvrdDef($cast($SingleMemberShortArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberIntArrOvrdDef($cast($SingleMemberIntArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberLongArrOvrdDef($cast($SingleMemberLongArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberCharArrOvrdDef($cast($SingleMemberCharArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberFloatArrOvrdDef($cast($SingleMemberFloatArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberDoubleArrOvrdDef($cast($SingleMemberDoubleArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberBooleanArrOvrdDef($cast($SingleMemberBooleanArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberStringArrOvrdDef($cast($SingleMemberStringArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberClassArrOvrdDef($cast($SingleMemberClassArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrOvrdDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberEnumArrOvrdDef($cast($SingleMemberEnumArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrOvrdDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberByteArrAcceptDef($cast($SingleMemberByteArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberShortArrAcceptDef($cast($SingleMemberShortArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberIntArrAcceptDef($cast($SingleMemberIntArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberLongArrAcceptDef($cast($SingleMemberLongArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberCharArrAcceptDef($cast($SingleMemberCharArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberFloatArrAcceptDef($cast($SingleMemberFloatArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberDoubleArrAcceptDef($cast($SingleMemberDoubleArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberBooleanArrAcceptDef($cast($SingleMemberBooleanArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberStringArrAcceptDef($cast($SingleMemberStringArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberClassArrAcceptDef($cast($SingleMemberClassArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrAcceptDefParam($Method* m) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		checkSingleMemberEnumArrAcceptDef($cast($SingleMemberEnumArrayDef, $nc($nc($($nc(m)->getParameterAnnotations()))->get(0))->get(0)), static_cast<$AnnotatedElement*>(static_cast<$AccessibleObject*>(static_cast<$Executable*>(m))));
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrAcceptDef"_s, m, ": "_s, t}));
	}
}

void UnitTest::checkMarker($AnnotatedElement* e) {
	$init(UnitTest);
	$load($Marker);
	checkMarker($cast($Marker, $($nc(e)->getAnnotation($Marker::class$))), e);
}

void UnitTest::checkMarker($Marker* m, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if (m == nullptr) {
			fail($$str({"Marker "_s, e}));
		}
	} catch ($Throwable& t) {
		fail($$str({"Marker "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByte($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberByte);
	checkSingleMemberByte($cast($SingleMemberByte, $($nc(e)->getAnnotation($SingleMemberByte::class$))), e);
}

void UnitTest::checkSingleMemberByte($SingleMemberByte* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 1) {
			$var($String, var$0, $$str({"SingleMemberByte "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByte "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShort($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberShort);
	checkSingleMemberShort($cast($SingleMemberShort, $($nc(e)->getAnnotation($SingleMemberShort::class$))), e);
}

void UnitTest::checkSingleMemberShort($SingleMemberShort* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 2) {
			$var($String, var$0, $$str({"SingleMemberShort "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShort "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberInt($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberInt);
	checkSingleMemberInt($cast($SingleMemberInt, $($nc(e)->getAnnotation($SingleMemberInt::class$))), e);
}

void UnitTest::checkSingleMemberInt($SingleMemberInt* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 3) {
			$var($String, var$0, $$str({"SingleMemberInt "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberInt "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLong($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberLong);
	checkSingleMemberLong($cast($SingleMemberLong, $($nc(e)->getAnnotation($SingleMemberLong::class$))), e);
}

void UnitTest::checkSingleMemberLong($SingleMemberLong* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != (int64_t)4) {
			$var($String, var$0, $$str({"SingleMemberLong "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLong "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberChar($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberChar);
	checkSingleMemberChar($cast($SingleMemberChar, $($nc(e)->getAnnotation($SingleMemberChar::class$))), e);
}

void UnitTest::checkSingleMemberChar($SingleMemberChar* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != u'5') {
			$var($String, var$0, $$str({"SingleMemberChar "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberChar "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloat($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberFloat);
	checkSingleMemberFloat($cast($SingleMemberFloat, $($nc(e)->getAnnotation($SingleMemberFloat::class$))), e);
}

void UnitTest::checkSingleMemberFloat($SingleMemberFloat* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 6.0f) {
			$var($String, var$0, $$str({"SingleMemberFloat "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloat "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDouble($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberDouble);
	checkSingleMemberDouble($cast($SingleMemberDouble, $($nc(e)->getAnnotation($SingleMemberDouble::class$))), e);
}

void UnitTest::checkSingleMemberDouble($SingleMemberDouble* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 7.0) {
			$var($String, var$0, $$str({"SingleMemberDouble "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDouble "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBoolean($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberBoolean);
	checkSingleMemberBoolean($cast($SingleMemberBoolean, $($nc(e)->getAnnotation($SingleMemberBoolean::class$))), e);
}

void UnitTest::checkSingleMemberBoolean($SingleMemberBoolean* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if (!$nc(a)->value()) {
			$var($String, var$0, $$str({"SingleMemberBoolean "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBoolean "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberString($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberString);
	checkSingleMemberString($cast($SingleMemberString, $($nc(e)->getAnnotation($SingleMemberString::class$))), e);
}

void UnitTest::checkSingleMemberString($SingleMemberString* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if (!($nc($($nc(a)->value()))->equals("custom"_s))) {
			$var($String, var$0, $$str({"SingleMemberString "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberString "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClass($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberClass);
	checkSingleMemberClass($cast($SingleMemberClass, $($nc(e)->getAnnotation($SingleMemberClass::class$))), e);
}

void UnitTest::checkSingleMemberClass($SingleMemberClass* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		$load($Map);
		if ($nc(a)->value() != $Map::class$) {
			$var($String, var$0, $$str({"SingleMemberClass "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClass "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnum($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberEnum);
	checkSingleMemberEnum($cast($SingleMemberEnum, $($nc(e)->getAnnotation($SingleMemberEnum::class$))), e);
}

void UnitTest::checkSingleMemberEnum($SingleMemberEnum* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		$init($Stooge);
		if ($nc(a)->value() != $Stooge::MOE) {
			$var($String, var$0, $$str({"SingleMemberEnum "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnum "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberByteWithDef);
	checkSingleMemberByteOvrdDef($cast($SingleMemberByteWithDef, $($nc(e)->getAnnotation($SingleMemberByteWithDef::class$))), e);
}

void UnitTest::checkSingleMemberByteOvrdDef($SingleMemberByteWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 1) {
			$var($String, var$0, $$str({"SingleMemberByteOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberShortWithDef);
	checkSingleMemberShortOvrdDef($cast($SingleMemberShortWithDef, $($nc(e)->getAnnotation($SingleMemberShortWithDef::class$))), e);
}

void UnitTest::checkSingleMemberShortOvrdDef($SingleMemberShortWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 2) {
			$var($String, var$0, $$str({"SingleMemberShortOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberIntWithDef);
	checkSingleMemberIntOvrdDef($cast($SingleMemberIntWithDef, $($nc(e)->getAnnotation($SingleMemberIntWithDef::class$))), e);
}

void UnitTest::checkSingleMemberIntOvrdDef($SingleMemberIntWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 3) {
			$var($String, var$0, $$str({"SingleMemberIntOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberLongWithDef);
	checkSingleMemberLongOvrdDef($cast($SingleMemberLongWithDef, $($nc(e)->getAnnotation($SingleMemberLongWithDef::class$))), e);
}

void UnitTest::checkSingleMemberLongOvrdDef($SingleMemberLongWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != (int64_t)4) {
			$var($String, var$0, $$str({"SingleMemberLongOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberCharWithDef);
	checkSingleMemberCharOvrdDef($cast($SingleMemberCharWithDef, $($nc(e)->getAnnotation($SingleMemberCharWithDef::class$))), e);
}

void UnitTest::checkSingleMemberCharOvrdDef($SingleMemberCharWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != u'5') {
			$var($String, var$0, $$str({"SingleMemberCharOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberFloatWithDef);
	checkSingleMemberFloatOvrdDef($cast($SingleMemberFloatWithDef, $($nc(e)->getAnnotation($SingleMemberFloatWithDef::class$))), e);
}

void UnitTest::checkSingleMemberFloatOvrdDef($SingleMemberFloatWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 6.0f) {
			$var($String, var$0, $$str({"SingleMemberFloatOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberDoubleWithDef);
	checkSingleMemberDoubleOvrdDef($cast($SingleMemberDoubleWithDef, $($nc(e)->getAnnotation($SingleMemberDoubleWithDef::class$))), e);
}

void UnitTest::checkSingleMemberDoubleOvrdDef($SingleMemberDoubleWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 7.0) {
			$var($String, var$0, $$str({"SingleMemberDoubleOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberBooleanWithDef);
	checkSingleMemberBooleanOvrdDef($cast($SingleMemberBooleanWithDef, $($nc(e)->getAnnotation($SingleMemberBooleanWithDef::class$))), e);
}

void UnitTest::checkSingleMemberBooleanOvrdDef($SingleMemberBooleanWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if (!$nc(a)->value()) {
			$var($String, var$0, $$str({"SingleMemberBooleanOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberStringWithDef);
	checkSingleMemberStringOvrdDef($cast($SingleMemberStringWithDef, $($nc(e)->getAnnotation($SingleMemberStringWithDef::class$))), e);
}

void UnitTest::checkSingleMemberStringOvrdDef($SingleMemberStringWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if (!($nc($($nc(a)->value()))->equals("custom"_s))) {
			$var($String, var$0, $$str({"SingleMemberStringOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberClassWithDef);
	checkSingleMemberClassOvrdDef($cast($SingleMemberClassWithDef, $($nc(e)->getAnnotation($SingleMemberClassWithDef::class$))), e);
}

void UnitTest::checkSingleMemberClassOvrdDef($SingleMemberClassWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		$load($Map);
		if ($nc(a)->value() != $Map::class$) {
			$var($String, var$0, $$str({"SingleMemberClassOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberEnumWithDef);
	checkSingleMemberEnumOvrdDef($cast($SingleMemberEnumWithDef, $($nc(e)->getAnnotation($SingleMemberEnumWithDef::class$))), e);
}

void UnitTest::checkSingleMemberEnumOvrdDef($SingleMemberEnumWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		$init($Stooge);
		if ($nc(a)->value() != $Stooge::MOE) {
			$var($String, var$0, $$str({"SingleMemberEnumOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberByteWithDef);
	checkSingleMemberByteAcceptDef($cast($SingleMemberByteWithDef, $($nc(e)->getAnnotation($SingleMemberByteWithDef::class$))), e);
}

void UnitTest::checkSingleMemberByteAcceptDef($SingleMemberByteWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 11) {
			$var($String, var$0, $$str({"SingleMemberByteAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberShortWithDef);
	checkSingleMemberShortAcceptDef($cast($SingleMemberShortWithDef, $($nc(e)->getAnnotation($SingleMemberShortWithDef::class$))), e);
}

void UnitTest::checkSingleMemberShortAcceptDef($SingleMemberShortWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 12) {
			$var($String, var$0, $$str({"SingleMemberShortAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberIntWithDef);
	checkSingleMemberIntAcceptDef($cast($SingleMemberIntWithDef, $($nc(e)->getAnnotation($SingleMemberIntWithDef::class$))), e);
}

void UnitTest::checkSingleMemberIntAcceptDef($SingleMemberIntWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 13) {
			$var($String, var$0, $$str({"SingleMemberIntAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberLongWithDef);
	checkSingleMemberLongAcceptDef($cast($SingleMemberLongWithDef, $($nc(e)->getAnnotation($SingleMemberLongWithDef::class$))), e);
}

void UnitTest::checkSingleMemberLongAcceptDef($SingleMemberLongWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != (int64_t)14) {
			$var($String, var$0, $$str({"SingleMemberLongAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberCharWithDef);
	checkSingleMemberCharAcceptDef($cast($SingleMemberCharWithDef, $($nc(e)->getAnnotation($SingleMemberCharWithDef::class$))), e);
}

void UnitTest::checkSingleMemberCharAcceptDef($SingleMemberCharWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != u'V') {
			$var($String, var$0, $$str({"SingleMemberCharAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberFloatWithDef);
	checkSingleMemberFloatAcceptDef($cast($SingleMemberFloatWithDef, $($nc(e)->getAnnotation($SingleMemberFloatWithDef::class$))), e);
}

void UnitTest::checkSingleMemberFloatAcceptDef($SingleMemberFloatWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 16.0f) {
			$var($String, var$0, $$str({"SingleMemberFloatAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberDoubleWithDef);
	checkSingleMemberDoubleAcceptDef($cast($SingleMemberDoubleWithDef, $($nc(e)->getAnnotation($SingleMemberDoubleWithDef::class$))), e);
}

void UnitTest::checkSingleMemberDoubleAcceptDef($SingleMemberDoubleWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != 17.0) {
			$var($String, var$0, $$str({"SingleMemberDoubleAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberBooleanWithDef);
	checkSingleMemberBooleanAcceptDef($cast($SingleMemberBooleanWithDef, $($nc(e)->getAnnotation($SingleMemberBooleanWithDef::class$))), e);
}

void UnitTest::checkSingleMemberBooleanAcceptDef($SingleMemberBooleanWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value()) {
			$var($String, var$0, $$str({"SingleMemberBooleanAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $$str(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberStringWithDef);
	checkSingleMemberStringAcceptDef($cast($SingleMemberStringWithDef, $($nc(e)->getAnnotation($SingleMemberStringWithDef::class$))), e);
}

void UnitTest::checkSingleMemberStringAcceptDef($SingleMemberStringWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if (!($nc($($nc(a)->value()))->equals("default"_s))) {
			$var($String, var$0, $$str({"SingleMemberStringAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberClassWithDef);
	checkSingleMemberClassAcceptDef($cast($SingleMemberClassWithDef, $($nc(e)->getAnnotation($SingleMemberClassWithDef::class$))), e);
}

void UnitTest::checkSingleMemberClassAcceptDef($SingleMemberClassWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc(a)->value() != $Class::class$) {
			$var($String, var$0, $$str({"SingleMemberClassAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberEnumWithDef);
	checkSingleMemberEnumAcceptDef($cast($SingleMemberEnumWithDef, $($nc(e)->getAnnotation($SingleMemberEnumWithDef::class$))), e);
}

void UnitTest::checkSingleMemberEnumAcceptDef($SingleMemberEnumWithDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		$init($Stooge);
		if ($nc(a)->value() != $Stooge::LARRY) {
			$var($String, var$0, $$str({"SingleMemberEnumAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberByteArray);
	checkSingleMemberByteArrEmpty($cast($SingleMemberByteArray, $($nc(e)->getAnnotation($SingleMemberByteArray::class$))), e);
}

void UnitTest::checkSingleMemberByteArrEmpty($SingleMemberByteArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberByteArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberShortArray);
	checkSingleMemberShortArrEmpty($cast($SingleMemberShortArray, $($nc(e)->getAnnotation($SingleMemberShortArray::class$))), e);
}

void UnitTest::checkSingleMemberShortArrEmpty($SingleMemberShortArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberShortArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberIntArray);
	checkSingleMemberIntArrEmpty($cast($SingleMemberIntArray, $($nc(e)->getAnnotation($SingleMemberIntArray::class$))), e);
}

void UnitTest::checkSingleMemberIntArrEmpty($SingleMemberIntArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberIntArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberLongArray);
	checkSingleMemberLongArrEmpty($cast($SingleMemberLongArray, $($nc(e)->getAnnotation($SingleMemberLongArray::class$))), e);
}

void UnitTest::checkSingleMemberLongArrEmpty($SingleMemberLongArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberLongArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberCharArray);
	checkSingleMemberCharArrEmpty($cast($SingleMemberCharArray, $($nc(e)->getAnnotation($SingleMemberCharArray::class$))), e);
}

void UnitTest::checkSingleMemberCharArrEmpty($SingleMemberCharArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberCharArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberFloatArray);
	checkSingleMemberFloatArrEmpty($cast($SingleMemberFloatArray, $($nc(e)->getAnnotation($SingleMemberFloatArray::class$))), e);
}

void UnitTest::checkSingleMemberFloatArrEmpty($SingleMemberFloatArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberFloatArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberDoubleArray);
	checkSingleMemberDoubleArrEmpty($cast($SingleMemberDoubleArray, $($nc(e)->getAnnotation($SingleMemberDoubleArray::class$))), e);
}

void UnitTest::checkSingleMemberDoubleArrEmpty($SingleMemberDoubleArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberDoubleArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberBooleanArray);
	checkSingleMemberBooleanArrEmpty($cast($SingleMemberBooleanArray, $($nc(e)->getAnnotation($SingleMemberBooleanArray::class$))), e);
}

void UnitTest::checkSingleMemberBooleanArrEmpty($SingleMemberBooleanArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberBooleanArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberStringArray);
	checkSingleMemberStringArrEmpty($cast($SingleMemberStringArray, $($nc(e)->getAnnotation($SingleMemberStringArray::class$))), e);
}

void UnitTest::checkSingleMemberStringArrEmpty($SingleMemberStringArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberStringArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberClassArray);
	checkSingleMemberClassArrEmpty($cast($SingleMemberClassArray, $($nc(e)->getAnnotation($SingleMemberClassArray::class$))), e);
}

void UnitTest::checkSingleMemberClassArrEmpty($SingleMemberClassArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberClassArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrEmpty($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberEnumArray);
	checkSingleMemberEnumArrEmpty($cast($SingleMemberEnumArray, $($nc(e)->getAnnotation($SingleMemberEnumArray::class$))), e);
}

void UnitTest::checkSingleMemberEnumArrEmpty($SingleMemberEnumArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		if ($nc($($nc(a)->value()))->length != 0) {
			$var($String, var$0, $$str({"SingleMemberEnumArrEmpty "_s, e, " = "_s}));
			fail($$concat(var$0, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrEmpty "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberByteArray);
	checkSingleMemberByteArrOne($cast($SingleMemberByteArray, $($nc(e)->getAnnotation($SingleMemberByteArray::class$))), e);
}

void UnitTest::checkSingleMemberByteArrOne($SingleMemberByteArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != (int8_t)1) {
			$var($String, var$1, $$str({"SingleMemberByteArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberShortArray);
	checkSingleMemberShortArrOne($cast($SingleMemberShortArray, $($nc(e)->getAnnotation($SingleMemberShortArray::class$))), e);
}

void UnitTest::checkSingleMemberShortArrOne($SingleMemberShortArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != (int16_t)2) {
			$var($String, var$1, $$str({"SingleMemberShortArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberIntArray);
	checkSingleMemberIntArrOne($cast($SingleMemberIntArray, $($nc(e)->getAnnotation($SingleMemberIntArray::class$))), e);
}

void UnitTest::checkSingleMemberIntArrOne($SingleMemberIntArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != 3) {
			$var($String, var$1, $$str({"SingleMemberIntArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberLongArray);
	checkSingleMemberLongArrOne($cast($SingleMemberLongArray, $($nc(e)->getAnnotation($SingleMemberLongArray::class$))), e);
}

void UnitTest::checkSingleMemberLongArrOne($SingleMemberLongArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != (int64_t)4) {
			$var($String, var$1, $$str({"SingleMemberLongArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberCharArray);
	checkSingleMemberCharArrOne($cast($SingleMemberCharArray, $($nc(e)->getAnnotation($SingleMemberCharArray::class$))), e);
}

void UnitTest::checkSingleMemberCharArrOne($SingleMemberCharArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != u'5') {
			$var($String, var$1, $$str({"SingleMemberCharArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberFloatArray);
	checkSingleMemberFloatArrOne($cast($SingleMemberFloatArray, $($nc(e)->getAnnotation($SingleMemberFloatArray::class$))), e);
}

void UnitTest::checkSingleMemberFloatArrOne($SingleMemberFloatArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != 6.0f) {
			$var($String, var$1, $$str({"SingleMemberFloatArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberDoubleArray);
	checkSingleMemberDoubleArrOne($cast($SingleMemberDoubleArray, $($nc(e)->getAnnotation($SingleMemberDoubleArray::class$))), e);
}

void UnitTest::checkSingleMemberDoubleArrOne($SingleMemberDoubleArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != 7.0) {
			$var($String, var$1, $$str({"SingleMemberDoubleArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberBooleanArray);
	checkSingleMemberBooleanArrOne($cast($SingleMemberBooleanArray, $($nc(e)->getAnnotation($SingleMemberBooleanArray::class$))), e);
}

void UnitTest::checkSingleMemberBooleanArrOne($SingleMemberBooleanArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || !$nc($($nc(a)->value()))->get(0)) {
			$var($String, var$1, $$str({"SingleMemberBooleanArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberStringArray);
	checkSingleMemberStringArrOne($cast($SingleMemberStringArray, $($nc(e)->getAnnotation($SingleMemberStringArray::class$))), e);
}

void UnitTest::checkSingleMemberStringArrOne($SingleMemberStringArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || !($nc($nc($($nc(a)->value()))->get(0))->equals("custom"_s))) {
			$var($String, var$1, $$str({"SingleMemberStringArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberClassArray);
	checkSingleMemberClassArrOne($cast($SingleMemberClassArray, $($nc(e)->getAnnotation($SingleMemberClassArray::class$))), e);
}

void UnitTest::checkSingleMemberClassArrOne($SingleMemberClassArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		$load($Map);
		if (var$0 || $nc($($nc(a)->value()))->get(0) != $Map::class$) {
			$var($String, var$1, $$str({"SingleMemberClassArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrOne($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberEnumArray);
	checkSingleMemberEnumArrOne($cast($SingleMemberEnumArray, $($nc(e)->getAnnotation($SingleMemberEnumArray::class$))), e);
}

void UnitTest::checkSingleMemberEnumArrOne($SingleMemberEnumArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		$init($Stooge);
		if (var$0 || $nc($($nc(a)->value()))->get(0) != $Stooge::MOE) {
			$var($String, var$1, $$str({"SingleMemberEnumArrOne "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrOne "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberByteArray);
	checkSingleMemberByteArrTwo($cast($SingleMemberByteArray, $($nc(e)->getAnnotation($SingleMemberByteArray::class$))), e);
}

void UnitTest::checkSingleMemberByteArrTwo($SingleMemberByteArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		bool var$0 = var$1 || $nc($($nc(a)->value()))->get(0) != (int8_t)1;
		if (var$0 || $nc($($nc(a)->value()))->get(1) != (int8_t)2) {
			$var($String, var$2, $$str({"SingleMemberByteArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberShortArray);
	checkSingleMemberShortArrTwo($cast($SingleMemberShortArray, $($nc(e)->getAnnotation($SingleMemberShortArray::class$))), e);
}

void UnitTest::checkSingleMemberShortArrTwo($SingleMemberShortArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		bool var$0 = var$1 || $nc($($nc(a)->value()))->get(0) != (int16_t)2;
		if (var$0 || $nc($($nc(a)->value()))->get(1) != (int16_t)3) {
			$var($String, var$2, $$str({"SingleMemberShortArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberIntArray);
	checkSingleMemberIntArrTwo($cast($SingleMemberIntArray, $($nc(e)->getAnnotation($SingleMemberIntArray::class$))), e);
}

void UnitTest::checkSingleMemberIntArrTwo($SingleMemberIntArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		bool var$0 = var$1 || $nc($($nc(a)->value()))->get(0) != 3;
		if (var$0 || $nc($($nc(a)->value()))->get(1) != 4) {
			$var($String, var$2, $$str({"SingleMemberIntArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberLongArray);
	checkSingleMemberLongArrTwo($cast($SingleMemberLongArray, $($nc(e)->getAnnotation($SingleMemberLongArray::class$))), e);
}

void UnitTest::checkSingleMemberLongArrTwo($SingleMemberLongArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		bool var$0 = var$1 || $nc($($nc(a)->value()))->get(0) != (int64_t)4;
		if (var$0 || $nc($($nc(a)->value()))->get(1) != (int64_t)5) {
			$var($String, var$2, $$str({"SingleMemberLongArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberCharArray);
	checkSingleMemberCharArrTwo($cast($SingleMemberCharArray, $($nc(e)->getAnnotation($SingleMemberCharArray::class$))), e);
}

void UnitTest::checkSingleMemberCharArrTwo($SingleMemberCharArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		bool var$0 = var$1 || $nc($($nc(a)->value()))->get(0) != u'5';
		if (var$0 || $nc($($nc(a)->value()))->get(1) != u'6') {
			$var($String, var$2, $$str({"SingleMemberCharArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberFloatArray);
	checkSingleMemberFloatArrTwo($cast($SingleMemberFloatArray, $($nc(e)->getAnnotation($SingleMemberFloatArray::class$))), e);
}

void UnitTest::checkSingleMemberFloatArrTwo($SingleMemberFloatArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		bool var$0 = var$1 || $nc($($nc(a)->value()))->get(0) != 6.0f;
		if (var$0 || $nc($($nc(a)->value()))->get(1) != 7.0f) {
			$var($String, var$2, $$str({"SingleMemberFloatArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberDoubleArray);
	checkSingleMemberDoubleArrTwo($cast($SingleMemberDoubleArray, $($nc(e)->getAnnotation($SingleMemberDoubleArray::class$))), e);
}

void UnitTest::checkSingleMemberDoubleArrTwo($SingleMemberDoubleArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		bool var$0 = var$1 || $nc($($nc(a)->value()))->get(0) != 7.0;
		if (var$0 || $nc($($nc(a)->value()))->get(1) != 8.0) {
			$var($String, var$2, $$str({"SingleMemberDoubleArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberBooleanArray);
	checkSingleMemberBooleanArrTwo($cast($SingleMemberBooleanArray, $($nc(e)->getAnnotation($SingleMemberBooleanArray::class$))), e);
}

void UnitTest::checkSingleMemberBooleanArrTwo($SingleMemberBooleanArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		bool var$0 = var$1 || !$nc($($nc(a)->value()))->get(0);
		if (var$0 || $nc($($nc(a)->value()))->get(1)) {
			$var($String, var$2, $$str({"SingleMemberBooleanArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberStringArray);
	checkSingleMemberStringArrTwo($cast($SingleMemberStringArray, $($nc(e)->getAnnotation($SingleMemberStringArray::class$))), e);
}

void UnitTest::checkSingleMemberStringArrTwo($SingleMemberStringArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		bool var$0 = var$1 || !($nc($nc($($nc(a)->value()))->get(0))->equals("custom"_s));
		if (var$0 || !($nc($nc($($nc(a)->value()))->get(1))->equals("paint"_s))) {
			$var($String, var$2, $$str({"SingleMemberStringArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberClassArray);
	checkSingleMemberClassArrTwo($cast($SingleMemberClassArray, $($nc(e)->getAnnotation($SingleMemberClassArray::class$))), e);
}

void UnitTest::checkSingleMemberClassArrTwo($SingleMemberClassArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		$load($Map);
		bool var$0 = var$1 || $nc($($nc(a)->value()))->get(0) != $Map::class$;
		$load($Set);
		if (var$0 || $nc($($nc(a)->value()))->get(1) != $Set::class$) {
			$var($String, var$2, $$str({"SingleMemberClassArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrTwo($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberEnumArray);
	checkSingleMemberEnumArrTwo($cast($SingleMemberEnumArray, $($nc(e)->getAnnotation($SingleMemberEnumArray::class$))), e);
}

void UnitTest::checkSingleMemberEnumArrTwo($SingleMemberEnumArray* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$1 = $nc($($nc(a)->value()))->length != 2;
		$init($Stooge);
		bool var$0 = var$1 || $nc($($nc(a)->value()))->get(0) != $Stooge::MOE;
		if (var$0 || $nc($($nc(a)->value()))->get(1) != $Stooge::CURLY) {
			$var($String, var$2, $$str({"SingleMemberEnumArrTwo "_s, e, " = "_s}));
			fail($$concat(var$2, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrTwo "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberByteArrayDef);
	checkSingleMemberByteArrOvrdDef($cast($SingleMemberByteArrayDef, $($nc(e)->getAnnotation($SingleMemberByteArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberByteArrOvrdDef($SingleMemberByteArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != (int8_t)1) {
			$var($String, var$1, $$str({"SingleMemberByteArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberShortArrayDef);
	checkSingleMemberShortArrOvrdDef($cast($SingleMemberShortArrayDef, $($nc(e)->getAnnotation($SingleMemberShortArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberShortArrOvrdDef($SingleMemberShortArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != (int16_t)2) {
			$var($String, var$1, $$str({"SingleMemberShortArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberIntArrayDef);
	checkSingleMemberIntArrOvrdDef($cast($SingleMemberIntArrayDef, $($nc(e)->getAnnotation($SingleMemberIntArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberIntArrOvrdDef($SingleMemberIntArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != 3) {
			$var($String, var$1, $$str({"SingleMemberIntArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberLongArrayDef);
	checkSingleMemberLongArrOvrdDef($cast($SingleMemberLongArrayDef, $($nc(e)->getAnnotation($SingleMemberLongArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberLongArrOvrdDef($SingleMemberLongArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != (int64_t)4) {
			$var($String, var$1, $$str({"SingleMemberLongArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberCharArrayDef);
	checkSingleMemberCharArrOvrdDef($cast($SingleMemberCharArrayDef, $($nc(e)->getAnnotation($SingleMemberCharArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberCharArrOvrdDef($SingleMemberCharArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != u'5') {
			$var($String, var$1, $$str({"SingleMemberCharArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberFloatArrayDef);
	checkSingleMemberFloatArrOvrdDef($cast($SingleMemberFloatArrayDef, $($nc(e)->getAnnotation($SingleMemberFloatArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberFloatArrOvrdDef($SingleMemberFloatArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != 6.0f) {
			$var($String, var$1, $$str({"SingleMemberFloatArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberDoubleArrayDef);
	checkSingleMemberDoubleArrOvrdDef($cast($SingleMemberDoubleArrayDef, $($nc(e)->getAnnotation($SingleMemberDoubleArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberDoubleArrOvrdDef($SingleMemberDoubleArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != 7.0) {
			$var($String, var$1, $$str({"SingleMemberDoubleArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberBooleanArrayDef);
	checkSingleMemberBooleanArrOvrdDef($cast($SingleMemberBooleanArrayDef, $($nc(e)->getAnnotation($SingleMemberBooleanArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberBooleanArrOvrdDef($SingleMemberBooleanArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || !$nc($($nc(a)->value()))->get(0)) {
			$var($String, var$1, $$str({"SingleMemberBooleanArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberStringArrayDef);
	checkSingleMemberStringArrOvrdDef($cast($SingleMemberStringArrayDef, $($nc(e)->getAnnotation($SingleMemberStringArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberStringArrOvrdDef($SingleMemberStringArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || !($nc($nc($($nc(a)->value()))->get(0))->equals("custom"_s))) {
			$var($String, var$1, $$str({"SingleMemberStringArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberClassArrayDef);
	checkSingleMemberClassArrOvrdDef($cast($SingleMemberClassArrayDef, $($nc(e)->getAnnotation($SingleMemberClassArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberClassArrOvrdDef($SingleMemberClassArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		$load($Map);
		if (var$0 || $nc($($nc(a)->value()))->get(0) != $Map::class$) {
			$var($String, var$1, $$str({"SingleMemberClassArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrOvrdDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberEnumArrayDef);
	checkSingleMemberEnumArrOvrdDef($cast($SingleMemberEnumArrayDef, $($nc(e)->getAnnotation($SingleMemberEnumArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberEnumArrOvrdDef($SingleMemberEnumArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		$init($Stooge);
		if (var$0 || $nc($($nc(a)->value()))->get(0) != $Stooge::MOE) {
			$var($String, var$1, $$str({"SingleMemberEnumArrOvrdDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrOvrdDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberByteArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberByteArrayDef);
	checkSingleMemberByteArrAcceptDef($cast($SingleMemberByteArrayDef, $($nc(e)->getAnnotation($SingleMemberByteArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberByteArrAcceptDef($SingleMemberByteArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != (int8_t)11) {
			$var($String, var$1, $$str({"SingleMemberByteArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberByteArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberShortArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberShortArrayDef);
	checkSingleMemberShortArrAcceptDef($cast($SingleMemberShortArrayDef, $($nc(e)->getAnnotation($SingleMemberShortArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberShortArrAcceptDef($SingleMemberShortArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != (int16_t)12) {
			$var($String, var$1, $$str({"SingleMemberShortArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberShortArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberIntArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberIntArrayDef);
	checkSingleMemberIntArrAcceptDef($cast($SingleMemberIntArrayDef, $($nc(e)->getAnnotation($SingleMemberIntArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberIntArrAcceptDef($SingleMemberIntArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != 13) {
			$var($String, var$1, $$str({"SingleMemberIntArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberIntArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberLongArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberLongArrayDef);
	checkSingleMemberLongArrAcceptDef($cast($SingleMemberLongArrayDef, $($nc(e)->getAnnotation($SingleMemberLongArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberLongArrAcceptDef($SingleMemberLongArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != (int64_t)14) {
			$var($String, var$1, $$str({"SingleMemberLongArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberLongArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberCharArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberCharArrayDef);
	checkSingleMemberCharArrAcceptDef($cast($SingleMemberCharArrayDef, $($nc(e)->getAnnotation($SingleMemberCharArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberCharArrAcceptDef($SingleMemberCharArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != u'V') {
			$var($String, var$1, $$str({"SingleMemberCharArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberCharArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberFloatArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberFloatArrayDef);
	checkSingleMemberFloatArrAcceptDef($cast($SingleMemberFloatArrayDef, $($nc(e)->getAnnotation($SingleMemberFloatArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberFloatArrAcceptDef($SingleMemberFloatArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != 16.0f) {
			$var($String, var$1, $$str({"SingleMemberFloatArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberFloatArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberDoubleArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberDoubleArrayDef);
	checkSingleMemberDoubleArrAcceptDef($cast($SingleMemberDoubleArrayDef, $($nc(e)->getAnnotation($SingleMemberDoubleArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberDoubleArrAcceptDef($SingleMemberDoubleArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != 17.0) {
			$var($String, var$1, $$str({"SingleMemberDoubleArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberDoubleArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberBooleanArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberBooleanArrayDef);
	checkSingleMemberBooleanArrAcceptDef($cast($SingleMemberBooleanArrayDef, $($nc(e)->getAnnotation($SingleMemberBooleanArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberBooleanArrAcceptDef($SingleMemberBooleanArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0)) {
			$var($String, var$1, $$str({"SingleMemberBooleanArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberBooleanArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberStringArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberStringArrayDef);
	checkSingleMemberStringArrAcceptDef($cast($SingleMemberStringArrayDef, $($nc(e)->getAnnotation($SingleMemberStringArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberStringArrAcceptDef($SingleMemberStringArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || !($nc($nc($($nc(a)->value()))->get(0))->equals("default"_s))) {
			$var($String, var$1, $$str({"SingleMemberStringArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberStringArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberClassArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberClassArrayDef);
	checkSingleMemberClassArrAcceptDef($cast($SingleMemberClassArrayDef, $($nc(e)->getAnnotation($SingleMemberClassArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberClassArrAcceptDef($SingleMemberClassArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		if (var$0 || $nc($($nc(a)->value()))->get(0) != $Class::class$) {
			$var($String, var$1, $$str({"SingleMemberClassArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberClassArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkSingleMemberEnumArrAcceptDef($AnnotatedElement* e) {
	$init(UnitTest);
	$load($SingleMemberEnumArrayDef);
	checkSingleMemberEnumArrAcceptDef($cast($SingleMemberEnumArrayDef, $($nc(e)->getAnnotation($SingleMemberEnumArrayDef::class$))), e);
}

void UnitTest::checkSingleMemberEnumArrAcceptDef($SingleMemberEnumArrayDef* a, $AnnotatedElement* e) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool var$0 = $nc($($nc(a)->value()))->length != 1;
		$init($Stooge);
		if (var$0 || $nc($($nc(a)->value()))->get(0) != $Stooge::LARRY) {
			$var($String, var$1, $$str({"SingleMemberEnumArrAcceptDef "_s, e, " = "_s}));
			fail($$concat(var$1, $(a->value())));
		}
	} catch ($Throwable& t) {
		fail($$str({"SingleMemberEnumArrAcceptDef "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkEquals($AnnotatedElement* e1, $AnnotatedElement* e2, $Class* annoType) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	$var($Annotation, a1, $nc(e1)->getAnnotation(annoType));
	$var($Annotation, a2, $nc(e2)->getAnnotation(annoType));
	try {
		if (!$nc(a1)->equals(a2)) {
			fail($$str({a1, " != "_s, a2}));
		}
		int32_t var$0 = $nc(a1)->hashCode();
		if (var$0 != $nc(a2)->hashCode()) {
			$var($String, var$6, $$str({a1, ".hashCode() ["_s}));
			$var($String, var$5, $$concat(var$6, $$str(a1->hashCode())));
			$var($String, var$4, $$concat(var$5, "] != "_s));
			$var($String, var$3, $$concat(var$4, $(a2)));
			$var($String, var$2, $$concat(var$3, " .hashCode()["_s));
			$var($String, var$1, $$concat(var$2, $$str(a2->hashCode())));
			fail($$concat(var$1, "]"_s));
		}
		if (!($nc($($nc(a1)->toString()))->equals($($nc(a2)->toString())))) {
			fail($$str({a1, ".toString() != "_s, a2, ".toString()"_s}));
		}
	} catch ($Throwable& t) {
		fail($$str({a1, " == "_s, a2, ": "_s, t}));
	}
}

void UnitTest::checkUnequals($AnnotatedElement* e1, $AnnotatedElement* e2, $Class* annoType) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	$var($Annotation, a1, $nc(e1)->getAnnotation(annoType));
	$var($Annotation, a2, $nc(e2)->getAnnotation(annoType));
	try {
		if ($nc(a1)->equals(a2)) {
			fail($$str({a1, " == "_s, a2}));
		}
		int32_t var$0 = $nc(a1)->hashCode();
		if (var$0 == $nc(a2)->hashCode()) {
			$var($String, var$6, $$str({a1, ".hashCode() ["_s}));
			$var($String, var$5, $$concat(var$6, $$str(a1->hashCode())));
			$var($String, var$4, $$concat(var$5, "] == "_s));
			$var($String, var$3, $$concat(var$4, $(a2)));
			$var($String, var$2, $$concat(var$3, " .hashCode()["_s));
			$var($String, var$1, $$concat(var$2, $$str(a2->hashCode())));
			fail($$concat(var$1, "]"_s));
		}
		if ($nc($($nc(a1)->toString()))->equals($($nc(a2)->toString()))) {
			fail($$str({a1, ".toString() == "_s, a2, ".toString()"_s}));
		}
	} catch ($Throwable& t) {
		fail($$str({a1, " != "_s, a2, ": "_s, t}));
	}
}

void UnitTest::checkSerialization($AnnotatedElement* e, $Class* annoType) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	$var($Annotation, a1, $nc(e)->getAnnotation(annoType));
	$var($Object, a2, deepCopy(a1));
	try {
		if (!$nc(a1)->equals(a2)) {
			fail($$str({"Serialization: "_s, a1, " != "_s, a2}));
		}
		int32_t var$0 = $nc(a1)->hashCode();
		if (var$0 != $nc($of(a2))->hashCode()) {
			$var($String, var$6, $$str({"Serialization: "_s, a1, ".hashCode() ["_s}));
			$var($String, var$5, $$concat(var$6, $$str(a1->hashCode())));
			$var($String, var$4, $$concat(var$5, "] != "_s));
			$var($String, var$3, $$concat(var$4, $(a2)));
			$var($String, var$2, $$concat(var$3, " .hashCode()["_s));
			$var($String, var$1, $$concat(var$2, $$str($of(a2)->hashCode())));
			fail($$concat(var$1, "]"_s));
		}
		if (!($nc($($nc(a1)->toString()))->equals($($nc($of(a2))->toString())))) {
			fail($$str({"Serialization: "_s, a1, ".toString() != "_s, a2, ".toString()"_s}));
		}
	} catch ($Throwable& t) {
		fail($$str({"Serialization: "_s, a1, " == "_s, a2, ": "_s, t}));
	}
}

$Object* UnitTest::deepCopy(Object$* original) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	try {
		$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream));
		$var($ObjectOutputStream, oos, $new($ObjectOutputStream, bos));
		oos->writeObject(original);
		oos->flush();
		$var($ByteArrayInputStream, bin, $new($ByteArrayInputStream, $(bos->toByteArray())));
		$var($ObjectInputStream, ois, $new($ObjectInputStream, bin));
		return $of(ois->readObject());
	} catch ($Exception& e) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void UnitTest::checkInheritence($AnnotatedElement* e, bool shouldHaveFoo, bool shouldHaveBar) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		$load($Foo);
		bool hasFoo = $nc(e)->isAnnotationPresent($Foo::class$);
		$load($Bar);
		bool hasBar = e->isAnnotationPresent($Bar::class$);
		if (hasFoo != shouldHaveFoo || hasBar != shouldHaveBar) {
			fail($$str({"Inheritance(1): "_s, e, " - Foo: "_s, $$str(hasFoo), ", Bar: "_s, $$str(hasBar)}));
		}
		hasFoo = (hasBar = false);
		$var($AnnotationArray, allAnnotations, e->getAnnotations());
		{
			$var($AnnotationArray, arr$, allAnnotations);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Annotation, a, arr$->get(i$));
				{
					if ($instanceOf($Foo, a)) {
						hasFoo = true;
					} else if ($instanceOf($Bar, a)) {
						hasBar = true;
					}
				}
			}
		}
		if (hasFoo != shouldHaveFoo || hasBar != shouldHaveBar) {
			fail($$str({"Inheritance(2): "_s, e, " - Foo: "_s, $$str(hasFoo), ", Bar: "_s, $$str(hasBar)}));
		}
	} catch ($Throwable& t) {
		fail($$str({"Inheritance: "_s, e, ": "_s, t}));
	}
}

void UnitTest::checkDeclaredAnnotations($AnnotatedElement* e, bool shouldHaveFoo, bool shouldHaveBar) {
	$init(UnitTest);
	$useLocalCurrentObjectStackCache();
	++UnitTest::numTests;
	try {
		bool hasFoo = false;
		bool hasBar = false;
		$var($AnnotationArray, declaredAnnotations, $nc(e)->getDeclaredAnnotations());
		{
			$var($AnnotationArray, arr$, declaredAnnotations);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Annotation, a, arr$->get(i$));
				{
					if ($instanceOf($Foo, a)) {
						hasFoo = true;
					} else if ($instanceOf($Bar, a)) {
						hasBar = true;
					}
				}
			}
		}
		if (hasFoo != shouldHaveFoo || hasBar != shouldHaveBar) {
			fail($$str({"Declared annotations: "_s, e, " - Foo: "_s, $$str(hasFoo), ", Bar: "_s, $$str(hasBar)}));
		}
	} catch ($Throwable& t) {
		fail($$str({"Declared annotations: "_s, e, ": "_s, t}));
	}
}

void UnitTest::scalarTypesMethod() {
}

void UnitTest::scalarTypesAcceptDefaultMethod() {
}

void UnitTest::scalarTypesOverrideDefaultMethod() {
}

void UnitTest::emptyArrayTypesMethod() {
}

void UnitTest::singleElementArrayTypesMethod() {
}

void UnitTest::twoElementArrayTypesMethod() {
}

void UnitTest::arrayTypesAcceptDefaultMethod() {
}

void UnitTest::arrayTypesOverrideDefaultMethod() {
}

void UnitTest::markerMethod() {
}

void UnitTest::SingleMemberByte() {
}

void UnitTest::SingleMemberShort() {
}

void UnitTest::SingleMemberInt() {
}

void UnitTest::SingleMemberLong() {
}

void UnitTest::SingleMemberChar() {
}

void UnitTest::SingleMemberFloat() {
}

void UnitTest::SingleMemberDouble() {
}

void UnitTest::SingleMemberBoolean() {
}

void UnitTest::SingleMemberString() {
}

void UnitTest::SingleMemberClass() {
}

void UnitTest::SingleMemberEnum() {
}

void UnitTest::SingleMemberByteOvrdDef() {
}

void UnitTest::SingleMemberShortOvrdDef() {
}

void UnitTest::SingleMemberIntOvrdDef() {
}

void UnitTest::SingleMemberLongOvrdDef() {
}

void UnitTest::SingleMemberCharOvrdDef() {
}

void UnitTest::SingleMemberFloatOvrdDef() {
}

void UnitTest::SingleMemberDoubleOvrdDef() {
}

void UnitTest::SingleMemberBooleanOvrdDef() {
}

void UnitTest::SingleMemberStringOvrdDef() {
}

void UnitTest::SingleMemberClassOvrdDef() {
}

void UnitTest::SingleMemberEnumOvrdDef() {
}

void UnitTest::SingleMemberByteAcceptDef() {
}

void UnitTest::SingleMemberShortAcceptDef() {
}

void UnitTest::SingleMemberIntAcceptDef() {
}

void UnitTest::SingleMemberLongAcceptDef() {
}

void UnitTest::SingleMemberCharAcceptDef() {
}

void UnitTest::SingleMemberFloatAcceptDef() {
}

void UnitTest::SingleMemberDoubleAcceptDef() {
}

void UnitTest::SingleMemberBooleanAcceptDef() {
}

void UnitTest::SingleMemberStringAcceptDef() {
}

void UnitTest::SingleMemberClassAcceptDef() {
}

void UnitTest::SingleMemberEnumAcceptDef() {
}

void UnitTest::SingleMemberByteArrEmpty() {
}

void UnitTest::SingleMemberShortArrEmpty() {
}

void UnitTest::SingleMemberIntArrEmpty() {
}

void UnitTest::SingleMemberLongArrEmpty() {
}

void UnitTest::SingleMemberCharArrEmpty() {
}

void UnitTest::SingleMemberFloatArrEmpty() {
}

void UnitTest::SingleMemberDoubleArrEmpty() {
}

void UnitTest::SingleMemberBooleanArrEmpty() {
}

void UnitTest::SingleMemberStringArrEmpty() {
}

void UnitTest::SingleMemberClassArrEmpty() {
}

void UnitTest::SingleMemberEnumArrEmpty() {
}

void UnitTest::SingleMemberByteArrOne() {
}

void UnitTest::SingleMemberShortArrOne() {
}

void UnitTest::SingleMemberIntArrOne() {
}

void UnitTest::SingleMemberLongArrOne() {
}

void UnitTest::SingleMemberCharArrOne() {
}

void UnitTest::SingleMemberFloatArrOne() {
}

void UnitTest::SingleMemberDoubleArrOne() {
}

void UnitTest::SingleMemberBooleanArrOne() {
}

void UnitTest::SingleMemberStringArrOne() {
}

void UnitTest::SingleMemberClassArrOne() {
}

void UnitTest::SingleMemberEnumArrOne() {
}

void UnitTest::SingleMemberByteArrTwo() {
}

void UnitTest::SingleMemberShortArrTwo() {
}

void UnitTest::SingleMemberIntArrTwo() {
}

void UnitTest::SingleMemberLongArrTwo() {
}

void UnitTest::SingleMemberCharArrTwo() {
}

void UnitTest::SingleMemberFloatArrTwo() {
}

void UnitTest::SingleMemberDoubleArrTwo() {
}

void UnitTest::SingleMemberBooleanArrTwo() {
}

void UnitTest::SingleMemberStringArrTwo() {
}

void UnitTest::SingleMemberClassArrTwo() {
}

void UnitTest::SingleMemberEnumArrTwo() {
}

void UnitTest::SingleMemberByteArrOvrdDef() {
}

void UnitTest::SingleMemberShortArrOvrdDef() {
}

void UnitTest::SingleMemberIntArrOvrdDef() {
}

void UnitTest::SingleMemberLongArrOvrdDef() {
}

void UnitTest::SingleMemberCharArrOvrdDef() {
}

void UnitTest::SingleMemberFloatArrOvrdDef() {
}

void UnitTest::SingleMemberDoubleArrOvrdDef() {
}

void UnitTest::SingleMemberBooleanArrOvrdDef() {
}

void UnitTest::SingleMemberStringArrOvrdDef() {
}

void UnitTest::SingleMemberClassArrOvrdDef() {
}

void UnitTest::SingleMemberEnumArrOvrdDef() {
}

void UnitTest::SingleMemberByteArrAcceptDef() {
}

void UnitTest::SingleMemberShortArrAcceptDef() {
}

void UnitTest::SingleMemberIntArrAcceptDef() {
}

void UnitTest::SingleMemberLongArrAcceptDef() {
}

void UnitTest::SingleMemberCharArrAcceptDef() {
}

void UnitTest::SingleMemberFloatArrAcceptDef() {
}

void UnitTest::SingleMemberDoubleArrAcceptDef() {
}

void UnitTest::SingleMemberBooleanArrAcceptDef() {
}

void UnitTest::SingleMemberStringArrAcceptDef() {
}

void UnitTest::SingleMemberClassArrAcceptDef() {
}

void UnitTest::SingleMemberEnumArrAcceptDef() {
}

void UnitTest::init$($Iterator* it) {
}

void UnitTest::init$($Set* s) {
}

void UnitTest::init$($Map* s) {
}

void UnitTest::init$($List* l) {
}

void UnitTest::init$($Collection* c) {
}

void UnitTest::init$($SortedSet* ss) {
}

void UnitTest::init$($SortedMap* sm) {
}

void UnitTest::init$($RandomAccess* r) {
}

void UnitTest::init$() {
}

void UnitTest::init$(int8_t b) {
}

void UnitTest::init$(int16_t s) {
}

void UnitTest::init$(int32_t i) {
}

void UnitTest::init$(int64_t l) {
}

void UnitTest::init$(char16_t c) {
}

void UnitTest::init$(float f) {
}

void UnitTest::init$(double d) {
}

void UnitTest::init$(bool b) {
}

void UnitTest::init$($String* s) {
}

void UnitTest::init$($Class* c) {
}

void UnitTest::init$($Enum* e) {
}

void UnitTest::init$(int8_t b, $Set* s) {
}

void UnitTest::init$(int16_t s, $Set* x) {
}

void UnitTest::init$(int32_t i, $Set* s) {
}

void UnitTest::init$(int64_t l, $Set* s) {
}

void UnitTest::init$(char16_t c, $Set* s) {
}

void UnitTest::init$(float f, $Set* s) {
}

void UnitTest::init$(double d, $Set* s) {
}

void UnitTest::init$(bool b, $Set* s) {
}

void UnitTest::init$($String* s, $Set* x) {
}

void UnitTest::init$($Class* c, $Set* s) {
}

void UnitTest::init$($Enum* e, $Set* s) {
}

void UnitTest::init$(int8_t b, $Map* m) {
}

void UnitTest::init$(int16_t s, $Map* m) {
}

void UnitTest::init$(int32_t i, $Map* m) {
}

void UnitTest::init$(int64_t l, $Map* m) {
}

void UnitTest::init$(char16_t c, $Map* m) {
}

void UnitTest::init$(float f, $Map* m) {
}

void UnitTest::init$(double d, $Map* m) {
}

void UnitTest::init$(bool b, $Map* m) {
}

void UnitTest::init$($String* s, $Map* m) {
}

void UnitTest::init$($Class* c, $Map* m) {
}

void UnitTest::init$($Enum* e, $Map* m) {
}

void UnitTest::init$($bytes* b) {
}

void UnitTest::init$($shorts* s) {
}

void UnitTest::init$($ints* i) {
}

void UnitTest::init$($longs* l) {
}

void UnitTest::init$($chars* c) {
}

void UnitTest::init$($floats* f) {
}

void UnitTest::init$($doubles* d) {
}

void UnitTest::init$($booleans* b) {
}

void UnitTest::init$($StringArray* s) {
}

void UnitTest::init$($ClassArray* c) {
}

void UnitTest::init$($EnumArray* e) {
}

void UnitTest::init$($bytes* b, $Set* s) {
}

void UnitTest::init$($shorts* s, $Set* x) {
}

void UnitTest::init$($ints* i, $Set* s) {
}

void UnitTest::init$($longs* l, $Set* s) {
}

void UnitTest::init$($chars* c, $Set* s) {
}

void UnitTest::init$($floats* f, $Set* s) {
}

void UnitTest::init$($doubles* d, $Set* s) {
}

void UnitTest::init$($booleans* b, $Set* s) {
}

void UnitTest::init$($StringArray* s, $Set* x) {
}

void UnitTest::init$($ClassArray* c, $Set* s) {
}

void UnitTest::init$($EnumArray* e, $Set* s) {
}

void UnitTest::init$($bytes* b, $Map* m) {
}

void UnitTest::init$($shorts* s, $Map* m) {
}

void UnitTest::init$($ints* i, $Map* m) {
}

void UnitTest::init$($longs* l, $Map* m) {
}

void UnitTest::init$($chars* c, $Map* m) {
}

void UnitTest::init$($floats* f, $Map* m) {
}

void UnitTest::init$($doubles* d, $Map* m) {
}

void UnitTest::init$($booleans* b, $Map* m) {
}

void UnitTest::init$($StringArray* s, $Map* m) {
}

void UnitTest::init$($ClassArray* c, $Map* m) {
}

void UnitTest::init$($EnumArray* e, $Map* m) {
}

void UnitTest::init$($bytes* b, $List* l) {
}

void UnitTest::init$($shorts* s, $List* l) {
}

void UnitTest::init$($ints* i, $List* l) {
}

void UnitTest::init$($longs* l, $List* x) {
}

void UnitTest::init$($chars* c, $List* l) {
}

void UnitTest::init$($floats* f, $List* l) {
}

void UnitTest::init$($doubles* d, $List* l) {
}

void UnitTest::init$($booleans* b, $List* l) {
}

void UnitTest::init$($StringArray* s, $List* l) {
}

void UnitTest::init$($ClassArray* c, $List* l) {
}

void UnitTest::init$($EnumArray* e, $List* l) {
}

void UnitTest::init$($bytes* b, $Collection* c) {
}

void UnitTest::init$($shorts* s, $Collection* c) {
}

void UnitTest::init$($ints* i, $Collection* c) {
}

void UnitTest::init$($longs* l, $Collection* c) {
}

void UnitTest::init$($chars* c, $Collection* x) {
}

void UnitTest::init$($floats* f, $Collection* c) {
}

void UnitTest::init$($doubles* d, $Collection* c) {
}

void UnitTest::init$($booleans* b, $Collection* c) {
}

void UnitTest::init$($StringArray* s, $Collection* c) {
}

void UnitTest::init$($ClassArray* c, $Collection* x) {
}

void UnitTest::init$($EnumArray* e, $Collection* c) {
}

void UnitTest::scalarTypesParam(int32_t x) {
}

void UnitTest::scalarTypesAcceptDefaultParam(int32_t x) {
}

void UnitTest::scalarTypesOverrideDefaultParam(int32_t x) {
}

void UnitTest::emptyArrayTypesParam(int32_t x) {
}

void UnitTest::singleElementArrayTypesParam(int32_t x) {
}

void UnitTest::twoElementArrayTypesParam(int32_t x) {
}

void UnitTest::arrayTypesAcceptDefaultParam(int32_t x) {
}

void UnitTest::arrayTypesOverrideDefaultParam(int32_t x) {
}

void UnitTest::markerParam(int32_t x) {
}

void UnitTest::SingleMemberByteParam(int32_t x) {
}

void UnitTest::SingleMemberShortParam(int32_t x) {
}

void UnitTest::SingleMemberIntParam(int32_t x) {
}

void UnitTest::SingleMemberLongParam(int32_t x) {
}

void UnitTest::SingleMemberCharParam(int32_t x) {
}

void UnitTest::SingleMemberFloatParam(int32_t x) {
}

void UnitTest::SingleMemberDoubleParam(int32_t x) {
}

void UnitTest::SingleMemberBooleanParam(int32_t x) {
}

void UnitTest::SingleMemberStringParam(int32_t x) {
}

void UnitTest::SingleMemberClassParam(int32_t x) {
}

void UnitTest::SingleMemberEnumParam(int32_t x) {
}

void UnitTest::SingleMemberByteOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberShortOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberIntOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberLongOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberCharOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberFloatOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberDoubleOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberBooleanOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberStringOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberClassOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberEnumOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberByteAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberShortAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberIntAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberLongAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberCharAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberFloatAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberDoubleAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberBooleanAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberStringAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberClassAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberEnumAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberByteArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberShortArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberIntArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberLongArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberCharArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberFloatArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberDoubleArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberBooleanArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberStringArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberClassArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberEnumArrEmptyParam(int32_t x) {
}

void UnitTest::SingleMemberByteArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberShortArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberIntArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberLongArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberCharArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberFloatArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberDoubleArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberBooleanArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberStringArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberClassArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberEnumArrOneParam(int32_t x) {
}

void UnitTest::SingleMemberByteArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberShortArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberIntArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberLongArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberCharArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberFloatArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberDoubleArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberBooleanArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberStringArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberClassArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberEnumArrTwoParam(int32_t x) {
}

void UnitTest::SingleMemberByteArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberShortArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberIntArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberLongArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberCharArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberFloatArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberDoubleArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberBooleanArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberStringArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberClassArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberEnumArrOvrdDefParam(int32_t x) {
}

void UnitTest::SingleMemberByteArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberShortArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberIntArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberLongArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberCharArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberFloatArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberDoubleArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberBooleanArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberStringArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberClassArrAcceptDefParam(int32_t x) {
}

void UnitTest::SingleMemberEnumArrAcceptDefParam(int32_t x) {
}

void clinit$UnitTest($Class* class$) {
	$assignStatic(UnitTest::X, $new($ClassArray, 0));
	$init($Integer);
	$assignStatic(UnitTest::Y, $new($ClassArray, {$Integer::TYPE}));
	UnitTest::numTests = 0;
	UnitTest::failCount = 0;
}

UnitTest::UnitTest() {
}

$Class* UnitTest::load$($String* name, bool initialize) {
	$loadClass(UnitTest, name, initialize, &_UnitTest_ClassInfo_, clinit$UnitTest, allocate$UnitTest);
	return class$;
}

$Class* UnitTest::class$ = nullptr;

} // UniTest
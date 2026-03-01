#include <ImplicitStringConcatShapesTestGen.h>

#include <java/io/OutputStream.h>
#include <java/io/PrintWriter.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Random.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef STRIDE

using $OutputStream = ::java::io::OutputStream;
using $PrintWriter = ::java::io::PrintWriter;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Files = ::java::nio::file::Files;
using $Paths = ::java::nio::file::Paths;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Random = ::java::util::Random;

$MethodInfo _ImplicitStringConcatShapesTestGen_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ImplicitStringConcatShapesTestGen, init$, void)},
	{"escapeToUnicode", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(ImplicitStringConcatShapesTestGen, escapeToUnicode, $String*, $String*)},
	{"initValue", "(Ljava/lang/String;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ImplicitStringConcatShapesTestGen, initValue, $String*, $String*, int32_t)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(ImplicitStringConcatShapesTestGen, main, void, $StringArray*), "java.io.IOException"},
	{"stringValue", "(Ljava/lang/String;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ImplicitStringConcatShapesTestGen, stringValue, $String*, $String*, int32_t)},
	{"typeSig", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ImplicitStringConcatShapesTestGen, typeSig, $String*, $String*)},
	{"typeValue", "(Ljava/lang/String;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ImplicitStringConcatShapesTestGen, typeValue, $String*, $String*, int32_t)},
	{}
};

$ClassInfo _ImplicitStringConcatShapesTestGen_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ImplicitStringConcatShapesTestGen",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ImplicitStringConcatShapesTestGen_MethodInfo_
};

$Object* allocate$ImplicitStringConcatShapesTestGen($Class* clazz) {
	return $of($alloc(ImplicitStringConcatShapesTestGen));
}

void ImplicitStringConcatShapesTestGen::init$() {
}

$String* ImplicitStringConcatShapesTestGen::escapeToUnicode($String* str) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, b, $new($StringBuilder));
	{
		$var($chars, arr$, $nc(str)->toCharArray());
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			char16_t c = arr$->get(i$);
			{
				if (c < 128) {
					b->append(c);
				} else {
					b->append("\\u"_s)->append($($String::format("%04X"_s, $$new($ObjectArray, {$($of($Integer::valueOf((int32_t)c)))}))));
				}
			}
		}
	}
	return b->toString();
}

void ImplicitStringConcatShapesTestGen::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($PrintWriter, pw, $new($PrintWriter, static_cast<$OutputStream*>($System::out)));
	$var($StringArray, types, $new($StringArray, {
		"boolean"_s,
		"byte"_s,
		"byteMinus"_s,
		"char"_s,
		"short"_s,
		"shortMinus"_s,
		"int"_s,
		"intMinus"_s,
		"integer"_s,
		"integerNull"_s,
		"float"_s,
		"floatMinus"_s,
		"long"_s,
		"longMinus"_s,
		"double"_s,
		"doubleMinus"_s,
		"object"_s,
		"objectNull"_s,
		"objectNullToString"_s,
		"String"_s,
		"StringUTF16"_s,
		"StringU1"_s,
		"StringU2"_s,
		"intArrayNull"_s,
		"objectArrayNull"_s
	}));
	{
		$var($Iterator, i$, $nc($($Files::readAllLines($($Paths::get("ImplicitStringConcatShapes-head.template"_s, $$new($StringArray, 0))))))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, t, $cast($String, i$->next()));
			{
				pw->println(t);
			}
		}
	}
	$var($Map, values, $new($HashMap));
	$var($Random, current, $new($Random, 12345));
	for (int32_t mode = 0; mode <= 2; ++mode) {
		{
			$var($StringArray, arr$, types);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, type, arr$->get(i$));
				{
					int32_t i = current->nextInt(100);
					bool isStatic = (mode | 1) == 1;
					bool isFinal = (mode | 2) == 2;
					$var($String, fieldName, $str({(isStatic ? "s"_s : ""_s), (isFinal ? "f"_s : ""_s), "_"_s, $(typeSig(type))}));
					$var($String, value, initValue(type, i));
					$var($String, stringValue, ImplicitStringConcatShapesTestGen::stringValue(type, i));
					values->put(fieldName, stringValue);
					pw->printf("    %s %s %s %s = %s;%n"_s, $$new($ObjectArray, {
						isStatic ? $of("static"_s) : $of(""_s),
						isFinal ? $of("final"_s) : $of(""_s),
						$($of(typeValue(type, i))),
						$of(fieldName),
						$of(value)
					}));
				}
			}
		}
	}
	pw->println();
	$var($List, lines, $new($ArrayList));
	$var($List, l, $new($ArrayList, $(static_cast<$Collection*>(values->keySet()))));
	{
		$var($Iterator, i$, l->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, l1, $cast($String, i$->next()));
			{
				lines->add($($String::format("test(\"%s\", \"\" + %s);"_s, $$new($ObjectArray, {
					$($of(escapeToUnicode($cast($String, $(values->get(l1)))))),
					$of(l1)
				}))));
				lines->add($($String::format("test(\"%s\", \"prefix\" + %s);"_s, $$new($ObjectArray, {
					$($of(escapeToUnicode($$str({"prefix"_s, $cast($String, $(values->get(l1)))})))),
					$of(l1)
				}))));
				lines->add($($String::format("test(\"%s\", %s + \"suffix\");"_s, $$new($ObjectArray, {
					$($of(escapeToUnicode($$str({$cast($String, $(values->get(l1))), "suffix"_s})))),
					$of(l1)
				}))));
				lines->add($($String::format("test(\"%s\", \"prefix\" + %s + \"suffix\");"_s, $$new($ObjectArray, {
					$($of(escapeToUnicode($$str({"prefix"_s, $cast($String, $(values->get(l1))), "suffix"_s})))),
					$of(l1)
				}))));
			}
		}
	}
	{
		$var($Iterator, i$, l->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, l1, $cast($String, i$->next()));
			{
				{
					$var($Iterator, i$, l->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, l2, $cast($String, i$->next()));
						{
							$var($String, var$0, $cast($String, $(values->get(l1))));
							lines->add($($String::format("test(\"%s\", \"\" + %s + %s);"_s, $$new($ObjectArray, {
								$($of(escapeToUnicode($$concat(var$0, $cast($String, $(values->get(l2))))))),
								$of(l1),
								$of(l2)
							}))));
							$var($String, var$2, $cast($String, $(values->get(l1))));
							$var($String, var$1, $$concat(var$2, $cast($String, $(values->get(l2)))));
							lines->add($($String::format("test(\"%s\", \"\" + %s + %s + \"suffix\");"_s, $$new($ObjectArray, {
								$($of(escapeToUnicode($$concat(var$1, "suffix"_s)))),
								$of(l1),
								$of(l2)
							}))));
							$var($String, var$4, $$str({"prefix"_s, $cast($String, $(values->get(l1))), "suffix1"_s}));
							$var($String, var$3, $$concat(var$4, $cast($String, $(values->get(l2)))));
							lines->add($($String::format("test(\"%s\", \"prefix\" + %s + \"suffix1\" + %s + \"suffix2\");"_s, $$new($ObjectArray, {
								$($of(escapeToUnicode($$concat(var$3, "suffix2"_s)))),
								$of(l1),
								$of(l2)
							}))));
						}
					}
				}
			}
		}
	}
	int32_t STRIDE = 1000;
	int32_t strides = $div(lines->size(), STRIDE) + 1;
	pw->println("    public void run() {"_s);
	for (int32_t c = 0; c < strides; ++c) {
		pw->println($$str({"        run"_s, $$str(c), "();"_s}));
	}
	pw->println("    }"_s);
	pw->println();
	for (int32_t c = 0; c < strides; ++c) {
		pw->println($$str({"    public void run"_s, $$str(c), "() {"_s}));
		{
			$var($Iterator, i$, $nc($(lines->subList(c * STRIDE, $Math::min(lines->size(), (c + 1) * STRIDE))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, line, $cast($String, i$->next()));
				{
					pw->println($$str({"        "_s, line}));
				}
			}
		}
		pw->println("    }"_s);
		pw->println();
	}
	pw->println("}"_s);
	pw->flush();
	pw->close();
}

$String* ImplicitStringConcatShapesTestGen::typeSig($String* type) {
	{
		$var($String, s5766$, type);
		int32_t tmp5766$ = -1;
		switch ($nc(s5766$)->hashCode()) {
		case 0x03DB6C28:
			{
				if (s5766$->equals("boolean"_s)) {
					tmp5766$ = 0;
				}
				break;
			}
		case 0x002E6108:
			{
				if (s5766$->equals("byte"_s)) {
					tmp5766$ = 1;
				}
				break;
			}
		case (int32_t)0x84BB7C48:
			{
				if (s5766$->equals("byteMinus"_s)) {
					tmp5766$ = 2;
				}
				break;
			}
		case 0x0685847C:
			{
				if (s5766$->equals("short"_s)) {
					tmp5766$ = 3;
				}
				break;
			}
		case 0x5C546154:
			{
				if (s5766$->equals("shortMinus"_s)) {
					tmp5766$ = 4;
				}
				break;
			}
		case 0x002E9356:
			{
				if (s5766$->equals("char"_s)) {
					tmp5766$ = 5;
				}
				break;
			}
		case 0x000197EF:
			{
				if (s5766$->equals("int"_s)) {
					tmp5766$ = 6;
				}
				break;
			}
		case 0x20A97DC1:
			{
				if (s5766$->equals("intMinus"_s)) {
					tmp5766$ = 7;
				}
				break;
			}
		case 0x74B5813E:
			{
				if (s5766$->equals("integer"_s)) {
					tmp5766$ = 8;
				}
				break;
			}
		case 0x2F9BEBE5:
			{
				if (s5766$->equals("integerNull"_s)) {
					tmp5766$ = 9;
				}
				break;
			}
		case 0x05D0225C:
			{
				if (s5766$->equals("float"_s)) {
					tmp5766$ = 10;
				}
				break;
			}
		case (int32_t)0xC2616F74:
			{
				if (s5766$->equals("floatMinus"_s)) {
					tmp5766$ = 11;
				}
				break;
			}
		case 0x0032C67C:
			{
				if (s5766$->equals("long"_s)) {
					tmp5766$ = 12;
				}
				break;
			}
		case 0x06A05F54:
			{
				if (s5766$->equals("longMinus"_s)) {
					tmp5766$ = 13;
				}
				break;
			}
		case (int32_t)0xB0F77BD1:
			{
				if (s5766$->equals("double"_s)) {
					tmp5766$ = 14;
				}
				break;
			}
		case (int32_t)0x9E90B71F:
			{
				if (s5766$->equals("doubleMinus"_s)) {
					tmp5766$ = 15;
				}
				break;
			}
		case (int32_t)0x943A4C31:
			{
				if (s5766$->equals("String"_s)) {
					tmp5766$ = 16;
				}
				break;
			}
		case 0x08C7B45B:
			{
				if (s5766$->equals("StringUTF16"_s)) {
					tmp5766$ = 17;
				}
				break;
			}
		case 0x6ED80E6D:
			{
				if (s5766$->equals("StringU1"_s)) {
					tmp5766$ = 18;
				}
				break;
			}
		case 0x6ED80E6E:
			{
				if (s5766$->equals("StringU2"_s)) {
					tmp5766$ = 19;
				}
				break;
			}
		case (int32_t)0xC300A33F:
			{
				if (s5766$->equals("object"_s)) {
					tmp5766$ = 20;
				}
				break;
			}
		case 0x3F942566:
			{
				if (s5766$->equals("objectNull"_s)) {
					tmp5766$ = 21;
				}
				break;
			}
		case (int32_t)0xFCD415F2:
			{
				if (s5766$->equals("objectNullToString"_s)) {
					tmp5766$ = 22;
				}
				break;
			}
		case (int32_t)0xF5E9DC51:
			{
				if (s5766$->equals("intArrayNull"_s)) {
					tmp5766$ = 23;
				}
				break;
			}
		case (int32_t)0xA09A8B01:
			{
				if (s5766$->equals("objectArrayNull"_s)) {
					tmp5766$ = 24;
				}
				break;
			}
		}
		switch (tmp5766$) {
		case 0:
			{
				return "bl"_s;
			}
		case 1:
			{
				return "b"_s;
			}
		case 2:
			{
				return "bM"_s;
			}
		case 3:
			{
				return "s"_s;
			}
		case 4:
			{
				return "sM"_s;
			}
		case 5:
			{
				return "c"_s;
			}
		case 6:
			{
				return "i"_s;
			}
		case 7:
			{
				return "iM"_s;
			}
		case 8:
			{
				return "I"_s;
			}
		case 9:
			{
				return "IN"_s;
			}
		case 10:
			{
				return "f"_s;
			}
		case 11:
			{
				return "fM"_s;
			}
		case 12:
			{
				return "l"_s;
			}
		case 13:
			{
				return "lM"_s;
			}
		case 14:
			{
				return "d"_s;
			}
		case 15:
			{
				return "dM"_s;
			}
		case 16:
			{
				return "str"_s;
			}
		case 17:
			{
				return "strU"_s;
			}
		case 18:
			{
				return "strU1"_s;
			}
		case 19:
			{
				return "strU2"_s;
			}
		case 20:
			{
				return "o"_s;
			}
		case 21:
			{
				return "oN"_s;
			}
		case 22:
			{
				return "oNtS"_s;
			}
		case 23:
			{
				return "iAN"_s;
			}
		case 24:
			{
				return "oAN"_s;
			}
		default:
			{
				$throwNew($IllegalStateException);
			}
		}
	}
}

$String* ImplicitStringConcatShapesTestGen::typeValue($String* type, int32_t i) {
	{
		$var($String, s7266$, type);
		int32_t tmp7266$ = -1;
		switch ($nc(s7266$)->hashCode()) {
		case 0x03DB6C28:
			{
				if (s7266$->equals("boolean"_s)) {
					tmp7266$ = 0;
				}
				break;
			}
		case 0x002E6108:
			{
				if (s7266$->equals("byte"_s)) {
					tmp7266$ = 1;
				}
				break;
			}
		case (int32_t)0x84BB7C48:
			{
				if (s7266$->equals("byteMinus"_s)) {
					tmp7266$ = 2;
				}
				break;
			}
		case 0x002E9356:
			{
				if (s7266$->equals("char"_s)) {
					tmp7266$ = 3;
				}
				break;
			}
		case 0x0685847C:
			{
				if (s7266$->equals("short"_s)) {
					tmp7266$ = 4;
				}
				break;
			}
		case 0x5C546154:
			{
				if (s7266$->equals("shortMinus"_s)) {
					tmp7266$ = 5;
				}
				break;
			}
		case 0x000197EF:
			{
				if (s7266$->equals("int"_s)) {
					tmp7266$ = 6;
				}
				break;
			}
		case 0x20A97DC1:
			{
				if (s7266$->equals("intMinus"_s)) {
					tmp7266$ = 7;
				}
				break;
			}
		case 0x05D0225C:
			{
				if (s7266$->equals("float"_s)) {
					tmp7266$ = 8;
				}
				break;
			}
		case (int32_t)0xC2616F74:
			{
				if (s7266$->equals("floatMinus"_s)) {
					tmp7266$ = 9;
				}
				break;
			}
		case 0x0032C67C:
			{
				if (s7266$->equals("long"_s)) {
					tmp7266$ = 10;
				}
				break;
			}
		case 0x06A05F54:
			{
				if (s7266$->equals("longMinus"_s)) {
					tmp7266$ = 11;
				}
				break;
			}
		case (int32_t)0xB0F77BD1:
			{
				if (s7266$->equals("double"_s)) {
					tmp7266$ = 12;
				}
				break;
			}
		case (int32_t)0x9E90B71F:
			{
				if (s7266$->equals("doubleMinus"_s)) {
					tmp7266$ = 13;
				}
				break;
			}
		case (int32_t)0x943A4C31:
			{
				if (s7266$->equals("String"_s)) {
					tmp7266$ = 14;
				}
				break;
			}
		case 0x08C7B45B:
			{
				if (s7266$->equals("StringUTF16"_s)) {
					tmp7266$ = 15;
				}
				break;
			}
		case 0x6ED80E6D:
			{
				if (s7266$->equals("StringU1"_s)) {
					tmp7266$ = 16;
				}
				break;
			}
		case 0x6ED80E6E:
			{
				if (s7266$->equals("StringU2"_s)) {
					tmp7266$ = 17;
				}
				break;
			}
		case (int32_t)0xC300A33F:
			{
				if (s7266$->equals("object"_s)) {
					tmp7266$ = 18;
				}
				break;
			}
		case 0x3F942566:
			{
				if (s7266$->equals("objectNull"_s)) {
					tmp7266$ = 19;
				}
				break;
			}
		case (int32_t)0xFCD415F2:
			{
				if (s7266$->equals("objectNullToString"_s)) {
					tmp7266$ = 20;
				}
				break;
			}
		case 0x74B5813E:
			{
				if (s7266$->equals("integer"_s)) {
					tmp7266$ = 21;
				}
				break;
			}
		case 0x2F9BEBE5:
			{
				if (s7266$->equals("integerNull"_s)) {
					tmp7266$ = 22;
				}
				break;
			}
		case (int32_t)0xF5E9DC51:
			{
				if (s7266$->equals("intArrayNull"_s)) {
					tmp7266$ = 23;
				}
				break;
			}
		case (int32_t)0xA09A8B01:
			{
				if (s7266$->equals("objectArrayNull"_s)) {
					tmp7266$ = 24;
				}
				break;
			}
		}
		switch (tmp7266$) {
		case 0:
			{}
		case 1:
			{}
		case 2:
			{}
		case 3:
			{}
		case 4:
			{}
		case 5:
			{}
		case 6:
			{}
		case 7:
			{}
		case 8:
			{}
		case 9:
			{}
		case 10:
			{}
		case 11:
			{}
		case 12:
			{}
		case 13:
			{
				return $nc(type)->replace(static_cast<$CharSequence*>("Minus"_s), static_cast<$CharSequence*>(""_s));
			}
		case 14:
			{}
		case 15:
			{}
		case 16:
			{}
		case 17:
			{
				return "String"_s;
			}
		case 18:
			{}
		case 19:
			{}
		case 20:
			{
				return "Object"_s;
			}
		case 21:
			{}
		case 22:
			{
				return "Integer"_s;
			}
		case 23:
			{
				return "int[]"_s;
			}
		case 24:
			{
				return "Object[]"_s;
			}
		default:
			{
				$throwNew($IllegalStateException);
			}
		}
	}
}

$String* ImplicitStringConcatShapesTestGen::initValue($String* type, int32_t i) {
	$useLocalCurrentObjectStackCache();
	{
		$var($String, s8386$, type);
		int32_t tmp8386$ = -1;
		switch ($nc(s8386$)->hashCode()) {
		case 0x03DB6C28:
			{
				if (s8386$->equals("boolean"_s)) {
					tmp8386$ = 0;
				}
				break;
			}
		case 0x002E6108:
			{
				if (s8386$->equals("byte"_s)) {
					tmp8386$ = 1;
				}
				break;
			}
		case (int32_t)0x84BB7C48:
			{
				if (s8386$->equals("byteMinus"_s)) {
					tmp8386$ = 2;
				}
				break;
			}
		case 0x0685847C:
			{
				if (s8386$->equals("short"_s)) {
					tmp8386$ = 3;
				}
				break;
			}
		case 0x5C546154:
			{
				if (s8386$->equals("shortMinus"_s)) {
					tmp8386$ = 4;
				}
				break;
			}
		case 0x20A97DC1:
			{
				if (s8386$->equals("intMinus"_s)) {
					tmp8386$ = 5;
				}
				break;
			}
		case 0x000197EF:
			{
				if (s8386$->equals("int"_s)) {
					tmp8386$ = 6;
				}
				break;
			}
		case 0x74B5813E:
			{
				if (s8386$->equals("integer"_s)) {
					tmp8386$ = 7;
				}
				break;
			}
		case 0x0032C67C:
			{
				if (s8386$->equals("long"_s)) {
					tmp8386$ = 8;
				}
				break;
			}
		case 0x06A05F54:
			{
				if (s8386$->equals("longMinus"_s)) {
					tmp8386$ = 9;
				}
				break;
			}
		case 0x002E9356:
			{
				if (s8386$->equals("char"_s)) {
					tmp8386$ = 10;
				}
				break;
			}
		case (int32_t)0xB0F77BD1:
			{
				if (s8386$->equals("double"_s)) {
					tmp8386$ = 11;
				}
				break;
			}
		case (int32_t)0x9E90B71F:
			{
				if (s8386$->equals("doubleMinus"_s)) {
					tmp8386$ = 12;
				}
				break;
			}
		case 0x05D0225C:
			{
				if (s8386$->equals("float"_s)) {
					tmp8386$ = 13;
				}
				break;
			}
		case (int32_t)0xC2616F74:
			{
				if (s8386$->equals("floatMinus"_s)) {
					tmp8386$ = 14;
				}
				break;
			}
		case (int32_t)0xC300A33F:
			{
				if (s8386$->equals("object"_s)) {
					tmp8386$ = 15;
				}
				break;
			}
		case (int32_t)0xFCD415F2:
			{
				if (s8386$->equals("objectNullToString"_s)) {
					tmp8386$ = 16;
				}
				break;
			}
		case 0x2F9BEBE5:
			{
				if (s8386$->equals("integerNull"_s)) {
					tmp8386$ = 17;
				}
				break;
			}
		case 0x3F942566:
			{
				if (s8386$->equals("objectNull"_s)) {
					tmp8386$ = 18;
				}
				break;
			}
		case (int32_t)0xF5E9DC51:
			{
				if (s8386$->equals("intArrayNull"_s)) {
					tmp8386$ = 19;
				}
				break;
			}
		case (int32_t)0xA09A8B01:
			{
				if (s8386$->equals("objectArrayNull"_s)) {
					tmp8386$ = 20;
				}
				break;
			}
		case (int32_t)0x943A4C31:
			{
				if (s8386$->equals("String"_s)) {
					tmp8386$ = 21;
				}
				break;
			}
		case 0x08C7B45B:
			{
				if (s8386$->equals("StringUTF16"_s)) {
					tmp8386$ = 22;
				}
				break;
			}
		case 0x6ED80E6D:
			{
				if (s8386$->equals("StringU1"_s)) {
					tmp8386$ = 23;
				}
				break;
			}
		case 0x6ED80E6E:
			{
				if (s8386$->equals("StringU2"_s)) {
					tmp8386$ = 24;
				}
				break;
			}
		}
		switch (tmp8386$) {
		case 0:
			{
				return $String::valueOf(((int32_t)(i & (uint32_t)1)) == 1);
			}
		case 1:
			{
				return $String::valueOf(i);
			}
		case 2:
			{
				return $String::valueOf(-i);
			}
		case 3:
			{
				return $String::valueOf(i * 100);
			}
		case 4:
			{
				return $String::valueOf(-i * 100);
			}
		case 5:
			{
				return $String::valueOf(-i * 0x000F4240);
			}
		case 6:
			{}
		case 7:
			{
				return $String::valueOf(i * 0x000F4240);
			}
		case 8:
			{
				return $str({$($String::valueOf(i * 0x3B9ACA00)), "L"_s});
			}
		case 9:
			{
				return $str({$($String::valueOf(-i * 0x3B9ACA00)), "L"_s});
			}
		case 10:
			{
				return $str({"\'"_s, $$str((char16_t)(i % 26 + 65)), "\'"_s});
			}
		case 11:
			{
				return $str({$($String::valueOf(i)), ".0d"_s});
			}
		case 12:
			{
				return $str({"-"_s, $($String::valueOf(i)), ".0d"_s});
			}
		case 13:
			{
				return $str({$($String::valueOf(i)), ".0f"_s});
			}
		case 14:
			{
				return $str({"-"_s, $($String::valueOf(i)), ".0f"_s});
			}
		case 15:
			{
				return $str({"new MyClass("_s, $$str(i), ")"_s});
			}
		case 16:
			{
				return "new MyClassNullToString()"_s;
			}
		case 17:
			{}
		case 18:
			{}
		case 19:
			{}
		case 20:
			{
				return "null"_s;
			}
		case 21:
			{
				return $str({"\""_s, $$str(i), "\""_s});
			}
		case 22:
			{
				return $str({"\"\\u0451"_s, $$str(i), "\""_s});
			}
		case 23:
			{
				return $str({"\"\\u0001"_s, $$str(i), "\""_s});
			}
		case 24:
			{
				return $str({"\"\\u0002"_s, $$str(i), "\""_s});
			}
		default:
			{
				$throwNew($IllegalStateException);
			}
		}
	}
}

$String* ImplicitStringConcatShapesTestGen::stringValue($String* type, int32_t i) {
	$useLocalCurrentObjectStackCache();
	{
		$var($String, s10333$, type);
		int32_t tmp10333$ = -1;
		switch ($nc(s10333$)->hashCode()) {
		case 0x03DB6C28:
			{
				if (s10333$->equals("boolean"_s)) {
					tmp10333$ = 0;
				}
				break;
			}
		case 0x002E6108:
			{
				if (s10333$->equals("byte"_s)) {
					tmp10333$ = 1;
				}
				break;
			}
		case (int32_t)0x84BB7C48:
			{
				if (s10333$->equals("byteMinus"_s)) {
					tmp10333$ = 2;
				}
				break;
			}
		case 0x0685847C:
			{
				if (s10333$->equals("short"_s)) {
					tmp10333$ = 3;
				}
				break;
			}
		case 0x5C546154:
			{
				if (s10333$->equals("shortMinus"_s)) {
					tmp10333$ = 4;
				}
				break;
			}
		case 0x20A97DC1:
			{
				if (s10333$->equals("intMinus"_s)) {
					tmp10333$ = 5;
				}
				break;
			}
		case 0x000197EF:
			{
				if (s10333$->equals("int"_s)) {
					tmp10333$ = 6;
				}
				break;
			}
		case 0x74B5813E:
			{
				if (s10333$->equals("integer"_s)) {
					tmp10333$ = 7;
				}
				break;
			}
		case 0x0032C67C:
			{
				if (s10333$->equals("long"_s)) {
					tmp10333$ = 8;
				}
				break;
			}
		case 0x06A05F54:
			{
				if (s10333$->equals("longMinus"_s)) {
					tmp10333$ = 9;
				}
				break;
			}
		case 0x002E9356:
			{
				if (s10333$->equals("char"_s)) {
					tmp10333$ = 10;
				}
				break;
			}
		case (int32_t)0xB0F77BD1:
			{
				if (s10333$->equals("double"_s)) {
					tmp10333$ = 11;
				}
				break;
			}
		case 0x05D0225C:
			{
				if (s10333$->equals("float"_s)) {
					tmp10333$ = 12;
				}
				break;
			}
		case (int32_t)0x9E90B71F:
			{
				if (s10333$->equals("doubleMinus"_s)) {
					tmp10333$ = 13;
				}
				break;
			}
		case (int32_t)0xC2616F74:
			{
				if (s10333$->equals("floatMinus"_s)) {
					tmp10333$ = 14;
				}
				break;
			}
		case (int32_t)0xC300A33F:
			{
				if (s10333$->equals("object"_s)) {
					tmp10333$ = 15;
				}
				break;
			}
		case 0x2F9BEBE5:
			{
				if (s10333$->equals("integerNull"_s)) {
					tmp10333$ = 16;
				}
				break;
			}
		case 0x3F942566:
			{
				if (s10333$->equals("objectNull"_s)) {
					tmp10333$ = 17;
				}
				break;
			}
		case (int32_t)0xFCD415F2:
			{
				if (s10333$->equals("objectNullToString"_s)) {
					tmp10333$ = 18;
				}
				break;
			}
		case (int32_t)0xF5E9DC51:
			{
				if (s10333$->equals("intArrayNull"_s)) {
					tmp10333$ = 19;
				}
				break;
			}
		case (int32_t)0xA09A8B01:
			{
				if (s10333$->equals("objectArrayNull"_s)) {
					tmp10333$ = 20;
				}
				break;
			}
		case (int32_t)0x943A4C31:
			{
				if (s10333$->equals("String"_s)) {
					tmp10333$ = 21;
				}
				break;
			}
		case 0x08C7B45B:
			{
				if (s10333$->equals("StringUTF16"_s)) {
					tmp10333$ = 22;
				}
				break;
			}
		case 0x6ED80E6D:
			{
				if (s10333$->equals("StringU1"_s)) {
					tmp10333$ = 23;
				}
				break;
			}
		case 0x6ED80E6E:
			{
				if (s10333$->equals("StringU2"_s)) {
					tmp10333$ = 24;
				}
				break;
			}
		}
		switch (tmp10333$) {
		case 0:
			{
				return $String::valueOf(((int32_t)(i & (uint32_t)1)) == 1);
			}
		case 1:
			{
				return $String::valueOf(i);
			}
		case 2:
			{
				return $String::valueOf(-i);
			}
		case 3:
			{
				return $String::valueOf(i * 100);
			}
		case 4:
			{
				return $String::valueOf(-i * 100);
			}
		case 5:
			{
				return $String::valueOf(-i * 0x000F4240);
			}
		case 6:
			{}
		case 7:
			{
				return $String::valueOf(i * 0x000F4240);
			}
		case 8:
			{
				return $String::valueOf(i * 0x3B9ACA00);
			}
		case 9:
			{
				return $String::valueOf(-i * 0x3B9ACA00);
			}
		case 10:
			{
				return $String::valueOf((char16_t)(i % 26 + 65));
			}
		case 11:
			{}
		case 12:
			{
				return $str({$($String::valueOf(i)), ".0"_s});
			}
		case 13:
			{}
		case 14:
			{
				return $str({"-"_s, $($String::valueOf(i)), ".0"_s});
			}
		case 15:
			{
				return $str({"C("_s, $$str(i), ")"_s});
			}
		case 16:
			{}
		case 17:
			{}
		case 18:
			{}
		case 19:
			{}
		case 20:
			{
				return "null"_s;
			}
		case 21:
			{
				return $str({""_s, $$str(i)});
			}
		case 22:
			{
				return $str({u"ё"_s, $$str(i)});
			}
		case 23:
			{
				return $str({"\u0001"_s, $$str(i)});
			}
		case 24:
			{
				return $str({"\u0002"_s, $$str(i)});
			}
		default:
			{
				$throwNew($IllegalStateException);
			}
		}
	}
}

ImplicitStringConcatShapesTestGen::ImplicitStringConcatShapesTestGen() {
}

$Class* ImplicitStringConcatShapesTestGen::load$($String* name, bool initialize) {
	$loadClass(ImplicitStringConcatShapesTestGen, name, initialize, &_ImplicitStringConcatShapesTestGen_ClassInfo_, allocate$ImplicitStringConcatShapesTestGen);
	return class$;
}

$Class* ImplicitStringConcatShapesTestGen::class$ = nullptr;
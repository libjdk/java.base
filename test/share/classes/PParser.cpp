#include <PParser.h>

#include <java/io/FileReader.h>
#include <java/io/IOException.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/lang/Iterable.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/ArrayList.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <jcpp.h>

#undef CLOSE_ARRAY
#undef CLOSE_PAIR
#undef EQUAL
#undef MORE
#undef OPEN_ARRAY
#undef OPEN_PAIR
#undef STRING
#undef WS

using $FileReader = ::java::io::FileReader;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;

class PParser$$Lambda$lambda$dump$0 : public $Consumer {
	$class(PParser$$Lambda$lambda$dump$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* l) override {
		PParser::lambda$dump$0(l);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PParser$$Lambda$lambda$dump$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo PParser$$Lambda$lambda$dump$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PParser$$Lambda$lambda$dump$0, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(PParser$$Lambda$lambda$dump$0, accept, void, Object$*)},
	{}
};
$ClassInfo PParser$$Lambda$lambda$dump$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"PParser$$Lambda$lambda$dump$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* PParser$$Lambda$lambda$dump$0::load$($String* name, bool initialize) {
	$loadClass(PParser$$Lambda$lambda$dump$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PParser$$Lambda$lambda$dump$0::class$ = nullptr;

class PParser$$Lambda$lambda$dump$1$1 : public $Consumer {
	$class(PParser$$Lambda$lambda$dump$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Map* ht) {
		$set(this, ht, ht);
	}
	virtual void accept(Object$* l) override {
		PParser::lambda$dump$1(ht, $cast($String, l));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<PParser$$Lambda$lambda$dump$1$1>());
	}
	$Map* ht = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo PParser$$Lambda$lambda$dump$1$1::fieldInfos[2] = {
	{"ht", "Ljava/util/Map;", nullptr, $PUBLIC, $field(PParser$$Lambda$lambda$dump$1$1, ht)},
	{}
};
$MethodInfo PParser$$Lambda$lambda$dump$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Map;)V", nullptr, $PUBLIC, $method(PParser$$Lambda$lambda$dump$1$1, init$, void, $Map*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(PParser$$Lambda$lambda$dump$1$1, accept, void, Object$*)},
	{}
};
$ClassInfo PParser$$Lambda$lambda$dump$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"PParser$$Lambda$lambda$dump$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* PParser$$Lambda$lambda$dump$1$1::load$($String* name, bool initialize) {
	$loadClass(PParser$$Lambda$lambda$dump$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* PParser$$Lambda$lambda$dump$1$1::class$ = nullptr;

$FieldInfo _PParser_FieldInfo_[] = {
	{"OPEN_PAIR", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(PParser, OPEN_PAIR)},
	{"CLOSE_PAIR", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(PParser, CLOSE_PAIR)},
	{"OPEN_ARRAY", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(PParser, OPEN_ARRAY)},
	{"CLOSE_ARRAY", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(PParser, CLOSE_ARRAY)},
	{"MORE", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(PParser, MORE)},
	{"EQUAL", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(PParser, EQUAL)},
	{"STRING", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(PParser, STRING)},
	{"WS", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(PParser, WS)},
	{"reader", "Ljava/io/Reader;", nullptr, $PROTECTED, $field(PParser, reader)},
	{"bufferedToken", "Z", nullptr, $PROTECTED, $field(PParser, bufferedToken)},
	{"stringBuffer", "Ljava/lang/StringBuffer;", nullptr, $PROTECTED, $field(PParser, stringBuffer)},
	{"lastChar", "I", nullptr, $PROTECTED, $field(PParser, lastChar)},
	{"lastToken", "I", nullptr, $PROTECTED, $field(PParser, lastToken)},
	{"lineNumber", "I", nullptr, $PROTECTED, $field(PParser, lineNumber)},
	{"column", "I", nullptr, $PROTECTED, $field(PParser, column)},
	{}
};

$MethodInfo _PParser_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PParser, init$, void)},
	{"dump", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(PParser, dump, void, Object$*)},
	{"error", "(Ljava/lang/String;)V", nullptr, $PROTECTED, $virtualMethod(PParser, error, void, $String*)},
	{"getToken", "()I", nullptr, $PROTECTED, $virtualMethod(PParser, getToken, int32_t), "java.io.IOException"},
	{"getToken", "(ZZ)I", nullptr, $PROTECTED, $virtualMethod(PParser, getToken, int32_t, bool, bool), "java.io.IOException"},
	{"lambda$dump$0", "(Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PParser, lambda$dump$0, void, Object$*)},
	{"lambda$dump$1", "(Ljava/util/Map;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(PParser, lambda$dump$1, void, $Map*, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(PParser, main, void, $StringArray*)},
	{"parse", "(Ljava/io/Reader;)Ljava/util/Map;", "(Ljava/io/Reader;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(PParser, parse, $Map*, $Reader*), "java.io.IOException"},
	{"parseArray", "()Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(PParser, parseArray, $Object*), "java.io.IOException"},
	{"parsePair", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PROTECTED, $virtualMethod(PParser, parsePair, $Map*), "java.io.IOException"},
	{"parseValue", "(I)Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(PParser, parseValue, $Object*, int32_t), "java.io.IOException"},
	{"ungetToken", "()V", nullptr, $PROTECTED, $virtualMethod(PParser, ungetToken, void)},
	{}
};

$ClassInfo _PParser_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"PParser",
	"java.lang.Object",
	nullptr,
	_PParser_FieldInfo_,
	_PParser_MethodInfo_
};

$Object* allocate$PParser($Class* clazz) {
	return $of($alloc(PParser));
}

void PParser::init$() {
	$set(this, stringBuffer, $new($StringBuffer));
}

$Map* PParser::parse($Reader* r) {
	$set(this, reader, r);
	this->bufferedToken = false;
	this->lineNumber = 0;
	this->column = 0;
	if (getToken() != PParser::OPEN_PAIR) {
		error("No initial open"_s);
	}
	return parsePair();
}

$Object* PParser::parseValue(int32_t lookAhead) {
	int32_t token = 0;
	if (lookAhead == -1) {
		token = getToken();
	} else {
		token = lookAhead;
	}
	switch (token) {
	case PParser::STRING:
		{
			return $of($nc(this->stringBuffer)->toString());
		}
	case PParser::OPEN_ARRAY:
		{
			return $of(parseArray());
		}
	case PParser::OPEN_PAIR:
		{
			return $of(parsePair());
		}
	default:
		{
			error("Expecting value"_s);
		}
	}
	return $of(nullptr);
}

$Object* PParser::parseArray() {
	$useLocalCurrentObjectStackCache();
	$var($List, array, $new($ArrayList));
	int32_t token = 0;
	while ((token = getToken()) != PParser::CLOSE_ARRAY) {
		if (token == PParser::MORE) {
			token = getToken();
		}
		if (token != PParser::CLOSE_ARRAY) {
			array->add($(parseValue(token)));
		}
	}
	return $of(array);
}

$Map* PParser::parsePair() {
	$useLocalCurrentObjectStackCache();
	$var($Map, ht, $new($HashMap, 11));
	int32_t token = 0;
	while ((token = getToken()) != PParser::CLOSE_PAIR) {
		if (token != PParser::STRING) {
			error("Pair expecting string got"_s);
		}
		$var($String, key, $nc(this->stringBuffer)->toString());
		if (getToken() != PParser::EQUAL) {
			error("Expecting = "_s);
		}
		$var($Object, value, parseValue(-1));
		ht->put(key, value);
	}
	return ht;
}

void PParser::ungetToken() {
	if (this->bufferedToken) {
		error("Can not buffer more than one token"_s);
	}
	this->bufferedToken = true;
}

int32_t PParser::getToken() {
	int32_t token = getToken(false, false);
	return token;
}

int32_t PParser::getToken(bool wantsWS, bool inString) {
	if (this->bufferedToken) {
		this->bufferedToken = false;
		if (this->lastToken != PParser::WS || wantsWS) {
			return this->lastToken;
		}
	}
	while ((this->lastChar = $nc(this->reader)->read()) != -1) {
		if (this->column == 0 && this->lastChar == u'#') {
			while (true) {
				bool var$0 = (this->lastChar = $nc(this->reader)->read()) != -1;
				if (!(var$0 && this->lastChar != u'\n')) {
					break;
				}
				{
				}
			}
			if (this->lastChar == -1) {
				break;
			}
		}
		++this->column;
		switch (this->lastChar) {
		case u'\n':
			{
				++this->lineNumber;
				this->column = 0;
			}
		case u' ':
			{}
		case u'\r':
			{}
		case u'\t':
			{
				if (wantsWS) {
					this->lastToken = PParser::WS;
					return PParser::WS;
				}
				break;
			}
		case u',':
			{
				this->lastToken = PParser::MORE;
				return PParser::MORE;
			}
		case u'(':
			{
				this->lastToken = PParser::OPEN_ARRAY;
				return PParser::OPEN_ARRAY;
			}
		case u')':
			{
				this->lastToken = PParser::CLOSE_ARRAY;
				return PParser::CLOSE_ARRAY;
			}
		case u'{':
			{
				this->lastToken = PParser::OPEN_PAIR;
				return PParser::OPEN_PAIR;
			}
		case u'}':
			{
				this->lastToken = PParser::CLOSE_PAIR;
				return PParser::CLOSE_PAIR;
			}
		case u'=':
			{
				this->lastToken = PParser::EQUAL;
				return PParser::EQUAL;
			}
		case u'\"':
			{
				this->lastToken = PParser::STRING;
				if (!inString) {
					$nc(this->stringBuffer)->setLength(0);
					while (true) {
						getToken(true, true);
						if (this->lastChar == u'\"') {
							this->lastToken = PParser::STRING;
							return PParser::STRING;
						}
						$nc(this->stringBuffer)->append((char16_t)this->lastChar);
					}
				}
				return PParser::STRING;
			}
		default:
			{
				this->lastToken = PParser::STRING;
				if (!inString) {
					$nc(this->stringBuffer)->setLength(0);
					$nc(this->stringBuffer)->append((char16_t)this->lastChar);
					while (getToken(true, true) == PParser::STRING) {
						if (this->lastChar == u'\"') {
							error("Unexpected quote"_s);
						}
						$nc(this->stringBuffer)->append((char16_t)this->lastChar);
					}
					ungetToken();
				}
				return PParser::STRING;
			}
		}
	}
	return -1;
}

void PParser::error($String* errorString) {
	$useLocalCurrentObjectStackCache();
	$throwNew($RuntimeException, $$str({errorString, " at line "_s, $$str(this->lineNumber), " column "_s, $$str(this->column)}));
}

void PParser::dump(Object$* o) {
	$useLocalCurrentObjectStackCache();
	if ($instanceOf($String, o)) {
		$nc($System::out)->print(o);
	} else if ($instanceOf($List, o)) {
		dump(" ("_s);
		$nc(($cast($List, o)))->forEach(static_cast<$Consumer*>($$new(PParser$$Lambda$lambda$dump$0)));
		dump(" )"_s);
	} else {
		$var($Map, ht, $cast($Map, o));
		dump(" {"_s);
		$nc($($nc(ht)->keySet()))->forEach(static_cast<$Consumer*>($$new(PParser$$Lambda$lambda$dump$1$1, ht)));
		dump(" }"_s);
	}
}

void PParser::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	if ($nc(args)->length == 0) {
		$nc($System::out)->println("need filename"_s);
	} else {
		try {
			$var($FileReader, fr, $new($FileReader, args->get(0)));
			$var(PParser, parser, $new(PParser));
			$var($Map, ht, parser->parse(fr));
			dump(ht);
			$nc($System::out)->println();
		} catch ($IOException& ioe) {
			$nc($System::out)->println($$str({"Couldn\'t parse: "_s, ioe}));
		}
	}
}

void PParser::lambda$dump$1($Map* ht, $String* l) {
	dump(l);
	dump(" = "_s);
	dump($($nc(ht)->get(l)));
	dump(";"_s);
}

void PParser::lambda$dump$0(Object$* l) {
	dump(l);
	dump(" -- "_s);
}

PParser::PParser() {
}

$Class* PParser::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(PParser$$Lambda$lambda$dump$0::classInfo$.name)) {
			return PParser$$Lambda$lambda$dump$0::load$(name, initialize);
		}
		if (name->equals(PParser$$Lambda$lambda$dump$1$1::classInfo$.name)) {
			return PParser$$Lambda$lambda$dump$1$1::load$(name, initialize);
		}
	}
	$loadClass(PParser, name, initialize, &_PParser_ClassInfo_, allocate$PParser);
	return class$;
}

$Class* PParser::class$ = nullptr;
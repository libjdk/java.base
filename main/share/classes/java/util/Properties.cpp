#include <java/util/Properties.h>

#include <java/io/BufferedWriter.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/io/PrintWriter.h>
#include <java/io/Reader.h>
#include <java/io/StreamCorruptedException.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/io/Writer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/nio/charset/UnsupportedCharsetException.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Hashtable.h>
#include <java/util/HexFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Properties$EntrySet.h>
#include <java/util/Properties$LineReader.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap$KeySetView.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Function.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/util/xml/PropertiesDefaultHandler.h>
#include <sun/nio/cs/ISO_8859_1.h>
#include <sun/nio/cs/UTF_8.h>
#include <jcpp.h>

#undef INSTANCE
#undef MAX_VALUE
#undef UNSAFE

using $Map$EntryArray = $Array<::java::util::Map$Entry>;
using $BufferedWriter = ::java::io::BufferedWriter;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $Reader = ::java::io::Reader;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $Charset = ::java::nio::charset::Charset;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $UnsupportedCharsetException = ::java::nio::charset::UnsupportedCharsetException;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $Hashtable = ::java::util::Hashtable;
using $HexFormat = ::java::util::HexFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Properties$EntrySet = ::java::util::Properties$EntrySet;
using $Properties$LineReader = ::java::util::Properties$LineReader;
using $Set = ::java::util::Set;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiFunction = ::java::util::function::BiFunction;
using $Function = ::java::util::function::Function;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $PropertiesDefaultHandler = ::jdk::internal::util::xml::PropertiesDefaultHandler;
using $ISO_8859_1 = ::sun::nio::cs::ISO_8859_1;
using $UTF_8 = ::sun::nio::cs::UTF_8;

namespace java {
	namespace util {

$CompoundAttribute _Properties_MethodAnnotations_save45[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _Properties_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Properties, serialVersionUID)},
	{"UNSAFE", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Properties, UNSAFE)},
	{"defaults", "Ljava/util/Properties;", nullptr, $PROTECTED | $VOLATILE, $field(Properties, defaults)},
	{"map", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/Object;Ljava/lang/Object;>;", $PRIVATE | $VOLATILE | $TRANSIENT, $field(Properties, map)},
	{}
};

$MethodInfo _Properties_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Properties, init$, void)},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(Properties, init$, void, int32_t)},
	{"<init>", "(Ljava/util/Properties;)V", nullptr, $PUBLIC, $method(Properties, init$, void, Properties*)},
	{"<init>", "(Ljava/util/Properties;I)V", nullptr, $PRIVATE, $method(Properties, init$, void, Properties*, int32_t)},
	{"clear", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, clear, void)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, clone, $Object*)},
	{"compute", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;*>;)Ljava/lang/Object;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, compute, $Object*, Object$*, $BiFunction*)},
	{"computeIfAbsent", "(Ljava/lang/Object;Ljava/util/function/Function;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/util/function/Function<-Ljava/lang/Object;*>;)Ljava/lang/Object;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, computeIfAbsent, $Object*, Object$*, $Function*)},
	{"computeIfPresent", "(Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;*>;)Ljava/lang/Object;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, computeIfPresent, $Object*, Object$*, $BiFunction*)},
	{"contains", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Properties, contains, bool, Object$*)},
	{"containsKey", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Properties, containsKey, bool, Object$*)},
	{"containsValue", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Properties, containsValue, bool, Object$*)},
	{"elements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(Properties, elements, $Enumeration*)},
	{"entrySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/Map$Entry<Ljava/lang/Object;Ljava/lang/Object;>;>;", $PUBLIC, $virtualMethod(Properties, entrySet, $Set*)},
	{"enumerate", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;)V", $PRIVATE, $method(Properties, enumerate, void, $Map*)},
	{"enumerateStringProperties", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;)V", $PRIVATE, $method(Properties, enumerateStringProperties, void, $Map*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, equals, bool, Object$*)},
	{"forEach", "(Ljava/util/function/BiConsumer;)V", "(Ljava/util/function/BiConsumer<-Ljava/lang/Object;-Ljava/lang/Object;>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, forEach, void, $BiConsumer*)},
	{"get", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Properties, get, $Object*, Object$*)},
	{"getOrDefault", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(Properties, getOrDefault, $Object*, Object$*, Object$*)},
	{"getProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Properties, getProperty, $String*, $String*)},
	{"getProperty", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Properties, getProperty, $String*, $String*, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, hashCode, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(Properties, isEmpty, bool)},
	{"keySet", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(Properties, keySet, $Set*)},
	{"keys", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(Properties, keys, $Enumeration*)},
	{"list", "(Ljava/io/PrintStream;)V", nullptr, $PUBLIC, $virtualMethod(Properties, list, void, $PrintStream*)},
	{"list", "(Ljava/io/PrintWriter;)V", nullptr, $PUBLIC, $virtualMethod(Properties, list, void, $PrintWriter*)},
	{"load", "(Ljava/io/Reader;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, load, void, $Reader*), "java.io.IOException"},
	{"load", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, load, void, $InputStream*), "java.io.IOException"},
	{"load0", "(Ljava/util/Properties$LineReader;)V", nullptr, $PRIVATE, $method(Properties, load0, void, $Properties$LineReader*), "java.io.IOException"},
	{"loadConvert", "([CIILjava/lang/StringBuilder;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Properties, loadConvert, $String*, $chars*, int32_t, int32_t, $StringBuilder*)},
	{"loadFromXML", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, loadFromXML, void, $InputStream*), "java.io.IOException,java.util.InvalidPropertiesFormatException"},
	{"merge", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction;)Ljava/lang/Object;", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;*>;)Ljava/lang/Object;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, merge, $Object*, Object$*, Object$*, $BiFunction*)},
	{"propertyNames", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<*>;", $PUBLIC, $virtualMethod(Properties, propertyNames, $Enumeration*)},
	{"put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, put, $Object*, Object$*, Object$*)},
	{"putAll", "(Ljava/util/Map;)V", "(Ljava/util/Map<**>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, putAll, void, $Map*)},
	{"putIfAbsent", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, putIfAbsent, $Object*, Object$*, Object$*)},
	{"readHashtable", "(Ljava/io/ObjectInputStream;)V", nullptr, 0, $virtualMethod(Properties, readHashtable, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"rehash", "()V", nullptr, $PROTECTED, $virtualMethod(Properties, rehash, void)},
	{"remove", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, remove, $Object*, Object$*)},
	{"remove", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, remove, bool, Object$*, Object$*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, replace, bool, Object$*, Object$*, Object$*)},
	{"replace", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, replace, $Object*, Object$*, Object$*)},
	{"replaceAll", "(Ljava/util/function/BiFunction;)V", "(Ljava/util/function/BiFunction<-Ljava/lang/Object;-Ljava/lang/Object;*>;)V", $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, replaceAll, void, $BiFunction*)},
	{"save", "(Ljava/io/OutputStream;Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(Properties, save, void, $OutputStream*, $String*), nullptr, nullptr, _Properties_MethodAnnotations_save45},
	{"saveConvert", "(Ljava/lang/String;ZZ)Ljava/lang/String;", nullptr, $PRIVATE, $method(Properties, saveConvert, $String*, $String*, bool, bool)},
	{"setProperty", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, setProperty, $Object*, $String*, $String*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(Properties, size, int32_t)},
	{"store", "(Ljava/io/Writer;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Properties, store, void, $Writer*, $String*), "java.io.IOException"},
	{"store", "(Ljava/io/OutputStream;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Properties, store, void, $OutputStream*, $String*), "java.io.IOException"},
	{"store0", "(Ljava/io/BufferedWriter;Ljava/lang/String;Z)V", nullptr, $PRIVATE, $method(Properties, store0, void, $BufferedWriter*, $String*, bool), "java.io.IOException"},
	{"storeToXML", "(Ljava/io/OutputStream;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Properties, storeToXML, void, $OutputStream*, $String*), "java.io.IOException"},
	{"storeToXML", "(Ljava/io/OutputStream;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Properties, storeToXML, void, $OutputStream*, $String*, $String*), "java.io.IOException"},
	{"storeToXML", "(Ljava/io/OutputStream;Ljava/lang/String;Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $virtualMethod(Properties, storeToXML, void, $OutputStream*, $String*, $Charset*), "java.io.IOException"},
	{"stringPropertyNames", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(Properties, stringPropertyNames, $Set*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Properties, toString, $String*)},
	{"values", "()Ljava/util/Collection;", "()Ljava/util/Collection<Ljava/lang/Object;>;", $PUBLIC, $virtualMethod(Properties, values, $Collection*)},
	{"writeComments", "(Ljava/io/BufferedWriter;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Properties, writeComments, void, $BufferedWriter*, $String*), "java.io.IOException"},
	{"writeHashtable", "(Ljava/io/ObjectOutputStream;)V", nullptr, 0, $virtualMethod(Properties, writeHashtable, void, $ObjectOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _Properties_InnerClassesInfo_[] = {
	{"java.util.Properties$EntrySet", "java.util.Properties", "EntrySet", $PRIVATE | $STATIC},
	{"java.util.Properties$LineReader", "java.util.Properties", "LineReader", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Properties_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.Properties",
	"java.util.Hashtable",
	nullptr,
	_Properties_FieldInfo_,
	_Properties_MethodInfo_,
	"Ljava/util/Hashtable<Ljava/lang/Object;Ljava/lang/Object;>;",
	nullptr,
	_Properties_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.Properties$EntrySet,java.util.Properties$LineReader"
};

$Object* allocate$Properties($Class* clazz) {
	return $of($alloc(Properties));
}

$Unsafe* Properties::UNSAFE = nullptr;

void Properties::init$() {
	Properties::init$(nullptr, 8);
}

void Properties::init$(int32_t initialCapacity) {
	Properties::init$(nullptr, initialCapacity);
}

void Properties::init$(Properties* defaults) {
	Properties::init$(defaults, 8);
}

void Properties::init$(Properties* defaults, int32_t initialCapacity) {
	$Hashtable::init$(($Void*)nullptr);
	$set(this, map, $new($ConcurrentHashMap, initialCapacity));
	$set(this, defaults, defaults);
	$nc(Properties::UNSAFE)->storeFence();
}

$Object* Properties::setProperty($String* key, $String* value) {
	$synchronized(this) {
		return $of(put(key, value));
	}
}

void Properties::load($Reader* reader) {
	$synchronized(this) {
		$Objects::requireNonNull($of(reader), "reader parameter is null"_s);
		load0($$new($Properties$LineReader, reader));
	}
}

void Properties::load($InputStream* inStream) {
	$synchronized(this) {
		$Objects::requireNonNull($of(inStream), "inStream parameter is null"_s);
		load0($$new($Properties$LineReader, inStream));
	}
}

void Properties::load0($Properties$LineReader* lr) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, outBuffer, $new($StringBuilder));
	int32_t limit = 0;
	int32_t keyLen = 0;
	int32_t valueStart = 0;
	bool hasSep = false;
	bool precedingBackslash = false;
	while ((limit = $nc(lr)->readLine()) >= 0) {
		keyLen = 0;
		valueStart = limit;
		hasSep = false;
		precedingBackslash = false;
		while (keyLen < limit) {
			char16_t c = $nc(lr->lineBuf)->get(keyLen);
			if ((c == u'=' || c == u':') && !precedingBackslash) {
				valueStart = keyLen + 1;
				hasSep = true;
				break;
			} else if ((c == u' ' || c == u'\t' || c == u'\f') && !precedingBackslash) {
				valueStart = keyLen + 1;
				break;
			}
			if (c == u'\\') {
				precedingBackslash = !precedingBackslash;
			} else {
				precedingBackslash = false;
			}
			++keyLen;
		}
		while (valueStart < limit) {
			char16_t c = $nc(lr->lineBuf)->get(valueStart);
			if (c != u' ' && c != u'\t' && c != u'\f') {
				if (!hasSep && (c == u'=' || c == u':')) {
					hasSep = true;
				} else {
					break;
				}
			}
			++valueStart;
		}
		$var($String, key, loadConvert(lr->lineBuf, 0, keyLen, outBuffer));
		$var($String, value, loadConvert(lr->lineBuf, valueStart, limit - valueStart, outBuffer));
		put(key, value);
	}
}

$String* Properties::loadConvert($chars* in, int32_t off, int32_t len, $StringBuilder* out) {
	char16_t aChar = 0;
	int32_t end = off + len;
	int32_t start = off;
	while (off < end) {
		aChar = $nc(in)->get(off++);
		if (aChar == u'\\') {
			break;
		}
	}
	if (off == end) {
		return $new($String, in, start, len);
	}
	$nc(out)->setLength(0);
	--off;
	out->append(in, start, off - start);
	while (off < end) {
		aChar = $nc(in)->get(off++);
		if (aChar == u'\\') {
			aChar = in->get(off++);
			if (aChar == u'u') {
				if (off > end - 4) {
					$throwNew($IllegalArgumentException, "Malformed \\uxxxx encoding."_s);
				}
				int32_t value = 0;
				for (int32_t i = 0; i < 4; ++i) {
					aChar = in->get(off++);

					int32_t var$0 = 0;
					switch (aChar) {
					case u'0':
						{}
					case u'1':
						{}
					case u'2':
						{}
					case u'3':
						{}
					case u'4':
						{}
					case u'5':
						{}
					case u'6':
						{}
					case u'7':
						{}
					case u'8':
						{}
					case u'9':
						{
							var$0 = (value << 4) + aChar - u'0';
							break;
						}
					case u'a':
						{}
					case u'b':
						{}
					case u'c':
						{}
					case u'd':
						{}
					case u'e':
						{}
					case u'f':
						{
							var$0 = (value << 4) + 10 + aChar - u'a';
							break;
						}
					case u'A':
						{}
					case u'B':
						{}
					case u'C':
						{}
					case u'D':
						{}
					case u'E':
						{}
					case u'F':
						{
							var$0 = (value << 4) + 10 + aChar - u'A';
							break;
						}
					default:
						{
							$throwNew($IllegalArgumentException, "Malformed \\uxxxx encoding."_s);
						}
					}
					value = var$0;
				}
				out->append((char16_t)value);
			} else {
				if (aChar == u't') {
					aChar = u'\t';
				} else if (aChar == u'r') {
					aChar = u'\r';
				} else if (aChar == u'n') {
					aChar = u'\n';
				} else if (aChar == u'f') {
					aChar = u'\f';
				}
				out->append(aChar);
			}
		} else {
			out->append(aChar);
		}
	}
	return out->toString();
}

$String* Properties::saveConvert($String* theString, bool escapeSpace, bool escapeUnicode) {
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(theString)->length();
	int32_t bufLen = len * 2;
	if (bufLen < 0) {
		bufLen = $Integer::MAX_VALUE;
	}
	$var($StringBuilder, outBuffer, $new($StringBuilder, bufLen));
	$var($HexFormat, hex, $nc($($HexFormat::of()))->withUpperCase());
	for (int32_t x = 0; x < len; ++x) {
		char16_t aChar = theString->charAt(x);
		if ((aChar > 61) && (aChar < 127)) {
			if (aChar == u'\\') {
				outBuffer->append(u'\\');
				outBuffer->append(u'\\');
				continue;
			}
			outBuffer->append(aChar);
			continue;
		}
		switch (aChar) {
		case u' ':
			{
				if (x == 0 || escapeSpace) {
					outBuffer->append(u'\\');
				}
				outBuffer->append(u' ');
				break;
			}
		case u'\t':
			{
				outBuffer->append(u'\\');
				outBuffer->append(u't');
				break;
			}
		case u'\n':
			{
				outBuffer->append(u'\\');
				outBuffer->append(u'n');
				break;
			}
		case u'\r':
			{
				outBuffer->append(u'\\');
				outBuffer->append(u'r');
				break;
			}
		case u'\f':
			{
				outBuffer->append(u'\\');
				outBuffer->append(u'f');
				break;
			}
		case u'=':
			{}
		case u':':
			{}
		case u'#':
			{}
		case u'!':
			{
				outBuffer->append(u'\\');
				outBuffer->append(aChar);
				break;
			}
		default:
			{
				if (((aChar < 32) || (aChar > 126)) & escapeUnicode) {
					outBuffer->append("\\u"_s);
					outBuffer->append($($nc(hex)->toHexDigits(aChar)));
				} else {
					outBuffer->append(aChar);
				}
			}
		}
	}
	return outBuffer->toString();
}

void Properties::writeComments($BufferedWriter* bw, $String* comments) {
	$init(Properties);
	$useLocalCurrentObjectStackCache();
	$var($HexFormat, hex, $nc($($HexFormat::of()))->withUpperCase());
	$nc(bw)->write("#"_s);
	int32_t len = $nc(comments)->length();
	int32_t current = 0;
	int32_t last = 0;
	while (current < len) {
		char16_t c = comments->charAt(current);
		if (c > (char16_t)0xFF || c == u'\n' || c == u'\r') {
			if (last != current) {
				bw->write($(comments->substring(last, current)));
			}
			if (c > (char16_t)0xFF) {
				bw->write("\\u"_s);
				bw->write($($nc(hex)->toHexDigits(c)));
			} else {
				bw->newLine();
				if (c == u'\r' && current != len - 1 && comments->charAt(current + 1) == u'\n') {
					++current;
				}
				bool var$0 = current == len - 1;
				if (!var$0) {
					bool var$1 = comments->charAt(current + 1) != u'#';
					var$0 = (var$1 && comments->charAt(current + 1) != u'!');
				}
				if (var$0) {
					bw->write("#"_s);
				}
			}
			last = current + 1;
		}
		++current;
	}
	if (last != current) {
		bw->write($(comments->substring(last, current)));
	}
	bw->newLine();
}

void Properties::save($OutputStream* out, $String* comments) {
	try {
		store(out, comments);
	} catch ($IOException& e) {
	}
}

void Properties::store($Writer* writer, $String* comments) {
	store0(($instanceOf($BufferedWriter, writer)) ? $cast($BufferedWriter, writer) : $$new($BufferedWriter, writer), comments, false);
}

void Properties::store($OutputStream* out, $String* comments) {
	$useLocalCurrentObjectStackCache();
	$init($ISO_8859_1);
	store0($$new($BufferedWriter, $$new($OutputStreamWriter, out, static_cast<$Charset*>($ISO_8859_1::INSTANCE))), comments, true);
}

void Properties::store0($BufferedWriter* bw, $String* comments, bool escUnicode) {
	$useLocalCurrentObjectStackCache();
	if (comments != nullptr) {
		writeComments(bw, comments);
	}
	$nc(bw)->write($$str({"#"_s, $($$new($Date)->toString())}));
	bw->newLine();
	$synchronized(this) {
		{
			$var($Iterator, i$, $nc($(entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
				{
					$var($String, key, $cast($String, $nc(e)->getKey()));
					$var($String, val, $cast($String, e->getValue()));
					$assign(key, saveConvert(key, true, escUnicode));
					$assign(val, saveConvert(val, false, escUnicode));
					bw->write($$str({key, "="_s, val}));
					bw->newLine();
				}
			}
		}
	}
	bw->flush();
}

void Properties::loadFromXML($InputStream* in) {
	$synchronized(this) {
		$Objects::requireNonNull(in);
		$var($PropertiesDefaultHandler, handler, $new($PropertiesDefaultHandler));
		handler->load(this, in);
		in->close();
	}
}

void Properties::storeToXML($OutputStream* os, $String* comment) {
	$init($UTF_8);
	storeToXML(os, comment, static_cast<$Charset*>($UTF_8::INSTANCE));
}

void Properties::storeToXML($OutputStream* os, $String* comment, $String* encoding) {
	$Objects::requireNonNull(os);
	$Objects::requireNonNull(encoding);
	try {
		$var($Charset, charset, $Charset::forName(encoding));
		storeToXML(os, comment, charset);
	} catch ($IllegalCharsetNameException& e) {
		$throwNew($UnsupportedEncodingException, encoding);
	} catch ($UnsupportedCharsetException& e) {
		$throwNew($UnsupportedEncodingException, encoding);
	}
}

void Properties::storeToXML($OutputStream* os, $String* comment, $Charset* charset) {
	$Objects::requireNonNull($of(os), "OutputStream"_s);
	$Objects::requireNonNull($of(charset), "Charset"_s);
	$var($PropertiesDefaultHandler, handler, $new($PropertiesDefaultHandler));
	handler->store(this, os, comment, charset);
}

$String* Properties::getProperty($String* key) {
	$useLocalCurrentObjectStackCache();
	$var($Object, oval, $nc(this->map)->get(key));
	$var($String, sval, ($instanceOf($String, oval)) ? $cast($String, oval) : ($String*)nullptr);
	$var(Properties, defaults, nullptr);
	return ((sval == nullptr) && (($assign(defaults, this->defaults)) != nullptr)) ? $nc(defaults)->getProperty(key) : sval;
}

$String* Properties::getProperty($String* key, $String* defaultValue) {
	$var($String, val, getProperty(key));
	return (val == nullptr) ? defaultValue : val;
}

$Enumeration* Properties::propertyNames() {
	$var($Hashtable, h, $new($Hashtable));
	enumerate(h);
	return h->keys();
}

$Set* Properties::stringPropertyNames() {
	$useLocalCurrentObjectStackCache();
	$var($Map, h, $new($HashMap));
	enumerateStringProperties(h);
	return $Collections::unmodifiableSet($(h->keySet()));
}

void Properties::list($PrintStream* out) {
	$useLocalCurrentObjectStackCache();
	$nc(out)->println("-- listing properties --"_s);
	$var($Map, h, $new($HashMap));
	enumerate(h);
	{
		$var($Iterator, i$, $nc($(h->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $cast($String, $nc(e)->getKey()));
				$var($String, val, $cast($String, e->getValue()));
				if ($nc(val)->length() > 40) {
					$assign(val, $str({$(val->substring(0, 37)), "..."_s}));
				}
				out->println($$str({key, "="_s, val}));
			}
		}
	}
}

void Properties::list($PrintWriter* out) {
	$useLocalCurrentObjectStackCache();
	$nc(out)->println("-- listing properties --"_s);
	$var($Map, h, $new($HashMap));
	enumerate(h);
	{
		$var($Iterator, i$, $nc($(h->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $cast($String, $nc(e)->getKey()));
				$var($String, val, $cast($String, e->getValue()));
				if ($nc(val)->length() > 40) {
					$assign(val, $str({$(val->substring(0, 37)), "..."_s}));
				}
				out->println($$str({key, "="_s, val}));
			}
		}
	}
}

void Properties::enumerate($Map* h) {
	$useLocalCurrentObjectStackCache();
	if (this->defaults != nullptr) {
		$nc(this->defaults)->enumerate(h);
	}
	{
		$var($Iterator, i$, $nc($(entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, key, $cast($String, $nc(e)->getKey()));
				$nc(h)->put(key, $(e->getValue()));
			}
		}
	}
}

void Properties::enumerateStringProperties($Map* h) {
	$useLocalCurrentObjectStackCache();
	if (this->defaults != nullptr) {
		$nc(this->defaults)->enumerateStringProperties(h);
	}
	{
		$var($Iterator, i$, $nc($(entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($Object, k, $nc(e)->getKey());
				$var($Object, v, e->getValue());
				if ($instanceOf($String, k) && $instanceOf($String, v)) {
					$nc(h)->put($cast($String, k), $cast($String, v));
				}
			}
		}
	}
}

int32_t Properties::size() {
	return $nc(this->map)->size();
}

bool Properties::isEmpty() {
	return $nc(this->map)->isEmpty();
}

$Enumeration* Properties::keys() {
	return $Collections::enumeration($($nc(this->map)->keySet()));
}

$Enumeration* Properties::elements() {
	return $Collections::enumeration($($nc(this->map)->values()));
}

bool Properties::contains(Object$* value) {
	return $nc(this->map)->contains(value);
}

bool Properties::containsValue(Object$* value) {
	return $nc(this->map)->containsValue(value);
}

bool Properties::containsKey(Object$* key) {
	return $nc(this->map)->containsKey(key);
}

$Object* Properties::get(Object$* key) {
	return $of($nc(this->map)->get(key));
}

$Object* Properties::put(Object$* key, Object$* value) {
	$synchronized(this) {
		return $of($nc(this->map)->put(key, value));
	}
}

$Object* Properties::remove(Object$* key) {
	$synchronized(this) {
		return $of($nc(this->map)->remove(key));
	}
}

void Properties::putAll($Map* t) {
	$synchronized(this) {
		$nc(this->map)->putAll(t);
	}
}

void Properties::clear() {
	$synchronized(this) {
		$nc(this->map)->clear();
	}
}

$String* Properties::toString() {
	$synchronized(this) {
		return $nc(this->map)->toString();
	}
}

$Set* Properties::keySet() {
	return $Collections::synchronizedSet($($nc(this->map)->keySet()), this);
}

$Collection* Properties::values() {
	return $Collections::synchronizedCollection($($nc(this->map)->values()), this);
}

$Set* Properties::entrySet() {
	$useLocalCurrentObjectStackCache();
	return $Collections::synchronizedSet($$new($Properties$EntrySet, $($nc(this->map)->entrySet())), this);
}

bool Properties::equals(Object$* o) {
	$synchronized(this) {
		return $nc(this->map)->equals(o);
	}
}

int32_t Properties::hashCode() {
	$synchronized(this) {
		return $nc(this->map)->hashCode();
	}
}

$Object* Properties::getOrDefault(Object$* key, Object$* defaultValue) {
	return $of($nc(this->map)->getOrDefault(key, defaultValue));
}

void Properties::forEach($BiConsumer* action) {
	$synchronized(this) {
		$nc(this->map)->forEach(action);
	}
}

void Properties::replaceAll($BiFunction* function) {
	$synchronized(this) {
		$nc(this->map)->replaceAll(function);
	}
}

$Object* Properties::putIfAbsent(Object$* key, Object$* value) {
	$synchronized(this) {
		return $of($nc(this->map)->putIfAbsent(key, value));
	}
}

bool Properties::remove(Object$* key, Object$* value) {
	$synchronized(this) {
		return $nc(this->map)->remove(key, value);
	}
}

bool Properties::replace(Object$* key, Object$* oldValue, Object$* newValue) {
	$synchronized(this) {
		return $nc(this->map)->replace(key, oldValue, newValue);
	}
}

$Object* Properties::replace(Object$* key, Object$* value) {
	$synchronized(this) {
		return $of($nc(this->map)->replace(key, value));
	}
}

$Object* Properties::computeIfAbsent(Object$* key, $Function* mappingFunction) {
	$synchronized(this) {
		return $of($nc(this->map)->computeIfAbsent(key, mappingFunction));
	}
}

$Object* Properties::computeIfPresent(Object$* key, $BiFunction* remappingFunction) {
	$synchronized(this) {
		return $of($nc(this->map)->computeIfPresent(key, remappingFunction));
	}
}

$Object* Properties::compute(Object$* key, $BiFunction* remappingFunction) {
	$synchronized(this) {
		return $of($nc(this->map)->compute(key, remappingFunction));
	}
}

$Object* Properties::merge(Object$* key, Object$* value, $BiFunction* remappingFunction) {
	$synchronized(this) {
		return $of($nc(this->map)->merge(key, value, remappingFunction));
	}
}

void Properties::rehash() {
}

$Object* Properties::clone() {
	$synchronized(this) {
		$var(Properties, clone, $cast(Properties, cloneHashtable()));
		$set($nc(clone), map, $new($ConcurrentHashMap, static_cast<$Map*>(static_cast<$AbstractMap*>(this->map))));
		return $of(clone);
	}
}

void Properties::writeHashtable($ObjectOutputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($ConcurrentHashMap, map, this->map);
	$var($List, entryStack, $new($ArrayList, $nc(map)->size() * 2));
	{
		$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				entryStack->add($($nc(entry)->getValue()));
				entryStack->add($($nc(entry)->getKey()));
			}
		}
	}
	float loadFactor = 0.75f;
	int32_t count = entryStack->size() / 2;
	int32_t length = $cast(int32_t, (count / loadFactor)) + (count / 20) + 3;
	if (length > count && ((int32_t)(length & (uint32_t)1)) == 0) {
		--length;
	}
	$synchronized(map) {
		defaultWriteHashtable(s, length, loadFactor);
	}
	$nc(s)->writeInt(length);
	s->writeInt(count);
	for (int32_t i = entryStack->size() - 1; i >= 0; --i) {
		s->writeObject($(entryStack->get(i)));
	}
}

void Properties::readHashtable($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	int32_t origlength = s->readInt();
	int32_t elements = s->readInt();
	if (elements < 0) {
		$throwNew($StreamCorruptedException, $$str({"Illegal # of Elements: "_s, $$str(elements)}));
	}
	$load($Map$EntryArray);
	$nc($($SharedSecrets::getJavaObjectInputStreamAccess()))->checkArray(s, $getClass($Map$EntryArray), $HashMap::tableSizeFor($cast(int32_t, (elements / 0.75))));
	$var($ConcurrentHashMap, map, $new($ConcurrentHashMap, elements));
	for (; elements > 0; --elements) {
		$var($Object, key, s->readObject());
		$var($Object, value, s->readObject());
		map->put(key, value);
	}
	$set(this, map, map);
}

void clinit$Properties($Class* class$) {
	$assignStatic(Properties::UNSAFE, $Unsafe::getUnsafe());
}

Properties::Properties() {
}

$Class* Properties::load$($String* name, bool initialize) {
	$loadClass(Properties, name, initialize, &_Properties_ClassInfo_, clinit$Properties, allocate$Properties);
	return class$;
}

$Class* Properties::class$ = nullptr;

	} // util
} // java
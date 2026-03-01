#include <jdk/internal/util/xml/PropertiesDefaultHandler.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/CharSequence.h>
#include <java/lang/ClassCastException.h>
#include <java/nio/charset/Charset.h>
#include <java/util/InvalidPropertiesFormatException.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <jdk/internal/org/xml/sax/Attributes.h>
#include <jdk/internal/org/xml/sax/InputSource.h>
#include <jdk/internal/org/xml/sax/Locator.h>
#include <jdk/internal/org/xml/sax/SAXException.h>
#include <jdk/internal/org/xml/sax/SAXParseException.h>
#include <jdk/internal/org/xml/sax/helpers/DefaultHandler.h>
#include <jdk/internal/util/xml/SAXParser.h>
#include <jdk/internal/util/xml/XMLStreamException.h>
#include <jdk/internal/util/xml/XMLStreamWriter.h>
#include <jdk/internal/util/xml/impl/SAXParserImpl.h>
#include <jdk/internal/util/xml/impl/XMLStreamWriterImpl.h>
#include <jcpp.h>

#undef ALLOWED_COMMENT
#undef ALLOWED_ELEMENTS
#undef ATTR_KEY
#undef ELEMENT_COMMENT
#undef ELEMENT_ENTRY
#undef ELEMENT_ROOT
#undef EXTERNAL_XML_VERSION
#undef PROPS_DTD
#undef PROPS_DTD_DECL
#undef PROPS_DTD_URI

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $CharSequence = ::java::lang::CharSequence;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $InvalidPropertiesFormatException = ::java::util::InvalidPropertiesFormatException;
using $Iterator = ::java::util::Iterator;
using $Map$Entry = ::java::util::Map$Entry;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $Attributes = ::jdk::internal::org::xml::sax::Attributes;
using $InputSource = ::jdk::internal::org::xml::sax::InputSource;
using $Locator = ::jdk::internal::org::xml::sax::Locator;
using $SAXException = ::jdk::internal::org::xml::sax::SAXException;
using $SAXParseException = ::jdk::internal::org::xml::sax::SAXParseException;
using $DefaultHandler = ::jdk::internal::org::xml::sax::helpers::DefaultHandler;
using $SAXParser = ::jdk::internal::util::xml::SAXParser;
using $XMLStreamException = ::jdk::internal::util::xml::XMLStreamException;
using $XMLStreamWriter = ::jdk::internal::util::xml::XMLStreamWriter;
using $SAXParserImpl = ::jdk::internal::util::xml::impl::SAXParserImpl;
using $XMLStreamWriterImpl = ::jdk::internal::util::xml::impl::XMLStreamWriterImpl;

namespace jdk {
	namespace internal {
		namespace util {
			namespace xml {

$FieldInfo _PropertiesDefaultHandler_FieldInfo_[] = {
	{"ELEMENT_ROOT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, ELEMENT_ROOT)},
	{"ELEMENT_COMMENT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, ELEMENT_COMMENT)},
	{"ELEMENT_ENTRY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, ELEMENT_ENTRY)},
	{"ATTR_KEY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, ATTR_KEY)},
	{"PROPS_DTD_DECL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, PROPS_DTD_DECL)},
	{"PROPS_DTD_URI", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, PROPS_DTD_URI)},
	{"PROPS_DTD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, PROPS_DTD)},
	{"EXTERNAL_XML_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, EXTERNAL_XML_VERSION)},
	{"properties", "Ljava/util/Properties;", nullptr, $PRIVATE, $field(PropertiesDefaultHandler, properties)},
	{"ALLOWED_ELEMENTS", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, ALLOWED_ELEMENTS)},
	{"ALLOWED_COMMENT", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(PropertiesDefaultHandler, ALLOWED_COMMENT)},
	{"buf", "Ljava/lang/StringBuilder;", nullptr, 0, $field(PropertiesDefaultHandler, buf)},
	{"sawRoot", "Z", nullptr, 0, $field(PropertiesDefaultHandler, sawRoot)},
	{"sawComment", "Z", nullptr, 0, $field(PropertiesDefaultHandler, sawComment)},
	{"validEntry", "Z", nullptr, 0, $field(PropertiesDefaultHandler, validEntry)},
	{"key", "Ljava/lang/String;", nullptr, 0, $field(PropertiesDefaultHandler, key)},
	{"rootElm", "Ljava/lang/String;", nullptr, 0, $field(PropertiesDefaultHandler, rootElm)},
	{}
};

$MethodInfo _PropertiesDefaultHandler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PropertiesDefaultHandler, init$, void)},
	{"characters", "([CII)V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, characters, void, $chars*, int32_t, int32_t), "jdk.internal.org.xml.sax.SAXException"},
	{"endElement", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, endElement, void, $String*, $String*, $String*), "jdk.internal.org.xml.sax.SAXException"},
	{"error", "(Ljdk/internal/org/xml/sax/SAXParseException;)V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, error, void, $SAXParseException*), "jdk.internal.org.xml.sax.SAXException"},
	{"fatalError", "(Ljdk/internal/org/xml/sax/SAXParseException;)V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, fatalError, void, $SAXParseException*), "jdk.internal.org.xml.sax.SAXException"},
	{"load", "(Ljava/util/Properties;Ljava/io/InputStream;)V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, load, void, $Properties*, $InputStream*), "java.io.IOException,java.util.InvalidPropertiesFormatException,java.io.UnsupportedEncodingException"},
	{"resolveEntity", "(Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/xml/sax/InputSource;", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, resolveEntity, $InputSource*, $String*, $String*), "jdk.internal.org.xml.sax.SAXException,java.io.IOException"},
	{"startDTD", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, startDTD, void, $String*, $String*, $String*), "jdk.internal.org.xml.sax.SAXException"},
	{"startElement", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljdk/internal/org/xml/sax/Attributes;)V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, startElement, void, $String*, $String*, $String*, $Attributes*), "jdk.internal.org.xml.sax.SAXException"},
	{"startInternalSub", "()V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, startInternalSub, void), "jdk.internal.org.xml.sax.SAXException"},
	{"store", "(Ljava/util/Properties;Ljava/io/OutputStream;Ljava/lang/String;Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, store, void, $Properties*, $OutputStream*, $String*, $Charset*), "java.io.IOException"},
	{"warning", "(Ljdk/internal/org/xml/sax/SAXParseException;)V", nullptr, $PUBLIC, $virtualMethod(PropertiesDefaultHandler, warning, void, $SAXParseException*), "jdk.internal.org.xml.sax.SAXException"},
	{}
};

$ClassInfo _PropertiesDefaultHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.util.xml.PropertiesDefaultHandler",
	"jdk.internal.org.xml.sax.helpers.DefaultHandler",
	nullptr,
	_PropertiesDefaultHandler_FieldInfo_,
	_PropertiesDefaultHandler_MethodInfo_
};

$Object* allocate$PropertiesDefaultHandler($Class* clazz) {
	return $of($alloc(PropertiesDefaultHandler));
}

$String* PropertiesDefaultHandler::ELEMENT_ROOT = nullptr;
$String* PropertiesDefaultHandler::ELEMENT_COMMENT = nullptr;
$String* PropertiesDefaultHandler::ELEMENT_ENTRY = nullptr;
$String* PropertiesDefaultHandler::ATTR_KEY = nullptr;
$String* PropertiesDefaultHandler::PROPS_DTD_DECL = nullptr;
$String* PropertiesDefaultHandler::PROPS_DTD_URI = nullptr;
$String* PropertiesDefaultHandler::PROPS_DTD = nullptr;
$String* PropertiesDefaultHandler::EXTERNAL_XML_VERSION = nullptr;
$String* PropertiesDefaultHandler::ALLOWED_ELEMENTS = nullptr;
$String* PropertiesDefaultHandler::ALLOWED_COMMENT = nullptr;

void PropertiesDefaultHandler::init$() {
	$DefaultHandler::init$();
	$set(this, buf, $new($StringBuilder));
	this->sawRoot = false;
	this->sawComment = false;
	this->validEntry = false;
}

void PropertiesDefaultHandler::load($Properties* props, $InputStream* in) {
	$set(this, properties, props);
	try {
		$var($SAXParser, parser, $new($SAXParserImpl));
		parser->parse(in, static_cast<$DefaultHandler*>(this));
	} catch ($SAXException& saxe) {
		$throwNew($InvalidPropertiesFormatException, static_cast<$Throwable*>(saxe));
	}
}

void PropertiesDefaultHandler::store($Properties* props, $OutputStream* os, $String* comment, $Charset* charset) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($XMLStreamWriter, writer, $new($XMLStreamWriterImpl, os, charset));
		writer->writeStartDocument();
		writer->writeDTD(PropertiesDefaultHandler::PROPS_DTD_DECL);
		writer->writeStartElement(PropertiesDefaultHandler::ELEMENT_ROOT);
		if (comment != nullptr && !comment->isEmpty()) {
			writer->writeStartElement(PropertiesDefaultHandler::ELEMENT_COMMENT);
			writer->writeCharacters(comment);
			writer->writeEndElement();
		}
		$synchronized(props) {
			{
				$var($Iterator, i$, $nc($($nc(props)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
					{
						$var($Object, k, $nc(e)->getKey());
						$var($Object, v, e->getValue());
						if ($instanceOf($String, k) && $instanceOf($String, v)) {
							writer->writeStartElement(PropertiesDefaultHandler::ELEMENT_ENTRY);
							writer->writeAttribute(PropertiesDefaultHandler::ATTR_KEY, $cast($String, k));
							writer->writeCharacters($cast($String, v));
							writer->writeEndElement();
						} else {
							$throwNew($ClassCastException, "Keys and values in Properties must be Strings"_s);
						}
					}
				}
			}
		}
		writer->writeEndElement();
		writer->writeEndDocument();
		writer->flush();
	} catch ($XMLStreamException& e) {
		if ($instanceOf($UnsupportedEncodingException, $(e->getCause()))) {
			$throw($cast($UnsupportedEncodingException, $(e->getCause())));
		}
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
}

void PropertiesDefaultHandler::startElement($String* uri, $String* localName, $String* qName, $Attributes* attributes) {
	$useLocalCurrentObjectStackCache();
	if (this->sawRoot) {
		if (!$nc(PropertiesDefaultHandler::ALLOWED_ELEMENTS)->contains(qName)) {
			fatalError($$new($SAXParseException, $$str({"Element type \""_s, qName, "\" must be declared."_s}), nullptr));
		}
	} else {
		if (this->rootElm == nullptr) {
			fatalError($$new($SAXParseException, "An XML properties document must contain the DOCTYPE declaration as defined by java.util.Properties."_s, nullptr));
		}
		if (!$nc(this->rootElm)->equals(qName)) {
			fatalError($$new($SAXParseException, $$str({"Document root element \""_s, qName, "\", must match DOCTYPE root \""_s, this->rootElm, "\""_s}), nullptr));
		}
		this->sawRoot = true;
	}
	if ($nc(qName)->equals(PropertiesDefaultHandler::ELEMENT_ENTRY)) {
		this->validEntry = true;
		$set(this, key, $nc(attributes)->getValue(PropertiesDefaultHandler::ATTR_KEY));
		if (this->key == nullptr) {
			fatalError($$new($SAXParseException, "Attribute \"key\" is required and must be specified for element type \"entry\""_s, nullptr));
		}
	} else if (qName->equals(PropertiesDefaultHandler::ALLOWED_COMMENT)) {
		if (this->sawComment) {
			fatalError($$new($SAXParseException, "Only one comment element may be allowed. The content of element type \"properties\" must match \"(comment?,entry*)\""_s, nullptr));
		}
		this->sawComment = true;
	}
}

void PropertiesDefaultHandler::characters($chars* ch, int32_t start, int32_t length) {
	if (this->validEntry) {
		$nc(this->buf)->append(ch, start, length);
	}
}

void PropertiesDefaultHandler::endElement($String* uri, $String* localName, $String* qName) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !$nc(PropertiesDefaultHandler::ALLOWED_ELEMENTS)->contains(qName);
	if (var$0 && !$nc(PropertiesDefaultHandler::ELEMENT_ROOT)->equals(qName)) {
		fatalError($$new($SAXParseException, $$str({"Element: "_s, qName, " is invalid, must match  \"(comment?,entry*)\"."_s}), nullptr));
	}
	if (this->validEntry) {
		$nc(this->properties)->setProperty(this->key, $($nc(this->buf)->toString()));
		$nc(this->buf)->delete$(0, $nc(this->buf)->length());
		this->validEntry = false;
	}
}

$InputSource* PropertiesDefaultHandler::resolveEntity($String* pubid, $String* sysid) {
	{
		if ($nc(sysid)->equals(PropertiesDefaultHandler::PROPS_DTD_URI)) {
			return nullptr;
		}
		$throwNew($SAXException, $$str({"Invalid system identifier: "_s, sysid}));
	}
}

void PropertiesDefaultHandler::error($SAXParseException* x) {
	$throw(x);
}

void PropertiesDefaultHandler::fatalError($SAXParseException* x) {
	$throw(x);
}

void PropertiesDefaultHandler::warning($SAXParseException* x) {
	$throw(x);
}

void PropertiesDefaultHandler::startDTD($String* name, $String* publicId, $String* systemId) {
	bool var$0 = !$nc(PropertiesDefaultHandler::ELEMENT_ROOT)->equals(name);
	if (var$0 || !$nc(PropertiesDefaultHandler::PROPS_DTD_URI)->equals(systemId)) {
		fatalError($$new($SAXParseException, "An XML properties document must contain the DOCTYPE declaration as defined by java.util.Properties."_s, nullptr));
	}
	$set(this, rootElm, name);
}

void PropertiesDefaultHandler::startInternalSub() {
	$useLocalCurrentObjectStackCache();
	fatalError($$new($SAXParseException, $$str({"Internal DTD subset is not allowed. The Properties XML document must have the following DOCTYPE declaration: \n"_s, PropertiesDefaultHandler::PROPS_DTD_DECL}), nullptr));
}

PropertiesDefaultHandler::PropertiesDefaultHandler() {
}

void clinit$PropertiesDefaultHandler($Class* class$) {
	$assignStatic(PropertiesDefaultHandler::ELEMENT_ROOT, "properties"_s);
	$assignStatic(PropertiesDefaultHandler::ELEMENT_COMMENT, "comment"_s);
	$assignStatic(PropertiesDefaultHandler::ELEMENT_ENTRY, "entry"_s);
	$assignStatic(PropertiesDefaultHandler::ATTR_KEY, "key"_s);
	$assignStatic(PropertiesDefaultHandler::PROPS_DTD_DECL, "<!DOCTYPE properties SYSTEM \"http://java.sun.com/dtd/properties.dtd\">"_s);
	$assignStatic(PropertiesDefaultHandler::PROPS_DTD_URI, "http://java.sun.com/dtd/properties.dtd"_s);
	$assignStatic(PropertiesDefaultHandler::PROPS_DTD, "<?xml version=\"1.0\" encoding=\"UTF-8\"?><!-- DTD for properties --><!ELEMENT properties ( comment?, entry* ) ><!ATTLIST properties version CDATA #FIXED \"1.0\"><!ELEMENT comment (#PCDATA) ><!ELEMENT entry (#PCDATA) ><!ATTLIST entry  key CDATA #REQUIRED>"_s);
	$assignStatic(PropertiesDefaultHandler::EXTERNAL_XML_VERSION, "1.0"_s);
	$assignStatic(PropertiesDefaultHandler::ALLOWED_ELEMENTS, "comment, entry"_s);
	$assignStatic(PropertiesDefaultHandler::ALLOWED_COMMENT, "comment"_s);
}

$Class* PropertiesDefaultHandler::load$($String* name, bool initialize) {
	$loadClass(PropertiesDefaultHandler, name, initialize, &_PropertiesDefaultHandler_ClassInfo_, clinit$PropertiesDefaultHandler, allocate$PropertiesDefaultHandler);
	return class$;
}

$Class* PropertiesDefaultHandler::class$ = nullptr;

			} // xml
		} // util
	} // internal
} // jdk
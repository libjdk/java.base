#include <jdk/internal/util/xml/impl/XMLStreamWriterImpl.h>

#include <java/io/OutputStream.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/nio/charset/UnsupportedCharsetException.h>
#include <jdk/internal/util/xml/XMLStreamException.h>
#include <jdk/internal/util/xml/XMLStreamWriter.h>
#include <jdk/internal/util/xml/impl/XMLStreamWriterImpl$Element.h>
#include <jdk/internal/util/xml/impl/XMLWriter.h>
#include <jcpp.h>

#undef AMPERSAND
#undef CLOSE_EMPTY_ELEMENT
#undef CLOSE_END_TAG
#undef CLOSE_START_TAG
#undef DEFAULT_CHARSET
#undef DEFAULT_XML_VERSION
#undef DOUBLEQUOT
#undef ELEMENT_ENDTAG_CLOSE
#undef ELEMENT_ENDTAG_OPEN
#undef ELEMENT_STARTTAG_CLOSE
#undef ELEMENT_STARTTAG_OPEN
#undef ENCODING_PREFIX
#undef END_CDATA
#undef OPEN_END_TAG
#undef OPEN_START_TAG
#undef SEMICOLON
#undef SPACE
#undef START_CDATA
#undef STATE_DTD_DECL
#undef STATE_ELEMENT
#undef STATE_PROLOG
#undef STATE_XML_DECL

using $OutputStream = ::java::io::OutputStream;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $UnsupportedCharsetException = ::java::nio::charset::UnsupportedCharsetException;
using $XMLStreamException = ::jdk::internal::util::xml::XMLStreamException;
using $XMLStreamWriter = ::jdk::internal::util::xml::XMLStreamWriter;
using $XMLStreamWriterImpl$Element = ::jdk::internal::util::xml::impl::XMLStreamWriterImpl$Element;
using $XMLWriter = ::jdk::internal::util::xml::impl::XMLWriter;

namespace jdk {
	namespace internal {
		namespace util {
			namespace xml {
				namespace impl {

$FieldInfo _XMLStreamWriterImpl_FieldInfo_[] = {
	{"STATE_XML_DECL", "I", nullptr, $STATIC | $FINAL, $constField(XMLStreamWriterImpl, STATE_XML_DECL)},
	{"STATE_PROLOG", "I", nullptr, $STATIC | $FINAL, $constField(XMLStreamWriterImpl, STATE_PROLOG)},
	{"STATE_DTD_DECL", "I", nullptr, $STATIC | $FINAL, $constField(XMLStreamWriterImpl, STATE_DTD_DECL)},
	{"STATE_ELEMENT", "I", nullptr, $STATIC | $FINAL, $constField(XMLStreamWriterImpl, STATE_ELEMENT)},
	{"ELEMENT_STARTTAG_OPEN", "I", nullptr, $STATIC | $FINAL, $constField(XMLStreamWriterImpl, ELEMENT_STARTTAG_OPEN)},
	{"ELEMENT_STARTTAG_CLOSE", "I", nullptr, $STATIC | $FINAL, $constField(XMLStreamWriterImpl, ELEMENT_STARTTAG_CLOSE)},
	{"ELEMENT_ENDTAG_OPEN", "I", nullptr, $STATIC | $FINAL, $constField(XMLStreamWriterImpl, ELEMENT_ENDTAG_OPEN)},
	{"ELEMENT_ENDTAG_CLOSE", "I", nullptr, $STATIC | $FINAL, $constField(XMLStreamWriterImpl, ELEMENT_ENDTAG_CLOSE)},
	{"CLOSE_START_TAG", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(XMLStreamWriterImpl, CLOSE_START_TAG)},
	{"OPEN_START_TAG", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(XMLStreamWriterImpl, OPEN_START_TAG)},
	{"OPEN_END_TAG", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(XMLStreamWriterImpl, OPEN_END_TAG)},
	{"CLOSE_END_TAG", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(XMLStreamWriterImpl, CLOSE_END_TAG)},
	{"START_CDATA", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(XMLStreamWriterImpl, START_CDATA)},
	{"END_CDATA", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(XMLStreamWriterImpl, END_CDATA)},
	{"CLOSE_EMPTY_ELEMENT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(XMLStreamWriterImpl, CLOSE_EMPTY_ELEMENT)},
	{"ENCODING_PREFIX", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(XMLStreamWriterImpl, ENCODING_PREFIX)},
	{"SPACE", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(XMLStreamWriterImpl, SPACE)},
	{"AMPERSAND", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(XMLStreamWriterImpl, AMPERSAND)},
	{"DOUBLEQUOT", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(XMLStreamWriterImpl, DOUBLEQUOT)},
	{"SEMICOLON", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(XMLStreamWriterImpl, SEMICOLON)},
	{"_state", "I", nullptr, $PRIVATE, $field(XMLStreamWriterImpl, _state)},
	{"_currentEle", "Ljdk/internal/util/xml/impl/XMLStreamWriterImpl$Element;", nullptr, $PRIVATE, $field(XMLStreamWriterImpl, _currentEle)},
	{"_writer", "Ljdk/internal/util/xml/impl/XMLWriter;", nullptr, $PRIVATE, $field(XMLStreamWriterImpl, _writer)},
	{"_charset", "Ljava/nio/charset/Charset;", nullptr, $PRIVATE, $field(XMLStreamWriterImpl, _charset)},
	{"_escapeCharacters", "Z", nullptr, 0, $field(XMLStreamWriterImpl, _escapeCharacters)},
	{"_doIndent", "Z", nullptr, $PRIVATE, $field(XMLStreamWriterImpl, _doIndent)},
	{"_lineSep", "[C", nullptr, $PRIVATE, $field(XMLStreamWriterImpl, _lineSep)},
	{}
};

$MethodInfo _XMLStreamWriterImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(XMLStreamWriterImpl, init$, void, $OutputStream*), "jdk.internal.util.xml.XMLStreamException"},
	{"<init>", "(Ljava/io/OutputStream;Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(XMLStreamWriterImpl, init$, void, $OutputStream*, $Charset*), "jdk.internal.util.xml.XMLStreamException"},
	{"checkCharset", "(Ljava/nio/charset/Charset;)Ljava/nio/charset/Charset;", nullptr, $PRIVATE, $method(XMLStreamWriterImpl, checkCharset, $Charset*, $Charset*), "java.io.UnsupportedEncodingException"},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, close, void), "jdk.internal.util.xml.XMLStreamException"},
	{"closeStartTag", "()V", nullptr, $PRIVATE, $method(XMLStreamWriterImpl, closeStartTag, void), "jdk.internal.util.xml.XMLStreamException"},
	{"flush", "()V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, flush, void), "jdk.internal.util.xml.XMLStreamException"},
	{"getCharset", "(Ljava/lang/String;)Ljava/nio/charset/Charset;", nullptr, $PRIVATE, $method(XMLStreamWriterImpl, getCharset, $Charset*, $String*), "java.io.UnsupportedEncodingException"},
	{"openStartTag", "()V", nullptr, $PRIVATE, $method(XMLStreamWriterImpl, openStartTag, void), "jdk.internal.util.xml.XMLStreamException"},
	{"setDoIndent", "(Z)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, setDoIndent, void, bool)},
	{"writeAttribute", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeAttribute, void, $String*, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeCData", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeCData, void, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeCharacters", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeCharacters, void, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeCharacters", "([CII)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeCharacters, void, $chars*, int32_t, int32_t), "jdk.internal.util.xml.XMLStreamException"},
	{"writeDTD", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeDTD, void, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeEmptyElement", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeEmptyElement, void, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeEndDocument", "()V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeEndDocument, void), "jdk.internal.util.xml.XMLStreamException"},
	{"writeEndElement", "()V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeEndElement, void), "jdk.internal.util.xml.XMLStreamException"},
	{"writeLineSeparator", "()V", nullptr, $PRIVATE, $method(XMLStreamWriterImpl, writeLineSeparator, void), "jdk.internal.util.xml.XMLStreamException"},
	{"writeStartDocument", "()V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeStartDocument, void), "jdk.internal.util.xml.XMLStreamException"},
	{"writeStartDocument", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeStartDocument, void, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeStartDocument", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeStartDocument, void, $String*, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeStartDocument", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeStartDocument, void, $String*, $String*, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeStartElement", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLStreamWriterImpl, writeStartElement, void, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeXMLContent", "([CIIZ)V", nullptr, $PRIVATE, $method(XMLStreamWriterImpl, writeXMLContent, void, $chars*, int32_t, int32_t, bool), "jdk.internal.util.xml.XMLStreamException"},
	{"writeXMLContent", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(XMLStreamWriterImpl, writeXMLContent, void, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"writeXMLContent", "(Ljava/lang/String;ZZ)V", nullptr, $PRIVATE, $method(XMLStreamWriterImpl, writeXMLContent, void, $String*, bool, bool), "jdk.internal.util.xml.XMLStreamException"},
	{}
};

$InnerClassInfo _XMLStreamWriterImpl_InnerClassesInfo_[] = {
	{"jdk.internal.util.xml.impl.XMLStreamWriterImpl$Element", "jdk.internal.util.xml.impl.XMLStreamWriterImpl", "Element", $PROTECTED | $STATIC},
	{}
};

$ClassInfo _XMLStreamWriterImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.util.xml.impl.XMLStreamWriterImpl",
	"java.lang.Object",
	"jdk.internal.util.xml.XMLStreamWriter",
	_XMLStreamWriterImpl_FieldInfo_,
	_XMLStreamWriterImpl_MethodInfo_,
	nullptr,
	nullptr,
	_XMLStreamWriterImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.util.xml.impl.XMLStreamWriterImpl$Element"
};

$Object* allocate$XMLStreamWriterImpl($Class* clazz) {
	return $of($alloc(XMLStreamWriterImpl));
}

$String* XMLStreamWriterImpl::OPEN_END_TAG = nullptr;
$String* XMLStreamWriterImpl::START_CDATA = nullptr;
$String* XMLStreamWriterImpl::END_CDATA = nullptr;
$String* XMLStreamWriterImpl::CLOSE_EMPTY_ELEMENT = nullptr;
$String* XMLStreamWriterImpl::ENCODING_PREFIX = nullptr;

void XMLStreamWriterImpl::init$($OutputStream* os) {
	$init($XMLStreamWriter);
	XMLStreamWriterImpl::init$(os, $XMLStreamWriter::DEFAULT_CHARSET);
}

void XMLStreamWriterImpl::init$($OutputStream* os, $Charset* cs) {
	this->_state = 0;
	this->_escapeCharacters = true;
	this->_doIndent = true;
	$set(this, _lineSep, $nc($($System::lineSeparator()))->toCharArray());
	if (cs == nullptr) {
		$init($XMLStreamWriter);
		$set(this, _charset, $XMLStreamWriter::DEFAULT_CHARSET);
	} else {
		try {
			$set(this, _charset, checkCharset(cs));
		} catch ($UnsupportedEncodingException& e) {
			$throwNew($XMLStreamException, static_cast<$Throwable*>(e));
		}
	}
	$set(this, _writer, $new($XMLWriter, os, nullptr, this->_charset));
}

void XMLStreamWriterImpl::writeStartDocument() {
	$init($XMLStreamWriter);
	writeStartDocument($($nc(this->_charset)->name()), $XMLStreamWriter::DEFAULT_XML_VERSION);
}

void XMLStreamWriterImpl::writeStartDocument($String* version) {
	writeStartDocument($($nc(this->_charset)->name()), version, nullptr);
}

void XMLStreamWriterImpl::writeStartDocument($String* encoding, $String* version) {
	writeStartDocument(encoding, version, nullptr);
}

void XMLStreamWriterImpl::writeStartDocument($String* encoding, $String* version$renamed, $String* standalone) {
	$useLocalCurrentObjectStackCache();
	$var($String, version, version$renamed);
	if (this->_state > 0) {
		$throwNew($XMLStreamException, "XML declaration must be as the first line in the XML document."_s);
	}
	this->_state = XMLStreamWriterImpl::STATE_XML_DECL;
	$var($String, enc, encoding);
	if (enc == nullptr) {
		$assign(enc, $nc(this->_charset)->name());
	} else {
		try {
			getCharset(encoding);
		} catch ($UnsupportedEncodingException& e) {
			$throwNew($XMLStreamException, static_cast<$Throwable*>(e));
		}
	}
	if (version == nullptr) {
		$init($XMLStreamWriter);
		$assign(version, $XMLStreamWriter::DEFAULT_XML_VERSION);
	}
	$nc(this->_writer)->write("<?xml version=\""_s);
	$nc(this->_writer)->write(version);
	$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::DOUBLEQUOT);
	if (enc != nullptr) {
		$nc(this->_writer)->write(" encoding=\""_s);
		$nc(this->_writer)->write(enc);
		$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::DOUBLEQUOT);
	}
	if (standalone != nullptr) {
		$nc(this->_writer)->write(" standalone=\""_s);
		$nc(this->_writer)->write(standalone);
		$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::DOUBLEQUOT);
	}
	$nc(this->_writer)->write("?>"_s);
	writeLineSeparator();
}

void XMLStreamWriterImpl::writeDTD($String* dtd) {
	if (this->_currentEle != nullptr && $nc(this->_currentEle)->getState() == XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN) {
		closeStartTag();
	}
	$nc(this->_writer)->write(dtd);
	writeLineSeparator();
}

void XMLStreamWriterImpl::writeStartElement($String* localName) {
	if (localName == nullptr || $nc(localName)->isEmpty()) {
		$throwNew($XMLStreamException, "Local Name cannot be null or empty"_s);
	}
	this->_state = XMLStreamWriterImpl::STATE_ELEMENT;
	if (this->_currentEle != nullptr && $nc(this->_currentEle)->getState() == XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN) {
		closeStartTag();
	}
	$set(this, _currentEle, $new($XMLStreamWriterImpl$Element, this->_currentEle, localName, false));
	openStartTag();
	$nc(this->_writer)->write(localName);
}

void XMLStreamWriterImpl::writeEmptyElement($String* localName) {
	if (this->_currentEle != nullptr && $nc(this->_currentEle)->getState() == XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN) {
		closeStartTag();
	}
	$set(this, _currentEle, $new($XMLStreamWriterImpl$Element, this->_currentEle, localName, true));
	openStartTag();
	$nc(this->_writer)->write(localName);
}

void XMLStreamWriterImpl::writeAttribute($String* localName, $String* value) {
	if ($nc(this->_currentEle)->getState() != XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN) {
		$throwNew($XMLStreamException, "Attribute not associated with any element"_s);
	}
	$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::SPACE);
	$nc(this->_writer)->write(localName);
	$nc(this->_writer)->write("=\""_s);
	writeXMLContent(value, true, true);
	$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::DOUBLEQUOT);
}

void XMLStreamWriterImpl::writeEndDocument() {
	$useLocalCurrentObjectStackCache();
	if (this->_currentEle != nullptr && $nc(this->_currentEle)->getState() == XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN) {
		closeStartTag();
	}
	while (this->_currentEle != nullptr) {
		if (!$nc(this->_currentEle)->isEmpty()) {
			$nc(this->_writer)->write(XMLStreamWriterImpl::OPEN_END_TAG);
			$nc(this->_writer)->write($($nc(this->_currentEle)->getLocalName()));
			$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::CLOSE_END_TAG);
		}
		$set(this, _currentEle, $nc(this->_currentEle)->getParent());
	}
}

void XMLStreamWriterImpl::writeEndElement() {
	if (this->_currentEle != nullptr && $nc(this->_currentEle)->getState() == XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN) {
		closeStartTag();
	}
	if (this->_currentEle == nullptr) {
		$throwNew($XMLStreamException, "No element was found to write"_s);
	}
	if ($nc(this->_currentEle)->isEmpty()) {
		return;
	}
	$nc(this->_writer)->write(XMLStreamWriterImpl::OPEN_END_TAG);
	$nc(this->_writer)->write($($nc(this->_currentEle)->getLocalName()));
	$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::CLOSE_END_TAG);
	writeLineSeparator();
	$set(this, _currentEle, $nc(this->_currentEle)->getParent());
}

void XMLStreamWriterImpl::writeCData($String* cdata) {
	if (cdata == nullptr) {
		$throwNew($XMLStreamException, "cdata cannot be null"_s);
	}
	if (this->_currentEle != nullptr && $nc(this->_currentEle)->getState() == XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN) {
		closeStartTag();
	}
	$nc(this->_writer)->write(XMLStreamWriterImpl::START_CDATA);
	$nc(this->_writer)->write(cdata);
	$nc(this->_writer)->write(XMLStreamWriterImpl::END_CDATA);
}

void XMLStreamWriterImpl::writeCharacters($String* data) {
	if (this->_currentEle != nullptr && $nc(this->_currentEle)->getState() == XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN) {
		closeStartTag();
	}
	writeXMLContent(data);
}

void XMLStreamWriterImpl::writeCharacters($chars* data, int32_t start, int32_t len) {
	if (this->_currentEle != nullptr && $nc(this->_currentEle)->getState() == XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN) {
		closeStartTag();
	}
	writeXMLContent(data, start, len, this->_escapeCharacters);
}

void XMLStreamWriterImpl::close() {
	if (this->_writer != nullptr) {
		$nc(this->_writer)->close();
	}
	$set(this, _writer, nullptr);
	$set(this, _currentEle, nullptr);
	this->_state = 0;
}

void XMLStreamWriterImpl::flush() {
	if (this->_writer != nullptr) {
		$nc(this->_writer)->flush();
	}
}

void XMLStreamWriterImpl::setDoIndent(bool doIndent) {
	this->_doIndent = doIndent;
}

void XMLStreamWriterImpl::writeXMLContent($chars* content, int32_t start, int32_t length, bool escapeChars) {
	$useLocalCurrentObjectStackCache();
	if (!escapeChars) {
		$nc(this->_writer)->write(content, start, length);
		return;
	}
	int32_t startWritePos = start;
	int32_t end = start + length;
	for (int32_t index = start; index < end; ++index) {
		char16_t ch = $nc(content)->get(index);
		if (!$nc(this->_writer)->canEncode(ch)) {
			$nc(this->_writer)->write(content, startWritePos, index - startWritePos);
			$nc(this->_writer)->write(XMLStreamWriterImpl::ENCODING_PREFIX);
			$nc(this->_writer)->write($($Integer::toHexString(ch)));
			$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::SEMICOLON);
			startWritePos = index + 1;
			continue;
		}
		switch (ch) {
		case XMLStreamWriterImpl::OPEN_START_TAG:
			{
				$nc(this->_writer)->write(content, startWritePos, index - startWritePos);
				$nc(this->_writer)->write("&lt;"_s);
				startWritePos = index + 1;
				break;
			}
		case XMLStreamWriterImpl::AMPERSAND:
			{
				$nc(this->_writer)->write(content, startWritePos, index - startWritePos);
				$nc(this->_writer)->write("&amp;"_s);
				startWritePos = index + 1;
				break;
			}
		case XMLStreamWriterImpl::CLOSE_START_TAG:
			{
				$nc(this->_writer)->write(content, startWritePos, index - startWritePos);
				$nc(this->_writer)->write("&gt;"_s);
				startWritePos = index + 1;
				break;
			}
		}
	}
	$nc(this->_writer)->write(content, startWritePos, end - startWritePos);
}

void XMLStreamWriterImpl::writeXMLContent($String* content) {
	if (content != nullptr && !content->isEmpty()) {
		writeXMLContent(content, this->_escapeCharacters, false);
	}
}

void XMLStreamWriterImpl::writeXMLContent($String* content, bool escapeChars, bool escapeDoubleQuotes) {
	$useLocalCurrentObjectStackCache();
	if (!escapeChars) {
		$nc(this->_writer)->write(content);
		return;
	}
	int32_t startWritePos = 0;
	int32_t end = $nc(content)->length();
	for (int32_t index = 0; index < end; ++index) {
		char16_t ch = content->charAt(index);
		if (!$nc(this->_writer)->canEncode(ch)) {
			$nc(this->_writer)->write(content, startWritePos, index - startWritePos);
			$nc(this->_writer)->write(XMLStreamWriterImpl::ENCODING_PREFIX);
			$nc(this->_writer)->write($($Integer::toHexString(ch)));
			$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::SEMICOLON);
			startWritePos = index + 1;
			continue;
		}
		switch (ch) {
		case XMLStreamWriterImpl::OPEN_START_TAG:
			{
				$nc(this->_writer)->write(content, startWritePos, index - startWritePos);
				$nc(this->_writer)->write("&lt;"_s);
				startWritePos = index + 1;
				break;
			}
		case XMLStreamWriterImpl::AMPERSAND:
			{
				$nc(this->_writer)->write(content, startWritePos, index - startWritePos);
				$nc(this->_writer)->write("&amp;"_s);
				startWritePos = index + 1;
				break;
			}
		case XMLStreamWriterImpl::CLOSE_START_TAG:
			{
				$nc(this->_writer)->write(content, startWritePos, index - startWritePos);
				$nc(this->_writer)->write("&gt;"_s);
				startWritePos = index + 1;
				break;
			}
		case XMLStreamWriterImpl::DOUBLEQUOT:
			{
				$nc(this->_writer)->write(content, startWritePos, index - startWritePos);
				if (escapeDoubleQuotes) {
					$nc(this->_writer)->write("&quot;"_s);
				} else {
					$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::DOUBLEQUOT);
				}
				startWritePos = index + 1;
				break;
			}
		}
	}
	$nc(this->_writer)->write(content, startWritePos, end - startWritePos);
}

void XMLStreamWriterImpl::openStartTag() {
	$nc(this->_currentEle)->setState(XMLStreamWriterImpl::ELEMENT_STARTTAG_OPEN);
	$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::OPEN_START_TAG);
}

void XMLStreamWriterImpl::closeStartTag() {
	if ($nc(this->_currentEle)->isEmpty()) {
		$nc(this->_writer)->write(XMLStreamWriterImpl::CLOSE_EMPTY_ELEMENT);
	} else {
		$nc(this->_writer)->write((int32_t)XMLStreamWriterImpl::CLOSE_START_TAG);
	}
	if ($nc(this->_currentEle)->getParent() == nullptr) {
		writeLineSeparator();
	}
	$nc(this->_currentEle)->setState(XMLStreamWriterImpl::ELEMENT_STARTTAG_CLOSE);
}

void XMLStreamWriterImpl::writeLineSeparator() {
	if (this->_doIndent) {
		$nc(this->_writer)->write(this->_lineSep, 0, $nc(this->_lineSep)->length);
	}
}

$Charset* XMLStreamWriterImpl::getCharset($String* encoding) {
	$useLocalCurrentObjectStackCache();
	if ($nc(encoding)->equalsIgnoreCase("UTF-32"_s)) {
		$throwNew($UnsupportedEncodingException, $$str({"The basic XMLWriter does not support "_s, encoding}));
	}
	$var($Charset, cs, nullptr);
	try {
		$assign(cs, $Charset::forName(encoding));
	} catch ($IllegalCharsetNameException& ex) {
		$throwNew($UnsupportedEncodingException, encoding);
	} catch ($UnsupportedCharsetException& ex) {
		$throwNew($UnsupportedEncodingException, encoding);
	}
	return cs;
}

$Charset* XMLStreamWriterImpl::checkCharset($Charset* charset) {
	$useLocalCurrentObjectStackCache();
	if ($nc($($nc(charset)->name()))->equalsIgnoreCase("UTF-32"_s)) {
		$throwNew($UnsupportedEncodingException, $$str({"The basic XMLWriter does not support "_s, $(charset->name())}));
	}
	return charset;
}

XMLStreamWriterImpl::XMLStreamWriterImpl() {
}

void clinit$XMLStreamWriterImpl($Class* class$) {
	$assignStatic(XMLStreamWriterImpl::OPEN_END_TAG, "</"_s);
	$assignStatic(XMLStreamWriterImpl::START_CDATA, "<![CDATA["_s);
	$assignStatic(XMLStreamWriterImpl::END_CDATA, "]]>"_s);
	$assignStatic(XMLStreamWriterImpl::CLOSE_EMPTY_ELEMENT, "/>"_s);
	$assignStatic(XMLStreamWriterImpl::ENCODING_PREFIX, "&#x"_s);
}

$Class* XMLStreamWriterImpl::load$($String* name, bool initialize) {
	$loadClass(XMLStreamWriterImpl, name, initialize, &_XMLStreamWriterImpl_ClassInfo_, clinit$XMLStreamWriterImpl, allocate$XMLStreamWriterImpl);
	return class$;
}

$Class* XMLStreamWriterImpl::class$ = nullptr;

				} // impl
			} // xml
		} // util
	} // internal
} // jdk
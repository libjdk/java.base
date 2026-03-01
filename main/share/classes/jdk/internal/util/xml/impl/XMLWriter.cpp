#include <jdk/internal/util/xml/impl/XMLWriter.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/io/Writer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <jdk/internal/util/xml/XMLStreamException.h>
#include <jcpp.h>

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $XMLStreamException = ::jdk::internal::util::xml::XMLStreamException;

namespace jdk {
	namespace internal {
		namespace util {
			namespace xml {
				namespace impl {

$FieldInfo _XMLWriter_FieldInfo_[] = {
	{"_writer", "Ljava/io/Writer;", nullptr, $PRIVATE, $field(XMLWriter, _writer)},
	{"_encoder", "Ljava/nio/charset/CharsetEncoder;", nullptr, $PRIVATE, $field(XMLWriter, _encoder)},
	{}
};

$MethodInfo _XMLWriter_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;Ljava/lang/String;Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(XMLWriter, init$, void, $OutputStream*, $String*, $Charset*), "jdk.internal.util.xml.XMLStreamException"},
	{"canEncode", "(C)Z", nullptr, $PUBLIC, $virtualMethod(XMLWriter, canEncode, bool, char16_t)},
	{"close", "()V", nullptr, 0, $virtualMethod(XMLWriter, close, void), "jdk.internal.util.xml.XMLStreamException"},
	{"flush", "()V", nullptr, 0, $virtualMethod(XMLWriter, flush, void), "jdk.internal.util.xml.XMLStreamException"},
	{"getWriter", "(Ljava/io/OutputStream;Ljava/lang/String;Ljava/nio/charset/Charset;)Ljava/io/Writer;", nullptr, $PRIVATE, $method(XMLWriter, getWriter, $Writer*, $OutputStream*, $String*, $Charset*), "jdk.internal.util.xml.XMLStreamException,java.io.UnsupportedEncodingException"},
	{"nl", "()V", nullptr, $PRIVATE, $method(XMLWriter, nl, void), "jdk.internal.util.xml.XMLStreamException"},
	{"write", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(XMLWriter, write, void, $String*), "jdk.internal.util.xml.XMLStreamException"},
	{"write", "(Ljava/lang/String;II)V", nullptr, $PUBLIC, $virtualMethod(XMLWriter, write, void, $String*, int32_t, int32_t), "jdk.internal.util.xml.XMLStreamException"},
	{"write", "([CII)V", nullptr, $PUBLIC, $virtualMethod(XMLWriter, write, void, $chars*, int32_t, int32_t), "jdk.internal.util.xml.XMLStreamException"},
	{"write", "(I)V", nullptr, 0, $virtualMethod(XMLWriter, write, void, int32_t), "jdk.internal.util.xml.XMLStreamException"},
	{}
};

$ClassInfo _XMLWriter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.util.xml.impl.XMLWriter",
	"java.lang.Object",
	nullptr,
	_XMLWriter_FieldInfo_,
	_XMLWriter_MethodInfo_
};

$Object* allocate$XMLWriter($Class* clazz) {
	return $of($alloc(XMLWriter));
}

void XMLWriter::init$($OutputStream* os, $String* encoding, $Charset* cs) {
	$set(this, _encoder, nullptr);
	$set(this, _encoder, $nc(cs)->newEncoder());
	try {
		$set(this, _writer, getWriter(os, encoding, cs));
	} catch ($UnsupportedEncodingException& ex) {
		$throwNew($XMLStreamException, static_cast<$Throwable*>(ex));
	}
}

bool XMLWriter::canEncode(char16_t ch) {
	if (this->_encoder == nullptr) {
		return false;
	}
	return ($nc(this->_encoder)->canEncode(ch));
}

void XMLWriter::write($String* s) {
	try {
		$nc(this->_writer)->write($($nc(s)->toCharArray()));
	} catch ($IOException& e) {
		$throwNew($XMLStreamException, "I/O error"_s, e);
	}
}

void XMLWriter::write($String* str, int32_t off, int32_t len) {
	try {
		$nc(this->_writer)->write(str, off, len);
	} catch ($IOException& e) {
		$throwNew($XMLStreamException, "I/O error"_s, e);
	}
}

void XMLWriter::write($chars* cbuf, int32_t off, int32_t len) {
	try {
		$nc(this->_writer)->write(cbuf, off, len);
	} catch ($IOException& e) {
		$throwNew($XMLStreamException, "I/O error"_s, e);
	}
}

void XMLWriter::write(int32_t b) {
	try {
		$nc(this->_writer)->write(b);
	} catch ($IOException& e) {
		$throwNew($XMLStreamException, "I/O error"_s, e);
	}
}

void XMLWriter::flush() {
	try {
		$nc(this->_writer)->flush();
	} catch ($IOException& ex) {
		$throwNew($XMLStreamException, static_cast<$Throwable*>(ex));
	}
}

void XMLWriter::close() {
	try {
		$nc(this->_writer)->close();
	} catch ($IOException& ex) {
		$throwNew($XMLStreamException, static_cast<$Throwable*>(ex));
	}
}

void XMLWriter::nl() {
	$var($String, lineEnd, $System::lineSeparator());
	try {
		$nc(this->_writer)->write(lineEnd);
	} catch ($IOException& e) {
		$throwNew($XMLStreamException, "I/O error"_s, e);
	}
}

$Writer* XMLWriter::getWriter($OutputStream* output, $String* encoding, $Charset* cs) {
	$useLocalCurrentObjectStackCache();
	if (cs != nullptr) {
		return ($new($OutputStreamWriter, static_cast<$OutputStream*>($$new($BufferedOutputStream, output)), cs));
	}
	return $new($OutputStreamWriter, static_cast<$OutputStream*>($$new($BufferedOutputStream, output)), encoding);
}

XMLWriter::XMLWriter() {
}

$Class* XMLWriter::load$($String* name, bool initialize) {
	$loadClass(XMLWriter, name, initialize, &_XMLWriter_ClassInfo_, allocate$XMLWriter);
	return class$;
}

$Class* XMLWriter::class$ = nullptr;

				} // impl
			} // xml
		} // util
	} // internal
} // jdk
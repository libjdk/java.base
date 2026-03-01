#include <java/io/PrintStream.h>

#include <java/io/BufferedWriter.h>
#include <java/io/File.h>
#include <java/io/FileOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InterruptedIOException.h>
#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/io/Writer.h>
#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/nio/charset/UnsupportedCharsetException.h>
#include <java/util/Formatter.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <jcpp.h>

#undef FORMAT

using $BufferedWriter = ::java::io::BufferedWriter;
using $File = ::java::io::File;
using $FileOutputStream = ::java::io::FileOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $InterruptedIOException = ::java::io::InterruptedIOException;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $Writer = ::java::io::Writer;
using $Appendable = ::java::lang::Appendable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Charset = ::java::nio::charset::Charset;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $UnsupportedCharsetException = ::java::nio::charset::UnsupportedCharsetException;
using $Formatter = ::java::util::Formatter;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;

namespace java {
	namespace io {

$FieldInfo _PrintStream_FieldInfo_[] = {
	{"autoFlush", "Z", nullptr, $PRIVATE | $FINAL, $field(PrintStream, autoFlush)},
	{"trouble", "Z", nullptr, $PRIVATE, $field(PrintStream, trouble)},
	{"formatter", "Ljava/util/Formatter;", nullptr, $PRIVATE, $field(PrintStream, formatter)},
	{"textOut", "Ljava/io/BufferedWriter;", nullptr, $PRIVATE, $field(PrintStream, textOut)},
	{"charOut", "Ljava/io/OutputStreamWriter;", nullptr, $PRIVATE, $field(PrintStream, charOut)},
	{"closing", "Z", nullptr, $PRIVATE, $field(PrintStream, closing)},
	{}
};

$MethodInfo _PrintStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(ZLjava/io/OutputStream;)V", nullptr, $PRIVATE, $method(PrintStream, init$, void, bool, $OutputStream*)},
	{"<init>", "(ZLjava/nio/charset/Charset;Ljava/io/OutputStream;)V", nullptr, $PRIVATE, $method(PrintStream, init$, void, bool, $Charset*, $OutputStream*)},
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $OutputStream*)},
	{"<init>", "(Ljava/io/OutputStream;Z)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $OutputStream*, bool)},
	{"<init>", "(Ljava/io/OutputStream;ZLjava/lang/String;)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $OutputStream*, bool, $String*), "java.io.UnsupportedEncodingException"},
	{"<init>", "(Ljava/io/OutputStream;ZLjava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $OutputStream*, bool, $Charset*)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $String*), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $String*, $String*), "java.io.FileNotFoundException,java.io.UnsupportedEncodingException"},
	{"<init>", "(Ljava/lang/String;Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $String*, $Charset*), "java.io.IOException"},
	{"<init>", "(Ljava/io/File;)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $File*), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/io/File;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $File*, $String*), "java.io.FileNotFoundException,java.io.UnsupportedEncodingException"},
	{"<init>", "(Ljava/io/File;Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(PrintStream, init$, void, $File*, $Charset*), "java.io.IOException"},
	{"append", "(Ljava/lang/CharSequence;)Ljava/io/PrintStream;", nullptr, $PUBLIC, $virtualMethod(PrintStream, append, $Appendable*, $CharSequence*)},
	{"append", "(Ljava/lang/CharSequence;II)Ljava/io/PrintStream;", nullptr, $PUBLIC, $virtualMethod(PrintStream, append, $Appendable*, $CharSequence*, int32_t, int32_t)},
	{"append", "(C)Ljava/io/PrintStream;", nullptr, $PUBLIC, $virtualMethod(PrintStream, append, $Appendable*, char16_t)},
	{"checkError", "()Z", nullptr, $PUBLIC, $virtualMethod(PrintStream, checkError, bool)},
	{"clearError", "()V", nullptr, $PROTECTED, $virtualMethod(PrintStream, clearError, void)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(PrintStream, close, void)},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(PrintStream, ensureOpen, void), "java.io.IOException"},
	{"flush", "()V", nullptr, $PUBLIC, $virtualMethod(PrintStream, flush, void)},
	{"format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PrintStream, format, PrintStream*, $String*, $ObjectArray*)},
	{"format", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PrintStream, format, PrintStream*, $Locale*, $String*, $ObjectArray*)},
	{"newLine", "()V", nullptr, $PRIVATE, $method(PrintStream, newLine, void)},
	{"print", "(Z)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, print, void, bool)},
	{"print", "(C)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, print, void, char16_t)},
	{"print", "(I)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, print, void, int32_t)},
	{"print", "(J)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, print, void, int64_t)},
	{"print", "(F)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, print, void, float)},
	{"print", "(D)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, print, void, double)},
	{"print", "([C)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, print, void, $chars*)},
	{"print", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, print, void, $String*)},
	{"print", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, print, void, Object$*)},
	{"printf", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PrintStream, printf, PrintStream*, $String*, $ObjectArray*)},
	{"printf", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(PrintStream, printf, PrintStream*, $Locale*, $String*, $ObjectArray*)},
	{"println", "()V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void)},
	{"println", "(Z)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void, bool)},
	{"println", "(C)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void, char16_t)},
	{"println", "(I)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void, int32_t)},
	{"println", "(J)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void, int64_t)},
	{"println", "(F)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void, float)},
	{"println", "(D)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void, double)},
	{"println", "([C)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void, $chars*)},
	{"println", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void, $String*)},
	{"println", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, println, void, Object$*)},
	{"requireNonNull", "(Ljava/lang/Object;Ljava/lang/String;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(TT;Ljava/lang/String;)TT;", $PRIVATE | $STATIC, $staticMethod(PrintStream, requireNonNull, $Object*, Object$*, $String*)},
	{"setError", "()V", nullptr, $PROTECTED, $virtualMethod(PrintStream, setError, void)},
	{"toCharset", "(Ljava/lang/String;)Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $STATIC, $staticMethod(PrintStream, toCharset, $Charset*, $String*), "java.io.UnsupportedEncodingException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"write", "(I)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, write, void, int32_t)},
	{"write", "([BII)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, write, void, $bytes*, int32_t, int32_t)},
	{"write", "([B)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, write, void, $bytes*), "java.io.IOException"},
	{"write", "([C)V", nullptr, $PRIVATE, $method(PrintStream, write, void, $chars*)},
	{"write", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(PrintStream, write, void, $String*)},
	{"writeBytes", "([B)V", nullptr, $PUBLIC, $virtualMethod(PrintStream, writeBytes, void, $bytes*)},
	{"writeln", "([C)V", nullptr, $PRIVATE, $method(PrintStream, writeln, void, $chars*)},
	{"writeln", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(PrintStream, writeln, void, $String*)},
	{}
};

$ClassInfo _PrintStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.io.PrintStream",
	"java.io.FilterOutputStream",
	"java.lang.Appendable",
	_PrintStream_FieldInfo_,
	_PrintStream_MethodInfo_
};

$Object* allocate$PrintStream($Class* clazz) {
	return $of($alloc(PrintStream));
}

int32_t PrintStream::hashCode() {
	 return this->$FilterOutputStream::hashCode();
}

bool PrintStream::equals(Object$* obj) {
	 return this->$FilterOutputStream::equals(obj);
}

$Object* PrintStream::clone() {
	 return this->$FilterOutputStream::clone();
}

$String* PrintStream::toString() {
	 return this->$FilterOutputStream::toString();
}

void PrintStream::finalize() {
	this->$FilterOutputStream::finalize();
}

$Object* PrintStream::requireNonNull(Object$* obj, $String* message) {
	$init(PrintStream);
	if (obj == nullptr) {
		$throwNew($NullPointerException, message);
	}
	return $of(obj);
}

$Charset* PrintStream::toCharset($String* csn) {
	$init(PrintStream);
	requireNonNull(csn, "charsetName"_s);
	try {
		return $Charset::forName(csn);
	} catch ($IllegalCharsetNameException& unused) {
		$throwNew($UnsupportedEncodingException, csn);
	} catch ($UnsupportedCharsetException& unused) {
		$throwNew($UnsupportedEncodingException, csn);
	}
	$shouldNotReachHere();
}

void PrintStream::init$(bool autoFlush, $OutputStream* out) {
	$FilterOutputStream::init$(out);
	this->trouble = false;
	this->closing = false;
	this->autoFlush = autoFlush;
	$set(this, charOut, $new($OutputStreamWriter, this));
	$set(this, textOut, $new($BufferedWriter, this->charOut));
}

void PrintStream::init$(bool autoFlush, $Charset* charset, $OutputStream* out) {
	PrintStream::init$(out, autoFlush, charset);
}

void PrintStream::init$($OutputStream* out) {
	PrintStream::init$(out, false);
}

void PrintStream::init$($OutputStream* out, bool autoFlush) {
	PrintStream::init$(autoFlush, $cast($OutputStream, $(requireNonNull(out, "Null output stream"_s))));
}

void PrintStream::init$($OutputStream* out, bool autoFlush, $String* encoding) {
	$useLocalCurrentObjectStackCache();
	$var($OutputStream, var$0, $cast($OutputStream, requireNonNull(out, "Null output stream"_s)));
	bool var$1 = autoFlush;
	PrintStream::init$(var$0, var$1, $(toCharset(encoding)));
}

void PrintStream::init$($OutputStream* out, bool autoFlush, $Charset* charset) {
	$FilterOutputStream::init$(out);
	this->trouble = false;
	this->closing = false;
	this->autoFlush = autoFlush;
	$set(this, charOut, $new($OutputStreamWriter, static_cast<$OutputStream*>(this), charset));
	$set(this, textOut, $new($BufferedWriter, this->charOut));
}

void PrintStream::init$($String* fileName) {
	PrintStream::init$(false, static_cast<$OutputStream*>($$new($FileOutputStream, fileName)));
}

void PrintStream::init$($String* fileName, $String* csn) {
	$useLocalCurrentObjectStackCache();
	$var($Charset, var$0, toCharset(csn));
	PrintStream::init$(false, var$0, static_cast<$OutputStream*>($$new($FileOutputStream, fileName)));
}

void PrintStream::init$($String* fileName, $Charset* charset) {
	$useLocalCurrentObjectStackCache();
	$var($Charset, var$0, $cast($Charset, requireNonNull(charset, "charset"_s)));
	PrintStream::init$(false, var$0, static_cast<$OutputStream*>($$new($FileOutputStream, fileName)));
}

void PrintStream::init$($File* file) {
	PrintStream::init$(false, static_cast<$OutputStream*>($$new($FileOutputStream, file)));
}

void PrintStream::init$($File* file, $String* csn) {
	$useLocalCurrentObjectStackCache();
	$var($Charset, var$0, toCharset(csn));
	PrintStream::init$(false, var$0, static_cast<$OutputStream*>($$new($FileOutputStream, file)));
}

void PrintStream::init$($File* file, $Charset* charset) {
	$useLocalCurrentObjectStackCache();
	$var($Charset, var$0, $cast($Charset, requireNonNull(charset, "charset"_s)));
	PrintStream::init$(false, var$0, static_cast<$OutputStream*>($$new($FileOutputStream, file)));
}

void PrintStream::ensureOpen() {
	if (this->out == nullptr) {
		$throwNew($IOException, "Stream closed"_s);
	}
}

void PrintStream::flush() {
	$synchronized(this) {
		try {
			ensureOpen();
			$nc(this->out)->flush();
		} catch ($IOException& x) {
			this->trouble = true;
		}
	}
}

void PrintStream::close() {
	$synchronized(this) {
		if (!this->closing) {
			this->closing = true;
			try {
				$nc(this->textOut)->close();
				$nc(this->out)->close();
			} catch ($IOException& x) {
				this->trouble = true;
			}
			$set(this, textOut, nullptr);
			$set(this, charOut, nullptr);
			$set(this, out, nullptr);
		}
	}
}

bool PrintStream::checkError() {
	$useLocalCurrentObjectStackCache();
	if (this->out != nullptr) {
		flush();
	}
	{
		$var(PrintStream, ps, nullptr);
		$var($OutputStream, patt19379$temp, this->out);
		bool var$0 = $instanceOf(PrintStream, patt19379$temp);
		if (var$0) {
			$assign(ps, $cast(PrintStream, patt19379$temp));
			var$0 = true;
		}
		if (var$0) {
			return $nc(ps)->checkError();
		}
	}
	return this->trouble;
}

void PrintStream::setError() {
	this->trouble = true;
}

void PrintStream::clearError() {
	this->trouble = false;
}

void PrintStream::write(int32_t b) {
	try {
		$synchronized(this) {
			ensureOpen();
			$nc(this->out)->write(b);
			if ((b == u'\n') && this->autoFlush) {
				$nc(this->out)->flush();
			}
		}
	} catch ($InterruptedIOException& x) {
		$($Thread::currentThread())->interrupt();
	} catch ($IOException& x) {
		this->trouble = true;
	}
}

void PrintStream::write($bytes* buf, int32_t off, int32_t len) {
	try {
		$synchronized(this) {
			ensureOpen();
			$nc(this->out)->write(buf, off, len);
			if (this->autoFlush) {
				$nc(this->out)->flush();
			}
		}
	} catch ($InterruptedIOException& x) {
		$($Thread::currentThread())->interrupt();
	} catch ($IOException& x) {
		this->trouble = true;
	}
}

void PrintStream::write($bytes* buf) {
	this->write(buf, 0, $nc(buf)->length);
}

void PrintStream::writeBytes($bytes* buf) {
	this->write(buf, 0, $nc(buf)->length);
}

void PrintStream::write($chars* buf) {
	try {
		$synchronized(this) {
			ensureOpen();
			$nc(this->textOut)->write(buf);
			$nc(this->textOut)->flushBuffer();
			$nc(this->charOut)->flushBuffer();
			if (this->autoFlush) {
				for (int32_t i = 0; i < $nc(buf)->length; ++i) {
					if (buf->get(i) == u'\n') {
						$nc(this->out)->flush();
						break;
					}
				}
			}
		}
	} catch ($InterruptedIOException& x) {
		$($Thread::currentThread())->interrupt();
	} catch ($IOException& x) {
		this->trouble = true;
	}
}

void PrintStream::writeln($chars* buf) {
	try {
		$synchronized(this) {
			ensureOpen();
			$nc(this->textOut)->write(buf);
			$nc(this->textOut)->newLine();
			$nc(this->textOut)->flushBuffer();
			$nc(this->charOut)->flushBuffer();
			if (this->autoFlush) {
				$nc(this->out)->flush();
			}
		}
	} catch ($InterruptedIOException& x) {
		$($Thread::currentThread())->interrupt();
	} catch ($IOException& x) {
		this->trouble = true;
	}
}

void PrintStream::write($String* s) {
	try {
		$synchronized(this) {
			ensureOpen();
			$nc(this->textOut)->write(s);
			$nc(this->textOut)->flushBuffer();
			$nc(this->charOut)->flushBuffer();
			if (this->autoFlush && ($nc(s)->indexOf((int32_t)u'\n') >= 0)) {
				$nc(this->out)->flush();
			}
		}
	} catch ($InterruptedIOException& x) {
		$($Thread::currentThread())->interrupt();
	} catch ($IOException& x) {
		this->trouble = true;
	}
}

void PrintStream::writeln($String* s) {
	try {
		$synchronized(this) {
			ensureOpen();
			$nc(this->textOut)->write(s);
			$nc(this->textOut)->newLine();
			$nc(this->textOut)->flushBuffer();
			$nc(this->charOut)->flushBuffer();
			if (this->autoFlush) {
				$nc(this->out)->flush();
			}
		}
	} catch ($InterruptedIOException& x) {
		$($Thread::currentThread())->interrupt();
	} catch ($IOException& x) {
		this->trouble = true;
	}
}

void PrintStream::newLine() {
	try {
		$synchronized(this) {
			ensureOpen();
			$nc(this->textOut)->newLine();
			$nc(this->textOut)->flushBuffer();
			$nc(this->charOut)->flushBuffer();
			if (this->autoFlush) {
				$nc(this->out)->flush();
			}
		}
	} catch ($InterruptedIOException& x) {
		$($Thread::currentThread())->interrupt();
	} catch ($IOException& x) {
		this->trouble = true;
	}
}

void PrintStream::print(bool b) {
	write($($String::valueOf(b)));
}

void PrintStream::print(char16_t c) {
	write($($String::valueOf(c)));
}

void PrintStream::print(int32_t i) {
	write($($String::valueOf(i)));
}

void PrintStream::print(int64_t l) {
	write($($String::valueOf(l)));
}

void PrintStream::print(float f) {
	write($($String::valueOf(f)));
}

void PrintStream::print(double d) {
	write($($String::valueOf(d)));
}

void PrintStream::print($chars* s) {
	write(s);
}

void PrintStream::print($String* s) {
	write($($String::valueOf($of(s))));
}

void PrintStream::print(Object$* obj) {
	write($($String::valueOf(obj)));
}

void PrintStream::println() {
	newLine();
}

void PrintStream::println(bool x) {
	if ($of(this)->getClass() == PrintStream::class$) {
		writeln($($String::valueOf(x)));
	} else {
		$synchronized(this) {
			print(x);
			newLine();
		}
	}
}

void PrintStream::println(char16_t x) {
	if ($of(this)->getClass() == PrintStream::class$) {
		writeln($($String::valueOf(x)));
	} else {
		$synchronized(this) {
			print(x);
			newLine();
		}
	}
}

void PrintStream::println(int32_t x) {
	if ($of(this)->getClass() == PrintStream::class$) {
		writeln($($String::valueOf(x)));
	} else {
		$synchronized(this) {
			print(x);
			newLine();
		}
	}
}

void PrintStream::println(int64_t x) {
	if ($of(this)->getClass() == PrintStream::class$) {
		writeln($($String::valueOf(x)));
	} else {
		$synchronized(this) {
			print(x);
			newLine();
		}
	}
}

void PrintStream::println(float x) {
	if ($of(this)->getClass() == PrintStream::class$) {
		writeln($($String::valueOf(x)));
	} else {
		$synchronized(this) {
			print(x);
			newLine();
		}
	}
}

void PrintStream::println(double x) {
	if ($of(this)->getClass() == PrintStream::class$) {
		writeln($($String::valueOf(x)));
	} else {
		$synchronized(this) {
			print(x);
			newLine();
		}
	}
}

void PrintStream::println($chars* x) {
	if ($of(this)->getClass() == PrintStream::class$) {
		writeln(x);
	} else {
		$synchronized(this) {
			print(x);
			newLine();
		}
	}
}

void PrintStream::println($String* x) {
	if ($of(this)->getClass() == PrintStream::class$) {
		writeln($($String::valueOf($of(x))));
	} else {
		$synchronized(this) {
			print(x);
			newLine();
		}
	}
}

void PrintStream::println(Object$* x) {
	$useLocalCurrentObjectStackCache();
	$var($String, s, $String::valueOf(x));
	if ($of(this)->getClass() == PrintStream::class$) {
		writeln($($String::valueOf($of(s))));
	} else {
		$synchronized(this) {
			print(s);
			newLine();
		}
	}
}

PrintStream* PrintStream::printf($String* format, $ObjectArray* args) {
	return this->format(format, args);
}

PrintStream* PrintStream::printf($Locale* l, $String* format, $ObjectArray* args) {
	return this->format(l, format, args);
}

PrintStream* PrintStream::format($String* format, $ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	try {
		$synchronized(this) {
			ensureOpen();
			bool var$0 = (this->formatter == nullptr);
			if (!var$0) {
				$init($Locale$Category);
				var$0 = ($nc(this->formatter)->locale() != $Locale::getDefault($Locale$Category::FORMAT));
			}
			if (var$0) {
				$set(this, formatter, $new($Formatter, static_cast<$Appendable*>(this)));
			}
			$init($Locale$Category);
			$nc(this->formatter)->format($($Locale::getDefault($Locale$Category::FORMAT)), format, args);
		}
	} catch ($InterruptedIOException& x) {
		$($Thread::currentThread())->interrupt();
	} catch ($IOException& x) {
		this->trouble = true;
	}
	return this;
}

PrintStream* PrintStream::format($Locale* l, $String* format, $ObjectArray* args) {
	try {
		$synchronized(this) {
			ensureOpen();
			if ((this->formatter == nullptr) || ($nc(this->formatter)->locale() != l)) {
				$set(this, formatter, $new($Formatter, static_cast<$Appendable*>(this), l));
			}
			$nc(this->formatter)->format(l, format, args);
		}
	} catch ($InterruptedIOException& x) {
		$($Thread::currentThread())->interrupt();
	} catch ($IOException& x) {
		this->trouble = true;
	}
	return this;
}

$Appendable* PrintStream::append($CharSequence* csq) {
	print($($String::valueOf($of(csq))));
	return this;
}

$Appendable* PrintStream::append($CharSequence* csq$renamed, int32_t start, int32_t end) {
	$useLocalCurrentObjectStackCache();
	$var($CharSequence, csq, csq$renamed);
	if (csq == nullptr) {
		$assign(csq, "null"_s);
	}
	return append($($nc(csq)->subSequence(start, end)));
}

$Appendable* PrintStream::append(char16_t c) {
	print(c);
	return this;
}

PrintStream::PrintStream() {
}

$Class* PrintStream::load$($String* name, bool initialize) {
	$loadClass(PrintStream, name, initialize, &_PrintStream_ClassInfo_, allocate$PrintStream);
	return class$;
}

$Class* PrintStream::class$ = nullptr;

	} // io
} // java
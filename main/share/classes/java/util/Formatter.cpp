#include <java/util/Formatter.h>

#include <java/io/BufferedWriter.h>
#include <java/io/Closeable.h>
#include <java/io/File.h>
#include <java/io/FileOutputStream.h>
#include <java/io/Flushable.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/io/Writer.h>
#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/nio/charset/UnsupportedCharsetException.h>
#include <java/text/DecimalFormatSymbols.h>
#include <java/util/ArrayList.h>
#include <java/util/Formatter$Conversion.h>
#include <java/util/Formatter$FixedString.h>
#include <java/util/Formatter$FormatSpecifier.h>
#include <java/util/Formatter$FormatString.h>
#include <java/util/FormatterClosedException.h>
#include <java/util/List.h>
#include <java/util/Locale$Category.h>
#include <java/util/Locale.h>
#include <java/util/MissingFormatArgumentException.h>
#include <java/util/Objects.h>
#include <java/util/UnknownFormatConversionException.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <jcpp.h>

#undef FORMAT
#undef US
#undef ZERO_SENTINEL

using $BufferedWriter = ::java::io::BufferedWriter;
using $Closeable = ::java::io::Closeable;
using $File = ::java::io::File;
using $FileOutputStream = ::java::io::FileOutputStream;
using $Flushable = ::java::io::Flushable;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $PrintStream = ::java::io::PrintStream;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $Writer = ::java::io::Writer;
using $Appendable = ::java::lang::Appendable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $UnsupportedCharsetException = ::java::nio::charset::UnsupportedCharsetException;
using $DecimalFormatSymbols = ::java::text::DecimalFormatSymbols;
using $ArrayList = ::java::util::ArrayList;
using $Formatter$Conversion = ::java::util::Formatter$Conversion;
using $Formatter$FixedString = ::java::util::Formatter$FixedString;
using $Formatter$FormatSpecifier = ::java::util::Formatter$FormatSpecifier;
using $Formatter$FormatString = ::java::util::Formatter$FormatString;
using $FormatterClosedException = ::java::util::FormatterClosedException;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Locale$Category = ::java::util::Locale$Category;
using $MissingFormatArgumentException = ::java::util::MissingFormatArgumentException;
using $Objects = ::java::util::Objects;
using $UnknownFormatConversionException = ::java::util::UnknownFormatConversionException;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;

namespace java {
	namespace util {

$FieldInfo _Formatter_FieldInfo_[] = {
	{"a", "Ljava/lang/Appendable;", nullptr, $PRIVATE, $field(Formatter, a)},
	{"l", "Ljava/util/Locale;", nullptr, $PRIVATE | $FINAL, $field(Formatter, l)},
	{"lastException", "Ljava/io/IOException;", nullptr, $PRIVATE, $field(Formatter, lastException)},
	{"ZERO_SENTINEL", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Formatter, ZERO_SENTINEL)},
	{"zero", "C", nullptr, $PRIVATE, $field(Formatter, zero$)},
	{"formatSpecifier", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Formatter, formatSpecifier)},
	{"fsPattern", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Formatter, fsPattern)},
	{}
};

$MethodInfo _Formatter_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/util/Locale;Ljava/lang/Appendable;)V", nullptr, $PRIVATE, $method(Formatter, init$, void, $Locale*, $Appendable*)},
	{"<init>", "(Ljava/nio/charset/Charset;Ljava/util/Locale;Ljava/io/File;)V", nullptr, $PRIVATE, $method(Formatter, init$, void, $Charset*, $Locale*, $File*), "java.io.FileNotFoundException"},
	{"<init>", "()V", nullptr, $PUBLIC, $method(Formatter, init$, void)},
	{"<init>", "(Ljava/lang/Appendable;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $Appendable*)},
	{"<init>", "(Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $Locale*)},
	{"<init>", "(Ljava/lang/Appendable;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $Appendable*, $Locale*)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $String*), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $String*, $String*), "java.io.FileNotFoundException,java.io.UnsupportedEncodingException"},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $String*, $String*, $Locale*), "java.io.FileNotFoundException,java.io.UnsupportedEncodingException"},
	{"<init>", "(Ljava/lang/String;Ljava/nio/charset/Charset;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $String*, $Charset*, $Locale*), "java.io.IOException"},
	{"<init>", "(Ljava/io/File;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $File*), "java.io.FileNotFoundException"},
	{"<init>", "(Ljava/io/File;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $File*, $String*), "java.io.FileNotFoundException,java.io.UnsupportedEncodingException"},
	{"<init>", "(Ljava/io/File;Ljava/lang/String;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $File*, $String*, $Locale*), "java.io.FileNotFoundException,java.io.UnsupportedEncodingException"},
	{"<init>", "(Ljava/io/File;Ljava/nio/charset/Charset;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $File*, $Charset*, $Locale*), "java.io.IOException"},
	{"<init>", "(Ljava/io/PrintStream;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $PrintStream*)},
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $OutputStream*)},
	{"<init>", "(Ljava/io/OutputStream;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $OutputStream*, $String*), "java.io.UnsupportedEncodingException"},
	{"<init>", "(Ljava/io/OutputStream;Ljava/lang/String;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $OutputStream*, $String*, $Locale*), "java.io.UnsupportedEncodingException"},
	{"<init>", "(Ljava/io/OutputStream;Ljava/nio/charset/Charset;Ljava/util/Locale;)V", nullptr, $PUBLIC, $method(Formatter, init$, void, $OutputStream*, $Charset*, $Locale*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(Formatter, close, void)},
	{"ensureOpen", "()V", nullptr, $PRIVATE, $method(Formatter, ensureOpen, void)},
	{"flush", "()V", nullptr, $PUBLIC, $virtualMethod(Formatter, flush, void)},
	{"format", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/util/Formatter;", nullptr, $PUBLIC | $TRANSIENT, $method(Formatter, format, Formatter*, $String*, $ObjectArray*)},
	{"format", "(Ljava/util/Locale;Ljava/lang/String;[Ljava/lang/Object;)Ljava/util/Formatter;", nullptr, $PUBLIC | $TRANSIENT, $method(Formatter, format, Formatter*, $Locale*, $String*, $ObjectArray*)},
	{"ioException", "()Ljava/io/IOException;", nullptr, $PUBLIC, $method(Formatter, ioException, $IOException*)},
	{"locale", "()Ljava/util/Locale;", nullptr, $PUBLIC, $method(Formatter, locale, $Locale*)},
	{"nonNullAppendable", "(Ljava/lang/Appendable;)Ljava/lang/Appendable;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(Formatter, nonNullAppendable, $Appendable*, $Appendable*)},
	{"out", "()Ljava/lang/Appendable;", nullptr, $PUBLIC, $method(Formatter, out, $Appendable*)},
	{"parse", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/util/Formatter$FormatString;>;", $PRIVATE, $method(Formatter, parse, $List*, $String*)},
	{"toCharset", "(Ljava/lang/String;)Ljava/nio/charset/Charset;", nullptr, $PRIVATE | $STATIC, $staticMethod(Formatter, toCharset, $Charset*, $String*), "java.io.UnsupportedEncodingException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Formatter, toString, $String*)},
	{"zero", "()C", nullptr, $PRIVATE, $method(Formatter, zero, char16_t)},
	{}
};

$InnerClassInfo _Formatter_InnerClassesInfo_[] = {
	{"java.util.Formatter$DateTime", "java.util.Formatter", "DateTime", $PRIVATE | $STATIC},
	{"java.util.Formatter$Conversion", "java.util.Formatter", "Conversion", $PRIVATE | $STATIC},
	{"java.util.Formatter$Flags", "java.util.Formatter", "Flags", $PRIVATE | $STATIC},
	{"java.util.Formatter$FormatSpecifier", "java.util.Formatter", "FormatSpecifier", $PRIVATE},
	{"java.util.Formatter$BigDecimalLayoutForm", "java.util.Formatter", "BigDecimalLayoutForm", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{"java.util.Formatter$FixedString", "java.util.Formatter", "FixedString", $PRIVATE},
	{"java.util.Formatter$FormatString", "java.util.Formatter", "FormatString", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Formatter_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.Formatter",
	"java.lang.Object",
	"java.io.Closeable,java.io.Flushable",
	_Formatter_FieldInfo_,
	_Formatter_MethodInfo_,
	nullptr,
	nullptr,
	_Formatter_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.Formatter$DateTime,java.util.Formatter$Conversion,java.util.Formatter$Flags,java.util.Formatter$FormatSpecifier,java.util.Formatter$FormatSpecifier$BigDecimalLayout,java.util.Formatter$BigDecimalLayoutForm,java.util.Formatter$FixedString,java.util.Formatter$FormatString"
};

$Object* allocate$Formatter($Class* clazz) {
	return $of($alloc(Formatter));
}

int32_t Formatter::hashCode() {
	 return this->$Closeable::hashCode();
}

bool Formatter::equals(Object$* obj) {
	 return this->$Closeable::equals(obj);
}

$Object* Formatter::clone() {
	 return this->$Closeable::clone();
}

void Formatter::finalize() {
	this->$Closeable::finalize();
}

$String* Formatter::formatSpecifier = nullptr;
$Pattern* Formatter::fsPattern = nullptr;

$Charset* Formatter::toCharset($String* csn) {
	$init(Formatter);
	$Objects::requireNonNull($of(csn), "charsetName"_s);
	try {
		return $Charset::forName(csn);
	} catch ($IllegalCharsetNameException& unused) {
		$throwNew($UnsupportedEncodingException, csn);
	} catch ($UnsupportedCharsetException& unused) {
		$throwNew($UnsupportedEncodingException, csn);
	}
	$shouldNotReachHere();
}

$Appendable* Formatter::nonNullAppendable($Appendable* a) {
	$init(Formatter);
	if (a == nullptr) {
		return $new($StringBuilder);
	}
	return a;
}

void Formatter::init$($Locale* l, $Appendable* a) {
	this->zero$ = Formatter::ZERO_SENTINEL;
	$set(this, a, a);
	$set(this, l, l);
}

void Formatter::init$($Charset* charset, $Locale* l, $File* file) {
	$useLocalCurrentObjectStackCache();
	Formatter::init$(l, static_cast<$Appendable*>($$new($BufferedWriter, $$new($OutputStreamWriter, static_cast<$OutputStream*>($$new($FileOutputStream, file)), charset))));
}

void Formatter::init$() {
	$useLocalCurrentObjectStackCache();
	$init($Locale$Category);
	$var($Locale, var$0, $Locale::getDefault($Locale$Category::FORMAT));
	Formatter::init$(var$0, static_cast<$Appendable*>($$new($StringBuilder)));
}

void Formatter::init$($Appendable* a) {
	$useLocalCurrentObjectStackCache();
	$init($Locale$Category);
	$var($Locale, var$0, $Locale::getDefault($Locale$Category::FORMAT));
	Formatter::init$(var$0, $(nonNullAppendable(a)));
}

void Formatter::init$($Locale* l) {
	Formatter::init$(l, static_cast<$Appendable*>($$new($StringBuilder)));
}

void Formatter::init$($Appendable* a, $Locale* l) {
	Formatter::init$(l, $(nonNullAppendable(a)));
}

void Formatter::init$($String* fileName) {
	$useLocalCurrentObjectStackCache();
	$init($Locale$Category);
	$var($Locale, var$0, $Locale::getDefault($Locale$Category::FORMAT));
	Formatter::init$(var$0, static_cast<$Appendable*>($$new($BufferedWriter, $$new($OutputStreamWriter, $$new($FileOutputStream, fileName)))));
}

void Formatter::init$($String* fileName, $String* csn) {
	$init($Locale$Category);
	Formatter::init$(fileName, csn, $($Locale::getDefault($Locale$Category::FORMAT)));
}

void Formatter::init$($String* fileName, $String* csn, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$var($Charset, var$0, toCharset(csn));
	$var($Locale, var$1, l);
	Formatter::init$(var$0, var$1, $$new($File, fileName));
}

void Formatter::init$($String* fileName, $Charset* charset, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	$var($Charset, var$0, $cast($Charset, $Objects::requireNonNull($of(charset), "charset"_s)));
	$var($Locale, var$1, l);
	Formatter::init$(var$0, var$1, $$new($File, fileName));
}

void Formatter::init$($File* file) {
	$useLocalCurrentObjectStackCache();
	$init($Locale$Category);
	$var($Locale, var$0, $Locale::getDefault($Locale$Category::FORMAT));
	Formatter::init$(var$0, static_cast<$Appendable*>($$new($BufferedWriter, $$new($OutputStreamWriter, $$new($FileOutputStream, file)))));
}

void Formatter::init$($File* file, $String* csn) {
	$init($Locale$Category);
	Formatter::init$(file, csn, $($Locale::getDefault($Locale$Category::FORMAT)));
}

void Formatter::init$($File* file, $String* csn, $Locale* l) {
	Formatter::init$($(toCharset(csn)), l, file);
}

void Formatter::init$($File* file, $Charset* charset, $Locale* l) {
	Formatter::init$($cast($Charset, $Objects::requireNonNull($of(charset), "charset"_s)), l, file);
}

void Formatter::init$($PrintStream* ps) {
	$init($Locale$Category);
	$var($Locale, var$0, $Locale::getDefault($Locale$Category::FORMAT));
	Formatter::init$(var$0, $cast($Appendable, $Objects::requireNonNull(ps)));
}

void Formatter::init$($OutputStream* os) {
	$useLocalCurrentObjectStackCache();
	$init($Locale$Category);
	$var($Locale, var$0, $Locale::getDefault($Locale$Category::FORMAT));
	Formatter::init$(var$0, static_cast<$Appendable*>($$new($BufferedWriter, $$new($OutputStreamWriter, os))));
}

void Formatter::init$($OutputStream* os, $String* csn) {
	$init($Locale$Category);
	Formatter::init$(os, csn, $($Locale::getDefault($Locale$Category::FORMAT)));
}

void Formatter::init$($OutputStream* os, $String* csn, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	Formatter::init$(l, static_cast<$Appendable*>($$new($BufferedWriter, $$new($OutputStreamWriter, os, csn))));
}

void Formatter::init$($OutputStream* os, $Charset* charset, $Locale* l) {
	$useLocalCurrentObjectStackCache();
	Formatter::init$(l, static_cast<$Appendable*>($$new($BufferedWriter, $$new($OutputStreamWriter, os, charset))));
}

char16_t Formatter::zero() {
	char16_t zero = this->zero$;
	if (zero == Formatter::ZERO_SENTINEL) {
		$init($Locale);
		if ((this->l != nullptr) && !$nc(this->l)->equals($Locale::US)) {
			$var($DecimalFormatSymbols, dfs, $DecimalFormatSymbols::getInstance(this->l));
			zero = $nc(dfs)->getZeroDigit();
		} else {
			zero = u'0';
		}
		this->zero$ = zero;
	}
	return zero;
}

$Locale* Formatter::locale() {
	ensureOpen();
	return this->l;
}

$Appendable* Formatter::out() {
	ensureOpen();
	return this->a;
}

$String* Formatter::toString() {
	ensureOpen();
	return $nc($of(this->a))->toString();
}

void Formatter::flush() {
	ensureOpen();
	if ($instanceOf($Flushable, this->a)) {
		try {
			$nc(($cast($Flushable, this->a)))->flush();
		} catch ($IOException& ioe) {
			$set(this, lastException, ioe);
		}
	}
}

void Formatter::close() {
	if (this->a == nullptr) {
		return;
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				if ($instanceOf($Closeable, this->a)) {
					$nc(($cast($Closeable, this->a)))->close();
				}
			} catch ($IOException& ioe) {
				$set(this, lastException, ioe);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$set(this, a, nullptr);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Formatter::ensureOpen() {
	if (this->a == nullptr) {
		$throwNew($FormatterClosedException);
	}
}

$IOException* Formatter::ioException() {
	return this->lastException;
}

Formatter* Formatter::format($String* format, $ObjectArray* args) {
	return this->format(this->l, format, args);
}

Formatter* Formatter::format($Locale* l, $String* format, $ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	ensureOpen();
	int32_t last = -1;
	int32_t lasto = -1;
	$var($List, fsa, parse(format));
	for (int32_t i = 0; i < $nc(fsa)->size(); ++i) {
		$var($Formatter$FormatString, fs, $cast($Formatter$FormatString, fsa->get(i)));
		int32_t index = $nc(fs)->index();
		try {
			switch (index) {
			case -2:
				{
					fs->print(nullptr, l);
					break;
				}
			case -1:
				{
					{
						if (last < 0 || (args != nullptr && last > args->length - 1)) {
							$throwNew($MissingFormatArgumentException, $(fs->toString()));
						}
						fs->print((args == nullptr ? ($Object*)nullptr : $nc(args)->get(last)), l);
					}
					break;
				}
			case 0:
				{
					{
						++lasto;
						last = lasto;
						if (args != nullptr && lasto > args->length - 1) {
							$throwNew($MissingFormatArgumentException, $(fs->toString()));
						}
						fs->print((args == nullptr ? ($Object*)nullptr : $nc(args)->get(lasto)), l);
					}
					break;
				}
			default:
				{
					{
						last = index - 1;
						if (args != nullptr && last > args->length - 1) {
							$throwNew($MissingFormatArgumentException, $(fs->toString()));
						}
						fs->print((args == nullptr ? ($Object*)nullptr : $nc(args)->get(last)), l);
					}
					break;
				}
			}
		} catch ($IOException& x) {
			$set(this, lastException, x);
		}
	}
	return this;
}

$List* Formatter::parse($String* s) {
	$useLocalCurrentObjectStackCache();
	$var($ArrayList, al, $new($ArrayList));
	int32_t i = 0;
	int32_t max = $nc(s)->length();
	$var($Matcher, m, nullptr);
	while (i < max) {
		int32_t n = s->indexOf((int32_t)u'%', i);
		if (n < 0) {
			al->add($$new($Formatter$FixedString, this, s, i, max));
			break;
		}
		if (i != n) {
			al->add($$new($Formatter$FixedString, this, s, i, n));
		}
		i = n + 1;
		if (i >= max) {
			$throwNew($UnknownFormatConversionException, "%"_s);
		}
		char16_t c = s->charAt(i);
		if ($Formatter$Conversion::isValid(c)) {
			al->add($$new($Formatter$FormatSpecifier, this, c));
			++i;
		} else {
			if (m == nullptr) {
				$assign(m, $nc(Formatter::fsPattern)->matcher(s));
			}
			bool var$0 = $nc(m)->find(n);
			if (var$0 && m->start() == n) {
				al->add($$new($Formatter$FormatSpecifier, this, s, m));
				i = m->end();
			} else {
				$throwNew($UnknownFormatConversionException, $($String::valueOf(c)));
			}
		}
	}
	return al;
}

void clinit$Formatter($Class* class$) {
	$assignStatic(Formatter::formatSpecifier, "%(\\d+\\$)?([-#+ 0,(\\<]*)?(\\d+)?(\\.\\d+)?([tT])?([a-zA-Z%])"_s);
	$assignStatic(Formatter::fsPattern, $Pattern::compile(Formatter::formatSpecifier));
}

Formatter::Formatter() {
}

$Class* Formatter::load$($String* name, bool initialize) {
	$loadClass(Formatter, name, initialize, &_Formatter_ClassInfo_, clinit$Formatter, allocate$Formatter);
	return class$;
}

$Class* Formatter::class$ = nullptr;

	} // util
} // java
#include <sun/security/util/Password.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/Console.h>
#include <java/io/InputStream.h>
#include <java/io/PushbackInputStream.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <java/nio/charset/CoderResult.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/util/Arrays.h>
#include <jcpp.h>

#undef REPLACE

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $Console = ::java::io::Console;
using $InputStream = ::java::io::InputStream;
using $PushbackInputStream = ::java::io::PushbackInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $Charset = ::java::nio::charset::Charset;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $Arrays = ::java::util::Arrays;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _Password_FieldInfo_[] = {
	{"enc", "Ljava/nio/charset/CharsetEncoder;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(Password, enc)},
	{}
};

$MethodInfo _Password_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Password, init$, void)},
	{"convertToBytes", "([C)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(Password, convertToBytes, $bytes*, $chars*)},
	{"readPassword", "(Ljava/io/InputStream;)[C", nullptr, $PUBLIC | $STATIC, $staticMethod(Password, readPassword, $chars*, $InputStream*), "java.io.IOException"},
	{"readPassword", "(Ljava/io/InputStream;Z)[C", nullptr, $PUBLIC | $STATIC, $staticMethod(Password, readPassword, $chars*, $InputStream*, bool), "java.io.IOException"},
	{}
};

$ClassInfo _Password_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.Password",
	"java.lang.Object",
	nullptr,
	_Password_FieldInfo_,
	_Password_MethodInfo_
};

$Object* allocate$Password($Class* clazz) {
	return $of($alloc(Password));
}

$volatile($CharsetEncoder*) Password::enc = nullptr;

void Password::init$() {
}

$chars* Password::readPassword($InputStream* in) {
	return readPassword(in, false);
}

$chars* Password::readPassword($InputStream* in$renamed, bool isEchoOn) {
	$useLocalCurrentObjectStackCache();
	$var($InputStream, in, in$renamed);
	$var($chars, consoleEntered, nullptr);
	$var($bytes, consoleBytes, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		$var($chars, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($Console, con, nullptr);
			if (!isEchoOn && in == $System::in && (($assign(con, $System::console())) != nullptr)) {
				$assign(consoleEntered, $nc(con)->readPassword());
				if (consoleEntered != nullptr && consoleEntered->length == 0) {
					$assign(var$2, nullptr);
					return$1 = true;
					goto $finally;
				}
				$assign(consoleBytes, convertToBytes(consoleEntered));
				$assign(in, $new($ByteArrayInputStream, consoleBytes));
			}
			$var($chars, lineBuffer, nullptr);
			$var($chars, buf, nullptr);
			int32_t i = 0;
			$assign(buf, ($assign(lineBuffer, $new($chars, 128))));
			int32_t room = $nc(buf)->length;
			int32_t offset = 0;
			int32_t c = 0;
			bool done = false;
			while (!done) {
				{
					int32_t c2 = 0;
					switch (c = $nc(in)->read()) {
					case -1:
						{}
					case u'\n':
						{
							done = true;
							break;
						}
					case u'\r':
						{
							c2 = in->read();
							if ((c2 != u'\n') && (c2 != -1)) {
								if (!($instanceOf($PushbackInputStream, in))) {
									$assign(in, $new($PushbackInputStream, in));
								}
								$nc(($cast($PushbackInputStream, in)))->unread(c2);
							} else {
								done = true;
								break;
							}
						}
					default:
						{
							if (--room < 0) {
								$assign(buf, $new($chars, offset + 128));
								room = buf->length - offset - 1;
								$System::arraycopy(lineBuffer, 0, buf, 0, offset);
								$Arrays::fill(lineBuffer, u' ');
								$assign(lineBuffer, buf);
							}
							buf->set(offset++, (char16_t)c);
							break;
						}
					}
				}
			}
			if (offset == 0) {
				$assign(var$2, nullptr);
				return$1 = true;
				goto $finally;
			}
			$var($chars, ret, $new($chars, offset));
			$System::arraycopy(buf, 0, ret, 0, offset);
			$Arrays::fill(buf, u' ');
			$assign(var$2, ret);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (consoleEntered != nullptr) {
				$Arrays::fill(consoleEntered, u' ');
			}
			if (consoleBytes != nullptr) {
				$Arrays::fill(consoleBytes, (int8_t)0);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$bytes* Password::convertToBytes($chars* pass) {
	$useLocalCurrentObjectStackCache();
	$init(Password);
	if (Password::enc == nullptr) {
		$synchronized(Password::class$) {
			$init($CodingErrorAction);
			$assignStatic(Password::enc, $nc($($nc($($nc($($nc($($System::console()))->charset()))->newEncoder()))->onMalformedInput($CodingErrorAction::REPLACE)))->onUnmappableCharacter($CodingErrorAction::REPLACE));
		}
	}
	$var($bytes, ba, $new($bytes, $cast(int32_t, ($nc(Password::enc)->maxBytesPerChar() * $nc(pass)->length))));
	$var($ByteBuffer, bb, $ByteBuffer::wrap(ba));
	$synchronized(Password::enc) {
		$nc($($nc(Password::enc)->reset()))->encode($($CharBuffer::wrap(pass)), bb, true);
	}
	if ($nc(bb)->position() < ba->length) {
		ba->set(bb->position(), (int8_t)u'\n');
	}
	return ba;
}

Password::Password() {
}

$Class* Password::load$($String* name, bool initialize) {
	$loadClass(Password, name, initialize, &_Password_ClassInfo_, allocate$Password);
	return class$;
}

$Class* Password::class$ = nullptr;

		} // util
	} // security
} // sun
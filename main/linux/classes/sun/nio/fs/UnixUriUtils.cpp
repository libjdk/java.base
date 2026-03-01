#include <sun/nio/fs/UnixUriUtils.h>

#include <java/io/File.h>
#include <java/lang/Appendable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Math.h>
#include <java/lang/SecurityException.h>
#include <java/net/URI.h>
#include <java/net/URISyntaxException.h>
#include <java/nio/file/Path.h>
#include <java/util/Arrays.h>
#include <java/util/HexFormat.h>
#include <sun/nio/fs/UnixConstants.h>
#include <sun/nio/fs/UnixFileSystem.h>
#include <sun/nio/fs/UnixNativeDispatcher.h>
#include <sun/nio/fs/UnixPath.h>
#include <jcpp.h>

#undef H_ALPHA
#undef H_ALPHANUM
#undef H_DIGIT
#undef H_LOWALPHA
#undef H_MARK
#undef H_PATH
#undef H_PCHAR
#undef H_UNRESERVED
#undef H_UPALPHA
#undef L_ALPHA
#undef L_ALPHANUM
#undef L_DIGIT
#undef L_LOWALPHA
#undef L_MARK
#undef L_PATH
#undef L_PCHAR
#undef L_UNRESERVED
#undef L_UPALPHA
#undef S_IFDIR
#undef S_IFMT

using $File = ::java::io::File;
using $Appendable = ::java::lang::Appendable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $URI = ::java::net::URI;
using $URISyntaxException = ::java::net::URISyntaxException;
using $Path = ::java::nio::file::Path;
using $Arrays = ::java::util::Arrays;
using $HexFormat = ::java::util::HexFormat;
using $UnixConstants = ::sun::nio::fs::UnixConstants;
using $UnixFileSystem = ::sun::nio::fs::UnixFileSystem;
using $UnixNativeDispatcher = ::sun::nio::fs::UnixNativeDispatcher;
using $UnixPath = ::sun::nio::fs::UnixPath;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _UnixUriUtils_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(UnixUriUtils, $assertionsDisabled)},
	{"L_DIGIT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, L_DIGIT)},
	{"H_DIGIT", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnixUriUtils, H_DIGIT)},
	{"L_UPALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnixUriUtils, L_UPALPHA)},
	{"H_UPALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, H_UPALPHA)},
	{"L_LOWALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnixUriUtils, L_LOWALPHA)},
	{"H_LOWALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, H_LOWALPHA)},
	{"L_ALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnixUriUtils, L_ALPHA)},
	{"H_ALPHA", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, H_ALPHA)},
	{"L_ALPHANUM", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, L_ALPHANUM)},
	{"H_ALPHANUM", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, H_ALPHANUM)},
	{"L_MARK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, L_MARK)},
	{"H_MARK", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, H_MARK)},
	{"L_UNRESERVED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, L_UNRESERVED)},
	{"H_UNRESERVED", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, H_UNRESERVED)},
	{"L_PCHAR", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, L_PCHAR)},
	{"H_PCHAR", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, H_PCHAR)},
	{"L_PATH", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, L_PATH)},
	{"H_PATH", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixUriUtils, H_PATH)},
	{}
};

$MethodInfo _UnixUriUtils_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(UnixUriUtils, init$, void)},
	{"decode", "(C)I", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixUriUtils, decode, int32_t, char16_t)},
	{"fromUri", "(Lsun/nio/fs/UnixFileSystem;Ljava/net/URI;)Ljava/nio/file/Path;", nullptr, $STATIC, $staticMethod(UnixUriUtils, fromUri, $Path*, $UnixFileSystem*, $URI*)},
	{"highMask", "(Ljava/lang/String;)J", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixUriUtils, highMask, int64_t, $String*)},
	{"highMask", "(CC)J", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixUriUtils, highMask, int64_t, char16_t, char16_t)},
	{"lowMask", "(Ljava/lang/String;)J", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixUriUtils, lowMask, int64_t, $String*)},
	{"lowMask", "(CC)J", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixUriUtils, lowMask, int64_t, char16_t, char16_t)},
	{"match", "(CJJ)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixUriUtils, match, bool, char16_t, int64_t, int64_t)},
	{"toUri", "(Lsun/nio/fs/UnixPath;)Ljava/net/URI;", nullptr, $STATIC, $staticMethod(UnixUriUtils, toUri, $URI*, $UnixPath*)},
	{}
};

$ClassInfo _UnixUriUtils_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.UnixUriUtils",
	"java.lang.Object",
	nullptr,
	_UnixUriUtils_FieldInfo_,
	_UnixUriUtils_MethodInfo_
};

$Object* allocate$UnixUriUtils($Class* clazz) {
	return $of($alloc(UnixUriUtils));
}

bool UnixUriUtils::$assertionsDisabled = false;
int64_t UnixUriUtils::L_DIGIT = 0;
int64_t UnixUriUtils::H_UPALPHA = 0;
int64_t UnixUriUtils::H_LOWALPHA = 0;
int64_t UnixUriUtils::H_ALPHA = 0;
int64_t UnixUriUtils::L_ALPHANUM = 0;
int64_t UnixUriUtils::H_ALPHANUM = 0;
int64_t UnixUriUtils::L_MARK = 0;
int64_t UnixUriUtils::H_MARK = 0;
int64_t UnixUriUtils::L_UNRESERVED = 0;
int64_t UnixUriUtils::H_UNRESERVED = 0;
int64_t UnixUriUtils::L_PCHAR = 0;
int64_t UnixUriUtils::H_PCHAR = 0;
int64_t UnixUriUtils::L_PATH = 0;
int64_t UnixUriUtils::H_PATH = 0;

void UnixUriUtils::init$() {
}

$Path* UnixUriUtils::fromUri($UnixFileSystem* fs, $URI* uri) {
	$init(UnixUriUtils);
	$useLocalCurrentObjectStackCache();
	if (!$nc(uri)->isAbsolute()) {
		$throwNew($IllegalArgumentException, "URI is not absolute"_s);
	}
	if ($nc(uri)->isOpaque()) {
		$throwNew($IllegalArgumentException, "URI is not hierarchical"_s);
	}
	$var($String, scheme, $nc(uri)->getScheme());
	if ((scheme == nullptr) || !$nc(scheme)->equalsIgnoreCase("file"_s)) {
		$throwNew($IllegalArgumentException, "URI scheme is not \"file\""_s);
	}
	if (uri->getRawAuthority() != nullptr) {
		$throwNew($IllegalArgumentException, "URI has an authority component"_s);
	}
	if (uri->getRawFragment() != nullptr) {
		$throwNew($IllegalArgumentException, "URI has a fragment component"_s);
	}
	if (uri->getRawQuery() != nullptr) {
		$throwNew($IllegalArgumentException, "URI has a query component"_s);
	}
	if (!$nc($(uri->toString()))->startsWith("file:///"_s)) {
		return $$new($File, uri)->toPath();
	}
	$var($String, p, uri->getRawPath());
	int32_t len = $nc(p)->length();
	if (len == 0) {
		$throwNew($IllegalArgumentException, "URI path component is empty"_s);
	}
	if (p->endsWith("/"_s) && len > 1) {
		--len;
	}
	$var($bytes, result, $new($bytes, len));
	int32_t rlen = 0;
	int32_t pos = 0;
	while (pos < len) {
		char16_t c = p->charAt(pos++);
		int8_t b = 0;
		if (c == u'%') {
			if (!UnixUriUtils::$assertionsDisabled && !((pos + 2) <= len)) {
				$throwNew($AssertionError);
			}
			char16_t c1 = p->charAt(pos++);
			char16_t c2 = p->charAt(pos++);
			int32_t var$0 = (decode(c1) << 4);
			b = (int8_t)(var$0 | decode(c2));
			if (b == 0) {
				$throwNew($IllegalArgumentException, "Nul character not allowed"_s);
			}
		} else {
			if (c == 0 || c >= 128) {
				$throwNew($IllegalArgumentException, "Bad escape"_s);
			}
			b = (int8_t)c;
		}
		result->set(rlen++, b);
	}
	if (rlen != result->length) {
		$assign(result, $Arrays::copyOf(result, rlen));
	}
	return $new($UnixPath, fs, result);
}

$URI* UnixUriUtils::toUri($UnixPath* up) {
	$init(UnixUriUtils);
	$useLocalCurrentObjectStackCache();
	$var($bytes, path, $nc($($nc(up)->toAbsolutePath()))->asByteArray());
	$var($StringBuilder, sb, $new($StringBuilder, "file:///"_s));
	if (!UnixUriUtils::$assertionsDisabled && !($nc(path)->get(0) == u'/')) {
		$throwNew($AssertionError);
	}
	$var($HexFormat, hex, $nc($($HexFormat::of()))->withUpperCase());
	for (int32_t i = 1; i < $nc(path)->length; ++i) {
		char16_t c = (char16_t)((int32_t)(path->get(i) & (uint32_t)255));
		if (match(c, UnixUriUtils::L_PATH, UnixUriUtils::H_PATH)) {
			sb->append(c);
		} else {
			sb->append(u'%');
			$nc(hex)->toHexDigits(static_cast<$Appendable*>(sb), (int8_t)c);
		}
	}
	if (sb->charAt(sb->length() - 1) != u'/') {
		try {
			up->checkRead();
			int32_t mode = $UnixNativeDispatcher::stat(up);
			$init($UnixConstants);
			if (((int32_t)(mode & (uint32_t)$UnixConstants::S_IFMT)) == $UnixConstants::S_IFDIR) {
				sb->append(u'/');
			}
		} catch ($SecurityException& ignore) {
		}
	}
	try {
		return $new($URI, $(sb->toString()));
	} catch ($URISyntaxException& x) {
		$throwNew($AssertionError, $of(x));
	}
	$shouldNotReachHere();
}

int64_t UnixUriUtils::lowMask($String* chars) {
	$init(UnixUriUtils);
	int32_t n = $nc(chars)->length();
	int64_t m = 0;
	for (int32_t i = 0; i < n; ++i) {
		char16_t c = chars->charAt(i);
		if (c < 64) {
			m |= ($sl((int64_t)1, c));
		}
	}
	return m;
}

int64_t UnixUriUtils::highMask($String* chars) {
	$init(UnixUriUtils);
	int32_t n = $nc(chars)->length();
	int64_t m = 0;
	for (int32_t i = 0; i < n; ++i) {
		char16_t c = chars->charAt(i);
		if ((c >= 64) && (c < 128)) {
			m |= ($sl((int64_t)1, c - 64));
		}
	}
	return m;
}

int64_t UnixUriUtils::lowMask(char16_t first, char16_t last) {
	$init(UnixUriUtils);
	int64_t m = 0;
	int32_t f = $Math::max($Math::min((int32_t)first, 63), 0);
	int32_t l = $Math::max($Math::min((int32_t)last, 63), 0);
	for (int32_t i = f; i <= l; ++i) {
		m |= $sl((int64_t)1, i);
	}
	return m;
}

int64_t UnixUriUtils::highMask(char16_t first, char16_t last) {
	$init(UnixUriUtils);
	int64_t m = 0;
	int32_t f = $Math::max($Math::min((int32_t)first, 127), 64) - 64;
	int32_t l = $Math::max($Math::min((int32_t)last, 127), 64) - 64;
	for (int32_t i = f; i <= l; ++i) {
		m |= $sl((int64_t)1, i);
	}
	return m;
}

bool UnixUriUtils::match(char16_t c, int64_t lowMask, int64_t highMask) {
	$init(UnixUriUtils);
	if (c < 64) {
		return ((int64_t)(($sl((int64_t)1, c)) & (uint64_t)lowMask)) != 0;
	}
	if (c < 128) {
		return ((int64_t)(($sl((int64_t)1, c - 64)) & (uint64_t)highMask)) != 0;
	}
	return false;
}

int32_t UnixUriUtils::decode(char16_t c) {
	$init(UnixUriUtils);
	if ((c >= u'0') && (c <= u'9')) {
		return c - u'0';
	}
	if ((c >= u'a') && (c <= u'f')) {
		return c - u'a' + 10;
	}
	if ((c >= u'A') && (c <= u'F')) {
		return c - u'A' + 10;
	}
	$throwNew($AssertionError);
}

void clinit$UnixUriUtils($Class* class$) {
	UnixUriUtils::$assertionsDisabled = !UnixUriUtils::class$->desiredAssertionStatus();
	UnixUriUtils::L_DIGIT = UnixUriUtils::lowMask(u'0', u'9');
	UnixUriUtils::H_UPALPHA = UnixUriUtils::highMask(u'A', u'Z');
	UnixUriUtils::H_LOWALPHA = UnixUriUtils::highMask(u'a', u'z');
	UnixUriUtils::H_ALPHA = UnixUriUtils::H_LOWALPHA | UnixUriUtils::H_UPALPHA;
	UnixUriUtils::L_ALPHANUM = UnixUriUtils::L_DIGIT | UnixUriUtils::L_ALPHA;
	UnixUriUtils::H_ALPHANUM = UnixUriUtils::H_DIGIT | UnixUriUtils::H_ALPHA;
	UnixUriUtils::L_MARK = UnixUriUtils::lowMask("-_.!~*\'()"_s);
	UnixUriUtils::H_MARK = UnixUriUtils::highMask("-_.!~*\'()"_s);
	UnixUriUtils::L_UNRESERVED = UnixUriUtils::L_ALPHANUM | UnixUriUtils::L_MARK;
	UnixUriUtils::H_UNRESERVED = UnixUriUtils::H_ALPHANUM | UnixUriUtils::H_MARK;
	UnixUriUtils::L_PCHAR = UnixUriUtils::L_UNRESERVED | UnixUriUtils::lowMask(":@&=+$,"_s);
	UnixUriUtils::H_PCHAR = UnixUriUtils::H_UNRESERVED | UnixUriUtils::highMask(":@&=+$,"_s);
	UnixUriUtils::L_PATH = UnixUriUtils::L_PCHAR | UnixUriUtils::lowMask(";/"_s);
	UnixUriUtils::H_PATH = UnixUriUtils::H_PCHAR | UnixUriUtils::highMask(";/"_s);
}

UnixUriUtils::UnixUriUtils() {
}

$Class* UnixUriUtils::load$($String* name, bool initialize) {
	$loadClass(UnixUriUtils, name, initialize, &_UnixUriUtils_ClassInfo_, clinit$UnixUriUtils, allocate$UnixUriUtils);
	return class$;
}

$Class* UnixUriUtils::class$ = nullptr;

		} // fs
	} // nio
} // sun
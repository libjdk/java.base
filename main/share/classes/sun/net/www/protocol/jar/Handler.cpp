#include <sun/net/www/protocol/jar/Handler.h>

#include <java/net/MalformedURLException.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/URLStreamHandler.h>
#include <sun/net/www/protocol/jar/JarURLConnection.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URL = ::java::net::URL;
using $URLConnection = ::java::net::URLConnection;
using $URLStreamHandler = ::java::net::URLStreamHandler;
using $JarURLConnection = ::sun::net::www::protocol::jar::JarURLConnection;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace jar {

$FieldInfo _Handler_FieldInfo_[] = {
	{"separator", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Handler, separator)},
	{}
};

$MethodInfo _Handler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Handler, init$, void)},
	{"canonicalizeString", "(Ljava/lang/String;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Handler, canonicalizeString, $String*, $String*, int32_t)},
	{"checkNestedProtocol", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Handler, checkNestedProtocol, $String*, $String*)},
	{"doCanonicalize", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Handler, doCanonicalize, $String*, $String*)},
	{"hashCode", "(Ljava/net/URL;)I", nullptr, $PROTECTED, $virtualMethod(Handler, hashCode, int32_t, $URL*)},
	{"indexOfBangSlash", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(Handler, indexOfBangSlash, int32_t, $String*)},
	{"openConnection", "(Ljava/net/URL;)Ljava/net/URLConnection;", nullptr, $PROTECTED, $virtualMethod(Handler, openConnection, $URLConnection*, $URL*), "java.io.IOException"},
	{"parseAbsoluteSpec", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Handler, parseAbsoluteSpec, $String*, $String*)},
	{"parseContextSpec", "(Ljava/net/URL;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Handler, parseContextSpec, $String*, $URL*, $String*)},
	{"parseURL", "(Ljava/net/URL;Ljava/lang/String;II)V", nullptr, $PROTECTED, $virtualMethod(Handler, parseURL, void, $URL*, $String*, int32_t, int32_t)},
	{"sameFile", "(Ljava/net/URL;Ljava/net/URL;)Z", nullptr, $PROTECTED, $virtualMethod(Handler, sameFile, bool, $URL*, $URL*)},
	{}
};

$ClassInfo _Handler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.jar.Handler",
	"java.net.URLStreamHandler",
	nullptr,
	_Handler_FieldInfo_,
	_Handler_MethodInfo_
};

$Object* allocate$Handler($Class* clazz) {
	return $of($alloc(Handler));
}

$String* Handler::separator = nullptr;

void Handler::init$() {
	$URLStreamHandler::init$();
}

$URLConnection* Handler::openConnection($URL* u) {
	return $new($JarURLConnection, u, this);
}

int32_t Handler::indexOfBangSlash($String* spec) {
	$init(Handler);
	int32_t indexOfBang = $nc(spec)->length();
	while ((indexOfBang = spec->lastIndexOf((int32_t)u'!', indexOfBang)) != -1) {
		bool var$0 = (indexOfBang != (spec->length() - 1));
		if (var$0 && (spec->charAt(indexOfBang + 1) == u'/')) {
			return indexOfBang + 1;
		} else {
			--indexOfBang;
		}
	}
	return -1;
}

bool Handler::sameFile($URL* u1, $URL* u2) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !$nc($($nc(u1)->getProtocol()))->equals("jar"_s);
	if (var$0 || !$nc($($nc(u2)->getProtocol()))->equals("jar"_s)) {
		return false;
	}
	$var($String, file1, $nc(u1)->getFile());
	$var($String, file2, $nc(u2)->getFile());
	int32_t sep1 = $nc(file1)->indexOf(Handler::separator);
	int32_t sep2 = $nc(file2)->indexOf(Handler::separator);
	if (sep1 == -1 || sep2 == -1) {
		return $URLStreamHandler::sameFile(u1, u2);
	}
	$var($String, entry1, file1->substring(sep1 + 2));
	$var($String, entry2, file2->substring(sep2 + 2));
	if (!entry1->equals(entry2)) {
		return false;
	}
	$var($URL, enclosedURL1, nullptr);
	$var($URL, enclosedURL2, nullptr);
	try {
		$assign(enclosedURL1, $new($URL, $(file1->substring(0, sep1))));
		$assign(enclosedURL2, $new($URL, $(file2->substring(0, sep2))));
	} catch ($MalformedURLException& unused) {
		return $URLStreamHandler::sameFile(u1, u2);
	}
	if (!$URLStreamHandler::sameFile(enclosedURL1, enclosedURL2)) {
		return false;
	}
	return true;
}

int32_t Handler::hashCode($URL* u) {
	$useLocalCurrentObjectStackCache();
	int32_t h = 0;
	$var($String, protocol, $nc(u)->getProtocol());
	if (protocol != nullptr) {
		h += protocol->hashCode();
	}
	$var($String, file, u->getFile());
	int32_t sep = $nc(file)->indexOf(Handler::separator);
	if (sep == -1) {
		return h + file->hashCode();
	}
	$var($URL, enclosedURL, nullptr);
	$var($String, fileWithoutEntry, file->substring(0, sep));
	try {
		$assign(enclosedURL, $new($URL, fileWithoutEntry));
		h += enclosedURL->hashCode();
	} catch ($MalformedURLException& unused) {
		h += fileWithoutEntry->hashCode();
	}
	$var($String, entry, file->substring(sep + 2));
	h += entry->hashCode();
	return h;
}

$String* Handler::checkNestedProtocol($String* spec) {
	if ($nc(spec)->regionMatches(true, 0, "jar:"_s, 0, 4)) {
		return "Nested JAR URLs are not supported"_s;
	} else {
		return nullptr;
	}
}

void Handler::parseURL($URL* url, $String* spec$renamed, int32_t start, int32_t limit) {
	$useLocalCurrentObjectStackCache();
	$var($String, spec, spec$renamed);
	$var($String, file, nullptr);
	$var($String, ref, nullptr);
	int32_t refPos = $nc(spec)->indexOf((int32_t)u'#', limit);
	bool refOnly = refPos == start;
	if (refPos > -1) {
		$assign(ref, spec->substring(refPos + 1, spec->length()));
		if (refOnly) {
			$assign(file, $nc(url)->getFile());
		}
	}
	bool absoluteSpec = spec->length() >= 4 ? spec->regionMatches(true, 0, "jar:"_s, 0, 4) : false;
	$assign(spec, spec->substring(start, limit));
	$var($String, exceptionMessage, checkNestedProtocol(spec));
	if (exceptionMessage != nullptr) {
		$throwNew($NullPointerException, exceptionMessage);
	}
	if (absoluteSpec) {
		$assign(file, parseAbsoluteSpec(spec));
	} else if (!refOnly) {
		$assign(file, parseContextSpec(url, spec));
		int32_t bangSlash = indexOfBangSlash(file);
		$assign(file, canonicalizeString(file, bangSlash));
	}
	setURL(url, "jar"_s, ""_s, -1, file, ref);
}

$String* Handler::parseAbsoluteSpec($String* spec) {
	$useLocalCurrentObjectStackCache();
	int32_t index = 0;
	if ((index = indexOfBangSlash(spec)) == -1) {
		$throwNew($NullPointerException, "no !/ in spec"_s);
	}
	try {
		$var($String, innerSpec, $nc(spec)->substring(0, index - 1));
		$new($URL, innerSpec);
	} catch ($MalformedURLException& e) {
		$throwNew($NullPointerException, $$str({"invalid url: "_s, spec, " ("_s, e, ")"_s}));
	}
	return spec;
}

$String* Handler::parseContextSpec($URL* url, $String* spec) {
	$useLocalCurrentObjectStackCache();
	$var($String, ctxFile, $nc(url)->getFile());
	if ($nc(spec)->startsWith("/"_s)) {
		int32_t bangSlash = indexOfBangSlash(ctxFile);
		if (bangSlash == -1) {
			$throwNew($NullPointerException, $$str({"malformed context url:"_s, url, ": no !/"_s}));
		}
		$assign(ctxFile, $nc(ctxFile)->substring(0, bangSlash));
	} else {
		int32_t lastSlash = $nc(ctxFile)->lastIndexOf((int32_t)u'/');
		if (lastSlash == -1) {
			$throwNew($NullPointerException, $$str({"malformed context url:"_s, url}));
		} else if (lastSlash < ctxFile->length() - 1) {
			$assign(ctxFile, ctxFile->substring(0, lastSlash + 1));
		}
	}
	return ($str({ctxFile, spec}));
}

$String* Handler::canonicalizeString($String* file, int32_t off) {
	$init(Handler);
	$useLocalCurrentObjectStackCache();
	int32_t len = $nc(file)->length();
	bool var$0 = off >= len;
	if (!var$0) {
		bool var$1 = file->indexOf("./"_s, off) == -1;
		var$0 = (var$1 && file->charAt(len - 1) != u'.');
	}
	if (var$0) {
		return file;
	} else {
		$var($String, before, file->substring(0, off));
		$var($String, after, file->substring(off));
		return $str({before, $(doCanonicalize(after))});
	}
}

$String* Handler::doCanonicalize($String* file$renamed) {
	$init(Handler);
	$useLocalCurrentObjectStackCache();
	$var($String, file, file$renamed);
	int32_t i = 0;
	int32_t lim = 0;
	while ((i = $nc(file)->indexOf("/../"_s)) >= 0) {
		if ((lim = file->lastIndexOf((int32_t)u'/', i - 1)) >= 0) {
			$var($String, var$0, $(file->substring(0, lim)));
			$assign(file, $concat(var$0, $(file->substring(i + 3))));
		} else {
			$assign(file, file->substring(i + 3));
		}
	}
	while ((i = $nc(file)->indexOf("/./"_s)) >= 0) {
		$var($String, var$1, $(file->substring(0, i)));
		$assign(file, $concat(var$1, $(file->substring(i + 2))));
	}
	while ($nc(file)->endsWith("/.."_s)) {
		i = file->indexOf("/.."_s);
		if ((lim = file->lastIndexOf((int32_t)u'/', i - 1)) >= 0) {
			$assign(file, file->substring(0, lim + 1));
		} else {
			$assign(file, file->substring(0, i));
		}
	}
	if ($nc(file)->endsWith("/."_s)) {
		$assign(file, file->substring(0, file->length() - 1));
	}
	return file;
}

Handler::Handler() {
}

void clinit$Handler($Class* class$) {
	$assignStatic(Handler::separator, "!/"_s);
}

$Class* Handler::load$($String* name, bool initialize) {
	$loadClass(Handler, name, initialize, &_Handler_ClassInfo_, clinit$Handler, allocate$Handler);
	return class$;
}

$Class* Handler::class$ = nullptr;

				} // jar
			} // protocol
		} // www
	} // net
} // sun
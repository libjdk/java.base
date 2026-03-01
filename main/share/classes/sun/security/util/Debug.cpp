#include <sun/security/util/Debug.h>

#include <java/lang/CharSequence.h>
#include <java/lang/StringBuffer.h>
#include <java/math/BigInteger.h>
#include <java/util/HexFormat.h>
#include <java/util/Locale.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef ENGLISH

using $PrintStream = ::java::io::PrintStream;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StringBuffer = ::java::lang::StringBuffer;
using $BigInteger = ::java::math::BigInteger;
using $HexFormat = ::java::util::HexFormat;
using $Locale = ::java::util::Locale;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace security {
		namespace util {

$FieldInfo _Debug_FieldInfo_[] = {
	{"prefix", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Debug, prefix)},
	{"args", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(Debug, args)},
	{}
};

$MethodInfo _Debug_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Debug, init$, void)},
	{"Help", "()V", nullptr, $PUBLIC | $STATIC, $staticMethod(Debug, Help, void)},
	{"getInstance", "(Ljava/lang/String;)Lsun/security/util/Debug;", nullptr, $PUBLIC | $STATIC, $staticMethod(Debug, getInstance, Debug*, $String*)},
	{"getInstance", "(Ljava/lang/String;Ljava/lang/String;)Lsun/security/util/Debug;", nullptr, $PUBLIC | $STATIC, $staticMethod(Debug, getInstance, Debug*, $String*, $String*)},
	{"getPrintStream", "()Ljava/io/PrintStream;", nullptr, $PUBLIC, $virtualMethod(Debug, getPrintStream, $PrintStream*)},
	{"isOn", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $staticMethod(Debug, isOn, bool, $String*)},
	{"isVerbose", "()Z", nullptr, $PUBLIC | $STATIC, $staticMethod(Debug, isVerbose, bool)},
	{"marshal", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(Debug, marshal, $String*, $String*)},
	{"println", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Debug, println, void, $String*)},
	{"println", "(Ljava/lang/Object;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(Debug, println, void, Object$*, $String*)},
	{"println", "()V", nullptr, $PUBLIC, $virtualMethod(Debug, println, void)},
	{"println", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Debug, println, void, $String*, $String*)},
	{"toHexString", "(Ljava/math/BigInteger;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Debug, toHexString, $String*, $BigInteger*)},
	{"toString", "([B)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(Debug, toString, $String*, $bytes*)},
	{}
};

$ClassInfo _Debug_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.util.Debug",
	"java.lang.Object",
	nullptr,
	_Debug_FieldInfo_,
	_Debug_MethodInfo_
};

$Object* allocate$Debug($Class* clazz) {
	return $of($alloc(Debug));
}

$String* Debug::args = nullptr;

void Debug::init$() {
}

void Debug::Help() {
	$init(Debug);
	$nc($System::err)->println();
	$nc($System::err)->println("all           turn on all debugging"_s);
	$nc($System::err)->println("access        print all checkPermission results"_s);
	$nc($System::err)->println("certpath      PKIX CertPathBuilder and"_s);
	$nc($System::err)->println("              CertPathValidator debugging"_s);
	$nc($System::err)->println("combiner      SubjectDomainCombiner debugging"_s);
	$nc($System::err)->println("gssloginconfig"_s);
	$nc($System::err)->println("              GSS LoginConfigImpl debugging"_s);
	$nc($System::err)->println("configfile    JAAS ConfigFile loading"_s);
	$nc($System::err)->println("configparser  JAAS ConfigFile parsing"_s);
	$nc($System::err)->println("jar           jar verification"_s);
	$nc($System::err)->println("logincontext  login context results"_s);
	$nc($System::err)->println("jca           JCA engine class debugging"_s);
	$nc($System::err)->println("keystore      KeyStore debugging"_s);
	$nc($System::err)->println("policy        loading and granting"_s);
	$nc($System::err)->println("provider      security provider debugging"_s);
	$nc($System::err)->println("pkcs11        PKCS11 session manager debugging"_s);
	$nc($System::err)->println("pkcs11keystore"_s);
	$nc($System::err)->println("              PKCS11 KeyStore debugging"_s);
	$nc($System::err)->println("pkcs12        PKCS12 KeyStore debugging"_s);
	$nc($System::err)->println("sunpkcs11     SunPKCS11 provider debugging"_s);
	$nc($System::err)->println("scl           permissions SecureClassLoader assigns"_s);
	$nc($System::err)->println("securerandom  SecureRandom"_s);
	$nc($System::err)->println("ts            timestamping"_s);
	$nc($System::err)->println();
	$nc($System::err)->println("The following can be used with access:"_s);
	$nc($System::err)->println();
	$nc($System::err)->println("stack         include stack trace"_s);
	$nc($System::err)->println("domain        dump all domains in context"_s);
	$nc($System::err)->println("failure       before throwing exception, dump stack"_s);
	$nc($System::err)->println("              and domain that didn\'t have permission"_s);
	$nc($System::err)->println();
	$nc($System::err)->println("The following can be used with stack and domain:"_s);
	$nc($System::err)->println();
	$nc($System::err)->println("permission=<classname>"_s);
	$nc($System::err)->println("              only dump output if specified permission"_s);
	$nc($System::err)->println("              is being checked"_s);
	$nc($System::err)->println("codebase=<URL>"_s);
	$nc($System::err)->println("              only dump output if specified codebase"_s);
	$nc($System::err)->println("              is being checked"_s);
	$nc($System::err)->println();
	$nc($System::err)->println("The following can be used with provider:"_s);
	$nc($System::err)->println();
	$nc($System::err)->println("engine=<engines>"_s);
	$nc($System::err)->println("              only dump output for the specified list"_s);
	$nc($System::err)->println("              of JCA engines. Supported values:"_s);
	$nc($System::err)->println("              Cipher, KeyAgreement, KeyGenerator,"_s);
	$nc($System::err)->println("              KeyPairGenerator, KeyStore, Mac,"_s);
	$nc($System::err)->println("              MessageDigest, SecureRandom, Signature."_s);
	$nc($System::err)->println();
	$nc($System::err)->println("The following can be used with certpath:"_s);
	$nc($System::err)->println();
	$nc($System::err)->println("ocsp          dump the OCSP protocol exchanges"_s);
	$nc($System::err)->println("verbose       verbose debugging"_s);
	$nc($System::err)->println();
	$nc($System::err)->println("Note: Separate multiple options with a comma"_s);
	$System::exit(0);
}

Debug* Debug::getInstance($String* option) {
	$init(Debug);
	return getInstance(option, option);
}

Debug* Debug::getInstance($String* option, $String* prefix) {
	$init(Debug);
	if (isOn(option)) {
		$var(Debug, d, $new(Debug));
		$set(d, prefix, prefix);
		return d;
	} else {
		return nullptr;
	}
}

bool Debug::isOn($String* option) {
	$init(Debug);
	if (Debug::args == nullptr) {
		return false;
	} else {
		if ($nc(Debug::args)->indexOf("all"_s) != -1) {
			return true;
		} else {
			return ($nc(Debug::args)->indexOf(option) != -1);
		}
	}
}

bool Debug::isVerbose() {
	$init(Debug);
	return isOn("verbose"_s);
}

void Debug::println($String* message) {
	$nc($System::err)->println($$str({this->prefix, ": "_s, message}));
}

void Debug::println(Object$* obj, $String* message) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$2, $$str({this->prefix, " ["_s, $($nc($of(obj))->getClass()->getSimpleName()), "@"_s}));
	$var($String, var$1, $$concat(var$2, $$str($System::identityHashCode(obj))));
	$var($String, var$0, $$concat(var$1, "]: "_s));
	$nc($System::err)->println($$concat(var$0, message));
}

void Debug::println() {
	$nc($System::err)->println($$str({this->prefix, ":"_s}));
}

void Debug::println($String* prefix, $String* message) {
	$init(Debug);
	$nc($System::err)->println($$str({prefix, ": "_s, message}));
}

$PrintStream* Debug::getPrintStream() {
	return $System::err;
}

$String* Debug::toHexString($BigInteger* b) {
	$init(Debug);
	$useLocalCurrentObjectStackCache();
	$var($String, hexValue, $nc(b)->toString(16));
	$var($StringBuilder, sb, $new($StringBuilder, $nc(hexValue)->length() * 2));
	if ($nc(hexValue)->startsWith("-"_s)) {
		sb->append("   -"_s);
		$assign(hexValue, hexValue->substring(1));
	} else {
		sb->append("    "_s);
	}
	if (($nc(hexValue)->length() % 2) != 0) {
		$assign(hexValue, $str({"0"_s, hexValue}));
	}
	int32_t i = 0;
	while (i < $nc(hexValue)->length()) {
		sb->append($(hexValue->substring(i, i + 2)));
		i += 2;
		if (i != hexValue->length()) {
			if ((i % 64) == 0) {
				sb->append("\n    "_s);
			} else if (i % 8 == 0) {
				sb->append(" "_s);
			}
		}
	}
	return sb->toString();
}

$String* Debug::marshal($String* args) {
	$init(Debug);
	$useLocalCurrentObjectStackCache();
	if (args != nullptr) {
		$var($StringBuilder, target, $new($StringBuilder));
		$var($StringBuffer, source, $new($StringBuffer, args));
		$var($String, keyReg, "[Pp][Ee][Rr][Mm][Ii][Ss][Ss][Ii][Oo][Nn]="_s);
		$var($String, keyStr, "permission="_s);
		$var($String, reg, $str({keyReg, "[a-zA-Z_$][a-zA-Z0-9_$]*([.][a-zA-Z_$][a-zA-Z0-9_$]*)*"_s}));
		$var($Pattern, pattern, $Pattern::compile(reg));
		$var($Matcher, matcher, $nc(pattern)->matcher(source));
		$var($StringBuffer, left, $new($StringBuffer));
		while ($nc(matcher)->find()) {
			$var($String, matched, matcher->group());
			target->append($($nc(matched)->replaceFirst(keyReg, keyStr)));
			target->append("  "_s);
			matcher->appendReplacement(left, ""_s);
		}
		$nc(matcher)->appendTail(left);
		$assign(source, left);
		$assign(keyReg, "[Cc][Oo][Dd][Ee][Bb][Aa][Ss][Ee]="_s);
		$assign(keyStr, "codebase="_s);
		$assign(reg, $str({keyReg, "[^, ;]*"_s}));
		$assign(pattern, $Pattern::compile(reg));
		$assign(matcher, pattern->matcher(source));
		$assign(left, $new($StringBuffer));
		while (matcher->find()) {
			$var($String, matched, matcher->group());
			target->append($($nc(matched)->replaceFirst(keyReg, keyStr)));
			target->append("  "_s);
			matcher->appendReplacement(left, ""_s);
		}
		matcher->appendTail(left);
		$assign(source, left);
		$init($Locale);
		target->append($($nc($(source->toString()))->toLowerCase($Locale::ENGLISH)));
		return target->toString();
	}
	return nullptr;
}

$String* Debug::toString($bytes* b) {
	$init(Debug);
	if (b == nullptr) {
		return "(null)"_s;
	}
	return $nc($($HexFormat::ofDelimiter(":"_s)))->formatHex(b);
}

void clinit$Debug($Class* class$) {
	{
		$assignStatic(Debug::args, $GetPropertyAction::privilegedGetProperty("java.security.debug"_s));
		$var($String, args2, $GetPropertyAction::privilegedGetProperty("java.security.auth.debug"_s));
		if (Debug::args == nullptr) {
			$assignStatic(Debug::args, args2);
		} else if (args2 != nullptr) {
			$assignStatic(Debug::args, $str({Debug::args, ","_s, args2}));
		}
		if (Debug::args != nullptr) {
			$assignStatic(Debug::args, Debug::marshal(Debug::args));
			if ($nc(Debug::args)->equals("help"_s)) {
				Debug::Help();
			}
		}
	}
}

Debug::Debug() {
}

$Class* Debug::load$($String* name, bool initialize) {
	$loadClass(Debug, name, initialize, &_Debug_ClassInfo_, clinit$Debug, allocate$Debug);
	return class$;
}

$Class* Debug::class$ = nullptr;

		} // util
	} // security
} // sun
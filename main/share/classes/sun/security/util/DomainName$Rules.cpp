#include <sun/security/util/DomainName$Rules.h>

#include <java/io/BufferedReader.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/Map.h>
#include <java/util/function/Function.h>
#include <java/util/zip/ZipEntry.h>
#include <java/util/zip/ZipInputStream.h>
#include <sun/security/ssl/SSLLogger.h>
#include <sun/security/util/DomainName$Match.h>
#include <sun/security/util/DomainName$Rule$Type.h>
#include <sun/security/util/DomainName$Rules$1.h>
#include <sun/security/util/DomainName$Rules$RuleSet.h>
#include <sun/security/util/DomainName.h>
#include <jcpp.h>

#undef EXCEPTION
#undef UTF_8

using $BufferedReader = ::java::io::BufferedReader;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $Map = ::java::util::Map;
using $Function = ::java::util::function::Function;
using $ZipEntry = ::java::util::zip::ZipEntry;
using $ZipInputStream = ::java::util::zip::ZipInputStream;
using $SSLLogger = ::sun::security::ssl::SSLLogger;
using $DomainName = ::sun::security::util::DomainName;
using $DomainName$Match = ::sun::security::util::DomainName$Match;
using $DomainName$Rule$Type = ::sun::security::util::DomainName$Rule$Type;
using $DomainName$Rules$1 = ::sun::security::util::DomainName$Rules$1;
using $DomainName$Rules$RuleSet = ::sun::security::util::DomainName$Rules$RuleSet;

namespace sun {
	namespace security {
		namespace util {

class DomainName$Rules$$Lambda$lambda$getRules$0 : public $Function {
	$class(DomainName$Rules$$Lambda$lambda$getRules$0, $NO_CLASS_INIT, $Function)
public:
	void init$($String* tld) {
		$set(this, tld, tld);
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(DomainName$Rules::lambda$getRules$0(tld, $cast($String, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DomainName$Rules$$Lambda$lambda$getRules$0>());
	}
	$String* tld = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DomainName$Rules$$Lambda$lambda$getRules$0::fieldInfos[2] = {
	{"tld", "Ljava/lang/String;", nullptr, $PUBLIC, $field(DomainName$Rules$$Lambda$lambda$getRules$0, tld)},
	{}
};
$MethodInfo DomainName$Rules$$Lambda$lambda$getRules$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(DomainName$Rules$$Lambda$lambda$getRules$0, init$, void, $String*)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(DomainName$Rules$$Lambda$lambda$getRules$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo DomainName$Rules$$Lambda$lambda$getRules$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.security.util.DomainName$Rules$$Lambda$lambda$getRules$0",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* DomainName$Rules$$Lambda$lambda$getRules$0::load$($String* name, bool initialize) {
	$loadClass(DomainName$Rules$$Lambda$lambda$getRules$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DomainName$Rules$$Lambda$lambda$getRules$0::class$ = nullptr;

$FieldInfo _DomainName$Rules_FieldInfo_[] = {
	{"ruleSets", "Ljava/util/LinkedList;", "Ljava/util/LinkedList<Lsun/security/util/DomainName$Rules$RuleSet;>;", $PRIVATE | $FINAL, $field(DomainName$Rules, ruleSets)},
	{"hasExceptions", "Z", nullptr, $PRIVATE | $FINAL, $field(DomainName$Rules, hasExceptions)},
	{}
};

$MethodInfo _DomainName$Rules_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PRIVATE, $method(DomainName$Rules, init$, void, $InputStream*), "java.io.IOException"},
	{"createRules", "(Ljava/lang/String;)Lsun/security/util/DomainName$Rules;", nullptr, $PRIVATE | $STATIC, $staticMethod(DomainName$Rules, createRules, DomainName$Rules*, $String*)},
	{"getPubSuffixStream", "()Ljava/io/InputStream;", nullptr, $PRIVATE | $STATIC, $staticMethod(DomainName$Rules, getPubSuffixStream, $InputStream*)},
	{"getRuleSet", "(I)Lsun/security/util/DomainName$Rules$RuleSet;", nullptr, $PRIVATE, $method(DomainName$Rules, getRuleSet, $DomainName$Rules$RuleSet*, int32_t)},
	{"getRules", "(Ljava/lang/String;)Lsun/security/util/DomainName$Rules;", nullptr, $STATIC, $staticMethod(DomainName$Rules, getRules, DomainName$Rules*, $String*)},
	{"getRules", "(Ljava/lang/String;Ljava/util/zip/ZipInputStream;)Lsun/security/util/DomainName$Rules;", nullptr, $PRIVATE | $STATIC, $staticMethod(DomainName$Rules, getRules, DomainName$Rules*, $String*, $ZipInputStream*), "java.io.IOException"},
	{"getTopLevelDomain", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(DomainName$Rules, getTopLevelDomain, $String*, $String*)},
	{"lambda$getRules$0", "(Ljava/lang/String;Ljava/lang/String;)Lsun/security/util/DomainName$Rules;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(DomainName$Rules, lambda$getRules$0, DomainName$Rules*, $String*, $String*)},
	{"match", "(Ljava/lang/String;)Lsun/security/util/DomainName$Match;", nullptr, 0, $virtualMethod(DomainName$Rules, match, $DomainName$Match*, $String*)},
	{}
};

$InnerClassInfo _DomainName$Rules_InnerClassesInfo_[] = {
	{"sun.security.util.DomainName$Rules", "sun.security.util.DomainName", "Rules", $PRIVATE | $STATIC},
	{"sun.security.util.DomainName$Rules$RuleSet", "sun.security.util.DomainName$Rules", "RuleSet", $PRIVATE | $STATIC},
	{"sun.security.util.DomainName$Rules$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _DomainName$Rules_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.util.DomainName$Rules",
	"java.lang.Object",
	nullptr,
	_DomainName$Rules_FieldInfo_,
	_DomainName$Rules_MethodInfo_,
	nullptr,
	nullptr,
	_DomainName$Rules_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.util.DomainName"
};

$Object* allocate$DomainName$Rules($Class* clazz) {
	return $of($alloc(DomainName$Rules));
}

void DomainName$Rules::init$($InputStream* is) {
	$useLocalCurrentObjectStackCache();
	$set(this, ruleSets, $new($LinkedList));
	$init($StandardCharsets);
	$var($InputStreamReader, isr, $new($InputStreamReader, is, $StandardCharsets::UTF_8));
	$var($BufferedReader, reader, $new($BufferedReader, isr));
	bool hasExceptions = false;
	$var($String, line, nullptr);
	int32_t type = reader->read();
	while (type != -1 && ($assign(line, reader->readLine())) != nullptr) {
		int32_t numLabels = $DomainName$Rules$RuleSet::numLabels(line);
		if (numLabels != 0) {
			$var($DomainName$Rules$RuleSet, ruleset, getRuleSet(numLabels - 1));
			$nc(ruleset)->addRule(type, line);
			hasExceptions |= ruleset->hasExceptions;
		}
		type = reader->read();
	}
	this->hasExceptions = hasExceptions;
}

DomainName$Rules* DomainName$Rules::getRules($String* domain) {
	$useLocalCurrentObjectStackCache();
	$var($String, tld, getTopLevelDomain(domain));
	if ($nc(tld)->isEmpty()) {
		return nullptr;
	}
	$init($DomainName);
	return $cast(DomainName$Rules, $nc($DomainName::cache)->computeIfAbsent(tld, static_cast<$Function*>($$new(DomainName$Rules$$Lambda$lambda$getRules$0, tld))));
}

$String* DomainName$Rules::getTopLevelDomain($String* domain) {
	int32_t n = $nc(domain)->lastIndexOf((int32_t)u'.');
	if (n == -1) {
		return domain;
	}
	return domain->substring(n + 1);
}

DomainName$Rules* DomainName$Rules::createRules($String* tld) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($InputStream, pubSuffixStream, getPubSuffixStream());
		{
			$var($Throwable, var$0, nullptr);
			$var(DomainName$Rules, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					if (pubSuffixStream == nullptr) {
						$assign(var$2, nullptr);
						return$1 = true;
						goto $finally;
					}
					$assign(var$2, getRules(tld, $$new($ZipInputStream, pubSuffixStream)));
					return$1 = true;
					goto $finally;
				} catch ($Throwable& t$) {
					if (pubSuffixStream != nullptr) {
						try {
							pubSuffixStream->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				if (pubSuffixStream != nullptr) {
					pubSuffixStream->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($IOException& e) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::fine($$str({"cannot parse public suffix data for "_s, tld, ": "_s, $(e->getMessage())}), $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	$shouldNotReachHere();
}

$InputStream* DomainName$Rules::getPubSuffixStream() {
	$load(DomainName$Rules);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($InputStream, is, $cast($InputStream, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($DomainName$Rules$1)))));
	if (is == nullptr) {
		$init($SSLLogger);
		bool var$0 = $SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s);
		if (var$0 && $SSLLogger::isOn("trustmanager"_s)) {
			$SSLLogger::fine("lib/security/public_suffix_list.dat not found"_s, $$new($ObjectArray, 0));
		}
	}
	return is;
}

DomainName$Rules* DomainName$Rules::getRules($String* tld, $ZipInputStream* zis) {
	$useLocalCurrentObjectStackCache();
	bool found = false;
	$var($ZipEntry, ze, $nc(zis)->getNextEntry());
	while (ze != nullptr && !found) {
		if ($nc($(ze->getName()))->equals(tld)) {
			found = true;
		} else {
			$assign(ze, zis->getNextEntry());
		}
	}
	if (!found) {
		$init($SSLLogger);
		if ($SSLLogger::isOn$ && $SSLLogger::isOn("ssl"_s)) {
			$SSLLogger::fine($$str({"Domain "_s, tld, " not found"_s}), $$new($ObjectArray, 0));
		}
		return nullptr;
	}
	return $new(DomainName$Rules, zis);
}

$DomainName$Rules$RuleSet* DomainName$Rules::getRuleSet(int32_t index) {
	if (index < $nc(this->ruleSets)->size()) {
		return $cast($DomainName$Rules$RuleSet, $nc(this->ruleSets)->get(index));
	}
	$var($DomainName$Rules$RuleSet, r, nullptr);
	for (int32_t i = $nc(this->ruleSets)->size(); i <= index; ++i) {
		$assign(r, $new($DomainName$Rules$RuleSet, i + 1));
		$nc(this->ruleSets)->add(r);
	}
	return r;
}

$DomainName$Match* DomainName$Rules::match($String* domain) {
	$useLocalCurrentObjectStackCache();
	$var($DomainName$Match, possibleMatch, nullptr);
	$var($Iterator, it, $nc(this->ruleSets)->descendingIterator());
	while ($nc(it)->hasNext()) {
		$var($DomainName$Rules$RuleSet, ruleSet, $cast($DomainName$Rules$RuleSet, it->next()));
		$var($DomainName$Match, match, $nc(ruleSet)->match(domain));
		if (match != nullptr) {
			$init($DomainName$Rule$Type);
			if (match->type() == $DomainName$Rule$Type::EXCEPTION || !this->hasExceptions) {
				return match;
			}
			if (possibleMatch == nullptr) {
				$assign(possibleMatch, match);
			}
		}
	}
	return possibleMatch;
}

DomainName$Rules* DomainName$Rules::lambda$getRules$0($String* tld, $String* k) {
	return createRules(tld);
}

DomainName$Rules::DomainName$Rules() {
}

$Class* DomainName$Rules::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DomainName$Rules$$Lambda$lambda$getRules$0::classInfo$.name)) {
			return DomainName$Rules$$Lambda$lambda$getRules$0::load$(name, initialize);
		}
	}
	$loadClass(DomainName$Rules, name, initialize, &_DomainName$Rules_ClassInfo_, allocate$DomainName$Rules);
	return class$;
}

$Class* DomainName$Rules::class$ = nullptr;

		} // util
	} // security
} // sun
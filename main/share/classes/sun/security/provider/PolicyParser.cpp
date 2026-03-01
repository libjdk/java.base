#include <sun/security/provider/PolicyParser.h>

#include <java/io/BufferedReader.h>
#include <java/io/BufferedWriter.h>
#include <java/io/File.h>
#include <java/io/FileReader.h>
#include <java/io/FileWriter.h>
#include <java/io/IOException.h>
#include <java/io/PrintWriter.h>
#include <java/io/Reader.h>
#include <java/io/StreamTokenizer.h>
#include <java/io/Writer.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/Date.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/LinkedList.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/StringTokenizer.h>
#include <java/util/TreeMap.h>
#include <java/util/Vector.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <sun/security/provider/PolicyParser$DomainEntry.h>
#include <sun/security/provider/PolicyParser$GrantEntry.h>
#include <sun/security/provider/PolicyParser$KeyStoreEntry.h>
#include <sun/security/provider/PolicyParser$ParsingException.h>
#include <sun/security/provider/PolicyParser$PermissionEntry.h>
#include <sun/security/provider/PolicyParser$PrincipalEntry.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/LocalizedMessage.h>
#include <sun/security/util/PropertyExpander$ExpandException.h>
#include <sun/security/util/PropertyExpander.h>
#include <jcpp.h>

#undef ENGLISH
#undef REPLACE_NAME
#undef TT_EOF
#undef TT_NUMBER
#undef TT_WORD
#undef WILDCARD_CLASS
#undef WILDCARD_NAME

using $BufferedReader = ::java::io::BufferedReader;
using $BufferedWriter = ::java::io::BufferedWriter;
using $File = ::java::io::File;
using $FileReader = ::java::io::FileReader;
using $FileWriter = ::java::io::FileWriter;
using $IOException = ::java::io::IOException;
using $PrintWriter = ::java::io::PrintWriter;
using $Reader = ::java::io::Reader;
using $StreamTokenizer = ::java::io::StreamTokenizer;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $Date = ::java::util::Date;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $LinkedList = ::java::util::LinkedList;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $StringTokenizer = ::java::util::StringTokenizer;
using $TreeMap = ::java::util::TreeMap;
using $Vector = ::java::util::Vector;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $PolicyParser$DomainEntry = ::sun::security::provider::PolicyParser$DomainEntry;
using $PolicyParser$GrantEntry = ::sun::security::provider::PolicyParser$GrantEntry;
using $PolicyParser$KeyStoreEntry = ::sun::security::provider::PolicyParser$KeyStoreEntry;
using $PolicyParser$ParsingException = ::sun::security::provider::PolicyParser$ParsingException;
using $PolicyParser$PermissionEntry = ::sun::security::provider::PolicyParser$PermissionEntry;
using $PolicyParser$PrincipalEntry = ::sun::security::provider::PolicyParser$PrincipalEntry;
using $Debug = ::sun::security::util::Debug;
using $LocalizedMessage = ::sun::security::util::LocalizedMessage;
using $PropertyExpander = ::sun::security::util::PropertyExpander;
using $PropertyExpander$ExpandException = ::sun::security::util::PropertyExpander$ExpandException;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _PolicyParser_FieldInfo_[] = {
	{"grantEntries", "Ljava/util/Vector;", "Ljava/util/Vector<Lsun/security/provider/PolicyParser$GrantEntry;>;", $PRIVATE, $field(PolicyParser, grantEntries)},
	{"domainEntries", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Lsun/security/provider/PolicyParser$DomainEntry;>;", $PRIVATE, $field(PolicyParser, domainEntries)},
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyParser, debug)},
	{"st", "Ljava/io/StreamTokenizer;", nullptr, $PRIVATE, $field(PolicyParser, st)},
	{"lookahead", "I", nullptr, $PRIVATE, $field(PolicyParser, lookahead)},
	{"expandProp", "Z", nullptr, $PRIVATE, $field(PolicyParser, expandProp)},
	{"keyStoreUrlString", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PolicyParser, keyStoreUrlString)},
	{"keyStoreType", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PolicyParser, keyStoreType)},
	{"keyStoreProvider", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PolicyParser, keyStoreProvider)},
	{"storePassURL", "Ljava/lang/String;", nullptr, $PRIVATE, $field(PolicyParser, storePassURL)},
	{}
};

$MethodInfo _PolicyParser_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PolicyParser, init$, void)},
	{"<init>", "(Z)V", nullptr, $PUBLIC, $method(PolicyParser, init$, void, bool)},
	{"add", "(Lsun/security/provider/PolicyParser$GrantEntry;)V", nullptr, $PUBLIC, $virtualMethod(PolicyParser, add, void, $PolicyParser$GrantEntry*)},
	{"expand", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(PolicyParser, expand, $String*, $String*), "sun.security.util.PropertyExpander$ExpandException"},
	{"expand", "(Ljava/lang/String;Z)Ljava/lang/String;", nullptr, $PRIVATE, $method(PolicyParser, expand, $String*, $String*, bool), "sun.security.util.PropertyExpander$ExpandException"},
	{"getDomainEntries", "()Ljava/util/Collection;", "()Ljava/util/Collection<Lsun/security/provider/PolicyParser$DomainEntry;>;", $PUBLIC, $virtualMethod(PolicyParser, getDomainEntries, $Collection*)},
	{"getKeyStoreProvider", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyParser, getKeyStoreProvider, $String*)},
	{"getKeyStoreType", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyParser, getKeyStoreType, $String*)},
	{"getKeyStoreUrl", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyParser, getKeyStoreUrl, $String*)},
	{"getStorePassURL", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(PolicyParser, getStorePassURL, $String*)},
	{"grantElements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Lsun/security/provider/PolicyParser$GrantEntry;>;", $PUBLIC, $virtualMethod(PolicyParser, grantElements, $Enumeration*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(PolicyParser, main, void, $StringArray*), "java.lang.Exception"},
	{"match", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(PolicyParser, match, $String*, $String*), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException"},
	{"parseDomainEntry", "()Lsun/security/provider/PolicyParser$DomainEntry;", nullptr, $PRIVATE, $method(PolicyParser, parseDomainEntry, $PolicyParser$DomainEntry*), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException"},
	{"parseGrantEntry", "()Lsun/security/provider/PolicyParser$GrantEntry;", nullptr, $PRIVATE, $method(PolicyParser, parseGrantEntry, $PolicyParser$GrantEntry*), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException"},
	{"parseKeyStoreEntry", "()V", nullptr, $PRIVATE, $method(PolicyParser, parseKeyStoreEntry, void), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException"},
	{"parsePermissionEntry", "()Lsun/security/provider/PolicyParser$PermissionEntry;", nullptr, $PRIVATE, $method(PolicyParser, parsePermissionEntry, $PolicyParser$PermissionEntry*), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException,sun.security.util.PropertyExpander$ExpandException"},
	{"parseProperties", "(Ljava/lang/String;)Ljava/util/Map;", "(Ljava/lang/String;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE, $method(PolicyParser, parseProperties, $Map*, $String*), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException"},
	{"parseStorePassURL", "()V", nullptr, $PRIVATE, $method(PolicyParser, parseStorePassURL, void), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException"},
	{"peek", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(PolicyParser, peek, bool, $String*)},
	{"peekAndMatch", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(PolicyParser, peekAndMatch, bool, $String*), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException"},
	{"read", "(Ljava/io/Reader;)V", nullptr, $PUBLIC, $virtualMethod(PolicyParser, read, void, $Reader*), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException"},
	{"remove", "(Lsun/security/provider/PolicyParser$GrantEntry;)Z", nullptr, $PUBLIC, $virtualMethod(PolicyParser, remove, bool, $PolicyParser$GrantEntry*)},
	{"replace", "(Lsun/security/provider/PolicyParser$GrantEntry;Lsun/security/provider/PolicyParser$GrantEntry;)V", nullptr, $PUBLIC, $virtualMethod(PolicyParser, replace, void, $PolicyParser$GrantEntry*, $PolicyParser$GrantEntry*)},
	{"setKeyStoreProvider", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PolicyParser, setKeyStoreProvider, void, $String*)},
	{"setKeyStoreType", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PolicyParser, setKeyStoreType, void, $String*)},
	{"setKeyStoreUrl", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PolicyParser, setKeyStoreUrl, void, $String*)},
	{"setStorePassURL", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(PolicyParser, setStorePassURL, void, $String*)},
	{"skipEntry", "()V", nullptr, $PRIVATE, $method(PolicyParser, skipEntry, void), "sun.security.provider.PolicyParser$ParsingException,java.io.IOException"},
	{"write", "(Ljava/io/Writer;)V", nullptr, $PUBLIC, $virtualMethod(PolicyParser, write, void, $Writer*)},
	{"writeKeyStoreEntry", "(Ljava/io/PrintWriter;)V", nullptr, $PRIVATE, $method(PolicyParser, writeKeyStoreEntry, void, $PrintWriter*)},
	{"writeStorePassURL", "(Ljava/io/PrintWriter;)V", nullptr, $PRIVATE, $method(PolicyParser, writeStorePassURL, void, $PrintWriter*)},
	{}
};

$InnerClassInfo _PolicyParser_InnerClassesInfo_[] = {
	{"sun.security.provider.PolicyParser$ParsingException", "sun.security.provider.PolicyParser", "ParsingException", $PUBLIC | $STATIC},
	{"sun.security.provider.PolicyParser$KeyStoreEntry", "sun.security.provider.PolicyParser", "KeyStoreEntry", $STATIC},
	{"sun.security.provider.PolicyParser$DomainEntry", "sun.security.provider.PolicyParser", "DomainEntry", $STATIC},
	{"sun.security.provider.PolicyParser$PermissionEntry", "sun.security.provider.PolicyParser", "PermissionEntry", $PUBLIC | $STATIC},
	{"sun.security.provider.PolicyParser$PrincipalEntry", "sun.security.provider.PolicyParser", "PrincipalEntry", $PUBLIC | $STATIC},
	{"sun.security.provider.PolicyParser$GrantEntry", "sun.security.provider.PolicyParser", "GrantEntry", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _PolicyParser_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.PolicyParser",
	"java.lang.Object",
	nullptr,
	_PolicyParser_FieldInfo_,
	_PolicyParser_MethodInfo_,
	nullptr,
	nullptr,
	_PolicyParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.PolicyParser$ParsingException,sun.security.provider.PolicyParser$KeyStoreEntry,sun.security.provider.PolicyParser$DomainEntry,sun.security.provider.PolicyParser$PermissionEntry,sun.security.provider.PolicyParser$PrincipalEntry,sun.security.provider.PolicyParser$GrantEntry"
};

$Object* allocate$PolicyParser($Class* clazz) {
	return $of($alloc(PolicyParser));
}

$Debug* PolicyParser::debug = nullptr;

$String* PolicyParser::expand($String* value) {
	return expand(value, false);
}

$String* PolicyParser::expand($String* value, bool encodeURL) {
	if (!this->expandProp) {
		return value;
	} else {
		return $PropertyExpander::expand(value, encodeURL);
	}
}

void PolicyParser::init$() {
	this->expandProp = false;
	$set(this, keyStoreUrlString, nullptr);
	$set(this, keyStoreType, nullptr);
	$set(this, keyStoreProvider, nullptr);
	$set(this, storePassURL, nullptr);
	$set(this, grantEntries, $new($Vector));
}

void PolicyParser::init$(bool expandProp) {
	PolicyParser::init$();
	this->expandProp = expandProp;
}

void PolicyParser::read($Reader* policy$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Reader, policy, policy$renamed);
	if (!($instanceOf($BufferedReader, policy))) {
		$assign(policy, $new($BufferedReader, policy));
	}
	$set(this, st, $new($StreamTokenizer, policy));
	$nc(this->st)->resetSyntax();
	$nc(this->st)->wordChars(u'a', u'z');
	$nc(this->st)->wordChars(u'A', u'Z');
	$nc(this->st)->wordChars(u'.', u'.');
	$nc(this->st)->wordChars(u'0', u'9');
	$nc(this->st)->wordChars(u'_', u'_');
	$nc(this->st)->wordChars(u'$', u'$');
	$nc(this->st)->wordChars(128 + 32, 255);
	$nc(this->st)->whitespaceChars(0, u' ');
	$nc(this->st)->commentChar(u'/');
	$nc(this->st)->quoteChar(u'\'');
	$nc(this->st)->quoteChar(u'\"');
	$nc(this->st)->lowerCaseMode(false);
	$nc(this->st)->ordinaryChar(u'/');
	$nc(this->st)->slashSlashComments(true);
	$nc(this->st)->slashStarComments(true);
	this->lookahead = $nc(this->st)->nextToken();
	$var($PolicyParser$GrantEntry, ge, nullptr);
	while (this->lookahead != $StreamTokenizer::TT_EOF) {
		if (peek("grant"_s)) {
			$assign(ge, parseGrantEntry());
			if (ge != nullptr) {
				add(ge);
			}
		} else if (peek("keystore"_s) && this->keyStoreUrlString == nullptr) {
			parseKeyStoreEntry();
		} else if (peek("keystorePasswordURL"_s) && this->storePassURL == nullptr) {
			parseStorePassURL();
		} else if (ge == nullptr && this->keyStoreUrlString == nullptr && this->storePassURL == nullptr && peek("domain"_s)) {
			if (this->domainEntries == nullptr) {
				$set(this, domainEntries, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
			}
			$var($PolicyParser$DomainEntry, de, parseDomainEntry());
			if (de != nullptr) {
				$var($String, domainName, de->getName());
				if (!$nc(this->domainEntries)->containsKey(domainName)) {
					$nc(this->domainEntries)->put(domainName, de);
				} else {
					$var($LocalizedMessage, localizedMsg, $new($LocalizedMessage, "duplicate.keystore.domain.name"_s));
					$var($ObjectArray, source, $new($ObjectArray, {$of(domainName)}));
					$var($String, msg, $str({"duplicate keystore domain name: "_s, domainName}));
					$throwNew($PolicyParser$ParsingException, msg, localizedMsg, source);
				}
			}
		} else {
		}
		match(";"_s);
	}
	if (this->keyStoreUrlString == nullptr && this->storePassURL != nullptr) {
		$throwNew($PolicyParser$ParsingException, $($LocalizedMessage::getNonlocalized("keystorePasswordURL.can.not.be.specified.without.also.specifying.keystore"_s, $$new($ObjectArray, 0))));
	}
}

void PolicyParser::add($PolicyParser$GrantEntry* ge) {
	$nc(this->grantEntries)->addElement(ge);
}

void PolicyParser::replace($PolicyParser$GrantEntry* origGe, $PolicyParser$GrantEntry* newGe) {
	$nc(this->grantEntries)->setElementAt(newGe, $nc(this->grantEntries)->indexOf(origGe));
}

bool PolicyParser::remove($PolicyParser$GrantEntry* ge) {
	return $nc(this->grantEntries)->removeElement(ge);
}

$String* PolicyParser::getKeyStoreUrl() {
	$useLocalCurrentObjectStackCache();
	try {
		if (this->keyStoreUrlString != nullptr && $nc(this->keyStoreUrlString)->length() != 0) {
			$init($File);
			return $nc($(expand(this->keyStoreUrlString, true)))->replace($File::separatorChar, u'/');
		}
	} catch ($PropertyExpander$ExpandException& peee) {
		if (PolicyParser::debug != nullptr) {
			$nc(PolicyParser::debug)->println($(peee->toString()));
		}
		return nullptr;
	}
	return nullptr;
}

void PolicyParser::setKeyStoreUrl($String* url) {
	$set(this, keyStoreUrlString, url);
}

$String* PolicyParser::getKeyStoreType() {
	return this->keyStoreType;
}

void PolicyParser::setKeyStoreType($String* type) {
	$set(this, keyStoreType, type);
}

$String* PolicyParser::getKeyStoreProvider() {
	return this->keyStoreProvider;
}

void PolicyParser::setKeyStoreProvider($String* provider) {
	$set(this, keyStoreProvider, provider);
}

$String* PolicyParser::getStorePassURL() {
	$useLocalCurrentObjectStackCache();
	try {
		if (this->storePassURL != nullptr && $nc(this->storePassURL)->length() != 0) {
			$init($File);
			return $nc($(expand(this->storePassURL, true)))->replace($File::separatorChar, u'/');
		}
	} catch ($PropertyExpander$ExpandException& peee) {
		if (PolicyParser::debug != nullptr) {
			$nc(PolicyParser::debug)->println($(peee->toString()));
		}
		return nullptr;
	}
	return nullptr;
}

void PolicyParser::setStorePassURL($String* storePassURL) {
	$set(this, storePassURL, storePassURL);
}

$Enumeration* PolicyParser::grantElements() {
	return $nc(this->grantEntries)->elements();
}

$Collection* PolicyParser::getDomainEntries() {
	return $nc(this->domainEntries)->values();
}

void PolicyParser::write($Writer* policy) {
	$useLocalCurrentObjectStackCache();
	$var($PrintWriter, out, $new($PrintWriter, static_cast<$Writer*>($$new($BufferedWriter, policy))));
	$var($Enumeration, enum_, grantElements());
	out->println($$str({"/* AUTOMATICALLY GENERATED ON "_s, ($$new($Date)), "*/"_s}));
	out->println("/* DO NOT EDIT */"_s);
	out->println();
	if (this->keyStoreUrlString != nullptr) {
		writeKeyStoreEntry(out);
	}
	if (this->storePassURL != nullptr) {
		writeStorePassURL(out);
	}
	while ($nc(enum_)->hasMoreElements()) {
		$var($PolicyParser$GrantEntry, ge, $cast($PolicyParser$GrantEntry, enum_->nextElement()));
		$nc(ge)->write(out);
		out->println();
	}
	out->flush();
}

void PolicyParser::parseKeyStoreEntry() {
	$useLocalCurrentObjectStackCache();
	match("keystore"_s);
	$set(this, keyStoreUrlString, match("quoted string"_s));
	if (!peek(","_s)) {
		return;
	}
	match(","_s);
	if (peek("\""_s)) {
		$set(this, keyStoreType, match("quoted string"_s));
	} else {
		int32_t var$0 = $nc(this->st)->lineno();
		$throwNew($PolicyParser$ParsingException, var$0, $($LocalizedMessage::getNonlocalized("expected.keystore.type"_s, $$new($ObjectArray, 0))));
	}
	if (!peek(","_s)) {
		return;
	}
	match(","_s);
	if (peek("\""_s)) {
		$set(this, keyStoreProvider, match("quoted string"_s));
	} else {
		int32_t var$1 = $nc(this->st)->lineno();
		$throwNew($PolicyParser$ParsingException, var$1, $($LocalizedMessage::getNonlocalized("expected.keystore.provider"_s, $$new($ObjectArray, 0))));
	}
}

void PolicyParser::parseStorePassURL() {
	match("keyStorePasswordURL"_s);
	$set(this, storePassURL, match("quoted string"_s));
}

void PolicyParser::writeKeyStoreEntry($PrintWriter* out) {
	$useLocalCurrentObjectStackCache();
	$nc(out)->print("keystore \""_s);
	out->print(this->keyStoreUrlString);
	out->print(u'\"');
	if (this->keyStoreType != nullptr && !$nc(this->keyStoreType)->isEmpty()) {
		out->print($$str({", \""_s, this->keyStoreType, "\""_s}));
	}
	if (this->keyStoreProvider != nullptr && !$nc(this->keyStoreProvider)->isEmpty()) {
		out->print($$str({", \""_s, this->keyStoreProvider, "\""_s}));
	}
	out->println(";"_s);
	out->println();
}

void PolicyParser::writeStorePassURL($PrintWriter* out) {
	$nc(out)->print("keystorePasswordURL \""_s);
	out->print(this->storePassURL);
	out->print(u'\"');
	out->println(";"_s);
	out->println();
}

$PolicyParser$GrantEntry* PolicyParser::parseGrantEntry() {
	$useLocalCurrentObjectStackCache();
	$var($PolicyParser$GrantEntry, e, $new($PolicyParser$GrantEntry));
	$var($LinkedList, principals, nullptr);
	bool ignoreEntry = false;
	match("grant"_s);
	while (!peek("{"_s)) {
		if (peekAndMatch("Codebase"_s)) {
			if (e->codeBase != nullptr) {
				int32_t var$0 = $nc(this->st)->lineno();
				$throwNew($PolicyParser$ParsingException, var$0, $($LocalizedMessage::getNonlocalized("multiple.Codebase.expressions"_s, $$new($ObjectArray, 0))));
			}
			$set(e, codeBase, match("quoted string"_s));
			peekAndMatch(","_s);
		} else if (peekAndMatch("SignedBy"_s)) {
			if (e->signedBy != nullptr) {
				int32_t var$1 = $nc(this->st)->lineno();
				$throwNew($PolicyParser$ParsingException, var$1, $($LocalizedMessage::getNonlocalized("multiple.SignedBy.expressions"_s, $$new($ObjectArray, 0))));
			}
			$set(e, signedBy, match("quoted string"_s));
			$var($StringTokenizer, aliases, $new($StringTokenizer, e->signedBy, ","_s, true));
			int32_t actr = 0;
			int32_t cctr = 0;
			while (aliases->hasMoreTokens()) {
				$var($String, alias, $nc($(aliases->nextToken()))->trim());
				if (alias->equals(","_s)) {
					++cctr;
				} else if (!alias->isEmpty()) {
					++actr;
				}
			}
			if (actr <= cctr) {
				int32_t var$2 = $nc(this->st)->lineno();
				$throwNew($PolicyParser$ParsingException, var$2, $($LocalizedMessage::getNonlocalized("SignedBy.has.empty.alias"_s, $$new($ObjectArray, 0))));
			}
			peekAndMatch(","_s);
		} else if (peekAndMatch("Principal"_s)) {
			if (principals == nullptr) {
				$assign(principals, $new($LinkedList));
			}
			$var($String, principalClass, nullptr);
			$var($String, principalName, nullptr);
			if (peek("\""_s)) {
				$init($PolicyParser$PrincipalEntry);
				$assign(principalClass, $PolicyParser$PrincipalEntry::REPLACE_NAME);
				$assign(principalName, match("principal type"_s));
			} else {
				if (peek("*"_s)) {
					match("*"_s);
					$init($PolicyParser$PrincipalEntry);
					$assign(principalClass, $PolicyParser$PrincipalEntry::WILDCARD_CLASS);
				} else {
					$assign(principalClass, match("principal type"_s));
				}
				if (peek("*"_s)) {
					match("*"_s);
					$init($PolicyParser$PrincipalEntry);
					$assign(principalName, $PolicyParser$PrincipalEntry::WILDCARD_NAME);
				} else {
					$assign(principalName, match("quoted string"_s));
				}
				$init($PolicyParser$PrincipalEntry);
				bool var$3 = $nc(principalClass)->equals($PolicyParser$PrincipalEntry::WILDCARD_CLASS);
				if (var$3 && !$nc(principalName)->equals($PolicyParser$PrincipalEntry::WILDCARD_NAME)) {
					if (PolicyParser::debug != nullptr) {
						$nc(PolicyParser::debug)->println("disallowing principal that has WILDCARD class but no WILDCARD name"_s);
					}
					int32_t var$4 = $nc(this->st)->lineno();
					$throwNew($PolicyParser$ParsingException, var$4, $($LocalizedMessage::getNonlocalized("can.not.specify.Principal.with.a.wildcard.class.without.a.wildcard.name"_s, $$new($ObjectArray, 0))));
				}
			}
			try {
				$assign(principalName, expand(principalName));
				bool var$5 = $nc(principalClass)->equals("javax.security.auth.x500.X500Principal"_s);
				$init($PolicyParser$PrincipalEntry);
				if (var$5 && !$nc(principalName)->equals($PolicyParser$PrincipalEntry::WILDCARD_NAME)) {
					$var($X500Principal, p, $new($X500Principal, $(($$new($X500Principal, principalName))->toString())));
					$assign(principalName, p->getName());
				}
				$nc(principals)->add($$new($PolicyParser$PrincipalEntry, principalClass, principalName));
			} catch ($PropertyExpander$ExpandException& peee) {
				if (PolicyParser::debug != nullptr) {
					$nc(PolicyParser::debug)->println($$str({"principal name expansion failed: "_s, principalName}));
				}
				ignoreEntry = true;
			}
			peekAndMatch(","_s);
		} else {
			int32_t var$6 = $nc(this->st)->lineno();
			$throwNew($PolicyParser$ParsingException, var$6, $($LocalizedMessage::getNonlocalized("expected.codeBase.or.SignedBy.or.Principal"_s, $$new($ObjectArray, 0))));
		}
	}
	if (principals != nullptr) {
		$set(e, principals, principals);
	}
	match("{"_s);
	while (!peek("}"_s)) {
		if (peek("Permission"_s)) {
			try {
				$var($PolicyParser$PermissionEntry, pe, parsePermissionEntry());
				e->add(pe);
			} catch ($PropertyExpander$ExpandException& peee) {
				if (PolicyParser::debug != nullptr) {
					$nc(PolicyParser::debug)->println($(peee->toString()));
				}
				skipEntry();
			}
			match(";"_s);
		} else {
			int32_t var$7 = $nc(this->st)->lineno();
			$throwNew($PolicyParser$ParsingException, var$7, $($LocalizedMessage::getNonlocalized("expected.permission.entry"_s, $$new($ObjectArray, 0))));
		}
	}
	match("}"_s);
	try {
		if (e->signedBy != nullptr) {
			$set(e, signedBy, expand(e->signedBy));
		}
		if (e->codeBase != nullptr) {
			$init($File);
			$set(e, codeBase, $nc($(expand(e->codeBase, true)))->replace($File::separatorChar, u'/'));
		}
	} catch ($PropertyExpander$ExpandException& peee) {
		if (PolicyParser::debug != nullptr) {
			$nc(PolicyParser::debug)->println($(peee->toString()));
		}
		return nullptr;
	}
	return (ignoreEntry == true) ? ($PolicyParser$GrantEntry*)nullptr : e;
}

$PolicyParser$PermissionEntry* PolicyParser::parsePermissionEntry() {
	$useLocalCurrentObjectStackCache();
	$var($PolicyParser$PermissionEntry, e, $new($PolicyParser$PermissionEntry));
	match("Permission"_s);
	$set(e, permission, match("permission type"_s));
	if (peek("\""_s)) {
		$set(e, name, expand($(match("quoted string"_s))));
	}
	if (!peek(","_s)) {
		return e;
	}
	match(","_s);
	if (peek("\""_s)) {
		$set(e, action, expand($(match("quoted string"_s))));
		if (!peek(","_s)) {
			return e;
		}
		match(","_s);
	}
	if (peekAndMatch("SignedBy"_s)) {
		$set(e, signedBy, expand($(match("quoted string"_s))));
	}
	return e;
}

$PolicyParser$DomainEntry* PolicyParser::parseDomainEntry() {
	$useLocalCurrentObjectStackCache();
	bool ignoreEntry = false;
	$var($PolicyParser$DomainEntry, domainEntry, nullptr);
	$var($String, name, nullptr);
	$var($Map, properties, $new($HashMap));
	match("domain"_s);
	$assign(name, match("domain name"_s));
	while (!peek("{"_s)) {
		$assign(properties, parseProperties("{"_s));
	}
	match("{"_s);
	$assign(domainEntry, $new($PolicyParser$DomainEntry, name, properties));
	while (!peek("}"_s)) {
		match("keystore"_s);
		$assign(name, match("keystore name"_s));
		if (!peek("}"_s)) {
			$assign(properties, parseProperties(";"_s));
		}
		match(";"_s);
		domainEntry->add($$new($PolicyParser$KeyStoreEntry, name, properties));
	}
	match("}"_s);
	return (ignoreEntry == true) ? ($PolicyParser$DomainEntry*)nullptr : domainEntry;
}

$Map* PolicyParser::parseProperties($String* terminator) {
	$useLocalCurrentObjectStackCache();
	$var($Map, properties, $new($HashMap));
	$var($String, key, nullptr);
	$var($String, value, nullptr);
	while (!peek(terminator)) {
		$assign(key, match("property name"_s));
		match("="_s);
		try {
			$assign(value, expand($(match("quoted string"_s))));
		} catch ($PropertyExpander$ExpandException& peee) {
			$throwNew($IOException, $(peee->getLocalizedMessage()));
		}
		$init($Locale);
		properties->put($($nc(key)->toLowerCase($Locale::ENGLISH)), value);
	}
	return properties;
}

bool PolicyParser::peekAndMatch($String* expect) {
	if (peek(expect)) {
		match(expect);
		return true;
	} else {
		return false;
	}
}

bool PolicyParser::peek($String* expect) {
	bool found = false;
	switch (this->lookahead) {
	case $StreamTokenizer::TT_WORD:
		{
			if ($nc(expect)->equalsIgnoreCase($nc(this->st)->sval)) {
				found = true;
			}
			break;
		}
	case u',':
		{
			if ($nc(expect)->equalsIgnoreCase(","_s)) {
				found = true;
			}
			break;
		}
	case u'{':
		{
			if ($nc(expect)->equalsIgnoreCase("{"_s)) {
				found = true;
			}
			break;
		}
	case u'}':
		{
			if ($nc(expect)->equalsIgnoreCase("}"_s)) {
				found = true;
			}
			break;
		}
	case u'\"':
		{
			if ($nc(expect)->equalsIgnoreCase("\""_s)) {
				found = true;
			}
			break;
		}
	case u'*':
		{
			if ($nc(expect)->equalsIgnoreCase("*"_s)) {
				found = true;
			}
			break;
		}
	case u';':
		{
			if ($nc(expect)->equalsIgnoreCase(";"_s)) {
				found = true;
			}
			break;
		}
	default:
		{}
	}
	return found;
}

$String* PolicyParser::match($String* expect) {
	$useLocalCurrentObjectStackCache();
	$var($String, value, nullptr);
	{
		$var($LocalizedMessage, localizedMsg, nullptr)
		$var($ObjectArray, source, nullptr)
		$var($String, msg, nullptr)
		switch (this->lookahead) {
		case $StreamTokenizer::TT_NUMBER:
			{
				int32_t var$0 = $nc(this->st)->lineno();
				$var($String, var$1, expect);
				$var($String, var$2, $($LocalizedMessage::getNonlocalized("number."_s, $$new($ObjectArray, 0))));
				$throwNew($PolicyParser$ParsingException, var$0, var$1, $$concat(var$2, $($String::valueOf($nc(this->st)->nval))));
			}
		case $StreamTokenizer::TT_EOF:
			{
				$assign(localizedMsg, $new($LocalizedMessage, "expected.expect.read.end.of.file."_s));
				$assign(source, $new($ObjectArray, {$of(expect)}));
				$assign(msg, $str({"expected ["_s, expect, "], read [end of file]"_s}));
				$throwNew($PolicyParser$ParsingException, msg, localizedMsg, source);
			}
		case $StreamTokenizer::TT_WORD:
			{
				if ($nc(expect)->equalsIgnoreCase($nc(this->st)->sval)) {
					this->lookahead = $nc(this->st)->nextToken();
				} else if (expect->equalsIgnoreCase("permission type"_s)) {
					$assign(value, $nc(this->st)->sval);
					this->lookahead = $nc(this->st)->nextToken();
				} else if (expect->equalsIgnoreCase("principal type"_s)) {
					$assign(value, $nc(this->st)->sval);
					this->lookahead = $nc(this->st)->nextToken();
				} else {
					bool var$6 = expect->equalsIgnoreCase("domain name"_s);
					bool var$5 = var$6 || expect->equalsIgnoreCase("keystore name"_s);
					if (var$5 || expect->equalsIgnoreCase("property name"_s)) {
						$assign(value, $nc(this->st)->sval);
						this->lookahead = $nc(this->st)->nextToken();
					} else {
						$throwNew($PolicyParser$ParsingException, $nc(this->st)->lineno(), expect, $nc(this->st)->sval);
					}
				}
				break;
			}
		case u'\"':
			{
				if ($nc(expect)->equalsIgnoreCase("quoted string"_s)) {
					$assign(value, $nc(this->st)->sval);
					this->lookahead = $nc(this->st)->nextToken();
				} else if (expect->equalsIgnoreCase("permission type"_s)) {
					$assign(value, $nc(this->st)->sval);
					this->lookahead = $nc(this->st)->nextToken();
				} else if (expect->equalsIgnoreCase("principal type"_s)) {
					$assign(value, $nc(this->st)->sval);
					this->lookahead = $nc(this->st)->nextToken();
				} else {
					$throwNew($PolicyParser$ParsingException, $nc(this->st)->lineno(), expect, $nc(this->st)->sval);
				}
				break;
			}
		case u',':
			{
				if ($nc(expect)->equalsIgnoreCase(","_s)) {
					this->lookahead = $nc(this->st)->nextToken();
				} else {
					$throwNew($PolicyParser$ParsingException, $nc(this->st)->lineno(), expect, ","_s);
				}
				break;
			}
		case u'{':
			{
				if ($nc(expect)->equalsIgnoreCase("{"_s)) {
					this->lookahead = $nc(this->st)->nextToken();
				} else {
					$throwNew($PolicyParser$ParsingException, $nc(this->st)->lineno(), expect, "{"_s);
				}
				break;
			}
		case u'}':
			{
				if ($nc(expect)->equalsIgnoreCase("}"_s)) {
					this->lookahead = $nc(this->st)->nextToken();
				} else {
					$throwNew($PolicyParser$ParsingException, $nc(this->st)->lineno(), expect, "}"_s);
				}
				break;
			}
		case u';':
			{
				if ($nc(expect)->equalsIgnoreCase(";"_s)) {
					this->lookahead = $nc(this->st)->nextToken();
				} else {
					$throwNew($PolicyParser$ParsingException, $nc(this->st)->lineno(), expect, ";"_s);
				}
				break;
			}
		case u'*':
			{
				if ($nc(expect)->equalsIgnoreCase("*"_s)) {
					this->lookahead = $nc(this->st)->nextToken();
				} else {
					$throwNew($PolicyParser$ParsingException, $nc(this->st)->lineno(), expect, "*"_s);
				}
				break;
			}
		case u'=':
			{
				if ($nc(expect)->equalsIgnoreCase("="_s)) {
					this->lookahead = $nc(this->st)->nextToken();
				} else {
					$throwNew($PolicyParser$ParsingException, $nc(this->st)->lineno(), expect, "="_s);
				}
				break;
			}
		default:
			{
				int32_t var$7 = $nc(this->st)->lineno();
				$var($String, var$8, expect);
				$throwNew($PolicyParser$ParsingException, var$7, var$8, $($String::valueOf((char16_t)this->lookahead)));
			}
		}
	}
	return value;
}

void PolicyParser::skipEntry() {
	$useLocalCurrentObjectStackCache();
	while (this->lookahead != u';') {
		switch (this->lookahead) {
		case $StreamTokenizer::TT_NUMBER:
			{
				int32_t var$0 = $nc(this->st)->lineno();
				$var($String, var$1, ";"_s);
				$var($String, var$2, $($LocalizedMessage::getNonlocalized("number."_s, $$new($ObjectArray, 0))));
				$throwNew($PolicyParser$ParsingException, var$0, var$1, $$concat(var$2, $($String::valueOf($nc(this->st)->nval))));
			}
		case $StreamTokenizer::TT_EOF:
			{
				$throwNew($PolicyParser$ParsingException, $($LocalizedMessage::getNonlocalized("expected.read.end.of.file."_s, $$new($ObjectArray, 0))));
			}
		default:
			{
				this->lookahead = $nc(this->st)->nextToken();
			}
		}
	}
}

void PolicyParser::main($StringArray* arg) {
	$init(PolicyParser);
	$useLocalCurrentObjectStackCache();
	{
		$var($FileReader, fr, $new($FileReader, $nc(arg)->get(0)));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($FileWriter, fw, $new($FileWriter, $nc(arg)->get(1)));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								$var(PolicyParser, pp, $new(PolicyParser, true));
								pp->read(fr);
								pp->write(fw);
							} catch ($Throwable& t$) {
								try {
									fw->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$2) {
							$assign(var$1, var$2);
						} /*finally*/ {
							fw->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					try {
						fr->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				fr->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void clinit$PolicyParser($Class* class$) {
	$assignStatic(PolicyParser::debug, $Debug::getInstance("parser"_s, "\t[Policy Parser]"_s));
}

PolicyParser::PolicyParser() {
}

$Class* PolicyParser::load$($String* name, bool initialize) {
	$loadClass(PolicyParser, name, initialize, &_PolicyParser_ClassInfo_, clinit$PolicyParser, allocate$PolicyParser);
	return class$;
}

$Class* PolicyParser::class$ = nullptr;

		} // provider
	} // security
} // sun
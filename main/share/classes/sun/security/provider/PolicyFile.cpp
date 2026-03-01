#include <sun/security/provider/PolicyFile.h>

#include <java/io/BufferedReader.h>
#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/net/MalformedURLException.h>
#include <java/net/NetPermission.h>
#include <java/net/SocketPermission.h>
#include <java/net/URL.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/nio/file/FileSystem.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/Path.h>
#include <java/security/AccessController.h>
#include <java/security/AllPermission.h>
#include <java/security/CodeSource.h>
#include <java/security/KeyStore.h>
#include <java/security/KeyStoreException.h>
#include <java/security/Permission.h>
#include <java/security/PermissionCollection.h>
#include <java/security/Permissions.h>
#include <java/security/Policy.h>
#include <java/security/Principal.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/security/SecurityPermission.h>
#include <java/security/UnresolvedPermission.h>
#include <java/security/cert/Certificate.h>
#include <java/security/cert/X509Certificate.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSequentialList.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/PropertyPermission.h>
#include <java/util/Set.h>
#include <java/util/StringTokenizer.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <javax/security/auth/Subject.h>
#include <javax/security/auth/x500/X500Principal.h>
#include <jdk/internal/access/JavaSecurityAccess$ProtectionDomainCache.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/nio/fs/DefaultFileSystemProvider.h>
#include <sun/security/provider/PolicyFile$1.h>
#include <sun/security/provider/PolicyFile$2.h>
#include <sun/security/provider/PolicyFile$3.h>
#include <sun/security/provider/PolicyFile$4.h>
#include <sun/security/provider/PolicyFile$5.h>
#include <sun/security/provider/PolicyFile$6.h>
#include <sun/security/provider/PolicyFile$7.h>
#include <sun/security/provider/PolicyFile$8.h>
#include <sun/security/provider/PolicyFile$PolicyEntry.h>
#include <sun/security/provider/PolicyFile$PolicyInfo.h>
#include <sun/security/provider/PolicyFile$SelfPermission.h>
#include <sun/security/provider/PolicyParser$GrantEntry.h>
#include <sun/security/provider/PolicyParser$ParsingException.h>
#include <sun/security/provider/PolicyParser$PermissionEntry.h>
#include <sun/security/provider/PolicyParser$PrincipalEntry.h>
#include <sun/security/provider/PolicyParser.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/FilePermCompat.h>
#include <sun/security/util/LocalizedMessage.h>
#include <sun/security/util/PolicyUtil.h>
#include <sun/security/util/SecurityConstants.h>
#include <jcpp.h>

#undef ALL_PERMISSION
#undef DEFAULT_CACHE_SIZE
#undef EMPTY_SET
#undef PARAMS0
#undef PARAMS1
#undef PARAMS2
#undef POLICY
#undef POLICY_URL
#undef SELF
#undef UTF_8
#undef X500PRINCIPAL

using $PrincipalArray = $Array<::java::security::Principal>;
using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $StringArray2 = $Array<::java::lang::String, 2>;
using $BufferedReader = ::java::io::BufferedReader;
using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $Boolean = ::java::lang::Boolean;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $Constructor = ::java::lang::reflect::Constructor;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $MalformedURLException = ::java::net::MalformedURLException;
using $NetPermission = ::java::net::NetPermission;
using $SocketPermission = ::java::net::SocketPermission;
using $URL = ::java::net::URL;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $FileSystem = ::java::nio::file::FileSystem;
using $Files = ::java::nio::file::Files;
using $Path = ::java::nio::file::Path;
using $AccessController = ::java::security::AccessController;
using $AllPermission = ::java::security::AllPermission;
using $CodeSource = ::java::security::CodeSource;
using $KeyStore = ::java::security::KeyStore;
using $KeyStoreException = ::java::security::KeyStoreException;
using $Permission = ::java::security::Permission;
using $PermissionCollection = ::java::security::PermissionCollection;
using $Permissions = ::java::security::Permissions;
using $Policy = ::java::security::Policy;
using $Principal = ::java::security::Principal;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $SecurityPermission = ::java::security::SecurityPermission;
using $UnresolvedPermission = ::java::security::UnresolvedPermission;
using $Certificate = ::java::security::cert::Certificate;
using $X509Certificate = ::java::security::cert::X509Certificate;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $PropertyPermission = ::java::util::PropertyPermission;
using $Set = ::java::util::Set;
using $StringTokenizer = ::java::util::StringTokenizer;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $Subject = ::javax::security::auth::Subject;
using $X500Principal = ::javax::security::auth::x500::X500Principal;
using $JavaSecurityAccess$ProtectionDomainCache = ::jdk::internal::access::JavaSecurityAccess$ProtectionDomainCache;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $DefaultFileSystemProvider = ::sun::nio::fs::DefaultFileSystemProvider;
using $PolicyFile$1 = ::sun::security::provider::PolicyFile$1;
using $PolicyFile$2 = ::sun::security::provider::PolicyFile$2;
using $PolicyFile$3 = ::sun::security::provider::PolicyFile$3;
using $PolicyFile$4 = ::sun::security::provider::PolicyFile$4;
using $PolicyFile$5 = ::sun::security::provider::PolicyFile$5;
using $PolicyFile$6 = ::sun::security::provider::PolicyFile$6;
using $PolicyFile$7 = ::sun::security::provider::PolicyFile$7;
using $PolicyFile$8 = ::sun::security::provider::PolicyFile$8;
using $PolicyFile$PolicyEntry = ::sun::security::provider::PolicyFile$PolicyEntry;
using $PolicyFile$PolicyInfo = ::sun::security::provider::PolicyFile$PolicyInfo;
using $PolicyFile$SelfPermission = ::sun::security::provider::PolicyFile$SelfPermission;
using $PolicyParser = ::sun::security::provider::PolicyParser;
using $PolicyParser$GrantEntry = ::sun::security::provider::PolicyParser$GrantEntry;
using $PolicyParser$ParsingException = ::sun::security::provider::PolicyParser$ParsingException;
using $PolicyParser$PermissionEntry = ::sun::security::provider::PolicyParser$PermissionEntry;
using $PolicyParser$PrincipalEntry = ::sun::security::provider::PolicyParser$PrincipalEntry;
using $Debug = ::sun::security::util::Debug;
using $FilePermCompat = ::sun::security::util::FilePermCompat;
using $LocalizedMessage = ::sun::security::util::LocalizedMessage;
using $PolicyUtil = ::sun::security::util::PolicyUtil;
using $SecurityConstants = ::sun::security::util::SecurityConstants;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _PolicyFile_FieldInfo_[] = {
	{"debug", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyFile, debug)},
	{"SELF", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyFile, SELF)},
	{"X500PRINCIPAL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyFile, X500PRINCIPAL)},
	{"POLICY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyFile, POLICY)},
	{"POLICY_URL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyFile, POLICY_URL)},
	{"DEFAULT_CACHE_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(PolicyFile, DEFAULT_CACHE_SIZE)},
	{"policyInfo", "Lsun/security/provider/PolicyFile$PolicyInfo;", nullptr, $PRIVATE | $VOLATILE, $field(PolicyFile, policyInfo)},
	{"expandProperties", "Z", nullptr, $PRIVATE, $field(PolicyFile, expandProperties)},
	{"allowSystemProperties", "Z", nullptr, $PRIVATE, $field(PolicyFile, allowSystemProperties)},
	{"notUtf8", "Z", nullptr, $PRIVATE, $field(PolicyFile, notUtf8)},
	{"url", "Ljava/net/URL;", nullptr, $PRIVATE, $field(PolicyFile, url)},
	{"PARAMS0", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(PolicyFile, PARAMS0)},
	{"PARAMS1", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(PolicyFile, PARAMS1)},
	{"PARAMS2", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(PolicyFile, PARAMS2)},
	{"badPolicyURLs", "Ljava/util/Set;", "Ljava/util/Set<Ljava/net/URL;>;", $PRIVATE | $STATIC, $staticField(PolicyFile, badPolicyURLs)},
	{"builtInFS", "Ljava/nio/file/FileSystem;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(PolicyFile, builtInFS)},
	{}
};

$MethodInfo _PolicyFile_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(PolicyFile, init$, void)},
	{"<init>", "(Ljava/net/URL;)V", nullptr, $PUBLIC, $method(PolicyFile, init$, void, $URL*)},
	{"addGrantEntry", "(Lsun/security/provider/PolicyParser$GrantEntry;Ljava/security/KeyStore;Lsun/security/provider/PolicyFile$PolicyInfo;)V", nullptr, $PRIVATE, $method(PolicyFile, addGrantEntry, void, $PolicyParser$GrantEntry*, $KeyStore*, $PolicyFile$PolicyInfo*)},
	{"addPermissions", "(Ljava/security/Permissions;Ljava/security/CodeSource;[Ljava/security/Principal;Lsun/security/provider/PolicyFile$PolicyEntry;)V", nullptr, $PRIVATE, $method(PolicyFile, addPermissions, void, $Permissions*, $CodeSource*, $PrincipalArray*, $PolicyFile$PolicyEntry*)},
	{"addPerms", "(Ljava/security/Permissions;[Ljava/security/Principal;Lsun/security/provider/PolicyFile$PolicyEntry;)V", nullptr, $PRIVATE, $method(PolicyFile, addPerms, void, $Permissions*, $PrincipalArray*, $PolicyFile$PolicyEntry*)},
	{"canonPath", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(PolicyFile, canonPath, $String*, $String*), "java.io.IOException"},
	{"canonicalizeCodebase", "(Ljava/security/CodeSource;Z)Ljava/security/CodeSource;", nullptr, $PRIVATE, $method(PolicyFile, canonicalizeCodebase, $CodeSource*, $CodeSource*, bool)},
	{"expandPermissionName", "(Lsun/security/provider/PolicyParser$PermissionEntry;Ljava/security/KeyStore;)V", nullptr, $PRIVATE, $method(PolicyFile, expandPermissionName, void, $PolicyParser$PermissionEntry*, $KeyStore*), "java.lang.Exception"},
	{"expandSelf", "(Lsun/security/provider/PolicyFile$SelfPermission;Ljava/util/List;[Ljava/security/Principal;Ljava/security/Permissions;)V", "(Lsun/security/provider/PolicyFile$SelfPermission;Ljava/util/List<Lsun/security/provider/PolicyParser$PrincipalEntry;>;[Ljava/security/Principal;Ljava/security/Permissions;)V", $PRIVATE, $method(PolicyFile, expandSelf, void, $PolicyFile$SelfPermission*, $List*, $PrincipalArray*, $Permissions*)},
	{"getCertificates", "(Ljava/security/KeyStore;Ljava/lang/String;Lsun/security/provider/PolicyFile$PolicyInfo;)[Ljava/security/cert/Certificate;", nullptr, $PRIVATE, $method(PolicyFile, getCertificates, $CertificateArray*, $KeyStore*, $String*, $PolicyFile$PolicyInfo*)},
	{"getCodeSource", "(Lsun/security/provider/PolicyParser$GrantEntry;Ljava/security/KeyStore;Lsun/security/provider/PolicyFile$PolicyInfo;)Ljava/security/CodeSource;", nullptr, $PRIVATE, $method(PolicyFile, getCodeSource, $CodeSource*, $PolicyParser$GrantEntry*, $KeyStore*, $PolicyFile$PolicyInfo*), "java.net.MalformedURLException"},
	{"getDN", "(Ljava/lang/String;Ljava/security/KeyStore;)Ljava/lang/String;", nullptr, $PRIVATE, $method(PolicyFile, getDN, $String*, $String*, $KeyStore*)},
	{"getInputStreamReader", "(Ljava/io/InputStream;)Ljava/io/InputStreamReader;", nullptr, $PRIVATE, $method(PolicyFile, getInputStreamReader, $InputStreamReader*, $InputStream*)},
	{"getInstance", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/security/Permission;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticMethod(PolicyFile, getInstance, $Permission*, $String*, $String*, $String*), "java.lang.ClassNotFoundException,java.lang.InstantiationException,java.lang.IllegalAccessException,java.lang.NoSuchMethodException,java.lang.reflect.InvocationTargetException"},
	{"getKnownPermission", "(Ljava/lang/Class;Ljava/lang/String;Ljava/lang/String;)Ljava/security/Permission;", "(Ljava/lang/Class<*>;Ljava/lang/String;Ljava/lang/String;)Ljava/security/Permission;", $PRIVATE | $STATIC, $staticMethod(PolicyFile, getKnownPermission, $Permission*, $Class*, $String*, $String*)},
	{"getKnownPrincipal", "(Ljava/lang/Class;Ljava/lang/String;)Ljava/security/Principal;", "(Ljava/lang/Class<*>;Ljava/lang/String;)Ljava/security/Principal;", $PRIVATE | $STATIC, $staticMethod(PolicyFile, getKnownPrincipal, $Principal*, $Class*, $String*)},
	{"getPermissions", "(Ljava/security/ProtectionDomain;)Ljava/security/PermissionCollection;", nullptr, $PUBLIC, $virtualMethod(PolicyFile, getPermissions, $PermissionCollection*, $ProtectionDomain*)},
	{"getPermissions", "(Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PUBLIC, $virtualMethod(PolicyFile, getPermissions, $PermissionCollection*, $CodeSource*)},
	{"getPermissions", "(Ljava/security/Permissions;Ljava/security/ProtectionDomain;)Ljava/security/PermissionCollection;", nullptr, $PRIVATE, $method(PolicyFile, getPermissions, $PermissionCollection*, $Permissions*, $ProtectionDomain*)},
	{"getPermissions", "(Ljava/security/Permissions;Ljava/security/CodeSource;)Ljava/security/PermissionCollection;", nullptr, $PRIVATE, $method(PolicyFile, getPermissions, $PermissionCollection*, $Permissions*, $CodeSource*)},
	{"getPermissions", "(Ljava/security/Permissions;Ljava/security/CodeSource;[Ljava/security/Principal;)Ljava/security/Permissions;", nullptr, $PRIVATE, $method(PolicyFile, getPermissions, $Permissions*, $Permissions*, $CodeSource*, $PrincipalArray*)},
	{"getPrincipalInfo", "(Lsun/security/provider/PolicyParser$PrincipalEntry;[Ljava/security/Principal;)[[Ljava/lang/String;", nullptr, $PRIVATE, $method(PolicyFile, getPrincipalInfo, $StringArray2*, $PolicyParser$PrincipalEntry*, $PrincipalArray*)},
	{"getSignerCertificates", "(Ljava/security/CodeSource;)[Ljava/security/cert/Certificate;", nullptr, $PROTECTED, $virtualMethod(PolicyFile, getSignerCertificates, $CertificateArray*, $CodeSource*)},
	{"implies", "(Ljava/security/ProtectionDomain;Ljava/security/Permission;)Z", nullptr, $PUBLIC, $virtualMethod(PolicyFile, implies, bool, $ProtectionDomain*, $Permission*)},
	{"init", "(Ljava/net/URL;)V", nullptr, $PRIVATE, $method(PolicyFile, init, void, $URL*)},
	{"init", "(Ljava/net/URL;Lsun/security/provider/PolicyFile$PolicyInfo;)Z", nullptr, $PRIVATE, $method(PolicyFile, init, bool, $URL*, $PolicyFile$PolicyInfo*)},
	{"initDefaultPolicy", "(Lsun/security/provider/PolicyFile$PolicyInfo;)V", nullptr, $PRIVATE, $method(PolicyFile, initDefaultPolicy, void, $PolicyFile$PolicyInfo*)},
	{"initPolicyFile", "(Lsun/security/provider/PolicyFile$PolicyInfo;Ljava/net/URL;)V", nullptr, $PRIVATE, $method(PolicyFile, initPolicyFile, void, $PolicyFile$PolicyInfo*, $URL*)},
	{"initPolicyFile", "(Ljava/lang/String;Ljava/lang/String;Lsun/security/provider/PolicyFile$PolicyInfo;)Z", nullptr, $PRIVATE, $method(PolicyFile, initPolicyFile, bool, $String*, $String*, $PolicyFile$PolicyInfo*)},
	{"initStaticPolicy", "(Lsun/security/provider/PolicyFile$PolicyInfo;)V", nullptr, $PRIVATE, $method(PolicyFile, initStaticPolicy, void, $PolicyFile$PolicyInfo*)},
	{"printPD", "(Ljava/security/ProtectionDomain;)Ljava/lang/String;", nullptr, $PRIVATE, $method(PolicyFile, printPD, $String*, $ProtectionDomain*)},
	{"refresh", "()V", nullptr, $PUBLIC, $virtualMethod(PolicyFile, refresh, void)},
	{"replacePrincipals", "(Ljava/util/List;Ljava/security/KeyStore;)Z", "(Ljava/util/List<Lsun/security/provider/PolicyParser$PrincipalEntry;>;Ljava/security/KeyStore;)Z", $PRIVATE, $method(PolicyFile, replacePrincipals, bool, $List*, $KeyStore*)},
	{"wildcardPrincipalNameImplies", "(Ljava/lang/String;[Ljava/security/Principal;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(PolicyFile, wildcardPrincipalNameImplies, bool, $String*, $PrincipalArray*)},
	{}
};

$InnerClassInfo _PolicyFile_InnerClassesInfo_[] = {
	{"sun.security.provider.PolicyFile$PolicyInfo", "sun.security.provider.PolicyFile", "PolicyInfo", $PRIVATE | $STATIC},
	{"sun.security.provider.PolicyFile$SelfPermission", "sun.security.provider.PolicyFile", "SelfPermission", $PRIVATE | $STATIC},
	{"sun.security.provider.PolicyFile$PolicyEntry", "sun.security.provider.PolicyFile", "PolicyEntry", $PRIVATE | $STATIC},
	{"sun.security.provider.PolicyFile$8", nullptr, nullptr, 0},
	{"sun.security.provider.PolicyFile$7", nullptr, nullptr, 0},
	{"sun.security.provider.PolicyFile$6", nullptr, nullptr, 0},
	{"sun.security.provider.PolicyFile$5", nullptr, nullptr, 0},
	{"sun.security.provider.PolicyFile$4", nullptr, nullptr, 0},
	{"sun.security.provider.PolicyFile$3", nullptr, nullptr, 0},
	{"sun.security.provider.PolicyFile$2", nullptr, nullptr, 0},
	{"sun.security.provider.PolicyFile$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _PolicyFile_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.provider.PolicyFile",
	"java.security.Policy",
	nullptr,
	_PolicyFile_FieldInfo_,
	_PolicyFile_MethodInfo_,
	nullptr,
	nullptr,
	_PolicyFile_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.security.provider.PolicyFile$PolicyInfo,sun.security.provider.PolicyFile$SelfPermission,sun.security.provider.PolicyFile$PolicyEntry,sun.security.provider.PolicyFile$8,sun.security.provider.PolicyFile$7,sun.security.provider.PolicyFile$6,sun.security.provider.PolicyFile$5,sun.security.provider.PolicyFile$4,sun.security.provider.PolicyFile$3,sun.security.provider.PolicyFile$2,sun.security.provider.PolicyFile$1"
};

$Object* allocate$PolicyFile($Class* clazz) {
	return $of($alloc(PolicyFile));
}

$Debug* PolicyFile::debug = nullptr;
$String* PolicyFile::SELF = nullptr;
$String* PolicyFile::X500PRINCIPAL = nullptr;
$String* PolicyFile::POLICY = nullptr;
$String* PolicyFile::POLICY_URL = nullptr;
$ClassArray* PolicyFile::PARAMS0 = nullptr;
$ClassArray* PolicyFile::PARAMS1 = nullptr;
$ClassArray* PolicyFile::PARAMS2 = nullptr;
$Set* PolicyFile::badPolicyURLs = nullptr;
$FileSystem* PolicyFile::builtInFS = nullptr;

void PolicyFile::init$() {
	$Policy::init$();
	this->expandProperties = true;
	this->allowSystemProperties = true;
	this->notUtf8 = false;
	init(($URL*)nullptr);
}

void PolicyFile::init$($URL* url) {
	$Policy::init$();
	this->expandProperties = true;
	this->allowSystemProperties = true;
	this->notUtf8 = false;
	$set(this, url, url);
	init(url);
}

void PolicyFile::init($URL* url) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, numCacheStr, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PolicyFile$1, this)))));
	int32_t numCaches = 0;
	if (numCacheStr != nullptr) {
		try {
			numCaches = $Integer::parseInt(numCacheStr);
		} catch ($NumberFormatException& e) {
			numCaches = PolicyFile::DEFAULT_CACHE_SIZE;
		}
	} else {
		numCaches = PolicyFile::DEFAULT_CACHE_SIZE;
	}
	$var($PolicyFile$PolicyInfo, newInfo, $new($PolicyFile$PolicyInfo, numCaches));
	initPolicyFile(newInfo, url);
	$set(this, policyInfo, newInfo);
}

void PolicyFile::initPolicyFile($PolicyFile$PolicyInfo* newInfo, $URL* url) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PolicyFile$2, this, newInfo)));
	if (url != nullptr) {
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println($$str({"reading "_s, url}));
		}
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PolicyFile$3, this, url, newInfo)));
	} else {
		bool loaded_one = initPolicyFile(PolicyFile::POLICY, PolicyFile::POLICY_URL, newInfo);
		if (!loaded_one) {
			initStaticPolicy(newInfo);
		}
	}
}

bool PolicyFile::initPolicyFile($String* propname, $String* urlname, $PolicyFile$PolicyInfo* newInfo) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	bool loadedPolicy = $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PolicyFile$4, this, propname, newInfo, urlname)))))))->booleanValue();
	return loadedPolicy;
}

void PolicyFile::initDefaultPolicy($PolicyFile$PolicyInfo* newInfo) {
	$var($Path, defaultPolicy, $nc(PolicyFile::builtInFS)->getPath($($StaticProperty::javaHome()), $$new($StringArray, {"lib"_s, "security"_s, "default.policy"_s})));
	if (PolicyFile::debug != nullptr) {
		$nc(PolicyFile::debug)->println($($String::valueOf({"reading "_s, defaultPolicy})));
	}
	if (!$($nc(defaultPolicy)->toFile())->exists()) {
		return;
	}
	try {
		$var($BufferedReader, br, $Files::newBufferedReader(defaultPolicy));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($PolicyParser, pp, $new<$PolicyParser>(this->expandProperties));
					pp->read(br);
					$var($Enumeration, enum_, pp->grantElements());
					while ($nullcheck(enum_)->hasMoreElements()) {
						$var($PolicyParser$GrantEntry, ge, $cast<$PolicyParser$GrantEntry>(enum_->nextElement()));
						addGrantEntry(ge, ($KeyStore*)nullptr, newInfo);
					}
				} catch ($Throwable& t$) {
					if (br != nullptr) {
						try {
							br->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& e) {
				$assign(var$0, e);
			} /*finally*/ {
				if (br != nullptr) {
					br->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($Exception& e) {
		$throwNew($InternalError, "Failed to load default.policy"_s, static_cast<$Throwable*>(e));
	}
}

bool PolicyFile::init($URL* policy, $PolicyFile$PolicyInfo* newInfo) {
	$useLocalCurrentObjectStackCache();
	if ($nc(PolicyFile::badPolicyURLs)->contains(policy)) {
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println($$str({"skipping bad policy file: "_s, policy}));
		}
		return false;
	}
	try {
		$var($InputStreamReader, isr, getInputStreamReader($($PolicyUtil::getInputStream(policy))));
		{
			$var($Throwable, var$0, nullptr);
			bool var$2 = false;
			bool return$1 = false;
			try {
				try {
					$var($PolicyParser, pp, $new($PolicyParser, this->expandProperties));
					pp->read(isr);
					$var($KeyStore, keyStore, nullptr);
					try {
						$var($URL, var$3, policy);
						$var($String, var$4, pp->getKeyStoreUrl());
						$var($String, var$5, pp->getKeyStoreType());
						$var($String, var$6, pp->getKeyStoreProvider());
						$assign(keyStore, $PolicyUtil::getKeyStore(var$3, var$4, var$5, var$6, $(pp->getStorePassURL()), PolicyFile::debug));
					} catch ($Exception& e) {
						if (PolicyFile::debug != nullptr) {
							$nc(PolicyFile::debug)->println("Debug info only. Ignoring exception."_s);
							e->printStackTrace();
						}
					}
					$var($Enumeration, enum_, pp->grantElements());
					while ($nc(enum_)->hasMoreElements()) {
						$var($PolicyParser$GrantEntry, ge, $cast($PolicyParser$GrantEntry, enum_->nextElement()));
						addGrantEntry(ge, keyStore, newInfo);
					}
					var$2 = true;
					return$1 = true;
					goto $finally;
				} catch ($Throwable& t$) {
					if (isr != nullptr) {
						try {
							isr->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$7) {
				$assign(var$0, var$7);
			} $finally: {
				if (isr != nullptr) {
					isr->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($PolicyParser$ParsingException& pe) {
		$nc(PolicyFile::badPolicyURLs)->add(policy);
		$var($ObjectArray, source, $new($ObjectArray, {
			$of(policy),
			$($of(pe->getNonlocalizedMessage()))
		}));
		$nc($System::err)->println($($LocalizedMessage::getNonlocalized($$str({PolicyFile::POLICY, ".error.parsing.policy.message"_s}), source)));
		if (PolicyFile::debug != nullptr) {
			pe->printStackTrace();
		}
	} catch ($Exception& e) {
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println($$str({"error parsing "_s, policy}));
			$nc(PolicyFile::debug)->println($(e->toString()));
			e->printStackTrace();
		}
	}
	return false;
}

$InputStreamReader* PolicyFile::getInputStreamReader($InputStream* is) {
	$init($StandardCharsets);
	return (this->notUtf8) ? $new($InputStreamReader, is) : $new($InputStreamReader, is, $StandardCharsets::UTF_8);
}

void PolicyFile::initStaticPolicy($PolicyFile$PolicyInfo* newInfo) {
	$beforeCallerSensitive();
	if (PolicyFile::debug != nullptr) {
		$nc(PolicyFile::debug)->println("Initializing with static permissions"_s);
	}
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PolicyFile$5, this, newInfo)));
}

$CodeSource* PolicyFile::getCodeSource($PolicyParser$GrantEntry* ge, $KeyStore* keyStore, $PolicyFile$PolicyInfo* newInfo) {
	$useLocalCurrentObjectStackCache();
	$var($CertificateArray, certs, nullptr);
	if ($nc(ge)->signedBy != nullptr) {
		$assign(certs, getCertificates(keyStore, ge->signedBy, newInfo));
		if (certs == nullptr) {
			if (PolicyFile::debug != nullptr) {
				$nc(PolicyFile::debug)->println($$str({"  -- No certs for alias \'"_s, ge->signedBy, "\' - ignoring entry"_s}));
			}
			return nullptr;
		}
	}
	$var($URL, location, nullptr);
	if ($nc(ge)->codeBase != nullptr) {
		$assign(location, $new($URL, ge->codeBase));
	} else {
		$assign(location, nullptr);
	}
	return (canonicalizeCodebase($$new($CodeSource, location, certs), false));
}

void PolicyFile::addGrantEntry($PolicyParser$GrantEntry* ge, $KeyStore* keyStore, $PolicyFile$PolicyInfo* newInfo) {
	$useLocalCurrentObjectStackCache();
	if (PolicyFile::debug != nullptr) {
		$nc(PolicyFile::debug)->println("Adding policy entry: "_s);
		$nc(PolicyFile::debug)->println($$str({"  signedBy "_s, $nc(ge)->signedBy}));
		$nc(PolicyFile::debug)->println($$str({"  codeBase "_s, $nc(ge)->codeBase}));
		if ($nc(ge)->principals != nullptr) {
			{
				$var($Iterator, i$, $nc(ge->principals)->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($PolicyParser$PrincipalEntry, pppe, $cast($PolicyParser$PrincipalEntry, i$->next()));
					{
						$nc(PolicyFile::debug)->println($$str({"  "_s, $($nc(pppe)->toString())}));
					}
				}
			}
		}
	}
	try {
		$var($CodeSource, codesource, getCodeSource(ge, keyStore, newInfo));
		if (codesource == nullptr) {
			return;
		}
		if (replacePrincipals($nc(ge)->principals, keyStore) == false) {
			return;
		}
		$var($PolicyFile$PolicyEntry, entry, $new($PolicyFile$PolicyEntry, codesource, $nc(ge)->principals));
		$var($Enumeration, enum_, $nc(ge)->permissionElements());
		while ($nc(enum_)->hasMoreElements()) {
			$var($PolicyParser$PermissionEntry, pe, $cast($PolicyParser$PermissionEntry, enum_->nextElement()));
			try {
				expandPermissionName(pe, keyStore);
				$var($Permission, perm, nullptr);
				bool var$0 = $nc($nc(pe)->permission)->equals("javax.security.auth.PrivateCredentialPermission"_s);
				if (var$0 && $nc(pe->name)->endsWith(" self"_s)) {
					$set(pe, name, $str({$($nc(pe->name)->substring(0, $nc(pe->name)->indexOf("self"_s))), PolicyFile::SELF}));
				}
				if ($nc(pe)->name != nullptr && $nc(pe->name)->indexOf(PolicyFile::SELF) != -1) {
					$var($CertificateArray, certs, nullptr);
					if (pe->signedBy != nullptr) {
						$assign(certs, getCertificates(keyStore, pe->signedBy, newInfo));
					} else {
						$assign(certs, nullptr);
					}
					$assign(perm, $new($PolicyFile$SelfPermission, pe->permission, pe->name, pe->action, certs));
				} else {
					$assign(perm, getInstance(pe->permission, pe->name, pe->action));
				}
				entry->add(perm);
				if (PolicyFile::debug != nullptr) {
					$nc(PolicyFile::debug)->println($$str({"  "_s, perm}));
				}
			} catch ($ClassNotFoundException& cnfe) {
				$var($CertificateArray, certs, nullptr);
				if ($nc(pe)->signedBy != nullptr) {
					$assign(certs, getCertificates(keyStore, pe->signedBy, newInfo));
				} else {
					$assign(certs, nullptr);
				}
				if (certs != nullptr || $nc(pe)->signedBy == nullptr) {
					$var($Permission, perm, $new($UnresolvedPermission, pe->permission, pe->name, pe->action, certs));
					entry->add(perm);
					if (PolicyFile::debug != nullptr) {
						$nc(PolicyFile::debug)->println($$str({"  "_s, perm}));
					}
				}
			} catch ($InvocationTargetException& ite) {
				$var($ObjectArray, source, $new($ObjectArray, {
					$of($nc(pe)->permission),
					$($of($nc($(ite->getCause()))->toString()))
				}));
				$nc($System::err)->println($($LocalizedMessage::getNonlocalized($$str({PolicyFile::POLICY, ".error.adding.Permission.perm.message"_s}), source)));
			} catch ($Exception& e) {
				$var($ObjectArray, source, $new($ObjectArray, {
					$of($nc(pe)->permission),
					$($of(e->toString()))
				}));
				$nc($System::err)->println($($LocalizedMessage::getNonlocalized($$str({PolicyFile::POLICY, ".error.adding.Permission.perm.message"_s}), source)));
			}
		}
		$nc($nc(newInfo)->policyEntries)->add(entry);
	} catch ($Exception& e) {
		$var($ObjectArray, source, $new($ObjectArray, {$($of(e->toString()))}));
		$nc($System::err)->println($($LocalizedMessage::getNonlocalized($$str({PolicyFile::POLICY, ".error.adding.Entry.message"_s}), source)));
	}
	if (PolicyFile::debug != nullptr) {
		$nc(PolicyFile::debug)->println();
	}
}

$Permission* PolicyFile::getInstance($String* type, $String* name, $String* actions) {
	$init(PolicyFile);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* pc = $Class::forName(type, false, nullptr);
	$var($Permission, answer, getKnownPermission(pc, name, actions));
	if (answer != nullptr) {
		return answer;
	}
	$load($Permission);
	if (!$Permission::class$->isAssignableFrom(pc)) {
		$throwNew($ClassCastException, $$str({type, " is not a Permission"_s}));
	}
	if (name == nullptr && actions == nullptr) {
		try {
			$var($Constructor, c, $nc(pc)->getConstructor(PolicyFile::PARAMS0));
			return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, 0)));
		} catch ($NoSuchMethodException& ne) {
			try {
				$var($Constructor, c, $nc(pc)->getConstructor(PolicyFile::PARAMS1));
				return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {$of(name)})));
			} catch ($NoSuchMethodException& ne1) {
				$var($Constructor, c, $nc(pc)->getConstructor(PolicyFile::PARAMS2));
				return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {
					$of(name),
					$of(actions)
				})));
			}
		}
	} else if (name != nullptr && actions == nullptr) {
		try {
			$var($Constructor, c, $nc(pc)->getConstructor(PolicyFile::PARAMS1));
			return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {$of(name)})));
		} catch ($NoSuchMethodException& ne) {
			$var($Constructor, c, $nc(pc)->getConstructor(PolicyFile::PARAMS2));
			return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {
				$of(name),
				$of(actions)
			})));
		}
	} else {
		$var($Constructor, c, $nc(pc)->getConstructor(PolicyFile::PARAMS2));
		return $cast($Permission, $nc(c)->newInstance($$new($ObjectArray, {
			$of(name),
			$of(actions)
		})));
	}
}

$Permission* PolicyFile::getKnownPermission($Class* claz, $String* name, $String* actions) {
	$init(PolicyFile);
	$load($FilePermission);
	if ($nc($of(claz))->equals($FilePermission::class$)) {
		return $new($FilePermission, name, actions);
	} else {
		$load($SocketPermission);
		if ($of(claz)->equals($SocketPermission::class$)) {
			return $new($SocketPermission, name, actions);
		} else {
			$load($RuntimePermission);
			if ($of(claz)->equals($RuntimePermission::class$)) {
				return $new($RuntimePermission, name, actions);
			} else {
				$load($PropertyPermission);
				if ($of(claz)->equals($PropertyPermission::class$)) {
					return $new($PropertyPermission, name, actions);
				} else {
					$load($NetPermission);
					if ($of(claz)->equals($NetPermission::class$)) {
						return $new($NetPermission, name, actions);
					} else {
						$load($AllPermission);
						if ($of(claz)->equals($AllPermission::class$)) {
							$init($SecurityConstants);
							return $SecurityConstants::ALL_PERMISSION;
						} else {
							$load($SecurityPermission);
							if ($of(claz)->equals($SecurityPermission::class$)) {
								return $new($SecurityPermission, name, actions);
							} else {
								return nullptr;
							}
						}
					}
				}
			}
		}
	}
}

$Principal* PolicyFile::getKnownPrincipal($Class* claz, $String* name) {
	$init(PolicyFile);
	$load($X500Principal);
	if ($nc($of(claz))->equals($X500Principal::class$)) {
		return $new($X500Principal, name);
	} else {
		return nullptr;
	}
}

$CertificateArray* PolicyFile::getCertificates($KeyStore* keyStore, $String* aliases, $PolicyFile$PolicyInfo* newInfo) {
	$useLocalCurrentObjectStackCache();
	$var($List, vcerts, nullptr);
	$var($StringTokenizer, st, $new($StringTokenizer, aliases, ","_s));
	int32_t n = 0;
	while (st->hasMoreTokens()) {
		$var($String, alias, $nc($(st->nextToken()))->trim());
		++n;
		$var($Certificate, cert, nullptr);
		$synchronized($nc(newInfo)->aliasMapping) {
			$assign(cert, $cast($Certificate, $nc(newInfo->aliasMapping)->get(alias)));
			if (cert == nullptr && keyStore != nullptr) {
				try {
					$assign(cert, keyStore->getCertificate(alias));
				} catch ($KeyStoreException& kse) {
				}
				if (cert != nullptr) {
					$nc(newInfo->aliasMapping)->put(alias, cert);
					$nc(newInfo->aliasMapping)->put(cert, alias);
				}
			}
		}
		if (cert != nullptr) {
			if (vcerts == nullptr) {
				$assign(vcerts, $new($ArrayList));
			}
			$nc(vcerts)->add(cert);
		}
	}
	if (vcerts != nullptr && n == vcerts->size()) {
		$var($CertificateArray, certs, $new($CertificateArray, vcerts->size()));
		vcerts->toArray(certs);
		return certs;
	} else {
		return nullptr;
	}
}

void PolicyFile::refresh() {
	init(this->url);
}

bool PolicyFile::implies($ProtectionDomain* pd, $Permission* p) {
	$useLocalCurrentObjectStackCache();
	$var($JavaSecurityAccess$ProtectionDomainCache, pdMap, $nc(this->policyInfo)->getPdMapping());
	$var($PermissionCollection, pc, $nc(pdMap)->get(pd));
	if (pc != nullptr) {
		return pc->implies(p);
	}
	$assign(pc, getPermissions(pd));
	if (pc == nullptr) {
		return false;
	}
	pdMap->put(pd, pc);
	return $nc(pc)->implies(p);
}

$PermissionCollection* PolicyFile::getPermissions($ProtectionDomain* domain) {
	$useLocalCurrentObjectStackCache();
	$var($Permissions, perms, $new($Permissions));
	if (domain == nullptr) {
		return perms;
	}
	getPermissions(perms, domain);
	$var($PermissionCollection, pc, $nc(domain)->getPermissions());
	if (pc != nullptr) {
		$synchronized(pc) {
			$var($Enumeration, e, pc->elements());
			while ($nc(e)->hasMoreElements()) {
				perms->add($($FilePermCompat::newPermPlusAltPath($cast($Permission, $(e->nextElement())))));
			}
		}
	}
	return perms;
}

$PermissionCollection* PolicyFile::getPermissions($CodeSource* codesource) {
	return getPermissions($$new($Permissions), codesource);
}

$PermissionCollection* PolicyFile::getPermissions($Permissions* perms, $ProtectionDomain* pd) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (PolicyFile::debug != nullptr) {
		$nc(PolicyFile::debug)->println($$str({"getPermissions:\n\t"_s, $(printPD(pd))}));
	}
	$var($CodeSource, cs, $nc(pd)->getCodeSource());
	if (cs == nullptr) {
		return perms;
	}
	$var($CodeSource, canonCodeSource, $cast($CodeSource, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PolicyFile$6, this, cs)))));
	return getPermissions(perms, canonCodeSource, $(pd->getPrincipals()));
}

$PermissionCollection* PolicyFile::getPermissions($Permissions* perms, $CodeSource* cs) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (cs == nullptr) {
		return perms;
	}
	$var($CodeSource, canonCodeSource, $cast($CodeSource, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PolicyFile$7, this, cs)))));
	return getPermissions(perms, canonCodeSource, nullptr);
}

$Permissions* PolicyFile::getPermissions($Permissions* perms, $CodeSource* cs, $PrincipalArray* principals) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc($nc(this->policyInfo)->policyEntries)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PolicyFile$PolicyEntry, entry, $cast($PolicyFile$PolicyEntry, i$->next()));
			{
				addPermissions(perms, cs, principals, entry);
			}
		}
	}
	return perms;
}

void PolicyFile::addPermissions($Permissions* perms, $CodeSource* cs, $PrincipalArray* principals, $PolicyFile$PolicyEntry* entry) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (PolicyFile::debug != nullptr) {
		$nc(PolicyFile::debug)->println($$str({"evaluate codesources:\n\tPolicy CodeSource: "_s, $($nc(entry)->getCodeSource()), "\n\tActive CodeSource: "_s, cs}));
	}
	$var($Boolean, imp, $cast($Boolean, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($PolicyFile$8, this, entry, cs)))));
	if (!$nc(imp)->booleanValue()) {
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println("evaluation (codesource) failed"_s);
		}
		return;
	}
	$var($List, entryPs, $nc(entry)->getPrincipals());
	if (PolicyFile::debug != nullptr) {
		$var($List, accPs, $new($ArrayList));
		if (principals != nullptr) {
			for (int32_t i = 0; i < principals->length; ++i) {
				$var($String, var$0, $nc($of(principals->get(i)))->getClass()->getName());
				accPs->add($$new($PolicyParser$PrincipalEntry, var$0, $($nc(principals->get(i))->getName())));
			}
		}
		$nc(PolicyFile::debug)->println($$str({"evaluate principals:\n\tPolicy Principals: "_s, entryPs, "\n\tActive Principals: "_s, accPs}));
	}
	if (entryPs == nullptr || $nc(entryPs)->isEmpty()) {
		addPerms(perms, principals, entry);
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println("evaluation (codesource/principals) passed"_s);
		}
		return;
	} else if (principals == nullptr || $nc(principals)->length == 0) {
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println("evaluation (principals) failed"_s);
		}
		return;
	}
	{
		$var($Iterator, i$, $nc(entryPs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PolicyParser$PrincipalEntry, pppe, $cast($PolicyParser$PrincipalEntry, i$->next()));
			{
				if ($nc(pppe)->isWildcardClass()) {
					continue;
				}
				if ($nc(pppe)->isWildcardName()) {
					if (wildcardPrincipalNameImplies(pppe->principalClass, principals)) {
						continue;
					}
					if (PolicyFile::debug != nullptr) {
						$nc(PolicyFile::debug)->println("evaluation (principal name wildcard) failed"_s);
					}
					return;
				}
				$var($Set, pSet, $new($HashSet, $(static_cast<$Collection*>($Arrays::asList(principals)))));
				$init($Collections);
				$var($Subject, subject, $new($Subject, true, pSet, $Collections::EMPTY_SET, $Collections::EMPTY_SET));
				try {
					$var($ClassLoader, cl, $($Thread::currentThread())->getContextClassLoader());
					$Class* pClass = $Class::forName($nc(pppe)->principalClass, false, cl);
					$var($Principal, p, getKnownPrincipal(pClass, $nc(pppe)->principalName));
					if (p == nullptr) {
						$load($Principal);
						if (!$Principal::class$->isAssignableFrom(pClass)) {
							$throwNew($ClassCastException, $$str({$nc(pppe)->principalClass, " is not a Principal"_s}));
						}
						$var($Constructor, c, $nc(pClass)->getConstructor(PolicyFile::PARAMS1));
						$assign(p, $cast($Principal, $nc(c)->newInstance($$new($ObjectArray, {$of($nc(pppe)->principalName)}))));
					}
					if (PolicyFile::debug != nullptr) {
						$nc(PolicyFile::debug)->println($$str({"found Principal "_s, $($nc($of(p))->getClass()->getName())}));
					}
					if (!$nc(p)->implies(subject)) {
						if (PolicyFile::debug != nullptr) {
							$nc(PolicyFile::debug)->println("evaluation (principal implies) failed"_s);
						}
						return;
					}
				} catch ($Exception& e) {
					if (PolicyFile::debug != nullptr) {
						e->printStackTrace();
					}
					if (!$nc(pppe)->implies(subject)) {
						if (PolicyFile::debug != nullptr) {
							$nc(PolicyFile::debug)->println("evaluation (default principal implies) failed"_s);
						}
						return;
					}
				}
			}
		}
	}
	if (PolicyFile::debug != nullptr) {
		$nc(PolicyFile::debug)->println("evaluation (codesource/principals) passed"_s);
	}
	addPerms(perms, principals, entry);
}

bool PolicyFile::wildcardPrincipalNameImplies($String* principalClass, $PrincipalArray* principals) {
	$init(PolicyFile);
	$useLocalCurrentObjectStackCache();
	{
		$var($PrincipalArray, arr$, principals);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Principal, p, arr$->get(i$));
			{
				if ($nc(principalClass)->equals($($nc($of(p))->getClass()->getName()))) {
					return true;
				}
			}
		}
	}
	return false;
}

void PolicyFile::addPerms($Permissions* perms, $PrincipalArray* accPs, $PolicyFile$PolicyEntry* entry) {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc($nc(entry)->permissions)->size(); ++i) {
		$var($Permission, p, $cast($Permission, $nc(entry->permissions)->get(i)));
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println($$str({"  granting "_s, p}));
		}
		if ($instanceOf($PolicyFile$SelfPermission, p)) {
			expandSelf($cast($PolicyFile$SelfPermission, p), $(entry->getPrincipals()), accPs, perms);
		} else {
			$nc(perms)->add($($FilePermCompat::newPermPlusAltPath(p)));
		}
	}
}

void PolicyFile::expandSelf($PolicyFile$SelfPermission* sp, $List* entryPs, $PrincipalArray* pdp, $Permissions* perms) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (entryPs == nullptr || $nc(entryPs)->isEmpty()) {
		if (PolicyFile::debug != nullptr) {
			$var($String, var$1, $$str({"Ignoring permission "_s, $($nc(sp)->getSelfType()), " with target name ("_s}));
			$var($String, var$0, $$concat(var$1, $(sp->getSelfName())));
			$nc(PolicyFile::debug)->println($$concat(var$0, ").  No Principal(s) specified in the grant clause.  SELF-based target names are only valid in the context of a Principal-based grant entry."_s));
		}
		return;
	}
	int32_t startIndex = 0;
	int32_t v = 0;
	$var($StringBuilder, sb, $new($StringBuilder));
	while ((v = $nc($($nc(sp)->getSelfName()))->indexOf(PolicyFile::SELF, startIndex)) != -1) {
		sb->append($($nc($(sp->getSelfName()))->substring(startIndex, v)));
		$var($Iterator, pli, $nc(entryPs)->iterator());
		while ($nc(pli)->hasNext()) {
			$var($PolicyParser$PrincipalEntry, pppe, $cast($PolicyParser$PrincipalEntry, pli->next()));
			$var($StringArray2, principalInfo, getPrincipalInfo(pppe, pdp));
			for (int32_t i = 0; i < $nc(principalInfo)->length; ++i) {
				if (i != 0) {
					sb->append(", "_s);
				}
				sb->append($$str({$nc(principalInfo->get(i))->get(0), " \""_s, $nc(principalInfo->get(i))->get(1), "\""_s}));
			}
			if (pli->hasNext()) {
				sb->append(", "_s);
			}
		}
		startIndex = v + $nc(PolicyFile::SELF)->length();
	}
	sb->append($($nc($($nc(sp)->getSelfName()))->substring(startIndex)));
	if (PolicyFile::debug != nullptr) {
		$var($String, var$2, $$str({"  expanded:\n\t"_s, $($nc(sp)->getSelfName()), "\n  into:\n\t"_s}));
		$nc(PolicyFile::debug)->println($$concat(var$2, $(sb->toString())));
	}
	try {
		$var($String, var$3, $nc(sp)->getSelfType());
		$var($String, var$4, sb->toString());
		$nc(perms)->add($($FilePermCompat::newPermPlusAltPath($(getInstance(var$3, var$4, $(sp->getSelfActions()))))));
	} catch ($ClassNotFoundException& cnfe) {
		$Class* pc = nullptr;
		$synchronized(perms) {
			$var($Enumeration, e, $nc(perms)->elements());
			while ($nc(e)->hasMoreElements()) {
				$var($Permission, pElement, $cast($Permission, e->nextElement()));
				if ($nc($($nc($of(pElement))->getClass()->getName()))->equals($($nc(sp)->getSelfType()))) {
					pc = $of(pElement)->getClass();
					break;
				}
			}
		}
		if (pc == nullptr) {
			$var($String, var$5, $nc(sp)->getSelfType());
			$var($String, var$6, sb->toString());
			$var($String, var$7, sp->getSelfActions());
			$nc(perms)->add($$new($UnresolvedPermission, var$5, var$6, var$7, $(sp->getCerts())));
		} else {
			try {
				$var($Constructor, c, nullptr);
				if ($nc(sp)->getSelfActions() == nullptr) {
					try {
						$assign(c, $nc(pc)->getConstructor(PolicyFile::PARAMS1));
						$nc(perms)->add($cast($Permission, $($nc(c)->newInstance($$new($ObjectArray, {$($of(sb->toString()))})))));
					} catch ($NoSuchMethodException& ne) {
						$assign(c, $nc(pc)->getConstructor(PolicyFile::PARAMS2));
						$nc(perms)->add($cast($Permission, $($nc(c)->newInstance($$new($ObjectArray, {
							$($of(sb->toString())),
							$($of(sp->getSelfActions()))
						})))));
					}
				} else {
					$assign(c, $nc(pc)->getConstructor(PolicyFile::PARAMS2));
					$nc(perms)->add($cast($Permission, $($nc(c)->newInstance($$new($ObjectArray, {
						$($of(sb->toString())),
						$($of(sp->getSelfActions()))
					})))));
				}
			} catch ($Exception& nme) {
				if (PolicyFile::debug != nullptr) {
					$nc(PolicyFile::debug)->println($$str({"self entry expansion  instantiation failed: "_s, $(nme->toString())}));
				}
			}
		}
	} catch ($Exception& e) {
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println($(e->toString()));
		}
	}
}

$StringArray2* PolicyFile::getPrincipalInfo($PolicyParser$PrincipalEntry* pe, $PrincipalArray* pdp) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !$nc(pe)->isWildcardClass();
	if (var$0 && !pe->isWildcardName()) {
		$var($StringArray2, info, $new($StringArray2, 1, 2));
		$nc(info->get(0))->set(0, pe->principalClass);
		$nc(info->get(0))->set(1, pe->principalName);
		return info;
	} else {
		bool var$2 = !pe->isWildcardClass();
		if (var$2 && pe->isWildcardName()) {
			$var($List, plist, $new($ArrayList));
			for (int32_t i = 0; i < $nc(pdp)->length; ++i) {
				if ($nc(pe->principalClass)->equals($($nc($of(pdp->get(i)))->getClass()->getName()))) {
					plist->add(pdp->get(i));
				}
			}
			$var($StringArray2, info, $new($StringArray2, plist->size(), 2));
			int32_t i = 0;
			{
				$var($Iterator, i$, plist->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Principal, p, $cast($Principal, i$->next()));
					{
						$nc(info->get(i))->set(0, $($nc($of(p))->getClass()->getName()));
						$nc(info->get(i))->set(1, $(p->getName()));
						++i;
					}
				}
			}
			return info;
		} else {
			$var($StringArray2, info, $new($StringArray2, $nc(pdp)->length, 2));
			for (int32_t i = 0; i < pdp->length; ++i) {
				$nc(info->get(i))->set(0, $($nc($of(pdp->get(i)))->getClass()->getName()));
				$nc(info->get(i))->set(1, $($nc(pdp->get(i))->getName()));
			}
			return info;
		}
	}
}

$CertificateArray* PolicyFile::getSignerCertificates($CodeSource* cs) {
	$useLocalCurrentObjectStackCache();
	$var($CertificateArray, certs, nullptr);
	if (($assign(certs, $nc(cs)->getCertificates())) == nullptr) {
		return nullptr;
	}
	for (int32_t i = 0; i < $nc(certs)->length; ++i) {
		if (!($instanceOf($X509Certificate, certs->get(i)))) {
			return $nc(cs)->getCertificates();
		}
	}
	int32_t i = 0;
	int32_t count = 0;
	while (i < $nc(certs)->length) {
		++count;
		while (((i + 1) < certs->length) && $nc($($nc(($cast($X509Certificate, certs->get(i))))->getIssuerX500Principal()))->equals($($nc(($cast($X509Certificate, certs->get(i + 1))))->getSubjectX500Principal()))) {
			++i;
		}
		++i;
	}
	if (count == $nc(certs)->length) {
		return certs;
	}
	$var($List, userCertList, $new($ArrayList));
	i = 0;
	while (i < $nc(certs)->length) {
		userCertList->add(certs->get(i));
		while (((i + 1) < certs->length) && $nc($($nc(($cast($X509Certificate, certs->get(i))))->getIssuerX500Principal()))->equals($($nc(($cast($X509Certificate, certs->get(i + 1))))->getSubjectX500Principal()))) {
			++i;
		}
		++i;
	}
	$var($CertificateArray, userCerts, $new($CertificateArray, userCertList->size()));
	userCertList->toArray(userCerts);
	return userCerts;
}

$CodeSource* PolicyFile::canonicalizeCodebase($CodeSource* cs, bool extractSignerCerts) {
	$useLocalCurrentObjectStackCache();
	$var($String, path, nullptr);
	$var($CodeSource, canonCs, cs);
	$var($URL, u, $nc(cs)->getLocation());
	if (u != nullptr) {
		if ($nc($(u->getProtocol()))->equals("jar"_s)) {
			$var($String, spec, u->getFile());
			int32_t separator = $nc(spec)->indexOf("!/"_s);
			if (separator != -1) {
				try {
					$assign(u, $new($URL, $(spec->substring(0, separator))));
				} catch ($MalformedURLException& e) {
				}
			}
		}
		if ($nc($(u->getProtocol()))->equals("file"_s)) {
			bool isLocalFile = false;
			$var($String, host, u->getHost());
			bool var$1 = host == nullptr || $nc(host)->isEmpty();
			bool var$0 = var$1 || $nc(host)->equals("~"_s);
			isLocalFile = (var$0 || $nc(host)->equalsIgnoreCase("localhost"_s));
			if (isLocalFile) {
				$init($File);
				$assign(path, $nc($(u->getFile()))->replace(u'/', $File::separatorChar));
				$assign(path, $ParseUtil::decode(path));
			}
		}
	}
	if (path != nullptr) {
		try {
			$var($URL, csUrl, nullptr);
			$assign(path, canonPath(path));
			$assign(csUrl, $ParseUtil::fileToEncodedURL($$new($File, path)));
			if (extractSignerCerts) {
				$assign(canonCs, $new($CodeSource, csUrl, $(getSignerCertificates(cs))));
			} else {
				$assign(canonCs, $new($CodeSource, csUrl, $(cs->getCertificates())));
			}
		} catch ($IOException& ioe) {
			if (extractSignerCerts) {
				$var($URL, var$2, cs->getLocation());
				$assign(canonCs, $new($CodeSource, var$2, $(getSignerCertificates(cs))));
			}
		}
	} else if (extractSignerCerts) {
		$var($URL, var$3, cs->getLocation());
		$assign(canonCs, $new($CodeSource, var$3, $(getSignerCertificates(cs))));
	}
	return canonCs;
}

$String* PolicyFile::canonPath($String* path$renamed) {
	$init(PolicyFile);
	$useLocalCurrentObjectStackCache();
	$var($String, path, path$renamed);
	if ($nc(path)->endsWith("*"_s)) {
		$assign(path, $str({$(path->substring(0, path->length() - 1)), "-"_s}));
		$assign(path, $$new($File, path)->getCanonicalPath());
		return $str({$($nc(path)->substring(0, path->length() - 1)), "*"_s});
	} else {
		return $$new($File, path)->getCanonicalPath();
	}
}

$String* PolicyFile::printPD($ProtectionDomain* pd) {
	$useLocalCurrentObjectStackCache();
	$var($PrincipalArray, principals, $nc(pd)->getPrincipals());
	$var($String, pals, "<no principals>"_s);
	if (principals != nullptr && principals->length > 0) {
		$var($StringBuilder, palBuf, $new($StringBuilder, "(principals "_s));
		for (int32_t i = 0; i < principals->length; ++i) {
			$var($String, var$1, $$str({$($nc($of(principals->get(i)))->getClass()->getName()), " \""_s}));
			$var($String, var$0, $$concat(var$1, $($nc(principals->get(i))->getName())));
			palBuf->append($$concat(var$0, "\""_s));
			if (i < principals->length - 1) {
				palBuf->append(", "_s);
			} else {
				palBuf->append(")"_s);
			}
		}
		$assign(pals, palBuf->toString());
	}
	$var($String, var$4, $$str({"PD CodeSource: "_s, $(pd->getCodeSource()), "\n\tPD ClassLoader: "_s}));
	$var($String, var$3, $$concat(var$4, $(pd->getClassLoader())));
	$var($String, var$2, $$concat(var$3, "\n\tPD Principals: "_s));
	return $concat(var$2, pals);
}

bool PolicyFile::replacePrincipals($List* principals, $KeyStore* keystore) {
	$useLocalCurrentObjectStackCache();
	if (principals == nullptr || $nc(principals)->isEmpty() || keystore == nullptr) {
		return true;
	}
	{
		$var($Iterator, i$, $nc(principals)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($PolicyParser$PrincipalEntry, pppe, $cast($PolicyParser$PrincipalEntry, i$->next()));
			{
				if ($nc(pppe)->isReplaceName()) {
					$var($String, name, nullptr);
					if (($assign(name, getDN(pppe->principalName, keystore))) == nullptr) {
						return false;
					}
					if (PolicyFile::debug != nullptr) {
						$nc(PolicyFile::debug)->println($$str({"  Replacing \""_s, pppe->principalName, "\" with "_s, PolicyFile::X500PRINCIPAL, "/\""_s, name, "\""_s}));
					}
					$set(pppe, principalClass, PolicyFile::X500PRINCIPAL);
					$set(pppe, principalName, name);
				}
			}
		}
	}
	return true;
}

void PolicyFile::expandPermissionName($PolicyParser$PermissionEntry* pe, $KeyStore* keystore) {
	$useLocalCurrentObjectStackCache();
	if ($nc(pe)->name == nullptr || $nc($nc(pe)->name)->indexOf("${{"_s, 0) == -1) {
		return;
	}
	int32_t startIndex = 0;
	int32_t b = 0;
	int32_t e = 0;
	$var($StringBuilder, sb, $new($StringBuilder));
	while ((b = $nc($nc(pe)->name)->indexOf("${{"_s, startIndex)) != -1) {
		e = $nc(pe->name)->indexOf("}}"_s, b);
		if (e < 1) {
			break;
		}
		sb->append($($nc(pe->name)->substring(startIndex, b)));
		$var($String, value, $nc(pe->name)->substring(b + 3, e));
		int32_t colonIndex = 0;
		$var($String, prefix, value);
		$var($String, suffix, nullptr);
		if ((colonIndex = value->indexOf((int32_t)u':')) != -1) {
			$assign(prefix, value->substring(0, colonIndex));
		}
		if (prefix->equalsIgnoreCase("self"_s)) {
			sb->append($($nc(pe->name)->substring(b, e + 2)));
			startIndex = e + 2;
			continue;
		} else if (prefix->equalsIgnoreCase("alias"_s)) {
			if (colonIndex == -1) {
				$var($ObjectArray, source, $new($ObjectArray, {$of(pe->name)}));
				$throwNew($Exception, $($LocalizedMessage::getNonlocalized("alias.name.not.provided.pe.name."_s, source)));
			}
			$assign(suffix, value->substring(colonIndex + 1));
			if (($assign(suffix, getDN(suffix, keystore))) == nullptr) {
				$var($ObjectArray, source, $new($ObjectArray, {$($of(value->substring(colonIndex + 1)))}));
				$throwNew($Exception, $($LocalizedMessage::getNonlocalized("unable.to.perform.substitution.on.alias.suffix"_s, source)));
			}
			sb->append($$str({PolicyFile::X500PRINCIPAL, " \""_s, suffix, "\""_s}));
			startIndex = e + 2;
		} else {
			$var($ObjectArray, source, $new($ObjectArray, {$of(prefix)}));
			$throwNew($Exception, $($LocalizedMessage::getNonlocalized("substitution.value.prefix.unsupported"_s, source)));
		}
	}
	sb->append($($nc($nc(pe)->name)->substring(startIndex)));
	if (PolicyFile::debug != nullptr) {
		$nc(PolicyFile::debug)->println($$str({"  Permission name expanded from:\n\t"_s, $nc(pe)->name, "\nto\n\t"_s, $(sb->toString())}));
	}
	$set($nc(pe), name, sb->toString());
}

$String* PolicyFile::getDN($String* alias, $KeyStore* keystore) {
	$useLocalCurrentObjectStackCache();
	$var($Certificate, cert, nullptr);
	try {
		$assign(cert, $nc(keystore)->getCertificate(alias));
	} catch ($Exception& e) {
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println($$str({"  Error retrieving certificate for \'"_s, alias, "\': "_s, $(e->toString())}));
		}
		return nullptr;
	}
	if (cert == nullptr || !($instanceOf($X509Certificate, cert))) {
		if (PolicyFile::debug != nullptr) {
			$nc(PolicyFile::debug)->println($$str({"  -- No certificate for \'"_s, alias, "\' - ignoring entry"_s}));
		}
		return nullptr;
	} else {
		$var($X509Certificate, x509Cert, $cast($X509Certificate, cert));
		$var($X500Principal, p, $new($X500Principal, $($nc($($nc(x509Cert)->getSubjectX500Principal()))->toString())));
		return p->getName();
	}
}

void clinit$PolicyFile($Class* class$) {
	$assignStatic(PolicyFile::SELF, "${{self}}"_s);
	$assignStatic(PolicyFile::X500PRINCIPAL, "javax.security.auth.x500.X500Principal"_s);
	$assignStatic(PolicyFile::POLICY, "java.security.policy"_s);
	$assignStatic(PolicyFile::POLICY_URL, "policy.url."_s);
	$assignStatic(PolicyFile::debug, $Debug::getInstance("policy"_s));
	$assignStatic(PolicyFile::PARAMS0, $new($ClassArray, 0));
	$assignStatic(PolicyFile::PARAMS1, $new($ClassArray, {$String::class$}));
	$assignStatic(PolicyFile::PARAMS2, $new($ClassArray, {
		$String::class$,
		$String::class$
	}));
	$assignStatic(PolicyFile::badPolicyURLs, $Collections::newSetFromMap(static_cast<$Map*>(static_cast<$AbstractMap*>($$new($ConcurrentHashMap)))));
	$assignStatic(PolicyFile::builtInFS, $DefaultFileSystemProvider::theFileSystem());
}

PolicyFile::PolicyFile() {
}

$Class* PolicyFile::load$($String* name, bool initialize) {
	$loadClass(PolicyFile, name, initialize, &_PolicyFile_ClassInfo_, clinit$PolicyFile, allocate$PolicyFile);
	return class$;
}

$Class* PolicyFile::class$ = nullptr;

		} // provider
	} // security
} // sun
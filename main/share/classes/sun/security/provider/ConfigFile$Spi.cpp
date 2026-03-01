#include <sun/security/provider/ConfigFile$Spi.h>

#include <java/io/BufferedReader.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/io/StreamTokenizer.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/security/Security.h>
#include <java/text/MessageFormat.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <javax/security/auth/AuthPermission.h>
#include <javax/security/auth/login/AppConfigurationEntry$LoginModuleControlFlag.h>
#include <javax/security/auth/login/AppConfigurationEntry.h>
#include <javax/security/auth/login/Configuration$Parameters.h>
#include <javax/security/auth/login/ConfigurationSpi.h>
#include <sun/security/provider/ConfigFile$Spi$1.h>
#include <sun/security/provider/ConfigFile$Spi$2.h>
#include <sun/security/provider/ConfigFile.h>
#include <sun/security/util/Debug.h>
#include <sun/security/util/PropertyExpander$ExpandException.h>
#include <sun/security/util/PropertyExpander.h>
#include <sun/security/util/ResourcesMgr.h>
#include <jcpp.h>

#undef ENGLISH
#undef OPTIONAL
#undef REQUIRED
#undef REQUISITE
#undef SUFFICIENT
#undef TT_EOF
#undef TT_EOL
#undef TT_WORD
#undef UTF_8

using $AppConfigurationEntryArray = $Array<::javax::security::auth::login::AppConfigurationEntry>;
using $BufferedReader = ::java::io::BufferedReader;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $Reader = ::java::io::Reader;
using $StreamTokenizer = ::java::io::StreamTokenizer;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Security = ::java::security::Security;
using $MessageFormat = ::java::text::MessageFormat;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $AuthPermission = ::javax::security::auth::AuthPermission;
using $AppConfigurationEntry = ::javax::security::auth::login::AppConfigurationEntry;
using $AppConfigurationEntry$LoginModuleControlFlag = ::javax::security::auth::login::AppConfigurationEntry$LoginModuleControlFlag;
using $Configuration$Parameters = ::javax::security::auth::login::Configuration$Parameters;
using $ConfigurationSpi = ::javax::security::auth::login::ConfigurationSpi;
using $ConfigFile$Spi$1 = ::sun::security::provider::ConfigFile$Spi$1;
using $ConfigFile$Spi$2 = ::sun::security::provider::ConfigFile$Spi$2;
using $Debug = ::sun::security::util::Debug;
using $PropertyExpander = ::sun::security::util::PropertyExpander;
using $PropertyExpander$ExpandException = ::sun::security::util::PropertyExpander$ExpandException;
using $ResourcesMgr = ::sun::security::util::ResourcesMgr;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _ConfigFile$Spi_FieldInfo_[] = {
	{"url", "Ljava/net/URL;", nullptr, $PRIVATE, $field(ConfigFile$Spi, url)},
	{"expandProp", "Z", nullptr, $PRIVATE, $field(ConfigFile$Spi, expandProp)},
	{"configuration", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljavax/security/auth/login/AppConfigurationEntry;>;>;", $PRIVATE, $field(ConfigFile$Spi, configuration)},
	{"linenum", "I", nullptr, $PRIVATE, $field(ConfigFile$Spi, linenum)},
	{"st", "Ljava/io/StreamTokenizer;", nullptr, $PRIVATE, $field(ConfigFile$Spi, st)},
	{"lookahead", "I", nullptr, $PRIVATE, $field(ConfigFile$Spi, lookahead)},
	{"debugConfig", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC, $staticField(ConfigFile$Spi, debugConfig)},
	{"debugParser", "Lsun/security/util/Debug;", nullptr, $PRIVATE | $STATIC, $staticField(ConfigFile$Spi, debugParser)},
	{}
};

$MethodInfo _ConfigFile$Spi_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ConfigFile$Spi, init$, void)},
	{"<init>", "(Ljava/net/URI;)V", nullptr, $PUBLIC, $method(ConfigFile$Spi, init$, void, $URI*)},
	{"<init>", "(Ljavax/security/auth/login/Configuration$Parameters;)V", nullptr, $PUBLIC, $method(ConfigFile$Spi, init$, void, $Configuration$Parameters*), "java.io.IOException"},
	{"engineGetAppConfigurationEntry", "(Ljava/lang/String;)[Ljavax/security/auth/login/AppConfigurationEntry;", nullptr, $PUBLIC, $virtualMethod(ConfigFile$Spi, engineGetAppConfigurationEntry, $AppConfigurationEntryArray*, $String*)},
	{"engineRefresh", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(ConfigFile$Spi, engineRefresh, void)},
	{"expand", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(ConfigFile$Spi, expand, $String*, $String*), "sun.security.util.PropertyExpander$ExpandException,java.io.IOException"},
	{"getInputStream", "(Ljava/net/URL;)Ljava/io/InputStream;", nullptr, $PRIVATE, $method(ConfigFile$Spi, getInputStream, $InputStream*, $URL*), "java.io.IOException"},
	{"init", "()V", nullptr, $PRIVATE, $method(ConfigFile$Spi, init, void), "java.io.IOException"},
	{"init", "(Ljava/net/URL;Ljava/util/Map;)V", "(Ljava/net/URL;Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljavax/security/auth/login/AppConfigurationEntry;>;>;)V", $PRIVATE, $method(ConfigFile$Spi, init, void, $URL*, $Map*), "java.io.IOException"},
	{"ioException", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/IOException;", nullptr, $PRIVATE | $TRANSIENT, $method(ConfigFile$Spi, ioException, $IOException*, $String*, $ObjectArray*)},
	{"match", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(ConfigFile$Spi, match, $String*, $String*), "java.io.IOException"},
	{"nextToken", "()I", nullptr, $PRIVATE, $method(ConfigFile$Spi, nextToken, int32_t), "java.io.IOException"},
	{"parseLoginEntry", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljavax/security/auth/login/AppConfigurationEntry;>;>;)V", $PRIVATE, $method(ConfigFile$Spi, parseLoginEntry, void, $Map*), "java.io.IOException"},
	{"peek", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(ConfigFile$Spi, peek, bool, $String*)},
	{"readConfig", "(Ljava/io/Reader;Ljava/util/Map;)V", "(Ljava/io/Reader;Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljavax/security/auth/login/AppConfigurationEntry;>;>;)V", $PRIVATE, $method(ConfigFile$Spi, readConfig, void, $Reader*, $Map*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ConfigFile$Spi_InnerClassesInfo_[] = {
	{"sun.security.provider.ConfigFile$Spi", "sun.security.provider.ConfigFile", "Spi", $PUBLIC | $STATIC | $FINAL},
	{"sun.security.provider.ConfigFile$Spi$2", nullptr, nullptr, 0},
	{"sun.security.provider.ConfigFile$Spi$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ConfigFile$Spi_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.security.provider.ConfigFile$Spi",
	"javax.security.auth.login.ConfigurationSpi",
	nullptr,
	_ConfigFile$Spi_FieldInfo_,
	_ConfigFile$Spi_MethodInfo_,
	nullptr,
	nullptr,
	_ConfigFile$Spi_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.provider.ConfigFile"
};

$Object* allocate$ConfigFile$Spi($Class* clazz) {
	return $of($alloc(ConfigFile$Spi));
}

$Debug* ConfigFile$Spi::debugConfig = nullptr;
$Debug* ConfigFile$Spi::debugParser = nullptr;

void ConfigFile$Spi::init$() {
	$ConfigurationSpi::init$();
	this->expandProp = true;
	try {
		init();
	} catch ($IOException& ioe) {
		$throwNew($SecurityException, static_cast<$Throwable*>(ioe));
	}
}

void ConfigFile$Spi::init$($URI* uri) {
	$ConfigurationSpi::init$();
	this->expandProp = true;
	try {
		$set(this, url, $nc(uri)->toURL());
		init();
	} catch ($IOException& ioe) {
		$throwNew($SecurityException, static_cast<$Throwable*>(ioe));
	}
}

void ConfigFile$Spi::init$($Configuration$Parameters* params) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$ConfigurationSpi::init$();
	this->expandProp = true;
	try {
		$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new($ConfigFile$Spi$1, this, params)));
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($IOException, $(pae->getException())));
	}
}

void ConfigFile$Spi::init() {
	$useLocalCurrentObjectStackCache();
	bool initialized = false;
	$var($String, expand, $Security::getProperty("policy.expandProperties"_s));
	if (expand == nullptr) {
		$assign(expand, $System::getProperty("policy.expandProperties"_s));
	}
	if ("false"_s->equals(expand)) {
		this->expandProp = false;
	}
	$var($Map, newConfig, $new($HashMap));
	if (this->url != nullptr) {
		if (ConfigFile$Spi::debugConfig != nullptr) {
			$nc(ConfigFile$Spi::debugConfig)->println($$str({"reading "_s, this->url}));
		}
		init(this->url, newConfig);
		$set(this, configuration, newConfig);
		return;
	}
	$var($String, allowSys, $Security::getProperty("policy.allowSystemProperty"_s));
	if ("true"_s->equalsIgnoreCase(allowSys)) {
		$var($String, extra_config, $System::getProperty("java.security.auth.login.config"_s));
		if (extra_config != nullptr) {
			bool overrideAll = false;
			if (extra_config->startsWith("="_s)) {
				overrideAll = true;
				$assign(extra_config, extra_config->substring(1));
			}
			try {
				$assign(extra_config, $PropertyExpander::expand(extra_config));
			} catch ($PropertyExpander$ExpandException& peee) {
				$throw($(ioException("Unable.to.properly.expand.config"_s, $$new($ObjectArray, {$of(extra_config)}))));
			}
			$var($URL, configURL, nullptr);
			try {
				$assign(configURL, $new($URL, extra_config));
			} catch ($MalformedURLException& mue) {
				$var($File, configFile, $new($File, extra_config));
				if (configFile->exists()) {
					$assign(configURL, $nc($(configFile->toURI()))->toURL());
				} else {
					$throw($(ioException("extra.config.No.such.file.or.directory."_s, $$new($ObjectArray, {$of(extra_config)}))));
				}
			}
			if (ConfigFile$Spi::debugConfig != nullptr) {
				$nc(ConfigFile$Spi::debugConfig)->println($$str({"reading "_s, configURL}));
			}
			init(configURL, newConfig);
			initialized = true;
			if (overrideAll) {
				if (ConfigFile$Spi::debugConfig != nullptr) {
					$nc(ConfigFile$Spi::debugConfig)->println("overriding other policies!"_s);
				}
				$set(this, configuration, newConfig);
				return;
			}
		}
	}
	int32_t n = 1;
	$var($String, config_url, nullptr);
	while (($assign(config_url, $Security::getProperty($$str({"login.config.url."_s, $$str(n)})))) != nullptr) {
		try {
			$init($File);
			$assign(config_url, $nc($($PropertyExpander::expand(config_url)))->replace($File::separatorChar, u'/'));
			if (ConfigFile$Spi::debugConfig != nullptr) {
				$nc(ConfigFile$Spi::debugConfig)->println($$str({"\tReading config: "_s, config_url}));
			}
			init($$new($URL, config_url), newConfig);
			initialized = true;
		} catch ($PropertyExpander$ExpandException& peee) {
			$throw($(ioException("Unable.to.properly.expand.config"_s, $$new($ObjectArray, {$of(config_url)}))));
		}
		++n;
	}
	if (initialized == false && n == 1 && config_url == nullptr) {
		if (ConfigFile$Spi::debugConfig != nullptr) {
			$nc(ConfigFile$Spi::debugConfig)->println("\tReading Policy from ~/.java.login.config"_s);
		}
		$assign(config_url, $System::getProperty("user.home"_s));
		$init($File);
		$var($String, userConfigFile, $str({config_url, $$str($File::separatorChar), ".java.login.config"_s}));
		if ($$new($File, userConfigFile)->exists()) {
			init($($nc($($$new($File, userConfigFile)->toURI()))->toURL()), newConfig);
		}
	}
	$set(this, configuration, newConfig);
}

void ConfigFile$Spi::init($URL* config, $Map* newConfig) {
	$useLocalCurrentObjectStackCache();
	try {
		$init($StandardCharsets);
		$var($InputStreamReader, isr, $new($InputStreamReader, $(getInputStream(config)), $StandardCharsets::UTF_8));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					readConfig(isr, newConfig);
				} catch ($Throwable& t$) {
					try {
						isr->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				isr->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($FileNotFoundException& fnfe) {
		if (ConfigFile$Spi::debugConfig != nullptr) {
			$nc(ConfigFile$Spi::debugConfig)->println($(fnfe->toString()));
		}
		$throwNew($IOException, $($ResourcesMgr::getAuthResourceString("Configuration.Error.No.such.file.or.directory"_s)));
	}
}

$AppConfigurationEntryArray* ConfigFile$Spi::engineGetAppConfigurationEntry($String* applicationName) {
	$useLocalCurrentObjectStackCache();
	$var($List, list, nullptr);
	$synchronized(this->configuration) {
		$assign(list, $cast($List, $nc(this->configuration)->get(applicationName)));
	}
	if (list == nullptr || $nc(list)->size() == 0) {
		return nullptr;
	}
	$var($AppConfigurationEntryArray, entries, $new($AppConfigurationEntryArray, $nc(list)->size()));
	$var($Iterator, iterator, list->iterator());
	for (int32_t i = 0; $nc(iterator)->hasNext(); ++i) {
		$var($AppConfigurationEntry, e, $cast($AppConfigurationEntry, iterator->next()));
		$var($String, var$0, $nc(e)->getLoginModuleName());
		$var($AppConfigurationEntry$LoginModuleControlFlag, var$1, e->getControlFlag());
		entries->set(i, $$new($AppConfigurationEntry, var$0, var$1, $(e->getOptions())));
	}
	return entries;
}

void ConfigFile$Spi::engineRefresh() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkPermission($$new($AuthPermission, "refreshLoginConfiguration"_s));
		}
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ConfigFile$Spi$2, this)));
	}
}

void ConfigFile$Spi::readConfig($Reader* reader$renamed, $Map* newConfig) {
	$var($Reader, reader, reader$renamed);
	this->linenum = 1;
	if (!($instanceOf($BufferedReader, reader))) {
		$assign(reader, $new($BufferedReader, reader));
	}
	$set(this, st, $new($StreamTokenizer, reader));
	$nc(this->st)->quoteChar(u'\"');
	$nc(this->st)->wordChars(u'$', u'$');
	$nc(this->st)->wordChars(u'_', u'_');
	$nc(this->st)->wordChars(u'-', u'-');
	$nc(this->st)->wordChars(u'*', u'*');
	$nc(this->st)->lowerCaseMode(false);
	$nc(this->st)->slashSlashComments(true);
	$nc(this->st)->slashStarComments(true);
	$nc(this->st)->eolIsSignificant(true);
	this->lookahead = nextToken();
	while (this->lookahead != $StreamTokenizer::TT_EOF) {
		parseLoginEntry(newConfig);
	}
}

void ConfigFile$Spi::parseLoginEntry($Map* newConfig) {
	$useLocalCurrentObjectStackCache();
	$var($List, configEntries, $new($LinkedList));
	$var($String, appName, $nc(this->st)->sval);
	this->lookahead = nextToken();
	if (ConfigFile$Spi::debugParser != nullptr) {
		$nc(ConfigFile$Spi::debugParser)->println($$str({"\tReading next config entry: "_s, appName}));
	}
	match("{"_s);
	while (peek("}"_s) == false) {
		$var($String, moduleClass, match("module class name"_s));
		$var($AppConfigurationEntry$LoginModuleControlFlag, controlFlag, nullptr);
		$init($Locale);
		$var($String, sflag, $nc($(match("controlFlag"_s)))->toUpperCase($Locale::ENGLISH));
		{
			$var($String, s17620$, sflag);
			int32_t tmp17620$ = -1;
			switch (s17620$->hashCode()) {
			case 0x17371B9F:
				{
					if (s17620$->equals("REQUIRED"_s)) {
						tmp17620$ = 0;
					}
					break;
				}
			case (int32_t)0xCFACDDD9:
				{
					if (s17620$->equals("REQUISITE"_s)) {
						tmp17620$ = 1;
					}
					break;
				}
			case (int32_t)0xCD73291E:
				{
					if (s17620$->equals("SUFFICIENT"_s)) {
						tmp17620$ = 2;
					}
					break;
				}
			case 0x29F03B60:
				{
					if (s17620$->equals("OPTIONAL"_s)) {
						tmp17620$ = 3;
					}
					break;
				}
			}
			switch (tmp17620$) {
			case 0:
				{
					$init($AppConfigurationEntry$LoginModuleControlFlag);
					$assign(controlFlag, $AppConfigurationEntry$LoginModuleControlFlag::REQUIRED);
					break;
				}
			case 1:
				{
					$init($AppConfigurationEntry$LoginModuleControlFlag);
					$assign(controlFlag, $AppConfigurationEntry$LoginModuleControlFlag::REQUISITE);
					break;
				}
			case 2:
				{
					$init($AppConfigurationEntry$LoginModuleControlFlag);
					$assign(controlFlag, $AppConfigurationEntry$LoginModuleControlFlag::SUFFICIENT);
					break;
				}
			case 3:
				{
					$init($AppConfigurationEntry$LoginModuleControlFlag);
					$assign(controlFlag, $AppConfigurationEntry$LoginModuleControlFlag::OPTIONAL);
					break;
				}
			default:
				{
					$throw($(ioException("Configuration.Error.Invalid.control.flag.flag"_s, $$new($ObjectArray, {$of(sflag)}))));
				}
			}
		}
		$var($Map, options, $new($HashMap));
		while (peek(";"_s) == false) {
			$var($String, key, match("option key"_s));
			match("="_s);
			try {
				options->put(key, $(expand($(match("option value"_s)))));
			} catch ($PropertyExpander$ExpandException& peee) {
				$throwNew($IOException, $(peee->getLocalizedMessage()));
			}
		}
		this->lookahead = nextToken();
		if (ConfigFile$Spi::debugParser != nullptr) {
			$nc(ConfigFile$Spi::debugParser)->println($$str({"\t\t"_s, moduleClass, ", "_s, sflag}));
			{
				$var($Iterator, i$, $nc($(options->keySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($String, key, $cast($String, i$->next()));
					{
						$nc(ConfigFile$Spi::debugParser)->println($$str({"\t\t\t"_s, key, "="_s, $cast($String, $(options->get(key)))}));
					}
				}
			}
		}
		configEntries->add($$new($AppConfigurationEntry, moduleClass, controlFlag, options));
	}
	match("}"_s);
	match(";"_s);
	if ($nc(newConfig)->containsKey(appName)) {
		$throw($(ioException("Configuration.Error.Can.not.specify.multiple.entries.for.appName"_s, $$new($ObjectArray, {$of(appName)}))));
	}
	$nc(newConfig)->put(appName, configEntries);
}

$String* ConfigFile$Spi::match($String* expect) {
	$useLocalCurrentObjectStackCache();
	$var($String, value, nullptr);
	switch (this->lookahead) {
	case $StreamTokenizer::TT_EOF:
		{
			$throw($(ioException("Configuration.Error.expected.expect.read.end.of.file."_s, $$new($ObjectArray, {$of(expect)}))));
		}
	case u'\"':
		{}
	case $StreamTokenizer::TT_WORD:
		{
			bool var$2 = $nc(expect)->equalsIgnoreCase("module class name"_s);
			bool var$1 = var$2 || $nc(expect)->equalsIgnoreCase("controlFlag"_s);
			bool var$0 = var$1 || $nc(expect)->equalsIgnoreCase("option key"_s);
			if (var$0 || $nc(expect)->equalsIgnoreCase("option value"_s)) {
				$assign(value, $nc(this->st)->sval);
				this->lookahead = nextToken();
			} else {
				$throw($(ioException("Configuration.Error.Line.line.expected.expect.found.value."_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(this->linenum))),
					$of(expect),
					$of($nc(this->st)->sval)
				}))));
			}
			break;
		}
	case u'{':
		{
			if ($nc(expect)->equalsIgnoreCase("{"_s)) {
				this->lookahead = nextToken();
			} else {
				$throw($(ioException("Configuration.Error.Line.line.expected.expect."_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(this->linenum))),
					$of(expect),
					$of($nc(this->st)->sval)
				}))));
			}
			break;
		}
	case u';':
		{
			if ($nc(expect)->equalsIgnoreCase(";"_s)) {
				this->lookahead = nextToken();
			} else {
				$throw($(ioException("Configuration.Error.Line.line.expected.expect."_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(this->linenum))),
					$of(expect),
					$of($nc(this->st)->sval)
				}))));
			}
			break;
		}
	case u'}':
		{
			if ($nc(expect)->equalsIgnoreCase("}"_s)) {
				this->lookahead = nextToken();
			} else {
				$throw($(ioException("Configuration.Error.Line.line.expected.expect."_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(this->linenum))),
					$of(expect),
					$of($nc(this->st)->sval)
				}))));
			}
			break;
		}
	case u'=':
		{
			if ($nc(expect)->equalsIgnoreCase("="_s)) {
				this->lookahead = nextToken();
			} else {
				$throw($(ioException("Configuration.Error.Line.line.expected.expect."_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(this->linenum))),
					$of(expect),
					$of($nc(this->st)->sval)
				}))));
			}
			break;
		}
	default:
		{
			$throw($(ioException("Configuration.Error.Line.line.expected.expect.found.value."_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(this->linenum))),
				$of(expect),
				$of($nc(this->st)->sval)
			}))));
		}
	}
	return value;
}

bool ConfigFile$Spi::peek($String* expect) {
	switch (this->lookahead) {
	case u',':
		{
			return $nc(expect)->equalsIgnoreCase(","_s);
		}
	case u';':
		{
			return $nc(expect)->equalsIgnoreCase(";"_s);
		}
	case u'{':
		{
			return $nc(expect)->equalsIgnoreCase("{"_s);
		}
	case u'}':
		{
			return $nc(expect)->equalsIgnoreCase("}"_s);
		}
	default:
		{
			return false;
		}
	}
}

int32_t ConfigFile$Spi::nextToken() {
	int32_t tok = 0;
	while ((tok = $nc(this->st)->nextToken()) == $StreamTokenizer::TT_EOL) {
		++this->linenum;
	}
	return tok;
}

$InputStream* ConfigFile$Spi::getInputStream($URL* url) {
	$useLocalCurrentObjectStackCache();
	if ("file"_s->equalsIgnoreCase($($nc(url)->getProtocol()))) {
		try {
			return $nc(url)->openStream();
		} catch ($Exception& e) {
			$var($String, file, $nc(url)->getPath());
			if (!$nc($(url->getHost()))->isEmpty()) {
				$assign(file, $str({"//"_s, $(url->getHost()), file}));
			}
			if (ConfigFile$Spi::debugConfig != nullptr) {
				$nc(ConfigFile$Spi::debugConfig)->println($$str({"cannot read "_s, url, ", try "_s, file}));
			}
			return $new($FileInputStream, file);
		}
	} else {
		return $nc(url)->openStream();
	}
}

$String* ConfigFile$Spi::expand($String* value) {
	$useLocalCurrentObjectStackCache();
	if ($nc(value)->isEmpty()) {
		return value;
	}
	if (!this->expandProp) {
		return value;
	}
	$var($String, s, $PropertyExpander::expand(value));
	if (s == nullptr || $nc(s)->isEmpty()) {
		$throw($(ioException("Configuration.Error.Line.line.system.property.value.expanded.to.empty.value"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(this->linenum))),
			$of(value)
		}))));
	}
	return s;
}

$IOException* ConfigFile$Spi::ioException($String* resourceKey, $ObjectArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($MessageFormat, form, $new($MessageFormat, $($ResourcesMgr::getAuthResourceString(resourceKey))));
	return $new($IOException, $(form->format(args)));
}

void clinit$ConfigFile$Spi($Class* class$) {
	$assignStatic(ConfigFile$Spi::debugConfig, $Debug::getInstance("configfile"_s));
	$assignStatic(ConfigFile$Spi::debugParser, $Debug::getInstance("configparser"_s));
}

ConfigFile$Spi::ConfigFile$Spi() {
}

$Class* ConfigFile$Spi::load$($String* name, bool initialize) {
	$loadClass(ConfigFile$Spi, name, initialize, &_ConfigFile$Spi_ClassInfo_, clinit$ConfigFile$Spi, allocate$ConfigFile$Spi);
	return class$;
}

$Class* ConfigFile$Spi::class$ = nullptr;

		} // provider
	} // security
} // sun
#include <jdk/internal/util/SystemProps.h>

#include <java/lang/AssertionError.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jdk/internal/util/SystemProps$Raw.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $SystemProps$Raw = ::jdk::internal::util::SystemProps$Raw;

namespace jdk {
	namespace internal {
		namespace util {

$FieldInfo _SystemProps_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SystemProps, $assertionsDisabled)},
	{}
};

$MethodInfo _SystemProps_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SystemProps, init$, void)},
	{"fillI18nProps", "(Ljava/util/HashMap;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", "(Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(SystemProps, fillI18nProps, void, $HashMap*, $String*, $String*, $String*)},
	{"initProperties", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC, $staticMethod(SystemProps, initProperties, $Map*)},
	{"put", "(Ljava/util/HashMap;Ljava/lang/String;Ljava/lang/String;)V", "(Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;Ljava/lang/String;Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(SystemProps, put, void, $HashMap*, $String*, $String*)},
	{"putIfAbsent", "(Ljava/util/HashMap;Ljava/lang/String;Ljava/lang/String;)V", "(Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/String;>;Ljava/lang/String;Ljava/lang/String;)V", $PRIVATE | $STATIC, $staticMethod(SystemProps, putIfAbsent, void, $HashMap*, $String*, $String*)},
	{}
};

$InnerClassInfo _SystemProps_InnerClassesInfo_[] = {
	{"jdk.internal.util.SystemProps$Raw", "jdk.internal.util.SystemProps", "Raw", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _SystemProps_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.util.SystemProps",
	"java.lang.Object",
	nullptr,
	_SystemProps_FieldInfo_,
	_SystemProps_MethodInfo_,
	nullptr,
	nullptr,
	_SystemProps_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.util.SystemProps$Raw"
};

$Object* allocate$SystemProps($Class* clazz) {
	return $of($alloc(SystemProps));
}

bool SystemProps::$assertionsDisabled = false;

void SystemProps::init$() {
}

$Map* SystemProps::initProperties() {
	$init(SystemProps);
	$useLocalCurrentObjectStackCache();
	$var($SystemProps$Raw, raw, $new($SystemProps$Raw));
	$var($HashMap, props, raw->cmdProperties());
	$var($String, javaHome, $cast($String, $nc(props)->get("java.home"_s)));
	if (!SystemProps::$assertionsDisabled && !(javaHome != nullptr)) {
		$throwNew($AssertionError, $of("java.home not set"_s));
	}
	putIfAbsent(props, "user.home"_s, $(raw->propDefault($SystemProps$Raw::_user_home_NDX)));
	putIfAbsent(props, "user.dir"_s, $(raw->propDefault($SystemProps$Raw::_user_dir_NDX)));
	putIfAbsent(props, "user.name"_s, $(raw->propDefault($SystemProps$Raw::_user_name_NDX)));
	put(props, "sun.jnu.encoding"_s, $(raw->propDefault($SystemProps$Raw::_sun_jnu_encoding_NDX)));
	$var($String, nativeEncoding, (raw->propDefault($SystemProps$Raw::_file_encoding_NDX) == nullptr) ? raw->propDefault($SystemProps$Raw::_sun_jnu_encoding_NDX) : raw->propDefault($SystemProps$Raw::_file_encoding_NDX));
	put(props, "native.encoding"_s, nativeEncoding);
	putIfAbsent(props, "file.encoding"_s, nativeEncoding);
	putIfAbsent(props, "os.name"_s, $(raw->propDefault($SystemProps$Raw::_os_name_NDX)));
	putIfAbsent(props, "os.arch"_s, $(raw->propDefault($SystemProps$Raw::_os_arch_NDX)));
	putIfAbsent(props, "os.version"_s, $(raw->propDefault($SystemProps$Raw::_os_version_NDX)));
	putIfAbsent(props, "line.separator"_s, $(raw->propDefault($SystemProps$Raw::_line_separator_NDX)));
	putIfAbsent(props, "file.separator"_s, $(raw->propDefault($SystemProps$Raw::_file_separator_NDX)));
	putIfAbsent(props, "path.separator"_s, $(raw->propDefault($SystemProps$Raw::_path_separator_NDX)));
	putIfAbsent(props, "java.io.tmpdir"_s, $(raw->propDefault($SystemProps$Raw::_java_io_tmpdir_NDX)));
	putIfAbsent(props, "http.proxyHost"_s, $(raw->propDefault($SystemProps$Raw::_http_proxyHost_NDX)));
	putIfAbsent(props, "http.proxyPort"_s, $(raw->propDefault($SystemProps$Raw::_http_proxyPort_NDX)));
	putIfAbsent(props, "https.proxyHost"_s, $(raw->propDefault($SystemProps$Raw::_https_proxyHost_NDX)));
	putIfAbsent(props, "https.proxyPort"_s, $(raw->propDefault($SystemProps$Raw::_https_proxyPort_NDX)));
	putIfAbsent(props, "ftp.proxyHost"_s, $(raw->propDefault($SystemProps$Raw::_ftp_proxyHost_NDX)));
	putIfAbsent(props, "ftp.proxyPort"_s, $(raw->propDefault($SystemProps$Raw::_ftp_proxyPort_NDX)));
	putIfAbsent(props, "socksProxyHost"_s, $(raw->propDefault($SystemProps$Raw::_socksProxyHost_NDX)));
	putIfAbsent(props, "socksProxyPort"_s, $(raw->propDefault($SystemProps$Raw::_socksProxyPort_NDX)));
	putIfAbsent(props, "http.nonProxyHosts"_s, $(raw->propDefault($SystemProps$Raw::_http_nonProxyHosts_NDX)));
	putIfAbsent(props, "ftp.nonProxyHosts"_s, $(raw->propDefault($SystemProps$Raw::_ftp_nonProxyHosts_NDX)));
	putIfAbsent(props, "socksNonProxyHosts"_s, $(raw->propDefault($SystemProps$Raw::_socksNonProxyHosts_NDX)));
	putIfAbsent(props, "sun.arch.abi"_s, $(raw->propDefault($SystemProps$Raw::_sun_arch_abi_NDX)));
	putIfAbsent(props, "sun.arch.data.model"_s, $(raw->propDefault($SystemProps$Raw::_sun_arch_data_model_NDX)));
	putIfAbsent(props, "sun.os.patch.level"_s, $(raw->propDefault($SystemProps$Raw::_sun_os_patch_level_NDX)));
	putIfAbsent(props, "sun.stdout.encoding"_s, $(raw->propDefault($SystemProps$Raw::_sun_stdout_encoding_NDX)));
	putIfAbsent(props, "sun.stderr.encoding"_s, $(raw->propDefault($SystemProps$Raw::_sun_stderr_encoding_NDX)));
	putIfAbsent(props, "sun.io.unicode.encoding"_s, $(raw->propDefault($SystemProps$Raw::_sun_io_unicode_encoding_NDX)));
	putIfAbsent(props, "sun.cpu.isalist"_s, $(raw->propDefault($SystemProps$Raw::_sun_cpu_isalist_NDX)));
	putIfAbsent(props, "sun.cpu.endian"_s, $(raw->propDefault($SystemProps$Raw::_sun_cpu_endian_NDX)));
	$var($HashMap, var$0, props);
	$var($String, var$1, "user.language"_s);
	$var($String, var$2, raw->propDefault($SystemProps$Raw::_display_language_NDX));
	fillI18nProps(var$0, var$1, var$2, $(raw->propDefault($SystemProps$Raw::_format_language_NDX)));
	$var($HashMap, var$3, props);
	$var($String, var$4, "user.script"_s);
	$var($String, var$5, raw->propDefault($SystemProps$Raw::_display_script_NDX));
	fillI18nProps(var$3, var$4, var$5, $(raw->propDefault($SystemProps$Raw::_format_script_NDX)));
	$var($HashMap, var$6, props);
	$var($String, var$7, "user.country"_s);
	$var($String, var$8, raw->propDefault($SystemProps$Raw::_display_country_NDX));
	fillI18nProps(var$6, var$7, var$8, $(raw->propDefault($SystemProps$Raw::_format_country_NDX)));
	$var($HashMap, var$9, props);
	$var($String, var$10, "user.variant"_s);
	$var($String, var$11, raw->propDefault($SystemProps$Raw::_display_variant_NDX));
	fillI18nProps(var$9, var$10, var$11, $(raw->propDefault($SystemProps$Raw::_format_variant_NDX)));
	return props;
}

void SystemProps::put($HashMap* props, $String* key, $String* value) {
	$init(SystemProps);
	if (value != nullptr) {
		$nc(props)->put(key, value);
	}
}

void SystemProps::putIfAbsent($HashMap* props, $String* key, $String* value) {
	$init(SystemProps);
	if (value != nullptr) {
		$nc(props)->putIfAbsent(key, value);
	}
}

void SystemProps::fillI18nProps($HashMap* cmdProps, $String* base, $String* display, $String* format) {
	$init(SystemProps);
	$useLocalCurrentObjectStackCache();
	$var($String, baseValue, $cast($String, $nc(cmdProps)->get(base)));
	if (baseValue != nullptr) {
		return;
	}
	if (display != nullptr) {
		cmdProps->put(base, display);
		$assign(baseValue, display);
	}
	$var($String, disp, $nc(base)->concat(".display"_s));
	$var($String, dispValue, $cast($String, cmdProps->get(disp)));
	if (dispValue == nullptr && display != nullptr && !display->equals(baseValue)) {
		cmdProps->put(disp, display);
	}
	$var($String, fmt, base->concat(".format"_s));
	$var($String, fmtValue, $cast($String, cmdProps->get(fmt)));
	if (fmtValue == nullptr && format != nullptr && !format->equals(baseValue)) {
		cmdProps->put(fmt, format);
	}
}

void clinit$SystemProps($Class* class$) {
	SystemProps::$assertionsDisabled = !SystemProps::class$->desiredAssertionStatus();
}

SystemProps::SystemProps() {
}

$Class* SystemProps::load$($String* name, bool initialize) {
	$loadClass(SystemProps, name, initialize, &_SystemProps_ClassInfo_, clinit$SystemProps, allocate$SystemProps);
	return class$;
}

$Class* SystemProps::class$ = nullptr;

		} // util
	} // internal
} // jdk
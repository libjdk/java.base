#machine generated

if(BUILD_SHARED_LIB)
	add_definitions(-DJCPP_SHARED_BUILD)
endif()

include_directories("share/classes")
include_directories("share/native")

if(JCPP_OS MATCHES "linux")
	include_directories("linux/classes")
	include_directories("linux/native")
endif()

if(JCPP_OS MATCHES "macos")
	include_directories("macos/classes")
	include_directories("macos/native")
endif()

if(JCPP_OS MATCHES "windows")
	include_directories("windows/classes")
	include_directories("windows/native")
endif()

add_subdirectory("share/classes")
add_subdirectory("share/native")

if(JCPP_OS MATCHES "linux")
	add_subdirectory("linux/classes")
	add_subdirectory("linux/native")
endif()

if(JCPP_OS MATCHES "macos")
	add_subdirectory("macos/classes")
	add_subdirectory("macos/native")
endif()

if(JCPP_OS MATCHES "windows")
	add_subdirectory("windows/classes")
	add_subdirectory("windows/native")
endif()

set(local_object ${local_object}
	"$<TARGET_OBJECTS:com.sun.crypto.provider>"
	"$<TARGET_OBJECTS:com.sun.security.ntlm>"
	"$<TARGET_OBJECTS:java.io>"
	"$<TARGET_OBJECTS:java.lang>"
	"$<TARGET_OBJECTS:java.lang.annotation>"
	"$<TARGET_OBJECTS:java.lang.constant>"
	"$<TARGET_OBJECTS:java.lang.interpreter>"
	"$<TARGET_OBJECTS:java.lang.invoke>"
	"$<TARGET_OBJECTS:java.lang.module>"
	"$<TARGET_OBJECTS:java.lang.ref>"
	"$<TARGET_OBJECTS:java.lang.reflect>"
	"$<TARGET_OBJECTS:java.lang.runtime>"
	"$<TARGET_OBJECTS:java.math>"
	"$<TARGET_OBJECTS:java.net>"
	"$<TARGET_OBJECTS:java.net.spi>"
	"$<TARGET_OBJECTS:java.nio>"
	"$<TARGET_OBJECTS:java.nio.channels>"
	"$<TARGET_OBJECTS:java.nio.channels.spi>"
	"$<TARGET_OBJECTS:java.nio.charset>"
	"$<TARGET_OBJECTS:java.nio.charset.spi>"
	"$<TARGET_OBJECTS:java.nio.file>"
	"$<TARGET_OBJECTS:java.nio.file.attribute>"
	"$<TARGET_OBJECTS:java.nio.file.spi>"
	"$<TARGET_OBJECTS:java.security>"
	"$<TARGET_OBJECTS:java.security.cert>"
	"$<TARGET_OBJECTS:java.security.interfaces>"
	"$<TARGET_OBJECTS:java.security.spec>"
	"$<TARGET_OBJECTS:java.text>"
	"$<TARGET_OBJECTS:java.text.spi>"
	"$<TARGET_OBJECTS:java.time>"
	"$<TARGET_OBJECTS:java.time.chrono>"
	"$<TARGET_OBJECTS:java.time.format>"
	"$<TARGET_OBJECTS:java.time.temporal>"
	"$<TARGET_OBJECTS:java.time.zone>"
	"$<TARGET_OBJECTS:java.util>"
	"$<TARGET_OBJECTS:java.util.concurrent>"
	"$<TARGET_OBJECTS:java.util.concurrent.atomic>"
	"$<TARGET_OBJECTS:java.util.concurrent.locks>"
	"$<TARGET_OBJECTS:java.util.function>"
	"$<TARGET_OBJECTS:java.util.jar>"
	"$<TARGET_OBJECTS:java.util.random>"
	"$<TARGET_OBJECTS:java.util.regex>"
	"$<TARGET_OBJECTS:java.util.spi>"
	"$<TARGET_OBJECTS:java.util.stream>"
	"$<TARGET_OBJECTS:java.util.zip>"
	"$<TARGET_OBJECTS:javax.crypto>"
	"$<TARGET_OBJECTS:javax.crypto.interfaces>"
	"$<TARGET_OBJECTS:javax.crypto.spec>"
	"$<TARGET_OBJECTS:javax.net>"
	"$<TARGET_OBJECTS:javax.net.ssl>"
	"$<TARGET_OBJECTS:javax.security.auth>"
	"$<TARGET_OBJECTS:javax.security.auth.callback>"
	"$<TARGET_OBJECTS:javax.security.auth.login>"
	"$<TARGET_OBJECTS:javax.security.auth.spi>"
	"$<TARGET_OBJECTS:javax.security.auth.x500>"
	"$<TARGET_OBJECTS:javax.security.cert>"
	"$<TARGET_OBJECTS:jdk.internal>"
	"$<TARGET_OBJECTS:jdk.internal.access>"
	"$<TARGET_OBJECTS:jdk.internal.access.foreign>"
	"$<TARGET_OBJECTS:jdk.internal.event>"
	"$<TARGET_OBJECTS:jdk.internal.icu.impl>"
	"$<TARGET_OBJECTS:jdk.internal.icu.impl.data.icu>"
	"$<TARGET_OBJECTS:jdk.internal.icu.lang>"
	"$<TARGET_OBJECTS:jdk.internal.icu.text>"
	"$<TARGET_OBJECTS:jdk.internal.icu.util>"
	"$<TARGET_OBJECTS:jdk.internal.invoke>"
	"$<TARGET_OBJECTS:jdk.internal.javac>"
	"$<TARGET_OBJECTS:jdk.internal.jimage>"
	"$<TARGET_OBJECTS:jdk.internal.jimage.decompress>"
	"$<TARGET_OBJECTS:jdk.internal.jmod>"
	"$<TARGET_OBJECTS:jdk.internal.jrtfs>"
	"$<TARGET_OBJECTS:jdk.internal.loader>"
	"$<TARGET_OBJECTS:jdk.internal.logger>"
	"$<TARGET_OBJECTS:jdk.internal.math>"
	"$<TARGET_OBJECTS:jdk.internal.misc>"
	"$<TARGET_OBJECTS:jdk.internal.module>"
	"$<TARGET_OBJECTS:jdk.internal.org.objectweb.asm>"
	"$<TARGET_OBJECTS:jdk.internal.org.objectweb.a_0>"
	"$<TARGET_OBJECTS:jdk.internal.org.objectweb.a_1>"
	"$<TARGET_OBJECTS:jdk.internal.org.objectweb.a_2>"
	"$<TARGET_OBJECTS:jdk.internal.org.objectweb.a_3>"
	"$<TARGET_OBJECTS:jdk.internal.org.objectweb.a_4>"
	"$<TARGET_OBJECTS:jdk.internal.org.xml.sax>"
	"$<TARGET_OBJECTS:jdk.internal.org.xml.sax.helpe>"
	"$<TARGET_OBJECTS:jdk.internal.perf>"
	"$<TARGET_OBJECTS:jdk.internal.platform>"
	"$<TARGET_OBJECTS:jdk.internal.ref>"
	"$<TARGET_OBJECTS:jdk.internal.reflect>"
	"$<TARGET_OBJECTS:jdk.internal.util>"
	"$<TARGET_OBJECTS:jdk.internal.util.jar>"
	"$<TARGET_OBJECTS:jdk.internal.util.random>"
	"$<TARGET_OBJECTS:jdk.internal.util.xml>"
	"$<TARGET_OBJECTS:jdk.internal.util.xml.impl>"
	"$<TARGET_OBJECTS:jdk.internal.vm>"
	"$<TARGET_OBJECTS:jdk.internal.vm.annotation>"
	"$<TARGET_OBJECTS:jdk.internal.vm.vector>"
	"$<TARGET_OBJECTS:META-INF.services>"
	"$<TARGET_OBJECTS:sun.invoke>"
	"$<TARGET_OBJECTS:sun.invoke.empty>"
	"$<TARGET_OBJECTS:sun.invoke.util>"
	"$<TARGET_OBJECTS:sun.launcher>"
	"$<TARGET_OBJECTS:sun.launcher.resources>"
	"$<TARGET_OBJECTS:sun.net>"
	"$<TARGET_OBJECTS:sun.net.dns>"
	"$<TARGET_OBJECTS:sun.net.ext>"
	"$<TARGET_OBJECTS:sun.net.ftp>"
	"$<TARGET_OBJECTS:sun.net.ftp.impl>"
	"$<TARGET_OBJECTS:sun.net.idn>"
	"$<TARGET_OBJECTS:sun.net.sdp>"
	"$<TARGET_OBJECTS:sun.net.smtp>"
	"$<TARGET_OBJECTS:sun.net.spi>"
	"$<TARGET_OBJECTS:sun.net.util>"
	"$<TARGET_OBJECTS:sun.net.www>"
	"$<TARGET_OBJECTS:sun.net.www.content.text>"
	"$<TARGET_OBJECTS:sun.net.www.http>"
	"$<TARGET_OBJECTS:sun.net.www.protocol.file>"
	"$<TARGET_OBJECTS:sun.net.www.protocol.ftp>"
	"$<TARGET_OBJECTS:sun.net.www.protocol.http>"
	"$<TARGET_OBJECTS:sun.net.www.protocol.http.ntlm>"
	"$<TARGET_OBJECTS:sun.net.www.protocol.https>"
	"$<TARGET_OBJECTS:sun.net.www.protocol.jar>"
	"$<TARGET_OBJECTS:sun.net.www.protocol.jmod>"
	"$<TARGET_OBJECTS:sun.net.www.protocol.jrt>"
	"$<TARGET_OBJECTS:sun.net.www.protocol.mailto>"
	"$<TARGET_OBJECTS:sun.nio>"
	"$<TARGET_OBJECTS:sun.nio.ch>"
	"$<TARGET_OBJECTS:sun.nio.cs>"
	"$<TARGET_OBJECTS:sun.nio.fs>"
	"$<TARGET_OBJECTS:sun.reflect.annotation>"
	"$<TARGET_OBJECTS:sun.reflect.generics.factory>"
	"$<TARGET_OBJECTS:sun.reflect.generics.parser>"
	"$<TARGET_OBJECTS:sun.reflect.generics.reflectiv>"
	"$<TARGET_OBJECTS:sun.reflect.generics.repositor>"
	"$<TARGET_OBJECTS:sun.reflect.generics.scope>"
	"$<TARGET_OBJECTS:sun.reflect.generics.tree>"
	"$<TARGET_OBJECTS:sun.reflect.generics.visitor>"
	"$<TARGET_OBJECTS:sun.reflect.misc>"
	"$<TARGET_OBJECTS:sun.security.action>"
	"$<TARGET_OBJECTS:sun.security.internal.interfac>"
	"$<TARGET_OBJECTS:sun.security.internal.spec>"
	"$<TARGET_OBJECTS:sun.security.jca>"
	"$<TARGET_OBJECTS:sun.security.pkcs>"
	"$<TARGET_OBJECTS:sun.security.pkcs10>"
	"$<TARGET_OBJECTS:sun.security.pkcs12>"
	"$<TARGET_OBJECTS:sun.security.provider>"
	"$<TARGET_OBJECTS:sun.security.provider.certpath>"
	"$<TARGET_OBJECTS:sun.security.provider.certpa_5>"
	"$<TARGET_OBJECTS:sun.security.rsa>"
	"$<TARGET_OBJECTS:sun.security.ssl>"
	"$<TARGET_OBJECTS:sun.security.timestamp>"
	"$<TARGET_OBJECTS:sun.security.tools>"
	"$<TARGET_OBJECTS:sun.security.tools.keytool>"
	"$<TARGET_OBJECTS:sun.security.util>"
	"$<TARGET_OBJECTS:sun.security.util.math>"
	"$<TARGET_OBJECTS:sun.security.util.math.intpoly>"
	"$<TARGET_OBJECTS:sun.security.validator>"
	"$<TARGET_OBJECTS:sun.security.x509>"
	"$<TARGET_OBJECTS:sun.text>"
	"$<TARGET_OBJECTS:sun.text.resources>"
	"$<TARGET_OBJECTS:sun.text.resources.cldr>"
	"$<TARGET_OBJECTS:sun.text.spi>"
	"$<TARGET_OBJECTS:sun.util>"
	"$<TARGET_OBJECTS:sun.util.calendar>"
	"$<TARGET_OBJECTS:sun.util.cldr>"
	"$<TARGET_OBJECTS:sun.util.locale>"
	"$<TARGET_OBJECTS:sun.util.locale.provider>"
	"$<TARGET_OBJECTS:sun.util.logging>"
	"$<TARGET_OBJECTS:sun.util.resources>"
	"$<TARGET_OBJECTS:sun.util.resources.cldr>"
	"$<TARGET_OBJECTS:sun.util.spi>"
)

if(JCPP_OS MATCHES "linux")
	set(local_object ${local_object}
		"$<TARGET_OBJECTS:linux>"
		"$<TARGET_OBJECTS:linux.java.io>"
		"$<TARGET_OBJECTS:linux.java.lang>"
		"$<TARGET_OBJECTS:linux.java.net>"
		"$<TARGET_OBJECTS:linux.java.nio.file>"
		"$<TARGET_OBJECTS:linux.jdk.internal.loader>"
		"$<TARGET_OBJECTS:linux.jdk.internal.misc>"
		"$<TARGET_OBJECTS:linux.jdk.internal.module>"
		"$<TARGET_OBJECTS:linux.jdk.internal.platform>"
		"$<TARGET_OBJECTS:linux.jdk.internal.platform.cg>"
		"$<TARGET_OBJECTS:linux.jdk.internal.platform._6>"
		"$<TARGET_OBJECTS:linux.sun.net>"
		"$<TARGET_OBJECTS:linux.sun.net.dns>"
		"$<TARGET_OBJECTS:linux.sun.net.sdp>"
		"$<TARGET_OBJECTS:linux.sun.net.www.protocol.fil>"
		"$<TARGET_OBJECTS:linux.sun.net.www.protocol.h_7>"
		"$<TARGET_OBJECTS:linux.sun.net.www.protocol.jar>"
		"$<TARGET_OBJECTS:linux.sun.nio.ch>"
		"$<TARGET_OBJECTS:linux.sun.nio.cs>"
		"$<TARGET_OBJECTS:linux.sun.nio.fs>"
		"$<TARGET_OBJECTS:linux.sun.security.provider>"
	)
endif()

if(JCPP_OS MATCHES "macos")
	set(local_object ${local_object}
		"$<TARGET_OBJECTS:macos>"
		"$<TARGET_OBJECTS:macos.apple.security>"
		"$<TARGET_OBJECTS:macos.java.io>"
		"$<TARGET_OBJECTS:macos.java.lang>"
		"$<TARGET_OBJECTS:macos.java.net>"
		"$<TARGET_OBJECTS:macos.java.nio.file>"
		"$<TARGET_OBJECTS:macos.jdk.internal.loader>"
		"$<TARGET_OBJECTS:macos.jdk.internal.misc>"
		"$<TARGET_OBJECTS:macos.jdk.internal.module>"
		"$<TARGET_OBJECTS:macos.jdk.internal.platform>"
		"$<TARGET_OBJECTS:macos.sun.net>"
		"$<TARGET_OBJECTS:macos.sun.net.dns>"
		"$<TARGET_OBJECTS:macos.sun.net.sdp>"
		"$<TARGET_OBJECTS:macos.sun.net.www.protocol.fil>"
		"$<TARGET_OBJECTS:macos.sun.net.www.protocol.h_8>"
		"$<TARGET_OBJECTS:macos.sun.net.www.protocol.jar>"
		"$<TARGET_OBJECTS:macos.sun.nio.ch>"
		"$<TARGET_OBJECTS:macos.sun.nio.cs>"
		"$<TARGET_OBJECTS:macos.sun.nio.fs>"
		"$<TARGET_OBJECTS:macos.sun.security.provider>"
		"$<TARGET_OBJECTS:macos.sun.util.locale.provider>"
	)
endif()

if(JCPP_OS MATCHES "windows")
	set(local_object ${local_object}
		"$<TARGET_OBJECTS:windows>"
		"$<TARGET_OBJECTS:windows.java.io>"
		"$<TARGET_OBJECTS:windows.java.lang>"
		"$<TARGET_OBJECTS:windows.java.net>"
		"$<TARGET_OBJECTS:windows.java.nio.file>"
		"$<TARGET_OBJECTS:windows.jdk.internal.loader>"
		"$<TARGET_OBJECTS:windows.jdk.internal.misc>"
		"$<TARGET_OBJECTS:windows.jdk.internal.module>"
		"$<TARGET_OBJECTS:windows.jdk.internal.platform>"
		"$<TARGET_OBJECTS:windows.sun.io>"
		"$<TARGET_OBJECTS:windows.sun.net>"
		"$<TARGET_OBJECTS:windows.sun.net.dns>"
		"$<TARGET_OBJECTS:windows.sun.net.www.protocol.f>"
		"$<TARGET_OBJECTS:windows.sun.net.www.protocol_9>"
		"$<TARGET_OBJECTS:windows.sun.net.www.protocol.j>"
		"$<TARGET_OBJECTS:windows.sun.nio.ch>"
		"$<TARGET_OBJECTS:windows.sun.nio.cs>"
		"$<TARGET_OBJECTS:windows.sun.nio.fs>"
		"$<TARGET_OBJECTS:windows.sun.security.provider>"
		"$<TARGET_OBJECTS:windows.sun.util.locale.provid>"
	)
endif()

if(BUILD_STATIC_LIB)
	add_library(${JCPP_PROJECT_NAME}-main STATIC ${local_object} ${source_SRCS})
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}-main PROPERTIES OUTPUT_NAME "${JCPP_PROJECT_FULL_NAME}")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}-main PROPERTIES CLEAN_DIRECT_OUTPUT 1)
endif()

if(BUILD_SHARED_LIB)
	add_library(${JCPP_PROJECT_NAME}-main SHARED ${local_object} ${source_SRCS})
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}-main PROPERTIES OUTPUT_NAME "${JCPP_PROJECT_FULL_NAME}")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}-main PROPERTIES CLEAN_DIRECT_OUTPUT 1)
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}-main PROPERTIES VERSION ${JCPP_PROJECT_VERSION} SOVERSION 1)
	if(JCPP_OS MATCHES "linux")
		SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}-main PROPERTIES INSTALL_RPATH "\$ORIGIN;\$ORIGIN/../lib")
	elseif(JCPP_OS MATCHES "macos")
		SET_TARGET_PROPERTIES(${JCPP_PROJECT_NAME}-main PROPERTIES INSTALL_RPATH ".;../lib")
	endif()
	if(JCPP_OS MATCHES "linux")
		set(JCPP_EXT_LIBS ${JCPP_EXT_LIBS}
			pthread dl
		)
	endif()
	if(JCPP_OS MATCHES "macos")
		set(JCPP_EXT_LIBS ${JCPP_EXT_LIBS}
			"-framework CoreFoundation"
			"-framework Foundation"
			"-framework SystemConfiguration"
			"-framework Cocoa"
			"-framework Security"
			"-framework ApplicationServices"
		)
	endif()
	if(JCPP_OS MATCHES "windows")
		set(JCPP_EXT_LIBS ${JCPP_EXT_LIBS}
			wsock32 ws2_32 Iphlpapi Winhttp Secur32 Version Winmm Psapi
			advapi32.lib comctl32.lib user32.lib
		)
	endif()
	target_link_libraries(${JCPP_PROJECT_NAME}-main
		PUBLIC ${JCPP_DEPENDENCY_LIBS}
		PRIVATE ${JCPP_EXT_LIBS}
	)
	jcpp_encode_symbol(${JCPP_PROJECT_NAME}-main)
endif()

jcpp_enable_bigobj(${JCPP_PROJECT_NAME}-main)
install(TARGETS ${JCPP_PROJECT_NAME}-main
	LIBRARY DESTINATION "${JCPP_INSTALL_LIB_DIR}"
	ARCHIVE DESTINATION "${JCPP_INSTALL_LIB_DIR}"
	RUNTIME DESTINATION "${JCPP_INSTALL_BIN_DIR}"
)


install(
	DIRECTORY "share/include/"
	DESTINATION "${JCPP_INSTALL_INCLUDE_DIR}"
)

if(JCPP_OS MATCHES "linux")
	install(
		DIRECTORY "linux/include/"
		DESTINATION "${JCPP_INSTALL_INCLUDE_DIR}"
	)
endif()

if(JCPP_OS MATCHES "macos")
	install(
		DIRECTORY "macos/include/"
		DESTINATION "${JCPP_INSTALL_INCLUDE_DIR}"
	)
endif()

if(JCPP_OS MATCHES "windows")
	install(
		DIRECTORY "windows/include/"
		DESTINATION "${JCPP_INSTALL_INCLUDE_DIR}"
	)
endif()

#machine generated

include_directories("share/classes")
include_directories("../main/share/include")

if(JCPP_OS MATCHES "linux")
	include_directories("../main/linux/include")
endif()

if(JCPP_OS MATCHES "macos")
	include_directories("../main/macos/include")
endif()

if(JCPP_OS MATCHES "windows")
	include_directories("../main/windows/include")
endif()

add_subdirectory("share/classes")

if(JCPP_SUBSYSTEM MATCHES "WINDOWS")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
	add_definitions(-DJCPP_SUBSYSTEM_WINDOWS)
	message(STATUS "set the WINDOWS subsystem for the executable")
endif()

aux_source_directory("share" source_SRCS)

set(local_object ${local_object}
	"$<TARGET_OBJECTS:checkclassadapter>"
)

add_executable(${JCPP_PROJECT_FULL_NAME}-checkclassadapter "${local_object}" "${source_SRCS}")

SET_TARGET_PROPERTIES(${JCPP_PROJECT_FULL_NAME}-checkclassadapter PROPERTIES OUTPUT_NAME "checkclassadapter")
if(JCPP_OS MATCHES "linux")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_FULL_NAME}-checkclassadapter PROPERTIES INSTALL_RPATH "\$ORIGIN;\$ORIGIN/../lib")
elseif(JCPP_OS MATCHES "macos")
	SET_TARGET_PROPERTIES(${JCPP_PROJECT_FULL_NAME}-checkclassadapter PROPERTIES INSTALL_RPATH ".;../lib")
endif()

jcpp_encode_symbol(${JCPP_PROJECT_FULL_NAME}-checkclassadapter)

if(BUILD_SHARED_LIB)
	target_link_libraries(${JCPP_PROJECT_FULL_NAME}-checkclassadapter
		PRIVATE ${JCPP_DEPENDENCY_LIBS}
		PRIVATE ${JCPP_PROJECT_NAME}-main
	)
	if(JCPP_OS MATCHES "windows")
		foreach(runtimeFile IN LISTS JCPP_DEPENDENCY_RUNTIME_FILE_PATHS)
			add_custom_command(TARGET ${JCPP_PROJECT_FULL_NAME}-checkclassadapter POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy_if_different
					${runtimeFile}
					$<TARGET_FILE_DIR:${JCPP_PROJECT_FULL_NAME}-checkclassadapter>
			)
		endforeach()
		add_custom_command(TARGET ${JCPP_PROJECT_FULL_NAME}-checkclassadapter POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy_if_different
				$<TARGET_FILE:${JCPP_PROJECT_NAME}-main>
				$<TARGET_FILE_DIR:${JCPP_PROJECT_FULL_NAME}-checkclassadapter>
		)
	endif()
else()
	target_link_libraries(${JCPP_PROJECT_FULL_NAME}-checkclassadapter
		PRIVATE ${JCPP_PROJECT_NAME}-main
		${JCPP_EXT_LIBS}
	)
endif()

jcpp_enable_bigobj(${JCPP_PROJECT_FULL_NAME}-checkclassadapter)

install(TARGETS ${JCPP_PROJECT_FULL_NAME}-checkclassadapter DESTINATION "${JCPP_INSTALL_BIN_DIR}")

#include <UnixCommands.h>

#include <java/io/File.h>
#include <java/lang/Error.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;

$FieldInfo _UnixCommands_FieldInfo_[] = {
	{"isUnix", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(UnixCommands, isUnix)},
	{"isLinux", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(UnixCommands, isLinux)},
	{"paths", "[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(UnixCommands, paths)},
	{"nameToCommand", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC, $staticField(UnixCommands, nameToCommand)},
	{}
};

$MethodInfo _UnixCommands_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(UnixCommands, init$, void)},
	{"cat", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnixCommands, cat, $String*)},
	{"echo", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnixCommands, echo, $String*)},
	{"ensureCommandsAvailable", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(UnixCommands, ensureCommandsAvailable, void, $StringArray*)},
	{"findCommand", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnixCommands, findCommand, $String*, $String*)},
	{"findCommand0", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(UnixCommands, findCommand0, $String*, $String*)},
	{"kill", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnixCommands, kill, $String*)},
	{"sh", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnixCommands, sh, $String*)},
	{"sleep", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnixCommands, sleep, $String*)},
	{"tee", "()Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(UnixCommands, tee, $String*)},
	{}
};

$ClassInfo _UnixCommands_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"UnixCommands",
	"java.lang.Object",
	nullptr,
	_UnixCommands_FieldInfo_,
	_UnixCommands_MethodInfo_
};

$Object* allocate$UnixCommands($Class* clazz) {
	return $of($alloc(UnixCommands));
}

bool UnixCommands::isUnix = false;
bool UnixCommands::isLinux = false;
$StringArray* UnixCommands::paths = nullptr;
$Map* UnixCommands::nameToCommand = nullptr;

void UnixCommands::init$() {
}

void UnixCommands::ensureCommandsAvailable($StringArray* commands) {
	$init(UnixCommands);
	$useLocalCurrentObjectStackCache();
	{
		$var($StringArray, arr$, commands);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, command, arr$->get(i$));
			{
				if (findCommand(command) == nullptr) {
					$throwNew($Error, $$str({"Command \'"_s, command, "\' not found; bailing out"_s}));
				}
			}
		}
	}
}

$String* UnixCommands::cat() {
	$init(UnixCommands);
	return findCommand("cat"_s);
}

$String* UnixCommands::sh() {
	$init(UnixCommands);
	return findCommand("sh"_s);
}

$String* UnixCommands::kill() {
	$init(UnixCommands);
	return findCommand("kill"_s);
}

$String* UnixCommands::sleep() {
	$init(UnixCommands);
	return findCommand("sleep"_s);
}

$String* UnixCommands::tee() {
	$init(UnixCommands);
	return findCommand("tee"_s);
}

$String* UnixCommands::echo() {
	$init(UnixCommands);
	return findCommand("echo"_s);
}

$String* UnixCommands::findCommand($String* name) {
	$init(UnixCommands);
	if ($nc(UnixCommands::nameToCommand)->containsKey(name)) {
		return $cast($String, $nc(UnixCommands::nameToCommand)->get(name));
	}
	$var($String, command, findCommand0(name));
	$nc(UnixCommands::nameToCommand)->put(name, command);
	return command;
}

$String* UnixCommands::findCommand0($String* name) {
	$init(UnixCommands);
	$useLocalCurrentObjectStackCache();
	{
		$var($StringArray, arr$, UnixCommands::paths);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, path, arr$->get(i$));
			{
				$var($File, file, $new($File, path, name));
				if (file->canExecute()) {
					return file->getPath();
				}
			}
		}
	}
	return nullptr;
}

void clinit$UnixCommands($Class* class$) {
	$useLocalCurrentObjectStackCache();
	UnixCommands::isUnix = !$nc($($System::getProperty("os.name"_s)))->startsWith("Windows"_s);
	UnixCommands::isLinux = $nc($($System::getProperty("os.name"_s)))->startsWith("Linux"_s);
	$assignStatic(UnixCommands::paths, $new($StringArray, {
		"/bin"_s,
		"/usr/bin"_s
	}));
	$assignStatic(UnixCommands::nameToCommand, $new($HashMap, 16));
}

UnixCommands::UnixCommands() {
}

$Class* UnixCommands::load$($String* name, bool initialize) {
	$loadClass(UnixCommands, name, initialize, &_UnixCommands_ClassInfo_, clinit$UnixCommands, allocate$UnixCommands);
	return class$;
}

$Class* UnixCommands::class$ = nullptr;
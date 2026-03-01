#include <java/lang/ProcessBuilder.h>

#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Iterable.h>
#include <java/lang/Process.h>
#include <java/lang/ProcessBuilder$Redirect$Type.h>
#include <java/lang/ProcessBuilder$Redirect.h>
#include <java/lang/ProcessBuilder$RedirectPipeImpl.h>
#include <java/lang/ProcessEnvironment.h>
#include <java/lang/ProcessImpl.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/Permission.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/StringJoiner.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/event/ProcessStartEvent.h>
#include <jcpp.h>

#undef APPEND
#undef INHERIT
#undef MIN_NAME_LENGTH
#undef PIPE
#undef READ
#undef WRITE

using $ProcessBuilder$RedirectArray = $Array<::java::lang::ProcessBuilder$Redirect>;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Process = ::java::lang::Process;
using $ProcessBuilder$Redirect = ::java::lang::ProcessBuilder$Redirect;
using $ProcessBuilder$Redirect$Type = ::java::lang::ProcessBuilder$Redirect$Type;
using $ProcessBuilder$RedirectPipeImpl = ::java::lang::ProcessBuilder$RedirectPipeImpl;
using $ProcessEnvironment = ::java::lang::ProcessEnvironment;
using $ProcessImpl = ::java::lang::ProcessImpl;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Permission = ::java::security::Permission;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $StringJoiner = ::java::util::StringJoiner;
using $Consumer = ::java::util::function::Consumer;
using $ProcessStartEvent = ::jdk::internal::event::ProcessStartEvent;

namespace java {
	namespace lang {

class ProcessBuilder$$Lambda$destroyForcibly : public $Consumer {
	$class(ProcessBuilder$$Lambda$destroyForcibly, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$) override {
		$sure($Process, inst$)->destroyForcibly();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProcessBuilder$$Lambda$destroyForcibly>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ProcessBuilder$$Lambda$destroyForcibly::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ProcessBuilder$$Lambda$destroyForcibly, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ProcessBuilder$$Lambda$destroyForcibly, accept, void, Object$*)},
	{}
};
$ClassInfo ProcessBuilder$$Lambda$destroyForcibly::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ProcessBuilder$$Lambda$destroyForcibly",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* ProcessBuilder$$Lambda$destroyForcibly::load$($String* name, bool initialize) {
	$loadClass(ProcessBuilder$$Lambda$destroyForcibly, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProcessBuilder$$Lambda$destroyForcibly::class$ = nullptr;

class ProcessBuilder$$Lambda$lambda$startPipeline$0$1 : public $Consumer {
	$class(ProcessBuilder$$Lambda$lambda$startPipeline$0$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* p) override {
		ProcessBuilder::lambda$startPipeline$0($cast($Process, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProcessBuilder$$Lambda$lambda$startPipeline$0$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ProcessBuilder$$Lambda$lambda$startPipeline$0$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ProcessBuilder$$Lambda$lambda$startPipeline$0$1, init$, void)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ProcessBuilder$$Lambda$lambda$startPipeline$0$1, accept, void, Object$*)},
	{}
};
$ClassInfo ProcessBuilder$$Lambda$lambda$startPipeline$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.ProcessBuilder$$Lambda$lambda$startPipeline$0$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* ProcessBuilder$$Lambda$lambda$startPipeline$0$1::load$($String* name, bool initialize) {
	$loadClass(ProcessBuilder$$Lambda$lambda$startPipeline$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProcessBuilder$$Lambda$lambda$startPipeline$0$1::class$ = nullptr;

$FieldInfo _ProcessBuilder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ProcessBuilder, $assertionsDisabled)},
	{"command", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE, $field(ProcessBuilder, command$)},
	{"directory", "Ljava/io/File;", nullptr, $PRIVATE, $field(ProcessBuilder, directory$)},
	{"environment", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE, $field(ProcessBuilder, environment$)},
	{"redirectErrorStream", "Z", nullptr, $PRIVATE, $field(ProcessBuilder, redirectErrorStream$)},
	{"redirects", "[Ljava/lang/ProcessBuilder$Redirect;", nullptr, $PRIVATE, $field(ProcessBuilder, redirects$)},
	{}
};

$MethodInfo _ProcessBuilder_MethodInfo_[] = {
	{"<init>", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/lang/String;>;)V", $PUBLIC, $method(ProcessBuilder, init$, void, $List*)},
	{"<init>", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $method(ProcessBuilder, init$, void, $StringArray*)},
	{"command", "(Ljava/util/List;)Ljava/lang/ProcessBuilder;", "(Ljava/util/List<Ljava/lang/String;>;)Ljava/lang/ProcessBuilder;", $PUBLIC, $method(ProcessBuilder, command, ProcessBuilder*, $List*)},
	{"command", "([Ljava/lang/String;)Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC | $TRANSIENT, $method(ProcessBuilder, command, ProcessBuilder*, $StringArray*)},
	{"command", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $method(ProcessBuilder, command, $List*)},
	{"directory", "()Ljava/io/File;", nullptr, $PUBLIC, $method(ProcessBuilder, directory, $File*)},
	{"directory", "(Ljava/io/File;)Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC, $method(ProcessBuilder, directory, ProcessBuilder*, $File*)},
	{"environment", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC, $method(ProcessBuilder, environment, $Map*)},
	{"environment", "([Ljava/lang/String;)Ljava/lang/ProcessBuilder;", nullptr, 0, $method(ProcessBuilder, environment, ProcessBuilder*, $StringArray*)},
	{"inheritIO", "()Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC, $method(ProcessBuilder, inheritIO, ProcessBuilder*)},
	{"lambda$startPipeline$0", "(Ljava/lang/Process;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ProcessBuilder, lambda$startPipeline$0, void, $Process*)},
	{"redirectError", "(Ljava/lang/ProcessBuilder$Redirect;)Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectError, ProcessBuilder*, $ProcessBuilder$Redirect*)},
	{"redirectError", "(Ljava/io/File;)Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectError, ProcessBuilder*, $File*)},
	{"redirectError", "()Ljava/lang/ProcessBuilder$Redirect;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectError, $ProcessBuilder$Redirect*)},
	{"redirectErrorStream", "()Z", nullptr, $PUBLIC, $method(ProcessBuilder, redirectErrorStream, bool)},
	{"redirectErrorStream", "(Z)Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectErrorStream, ProcessBuilder*, bool)},
	{"redirectInput", "(Ljava/lang/ProcessBuilder$Redirect;)Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectInput, ProcessBuilder*, $ProcessBuilder$Redirect*)},
	{"redirectInput", "(Ljava/io/File;)Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectInput, ProcessBuilder*, $File*)},
	{"redirectInput", "()Ljava/lang/ProcessBuilder$Redirect;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectInput, $ProcessBuilder$Redirect*)},
	{"redirectOutput", "(Ljava/lang/ProcessBuilder$Redirect;)Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectOutput, ProcessBuilder*, $ProcessBuilder$Redirect*)},
	{"redirectOutput", "(Ljava/io/File;)Ljava/lang/ProcessBuilder;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectOutput, ProcessBuilder*, $File*)},
	{"redirectOutput", "()Ljava/lang/ProcessBuilder$Redirect;", nullptr, $PUBLIC, $method(ProcessBuilder, redirectOutput, $ProcessBuilder$Redirect*)},
	{"redirects", "()[Ljava/lang/ProcessBuilder$Redirect;", nullptr, $PRIVATE, $method(ProcessBuilder, redirects, $ProcessBuilder$RedirectArray*)},
	{"start", "()Ljava/lang/Process;", nullptr, $PUBLIC, $method(ProcessBuilder, start, $Process*), "java.io.IOException"},
	{"start", "([Ljava/lang/ProcessBuilder$Redirect;)Ljava/lang/Process;", nullptr, $PRIVATE, $method(ProcessBuilder, start, $Process*, $ProcessBuilder$RedirectArray*), "java.io.IOException"},
	{"startPipeline", "(Ljava/util/List;)Ljava/util/List;", "(Ljava/util/List<Ljava/lang/ProcessBuilder;>;)Ljava/util/List<Ljava/lang/Process;>;", $PUBLIC | $STATIC, $staticMethod(ProcessBuilder, startPipeline, $List*, $List*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ProcessBuilder_InnerClassesInfo_[] = {
	{"java.lang.ProcessBuilder$RedirectPipeImpl", "java.lang.ProcessBuilder", "RedirectPipeImpl", $STATIC},
	{"java.lang.ProcessBuilder$Redirect", "java.lang.ProcessBuilder", "Redirect", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.lang.ProcessBuilder$NullOutputStream", "java.lang.ProcessBuilder", "NullOutputStream", $STATIC},
	{"java.lang.ProcessBuilder$NullInputStream", "java.lang.ProcessBuilder", "NullInputStream", $STATIC},
	{}
};

$ClassInfo _ProcessBuilder_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.ProcessBuilder",
	"java.lang.Object",
	nullptr,
	_ProcessBuilder_FieldInfo_,
	_ProcessBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_ProcessBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.ProcessBuilder$RedirectPipeImpl,java.lang.ProcessBuilder$Redirect,java.lang.ProcessBuilder$Redirect$Type,java.lang.ProcessBuilder$Redirect$6,java.lang.ProcessBuilder$Redirect$5,java.lang.ProcessBuilder$Redirect$4,java.lang.ProcessBuilder$Redirect$3,java.lang.ProcessBuilder$Redirect$2,java.lang.ProcessBuilder$Redirect$1,java.lang.ProcessBuilder$NullOutputStream,java.lang.ProcessBuilder$NullInputStream"
};

$Object* allocate$ProcessBuilder($Class* clazz) {
	return $of($alloc(ProcessBuilder));
}

bool ProcessBuilder::$assertionsDisabled = false;

void ProcessBuilder::init$($List* command) {
	if (command == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, command$, command);
}

void ProcessBuilder::init$($StringArray* command) {
	$useLocalCurrentObjectStackCache();
	$set(this, command$, $new($ArrayList, $nc(command)->length));
	{
		$var($StringArray, arr$, command);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, arg, arr$->get(i$));
			$nc(this->command$)->add(arg);
		}
	}
}

ProcessBuilder* ProcessBuilder::command($List* command) {
	if (command == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, command$, command);
	return this;
}

ProcessBuilder* ProcessBuilder::command($StringArray* command) {
	$useLocalCurrentObjectStackCache();
	$set(this, command$, $new($ArrayList, $nc(command)->length));
	{
		$var($StringArray, arr$, command);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, arg, arr$->get(i$));
			$nc(this->command$)->add(arg);
		}
	}
	return this;
}

$List* ProcessBuilder::command() {
	return this->command$;
}

$Map* ProcessBuilder::environment() {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkPermission($$new($RuntimePermission, "getenv.*"_s));
	}
	if (this->environment$ == nullptr) {
		$set(this, environment$, $ProcessEnvironment::environment());
	}
	if (!ProcessBuilder::$assertionsDisabled && !(this->environment$ != nullptr)) {
		$throwNew($AssertionError);
	}
	return this->environment$;
}

ProcessBuilder* ProcessBuilder::environment($StringArray* envp) {
	$useLocalCurrentObjectStackCache();
	if (!ProcessBuilder::$assertionsDisabled && !(this->environment$ == nullptr)) {
		$throwNew($AssertionError);
	}
	if (envp != nullptr) {
		$set(this, environment$, $ProcessEnvironment::emptyEnvironment(envp->length));
		if (!ProcessBuilder::$assertionsDisabled && !(this->environment$ != nullptr)) {
			$throwNew($AssertionError);
		}
		{
			$var($StringArray, arr$, envp);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, envstring, arr$->get(i$));
				{
					if ($nc(envstring)->indexOf((int32_t)u'\0') != -1) {
						$assign(envstring, envstring->replaceFirst($cstr({'\0', '.', '*'}), ""_s));
					}
					int32_t eqlsign = $nc(envstring)->indexOf((int32_t)u'=', $ProcessEnvironment::MIN_NAME_LENGTH);
					if (eqlsign != -1) {
						$var($Object, var$0, $of(envstring->substring(0, eqlsign)));
						$nc(this->environment$)->put(var$0, $(envstring->substring(eqlsign + 1)));
					}
				}
			}
		}
	}
	return this;
}

$File* ProcessBuilder::directory() {
	return this->directory$;
}

ProcessBuilder* ProcessBuilder::directory($File* directory) {
	$set(this, directory$, directory);
	return this;
}

$ProcessBuilder$RedirectArray* ProcessBuilder::redirects() {
	if (this->redirects$ == nullptr) {
		$init($ProcessBuilder$Redirect);
		$set(this, redirects$, $new($ProcessBuilder$RedirectArray, {
			$ProcessBuilder$Redirect::PIPE,
			$ProcessBuilder$Redirect::PIPE,
			$ProcessBuilder$Redirect::PIPE
		}));
	}
	return this->redirects$;
}

ProcessBuilder* ProcessBuilder::redirectInput($ProcessBuilder$Redirect* source) {
	$useLocalCurrentObjectStackCache();
	$init($ProcessBuilder$Redirect$Type);
	bool var$0 = $nc(source)->type() == $ProcessBuilder$Redirect$Type::WRITE;
	if (var$0 || $nc(source)->type() == $ProcessBuilder$Redirect$Type::APPEND) {
		$throwNew($IllegalArgumentException, $$str({"Redirect invalid for reading: "_s, source}));
	}
	$nc($(redirects()))->set(0, source);
	return this;
}

ProcessBuilder* ProcessBuilder::redirectOutput($ProcessBuilder$Redirect* destination) {
	$useLocalCurrentObjectStackCache();
	$init($ProcessBuilder$Redirect$Type);
	if ($nc(destination)->type() == $ProcessBuilder$Redirect$Type::READ) {
		$throwNew($IllegalArgumentException, $$str({"Redirect invalid for writing: "_s, destination}));
	}
	$nc($(redirects()))->set(1, destination);
	return this;
}

ProcessBuilder* ProcessBuilder::redirectError($ProcessBuilder$Redirect* destination) {
	$useLocalCurrentObjectStackCache();
	$init($ProcessBuilder$Redirect$Type);
	if ($nc(destination)->type() == $ProcessBuilder$Redirect$Type::READ) {
		$throwNew($IllegalArgumentException, $$str({"Redirect invalid for writing: "_s, destination}));
	}
	$nc($(redirects()))->set(2, destination);
	return this;
}

ProcessBuilder* ProcessBuilder::redirectInput($File* file) {
	return redirectInput($($ProcessBuilder$Redirect::from(file)));
}

ProcessBuilder* ProcessBuilder::redirectOutput($File* file) {
	return redirectOutput($($ProcessBuilder$Redirect::to(file)));
}

ProcessBuilder* ProcessBuilder::redirectError($File* file) {
	return redirectError($($ProcessBuilder$Redirect::to(file)));
}

$ProcessBuilder$Redirect* ProcessBuilder::redirectInput() {
	$init($ProcessBuilder$Redirect);
	return (this->redirects$ == nullptr) ? $ProcessBuilder$Redirect::PIPE : $nc(this->redirects$)->get(0);
}

$ProcessBuilder$Redirect* ProcessBuilder::redirectOutput() {
	$init($ProcessBuilder$Redirect);
	return (this->redirects$ == nullptr) ? $ProcessBuilder$Redirect::PIPE : $nc(this->redirects$)->get(1);
}

$ProcessBuilder$Redirect* ProcessBuilder::redirectError() {
	$init($ProcessBuilder$Redirect);
	return (this->redirects$ == nullptr) ? $ProcessBuilder$Redirect::PIPE : $nc(this->redirects$)->get(2);
}

ProcessBuilder* ProcessBuilder::inheritIO() {
	$init($ProcessBuilder$Redirect);
	$Arrays::fill($(redirects()), $of($ProcessBuilder$Redirect::INHERIT));
	return this;
}

bool ProcessBuilder::redirectErrorStream() {
	return this->redirectErrorStream$;
}

ProcessBuilder* ProcessBuilder::redirectErrorStream(bool redirectErrorStream) {
	this->redirectErrorStream$ = redirectErrorStream;
	return this;
}

$Process* ProcessBuilder::start() {
	return start(this->redirects$);
}

$Process* ProcessBuilder::start($ProcessBuilder$RedirectArray* redirects) {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, cmdarray, $fcast($StringArray, $nc(this->command$)->toArray($$new($StringArray, $nc(this->command$)->size()))));
	$assign(cmdarray, $cast($StringArray, $nc(cmdarray)->clone()));
	{
		$var($StringArray, arr$, cmdarray);
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, arg, arr$->get(i$));
			if (arg == nullptr) {
				$throwNew($NullPointerException);
			}
		}
	}
	$var($String, prog, cmdarray->get(0));
	$var($SecurityManager, security, $System::getSecurityManager());
	if (security != nullptr) {
		security->checkExec(prog);
	}
	$var($String, dir, this->directory$ == nullptr ? ($String*)nullptr : $nc(this->directory$)->toString());
	for (int32_t i = 1; i < cmdarray->length; ++i) {
		if ($nc(cmdarray->get(i))->indexOf((int32_t)u'\0') >= 0) {
			$throwNew($IOException, "invalid null character in command"_s);
		}
	}
	try {
		$var($Process, process, $ProcessImpl::start(cmdarray, this->environment$, dir, redirects, this->redirectErrorStream$));
		$var($ProcessStartEvent, event, $new($ProcessStartEvent));
		if (event->isEnabled()) {
			$var($StringJoiner, command, $new($StringJoiner, " "_s));
			{
				$var($StringArray, arr$, cmdarray);
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, s, arr$->get(i$));
					{
						command->add(s);
					}
				}
			}
			$set(event, directory, dir);
			$set(event, command, command->toString());
			event->pid = $nc(process)->pid();
			event->commit();
		}
		return process;
	} catch ($IOException& e) {
		$var($String, exceptionInfo, $str({": "_s, $(e->getMessage())}));
		$var($Throwable, cause, e);
		if (($instanceOf($IOException, e)) && security != nullptr) {
			try {
				security->checkRead(prog);
			} catch ($SecurityException& se) {
				$assign(exceptionInfo, ""_s);
				$assign(cause, se);
			}
		}
		$throwNew($IOException, $$str({"Cannot run program \""_s, prog, "\""_s, (dir == nullptr ? ""_s : $$str({" (in directory \""_s, dir, "\")"_s})), exceptionInfo}), cause);
	} catch ($IllegalArgumentException& e) {
		$var($String, exceptionInfo, $str({": "_s, $(e->getMessage())}));
		$var($Throwable, cause, e);
		if (($instanceOf($IOException, e)) && security != nullptr) {
			try {
				security->checkRead(prog);
			} catch ($SecurityException& se) {
				$assign(exceptionInfo, ""_s);
				$assign(cause, se);
			}
		}
		$throwNew($IOException, $$str({"Cannot run program \""_s, prog, "\""_s, (dir == nullptr ? ""_s : $$str({" (in directory \""_s, dir, "\")"_s})), exceptionInfo}), cause);
	}
	$shouldNotReachHere();
}

$List* ProcessBuilder::startPipeline($List* builders) {
	$init(ProcessBuilder);
	$useLocalCurrentObjectStackCache();
	int32_t numBuilders = $nc(builders)->size();
	$var($List, processes, $new($ArrayList, numBuilders));
	try {
		$var($ProcessBuilder$Redirect, prevOutput, nullptr);
		for (int32_t index = 0; index < builders->size(); ++index) {
			$var(ProcessBuilder, builder, $cast(ProcessBuilder, builders->get(index)));
			$var($ProcessBuilder$RedirectArray, redirects, $nc(builder)->redirects());
			if (index > 0) {
				$init($ProcessBuilder$Redirect);
				if (builder->redirectInput() != $ProcessBuilder$Redirect::PIPE) {
					$throwNew($IllegalArgumentException, $$str({"builder redirectInput() must be PIPE except for the first builder: "_s, $(builder->redirectInput())}));
				}
				$nc(redirects)->set(0, prevOutput);
			}
			if (index < numBuilders - 1) {
				$init($ProcessBuilder$Redirect);
				if (builder->redirectOutput() != $ProcessBuilder$Redirect::PIPE) {
					$throwNew($IllegalArgumentException, $$str({"builder redirectOutput() must be PIPE except for the last builder: "_s, $(builder->redirectOutput())}));
				}
				$nc(redirects)->set(1, $$new($ProcessBuilder$RedirectPipeImpl));
			}
			processes->add($(builder->start(redirects)));
			$assign(prevOutput, $nc(redirects)->get(1));
		}
	} catch ($Exception& ex) {
		processes->forEach(static_cast<$Consumer*>($$new(ProcessBuilder$$Lambda$destroyForcibly)));
		processes->forEach(static_cast<$Consumer*>($$new(ProcessBuilder$$Lambda$lambda$startPipeline$0$1)));
		$throw(ex);
	}
	return processes;
}

void ProcessBuilder::lambda$startPipeline$0($Process* p) {
	$init(ProcessBuilder);
	try {
		$nc(p)->waitFor();
	} catch ($InterruptedException& ie) {
		$($Thread::currentThread())->interrupt();
	}
}

void clinit$ProcessBuilder($Class* class$) {
	ProcessBuilder::$assertionsDisabled = !ProcessBuilder::class$->desiredAssertionStatus();
}

ProcessBuilder::ProcessBuilder() {
}

$Class* ProcessBuilder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ProcessBuilder$$Lambda$destroyForcibly::classInfo$.name)) {
			return ProcessBuilder$$Lambda$destroyForcibly::load$(name, initialize);
		}
		if (name->equals(ProcessBuilder$$Lambda$lambda$startPipeline$0$1::classInfo$.name)) {
			return ProcessBuilder$$Lambda$lambda$startPipeline$0$1::load$(name, initialize);
		}
	}
	$loadClass(ProcessBuilder, name, initialize, &_ProcessBuilder_ClassInfo_, clinit$ProcessBuilder, allocate$ProcessBuilder);
	return class$;
}

$Class* ProcessBuilder::class$ = nullptr;

	} // lang
} // java
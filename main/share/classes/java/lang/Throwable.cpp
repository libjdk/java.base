#include <java/lang/Throwable.h>

#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/PrintWriter.h>
#include <java/io/StreamCorruptedException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/lang/Module.h>
#include <java/lang/StackTraceElement.h>
#include <java/lang/Throwable$PrintStreamOrWriter.h>
#include <java/lang/Throwable$SentinelHolder.h>
#include <java/lang/Throwable$WrappedPrintStream.h>
#include <java/lang/Throwable$WrappedPrintWriter.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/IdentityHashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <jcpp.h>

#include "StackWalk.h"

#undef CAUSE_CAPTION
#undef EMPTY_THROWABLE_ARRAY
#undef NULL_CAUSE_MESSAGE
#undef SELF_SUPPRESSION_MESSAGE
#undef STACK_TRACE_ELEMENT_SENTINEL
#undef STACK_TRACE_SENTINEL
#undef SUPPRESSED_CAPTION
#undef SUPPRESSED_SENTINEL
#undef UNASSIGNED_STACK

using $StackTraceElementArray = $Array<::java::lang::StackTraceElement>;
using $ThrowableArray = $Array<::java::lang::Throwable>;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $PrintStream = ::java::io::PrintStream;
using $PrintWriter = ::java::io::PrintWriter;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NullPointerException = ::java::lang::NullPointerException;
using $StackTraceElement = ::java::lang::StackTraceElement;
using $Throwable$PrintStreamOrWriter = ::java::lang::Throwable$PrintStreamOrWriter;
using $Throwable$SentinelHolder = ::java::lang::Throwable$SentinelHolder;
using $Throwable$WrappedPrintStream = ::java::lang::Throwable$WrappedPrintStream;
using $Throwable$WrappedPrintWriter = ::java::lang::Throwable$WrappedPrintWriter;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $IdentityHashMap = ::java::util::IdentityHashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;

namespace java {
	namespace lang {

$FieldInfo _Throwable_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Throwable, $assertionsDisabled)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Throwable, serialVersionUID)},
	{"backtrace", "Ljava/lang/Object;", nullptr, $PRIVATE | $TRANSIENT, $field(Throwable, backtrace)},
	{"detailMessage", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Throwable, detailMessage)},
	{"UNASSIGNED_STACK", "[Ljava/lang/StackTraceElement;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Throwable, UNASSIGNED_STACK)},
	{"cause", "Ljava/lang/Throwable;", nullptr, $PRIVATE, $field(Throwable, cause)},
	{"stackTrace", "[Ljava/lang/StackTraceElement;", nullptr, $PRIVATE, $field(Throwable, stackTrace)},
	{"depth", "I", nullptr, $PRIVATE | $TRANSIENT, $field(Throwable, depth)},
	{"SUPPRESSED_SENTINEL", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Throwable;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Throwable, SUPPRESSED_SENTINEL)},
	{"suppressedExceptions", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Throwable;>;", $PRIVATE, $field(Throwable, suppressedExceptions)},
	{"NULL_CAUSE_MESSAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Throwable, NULL_CAUSE_MESSAGE)},
	{"SELF_SUPPRESSION_MESSAGE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Throwable, SELF_SUPPRESSION_MESSAGE)},
	{"CAUSE_CAPTION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Throwable, CAUSE_CAPTION)},
	{"SUPPRESSED_CAPTION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Throwable, SUPPRESSED_CAPTION)},
	{"EMPTY_THROWABLE_ARRAY", "[Ljava/lang/Throwable;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Throwable, EMPTY_THROWABLE_ARRAY)},
	{}
};

$MethodInfo _Throwable_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Throwable, init$, void)},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Throwable, init$, void, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(Throwable, init$, void, $String*, Throwable*)},
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(Throwable, init$, void, Throwable*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/Throwable;ZZ)V", nullptr, $PROTECTED, $method(Throwable, init$, void, $String*, Throwable*, bool, bool)},
	{"addSuppressed", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $FINAL | $SYNCHRONIZED, $method(Throwable, addSuppressed, void, Throwable*)},
	{"fillInStackTrace", "()Ljava/lang/Throwable;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Throwable, fillInStackTrace, Throwable*)},
	{"fillInStackTrace", "(I)Ljava/lang/Throwable;", nullptr, $PRIVATE | $NATIVE, $method(Throwable, fillInStackTrace, Throwable*, int32_t)},
	{"getCause", "()Ljava/lang/Throwable;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Throwable, getCause, Throwable*)},
	{"getLocalizedMessage", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Throwable, getLocalizedMessage, $String*)},
	{"getMessage", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Throwable, getMessage, $String*)},
	{"getOurStackTrace", "()[Ljava/lang/StackTraceElement;", nullptr, $PRIVATE | $SYNCHRONIZED, $method(Throwable, getOurStackTrace, $StackTraceElementArray*)},
	{"getStackTrace", "()[Ljava/lang/StackTraceElement;", nullptr, $PUBLIC, $virtualMethod(Throwable, getStackTrace, $StackTraceElementArray*)},
	{"getSuppressed", "()[Ljava/lang/Throwable;", nullptr, $PUBLIC | $FINAL | $SYNCHRONIZED, $method(Throwable, getSuppressed, $ThrowableArray*)},
	{"initCause", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(Throwable, initCause, Throwable*, Throwable*)},
	{"printEnclosedStackTrace", "(Ljava/lang/Throwable$PrintStreamOrWriter;[Ljava/lang/StackTraceElement;Ljava/lang/String;Ljava/lang/String;Ljava/util/Set;)V", "(Ljava/lang/Throwable$PrintStreamOrWriter;[Ljava/lang/StackTraceElement;Ljava/lang/String;Ljava/lang/String;Ljava/util/Set<Ljava/lang/Throwable;>;)V", $PRIVATE, $method(Throwable, printEnclosedStackTrace, void, $Throwable$PrintStreamOrWriter*, $StackTraceElementArray*, $String*, $String*, $Set*)},
	{"printStackTrace", "()V", nullptr, $PUBLIC, $virtualMethod(Throwable, printStackTrace, void)},
	{"printStackTrace", "(Ljava/io/PrintStream;)V", nullptr, $PUBLIC, $virtualMethod(Throwable, printStackTrace, void, $PrintStream*)},
	{"printStackTrace", "(Ljava/lang/Throwable$PrintStreamOrWriter;)V", nullptr, $PRIVATE, $method(Throwable, printStackTrace, void, $Throwable$PrintStreamOrWriter*)},
	{"printStackTrace", "(Ljava/io/PrintWriter;)V", nullptr, $PUBLIC, $virtualMethod(Throwable, printStackTrace, void, $PrintWriter*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(Throwable, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setCause", "(Ljava/lang/Throwable;)V", nullptr, $FINAL, $method(Throwable, setCause, void, Throwable*)},
	{"setStackTrace", "([Ljava/lang/StackTraceElement;)V", nullptr, $PUBLIC, $virtualMethod(Throwable, setStackTrace, void, $StackTraceElementArray*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Throwable, toString, $String*)},
	{"validateSuppressedExceptionsList", "(Ljava/util/List;)I", "(Ljava/util/List<Ljava/lang/Throwable;>;)I", $PRIVATE, $method(Throwable, validateSuppressedExceptionsList, int32_t, $List*), "java.io.IOException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(Throwable, writeObject, void, $ObjectOutputStream*), "java.io.IOException"},
	{"*throw$", "()V", nullptr, $PUBLIC},
	{}
};

#define _METHOD_INDEX_fillInStackTrace 7

$InnerClassInfo _Throwable_InnerClassesInfo_[] = {
	{"java.lang.Throwable$WrappedPrintWriter", "java.lang.Throwable", "WrappedPrintWriter", $PRIVATE | $STATIC},
	{"java.lang.Throwable$WrappedPrintStream", "java.lang.Throwable", "WrappedPrintStream", $PRIVATE | $STATIC},
	{"java.lang.Throwable$PrintStreamOrWriter", "java.lang.Throwable", "PrintStreamOrWriter", $PRIVATE | $STATIC | $ABSTRACT},
	{"java.lang.Throwable$SentinelHolder", "java.lang.Throwable", "SentinelHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Throwable_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.Throwable",
	"java.lang.Object",
	"java.io.Serializable",
	_Throwable_FieldInfo_,
	_Throwable_MethodInfo_,
	nullptr,
	nullptr,
	_Throwable_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.Throwable$WrappedPrintWriter,java.lang.Throwable$WrappedPrintStream,java.lang.Throwable$PrintStreamOrWriter,java.lang.Throwable$SentinelHolder"
};

$Object* allocate$Throwable($Class* clazz) {
	return $of($alloc(Throwable));
}

bool Throwable::$assertionsDisabled = false;
$StackTraceElementArray* Throwable::UNASSIGNED_STACK = nullptr;
$List* Throwable::SUPPRESSED_SENTINEL = nullptr;
$String* Throwable::NULL_CAUSE_MESSAGE = nullptr;
$String* Throwable::SELF_SUPPRESSION_MESSAGE = nullptr;
$String* Throwable::CAUSE_CAPTION = nullptr;
$String* Throwable::SUPPRESSED_CAPTION = nullptr;
$ThrowableArray* Throwable::EMPTY_THROWABLE_ARRAY = nullptr;

void Throwable::init$() {
	$set(this, cause, this);
	$set(this, stackTrace, Throwable::UNASSIGNED_STACK);
	$set(this, suppressedExceptions, Throwable::SUPPRESSED_SENTINEL);
	fillInStackTrace();
}

void Throwable::init$($String* message) {
	$set(this, cause, this);
	$set(this, stackTrace, Throwable::UNASSIGNED_STACK);
	$set(this, suppressedExceptions, Throwable::SUPPRESSED_SENTINEL);
	fillInStackTrace();
	$set(this, detailMessage, message);
}

void Throwable::init$($String* message, Throwable* cause) {
	$set(this, cause, this);
	$set(this, stackTrace, Throwable::UNASSIGNED_STACK);
	$set(this, suppressedExceptions, Throwable::SUPPRESSED_SENTINEL);
	fillInStackTrace();
	$set(this, detailMessage, message);
	$set(this, cause, cause);
}

void Throwable::init$(Throwable* cause) {
	$set(this, cause, this);
	$set(this, stackTrace, Throwable::UNASSIGNED_STACK);
	$set(this, suppressedExceptions, Throwable::SUPPRESSED_SENTINEL);
	fillInStackTrace();
	$set(this, detailMessage, cause == nullptr ? ($String*)nullptr : $nc(cause)->toString());
	$set(this, cause, cause);
}

void Throwable::init$($String* message, Throwable* cause, bool enableSuppression, bool writableStackTrace) {
	$set(this, cause, this);
	$set(this, stackTrace, Throwable::UNASSIGNED_STACK);
	$set(this, suppressedExceptions, Throwable::SUPPRESSED_SENTINEL);
	if (writableStackTrace) {
		fillInStackTrace();
	} else {
		$set(this, stackTrace, nullptr);
	}
	$set(this, detailMessage, message);
	$set(this, cause, cause);
	if (!enableSuppression) {
		$set(this, suppressedExceptions, nullptr);
	}
}

$String* Throwable::getMessage() {
	return this->detailMessage;
}

$String* Throwable::getLocalizedMessage() {
	return getMessage();
}

Throwable* Throwable::getCause() {
	$synchronized(this) {
		return (this->cause == this ? (Throwable*)nullptr : this->cause);
	}
}

Throwable* Throwable::initCause(Throwable* cause) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->cause != this) {
			$throwNew($IllegalStateException, $$str({"Can\'t overwrite cause with "_s, $($Objects::toString(cause, "a null"_s))}), this);
		}
		if (cause == this) {
			$throwNew($IllegalArgumentException, "Self-causation not permitted"_s, this);
		}
		$set(this, cause, cause);
		return this;
	}
}

void Throwable::setCause(Throwable* t) {
	$set(this, cause, t);
}

$String* Throwable::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, s, $of(this)->getClass()->getName());
	$var($String, message, getLocalizedMessage());
	return (message != nullptr) ? ($str({s, ": "_s, message})) : s;
}

void Throwable::printStackTrace() {
	printStackTrace($System::err);
}

void Throwable::printStackTrace($PrintStream* s) {
	printStackTrace(static_cast<$Throwable$PrintStreamOrWriter*>($$new($Throwable$WrappedPrintStream, s)));
}

void Throwable::printStackTrace($Throwable$PrintStreamOrWriter* s) {
	$useLocalCurrentObjectStackCache();
	$var($Set, dejaVu, $Collections::newSetFromMap($$new($IdentityHashMap)));
	$nc(dejaVu)->add(this);
	$synchronized($nc(s)->lock()) {
		s->println(this);
		$var($StackTraceElementArray, trace, getOurStackTrace());
		{
			$var($StackTraceElementArray, arr$, trace);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($StackTraceElement, traceElement, arr$->get(i$));
				s->println($$str({"\tat "_s, traceElement}));
			}
		}
		{
			$var($ThrowableArray, arr$, getSuppressed());
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var(Throwable, se, arr$->get(i$));
				$nc(se)->printEnclosedStackTrace(s, trace, Throwable::SUPPRESSED_CAPTION, "\t"_s, dejaVu);
			}
		}
		$var(Throwable, ourCause, getCause());
		if (ourCause != nullptr) {
			ourCause->printEnclosedStackTrace(s, trace, Throwable::CAUSE_CAPTION, ""_s, dejaVu);
		}
	}
}

void Throwable::printEnclosedStackTrace($Throwable$PrintStreamOrWriter* s, $StackTraceElementArray* enclosingTrace, $String* caption, $String* prefix, $Set* dejaVu) {
	$useLocalCurrentObjectStackCache();
	if (!Throwable::$assertionsDisabled && !$Thread::holdsLock($($nc(s)->lock()))) {
		$throwNew($AssertionError);
	}
	if ($nc(dejaVu)->contains(this)) {
		$nc(s)->println($$str({prefix, caption, "[CIRCULAR REFERENCE: "_s, this, "]"_s}));
	} else {
		dejaVu->add(this);
		$var($StackTraceElementArray, trace, getOurStackTrace());
		int32_t m = $nc(trace)->length - 1;
		int32_t n = $nc(enclosingTrace)->length - 1;
		while (m >= 0 && n >= 0 && $nc(trace->get(m))->equals(enclosingTrace->get(n))) {
			--m;
			--n;
		}
		int32_t framesInCommon = trace->length - 1 - m;
		$nc(s)->println($$str({prefix, caption, this}));
		for (int32_t i = 0; i <= m; ++i) {
			s->println($$str({prefix, "\tat "_s, trace->get(i)}));
		}
		if (framesInCommon != 0) {
			s->println($$str({prefix, "\t... "_s, $$str(framesInCommon), " more"_s}));
		}
		{
			$var($ThrowableArray, arr$, getSuppressed());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var(Throwable, se, arr$->get(i$));
				$nc(se)->printEnclosedStackTrace(s, trace, Throwable::SUPPRESSED_CAPTION, $$str({prefix, "\t"_s}), dejaVu);
			}
		}
		$var(Throwable, ourCause, getCause());
		if (ourCause != nullptr) {
			ourCause->printEnclosedStackTrace(s, trace, Throwable::CAUSE_CAPTION, prefix, dejaVu);
		}
	}
}

void Throwable::printStackTrace($PrintWriter* s) {
	printStackTrace(static_cast<$Throwable$PrintStreamOrWriter*>($$new($Throwable$WrappedPrintWriter, s)));
}

Throwable* Throwable::fillInStackTrace() {
	$synchronized(this) {
		if (this->stackTrace != nullptr || this->backtrace != nullptr) {
			fillInStackTrace(0);
			$set(this, stackTrace, Throwable::UNASSIGNED_STACK);
		}
		return this;
	}
}

Throwable* Throwable::fillInStackTrace(int32_t dummy) {
	StackWalk::fillInStackTrace(this);
	return this;
}

$StackTraceElementArray* Throwable::getStackTrace() {
	return $cast($StackTraceElementArray, $nc($(getOurStackTrace()))->clone());
}

$StackTraceElementArray* Throwable::getOurStackTrace() {
	$synchronized(this) {
		if (this->stackTrace == Throwable::UNASSIGNED_STACK || (this->stackTrace == nullptr && this->backtrace != nullptr)) {
			$set(this, stackTrace, $StackTraceElement::of(this, this->depth));
		} else if (this->stackTrace == nullptr) {
			return Throwable::UNASSIGNED_STACK;
		}
		return this->stackTrace;
	}
}

void Throwable::setStackTrace($StackTraceElementArray* stackTrace) {
	$useLocalCurrentObjectStackCache();
	$var($StackTraceElementArray, defensiveCopy, $cast($StackTraceElementArray, $nc(stackTrace)->clone()));
	for (int32_t i = 0; i < defensiveCopy->length; ++i) {
		if (defensiveCopy->get(i) == nullptr) {
			$throwNew($NullPointerException, $$str({"stackTrace["_s, $$str(i), "]"_s}));
		}
	}
	$synchronized(this) {
		if (this->stackTrace == nullptr && this->backtrace == nullptr) {
			return;
		}
		$set(this, stackTrace, defensiveCopy);
	}
}

void Throwable::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$nc(s)->defaultReadObject();
	$var($List, candidateSuppressedExceptions, this->suppressedExceptions);
	$set(this, suppressedExceptions, Throwable::SUPPRESSED_SENTINEL);
	$var($StackTraceElementArray, candidateStackTrace, this->stackTrace);
	$set(this, stackTrace, $cast($StackTraceElementArray, $nc(Throwable::UNASSIGNED_STACK)->clone()));
	if (candidateSuppressedExceptions != nullptr) {
		int32_t suppressedSize = validateSuppressedExceptionsList(candidateSuppressedExceptions);
		if (suppressedSize > 0) {
			$var($ArrayList, suppList, $new($ArrayList, $Math::min(100, suppressedSize)));
			{
				$var($Iterator, i$, candidateSuppressedExceptions->iterator());
				for (; $nc(i$)->hasNext();) {
					$var(Throwable, t, $cast(Throwable, i$->next()));
					{
						$Objects::requireNonNull($of(t), Throwable::NULL_CAUSE_MESSAGE);
						if (t == this) {
							$throwNew($IllegalArgumentException, Throwable::SELF_SUPPRESSION_MESSAGE);
						}
						suppList->add(t);
					}
				}
			}
			$set(this, suppressedExceptions, suppList);
		}
	} else {
		$set(this, suppressedExceptions, nullptr);
	}
	if (candidateStackTrace != nullptr) {
		$assign(candidateStackTrace, $cast($StackTraceElementArray, candidateStackTrace->clone()));
		if (candidateStackTrace->length >= 1) {
			$init($Throwable$SentinelHolder);
			if (candidateStackTrace->length == 1 && $nc($Throwable$SentinelHolder::STACK_TRACE_ELEMENT_SENTINEL)->equals(candidateStackTrace->get(0))) {
				$set(this, stackTrace, nullptr);
			} else {
				{
					$var($StackTraceElementArray, arr$, candidateStackTrace);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($StackTraceElement, ste, arr$->get(i$));
						{
							$Objects::requireNonNull($of(ste), "null StackTraceElement in serial stream."_s);
						}
					}
				}
				$set(this, stackTrace, candidateStackTrace);
			}
		}
	}
}

int32_t Throwable::validateSuppressedExceptionsList($List* deserSuppressedExceptions) {
	$useLocalCurrentObjectStackCache();
	if (!$nc($of($($Object::class$->getModule())))->equals($($nc($of(deserSuppressedExceptions))->getClass()->getModule()))) {
		$throwNew($StreamCorruptedException, "List implementation not in base module."_s);
	} else {
		int32_t size = $nc(deserSuppressedExceptions)->size();
		if (size < 0) {
			$throwNew($StreamCorruptedException, "Negative list size reported."_s);
		}
		return size;
	}
}

void Throwable::writeObject($ObjectOutputStream* s) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		getOurStackTrace();
		$var($StackTraceElementArray, oldStackTrace, this->stackTrace);
		{
			$var(Throwable, var$0, nullptr);
			try {
				if (this->stackTrace == nullptr) {
					$init($Throwable$SentinelHolder);
					$set(this, stackTrace, $Throwable$SentinelHolder::STACK_TRACE_SENTINEL);
				}
				$nc(s)->defaultWriteObject();
			} catch (Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$set(this, stackTrace, oldStackTrace);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void Throwable::addSuppressed(Throwable* exception) {
	$synchronized(this) {
		if (exception == this) {
			$throwNew($IllegalArgumentException, Throwable::SELF_SUPPRESSION_MESSAGE, exception);
		}
		$Objects::requireNonNull($of(exception), Throwable::NULL_CAUSE_MESSAGE);
		if (this->suppressedExceptions == nullptr) {
			return;
		}
		if (this->suppressedExceptions == Throwable::SUPPRESSED_SENTINEL) {
			$set(this, suppressedExceptions, $new($ArrayList, 1));
		}
		$nc(this->suppressedExceptions)->add(exception);
	}
}

$ThrowableArray* Throwable::getSuppressed() {
	$synchronized(this) {
		if (this->suppressedExceptions == Throwable::SUPPRESSED_SENTINEL || this->suppressedExceptions == nullptr) {
			return Throwable::EMPTY_THROWABLE_ARRAY;
		} else {
			return $fcast($ThrowableArray, $nc(this->suppressedExceptions)->toArray(Throwable::EMPTY_THROWABLE_ARRAY));
		}
	}
}

void clinit$Throwable($Class* class$) {
	$assignStatic(Throwable::NULL_CAUSE_MESSAGE, "Cannot suppress a null exception."_s);
	$assignStatic(Throwable::SELF_SUPPRESSION_MESSAGE, "Self-suppression not permitted"_s);
	$assignStatic(Throwable::CAUSE_CAPTION, "Caused by: "_s);
	$assignStatic(Throwable::SUPPRESSED_CAPTION, "Suppressed: "_s);
	Throwable::$assertionsDisabled = !Throwable::class$->desiredAssertionStatus();
	$assignStatic(Throwable::UNASSIGNED_STACK, $new($StackTraceElementArray, 0));
	$assignStatic(Throwable::SUPPRESSED_SENTINEL, $Collections::emptyList());
	$assignStatic(Throwable::EMPTY_THROWABLE_ARRAY, $new($ThrowableArray, 0));
}

Throwable::Throwable() {
}

Throwable::Throwable(const Throwable& e) {
	if (e.throwing$ != nullptr) {
		this->throwing$ = e.throwing$;
	} else {
		this->throwing$ = (Throwable*)&e;
	}
	ObjectManager::newLocalRef(throwing$);
}

void Throwable::throw$() {
	throw *this;
}

void Throwable::setThrowing$(Throwable* throwing) {
	if (this->throwing$ != throwing) {
		if (this->throwing$ != nullptr) {
			ObjectManager::deleteLocalRef(throwing$);
			this->throwing$ = nullptr;
		}
		if (throwing != nullptr) {
			this->throwing$ = throwing;
			ObjectManager::newLocalRef(throwing);
		}
	}
}

Throwable::~Throwable() {
	if (throwing$ != nullptr) {
		ObjectManager::deleteLocalRef(throwing$);
	}
}

$Class* Throwable::load$($String* name, bool initialize) {
	$loadClass(Throwable, name, initialize, &_Throwable_ClassInfo_, clinit$Throwable, allocate$Throwable);
	return class$;
}

$Class* Throwable::class$ = nullptr;

	} // lang
} // java
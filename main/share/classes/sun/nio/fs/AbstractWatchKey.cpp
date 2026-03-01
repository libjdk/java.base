#include <sun/nio/fs/AbstractWatchKey.h>

#include <java/lang/AssertionError.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardWatchEventKinds.h>
#include <java/nio/file/WatchEvent$Kind.h>
#include <java/nio/file/WatchEvent.h>
#include <java/nio/file/WatchKey.h>
#include <java/nio/file/Watchable.h>
#include <java/util/ArrayList.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <sun/nio/fs/AbstractWatchKey$Event.h>
#include <sun/nio/fs/AbstractWatchKey$State.h>
#include <sun/nio/fs/AbstractWatchService.h>
#include <jcpp.h>

#undef ENTRY_MODIFY
#undef MAX_EVENT_LIST_SIZE
#undef OVERFLOW
#undef OVERFLOW_EVENT
#undef READY
#undef SIGNALLED

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Path = ::java::nio::file::Path;
using $StandardWatchEventKinds = ::java::nio::file::StandardWatchEventKinds;
using $WatchEvent = ::java::nio::file::WatchEvent;
using $WatchEvent$Kind = ::java::nio::file::WatchEvent$Kind;
using $WatchKey = ::java::nio::file::WatchKey;
using $Watchable = ::java::nio::file::Watchable;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $AbstractWatchKey$Event = ::sun::nio::fs::AbstractWatchKey$Event;
using $AbstractWatchKey$State = ::sun::nio::fs::AbstractWatchKey$State;
using $AbstractWatchService = ::sun::nio::fs::AbstractWatchService;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _AbstractWatchKey_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(AbstractWatchKey, $assertionsDisabled)},
	{"MAX_EVENT_LIST_SIZE", "I", nullptr, $STATIC | $FINAL, $constField(AbstractWatchKey, MAX_EVENT_LIST_SIZE)},
	{"OVERFLOW_EVENT", "Lsun/nio/fs/AbstractWatchKey$Event;", "Lsun/nio/fs/AbstractWatchKey$Event<Ljava/lang/Object;>;", $STATIC | $FINAL, $staticField(AbstractWatchKey, OVERFLOW_EVENT)},
	{"watcher", "Lsun/nio/fs/AbstractWatchService;", nullptr, $PRIVATE | $FINAL, $field(AbstractWatchKey, watcher$)},
	{"dir", "Ljava/nio/file/Path;", nullptr, $PRIVATE | $FINAL, $field(AbstractWatchKey, dir)},
	{"state", "Lsun/nio/fs/AbstractWatchKey$State;", nullptr, $PRIVATE, $field(AbstractWatchKey, state)},
	{"events", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/file/WatchEvent<*>;>;", $PRIVATE, $field(AbstractWatchKey, events)},
	{"lastModifyEvents", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Object;Ljava/nio/file/WatchEvent<*>;>;", $PRIVATE, $field(AbstractWatchKey, lastModifyEvents)},
	{}
};

$MethodInfo _AbstractWatchKey_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/Path;Lsun/nio/fs/AbstractWatchService;)V", nullptr, $PROTECTED, $method(AbstractWatchKey, init$, void, $Path*, $AbstractWatchService*)},
	{"pollEvents", "()Ljava/util/List;", "()Ljava/util/List<Ljava/nio/file/WatchEvent<*>;>;", $PUBLIC | $FINAL, $virtualMethod(AbstractWatchKey, pollEvents, $List*)},
	{"reset", "()Z", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractWatchKey, reset, bool)},
	{"signal", "()V", nullptr, $FINAL, $method(AbstractWatchKey, signal, void)},
	{"signalEvent", "(Ljava/nio/file/WatchEvent$Kind;Ljava/lang/Object;)V", "(Ljava/nio/file/WatchEvent$Kind<*>;Ljava/lang/Object;)V", $FINAL, $method(AbstractWatchKey, signalEvent, void, $WatchEvent$Kind*, Object$*)},
	{"watchable", "()Ljava/nio/file/Path;", nullptr, $PUBLIC, $virtualMethod(AbstractWatchKey, watchable, $Watchable*)},
	{"watcher", "()Lsun/nio/fs/AbstractWatchService;", nullptr, $FINAL, $method(AbstractWatchKey, watcher, $AbstractWatchService*)},
	{}
};

$InnerClassInfo _AbstractWatchKey_InnerClassesInfo_[] = {
	{"sun.nio.fs.AbstractWatchKey$Event", "sun.nio.fs.AbstractWatchKey", "Event", $PRIVATE | $STATIC},
	{"sun.nio.fs.AbstractWatchKey$State", "sun.nio.fs.AbstractWatchKey", "State", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _AbstractWatchKey_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.fs.AbstractWatchKey",
	"java.lang.Object",
	"java.nio.file.WatchKey",
	_AbstractWatchKey_FieldInfo_,
	_AbstractWatchKey_MethodInfo_,
	nullptr,
	nullptr,
	_AbstractWatchKey_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.AbstractWatchKey$Event,sun.nio.fs.AbstractWatchKey$State"
};

$Object* allocate$AbstractWatchKey($Class* clazz) {
	return $of($alloc(AbstractWatchKey));
}

bool AbstractWatchKey::$assertionsDisabled = false;
$AbstractWatchKey$Event* AbstractWatchKey::OVERFLOW_EVENT = nullptr;

void AbstractWatchKey::init$($Path* dir, $AbstractWatchService* watcher) {
	$set(this, watcher$, watcher);
	$set(this, dir, dir);
	$init($AbstractWatchKey$State);
	$set(this, state, $AbstractWatchKey$State::READY);
	$set(this, events, $new($ArrayList));
	$set(this, lastModifyEvents, $new($HashMap));
}

$AbstractWatchService* AbstractWatchKey::watcher() {
	return this->watcher$;
}

$Watchable* AbstractWatchKey::watchable() {
	return this->dir;
}

void AbstractWatchKey::signal() {
	$synchronized(this) {
		$init($AbstractWatchKey$State);
		if (this->state == $AbstractWatchKey$State::READY) {
			$set(this, state, $AbstractWatchKey$State::SIGNALLED);
			$nc(this->watcher$)->enqueueKey(this);
		}
	}
}

void AbstractWatchKey::signalEvent($WatchEvent$Kind* kind$renamed, Object$* context$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($WatchEvent$Kind, kind, kind$renamed);
	$var($Object, context, context$renamed);
	$init($StandardWatchEventKinds);
	bool isModify = (kind == $StandardWatchEventKinds::ENTRY_MODIFY);
	$synchronized(this) {
		int32_t size = $nc(this->events)->size();
		if (size > 0) {
			$var($WatchEvent, prev, $cast($WatchEvent, $nc(this->events)->get(size - 1)));
			bool var$0 = ($nc(prev)->kind() == $StandardWatchEventKinds::OVERFLOW);
			if (!var$0) {
				bool var$1 = kind == $nc(prev)->kind();
				var$0 = (var$1 && $Objects::equals(context, $(prev->context())));
			}
			if (var$0) {
				$nc(($cast($AbstractWatchKey$Event, prev)))->increment();
				return;
			}
			if (!$nc(this->lastModifyEvents)->isEmpty()) {
				if (isModify) {
					$var($WatchEvent, ev, $cast($WatchEvent, $nc(this->lastModifyEvents)->get(context)));
					if (ev != nullptr) {
						if (!AbstractWatchKey::$assertionsDisabled && !(ev->kind() == $StandardWatchEventKinds::ENTRY_MODIFY)) {
							$throwNew($AssertionError);
						}
						$nc(($cast($AbstractWatchKey$Event, ev)))->increment();
						return;
					}
				} else {
					$nc(this->lastModifyEvents)->remove(context);
				}
			}
			if (size >= AbstractWatchKey::MAX_EVENT_LIST_SIZE) {
				$assign(kind, $StandardWatchEventKinds::OVERFLOW);
				isModify = false;
				$assign(context, nullptr);
			}
		}
		$var($AbstractWatchKey$Event, ev, $new($AbstractWatchKey$Event, kind, context));
		if (isModify) {
			$nc(this->lastModifyEvents)->put(context, ev);
		} else {
			if (kind == $StandardWatchEventKinds::OVERFLOW) {
				$nc(this->events)->clear();
				$nc(this->lastModifyEvents)->clear();
			}
		}
		$nc(this->events)->add(ev);
		signal();
	}
}

$List* AbstractWatchKey::pollEvents() {
	$synchronized(this) {
		$var($List, result, this->events);
		$set(this, events, $new($ArrayList));
		$nc(this->lastModifyEvents)->clear();
		return result;
	}
}

bool AbstractWatchKey::reset() {
	$synchronized(this) {
		$init($AbstractWatchKey$State);
		if (this->state == $AbstractWatchKey$State::SIGNALLED && isValid()) {
			if ($nc(this->events)->isEmpty()) {
				$set(this, state, $AbstractWatchKey$State::READY);
			} else {
				$nc(this->watcher$)->enqueueKey(this);
			}
		}
		return isValid();
	}
}

void clinit$AbstractWatchKey($Class* class$) {
	AbstractWatchKey::$assertionsDisabled = !AbstractWatchKey::class$->desiredAssertionStatus();
	$init($StandardWatchEventKinds);
	$assignStatic(AbstractWatchKey::OVERFLOW_EVENT, $new($AbstractWatchKey$Event, $StandardWatchEventKinds::OVERFLOW, nullptr));
}

AbstractWatchKey::AbstractWatchKey() {
}

$Class* AbstractWatchKey::load$($String* name, bool initialize) {
	$loadClass(AbstractWatchKey, name, initialize, &_AbstractWatchKey_ClassInfo_, clinit$AbstractWatchKey, allocate$AbstractWatchKey);
	return class$;
}

$Class* AbstractWatchKey::class$ = nullptr;

		} // fs
	} // nio
} // sun
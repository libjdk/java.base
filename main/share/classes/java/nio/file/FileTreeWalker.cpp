#include <java/nio/file/FileTreeWalker.h>

#include <java/io/IOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/file/DirectoryIteratorException.h>
#include <java/nio/file/DirectoryStream.h>
#include <java/nio/file/FileSystemLoopException.h>
#include <java/nio/file/FileTreeWalker$1.h>
#include <java/nio/file/FileTreeWalker$DirectoryNode.h>
#include <java/nio/file/FileTreeWalker$Event.h>
#include <java/nio/file/FileTreeWalker$EventType.h>
#include <java/nio/file/FileVisitOption.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/attribute/BasicFileAttributes.h>
#include <java/util/ArrayDeque.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <sun/nio/fs/BasicFileAttributesHolder.h>
#include <jcpp.h>

#undef END_DIRECTORY
#undef ENTRY
#undef NOFOLLOW_LINKS
#undef START_DIRECTORY

using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $IOException = ::java::io::IOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityException = ::java::lang::SecurityException;
using $DirectoryIteratorException = ::java::nio::file::DirectoryIteratorException;
using $DirectoryStream = ::java::nio::file::DirectoryStream;
using $FileSystemLoopException = ::java::nio::file::FileSystemLoopException;
using $FileTreeWalker$1 = ::java::nio::file::FileTreeWalker$1;
using $FileTreeWalker$DirectoryNode = ::java::nio::file::FileTreeWalker$DirectoryNode;
using $FileTreeWalker$Event = ::java::nio::file::FileTreeWalker$Event;
using $FileTreeWalker$EventType = ::java::nio::file::FileTreeWalker$EventType;
using $FileVisitOption = ::java::nio::file::FileVisitOption;
using $Files = ::java::nio::file::Files;
using $LinkOption = ::java::nio::file::LinkOption;
using $Path = ::java::nio::file::Path;
using $BasicFileAttributes = ::java::nio::file::attribute::BasicFileAttributes;
using $ArrayDeque = ::java::util::ArrayDeque;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $BasicFileAttributesHolder = ::sun::nio::fs::BasicFileAttributesHolder;

namespace java {
	namespace nio {
		namespace file {

$FieldInfo _FileTreeWalker_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(FileTreeWalker, $assertionsDisabled)},
	{"followLinks", "Z", nullptr, $PRIVATE | $FINAL, $field(FileTreeWalker, followLinks)},
	{"linkOptions", "[Ljava/nio/file/LinkOption;", nullptr, $PRIVATE | $FINAL, $field(FileTreeWalker, linkOptions)},
	{"maxDepth", "I", nullptr, $PRIVATE | $FINAL, $field(FileTreeWalker, maxDepth)},
	{"stack", "Ljava/util/ArrayDeque;", "Ljava/util/ArrayDeque<Ljava/nio/file/FileTreeWalker$DirectoryNode;>;", $PRIVATE | $FINAL, $field(FileTreeWalker, stack)},
	{"closed", "Z", nullptr, $PRIVATE, $field(FileTreeWalker, closed)},
	{}
};

$MethodInfo _FileTreeWalker_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Collection;I)V", "(Ljava/util/Collection<Ljava/nio/file/FileVisitOption;>;I)V", 0, $method(FileTreeWalker, init$, void, $Collection*, int32_t)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(FileTreeWalker, close, void)},
	{"getAttributes", "(Ljava/nio/file/Path;Z)Ljava/nio/file/attribute/BasicFileAttributes;", nullptr, $PRIVATE, $method(FileTreeWalker, getAttributes, $BasicFileAttributes*, $Path*, bool), "java.io.IOException"},
	{"isOpen", "()Z", nullptr, 0, $virtualMethod(FileTreeWalker, isOpen, bool)},
	{"next", "()Ljava/nio/file/FileTreeWalker$Event;", nullptr, 0, $virtualMethod(FileTreeWalker, next, $FileTreeWalker$Event*)},
	{"pop", "()V", nullptr, 0, $virtualMethod(FileTreeWalker, pop, void)},
	{"skipRemainingSiblings", "()V", nullptr, 0, $virtualMethod(FileTreeWalker, skipRemainingSiblings, void)},
	{"visit", "(Ljava/nio/file/Path;ZZ)Ljava/nio/file/FileTreeWalker$Event;", nullptr, $PRIVATE, $method(FileTreeWalker, visit, $FileTreeWalker$Event*, $Path*, bool, bool)},
	{"walk", "(Ljava/nio/file/Path;)Ljava/nio/file/FileTreeWalker$Event;", nullptr, 0, $virtualMethod(FileTreeWalker, walk, $FileTreeWalker$Event*, $Path*)},
	{"wouldLoop", "(Ljava/nio/file/Path;Ljava/lang/Object;)Z", nullptr, $PRIVATE, $method(FileTreeWalker, wouldLoop, bool, $Path*, Object$*)},
	{}
};

$InnerClassInfo _FileTreeWalker_InnerClassesInfo_[] = {
	{"java.nio.file.FileTreeWalker$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.nio.file.FileTreeWalker$Event", "java.nio.file.FileTreeWalker", "Event", $STATIC},
	{"java.nio.file.FileTreeWalker$EventType", "java.nio.file.FileTreeWalker", "EventType", $STATIC | $FINAL | $ENUM},
	{"java.nio.file.FileTreeWalker$DirectoryNode", "java.nio.file.FileTreeWalker", "DirectoryNode", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _FileTreeWalker_ClassInfo_ = {
	$ACC_SUPER,
	"java.nio.file.FileTreeWalker",
	"java.lang.Object",
	"java.io.Closeable",
	_FileTreeWalker_FieldInfo_,
	_FileTreeWalker_MethodInfo_,
	nullptr,
	nullptr,
	_FileTreeWalker_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.nio.file.FileTreeWalker$1,java.nio.file.FileTreeWalker$Event,java.nio.file.FileTreeWalker$EventType,java.nio.file.FileTreeWalker$DirectoryNode"
};

$Object* allocate$FileTreeWalker($Class* clazz) {
	return $of($alloc(FileTreeWalker));
}

bool FileTreeWalker::$assertionsDisabled = false;

void FileTreeWalker::init$($Collection* options, int32_t maxDepth) {
	$set(this, stack, $new($ArrayDeque));
	bool fl = false;
	{
		$var($Iterator, i$, $nc(options)->iterator());
		for (; $nc(i$)->hasNext();) {
			$FileVisitOption* option = $cast($FileVisitOption, i$->next());
			{
				$init($FileTreeWalker$1);
				switch ($nc($FileTreeWalker$1::$SwitchMap$java$nio$file$FileVisitOption)->get($nc((option))->ordinal())) {
				case 1:
					{
						fl = true;
						break;
					}
				default:
					{
						$throwNew($AssertionError, $of("Should not get here"_s));
					}
				}
			}
		}
	}
	if (maxDepth < 0) {
		$throwNew($IllegalArgumentException, "\'maxDepth\' is negative"_s);
	}
	this->followLinks = fl;
	$init($LinkOption);
	$set(this, linkOptions, (fl) ? $new($LinkOptionArray, 0) : $new($LinkOptionArray, {$LinkOption::NOFOLLOW_LINKS}));
	this->maxDepth = maxDepth;
}

$BasicFileAttributes* FileTreeWalker::getAttributes($Path* file, bool canUseCached) {
	$useLocalCurrentObjectStackCache();
	if (canUseCached && ($instanceOf($BasicFileAttributesHolder, file)) && ($System::getSecurityManager() == nullptr)) {
		$var($BasicFileAttributes, cached, $nc(($cast($BasicFileAttributesHolder, file)))->get());
		if (cached != nullptr && (!this->followLinks || !$nc(cached)->isSymbolicLink())) {
			return cached;
		}
	}
	$var($BasicFileAttributes, attrs, nullptr);
	try {
		$load($BasicFileAttributes);
		$assign(attrs, $Files::readAttributes(file, $BasicFileAttributes::class$, this->linkOptions));
	} catch ($IOException& ioe) {
		if (!this->followLinks) {
			$throw(ioe);
		}
		$load($BasicFileAttributes);
		$init($LinkOption);
		$assign(attrs, $Files::readAttributes(file, $BasicFileAttributes::class$, $$new($LinkOptionArray, {$LinkOption::NOFOLLOW_LINKS})));
	}
	return attrs;
}

bool FileTreeWalker::wouldLoop($Path* dir, Object$* key) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(this->stack)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($FileTreeWalker$DirectoryNode, ancestor, $cast($FileTreeWalker$DirectoryNode, i$->next()));
			{
				$var($Object, ancestorKey, $nc(ancestor)->key());
				if (key != nullptr && ancestorKey != nullptr) {
					if ($of(key)->equals(ancestorKey)) {
						return true;
					}
				} else {
					try {
						if ($Files::isSameFile(dir, $(ancestor->directory()))) {
							return true;
						}
					} catch ($IOException& x) {
					} catch ($SecurityException& x) {
					}
				}
			}
		}
	}
	return false;
}

$FileTreeWalker$Event* FileTreeWalker::visit($Path* entry, bool ignoreSecurityException, bool canUseCached) {
	$useLocalCurrentObjectStackCache();
	$var($BasicFileAttributes, attrs, nullptr);
	try {
		$assign(attrs, getAttributes(entry, canUseCached));
	} catch ($IOException& ioe) {
		$init($FileTreeWalker$EventType);
		return $new($FileTreeWalker$Event, $FileTreeWalker$EventType::ENTRY, entry, $cast($IOException, ioe));
	} catch ($SecurityException& se) {
		if (ignoreSecurityException) {
			return nullptr;
		}
		$throw(se);
	}
	int32_t depth = $nc(this->stack)->size();
	if (depth >= this->maxDepth || !$nc(attrs)->isDirectory()) {
		$init($FileTreeWalker$EventType);
		return $new($FileTreeWalker$Event, $FileTreeWalker$EventType::ENTRY, entry, attrs);
	}
	if (this->followLinks && wouldLoop(entry, $($nc(attrs)->fileKey()))) {
		$init($FileTreeWalker$EventType);
		return $new($FileTreeWalker$Event, $FileTreeWalker$EventType::ENTRY, entry, static_cast<$IOException*>($$new($FileSystemLoopException, $($nc(entry)->toString()))));
	}
	$var($DirectoryStream, stream, nullptr);
	try {
		$assign(stream, $Files::newDirectoryStream(entry));
	} catch ($IOException& ioe) {
		$init($FileTreeWalker$EventType);
		return $new($FileTreeWalker$Event, $FileTreeWalker$EventType::ENTRY, entry, $cast($IOException, ioe));
	} catch ($SecurityException& se) {
		if (ignoreSecurityException) {
			return nullptr;
		}
		$throw(se);
	}
	$nc(this->stack)->push($$new($FileTreeWalker$DirectoryNode, entry, $($nc(attrs)->fileKey()), stream));
	$init($FileTreeWalker$EventType);
	return $new($FileTreeWalker$Event, $FileTreeWalker$EventType::START_DIRECTORY, entry, attrs);
}

$FileTreeWalker$Event* FileTreeWalker::walk($Path* file) {
	if (this->closed) {
		$throwNew($IllegalStateException, "Closed"_s);
	}
	$var($FileTreeWalker$Event, ev, visit(file, false, false));
	if (!FileTreeWalker::$assertionsDisabled && !(ev != nullptr)) {
		$throwNew($AssertionError);
	}
	return ev;
}

$FileTreeWalker$Event* FileTreeWalker::next() {
	$useLocalCurrentObjectStackCache();
	$var($FileTreeWalker$DirectoryNode, top, $cast($FileTreeWalker$DirectoryNode, $nc(this->stack)->peek()));
	if (top == nullptr) {
		return nullptr;
	}
	$var($FileTreeWalker$Event, ev, nullptr);
	do {
		$var($Path, entry, nullptr);
		$var($IOException, ioe, nullptr);
		if (!$nc(top)->skipped()) {
			$var($Iterator, iterator, top->iterator());
			try {
				if ($nc(iterator)->hasNext()) {
					$assign(entry, $cast($Path, iterator->next()));
				}
			} catch ($DirectoryIteratorException& x) {
				$assign(ioe, $cast($IOException, x->getCause()));
			}
		}
		if (entry == nullptr) {
			try {
				$nc($($nc(top)->stream()))->close();
			} catch ($IOException& e) {
				if (ioe == nullptr) {
					$assign(ioe, e);
				} else {
					$nc(ioe)->addSuppressed(e);
				}
			}
			$nc(this->stack)->pop();
			$init($FileTreeWalker$EventType);
			return $new($FileTreeWalker$Event, $FileTreeWalker$EventType::END_DIRECTORY, $($nc(top)->directory()), ioe);
		}
		$assign(ev, visit(entry, true, true));
	} while (ev == nullptr);
	return ev;
}

void FileTreeWalker::pop() {
	$useLocalCurrentObjectStackCache();
	if (!$nc(this->stack)->isEmpty()) {
		$var($FileTreeWalker$DirectoryNode, node, $cast($FileTreeWalker$DirectoryNode, $nc(this->stack)->pop()));
		try {
			$nc($($nc(node)->stream()))->close();
		} catch ($IOException& ignore) {
		}
	}
}

void FileTreeWalker::skipRemainingSiblings() {
	if (!$nc(this->stack)->isEmpty()) {
		$nc(($cast($FileTreeWalker$DirectoryNode, $($nc(this->stack)->peek()))))->skip();
	}
}

bool FileTreeWalker::isOpen() {
	return !this->closed;
}

void FileTreeWalker::close() {
	if (!this->closed) {
		while (!$nc(this->stack)->isEmpty()) {
			pop();
		}
		this->closed = true;
	}
}

void clinit$FileTreeWalker($Class* class$) {
	FileTreeWalker::$assertionsDisabled = !FileTreeWalker::class$->desiredAssertionStatus();
}

FileTreeWalker::FileTreeWalker() {
}

$Class* FileTreeWalker::load$($String* name, bool initialize) {
	$loadClass(FileTreeWalker, name, initialize, &_FileTreeWalker_ClassInfo_, clinit$FileTreeWalker, allocate$FileTreeWalker);
	return class$;
}

$Class* FileTreeWalker::class$ = nullptr;

		} // file
	} // nio
} // java
#include <sun/nio/fs/WindowsFileCopy.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/file/AtomicMoveNotSupportedException.h>
#include <java/nio/file/CopyOption.h>
#include <java/nio/file/DirectoryNotEmptyException.h>
#include <java/nio/file/DirectoryStream$Filter.h>
#include <java/nio/file/FileAlreadyExistsException.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/LinkPermission.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardCopyOption.h>
#include <java/security/Permission.h>
#include <java/util/Iterator.h>
#include <java/util/concurrent/ExecutionException.h>
#include <sun/nio/fs/Cancellable.h>
#include <sun/nio/fs/ExtendedOptions$InternalOption.h>
#include <sun/nio/fs/ExtendedOptions.h>
#include <sun/nio/fs/NativeBuffer.h>
#include <sun/nio/fs/WindowsAclFileAttributeView.h>
#include <sun/nio/fs/WindowsDirectoryStream.h>
#include <sun/nio/fs/WindowsException.h>
#include <sun/nio/fs/WindowsFileAttributeViews$Dos.h>
#include <sun/nio/fs/WindowsFileAttributeViews.h>
#include <sun/nio/fs/WindowsFileAttributes.h>
#include <sun/nio/fs/WindowsFileCopy$1.h>
#include <sun/nio/fs/WindowsLinkSupport.h>
#include <sun/nio/fs/WindowsNativeDispatcher.h>
#include <sun/nio/fs/WindowsPath.h>
#include <sun/nio/fs/WindowsSecurity$Privilege.h>
#include <sun/nio/fs/WindowsSecurity.h>
#include <jcpp.h>

#undef ATOMIC_MOVE
#undef COPY_ATTRIBUTES
#undef INTERRUPTIBLE
#undef NOFOLLOW_LINKS
#undef REPLACE_EXISTING

using $CopyOptionArray = $Array<::java::nio::file::CopyOption>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $AtomicMoveNotSupportedException = ::java::nio::file::AtomicMoveNotSupportedException;
using $CopyOption = ::java::nio::file::CopyOption;
using $DirectoryNotEmptyException = ::java::nio::file::DirectoryNotEmptyException;
using $DirectoryStream$Filter = ::java::nio::file::DirectoryStream$Filter;
using $FileAlreadyExistsException = ::java::nio::file::FileAlreadyExistsException;
using $LinkOption = ::java::nio::file::LinkOption;
using $LinkPermission = ::java::nio::file::LinkPermission;
using $Path = ::java::nio::file::Path;
using $StandardCopyOption = ::java::nio::file::StandardCopyOption;
using $Permission = ::java::security::Permission;
using $Iterator = ::java::util::Iterator;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $Cancellable = ::sun::nio::fs::Cancellable;
using $ExtendedOptions = ::sun::nio::fs::ExtendedOptions;
using $ExtendedOptions$InternalOption = ::sun::nio::fs::ExtendedOptions$InternalOption;
using $NativeBuffer = ::sun::nio::fs::NativeBuffer;
using $WindowsAclFileAttributeView = ::sun::nio::fs::WindowsAclFileAttributeView;
using $WindowsDirectoryStream = ::sun::nio::fs::WindowsDirectoryStream;
using $WindowsException = ::sun::nio::fs::WindowsException;
using $WindowsFileAttributeViews = ::sun::nio::fs::WindowsFileAttributeViews;
using $WindowsFileAttributeViews$Dos = ::sun::nio::fs::WindowsFileAttributeViews$Dos;
using $WindowsFileAttributes = ::sun::nio::fs::WindowsFileAttributes;
using $WindowsFileCopy$1 = ::sun::nio::fs::WindowsFileCopy$1;
using $WindowsLinkSupport = ::sun::nio::fs::WindowsLinkSupport;
using $WindowsNativeDispatcher = ::sun::nio::fs::WindowsNativeDispatcher;
using $WindowsPath = ::sun::nio::fs::WindowsPath;
using $WindowsSecurity = ::sun::nio::fs::WindowsSecurity;
using $WindowsSecurity$Privilege = ::sun::nio::fs::WindowsSecurity$Privilege;

namespace sun {
	namespace nio {
		namespace fs {

class WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0 : public $DirectoryStream$Filter {
	$class(WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0, $NO_CLASS_INIT, $DirectoryStream$Filter)
public:
	void init$() {
	}
	virtual bool accept(Object$* e) override {
		 return WindowsFileCopy::lambda$ensureEmptyDir$0($cast($Path, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0, init$, void)},
	{"accept", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0, accept, bool, Object$*)},
	{}
};
$ClassInfo WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.nio.fs.WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0",
	"java.lang.Object",
	"java.nio.file.DirectoryStream$Filter",
	nullptr,
	methodInfos
};
$Class* WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0::load$($String* name, bool initialize) {
	$loadClass(WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0::class$ = nullptr;

$FieldInfo _WindowsFileCopy_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(WindowsFileCopy, $assertionsDisabled)},
	{}
};

$MethodInfo _WindowsFileCopy_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(WindowsFileCopy, init$, void)},
	{"asWin32Path", "(Lsun/nio/fs/WindowsPath;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(WindowsFileCopy, asWin32Path, $String*, $WindowsPath*), "java.io.IOException"},
	{"copy", "(Lsun/nio/fs/WindowsPath;Lsun/nio/fs/WindowsPath;[Ljava/nio/file/CopyOption;)V", nullptr, $STATIC | $TRANSIENT, $staticMethod(WindowsFileCopy, copy, void, $WindowsPath*, $WindowsPath*, $CopyOptionArray*), "java.io.IOException"},
	{"copySecurityAttributes", "(Lsun/nio/fs/WindowsPath;Lsun/nio/fs/WindowsPath;Z)V", nullptr, $PRIVATE | $STATIC, $staticMethod(WindowsFileCopy, copySecurityAttributes, void, $WindowsPath*, $WindowsPath*, bool), "java.io.IOException"},
	{"ensureEmptyDir", "(Lsun/nio/fs/WindowsPath;)V", nullptr, $STATIC, $staticMethod(WindowsFileCopy, ensureEmptyDir, void, $WindowsPath*), "java.io.IOException"},
	{"lambda$ensureEmptyDir$0", "(Ljava/nio/file/Path;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(WindowsFileCopy, lambda$ensureEmptyDir$0, bool, $Path*), "java.io.IOException"},
	{"move", "(Lsun/nio/fs/WindowsPath;Lsun/nio/fs/WindowsPath;[Ljava/nio/file/CopyOption;)V", nullptr, $STATIC | $TRANSIENT, $staticMethod(WindowsFileCopy, move, void, $WindowsPath*, $WindowsPath*, $CopyOptionArray*), "java.io.IOException"},
	{}
};

$InnerClassInfo _WindowsFileCopy_InnerClassesInfo_[] = {
	{"sun.nio.fs.WindowsFileCopy$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _WindowsFileCopy_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.WindowsFileCopy",
	"java.lang.Object",
	nullptr,
	_WindowsFileCopy_FieldInfo_,
	_WindowsFileCopy_MethodInfo_,
	nullptr,
	nullptr,
	_WindowsFileCopy_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.WindowsFileCopy$1"
};

$Object* allocate$WindowsFileCopy($Class* clazz) {
	return $of($alloc(WindowsFileCopy));
}

bool WindowsFileCopy::$assertionsDisabled = false;

void WindowsFileCopy::init$() {
}

void WindowsFileCopy::copy($WindowsPath* source, $WindowsPath* target, $CopyOptionArray* options) {
	$init(WindowsFileCopy);
	$useLocalCurrentObjectStackCache();
	bool replaceExisting = false;
	bool copyAttributes = false;
	bool followLinks = true;
	bool interruptible = false;
	{
		$var($CopyOptionArray, arr$, options);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($CopyOption, option, arr$->get(i$));
			{
				$init($StandardCopyOption);
				if ($equals(option, $StandardCopyOption::REPLACE_EXISTING)) {
					replaceExisting = true;
					continue;
				}
				$init($LinkOption);
				if ($equals(option, $LinkOption::NOFOLLOW_LINKS)) {
					followLinks = false;
					continue;
				}
				if ($equals(option, $StandardCopyOption::COPY_ATTRIBUTES)) {
					copyAttributes = true;
					continue;
				}
				$init($ExtendedOptions);
				if ($nc($ExtendedOptions::INTERRUPTIBLE)->matches(option)) {
					interruptible = true;
					continue;
				}
				if (option == nullptr) {
					$throwNew($NullPointerException);
				}
				$throwNew($UnsupportedOperationException, "Unsupported copy option"_s);
			}
		}
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$nc(source)->checkRead();
		$nc(target)->checkWrite();
	}
	$var($WindowsFileAttributes, sourceAttrs, nullptr);
	$var($WindowsFileAttributes, targetAttrs, nullptr);
	int64_t sourceHandle = 0;
	try {
		sourceHandle = $nc(source)->openForReadAttributeAccess(followLinks);
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(source);
	}
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				$assign(sourceAttrs, $WindowsFileAttributes::readAttributes(sourceHandle));
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(source);
			}
			int64_t targetHandle = 0;
			try {
				targetHandle = $nc(target)->openForReadAttributeAccess(false);
				{
					$var($Throwable, var$2, nullptr);
					bool return$3 = false;
					try {
						$assign(targetAttrs, $WindowsFileAttributes::readAttributes(targetHandle));
						if ($WindowsFileAttributes::isSameFile(sourceAttrs, targetAttrs)) {
							return$3 = true;
							goto $finally1;
						}
						if (!replaceExisting) {
							$throwNew($FileAlreadyExistsException, $(target->getPathForExceptionMessage()));
						}
					} catch ($Throwable& var$4) {
						$assign(var$2, var$4);
					} $finally1: {
						$WindowsNativeDispatcher::CloseHandle(targetHandle);
					}
					if (var$2 != nullptr) {
						$throw(var$2);
					}
					if (return$3) {
						return;
					}
				}
			} catch ($WindowsException& x) {
			}
		} catch ($Throwable& var$5) {
			$assign(var$0, var$5);
		} /*finally*/ {
			$WindowsNativeDispatcher::CloseHandle(sourceHandle);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	if (sm != nullptr && $nc(sourceAttrs)->isSymbolicLink()) {
		sm->checkPermission($$new($LinkPermission, "symbolic"_s));
	}
	if ($nc(sourceAttrs)->isUnixDomainSocket()) {
		$throwNew($IOException, "Can not copy socket file"_s);
	}
	$var($String, sourcePath, asWin32Path(source));
	$var($String, targetPath, asWin32Path(target));
	if (targetAttrs != nullptr) {
		try {
			bool var$6 = targetAttrs->isDirectory();
			if (var$6 || targetAttrs->isDirectoryLink()) {
				$WindowsNativeDispatcher::RemoveDirectory(targetPath);
			} else {
				$WindowsNativeDispatcher::DeleteFile(targetPath);
			}
		} catch ($WindowsException& x) {
			if (targetAttrs->isDirectory()) {
				bool var$7 = x->lastError() == 145;
				if (var$7 || x->lastError() == 183) {
					$throwNew($DirectoryNotEmptyException, $($nc(target)->getPathForExceptionMessage()));
				}
			}
			x->rethrowAsIOException(target);
		}
	}
	bool var$8 = !$nc(sourceAttrs)->isDirectory();
	if (var$8 && !sourceAttrs->isDirectoryLink()) {
		int32_t flags = (!followLinks) ? 2048 : 0;
		if (interruptible) {
			$var($Cancellable, copyTask, $new($WindowsFileCopy$1, sourcePath, targetPath, flags, source, target));
			try {
				$Cancellable::runInterruptibly(copyTask);
			} catch ($ExecutionException& e) {
				$var($Throwable, t, e->getCause());
				if ($instanceOf($IOException, t)) {
					$throw($cast($IOException, t));
				}
				$throwNew($IOException, t);
			}
		} else {
			try {
				$WindowsNativeDispatcher::CopyFileEx(sourcePath, targetPath, flags, 0);
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(source, target);
			}
		}
		if (copyAttributes) {
			try {
				copySecurityAttributes(source, target, followLinks);
			} catch ($IOException& x) {
			}
		}
		return;
	}
	try {
		if ($nc(sourceAttrs)->isDirectory()) {
			$WindowsNativeDispatcher::CreateDirectory(targetPath, 0);
		} else {
			$var($String, linkTarget, $WindowsLinkSupport::readLink(source));
			int32_t flags = 1;
			$WindowsNativeDispatcher::CreateSymbolicLink(targetPath, $($WindowsPath::addPrefixIfNeeded(linkTarget)), flags);
		}
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(target);
	}
	if (copyAttributes) {
		$var($WindowsFileAttributeViews$Dos, view, $WindowsFileAttributeViews::createDosView(target, false));
		try {
			$nc(view)->setAttributes(sourceAttrs);
		} catch ($IOException& x) {
			if ($nc(sourceAttrs)->isDirectory()) {
				try {
					$WindowsNativeDispatcher::RemoveDirectory(targetPath);
				} catch ($WindowsException& ignore) {
				}
			}
		}
		try {
			copySecurityAttributes(source, target, followLinks);
		} catch ($IOException& ignore) {
		}
	}
}

void WindowsFileCopy::ensureEmptyDir($WindowsPath* dir) {
	$init(WindowsFileCopy);
	$useLocalCurrentObjectStackCache();
	{
		$var($WindowsDirectoryStream, dirStream, $new($WindowsDirectoryStream, dir, static_cast<$DirectoryStream$Filter*>($$new(WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0))));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					if ($nc($(dirStream->iterator()))->hasNext()) {
						$throwNew($DirectoryNotEmptyException, $($nc(dir)->getPathForExceptionMessage()));
					}
				} catch ($Throwable& t$) {
					try {
						dirStream->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				dirStream->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void WindowsFileCopy::move($WindowsPath* source, $WindowsPath* target, $CopyOptionArray* options) {
	$init(WindowsFileCopy);
	$useLocalCurrentObjectStackCache();
	bool atomicMove = false;
	bool replaceExisting = false;
	{
		$var($CopyOptionArray, arr$, options);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($CopyOption, option, arr$->get(i$));
			{
				$init($StandardCopyOption);
				if ($equals(option, $StandardCopyOption::ATOMIC_MOVE)) {
					atomicMove = true;
					continue;
				}
				if ($equals(option, $StandardCopyOption::REPLACE_EXISTING)) {
					replaceExisting = true;
					continue;
				}
				$init($LinkOption);
				if ($equals(option, $LinkOption::NOFOLLOW_LINKS)) {
					continue;
				}
				if (option == nullptr) {
					$throwNew($NullPointerException);
				}
				$throwNew($UnsupportedOperationException, "Unsupported copy option"_s);
			}
		}
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$nc(source)->checkWrite();
		$nc(target)->checkWrite();
	}
	$var($String, sourcePath, asWin32Path(source));
	$var($String, targetPath, asWin32Path(target));
	if (atomicMove) {
		try {
			$WindowsNativeDispatcher::MoveFileEx(sourcePath, targetPath, 1);
		} catch ($WindowsException& x) {
			if (x->lastError() == 17) {
				$var($String, var$0, $nc(source)->getPathForExceptionMessage());
				$var($String, var$1, $nc(target)->getPathForExceptionMessage());
				$throwNew($AtomicMoveNotSupportedException, var$0, var$1, $(x->errorString()));
			}
			x->rethrowAsIOException(source, target);
		}
		return;
	}
	$var($WindowsFileAttributes, sourceAttrs, nullptr);
	$var($WindowsFileAttributes, targetAttrs, nullptr);
	int64_t sourceHandle = 0;
	try {
		sourceHandle = $nc(source)->openForReadAttributeAccess(false);
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(source);
	}
	{
		$var($Throwable, var$2, nullptr);
		bool return$3 = false;
		try {
			try {
				$assign(sourceAttrs, $WindowsFileAttributes::readAttributes(sourceHandle));
			} catch ($WindowsException& x) {
				x->rethrowAsIOException(source);
			}
			int64_t targetHandle = 0;
			try {
				targetHandle = $nc(target)->openForReadAttributeAccess(false);
				{
					$var($Throwable, var$4, nullptr);
					bool return$5 = false;
					try {
						$assign(targetAttrs, $WindowsFileAttributes::readAttributes(targetHandle));
						if ($WindowsFileAttributes::isSameFile(sourceAttrs, targetAttrs)) {
							return$5 = true;
							goto $finally1;
						}
						if (!replaceExisting) {
							$throwNew($FileAlreadyExistsException, $(target->getPathForExceptionMessage()));
						}
					} catch ($Throwable& var$6) {
						$assign(var$4, var$6);
					} $finally1: {
						$WindowsNativeDispatcher::CloseHandle(targetHandle);
					}
					if (var$4 != nullptr) {
						$throw(var$4);
					}
					if (return$5) {
						return;
					}
				}
			} catch ($WindowsException& x) {
			}
		} catch ($Throwable& var$7) {
			$assign(var$2, var$7);
		} /*finally*/ {
			$WindowsNativeDispatcher::CloseHandle(sourceHandle);
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
		if (return$3) {
			return;
		}
	}
	if (targetAttrs != nullptr) {
		try {
			bool var$8 = targetAttrs->isDirectory();
			if (var$8 || targetAttrs->isDirectoryLink()) {
				$WindowsNativeDispatcher::RemoveDirectory(targetPath);
			} else {
				$WindowsNativeDispatcher::DeleteFile(targetPath);
			}
		} catch ($WindowsException& x) {
			if (targetAttrs->isDirectory()) {
				bool var$9 = x->lastError() == 145;
				if (var$9 || x->lastError() == 183) {
					$throwNew($DirectoryNotEmptyException, $($nc(target)->getPathForExceptionMessage()));
				}
			}
			x->rethrowAsIOException(target);
		}
	}
	try {
		$WindowsNativeDispatcher::MoveFileEx(sourcePath, targetPath, 0);
		return;
	} catch ($WindowsException& x) {
		if (x->lastError() != 17) {
			x->rethrowAsIOException(source, target);
		}
	}
	bool var$10 = !$nc(sourceAttrs)->isDirectory();
	if (var$10 && !sourceAttrs->isDirectoryLink()) {
		try {
			$WindowsNativeDispatcher::MoveFileEx(sourcePath, targetPath, 2);
		} catch ($WindowsException& x) {
			x->rethrowAsIOException(source, target);
		}
		try {
			copySecurityAttributes(source, target, false);
		} catch ($IOException& x) {
		}
		return;
	}
	bool var$11 = !WindowsFileCopy::$assertionsDisabled;
	if (var$11) {
		bool var$12 = $nc(sourceAttrs)->isDirectory();
		var$11 = !(var$12 || $nc(sourceAttrs)->isDirectoryLink());
	}
	if (var$11) {
		$throwNew($AssertionError);
	}
	try {
		if ($nc(sourceAttrs)->isDirectory()) {
			ensureEmptyDir(source);
			$WindowsNativeDispatcher::CreateDirectory(targetPath, 0);
		} else {
			$var($String, linkTarget, $WindowsLinkSupport::readLink(source));
			$WindowsNativeDispatcher::CreateSymbolicLink(targetPath, $($WindowsPath::addPrefixIfNeeded(linkTarget)), 1);
		}
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(target);
	}
	$var($WindowsFileAttributeViews$Dos, view, $WindowsFileAttributeViews::createDosView(target, false));
	try {
		$nc(view)->setAttributes(sourceAttrs);
	} catch ($IOException& x) {
		try {
			$WindowsNativeDispatcher::RemoveDirectory(targetPath);
		} catch ($WindowsException& ignore) {
		}
		$throw(x);
	}
	try {
		copySecurityAttributes(source, target, false);
	} catch ($IOException& ignore) {
	}
	try {
		$WindowsNativeDispatcher::RemoveDirectory(sourcePath);
	} catch ($WindowsException& x) {
		try {
			$WindowsNativeDispatcher::RemoveDirectory(targetPath);
		} catch ($WindowsException& ignore) {
		}
		bool var$13 = x->lastError() == 145;
		if (var$13 || x->lastError() == 183) {
			$throwNew($DirectoryNotEmptyException, $($nc(target)->getPathForExceptionMessage()));
		}
		x->rethrowAsIOException(source);
	}
}

$String* WindowsFileCopy::asWin32Path($WindowsPath* path) {
	$init(WindowsFileCopy);
	try {
		return $nc(path)->getPathForWin32Calls();
	} catch ($WindowsException& x) {
		x->rethrowAsIOException(path);
		return nullptr;
	}
	$shouldNotReachHere();
}

void WindowsFileCopy::copySecurityAttributes($WindowsPath* source, $WindowsPath* target, bool followLinks) {
	$init(WindowsFileCopy);
	$useLocalCurrentObjectStackCache();
	$var($String, path, $WindowsLinkSupport::getFinalPath(source, followLinks));
	$var($WindowsSecurity$Privilege, priv, $WindowsSecurity::enablePrivilege("SeRestorePrivilege"_s));
	{
		$var($Throwable, var$0, nullptr);
		try {
			int32_t request = ((4 | 1) | 2);
			$var($NativeBuffer, buffer, $WindowsAclFileAttributeView::getFileSecurity(path, request));
			{
				$var($Throwable, var$1, nullptr);
				try {
					try {
						$var($String, var$2, $nc(target)->getPathForWin32Calls());
						int32_t var$3 = request;
						$WindowsNativeDispatcher::SetFileSecurity(var$2, var$3, $nc(buffer)->address());
					} catch ($WindowsException& x) {
						x->rethrowAsIOException(target);
					}
				} catch ($Throwable& var$4) {
					$assign(var$1, var$4);
				} /*finally*/ {
					$nc(buffer)->release();
				}
				if (var$1 != nullptr) {
					$throw(var$1);
				}
			}
		} catch ($Throwable& var$5) {
			$assign(var$0, var$5);
		} /*finally*/ {
			$nc(priv)->drop();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool WindowsFileCopy::lambda$ensureEmptyDir$0($Path* e) {
	$init(WindowsFileCopy);
	return true;
}

void clinit$WindowsFileCopy($Class* class$) {
	WindowsFileCopy::$assertionsDisabled = !WindowsFileCopy::class$->desiredAssertionStatus();
}

WindowsFileCopy::WindowsFileCopy() {
}

$Class* WindowsFileCopy::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0::classInfo$.name)) {
			return WindowsFileCopy$$Lambda$lambda$ensureEmptyDir$0::load$(name, initialize);
		}
	}
	$loadClass(WindowsFileCopy, name, initialize, &_WindowsFileCopy_ClassInfo_, clinit$WindowsFileCopy, allocate$WindowsFileCopy);
	return class$;
}

$Class* WindowsFileCopy::class$ = nullptr;

		} // fs
	} // nio
} // sun
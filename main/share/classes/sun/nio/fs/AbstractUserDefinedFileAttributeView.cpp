#include <sun/nio/fs/AbstractUserDefinedFileAttributeView.h>

#include <java/lang/AssertionError.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/file/attribute/UserDefinedFileAttributeView.h>
#include <java/security/Permission.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $UserDefinedFileAttributeView = ::java::nio::file::attribute::UserDefinedFileAttributeView;
using $Permission = ::java::security::Permission;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _AbstractUserDefinedFileAttributeView_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(AbstractUserDefinedFileAttributeView, $assertionsDisabled)},
	{}
};

$MethodInfo _AbstractUserDefinedFileAttributeView_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PROTECTED, $method(AbstractUserDefinedFileAttributeView, init$, void)},
	{"checkAccess", "(Ljava/lang/String;ZZ)V", nullptr, $PROTECTED, $virtualMethod(AbstractUserDefinedFileAttributeView, checkAccess, void, $String*, bool, bool)},
	{"name", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractUserDefinedFileAttributeView, name, $String*)},
	{"readAttributes", "([Ljava/lang/String;)Ljava/util/Map;", "([Ljava/lang/String;)Ljava/util/Map<Ljava/lang/String;Ljava/lang/Object;>;", $PUBLIC | $FINAL, $virtualMethod(AbstractUserDefinedFileAttributeView, readAttributes, $Map*, $StringArray*), "java.io.IOException"},
	{"setAttribute", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(AbstractUserDefinedFileAttributeView, setAttribute, void, $String*, Object$*), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _AbstractUserDefinedFileAttributeView_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"sun.nio.fs.AbstractUserDefinedFileAttributeView",
	"java.lang.Object",
	"java.nio.file.attribute.UserDefinedFileAttributeView,sun.nio.fs.DynamicFileAttributeView",
	_AbstractUserDefinedFileAttributeView_FieldInfo_,
	_AbstractUserDefinedFileAttributeView_MethodInfo_
};

$Object* allocate$AbstractUserDefinedFileAttributeView($Class* clazz) {
	return $of($alloc(AbstractUserDefinedFileAttributeView));
}

int32_t AbstractUserDefinedFileAttributeView::hashCode() {
	 return this->$UserDefinedFileAttributeView::hashCode();
}

bool AbstractUserDefinedFileAttributeView::equals(Object$* obj) {
	 return this->$UserDefinedFileAttributeView::equals(obj);
}

$Object* AbstractUserDefinedFileAttributeView::clone() {
	 return this->$UserDefinedFileAttributeView::clone();
}

$String* AbstractUserDefinedFileAttributeView::toString() {
	 return this->$UserDefinedFileAttributeView::toString();
}

void AbstractUserDefinedFileAttributeView::finalize() {
	this->$UserDefinedFileAttributeView::finalize();
}

bool AbstractUserDefinedFileAttributeView::$assertionsDisabled = false;

void AbstractUserDefinedFileAttributeView::init$() {
}

void AbstractUserDefinedFileAttributeView::checkAccess($String* file, bool checkRead, bool checkWrite) {
	$useLocalCurrentObjectStackCache();
	if (!AbstractUserDefinedFileAttributeView::$assertionsDisabled && !(checkRead || checkWrite)) {
		$throwNew($AssertionError);
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		if (checkRead) {
			sm->checkRead(file);
		}
		if (checkWrite) {
			sm->checkWrite(file);
		}
		sm->checkPermission($$new($RuntimePermission, "accessUserDefinedAttributes"_s));
	}
}

$String* AbstractUserDefinedFileAttributeView::name() {
	return "user"_s;
}

void AbstractUserDefinedFileAttributeView::setAttribute($String* attribute, Object$* value) {
	$var($ByteBuffer, bb, nullptr);
	if ($instanceOf($bytes, value)) {
		$assign(bb, $ByteBuffer::wrap($cast($bytes, value)));
	} else {
		$assign(bb, $cast($ByteBuffer, value));
	}
	write(attribute, bb);
}

$Map* AbstractUserDefinedFileAttributeView::readAttributes($StringArray* attributes) {
	$useLocalCurrentObjectStackCache();
	$var($List, names, $new($ArrayList));
	{
		$var($StringArray, arr$, attributes);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, name, arr$->get(i$));
			{
				if ($nc(name)->equals("*"_s)) {
					$assign(names, list());
					break;
				} else {
					if (name->isEmpty()) {
						$throwNew($IllegalArgumentException);
					}
					$nc(names)->add(name);
				}
			}
		}
	}
	$var($Map, result, $new($HashMap));
	{
		$var($Iterator, i$, $nc(names)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($String, name, $cast($String, i$->next()));
			{
				int32_t size = this->size(name);
				$var($bytes, buf, $new($bytes, size));
				int32_t n = read(name, $($ByteBuffer::wrap(buf)));
				$var($bytes, value, (n == size) ? buf : $Arrays::copyOf(buf, n));
				result->put(name, value);
			}
		}
	}
	return result;
}

void clinit$AbstractUserDefinedFileAttributeView($Class* class$) {
	AbstractUserDefinedFileAttributeView::$assertionsDisabled = !AbstractUserDefinedFileAttributeView::class$->desiredAssertionStatus();
}

AbstractUserDefinedFileAttributeView::AbstractUserDefinedFileAttributeView() {
}

$Class* AbstractUserDefinedFileAttributeView::load$($String* name, bool initialize) {
	$loadClass(AbstractUserDefinedFileAttributeView, name, initialize, &_AbstractUserDefinedFileAttributeView_ClassInfo_, clinit$AbstractUserDefinedFileAttributeView, allocate$AbstractUserDefinedFileAttributeView);
	return class$;
}

$Class* AbstractUserDefinedFileAttributeView::class$ = nullptr;

		} // fs
	} // nio
} // sun
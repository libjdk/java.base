#include <java/nio/file/DirectoryIteratorException.h>

#include <java/io/IOException.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream.h>
#include <java/util/ConcurrentModificationException.h>
#include <java/util/Objects.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ConcurrentModificationException = ::java::util::ConcurrentModificationException;
using $Objects = ::java::util::Objects;

namespace java {
	namespace nio {
		namespace file {

$FieldInfo _DirectoryIteratorException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(DirectoryIteratorException, serialVersionUID)},
	{}
};

$MethodInfo _DirectoryIteratorException_MethodInfo_[] = {
	{"<init>", "(Ljava/io/IOException;)V", nullptr, $PUBLIC, $method(DirectoryIteratorException, init$, void, $IOException*)},
	{"getCause", "()Ljava/io/IOException;", nullptr, $PUBLIC, $virtualMethod(DirectoryIteratorException, getCause, $Throwable*)},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(DirectoryIteratorException, readObject, void, $ObjectInputStream*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{}
};

$ClassInfo _DirectoryIteratorException_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.nio.file.DirectoryIteratorException",
	"java.util.ConcurrentModificationException",
	nullptr,
	_DirectoryIteratorException_FieldInfo_,
	_DirectoryIteratorException_MethodInfo_
};

$Object* allocate$DirectoryIteratorException($Class* clazz) {
	return $of($alloc(DirectoryIteratorException));
}

void DirectoryIteratorException::init$($IOException* cause) {
	$ConcurrentModificationException::init$($cast($Throwable, $Objects::requireNonNull(cause)));
}

$Throwable* DirectoryIteratorException::getCause() {
	return $cast($IOException, $ConcurrentModificationException::getCause());
}

void DirectoryIteratorException::readObject($ObjectInputStream* s) {
	$nc(s)->defaultReadObject();
	$var($Throwable, cause, $ConcurrentModificationException::getCause());
	if (!($instanceOf($IOException, cause))) {
		$throwNew($InvalidObjectException, "Cause must be an IOException"_s);
	}
}

DirectoryIteratorException::DirectoryIteratorException() {
}

DirectoryIteratorException::DirectoryIteratorException(const DirectoryIteratorException& e) : $ConcurrentModificationException(e) {
}

void DirectoryIteratorException::throw$() {
	throw *this;
}

$Class* DirectoryIteratorException::load$($String* name, bool initialize) {
	$loadClass(DirectoryIteratorException, name, initialize, &_DirectoryIteratorException_ClassInfo_, allocate$DirectoryIteratorException);
	return class$;
}

$Class* DirectoryIteratorException::class$ = nullptr;

		} // file
	} // nio
} // java
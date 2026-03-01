#include <indify/Indify$Attr.h>

#include <indify/Indify$ClassFile.h>
#include <indify/Indify$Code.h>
#include <indify/Indify$Inner.h>
#include <indify/Indify$InnerOuter.h>
#include <indify/Indify$Method.h>
#include <indify/Indify$Outer.h>
#include <indify/Indify$Pool.h>
#include <indify/Indify.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/util/Collections.h>
#include <java/util/List.h>
#include <jcpp.h>

using $Indify = ::indify::Indify;
using $Indify$ClassFile = ::indify::Indify$ClassFile;
using $Indify$Code = ::indify::Indify$Code;
using $Indify$Inner = ::indify::Indify$Inner;
using $Indify$InnerOuter = ::indify::Indify$InnerOuter;
using $Indify$Method = ::indify::Indify$Method;
using $Indify$Outer = ::indify::Indify$Outer;
using $Indify$Pool = ::indify::Indify$Pool;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collections = ::java::util::Collections;
using $List = ::java::util::List;

namespace indify {

$FieldInfo _Indify$Attr_FieldInfo_[] = {
	{"name", "S", nullptr, $PUBLIC, $field(Indify$Attr, name)},
	{"size", "I", nullptr, $PUBLIC, $field(Indify$Attr, size)},
	{"item", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Indify$Attr, item)},
	{}
};

$MethodInfo _Indify$Attr_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(Indify$Attr, init$, void)},
	{"<init>", "(Lindify/Indify$Outer;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(Indify$Attr, init$, void, $Indify$Outer*, $String*, Object$*)},
	{"attrs", "()Ljava/util/List;", "()Ljava/util/List<Lindify/Indify$Attr;>;", $PUBLIC, $virtualMethod(Indify$Attr, attrs, $List*)},
	{"flatten", "()[B", nullptr, $PUBLIC, $virtualMethod(Indify$Attr, flatten, $bytes*)},
	{"flatten", "(Ljava/io/DataOutputStream;)I", nullptr, $PUBLIC, $virtualMethod(Indify$Attr, flatten, int32_t, $DataOutputStream*), "java.io.IOException"},
	{"flatten", "(Ljava/io/ByteArrayOutputStream;)I", nullptr, $PRIVATE, $method(Indify$Attr, flatten, int32_t, $ByteArrayOutputStream*)},
	{"inners", "()Ljava/util/List;", "()Ljava/util/List<Lindify/Indify$Inner;>;", $PUBLIC, $virtualMethod(Indify$Attr, inners, $List*)},
	{"linkOuter", "(Lindify/Indify$Outer;)V", nullptr, $PUBLIC, $virtualMethod(Indify$Attr, linkOuter, void, $Indify$Outer*)},
	{"nameString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Indify$Attr, nameString, $String*)},
	{"readFrom", "(Ljava/io/DataInputStream;)V", nullptr, $PUBLIC, $virtualMethod(Indify$Attr, readFrom, void, $DataInputStream*), "java.io.IOException"},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Indify$Attr, toString, $String*)},
	{"writeTo", "(Ljava/io/DataOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(Indify$Attr, writeTo, void, $DataOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _Indify$Attr_InnerClassesInfo_[] = {
	{"indify.Indify$Attr", "indify.Indify", "Attr", $PUBLIC | $STATIC},
	{"indify.Indify$InnerOuter", "indify.Indify", "InnerOuter", $PUBLIC | $STATIC | $ABSTRACT},
	{"indify.Indify$Chunk", "indify.Indify", "Chunk", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Indify$Attr_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"indify.Indify$Attr",
	"indify.Indify$InnerOuter",
	"indify.Indify$Chunk",
	_Indify$Attr_FieldInfo_,
	_Indify$Attr_MethodInfo_,
	nullptr,
	nullptr,
	_Indify$Attr_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"indify.Indify"
};

$Object* allocate$Indify$Attr($Class* clazz) {
	return $of($alloc(Indify$Attr));
}

int32_t Indify$Attr::hashCode() {
	 return this->$Indify$InnerOuter::hashCode();
}

bool Indify$Attr::equals(Object$* arg0) {
	 return this->$Indify$InnerOuter::equals(arg0);
}

$Object* Indify$Attr::clone() {
	 return this->$Indify$InnerOuter::clone();
}

void Indify$Attr::finalize() {
	this->$Indify$InnerOuter::finalize();
}

void Indify$Attr::init$() {
	$Indify$InnerOuter::init$();
	this->size = -1;
}

void Indify$Attr::init$($Indify$Outer* outer, $String* name, Object$* item) {
	$useLocalCurrentObjectStackCache();
	$Indify$InnerOuter::init$();
	this->size = -1;
	$load($Indify$ClassFile);
	$var($Indify$ClassFile, cf, $cast($Indify$ClassFile, $nc(outer)->outer($Indify$ClassFile::class$)));
	linkOuter(outer);
	this->name = (int16_t)$nc($nc(cf)->pool)->stringIndex(name, true);
	$set(this, item, item);
	$nc($(outer->attrs()))->add(this);
}

void Indify$Attr::readFrom($DataInputStream* in) {
	this->name = $nc(in)->readShort();
	this->size = in->readInt();
	$set(this, item, $Indify::readRawBytes(in, this->size));
}

void Indify$Attr::writeTo($DataOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$nc(out)->writeShort(this->name);
	$var($bytes, bytes, nullptr);
	int32_t trueSize = 0;
	if ($instanceOf($bytes, this->item)) {
		$assign(bytes, $cast($bytes, this->item));
		out->writeInt(trueSize = $nc(bytes)->length);
		out->write(bytes);
	} else {
		trueSize = flatten(out);
	}
	if (trueSize != this->size && this->size >= 0) {
		$nc($System::err)->println($$str({"warning: attribute size changed "_s, $$str(this->size), " to "_s, $$str(trueSize)}));
	}
}

void Indify$Attr::linkOuter($Indify$Outer* o) {
	$Indify$InnerOuter::linkOuter(o);
	if ($instanceOf($bytes, this->item) && $instanceOf($Indify$Method, this->outer$) && $nc($($cast($Indify$ClassFile, $nc(($cast($Indify$Method, this->outer$)))->outer())))->Code_index == this->name) {
		$load($Indify$Code);
		$set(this, item, $Indify::readInput($cast($bytes, this->item), $Indify$Code::class$));
	}
}

$List* Indify$Attr::inners() {
	if ($instanceOf($Indify$Inner, this->item)) {
		return $Collections::nCopies(1, $cast($Indify$Inner, this->item));
	}
	return $Collections::emptyList();
}

$List* Indify$Attr::attrs() {
	return nullptr;
}

$bytes* Indify$Attr::flatten() {
	$var($ByteArrayOutputStream, buf, $new($ByteArrayOutputStream, $Math::max(20, this->size)));
	flatten(buf);
	return buf->toByteArray();
}

int32_t Indify$Attr::flatten($DataOutputStream* out) {
	$var($ByteArrayOutputStream, buf, $new($ByteArrayOutputStream, $Math::max(20, this->size)));
	int32_t trueSize = flatten(buf);
	$nc(out)->writeInt(trueSize);
	buf->writeTo(out);
	return trueSize;
}

int32_t Indify$Attr::flatten($ByteArrayOutputStream* buf) {
	try {
		$Indify::writeOutput($$new($DataOutputStream, buf), this->item);
		return $nc(buf)->size();
	} catch ($IOException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

$String* Indify$Attr::nameString() {
	$useLocalCurrentObjectStackCache();
	$load($Indify$ClassFile);
	$var($Indify$ClassFile, cf, $cast($Indify$ClassFile, outer($Indify$ClassFile::class$)));
	if (cf == nullptr) {
		return $str({"#"_s, $$str(this->name)});
	}
	return $nc($nc(cf)->pool)->getString(this->name);
}

$String* Indify$Attr::toString() {
	$useLocalCurrentObjectStackCache();
	return $str({$(nameString()), (this->size < 0 ? "="_s : $$str({"["_s, $$str(this->size), "]="_s})), this->item});
}

Indify$Attr::Indify$Attr() {
}

$Class* Indify$Attr::load$($String* name, bool initialize) {
	$loadClass(Indify$Attr, name, initialize, &_Indify$Attr_ClassInfo_, allocate$Indify$Attr);
	return class$;
}

$Class* Indify$Attr::class$ = nullptr;

} // indify
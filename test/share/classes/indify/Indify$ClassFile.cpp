#include <indify/Indify$ClassFile.h>

#include <indify/Indify$Attr.h>
#include <indify/Indify$CountedList.h>
#include <indify/Indify$Field.h>
#include <indify/Indify$Method.h>
#include <indify/Indify$Outer.h>
#include <indify/Indify$Pool.h>
#include <indify/Indify.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/DataOutputStream.h>
#include <java/io/File.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/InternalError.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <jcpp.h>

using $Indify = ::indify::Indify;
using $Indify$Attr = ::indify::Indify$Attr;
using $Indify$CountedList = ::indify::Indify$CountedList;
using $Indify$Field = ::indify::Indify$Field;
using $Indify$Method = ::indify::Indify$Method;
using $Indify$Outer = ::indify::Indify$Outer;
using $Indify$Pool = ::indify::Indify$Pool;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $DataOutputStream = ::java::io::DataOutputStream;
using $File = ::java::io::File;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;

namespace indify {

$FieldInfo _Indify$ClassFile_FieldInfo_[] = {
	{"this$0", "Lindify/Indify;", nullptr, $FINAL | $SYNTHETIC, $field(Indify$ClassFile, this$0)},
	{"magic", "I", nullptr, $PUBLIC, $field(Indify$ClassFile, magic)},
	{"version", "I", nullptr, $PUBLIC, $field(Indify$ClassFile, version)},
	{"pool", "Lindify/Indify$Pool;", nullptr, $PUBLIC | $FINAL, $field(Indify$ClassFile, pool)},
	{"access", "S", nullptr, $PUBLIC, $field(Indify$ClassFile, access)},
	{"thisc", "S", nullptr, $PUBLIC, $field(Indify$ClassFile, thisc)},
	{"superc", "S", nullptr, $PUBLIC, $field(Indify$ClassFile, superc)},
	{"interfaces", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Short;>;", $PUBLIC | $FINAL, $field(Indify$ClassFile, interfaces)},
	{"fields", "Ljava/util/List;", "Ljava/util/List<Lindify/Indify$Field;>;", $PUBLIC | $FINAL, $field(Indify$ClassFile, fields)},
	{"methods", "Ljava/util/List;", "Ljava/util/List<Lindify/Indify$Method;>;", $PUBLIC | $FINAL, $field(Indify$ClassFile, methods)},
	{"attrs", "Ljava/util/List;", "Ljava/util/List<Lindify/Indify$Attr;>;", $PUBLIC | $FINAL, $field(Indify$ClassFile, attrs$)},
	{"Code_index", "I", nullptr, 0, $field(Indify$ClassFile, Code_index)},
	{}
};

$MethodInfo _Indify$ClassFile_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Lindify/Indify;Ljava/io/File;)V", nullptr, 0, $method(Indify$ClassFile, init$, void, $Indify*, $File*), "java.io.IOException"},
	{"attrs", "()Ljava/util/List;", "()Ljava/util/List<Lindify/Indify$Attr;>;", $PUBLIC, $virtualMethod(Indify$ClassFile, attrs, $List*)},
	{"inners", "()Ljava/util/List;", "()Ljava/util/List<Lindify/Indify$Inner;>;", $PUBLIC, $virtualMethod(Indify$ClassFile, inners, $List*)},
	{"nameString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Indify$ClassFile, nameString, $String*)},
	{"readFrom", "(Ljava/io/DataInputStream;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(Indify$ClassFile, readFrom, void, $DataInputStream*), "java.io.IOException"},
	{"toByteArray", "()[B", nullptr, $PUBLIC, $virtualMethod(Indify$ClassFile, toByteArray, $bytes*)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeTo", "(Ljava/io/File;)V", nullptr, 0, $virtualMethod(Indify$ClassFile, writeTo, void, $File*), "java.io.IOException"},
	{"writeTo", "(Ljava/io/DataOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(Indify$ClassFile, writeTo, void, $DataOutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _Indify$ClassFile_InnerClassesInfo_[] = {
	{"indify.Indify$ClassFile", "indify.Indify", "ClassFile", $PUBLIC},
	{"indify.Indify$Outer", "indify.Indify", "Outer", $PUBLIC | $STATIC | $ABSTRACT},
	{"indify.Indify$Chunk", "indify.Indify", "Chunk", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Indify$ClassFile_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"indify.Indify$ClassFile",
	"indify.Indify$Outer",
	"indify.Indify$Chunk",
	_Indify$ClassFile_FieldInfo_,
	_Indify$ClassFile_MethodInfo_,
	nullptr,
	nullptr,
	_Indify$ClassFile_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"indify.Indify"
};

$Object* allocate$Indify$ClassFile($Class* clazz) {
	return $of($alloc(Indify$ClassFile));
}

int32_t Indify$ClassFile::hashCode() {
	 return this->$Indify$Outer::hashCode();
}

bool Indify$ClassFile::equals(Object$* arg0) {
	 return this->$Indify$Outer::equals(arg0);
}

$Object* Indify$ClassFile::clone() {
	 return this->$Indify$Outer::clone();
}

$String* Indify$ClassFile::toString() {
	 return this->$Indify$Outer::toString();
}

void Indify$ClassFile::finalize() {
	this->$Indify$Outer::finalize();
}

void Indify$ClassFile::init$($Indify* this$0, $File* f) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$0, this$0);
	$Indify$Outer::init$();
	$set(this, pool, $new($Indify$Pool));
	$load($Short);
	$set(this, interfaces, $new($Indify$CountedList, $Short::class$));
	$load($Indify$Field);
	$set(this, fields, $new($Indify$CountedList, $Indify$Field::class$));
	$load($Indify$Method);
	$set(this, methods, $new($Indify$CountedList, $Indify$Method::class$));
	$load($Indify$Attr);
	$set(this, attrs$, $new($Indify$CountedList, $Indify$Attr::class$));
	$var($DataInputStream, in, this$0->openInput(f));
	{
		$var($Throwable, var$0, nullptr);
		try {
			readFrom(in);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (in != nullptr) {
				in->close();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Indify$ClassFile::readFrom($DataInputStream* in) {
	this->magic = $nc(in)->readInt();
	this->version = in->readInt();
	if (this->magic != (int32_t)0xCAFEBABE) {
		$throwNew($IOException, "bad magic number"_s);
	}
	$nc(this->pool)->readFrom(in);
	this->Code_index = $nc(this->pool)->stringIndex("Code"_s, false);
	this->access = in->readShort();
	this->thisc = in->readShort();
	this->superc = in->readShort();
	$Indify::readInputs(in, $$new($ObjectArray, {
		$of(this->interfaces),
		$of(this->fields),
		$of(this->methods),
		$of(this->attrs$)
	}));
	if (in->read() >= 0) {
		$throwNew($IOException, "junk after end of file"_s);
	}
	linkInners();
}

void Indify$ClassFile::writeTo($File* f) {
	$useLocalCurrentObjectStackCache();
	$var($DataOutputStream, out, this->this$0->openOutput(f));
	{
		$var($Throwable, var$0, nullptr);
		try {
			writeTo(out);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(out)->close();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Indify$ClassFile::writeTo($DataOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$Indify::writeOutputs(out, $$new($ObjectArray, {
		$($of($Integer::valueOf(this->magic))),
		$($of($Integer::valueOf(this->version))),
		$of(this->pool),
		$($of($Short::valueOf(this->access))),
		$($of($Short::valueOf(this->thisc))),
		$($of($Short::valueOf(this->superc))),
		$of(this->interfaces),
		$of(this->fields),
		$of(this->methods),
		$of(this->attrs$)
	}));
}

$bytes* Indify$ClassFile::toByteArray() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ByteArrayOutputStream, buf, $new($ByteArrayOutputStream));
		writeTo($$new($DataOutputStream, buf));
		return buf->toByteArray();
	} catch ($IOException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

$List* Indify$ClassFile::inners() {
	$var($List, inns, $new($ArrayList));
	inns->addAll(this->fields);
	inns->addAll(this->methods);
	inns->addAll(this->attrs$);
	return inns;
}

$List* Indify$ClassFile::attrs() {
	return this->attrs$;
}

$String* Indify$ClassFile::nameString() {
	return $nc(this->pool)->getString((int8_t)7, this->thisc);
}

Indify$ClassFile::Indify$ClassFile() {
}

$Class* Indify$ClassFile::load$($String* name, bool initialize) {
	$loadClass(Indify$ClassFile, name, initialize, &_Indify$ClassFile_ClassInfo_, allocate$Indify$ClassFile);
	return class$;
}

$Class* Indify$ClassFile::class$ = nullptr;

} // indify
#include <DefineClassByteBuffer$DummyClassLoader.h>

#include <DefineClassByteBuffer.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/IOException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/MappedByteBuffer.h>
#include <java/nio/channels/FileChannel$MapMode.h>
#include <java/nio/channels/FileChannel.h>
#include <java/security/ProtectionDomain.h>
#include <jcpp.h>

#undef ARRAY_BUFFER
#undef CLASS_NAME
#undef DIRECT_BUFFER
#undef DUP_ARRAY_BUFFER
#undef DUP_DIRECT_BUFFER
#undef MAPPED_BUFFER
#undef MAX_TYPE
#undef READ_ONLY
#undef READ_ONLY_ARRAY_BUFFER
#undef READ_ONLY_DIRECT_BUFFER
#undef WRAPPED_BUFFER

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $FileChannel = ::java::nio::channels::FileChannel;
using $FileChannel$MapMode = ::java::nio::channels::FileChannel$MapMode;
using $ProtectionDomain = ::java::security::ProtectionDomain;

$FieldInfo _DefineClassByteBuffer$DummyClassLoader_FieldInfo_[] = {
	{"CLASS_NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(DefineClassByteBuffer$DummyClassLoader, CLASS_NAME)},
	{"MAPPED_BUFFER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DefineClassByteBuffer$DummyClassLoader, MAPPED_BUFFER)},
	{"DIRECT_BUFFER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DefineClassByteBuffer$DummyClassLoader, DIRECT_BUFFER)},
	{"ARRAY_BUFFER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DefineClassByteBuffer$DummyClassLoader, ARRAY_BUFFER)},
	{"WRAPPED_BUFFER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DefineClassByteBuffer$DummyClassLoader, WRAPPED_BUFFER)},
	{"READ_ONLY_ARRAY_BUFFER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DefineClassByteBuffer$DummyClassLoader, READ_ONLY_ARRAY_BUFFER)},
	{"READ_ONLY_DIRECT_BUFFER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DefineClassByteBuffer$DummyClassLoader, READ_ONLY_DIRECT_BUFFER)},
	{"DUP_ARRAY_BUFFER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DefineClassByteBuffer$DummyClassLoader, DUP_ARRAY_BUFFER)},
	{"DUP_DIRECT_BUFFER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DefineClassByteBuffer$DummyClassLoader, DUP_DIRECT_BUFFER)},
	{"MAX_TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(DefineClassByteBuffer$DummyClassLoader, MAX_TYPE)},
	{"loaderType", "I", nullptr, 0, $field(DefineClassByteBuffer$DummyClassLoader, loaderType)},
	{"buffers", "[Ljava/nio/ByteBuffer;", nullptr, $STATIC, $staticField(DefineClassByteBuffer$DummyClassLoader, buffers)},
	{}
};

$MethodInfo _DefineClassByteBuffer$DummyClassLoader_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, 0, $method(DefineClassByteBuffer$DummyClassLoader, init$, void, int32_t)},
	{"findClass", "(Ljava/lang/String;)Ljava/lang/Class;", "(Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(DefineClassByteBuffer$DummyClassLoader, findClass, $Class*, $String*), "java.lang.ClassNotFoundException"},
	{"loadClass", "(Ljava/lang/String;Z)Ljava/lang/Class;", "(Ljava/lang/String;Z)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(DefineClassByteBuffer$DummyClassLoader, loadClass, $Class*, $String*, bool), "java.lang.ClassNotFoundException"},
	{"readClassFile", "(Ljava/lang/String;)Ljava/nio/ByteBuffer;", nullptr, $STATIC, $staticMethod(DefineClassByteBuffer$DummyClassLoader, readClassFile, $ByteBuffer*, $String*)},
	{}
};

$InnerClassInfo _DefineClassByteBuffer$DummyClassLoader_InnerClassesInfo_[] = {
	{"DefineClassByteBuffer$DummyClassLoader", "DefineClassByteBuffer", "DummyClassLoader", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _DefineClassByteBuffer$DummyClassLoader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"DefineClassByteBuffer$DummyClassLoader",
	"java.lang.ClassLoader",
	nullptr,
	_DefineClassByteBuffer$DummyClassLoader_FieldInfo_,
	_DefineClassByteBuffer$DummyClassLoader_MethodInfo_,
	nullptr,
	nullptr,
	_DefineClassByteBuffer$DummyClassLoader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"DefineClassByteBuffer"
};

$Object* allocate$DefineClassByteBuffer$DummyClassLoader($Class* clazz) {
	return $of($alloc(DefineClassByteBuffer$DummyClassLoader));
}

$String* DefineClassByteBuffer$DummyClassLoader::CLASS_NAME = nullptr;
$ByteBufferArray* DefineClassByteBuffer$DummyClassLoader::buffers = nullptr;

void DefineClassByteBuffer$DummyClassLoader::init$(int32_t loaderType) {
	$ClassLoader::init$();
	this->loaderType = loaderType;
}

$ByteBuffer* DefineClassByteBuffer$DummyClassLoader::readClassFile($String* name) {
	$init(DefineClassByteBuffer$DummyClassLoader);
	$useLocalCurrentObjectStackCache();
	try {
		$var($File, f, $new($File, $($System::getProperty("test.classes"_s, "."_s)), name));
		$var($FileInputStream, fin, $new($FileInputStream, f));
		$var($FileChannel, fc, fin->getChannel());
		$init($FileChannel$MapMode);
		return $nc(fc)->map($FileChannel$MapMode::READ_ONLY, 0, fc->size());
	} catch ($FileNotFoundException& e) {
		$throwNew($RuntimeException, $$str({"Can\'t open file: "_s, name}), e);
	} catch ($IOException& e) {
		$throwNew($RuntimeException, $$str({"Can\'t open file: "_s, name}), e);
	}
	$shouldNotReachHere();
}

$Class* DefineClassByteBuffer$DummyClassLoader::loadClass($String* name, bool resolve) {
	$Class* c = nullptr;
	if (!"TestClass"_s->equals(name)) {
		c = $ClassLoader::loadClass(name, resolve);
	} else {
		c = findClass(name);
		if (resolve) {
			resolveClass(c);
		}
	}
	return c;
}

$Class* DefineClassByteBuffer$DummyClassLoader::findClass($String* name) {
	if (!"TestClass"_s->equals(name)) {
		$throwNew($ClassNotFoundException, $$str({"Unexpected class: "_s, name}));
	}
	return defineClass(name, $nc(DefineClassByteBuffer$DummyClassLoader::buffers)->get(this->loaderType), ($ProtectionDomain*)nullptr);
}

void clinit$DefineClassByteBuffer$DummyClassLoader($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(DefineClassByteBuffer$DummyClassLoader::CLASS_NAME, "TestClass"_s);
	$assignStatic(DefineClassByteBuffer$DummyClassLoader::buffers, $new($ByteBufferArray, DefineClassByteBuffer$DummyClassLoader::MAX_TYPE + 1));
	{
		$nc(DefineClassByteBuffer$DummyClassLoader::buffers)->set(DefineClassByteBuffer$DummyClassLoader::MAPPED_BUFFER, $(DefineClassByteBuffer$DummyClassLoader::readClassFile($$str({DefineClassByteBuffer$DummyClassLoader::CLASS_NAME, ".class"_s}))));
		$var($bytes, array, $new($bytes, $nc($nc(DefineClassByteBuffer$DummyClassLoader::buffers)->get(DefineClassByteBuffer$DummyClassLoader::MAPPED_BUFFER))->limit()));
		$nc($($nc($nc(DefineClassByteBuffer$DummyClassLoader::buffers)->get(DefineClassByteBuffer$DummyClassLoader::MAPPED_BUFFER))->get(array)))->flip();
		$nc(DefineClassByteBuffer$DummyClassLoader::buffers)->set(DefineClassByteBuffer$DummyClassLoader::DIRECT_BUFFER, $($ByteBuffer::allocateDirect(array->length)));
		$nc($($nc($nc(DefineClassByteBuffer$DummyClassLoader::buffers)->get(DefineClassByteBuffer$DummyClassLoader::DIRECT_BUFFER))->put(array)))->flip();
		$nc(DefineClassByteBuffer$DummyClassLoader::buffers)->set(DefineClassByteBuffer$DummyClassLoader::ARRAY_BUFFER, $($ByteBuffer::allocate(array->length)));
		$nc($($nc($nc(DefineClassByteBuffer$DummyClassLoader::buffers)->get(DefineClassByteBuffer$DummyClassLoader::ARRAY_BUFFER))->put(array)))->flip();
		$nc(DefineClassByteBuffer$DummyClassLoader::buffers)->set(DefineClassByteBuffer$DummyClassLoader::WRAPPED_BUFFER, $($ByteBuffer::wrap(array)));
		$nc(DefineClassByteBuffer$DummyClassLoader::buffers)->set(DefineClassByteBuffer$DummyClassLoader::READ_ONLY_ARRAY_BUFFER, $($nc($nc(DefineClassByteBuffer$DummyClassLoader::buffers)->get(DefineClassByteBuffer$DummyClassLoader::ARRAY_BUFFER))->asReadOnlyBuffer()));
		$nc(DefineClassByteBuffer$DummyClassLoader::buffers)->set(DefineClassByteBuffer$DummyClassLoader::READ_ONLY_DIRECT_BUFFER, $($nc($nc(DefineClassByteBuffer$DummyClassLoader::buffers)->get(DefineClassByteBuffer$DummyClassLoader::DIRECT_BUFFER))->asReadOnlyBuffer()));
		$nc(DefineClassByteBuffer$DummyClassLoader::buffers)->set(DefineClassByteBuffer$DummyClassLoader::DUP_ARRAY_BUFFER, $($nc($nc(DefineClassByteBuffer$DummyClassLoader::buffers)->get(DefineClassByteBuffer$DummyClassLoader::ARRAY_BUFFER))->duplicate()));
		$nc(DefineClassByteBuffer$DummyClassLoader::buffers)->set(DefineClassByteBuffer$DummyClassLoader::DUP_DIRECT_BUFFER, $($nc($nc(DefineClassByteBuffer$DummyClassLoader::buffers)->get(DefineClassByteBuffer$DummyClassLoader::DIRECT_BUFFER))->duplicate()));
	}
}

DefineClassByteBuffer$DummyClassLoader::DefineClassByteBuffer$DummyClassLoader() {
}

$Class* DefineClassByteBuffer$DummyClassLoader::load$($String* name, bool initialize) {
	$loadClass(DefineClassByteBuffer$DummyClassLoader, name, initialize, &_DefineClassByteBuffer$DummyClassLoader_ClassInfo_, clinit$DefineClassByteBuffer$DummyClassLoader, allocate$DefineClassByteBuffer$DummyClassLoader);
	return class$;
}

$Class* DefineClassByteBuffer$DummyClassLoader::class$ = nullptr;
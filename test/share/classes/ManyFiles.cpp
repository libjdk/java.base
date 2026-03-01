#include <ManyFiles.h>

#include <java/io/File.h>
#include <java/io/FileOutputStream.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef NUM_FILES

using $File = ::java::io::File;
using $FileOutputStream = ::java::io::FileOutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$FieldInfo _ManyFiles_FieldInfo_[] = {
	{"count", "I", nullptr, $STATIC, $staticField(ManyFiles, count)},
	{"files", "Ljava/util/List;", nullptr, $STATIC, $staticField(ManyFiles, files)},
	{"streams", "Ljava/util/List;", nullptr, $STATIC, $staticField(ManyFiles, streams)},
	{"NUM_FILES", "I", nullptr, $STATIC, $staticField(ManyFiles, NUM_FILES)},
	{}
};

$MethodInfo _ManyFiles_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ManyFiles, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ManyFiles, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _ManyFiles_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ManyFiles",
	"java.lang.Object",
	nullptr,
	_ManyFiles_FieldInfo_,
	_ManyFiles_MethodInfo_
};

$Object* allocate$ManyFiles($Class* clazz) {
	return $of($alloc(ManyFiles));
}

int32_t ManyFiles::count = 0;
$List* ManyFiles::files = nullptr;
$List* ManyFiles::streams = nullptr;
int32_t ManyFiles::NUM_FILES = 0;

void ManyFiles::init$() {
}

void ManyFiles::main($StringArray* args) {
	$init(ManyFiles);
	$useLocalCurrentObjectStackCache();
	$var($String, osName, $System::getProperty("os.name"_s));
	if ($nc(osName)->startsWith("Linux"_s)) {
		return;
	}
	for (int32_t n = 0; n < ManyFiles::NUM_FILES; ++n) {
		$var($String, var$0, "file"_s);
		$var($File, f, $new($File, $$concat(var$0, $$str(ManyFiles::count++))));
		$nc(ManyFiles::files)->add(f);
		$nc(ManyFiles::streams)->add($$new($FileOutputStream, f));
	}
	$var($Iterator, i, $nc(ManyFiles::streams)->iterator());
	while ($nc(i)->hasNext()) {
		$var($FileOutputStream, fos, $cast($FileOutputStream, i->next()));
		$nc(fos)->close();
	}
	$assign(i, $nc(ManyFiles::files)->iterator());
	while ($nc(i)->hasNext()) {
		$var($File, f, $cast($File, i->next()));
		$nc(f)->delete$();
	}
}

void clinit$ManyFiles($Class* class$) {
	$assignStatic(ManyFiles::files, $new($ArrayList));
	$assignStatic(ManyFiles::streams, $new($ArrayList));
	ManyFiles::NUM_FILES = 2050;
}

ManyFiles::ManyFiles() {
}

$Class* ManyFiles::load$($String* name, bool initialize) {
	$loadClass(ManyFiles, name, initialize, &_ManyFiles_ClassInfo_, clinit$ManyFiles, allocate$ManyFiles);
	return class$;
}

$Class* ManyFiles::class$ = nullptr;
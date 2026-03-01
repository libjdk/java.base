#include <jdk/internal/util/jar/JarIndex.h>

#include <java/io/BufferedReader.h>
#include <java/io/BufferedWriter.h>
#include <java/io/File.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/io/Reader.h>
#include <java/io/Writer.h>
#include <java/nio/charset/Charset.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/Map$Entry.h>
#include <java/util/Set.h>
#include <java/util/Vector.h>
#include <java/util/jar/JarEntry.h>
#include <java/util/jar/JarFile.h>
#include <java/util/zip/ZipEntry.h>
#include <java/util/zip/ZipFile.h>
#include <sun/nio/cs/UTF_8.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef INDEX_NAME
#undef INSTANCE
#undef MANIFEST_NAME

using $BufferedReader = ::java::io::BufferedReader;
using $BufferedWriter = ::java::io::BufferedWriter;
using $File = ::java::io::File;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $Reader = ::java::io::Reader;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Charset = ::java::nio::charset::Charset;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Vector = ::java::util::Vector;
using $JarEntry = ::java::util::jar::JarEntry;
using $JarFile = ::java::util::jar::JarFile;
using $ZipEntry = ::java::util::zip::ZipEntry;
using $ZipFile = ::java::util::zip::ZipFile;
using $UTF_8 = ::sun::nio::cs::UTF_8;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace jdk {
	namespace internal {
		namespace util {
			namespace jar {

$FieldInfo _JarIndex_FieldInfo_[] = {
	{"indexMap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/util/LinkedList<Ljava/lang/String;>;>;", $PRIVATE, $field(JarIndex, indexMap)},
	{"jarMap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/util/LinkedList<Ljava/lang/String;>;>;", $PRIVATE, $field(JarIndex, jarMap)},
	{"jarFiles", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(JarIndex, jarFiles)},
	{"INDEX_NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(JarIndex, INDEX_NAME)},
	{"metaInfFilenames", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JarIndex, metaInfFilenames)},
	{}
};

$MethodInfo _JarIndex_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(JarIndex, init$, void)},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(JarIndex, init$, void, $InputStream*), "java.io.IOException"},
	{"<init>", "([Ljava/lang/String;)V", nullptr, $PUBLIC, $method(JarIndex, init$, void, $StringArray*), "java.io.IOException"},
	{"add", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(JarIndex, add, void, $String*, $String*)},
	{"addMapping", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(JarIndex, addMapping, void, $String*, $String*)},
	{"addToList", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap;)V", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/HashMap<Ljava/lang/String;Ljava/util/LinkedList<Ljava/lang/String;>;>;)V", $PRIVATE, $method(JarIndex, addToList, void, $String*, $String*, $HashMap*)},
	{"get", "(Ljava/lang/String;)Ljava/util/LinkedList;", "(Ljava/lang/String;)Ljava/util/LinkedList<Ljava/lang/String;>;", $PUBLIC, $virtualMethod(JarIndex, get, $LinkedList*, $String*)},
	{"getJarFiles", "()[Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(JarIndex, getJarFiles, $StringArray*)},
	{"getJarIndex", "(Ljava/util/jar/JarFile;)Ljdk/internal/util/jar/JarIndex;", nullptr, $PUBLIC | $STATIC, $staticMethod(JarIndex, getJarIndex, JarIndex*, $JarFile*), "java.io.IOException"},
	{"merge", "(Ljdk/internal/util/jar/JarIndex;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(JarIndex, merge, void, JarIndex*, $String*)},
	{"parseJars", "([Ljava/lang/String;)V", nullptr, $PRIVATE, $method(JarIndex, parseJars, void, $StringArray*), "java.io.IOException"},
	{"read", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $virtualMethod(JarIndex, read, void, $InputStream*), "java.io.IOException"},
	{"write", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $virtualMethod(JarIndex, write, void, $OutputStream*), "java.io.IOException"},
	{}
};

$ClassInfo _JarIndex_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.util.jar.JarIndex",
	"java.lang.Object",
	nullptr,
	_JarIndex_FieldInfo_,
	_JarIndex_MethodInfo_
};

$Object* allocate$JarIndex($Class* clazz) {
	return $of($alloc(JarIndex));
}

$String* JarIndex::INDEX_NAME = nullptr;
bool JarIndex::metaInfFilenames = false;

void JarIndex::init$() {
	$set(this, indexMap, $new($HashMap));
	$set(this, jarMap, $new($HashMap));
}

void JarIndex::init$($InputStream* is) {
	JarIndex::init$();
	read(is);
}

void JarIndex::init$($StringArray* files) {
	JarIndex::init$();
	$set(this, jarFiles, files);
	parseJars(files);
}

JarIndex* JarIndex::getJarIndex($JarFile* jar) {
	$init(JarIndex);
	$useLocalCurrentObjectStackCache();
	$var(JarIndex, index, nullptr);
	$var($JarEntry, e, $nc(jar)->getJarEntry(JarIndex::INDEX_NAME));
	if (e != nullptr) {
		$assign(index, $new(JarIndex, $(jar->getInputStream(e))));
	}
	return index;
}

$StringArray* JarIndex::getJarFiles() {
	return this->jarFiles;
}

void JarIndex::addToList($String* key, $String* value, $HashMap* t) {
	$var($LinkedList, list, $cast($LinkedList, $nc(t)->get(key)));
	if (list == nullptr) {
		$assign(list, $new($LinkedList));
		list->add(value);
		t->put(key, list);
	} else if (!$nc(list)->contains(value)) {
		list->add(value);
	}
}

$LinkedList* JarIndex::get($String* fileName) {
	$useLocalCurrentObjectStackCache();
	$var($LinkedList, jarFiles, nullptr);
	if (($assign(jarFiles, $cast($LinkedList, $nc(this->indexMap)->get(fileName)))) == nullptr) {
		int32_t pos = 0;
		if ((pos = $nc(fileName)->lastIndexOf((int32_t)u'/')) != -1) {
			$assign(jarFiles, $cast($LinkedList, $nc(this->indexMap)->get($(fileName->substring(0, pos)))));
		}
	}
	return jarFiles;
}

void JarIndex::add($String* fileName, $String* jarName) {
	$var($String, packageName, nullptr);
	int32_t pos = 0;
	if ((pos = $nc(fileName)->lastIndexOf((int32_t)u'/')) != -1) {
		$assign(packageName, fileName->substring(0, pos));
	} else {
		$assign(packageName, fileName);
	}
	addMapping(packageName, jarName);
}

void JarIndex::addMapping($String* jarItem, $String* jarName) {
	addToList(jarItem, jarName, this->indexMap);
	addToList(jarName, jarItem, this->jarMap);
}

void JarIndex::parseJars($StringArray* files) {
	$useLocalCurrentObjectStackCache();
	if (files == nullptr) {
		return;
	}
	$var($String, currentJar, nullptr);
	for (int32_t i = 0; i < $nc(files)->length; ++i) {
		$assign(currentJar, files->get(i));
		$init($File);
		$var($ZipFile, zrf, $new($ZipFile, $($nc(currentJar)->replace(u'/', $File::separatorChar))));
		$var($Enumeration, entries, zrf->entries());
		while ($nc(entries)->hasMoreElements()) {
			$var($ZipEntry, entry, $cast($ZipEntry, entries->nextElement()));
			$var($String, fileName, $nc(entry)->getName());
			bool var$2 = $nc(fileName)->equals("META-INF/"_s);
			bool var$1 = var$2 || $nc(fileName)->equals(JarIndex::INDEX_NAME);
			$init($JarFile);
			bool var$0 = var$1 || $nc(fileName)->equals($JarFile::MANIFEST_NAME);
			if (var$0 || $nc(fileName)->startsWith("META-INF/versions/"_s)) {
				continue;
			}
			if (!JarIndex::metaInfFilenames || !$nc(fileName)->startsWith("META-INF/"_s)) {
				add(fileName, currentJar);
			} else if (!entry->isDirectory()) {
				addMapping(fileName, currentJar);
			}
		}
		zrf->close();
	}
}

void JarIndex::write($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$init($UTF_8);
	$var($BufferedWriter, bw, $new($BufferedWriter, $$new($OutputStreamWriter, out, static_cast<$Charset*>($UTF_8::INSTANCE))));
	bw->write("JarIndex-Version: 1.0\n\n"_s);
	if (this->jarFiles != nullptr) {
		for (int32_t i = 0; i < $nc(this->jarFiles)->length; ++i) {
			$var($String, jar, $nc(this->jarFiles)->get(i));
			bw->write($$str({jar, "\n"_s}));
			$var($LinkedList, jarlist, $cast($LinkedList, $nc(this->jarMap)->get(jar)));
			if (jarlist != nullptr) {
				$var($Iterator, listitr, jarlist->iterator());
				while ($nc(listitr)->hasNext()) {
					bw->write($$str({$cast($String, $(listitr->next())), "\n"_s}));
				}
			}
			bw->write("\n"_s);
		}
		bw->flush();
	}
}

void JarIndex::read($InputStream* is) {
	$useLocalCurrentObjectStackCache();
	$init($UTF_8);
	$var($BufferedReader, br, $new($BufferedReader, $$new($InputStreamReader, is, static_cast<$Charset*>($UTF_8::INSTANCE))));
	$var($String, line, nullptr);
	$var($String, currentJar, nullptr);
	$var($Vector, jars, $new($Vector));
	while (true) {
		bool var$0 = ($assign(line, br->readLine())) != nullptr;
		if (!(var$0 && !$nc(line)->endsWith(".jar"_s))) {
			break;
		}
		{
		}
	}
	for (; line != nullptr; $assign(line, br->readLine())) {
		if ($nc(line)->isEmpty()) {
			continue;
		}
		if ($nc(line)->endsWith(".jar"_s)) {
			$assign(currentJar, line);
			jars->add(currentJar);
		} else {
			$var($String, name, line);
			addMapping(name, currentJar);
		}
	}
	$set(this, jarFiles, $fcast($StringArray, jars->toArray($$new($StringArray, jars->size()))));
}

void JarIndex::merge(JarIndex* toIndex, $String* path) {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, itr, $nc($($nc(this->indexMap)->entrySet()))->iterator());
	while ($nc(itr)->hasNext()) {
		$var($Map$Entry, e, $cast($Map$Entry, itr->next()));
		$var($String, packageName, $cast($String, $nc(e)->getKey()));
		$var($LinkedList, from_list, $cast($LinkedList, e->getValue()));
		$var($Iterator, listItr, $nc(from_list)->iterator());
		while ($nc(listItr)->hasNext()) {
			$var($String, jarName, $cast($String, listItr->next()));
			if (path != nullptr) {
				$assign(jarName, path->concat(jarName));
			}
			$nc(toIndex)->addMapping(packageName, jarName);
		}
	}
}

void clinit$JarIndex($Class* class$) {
	$assignStatic(JarIndex::INDEX_NAME, "META-INF/INDEX.LIST"_s);
	JarIndex::metaInfFilenames = "true"_s->equals($($GetPropertyAction::privilegedGetProperty("sun.misc.JarIndex.metaInfFilenames"_s)));
}

JarIndex::JarIndex() {
}

$Class* JarIndex::load$($String* name, bool initialize) {
	$loadClass(JarIndex, name, initialize, &_JarIndex_ClassInfo_, clinit$JarIndex, allocate$JarIndex);
	return class$;
}

$Class* JarIndex::class$ = nullptr;

			} // jar
		} // util
	} // internal
} // jdk
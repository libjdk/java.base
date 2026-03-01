#include <sun/net/www/MimeTable.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/FileOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/SecurityManager.h>
#include <java/net/FileNameMap.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Enumeration.h>
#include <java/util/Hashtable.h>
#include <java/util/Properties.h>
#include <java/util/StringTokenizer.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/net/www/MimeEntry.h>
#include <sun/net/www/MimeTable$1.h>
#include <sun/net/www/MimeTable$DefaultInstanceHolder.h>
#include <jcpp.h>

#undef UNKNOWN

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $FileOutputStream = ::java::io::FileOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $FileNameMap = ::java::net::FileNameMap;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Enumeration = ::java::util::Enumeration;
using $Hashtable = ::java::util::Hashtable;
using $Properties = ::java::util::Properties;
using $StringTokenizer = ::java::util::StringTokenizer;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $MimeEntry = ::sun::net::www::MimeEntry;
using $MimeTable$1 = ::sun::net::www::MimeTable$1;
using $MimeTable$DefaultInstanceHolder = ::sun::net::www::MimeTable$DefaultInstanceHolder;

namespace sun {
	namespace net {
		namespace www {

$FieldInfo _MimeTable_FieldInfo_[] = {
	{"entries", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;Lsun/net/www/MimeEntry;>;", $PRIVATE, $field(MimeTable, entries)},
	{"extensionMap", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;Lsun/net/www/MimeEntry;>;", $PRIVATE, $field(MimeTable, extensionMap)},
	{"tempFileTemplate", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(MimeTable, tempFileTemplate)},
	{"filePreamble", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MimeTable, filePreamble)},
	{"fileMagic", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(MimeTable, fileMagic)},
	{"mailcapLocations", "[Ljava/lang/String;", nullptr, $PROTECTED | $STATIC, $staticField(MimeTable, mailcapLocations)},
	{}
};

$MethodInfo _MimeTable_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(MimeTable, init$, void)},
	{"add", "(Lsun/net/www/MimeEntry;)V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, add, void, $MimeEntry*)},
	{"elements", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Lsun/net/www/MimeEntry;>;", $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, elements, $Enumeration*)},
	{"fill", "(Lsun/net/www/MimeEntry;Ljava/lang/String;Ljava/lang/String;)V", nullptr, 0, $virtualMethod(MimeTable, fill, void, $MimeEntry*, $String*, $String*)},
	{"find", "(Ljava/lang/String;)Lsun/net/www/MimeEntry;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, find, $MimeEntry*, $String*)},
	{"findByDescription", "(Ljava/lang/String;)Lsun/net/www/MimeEntry;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, findByDescription, $MimeEntry*, $String*)},
	{"findByExt", "(Ljava/lang/String;)Lsun/net/www/MimeEntry;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, findByExt, $MimeEntry*, $String*)},
	{"findByFileName", "(Ljava/lang/String;)Lsun/net/www/MimeEntry;", nullptr, $PUBLIC, $virtualMethod(MimeTable, findByFileName, $MimeEntry*, $String*)},
	{"getActionCode", "(Ljava/lang/String;)I", nullptr, 0, $virtualMethod(MimeTable, getActionCode, int32_t, $String*)},
	{"getAsProperties", "()Ljava/util/Properties;", nullptr, $PUBLIC, $virtualMethod(MimeTable, getAsProperties, $Properties*)},
	{"getContentTypeFor", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, getContentTypeFor, $String*, $String*)},
	{"getDefaultTable", "()Lsun/net/www/MimeTable;", nullptr, $PUBLIC | $STATIC, $staticMethod(MimeTable, getDefaultTable, MimeTable*)},
	{"getExtensions", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, 0, $virtualMethod(MimeTable, getExtensions, $StringArray*, $String*)},
	{"getSize", "()I", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, getSize, int32_t)},
	{"getTempFileTemplate", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(MimeTable, getTempFileTemplate, $String*)},
	{"load", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, load, void)},
	{"loadTable", "()Ljava/net/FileNameMap;", nullptr, $PUBLIC | $STATIC, $staticMethod(MimeTable, loadTable, $FileNameMap*)},
	{"parse", "(Ljava/util/Properties;)V", nullptr, 0, $virtualMethod(MimeTable, parse, void, $Properties*)},
	{"parse", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, 0, $virtualMethod(MimeTable, parse, void, $String*, $String*)},
	{"parse", "(Ljava/lang/String;Lsun/net/www/MimeEntry;)V", nullptr, 0, $virtualMethod(MimeTable, parse, void, $String*, $MimeEntry*)},
	{"remove", "(Ljava/lang/String;)Lsun/net/www/MimeEntry;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, remove, $MimeEntry*, $String*)},
	{"remove", "(Lsun/net/www/MimeEntry;)Lsun/net/www/MimeEntry;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MimeTable, remove, $MimeEntry*, $MimeEntry*)},
	{"saveAsProperties", "(Ljava/io/File;)Z", nullptr, $PROTECTED, $virtualMethod(MimeTable, saveAsProperties, bool, $File*)},
	{}
};

$InnerClassInfo _MimeTable_InnerClassesInfo_[] = {
	{"sun.net.www.MimeTable$DefaultInstanceHolder", "sun.net.www.MimeTable", "DefaultInstanceHolder", $PRIVATE | $STATIC},
	{"sun.net.www.MimeTable$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MimeTable_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.MimeTable",
	"java.lang.Object",
	"java.net.FileNameMap",
	_MimeTable_FieldInfo_,
	_MimeTable_MethodInfo_,
	nullptr,
	nullptr,
	_MimeTable_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.net.www.MimeTable$DefaultInstanceHolder,sun.net.www.MimeTable$DefaultInstanceHolder$1,sun.net.www.MimeTable$1"
};

$Object* allocate$MimeTable($Class* clazz) {
	return $of($alloc(MimeTable));
}

$String* MimeTable::tempFileTemplate = nullptr;
$String* MimeTable::filePreamble = nullptr;
$String* MimeTable::fileMagic = nullptr;
$StringArray* MimeTable::mailcapLocations = nullptr;

void MimeTable::init$() {
	$set(this, entries, $new($Hashtable));
	$set(this, extensionMap, $new($Hashtable));
	load();
}

MimeTable* MimeTable::getDefaultTable() {
	$init(MimeTable);
	$init($MimeTable$DefaultInstanceHolder);
	return $MimeTable$DefaultInstanceHolder::defaultInstance;
}

$FileNameMap* MimeTable::loadTable() {
	$init(MimeTable);
	$var(MimeTable, mt, getDefaultTable());
	return static_cast<$FileNameMap*>(mt);
}

int32_t MimeTable::getSize() {
	$synchronized(this) {
		return $nc(this->entries)->size();
	}
}

$String* MimeTable::getContentTypeFor($String* fileName) {
	$synchronized(this) {
		$var($MimeEntry, entry, findByFileName(fileName));
		if (entry != nullptr) {
			return entry->getType();
		} else {
			return nullptr;
		}
	}
}

void MimeTable::add($MimeEntry* m) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$nc(this->entries)->put($($nc(m)->getType()), m);
		$var($StringArray, exts, $nc(m)->getExtensions());
		if (exts == nullptr) {
			return;
		}
		for (int32_t i = 0; i < $nc(exts)->length; ++i) {
			$nc(this->extensionMap)->put(exts->get(i), m);
		}
	}
}

$MimeEntry* MimeTable::remove($String* type) {
	$synchronized(this) {
		$var($MimeEntry, entry, $cast($MimeEntry, $nc(this->entries)->get(type)));
		return remove(entry);
	}
}

$MimeEntry* MimeTable::remove($MimeEntry* entry) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($StringArray, extensionKeys, $nc(entry)->getExtensions());
		if (extensionKeys != nullptr) {
			for (int32_t i = 0; i < extensionKeys->length; ++i) {
				$nc(this->extensionMap)->remove(extensionKeys->get(i));
			}
		}
		return $cast($MimeEntry, $nc(this->entries)->remove($(entry->getType())));
	}
}

$MimeEntry* MimeTable::find($String* type) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($MimeEntry, entry, $cast($MimeEntry, $nc(this->entries)->get(type)));
		if (entry == nullptr) {
			$var($Enumeration, e, $nc(this->entries)->elements());
			while ($nc(e)->hasMoreElements()) {
				$var($MimeEntry, wild, $cast($MimeEntry, e->nextElement()));
				if ($nc(wild)->matches(type)) {
					return wild;
				}
			}
		}
		return entry;
	}
}

$MimeEntry* MimeTable::findByFileName($String* fname$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, fname, fname$renamed);
	$var($String, ext, ""_s);
	int32_t i = $nc(fname)->lastIndexOf((int32_t)u'#');
	if (i > 0) {
		$assign(fname, fname->substring(0, i - 1));
	}
	i = fname->lastIndexOf((int32_t)u'.');
	i = $Math::max(i, fname->lastIndexOf((int32_t)u'/'));
	i = $Math::max(i, fname->lastIndexOf((int32_t)u'?'));
	if (i != -1 && fname->charAt(i) == u'.') {
		$assign(ext, $(fname->substring(i))->toLowerCase());
	}
	return findByExt(ext);
}

$MimeEntry* MimeTable::findByExt($String* fileExtension) {
	$synchronized(this) {
		return $cast($MimeEntry, $nc(this->extensionMap)->get(fileExtension));
	}
}

$MimeEntry* MimeTable::findByDescription($String* description) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Enumeration, e, elements());
		while ($nc(e)->hasMoreElements()) {
			$var($MimeEntry, entry, $cast($MimeEntry, e->nextElement()));
			if ($nc(description)->equals($($nc(entry)->getDescription()))) {
				return entry;
			}
		}
		return find(description);
	}
}

$String* MimeTable::getTempFileTemplate() {
	return MimeTable::tempFileTemplate;
}

$Enumeration* MimeTable::elements() {
	$synchronized(this) {
		return $nc(this->entries)->elements();
	}
}

void MimeTable::load() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		$var($Properties, entries, $new($Properties));
		$var($File, file, nullptr);
		$var($InputStream, in, nullptr);
		$var($String, userTablePath, $System::getProperty("content.types.user.table"_s));
		if (userTablePath != nullptr && $nc(($assign(file, $new($File, userTablePath))))->exists()) {
			try {
				$assign(in, $new($FileInputStream, file));
			} catch ($FileNotFoundException& e) {
				$nc($System::err)->println($$str({"Warning: "_s, $(file->getPath()), " mime table not found."_s}));
				return;
			}
		} else {
			$assign(in, MimeTable::class$->getResourceAsStream("content-types.properties"_s));
			if (in == nullptr) {
				$throwNew($InternalError, "default mime table not found"_s);
			}
		}
		try {
			$var($BufferedInputStream, bin, $new($BufferedInputStream, in));
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						entries->load(static_cast<$InputStream*>(bin));
					} catch ($Throwable& t$) {
						try {
							bin->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
						$throw(t$);
					}
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					bin->close();
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		} catch ($IOException& e) {
			$nc($System::err)->println($$str({"Warning: "_s, $(e->getMessage())}));
		}
		parse(entries);
	}
}

void MimeTable::parse($Properties* entries) {
	$useLocalCurrentObjectStackCache();
	$var($String, tempFileTemplate, $cast($String, $nc(entries)->get("temp.file.template"_s)));
	if (tempFileTemplate != nullptr) {
		entries->remove("temp.file.template"_s);
		$assignStatic(MimeTable::tempFileTemplate, tempFileTemplate);
	}
	$var($Enumeration, types, entries->propertyNames());
	while ($nc(types)->hasMoreElements()) {
		$var($String, type, $cast($String, types->nextElement()));
		$var($String, attrs, entries->getProperty(type));
		parse(type, attrs);
	}
}

void MimeTable::parse($String* type, $String* attrs) {
	$useLocalCurrentObjectStackCache();
	$var($MimeEntry, newEntry, $new($MimeEntry, type));
	$var($StringTokenizer, tokenizer, $new($StringTokenizer, attrs, ";"_s));
	while (tokenizer->hasMoreTokens()) {
		$var($String, pair, tokenizer->nextToken());
		parse(pair, newEntry);
	}
	add(newEntry);
}

void MimeTable::parse($String* pair, $MimeEntry* entry) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, nullptr);
	$var($String, value, nullptr);
	bool gotName = false;
	$var($StringTokenizer, tokenizer, $new($StringTokenizer, pair, "="_s));
	while (tokenizer->hasMoreTokens()) {
		if (gotName) {
			$assign(value, $nc($(tokenizer->nextToken()))->trim());
		} else {
			$assign(name, $nc($(tokenizer->nextToken()))->trim());
			gotName = true;
		}
	}
	fill(entry, name, value);
}

void MimeTable::fill($MimeEntry* entry, $String* name, $String* value) {
	if ("description"_s->equalsIgnoreCase(name)) {
		$nc(entry)->setDescription(value);
	} else if ("action"_s->equalsIgnoreCase(name)) {
		$nc(entry)->setAction(getActionCode(value));
	} else if ("application"_s->equalsIgnoreCase(name)) {
		$nc(entry)->setCommand(value);
	} else if ("icon"_s->equalsIgnoreCase(name)) {
		$nc(entry)->setImageFileName(value);
	} else if ("file_extensions"_s->equalsIgnoreCase(name)) {
		$nc(entry)->setExtensions(value);
	}
}

$StringArray* MimeTable::getExtensions($String* list) {
	$useLocalCurrentObjectStackCache();
	$var($StringTokenizer, tokenizer, $new($StringTokenizer, list, ","_s));
	int32_t n = tokenizer->countTokens();
	$var($StringArray, extensions, $new($StringArray, n));
	for (int32_t i = 0; i < n; ++i) {
		extensions->set(i, $(tokenizer->nextToken()));
	}
	return extensions;
}

int32_t MimeTable::getActionCode($String* action) {
	$init($MimeEntry);
	for (int32_t i = 0; i < $nc($MimeEntry::actionKeywords)->length; ++i) {
		if ($nc(action)->equalsIgnoreCase($nc($MimeEntry::actionKeywords)->get(i))) {
			return i;
		}
	}
	return $MimeEntry::UNKNOWN;
}

$Properties* MimeTable::getAsProperties() {
	$useLocalCurrentObjectStackCache();
	$var($Properties, properties, $new($Properties));
	$var($Enumeration, e, elements());
	while ($nc(e)->hasMoreElements()) {
		$var($MimeEntry, entry, $cast($MimeEntry, e->nextElement()));
		$var($Object, var$0, $of($nc(entry)->getType()));
		properties->put(var$0, $(entry->toProperty()));
	}
	return properties;
}

bool MimeTable::saveAsProperties($File* file) {
	$useLocalCurrentObjectStackCache();
	$var($FileOutputStream, os, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			try {
				$assign(os, $new($FileOutputStream, file));
				$var($Properties, properties, getAsProperties());
				$nc(properties)->put("temp.file.template"_s, MimeTable::tempFileTemplate);
				$var($String, tag, nullptr);
				$var($SecurityManager, sm, $System::getSecurityManager());
				if (sm != nullptr) {
					sm->checkPropertyAccess("user.name"_s);
				}
				$var($String, user, $StaticProperty::userName());
				if (user != nullptr) {
					$assign(tag, $str({"; customized for "_s, user}));
					properties->store(static_cast<$OutputStream*>(os), $$str({MimeTable::filePreamble, tag}));
				} else {
					properties->store(static_cast<$OutputStream*>(os), MimeTable::filePreamble);
				}
			} catch ($IOException& e) {
				e->printStackTrace();
				var$2 = false;
				return$1 = true;
				goto $finally;
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			if (os != nullptr) {
				try {
					os->close();
				} catch ($IOException& e) {
				}
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	return true;
}

void clinit$MimeTable($Class* class$) {
	$assignStatic(MimeTable::filePreamble, "sun.net.www MIME content-types table"_s);
	$assignStatic(MimeTable::fileMagic, $str({"#"_s, MimeTable::filePreamble}));
	$beforeCallerSensitive();
	{
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($MimeTable$1)));
	}
}

MimeTable::MimeTable() {
}

$Class* MimeTable::load$($String* name, bool initialize) {
	$loadClass(MimeTable, name, initialize, &_MimeTable_ClassInfo_, clinit$MimeTable, allocate$MimeTable);
	return class$;
}

$Class* MimeTable::class$ = nullptr;

		} // www
	} // net
} // sun
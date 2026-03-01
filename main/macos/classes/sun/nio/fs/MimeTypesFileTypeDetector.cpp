#include <sun/nio/fs/MimeTypesFileTypeDetector.h>

#include <java/lang/CharSequence.h>
#include <java/nio/file/Path.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <sun/nio/fs/AbstractFileTypeDetector.h>
#include <sun/nio/fs/MimeTypesFileTypeDetector$1.h>
#include <jcpp.h>

#undef EXTEQUAL
#undef TYPEEQUAL

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Path = ::java::nio::file::Path;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $AbstractFileTypeDetector = ::sun::nio::fs::AbstractFileTypeDetector;
using $MimeTypesFileTypeDetector$1 = ::sun::nio::fs::MimeTypesFileTypeDetector$1;

namespace sun {
	namespace nio {
		namespace fs {

$FieldInfo _MimeTypesFileTypeDetector_FieldInfo_[] = {
	{"mimeTypesFile", "Ljava/nio/file/Path;", nullptr, $PRIVATE | $FINAL, $field(MimeTypesFileTypeDetector, mimeTypesFile)},
	{"mimeTypeMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE, $field(MimeTypesFileTypeDetector, mimeTypeMap)},
	{"loaded", "Z", nullptr, $PRIVATE | $VOLATILE, $field(MimeTypesFileTypeDetector, loaded)},
	{}
};

$MethodInfo _MimeTypesFileTypeDetector_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/Path;)V", nullptr, $PUBLIC, $method(MimeTypesFileTypeDetector, init$, void, $Path*)},
	{"implProbeContentType", "(Ljava/nio/file/Path;)Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(MimeTypesFileTypeDetector, implProbeContentType, $String*, $Path*)},
	{"loadMimeTypes", "()V", nullptr, $PRIVATE, $method(MimeTypesFileTypeDetector, loadMimeTypes, void)},
	{"parseMimeEntry", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(MimeTypesFileTypeDetector, parseMimeEntry, void, $String*)},
	{"putIfAbsent", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(MimeTypesFileTypeDetector, putIfAbsent, void, $String*, $String*)},
	{}
};

$InnerClassInfo _MimeTypesFileTypeDetector_InnerClassesInfo_[] = {
	{"sun.nio.fs.MimeTypesFileTypeDetector$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _MimeTypesFileTypeDetector_ClassInfo_ = {
	$ACC_SUPER,
	"sun.nio.fs.MimeTypesFileTypeDetector",
	"sun.nio.fs.AbstractFileTypeDetector",
	nullptr,
	_MimeTypesFileTypeDetector_FieldInfo_,
	_MimeTypesFileTypeDetector_MethodInfo_,
	nullptr,
	nullptr,
	_MimeTypesFileTypeDetector_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.nio.fs.MimeTypesFileTypeDetector$1"
};

$Object* allocate$MimeTypesFileTypeDetector($Class* clazz) {
	return $of($alloc(MimeTypesFileTypeDetector));
}

void MimeTypesFileTypeDetector::init$($Path* filePath) {
	$AbstractFileTypeDetector::init$();
	$set(this, mimeTypesFile, filePath);
}

$String* MimeTypesFileTypeDetector::implProbeContentType($Path* path) {
	$useLocalCurrentObjectStackCache();
	$var($Path, fn, $nc(path)->getFileName());
	if (fn == nullptr) {
		return nullptr;
	}
	$var($String, ext, getExtension($($nc(fn)->toString())));
	if ($nc(ext)->isEmpty()) {
		return nullptr;
	}
	loadMimeTypes();
	if (this->mimeTypeMap == nullptr || $nc(this->mimeTypeMap)->isEmpty()) {
		return nullptr;
	}
	$var($String, mimeType, nullptr);
	do {
		$assign(mimeType, $cast($String, $nc(this->mimeTypeMap)->get(ext)));
		if (mimeType == nullptr) {
			$assign(ext, getExtension(ext));
		}
	} while (mimeType == nullptr && !$nc(ext)->isEmpty());
	return mimeType;
}

void MimeTypesFileTypeDetector::loadMimeTypes() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (!this->loaded) {
		$synchronized(this) {
			if (!this->loaded) {
				$var($List, lines, $cast($List, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($MimeTypesFileTypeDetector$1, this)))));
				$set(this, mimeTypeMap, $new($HashMap, $nc(lines)->size()));
				$var($String, entry, ""_s);
				{
					$var($Iterator, i$, $nc(lines)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($String, line, $cast($String, i$->next()));
						{
							$plusAssign(entry, line);
							if (entry->endsWith("\\"_s)) {
								$assign(entry, entry->substring(0, entry->length() - 1));
								continue;
							}
							parseMimeEntry(entry);
							$assign(entry, ""_s);
						}
					}
				}
				if (!entry->isEmpty()) {
					parseMimeEntry(entry);
				}
				this->loaded = true;
			}
		}
	}
}

void MimeTypesFileTypeDetector::parseMimeEntry($String* entry$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, entry, entry$renamed);
	$assign(entry, $nc(entry)->trim());
	bool var$0 = entry->isEmpty();
	if (var$0 || entry->charAt(0) == u'#') {
		return;
	}
	$assign(entry, entry->replaceAll("\\s*#.*"_s, ""_s));
	int32_t equalIdx = entry->indexOf((int32_t)u'=');
	if (equalIdx > 0) {
		$var($String, TYPEEQUAL, "type="_s);
		$var($String, typeRegex, $str({"\\b"_s, TYPEEQUAL, "(\"\\p{Graph}+?/\\p{Graph}+?\"|\\p{Graph}+/\\p{Graph}+\\b)"_s}));
		$var($Pattern, typePattern, $Pattern::compile(typeRegex));
		$var($Matcher, typeMatcher, $nc(typePattern)->matcher(entry));
		if ($nc(typeMatcher)->find()) {
			$var($String, type, $nc($(typeMatcher->group()))->substring(TYPEEQUAL->length()));
			if (type->charAt(0) == u'\"') {
				$assign(type, type->substring(1, type->length() - 1));
			}
			$var($String, EXTEQUAL, "exts="_s);
			$var($String, extRegex, $str({"\\b"_s, EXTEQUAL, "(\"[\\p{Graph}\\p{Blank}]+?\"|\\p{Graph}+\\b)"_s}));
			$var($Pattern, extPattern, $Pattern::compile(extRegex));
			$var($Matcher, extMatcher, $nc(extPattern)->matcher(entry));
			if ($nc(extMatcher)->find()) {
				$var($String, exts, $nc($(extMatcher->group()))->substring(EXTEQUAL->length()));
				if (exts->charAt(0) == u'\"') {
					$assign(exts, exts->substring(1, exts->length() - 1));
				}
				$var($StringArray, extList, exts->split("[\\p{Blank}\\p{Punct}]+"_s));
				{
					$var($StringArray, arr$, extList);
					int32_t len$ = arr$->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($String, ext, arr$->get(i$));
						{
							putIfAbsent(ext, type);
						}
					}
				}
			}
		}
	} else {
		$var($StringArray, elements, entry->split("\\s+"_s));
		int32_t i = 1;
		while (i < elements->length) {
			putIfAbsent(elements->get(i++), elements->get(0));
		}
	}
}

void MimeTypesFileTypeDetector::putIfAbsent($String* key, $String* value) {
	bool var$1 = key != nullptr && !key->isEmpty() && value != nullptr;
	bool var$0 = var$1 && !value->isEmpty();
	if (var$0 && !$nc(this->mimeTypeMap)->containsKey(key)) {
		$nc(this->mimeTypeMap)->put(key, value);
	}
}

MimeTypesFileTypeDetector::MimeTypesFileTypeDetector() {
}

$Class* MimeTypesFileTypeDetector::load$($String* name, bool initialize) {
	$loadClass(MimeTypesFileTypeDetector, name, initialize, &_MimeTypesFileTypeDetector_ClassInfo_, allocate$MimeTypesFileTypeDetector);
	return class$;
}

$Class* MimeTypesFileTypeDetector::class$ = nullptr;

		} // fs
	} // nio
} // sun
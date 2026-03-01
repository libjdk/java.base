#include <sun/net/www/protocol/file/FileURLConnection.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/File.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/net/FileNameMap.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/security/Permission.h>
#include <java/text/Collator.h>
#include <java/text/SimpleDateFormat.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Date.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/TimeZone.h>
#include <sun/net/ProgressMonitor.h>
#include <sun/net/ProgressSource.h>
#include <sun/net/www/MessageHeader.h>
#include <sun/net/www/MeteredStream.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/net/www/URLConnection.h>
#include <jcpp.h>

#undef CONTENT_LENGTH
#undef CONTENT_TYPE
#undef LAST_MODIFIED
#undef MAX_VALUE
#undef TEXT_PLAIN
#undef US

using $BufferedInputStream = ::java::io::BufferedInputStream;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $File = ::java::io::File;
using $FileInputStream = ::java::io::FileInputStream;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $FileNameMap = ::java::net::FileNameMap;
using $URL = ::java::net::URL;
using $1URLConnection = ::java::net::URLConnection;
using $Permission = ::java::security::Permission;
using $Collator = ::java::text::Collator;
using $SimpleDateFormat = ::java::text::SimpleDateFormat;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $Date = ::java::util::Date;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $TimeZone = ::java::util::TimeZone;
using $ProgressMonitor = ::sun::net::ProgressMonitor;
using $ProgressSource = ::sun::net::ProgressSource;
using $MessageHeader = ::sun::net::www::MessageHeader;
using $MeteredStream = ::sun::net::www::MeteredStream;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $URLConnection = ::sun::net::www::URLConnection;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace file {

$FieldInfo _FileURLConnection_FieldInfo_[] = {
	{"CONTENT_LENGTH", "Ljava/lang/String;", nullptr, $STATIC, $staticField(FileURLConnection, CONTENT_LENGTH)},
	{"CONTENT_TYPE", "Ljava/lang/String;", nullptr, $STATIC, $staticField(FileURLConnection, CONTENT_TYPE)},
	{"TEXT_PLAIN", "Ljava/lang/String;", nullptr, $STATIC, $staticField(FileURLConnection, TEXT_PLAIN)},
	{"LAST_MODIFIED", "Ljava/lang/String;", nullptr, $STATIC, $staticField(FileURLConnection, LAST_MODIFIED)},
	{"contentType", "Ljava/lang/String;", nullptr, 0, $field(FileURLConnection, contentType)},
	{"is", "Ljava/io/InputStream;", nullptr, 0, $field(FileURLConnection, is)},
	{"file", "Ljava/io/File;", nullptr, 0, $field(FileURLConnection, file)},
	{"filename", "Ljava/lang/String;", nullptr, 0, $field(FileURLConnection, filename)},
	{"isDirectory", "Z", nullptr, 0, $field(FileURLConnection, isDirectory)},
	{"exists", "Z", nullptr, 0, $field(FileURLConnection, exists)},
	{"files", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", 0, $field(FileURLConnection, files)},
	{"length", "J", nullptr, 0, $field(FileURLConnection, length)},
	{"lastModified", "J", nullptr, 0, $field(FileURLConnection, lastModified)},
	{"initializedHeaders", "Z", nullptr, $PRIVATE, $field(FileURLConnection, initializedHeaders)},
	{"permission", "Ljava/security/Permission;", nullptr, 0, $field(FileURLConnection, permission)},
	{}
};

$MethodInfo _FileURLConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URL;Ljava/io/File;)V", nullptr, $PROTECTED, $method(FileURLConnection, init$, void, $URL*, $File*)},
	{"connect", "()V", nullptr, $PUBLIC, $virtualMethod(FileURLConnection, connect, void), "java.io.IOException"},
	{"getContentLength", "()I", nullptr, $PUBLIC, $virtualMethod(FileURLConnection, getContentLength, int32_t)},
	{"getContentLengthLong", "()J", nullptr, $PUBLIC, $virtualMethod(FileURLConnection, getContentLengthLong, int64_t)},
	{"getHeaderField", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FileURLConnection, getHeaderField, $String*, $String*)},
	{"getHeaderField", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FileURLConnection, getHeaderField, $String*, int32_t)},
	{"getHeaderFieldKey", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FileURLConnection, getHeaderFieldKey, $String*, int32_t)},
	{"getHeaderFields", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PUBLIC, $virtualMethod(FileURLConnection, getHeaderFields, $Map*)},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(FileURLConnection, getInputStream, $InputStream*), "java.io.IOException"},
	{"getLastModified", "()J", nullptr, $PUBLIC, $virtualMethod(FileURLConnection, getLastModified, int64_t)},
	{"getPermission", "()Ljava/security/Permission;", nullptr, $PUBLIC, $virtualMethod(FileURLConnection, getPermission, $Permission*), "java.io.IOException"},
	{"getProperties", "()Lsun/net/www/MessageHeader;", nullptr, $PUBLIC, $virtualMethod(FileURLConnection, getProperties, $MessageHeader*)},
	{"initializeHeaders", "()V", nullptr, $PRIVATE, $method(FileURLConnection, initializeHeaders, void)},
	{}
};

$ClassInfo _FileURLConnection_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.file.FileURLConnection",
	"sun.net.www.URLConnection",
	nullptr,
	_FileURLConnection_FieldInfo_,
	_FileURLConnection_MethodInfo_
};

$Object* allocate$FileURLConnection($Class* clazz) {
	return $of($alloc(FileURLConnection));
}

$String* FileURLConnection::CONTENT_LENGTH = nullptr;
$String* FileURLConnection::CONTENT_TYPE = nullptr;
$String* FileURLConnection::TEXT_PLAIN = nullptr;
$String* FileURLConnection::LAST_MODIFIED = nullptr;

void FileURLConnection::init$($URL* u, $File* file) {
	$URLConnection::init$(u);
	this->isDirectory = false;
	this->exists = false;
	this->length = -1;
	this->lastModified = 0;
	this->initializedHeaders = false;
	$set(this, file, file);
}

void FileURLConnection::connect() {
	$useLocalCurrentObjectStackCache();
	if (!this->connected) {
		try {
			$set(this, filename, $nc(this->file)->toString());
			this->isDirectory = $nc(this->file)->isDirectory();
			if (this->isDirectory) {
				$var($StringArray, fileList, $nc(this->file)->list());
				if (fileList == nullptr) {
					$throwNew($FileNotFoundException, $$str({this->filename, " exists, but is not accessible"_s}));
				}
				$set(this, files, $Arrays::asList(fileList));
			} else {
				$set(this, is, $new($BufferedInputStream, $$new($FileInputStream, this->filename)));
				bool meteredInput = $nc($($ProgressMonitor::getDefault()))->shouldMeterInput(this->url, "GET"_s);
				if (meteredInput) {
					$var($ProgressSource, pi, $new($ProgressSource, this->url, "GET"_s, $nc(this->file)->length()));
					$set(this, is, $new($MeteredStream, this->is, pi, $nc(this->file)->length()));
				}
			}
		} catch ($IOException& e) {
			$throw(e);
		}
		this->connected = true;
	}
}

void FileURLConnection::initializeHeaders() {
	$useLocalCurrentObjectStackCache();
	try {
		connect();
		this->exists = $nc(this->file)->exists();
	} catch ($IOException& e) {
	}
	if (!this->initializedHeaders || !this->exists) {
		this->length = $nc(this->file)->length();
		this->lastModified = $nc(this->file)->lastModified();
		if (!this->isDirectory) {
			$var($FileNameMap, map, $1URLConnection::getFileNameMap());
			$set(this, contentType, $nc(map)->getContentTypeFor(this->filename));
			if (this->contentType != nullptr) {
				$nc(this->properties)->add(FileURLConnection::CONTENT_TYPE, this->contentType);
			}
			$nc(this->properties)->add(FileURLConnection::CONTENT_LENGTH, $($String::valueOf(this->length)));
			if (this->lastModified != 0) {
				$var($Date, date, $new($Date, this->lastModified));
				$init($Locale);
				$var($SimpleDateFormat, fo, $new($SimpleDateFormat, "EEE, dd MMM yyyy HH:mm:ss \'GMT\'"_s, $Locale::US));
				fo->setTimeZone($($TimeZone::getTimeZone("GMT"_s)));
				$nc(this->properties)->add(FileURLConnection::LAST_MODIFIED, $(fo->format(date)));
			}
		} else {
			$nc(this->properties)->add(FileURLConnection::CONTENT_TYPE, FileURLConnection::TEXT_PLAIN);
		}
		this->initializedHeaders = true;
	}
}

$Map* FileURLConnection::getHeaderFields() {
	initializeHeaders();
	return $URLConnection::getHeaderFields();
}

$String* FileURLConnection::getHeaderField($String* name) {
	initializeHeaders();
	return $URLConnection::getHeaderField(name);
}

$String* FileURLConnection::getHeaderField(int32_t n) {
	initializeHeaders();
	return $URLConnection::getHeaderField(n);
}

int32_t FileURLConnection::getContentLength() {
	initializeHeaders();
	if (this->length > $Integer::MAX_VALUE) {
		return -1;
	}
	return (int32_t)this->length;
}

int64_t FileURLConnection::getContentLengthLong() {
	initializeHeaders();
	return this->length;
}

$String* FileURLConnection::getHeaderFieldKey(int32_t n) {
	initializeHeaders();
	return $URLConnection::getHeaderFieldKey(n);
}

$MessageHeader* FileURLConnection::getProperties() {
	initializeHeaders();
	return $URLConnection::getProperties();
}

int64_t FileURLConnection::getLastModified() {
	initializeHeaders();
	return this->lastModified;
}

$InputStream* FileURLConnection::getInputStream() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		int32_t iconHeight = 0;
		int32_t iconWidth = 0;
		connect();
		if (this->is == nullptr) {
			if (this->isDirectory) {
				$var($FileNameMap, map, $1URLConnection::getFileNameMap());
				$var($StringBuilder, sb, $new($StringBuilder));
				if (this->files == nullptr) {
					$throwNew($FileNotFoundException, this->filename);
				}
				$Collections::sort(this->files, $($Collator::getInstance()));
				for (int32_t i = 0; i < $nc(this->files)->size(); ++i) {
					$var($String, fileName, $cast($String, $nc(this->files)->get(i)));
					sb->append(fileName);
					sb->append("\n"_s);
				}
				$set(this, is, $new($ByteArrayInputStream, $($nc($(sb->toString()))->getBytes())));
			} else {
				$throwNew($FileNotFoundException, this->filename);
			}
		}
		return this->is;
	}
}

$Permission* FileURLConnection::getPermission() {
	$useLocalCurrentObjectStackCache();
	if (this->permission == nullptr) {
		$var($String, decodedPath, $ParseUtil::decode($($nc(this->url)->getPath())));
		$init($File);
		if ($File::separatorChar == u'/') {
			$set(this, permission, $new($FilePermission, decodedPath, "read"_s));
		} else {
			bool var$1 = $nc(decodedPath)->length() > 2;
			bool var$0 = var$1 && decodedPath->charAt(0) == u'/';
			if (var$0 && decodedPath->charAt(2) == u':') {
				$assign(decodedPath, decodedPath->substring(1));
			}
			$set(this, permission, $new($FilePermission, $($nc(decodedPath)->replace(u'/', $File::separatorChar)), "read"_s));
		}
	}
	return this->permission;
}

void clinit$FileURLConnection($Class* class$) {
	$assignStatic(FileURLConnection::CONTENT_LENGTH, "content-length"_s);
	$assignStatic(FileURLConnection::CONTENT_TYPE, "content-type"_s);
	$assignStatic(FileURLConnection::TEXT_PLAIN, "text/plain"_s);
	$assignStatic(FileURLConnection::LAST_MODIFIED, "last-modified"_s);
}

FileURLConnection::FileURLConnection() {
}

$Class* FileURLConnection::load$($String* name, bool initialize) {
	$loadClass(FileURLConnection, name, initialize, &_FileURLConnection_ClassInfo_, clinit$FileURLConnection, allocate$FileURLConnection);
	return class$;
}

$Class* FileURLConnection::class$ = nullptr;

				} // file
			} // protocol
		} // www
	} // net
} // sun
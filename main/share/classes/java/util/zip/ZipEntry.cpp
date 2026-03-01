#include <java/util/zip/ZipEntry.h>

#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/nio/file/attribute/FileTime.h>
#include <java/time/Instant.h>
#include <java/time/LocalDateTime.h>
#include <java/time/ZoneId.h>
#include <java/time/ZonedDateTime.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/TimeUnit.h>
#include <java/util/zip/ZipConstants.h>
#include <java/util/zip/ZipUtils.h>
#include <jcpp.h>

#undef DEFLATED
#undef MILLISECONDS
#undef STORED
#undef UPPER_DOSTIME_BOUND

using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $FileTime = ::java::nio::file::attribute::FileTime;
using $Instant = ::java::time::Instant;
using $LocalDateTime = ::java::time::LocalDateTime;
using $ZoneId = ::java::time::ZoneId;
using $ZonedDateTime = ::java::time::ZonedDateTime;
using $Objects = ::java::util::Objects;
using $TimeUnit = ::java::util::concurrent::TimeUnit;
using $ZipConstants = ::java::util::zip::ZipConstants;
using $ZipUtils = ::java::util::zip::ZipUtils;

namespace java {
	namespace util {
		namespace zip {

$FieldInfo _ZipEntry_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, 0, $field(ZipEntry, name)},
	{"xdostime", "J", nullptr, 0, $field(ZipEntry, xdostime)},
	{"mtime", "Ljava/nio/file/attribute/FileTime;", nullptr, 0, $field(ZipEntry, mtime)},
	{"atime", "Ljava/nio/file/attribute/FileTime;", nullptr, 0, $field(ZipEntry, atime)},
	{"ctime", "Ljava/nio/file/attribute/FileTime;", nullptr, 0, $field(ZipEntry, ctime)},
	{"crc", "J", nullptr, 0, $field(ZipEntry, crc)},
	{"size", "J", nullptr, 0, $field(ZipEntry, size)},
	{"csize", "J", nullptr, 0, $field(ZipEntry, csize)},
	{"csizeSet", "Z", nullptr, 0, $field(ZipEntry, csizeSet)},
	{"method", "I", nullptr, 0, $field(ZipEntry, method)},
	{"flag", "I", nullptr, 0, $field(ZipEntry, flag)},
	{"extra", "[B", nullptr, 0, $field(ZipEntry, extra)},
	{"comment", "Ljava/lang/String;", nullptr, 0, $field(ZipEntry, comment)},
	{"extraAttributes", "I", nullptr, 0, $field(ZipEntry, extraAttributes)},
	{"STORED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ZipEntry, STORED)},
	{"DEFLATED", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ZipEntry, DEFLATED)},
	{"DOSTIME_BEFORE_1980", "J", nullptr, $STATIC | $FINAL, $constField(ZipEntry, DOSTIME_BEFORE_1980)},
	{"UPPER_DOSTIME_BOUND", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ZipEntry, UPPER_DOSTIME_BOUND)},
	{}
};

$MethodInfo _ZipEntry_MethodInfo_[] = {
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(ZipEntry, init$, void, $String*)},
	{"<init>", "(Ljava/util/zip/ZipEntry;)V", nullptr, $PUBLIC, $method(ZipEntry, init$, void, ZipEntry*)},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, clone, $Object*)},
	{"getComment", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getComment, $String*)},
	{"getCompressedSize", "()J", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getCompressedSize, int64_t)},
	{"getCrc", "()J", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getCrc, int64_t)},
	{"getCreationTime", "()Ljava/nio/file/attribute/FileTime;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getCreationTime, $FileTime*)},
	{"getExtra", "()[B", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getExtra, $bytes*)},
	{"getLastAccessTime", "()Ljava/nio/file/attribute/FileTime;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getLastAccessTime, $FileTime*)},
	{"getLastModifiedTime", "()Ljava/nio/file/attribute/FileTime;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getLastModifiedTime, $FileTime*)},
	{"getMethod", "()I", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getMethod, int32_t)},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getName, $String*)},
	{"getSize", "()J", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getSize, int64_t)},
	{"getTime", "()J", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getTime, int64_t)},
	{"getTimeLocal", "()Ljava/time/LocalDateTime;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, getTimeLocal, $LocalDateTime*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ZipEntry, hashCode, int32_t)},
	{"isDirectory", "()Z", nullptr, $PUBLIC, $virtualMethod(ZipEntry, isDirectory, bool)},
	{"setComment", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setComment, void, $String*)},
	{"setCompressedSize", "(J)V", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setCompressedSize, void, int64_t)},
	{"setCrc", "(J)V", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setCrc, void, int64_t)},
	{"setCreationTime", "(Ljava/nio/file/attribute/FileTime;)Ljava/util/zip/ZipEntry;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setCreationTime, ZipEntry*, $FileTime*)},
	{"setExtra", "([B)V", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setExtra, void, $bytes*)},
	{"setExtra0", "([BZZ)V", nullptr, 0, $virtualMethod(ZipEntry, setExtra0, void, $bytes*, bool, bool)},
	{"setLastAccessTime", "(Ljava/nio/file/attribute/FileTime;)Ljava/util/zip/ZipEntry;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setLastAccessTime, ZipEntry*, $FileTime*)},
	{"setLastModifiedTime", "(Ljava/nio/file/attribute/FileTime;)Ljava/util/zip/ZipEntry;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setLastModifiedTime, ZipEntry*, $FileTime*)},
	{"setMethod", "(I)V", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setMethod, void, int32_t)},
	{"setSize", "(J)V", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setSize, void, int64_t)},
	{"setTime", "(J)V", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setTime, void, int64_t)},
	{"setTimeLocal", "(Ljava/time/LocalDateTime;)V", nullptr, $PUBLIC, $virtualMethod(ZipEntry, setTimeLocal, void, $LocalDateTime*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ZipEntry, toString, $String*)},
	{}
};

$ClassInfo _ZipEntry_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.zip.ZipEntry",
	"java.lang.Object",
	"java.util.zip.ZipConstants,java.lang.Cloneable",
	_ZipEntry_FieldInfo_,
	_ZipEntry_MethodInfo_
};

$Object* allocate$ZipEntry($Class* clazz) {
	return $of($alloc(ZipEntry));
}

bool ZipEntry::equals(Object$* obj) {
	 return this->$ZipConstants::equals(obj);
}

void ZipEntry::finalize() {
	this->$ZipConstants::finalize();
}

void ZipEntry::init$($String* name) {
	this->xdostime = -1;
	this->crc = -1;
	this->size = -1;
	this->csize = -1;
	this->csizeSet = false;
	this->method = -1;
	this->flag = 0;
	this->extraAttributes = -1;
	$Objects::requireNonNull($of(name), "name"_s);
	if ($nc(name)->length() > 0x0000FFFF) {
		$throwNew($IllegalArgumentException, "entry name too long"_s);
	}
	$set(this, name, name);
}

void ZipEntry::init$(ZipEntry* e) {
	this->xdostime = -1;
	this->crc = -1;
	this->size = -1;
	this->csize = -1;
	this->csizeSet = false;
	this->method = -1;
	this->flag = 0;
	this->extraAttributes = -1;
	$Objects::requireNonNull($of(e), "entry"_s);
	$set(this, name, $nc(e)->name);
	this->xdostime = e->xdostime;
	$set(this, mtime, e->mtime);
	$set(this, atime, e->atime);
	$set(this, ctime, e->ctime);
	this->crc = e->crc;
	this->size = e->size;
	this->csize = e->csize;
	this->csizeSet = e->csizeSet;
	this->method = e->method;
	this->flag = e->flag;
	$set(this, extra, e->extra);
	$set(this, comment, e->comment);
	this->extraAttributes = e->extraAttributes;
}

$String* ZipEntry::getName() {
	return this->name;
}

void ZipEntry::setTime(int64_t time) {
	this->xdostime = $ZipUtils::javaToExtendedDosTime(time);
	if (this->xdostime != ZipEntry::DOSTIME_BEFORE_1980 && time <= ZipEntry::UPPER_DOSTIME_BOUND) {
		$set(this, mtime, nullptr);
	} else {
		int32_t localYear = $nc($($ZipUtils::javaEpochToLocalDateTime(time)))->getYear();
		if (localYear >= 1980 && localYear <= 2099) {
			$set(this, mtime, nullptr);
		} else {
			$init($TimeUnit);
			$set(this, mtime, $FileTime::from(time, $TimeUnit::MILLISECONDS));
		}
	}
}

int64_t ZipEntry::getTime() {
	if (this->mtime != nullptr) {
		return $nc(this->mtime)->toMillis();
	}
	return (this->xdostime != -1) ? $ZipUtils::extendedDosToJavaTime(this->xdostime) : (int64_t)-1;
}

void ZipEntry::setTimeLocal($LocalDateTime* time) {
	$useLocalCurrentObjectStackCache();
	int32_t year = $nc(time)->getYear() - 1980;
	if (year < 0) {
		this->xdostime = ZipEntry::DOSTIME_BEFORE_1980;
	} else {
		int32_t var$4 = (year << 25) | (time->getMonthValue() << 21);
		int32_t var$3 = var$4 | (time->getDayOfMonth() << 16);
		int32_t var$2 = var$3 | (time->getHour() << 11);
		int32_t var$1 = var$2 | (time->getMinute() << 5);
		int64_t var$0 = ((int64_t)((var$1 | (time->getSecond() >> 1)) & (uint64_t)(int64_t)0x00000000FFFFFFFF));
		int32_t var$6 = (((int32_t)(time->getSecond() & (uint32_t)1)) * 1000);
		int64_t var$5 = ((int64_t)(var$6 + time->getNano() / 0x000F4240) << 32);
		this->xdostime = var$0 + var$5;
	}
	if (this->xdostime != ZipEntry::DOSTIME_BEFORE_1980 && year <= 127) {
		$set(this, mtime, nullptr);
	} else {
		$set(this, mtime, $FileTime::from($($nc($($ZonedDateTime::of(time, $($ZoneId::systemDefault()))))->toInstant())));
	}
}

$LocalDateTime* ZipEntry::getTimeLocal() {
	$useLocalCurrentObjectStackCache();
	if (this->mtime != nullptr) {
		$var($Instant, var$0, $nc(this->mtime)->toInstant());
		return $LocalDateTime::ofInstant(var$0, $($ZoneId::systemDefault()));
	}
	int32_t ms = (int32_t)(this->xdostime >> 32);
	return $LocalDateTime::of((int32_t)(((int64_t)((this->xdostime >> 25) & (uint64_t)(int64_t)127)) + 1980), (int32_t)((int64_t)((this->xdostime >> 21) & (uint64_t)(int64_t)15)), (int32_t)((int64_t)((this->xdostime >> 16) & (uint64_t)(int64_t)31)), (int32_t)((int64_t)((this->xdostime >> 11) & (uint64_t)(int64_t)31)), (int32_t)((int64_t)((this->xdostime >> 5) & (uint64_t)(int64_t)63)), (int32_t)((int64_t)((this->xdostime << 1) & (uint64_t)(int64_t)62)) + ms / 1000, (ms % 1000) * 0x000F4240);
}

ZipEntry* ZipEntry::setLastModifiedTime($FileTime* time) {
	$set(this, mtime, $cast($FileTime, $Objects::requireNonNull($of(time), "lastModifiedTime"_s)));
	$init($TimeUnit);
	this->xdostime = $ZipUtils::javaToExtendedDosTime($nc(time)->to($TimeUnit::MILLISECONDS));
	return this;
}

$FileTime* ZipEntry::getLastModifiedTime() {
	if (this->mtime != nullptr) {
		return this->mtime;
	}
	if (this->xdostime == -1) {
		return nullptr;
	}
	$init($TimeUnit);
	return $FileTime::from(getTime(), $TimeUnit::MILLISECONDS);
}

ZipEntry* ZipEntry::setLastAccessTime($FileTime* time) {
	$set(this, atime, $cast($FileTime, $Objects::requireNonNull($of(time), "lastAccessTime"_s)));
	return this;
}

$FileTime* ZipEntry::getLastAccessTime() {
	return this->atime;
}

ZipEntry* ZipEntry::setCreationTime($FileTime* time) {
	$set(this, ctime, $cast($FileTime, $Objects::requireNonNull($of(time), "creationTime"_s)));
	return this;
}

$FileTime* ZipEntry::getCreationTime() {
	return this->ctime;
}

void ZipEntry::setSize(int64_t size) {
	if (size < 0) {
		$throwNew($IllegalArgumentException, "invalid entry size"_s);
	}
	this->size = size;
}

int64_t ZipEntry::getSize() {
	return this->size;
}

int64_t ZipEntry::getCompressedSize() {
	return this->csize;
}

void ZipEntry::setCompressedSize(int64_t csize) {
	this->csize = csize;
	this->csizeSet = true;
}

void ZipEntry::setCrc(int64_t crc) {
	if (crc < 0 || crc > (int64_t)0x00000000FFFFFFFF) {
		$throwNew($IllegalArgumentException, "invalid entry crc-32"_s);
	}
	this->crc = crc;
}

int64_t ZipEntry::getCrc() {
	return this->crc;
}

void ZipEntry::setMethod(int32_t method) {
	if (method != ZipEntry::STORED && method != ZipEntry::DEFLATED) {
		$throwNew($IllegalArgumentException, "invalid compression method"_s);
	}
	this->method = method;
}

int32_t ZipEntry::getMethod() {
	return this->method;
}

void ZipEntry::setExtra($bytes* extra) {
	setExtra0(extra, false, true);
}

void ZipEntry::setExtra0($bytes* extra, bool doZIP64, bool isLOC) {
	if (extra != nullptr) {
		if (extra->length > 0x0000FFFF) {
			$throwNew($IllegalArgumentException, "invalid extra field length"_s);
		}
		int32_t off = 0;
		int32_t len = extra->length;
		while (off + 4 < len) {
			int32_t tag = $ZipUtils::get16(extra, off);
			int32_t sz = $ZipUtils::get16(extra, off + 2);
			off += 4;
			if (off + sz > len) {
				break;
			}
			{
				int32_t pos = 0;
				int64_t wtime = 0;
				int32_t flag = 0;
				int32_t sz0 = 0;
				switch (tag) {
				case 1:
					{
						if (doZIP64) {
							if (isLOC) {
								if (sz >= 16) {
									this->size = $ZipUtils::get64(extra, off);
									this->csize = $ZipUtils::get64(extra, off + 8);
								}
							} else {
								if (this->size == (int64_t)0x00000000FFFFFFFF) {
									if (off + 8 > len) {
										break;
									}
									this->size = $ZipUtils::get64(extra, off);
								}
								if (this->csize == (int64_t)0x00000000FFFFFFFF) {
									if (off + 16 > len) {
										break;
									}
									this->csize = $ZipUtils::get64(extra, off + 8);
								}
							}
						}
						break;
					}
				case 10:
					{
						if (sz < 32) {
							break;
						}
						pos = off + 4;
						bool var$0 = $ZipUtils::get16(extra, pos) != 1;
						if (var$0 || $ZipUtils::get16(extra, pos + 2) != 24) {
							break;
						}
						wtime = $ZipUtils::get64(extra, pos + 4);
						if (wtime != (int64_t)0x8000000000000000) {
							$set(this, mtime, $ZipUtils::winTimeToFileTime(wtime));
						}
						wtime = $ZipUtils::get64(extra, pos + 12);
						if (wtime != (int64_t)0x8000000000000000) {
							$set(this, atime, $ZipUtils::winTimeToFileTime(wtime));
						}
						wtime = $ZipUtils::get64(extra, pos + 20);
						if (wtime != (int64_t)0x8000000000000000) {
							$set(this, ctime, $ZipUtils::winTimeToFileTime(wtime));
						}
						break;
					}
				case 21589:
					{
						flag = $Byte::toUnsignedInt(extra->get(off));
						sz0 = 1;
						if (((int32_t)(flag & (uint32_t)1)) != 0 && (sz0 + 4) <= sz) {
							$set(this, mtime, $ZipUtils::unixTimeToFileTime($ZipUtils::get32S(extra, off + sz0)));
							sz0 += 4;
						}
						if (((int32_t)(flag & (uint32_t)2)) != 0 && (sz0 + 4) <= sz) {
							$set(this, atime, $ZipUtils::unixTimeToFileTime($ZipUtils::get32S(extra, off + sz0)));
							sz0 += 4;
						}
						if (((int32_t)(flag & (uint32_t)4)) != 0 && (sz0 + 4) <= sz) {
							$set(this, ctime, $ZipUtils::unixTimeToFileTime($ZipUtils::get32S(extra, off + sz0)));
							sz0 += 4;
						}
						break;
					}
				default:
					{}
				}
			}
			off += sz;
		}
	}
	$set(this, extra, extra);
}

$bytes* ZipEntry::getExtra() {
	return this->extra;
}

void ZipEntry::setComment($String* comment) {
	$set(this, comment, comment);
}

$String* ZipEntry::getComment() {
	return this->comment;
}

bool ZipEntry::isDirectory() {
	return $nc(this->name)->endsWith("/"_s);
}

$String* ZipEntry::toString() {
	return getName();
}

int32_t ZipEntry::hashCode() {
	return $nc(this->name)->hashCode();
}

$Object* ZipEntry::clone() {
	try {
		$var(ZipEntry, e, $cast(ZipEntry, $ZipConstants::clone()));
		$set($nc(e), extra, (this->extra == nullptr) ? ($bytes*)nullptr : $cast($bytes, $nc(this->extra)->clone()));
		return $of(e);
	} catch ($CloneNotSupportedException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

ZipEntry::ZipEntry() {
}

$Class* ZipEntry::load$($String* name, bool initialize) {
	$loadClass(ZipEntry, name, initialize, &_ZipEntry_ClassInfo_, allocate$ZipEntry);
	return class$;
}

$Class* ZipEntry::class$ = nullptr;

		} // zip
	} // util
} // java
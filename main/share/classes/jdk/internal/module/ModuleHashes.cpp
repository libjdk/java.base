#include <jdk/internal/module/ModuleHashes.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/lang/module/ModuleReader.h>
#include <java/lang/module/ModuleReference.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/util/AbstractMap.h>
#include <java/util/Arrays.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/TreeMap.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef UTF_8

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleReader = ::java::lang::module::ModuleReader;
using $ModuleReference = ::java::lang::module::ModuleReference;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $AbstractMap = ::java::util::AbstractMap;
using $Arrays = ::java::util::Arrays;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $TreeMap = ::java::util::TreeMap;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $Stream = ::java::util::stream::Stream;

namespace jdk {
	namespace internal {
		namespace module {

class ModuleHashes$$Lambda$lambda$computeHash$0 : public $Consumer {
	$class(ModuleHashes$$Lambda$lambda$computeHash$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$($MessageDigest* md, $ModuleReader* reader, $bytes* buf) {
		$set(this, md, md);
		$set(this, reader, reader);
		$set(this, buf, buf);
	}
	virtual void accept(Object$* rn) override {
		ModuleHashes::lambda$computeHash$0(md, reader, buf, $cast($String, rn));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleHashes$$Lambda$lambda$computeHash$0>());
	}
	$MessageDigest* md = nullptr;
	$ModuleReader* reader = nullptr;
	$bytes* buf = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleHashes$$Lambda$lambda$computeHash$0::fieldInfos[4] = {
	{"md", "Ljava/security/MessageDigest;", nullptr, $PUBLIC, $field(ModuleHashes$$Lambda$lambda$computeHash$0, md)},
	{"reader", "Ljava/lang/module/ModuleReader;", nullptr, $PUBLIC, $field(ModuleHashes$$Lambda$lambda$computeHash$0, reader)},
	{"buf", "[B", nullptr, $PUBLIC, $field(ModuleHashes$$Lambda$lambda$computeHash$0, buf)},
	{}
};
$MethodInfo ModuleHashes$$Lambda$lambda$computeHash$0::methodInfos[3] = {
	{"<init>", "(Ljava/security/MessageDigest;Ljava/lang/module/ModuleReader;[B)V", nullptr, $PUBLIC, $method(ModuleHashes$$Lambda$lambda$computeHash$0, init$, void, $MessageDigest*, $ModuleReader*, $bytes*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModuleHashes$$Lambda$lambda$computeHash$0, accept, void, Object$*)},
	{}
};
$ClassInfo ModuleHashes$$Lambda$lambda$computeHash$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleHashes$$Lambda$lambda$computeHash$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModuleHashes$$Lambda$lambda$computeHash$0::load$($String* name, bool initialize) {
	$loadClass(ModuleHashes$$Lambda$lambda$computeHash$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleHashes$$Lambda$lambda$computeHash$0::class$ = nullptr;

class ModuleHashes$$Lambda$lambda$toString$1$1 : public $Consumer {
	$class(ModuleHashes$$Lambda$lambda$toString$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($StringBuilder* sb) {
		$set(this, sb, sb);
	}
	virtual void accept(Object$* e) override {
		ModuleHashes::lambda$toString$1(sb, $cast($Map$Entry, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ModuleHashes$$Lambda$lambda$toString$1$1>());
	}
	$StringBuilder* sb = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ModuleHashes$$Lambda$lambda$toString$1$1::fieldInfos[2] = {
	{"sb", "Ljava/lang/StringBuilder;", nullptr, $PUBLIC, $field(ModuleHashes$$Lambda$lambda$toString$1$1, sb)},
	{}
};
$MethodInfo ModuleHashes$$Lambda$lambda$toString$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/StringBuilder;)V", nullptr, $PUBLIC, $method(ModuleHashes$$Lambda$lambda$toString$1$1, init$, void, $StringBuilder*)},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ModuleHashes$$Lambda$lambda$toString$1$1, accept, void, Object$*)},
	{}
};
$ClassInfo ModuleHashes$$Lambda$lambda$toString$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.module.ModuleHashes$$Lambda$lambda$toString$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* ModuleHashes$$Lambda$lambda$toString$1$1::load$($String* name, bool initialize) {
	$loadClass(ModuleHashes$$Lambda$lambda$toString$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ModuleHashes$$Lambda$lambda$toString$1$1::class$ = nullptr;

$FieldInfo _ModuleHashes_FieldInfo_[] = {
	{"algorithm", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ModuleHashes, algorithm$)},
	{"nameToHash", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;[B>;", $PRIVATE | $FINAL, $field(ModuleHashes, nameToHash)},
	{}
};

$MethodInfo _ModuleHashes_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/Map;)V", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;[B>;)V", 0, $method(ModuleHashes, init$, void, $String*, $Map*)},
	{"algorithm", "()Ljava/lang/String;", nullptr, $PUBLIC, $method(ModuleHashes, algorithm, $String*)},
	{"computeHash", "(Ljava/lang/module/ModuleReader;Ljava/lang/String;)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleHashes, computeHash, $bytes*, $ModuleReader*, $String*)},
	{"computeHash", "(Ljava/util/function/Supplier;Ljava/lang/String;)[B", "(Ljava/util/function/Supplier<Ljava/lang/module/ModuleReader;>;Ljava/lang/String;)[B", $STATIC, $staticMethod(ModuleHashes, computeHash, $bytes*, $Supplier*, $String*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(ModuleHashes, equals, bool, Object$*)},
	{"generate", "(Ljava/util/Set;Ljava/lang/String;)Ljdk/internal/module/ModuleHashes;", "(Ljava/util/Set<Ljava/lang/module/ModuleReference;>;Ljava/lang/String;)Ljdk/internal/module/ModuleHashes;", $STATIC, $staticMethod(ModuleHashes, generate, ModuleHashes*, $Set*, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(ModuleHashes, hashCode, int32_t)},
	{"hashFor", "(Ljava/lang/String;)[B", nullptr, $PUBLIC, $method(ModuleHashes, hashFor, $bytes*, $String*)},
	{"hashes", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;[B>;", $PUBLIC, $method(ModuleHashes, hashes, $Map*)},
	{"lambda$computeHash$0", "(Ljava/security/MessageDigest;Ljava/lang/module/ModuleReader;[BLjava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleHashes, lambda$computeHash$0, void, $MessageDigest*, $ModuleReader*, $bytes*, $String*)},
	{"lambda$toString$1", "(Ljava/lang/StringBuilder;Ljava/util/Map$Entry;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ModuleHashes, lambda$toString$1, void, $StringBuilder*, $Map$Entry*)},
	{"names", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PUBLIC, $method(ModuleHashes, names, $Set*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ModuleHashes, toString, $String*)},
	{}
};

$InnerClassInfo _ModuleHashes_InnerClassesInfo_[] = {
	{"jdk.internal.module.ModuleHashes$Builder", "jdk.internal.module.ModuleHashes", "Builder", $PUBLIC | $STATIC},
	{"jdk.internal.module.ModuleHashes$HashSupplier", "jdk.internal.module.ModuleHashes", "HashSupplier", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ModuleHashes_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.module.ModuleHashes",
	"java.lang.Object",
	nullptr,
	_ModuleHashes_FieldInfo_,
	_ModuleHashes_MethodInfo_,
	nullptr,
	nullptr,
	_ModuleHashes_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.module.ModuleHashes$Builder,jdk.internal.module.ModuleHashes$HashSupplier"
};

$Object* allocate$ModuleHashes($Class* clazz) {
	return $of($alloc(ModuleHashes));
}

void ModuleHashes::init$($String* algorithm, $Map* nameToHash) {
	$set(this, algorithm$, $cast($String, $Objects::requireNonNull(algorithm)));
	$set(this, nameToHash, $Collections::unmodifiableMap(nameToHash));
}

$String* ModuleHashes::algorithm() {
	return this->algorithm$;
}

$Set* ModuleHashes::names() {
	return $nc(this->nameToHash)->keySet();
}

$bytes* ModuleHashes::hashFor($String* mn) {
	return $cast($bytes, $nc(this->nameToHash)->get(mn));
}

$Map* ModuleHashes::hashes() {
	return this->nameToHash;
}

$bytes* ModuleHashes::computeHash($ModuleReader* reader, $String* algorithm) {
	$useLocalCurrentObjectStackCache();
	$var($MessageDigest, md, nullptr);
	try {
		$assign(md, $MessageDigest::getInstance(algorithm));
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($IllegalArgumentException, static_cast<$Throwable*>(e));
	}
	try {
		$var($bytes, buf, $new($bytes, 32 * 1024));
		$nc($($nc($($nc(reader)->list()))->sorted()))->forEach(static_cast<$Consumer*>($$new(ModuleHashes$$Lambda$lambda$computeHash$0, md, reader, buf)));
	} catch ($IOException& ioe) {
		$throwNew($UncheckedIOException, ioe);
	}
	return $nc(md)->digest();
}

$bytes* ModuleHashes::computeHash($Supplier* supplier, $String* algorithm) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ModuleReader, reader, $cast($ModuleReader, $nc(supplier)->get()));
		{
			$var($Throwable, var$0, nullptr);
			$var($bytes, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					$assign(var$2, computeHash(reader, algorithm));
					return$1 = true;
					goto $finally;
				} catch ($Throwable& t$) {
					if (reader != nullptr) {
						try {
							reader->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} $finally: {
				if (reader != nullptr) {
					reader->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	} catch ($IOException& ioe) {
		$throwNew($UncheckedIOException, ioe);
	}
	$shouldNotReachHere();
}

ModuleHashes* ModuleHashes::generate($Set* mrefs, $String* algorithm) {
	$useLocalCurrentObjectStackCache();
	$var($Map, nameToHash, static_cast<$Map*>(static_cast<$AbstractMap*>($new($TreeMap))));
	{
		$var($Iterator, i$, $nc(mrefs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ModuleReference, mref, $cast($ModuleReference, i$->next()));
			{
				try {
					$var($ModuleReader, reader, $nc(mref)->open());
					{
						$var($Throwable, var$0, nullptr);
						try {
							try {
								$var($bytes, hash, computeHash(reader, algorithm));
								nameToHash->put($($nc($(mref->descriptor()))->name()), hash);
							} catch ($Throwable& t$) {
								if (reader != nullptr) {
									try {
										reader->close();
									} catch ($Throwable& x2) {
										t$->addSuppressed(x2);
									}
								}
								$throw(t$);
							}
						} catch ($Throwable& var$1) {
							$assign(var$0, var$1);
						} /*finally*/ {
							if (reader != nullptr) {
								reader->close();
							}
						}
						if (var$0 != nullptr) {
							$throw(var$0);
						}
					}
				} catch ($IOException& ioe) {
					$throwNew($UncheckedIOException, ioe);
				}
			}
		}
	}
	return $new(ModuleHashes, algorithm, nameToHash);
}

int32_t ModuleHashes::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t h = $nc(this->algorithm$)->hashCode();
	{
		$var($Iterator, i$, $nc($($nc(this->nameToHash)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				h = h * 31 + $nc(($cast($String, $($nc(e)->getKey()))))->hashCode();
				h = h * 31 + $Arrays::hashCode($cast($bytes, $(e->getValue())));
			}
		}
	}
	return h;
}

bool ModuleHashes::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf(ModuleHashes, obj))) {
		return false;
	}
	$var(ModuleHashes, other, $cast(ModuleHashes, obj));
	bool var$0 = !$nc(this->algorithm$)->equals($nc(other)->algorithm$);
	if (!var$0) {
		int32_t var$1 = $nc(this->nameToHash)->size();
		var$0 = var$1 != $nc($nc(other)->nameToHash)->size();
	}
	if (var$0) {
		return false;
	}
	{
		$var($Iterator, i$, $nc($($nc(this->nameToHash)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, name, $cast($String, $nc(e)->getKey()));
				$var($bytes, hash, $cast($bytes, e->getValue()));
				if (!$Arrays::equals(hash, $cast($bytes, $($nc($nc(other)->nameToHash)->get(name))))) {
					return false;
				}
			}
		}
	}
	return true;
}

$String* ModuleHashes::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, this->algorithm$));
	sb->append(" "_s);
	$nc($($nc($($nc($($nc(this->nameToHash)->entrySet()))->stream()))->sorted($($Map$Entry::comparingByKey()))))->forEach(static_cast<$Consumer*>($$new(ModuleHashes$$Lambda$lambda$toString$1$1, sb)));
	return sb->toString();
}

void ModuleHashes::lambda$toString$1($StringBuilder* sb, $Map$Entry* e) {
	$useLocalCurrentObjectStackCache();
	$nc(sb)->append($cast($String, $($nc(e)->getKey())));
	sb->append("="_s);
	$var($bytes, ba, $cast($bytes, $nc(e)->getValue()));
	{
		$var($bytes, arr$, ba);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int8_t b = arr$->get(i$);
			{
				sb->append($($String::format("%02x"_s, $$new($ObjectArray, {$($of($Integer::valueOf((int32_t)(b & (uint32_t)255))))}))));
			}
		}
	}
}

void ModuleHashes::lambda$computeHash$0($MessageDigest* md, $ModuleReader* reader, $bytes* buf, $String* rn) {
	$useLocalCurrentObjectStackCache();
	$init($StandardCharsets);
	$nc(md)->update($($nc(rn)->getBytes($StandardCharsets::UTF_8)));
	try {
		$var($InputStream, in, $cast($InputStream, $nc($($nc(reader)->open(rn)))->orElseThrow()));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					int32_t n = 0;
					while ((n = $nc(in)->read(buf)) > 0) {
						md->update(buf, 0, n);
					}
				} catch ($Throwable& t$) {
					if (in != nullptr) {
						try {
							in->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
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
	} catch ($IOException& ioe) {
		$throwNew($UncheckedIOException, ioe);
	}
}

ModuleHashes::ModuleHashes() {
}

$Class* ModuleHashes::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ModuleHashes$$Lambda$lambda$computeHash$0::classInfo$.name)) {
			return ModuleHashes$$Lambda$lambda$computeHash$0::load$(name, initialize);
		}
		if (name->equals(ModuleHashes$$Lambda$lambda$toString$1$1::classInfo$.name)) {
			return ModuleHashes$$Lambda$lambda$toString$1$1::load$(name, initialize);
		}
	}
	$loadClass(ModuleHashes, name, initialize, &_ModuleHashes_ClassInfo_, allocate$ModuleHashes);
	return class$;
}

$Class* ModuleHashes::class$ = nullptr;

		} // module
	} // internal
} // jdk
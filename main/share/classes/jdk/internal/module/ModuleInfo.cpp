#include <jdk/internal/module/ModuleInfo.h>

#include <java/io/DataInput.h>
#include <java/io/DataInputStream.h>
#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/module/InvalidModuleDescriptorException.h>
#include <java/lang/module/ModuleDescriptor$Builder.h>
#include <java/lang/module/ModuleDescriptor$Exports$Modifier.h>
#include <java/lang/module/ModuleDescriptor$Modifier.h>
#include <java/lang/module/ModuleDescriptor$Opens$Modifier.h>
#include <java/lang/module/ModuleDescriptor$Requires$Modifier.h>
#include <java/lang/module/ModuleDescriptor.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/access/JavaLangModuleAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/misc/VM.h>
#include <jdk/internal/module/ModuleHashes.h>
#include <jdk/internal/module/ModuleInfo$Attributes.h>
#include <jdk/internal/module/ModuleInfo$ConstantPool.h>
#include <jdk/internal/module/ModuleInfo$CountingDataInput.h>
#include <jdk/internal/module/ModuleInfo$DataInputWrapper.h>
#include <jdk/internal/module/ModuleResolution.h>
#include <jdk/internal/module/ModuleTarget.h>
#include <jcpp.h>

#undef JLMA
#undef MANDATED
#undef OPEN
#undef STATIC
#undef SYNTHETIC
#undef TRANSITIVE

using $DataInput = ::java::io::DataInput;
using $DataInputStream = ::java::io::DataInputStream;
using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $InvalidModuleDescriptorException = ::java::lang::module::InvalidModuleDescriptorException;
using $ModuleDescriptor = ::java::lang::module::ModuleDescriptor;
using $ModuleDescriptor$Builder = ::java::lang::module::ModuleDescriptor$Builder;
using $ModuleDescriptor$Exports$Modifier = ::java::lang::module::ModuleDescriptor$Exports$Modifier;
using $ModuleDescriptor$Modifier = ::java::lang::module::ModuleDescriptor$Modifier;
using $ModuleDescriptor$Opens$Modifier = ::java::lang::module::ModuleDescriptor$Opens$Modifier;
using $ModuleDescriptor$Requires$Modifier = ::java::lang::module::ModuleDescriptor$Requires$Modifier;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Supplier = ::java::util::function::Supplier;
using $JavaLangModuleAccess = ::jdk::internal::access::JavaLangModuleAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $VM = ::jdk::internal::misc::VM;
using $ModuleHashes = ::jdk::internal::module::ModuleHashes;
using $ModuleInfo$Attributes = ::jdk::internal::module::ModuleInfo$Attributes;
using $ModuleInfo$ConstantPool = ::jdk::internal::module::ModuleInfo$ConstantPool;
using $ModuleInfo$CountingDataInput = ::jdk::internal::module::ModuleInfo$CountingDataInput;
using $ModuleInfo$DataInputWrapper = ::jdk::internal::module::ModuleInfo$DataInputWrapper;
using $ModuleResolution = ::jdk::internal::module::ModuleResolution;
using $ModuleTarget = ::jdk::internal::module::ModuleTarget;

namespace jdk {
	namespace internal {
		namespace module {

$FieldInfo _ModuleInfo_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ModuleInfo, $assertionsDisabled)},
	{"JLMA", "Ljdk/internal/access/JavaLangModuleAccess;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ModuleInfo, JLMA)},
	{"packageFinder", "Ljava/util/function/Supplier;", "Ljava/util/function/Supplier<Ljava/util/Set<Ljava/lang/String;>;>;", $PRIVATE | $FINAL, $field(ModuleInfo, packageFinder)},
	{"parseHashes", "Z", nullptr, $PRIVATE | $FINAL, $field(ModuleInfo, parseHashes)},
	{"predefinedNotAllowed", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $VOLATILE, $staticField(ModuleInfo, predefinedNotAllowed)},
	{}
};

$MethodInfo _ModuleInfo_MethodInfo_[] = {
	{"<init>", "(Ljava/util/function/Supplier;Z)V", "(Ljava/util/function/Supplier<Ljava/util/Set<Ljava/lang/String;>;>;Z)V", $PRIVATE, $method(ModuleInfo, init$, void, $Supplier*, bool)},
	{"<init>", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/util/Set<Ljava/lang/String;>;>;)V", $PRIVATE, $method(ModuleInfo, init$, void, $Supplier*)},
	{"doRead", "(Ljava/io/DataInput;)Ljdk/internal/module/ModuleInfo$Attributes;", nullptr, $PRIVATE, $method(ModuleInfo, doRead, $ModuleInfo$Attributes*, $DataInput*), "java.io.IOException"},
	{"invalidModuleDescriptor", "(Ljava/lang/String;)Ljava/lang/module/InvalidModuleDescriptorException;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleInfo, invalidModuleDescriptor, $InvalidModuleDescriptorException*, $String*)},
	{"isAttributeAtMostOnce", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleInfo, isAttributeAtMostOnce, bool, $String*)},
	{"isAttributeDisallowed", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleInfo, isAttributeDisallowed, bool, $String*)},
	{"read", "(Ljava/io/InputStream;Ljava/util/function/Supplier;)Ljdk/internal/module/ModuleInfo$Attributes;", "(Ljava/io/InputStream;Ljava/util/function/Supplier<Ljava/util/Set<Ljava/lang/String;>;>;)Ljdk/internal/module/ModuleInfo$Attributes;", $PUBLIC | $STATIC, $staticMethod(ModuleInfo, read, $ModuleInfo$Attributes*, $InputStream*, $Supplier*), "java.io.IOException"},
	{"read", "(Ljava/nio/ByteBuffer;Ljava/util/function/Supplier;)Ljdk/internal/module/ModuleInfo$Attributes;", "(Ljava/nio/ByteBuffer;Ljava/util/function/Supplier<Ljava/util/Set<Ljava/lang/String;>;>;)Ljdk/internal/module/ModuleInfo$Attributes;", $PUBLIC | $STATIC, $staticMethod(ModuleInfo, read, $ModuleInfo$Attributes*, $ByteBuffer*, $Supplier*)},
	{"readIgnoringHashes", "(Ljava/nio/ByteBuffer;Ljava/util/function/Supplier;)Ljdk/internal/module/ModuleInfo$Attributes;", "(Ljava/nio/ByteBuffer;Ljava/util/function/Supplier<Ljava/util/Set<Ljava/lang/String;>;>;)Ljdk/internal/module/ModuleInfo$Attributes;", $PUBLIC | $STATIC, $staticMethod(ModuleInfo, readIgnoringHashes, $ModuleInfo$Attributes*, $ByteBuffer*, $Supplier*)},
	{"readModuleAttribute", "(Ljava/io/DataInput;Ljdk/internal/module/ModuleInfo$ConstantPool;I)Ljava/lang/module/ModuleDescriptor$Builder;", nullptr, $PRIVATE, $method(ModuleInfo, readModuleAttribute, $ModuleDescriptor$Builder*, $DataInput*, $ModuleInfo$ConstantPool*, int32_t), "java.io.IOException"},
	{"readModuleHashesAttribute", "(Ljava/io/DataInput;Ljdk/internal/module/ModuleInfo$ConstantPool;)Ljdk/internal/module/ModuleHashes;", nullptr, $PRIVATE, $method(ModuleInfo, readModuleHashesAttribute, $ModuleHashes*, $DataInput*, $ModuleInfo$ConstantPool*), "java.io.IOException"},
	{"readModuleMainClassAttribute", "(Ljava/io/DataInput;Ljdk/internal/module/ModuleInfo$ConstantPool;)Ljava/lang/String;", nullptr, $PRIVATE, $method(ModuleInfo, readModuleMainClassAttribute, $String*, $DataInput*, $ModuleInfo$ConstantPool*), "java.io.IOException"},
	{"readModulePackagesAttribute", "(Ljava/io/DataInput;Ljdk/internal/module/ModuleInfo$ConstantPool;)Ljava/util/Set;", "(Ljava/io/DataInput;Ljdk/internal/module/ModuleInfo$ConstantPool;)Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE, $method(ModuleInfo, readModulePackagesAttribute, $Set*, $DataInput*, $ModuleInfo$ConstantPool*), "java.io.IOException"},
	{"readModuleResolution", "(Ljava/io/DataInput;Ljdk/internal/module/ModuleInfo$ConstantPool;)Ljdk/internal/module/ModuleResolution;", nullptr, $PRIVATE, $method(ModuleInfo, readModuleResolution, $ModuleResolution*, $DataInput*, $ModuleInfo$ConstantPool*), "java.io.IOException"},
	{"readModuleTargetAttribute", "(Ljava/io/DataInput;Ljdk/internal/module/ModuleInfo$ConstantPool;)Ljdk/internal/module/ModuleTarget;", nullptr, $PRIVATE, $method(ModuleInfo, readModuleTargetAttribute, $ModuleTarget*, $DataInput*, $ModuleInfo$ConstantPool*), "java.io.IOException"},
	{"truncatedModuleDescriptor", "()Ljava/lang/module/InvalidModuleDescriptorException;", nullptr, $PRIVATE | $STATIC, $staticMethod(ModuleInfo, truncatedModuleDescriptor, $InvalidModuleDescriptorException*)},
	{}
};

$InnerClassInfo _ModuleInfo_InnerClassesInfo_[] = {
	{"jdk.internal.module.ModuleInfo$CountingDataInput", "jdk.internal.module.ModuleInfo", "CountingDataInput", $PRIVATE | $STATIC},
	{"jdk.internal.module.ModuleInfo$DataInputWrapper", "jdk.internal.module.ModuleInfo", "DataInputWrapper", $PRIVATE | $STATIC},
	{"jdk.internal.module.ModuleInfo$ConstantPool", "jdk.internal.module.ModuleInfo", "ConstantPool", $PRIVATE | $STATIC},
	{"jdk.internal.module.ModuleInfo$Attributes", "jdk.internal.module.ModuleInfo", "Attributes", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _ModuleInfo_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.module.ModuleInfo",
	"java.lang.Object",
	nullptr,
	_ModuleInfo_FieldInfo_,
	_ModuleInfo_MethodInfo_,
	nullptr,
	nullptr,
	_ModuleInfo_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.module.ModuleInfo$CountingDataInput,jdk.internal.module.ModuleInfo$DataInputWrapper,jdk.internal.module.ModuleInfo$ConstantPool,jdk.internal.module.ModuleInfo$ConstantPool$ValueEntry,jdk.internal.module.ModuleInfo$ConstantPool$Index2Entry,jdk.internal.module.ModuleInfo$ConstantPool$IndexEntry,jdk.internal.module.ModuleInfo$ConstantPool$Entry,jdk.internal.module.ModuleInfo$Attributes"
};

$Object* allocate$ModuleInfo($Class* clazz) {
	return $of($alloc(ModuleInfo));
}

bool ModuleInfo::$assertionsDisabled = false;
$JavaLangModuleAccess* ModuleInfo::JLMA = nullptr;
$volatile($Set*) ModuleInfo::predefinedNotAllowed = nullptr;

void ModuleInfo::init$($Supplier* pf, bool ph) {
	$set(this, packageFinder, pf);
	this->parseHashes = ph;
}

void ModuleInfo::init$($Supplier* pf) {
	ModuleInfo::init$(pf, true);
}

$ModuleInfo$Attributes* ModuleInfo::read($InputStream* in, $Supplier* pf) {
	$init(ModuleInfo);
	$useLocalCurrentObjectStackCache();
	try {
		return $$new(ModuleInfo, pf)->doRead($$new($DataInputStream, in));
	} catch ($IllegalArgumentException& e) {
		$throw($(invalidModuleDescriptor($(e->getMessage()))));
	} catch ($IllegalStateException& e) {
		$throw($(invalidModuleDescriptor($(e->getMessage()))));
	} catch ($EOFException& x) {
		$throw($(truncatedModuleDescriptor()));
	}
	$shouldNotReachHere();
}

$ModuleInfo$Attributes* ModuleInfo::read($ByteBuffer* bb, $Supplier* pf) {
	$init(ModuleInfo);
	$useLocalCurrentObjectStackCache();
	try {
		return $$new(ModuleInfo, pf)->doRead($$new($ModuleInfo$DataInputWrapper, bb));
	} catch ($IllegalArgumentException& e) {
		$throw($(invalidModuleDescriptor($(e->getMessage()))));
	} catch ($IllegalStateException& e) {
		$throw($(invalidModuleDescriptor($(e->getMessage()))));
	} catch ($EOFException& x) {
		$throw($(truncatedModuleDescriptor()));
	} catch ($IOException& ioe) {
		$throwNew($UncheckedIOException, ioe);
	}
	$shouldNotReachHere();
}

$ModuleInfo$Attributes* ModuleInfo::readIgnoringHashes($ByteBuffer* bb, $Supplier* pf) {
	$init(ModuleInfo);
	$useLocalCurrentObjectStackCache();
	try {
		return $$new(ModuleInfo, pf, false)->doRead($$new($ModuleInfo$DataInputWrapper, bb));
	} catch ($IllegalArgumentException& e) {
		$throw($(invalidModuleDescriptor($(e->getMessage()))));
	} catch ($IllegalStateException& e) {
		$throw($(invalidModuleDescriptor($(e->getMessage()))));
	} catch ($EOFException& x) {
		$throw($(truncatedModuleDescriptor()));
	} catch ($IOException& ioe) {
		$throwNew($UncheckedIOException, ioe);
	}
	$shouldNotReachHere();
}

$ModuleInfo$Attributes* ModuleInfo::doRead($DataInput* input) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleInfo$CountingDataInput, in, $new($ModuleInfo$CountingDataInput, input));
	int32_t magic = in->readInt();
	if (magic != (int32_t)0xCAFEBABE) {
		$throw($(invalidModuleDescriptor("Bad magic number"_s)));
	}
	int32_t minor_version = in->readUnsignedShort();
	int32_t major_version = in->readUnsignedShort();
	if (!$VM::isSupportedModuleDescriptorVersion(major_version, minor_version)) {
		$throw($(invalidModuleDescriptor($$str({"Unsupported major.minor version "_s, $$str(major_version), "."_s, $$str(minor_version)}))));
	}
	$var($ModuleInfo$ConstantPool, cpool, $new($ModuleInfo$ConstantPool, in));
	int32_t access_flags = in->readUnsignedShort();
	if (access_flags != 32768) {
		$throw($(invalidModuleDescriptor("access_flags should be ACC_MODULE"_s)));
	}
	int32_t this_class = in->readUnsignedShort();
	$var($String, mn, cpool->getClassName(this_class));
	if (!"module-info"_s->equals(mn)) {
		$throw($(invalidModuleDescriptor("this_class should be module-info"_s)));
	}
	int32_t super_class = in->readUnsignedShort();
	if (super_class > 0) {
		$throw($(invalidModuleDescriptor("bad #super_class"_s)));
	}
	int32_t interfaces_count = in->readUnsignedShort();
	if (interfaces_count > 0) {
		$throw($(invalidModuleDescriptor("Bad #interfaces"_s)));
	}
	int32_t fields_count = in->readUnsignedShort();
	if (fields_count > 0) {
		$throw($(invalidModuleDescriptor("Bad #fields"_s)));
	}
	int32_t methods_count = in->readUnsignedShort();
	if (methods_count > 0) {
		$throw($(invalidModuleDescriptor("Bad #methods"_s)));
	}
	int32_t attributes_count = in->readUnsignedShort();
	$var($Set, attributes, $new($HashSet));
	$var($ModuleDescriptor$Builder, builder, nullptr);
	$var($Set, allPackages, nullptr);
	$var($String, mainClass, nullptr);
	$var($ModuleTarget, moduleTarget, nullptr);
	$var($ModuleHashes, moduleHashes, nullptr);
	$var($ModuleResolution, moduleResolution, nullptr);
	for (int32_t i = 0; i < attributes_count; ++i) {
		int32_t name_index = in->readUnsignedShort();
		$var($String, attribute_name, cpool->getUtf8(name_index));
		int32_t length = in->readInt();
		bool added = attributes->add(attribute_name);
		if (!added && isAttributeAtMostOnce(attribute_name)) {
			$throw($(invalidModuleDescriptor($$str({"More than one "_s, attribute_name, " attribute"_s}))));
		}
		int64_t initialPosition = in->count();
		{
			$var($String, s9156$, attribute_name);
			int32_t tmp9156$ = -1;
			switch ($nc(s9156$)->hashCode()) {
			case (int32_t)0x89B0928C:
				{
					if (s9156$->equals("Module"_s)) {
						tmp9156$ = 0;
					}
					break;
				}
			case 0x2706FF99:
				{
					if (s9156$->equals("ModulePackages"_s)) {
						tmp9156$ = 1;
					}
					break;
				}
			case 0x3DEB0A13:
				{
					if (s9156$->equals("ModuleMainClass"_s)) {
						tmp9156$ = 2;
					}
					break;
				}
			case 0x5646D73D:
				{
					if (s9156$->equals("ModuleTarget"_s)) {
						tmp9156$ = 3;
					}
					break;
				}
			case 0x41CD27E8:
				{
					if (s9156$->equals("ModuleHashes"_s)) {
						tmp9156$ = 4;
					}
					break;
				}
			case 0x20272858:
				{
					if (s9156$->equals("ModuleResolution"_s)) {
						tmp9156$ = 5;
					}
					break;
				}
			}
			switch (tmp9156$) {
			case 0:
				{
					$assign(builder, readModuleAttribute(in, cpool, major_version));
					break;
				}
			case 1:
				{
					$assign(allPackages, readModulePackagesAttribute(in, cpool));
					break;
				}
			case 2:
				{
					$assign(mainClass, readModuleMainClassAttribute(in, cpool));
					break;
				}
			case 3:
				{
					$assign(moduleTarget, readModuleTargetAttribute(in, cpool));
					break;
				}
			case 4:
				{
					if (this->parseHashes) {
						$assign(moduleHashes, readModuleHashesAttribute(in, cpool));
					} else {
						in->skipBytes(length);
					}
					break;
				}
			case 5:
				{
					$assign(moduleResolution, readModuleResolution(in, cpool));
					break;
				}
			default:
				{
					if (isAttributeDisallowed(attribute_name)) {
						$throw($(invalidModuleDescriptor($$str({attribute_name, " attribute not allowed"_s}))));
					} else {
						in->skipBytes(length);
					}
				}
			}
		}
		int64_t newPosition = in->count();
		if ((newPosition - initialPosition) != length) {
			$throw($(invalidModuleDescriptor($$str({"Attribute "_s, attribute_name, " does not match its expected length"_s}))));
		}
	}
	if (builder == nullptr) {
		$throw($(invalidModuleDescriptor($$str({"Module"_s, " attribute not found"_s}))));
	}
	if (mainClass != nullptr) {
		$nc(builder)->mainClass(mainClass);
	}
	bool usedPackageFinder = false;
	if (allPackages == nullptr && this->packageFinder != nullptr) {
		try {
			$assign(allPackages, $cast($Set, $nc(this->packageFinder)->get()));
		} catch ($UncheckedIOException& x) {
			$throw($($cast($IOException, x->getCause())));
		}
		usedPackageFinder = true;
	}
	if (allPackages != nullptr) {
		$var($Set, knownPackages, $nc(ModuleInfo::JLMA)->packages(builder));
		if (!allPackages->containsAll(knownPackages)) {
			$var($Set, missingPackages, $new($HashSet, static_cast<$Collection*>(knownPackages)));
			missingPackages->removeAll(allPackages);
			if (!ModuleInfo::$assertionsDisabled && ! !missingPackages->isEmpty()) {
				$throwNew($AssertionError);
			}
			$var($String, missingPackage, $cast($String, $nc($(missingPackages->iterator()))->next()));
			$var($String, tail, nullptr);
			if (usedPackageFinder) {
				$assign(tail, " not found in module"_s);
			} else {
				$assign(tail, " missing from ModulePackages class file attribute"_s);
			}
			$throw($(invalidModuleDescriptor($$str({"Package "_s, missingPackage, tail}))));
		}
		$nc(builder)->packages(allPackages);
	}
	$var($ModuleDescriptor, descriptor, $nc(builder)->build());
	return $new($ModuleInfo$Attributes, descriptor, moduleTarget, moduleHashes, moduleResolution);
}

$ModuleDescriptor$Builder* ModuleInfo::readModuleAttribute($DataInput* in, $ModuleInfo$ConstantPool* cpool, int32_t major) {
	$useLocalCurrentObjectStackCache();
	int32_t module_name_index = $nc(in)->readUnsignedShort();
	$var($String, mn, $nc(cpool)->getModuleName(module_name_index));
	int32_t module_flags = in->readUnsignedShort();
	$var($Set, modifiers, $new($HashSet));
	bool open = (((int32_t)(module_flags & (uint32_t)32)) != 0);
	if (open) {
		$init($ModuleDescriptor$Modifier);
		modifiers->add($ModuleDescriptor$Modifier::OPEN);
	}
	if (((int32_t)(module_flags & (uint32_t)4096)) != 0) {
		$init($ModuleDescriptor$Modifier);
		modifiers->add($ModuleDescriptor$Modifier::SYNTHETIC);
	}
	if (((int32_t)(module_flags & (uint32_t)32768)) != 0) {
		$init($ModuleDescriptor$Modifier);
		modifiers->add($ModuleDescriptor$Modifier::MANDATED);
	}
	$var($ModuleDescriptor$Builder, builder, $nc(ModuleInfo::JLMA)->newModuleBuilder(mn, false, modifiers));
	int32_t module_version_index = in->readUnsignedShort();
	if (module_version_index != 0) {
		$var($String, vs, cpool->getUtf8(module_version_index));
		$nc(builder)->version(vs);
	}
	int32_t requires_count = in->readUnsignedShort();
	bool requiresJavaBase = false;
	for (int32_t i = 0; i < requires_count; ++i) {
		int32_t requires_index = in->readUnsignedShort();
		$var($String, dn, cpool->getModuleName(requires_index));
		int32_t requires_flags = in->readUnsignedShort();
		$var($Set, mods, nullptr);
		if (requires_flags == 0) {
			$assign(mods, $Set::of());
		} else {
			$assign(mods, $new($HashSet));
			if (((int32_t)(requires_flags & (uint32_t)32)) != 0) {
				$init($ModuleDescriptor$Requires$Modifier);
				mods->add($ModuleDescriptor$Requires$Modifier::TRANSITIVE);
			}
			if (((int32_t)(requires_flags & (uint32_t)64)) != 0) {
				$init($ModuleDescriptor$Requires$Modifier);
				mods->add($ModuleDescriptor$Requires$Modifier::STATIC);
			}
			if (((int32_t)(requires_flags & (uint32_t)4096)) != 0) {
				$init($ModuleDescriptor$Requires$Modifier);
				mods->add($ModuleDescriptor$Requires$Modifier::SYNTHETIC);
			}
			if (((int32_t)(requires_flags & (uint32_t)32768)) != 0) {
				$init($ModuleDescriptor$Requires$Modifier);
				mods->add($ModuleDescriptor$Requires$Modifier::MANDATED);
			}
		}
		int32_t requires_version_index = in->readUnsignedShort();
		if (requires_version_index == 0) {
			$nc(builder)->requires(mods, dn);
		} else {
			$var($String, vs, cpool->getUtf8(requires_version_index));
			$nc(ModuleInfo::JLMA)->requires(builder, mods, dn, vs);
		}
		if ($nc(dn)->equals("java.base"_s)) {
			bool var$0 = major >= 54;
			if (var$0) {
				$init($ModuleDescriptor$Requires$Modifier);
				bool var$1 = $nc(mods)->contains($ModuleDescriptor$Requires$Modifier::TRANSITIVE);
				var$0 = (var$1 || $nc(mods)->contains($ModuleDescriptor$Requires$Modifier::STATIC));
			}
			if (var$0) {
				$var($String, flagName, nullptr);
				$init($ModuleDescriptor$Requires$Modifier);
				if (mods->contains($ModuleDescriptor$Requires$Modifier::TRANSITIVE)) {
					$assign(flagName, "ACC_TRANSITIVE"_s);
				} else {
					$assign(flagName, "ACC_STATIC_PHASE"_s);
				}
				$throw($(invalidModuleDescriptor($$str({"The requires entry for java.base has "_s, flagName, " set"_s}))));
			}
			requiresJavaBase = true;
		}
	}
	if ($nc(mn)->equals("java.base"_s)) {
		if (requires_count > 0) {
			$throw($(invalidModuleDescriptor("The requires table for java.base must be 0 length"_s)));
		}
	} else if (!requiresJavaBase) {
		$throw($(invalidModuleDescriptor("The requires table must have an entry for java.base"_s)));
	}
	int32_t exports_count = in->readUnsignedShort();
	if (exports_count > 0) {
		for (int32_t i = 0; i < exports_count; ++i) {
			int32_t exports_index = in->readUnsignedShort();
			$var($String, pkg, cpool->getPackageName(exports_index));
			$var($Set, mods, nullptr);
			int32_t exports_flags = in->readUnsignedShort();
			if (exports_flags == 0) {
				$assign(mods, $Set::of());
			} else {
				$assign(mods, $new($HashSet));
				if (((int32_t)(exports_flags & (uint32_t)4096)) != 0) {
					$init($ModuleDescriptor$Exports$Modifier);
					mods->add($ModuleDescriptor$Exports$Modifier::SYNTHETIC);
				}
				if (((int32_t)(exports_flags & (uint32_t)32768)) != 0) {
					$init($ModuleDescriptor$Exports$Modifier);
					mods->add($ModuleDescriptor$Exports$Modifier::MANDATED);
				}
			}
			int32_t exports_to_count = in->readUnsignedShort();
			if (exports_to_count > 0) {
				$var($Set, targets, $new($HashSet, exports_to_count));
				for (int32_t j = 0; j < exports_to_count; ++j) {
					int32_t exports_to_index = in->readUnsignedShort();
					$var($String, target, cpool->getModuleName(exports_to_index));
					if (!targets->add(target)) {
						$throw($(invalidModuleDescriptor($$str({pkg, " exported to "_s, target, " more than once"_s}))));
					}
				}
				$nc(builder)->exports(mods, pkg, targets);
			} else {
				$nc(builder)->exports(mods, pkg);
			}
		}
	}
	int32_t opens_count = in->readUnsignedShort();
	if (opens_count > 0) {
		if (open) {
			$throw($(invalidModuleDescriptor("The opens table for an open module must be 0 length"_s)));
		}
		for (int32_t i = 0; i < opens_count; ++i) {
			int32_t opens_index = in->readUnsignedShort();
			$var($String, pkg, cpool->getPackageName(opens_index));
			$var($Set, mods, nullptr);
			int32_t opens_flags = in->readUnsignedShort();
			if (opens_flags == 0) {
				$assign(mods, $Set::of());
			} else {
				$assign(mods, $new($HashSet));
				if (((int32_t)(opens_flags & (uint32_t)4096)) != 0) {
					$init($ModuleDescriptor$Opens$Modifier);
					mods->add($ModuleDescriptor$Opens$Modifier::SYNTHETIC);
				}
				if (((int32_t)(opens_flags & (uint32_t)32768)) != 0) {
					$init($ModuleDescriptor$Opens$Modifier);
					mods->add($ModuleDescriptor$Opens$Modifier::MANDATED);
				}
			}
			int32_t open_to_count = in->readUnsignedShort();
			if (open_to_count > 0) {
				$var($Set, targets, $new($HashSet, open_to_count));
				for (int32_t j = 0; j < open_to_count; ++j) {
					int32_t opens_to_index = in->readUnsignedShort();
					$var($String, target, cpool->getModuleName(opens_to_index));
					if (!targets->add(target)) {
						$throw($(invalidModuleDescriptor($$str({pkg, " opened to "_s, target, " more than once"_s}))));
					}
				}
				$nc(builder)->opens(mods, pkg, targets);
			} else {
				$nc(builder)->opens(mods, pkg);
			}
		}
	}
	int32_t uses_count = in->readUnsignedShort();
	if (uses_count > 0) {
		for (int32_t i = 0; i < uses_count; ++i) {
			int32_t index = in->readUnsignedShort();
			$var($String, sn, cpool->getClassName(index));
			$nc(builder)->uses(sn);
		}
	}
	int32_t provides_count = in->readUnsignedShort();
	if (provides_count > 0) {
		for (int32_t i = 0; i < provides_count; ++i) {
			int32_t index = in->readUnsignedShort();
			$var($String, sn, cpool->getClassName(index));
			int32_t with_count = in->readUnsignedShort();
			$var($List, providers, $new($ArrayList, with_count));
			for (int32_t j = 0; j < with_count; ++j) {
				index = in->readUnsignedShort();
				$var($String, pn, cpool->getClassName(index));
				if (!providers->add(pn)) {
					$throw($(invalidModuleDescriptor($$str({sn, " provides "_s, pn, " more than once"_s}))));
				}
			}
			$nc(builder)->provides(sn, providers);
		}
	}
	return builder;
}

$Set* ModuleInfo::readModulePackagesAttribute($DataInput* in, $ModuleInfo$ConstantPool* cpool) {
	$useLocalCurrentObjectStackCache();
	int32_t package_count = $nc(in)->readUnsignedShort();
	$var($Set, packages, $new($HashSet, package_count));
	for (int32_t i = 0; i < package_count; ++i) {
		int32_t index = in->readUnsignedShort();
		$var($String, pn, $nc(cpool)->getPackageName(index));
		bool added = packages->add(pn);
		if (!added) {
			$throw($(invalidModuleDescriptor($$str({"Package "_s, pn, " in ModulePackagesattribute more than once"_s}))));
		}
	}
	return packages;
}

$String* ModuleInfo::readModuleMainClassAttribute($DataInput* in, $ModuleInfo$ConstantPool* cpool) {
	int32_t index = $nc(in)->readUnsignedShort();
	return $nc(cpool)->getClassName(index);
}

$ModuleTarget* ModuleInfo::readModuleTargetAttribute($DataInput* in, $ModuleInfo$ConstantPool* cpool) {
	$var($String, targetPlatform, nullptr);
	int32_t index = $nc(in)->readUnsignedShort();
	if (index != 0) {
		$assign(targetPlatform, $nc(cpool)->getUtf8(index));
	}
	return $new($ModuleTarget, targetPlatform);
}

$ModuleHashes* ModuleInfo::readModuleHashesAttribute($DataInput* in, $ModuleInfo$ConstantPool* cpool) {
	$useLocalCurrentObjectStackCache();
	int32_t algorithm_index = $nc(in)->readUnsignedShort();
	$var($String, algorithm, $nc(cpool)->getUtf8(algorithm_index));
	int32_t hash_count = in->readUnsignedShort();
	$var($Map, map, $new($HashMap, hash_count));
	for (int32_t i = 0; i < hash_count; ++i) {
		int32_t module_name_index = in->readUnsignedShort();
		$var($String, mn, cpool->getModuleName(module_name_index));
		int32_t hash_length = in->readUnsignedShort();
		if (hash_length == 0) {
			$throw($(invalidModuleDescriptor("hash_length == 0"_s)));
		}
		$var($bytes, hash, $new($bytes, hash_length));
		in->readFully(hash);
		map->put(mn, hash);
	}
	return $new($ModuleHashes, algorithm, map);
}

$ModuleResolution* ModuleInfo::readModuleResolution($DataInput* in, $ModuleInfo$ConstantPool* cpool) {
	$useLocalCurrentObjectStackCache();
	int32_t flags = $nc(in)->readUnsignedShort();
	int32_t reason = 0;
	if (((int32_t)(flags & (uint32_t)2)) != 0) {
		reason = 2;
	}
	if (((int32_t)(flags & (uint32_t)4)) != 0) {
		if (reason != 0) {
			$throw($(invalidModuleDescriptor($$str({"Bad module resolution flags:"_s, $$str(flags)}))));
		}
		reason = 4;
	}
	if (((int32_t)(flags & (uint32_t)8)) != 0) {
		if (reason != 0) {
			$throw($(invalidModuleDescriptor($$str({"Bad module resolution flags:"_s, $$str(flags)}))));
		}
	}
	return $new($ModuleResolution, flags);
}

bool ModuleInfo::isAttributeAtMostOnce($String* name) {
	$init(ModuleInfo);
	bool var$6 = $nc(name)->equals("Module"_s);
	bool var$5 = var$6 || $nc(name)->equals("SourceFile"_s);
	bool var$4 = var$5 || $nc(name)->equals("SourceDebugExtension"_s);
	bool var$3 = var$4 || $nc(name)->equals("ModulePackages"_s);
	bool var$2 = var$3 || $nc(name)->equals("ModuleMainClass"_s);
	bool var$1 = var$2 || $nc(name)->equals("ModuleTarget"_s);
	bool var$0 = var$1 || $nc(name)->equals("ModuleHashes"_s);
	if (var$0 || $nc(name)->equals("ModuleResolution"_s)) {
		return true;
	}
	return false;
}

bool ModuleInfo::isAttributeDisallowed($String* name) {
	$init(ModuleInfo);
	$useLocalCurrentObjectStackCache();
	$var($Set, notAllowed, ModuleInfo::predefinedNotAllowed);
	if (notAllowed == nullptr) {
		$assign(notAllowed, $Set::of($$new($StringArray, {
			"ConstantValue"_s,
			"Code"_s,
			"Deprecated"_s,
			"StackMapTable"_s,
			"Exceptions"_s,
			"EnclosingMethod"_s,
			"Signature"_s,
			"LineNumberTable"_s,
			"LocalVariableTable"_s,
			"LocalVariableTypeTable"_s,
			"RuntimeVisibleParameterAnnotations"_s,
			"RuntimeInvisibleParameterAnnotations"_s,
			"RuntimeVisibleTypeAnnotations"_s,
			"RuntimeInvisibleTypeAnnotations"_s,
			"Synthetic"_s,
			"AnnotationDefault"_s,
			"BootstrapMethods"_s,
			"MethodParameters"_s
		})));
		$assignStatic(ModuleInfo::predefinedNotAllowed, notAllowed);
	}
	return $nc(notAllowed)->contains(name);
}

$InvalidModuleDescriptorException* ModuleInfo::invalidModuleDescriptor($String* msg) {
	$init(ModuleInfo);
	return $new($InvalidModuleDescriptorException, msg);
}

$InvalidModuleDescriptorException* ModuleInfo::truncatedModuleDescriptor() {
	$init(ModuleInfo);
	return invalidModuleDescriptor("Truncated module-info.class"_s);
}

void clinit$ModuleInfo($Class* class$) {
	ModuleInfo::$assertionsDisabled = !ModuleInfo::class$->desiredAssertionStatus();
	$assignStatic(ModuleInfo::JLMA, $SharedSecrets::getJavaLangModuleAccess());
}

ModuleInfo::ModuleInfo() {
}

$Class* ModuleInfo::load$($String* name, bool initialize) {
	$loadClass(ModuleInfo, name, initialize, &_ModuleInfo_ClassInfo_, clinit$ModuleInfo, allocate$ModuleInfo);
	return class$;
}

$Class* ModuleInfo::class$ = nullptr;

		} // module
	} // internal
} // jdk
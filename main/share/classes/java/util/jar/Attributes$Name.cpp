#include <java/util/jar/Attributes$Name.h>

#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/jar/Attributes.h>
#include <jdk/internal/misc/CDS.h>
#include <jcpp.h>

#undef CLASS_PATH
#undef CONTENT_TYPE
#undef EXTENSION_INSTALLATION
#undef EXTENSION_LIST
#undef EXTENSION_NAME
#undef IMPLEMENTATION_TITLE
#undef IMPLEMENTATION_URL
#undef IMPLEMENTATION_VENDOR
#undef IMPLEMENTATION_VENDOR_ID
#undef IMPLEMENTATION_VERSION
#undef KNOWN_NAMES
#undef MAIN_CLASS
#undef MANIFEST_VERSION
#undef MULTI_RELEASE
#undef SEALED
#undef SIGNATURE_VERSION
#undef SPECIFICATION_TITLE
#undef SPECIFICATION_VENDOR
#undef SPECIFICATION_VERSION

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $CDS = ::jdk::internal::misc::CDS;

namespace java {
	namespace util {
		namespace jar {

$CompoundAttribute _Attributes$Name_FieldAnnotations_KNOWN_NAMES[] = {
	{"Ljdk/internal/vm/annotation/Stable;", nullptr},
	{}
};

$CompoundAttribute _Attributes$Name_FieldAnnotations_EXTENSION_INSTALLATION[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Attributes$Name_FieldAnnotations_IMPLEMENTATION_VENDOR_ID[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Attributes$Name_FieldAnnotations_IMPLEMENTATION_URL[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _Attributes$Name_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Attributes$Name, name)},
	{"hashCode", "I", nullptr, $PRIVATE | $FINAL, $field(Attributes$Name, hashCode$)},
	{"KNOWN_NAMES", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/jar/Attributes$Name;>;", $PRIVATE | $STATIC, $staticField(Attributes$Name, KNOWN_NAMES), _Attributes$Name_FieldAnnotations_KNOWN_NAMES},
	{"MANIFEST_VERSION", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, MANIFEST_VERSION)},
	{"SIGNATURE_VERSION", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, SIGNATURE_VERSION)},
	{"CONTENT_TYPE", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, CONTENT_TYPE)},
	{"CLASS_PATH", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, CLASS_PATH)},
	{"MAIN_CLASS", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, MAIN_CLASS)},
	{"SEALED", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, SEALED)},
	{"EXTENSION_LIST", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, EXTENSION_LIST)},
	{"EXTENSION_NAME", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, EXTENSION_NAME)},
	{"EXTENSION_INSTALLATION", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $staticField(Attributes$Name, EXTENSION_INSTALLATION), _Attributes$Name_FieldAnnotations_EXTENSION_INSTALLATION},
	{"IMPLEMENTATION_TITLE", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, IMPLEMENTATION_TITLE)},
	{"IMPLEMENTATION_VERSION", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, IMPLEMENTATION_VERSION)},
	{"IMPLEMENTATION_VENDOR", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, IMPLEMENTATION_VENDOR)},
	{"IMPLEMENTATION_VENDOR_ID", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $staticField(Attributes$Name, IMPLEMENTATION_VENDOR_ID), _Attributes$Name_FieldAnnotations_IMPLEMENTATION_VENDOR_ID},
	{"IMPLEMENTATION_URL", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $staticField(Attributes$Name, IMPLEMENTATION_URL), _Attributes$Name_FieldAnnotations_IMPLEMENTATION_URL},
	{"SPECIFICATION_TITLE", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, SPECIFICATION_TITLE)},
	{"SPECIFICATION_VERSION", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, SPECIFICATION_VERSION)},
	{"SPECIFICATION_VENDOR", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, SPECIFICATION_VENDOR)},
	{"MULTI_RELEASE", "Ljava/util/jar/Attributes$Name;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Attributes$Name, MULTI_RELEASE)},
	{}
};

$MethodInfo _Attributes$Name_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(Attributes$Name, init$, void, $String*)},
	{"addName", "(Ljava/util/Map;Ljava/util/jar/Attributes$Name;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/util/jar/Attributes$Name;>;Ljava/util/jar/Attributes$Name;)V", $PRIVATE | $STATIC, $staticMethod(Attributes$Name, addName, void, $Map*, Attributes$Name*)},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(Attributes$Name, equals, bool, Object$*)},
	{"hash", "(Ljava/lang/String;)I", nullptr, $PRIVATE | $FINAL, $method(Attributes$Name, hash, int32_t, $String*)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(Attributes$Name, hashCode, int32_t)},
	{"of", "(Ljava/lang/String;)Ljava/util/jar/Attributes$Name;", nullptr, $STATIC | $FINAL, $staticMethod(Attributes$Name, of, Attributes$Name*, $String*)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(Attributes$Name, toString, $String*)},
	{}
};

$InnerClassInfo _Attributes$Name_InnerClassesInfo_[] = {
	{"java.util.jar.Attributes$Name", "java.util.jar.Attributes", "Name", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _Attributes$Name_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.jar.Attributes$Name",
	"java.lang.Object",
	nullptr,
	_Attributes$Name_FieldInfo_,
	_Attributes$Name_MethodInfo_,
	nullptr,
	nullptr,
	_Attributes$Name_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.jar.Attributes"
};

$Object* allocate$Attributes$Name($Class* clazz) {
	return $of($alloc(Attributes$Name));
}

$Map* Attributes$Name::KNOWN_NAMES = nullptr;
Attributes$Name* Attributes$Name::MANIFEST_VERSION = nullptr;
Attributes$Name* Attributes$Name::SIGNATURE_VERSION = nullptr;
Attributes$Name* Attributes$Name::CONTENT_TYPE = nullptr;
Attributes$Name* Attributes$Name::CLASS_PATH = nullptr;
Attributes$Name* Attributes$Name::MAIN_CLASS = nullptr;
Attributes$Name* Attributes$Name::SEALED = nullptr;
Attributes$Name* Attributes$Name::EXTENSION_LIST = nullptr;
Attributes$Name* Attributes$Name::EXTENSION_NAME = nullptr;
Attributes$Name* Attributes$Name::EXTENSION_INSTALLATION = nullptr;
Attributes$Name* Attributes$Name::IMPLEMENTATION_TITLE = nullptr;
Attributes$Name* Attributes$Name::IMPLEMENTATION_VERSION = nullptr;
Attributes$Name* Attributes$Name::IMPLEMENTATION_VENDOR = nullptr;
Attributes$Name* Attributes$Name::IMPLEMENTATION_VENDOR_ID = nullptr;
Attributes$Name* Attributes$Name::IMPLEMENTATION_URL = nullptr;
Attributes$Name* Attributes$Name::SPECIFICATION_TITLE = nullptr;
Attributes$Name* Attributes$Name::SPECIFICATION_VERSION = nullptr;
Attributes$Name* Attributes$Name::SPECIFICATION_VENDOR = nullptr;
Attributes$Name* Attributes$Name::MULTI_RELEASE = nullptr;

Attributes$Name* Attributes$Name::of($String* name) {
	$init(Attributes$Name);
	$var(Attributes$Name, n, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get(name)));
	if (n != nullptr) {
		return n;
	}
	return $new(Attributes$Name, name);
}

void Attributes$Name::init$($String* name) {
	this->hashCode$ = hash(name);
	$set(this, name, $nc(name)->intern());
}

int32_t Attributes$Name::hash($String* name) {
	$Objects::requireNonNull($of(name), "name"_s);
	int32_t len = $nc(name)->length();
	if (len > 70 || len == 0) {
		$throwNew($IllegalArgumentException, name);
	}
	int32_t h = 0;
	for (int32_t i = 0; i < len; ++i) {
		char16_t c = name->charAt(i);
		if (c >= u'a' && c <= u'z') {
			h = h * 31 + (c - 32);
		} else if (c >= u'A' && c <= u'Z' || c >= u'0' && c <= u'9' || c == u'_' || c == u'-') {
			h = h * 31 + c;
		} else {
			$throwNew($IllegalArgumentException, name);
		}
	}
	return h;
}

bool Attributes$Name::equals(Object$* o) {
	if ($equals(this, o)) {
		return true;
	}
	$var(Attributes$Name, other, nullptr);
	bool var$1 = $instanceOf(Attributes$Name, o);
	if (var$1) {
		$assign(other, $cast(Attributes$Name, o));
		var$1 = true;
	}
	bool var$0 = var$1;
	return var$0 && $nc($nc(other)->name)->equalsIgnoreCase(this->name);
}

int32_t Attributes$Name::hashCode() {
	return this->hashCode$;
}

$String* Attributes$Name::toString() {
	return this->name;
}

void Attributes$Name::addName($Map* names, Attributes$Name* name) {
	$init(Attributes$Name);
	$nc(names)->put($nc(name)->name, name);
}

void clinit$Attributes$Name($Class* class$) {
	$useLocalCurrentObjectStackCache();
	{
		$CDS::initializeFromArchive(Attributes$Name::class$);
		if (Attributes$Name::KNOWN_NAMES == nullptr) {
			$assignStatic(Attributes$Name::MANIFEST_VERSION, $new(Attributes$Name, "Manifest-Version"_s));
			$assignStatic(Attributes$Name::SIGNATURE_VERSION, $new(Attributes$Name, "Signature-Version"_s));
			$assignStatic(Attributes$Name::CONTENT_TYPE, $new(Attributes$Name, "Content-Type"_s));
			$assignStatic(Attributes$Name::CLASS_PATH, $new(Attributes$Name, "Class-Path"_s));
			$assignStatic(Attributes$Name::MAIN_CLASS, $new(Attributes$Name, "Main-Class"_s));
			$assignStatic(Attributes$Name::SEALED, $new(Attributes$Name, "Sealed"_s));
			$assignStatic(Attributes$Name::EXTENSION_LIST, $new(Attributes$Name, "Extension-List"_s));
			$assignStatic(Attributes$Name::EXTENSION_NAME, $new(Attributes$Name, "Extension-Name"_s));
			$assignStatic(Attributes$Name::EXTENSION_INSTALLATION, $new(Attributes$Name, "Extension-Installation"_s));
			$assignStatic(Attributes$Name::IMPLEMENTATION_TITLE, $new(Attributes$Name, "Implementation-Title"_s));
			$assignStatic(Attributes$Name::IMPLEMENTATION_VERSION, $new(Attributes$Name, "Implementation-Version"_s));
			$assignStatic(Attributes$Name::IMPLEMENTATION_VENDOR, $new(Attributes$Name, "Implementation-Vendor"_s));
			$assignStatic(Attributes$Name::IMPLEMENTATION_VENDOR_ID, $new(Attributes$Name, "Implementation-Vendor-Id"_s));
			$assignStatic(Attributes$Name::IMPLEMENTATION_URL, $new(Attributes$Name, "Implementation-URL"_s));
			$assignStatic(Attributes$Name::SPECIFICATION_TITLE, $new(Attributes$Name, "Specification-Title"_s));
			$assignStatic(Attributes$Name::SPECIFICATION_VERSION, $new(Attributes$Name, "Specification-Version"_s));
			$assignStatic(Attributes$Name::SPECIFICATION_VENDOR, $new(Attributes$Name, "Specification-Vendor"_s));
			$assignStatic(Attributes$Name::MULTI_RELEASE, $new(Attributes$Name, "Multi-Release"_s));
			$var($HashMap, names, $new($HashMap, 64));
			Attributes$Name::addName(names, Attributes$Name::MANIFEST_VERSION);
			Attributes$Name::addName(names, Attributes$Name::SIGNATURE_VERSION);
			Attributes$Name::addName(names, Attributes$Name::CONTENT_TYPE);
			Attributes$Name::addName(names, Attributes$Name::CLASS_PATH);
			Attributes$Name::addName(names, Attributes$Name::MAIN_CLASS);
			Attributes$Name::addName(names, Attributes$Name::SEALED);
			Attributes$Name::addName(names, Attributes$Name::EXTENSION_LIST);
			Attributes$Name::addName(names, Attributes$Name::EXTENSION_NAME);
			Attributes$Name::addName(names, Attributes$Name::EXTENSION_INSTALLATION);
			Attributes$Name::addName(names, Attributes$Name::IMPLEMENTATION_TITLE);
			Attributes$Name::addName(names, Attributes$Name::IMPLEMENTATION_VERSION);
			Attributes$Name::addName(names, Attributes$Name::IMPLEMENTATION_VENDOR);
			Attributes$Name::addName(names, Attributes$Name::IMPLEMENTATION_VENDOR_ID);
			Attributes$Name::addName(names, Attributes$Name::IMPLEMENTATION_URL);
			Attributes$Name::addName(names, Attributes$Name::SPECIFICATION_TITLE);
			Attributes$Name::addName(names, Attributes$Name::SPECIFICATION_VERSION);
			Attributes$Name::addName(names, Attributes$Name::SPECIFICATION_VENDOR);
			Attributes$Name::addName(names, Attributes$Name::MULTI_RELEASE);
			Attributes$Name::addName(names, $$new(Attributes$Name, "Add-Exports"_s));
			Attributes$Name::addName(names, $$new(Attributes$Name, "Add-Opens"_s));
			Attributes$Name::addName(names, $$new(Attributes$Name, "Launcher-Agent-Class"_s));
			Attributes$Name::addName(names, $$new(Attributes$Name, "JavaFX-Application-Class"_s));
			Attributes$Name::addName(names, $$new(Attributes$Name, "Name"_s));
			Attributes$Name::addName(names, $$new(Attributes$Name, "Created-By"_s));
			Attributes$Name::addName(names, $$new(Attributes$Name, "SHA1-Digest"_s));
			Attributes$Name::addName(names, $$new(Attributes$Name, "SHA-256-Digest"_s));
			$assignStatic(Attributes$Name::KNOWN_NAMES, $Map::copyOf(names));
		} else {
			$assignStatic(Attributes$Name::MANIFEST_VERSION, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Manifest-Version"_s)));
			$assignStatic(Attributes$Name::SIGNATURE_VERSION, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Signature-Version"_s)));
			$assignStatic(Attributes$Name::CONTENT_TYPE, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Content-Type"_s)));
			$assignStatic(Attributes$Name::CLASS_PATH, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Class-Path"_s)));
			$assignStatic(Attributes$Name::MAIN_CLASS, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Main-Class"_s)));
			$assignStatic(Attributes$Name::SEALED, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Sealed"_s)));
			$assignStatic(Attributes$Name::EXTENSION_LIST, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Extension-List"_s)));
			$assignStatic(Attributes$Name::EXTENSION_NAME, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Extension-Name"_s)));
			$assignStatic(Attributes$Name::EXTENSION_INSTALLATION, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Extension-Installation"_s)));
			$assignStatic(Attributes$Name::IMPLEMENTATION_TITLE, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Implementation-Title"_s)));
			$assignStatic(Attributes$Name::IMPLEMENTATION_VERSION, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Implementation-Version"_s)));
			$assignStatic(Attributes$Name::IMPLEMENTATION_VENDOR, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Implementation-Vendor"_s)));
			$assignStatic(Attributes$Name::IMPLEMENTATION_VENDOR_ID, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Implementation-Vendor-Id"_s)));
			$assignStatic(Attributes$Name::IMPLEMENTATION_URL, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Implementation-URL"_s)));
			$assignStatic(Attributes$Name::SPECIFICATION_TITLE, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Specification-Title"_s)));
			$assignStatic(Attributes$Name::SPECIFICATION_VERSION, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Specification-Version"_s)));
			$assignStatic(Attributes$Name::SPECIFICATION_VENDOR, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Specification-Vendor"_s)));
			$assignStatic(Attributes$Name::MULTI_RELEASE, $cast(Attributes$Name, $nc(Attributes$Name::KNOWN_NAMES)->get("Multi-Release"_s)));
		}
	}
}

Attributes$Name::Attributes$Name() {
}

$Class* Attributes$Name::load$($String* name, bool initialize) {
	$loadClass(Attributes$Name, name, initialize, &_Attributes$Name_ClassInfo_, clinit$Attributes$Name, allocate$Attributes$Name);
	return class$;
}

$Class* Attributes$Name::class$ = nullptr;

		} // jar
	} // util
} // java
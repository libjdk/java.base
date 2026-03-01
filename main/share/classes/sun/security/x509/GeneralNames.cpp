#include <sun/security/x509/GeneralNames.h>

#include <java/io/IOException.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <sun/security/util/DerInputStream.h>
#include <sun/security/util/DerOutputStream.h>
#include <sun/security/util/DerValue.h>
#include <sun/security/x509/GeneralName.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $DerInputStream = ::sun::security::util::DerInputStream;
using $DerOutputStream = ::sun::security::util::DerOutputStream;
using $DerValue = ::sun::security::util::DerValue;
using $GeneralName = ::sun::security::x509::GeneralName;

namespace sun {
	namespace security {
		namespace x509 {

$FieldInfo _GeneralNames_FieldInfo_[] = {
	{"names", "Ljava/util/List;", "Ljava/util/List<Lsun/security/x509/GeneralName;>;", $PRIVATE | $FINAL, $field(GeneralNames, names$)},
	{}
};

$MethodInfo _GeneralNames_MethodInfo_[] = {
	{"<init>", "(Lsun/security/util/DerValue;)V", nullptr, $PUBLIC, $method(GeneralNames, init$, void, $DerValue*), "java.io.IOException"},
	{"<init>", "()V", nullptr, $PUBLIC, $method(GeneralNames, init$, void)},
	{"add", "(Lsun/security/x509/GeneralName;)Lsun/security/x509/GeneralNames;", nullptr, $PUBLIC, $virtualMethod(GeneralNames, add, GeneralNames*, $GeneralName*)},
	{"encode", "(Lsun/security/util/DerOutputStream;)V", nullptr, $PUBLIC, $virtualMethod(GeneralNames, encode, void, $DerOutputStream*), "java.io.IOException"},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC, $virtualMethod(GeneralNames, equals, bool, Object$*)},
	{"get", "(I)Lsun/security/x509/GeneralName;", nullptr, $PUBLIC, $virtualMethod(GeneralNames, get, $GeneralName*, int32_t)},
	{"hashCode", "()I", nullptr, $PUBLIC, $virtualMethod(GeneralNames, hashCode, int32_t)},
	{"isEmpty", "()Z", nullptr, $PUBLIC, $virtualMethod(GeneralNames, isEmpty, bool)},
	{"iterator", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Lsun/security/x509/GeneralName;>;", $PUBLIC, $virtualMethod(GeneralNames, iterator, $Iterator*)},
	{"names", "()Ljava/util/List;", "()Ljava/util/List<Lsun/security/x509/GeneralName;>;", $PUBLIC, $virtualMethod(GeneralNames, names, $List*)},
	{"size", "()I", nullptr, $PUBLIC, $virtualMethod(GeneralNames, size, int32_t)},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(GeneralNames, toString, $String*)},
	{}
};

$ClassInfo _GeneralNames_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.security.x509.GeneralNames",
	"java.lang.Object",
	nullptr,
	_GeneralNames_FieldInfo_,
	_GeneralNames_MethodInfo_
};

$Object* allocate$GeneralNames($Class* clazz) {
	return $of($alloc(GeneralNames));
}

void GeneralNames::init$($DerValue* derVal) {
	$useLocalCurrentObjectStackCache();
	GeneralNames::init$();
	if ($nc(derVal)->tag != $DerValue::tag_Sequence) {
		$throwNew($IOException, "Invalid encoding for GeneralNames."_s);
	}
	if ($nc($nc(derVal)->data$)->available() == 0) {
		$throwNew($IOException, "No data available in passed DER encoded value."_s);
	}
	while ($nc($nc(derVal)->data$)->available() != 0) {
		$var($DerValue, encName, $nc(derVal->data$)->getDerValue());
		$var($GeneralName, name, $new($GeneralName, encName));
		add(name);
	}
}

void GeneralNames::init$() {
	$set(this, names$, $new($ArrayList));
}

GeneralNames* GeneralNames::add($GeneralName* name) {
	if (name == nullptr) {
		$throwNew($NullPointerException);
	}
	$nc(this->names$)->add(name);
	return this;
}

$GeneralName* GeneralNames::get(int32_t index) {
	return $cast($GeneralName, $nc(this->names$)->get(index));
}

bool GeneralNames::isEmpty() {
	return $nc(this->names$)->isEmpty();
}

int32_t GeneralNames::size() {
	return $nc(this->names$)->size();
}

$Iterator* GeneralNames::iterator() {
	return $nc(this->names$)->iterator();
}

$List* GeneralNames::names() {
	return this->names$;
}

void GeneralNames::encode($DerOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	if (isEmpty()) {
		return;
	}
	$var($DerOutputStream, temp, $new($DerOutputStream));
	{
		$var($Iterator, i$, $nc(this->names$)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($GeneralName, gn, $cast($GeneralName, i$->next()));
			{
				$nc(gn)->encode(temp);
			}
		}
	}
	$nc(out)->write($DerValue::tag_Sequence, temp);
}

bool GeneralNames::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(GeneralNames, obj) == false) {
		return false;
	}
	$var(GeneralNames, other, $cast(GeneralNames, obj));
	return $nc(this->names$)->equals($nc(other)->names$);
}

int32_t GeneralNames::hashCode() {
	return $nc(this->names$)->hashCode();
}

$String* GeneralNames::toString() {
	return $nc($of(this->names$))->toString();
}

GeneralNames::GeneralNames() {
}

$Class* GeneralNames::load$($String* name, bool initialize) {
	$loadClass(GeneralNames, name, initialize, &_GeneralNames_ClassInfo_, allocate$GeneralNames);
	return class$;
}

$Class* GeneralNames::class$ = nullptr;

		} // x509
	} // security
} // sun
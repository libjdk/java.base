#include <java/lang/Class$2.h>

#include <java/lang/reflect/Modifier.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Modifier = ::java::lang::reflect::Modifier;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

namespace java {
	namespace lang {

$FieldInfo _Class$2_FieldInfo_[] = {
	{"this$0", "Ljava/lang/Class;", nullptr, $FINAL | $SYNTHETIC, $field(Class$2, this$0)},
	{}
};

$MethodInfo _Class$2_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;)V", nullptr, 0, $method(Class$2, init$, void, $Class*)},
	{"run", "()[Ljava/lang/Class;", "()[Ljava/lang/Class<*>;", $PUBLIC, $virtualMethod(Class$2, run, $Object*)},
	{}
};

$EnclosingMethodInfo _Class$2_EnclosingMethodInfo_ = {
	"java.lang.Class",
	"getClasses",
	"()[Ljava/lang/Class;"
};

$InnerClassInfo _Class$2_InnerClassesInfo_[] = {
	{"java.lang.Class$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Class$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.Class$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_Class$2_FieldInfo_,
	_Class$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<[Ljava/lang/Class<*>;>;",
	&_Class$2_EnclosingMethodInfo_,
	_Class$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.Class"
};

$Object* allocate$Class$2($Class* clazz) {
	return $of($alloc(Class$2));
}

void Class$2::init$($Class* this$0) {
	$set(this, this$0, this$0);
}

$Object* Class$2::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($List, list, $new($ArrayList));
	$Class* currentClass = this->this$0;
	while (currentClass != nullptr) {
		{
			$var($ClassArray, arr$, currentClass->getDeclaredClasses());
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$Class* m = arr$->get(i$);
				{
					if ($Modifier::isPublic($nc(m)->getModifiers())) {
						list->add(m);
					}
				}
			}
		}
		currentClass = currentClass->getSuperclass();
	}
	return $of($fcast($ClassArray, list->toArray($$new($ClassArray, 0))));
}

Class$2::Class$2() {
}

$Class* Class$2::load$($String* name, bool initialize) {
	$loadClass(Class$2, name, initialize, &_Class$2_ClassInfo_, allocate$Class$2);
	return class$;
}

$Class* Class$2::class$ = nullptr;

	} // lang
} // java
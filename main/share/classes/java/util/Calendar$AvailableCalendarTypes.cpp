#include <java/util/Calendar$AvailableCalendarTypes.h>

#include <java/util/Calendar.h>
#include <java/util/Collections.h>
#include <java/util/HashSet.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef SET

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collections = ::java::util::Collections;
using $HashSet = ::java::util::HashSet;
using $Set = ::java::util::Set;

namespace java {
	namespace util {

$FieldInfo _Calendar$AvailableCalendarTypes_FieldInfo_[] = {
	{"SET", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Calendar$AvailableCalendarTypes, SET)},
	{}
};

$MethodInfo _Calendar$AvailableCalendarTypes_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(Calendar$AvailableCalendarTypes, init$, void)},
	{}
};

$InnerClassInfo _Calendar$AvailableCalendarTypes_InnerClassesInfo_[] = {
	{"java.util.Calendar$AvailableCalendarTypes", "java.util.Calendar", "AvailableCalendarTypes", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _Calendar$AvailableCalendarTypes_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.Calendar$AvailableCalendarTypes",
	"java.lang.Object",
	nullptr,
	_Calendar$AvailableCalendarTypes_FieldInfo_,
	_Calendar$AvailableCalendarTypes_MethodInfo_,
	nullptr,
	nullptr,
	_Calendar$AvailableCalendarTypes_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.Calendar"
};

$Object* allocate$Calendar$AvailableCalendarTypes($Class* clazz) {
	return $of($alloc(Calendar$AvailableCalendarTypes));
}

$Set* Calendar$AvailableCalendarTypes::SET = nullptr;

void Calendar$AvailableCalendarTypes::init$() {
}

void clinit$Calendar$AvailableCalendarTypes($Class* class$) {
	{
		$var($Set, set, $new($HashSet, 3));
		set->add("gregory"_s);
		set->add("buddhist"_s);
		set->add("japanese"_s);
		$assignStatic(Calendar$AvailableCalendarTypes::SET, $Collections::unmodifiableSet(set));
	}
}

Calendar$AvailableCalendarTypes::Calendar$AvailableCalendarTypes() {
}

$Class* Calendar$AvailableCalendarTypes::load$($String* name, bool initialize) {
	$loadClass(Calendar$AvailableCalendarTypes, name, initialize, &_Calendar$AvailableCalendarTypes_ClassInfo_, clinit$Calendar$AvailableCalendarTypes, allocate$Calendar$AvailableCalendarTypes);
	return class$;
}

$Class* Calendar$AvailableCalendarTypes::class$ = nullptr;

	} // util
} // java
#include <sun/text/resources/BreakIteratorResources.h>

#include <java/util/ResourceBundle.h>
#include <sun/text/resources/BreakIteratorInfo.h>
#include <sun/util/resources/BreakIteratorResourceBundle.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ResourceBundle = ::java::util::ResourceBundle;
using $BreakIteratorInfo = ::sun::text::resources::BreakIteratorInfo;
using $BreakIteratorResourceBundle = ::sun::util::resources::BreakIteratorResourceBundle;

namespace sun {
	namespace text {
		namespace resources {

$MethodInfo _BreakIteratorResources_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(BreakIteratorResources, init$, void)},
	{"getBreakIteratorInfo", "()Ljava/util/ResourceBundle;", nullptr, $PROTECTED, $virtualMethod(BreakIteratorResources, getBreakIteratorInfo, $ResourceBundle*)},
	{}
};

$ClassInfo _BreakIteratorResources_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.text.resources.BreakIteratorResources",
	"sun.util.resources.BreakIteratorResourceBundle",
	nullptr,
	nullptr,
	_BreakIteratorResources_MethodInfo_
};

$Object* allocate$BreakIteratorResources($Class* clazz) {
	return $of($alloc(BreakIteratorResources));
}

void BreakIteratorResources::init$() {
	$BreakIteratorResourceBundle::init$();
}

$ResourceBundle* BreakIteratorResources::getBreakIteratorInfo() {
	return $new($BreakIteratorInfo);
}

BreakIteratorResources::BreakIteratorResources() {
}

$Class* BreakIteratorResources::load$($String* name, bool initialize) {
	$loadClass(BreakIteratorResources, name, initialize, &_BreakIteratorResources_ClassInfo_, allocate$BreakIteratorResources);
	return class$;
}

$Class* BreakIteratorResources::class$ = nullptr;

		} // resources
	} // text
} // sun
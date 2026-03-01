#ifndef _jdk_internal_reflect_MethodAccessor_h_
#define _jdk_internal_reflect_MethodAccessor_h_
//$ interface jdk.internal.reflect.MethodAccessor
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace jdk {
	namespace internal {
		namespace reflect {

class $import MethodAccessor : public ::java::lang::Object {
	$interface(MethodAccessor, $PRELOAD | $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $Object* invoke(Object$* obj, $ObjectArray* args) {return nullptr;}
	virtual $Object* invokeSpecial(Object$* obj, $ObjectArray* args) {return nullptr;}
	virtual $Value invokev(Object$* obj, $Value* argv) {return nullptr;}
};

		} // reflect
	} // internal
} // jdk

#endif // _jdk_internal_reflect_MethodAccessor_h_
#ifndef _java_lang_FdLibm_h_
#define _java_lang_FdLibm_h_
//$ class java.lang.FdLibm
//$ extends java.lang.Object

#include <java/lang/Double.h>

#pragma push_macro("INFINITY")
#undef INFINITY

namespace java {
	namespace lang {

class FdLibm : public ::java::lang::Object {
	$class(FdLibm, 0, ::java::lang::Object)
public:
	FdLibm();
	void init$();
	static int32_t __HI(double x);
	static double __HI(double x, int32_t high);
	static int32_t __LO(double x);
	static double __LO(double x, int32_t low);
	static double INFINITY;
};

	} // lang
} // java

#pragma pop_macro("INFINITY")

#endif // _java_lang_FdLibm_h_
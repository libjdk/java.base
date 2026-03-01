#ifndef _Person_h_
#define _Person_h_
//$ class Person
//$ extends java.lang.Record

#include <java/lang/Record.h>

class Person : public ::java::lang::Record {
	$class(Person, $NO_CLASS_INIT, ::java::lang::Record)
public:
	Person();
	void init$($String* name, int32_t age, double d);
	virtual int32_t age();
	virtual double d();
	virtual bool equals(Object$* o) override;
	virtual int32_t hashCode() override;
	virtual $String* name();
	virtual $String* toString() override;
	$String* name$ = nullptr;
	int32_t age$ = 0;
	double d$ = 0.0;
};

#endif // _Person_h_
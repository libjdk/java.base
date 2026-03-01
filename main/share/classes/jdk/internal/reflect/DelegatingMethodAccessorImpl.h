#ifndef _jdk_internal_reflect_DelegatingMethodAccessorImpl_h_
#define _jdk_internal_reflect_DelegatingMethodAccessorImpl_h_
//$ class jdk.internal.reflect.DelegatingMethodAccessorImpl
//$ extends jdk.internal.reflect.MethodAccessorImpl

#include <java/lang/Array.h>
#include <jdk/internal/reflect/MethodAccessorImpl.h>

namespace jdk {
	namespace internal {
		namespace reflect {

class DelegatingMethodAccessorImpl : public ::jdk::internal::reflect::MethodAccessorImpl {
	$class(DelegatingMethodAccessorImpl, $PRELOAD | $NO_CLASS_INIT, ::jdk::internal::reflect::MethodAccessorImpl)
public:
	DelegatingMethodAccessorImpl();
	void init$(::jdk::internal::reflect::MethodAccessorImpl* delegate);
	virtual $Object* invoke(Object$* obj, $ObjectArray* args) override;
	virtual void setDelegate(::jdk::internal::reflect::MethodAccessorImpl* delegate);
	::jdk::internal::reflect::MethodAccessorImpl* delegate = nullptr;
	virtual $Object* invokeSpecial(Object$* obj, $ObjectArray* args) override;
	virtual $Value invokev(Object$* obj, $Value* argv) override;
};

		} // reflect
	} // internal
} // jdk

#endif // _jdk_internal_reflect_DelegatingMethodAccessorImpl_h_
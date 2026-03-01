#ifndef _jdk_internal_reflect_NativeMethodAccessorImpl_h_
#define _jdk_internal_reflect_NativeMethodAccessorImpl_h_
//$ class jdk.internal.reflect.NativeMethodAccessorImpl
//$ extends jdk.internal.reflect.MethodAccessorImpl

#include <java/lang/Array.h>
#include <jdk/internal/reflect/MethodAccessorImpl.h>

#pragma push_macro("GENERATED_OFFSET")
#undef GENERATED_OFFSET
#pragma push_macro("U")
#undef U

namespace java {
	namespace lang {
		namespace reflect {
			class Method;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace misc {
			class Unsafe;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace reflect {
			class DelegatingMethodAccessorImpl;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace reflect {

class NativeMethodAccessorImpl : public ::jdk::internal::reflect::MethodAccessorImpl {
	$class(NativeMethodAccessorImpl, $PRELOAD, ::jdk::internal::reflect::MethodAccessorImpl)
public:
	NativeMethodAccessorImpl();
	void init$(::java::lang::reflect::Method* method);
	virtual $Object* invoke(Object$* obj, $ObjectArray* args) override;
	static $Object* invoke0(::java::lang::reflect::Method* m, Object$* obj, $ObjectArray* args);
	virtual void setParent(::jdk::internal::reflect::DelegatingMethodAccessorImpl* parent);
	static ::jdk::internal::misc::Unsafe* U;
	static int64_t GENERATED_OFFSET;
	::java::lang::reflect::Method* method = nullptr;
	::jdk::internal::reflect::DelegatingMethodAccessorImpl* parent = nullptr;
	int32_t numInvocations = 0;
	$volatile(int32_t) generated = 0;
	virtual $Object* invokeSpecial(Object$* obj, $ObjectArray* args) override;
	virtual $Value invokev(Object$* obj, $Value* argv) override;
};

		} // reflect
	} // internal
} // jdk

#pragma pop_macro("GENERATED_OFFSET")
#pragma pop_macro("U")

#endif // _jdk_internal_reflect_NativeMethodAccessorImpl_h_
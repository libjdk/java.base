#include <jdk/internal/jimage/decompressor/SignatureParser$ParseResult.h>

#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jdk/internal/jimage/decompressor/SignatureParser.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;

namespace jdk {
	namespace internal {
		namespace jimage {
			namespace decompressor {

$FieldInfo _SignatureParser$ParseResult_FieldInfo_[] = {
	{"types", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $FINAL, $field(SignatureParser$ParseResult, types)},
	{"formatted", "Ljava/lang/String;", nullptr, $PUBLIC, $field(SignatureParser$ParseResult, formatted)},
	{}
};

$MethodInfo _SignatureParser$ParseResult_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SignatureParser$ParseResult, init$, void)},
	{}
};

$InnerClassInfo _SignatureParser$ParseResult_InnerClassesInfo_[] = {
	{"jdk.internal.jimage.decompressor.SignatureParser$ParseResult", "jdk.internal.jimage.decompressor.SignatureParser", "ParseResult", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _SignatureParser$ParseResult_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.jimage.decompressor.SignatureParser$ParseResult",
	"java.lang.Object",
	nullptr,
	_SignatureParser$ParseResult_FieldInfo_,
	_SignatureParser$ParseResult_MethodInfo_,
	nullptr,
	nullptr,
	_SignatureParser$ParseResult_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.jimage.decompressor.SignatureParser"
};

$Object* allocate$SignatureParser$ParseResult($Class* clazz) {
	return $of($alloc(SignatureParser$ParseResult));
}

void SignatureParser$ParseResult::init$() {
	$set(this, types, $new($ArrayList));
}

SignatureParser$ParseResult::SignatureParser$ParseResult() {
}

$Class* SignatureParser$ParseResult::load$($String* name, bool initialize) {
	$loadClass(SignatureParser$ParseResult, name, initialize, &_SignatureParser$ParseResult_ClassInfo_, allocate$SignatureParser$ParseResult);
	return class$;
}

$Class* SignatureParser$ParseResult::class$ = nullptr;

			} // decompressor
		} // jimage
	} // internal
} // jdk
#include <jdk/internal/reflect/Label.h>

#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jdk/internal/reflect/ClassFileAssembler.h>
#include <jdk/internal/reflect/Label$PatchInfo.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $ClassFileAssembler = ::jdk::internal::reflect::ClassFileAssembler;
using $Label$PatchInfo = ::jdk::internal::reflect::Label$PatchInfo;

namespace jdk {
	namespace internal {
		namespace reflect {

$FieldInfo _Label_FieldInfo_[] = {
	{"patches", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/reflect/Label$PatchInfo;>;", $PRIVATE | $FINAL, $field(Label, patches)},
	{}
};

$MethodInfo _Label_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Label, init$, void)},
	{"add", "(Ljdk/internal/reflect/ClassFileAssembler;SSI)V", nullptr, 0, $virtualMethod(Label, add, void, $ClassFileAssembler*, int16_t, int16_t, int32_t)},
	{"bind", "()V", nullptr, $PUBLIC, $virtualMethod(Label, bind, void)},
	{}
};

$InnerClassInfo _Label_InnerClassesInfo_[] = {
	{"jdk.internal.reflect.Label$PatchInfo", "jdk.internal.reflect.Label", "PatchInfo", $STATIC},
	{}
};

$ClassInfo _Label_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.reflect.Label",
	"java.lang.Object",
	nullptr,
	_Label_FieldInfo_,
	_Label_MethodInfo_,
	nullptr,
	nullptr,
	_Label_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.reflect.Label$PatchInfo"
};

$Object* allocate$Label($Class* clazz) {
	return $of($alloc(Label));
}

void Label::init$() {
	$set(this, patches, $new($ArrayList));
}

void Label::add($ClassFileAssembler* asm$, int16_t instrBCI, int16_t patchBCI, int32_t stackDepth) {
	$nc(this->patches)->add($$new($Label$PatchInfo, asm$, instrBCI, patchBCI, stackDepth));
}

void Label::bind() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(this->patches)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Label$PatchInfo, patch, $cast($Label$PatchInfo, i$->next()));
			{
				int16_t curBCI = $nc($nc(patch)->asm$)->getLength();
				int16_t offset = (int16_t)(curBCI - patch->instrBCI);
				$nc(patch->asm$)->emitShort(patch->patchBCI, offset);
				$nc(patch->asm$)->setStack(patch->stackDepth);
			}
		}
	}
}

Label::Label() {
}

$Class* Label::load$($String* name, bool initialize) {
	$loadClass(Label, name, initialize, &_Label_ClassInfo_, allocate$Label);
	return class$;
}

$Class* Label::class$ = nullptr;

		} // reflect
	} // internal
} // jdk
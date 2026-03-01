#include <java/lang/invoke/ClassSpecializer$Factory$1Var.h>

#include <java/lang/AssertionError.h>
#include <java/lang/invoke/ClassSpecializer$Factory.h>
#include <java/lang/invoke/ClassSpecializer.h>
#include <java/lang/invoke/LambdaForm$BasicType.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jcpp.h>

#undef TYPE
#undef V_TYPE

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $ClassSpecializer = ::java::lang::invoke::ClassSpecializer;
using $ClassSpecializer$Factory = ::java::lang::invoke::ClassSpecializer$Factory;
using $LambdaForm$BasicType = ::java::lang::invoke::LambdaForm$BasicType;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;

namespace java {
	namespace lang {
		namespace invoke {

$FieldInfo _ClassSpecializer$Factory$1Var_FieldInfo_[] = {
	{"this$1", "Ljava/lang/invoke/ClassSpecializer$Factory;", nullptr, $FINAL | $SYNTHETIC, $field(ClassSpecializer$Factory$1Var, this$1)},
	{"val$className", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(ClassSpecializer$Factory$1Var, val$className)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ClassSpecializer$Factory$1Var, $assertionsDisabled)},
	{"index", "I", nullptr, $FINAL, $field(ClassSpecializer$Factory$1Var, index)},
	{"name", "Ljava/lang/String;", nullptr, $FINAL, $field(ClassSpecializer$Factory$1Var, name)},
	{"type", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $FINAL, $field(ClassSpecializer$Factory$1Var, type)},
	{"desc", "Ljava/lang/String;", nullptr, $FINAL, $field(ClassSpecializer$Factory$1Var, desc)},
	{"basicType", "Ljava/lang/invoke/LambdaForm$BasicType;", nullptr, $FINAL, $field(ClassSpecializer$Factory$1Var, basicType)},
	{"slotIndex", "I", nullptr, $FINAL, $field(ClassSpecializer$Factory$1Var, slotIndex)},
	{}
};

$MethodInfo _ClassSpecializer$Factory$1Var_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/invoke/ClassSpecializer$Factory;IILjava/lang/String;)V", "(II)V", 0, $method(ClassSpecializer$Factory$1Var, init$, void, $ClassSpecializer$Factory*, int32_t, int32_t, $String*)},
	{"<init>", "(Ljava/lang/invoke/ClassSpecializer$Factory;Ljava/lang/String;Ljava/lang/Class;Ljava/lang/invoke/ClassSpecializer$Factory$1Var;Ljava/lang/String;)V", "(Ljava/lang/String;Ljava/lang/Class<*>;Ljava/lang/invoke/ClassSpecializer$Factory$1Var;)V", 0, $method(ClassSpecializer$Factory$1Var, init$, void, $ClassSpecializer$Factory*, $String*, $Class*, ClassSpecializer$Factory$1Var*, $String*)},
	{"emitFieldInsn", "(ILjdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, $PUBLIC, $virtualMethod(ClassSpecializer$Factory$1Var, emitFieldInsn, void, int32_t, $MethodVisitor*)},
	{"emitVarInstruction", "(ILjdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, 0, $virtualMethod(ClassSpecializer$Factory$1Var, emitVarInstruction, void, int32_t, $MethodVisitor*)},
	{"fromTypes", "(Ljava/util/List;)Ljava/util/List;", "<X:Ljava/lang/Object;>(Ljava/util/List<TX;>;)Ljava/util/List<Ljava/lang/invoke/ClassSpecializer$Factory$1Var;>;", 0, $virtualMethod(ClassSpecializer$Factory$1Var, fromTypes, $List*, $List*)},
	{"isInHeap", "()Z", nullptr, 0, $virtualMethod(ClassSpecializer$Factory$1Var, isInHeap, bool)},
	{"lastOf", "(Ljava/util/List;)Ljava/lang/invoke/ClassSpecializer$Factory$1Var;", "(Ljava/util/List<Ljava/lang/invoke/ClassSpecializer$Factory$1Var;>;)Ljava/lang/invoke/ClassSpecializer$Factory$1Var;", 0, $virtualMethod(ClassSpecializer$Factory$1Var, lastOf, ClassSpecializer$Factory$1Var*, $List*)},
	{"nextIndex", "()I", nullptr, 0, $virtualMethod(ClassSpecializer$Factory$1Var, nextIndex, int32_t)},
	{"nextSlotIndex", "()I", nullptr, 0, $virtualMethod(ClassSpecializer$Factory$1Var, nextSlotIndex, int32_t)},
	{"slotSize", "()I", nullptr, 0, $virtualMethod(ClassSpecializer$Factory$1Var, slotSize, int32_t)},
	{}
};

$EnclosingMethodInfo _ClassSpecializer$Factory$1Var_EnclosingMethodInfo_ = {
	"java.lang.invoke.ClassSpecializer$Factory",
	"generateConcreteSpeciesCodeFile",
	"(Ljava/lang/String;Ljava/lang/invoke/ClassSpecializer$SpeciesData;)[B"
};

$InnerClassInfo _ClassSpecializer$Factory$1Var_InnerClassesInfo_[] = {
	{"java.lang.invoke.ClassSpecializer$Factory", "java.lang.invoke.ClassSpecializer", "Factory", $PUBLIC},
	{"java.lang.invoke.ClassSpecializer$Factory$1Var", nullptr, "Var", 0},
	{"java.lang.invoke.ClassSpecializer$SpeciesData", "java.lang.invoke.ClassSpecializer", "SpeciesData", $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _ClassSpecializer$Factory$1Var_ClassInfo_ = {
	$ACC_SUPER,
	"java.lang.invoke.ClassSpecializer$Factory$1Var",
	"java.lang.Object",
	nullptr,
	_ClassSpecializer$Factory$1Var_FieldInfo_,
	_ClassSpecializer$Factory$1Var_MethodInfo_,
	nullptr,
	&_ClassSpecializer$Factory$1Var_EnclosingMethodInfo_,
	_ClassSpecializer$Factory$1Var_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.invoke.ClassSpecializer"
};

$Object* allocate$ClassSpecializer$Factory$1Var($Class* clazz) {
	return $of($alloc(ClassSpecializer$Factory$1Var));
}

bool ClassSpecializer$Factory$1Var::$assertionsDisabled = false;

void ClassSpecializer$Factory$1Var::init$($ClassSpecializer$Factory* this$1, int32_t index, int32_t slotIndex, $String* val$className) {
	$set(this, this$1, this$1);
	$set(this, val$className, val$className);
	this->index = index;
	this->slotIndex = slotIndex;
	$set(this, name, nullptr);
	$set(this, type, nullptr);
	$set(this, desc, nullptr);
	$init($LambdaForm$BasicType);
	$set(this, basicType, $LambdaForm$BasicType::V_TYPE);
}

void ClassSpecializer$Factory$1Var::init$($ClassSpecializer$Factory* this$1, $String* name$renamed, $Class* type, ClassSpecializer$Factory$1Var* prev, $String* val$className) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	$set(this, this$1, this$1);
	$set(this, val$className, val$className);
	int32_t slotIndex = $nc(prev)->nextSlotIndex();
	int32_t index = prev->nextIndex();
	if (name == nullptr) {
		$assign(name, "x"_s);
	}
	if ($nc(name)->endsWith("#"_s)) {
		$assign(name, $str({$(name->substring(0, name->length() - 1)), $$str(index)}));
	}
	$init($Void);
	if (!ClassSpecializer$Factory$1Var::$assertionsDisabled && !(!$nc($of(type))->equals($Void::TYPE))) {
		$throwNew($AssertionError);
	}
	$var($String, desc, $ClassSpecializer::classSig(type));
	$LambdaForm$BasicType* basicType = $LambdaForm$BasicType::basicType(type);
	this->index = index;
	$set(this, name, name);
	$set(this, type, type);
	$set(this, desc, desc);
	$set(this, basicType, basicType);
	this->slotIndex = slotIndex;
}

ClassSpecializer$Factory$1Var* ClassSpecializer$Factory$1Var::lastOf($List* vars) {
	int32_t n = $nc(vars)->size();
	return (n == 0 ? this : $cast(ClassSpecializer$Factory$1Var, vars->get(n - 1)));
}

$List* ClassSpecializer$Factory$1Var::fromTypes($List* types) {
	$useLocalCurrentObjectStackCache();
	$var(ClassSpecializer$Factory$1Var, prev, this);
	$var($ArrayList, result, $new($ArrayList, $nc(types)->size()));
	int32_t i = 0;
	{
		$var($Iterator, i$, $nc(types)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, x, i$->next());
			{
				$var($String, vn, this->name);
				$Class* vt = nullptr;
				if ($instanceOf($Class, x)) {
					vt = $cast($Class, x);
					if (!ClassSpecializer$Factory$1Var::$assertionsDisabled && !(($assign(vn, $str({vn, "_"_s, $$str((i++))}))) != nullptr)) {
						$throwNew($AssertionError);
					}
				} else {
					$var(ClassSpecializer$Factory$1Var, v, $cast(ClassSpecializer$Factory$1Var, x));
					$assign(vn, $nc(v)->name);
					vt = v->type;
				}
				$assign(prev, $new(ClassSpecializer$Factory$1Var, this->this$1, vn, vt, prev, this->val$className));
				result->add(prev);
			}
		}
	}
	return result;
}

int32_t ClassSpecializer$Factory$1Var::slotSize() {
	return this->basicType->basicTypeSlots();
}

int32_t ClassSpecializer$Factory$1Var::nextIndex() {
	return this->index + (slotSize() == 0 ? 0 : 1);
}

int32_t ClassSpecializer$Factory$1Var::nextSlotIndex() {
	return this->slotIndex >= 0 ? this->slotIndex + slotSize() : this->slotIndex;
}

bool ClassSpecializer$Factory$1Var::isInHeap() {
	return this->slotIndex < 0;
}

void ClassSpecializer$Factory$1Var::emitVarInstruction(int32_t asmop, $MethodVisitor* mv) {
	$useLocalCurrentObjectStackCache();
	if (asmop == 25) {
		asmop = this->this$1->typeLoadOp(this->basicType->basicTypeChar());
	} else {
		$throwNew($AssertionError, $of($$str({"bad op="_s, $$str(asmop), " for desc="_s, this->desc})));
	}
	$nc(mv)->visitVarInsn(asmop, this->slotIndex);
}

void ClassSpecializer$Factory$1Var::emitFieldInsn(int32_t asmop, $MethodVisitor* mv) {
	$nc(mv)->visitFieldInsn(asmop, this->val$className, this->name, this->desc);
}

void clinit$ClassSpecializer$Factory$1Var($Class* class$) {
	$load($ClassSpecializer);
	ClassSpecializer$Factory$1Var::$assertionsDisabled = !$ClassSpecializer::class$->desiredAssertionStatus();
}

ClassSpecializer$Factory$1Var::ClassSpecializer$Factory$1Var() {
}

$Class* ClassSpecializer$Factory$1Var::load$($String* name, bool initialize) {
	$loadClass(ClassSpecializer$Factory$1Var, name, initialize, &_ClassSpecializer$Factory$1Var_ClassInfo_, clinit$ClassSpecializer$Factory$1Var, allocate$ClassSpecializer$Factory$1Var);
	return class$;
}

$Class* ClassSpecializer$Factory$1Var::class$ = nullptr;

		} // invoke
	} // lang
} // java
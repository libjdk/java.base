#include <java/lang/invoke/ClassSpecializer$Factory.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NoSuchFieldException.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/TypeNotPresentException.h>
#include <java/lang/invoke/ClassSpecializer$Factory$1.h>
#include <java/lang/invoke/ClassSpecializer$Factory$1Var.h>
#include <java/lang/invoke/ClassSpecializer$SpeciesData.h>
#include <java/lang/invoke/ClassSpecializer.h>
#include <java/lang/invoke/InvokerBytecodeGenerator.h>
#include <java/lang/invoke/LambdaForm$BasicType.h>
#include <java/lang/invoke/LambdaForm$NamedFunction.h>
#include <java/lang/invoke/MemberName.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandleNatives.h>
#include <java/lang/invoke/MethodHandleStatics.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jdk/internal/access/JavaLangAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/org/objectweb/asm/AnnotationVisitor.h>
#include <jdk/internal/org/objectweb/asm/ClassWriter.h>
#include <jdk/internal/org/objectweb/asm/FieldVisitor.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jcpp.h>

#undef ACC_PPP
#undef AFTER_THIS
#undef COMPUTE_FRAMES
#undef COMPUTE_MAXS
#undef E_THROWABLE
#undef IMPL_LOOKUP
#undef IN_HEAP
#undef L_TYPE
#undef NOT_ACC_PUBLIC
#undef NO_THIS
#undef SPECIES_DATA
#undef SPECIES_DATA_MODS
#undef SPECIES_DATA_NAME
#undef SPECIES_DATA_SIG
#undef TMODS
#undef TNAME
#undef TRANSFORM_MODS
#undef TRANSFORM_NAMES
#undef TRANSFORM_TYPES
#undef TTYPE
#undef UNSAFE

using $IntegerArray = $Array<::java::lang::Integer>;
using $LambdaForm$NamedFunctionArray = $Array<::java::lang::invoke::LambdaForm$NamedFunction>;
using $MethodHandleArray = $Array<::java::lang::invoke::MethodHandle>;
using $MethodTypeArray = $Array<::java::lang::invoke::MethodType>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchFieldException = ::java::lang::NoSuchFieldException;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $TypeNotPresentException = ::java::lang::TypeNotPresentException;
using $ClassSpecializer = ::java::lang::invoke::ClassSpecializer;
using $ClassSpecializer$Factory$1 = ::java::lang::invoke::ClassSpecializer$Factory$1;
using $ClassSpecializer$Factory$1Var = ::java::lang::invoke::ClassSpecializer$Factory$1Var;
using $ClassSpecializer$SpeciesData = ::java::lang::invoke::ClassSpecializer$SpeciesData;
using $InvokerBytecodeGenerator = ::java::lang::invoke::InvokerBytecodeGenerator;
using $LambdaForm$BasicType = ::java::lang::invoke::LambdaForm$BasicType;
using $LambdaForm$NamedFunction = ::java::lang::invoke::LambdaForm$NamedFunction;
using $MemberName = ::java::lang::invoke::MemberName;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandleNatives = ::java::lang::invoke::MethodHandleNatives;
using $MethodHandleStatics = ::java::lang::invoke::MethodHandleStatics;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $JavaLangAccess = ::jdk::internal::access::JavaLangAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $ClassWriter = ::jdk::internal::org::objectweb::asm$::ClassWriter;
using $FieldVisitor = ::jdk::internal::org::objectweb::asm$::FieldVisitor;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;

namespace java {
	namespace lang {
		namespace invoke {

$FieldInfo _ClassSpecializer$Factory_FieldInfo_[] = {
	{"this$0", "Ljava/lang/invoke/ClassSpecializer;", nullptr, $FINAL | $SYNTHETIC, $field(ClassSpecializer$Factory, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ClassSpecializer$Factory, $assertionsDisabled)},
	{"SPECIES_DATA", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ClassSpecializer$Factory, SPECIES_DATA)},
	{"SPECIES_DATA_SIG", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ClassSpecializer$Factory, SPECIES_DATA_SIG)},
	{"SPECIES_DATA_NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ClassSpecializer$Factory, SPECIES_DATA_NAME)},
	{"SPECIES_DATA_MODS", "I", nullptr, $PRIVATE | $FINAL, $field(ClassSpecializer$Factory, SPECIES_DATA_MODS)},
	{"TRANSFORM_NAMES", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(ClassSpecializer$Factory, TRANSFORM_NAMES)},
	{"TRANSFORM_TYPES", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/invoke/MethodType;>;", $PRIVATE | $FINAL, $field(ClassSpecializer$Factory, TRANSFORM_TYPES)},
	{"TRANSFORM_MODS", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Integer;>;", $PRIVATE | $FINAL, $field(ClassSpecializer$Factory, TRANSFORM_MODS)},
	{"ACC_PPP", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ClassSpecializer$Factory, ACC_PPP)},
	{}
};

$MethodInfo _ClassSpecializer$Factory_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/invoke/ClassSpecializer;)V", nullptr, 0, $method(ClassSpecializer$Factory, init$, void, $ClassSpecializer*)},
	{"chooseFieldName", "(Ljava/lang/Class;I)Ljava/lang/String;", "(Ljava/lang/Class<*>;I)Ljava/lang/String;", $PROTECTED, $virtualMethod(ClassSpecializer$Factory, chooseFieldName, $String*, $Class*, int32_t)},
	{"emitIntConstant", "(ILjdk/internal/org/objectweb/asm/MethodVisitor;)V", nullptr, $PRIVATE, $method(ClassSpecializer$Factory, emitIntConstant, void, int32_t, $MethodVisitor*)},
	{"findFactories", "(Ljava/lang/Class;Ljava/util/List;)Ljava/util/List;", "(Ljava/lang/Class<+TT;>;Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;", $PRIVATE, $method(ClassSpecializer$Factory, findFactories, $List*, $Class*, $List*)},
	{"findFactory", "(Ljava/lang/Class;Ljava/util/List;)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<+TT;>;Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/lang/invoke/MethodHandle;", 0, $virtualMethod(ClassSpecializer$Factory, findFactory, $MethodHandle*, $Class*, $List*)},
	{"findGetter", "(Ljava/lang/Class;Ljava/util/List;I)Ljava/lang/invoke/MethodHandle;", "(Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/Class<*>;>;I)Ljava/lang/invoke/MethodHandle;", $PRIVATE, $method(ClassSpecializer$Factory, findGetter, $MethodHandle*, $Class*, $List*, int32_t)},
	{"findGetters", "(Ljava/lang/Class;Ljava/util/List;)Ljava/util/List;", "(Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/Class<*>;>;)Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;", $PRIVATE, $method(ClassSpecializer$Factory, findGetters, $List*, $Class*, $List*)},
	{"generateConcreteSpeciesCode", "(Ljava/lang/String;Ljava/lang/invoke/ClassSpecializer$SpeciesData;)Ljava/lang/Class;", "(Ljava/lang/String;Ljava/lang/invoke/ClassSpecializer<TT;TK;TS;>.SpeciesData;)Ljava/lang/Class<+TT;>;", 0, $virtualMethod(ClassSpecializer$Factory, generateConcreteSpeciesCode, $Class*, $String*, $ClassSpecializer$SpeciesData*)},
	{"generateConcreteSpeciesCodeFile", "(Ljava/lang/String;Ljava/lang/invoke/ClassSpecializer$SpeciesData;)[B", "(Ljava/lang/String;Ljava/lang/invoke/ClassSpecializer<TT;TK;TS;>.SpeciesData;)[B", 0, $virtualMethod(ClassSpecializer$Factory, generateConcreteSpeciesCodeFile, $bytes*, $String*, $ClassSpecializer$SpeciesData*)},
	{"linkCodeToSpeciesData", "(Ljava/lang/Class;Ljava/lang/invoke/ClassSpecializer$SpeciesData;Z)V", "(Ljava/lang/Class<+TT;>;Ljava/lang/invoke/ClassSpecializer<TT;TK;TS;>.SpeciesData;Z)V", $PROTECTED, $virtualMethod(ClassSpecializer$Factory, linkCodeToSpeciesData, void, $Class*, $ClassSpecializer$SpeciesData*, bool)},
	{"linkSpeciesDataToCode", "(Ljava/lang/invoke/ClassSpecializer$SpeciesData;Ljava/lang/Class;)V", "(Ljava/lang/invoke/ClassSpecializer<TT;TK;TS;>.SpeciesData;Ljava/lang/Class<+TT;>;)V", $PROTECTED, $virtualMethod(ClassSpecializer$Factory, linkSpeciesDataToCode, void, $ClassSpecializer$SpeciesData*, $Class*)},
	{"loadSpecies", "(Ljava/lang/invoke/ClassSpecializer$SpeciesData;)Ljava/lang/invoke/ClassSpecializer$SpeciesData;", "(TS;)TS;", 0, $virtualMethod(ClassSpecializer$Factory, loadSpecies, $ClassSpecializer$SpeciesData*, $ClassSpecializer$SpeciesData*)},
	{"loadSpeciesDataFromCode", "(Ljava/lang/Class;)Ljava/lang/invoke/ClassSpecializer$SpeciesData;", "(Ljava/lang/Class<+TT;>;)TS;", $PROTECTED, $virtualMethod(ClassSpecializer$Factory, loadSpeciesDataFromCode, $ClassSpecializer$SpeciesData*, $Class*)},
	{"makeNominalGetters", "(Ljava/util/List;Ljava/util/List;)Ljava/util/List;", "(Ljava/util/List<Ljava/lang/Class<*>;>;Ljava/util/List<Ljava/lang/invoke/MethodHandle;>;)Ljava/util/List<Ljava/lang/invoke/LambdaForm$NamedFunction;>;", 0, $virtualMethod(ClassSpecializer$Factory, makeNominalGetters, $List*, $List*, $List*)},
	{"readSpeciesDataFromCode", "(Ljava/lang/Class;)Ljava/lang/invoke/ClassSpecializer$SpeciesData;", "(Ljava/lang/Class<+TT;>;)TS;", $PRIVATE, $method(ClassSpecializer$Factory, readSpeciesDataFromCode, $ClassSpecializer$SpeciesData*, $Class*)},
	{"reflectSDField", "(Ljava/lang/Class;)Ljava/lang/reflect/Field;", "(Ljava/lang/Class<+TT;>;)Ljava/lang/reflect/Field;", $PRIVATE, $method(ClassSpecializer$Factory, reflectSDField, $Field*, $Class*)},
	{"typeLoadOp", "(C)I", nullptr, $PRIVATE, $method(ClassSpecializer$Factory, typeLoadOp, int32_t, char16_t)},
	{}
};

$InnerClassInfo _ClassSpecializer$Factory_InnerClassesInfo_[] = {
	{"java.lang.invoke.ClassSpecializer$Factory", "java.lang.invoke.ClassSpecializer", "Factory", $PUBLIC},
	{"java.lang.invoke.ClassSpecializer$Factory$1Var", nullptr, "Var", 0},
	{"java.lang.invoke.ClassSpecializer$Factory$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ClassSpecializer$Factory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.invoke.ClassSpecializer$Factory",
	"java.lang.Object",
	nullptr,
	_ClassSpecializer$Factory_FieldInfo_,
	_ClassSpecializer$Factory_MethodInfo_,
	nullptr,
	nullptr,
	_ClassSpecializer$Factory_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.invoke.ClassSpecializer"
};

$Object* allocate$ClassSpecializer$Factory($Class* clazz) {
	return $of($alloc(ClassSpecializer$Factory));
}

bool ClassSpecializer$Factory::$assertionsDisabled = false;

void ClassSpecializer$Factory::init$($ClassSpecializer* this$0) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$0, this$0);
	$set(this, SPECIES_DATA, $ClassSpecializer::classBCName(this->this$0->metaType$));
	$set(this, SPECIES_DATA_SIG, $ClassSpecializer::classSig(this->SPECIES_DATA));
	$set(this, SPECIES_DATA_NAME, $nc(this->this$0->sdAccessor)->getName());
	this->SPECIES_DATA_MODS = $nc(this->this$0->sdAccessor)->getModifiers();
	{
		$var($List, tns, $new($ArrayList));
		$var($List, tts, $new($ArrayList));
		$var($List, tms, $new($ArrayList));
		for (int32_t i = 0; i < $nc(this->this$0->transformMethods$)->size(); ++i) {
			$var($MemberName, tm, $cast($MemberName, $nc(this->this$0->transformMethods$)->get(i)));
			tns->add($($nc(tm)->getName()));
			$var($MethodType, tt, $nc(tm)->getMethodType());
			tts->add(tt);
			tms->add($($Integer::valueOf(tm->getModifiers())));
		}
		$set(this, TRANSFORM_NAMES, $List::of($fcast($StringArray, $(tns->toArray($$new($StringArray, 0))))));
		$set(this, TRANSFORM_TYPES, $List::of($fcast($MethodTypeArray, $(tts->toArray($$new($MethodTypeArray, 0))))));
		$set(this, TRANSFORM_MODS, $List::of($fcast($IntegerArray, $(tms->toArray($$new($IntegerArray, 0))))));
	}
}

$ClassSpecializer$SpeciesData* ClassSpecializer$Factory::loadSpecies($ClassSpecializer$SpeciesData* speciesData) {
	$useLocalCurrentObjectStackCache();
	$var($String, className, $nc(speciesData)->deriveClassName());
	if (!ClassSpecializer$Factory::$assertionsDisabled && !($nc(className)->indexOf((int32_t)u'/') < 0)) {
		$throwNew($AssertionError, $of(className));
	}
	$Class* salvage = nullptr;
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				salvage = $BootLoader::loadClassOrNull(className);
			} catch ($Error& ex) {
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$MethodHandleStatics::traceSpeciesType(className, salvage);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$Class* speciesCode = nullptr;
	if (salvage != nullptr) {
		speciesCode = salvage->asSubclass(this->this$0->topClass());
		linkSpeciesDataToCode(speciesData, speciesCode);
		linkCodeToSpeciesData(speciesCode, speciesData, true);
	} else {
		try {
			speciesCode = generateConcreteSpeciesCode(className, speciesData);
			linkSpeciesDataToCode(speciesData, speciesCode);
			linkCodeToSpeciesData(speciesCode, speciesData, false);
		} catch ($Error& ex) {
			$throw(ex);
		}
	}
	if (!speciesData->isResolved()) {
		$throw($($MethodHandleStatics::newInternalError($$str({"bad species class linkage for "_s, className, ": "_s, speciesData}))));
	}
	if (!ClassSpecializer$Factory::$assertionsDisabled && !(speciesData == loadSpeciesDataFromCode(speciesCode))) {
		$throwNew($AssertionError);
	}
	return speciesData;
}

$Class* ClassSpecializer$Factory::generateConcreteSpeciesCode($String* className, $ClassSpecializer$SpeciesData* speciesData) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($bytes, classFile, generateConcreteSpeciesCodeFile(className, speciesData));
	$InvokerBytecodeGenerator::maybeDump($($ClassSpecializer::classBCName(className)), classFile);
	$var($ClassLoader, cl, $nc(this->this$0->topClass$)->getClassLoader());
	$var($ProtectionDomain, pd, nullptr);
	if (cl != nullptr) {
		$assign(pd, $cast($ProtectionDomain, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ClassSpecializer$Factory$1, this)))));
	}
	$Class* speciesCode = $nc($($SharedSecrets::getJavaLangAccess()))->defineClass(cl, className, classFile, pd, "_ClassSpecializer_generateConcreteSpeciesCode"_s);
	return $nc(speciesCode)->asSubclass(this->this$0->topClass());
}

$bytes* ClassSpecializer$Factory::generateConcreteSpeciesCodeFile($String* className0, $ClassSpecializer$SpeciesData* speciesData) {
	$useLocalCurrentObjectStackCache();
	$var($String, className, $ClassSpecializer::classBCName(className0));
	$var($String, superClassName, $ClassSpecializer::classBCName($nc(speciesData)->deriveSuperClass()));
	$var($ClassWriter, cw, $new($ClassWriter, $ClassWriter::COMPUTE_MAXS + $ClassWriter::COMPUTE_FRAMES));
	int32_t NOT_ACC_PUBLIC = 0;
	cw->visit(50, NOT_ACC_PUBLIC + 16 + 32, className, nullptr, superClassName, nullptr);
	$var($String, sourceFile, $nc(className)->substring(className->lastIndexOf((int32_t)u'.') + 1));
	cw->visitSource(sourceFile, nullptr);
	$var($FieldVisitor, fw, cw->visitField(NOT_ACC_PUBLIC + 8, this->this$0->sdFieldName, this->SPECIES_DATA_SIG, nullptr, nullptr));
	$nc(fw)->visitAnnotation("Ljdk/internal/vm/annotation/Stable;"_s, true);
	fw->visitEnd();
	{
	}
	$var($ClassSpecializer$Factory$1Var, NO_THIS, $new($ClassSpecializer$Factory$1Var, this, 0, 0, className));
	$var($ClassSpecializer$Factory$1Var, AFTER_THIS, $new($ClassSpecializer$Factory$1Var, this, 0, 1, className));
	$var($ClassSpecializer$Factory$1Var, IN_HEAP, $new($ClassSpecializer$Factory$1Var, this, 0, -1, className));
	$var($List, fieldTypes, $nc(speciesData)->fieldTypes());
	$var($List, fields, $new($ArrayList, $nc(fieldTypes)->size()));
	{
		$var($ClassSpecializer$Factory$1Var, nextF, IN_HEAP);
		{
			$var($Iterator, i$, $nc(fieldTypes)->iterator());
			for (; $nc(i$)->hasNext();) {
				$Class* ft = $cast($Class, i$->next());
				{
					$var($String, fn, chooseFieldName(ft, nextF->nextIndex()));
					$assign(nextF, $new($ClassSpecializer$Factory$1Var, this, fn, ft, nextF, className));
					fields->add(nextF);
				}
			}
		}
	}
	{
		$var($Iterator, i$, fields->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ClassSpecializer$Factory$1Var, field, $cast($ClassSpecializer$Factory$1Var, i$->next()));
			{
				$nc($(cw->visitField(16, $nc(field)->name, field->desc, nullptr, nullptr)))->visitEnd();
			}
		}
	}
	$var($MethodVisitor, mv, nullptr);
	$assign(mv, cw->visitMethod(((int32_t)(this->SPECIES_DATA_MODS & (uint32_t)ClassSpecializer$Factory::ACC_PPP)) + 16, this->SPECIES_DATA_NAME, $$str({"()"_s, this->SPECIES_DATA_SIG}), nullptr, nullptr));
	$nc(mv)->visitCode();
	mv->visitFieldInsn(178, className, this->this$0->sdFieldName, this->SPECIES_DATA_SIG);
	mv->visitInsn(176);
	mv->visitMaxs(0, 0);
	mv->visitEnd();
	$var($MethodType, superCtorType, this->this$0->baseConstructorType());
	$var($MethodType, thisCtorType, $nc(superCtorType)->appendParameterTypes(fieldTypes));
	{
		$assign(mv, cw->visitMethod(2, "<init>"_s, $($ClassSpecializer::methodSig(thisCtorType)), nullptr, nullptr));
		$nc(mv)->visitCode();
		mv->visitVarInsn(25, 0);
		$var($List, ctorArgs, AFTER_THIS->fromTypes($(superCtorType->parameterList())));
		{
			$var($Iterator, i$, $nc(ctorArgs)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ClassSpecializer$Factory$1Var, ca, $cast($ClassSpecializer$Factory$1Var, i$->next()));
				{
					$nc(ca)->emitVarInstruction(25, mv);
				}
			}
		}
		mv->visitMethodInsn(183, superClassName, "<init>"_s, $($ClassSpecializer::methodSig(superCtorType)), false);
		$var($ClassSpecializer$Factory$1Var, lastFV, AFTER_THIS->lastOf(ctorArgs));
		{
			$var($Iterator, i$, fields->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ClassSpecializer$Factory$1Var, f, $cast($ClassSpecializer$Factory$1Var, i$->next()));
				{
					mv->visitVarInsn(25, 0);
					$assign(lastFV, $new($ClassSpecializer$Factory$1Var, this, $nc(f)->name, f->type, lastFV, className));
					lastFV->emitVarInstruction(25, mv);
					$nc(f)->emitFieldInsn(181, mv);
				}
			}
		}
		mv->visitInsn(177);
		mv->visitMaxs(0, 0);
		mv->visitEnd();
	}
	{
		$var($MethodType, ftryType, $nc(thisCtorType)->changeReturnType(this->this$0->topClass()));
		$assign(mv, cw->visitMethod(NOT_ACC_PUBLIC + 8, "make"_s, $($ClassSpecializer::methodSig(ftryType)), nullptr, nullptr));
		$nc(mv)->visitCode();
		mv->visitTypeInsn(187, className);
		mv->visitInsn(89);
		{
			$var($Iterator, i$, $nc($(NO_THIS->fromTypes($($nc(ftryType)->parameterList()))))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ClassSpecializer$Factory$1Var, v, $cast($ClassSpecializer$Factory$1Var, i$->next()));
				{
					$nc(v)->emitVarInstruction(25, mv);
				}
			}
		}
		mv->visitMethodInsn(183, className, "<init>"_s, $($ClassSpecializer::methodSig(thisCtorType)), false);
		mv->visitInsn(176);
		mv->visitMaxs(0, 0);
		mv->visitEnd();
	}
	for (int32_t whichtm = 0; whichtm < $nc(this->TRANSFORM_NAMES)->size(); ++whichtm) {
		$var($String, TNAME, $cast($String, $nc(this->TRANSFORM_NAMES)->get(whichtm)));
		$var($MethodType, TTYPE, $cast($MethodType, $nc(this->TRANSFORM_TYPES)->get(whichtm)));
		int32_t TMODS = $nc(($cast($Integer, $($nc(this->TRANSFORM_MODS)->get(whichtm)))))->intValue();
		$assign(mv, cw->visitMethod(((int32_t)(TMODS & (uint32_t)ClassSpecializer$Factory::ACC_PPP)) | 16, TNAME, $($nc(TTYPE)->toMethodDescriptorString()), nullptr, $ClassSpecializer::E_THROWABLE));
		$nc(mv)->visitCode();
		mv->visitFieldInsn(178, className, this->this$0->sdFieldName, this->SPECIES_DATA_SIG);
		emitIntConstant(whichtm, mv);
		mv->visitMethodInsn(182, this->SPECIES_DATA, "transformHelper"_s, $$str({"(I)"_s, "Ljava/lang/invoke/MethodHandle;"_s}), false);
		$var($List, targs, AFTER_THIS->fromTypes($($nc(TTYPE)->parameterList())));
		$var($List, tfields, $new($ArrayList, static_cast<$Collection*>(fields)));
		$var($List, helperArgs, speciesData->deriveTransformHelperArguments($cast($MemberName, $($nc(this->this$0->transformMethods$)->get(whichtm))), whichtm, targs, tfields));
		$var($List, helperTypes, $new($ArrayList, $nc(helperArgs)->size()));
		{
			$var($Iterator, i$, $nc(helperArgs)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ClassSpecializer$Factory$1Var, ha, $cast($ClassSpecializer$Factory$1Var, i$->next()));
				{
					helperTypes->add($nc(ha)->basicType->basicTypeClass());
					if ($nc(ha)->isInHeap()) {
						if (!ClassSpecializer$Factory::$assertionsDisabled && !(tfields->contains(ha))) {
							$throwNew($AssertionError);
						}
						mv->visitVarInsn(25, 0);
						ha->emitFieldInsn(180, mv);
					} else {
						if (!ClassSpecializer$Factory::$assertionsDisabled && !($nc(targs)->contains(ha))) {
							$throwNew($AssertionError);
						}
						ha->emitVarInstruction(25, mv);
					}
				}
			}
		}
		$Class* rtype = $cast($Class, $nc(TTYPE)->returnType());
		$LambdaForm$BasicType* rbt = $LambdaForm$BasicType::basicType(rtype);
		$var($MethodType, invokeBasicType, $MethodType::methodType(rbt->basicTypeClass(), helperTypes));
		mv->visitMethodInsn(182, "java/lang/invoke/MethodHandle"_s, "invokeBasic"_s, $($ClassSpecializer::methodSig(invokeBasicType)), false);
		if (rbt == $LambdaForm$BasicType::L_TYPE) {
			mv->visitTypeInsn(192, $($ClassSpecializer::classBCName(rtype)));
			mv->visitInsn(176);
		} else {
			$throw($($MethodHandleStatics::newInternalError($$str({"NYI: transform of type "_s, rtype}))));
		}
		mv->visitMaxs(0, 0);
		mv->visitEnd();
	}
	cw->visitEnd();
	return cw->toByteArray();
}

int32_t ClassSpecializer$Factory::typeLoadOp(char16_t t) {
	$useLocalCurrentObjectStackCache();

	int32_t var$0 = 0;
	switch (t) {
	case u'L':
		{
			var$0 = 25;
			break;
		}
	case u'I':
		{
			var$0 = 21;
			break;
		}
	case u'J':
		{
			var$0 = 22;
			break;
		}
	case u'F':
		{
			var$0 = 23;
			break;
		}
	case u'D':
		{
			var$0 = 24;
			break;
		}
	default:
		{
			$throw($($MethodHandleStatics::newInternalError($$str({"unrecognized type "_s, $$str(t)}))));
		}
	}
	return var$0;
}

void ClassSpecializer$Factory::emitIntConstant(int32_t con, $MethodVisitor* mv) {
	if (2 - 3 <= con && con <= 8 - 3) {
		$nc(mv)->visitInsn(3 + con);
	} else if (con == (int8_t)con) {
		$nc(mv)->visitIntInsn(16, con);
	} else if (con == (int16_t)con) {
		$nc(mv)->visitIntInsn(17, con);
	} else {
		$nc(mv)->visitLdcInsn($($Integer::valueOf(con)));
	}
}

$MethodHandle* ClassSpecializer$Factory::findGetter($Class* speciesCode, $List* types, int32_t index) {
	$useLocalCurrentObjectStackCache();
	$Class* fieldType = $cast($Class, $nc(types)->get(index));
	$var($String, fieldName, chooseFieldName(fieldType, index));
	try {
		$init($MethodHandles$Lookup);
		return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findGetter(speciesCode, fieldName, fieldType);
	} catch ($NoSuchFieldException& e) {
		$throw($($MethodHandleStatics::newInternalError(static_cast<$Exception*>(e))));
	} catch ($IllegalAccessException& e) {
		$throw($($MethodHandleStatics::newInternalError(static_cast<$Exception*>(e))));
	}
	$shouldNotReachHere();
}

$List* ClassSpecializer$Factory::findGetters($Class* speciesCode, $List* types) {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandleArray, mhs, $new($MethodHandleArray, $nc(types)->size()));
	for (int32_t i = 0; i < mhs->length; ++i) {
		mhs->set(i, $(findGetter(speciesCode, types, i)));
		if (!ClassSpecializer$Factory::$assertionsDisabled && !($nc($($nc(mhs->get(i))->internalMemberName()))->getDeclaringClass() == speciesCode)) {
			$throwNew($AssertionError);
		}
	}
	return $List::of(mhs);
}

$List* ClassSpecializer$Factory::findFactories($Class* speciesCode, $List* types) {
	$useLocalCurrentObjectStackCache();
	$var($MethodHandleArray, mhs, $new($MethodHandleArray, 1));
	mhs->set(0, $(findFactory(speciesCode, types)));
	return $List::of(mhs);
}

$List* ClassSpecializer$Factory::makeNominalGetters($List* types, $List* getters) {
	$useLocalCurrentObjectStackCache();
	$var($LambdaForm$NamedFunctionArray, nfs, $new($LambdaForm$NamedFunctionArray, $nc(types)->size()));
	for (int32_t i = 0; i < nfs->length; ++i) {
		nfs->set(i, $$new($LambdaForm$NamedFunction, $cast($MethodHandle, $($nc(getters)->get(i)))));
	}
	return $List::of(nfs);
}

void ClassSpecializer$Factory::linkSpeciesDataToCode($ClassSpecializer$SpeciesData* speciesData, $Class* speciesCode) {
	$set($nc(speciesData), speciesCode$, $nc(speciesCode)->asSubclass(this->this$0->topClass$));
	$var($List, types, speciesData->fieldTypes$);
	$set(speciesData, factories, this->findFactories(speciesCode, types));
	$set(speciesData, getters$, this->findGetters(speciesCode, types));
	$set(speciesData, nominalGetters, this->makeNominalGetters(types, speciesData->getters$));
}

$Field* ClassSpecializer$Factory::reflectSDField($Class* speciesCode) {
	$var($Field, field, $ClassSpecializer::reflectField(speciesCode, this->this$0->sdFieldName));
	if (!ClassSpecializer$Factory::$assertionsDisabled && !($nc(field)->getType() == this->this$0->metaType$)) {
		$throwNew($AssertionError);
	}
	if (!ClassSpecializer$Factory::$assertionsDisabled && !($Modifier::isStatic($nc(field)->getModifiers()))) {
		$throwNew($AssertionError);
	}
	return field;
}

$ClassSpecializer$SpeciesData* ClassSpecializer$Factory::readSpeciesDataFromCode($Class* speciesCode) {
	$useLocalCurrentObjectStackCache();
	try {
		$init($MethodHandles$Lookup);
		$var($MemberName, sdField, $nc($MethodHandles$Lookup::IMPL_LOOKUP)->resolveOrFail((int8_t)2, speciesCode, this->this$0->sdFieldName, this->this$0->metaType$));
		$var($Object, base, $MethodHandleNatives::staticFieldBase(sdField));
		int64_t offset = $MethodHandleNatives::staticFieldOffset(sdField);
		$init($MethodHandleStatics);
		$nc($MethodHandleStatics::UNSAFE)->loadFence();
		return $cast($ClassSpecializer$SpeciesData, $nc(this->this$0->metaType$)->cast($($nc($MethodHandleStatics::UNSAFE)->getReference(base, offset))));
	} catch ($Error& err) {
		$throw(err);
	} catch ($Exception& ex) {
		$throw($($MethodHandleStatics::newInternalError($$str({"Failed to load speciesData from speciesCode: "_s, $($nc(speciesCode)->getName())}), ex)));
	} catch ($Throwable& t) {
		$throw($($MethodHandleStatics::uncaughtException(t)));
	}
	$shouldNotReachHere();
}

$ClassSpecializer$SpeciesData* ClassSpecializer$Factory::loadSpeciesDataFromCode($Class* speciesCode) {
	$useLocalCurrentObjectStackCache();
	if (speciesCode == this->this$0->topClass()) {
		return this->this$0->topSpecies$;
	}
	$var($ClassSpecializer$SpeciesData, result, readSpeciesDataFromCode(speciesCode));
	if ($nc(result)->outer() != this->this$0) {
		$throw($($MethodHandleStatics::newInternalError("wrong class"_s)));
	}
	return result;
}

void ClassSpecializer$Factory::linkCodeToSpeciesData($Class* speciesCode, $ClassSpecializer$SpeciesData* speciesData, bool salvage) {
	$useLocalCurrentObjectStackCache();
	try {
		bool var$0 = !ClassSpecializer$Factory::$assertionsDisabled;
		if (var$0) {
			bool var$1 = readSpeciesDataFromCode(speciesCode) == nullptr;
			var$0 = !(var$1 || (salvage && $nc($(readSpeciesDataFromCode(speciesCode)))->equals(speciesData)));
		}
		if (var$0) {
			$throwNew($AssertionError);
		}
		$init($MethodHandles$Lookup);
		$var($MemberName, sdField, $nc($MethodHandles$Lookup::IMPL_LOOKUP)->resolveOrFail((int8_t)4, speciesCode, this->this$0->sdFieldName, this->this$0->metaType$));
		$var($Object, base, $MethodHandleNatives::staticFieldBase(sdField));
		int64_t offset = $MethodHandleNatives::staticFieldOffset(sdField);
		$init($MethodHandleStatics);
		$nc($MethodHandleStatics::UNSAFE)->storeFence();
		$nc($MethodHandleStatics::UNSAFE)->putReference(base, offset, speciesData);
		$nc($MethodHandleStatics::UNSAFE)->storeFence();
	} catch ($Error& err) {
		$throw(err);
	} catch ($Exception& ex) {
		$throw($($MethodHandleStatics::newInternalError($$str({"Failed to link speciesData to speciesCode: "_s, $($nc(speciesCode)->getName())}), ex)));
	} catch ($Throwable& t) {
		$throw($($MethodHandleStatics::uncaughtException(t)));
	}
}

$String* ClassSpecializer$Factory::chooseFieldName($Class* type, int32_t index) {
	$useLocalCurrentObjectStackCache();
	$LambdaForm$BasicType* bt = $LambdaForm$BasicType::basicType(type);
	return $str({""_s, $$str($nc(bt)->basicTypeChar()), $$str(index)});
}

$MethodHandle* ClassSpecializer$Factory::findFactory($Class* speciesCode, $List* types) {
	$useLocalCurrentObjectStackCache();
	$var($MethodType, type, $nc($($nc($(this->this$0->baseConstructorType()))->changeReturnType(this->this$0->topClass())))->appendParameterTypes(types));
	try {
		$init($MethodHandles$Lookup);
		return $nc($MethodHandles$Lookup::IMPL_LOOKUP)->findStatic(speciesCode, "make"_s, type);
	} catch ($NoSuchMethodException& e) {
		$throw($($MethodHandleStatics::newInternalError($cast($Exception, e))));
	} catch ($IllegalAccessException& e) {
		$throw($($MethodHandleStatics::newInternalError($cast($Exception, e))));
	} catch ($IllegalArgumentException& e) {
		$throw($($MethodHandleStatics::newInternalError($cast($Exception, e))));
	} catch ($TypeNotPresentException& e) {
		$throw($($MethodHandleStatics::newInternalError($cast($Exception, e))));
	}
	$shouldNotReachHere();
}

void clinit$ClassSpecializer$Factory($Class* class$) {
	$load($ClassSpecializer);
	ClassSpecializer$Factory::$assertionsDisabled = !$ClassSpecializer::class$->desiredAssertionStatus();
}

ClassSpecializer$Factory::ClassSpecializer$Factory() {
}

$Class* ClassSpecializer$Factory::load$($String* name, bool initialize) {
	$loadClass(ClassSpecializer$Factory, name, initialize, &_ClassSpecializer$Factory_ClassInfo_, clinit$ClassSpecializer$Factory, allocate$ClassSpecializer$Factory);
	return class$;
}

$Class* ClassSpecializer$Factory::class$ = nullptr;

		} // invoke
	} // lang
} // java
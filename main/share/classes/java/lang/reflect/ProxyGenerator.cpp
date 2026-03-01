#include <java/lang/reflect/ProxyGenerator.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Error.h>
#include <java/lang/NoSuchMethodError.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/lang/reflect/ProxyGenerator$1.h>
#include <java/lang/reflect/ProxyGenerator$ProxyMethod.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/ListIterator.h>
#include <java/util/Map.h>
#include <java/util/function/Function.h>
#include <jdk/internal/org/objectweb/asm/ClassWriter.h>
#include <jdk/internal/org/objectweb/asm/FieldVisitor.h>
#include <jdk/internal/org/objectweb/asm/Label.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/Type.h>
#include <sun/security/action/GetBooleanAction.h>
#include <jcpp.h>

#undef COMPUTE_FRAMES
#undef EMPTY_CLASS_ARRAY
#undef JLI_LOOKUP
#undef JLI_METHODHANDLES
#undef JLR_INVOCATION_HANDLER
#undef JLR_PROXY
#undef JLR_UNDECLARED_THROWABLE_EX
#undef JL_CLASS
#undef JL_CLASS_NOT_FOUND_EX
#undef JL_ILLEGAL_ACCESS_EX
#undef JL_NO_CLASS_DEF_FOUND_ERROR
#undef JL_NO_SUCH_METHOD_ERROR
#undef JL_NO_SUCH_METHOD_EX
#undef JL_OBJECT
#undef JL_THROWABLE
#undef LJLR_INVOCATION_HANDLER
#undef LJLR_METHOD
#undef LJL_CLASS
#undef MJLR_INVOCATIONHANDLER
#undef NAME_CLINIT
#undef NAME_CTOR
#undef NAME_LOOKUP_ACCESSOR
#undef NEW
#undef PUBLIC
#undef STATIC
#undef TYPE

using $MethodArray = $Array<::java::lang::reflect::Method>;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $Double = ::java::lang::Double;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchMethodError = ::java::lang::NoSuchMethodError;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $RuntimeException = ::java::lang::RuntimeException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $ProxyGenerator$1 = ::java::lang::reflect::ProxyGenerator$1;
using $ProxyGenerator$ProxyMethod = ::java::lang::reflect::ProxyGenerator$ProxyMethod;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $ListIterator = ::java::util::ListIterator;
using $Map = ::java::util::Map;
using $Function = ::java::util::function::Function;
using $ClassWriter = ::jdk::internal::org::objectweb::asm$::ClassWriter;
using $Label = ::jdk::internal::org::objectweb::asm$::Label;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $Type = ::jdk::internal::org::objectweb::asm$::Type;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;

namespace java {
	namespace lang {
		namespace reflect {

class ProxyGenerator$$Lambda$lambda$addProxyMethod$0 : public $Function {
	$class(ProxyGenerator$$Lambda$lambda$addProxyMethod$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* f) override {
		 return $of(ProxyGenerator::lambda$addProxyMethod$0($cast($String, f)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ProxyGenerator$$Lambda$lambda$addProxyMethod$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ProxyGenerator$$Lambda$lambda$addProxyMethod$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ProxyGenerator$$Lambda$lambda$addProxyMethod$0, init$, void)},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ProxyGenerator$$Lambda$lambda$addProxyMethod$0, apply, $Object*, Object$*)},
	{}
};
$ClassInfo ProxyGenerator$$Lambda$lambda$addProxyMethod$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.lang.reflect.ProxyGenerator$$Lambda$lambda$addProxyMethod$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* ProxyGenerator$$Lambda$lambda$addProxyMethod$0::load$($String* name, bool initialize) {
	$loadClass(ProxyGenerator$$Lambda$lambda$addProxyMethod$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ProxyGenerator$$Lambda$lambda$addProxyMethod$0::class$ = nullptr;

$FieldInfo _ProxyGenerator_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ProxyGenerator, $assertionsDisabled)},
	{"JL_CLASS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JL_CLASS)},
	{"JL_OBJECT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JL_OBJECT)},
	{"JL_THROWABLE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JL_THROWABLE)},
	{"JL_CLASS_NOT_FOUND_EX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JL_CLASS_NOT_FOUND_EX)},
	{"JL_ILLEGAL_ACCESS_EX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JL_ILLEGAL_ACCESS_EX)},
	{"JL_NO_CLASS_DEF_FOUND_ERROR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JL_NO_CLASS_DEF_FOUND_ERROR)},
	{"JL_NO_SUCH_METHOD_EX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JL_NO_SUCH_METHOD_EX)},
	{"JL_NO_SUCH_METHOD_ERROR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JL_NO_SUCH_METHOD_ERROR)},
	{"JLI_LOOKUP", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JLI_LOOKUP)},
	{"JLI_METHODHANDLES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JLI_METHODHANDLES)},
	{"JLR_INVOCATION_HANDLER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JLR_INVOCATION_HANDLER)},
	{"JLR_PROXY", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JLR_PROXY)},
	{"JLR_UNDECLARED_THROWABLE_EX", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, JLR_UNDECLARED_THROWABLE_EX)},
	{"LJL_CLASS", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, LJL_CLASS)},
	{"LJLR_METHOD", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, LJLR_METHOD)},
	{"LJLR_INVOCATION_HANDLER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, LJLR_INVOCATION_HANDLER)},
	{"MJLR_INVOCATIONHANDLER", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, MJLR_INVOCATIONHANDLER)},
	{"NAME_CTOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, NAME_CTOR)},
	{"NAME_CLINIT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, NAME_CLINIT)},
	{"NAME_LOOKUP_ACCESSOR", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, NAME_LOOKUP_ACCESSOR)},
	{"EMPTY_CLASS_ARRAY", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, EMPTY_CLASS_ARRAY)},
	{"handlerFieldName", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, handlerFieldName)},
	{"saveGeneratedFiles", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, saveGeneratedFiles)},
	{"hashCodeMethod", "Ljava/lang/reflect/ProxyGenerator$ProxyMethod;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, hashCodeMethod)},
	{"equalsMethod", "Ljava/lang/reflect/ProxyGenerator$ProxyMethod;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, equalsMethod)},
	{"toStringMethod", "Ljava/lang/reflect/ProxyGenerator$ProxyMethod;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ProxyGenerator, toStringMethod)},
	{"loader", "Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $FINAL, $field(ProxyGenerator, loader)},
	{"className", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ProxyGenerator, className)},
	{"interfaces", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/Class<*>;>;", $PRIVATE | $FINAL, $field(ProxyGenerator, interfaces)},
	{"accessFlags", "I", nullptr, $PRIVATE | $FINAL, $field(ProxyGenerator, accessFlags)},
	{"proxyMethods", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/reflect/ProxyGenerator$ProxyMethod;>;>;", $PRIVATE | $FINAL, $field(ProxyGenerator, proxyMethods)},
	{"proxyMethodCount", "I", nullptr, $PRIVATE, $field(ProxyGenerator, proxyMethodCount)},
	{}
};

$MethodInfo _ProxyGenerator_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/util/List;I)V", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/util/List<Ljava/lang/Class<*>;>;I)V", $PRIVATE, $method(ProxyGenerator, init$, void, $ClassLoader*, $String*, $List*, int32_t)},
	{"addProxyMethod", "(Ljava/lang/reflect/Method;Ljava/lang/Class;)V", "(Ljava/lang/reflect/Method;Ljava/lang/Class<*>;)V", $PRIVATE, $method(ProxyGenerator, addProxyMethod, void, $Method*, $Class*)},
	{"addProxyMethod", "(Ljava/lang/reflect/ProxyGenerator$ProxyMethod;)V", nullptr, $PRIVATE, $method(ProxyGenerator, addProxyMethod, void, $ProxyGenerator$ProxyMethod*)},
	{"checkReturnTypes", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/lang/reflect/ProxyGenerator$ProxyMethod;>;)V", $PRIVATE | $STATIC, $staticMethod(ProxyGenerator, checkReturnTypes, void, $List*)},
	{"collectCompatibleTypes", "([Ljava/lang/Class;[Ljava/lang/Class;Ljava/util/List;)V", "([Ljava/lang/Class<*>;[Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/Class<*>;>;)V", $PRIVATE | $STATIC, $staticMethod(ProxyGenerator, collectCompatibleTypes, void, $ClassArray*, $ClassArray*, $List*)},
	{"computeUniqueCatchList", "([Ljava/lang/Class;)Ljava/util/List;", "([Ljava/lang/Class<*>;)Ljava/util/List<Ljava/lang/Class<*>;>;", $PRIVATE | $STATIC, $staticMethod(ProxyGenerator, computeUniqueCatchList, $List*, $ClassArray*)},
	{"dotToSlash", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticMethod(ProxyGenerator, dotToSlash, $String*, $String*)},
	{"generateClassFile", "()[B", nullptr, $PRIVATE, $method(ProxyGenerator, generateClassFile, $bytes*)},
	{"generateConstructor", "()V", nullptr, $PRIVATE, $method(ProxyGenerator, generateConstructor, void)},
	{"generateLookupAccessor", "()V", nullptr, $PRIVATE, $method(ProxyGenerator, generateLookupAccessor, void)},
	{"generateProxyClass", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/util/List;I)[B", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/util/List<Ljava/lang/Class<*>;>;I)[B", $STATIC, $staticMethod(ProxyGenerator, generateProxyClass, $bytes*, $ClassLoader*, $String*, $List*, int32_t)},
	{"generateStaticInitializer", "()V", nullptr, $PRIVATE, $method(ProxyGenerator, generateStaticInitializer, void)},
	{"getClassLoader", "()Ljava/lang/ClassLoader;", nullptr, $PROTECTED, $virtualMethod(ProxyGenerator, getClassLoader, $ClassLoader*)},
	{"getWordsPerType", "(Ljava/lang/Class;)I", "(Ljava/lang/Class<*>;)I", $PRIVATE | $STATIC, $staticMethod(ProxyGenerator, getWordsPerType, int32_t, $Class*)},
	{"lambda$addProxyMethod$0", "(Ljava/lang/String;)Ljava/util/List;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(ProxyGenerator, lambda$addProxyMethod$0, $List*, $String*)},
	{"typeNames", "(Ljava/util/List;)[Ljava/lang/String;", "(Ljava/util/List<Ljava/lang/Class<*>;>;)[Ljava/lang/String;", $PRIVATE | $STATIC, $staticMethod(ProxyGenerator, typeNames, $StringArray*, $List*)},
	{}
};

$InnerClassInfo _ProxyGenerator_InnerClassesInfo_[] = {
	{"java.lang.reflect.ProxyGenerator$PrimitiveTypeInfo", "java.lang.reflect.ProxyGenerator", "PrimitiveTypeInfo", $PRIVATE | $STATIC},
	{"java.lang.reflect.ProxyGenerator$ProxyMethod", "java.lang.reflect.ProxyGenerator", "ProxyMethod", $PRIVATE | $STATIC},
	{"java.lang.reflect.ProxyGenerator$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ProxyGenerator_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.lang.reflect.ProxyGenerator",
	"jdk.internal.org.objectweb.asm.ClassWriter",
	nullptr,
	_ProxyGenerator_FieldInfo_,
	_ProxyGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_ProxyGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.lang.reflect.ProxyGenerator$PrimitiveTypeInfo,java.lang.reflect.ProxyGenerator$ProxyMethod,java.lang.reflect.ProxyGenerator$1"
};

$Object* allocate$ProxyGenerator($Class* clazz) {
	return $of($alloc(ProxyGenerator));
}

bool ProxyGenerator::$assertionsDisabled = false;
$String* ProxyGenerator::JL_CLASS = nullptr;
$String* ProxyGenerator::JL_OBJECT = nullptr;
$String* ProxyGenerator::JL_THROWABLE = nullptr;
$String* ProxyGenerator::JL_CLASS_NOT_FOUND_EX = nullptr;
$String* ProxyGenerator::JL_ILLEGAL_ACCESS_EX = nullptr;
$String* ProxyGenerator::JL_NO_CLASS_DEF_FOUND_ERROR = nullptr;
$String* ProxyGenerator::JL_NO_SUCH_METHOD_EX = nullptr;
$String* ProxyGenerator::JL_NO_SUCH_METHOD_ERROR = nullptr;
$String* ProxyGenerator::JLI_LOOKUP = nullptr;
$String* ProxyGenerator::JLI_METHODHANDLES = nullptr;
$String* ProxyGenerator::JLR_INVOCATION_HANDLER = nullptr;
$String* ProxyGenerator::JLR_PROXY = nullptr;
$String* ProxyGenerator::JLR_UNDECLARED_THROWABLE_EX = nullptr;
$String* ProxyGenerator::LJL_CLASS = nullptr;
$String* ProxyGenerator::LJLR_METHOD = nullptr;
$String* ProxyGenerator::LJLR_INVOCATION_HANDLER = nullptr;
$String* ProxyGenerator::MJLR_INVOCATIONHANDLER = nullptr;
$String* ProxyGenerator::NAME_CTOR = nullptr;
$String* ProxyGenerator::NAME_CLINIT = nullptr;
$String* ProxyGenerator::NAME_LOOKUP_ACCESSOR = nullptr;
$ClassArray* ProxyGenerator::EMPTY_CLASS_ARRAY = nullptr;
$String* ProxyGenerator::handlerFieldName = nullptr;
bool ProxyGenerator::saveGeneratedFiles = false;
$ProxyGenerator$ProxyMethod* ProxyGenerator::hashCodeMethod = nullptr;
$ProxyGenerator$ProxyMethod* ProxyGenerator::equalsMethod = nullptr;
$ProxyGenerator$ProxyMethod* ProxyGenerator::toStringMethod = nullptr;

void ProxyGenerator::init$($ClassLoader* loader, $String* className, $List* interfaces, int32_t accessFlags) {
	$ClassWriter::init$($ClassWriter::COMPUTE_FRAMES);
	$set(this, proxyMethods, $new($LinkedHashMap));
	this->proxyMethodCount = 3;
	$set(this, loader, loader);
	$set(this, className, className);
	$set(this, interfaces, interfaces);
	this->accessFlags = accessFlags;
}

$bytes* ProxyGenerator::generateProxyClass($ClassLoader* loader, $String* name, $List* interfaces, int32_t accessFlags) {
	$init(ProxyGenerator);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var(ProxyGenerator, gen, $new(ProxyGenerator, loader, name, interfaces, accessFlags));
	$var($bytes, classFile, gen->generateClassFile());
	if (ProxyGenerator::saveGeneratedFiles) {
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ProxyGenerator$1, name, classFile)));
	}
	return classFile;
}

$StringArray* ProxyGenerator::typeNames($List* classes) {
	$init(ProxyGenerator);
	$useLocalCurrentObjectStackCache();
	if (classes == nullptr || $nc(classes)->size() == 0) {
		return nullptr;
	}
	int32_t size = $nc(classes)->size();
	$var($StringArray, ifaces, $new($StringArray, size));
	for (int32_t i = 0; i < size; ++i) {
		ifaces->set(i, $(dotToSlash($($nc(($cast($Class, $(classes->get(i)))))->getName()))));
	}
	return ifaces;
}

void ProxyGenerator::checkReturnTypes($List* methods) {
	$init(ProxyGenerator);
	$useLocalCurrentObjectStackCache();
	if ($nc(methods)->size() < 2) {
		return;
	}
	$var($LinkedList, uncoveredReturnTypes, $new($LinkedList));
	bool nextNewReturnType$continue = false;
	{
		$var($Iterator, i$, $nc(methods)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ProxyGenerator$ProxyMethod, pm, $cast($ProxyGenerator$ProxyMethod, i$->next()));
			{
				$Class* newReturnType = $nc(pm)->returnType;
				if ($nc(newReturnType)->isPrimitive()) {
					$throwNew($IllegalArgumentException, $$str({"methods with same signature "_s, pm->shortSignature, " but incompatible return types: "_s, $(newReturnType->getName()), " and others"_s}));
				}
				bool added = false;
				$var($ListIterator, liter, uncoveredReturnTypes->listIterator());
				while ($nc(liter)->hasNext()) {
					$Class* uncoveredReturnType = $cast($Class, liter->next());
					if ($nc(newReturnType)->isAssignableFrom(uncoveredReturnType)) {
						if (!ProxyGenerator::$assertionsDisabled && ! !added) {
							$throwNew($AssertionError);
						}
						nextNewReturnType$continue = true;
						break;
					}
					if ($nc(uncoveredReturnType)->isAssignableFrom(newReturnType)) {
						if (!added) {
							liter->set(newReturnType);
							added = true;
						} else {
							liter->remove();
						}
					}
				}
				if (nextNewReturnType$continue) {
					nextNewReturnType$continue = false;
					continue;
				}
				if (!added) {
					uncoveredReturnTypes->add(newReturnType);
				}
			}
		}
	}
	if (uncoveredReturnTypes->size() > 1) {
		$var($ProxyGenerator$ProxyMethod, pm, $cast($ProxyGenerator$ProxyMethod, methods->get(0)));
		$throwNew($IllegalArgumentException, $$str({"methods with same signature "_s, $nc(pm)->shortSignature, " but incompatible return types: "_s, uncoveredReturnTypes}));
	}
}

$List* ProxyGenerator::computeUniqueCatchList($ClassArray* exceptions) {
	$init(ProxyGenerator);
	$useLocalCurrentObjectStackCache();
	$var($List, uniqueList, $new($ArrayList));
	$load($Error);
	uniqueList->add($Error::class$);
	$load($RuntimeException);
	uniqueList->add($RuntimeException::class$);
	bool nextException$continue = false;
	{
		$var($ClassArray, arr$, exceptions);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* ex = arr$->get(i$);
			{
				if ($nc(ex)->isAssignableFrom($Throwable::class$)) {
					uniqueList->clear();
					break;
				} else if (!$Throwable::class$->isAssignableFrom(ex)) {
					continue;
				}
				for (int32_t j = 0; j < uniqueList->size();) {
					$Class* ex2 = $cast($Class, uniqueList->get(j));
					if ($nc(ex2)->isAssignableFrom(ex)) {
						nextException$continue = true;
						break;
					} else if ($nc(ex)->isAssignableFrom(ex2)) {
						uniqueList->remove(j);
					} else {
						++j;
					}
				}
				if (nextException$continue) {
					nextException$continue = false;
					continue;
				}
				uniqueList->add(ex);
			}
		}
	}
	return uniqueList;
}

$String* ProxyGenerator::dotToSlash($String* name) {
	$init(ProxyGenerator);
	return $nc(name)->replace(u'.', u'/');
}

int32_t ProxyGenerator::getWordsPerType($Class* type) {
	$init(ProxyGenerator);
	$init($Long);
	$init($Double);
	if (type == $Long::TYPE || type == $Double::TYPE) {
		return 2;
	} else {
		return 1;
	}
}

void ProxyGenerator::collectCompatibleTypes($ClassArray* from, $ClassArray* with, $List* list) {
	$init(ProxyGenerator);
	$useLocalCurrentObjectStackCache();
	{
		$var($ClassArray, arr$, from);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* fc = arr$->get(i$);
			{
				if (!$nc(list)->contains(fc)) {
					{
						$var($ClassArray, arr$, with);
						int32_t len$ = arr$->length;
						int32_t i$ = 0;
						for (; i$ < len$; ++i$) {
							$Class* wc = arr$->get(i$);
							{
								if ($nc(wc)->isAssignableFrom(fc)) {
									list->add(fc);
									break;
								}
							}
						}
					}
				}
			}
		}
	}
}

$ClassLoader* ProxyGenerator::getClassLoader() {
	return this->loader;
}

$bytes* ProxyGenerator::generateClassFile() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	int32_t var$0 = this->accessFlags;
	$var($String, var$1, dotToSlash(this->className));
	$var($String, var$2, ProxyGenerator::JLR_PROXY);
	visit(58, var$0, var$1, nullptr, var$2, $(typeNames(this->interfaces)));
	addProxyMethod(ProxyGenerator::hashCodeMethod);
	addProxyMethod(ProxyGenerator::equalsMethod);
	addProxyMethod(ProxyGenerator::toStringMethod);
	{
		$var($Iterator, i$, $nc(this->interfaces)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* intf = $cast($Class, i$->next());
			{
				{
					$var($MethodArray, arr$, $nc(intf)->getMethods());
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($Method, m, arr$->get(i$));
						{
							if (!$Modifier::isStatic($nc(m)->getModifiers())) {
								addProxyMethod(m, intf);
							}
						}
					}
				}
			}
		}
	}
	{
		$var($Iterator, i$, $nc($($nc(this->proxyMethods)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, sigmethods, $cast($List, i$->next()));
			{
				checkReturnTypes(sigmethods);
			}
		}
	}
	generateConstructor();
	{
		$var($Iterator, i$, $nc($($nc(this->proxyMethods)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, sigmethods, $cast($List, i$->next()));
			{
				{
					$var($Iterator, i$, $nc(sigmethods)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($ProxyGenerator$ProxyMethod, pm, $cast($ProxyGenerator$ProxyMethod, i$->next()));
						{
							visitField((2 | 8) | 16, $nc(pm)->methodFieldName, ProxyGenerator::LJLR_METHOD, nullptr, nullptr);
							$nc(pm)->generateMethod(this, this->className);
						}
					}
				}
			}
		}
	}
	generateStaticInitializer();
	generateLookupAccessor();
	return toByteArray();
}

void ProxyGenerator::addProxyMethod($Method* m, $Class* fromClass) {
	$useLocalCurrentObjectStackCache();
	$Class* returnType = $nc(m)->getReturnType();
	$var($ClassArray, exceptionTypes, m->getExceptionTypes());
	$var($String, sig, m->toShortSignature());
	$var($List, sigmethods, $cast($List, $nc(this->proxyMethods)->computeIfAbsent(sig, static_cast<$Function*>($$new(ProxyGenerator$$Lambda$lambda$addProxyMethod$0)))));
	{
		$var($Iterator, i$, $nc(sigmethods)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ProxyGenerator$ProxyMethod, pm, $cast($ProxyGenerator$ProxyMethod, i$->next()));
			{
				if (returnType == $nc(pm)->returnType) {
					$var($List, legalExceptions, $new($ArrayList));
					collectCompatibleTypes(exceptionTypes, pm->exceptionTypes, legalExceptions);
					collectCompatibleTypes(pm->exceptionTypes, exceptionTypes, legalExceptions);
					$set(pm, exceptionTypes, $fcast($ClassArray, legalExceptions->toArray(ProxyGenerator::EMPTY_CLASS_ARRAY)));
					return;
				}
			}
		}
	}
	$var($String, var$0, "m"_s);
	sigmethods->add($$new($ProxyGenerator$ProxyMethod, m, sig, $(m->getParameterTypes()), returnType, exceptionTypes, fromClass, $$concat(var$0, $$str(this->proxyMethodCount++))));
}

void ProxyGenerator::addProxyMethod($ProxyGenerator$ProxyMethod* pm) {
	$useLocalCurrentObjectStackCache();
	$var($String, sig, $nc(pm)->shortSignature);
	$var($List, sigmethods, $cast($List, $nc(this->proxyMethods)->computeIfAbsent(sig, static_cast<$Function*>($$new(ProxyGenerator$$Lambda$lambda$addProxyMethod$0)))));
	$nc(sigmethods)->add(pm);
}

void ProxyGenerator::generateConstructor() {
	$var($MethodVisitor, ctor, visitMethod($Modifier::PUBLIC, ProxyGenerator::NAME_CTOR, ProxyGenerator::MJLR_INVOCATIONHANDLER, nullptr, nullptr));
	$nc(ctor)->visitParameter(nullptr, 0);
	ctor->visitCode();
	ctor->visitVarInsn(25, 0);
	ctor->visitVarInsn(25, 1);
	ctor->visitMethodInsn(183, ProxyGenerator::JLR_PROXY, ProxyGenerator::NAME_CTOR, ProxyGenerator::MJLR_INVOCATIONHANDLER, false);
	ctor->visitInsn(177);
	ctor->visitMaxs(-1, -1);
	ctor->visitEnd();
}

void ProxyGenerator::generateStaticInitializer() {
	$useLocalCurrentObjectStackCache();
	$var($MethodVisitor, mv, visitMethod($Modifier::STATIC, ProxyGenerator::NAME_CLINIT, "()V"_s, nullptr, nullptr));
	$nc(mv)->visitCode();
	$var($Label, L_startBlock, $new($Label));
	$var($Label, L_endBlock, $new($Label));
	$var($Label, L_NoMethodHandler, $new($Label));
	$var($Label, L_NoClassHandler, $new($Label));
	mv->visitTryCatchBlock(L_startBlock, L_endBlock, L_NoMethodHandler, ProxyGenerator::JL_NO_SUCH_METHOD_EX);
	mv->visitTryCatchBlock(L_startBlock, L_endBlock, L_NoClassHandler, ProxyGenerator::JL_CLASS_NOT_FOUND_EX);
	mv->visitLabel(L_startBlock);
	{
		$var($Iterator, i$, $nc($($nc(this->proxyMethods)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($List, sigmethods, $cast($List, i$->next()));
			{
				{
					$var($Iterator, i$, $nc(sigmethods)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($ProxyGenerator$ProxyMethod, pm, $cast($ProxyGenerator$ProxyMethod, i$->next()));
						{
							$nc(pm)->codeFieldInitialization(mv, this->className);
						}
					}
				}
			}
		}
	}
	mv->visitInsn(177);
	mv->visitLabel(L_endBlock);
	mv->visitLabel(L_NoMethodHandler);
	mv->visitVarInsn(58, 1);
	mv->visitTypeInsn($Opcodes::NEW, ProxyGenerator::JL_NO_SUCH_METHOD_ERROR);
	mv->visitInsn(89);
	mv->visitVarInsn(25, 1);
	mv->visitMethodInsn(182, ProxyGenerator::JL_THROWABLE, "getMessage"_s, "()Ljava/lang/String;"_s, false);
	mv->visitMethodInsn(183, ProxyGenerator::JL_NO_SUCH_METHOD_ERROR, "<init>"_s, "(Ljava/lang/String;)V"_s, false);
	mv->visitInsn(191);
	mv->visitLabel(L_NoClassHandler);
	mv->visitVarInsn(58, 1);
	mv->visitTypeInsn($Opcodes::NEW, ProxyGenerator::JL_NO_CLASS_DEF_FOUND_ERROR);
	mv->visitInsn(89);
	mv->visitVarInsn(25, 1);
	mv->visitMethodInsn(182, ProxyGenerator::JL_THROWABLE, "getMessage"_s, "()Ljava/lang/String;"_s, false);
	mv->visitMethodInsn(183, ProxyGenerator::JL_NO_CLASS_DEF_FOUND_ERROR, "<init>"_s, "(Ljava/lang/String;)V"_s, false);
	mv->visitInsn(191);
	mv->visitMaxs(-1, -1);
	mv->visitEnd();
}

void ProxyGenerator::generateLookupAccessor() {
	$useLocalCurrentObjectStackCache();
	$var($MethodVisitor, mv, visitMethod(2 | 8, ProxyGenerator::NAME_LOOKUP_ACCESSOR, "(Ljava/lang/invoke/MethodHandles$Lookup;)Ljava/lang/invoke/MethodHandles$Lookup;"_s, nullptr, $$new($StringArray, {ProxyGenerator::JL_ILLEGAL_ACCESS_EX})));
	$nc(mv)->visitCode();
	$var($Label, L_illegalAccess, $new($Label));
	mv->visitVarInsn(25, 0);
	mv->visitMethodInsn(182, ProxyGenerator::JLI_LOOKUP, "lookupClass"_s, "()Ljava/lang/Class;"_s, false);
	$load($Proxy);
	mv->visitLdcInsn($($Type::getType($Proxy::class$)));
	mv->visitJumpInsn(166, L_illegalAccess);
	mv->visitVarInsn(25, 0);
	mv->visitMethodInsn(182, ProxyGenerator::JLI_LOOKUP, "hasFullPrivilegeAccess"_s, "()Z"_s, false);
	mv->visitJumpInsn(153, L_illegalAccess);
	mv->visitMethodInsn(184, ProxyGenerator::JLI_METHODHANDLES, "lookup"_s, "()Ljava/lang/invoke/MethodHandles$Lookup;"_s, false);
	mv->visitInsn(176);
	mv->visitLabel(L_illegalAccess);
	mv->visitTypeInsn($Opcodes::NEW, ProxyGenerator::JL_ILLEGAL_ACCESS_EX);
	mv->visitInsn(89);
	mv->visitVarInsn(25, 0);
	mv->visitMethodInsn(182, ProxyGenerator::JLI_LOOKUP, "toString"_s, "()Ljava/lang/String;"_s, false);
	mv->visitMethodInsn(183, ProxyGenerator::JL_ILLEGAL_ACCESS_EX, "<init>"_s, "(Ljava/lang/String;)V"_s, false);
	mv->visitInsn(191);
	mv->visitMaxs(-1, -1);
	mv->visitEnd();
}

$List* ProxyGenerator::lambda$addProxyMethod$0($String* f) {
	$init(ProxyGenerator);
	return $new($ArrayList, 3);
}

void clinit$ProxyGenerator($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(ProxyGenerator::JL_CLASS, "java/lang/Class"_s);
	$assignStatic(ProxyGenerator::JL_OBJECT, "java/lang/Object"_s);
	$assignStatic(ProxyGenerator::JL_THROWABLE, "java/lang/Throwable"_s);
	$assignStatic(ProxyGenerator::JL_CLASS_NOT_FOUND_EX, "java/lang/ClassNotFoundException"_s);
	$assignStatic(ProxyGenerator::JL_ILLEGAL_ACCESS_EX, "java/lang/IllegalAccessException"_s);
	$assignStatic(ProxyGenerator::JL_NO_CLASS_DEF_FOUND_ERROR, "java/lang/NoClassDefFoundError"_s);
	$assignStatic(ProxyGenerator::JL_NO_SUCH_METHOD_EX, "java/lang/NoSuchMethodException"_s);
	$assignStatic(ProxyGenerator::JL_NO_SUCH_METHOD_ERROR, "java/lang/NoSuchMethodError"_s);
	$assignStatic(ProxyGenerator::JLI_LOOKUP, "java/lang/invoke/MethodHandles$Lookup"_s);
	$assignStatic(ProxyGenerator::JLI_METHODHANDLES, "java/lang/invoke/MethodHandles"_s);
	$assignStatic(ProxyGenerator::JLR_INVOCATION_HANDLER, "java/lang/reflect/InvocationHandler"_s);
	$assignStatic(ProxyGenerator::JLR_PROXY, "java/lang/reflect/Proxy"_s);
	$assignStatic(ProxyGenerator::JLR_UNDECLARED_THROWABLE_EX, "java/lang/reflect/UndeclaredThrowableException"_s);
	$assignStatic(ProxyGenerator::LJL_CLASS, "Ljava/lang/Class;"_s);
	$assignStatic(ProxyGenerator::LJLR_METHOD, "Ljava/lang/reflect/Method;"_s);
	$assignStatic(ProxyGenerator::LJLR_INVOCATION_HANDLER, "Ljava/lang/reflect/InvocationHandler;"_s);
	$assignStatic(ProxyGenerator::MJLR_INVOCATIONHANDLER, "(Ljava/lang/reflect/InvocationHandler;)V"_s);
	$assignStatic(ProxyGenerator::NAME_CTOR, "<init>"_s);
	$assignStatic(ProxyGenerator::NAME_CLINIT, "<clinit>"_s);
	$assignStatic(ProxyGenerator::NAME_LOOKUP_ACCESSOR, "proxyClassLookup"_s);
	$assignStatic(ProxyGenerator::handlerFieldName, "h"_s);
	$beforeCallerSensitive();
	ProxyGenerator::$assertionsDisabled = !ProxyGenerator::class$->desiredAssertionStatus();
	$assignStatic(ProxyGenerator::EMPTY_CLASS_ARRAY, $new($ClassArray, 0));
	ProxyGenerator::saveGeneratedFiles = $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GetBooleanAction, "jdk.proxy.ProxyGenerator.saveGeneratedFiles"_s)))))))->booleanValue();
	{
		try {
			$assignStatic(ProxyGenerator::hashCodeMethod, $new($ProxyGenerator$ProxyMethod, $($Object::class$->getMethod("hashCode"_s, $$new($ClassArray, 0))), "m0"_s));
			$assignStatic(ProxyGenerator::equalsMethod, $new($ProxyGenerator$ProxyMethod, $($Object::class$->getMethod("equals"_s, $$new($ClassArray, {$Object::class$}))), "m1"_s));
			$assignStatic(ProxyGenerator::toStringMethod, $new($ProxyGenerator$ProxyMethod, $($Object::class$->getMethod("toString"_s, $$new($ClassArray, 0))), "m2"_s));
		} catch ($NoSuchMethodException& e) {
			$throwNew($NoSuchMethodError, $(e->getMessage()));
		}
	}
}

ProxyGenerator::ProxyGenerator() {
}

$Class* ProxyGenerator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ProxyGenerator$$Lambda$lambda$addProxyMethod$0::classInfo$.name)) {
			return ProxyGenerator$$Lambda$lambda$addProxyMethod$0::load$(name, initialize);
		}
	}
	$loadClass(ProxyGenerator, name, initialize, &_ProxyGenerator_ClassInfo_, clinit$ProxyGenerator, allocate$ProxyGenerator);
	return class$;
}

$Class* ProxyGenerator::class$ = nullptr;

		} // reflect
	} // lang
} // java
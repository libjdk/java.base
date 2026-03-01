#include <TestSynchronization.h>

#include <TestSynchronization$1.h>
#include <TestSynchronization$InvokeTask.h>
#include <TestSynchronization$MyTestClass.h>
#include <TestSynchronization$TestFailedException.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Runnable.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/Thread$State.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef BOOLEAN_VAL
#undef CHAR_ARRAY_VAL
#undef CHAR_SEQUENCE_VAL
#undef CHAR_VAL
#undef DOUBLE_VAL
#undef FLOAT_VAL
#undef INT_VAL
#undef LONG_VAL
#undef OBJECT_VAL
#undef STRING_BUFFER_VAL
#undef STRING_BUILDER_VAL
#undef STRING_VAL
#undef TYPE

using $TestSynchronization$1 = ::TestSynchronization$1;
using $TestSynchronization$InvokeTask = ::TestSynchronization$InvokeTask;
using $TestSynchronization$MyTestClass = ::TestSynchronization$MyTestClass;
using $TestSynchronization$TestFailedException = ::TestSynchronization$TestFailedException;
using $CharSequenceArray = $Array<::java::lang::CharSequence>;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InterruptedException = ::java::lang::InterruptedException;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $StringBuffer = ::java::lang::StringBuffer;
using $Thread$State = ::java::lang::Thread$State;
using $Constructor = ::java::lang::reflect::Constructor;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$FieldInfo _TestSynchronization_FieldInfo_[] = {
	{"BOOLEAN_VAL", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TestSynchronization, BOOLEAN_VAL)},
	{"CHAR_VAL", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TestSynchronization, CHAR_VAL)},
	{"CHAR_ARRAY_VAL", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TestSynchronization, CHAR_ARRAY_VAL)},
	{"INT_VAL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TestSynchronization, INT_VAL)},
	{"DOUBLE_VAL", "D", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TestSynchronization, DOUBLE_VAL)},
	{"FLOAT_VAL", "F", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TestSynchronization, FLOAT_VAL)},
	{"LONG_VAL", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(TestSynchronization, LONG_VAL)},
	{"OBJECT_VAL", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TestSynchronization, OBJECT_VAL)},
	{"STRING_VAL", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TestSynchronization, STRING_VAL)},
	{"STRING_BUILDER_VAL", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TestSynchronization, STRING_BUILDER_VAL)},
	{"STRING_BUFFER_VAL", "Ljava/lang/StringBuffer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TestSynchronization, STRING_BUFFER_VAL)},
	{"CHAR_SEQUENCE_VAL", "[Ljava/lang/CharSequence;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(TestSynchronization, CHAR_SEQUENCE_VAL)},
	{}
};

$MethodInfo _TestSynchronization_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TestSynchronization, init$, void)},
	{"invokeMethod", "(Ljava/lang/Class;Ljava/lang/reflect/Method;[Ljava/lang/Object;)V", "(Ljava/lang/Class<*>;Ljava/lang/reflect/Method;[Ljava/lang/Object;)V", $PRIVATE | $STATIC, $staticMethod(TestSynchronization, invokeMethod, void, $Class*, $Method*, $ObjectArray*), "TestSynchronization$TestFailedException,java.lang.Exception"},
	{"isSynchronized", "(Ljava/lang/reflect/Method;Ljava/lang/Object;[Ljava/lang/Object;)Z", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(TestSynchronization, isSynchronized, bool, $Method*, Object$*, $ObjectArray*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(TestSynchronization, main, void, $StringArray*), "java.lang.Exception"},
	{"testClass", "(Ljava/lang/Class;Z)V", "(Ljava/lang/Class<*>;Z)V", $PRIVATE | $STATIC, $staticMethod(TestSynchronization, testClass, void, $Class*, bool), "java.lang.Exception"},
	{"testMethod", "(Ljava/lang/Class;Ljava/lang/reflect/Method;)V", "(Ljava/lang/Class<*>;Ljava/lang/reflect/Method;)V", $PRIVATE | $STATIC, $staticMethod(TestSynchronization, testMethod, void, $Class*, $Method*), "java.lang.Exception"},
	{}
};

$InnerClassInfo _TestSynchronization_InnerClassesInfo_[] = {
	{"TestSynchronization$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"TestSynchronization$MyTestClass", "TestSynchronization", "MyTestClass", $PRIVATE | $STATIC},
	{"TestSynchronization$InvokeTask", "TestSynchronization", "InvokeTask", $STATIC},
	{"TestSynchronization$TestFailedException", "TestSynchronization", "TestFailedException", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _TestSynchronization_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"TestSynchronization",
	"java.lang.Object",
	nullptr,
	_TestSynchronization_FieldInfo_,
	_TestSynchronization_MethodInfo_,
	nullptr,
	nullptr,
	_TestSynchronization_InnerClassesInfo_,
	nullptr,
	nullptr,
	"TestSynchronization$1,TestSynchronization$MyTestClass,TestSynchronization$InvokeTask,TestSynchronization$TestFailedException"
};

$Object* allocate$TestSynchronization($Class* clazz) {
	return $of($alloc(TestSynchronization));
}

$chars* TestSynchronization::CHAR_ARRAY_VAL = nullptr;
double TestSynchronization::DOUBLE_VAL = 0.0;
float TestSynchronization::FLOAT_VAL = 0.0;
$Object* TestSynchronization::OBJECT_VAL = nullptr;
$String* TestSynchronization::STRING_VAL = nullptr;
$StringBuilder* TestSynchronization::STRING_BUILDER_VAL = nullptr;
$StringBuffer* TestSynchronization::STRING_BUFFER_VAL = nullptr;
$CharSequenceArray* TestSynchronization::CHAR_SEQUENCE_VAL = nullptr;

void TestSynchronization::init$() {
}

void TestSynchronization::main($StringArray* args) {
	$init(TestSynchronization);
	$load($TestSynchronization$MyTestClass);
	testClass($TestSynchronization$MyTestClass::class$, true);
	$load($StringBuffer);
	testClass($StringBuffer::class$, false);
}

void TestSynchronization::testClass($Class* aClass, bool isSelfTest) {
	$init(TestSynchronization);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($List, methods, $Arrays::asList($($nc(aClass)->getDeclaredMethods())));
	{
		$var($Iterator, i$, $nc(methods)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Method, m, $cast($Method, i$->next()));
			{
				if ($nc(m)->isSynthetic()) {
					continue;
				}
				int32_t modifiers = $nc(m)->getModifiers();
				bool var$0 = $Modifier::isPublic(modifiers);
				if (var$0 && !$Modifier::isSynchronized(modifiers)) {
					try {
						testMethod(aClass, m);
					} catch ($TestSynchronization$TestFailedException& e) {
						if (isSelfTest) {
							$var($String, methodName, $nc($(e->getMethod()))->getName());
							{
								$var($String, s4812$, methodName);
								int32_t tmp4812$ = -1;
								switch ($nc(s4812$)->hashCode()) {
								case (int32_t)0xE55C9F1D:
									{
										if (s4812$->equals("should_pass"_s)) {
											tmp4812$ = 0;
										}
										break;
									}
								case (int32_t)0xE558122A:
									{
										if (s4812$->equals("should_fail"_s)) {
											tmp4812$ = 1;
										}
										break;
									}
								}
								switch (tmp4812$) {
								case 0:
									{
										$throwNew($RuntimeException, "Test failed: self-test failed.  The \'should_pass\' method did not pass the synchronization test. Check the test code."_s);
									}
								case 1:
									{
										break;
									}
								default:
									{
										$throwNew($RuntimeException, $$str({"Test failed: something is amiss with the test. A TestFailedException was generated on a call to "_s, methodName, " which we didn\'t expect to test in the first place."_s}));
									}
								}
							}
						} else {
							$throwNew($RuntimeException, $$str({"Test failed: the method "_s, $($nc($(e->getMethod()))->toString()), " should be synchronized, but isn\'t."_s}));
						}
					}
				}
			}
		}
	}
}

void TestSynchronization::invokeMethod($Class* aClass, $Method* m, $ObjectArray* args) {
	$init(TestSynchronization);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Constructor, objConstructor, nullptr);
	$var($Object, obj, nullptr);
	$assign(objConstructor, $nc(aClass)->getConstructor($$new($ClassArray, {$String::class$})));
	$assign(obj, $nc(objConstructor)->newInstance($$new($ObjectArray, {$of("LeftPalindrome-emordnilaP-thgiR"_s)})));
	if (!isSynchronized(m, obj, args)) {
		$throwNew($TestSynchronization$TestFailedException, m);
	}
}

void TestSynchronization::testMethod($Class* aClass, $Method* m) {
	$init(TestSynchronization);
	$useLocalCurrentObjectStackCache();
	$var($ClassArray, pTypes, $nc(m)->getParameterTypes());
	$var($List, charSequenceArgs, $new($ArrayList));
	$var($ObjectArray, args, $new($ObjectArray, $nc(pTypes)->length));
	for (int32_t i = 0; i < pTypes->length; ++i) {
		$Class* pType = pTypes->get(i);
		$init($Boolean);
		if ($nc($of(pType))->equals($Boolean::TYPE)) {
			args->set(i, $($Boolean::valueOf(TestSynchronization::BOOLEAN_VAL)));
		} else {
			$init($Character);
			if ($of(pType)->equals($Character::TYPE)) {
				args->set(i, $($Character::valueOf(TestSynchronization::CHAR_VAL)));
			} else {
				$init($Integer);
				if ($of(pType)->equals($Integer::TYPE)) {
					args->set(i, $($Integer::valueOf(TestSynchronization::INT_VAL)));
				} else {
					$init($Double);
					if ($of(pType)->equals($Double::TYPE)) {
						args->set(i, $($Double::valueOf(TestSynchronization::DOUBLE_VAL)));
					} else {
						$init($Float);
						if ($of(pType)->equals($Float::TYPE)) {
							args->set(i, $($Float::valueOf(TestSynchronization::FLOAT_VAL)));
						} else {
							$init($Long);
							if ($of(pType)->equals($Long::TYPE)) {
								args->set(i, $($Long::valueOf(TestSynchronization::LONG_VAL)));
							} else if ($of(pType)->equals($Object::class$)) {
								args->set(i, TestSynchronization::OBJECT_VAL);
							} else {
								$load($StringBuilder);
								if ($of(pType)->equals($StringBuilder::class$)) {
									args->set(i, TestSynchronization::STRING_BUILDER_VAL);
								} else {
									$load($StringBuffer);
									if ($of(pType)->equals($StringBuffer::class$)) {
										args->set(i, TestSynchronization::STRING_BUFFER_VAL);
									} else if ($of(pType)->equals($String::class$)) {
										args->set(i, TestSynchronization::STRING_VAL);
									} else {
										bool var$1 = pType->isArray();
										if (var$1 && $nc($of(pType->getComponentType()))->equals($Character::TYPE)) {
											args->set(i, TestSynchronization::CHAR_ARRAY_VAL);
										} else {
											$load($CharSequence);
											if ($of(pType)->equals($CharSequence::class$)) {
												charSequenceArgs->add($$new($Integer, i));
											} else {
												$throwNew($RuntimeException, $$str({"Test Failed: not accounting for method call with parameter type of "_s, $(pType->getName()), " You must update the test."_s}));
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (charSequenceArgs->isEmpty()) {
		invokeMethod(aClass, m, args);
	} else {
		if (charSequenceArgs->size() > 1) {
			$throwNew($RuntimeException, $$str({"Test Failed: the test cannot handle a method with multiple CharSequence arguments.  You must update the test to handle the method "_s, $(m->toString())}));
		}
		for (int32_t j = 0; j < $nc(TestSynchronization::CHAR_SEQUENCE_VAL)->length; ++j) {
			args->set($nc(($cast($Integer, $(charSequenceArgs->get(0)))))->intValue(), $nc(TestSynchronization::CHAR_SEQUENCE_VAL)->get(j));
			invokeMethod(aClass, m, args);
		}
	}
}

bool TestSynchronization::isSynchronized($Method* m, Object$* target, $ObjectArray* args) {
	$init(TestSynchronization);
	$useLocalCurrentObjectStackCache();
	$var($Thread, t, $new($Thread, static_cast<$Runnable*>($$new($TestSynchronization$InvokeTask, m, target, args))));
	$var($Boolean, isSynchronized, nullptr);
	$synchronized(target) {
		t->start();
		while (isSynchronized == nullptr) {
			$init($TestSynchronization$1);
			switch ($nc($TestSynchronization$1::$SwitchMap$java$lang$Thread$State)->get($nc(($(t->getState())))->ordinal())) {
			case 1:
				{}
			case 2:
				{}
			case 3:
				{}
			case 4:
				{
					$Thread::yield();
					break;
				}
			case 5:
				{
					$assign(isSynchronized, $Boolean::valueOf(true));
					break;
				}
			case 6:
				{
					$assign(isSynchronized, $Boolean::valueOf(false));
					break;
				}
			}
		}
	}
	try {
		t->join();
	} catch ($InterruptedException& ex) {
		ex->printStackTrace();
	}
	return $nc(isSynchronized)->booleanValue();
}

void clinit$TestSynchronization($Class* class$) {
	TestSynchronization::DOUBLE_VAL = 1.0;
	TestSynchronization::FLOAT_VAL = 1.0f;
	$assignStatic(TestSynchronization::STRING_VAL, "String value"_s);
	$assignStatic(TestSynchronization::CHAR_ARRAY_VAL, $new($chars, {
		u'c',
		u'h',
		u'a',
		u'r',
		u'a',
		u'r',
		u'r',
		u'a',
		u'y'
	}));
	$assignStatic(TestSynchronization::OBJECT_VAL, $new($Object));
	$assignStatic(TestSynchronization::STRING_BUILDER_VAL, $new($StringBuilder, "StringBuilder value"_s));
	$assignStatic(TestSynchronization::STRING_BUFFER_VAL, $new($StringBuffer, "StringBuffer value"_s));
	$assignStatic(TestSynchronization::CHAR_SEQUENCE_VAL, $new($CharSequenceArray, {
		static_cast<$CharSequence*>(TestSynchronization::STRING_VAL),
		static_cast<$CharSequence*>(TestSynchronization::STRING_BUILDER_VAL),
		static_cast<$CharSequence*>(TestSynchronization::STRING_BUFFER_VAL)
	}));
}

TestSynchronization::TestSynchronization() {
}

$Class* TestSynchronization::load$($String* name, bool initialize) {
	$loadClass(TestSynchronization, name, initialize, &_TestSynchronization_ClassInfo_, clinit$TestSynchronization, allocate$TestSynchronization);
	return class$;
}

$Class* TestSynchronization::class$ = nullptr;
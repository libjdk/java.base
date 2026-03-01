#include <LegacyChainedExceptionSerialization.h>

#include <LegacyChainedExceptionSerialization$SubClass.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Error.h>
#include <java/lang/ExceptionInInitializerError.h>
#include <java/lang/reflect/InvocationTargetException.h>
#include <java/lang/reflect/UndeclaredThrowableException.h>
#include <java/security/PrivilegedActionException.h>
#include <java/util/Base64$Decoder.h>
#include <java/util/Base64.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef CNFE_OLD_VERSION
#undef EIIE_OLD_VERSION
#undef ITE1_OLD_VERSION
#undef ITE2_OLD_VERSION
#undef PAE_OLD_VERSION
#undef SERIALIZED_DATA
#undef UTE1_OLD_VERSION
#undef UTE2_OLD_VERSION

using $LegacyChainedExceptionSerialization$SubClass = ::LegacyChainedExceptionSerialization$SubClass;
using $ThrowableArray = $Array<::java::lang::Throwable>;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $ExceptionInInitializerError = ::java::lang::ExceptionInInitializerError;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $InvocationTargetException = ::java::lang::reflect::InvocationTargetException;
using $UndeclaredThrowableException = ::java::lang::reflect::UndeclaredThrowableException;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $Base64 = ::java::util::Base64;
using $Base64$Decoder = ::java::util::Base64$Decoder;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;

$FieldInfo _LegacyChainedExceptionSerialization_FieldInfo_[] = {
	{"broken", "[Ljava/lang/Throwable;", nullptr, $PRIVATE | $STATIC, $staticField(LegacyChainedExceptionSerialization, broken)},
	{"EIIE_OLD_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LegacyChainedExceptionSerialization, EIIE_OLD_VERSION)},
	{"CNFE_OLD_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LegacyChainedExceptionSerialization, CNFE_OLD_VERSION)},
	{"ITE1_OLD_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LegacyChainedExceptionSerialization, ITE1_OLD_VERSION)},
	{"ITE2_OLD_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LegacyChainedExceptionSerialization, ITE2_OLD_VERSION)},
	{"UTE1_OLD_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LegacyChainedExceptionSerialization, UTE1_OLD_VERSION)},
	{"UTE2_OLD_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LegacyChainedExceptionSerialization, UTE2_OLD_VERSION)},
	{"PAE_OLD_VERSION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LegacyChainedExceptionSerialization, PAE_OLD_VERSION)},
	{"SERIALIZED_DATA", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Throwable;>;", $PRIVATE | $STATIC, $staticField(LegacyChainedExceptionSerialization, SERIALIZED_DATA)},
	{}
};

$MethodInfo _LegacyChainedExceptionSerialization_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LegacyChainedExceptionSerialization, init$, void)},
	{"deserialize", "(Ljava/lang/String;)Ljava/lang/Throwable;", nullptr, $PRIVATE | $STATIC, $staticMethod(LegacyChainedExceptionSerialization, deserialize, $Throwable*, $String*), "java.lang.Exception"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(LegacyChainedExceptionSerialization, main, void, $StringArray*), "java.lang.Exception"},
	{"test", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;", nullptr, $PRIVATE | $STATIC, $staticMethod(LegacyChainedExceptionSerialization, test, $Throwable*, $Throwable*), "java.lang.Exception"},
	{"testOverriddenGetCause", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(LegacyChainedExceptionSerialization, testOverriddenGetCause, void), "java.lang.Exception"},
	{"verify", "(Ljava/lang/Throwable;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(LegacyChainedExceptionSerialization, verify, void, $Throwable*, $Throwable*)},
	{}
};

$InnerClassInfo _LegacyChainedExceptionSerialization_InnerClassesInfo_[] = {
	{"LegacyChainedExceptionSerialization$SubClass", "LegacyChainedExceptionSerialization", "SubClass", $STATIC},
	{}
};

$ClassInfo _LegacyChainedExceptionSerialization_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"LegacyChainedExceptionSerialization",
	"java.lang.Object",
	nullptr,
	_LegacyChainedExceptionSerialization_FieldInfo_,
	_LegacyChainedExceptionSerialization_MethodInfo_,
	nullptr,
	nullptr,
	_LegacyChainedExceptionSerialization_InnerClassesInfo_,
	nullptr,
	nullptr,
	"LegacyChainedExceptionSerialization$SubClass"
};

$Object* allocate$LegacyChainedExceptionSerialization($Class* clazz) {
	return $of($alloc(LegacyChainedExceptionSerialization));
}

$ThrowableArray* LegacyChainedExceptionSerialization::broken = nullptr;
$String* LegacyChainedExceptionSerialization::EIIE_OLD_VERSION = nullptr;
$String* LegacyChainedExceptionSerialization::CNFE_OLD_VERSION = nullptr;
$String* LegacyChainedExceptionSerialization::ITE1_OLD_VERSION = nullptr;
$String* LegacyChainedExceptionSerialization::ITE2_OLD_VERSION = nullptr;
$String* LegacyChainedExceptionSerialization::UTE1_OLD_VERSION = nullptr;
$String* LegacyChainedExceptionSerialization::UTE2_OLD_VERSION = nullptr;
$String* LegacyChainedExceptionSerialization::PAE_OLD_VERSION = nullptr;
$Map* LegacyChainedExceptionSerialization::SERIALIZED_DATA = nullptr;

void LegacyChainedExceptionSerialization::init$() {
}

void LegacyChainedExceptionSerialization::main($StringArray* args) {
	$init(LegacyChainedExceptionSerialization);
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < $nc(LegacyChainedExceptionSerialization::broken)->length; ++i) {
		test($nc(LegacyChainedExceptionSerialization::broken)->get(i));
	}
	{
		$var($Iterator, i$, $nc($($nc(LegacyChainedExceptionSerialization::SERIALIZED_DATA)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($Throwable, t, deserialize($cast($String, $($nc(e)->getKey()))));
				verify(t, $cast($Throwable, $($nc(e)->getValue())));
			}
		}
	}
	testOverriddenGetCause();
}

$Throwable* LegacyChainedExceptionSerialization::test($Throwable* e) {
	$init(LegacyChainedExceptionSerialization);
	$useLocalCurrentObjectStackCache();
	$var($ByteArrayOutputStream, bout, $new($ByteArrayOutputStream));
	$var($ObjectOutputStream, out, $new($ObjectOutputStream, bout));
	out->writeObject(e);
	out->flush();
	$var($ByteArrayInputStream, bin, $new($ByteArrayInputStream, $(bout->toByteArray())));
	$var($ObjectInputStream, in, $new($ObjectInputStream, bin));
	$var($Throwable, clone, $cast($Throwable, in->readObject()));
	return clone;
}

void LegacyChainedExceptionSerialization::testOverriddenGetCause() {
	$init(LegacyChainedExceptionSerialization);
	$useLocalCurrentObjectStackCache();
	$var($LegacyChainedExceptionSerialization$SubClass, sc, $new($LegacyChainedExceptionSerialization$SubClass, $$new($NullPointerException)));
	$var($LegacyChainedExceptionSerialization$SubClass, clone, $cast($LegacyChainedExceptionSerialization$SubClass, test(sc)));
	$var($Throwable, cause, $nc(clone)->getException());
	if (!($instanceOf($NullPointerException, cause)) || $nc(cause)->getMessage() != nullptr) {
		$throwNew($RuntimeException, $$str({"unexpected cause: "_s, cause}));
	}
}

$Throwable* LegacyChainedExceptionSerialization::deserialize($String* ser) {
	$init(LegacyChainedExceptionSerialization);
	$useLocalCurrentObjectStackCache();
	$var($Base64$Decoder, decoder, $Base64::getDecoder());
	{
		$var($ByteArrayInputStream, bin, $new($ByteArrayInputStream, $($nc(decoder)->decode(ser))));
		{
			$var($Throwable, var$0, nullptr);
			$var($Throwable, var$2, nullptr);
			bool return$1 = false;
			try {
				try {
					$var($ObjectInputStream, ois, $new($ObjectInputStream, bin));
					{
						$var($Throwable, var$3, nullptr);
						$var($Throwable, var$5, nullptr);
						bool return$4 = false;
						try {
							try {
								$assign(var$5, $cast($Throwable, ois->readObject()));
								return$4 = true;
								goto $finally1;
							} catch ($Throwable& t$) {
								try {
									ois->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$6) {
							$assign(var$3, var$6);
						} $finally1: {
							ois->close();
						}
						if (var$3 != nullptr) {
							$throw(var$3);
						}
						if (return$4) {
							$assign(var$2, var$5);
							return$1 = true;
							goto $finally;
						}
					}
				} catch ($Throwable& t$) {
					try {
						bin->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$7) {
				$assign(var$0, var$7);
			} $finally: {
				bin->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

void LegacyChainedExceptionSerialization::verify($Throwable* t, $Throwable* expected) {
	$init(LegacyChainedExceptionSerialization);
	$useLocalCurrentObjectStackCache();
	$var($String, msg, $nc(expected)->getMessage());
	$var($Throwable, cause, expected->getCause());
	bool var$0 = $nc(t)->getMessage() != msg && msg != nullptr;
	if (var$0 && !msg->equals($(t->getMessage()))) {
		$throwNew($RuntimeException, $$str({"unexpected message: "_s, $(t->getMessage()), " expected: "_s, msg}));
	}
	$var($Throwable, e, $nc(t)->getCause());
	if ($nc($of(e))->getClass() != $nc($of(cause))->getClass()) {
		$throwNew($RuntimeException, $$str({"unexpected cause: "_s, $(t->getCause())}));
	}
	$var($String, causedBy, $nc(cause)->getMessage());
	if ($nc(e)->getMessage() != causedBy) {
		bool var$1 = e->getMessage() == nullptr || causedBy == nullptr;
		if (var$1 || !$nc(causedBy)->equals($(e->getMessage()))) {
			$throwNew($RuntimeException, $$str({"unexpected message: "_s, $(t->getMessage()), " expected: "_s, causedBy}));
		}
	}
	$var($Throwable, exception, nullptr);
	if ($instanceOf($ExceptionInInitializerError, t)) {
		$assign(exception, $nc(($cast($ExceptionInInitializerError, t)))->getException());
	} else if ($instanceOf($ClassNotFoundException, t)) {
		$assign(exception, $nc(($cast($ClassNotFoundException, t)))->getException());
	} else if ($instanceOf($InvocationTargetException, t)) {
		$assign(exception, $nc(($cast($InvocationTargetException, t)))->getTargetException());
	} else if ($instanceOf($UndeclaredThrowableException, t)) {
		$assign(exception, $nc(($cast($UndeclaredThrowableException, t)))->getUndeclaredThrowable());
	} else if ($instanceOf($PrivilegedActionException, t)) {
		$assign(exception, $nc(($cast($PrivilegedActionException, t)))->getException());
	} else {
		$assign(e, nullptr);
	}
	if (e != exception) {
		$throwNew($RuntimeException, $$str({"unexpected exception: "_s, exception}));
	}
}

void clinit$LegacyChainedExceptionSerialization($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(LegacyChainedExceptionSerialization::EIIE_OLD_VERSION, "rO0ABXNyACVqYXZhLmxhbmcuRXhjZXB0aW9uSW5Jbml0aWFsaXplckVycm9yFR400Amhk4ACAAFMAAlleGNlcHRpb250ABVMamF2YS9sYW5nL1Rocm93YWJsZTt4cgAWamF2YS5sYW5nLkxpbmthZ2VFcnJvcjGtS1U0qEq6AgAAeHIAD2phdmEubGFuZy5FcnJvckUdNlaLgg5WAgAAeHIAE2phdmEubGFuZy5UaHJvd2FibGXVxjUnOXe4ywMABEwABWNhdXNlcQB+AAFMAA1kZXRhaWxNZXNzYWdldAASTGphdmEvbGFuZy9TdHJpbmc7WwAKc3RhY2tUcmFjZXQAHltMamF2YS9sYW5nL1N0YWNrVHJhY2VFbGVtZW50O0wAFHN1cHByZXNzZWRFeGNlcHRpb25zdAAQTGphdmEvdXRpbC9MaXN0O3hwcHB1cgAeW0xqYXZhLmxhbmcuU3RhY2tUcmFjZUVsZW1lbnQ7AkYqPDz9IjkCAAB4cAAAAAFzcgAbamF2YS5sYW5nLlN0YWNrVHJhY2VFbGVtZW50YQnFmiY23YUCAAhCAAZmb3JtYXRJAApsaW5lTnVtYmVyTAAPY2xhc3NMb2FkZXJOYW1lcQB+AAVMAA5kZWNsYXJpbmdDbGFzc3EAfgAFTAAIZmlsZU5hbWVxAH4ABUwACm1ldGhvZE5hbWVxAH4ABUwACm1vZHVsZU5hbWVxAH4ABUwADW1vZHVsZVZlcnNpb25xAH4ABXhwAQAAAAd0AANhcHB0AARUZXN0dAAJVGVzdC5qYXZhdAAEbWFpbnBwc3IAH2phdmEudXRpbC5Db2xsZWN0aW9ucyRFbXB0eUxpc3R6uBe0PKee3gIAAHhweHNyAB5qYXZhLmxhbmcuTnVsbFBvaW50ZXJFeGNlcHRpb25HpaGO/zHhuAIAAHhyABpqYXZhLmxhbmcuUnVudGltZUV4Y2VwdGlvbp5fBkcKNIPlAgAAeHIAE2phdmEubGFuZy5FeGNlcHRpb27Q"
		"/R8+GjscxAIAAHhxAH4ABHEAfgAWdAADZm9vdXEAfgAJAAAAAXNxAH4ACwEAAAAHcQB+AA1xAH4ADnEAfgAPcQB+ABBwcHEAfgASeA=="_s);
	$assignStatic(LegacyChainedExceptionSerialization::CNFE_OLD_VERSION, "rO0ABXNyACBqYXZhLmxhbmcuQ2xhc3NOb3RGb3VuZEV4Y2VwdGlvbn9azWY+1CCOAgABTAACZXh0ABVMamF2YS9sYW5nL1Rocm93YWJsZTt4cgAmamF2YS5sYW5nLlJlZmxlY3RpdmVPcGVyYXRpb25FeGNlcHRpb24AAAAAB1vNFQIAAHhyABNqYXZhLmxhbmcuRXhjZXB0aW9u0P0fPho7HMQCAAB4cgATamF2YS5sYW5nLlRocm93YWJsZdXGNSc5d7jLAwAETAAFY2F1c2VxAH4AAUwADWRldGFpbE1lc3NhZ2V0ABJMamF2YS9sYW5nL1N0cmluZztbAApzdGFja1RyYWNldAAeW0xqYXZhL2xhbmcvU3RhY2tUcmFjZUVsZW1lbnQ7TAAUc3VwcHJlc3NlZEV4Y2VwdGlvbnN0ABBMamF2YS91dGlsL0xpc3Q7eHBwdAADYmFydXIAHltMamF2YS5sYW5nLlN0YWNrVHJhY2VFbGVtZW50OwJGKjw8/SI5AgAAeHAAAAABc3IAG2phdmEubGFuZy5TdGFja1RyYWNlRWxlbWVudGEJxZomNt2FAgAIQgAGZm9ybWF0SQAKbGluZU51bWJlckwAD2NsYXNzTG9hZGVyTmFtZXEAfgAFTAAOZGVjbGFyaW5nQ2xhc3NxAH4ABUwACGZpbGVOYW1lcQB+AAVMAAptZXRob2ROYW1lcQB+AAVMAAptb2R1bGVOYW1lcQB+AAVMAA1tb2R1bGVWZXJzaW9ucQB+AAV4cAEAAAAMdAADYXBwdAAEVGVzdHQACVRlc3QuamF2YXQABG1haW5wcHNyAB9qYXZhLnV0aWwuQ29sbGVjdGlvbnMkRW1wdHlMaXN0ergXtDynnt4CAAB4cHhzcgATamF2YS5pby5JT0V4Y2VwdGlvbmyAc2RlJfCrAgAAeHEAfgADcQB+ABV0ABJyZWFkaW5nIGNsYXNzIGZpbGV1cQB+AAoAAAABc3EAfgAMAQAAAAxxAH4ADnEAfgAP"
		"cQB+ABBxAH4AEXBwcQB+ABN4"_s);
	$assignStatic(LegacyChainedExceptionSerialization::ITE1_OLD_VERSION, "rO0ABXNyACtqYXZhLmxhbmcucmVmbGVjdC5JbnZvY2F0aW9uVGFyZ2V0RXhjZXB0aW9uOLEmjtZxJG8CAAFMAAZ0YXJnZXR0ABVMamF2YS9sYW5nL1Rocm93YWJsZTt4cgAmamF2YS5sYW5nLlJlZmxlY3RpdmVPcGVyYXRpb25FeGNlcHRpb24AAAAAB1vNFQIAAHhyABNqYXZhLmxhbmcuRXhjZXB0aW9u0P0fPho7HMQCAAB4cgATamF2YS5sYW5nLlRocm93YWJsZdXGNSc5d7jLAwAETAAFY2F1c2VxAH4AAUwADWRldGFpbE1lc3NhZ2V0ABJMamF2YS9sYW5nL1N0cmluZztbAApzdGFja1RyYWNldAAeW0xqYXZhL2xhbmcvU3RhY2tUcmFjZUVsZW1lbnQ7TAAUc3VwcHJlc3NlZEV4Y2VwdGlvbnN0ABBMamF2YS91dGlsL0xpc3Q7eHBwdAADYmFydXIAHltMamF2YS5sYW5nLlN0YWNrVHJhY2VFbGVtZW50OwJGKjw8/SI5AgAAeHAAAAABc3IAG2phdmEubGFuZy5TdGFja1RyYWNlRWxlbWVudGEJxZomNt2FAgAIQgAGZm9ybWF0SQAKbGluZU51bWJlckwAD2NsYXNzTG9hZGVyTmFtZXEAfgAFTAAOZGVjbGFyaW5nQ2xhc3NxAH4ABUwACGZpbGVOYW1lcQB+AAVMAAptZXRob2ROYW1lcQB+AAVMAAptb2R1bGVOYW1lcQB+AAVMAA1tb2R1bGVWZXJzaW9ucQB+AAV4cAEAAAARdAADYXBwdAAEVGVzdHQACVRlc3QuamF2YXQABG1haW5wcHNyAB9qYXZhLnV0aWwuQ29sbGVjdGlvbnMkRW1wdHlMaXN0ergXtDynnt4CAAB4cHhzcgAPamF2YS5sYW5nLkVycm9yRR02VouCDlYCAAB4cQB+AARxAH4AFXQAA2Zvb3VxAH4ACgAAAAFzcQB+AAwBAAAAEXEAfgAOcQB+AA9xAH4A"
		"EHEAfgARcHBxAH4AE3g="_s);
	$assignStatic(LegacyChainedExceptionSerialization::ITE2_OLD_VERSION, "rO0ABXNyACtqYXZhLmxhbmcucmVmbGVjdC5JbnZvY2F0aW9uVGFyZ2V0RXhjZXB0aW9uOLEmjtZxJG8CAAFMAAZ0YXJnZXR0ABVMamF2YS9sYW5nL1Rocm93YWJsZTt4cgAmamF2YS5sYW5nLlJlZmxlY3RpdmVPcGVyYXRpb25FeGNlcHRpb24AAAAAB1vNFQIAAHhyABNqYXZhLmxhbmcuRXhjZXB0aW9u0P0fPho7HMQCAAB4cgATamF2YS5sYW5nLlRocm93YWJsZdXGNSc5d7jLAwAETAAFY2F1c2VxAH4AAUwADWRldGFpbE1lc3NhZ2V0ABJMamF2YS9sYW5nL1N0cmluZztbAApzdGFja1RyYWNldAAeW0xqYXZhL2xhbmcvU3RhY2tUcmFjZUVsZW1lbnQ7TAAUc3VwcHJlc3NlZEV4Y2VwdGlvbnN0ABBMamF2YS91dGlsL0xpc3Q7eHBwcHVyAB5bTGphdmEubGFuZy5TdGFja1RyYWNlRWxlbWVudDsCRio8PP0iOQIAAHhwAAAAAXNyABtqYXZhLmxhbmcuU3RhY2tUcmFjZUVsZW1lbnRhCcWaJjbdhQIACEIABmZvcm1hdEkACmxpbmVOdW1iZXJMAA9jbGFzc0xvYWRlck5hbWVxAH4ABUwADmRlY2xhcmluZ0NsYXNzcQB+AAVMAAhmaWxlTmFtZXEAfgAFTAAKbWV0aG9kTmFtZXEAfgAFTAAKbW9kdWxlTmFtZXEAfgAFTAANbW9kdWxlVmVyc2lvbnEAfgAFeHABAAAAEnQAA2FwcHQABFRlc3R0AAlUZXN0LmphdmF0AARtYWlucHBzcgAfamF2YS51dGlsLkNvbGxlY3Rpb25zJEVtcHR5TGlzdHq4F7Q8p57eAgAAeHB4c3IAD2phdmEubGFuZy5FcnJvckUdNlaLgg5WAgAAeHEAfgAEcQB+ABR0AANnb291cQB+AAkAAAABc3EAfgALAQAAABJxAH4ADXEAfgAOcQB+AA9xAH4A"
		"EHBwcQB+ABJ4"_s);
	$assignStatic(LegacyChainedExceptionSerialization::UTE1_OLD_VERSION, "rO0ABXNyAC5qYXZhLmxhbmcucmVmbGVjdC5VbmRlY2xhcmVkVGhyb3dhYmxlRXhjZXB0aW9uBJTY3HP5/P8CAAFMABN1bmRlY2xhcmVkVGhyb3dhYmxldAAVTGphdmEvbGFuZy9UaHJvd2FibGU7eHIAGmphdmEubGFuZy5SdW50aW1lRXhjZXB0aW9unl8GRwo0g+UCAAB4cgATamF2YS5sYW5nLkV4Y2VwdGlvbtD9Hz4aOxzEAgAAeHIAE2phdmEubGFuZy5UaHJvd2FibGXVxjUnOXe4ywMABEwABWNhdXNlcQB+AAFMAA1kZXRhaWxNZXNzYWdldAASTGphdmEvbGFuZy9TdHJpbmc7WwAKc3RhY2tUcmFjZXQAHltMamF2YS9sYW5nL1N0YWNrVHJhY2VFbGVtZW50O0wAFHN1cHByZXNzZWRFeGNlcHRpb25zdAAQTGphdmEvdXRpbC9MaXN0O3hwcHQAA2JhcnVyAB5bTGphdmEubGFuZy5TdGFja1RyYWNlRWxlbWVudDsCRio8PP0iOQIAAHhwAAAAAXNyABtqYXZhLmxhbmcuU3RhY2tUcmFjZUVsZW1lbnRhCcWaJjbdhQIACEIABmZvcm1hdEkACmxpbmVOdW1iZXJMAA9jbGFzc0xvYWRlck5hbWVxAH4ABUwADmRlY2xhcmluZ0NsYXNzcQB+AAVMAAhmaWxlTmFtZXEAfgAFTAAKbWV0aG9kTmFtZXEAfgAFTAAKbW9kdWxlTmFtZXEAfgAFTAANbW9kdWxlVmVyc2lvbnEAfgAFeHABAAAAE3QAA2FwcHQABFRlc3R0AAlUZXN0LmphdmF0AARtYWlucHBzcgAfamF2YS51dGlsLkNvbGxlY3Rpb25zJEVtcHR5TGlzdHq4F7Q8p57eAgAAeHB4c3IAImphdmEubGFuZy5JbGxlZ2FsQXJndW1lbnRFeGNlcHRpb261iXPTfWaPvAIAAHhxAH4AAnEAfgAVdAADZm9vdXEAfgAKAAAAAXNx"
		"AH4ADAEAAAATcQB+AA5xAH4AD3EAfgAQcQB+ABFwcHEAfgATeA=="_s);
	$assignStatic(LegacyChainedExceptionSerialization::UTE2_OLD_VERSION, "rO0ABXNyAC5qYXZhLmxhbmcucmVmbGVjdC5VbmRlY2xhcmVkVGhyb3dhYmxlRXhjZXB0aW9uBJTY3HP5/P8CAAFMABN1bmRlY2xhcmVkVGhyb3dhYmxldAAVTGphdmEvbGFuZy9UaHJvd2FibGU7eHIAGmphdmEubGFuZy5SdW50aW1lRXhjZXB0aW9unl8GRwo0g+UCAAB4cgATamF2YS5sYW5nLkV4Y2VwdGlvbtD9Hz4aOxzEAgAAeHIAE2phdmEubGFuZy5UaHJvd2FibGXVxjUnOXe4ywMABEwABWNhdXNlcQB+AAFMAA1kZXRhaWxNZXNzYWdldAASTGphdmEvbGFuZy9TdHJpbmc7WwAKc3RhY2tUcmFjZXQAHltMamF2YS9sYW5nL1N0YWNrVHJhY2VFbGVtZW50O0wAFHN1cHByZXNzZWRFeGNlcHRpb25zdAAQTGphdmEvdXRpbC9MaXN0O3hwcHB1cgAeW0xqYXZhLmxhbmcuU3RhY2tUcmFjZUVsZW1lbnQ7AkYqPDz9IjkCAAB4cAAAAAFzcgAbamF2YS5sYW5nLlN0YWNrVHJhY2VFbGVtZW50YQnFmiY23YUCAAhCAAZmb3JtYXRJAApsaW5lTnVtYmVyTAAPY2xhc3NMb2FkZXJOYW1lcQB+AAVMAA5kZWNsYXJpbmdDbGFzc3EAfgAFTAAIZmlsZU5hbWVxAH4ABUwACm1ldGhvZE5hbWVxAH4ABUwACm1vZHVsZU5hbWVxAH4ABUwADW1vZHVsZVZlcnNpb25xAH4ABXhwAQAAABR0AANhcHB0AARUZXN0dAAJVGVzdC5qYXZhdAAEbWFpbnBwc3IAH2phdmEudXRpbC5Db2xsZWN0aW9ucyRFbXB0eUxpc3R6uBe0PKee3gIAAHhweHNyACJqYXZhLmxhbmcuSWxsZWdhbEFyZ3VtZW50RXhjZXB0aW9utYlz031mj7wCAAB4cQB+AAJxAH4AFHQAA2dvb3VxAH4ACQAAAAFzcQB+AAsB"
		"AAAAFHEAfgANcQB+AA5xAH4AD3EAfgAQcHBxAH4AEng="_s);
	$assignStatic(LegacyChainedExceptionSerialization::PAE_OLD_VERSION, "rO0ABXNyACdqYXZhLnNlY3VyaXR5LlByaXZpbGVnZWRBY3Rpb25FeGNlcHRpb25Bj1P2UhH1ugIAAUwACWV4Y2VwdGlvbnQAFUxqYXZhL2xhbmcvRXhjZXB0aW9uO3hyABNqYXZhLmxhbmcuRXhjZXB0aW9u0P0fPho7HMQCAAB4cgATamF2YS5sYW5nLlRocm93YWJsZdXGNSc5d7jLAwAETAAFY2F1c2V0ABVMamF2YS9sYW5nL1Rocm93YWJsZTtMAA1kZXRhaWxNZXNzYWdldAASTGphdmEvbGFuZy9TdHJpbmc7WwAKc3RhY2tUcmFjZXQAHltMamF2YS9sYW5nL1N0YWNrVHJhY2VFbGVtZW50O0wAFHN1cHByZXNzZWRFeGNlcHRpb25zdAAQTGphdmEvdXRpbC9MaXN0O3hwcHB1cgAeW0xqYXZhLmxhbmcuU3RhY2tUcmFjZUVsZW1lbnQ7AkYqPDz9IjkCAAB4cAAAAAFzcgAbamF2YS5sYW5nLlN0YWNrVHJhY2VFbGVtZW50YQnFmiY23YUCAAhCAAZmb3JtYXRJAApsaW5lTnVtYmVyTAAPY2xhc3NMb2FkZXJOYW1lcQB+AAVMAA5kZWNsYXJpbmdDbGFzc3EAfgAFTAAIZmlsZU5hbWVxAH4ABUwACm1ldGhvZE5hbWVxAH4ABUwACm1vZHVsZU5hbWVxAH4ABUwADW1vZHVsZVZlcnNpb25xAH4ABXhwAQAAABd0AANhcHB0AARUZXN0dAAJVGVzdC5qYXZhdAAEbWFpbnBwc3IAH2phdmEudXRpbC5Db2xsZWN0aW9ucyRFbXB0eUxpc3R6uBe0PKee3gIAAHhweHNyABNqYXZhLmlvLklPRXhjZXB0aW9ubIBzZGUl8KsCAAB4cQB+AAJxAH4AFHQAA2Zvb3VxAH4ACQAAAAFzcQB+AAsBAAAAF3EAfgANcQB+AA5xAH4AD3EAfgAQcHBxAH4AEng="_s);
	$assignStatic(LegacyChainedExceptionSerialization::broken, $new($ThrowableArray, {
		static_cast<$Throwable*>($$new($ClassNotFoundException)),
		static_cast<$Throwable*>($$new($ClassNotFoundException, "bar"_s, $$new($IOException, "reading class file"_s))),
		static_cast<$Throwable*>($$new($ExceptionInInitializerError)),
		static_cast<$Throwable*>($$new($ExceptionInInitializerError, static_cast<$Throwable*>($$new($NullPointerException, "foo"_s)))),
		static_cast<$Throwable*>($$new($UndeclaredThrowableException, nullptr)),
		static_cast<$Throwable*>($$new($UndeclaredThrowableException, $$new($IllegalArgumentException, "foo"_s))),
		static_cast<$Throwable*>($$new($InvocationTargetException, nullptr)),
		static_cast<$Throwable*>($$new($InvocationTargetException, $$new($Error, "goo"_s))),
		static_cast<$Throwable*>($$new($PrivilegedActionException, nullptr)),
		static_cast<$Throwable*>($$new($PrivilegedActionException, $$new($IOException, "foo"_s)))
	}));
	$var($Object, var$0, $of(LegacyChainedExceptionSerialization::EIIE_OLD_VERSION));
	$var($Object, var$1, $of($new($ExceptionInInitializerError, static_cast<$Throwable*>($$new($NullPointerException, "foo"_s)))));
	$var($Object, var$2, $of(LegacyChainedExceptionSerialization::CNFE_OLD_VERSION));
	$var($Object, var$3, $of($new($ClassNotFoundException, "bar"_s, $$new($IOException, "reading class file"_s))));
	$var($Object, var$4, $of(LegacyChainedExceptionSerialization::ITE1_OLD_VERSION));
	$var($Object, var$5, $of($new($InvocationTargetException, $$new($Error, "foo"_s), "bar"_s)));
	$var($Object, var$6, $of(LegacyChainedExceptionSerialization::ITE2_OLD_VERSION));
	$var($Object, var$7, $of($new($InvocationTargetException, $$new($Error, "goo"_s))));
	$var($Object, var$8, $of(LegacyChainedExceptionSerialization::UTE1_OLD_VERSION));
	$var($Object, var$9, $of($new($UndeclaredThrowableException, $$new($IllegalArgumentException, "foo"_s), "bar"_s)));
	$var($Object, var$10, $of(LegacyChainedExceptionSerialization::UTE2_OLD_VERSION));
	$var($Object, var$11, $of($new($UndeclaredThrowableException, $$new($IllegalArgumentException, "goo"_s))));
	$var($Object, var$12, $of(LegacyChainedExceptionSerialization::PAE_OLD_VERSION));
	$assignStatic(LegacyChainedExceptionSerialization::SERIALIZED_DATA, $Map::of(var$0, var$1, var$2, var$3, var$4, var$5, var$6, var$7, var$8, var$9, var$10, var$11, var$12, $$new($PrivilegedActionException, $$new($IOException, "foo"_s))));
}

LegacyChainedExceptionSerialization::LegacyChainedExceptionSerialization() {
}

$Class* LegacyChainedExceptionSerialization::load$($String* name, bool initialize) {
	$loadClass(LegacyChainedExceptionSerialization, name, initialize, &_LegacyChainedExceptionSerialization_ClassInfo_, clinit$LegacyChainedExceptionSerialization, allocate$LegacyChainedExceptionSerialization);
	return class$;
}

$Class* LegacyChainedExceptionSerialization::class$ = nullptr;
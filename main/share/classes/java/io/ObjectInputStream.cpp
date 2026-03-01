#include <java/io/ObjectInputStream.h>

#include <java/io/Externalizable.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InvalidClassException.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/NotActiveException.h>
#include <java/io/ObjectInput.h>
#include <java/io/ObjectInputFilter$Config.h>
#include <java/io/ObjectInputFilter$FilterInfo.h>
#include <java/io/ObjectInputFilter$Status.h>
#include <java/io/ObjectInputFilter.h>
#include <java/io/ObjectInputStream$1.h>
#include <java/io/ObjectInputStream$BlockDataInputStream.h>
#include <java/io/ObjectInputStream$Caches.h>
#include <java/io/ObjectInputStream$FieldValues.h>
#include <java/io/ObjectInputStream$FilterValues.h>
#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream$HandleTable.h>
#include <java/io/ObjectInputStream$Logging.h>
#include <java/io/ObjectInputStream$ValidationList.h>
#include <java/io/ObjectInputValidation.h>
#include <java/io/ObjectStreamClass$ClassDataSlot.h>
#include <java/io/ObjectStreamClass$RecordSupport.h>
#include <java/io/ObjectStreamClass$WeakClassKey.h>
#include <java/io/ObjectStreamClass.h>
#include <java/io/ObjectStreamConstants.h>
#include <java/io/ObjectStreamException.h>
#include <java/io/OptionalDataException.h>
#include <java/io/SerialCallbackContext.h>
#include <java/io/Serializable.h>
#include <java/io/SerializablePermission.h>
#include <java/io/StreamCorruptedException.h>
#include <java/io/WriteAbortedException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Enum.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalAccessError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/lang/NegativeArraySizeException.h>
#include <java/lang/OutOfMemoryError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/lang/ThreadDeath.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/lang/reflect/Array.h>
#include <java/lang/reflect/Modifier.h>
#include <java/lang/reflect/Proxy.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Arrays.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/function/BinaryOperator.h>
#include <jdk/internal/access/JavaObjectInputStreamAccess.h>
#include <jdk/internal/access/JavaObjectInputStreamReadString.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/event/DeserializationEvent.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/misc/VM.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef DEBUG
#undef NULL_HANDLE
#undef PROXY_INTERFACE_LIMIT
#undef PUBLIC
#undef REJECTED
#undef SERIAL_FILTER_PERMISSION
#undef SET_FILTER_AFTER_READ
#undef STREAM_MAGIC
#undef STREAM_VERSION
#undef SUBCLASS_IMPLEMENTATION_PERMISSION
#undef SUBSTITUTION_PERMISSION
#undef TC_ARRAY
#undef TC_BLOCKDATA
#undef TC_BLOCKDATALONG
#undef TC_CLASS
#undef TC_CLASSDESC
#undef TC_ENDBLOCKDATA
#undef TC_ENUM
#undef TC_EXCEPTION
#undef TC_LONGSTRING
#undef TC_NULL
#undef TC_OBJECT
#undef TC_PROXYCLASSDESC
#undef TC_REFERENCE
#undef TC_RESET
#undef TC_STRING
#undef TRACE
#undef TYPE
#undef UNSAFE

using $ObjectInputStream$FieldValuesArray = $Array<::java::io::ObjectInputStream$FieldValues>;
using $ObjectStreamClass$ClassDataSlotArray = $Array<::java::io::ObjectStreamClass$ClassDataSlot>;
using $Externalizable = ::java::io::Externalizable;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InvalidClassException = ::java::io::InvalidClassException;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $NotActiveException = ::java::io::NotActiveException;
using $ObjectInput = ::java::io::ObjectInput;
using $ObjectInputFilter = ::java::io::ObjectInputFilter;
using $ObjectInputFilter$Config = ::java::io::ObjectInputFilter$Config;
using $ObjectInputFilter$FilterInfo = ::java::io::ObjectInputFilter$FilterInfo;
using $ObjectInputFilter$Status = ::java::io::ObjectInputFilter$Status;
using $ObjectInputStream$1 = ::java::io::ObjectInputStream$1;
using $ObjectInputStream$BlockDataInputStream = ::java::io::ObjectInputStream$BlockDataInputStream;
using $ObjectInputStream$Caches = ::java::io::ObjectInputStream$Caches;
using $ObjectInputStream$FieldValues = ::java::io::ObjectInputStream$FieldValues;
using $ObjectInputStream$FilterValues = ::java::io::ObjectInputStream$FilterValues;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectInputStream$HandleTable = ::java::io::ObjectInputStream$HandleTable;
using $ObjectInputStream$Logging = ::java::io::ObjectInputStream$Logging;
using $ObjectInputStream$ValidationList = ::java::io::ObjectInputStream$ValidationList;
using $ObjectInputValidation = ::java::io::ObjectInputValidation;
using $ObjectStreamClass = ::java::io::ObjectStreamClass;
using $ObjectStreamClass$RecordSupport = ::java::io::ObjectStreamClass$RecordSupport;
using $ObjectStreamClass$WeakClassKey = ::java::io::ObjectStreamClass$WeakClassKey;
using $ObjectStreamConstants = ::java::io::ObjectStreamConstants;
using $ObjectStreamException = ::java::io::ObjectStreamException;
using $OptionalDataException = ::java::io::OptionalDataException;
using $SerialCallbackContext = ::java::io::SerialCallbackContext;
using $Serializable = ::java::io::Serializable;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $WriteAbortedException = ::java::io::WriteAbortedException;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $Enum = ::java::lang::Enum;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalAccessError = ::java::lang::IllegalAccessError;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NegativeArraySizeException = ::java::lang::NegativeArraySizeException;
using $NullPointerException = ::java::lang::NullPointerException;
using $OutOfMemoryError = ::java::lang::OutOfMemoryError;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Short = ::java::lang::Short;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $ThreadDeath = ::java::lang::ThreadDeath;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $1Array = ::java::lang::reflect::Array;
using $Modifier = ::java::lang::reflect::Modifier;
using $Proxy = ::java::lang::reflect::Proxy;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Arrays = ::java::util::Arrays;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $BinaryOperator = ::java::util::function::BinaryOperator;
using $JavaObjectInputStreamAccess = ::jdk::internal::access::JavaObjectInputStreamAccess;
using $JavaObjectInputStreamReadString = ::jdk::internal::access::JavaObjectInputStreamReadString;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $DeserializationEvent = ::jdk::internal::event::DeserializationEvent;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $VM = ::jdk::internal::misc::VM;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace java {
	namespace io {

class ObjectInputStream$$Lambda$checkArray : public $JavaObjectInputStreamAccess {
	$class(ObjectInputStream$$Lambda$checkArray, $NO_CLASS_INIT, $JavaObjectInputStreamAccess)
public:
	void init$() {
	}
	virtual void checkArray(ObjectInputStream* inst$, $Class* arrayType, int32_t arrayLength) override {
		$nc(inst$)->checkArray(arrayType, arrayLength);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectInputStream$$Lambda$checkArray>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ObjectInputStream$$Lambda$checkArray::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ObjectInputStream$$Lambda$checkArray, init$, void)},
	{"checkArray", "(Ljava/io/ObjectInputStream;Ljava/lang/Class;I)V", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream$$Lambda$checkArray, checkArray, void, ObjectInputStream*, $Class*, int32_t)},
	{}
};
$ClassInfo ObjectInputStream$$Lambda$checkArray::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectInputStream$$Lambda$checkArray",
	"java.lang.Object",
	"jdk.internal.access.JavaObjectInputStreamAccess",
	nullptr,
	methodInfos
};
$Class* ObjectInputStream$$Lambda$checkArray::load$($String* name, bool initialize) {
	$loadClass(ObjectInputStream$$Lambda$checkArray, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectInputStream$$Lambda$checkArray::class$ = nullptr;

class ObjectInputStream$$Lambda$readString$1 : public $JavaObjectInputStreamReadString {
	$class(ObjectInputStream$$Lambda$readString$1, $NO_CLASS_INIT, $JavaObjectInputStreamReadString)
public:
	void init$() {
	}
	virtual $String* readString(ObjectInputStream* inst$) override {
		 return $nc(inst$)->readString();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ObjectInputStream$$Lambda$readString$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ObjectInputStream$$Lambda$readString$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ObjectInputStream$$Lambda$readString$1, init$, void)},
	{"readString", "(Ljava/io/ObjectInputStream;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream$$Lambda$readString$1, readString, $String*, ObjectInputStream*)},
	{}
};
$ClassInfo ObjectInputStream$$Lambda$readString$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.io.ObjectInputStream$$Lambda$readString$1",
	"java.lang.Object",
	"jdk.internal.access.JavaObjectInputStreamReadString",
	nullptr,
	methodInfos
};
$Class* ObjectInputStream$$Lambda$readString$1::load$($String* name, bool initialize) {
	$loadClass(ObjectInputStream$$Lambda$readString$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ObjectInputStream$$Lambda$readString$1::class$ = nullptr;

$CompoundAttribute _ObjectInputStream_MethodAnnotations_readLine36[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _ObjectInputStream_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ObjectInputStream, $assertionsDisabled)},
	{"NULL_HANDLE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(ObjectInputStream, NULL_HANDLE)},
	{"unsharedMarker", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectInputStream, unsharedMarker)},
	{"primClasses", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ObjectInputStream, primClasses)},
	{"bin", "Ljava/io/ObjectInputStream$BlockDataInputStream;", nullptr, $PRIVATE | $FINAL, $field(ObjectInputStream, bin)},
	{"vlist", "Ljava/io/ObjectInputStream$ValidationList;", nullptr, $PRIVATE | $FINAL, $field(ObjectInputStream, vlist)},
	{"depth", "J", nullptr, $PRIVATE, $field(ObjectInputStream, depth)},
	{"totalObjectRefs", "J", nullptr, $PRIVATE, $field(ObjectInputStream, totalObjectRefs)},
	{"closed", "Z", nullptr, $PRIVATE, $field(ObjectInputStream, closed)},
	{"handles", "Ljava/io/ObjectInputStream$HandleTable;", nullptr, $PRIVATE | $FINAL, $field(ObjectInputStream, handles)},
	{"passHandle", "I", nullptr, $PRIVATE, $field(ObjectInputStream, passHandle)},
	{"defaultDataEnd", "Z", nullptr, $PRIVATE, $field(ObjectInputStream, defaultDataEnd)},
	{"enableOverride", "Z", nullptr, $PRIVATE | $FINAL, $field(ObjectInputStream, enableOverride)},
	{"enableResolve", "Z", nullptr, $PRIVATE, $field(ObjectInputStream, enableResolve)},
	{"curContext", "Ljava/io/SerialCallbackContext;", nullptr, $PRIVATE, $field(ObjectInputStream, curContext)},
	{"serialFilter", "Ljava/io/ObjectInputFilter;", nullptr, $PRIVATE, $field(ObjectInputStream, serialFilter)},
	{"streamFilterSet", "Z", nullptr, $PRIVATE, $field(ObjectInputStream, streamFilterSet)},
	{"UNSAFE", "Ljdk/internal/misc/Unsafe;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectInputStream, UNSAFE)},
	{}
};

$MethodInfo _ObjectInputStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(ObjectInputStream, init$, void, $InputStream*), "java.io.IOException"},
	{"<init>", "()V", nullptr, $PROTECTED, $method(ObjectInputStream, init$, void), "java.io.IOException,java.lang.SecurityException"},
	{"auditSubclass", "(Ljava/lang/Class;)Ljava/lang/Boolean;", "(Ljava/lang/Class<*>;)Ljava/lang/Boolean;", $PRIVATE | $STATIC, $staticMethod(ObjectInputStream, auditSubclass, $Boolean*, $Class*)},
	{"available", "()I", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, available, int32_t), "java.io.IOException"},
	{"checkArray", "(Ljava/lang/Class;I)V", "(Ljava/lang/Class<*>;I)V", $PRIVATE, $method(ObjectInputStream, checkArray, void, $Class*, int32_t), "java.io.InvalidClassException"},
	{"checkResolve", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(ObjectInputStream, checkResolve, $Object*, Object$*), "java.io.IOException"},
	{"clear", "()V", nullptr, $PRIVATE, $method(ObjectInputStream, clear, void)},
	{"cloneArray", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectInputStream, cloneArray, $Object*, Object$*)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, close, void), "java.io.IOException"},
	{"defaultReadObject", "()V", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, defaultReadObject, void), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"enableResolveObject", "(Z)Z", nullptr, $PROTECTED, $virtualMethod(ObjectInputStream, enableResolveObject, bool, bool), "java.lang.SecurityException"},
	{"filterCheck", "(Ljava/lang/Class;I)V", "(Ljava/lang/Class<*>;I)V", $PRIVATE, $method(ObjectInputStream, filterCheck, void, $Class*, int32_t), "java.io.InvalidClassException"},
	{"freeze", "()V", nullptr, $PRIVATE, $method(ObjectInputStream, freeze, void)},
	{"getObjectInputFilter", "()Ljava/io/ObjectInputFilter;", nullptr, $PUBLIC | $FINAL, $method(ObjectInputStream, getObjectInputFilter, $ObjectInputFilter*)},
	{"handleReset", "()V", nullptr, $PRIVATE, $method(ObjectInputStream, handleReset, void), "java.io.StreamCorruptedException"},
	{"isCustomSubclass", "()Z", nullptr, $PRIVATE, $method(ObjectInputStream, isCustomSubclass, bool)},
	{"latestUserDefinedLoader", "()Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $STATIC, $staticMethod(ObjectInputStream, latestUserDefinedLoader, $ClassLoader*)},
	{"*read", "([B)I", nullptr, $PUBLIC},
	{"read", "()I", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, read, int32_t), "java.io.IOException"},
	{"read", "([BII)I", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, read, int32_t, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"readArray", "(Z)Ljava/lang/Object;", nullptr, $PRIVATE, $method(ObjectInputStream, readArray, $Object*, bool), "java.io.IOException"},
	{"readBoolean", "()Z", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readBoolean, bool), "java.io.IOException"},
	{"readByte", "()B", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readByte, int8_t), "java.io.IOException"},
	{"readChar", "()C", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readChar, char16_t), "java.io.IOException"},
	{"readClass", "(Z)Ljava/lang/Class;", "(Z)Ljava/lang/Class<*>;", $PRIVATE, $method(ObjectInputStream, readClass, $Class*, bool), "java.io.IOException"},
	{"readClassDesc", "(Z)Ljava/io/ObjectStreamClass;", nullptr, $PRIVATE, $method(ObjectInputStream, readClassDesc, $ObjectStreamClass*, bool), "java.io.IOException"},
	{"readClassDescriptor", "()Ljava/io/ObjectStreamClass;", nullptr, $PROTECTED, $virtualMethod(ObjectInputStream, readClassDescriptor, $ObjectStreamClass*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readDouble", "()D", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readDouble, double), "java.io.IOException"},
	{"readEnum", "(Z)Ljava/lang/Enum;", "(Z)Ljava/lang/Enum<*>;", $PRIVATE, $method(ObjectInputStream, readEnum, $Enum*, bool), "java.io.IOException"},
	{"readExternalData", "(Ljava/io/Externalizable;Ljava/io/ObjectStreamClass;)V", nullptr, $PRIVATE, $method(ObjectInputStream, readExternalData, void, $Externalizable*, $ObjectStreamClass*), "java.io.IOException"},
	{"readFatalException", "()Ljava/io/IOException;", nullptr, $PRIVATE, $method(ObjectInputStream, readFatalException, $IOException*), "java.io.IOException"},
	{"readFields", "()Ljava/io/ObjectInputStream$GetField;", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readFields, $ObjectInputStream$GetField*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readFloat", "()F", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readFloat, float), "java.io.IOException"},
	{"readFully", "([B)V", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readFully, void, $bytes*), "java.io.IOException"},
	{"readFully", "([BII)V", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readFully, void, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"readHandle", "(Z)Ljava/lang/Object;", nullptr, $PRIVATE, $method(ObjectInputStream, readHandle, $Object*, bool), "java.io.IOException"},
	{"readInt", "()I", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readInt, int32_t), "java.io.IOException"},
	{"readLine", "()Ljava/lang/String;", nullptr, $PUBLIC | $DEPRECATED, $virtualMethod(ObjectInputStream, readLine, $String*), "java.io.IOException", nullptr, _ObjectInputStream_MethodAnnotations_readLine36},
	{"readLong", "()J", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readLong, int64_t), "java.io.IOException"},
	{"readNonProxyDesc", "(Z)Ljava/io/ObjectStreamClass;", nullptr, $PRIVATE, $method(ObjectInputStream, readNonProxyDesc, $ObjectStreamClass*, bool), "java.io.IOException"},
	{"readNull", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(ObjectInputStream, readNull, $Object*), "java.io.IOException"},
	{"readObject", "()Ljava/lang/Object;", nullptr, $PUBLIC | $FINAL, $virtualMethod(ObjectInputStream, readObject, $Object*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readObject", "(Ljava/lang/Class;)Ljava/lang/Object;", "(Ljava/lang/Class<*>;)Ljava/lang/Object;", $PRIVATE | $FINAL, $method(ObjectInputStream, readObject, $Object*, $Class*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readObject0", "(Ljava/lang/Class;Z)Ljava/lang/Object;", "(Ljava/lang/Class<*>;Z)Ljava/lang/Object;", $PRIVATE, $method(ObjectInputStream, readObject0, $Object*, $Class*, bool), "java.io.IOException"},
	{"readObjectOverride", "()Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(ObjectInputStream, readObjectOverride, $Object*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readOrdinaryObject", "(Z)Ljava/lang/Object;", nullptr, $PRIVATE, $method(ObjectInputStream, readOrdinaryObject, $Object*, bool), "java.io.IOException"},
	{"readProxyDesc", "(Z)Ljava/io/ObjectStreamClass;", nullptr, $PRIVATE, $method(ObjectInputStream, readProxyDesc, $ObjectStreamClass*, bool), "java.io.IOException"},
	{"readRecord", "(Ljava/io/ObjectStreamClass;)Ljava/lang/Object;", nullptr, $PRIVATE, $method(ObjectInputStream, readRecord, $Object*, $ObjectStreamClass*), "java.io.IOException"},
	{"readSerialData", "(Ljava/lang/Object;Ljava/io/ObjectStreamClass;)V", nullptr, $PRIVATE, $method(ObjectInputStream, readSerialData, void, Object$*, $ObjectStreamClass*), "java.io.IOException"},
	{"readShort", "()S", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readShort, int16_t), "java.io.IOException"},
	{"readStreamHeader", "()V", nullptr, $PROTECTED, $virtualMethod(ObjectInputStream, readStreamHeader, void), "java.io.IOException,java.io.StreamCorruptedException"},
	{"readString", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(ObjectInputStream, readString, $String*), "java.io.IOException"},
	{"readString", "(Z)Ljava/lang/String;", nullptr, $PRIVATE, $method(ObjectInputStream, readString, $String*, bool), "java.io.IOException"},
	{"readTypeString", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(ObjectInputStream, readTypeString, $String*), "java.io.IOException"},
	{"readUTF", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readUTF, $String*), "java.io.IOException"},
	{"readUnshared", "()Ljava/lang/Object;", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readUnshared, $Object*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readUnsignedByte", "()I", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readUnsignedByte, int32_t), "java.io.IOException"},
	{"readUnsignedShort", "()I", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, readUnsignedShort, int32_t), "java.io.IOException"},
	{"registerValidation", "(Ljava/io/ObjectInputValidation;I)V", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, registerValidation, void, $ObjectInputValidation*, int32_t), "java.io.NotActiveException,java.io.InvalidObjectException"},
	{"resolveClass", "(Ljava/io/ObjectStreamClass;)Ljava/lang/Class;", "(Ljava/io/ObjectStreamClass;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(ObjectInputStream, resolveClass, $Class*, $ObjectStreamClass*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"resolveObject", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(ObjectInputStream, resolveObject, $Object*, Object$*), "java.io.IOException"},
	{"resolveProxyClass", "([Ljava/lang/String;)Ljava/lang/Class;", "([Ljava/lang/String;)Ljava/lang/Class<*>;", $PROTECTED, $virtualMethod(ObjectInputStream, resolveProxyClass, $Class*, $StringArray*), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setObjectInputFilter", "(Ljava/io/ObjectInputFilter;)V", nullptr, $PUBLIC | $FINAL, $method(ObjectInputStream, setObjectInputFilter, void, $ObjectInputFilter*)},
	{"*skip", "(J)J", nullptr, $PUBLIC},
	{"skipBytes", "(I)I", nullptr, $PUBLIC, $virtualMethod(ObjectInputStream, skipBytes, int32_t, int32_t), "java.io.IOException"},
	{"skipCustomData", "()V", nullptr, $PRIVATE, $method(ObjectInputStream, skipCustomData, void), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"verifySubclass", "()V", nullptr, $PRIVATE, $method(ObjectInputStream, verifySubclass, void)},
	{}
};

$InnerClassInfo _ObjectInputStream_InnerClassesInfo_[] = {
	{"java.io.ObjectInputStream$HandleTable", "java.io.ObjectInputStream", "HandleTable", $PRIVATE | $STATIC},
	{"java.io.ObjectInputStream$BlockDataInputStream", "java.io.ObjectInputStream", "BlockDataInputStream", $PRIVATE},
	{"java.io.ObjectInputStream$PeekInputStream", "java.io.ObjectInputStream", "PeekInputStream", $PRIVATE | $STATIC},
	{"java.io.ObjectInputStream$FilterValues", "java.io.ObjectInputStream", "FilterValues", $STATIC},
	{"java.io.ObjectInputStream$ValidationList", "java.io.ObjectInputStream", "ValidationList", $PRIVATE | $STATIC},
	{"java.io.ObjectInputStream$FieldValues", "java.io.ObjectInputStream", "FieldValues", $PRIVATE | $FINAL},
	{"java.io.ObjectInputStream$GetField", "java.io.ObjectInputStream", "GetField", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.io.ObjectInputStream$Logging", "java.io.ObjectInputStream", "Logging", $PRIVATE | $STATIC},
	{"java.io.ObjectInputStream$Caches", "java.io.ObjectInputStream", "Caches", $PRIVATE | $STATIC},
	{"java.io.ObjectInputStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ObjectInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.io.ObjectInputStream",
	"java.io.InputStream",
	"java.io.ObjectInput,java.io.ObjectStreamConstants",
	_ObjectInputStream_FieldInfo_,
	_ObjectInputStream_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectInputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.ObjectInputStream$HandleTable,java.io.ObjectInputStream$HandleTable$HandleList,java.io.ObjectInputStream$BlockDataInputStream,java.io.ObjectInputStream$PeekInputStream,java.io.ObjectInputStream$FilterValues,java.io.ObjectInputStream$ValidationList,java.io.ObjectInputStream$ValidationList$Callback,java.io.ObjectInputStream$ValidationList$1,java.io.ObjectInputStream$FieldValues,java.io.ObjectInputStream$GetField,java.io.ObjectInputStream$Logging,java.io.ObjectInputStream$Caches,java.io.ObjectInputStream$1"
};

$Object* allocate$ObjectInputStream($Class* clazz) {
	return $of($alloc(ObjectInputStream));
}

int32_t ObjectInputStream::read($bytes* b) {
	 return this->$InputStream::read(b);
}

int64_t ObjectInputStream::skip(int64_t n) {
	 return this->$InputStream::skip(n);
}

int32_t ObjectInputStream::hashCode() {
	 return this->$InputStream::hashCode();
}

bool ObjectInputStream::equals(Object$* obj) {
	 return this->$InputStream::equals(obj);
}

$Object* ObjectInputStream::clone() {
	 return this->$InputStream::clone();
}

$String* ObjectInputStream::toString() {
	 return this->$InputStream::toString();
}

void ObjectInputStream::finalize() {
	this->$InputStream::finalize();
}

bool ObjectInputStream::$assertionsDisabled = false;
$Object* ObjectInputStream::unsharedMarker = nullptr;
$Map* ObjectInputStream::primClasses = nullptr;
$Unsafe* ObjectInputStream::UNSAFE = nullptr;

void ObjectInputStream::init$($InputStream* in) {
	$useLocalCurrentObjectStackCache();
	$InputStream::init$();
	this->passHandle = ObjectInputStream::NULL_HANDLE;
	this->defaultDataEnd = false;
	verifySubclass();
	$set(this, bin, $new($ObjectInputStream$BlockDataInputStream, this, in));
	$set(this, handles, $new($ObjectInputStream$HandleTable, 10));
	$set(this, vlist, $new($ObjectInputStream$ValidationList));
	this->streamFilterSet = false;
	$set(this, serialFilter, $cast($ObjectInputFilter, $nc($($ObjectInputFilter$Config::getSerialFilterFactorySingleton()))->apply(nullptr, $($ObjectInputFilter$Config::getSerialFilter()))));
	this->enableOverride = false;
	readStreamHeader();
	$nc(this->bin)->setBlockDataMode(true);
}

void ObjectInputStream::init$() {
	$useLocalCurrentObjectStackCache();
	$InputStream::init$();
	this->passHandle = ObjectInputStream::NULL_HANDLE;
	this->defaultDataEnd = false;
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($ObjectStreamConstants);
		sm->checkPermission($ObjectStreamConstants::SUBCLASS_IMPLEMENTATION_PERMISSION);
	}
	$set(this, bin, nullptr);
	$set(this, handles, nullptr);
	$set(this, vlist, nullptr);
	this->streamFilterSet = false;
	$set(this, serialFilter, $cast($ObjectInputFilter, $nc($($ObjectInputFilter$Config::getSerialFilterFactorySingleton()))->apply(nullptr, $($ObjectInputFilter$Config::getSerialFilter()))));
	this->enableOverride = true;
}

$Object* ObjectInputStream::readObject() {
	return $of(readObject($Object::class$));
}

$String* ObjectInputStream::readString() {
	try {
		return $cast($String, readObject($String::class$));
	} catch ($ClassNotFoundException& cnf) {
		$throwNew($IllegalStateException, static_cast<$Throwable*>(cnf));
	}
	$shouldNotReachHere();
}

$Object* ObjectInputStream::readObject($Class* type) {
	$useLocalCurrentObjectStackCache();
	if (this->enableOverride) {
		return $of(readObjectOverride());
	}
	if (!(type == $Object::class$ || type == $String::class$)) {
		$throwNew($AssertionError, $of("internal error"_s));
	}
	int32_t outerHandle = this->passHandle;
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($Object, obj, readObject0(type, false));
			$nc(this->handles)->markDependency(outerHandle, this->passHandle);
			$var($ClassNotFoundException, ex, $nc(this->handles)->lookupException(this->passHandle));
			if (ex != nullptr) {
				$throw(ex);
			}
			if (this->depth == 0) {
				$nc(this->vlist)->doCallbacks();
				freeze();
			}
			$assign(var$2, obj);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->passHandle = outerHandle;
			if (this->closed && this->depth == 0) {
				clear();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Object* ObjectInputStream::readObjectOverride() {
	return $of(nullptr);
}

$Object* ObjectInputStream::readUnshared() {
	$useLocalCurrentObjectStackCache();
	int32_t outerHandle = this->passHandle;
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($Object, obj, readObject0($Object::class$, true));
			$nc(this->handles)->markDependency(outerHandle, this->passHandle);
			$var($ClassNotFoundException, ex, $nc(this->handles)->lookupException(this->passHandle));
			if (ex != nullptr) {
				$throw(ex);
			}
			if (this->depth == 0) {
				$nc(this->vlist)->doCallbacks();
				freeze();
			}
			$assign(var$2, obj);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			this->passHandle = outerHandle;
			if (this->closed && this->depth == 0) {
				clear();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void ObjectInputStream::defaultReadObject() {
	$useLocalCurrentObjectStackCache();
	$var($SerialCallbackContext, ctx, this->curContext);
	if (ctx == nullptr) {
		$throwNew($NotActiveException, "not in call to readObject"_s);
	}
	$var($Object, curObj, $nc(ctx)->getObj());
	$var($ObjectStreamClass, curDesc, ctx->getDesc());
	$nc(this->bin)->setBlockDataMode(false);
	$var($ObjectInputStream$FieldValues, values, $new($ObjectInputStream$FieldValues, this, curDesc, true));
	if (curObj != nullptr) {
		values->defaultCheckFieldValues(curObj);
		values->defaultSetFieldValues(curObj);
	}
	$nc(this->bin)->setBlockDataMode(true);
	if (!$nc(curDesc)->hasWriteObjectData()) {
		this->defaultDataEnd = true;
	}
	$var($ClassNotFoundException, ex, $nc(this->handles)->lookupException(this->passHandle));
	if (ex != nullptr) {
		$throw(ex);
	}
}

$ObjectInputStream$GetField* ObjectInputStream::readFields() {
	$useLocalCurrentObjectStackCache();
	$var($SerialCallbackContext, ctx, this->curContext);
	if (ctx == nullptr) {
		$throwNew($NotActiveException, "not in call to readObject"_s);
	}
	$nc(ctx)->checkAndSetUsed();
	$var($ObjectStreamClass, curDesc, ctx->getDesc());
	$nc(this->bin)->setBlockDataMode(false);
	$var($ObjectInputStream$FieldValues, values, $new($ObjectInputStream$FieldValues, this, curDesc, false));
	$nc(this->bin)->setBlockDataMode(true);
	if (!$nc(curDesc)->hasWriteObjectData()) {
		this->defaultDataEnd = true;
	}
	return values;
}

void ObjectInputStream::registerValidation($ObjectInputValidation* obj, int32_t prio) {
	if (this->depth == 0) {
		$throwNew($NotActiveException, "stream inactive"_s);
	}
	$nc(this->vlist)->register$(obj, prio);
}

$Class* ObjectInputStream::resolveClass($ObjectStreamClass* desc) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, name, $nc(desc)->getName());
	try {
		return $Class::forName(name, false, $(latestUserDefinedLoader()));
	} catch ($ClassNotFoundException& ex) {
		$Class* cl = $cast($Class, $nc(ObjectInputStream::primClasses)->get(name));
		if (cl != nullptr) {
			return cl;
		} else {
			$throw(ex);
		}
	}
	$shouldNotReachHere();
}

$Class* ObjectInputStream::resolveProxyClass($StringArray* interfaces) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassLoader, latestLoader, latestUserDefinedLoader());
	$var($ClassLoader, nonPublicLoader, nullptr);
	bool hasNonPublicInterface = false;
	$var($ClassArray, classObjs, $new($ClassArray, $nc(interfaces)->length));
	for (int32_t i = 0; i < interfaces->length; ++i) {
		$Class* cl = $Class::forName(interfaces->get(i), false, latestLoader);
		if (((int32_t)($nc(cl)->getModifiers() & (uint32_t)$Modifier::PUBLIC)) == 0) {
			if (hasNonPublicInterface) {
				if (nonPublicLoader != cl->getClassLoader()) {
					$throwNew($IllegalAccessError, "conflicting non-public interface class loaders"_s);
				}
			} else {
				$assign(nonPublicLoader, cl->getClassLoader());
				hasNonPublicInterface = true;
			}
		}
		classObjs->set(i, cl);
	}
	try {
		$Class* proxyClass = $Proxy::getProxyClass(hasNonPublicInterface ? nonPublicLoader : latestLoader, classObjs);
		return proxyClass;
	} catch ($IllegalArgumentException& e) {
		$throwNew($ClassNotFoundException, nullptr, e);
	}
	$shouldNotReachHere();
}

$Object* ObjectInputStream::resolveObject(Object$* obj) {
	return $of(obj);
}

bool ObjectInputStream::enableResolveObject(bool enable) {
	if (enable == this->enableResolve) {
		return enable;
	}
	if (enable) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			$init($ObjectStreamConstants);
			sm->checkPermission($ObjectStreamConstants::SUBSTITUTION_PERMISSION);
		}
	}
	this->enableResolve = enable;
	return !this->enableResolve;
}

void ObjectInputStream::readStreamHeader() {
	$useLocalCurrentObjectStackCache();
	int16_t s0 = $nc(this->bin)->readShort();
	int16_t s1 = $nc(this->bin)->readShort();
	if (s0 != $ObjectStreamConstants::STREAM_MAGIC || s1 != $ObjectStreamConstants::STREAM_VERSION) {
		$throwNew($StreamCorruptedException, $($String::format("invalid stream header: %04X%04X"_s, $$new($ObjectArray, {
			$($of($Short::valueOf(s0))),
			$($of($Short::valueOf(s1)))
		}))));
	}
}

$ObjectStreamClass* ObjectInputStream::readClassDescriptor() {
	$var($ObjectStreamClass, desc, $new($ObjectStreamClass));
	desc->readNonProxy(this);
	return desc;
}

int32_t ObjectInputStream::read() {
	return $nc(this->bin)->read();
}

int32_t ObjectInputStream::read($bytes* buf, int32_t off, int32_t len) {
	if (buf == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t endoff = off + len;
	if (off < 0 || len < 0 || endoff > $nc(buf)->length || endoff < 0) {
		$throwNew($IndexOutOfBoundsException);
	}
	return $nc(this->bin)->read(buf, off, len, false);
}

int32_t ObjectInputStream::available() {
	return $nc(this->bin)->available();
}

void ObjectInputStream::close() {
	this->closed = true;
	if (this->depth == 0) {
		clear();
	}
	$nc(this->bin)->close();
}

bool ObjectInputStream::readBoolean() {
	return $nc(this->bin)->readBoolean();
}

int8_t ObjectInputStream::readByte() {
	return $nc(this->bin)->readByte();
}

int32_t ObjectInputStream::readUnsignedByte() {
	return $nc(this->bin)->readUnsignedByte();
}

char16_t ObjectInputStream::readChar() {
	return $nc(this->bin)->readChar();
}

int16_t ObjectInputStream::readShort() {
	return $nc(this->bin)->readShort();
}

int32_t ObjectInputStream::readUnsignedShort() {
	return $nc(this->bin)->readUnsignedShort();
}

int32_t ObjectInputStream::readInt() {
	return $nc(this->bin)->readInt();
}

int64_t ObjectInputStream::readLong() {
	return $nc(this->bin)->readLong();
}

float ObjectInputStream::readFloat() {
	return $nc(this->bin)->readFloat();
}

double ObjectInputStream::readDouble() {
	return $nc(this->bin)->readDouble();
}

void ObjectInputStream::readFully($bytes* buf) {
	$nc(this->bin)->readFully(buf, 0, $nc(buf)->length, false);
}

void ObjectInputStream::readFully($bytes* buf, int32_t off, int32_t len) {
	int32_t endoff = off + len;
	if (off < 0 || len < 0 || endoff > $nc(buf)->length || endoff < 0) {
		$throwNew($IndexOutOfBoundsException);
	}
	$nc(this->bin)->readFully(buf, off, len, false);
}

int32_t ObjectInputStream::skipBytes(int32_t len) {
	return $nc(this->bin)->skipBytes(len);
}

$String* ObjectInputStream::readLine() {
	return $nc(this->bin)->readLine();
}

$String* ObjectInputStream::readUTF() {
	return $nc(this->bin)->readUTF();
}

$ObjectInputFilter* ObjectInputStream::getObjectInputFilter() {
	return this->serialFilter;
}

void ObjectInputStream::setObjectInputFilter($ObjectInputFilter* filter) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($ObjectStreamConstants);
		sm->checkPermission($ObjectStreamConstants::SERIAL_FILTER_PERMISSION);
	}
	$init($ObjectInputStream$Caches);
	if (this->totalObjectRefs > 0 && !$ObjectInputStream$Caches::SET_FILTER_AFTER_READ) {
		$throwNew($IllegalStateException, "filter can not be set after an object has been read"_s);
	}
	if (this->streamFilterSet) {
		$throwNew($IllegalStateException, "filter can not be set more than once"_s);
	}
	this->streamFilterSet = true;
	$var($ObjectInputFilter, next, $cast($ObjectInputFilter, $nc($($ObjectInputFilter$Config::getSerialFilterFactory()))->apply(this->serialFilter, filter)));
	if (this->serialFilter != nullptr && next == nullptr) {
		$throwNew($IllegalStateException, "filter can not be replaced with null filter"_s);
	}
	$set(this, serialFilter, next);
}

void ObjectInputStream::filterCheck($Class* clazz, int32_t arrayLength) {
	$useLocalCurrentObjectStackCache();
	int64_t bytesRead = (this->bin == nullptr) ? (int64_t)0 : $nc(this->bin)->getBytesRead();
	$var($RuntimeException, ex, nullptr);
	$ObjectInputFilter$Status* status = nullptr;
	if (this->serialFilter != nullptr) {
		try {
			status = $nc(this->serialFilter)->checkInput($$new($ObjectInputStream$FilterValues, clazz, arrayLength, this->totalObjectRefs, this->depth, bytesRead));
		} catch ($RuntimeException& e) {
			$init($ObjectInputFilter$Status);
			status = $ObjectInputFilter$Status::REJECTED;
			$assign(ex, e);
		}
		$init($ObjectInputStream$Logging);
		if ($ObjectInputStream$Logging::filterLogger != nullptr) {
			$init($ObjectInputFilter$Status);
			$init($System$Logger$Level);
			$nc($ObjectInputStream$Logging::filterLogger)->log(status == nullptr || status == $ObjectInputFilter$Status::REJECTED ? $System$Logger$Level::DEBUG : $System$Logger$Level::TRACE, "ObjectInputFilter {0}: {1}, array length: {2}, nRefs: {3}, depth: {4}, bytes: {5}, ex: {6}"_s, $$new($ObjectArray, {
				$of(status),
				$of(clazz),
				$($of($Integer::valueOf(arrayLength))),
				$($of($Long::valueOf(this->totalObjectRefs))),
				$($of($Long::valueOf(this->depth))),
				$($of($Long::valueOf(bytesRead))),
				$($of($Objects::toString(ex, "n/a"_s)))
			}));
		}
	}
	$var($DeserializationEvent, event, $new($DeserializationEvent));
	if (event->shouldCommit()) {
		event->filterConfigured = this->serialFilter != nullptr;
		$set(event, filterStatus, status != nullptr ? $nc(status)->name() : ($String*)nullptr);
		$set(event, type, clazz);
		event->arrayLength = arrayLength;
		event->objectReferences = this->totalObjectRefs;
		event->depth = this->depth;
		event->bytesRead = bytesRead;
		$set(event, exceptionType, ex != nullptr ? $nc($of(ex))->getClass() : ($Class*)nullptr);
		$set(event, exceptionMessage, ex != nullptr ? ex->getMessage() : ($String*)nullptr);
		event->commit();
	}
	$init($ObjectInputFilter$Status);
	if (this->serialFilter != nullptr && (status == nullptr || status == $ObjectInputFilter$Status::REJECTED)) {
		$var($InvalidClassException, ice, $new($InvalidClassException, $$str({"filter status: "_s, status})));
		ice->initCause(ex);
		$throw(ice);
	}
}

void ObjectInputStream::checkArray($Class* arrayType, int32_t arrayLength) {
	if (!$nc(arrayType)->isArray()) {
		$throwNew($IllegalArgumentException, "not an array type"_s);
	}
	if (arrayLength < 0) {
		$throwNew($NegativeArraySizeException);
	}
	filterCheck(arrayType, arrayLength);
}

void ObjectInputStream::verifySubclass() {
	$useLocalCurrentObjectStackCache();
	$Class* cl = $of(this)->getClass();
	if (cl == ObjectInputStream::class$) {
		return;
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		return;
	}
	$init($ObjectInputStream$Caches);
	$ObjectStreamClass::processQueue($ObjectInputStream$Caches::subclassAuditsQueue, $ObjectInputStream$Caches::subclassAudits);
	$var($ObjectStreamClass$WeakClassKey, key, $new($ObjectStreamClass$WeakClassKey, cl, $ObjectInputStream$Caches::subclassAuditsQueue));
	$var($Boolean, result, $cast($Boolean, $nc($ObjectInputStream$Caches::subclassAudits)->get(key)));
	if (result == nullptr) {
		$assign(result, auditSubclass(cl));
		$nc($ObjectInputStream$Caches::subclassAudits)->putIfAbsent(key, result);
	}
	if (!$nc(result)->booleanValue()) {
		$init($ObjectStreamConstants);
		$nc(sm)->checkPermission($ObjectStreamConstants::SUBCLASS_IMPLEMENTATION_PERMISSION);
	}
}

$Boolean* ObjectInputStream::auditSubclass($Class* subcl) {
	$init(ObjectInputStream);
	$beforeCallerSensitive();
	return $cast($Boolean, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ObjectInputStream$1, subcl))));
}

void ObjectInputStream::clear() {
	$nc(this->handles)->clear();
	$nc(this->vlist)->clear();
}

$Object* ObjectInputStream::readObject0($Class* type, bool unshared) {
	$useLocalCurrentObjectStackCache();
	bool oldMode = $nc(this->bin)->getBlockDataMode();
	if (oldMode) {
		int32_t remain = $nc(this->bin)->currentBlockRemaining();
		if (remain > 0) {
			$throwNew($OptionalDataException, remain);
		} else if (this->defaultDataEnd) {
			$throwNew($OptionalDataException, true);
		}
		$nc(this->bin)->setBlockDataMode(false);
	}
	int8_t tc = 0;
	while ((tc = $nc(this->bin)->peekByte()) == $ObjectStreamConstants::TC_RESET) {
		$nc(this->bin)->readByte();
		handleReset();
	}
	++this->depth;
	++this->totalObjectRefs;
	{
		$var($Throwable, var$0, nullptr);
		$var($Object, var$2, nullptr);
		bool return$1 = false;
		try {
			{
				$var($IOException, ex, nullptr)
				switch (tc) {
				case $ObjectStreamConstants::TC_NULL:
					{
						$assign(var$2, readNull());
						return$1 = true;
						goto $finally;
					}
				case $ObjectStreamConstants::TC_REFERENCE:
					{
						$assign(var$2, $nc(type)->cast($(readHandle(unshared))));
						return$1 = true;
						goto $finally;
					}
				case $ObjectStreamConstants::TC_CLASS:
					{
						if (type == $String::class$) {
							$throwNew($ClassCastException, "Cannot cast a class to java.lang.String"_s);
						}
						$assign(var$2, readClass(unshared));
						return$1 = true;
						goto $finally;
					}
				case $ObjectStreamConstants::TC_CLASSDESC:
					{}
				case $ObjectStreamConstants::TC_PROXYCLASSDESC:
					{
						if (type == $String::class$) {
							$throwNew($ClassCastException, "Cannot cast a class to java.lang.String"_s);
						}
						$assign(var$2, readClassDesc(unshared));
						return$1 = true;
						goto $finally;
					}
				case $ObjectStreamConstants::TC_STRING:
					{}
				case $ObjectStreamConstants::TC_LONGSTRING:
					{
						$assign(var$2, checkResolve($(readString(unshared))));
						return$1 = true;
						goto $finally;
					}
				case $ObjectStreamConstants::TC_ARRAY:
					{
						if (type == $String::class$) {
							$throwNew($ClassCastException, "Cannot cast an array to java.lang.String"_s);
						}
						$assign(var$2, checkResolve($(readArray(unshared))));
						return$1 = true;
						goto $finally;
					}
				case $ObjectStreamConstants::TC_ENUM:
					{
						if (type == $String::class$) {
							$throwNew($ClassCastException, "Cannot cast an enum to java.lang.String"_s);
						}
						$assign(var$2, checkResolve($(readEnum(unshared))));
						return$1 = true;
						goto $finally;
					}
				case $ObjectStreamConstants::TC_OBJECT:
					{
						if (type == $String::class$) {
							$throwNew($ClassCastException, "Cannot cast an object to java.lang.String"_s);
						}
						$assign(var$2, checkResolve($(readOrdinaryObject(unshared))));
						return$1 = true;
						goto $finally;
					}
				case $ObjectStreamConstants::TC_EXCEPTION:
					{
						if (type == $String::class$) {
							$throwNew($ClassCastException, "Cannot cast an exception to java.lang.String"_s);
						}
						$assign(ex, readFatalException());
						$throwNew($WriteAbortedException, "writing aborted"_s, ex);
					}
				case $ObjectStreamConstants::TC_BLOCKDATA:
					{}
				case $ObjectStreamConstants::TC_BLOCKDATALONG:
					{
						if (oldMode) {
							$nc(this->bin)->setBlockDataMode(true);
							$nc(this->bin)->peek();
							$throwNew($OptionalDataException, $nc(this->bin)->currentBlockRemaining());
						} else {
							$throwNew($StreamCorruptedException, "unexpected block data"_s);
						}
					}
				case $ObjectStreamConstants::TC_ENDBLOCKDATA:
					{
						if (oldMode) {
							$throwNew($OptionalDataException, true);
						} else {
							$throwNew($StreamCorruptedException, "unexpected end of block data"_s);
						}
					}
				default:
					{
						$throwNew($StreamCorruptedException, $($String::format("invalid type code: %02X"_s, $$new($ObjectArray, {$($of($Byte::valueOf(tc)))}))));
					}
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			--this->depth;
			$nc(this->bin)->setBlockDataMode(oldMode);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Object* ObjectInputStream::checkResolve(Object$* obj) {
	if (!this->enableResolve || $nc(this->handles)->lookupException(this->passHandle) != nullptr) {
		return $of(obj);
	}
	$var($Object, rep, resolveObject(obj));
	if (!$equals(rep, obj)) {
		if (rep != nullptr) {
			if ($of(rep)->getClass()->isArray()) {
				$Class* var$0 = $of(rep)->getClass();
				filterCheck(var$0, $1Array::getLength(rep));
			} else {
				filterCheck($of(rep)->getClass(), -1);
			}
		}
		$nc(this->handles)->setObject(this->passHandle, rep);
	}
	return $of(rep);
}

$String* ObjectInputStream::readTypeString() {
	$useLocalCurrentObjectStackCache();
	int32_t oldHandle = this->passHandle;
	{
		$var($Throwable, var$0, nullptr);
		$var($String, var$2, nullptr);
		bool return$1 = false;
		try {
			int8_t tc = $nc(this->bin)->peekByte();

			$var($String, var$3, nullptr)
			switch (tc) {
			case $ObjectStreamConstants::TC_NULL:
				{
					$assign(var$3, $cast($String, readNull()));
					break;
				}
			case $ObjectStreamConstants::TC_REFERENCE:
				{
					$assign(var$3, $cast($String, readHandle(false)));
					break;
				}
			case $ObjectStreamConstants::TC_STRING:
				{}
			case $ObjectStreamConstants::TC_LONGSTRING:
				{
					$assign(var$3, readString(false));
					break;
				}
			default:
				{
					$throwNew($StreamCorruptedException, $($String::format("invalid type code: %02X"_s, $$new($ObjectArray, {$($of($Byte::valueOf(tc)))}))));
				}
			}
			$assign(var$2, var$3);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			this->passHandle = oldHandle;
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

$Object* ObjectInputStream::readNull() {
	if ($nc(this->bin)->readByte() != $ObjectStreamConstants::TC_NULL) {
		$throwNew($InternalError);
	}
	this->passHandle = ObjectInputStream::NULL_HANDLE;
	return $of(nullptr);
}

$Object* ObjectInputStream::readHandle(bool unshared) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->bin)->readByte() != $ObjectStreamConstants::TC_REFERENCE) {
		$throwNew($InternalError);
	}
	this->passHandle = $nc(this->bin)->readInt() - $ObjectStreamConstants::baseWireHandle;
	if (this->passHandle < 0 || this->passHandle >= $nc(this->handles)->size()) {
		$throwNew($StreamCorruptedException, $($String::format("invalid handle value: %08X"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->passHandle + $ObjectStreamConstants::baseWireHandle)))}))));
	}
	if (unshared) {
		$throwNew($InvalidObjectException, "cannot read back reference as unshared"_s);
	}
	$var($Object, obj, $nc(this->handles)->lookupObject(this->passHandle));
	if ($equals(obj, ObjectInputStream::unsharedMarker)) {
		$throwNew($InvalidObjectException, "cannot read back reference to unshared object"_s);
	}
	filterCheck(nullptr, -1);
	return $of(obj);
}

$Class* ObjectInputStream::readClass(bool unshared) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(this->bin)->readByte() != $ObjectStreamConstants::TC_CLASS) {
		$throwNew($InternalError);
	}
	$var($ObjectStreamClass, desc, readClassDesc(false));
	$Class* cl = $nc(desc)->forClass();
	this->passHandle = $nc(this->handles)->assign(unshared ? ObjectInputStream::unsharedMarker : $of(cl));
	$var($ClassNotFoundException, resolveEx, desc->getResolveException());
	if (resolveEx != nullptr) {
		$nc(this->handles)->markException(this->passHandle, resolveEx);
	}
	$nc(this->handles)->finish(this->passHandle);
	return cl;
}

$ObjectStreamClass* ObjectInputStream::readClassDesc(bool unshared) {
	$useLocalCurrentObjectStackCache();
	int8_t tc = $nc(this->bin)->peekByte();

	$var($ObjectStreamClass, var$0, nullptr)
	switch (tc) {
	case $ObjectStreamConstants::TC_NULL:
		{
			$assign(var$0, $cast($ObjectStreamClass, readNull()));
			break;
		}
	case $ObjectStreamConstants::TC_PROXYCLASSDESC:
		{
			$assign(var$0, readProxyDesc(unshared));
			break;
		}
	case $ObjectStreamConstants::TC_CLASSDESC:
		{
			$assign(var$0, readNonProxyDesc(unshared));
			break;
		}
	case $ObjectStreamConstants::TC_REFERENCE:
		{
			{
				$var($ObjectStreamClass, d, $cast($ObjectStreamClass, readHandle(unshared)));
				$nc(d)->checkInitialized();
				$assign(var$0, d);
				break;
			}
		}
	default:
		{
			$throwNew($StreamCorruptedException, $($String::format("invalid type code: %02X"_s, $$new($ObjectArray, {$($of($Byte::valueOf(tc)))}))));
		}
	}
	return var$0;
}

bool ObjectInputStream::isCustomSubclass() {
	$beforeCallerSensitive();
	return $of(this)->getClass()->getClassLoader() != ObjectInputStream::class$->getClassLoader();
}

$ObjectStreamClass* ObjectInputStream::readProxyDesc(bool unshared) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(this->bin)->readByte() != $ObjectStreamConstants::TC_PROXYCLASSDESC) {
		$throwNew($InternalError);
	}
	$var($ObjectStreamClass, desc, $new($ObjectStreamClass));
	int32_t descHandle = $nc(this->handles)->assign(unshared ? ObjectInputStream::unsharedMarker : $of(desc));
	this->passHandle = ObjectInputStream::NULL_HANDLE;
	int32_t numIfaces = $nc(this->bin)->readInt();
	if (numIfaces > 0x0000FFFF) {
		$init($ObjectInputStream$Caches);
		$throwNew($InvalidObjectException, $$str({"interface limit exceeded: "_s, $$str(numIfaces), ", limit: "_s, $$str($ObjectInputStream$Caches::PROXY_INTERFACE_LIMIT)}));
	}
	$var($StringArray, ifaces, $new($StringArray, numIfaces));
	for (int32_t i = 0; i < numIfaces; ++i) {
		ifaces->set(i, $($nc(this->bin)->readUTF()));
	}
	$init($ObjectInputStream$Caches);
	if (numIfaces > $ObjectInputStream$Caches::PROXY_INTERFACE_LIMIT) {
		$throwNew($InvalidObjectException, $$str({"interface limit exceeded: "_s, $$str(numIfaces), ", limit: "_s, $$str($ObjectInputStream$Caches::PROXY_INTERFACE_LIMIT), "; "_s, $($Arrays::toString(ifaces))}));
	}
	$Class* cl = nullptr;
	$var($ClassNotFoundException, resolveEx, nullptr);
	$nc(this->bin)->setBlockDataMode(true);
	try {
		if ((cl = resolveProxyClass(ifaces)) == nullptr) {
			$assign(resolveEx, $new($ClassNotFoundException, "null class"_s));
		} else if (!$Proxy::isProxyClass(cl)) {
			$throwNew($InvalidClassException, "Not a proxy"_s);
		} else {
			$var($ClassLoader, var$0, $of(this)->getClass()->getClassLoader());
			$ReflectUtil::checkProxyPackageAccess(var$0, $($nc(cl)->getInterfaces()));
			{
				$var($ClassArray, arr$, $nc(cl)->getInterfaces());
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$Class* clazz = arr$->get(i$);
					{
						filterCheck(clazz, -1);
					}
				}
			}
		}
	} catch ($ClassNotFoundException& ex) {
		$assign(resolveEx, ex);
	} catch ($OutOfMemoryError& memerr) {
		$var($IOException, ex, $new($InvalidObjectException, $$str({"Proxy interface limit exceeded: "_s, $($Arrays::toString(ifaces))})));
		ex->initCause(memerr);
		$throw(ex);
	}
	filterCheck(cl, -1);
	skipCustomData();
	{
		$var($Throwable, var$1, nullptr);
		try {
			try {
				++this->totalObjectRefs;
				++this->depth;
				desc->initProxy(cl, resolveEx, $(readClassDesc(false)));
			} catch ($OutOfMemoryError& memerr) {
				$var($IOException, ex, $new($InvalidObjectException, $$str({"Proxy interface limit exceeded: "_s, $($Arrays::toString(ifaces))})));
				ex->initCause(memerr);
				$throw(ex);
			}
		} catch ($Throwable& var$2) {
			$assign(var$1, var$2);
		} /*finally*/ {
			--this->depth;
		}
		if (var$1 != nullptr) {
			$throw(var$1);
		}
	}
	$nc(this->handles)->finish(descHandle);
	this->passHandle = descHandle;
	return desc;
}

$ObjectStreamClass* ObjectInputStream::readNonProxyDesc(bool unshared) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->bin)->readByte() != $ObjectStreamConstants::TC_CLASSDESC) {
		$throwNew($InternalError);
	}
	$var($ObjectStreamClass, desc, $new($ObjectStreamClass));
	int32_t descHandle = $nc(this->handles)->assign(unshared ? ObjectInputStream::unsharedMarker : $of(desc));
	this->passHandle = ObjectInputStream::NULL_HANDLE;
	$var($ObjectStreamClass, readDesc, nullptr);
	try {
		$assign(readDesc, readClassDescriptor());
	} catch ($ClassNotFoundException& ex) {
		$throw($cast($IOException, $($$new($InvalidClassException, "failed to read class descriptor"_s)->initCause(ex))));
	}
	$Class* cl = nullptr;
	$var($ClassNotFoundException, resolveEx, nullptr);
	$nc(this->bin)->setBlockDataMode(true);
	bool checksRequired = isCustomSubclass();
	try {
		if ((cl = resolveClass(readDesc)) == nullptr) {
			$assign(resolveEx, $new($ClassNotFoundException, "null class"_s));
		} else if (checksRequired) {
			$ReflectUtil::checkPackageAccess(cl);
		}
	} catch ($ClassNotFoundException& ex) {
		$assign(resolveEx, ex);
	}
	filterCheck(cl, -1);
	skipCustomData();
	{
		$var($Throwable, var$0, nullptr);
		try {
			++this->totalObjectRefs;
			++this->depth;
			desc->initNonProxy(readDesc, cl, resolveEx, $(readClassDesc(false)));
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			--this->depth;
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$nc(this->handles)->finish(descHandle);
	this->passHandle = descHandle;
	return desc;
}

$String* ObjectInputStream::readString(bool unshared) {
	$useLocalCurrentObjectStackCache();
	int8_t tc = $nc(this->bin)->readByte();

	$var($String, var$0, nullptr)
	switch (tc) {
	case $ObjectStreamConstants::TC_STRING:
		{
			$assign(var$0, $nc(this->bin)->readUTF());
			break;
		}
	case $ObjectStreamConstants::TC_LONGSTRING:
		{
			$assign(var$0, $nc(this->bin)->readLongUTF());
			break;
		}
	default:
		{
			$throwNew($StreamCorruptedException, $($String::format("invalid type code: %02X"_s, $$new($ObjectArray, {$($of($Byte::valueOf(tc)))}))));
		}
	}
	$var($String, str, var$0);
	this->passHandle = $nc(this->handles)->assign(unshared ? ObjectInputStream::unsharedMarker : $of(str));
	$nc(this->handles)->finish(this->passHandle);
	return str;
}

$Object* ObjectInputStream::readArray(bool unshared) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(this->bin)->readByte() != $ObjectStreamConstants::TC_ARRAY) {
		$throwNew($InternalError);
	}
	$var($ObjectStreamClass, desc, readClassDesc(false));
	int32_t len = $nc(this->bin)->readInt();
	filterCheck($nc(desc)->forClass(), len);
	$var($Object, array, nullptr);
	$Class* cl = nullptr;
	$Class* ccl = nullptr;
	if ((cl = $nc(desc)->forClass()) != nullptr) {
		ccl = $nc(cl)->getComponentType();
		$assign(array, $1Array::newInstance(ccl, len));
	}
	int32_t arrayHandle = $nc(this->handles)->assign(unshared ? ObjectInputStream::unsharedMarker : array);
	$var($ClassNotFoundException, resolveEx, $nc(desc)->getResolveException());
	if (resolveEx != nullptr) {
		$nc(this->handles)->markException(arrayHandle, resolveEx);
	}
	if (ccl == nullptr) {
		for (int32_t i = 0; i < len; ++i) {
			readObject0($Object::class$, false);
		}
	} else if ($nc(ccl)->isPrimitive()) {
		$init($Integer);
		if (ccl == $Integer::TYPE) {
			$nc(this->bin)->readInts($cast($ints, array), 0, len);
		} else {
			$init($Byte);
			if (ccl == $Byte::TYPE) {
				$nc(this->bin)->readFully($cast($bytes, array), 0, len, true);
			} else {
				$init($Long);
				if (ccl == $Long::TYPE) {
					$nc(this->bin)->readLongs($cast($longs, array), 0, len);
				} else {
					$init($Float);
					if (ccl == $Float::TYPE) {
						$nc(this->bin)->readFloats($cast($floats, array), 0, len);
					} else {
						$init($Double);
						if (ccl == $Double::TYPE) {
							$nc(this->bin)->readDoubles($cast($doubles, array), 0, len);
						} else {
							$init($Short);
							if (ccl == $Short::TYPE) {
								$nc(this->bin)->readShorts($cast($shorts, array), 0, len);
							} else {
								$init($Character);
								if (ccl == $Character::TYPE) {
									$nc(this->bin)->readChars($cast($chars, array), 0, len);
								} else {
									$init($Boolean);
									if (ccl == $Boolean::TYPE) {
										$nc(this->bin)->readBooleans($cast($booleans, array), 0, len);
									} else {
										$throwNew($InternalError);
									}
								}
							}
						}
					}
				}
			}
		}
	} else {
		$var($ObjectArray, oa, $cast($ObjectArray, array));
		for (int32_t i = 0; i < len; ++i) {
			$nc(oa)->set(i, $(readObject0($Object::class$, false)));
			$nc(this->handles)->markDependency(arrayHandle, this->passHandle);
		}
	}
	$nc(this->handles)->finish(arrayHandle);
	this->passHandle = arrayHandle;
	return $of(array);
}

$Enum* ObjectInputStream::readEnum(bool unshared) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(this->bin)->readByte() != $ObjectStreamConstants::TC_ENUM) {
		$throwNew($InternalError);
	}
	$var($ObjectStreamClass, desc, readClassDesc(false));
	if (!$nc(desc)->isEnum()) {
		$throwNew($InvalidClassException, $$str({"non-enum class: "_s, desc}));
	}
	int32_t enumHandle = $nc(this->handles)->assign(unshared ? ObjectInputStream::unsharedMarker : ($Object*)nullptr);
	$var($ClassNotFoundException, resolveEx, $nc(desc)->getResolveException());
	if (resolveEx != nullptr) {
		$nc(this->handles)->markException(enumHandle, resolveEx);
	}
	$var($String, name, readString(false));
	$var($Enum, result, nullptr);
	$Class* cl = desc->forClass();
	if (cl != nullptr) {
		try {
			$var($Enum, en, $Enum::valueOf(cl, name));
			$assign(result, en);
		} catch ($IllegalArgumentException& ex) {
			$throw($cast($IOException, $($$new($InvalidObjectException, $$str({"enum constant "_s, name, " does not exist in "_s, cl}))->initCause(ex))));
		}
		if (!unshared) {
			$nc(this->handles)->setObject(enumHandle, result);
		}
	}
	$nc(this->handles)->finish(enumHandle);
	this->passHandle = enumHandle;
	return result;
}

$Object* ObjectInputStream::readOrdinaryObject(bool unshared) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(this->bin)->readByte() != $ObjectStreamConstants::TC_OBJECT) {
		$throwNew($InternalError);
	}
	$var($ObjectStreamClass, desc, readClassDesc(false));
	$nc(desc)->checkDeserialize();
	$Class* cl = desc->forClass();
	if (cl == $String::class$ || cl == $Class::class$ || cl == $ObjectStreamClass::class$) {
		$throwNew($InvalidClassException, "invalid class descriptor"_s);
	}
	$var($Object, obj, nullptr);
	try {
		$assign(obj, desc->isInstantiable() ? desc->newInstance() : ($Object*)nullptr);
	} catch ($Exception& ex) {
		$throw($cast($IOException, $($$new($InvalidClassException, $($nc(desc->forClass())->getName()), "unable to create instance"_s)->initCause(ex))));
	}
	this->passHandle = $nc(this->handles)->assign(unshared ? ObjectInputStream::unsharedMarker : obj);
	$var($ClassNotFoundException, resolveEx, desc->getResolveException());
	if (resolveEx != nullptr) {
		$nc(this->handles)->markException(this->passHandle, resolveEx);
	}
	bool isRecord = desc->isRecord();
	if (isRecord) {
		if (!ObjectInputStream::$assertionsDisabled && !(obj == nullptr)) {
			$throwNew($AssertionError);
		}
		$assign(obj, readRecord(desc));
		if (!unshared) {
			$nc(this->handles)->setObject(this->passHandle, obj);
		}
	} else if (desc->isExternalizable()) {
		readExternalData($cast($Externalizable, obj), desc);
	} else {
		readSerialData(obj, desc);
	}
	$nc(this->handles)->finish(this->passHandle);
	bool var$0 = obj != nullptr && $nc(this->handles)->lookupException(this->passHandle) == nullptr;
	if (var$0 && desc->hasReadResolveMethod()) {
		$var($Object, rep, desc->invokeReadResolve(obj));
		if (unshared && $nc($of(rep))->getClass()->isArray()) {
			$assign(rep, cloneArray(rep));
		}
		if (!$equals(rep, obj)) {
			if (rep != nullptr) {
				if ($of(rep)->getClass()->isArray()) {
					$Class* var$1 = $of(rep)->getClass();
					filterCheck(var$1, $1Array::getLength(rep));
				} else {
					filterCheck($of(rep)->getClass(), -1);
				}
			}
			$nc(this->handles)->setObject(this->passHandle, $assign(obj, rep));
		}
	}
	return $of(obj);
}

void ObjectInputStream::readExternalData($Externalizable* obj, $ObjectStreamClass* desc) {
	$useLocalCurrentObjectStackCache();
	$var($SerialCallbackContext, oldContext, this->curContext);
	if (oldContext != nullptr) {
		oldContext->check();
	}
	$set(this, curContext, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			bool blocked = $nc(desc)->hasBlockExternalData();
			if (blocked) {
				$nc(this->bin)->setBlockDataMode(true);
			}
			if (obj != nullptr) {
				try {
					obj->readExternal(this);
				} catch ($ClassNotFoundException& ex) {
					$nc(this->handles)->markException(this->passHandle, ex);
				}
			}
			if (blocked) {
				skipCustomData();
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			if (oldContext != nullptr) {
				oldContext->check();
			}
			$set(this, curContext, oldContext);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$Object* ObjectInputStream::readRecord($ObjectStreamClass* desc) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectStreamClass$ClassDataSlotArray, slots, $nc(desc)->getClassDataLayout());
	if ($nc(slots)->length != 1) {
		for (int32_t i = 0; i < slots->length - 1; ++i) {
			if ($nc(slots->get(i))->hasData) {
				$new($ObjectInputStream$FieldValues, this, $nc(slots->get(i))->desc, true);
			}
		}
	}
	$var($ObjectInputStream$FieldValues, fieldValues, $new($ObjectInputStream$FieldValues, this, desc, true));
	$var($MethodHandle, ctrMH, $ObjectStreamClass$RecordSupport::deserializationCtr(desc));
	try {
		return $of($nc(ctrMH)->invokeExact($$new($ObjectArray, {$of(fieldValues->primValues), $of(fieldValues->objValues)})));
	} catch ($Exception& e) {
		$var($InvalidObjectException, ioe, $new($InvalidObjectException, $(e->getMessage())));
		ioe->initCause(e);
		$throw(ioe);
	} catch ($Error& e) {
		$throw(e);
	} catch ($Throwable& t) {
		$var($ObjectStreamException, ose, $new($InvalidObjectException, "ReflectiveOperationException during deserialization"_s));
		ose->initCause(t);
		$throw(ose);
	}
	$shouldNotReachHere();
}

void ObjectInputStream::readSerialData(Object$* obj, $ObjectStreamClass* desc) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectStreamClass$ClassDataSlotArray, slots, $nc(desc)->getClassDataLayout());
	$var($ObjectInputStream$FieldValuesArray, slotValues, nullptr);
	bool hasSpecialReadMethod = false;
	for (int32_t i = 1; i < $nc(slots)->length; ++i) {
		$var($ObjectStreamClass, slotDesc, $nc(slots->get(i))->desc);
		bool var$0 = $nc(slotDesc)->hasReadObjectMethod();
		if (var$0 || $nc(slotDesc)->hasReadObjectNoDataMethod()) {
			hasSpecialReadMethod = true;
			break;
		}
	}
	if (!hasSpecialReadMethod) {
		$assign(slotValues, $new($ObjectInputStream$FieldValuesArray, $nc(slots)->length));
	}
	for (int32_t i = 0; i < $nc(slots)->length; ++i) {
		$var($ObjectStreamClass, slotDesc, $nc(slots->get(i))->desc);
		if ($nc(slots->get(i))->hasData) {
			if (obj == nullptr || $nc(this->handles)->lookupException(this->passHandle) != nullptr) {
				$new($ObjectInputStream$FieldValues, this, slotDesc, true);
			} else if ($nc(slotDesc)->hasReadObjectMethod()) {
				$var($ThreadDeath, t, nullptr);
				bool reset = false;
				$var($SerialCallbackContext, oldContext, this->curContext);
				if (oldContext != nullptr) {
					oldContext->check();
				}
				{
					$var($Throwable, var$1, nullptr);
					try {
						try {
							$set(this, curContext, $new($SerialCallbackContext, obj, slotDesc));
							$nc(this->bin)->setBlockDataMode(true);
							slotDesc->invokeReadObject(obj, this);
						} catch ($ClassNotFoundException& ex) {
							$nc(this->handles)->markException(this->passHandle, ex);
						}
					} catch ($Throwable& var$2) {
						$assign(var$1, var$2);
					} /*finally*/ {
						do {
							try {
								$nc(this->curContext)->setUsed();
								if (oldContext != nullptr) {
									oldContext->check();
								}
								$set(this, curContext, oldContext);
								reset = true;
							} catch ($ThreadDeath& x) {
								$assign(t, x);
							}
						} while (!reset);
						if (t != nullptr) {
							$throw(t);
						}
					}
					if (var$1 != nullptr) {
						$throw(var$1);
					}
				}
				this->defaultDataEnd = false;
			} else {
				$var($ObjectInputStream$FieldValues, values, $new($ObjectInputStream$FieldValues, this, slotDesc, true));
				if (slotValues != nullptr) {
					slotValues->set(i, values);
				} else if (obj != nullptr) {
					values->defaultCheckFieldValues(obj);
					values->defaultSetFieldValues(obj);
				}
			}
			if ($nc(slotDesc)->hasWriteObjectData()) {
				skipCustomData();
			} else {
				$nc(this->bin)->setBlockDataMode(false);
			}
		} else {
			bool var$4 = obj != nullptr && $nc(slotDesc)->hasReadObjectNoDataMethod();
			if (var$4 && $nc(this->handles)->lookupException(this->passHandle) == nullptr) {
				slotDesc->invokeReadObjectNoData(obj);
			}
		}
	}
	if (obj != nullptr && slotValues != nullptr) {
		for (int32_t i = 0; i < $nc(slots)->length; ++i) {
			if (slotValues->get(i) != nullptr) {
				$nc(slotValues->get(i))->defaultCheckFieldValues(obj);
			}
		}
		for (int32_t i = 0; i < $nc(slots)->length; ++i) {
			if (slotValues->get(i) != nullptr) {
				$nc(slotValues->get(i))->defaultSetFieldValues(obj);
			}
		}
	}
}

void ObjectInputStream::skipCustomData() {
	int32_t oldHandle = this->passHandle;
	for (;;) {
		if ($nc(this->bin)->getBlockDataMode()) {
			$nc(this->bin)->skipBlockData();
			$nc(this->bin)->setBlockDataMode(false);
		}
		switch ($nc(this->bin)->peekByte()) {
		case $ObjectStreamConstants::TC_BLOCKDATA:
			{}
		case $ObjectStreamConstants::TC_BLOCKDATALONG:
			{
				$nc(this->bin)->setBlockDataMode(true);
				break;
			}
		case $ObjectStreamConstants::TC_ENDBLOCKDATA:
			{
				$nc(this->bin)->readByte();
				this->passHandle = oldHandle;
				return;
			}
		default:
			{
				readObject0($Object::class$, false);
				break;
			}
		}
	}
}

$IOException* ObjectInputStream::readFatalException() {
	if ($nc(this->bin)->readByte() != $ObjectStreamConstants::TC_EXCEPTION) {
		$throwNew($InternalError);
	}
	clear();
	return $cast($IOException, readObject0($Object::class$, false));
}

void ObjectInputStream::handleReset() {
	$useLocalCurrentObjectStackCache();
	if (this->depth > 0) {
		$throwNew($StreamCorruptedException, $$str({"unexpected reset; recursion depth: "_s, $$str(this->depth)}));
	}
	clear();
}

$ClassLoader* ObjectInputStream::latestUserDefinedLoader() {
	$init(ObjectInputStream);
	return $VM::latestUserDefinedLoader();
}

void ObjectInputStream::freeze() {
	$nc(ObjectInputStream::UNSAFE)->storeFence();
}

$Object* ObjectInputStream::cloneArray(Object$* array) {
	$init(ObjectInputStream);
	if ($instanceOf($ObjectArray, array)) {
		return $of($nc(($cast($ObjectArray, array)))->clone());
	} else if ($instanceOf($booleans, array)) {
		return $of($nc(($cast($booleans, array)))->clone());
	} else if ($instanceOf($bytes, array)) {
		return $of($nc(($cast($bytes, array)))->clone());
	} else if ($instanceOf($chars, array)) {
		return $of($nc(($cast($chars, array)))->clone());
	} else if ($instanceOf($doubles, array)) {
		return $of($nc(($cast($doubles, array)))->clone());
	} else if ($instanceOf($floats, array)) {
		return $of($nc(($cast($floats, array)))->clone());
	} else if ($instanceOf($ints, array)) {
		return $of($nc(($cast($ints, array)))->clone());
	} else if ($instanceOf($longs, array)) {
		return $of($nc(($cast($longs, array)))->clone());
	} else if ($instanceOf($shorts, array)) {
		return $of($nc(($cast($shorts, array)))->clone());
	} else {
		$throwNew($AssertionError);
	}
}

void clinit$ObjectInputStream($Class* class$) {
	$useLocalCurrentObjectStackCache();
	ObjectInputStream::$assertionsDisabled = !ObjectInputStream::class$->desiredAssertionStatus();
	$assignStatic(ObjectInputStream::unsharedMarker, $new($Object));
	$init($Boolean);
	$init($Byte);
	$init($Character);
	$init($Short);
	$init($Integer);
	$init($Long);
	$init($Float);
	$init($Double);
	$init($Void);
	$assignStatic(ObjectInputStream::primClasses, $Map::of("boolean"_s, $Boolean::TYPE, "byte"_s, $Byte::TYPE, "char"_s, $Character::TYPE, "short"_s, $Short::TYPE, "int"_s, $Integer::TYPE, "long"_s, $Long::TYPE, "float"_s, $Float::TYPE, "double"_s, $Double::TYPE, "void"_s, $Void::TYPE));
	$assignStatic(ObjectInputStream::UNSAFE, $Unsafe::getUnsafe());
	{
		$SharedSecrets::setJavaObjectInputStreamAccess(static_cast<$JavaObjectInputStreamAccess*>($$new(ObjectInputStream$$Lambda$checkArray)));
		$SharedSecrets::setJavaObjectInputStreamReadString(static_cast<$JavaObjectInputStreamReadString*>($$new(ObjectInputStream$$Lambda$readString$1)));
	}
}

ObjectInputStream::ObjectInputStream() {
}

$Class* ObjectInputStream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ObjectInputStream$$Lambda$checkArray::classInfo$.name)) {
			return ObjectInputStream$$Lambda$checkArray::load$(name, initialize);
		}
		if (name->equals(ObjectInputStream$$Lambda$readString$1::classInfo$.name)) {
			return ObjectInputStream$$Lambda$readString$1::load$(name, initialize);
		}
	}
	$loadClass(ObjectInputStream, name, initialize, &_ObjectInputStream_ClassInfo_, clinit$ObjectInputStream, allocate$ObjectInputStream);
	return class$;
}

$Class* ObjectInputStream::class$ = nullptr;

	} // io
} // java
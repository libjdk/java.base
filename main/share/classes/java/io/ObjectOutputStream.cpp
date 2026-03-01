#include <java/io/ObjectOutputStream.h>

#include <java/io/Externalizable.h>
#include <java/io/IOException.h>
#include <java/io/InvalidClassException.h>
#include <java/io/NotActiveException.h>
#include <java/io/NotSerializableException.h>
#include <java/io/ObjectOutput.h>
#include <java/io/ObjectOutputStream$1.h>
#include <java/io/ObjectOutputStream$BlockDataOutputStream.h>
#include <java/io/ObjectOutputStream$Caches.h>
#include <java/io/ObjectOutputStream$DebugTraceInfoStack.h>
#include <java/io/ObjectOutputStream$HandleTable.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream$PutFieldImpl.h>
#include <java/io/ObjectOutputStream$ReplaceTable.h>
#include <java/io/ObjectStreamClass$ClassDataSlot.h>
#include <java/io/ObjectStreamClass$WeakClassKey.h>
#include <java/io/ObjectStreamClass.h>
#include <java/io/ObjectStreamConstants.h>
#include <java/io/ObjectStreamField.h>
#include <java/io/OutputStream.h>
#include <java/io/SerialCallbackContext.h>
#include <java/io/Serializable.h>
#include <java/io/SerializablePermission.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Enum.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <sun/security/action/GetBooleanAction.h>
#include <jcpp.h>

#undef PROTOCOL_VERSION_1
#undef PROTOCOL_VERSION_2
#undef STREAM_MAGIC
#undef STREAM_VERSION
#undef SUBCLASS_IMPLEMENTATION_PERMISSION
#undef SUBSTITUTION_PERMISSION
#undef TC_ARRAY
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
#undef TYPE

using $ObjectStreamClass$ClassDataSlotArray = $Array<::java::io::ObjectStreamClass$ClassDataSlot>;
using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $Externalizable = ::java::io::Externalizable;
using $IOException = ::java::io::IOException;
using $InvalidClassException = ::java::io::InvalidClassException;
using $NotActiveException = ::java::io::NotActiveException;
using $NotSerializableException = ::java::io::NotSerializableException;
using $ObjectOutput = ::java::io::ObjectOutput;
using $ObjectOutputStream$1 = ::java::io::ObjectOutputStream$1;
using $ObjectOutputStream$BlockDataOutputStream = ::java::io::ObjectOutputStream$BlockDataOutputStream;
using $ObjectOutputStream$Caches = ::java::io::ObjectOutputStream$Caches;
using $ObjectOutputStream$DebugTraceInfoStack = ::java::io::ObjectOutputStream$DebugTraceInfoStack;
using $ObjectOutputStream$HandleTable = ::java::io::ObjectOutputStream$HandleTable;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $ObjectOutputStream$PutFieldImpl = ::java::io::ObjectOutputStream$PutFieldImpl;
using $ObjectOutputStream$ReplaceTable = ::java::io::ObjectOutputStream$ReplaceTable;
using $ObjectStreamClass = ::java::io::ObjectStreamClass;
using $ObjectStreamClass$WeakClassKey = ::java::io::ObjectStreamClass$WeakClassKey;
using $ObjectStreamConstants = ::java::io::ObjectStreamConstants;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $OutputStream = ::java::io::OutputStream;
using $SerialCallbackContext = ::java::io::SerialCallbackContext;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Short = ::java::lang::Short;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;
using $GetBooleanAction = ::sun::security::action::GetBooleanAction;

namespace java {
	namespace io {

$FieldInfo _ObjectOutputStream_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ObjectOutputStream, $assertionsDisabled)},
	{"bout", "Ljava/io/ObjectOutputStream$BlockDataOutputStream;", nullptr, $PRIVATE | $FINAL, $field(ObjectOutputStream, bout)},
	{"handles", "Ljava/io/ObjectOutputStream$HandleTable;", nullptr, $PRIVATE | $FINAL, $field(ObjectOutputStream, handles)},
	{"subs", "Ljava/io/ObjectOutputStream$ReplaceTable;", nullptr, $PRIVATE | $FINAL, $field(ObjectOutputStream, subs)},
	{"protocol", "I", nullptr, $PRIVATE, $field(ObjectOutputStream, protocol)},
	{"depth", "I", nullptr, $PRIVATE, $field(ObjectOutputStream, depth)},
	{"primVals", "[B", nullptr, $PRIVATE, $field(ObjectOutputStream, primVals)},
	{"enableOverride", "Z", nullptr, $PRIVATE | $FINAL, $field(ObjectOutputStream, enableOverride)},
	{"enableReplace", "Z", nullptr, $PRIVATE, $field(ObjectOutputStream, enableReplace)},
	{"curContext", "Ljava/io/SerialCallbackContext;", nullptr, $PRIVATE, $field(ObjectOutputStream, curContext)},
	{"curPut", "Ljava/io/ObjectOutputStream$PutFieldImpl;", nullptr, $PRIVATE, $field(ObjectOutputStream, curPut)},
	{"debugInfoStack", "Ljava/io/ObjectOutputStream$DebugTraceInfoStack;", nullptr, $PRIVATE | $FINAL, $field(ObjectOutputStream, debugInfoStack)},
	{"extendedDebugInfo", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ObjectOutputStream, extendedDebugInfo)},
	{}
};

$MethodInfo _ObjectOutputStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, $method(ObjectOutputStream, init$, void, $OutputStream*), "java.io.IOException"},
	{"<init>", "()V", nullptr, $PROTECTED, $method(ObjectOutputStream, init$, void), "java.io.IOException,java.lang.SecurityException"},
	{"annotateClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PROTECTED, $virtualMethod(ObjectOutputStream, annotateClass, void, $Class*), "java.io.IOException"},
	{"annotateProxyClass", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<*>;)V", $PROTECTED, $virtualMethod(ObjectOutputStream, annotateProxyClass, void, $Class*), "java.io.IOException"},
	{"auditSubclass", "(Ljava/lang/Class;)Ljava/lang/Boolean;", "(Ljava/lang/Class<*>;)Ljava/lang/Boolean;", $PRIVATE | $STATIC, $staticMethod(ObjectOutputStream, auditSubclass, $Boolean*, $Class*)},
	{"clear", "()V", nullptr, $PRIVATE, $method(ObjectOutputStream, clear, void)},
	{"close", "()V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, close, void), "java.io.IOException"},
	{"defaultWriteFields", "(Ljava/lang/Object;Ljava/io/ObjectStreamClass;)V", nullptr, $PRIVATE, $method(ObjectOutputStream, defaultWriteFields, void, Object$*, $ObjectStreamClass*), "java.io.IOException"},
	{"defaultWriteObject", "()V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, defaultWriteObject, void), "java.io.IOException"},
	{"drain", "()V", nullptr, $PROTECTED, $virtualMethod(ObjectOutputStream, drain, void), "java.io.IOException"},
	{"enableReplaceObject", "(Z)Z", nullptr, $PROTECTED, $virtualMethod(ObjectOutputStream, enableReplaceObject, bool, bool), "java.lang.SecurityException"},
	{"flush", "()V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, flush, void), "java.io.IOException"},
	{"getProtocolVersion", "()I", nullptr, 0, $virtualMethod(ObjectOutputStream, getProtocolVersion, int32_t)},
	{"isCustomSubclass", "()Z", nullptr, $PRIVATE, $method(ObjectOutputStream, isCustomSubclass, bool)},
	{"putFields", "()Ljava/io/ObjectOutputStream$PutField;", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, putFields, $ObjectOutputStream$PutField*), "java.io.IOException"},
	{"replaceObject", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PROTECTED, $virtualMethod(ObjectOutputStream, replaceObject, $Object*, Object$*), "java.io.IOException"},
	{"reset", "()V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, reset, void), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"useProtocolVersion", "(I)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, useProtocolVersion, void, int32_t), "java.io.IOException"},
	{"verifySubclass", "()V", nullptr, $PRIVATE, $method(ObjectOutputStream, verifySubclass, void)},
	{"write", "(I)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, write, void, int32_t), "java.io.IOException"},
	{"write", "([B)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, write, void, $bytes*), "java.io.IOException"},
	{"write", "([BII)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, write, void, $bytes*, int32_t, int32_t), "java.io.IOException"},
	{"writeArray", "(Ljava/lang/Object;Ljava/io/ObjectStreamClass;Z)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeArray, void, Object$*, $ObjectStreamClass*, bool), "java.io.IOException"},
	{"writeBoolean", "(Z)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeBoolean, void, bool), "java.io.IOException"},
	{"writeByte", "(I)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeByte, void, int32_t), "java.io.IOException"},
	{"writeBytes", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeBytes, void, $String*), "java.io.IOException"},
	{"writeChar", "(I)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeChar, void, int32_t), "java.io.IOException"},
	{"writeChars", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeChars, void, $String*), "java.io.IOException"},
	{"writeClass", "(Ljava/lang/Class;Z)V", "(Ljava/lang/Class<*>;Z)V", $PRIVATE, $method(ObjectOutputStream, writeClass, void, $Class*, bool), "java.io.IOException"},
	{"writeClassDesc", "(Ljava/io/ObjectStreamClass;Z)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeClassDesc, void, $ObjectStreamClass*, bool), "java.io.IOException"},
	{"writeClassDescriptor", "(Ljava/io/ObjectStreamClass;)V", nullptr, $PROTECTED, $virtualMethod(ObjectOutputStream, writeClassDescriptor, void, $ObjectStreamClass*), "java.io.IOException"},
	{"writeDouble", "(D)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeDouble, void, double), "java.io.IOException"},
	{"writeEnum", "(Ljava/lang/Enum;Ljava/io/ObjectStreamClass;Z)V", "(Ljava/lang/Enum<*>;Ljava/io/ObjectStreamClass;Z)V", $PRIVATE, $method(ObjectOutputStream, writeEnum, void, $Enum*, $ObjectStreamClass*, bool), "java.io.IOException"},
	{"writeExternalData", "(Ljava/io/Externalizable;)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeExternalData, void, $Externalizable*), "java.io.IOException"},
	{"writeFatalException", "(Ljava/io/IOException;)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeFatalException, void, $IOException*), "java.io.IOException"},
	{"writeFields", "()V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeFields, void), "java.io.IOException"},
	{"writeFloat", "(F)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeFloat, void, float), "java.io.IOException"},
	{"writeHandle", "(I)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeHandle, void, int32_t), "java.io.IOException"},
	{"writeInt", "(I)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeInt, void, int32_t), "java.io.IOException"},
	{"writeLong", "(J)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeLong, void, int64_t), "java.io.IOException"},
	{"writeNonProxyDesc", "(Ljava/io/ObjectStreamClass;Z)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeNonProxyDesc, void, $ObjectStreamClass*, bool), "java.io.IOException"},
	{"writeNull", "()V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeNull, void), "java.io.IOException"},
	{"writeObject", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $FINAL, $virtualMethod(ObjectOutputStream, writeObject, void, Object$*), "java.io.IOException"},
	{"writeObject0", "(Ljava/lang/Object;Z)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeObject0, void, Object$*, bool), "java.io.IOException"},
	{"writeObjectOverride", "(Ljava/lang/Object;)V", nullptr, $PROTECTED, $virtualMethod(ObjectOutputStream, writeObjectOverride, void, Object$*), "java.io.IOException"},
	{"writeOrdinaryObject", "(Ljava/lang/Object;Ljava/io/ObjectStreamClass;Z)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeOrdinaryObject, void, Object$*, $ObjectStreamClass*, bool), "java.io.IOException"},
	{"writeProxyDesc", "(Ljava/io/ObjectStreamClass;Z)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeProxyDesc, void, $ObjectStreamClass*, bool), "java.io.IOException"},
	{"writeRecordData", "(Ljava/lang/Object;Ljava/io/ObjectStreamClass;)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeRecordData, void, Object$*, $ObjectStreamClass*), "java.io.IOException"},
	{"writeSerialData", "(Ljava/lang/Object;Ljava/io/ObjectStreamClass;)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeSerialData, void, Object$*, $ObjectStreamClass*), "java.io.IOException"},
	{"writeShort", "(I)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeShort, void, int32_t), "java.io.IOException"},
	{"writeStreamHeader", "()V", nullptr, $PROTECTED, $virtualMethod(ObjectOutputStream, writeStreamHeader, void), "java.io.IOException"},
	{"writeString", "(Ljava/lang/String;Z)V", nullptr, $PRIVATE, $method(ObjectOutputStream, writeString, void, $String*, bool), "java.io.IOException"},
	{"writeTypeString", "(Ljava/lang/String;)V", nullptr, 0, $virtualMethod(ObjectOutputStream, writeTypeString, void, $String*), "java.io.IOException"},
	{"writeUTF", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeUTF, void, $String*), "java.io.IOException"},
	{"writeUnshared", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $virtualMethod(ObjectOutputStream, writeUnshared, void, Object$*), "java.io.IOException"},
	{}
};

$InnerClassInfo _ObjectOutputStream_InnerClassesInfo_[] = {
	{"java.io.ObjectOutputStream$DebugTraceInfoStack", "java.io.ObjectOutputStream", "DebugTraceInfoStack", $PRIVATE | $STATIC},
	{"java.io.ObjectOutputStream$ReplaceTable", "java.io.ObjectOutputStream", "ReplaceTable", $PRIVATE | $STATIC},
	{"java.io.ObjectOutputStream$HandleTable", "java.io.ObjectOutputStream", "HandleTable", $PRIVATE | $STATIC},
	{"java.io.ObjectOutputStream$BlockDataOutputStream", "java.io.ObjectOutputStream", "BlockDataOutputStream", $PRIVATE | $STATIC},
	{"java.io.ObjectOutputStream$PutFieldImpl", "java.io.ObjectOutputStream", "PutFieldImpl", $PRIVATE},
	{"java.io.ObjectOutputStream$PutField", "java.io.ObjectOutputStream", "PutField", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.io.ObjectOutputStream$Caches", "java.io.ObjectOutputStream", "Caches", $PRIVATE | $STATIC},
	{"java.io.ObjectOutputStream$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _ObjectOutputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.io.ObjectOutputStream",
	"java.io.OutputStream",
	"java.io.ObjectOutput,java.io.ObjectStreamConstants",
	_ObjectOutputStream_FieldInfo_,
	_ObjectOutputStream_MethodInfo_,
	nullptr,
	nullptr,
	_ObjectOutputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.io.ObjectOutputStream$DebugTraceInfoStack,java.io.ObjectOutputStream$ReplaceTable,java.io.ObjectOutputStream$HandleTable,java.io.ObjectOutputStream$BlockDataOutputStream,java.io.ObjectOutputStream$PutFieldImpl,java.io.ObjectOutputStream$PutField,java.io.ObjectOutputStream$Caches,java.io.ObjectOutputStream$1"
};

$Object* allocate$ObjectOutputStream($Class* clazz) {
	return $of($alloc(ObjectOutputStream));
}

int32_t ObjectOutputStream::hashCode() {
	 return this->$OutputStream::hashCode();
}

bool ObjectOutputStream::equals(Object$* obj) {
	 return this->$OutputStream::equals(obj);
}

$Object* ObjectOutputStream::clone() {
	 return this->$OutputStream::clone();
}

$String* ObjectOutputStream::toString() {
	 return this->$OutputStream::toString();
}

void ObjectOutputStream::finalize() {
	this->$OutputStream::finalize();
}

bool ObjectOutputStream::$assertionsDisabled = false;
bool ObjectOutputStream::extendedDebugInfo = false;

void ObjectOutputStream::init$($OutputStream* out) {
	$OutputStream::init$();
	this->protocol = $ObjectStreamConstants::PROTOCOL_VERSION_2;
	verifySubclass();
	$set(this, bout, $new($ObjectOutputStream$BlockDataOutputStream, out));
	$set(this, handles, $new($ObjectOutputStream$HandleTable, 10, (float)3.0));
	$set(this, subs, $new($ObjectOutputStream$ReplaceTable, 10, (float)3.0));
	this->enableOverride = false;
	writeStreamHeader();
	$nc(this->bout)->setBlockDataMode(true);
	if (ObjectOutputStream::extendedDebugInfo) {
		$set(this, debugInfoStack, $new($ObjectOutputStream$DebugTraceInfoStack));
	} else {
		$set(this, debugInfoStack, nullptr);
	}
}

void ObjectOutputStream::init$() {
	$OutputStream::init$();
	this->protocol = $ObjectStreamConstants::PROTOCOL_VERSION_2;
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$init($ObjectStreamConstants);
		sm->checkPermission($ObjectStreamConstants::SUBCLASS_IMPLEMENTATION_PERMISSION);
	}
	$set(this, bout, nullptr);
	$set(this, handles, nullptr);
	$set(this, subs, nullptr);
	this->enableOverride = true;
	$set(this, debugInfoStack, nullptr);
}

void ObjectOutputStream::useProtocolVersion(int32_t version) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->handles)->size() != 0) {
		$throwNew($IllegalStateException, "stream non-empty"_s);
	}
	switch (version) {
	case $ObjectStreamConstants::PROTOCOL_VERSION_1:
		{}
	case $ObjectStreamConstants::PROTOCOL_VERSION_2:
		{
			this->protocol = version;
			break;
		}
	default:
		{
			$throwNew($IllegalArgumentException, $$str({"unknown version: "_s, $$str(version)}));
		}
	}
}

void ObjectOutputStream::writeObject(Object$* obj) {
	if (this->enableOverride) {
		writeObjectOverride(obj);
		return;
	}
	try {
		writeObject0(obj, false);
	} catch ($IOException& ex) {
		if (this->depth == 0) {
			writeFatalException(ex);
		}
		$throw(ex);
	}
}

void ObjectOutputStream::writeObjectOverride(Object$* obj) {
}

void ObjectOutputStream::writeUnshared(Object$* obj) {
	try {
		writeObject0(obj, true);
	} catch ($IOException& ex) {
		if (this->depth == 0) {
			writeFatalException(ex);
		}
		$throw(ex);
	}
}

void ObjectOutputStream::defaultWriteObject() {
	$useLocalCurrentObjectStackCache();
	$var($SerialCallbackContext, ctx, this->curContext);
	if (ctx == nullptr) {
		$throwNew($NotActiveException, "not in call to writeObject"_s);
	}
	$var($Object, curObj, $nc(ctx)->getObj());
	$var($ObjectStreamClass, curDesc, ctx->getDesc());
	$nc(this->bout)->setBlockDataMode(false);
	defaultWriteFields(curObj, curDesc);
	$nc(this->bout)->setBlockDataMode(true);
}

$ObjectOutputStream$PutField* ObjectOutputStream::putFields() {
	$useLocalCurrentObjectStackCache();
	if (this->curPut == nullptr) {
		$var($SerialCallbackContext, ctx, this->curContext);
		if (ctx == nullptr) {
			$throwNew($NotActiveException, "not in call to writeObject"_s);
		}
		$nc(ctx)->checkAndSetUsed();
		$var($ObjectStreamClass, curDesc, ctx->getDesc());
		$set(this, curPut, $new($ObjectOutputStream$PutFieldImpl, this, curDesc));
	}
	return this->curPut;
}

void ObjectOutputStream::writeFields() {
	if (this->curPut == nullptr) {
		$throwNew($NotActiveException, "no current PutField object"_s);
	}
	$nc(this->bout)->setBlockDataMode(false);
	$nc(this->curPut)->writeFields();
	$nc(this->bout)->setBlockDataMode(true);
}

void ObjectOutputStream::reset() {
	if (this->depth != 0) {
		$throwNew($IOException, "stream active"_s);
	}
	$nc(this->bout)->setBlockDataMode(false);
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_RESET);
	clear();
	$nc(this->bout)->setBlockDataMode(true);
}

void ObjectOutputStream::annotateClass($Class* cl) {
}

void ObjectOutputStream::annotateProxyClass($Class* cl) {
}

$Object* ObjectOutputStream::replaceObject(Object$* obj) {
	return $of(obj);
}

bool ObjectOutputStream::enableReplaceObject(bool enable) {
	if (enable == this->enableReplace) {
		return enable;
	}
	if (enable) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			$init($ObjectStreamConstants);
			sm->checkPermission($ObjectStreamConstants::SUBSTITUTION_PERMISSION);
		}
	}
	this->enableReplace = enable;
	return !this->enableReplace;
}

void ObjectOutputStream::writeStreamHeader() {
	$nc(this->bout)->writeShort($ObjectStreamConstants::STREAM_MAGIC);
	$nc(this->bout)->writeShort($ObjectStreamConstants::STREAM_VERSION);
}

void ObjectOutputStream::writeClassDescriptor($ObjectStreamClass* desc) {
	$nc(desc)->writeNonProxy(this);
}

void ObjectOutputStream::write(int32_t val) {
	$nc(this->bout)->write(val);
}

void ObjectOutputStream::write($bytes* buf) {
	$nc(this->bout)->write(buf, 0, $nc(buf)->length, false);
}

void ObjectOutputStream::write($bytes* buf, int32_t off, int32_t len) {
	if (buf == nullptr) {
		$throwNew($NullPointerException);
	}
	int32_t endoff = off + len;
	if (off < 0 || len < 0 || endoff > $nc(buf)->length || endoff < 0) {
		$throwNew($IndexOutOfBoundsException);
	}
	$nc(this->bout)->write(buf, off, len, false);
}

void ObjectOutputStream::flush() {
	$nc(this->bout)->flush();
}

void ObjectOutputStream::drain() {
	$nc(this->bout)->drain();
}

void ObjectOutputStream::close() {
	flush();
	clear();
	$nc(this->bout)->close();
}

void ObjectOutputStream::writeBoolean(bool val) {
	$nc(this->bout)->writeBoolean(val);
}

void ObjectOutputStream::writeByte(int32_t val) {
	$nc(this->bout)->writeByte(val);
}

void ObjectOutputStream::writeShort(int32_t val) {
	$nc(this->bout)->writeShort(val);
}

void ObjectOutputStream::writeChar(int32_t val) {
	$nc(this->bout)->writeChar(val);
}

void ObjectOutputStream::writeInt(int32_t val) {
	$nc(this->bout)->writeInt(val);
}

void ObjectOutputStream::writeLong(int64_t val) {
	$nc(this->bout)->writeLong(val);
}

void ObjectOutputStream::writeFloat(float val) {
	$nc(this->bout)->writeFloat(val);
}

void ObjectOutputStream::writeDouble(double val) {
	$nc(this->bout)->writeDouble(val);
}

void ObjectOutputStream::writeBytes($String* str) {
	$nc(this->bout)->writeBytes(str);
}

void ObjectOutputStream::writeChars($String* str) {
	$nc(this->bout)->writeChars(str);
}

void ObjectOutputStream::writeUTF($String* str) {
	$nc(this->bout)->writeUTF(str);
}

int32_t ObjectOutputStream::getProtocolVersion() {
	return this->protocol;
}

void ObjectOutputStream::writeTypeString($String* str) {
	int32_t handle = 0;
	if (str == nullptr) {
		writeNull();
	} else if ((handle = $nc(this->handles)->lookup(str)) != -1) {
		writeHandle(handle);
	} else {
		writeString(str, false);
	}
}

void ObjectOutputStream::verifySubclass() {
	$useLocalCurrentObjectStackCache();
	$Class* cl = $of(this)->getClass();
	if (cl == ObjectOutputStream::class$) {
		return;
	}
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		return;
	}
	$init($ObjectOutputStream$Caches);
	$ObjectStreamClass::processQueue($ObjectOutputStream$Caches::subclassAuditsQueue, $ObjectOutputStream$Caches::subclassAudits);
	$var($ObjectStreamClass$WeakClassKey, key, $new($ObjectStreamClass$WeakClassKey, cl, $ObjectOutputStream$Caches::subclassAuditsQueue));
	$var($Boolean, result, $cast($Boolean, $nc($ObjectOutputStream$Caches::subclassAudits)->get(key)));
	if (result == nullptr) {
		$assign(result, auditSubclass(cl));
		$nc($ObjectOutputStream$Caches::subclassAudits)->putIfAbsent(key, result);
	}
	if (!$nc(result)->booleanValue()) {
		$init($ObjectStreamConstants);
		$nc(sm)->checkPermission($ObjectStreamConstants::SUBCLASS_IMPLEMENTATION_PERMISSION);
	}
}

$Boolean* ObjectOutputStream::auditSubclass($Class* subcl) {
	$init(ObjectOutputStream);
	$beforeCallerSensitive();
	return $cast($Boolean, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($ObjectOutputStream$1, subcl))));
}

void ObjectOutputStream::clear() {
	$nc(this->subs)->clear();
	$nc(this->handles)->clear();
}

void ObjectOutputStream::writeObject0(Object$* obj$renamed, bool unshared) {
	$useLocalCurrentObjectStackCache();
	$var($Object, obj, obj$renamed);
	bool oldMode = $nc(this->bout)->setBlockDataMode(false);
	++this->depth;
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			int32_t h = 0;
			if (($assign(obj, $nc(this->subs)->lookup(obj))) == nullptr) {
				writeNull();
				return$1 = true;
				goto $finally;
			} else if (!unshared && (h = $nc(this->handles)->lookup(obj)) != -1) {
				writeHandle(h);
				return$1 = true;
				goto $finally;
			} else if ($instanceOf($Class, obj)) {
				writeClass($cast($Class, obj), unshared);
				return$1 = true;
				goto $finally;
			} else if ($instanceOf($ObjectStreamClass, obj)) {
				writeClassDesc($cast($ObjectStreamClass, obj), unshared);
				return$1 = true;
				goto $finally;
			}
			$var($Object, orig, obj);
			$Class* cl = $nc($of(obj))->getClass();
			$var($ObjectStreamClass, desc, nullptr);
			for (;;) {
				$Class* repCl = nullptr;
				$assign(desc, $ObjectStreamClass::lookup(cl, true));
				bool var$3 = !$nc(desc)->hasWriteReplaceMethod();
				bool var$2 = var$3 || ($assign(obj, $nc(desc)->invokeWriteReplace(obj))) == nullptr;
				if (var$2 || (repCl = $of(obj)->getClass()) == cl) {
					break;
				}
				cl = repCl;
			}
			if (this->enableReplace) {
				$var($Object, rep, replaceObject(obj));
				if (!$equals(rep, obj) && rep != nullptr) {
					cl = $of(rep)->getClass();
					$assign(desc, $ObjectStreamClass::lookup(cl, true));
				}
				$assign(obj, rep);
			}
			if (!$equals(obj, orig)) {
				$nc(this->subs)->assign(orig, obj);
				if (obj == nullptr) {
					writeNull();
					return$1 = true;
					goto $finally;
				} else if (!unshared && (h = $nc(this->handles)->lookup(obj)) != -1) {
					writeHandle(h);
					return$1 = true;
					goto $finally;
				} else if ($instanceOf($Class, obj)) {
					writeClass($cast($Class, obj), unshared);
					return$1 = true;
					goto $finally;
				} else if ($instanceOf($ObjectStreamClass, obj)) {
					writeClassDesc($cast($ObjectStreamClass, obj), unshared);
					return$1 = true;
					goto $finally;
				}
			}
			if ($instanceOf($String, obj)) {
				writeString($cast($String, obj), unshared);
			} else if ($nc(cl)->isArray()) {
				writeArray(obj, desc, unshared);
			} else if ($instanceOf($Enum, obj)) {
				writeEnum($cast($Enum, obj), desc, unshared);
			} else if ($instanceOf($Serializable, obj)) {
				writeOrdinaryObject(obj, desc, unshared);
			} else if (ObjectOutputStream::extendedDebugInfo) {
				$var($String, var$4, $$str({$(cl->getName()), "\n"_s}));
				$throwNew($NotSerializableException, $$concat(var$4, $($nc(this->debugInfoStack)->toString())));
			} else {
				$throwNew($NotSerializableException, $(cl->getName()));
			}
		} catch ($Throwable& var$5) {
			$assign(var$0, var$5);
		} $finally: {
			--this->depth;
			$nc(this->bout)->setBlockDataMode(oldMode);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

void ObjectOutputStream::writeNull() {
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_NULL);
}

void ObjectOutputStream::writeHandle(int32_t handle) {
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_REFERENCE);
	$nc(this->bout)->writeInt($ObjectStreamConstants::baseWireHandle + handle);
}

void ObjectOutputStream::writeClass($Class* cl, bool unshared) {
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_CLASS);
	writeClassDesc($($ObjectStreamClass::lookup(cl, true)), false);
	$nc(this->handles)->assign(unshared ? ($Object*)nullptr : $of(cl));
}

void ObjectOutputStream::writeClassDesc($ObjectStreamClass* desc, bool unshared) {
	int32_t handle = 0;
	if (desc == nullptr) {
		writeNull();
	} else if (!unshared && (handle = $nc(this->handles)->lookup(desc)) != -1) {
		writeHandle(handle);
	} else if ($nc(desc)->isProxy()) {
		writeProxyDesc(desc, unshared);
	} else {
		writeNonProxyDesc(desc, unshared);
	}
}

bool ObjectOutputStream::isCustomSubclass() {
	$beforeCallerSensitive();
	return $of(this)->getClass()->getClassLoader() != ObjectOutputStream::class$->getClassLoader();
}

void ObjectOutputStream::writeProxyDesc($ObjectStreamClass* desc, bool unshared) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_PROXYCLASSDESC);
	$nc(this->handles)->assign(unshared ? ($Object*)nullptr : $of(desc));
	$Class* cl = $nc(desc)->forClass();
	$var($ClassArray, ifaces, $nc(cl)->getInterfaces());
	$nc(this->bout)->writeInt(ifaces->length);
	for (int32_t i = 0; i < ifaces->length; ++i) {
		$nc(this->bout)->writeUTF($($nc(ifaces->get(i))->getName()));
	}
	$nc(this->bout)->setBlockDataMode(true);
	if (cl != nullptr && isCustomSubclass()) {
		$ReflectUtil::checkPackageAccess(cl);
	}
	annotateProxyClass(cl);
	$nc(this->bout)->setBlockDataMode(false);
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_ENDBLOCKDATA);
	writeClassDesc($(desc->getSuperDesc()), false);
}

void ObjectOutputStream::writeNonProxyDesc($ObjectStreamClass* desc, bool unshared) {
	$beforeCallerSensitive();
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_CLASSDESC);
	$nc(this->handles)->assign(unshared ? ($Object*)nullptr : $of(desc));
	if (this->protocol == $ObjectStreamConstants::PROTOCOL_VERSION_1) {
		$nc(desc)->writeNonProxy(this);
	} else {
		writeClassDescriptor(desc);
	}
	$Class* cl = $nc(desc)->forClass();
	$nc(this->bout)->setBlockDataMode(true);
	if (cl != nullptr && isCustomSubclass()) {
		$ReflectUtil::checkPackageAccess(cl);
	}
	annotateClass(cl);
	$nc(this->bout)->setBlockDataMode(false);
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_ENDBLOCKDATA);
	writeClassDesc($(desc->getSuperDesc()), false);
}

void ObjectOutputStream::writeString($String* str, bool unshared) {
	$nc(this->handles)->assign(unshared ? ($Object*)nullptr : $of(str));
	int64_t utflen = $nc(this->bout)->getUTFLength(str);
	if (utflen <= 0x0000FFFF) {
		$nc(this->bout)->writeByte($ObjectStreamConstants::TC_STRING);
		$nc(this->bout)->writeUTF(str, utflen);
	} else {
		$nc(this->bout)->writeByte($ObjectStreamConstants::TC_LONGSTRING);
		$nc(this->bout)->writeLongUTF(str, utflen);
	}
}

void ObjectOutputStream::writeArray(Object$* array, $ObjectStreamClass* desc, bool unshared) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_ARRAY);
	writeClassDesc(desc, false);
	$nc(this->handles)->assign(unshared ? ($Object*)nullptr : $of(array));
	$Class* ccl = $nc($nc(desc)->forClass())->getComponentType();
	if ($nc(ccl)->isPrimitive()) {
		$init($Integer);
		if (ccl == $Integer::TYPE) {
			$var($ints, ia, $cast($ints, array));
			$nc(this->bout)->writeInt($nc(ia)->length);
			$nc(this->bout)->writeInts(ia, 0, $nc(ia)->length);
		} else {
			$init($Byte);
			if (ccl == $Byte::TYPE) {
				$var($bytes, ba, $cast($bytes, array));
				$nc(this->bout)->writeInt($nc(ba)->length);
				$nc(this->bout)->write(ba, 0, $nc(ba)->length, true);
			} else {
				$init($Long);
				if (ccl == $Long::TYPE) {
					$var($longs, ja, $cast($longs, array));
					$nc(this->bout)->writeInt($nc(ja)->length);
					$nc(this->bout)->writeLongs(ja, 0, $nc(ja)->length);
				} else {
					$init($Float);
					if (ccl == $Float::TYPE) {
						$var($floats, fa, $cast($floats, array));
						$nc(this->bout)->writeInt($nc(fa)->length);
						$nc(this->bout)->writeFloats(fa, 0, $nc(fa)->length);
					} else {
						$init($Double);
						if (ccl == $Double::TYPE) {
							$var($doubles, da, $cast($doubles, array));
							$nc(this->bout)->writeInt($nc(da)->length);
							$nc(this->bout)->writeDoubles(da, 0, $nc(da)->length);
						} else {
							$init($Short);
							if (ccl == $Short::TYPE) {
								$var($shorts, sa, $cast($shorts, array));
								$nc(this->bout)->writeInt($nc(sa)->length);
								$nc(this->bout)->writeShorts(sa, 0, $nc(sa)->length);
							} else {
								$init($Character);
								if (ccl == $Character::TYPE) {
									$var($chars, ca, $cast($chars, array));
									$nc(this->bout)->writeInt($nc(ca)->length);
									$nc(this->bout)->writeChars(ca, 0, $nc(ca)->length);
								} else {
									$init($Boolean);
									if (ccl == $Boolean::TYPE) {
										$var($booleans, za, $cast($booleans, array));
										$nc(this->bout)->writeInt($nc(za)->length);
										$nc(this->bout)->writeBooleans(za, 0, $nc(za)->length);
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
		$var($ObjectArray, objs, $cast($ObjectArray, array));
		int32_t len = $nc(objs)->length;
		$nc(this->bout)->writeInt(len);
		if (ObjectOutputStream::extendedDebugInfo) {
			$nc(this->debugInfoStack)->push($$str({"array (class \""_s, $($nc($of(array))->getClass()->getName()), "\", size: "_s, $$str(len), ")"_s}));
		}
		{
			$var($Throwable, var$0, nullptr);
			try {
				for (int32_t i = 0; i < len; ++i) {
					if (ObjectOutputStream::extendedDebugInfo) {
						$nc(this->debugInfoStack)->push($$str({"element of array (index: "_s, $$str(i), ")"_s}));
					}
					{
						$var($Throwable, var$1, nullptr);
						try {
							writeObject0(objs->get(i), false);
						} catch ($Throwable& var$2) {
							$assign(var$1, var$2);
						} /*finally*/ {
							if (ObjectOutputStream::extendedDebugInfo) {
								$nc(this->debugInfoStack)->pop();
							}
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				if (ObjectOutputStream::extendedDebugInfo) {
					$nc(this->debugInfoStack)->pop();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void ObjectOutputStream::writeEnum($Enum* en, $ObjectStreamClass* desc, bool unshared) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$nc(this->bout)->writeByte($ObjectStreamConstants::TC_ENUM);
	$var($ObjectStreamClass, sdesc, $nc(desc)->getSuperDesc());
	$load($Enum);
	writeClassDesc(($nc(sdesc)->forClass() == $Enum::class$) ? desc : sdesc, false);
	$nc(this->handles)->assign(unshared ? ($Object*)nullptr : $of(en));
	writeString($($nc(en)->name()), false);
}

void ObjectOutputStream::writeOrdinaryObject(Object$* obj, $ObjectStreamClass* desc, bool unshared) {
	$useLocalCurrentObjectStackCache();
	if (ObjectOutputStream::extendedDebugInfo) {
		$var($String, var$1, $$str({(this->depth == 1 ? "root "_s : ""_s), "object (class \""_s, $($nc($of(obj))->getClass()->getName()), "\", "_s}));
		$var($String, var$0, $$concat(var$1, $($of(obj)->toString())));
		$nc(this->debugInfoStack)->push($$concat(var$0, ")"_s));
	}
	{
		$var($Throwable, var$2, nullptr);
		try {
			$nc(desc)->checkSerialize();
			$nc(this->bout)->writeByte($ObjectStreamConstants::TC_OBJECT);
			writeClassDesc(desc, false);
			$nc(this->handles)->assign(unshared ? ($Object*)nullptr : $of(obj));
			if (desc->isRecord()) {
				writeRecordData(obj, desc);
			} else {
				bool var$4 = desc->isExternalizable();
				if (var$4 && !desc->isProxy()) {
					writeExternalData($cast($Externalizable, obj));
				} else {
					writeSerialData(obj, desc);
				}
			}
		} catch ($Throwable& var$5) {
			$assign(var$2, var$5);
		} /*finally*/ {
			if (ObjectOutputStream::extendedDebugInfo) {
				$nc(this->debugInfoStack)->pop();
			}
		}
		if (var$2 != nullptr) {
			$throw(var$2);
		}
	}
}

void ObjectOutputStream::writeExternalData($Externalizable* obj) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectOutputStream$PutFieldImpl, oldPut, this->curPut);
	$set(this, curPut, nullptr);
	if (ObjectOutputStream::extendedDebugInfo) {
		$nc(this->debugInfoStack)->push("writeExternal data"_s);
	}
	$var($SerialCallbackContext, oldContext, this->curContext);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$set(this, curContext, nullptr);
			if (this->protocol == $ObjectStreamConstants::PROTOCOL_VERSION_1) {
				$nc(obj)->writeExternal(this);
			} else {
				$nc(this->bout)->setBlockDataMode(true);
				$nc(obj)->writeExternal(this);
				$nc(this->bout)->setBlockDataMode(false);
				$nc(this->bout)->writeByte($ObjectStreamConstants::TC_ENDBLOCKDATA);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$set(this, curContext, oldContext);
			if (ObjectOutputStream::extendedDebugInfo) {
				$nc(this->debugInfoStack)->pop();
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
	$set(this, curPut, oldPut);
}

void ObjectOutputStream::writeRecordData(Object$* obj, $ObjectStreamClass* desc) {
	$useLocalCurrentObjectStackCache();
	if (!ObjectOutputStream::$assertionsDisabled && !$nc($of(obj))->getClass()->isRecord()) {
		$throwNew($AssertionError);
	}
	$var($ObjectStreamClass$ClassDataSlotArray, slots, $nc(desc)->getClassDataLayout());
	if ($nc(slots)->length != 1) {
		$throwNew($InvalidClassException, $$str({"expected a single record slot length, but found: "_s, $$str(slots->length)}));
	}
	defaultWriteFields(obj, desc);
}

void ObjectOutputStream::writeSerialData(Object$* obj, $ObjectStreamClass* desc) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectStreamClass$ClassDataSlotArray, slots, $nc(desc)->getClassDataLayout());
	for (int32_t i = 0; i < $nc(slots)->length; ++i) {
		$var($ObjectStreamClass, slotDesc, $nc(slots->get(i))->desc);
		if ($nc(slotDesc)->hasWriteObjectMethod()) {
			$var($ObjectOutputStream$PutFieldImpl, oldPut, this->curPut);
			$set(this, curPut, nullptr);
			$var($SerialCallbackContext, oldContext, this->curContext);
			if (ObjectOutputStream::extendedDebugInfo) {
				$nc(this->debugInfoStack)->push($$str({"custom writeObject data (class \""_s, $(slotDesc->getName()), "\")"_s}));
			}
			{
				$var($Throwable, var$0, nullptr);
				try {
					$set(this, curContext, $new($SerialCallbackContext, obj, slotDesc));
					$nc(this->bout)->setBlockDataMode(true);
					slotDesc->invokeWriteObject(obj, this);
					$nc(this->bout)->setBlockDataMode(false);
					$nc(this->bout)->writeByte($ObjectStreamConstants::TC_ENDBLOCKDATA);
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					$nc(this->curContext)->setUsed();
					$set(this, curContext, oldContext);
					if (ObjectOutputStream::extendedDebugInfo) {
						$nc(this->debugInfoStack)->pop();
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
			$set(this, curPut, oldPut);
		} else {
			defaultWriteFields(obj, slotDesc);
		}
	}
}

void ObjectOutputStream::defaultWriteFields(Object$* obj, $ObjectStreamClass* desc) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Class* cl = $nc(desc)->forClass();
	if (cl != nullptr && obj != nullptr && !cl->isInstance(obj)) {
		$throwNew($ClassCastException);
	}
	desc->checkDefaultSerialize();
	int32_t primDataSize = desc->getPrimDataSize();
	if (primDataSize > 0) {
		if (this->primVals == nullptr || $nc(this->primVals)->length < primDataSize) {
			$set(this, primVals, $new($bytes, primDataSize));
		}
		desc->getPrimFieldValues(obj, this->primVals);
		$nc(this->bout)->write(this->primVals, 0, primDataSize, false);
	}
	int32_t numObjFields = desc->getNumObjFields();
	if (numObjFields > 0) {
		$var($ObjectStreamFieldArray, fields, desc->getFields(false));
		$var($ObjectArray, objVals, $new($ObjectArray, numObjFields));
		int32_t numPrimFields = $nc(fields)->length - objVals->length;
		desc->getObjFieldValues(obj, objVals);
		for (int32_t i = 0; i < objVals->length; ++i) {
			if (ObjectOutputStream::extendedDebugInfo) {
				$var($String, var$3, $$str({"field (class \""_s, $(desc->getName()), "\", name: \""_s}));
				$var($String, var$2, $$concat(var$3, $($nc(fields->get(numPrimFields + i))->getName())));
				$var($String, var$1, $$concat(var$2, "\", type: \""_s));
				$var($String, var$0, $$concat(var$1, $($nc(fields->get(numPrimFields + i))->getType())));
				$nc(this->debugInfoStack)->push($$concat(var$0, "\")"_s));
			}
			{
				$var($Throwable, var$4, nullptr);
				try {
					writeObject0(objVals->get(i), $nc(fields->get(numPrimFields + i))->isUnshared());
				} catch ($Throwable& var$5) {
					$assign(var$4, var$5);
				} /*finally*/ {
					if (ObjectOutputStream::extendedDebugInfo) {
						$nc(this->debugInfoStack)->pop();
					}
				}
				if (var$4 != nullptr) {
					$throw(var$4);
				}
			}
		}
	}
}

void ObjectOutputStream::writeFatalException($IOException* ex) {
	clear();
	bool oldMode = $nc(this->bout)->setBlockDataMode(false);
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(this->bout)->writeByte($ObjectStreamConstants::TC_EXCEPTION);
			writeObject0(ex, false);
			clear();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->bout)->setBlockDataMode(oldMode);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void clinit$ObjectOutputStream($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	ObjectOutputStream::$assertionsDisabled = !ObjectOutputStream::class$->desiredAssertionStatus();
	ObjectOutputStream::extendedDebugInfo = $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($GetBooleanAction, "sun.io.serialization.extendedDebugInfo"_s)))))))->booleanValue();
}

ObjectOutputStream::ObjectOutputStream() {
}

$Class* ObjectOutputStream::load$($String* name, bool initialize) {
	$loadClass(ObjectOutputStream, name, initialize, &_ObjectOutputStream_ClassInfo_, clinit$ObjectOutputStream, allocate$ObjectOutputStream);
	return class$;
}

$Class* ObjectOutputStream::class$ = nullptr;

	} // io
} // java
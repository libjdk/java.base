#include <jdk/internal/org/objectweb/asm/commons/SerialVersionUIDAdder.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/DataOutput.h>
#include <java/io/DataOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Math.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <jdk/internal/org/objectweb/asm/ClassVisitor.h>
#include <jdk/internal/org/objectweb/asm/FieldVisitor.h>
#include <jdk/internal/org/objectweb/asm/MethodVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/commons/SerialVersionUIDAdder$Item.h>
#include <jcpp.h>

#undef ACC_ABSTRACT
#undef ACC_ENUM
#undef ACC_FINAL
#undef ACC_INTERFACE
#undef ACC_NATIVE
#undef ACC_PRIVATE
#undef ACC_PROTECTED
#undef ACC_PUBLIC
#undef ACC_STATIC
#undef ACC_STRICT
#undef ACC_SYNCHRONIZED
#undef ACC_TRANSIENT
#undef ACC_VOLATILE
#undef ASM8
#undef CLINIT

using $SerialVersionUIDAdder$ItemArray = $Array<::jdk::internal::org::objectweb::asm$::commons::SerialVersionUIDAdder$Item>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $DataOutput = ::java::io::DataOutput;
using $DataOutputStream = ::java::io::DataOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $ClassVisitor = ::jdk::internal::org::objectweb::asm$::ClassVisitor;
using $FieldVisitor = ::jdk::internal::org::objectweb::asm$::FieldVisitor;
using $MethodVisitor = ::jdk::internal::org::objectweb::asm$::MethodVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $SerialVersionUIDAdder$Item = ::jdk::internal::org::objectweb::asm$::commons::SerialVersionUIDAdder$Item;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace commons {

$FieldInfo _SerialVersionUIDAdder_FieldInfo_[] = {
	{"CLINIT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SerialVersionUIDAdder, CLINIT)},
	{"computeSvuid", "Z", nullptr, $PRIVATE, $field(SerialVersionUIDAdder, computeSvuid)},
	{"hasSvuid", "Z", nullptr, $PRIVATE, $field(SerialVersionUIDAdder, hasSvuid)},
	{"access", "I", nullptr, $PRIVATE, $field(SerialVersionUIDAdder, access)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SerialVersionUIDAdder, name)},
	{"interfaces", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(SerialVersionUIDAdder, interfaces)},
	{"svuidFields", "Ljava/util/Collection;", "Ljava/util/Collection<Ljdk/internal/org/objectweb/asm/commons/SerialVersionUIDAdder$Item;>;", $PRIVATE, $field(SerialVersionUIDAdder, svuidFields)},
	{"hasStaticInitializer", "Z", nullptr, $PRIVATE, $field(SerialVersionUIDAdder, hasStaticInitializer)},
	{"svuidConstructors", "Ljava/util/Collection;", "Ljava/util/Collection<Ljdk/internal/org/objectweb/asm/commons/SerialVersionUIDAdder$Item;>;", $PRIVATE, $field(SerialVersionUIDAdder, svuidConstructors)},
	{"svuidMethods", "Ljava/util/Collection;", "Ljava/util/Collection<Ljdk/internal/org/objectweb/asm/commons/SerialVersionUIDAdder$Item;>;", $PRIVATE, $field(SerialVersionUIDAdder, svuidMethods)},
	{}
};

$MethodInfo _SerialVersionUIDAdder_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/org/objectweb/asm/ClassVisitor;)V", nullptr, $PUBLIC, $method(SerialVersionUIDAdder, init$, void, $ClassVisitor*)},
	{"<init>", "(ILjdk/internal/org/objectweb/asm/ClassVisitor;)V", nullptr, $PROTECTED, $method(SerialVersionUIDAdder, init$, void, int32_t, $ClassVisitor*)},
	{"addSVUID", "(J)V", nullptr, $PROTECTED, $virtualMethod(SerialVersionUIDAdder, addSVUID, void, int64_t)},
	{"computeSHAdigest", "([B)[B", nullptr, $PROTECTED, $virtualMethod(SerialVersionUIDAdder, computeSHAdigest, $bytes*, $bytes*)},
	{"computeSVUID", "()J", nullptr, $PROTECTED, $virtualMethod(SerialVersionUIDAdder, computeSVUID, int64_t), "java.io.IOException"},
	{"hasSVUID", "()Z", nullptr, $PUBLIC, $virtualMethod(SerialVersionUIDAdder, hasSVUID, bool)},
	{"visit", "(IILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SerialVersionUIDAdder, visit, void, int32_t, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"visitEnd", "()V", nullptr, $PUBLIC, $virtualMethod(SerialVersionUIDAdder, visitEnd, void)},
	{"visitField", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Ljdk/internal/org/objectweb/asm/FieldVisitor;", nullptr, $PUBLIC, $virtualMethod(SerialVersionUIDAdder, visitField, $FieldVisitor*, int32_t, $String*, $String*, $String*, Object$*)},
	{"visitInnerClass", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", nullptr, $PUBLIC, $virtualMethod(SerialVersionUIDAdder, visitInnerClass, void, $String*, $String*, $String*, int32_t)},
	{"visitMethod", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Ljdk/internal/org/objectweb/asm/MethodVisitor;", nullptr, $PUBLIC, $virtualMethod(SerialVersionUIDAdder, visitMethod, $MethodVisitor*, int32_t, $String*, $String*, $String*, $StringArray*)},
	{"writeItems", "(Ljava/util/Collection;Ljava/io/DataOutput;Z)V", "(Ljava/util/Collection<Ljdk/internal/org/objectweb/asm/commons/SerialVersionUIDAdder$Item;>;Ljava/io/DataOutput;Z)V", $PRIVATE | $STATIC, $staticMethod(SerialVersionUIDAdder, writeItems, void, $Collection*, $DataOutput*, bool), "java.io.IOException"},
	{}
};

$InnerClassInfo _SerialVersionUIDAdder_InnerClassesInfo_[] = {
	{"jdk.internal.org.objectweb.asm.commons.SerialVersionUIDAdder$Item", "jdk.internal.org.objectweb.asm.commons.SerialVersionUIDAdder", "Item", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _SerialVersionUIDAdder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.commons.SerialVersionUIDAdder",
	"jdk.internal.org.objectweb.asm.ClassVisitor",
	nullptr,
	_SerialVersionUIDAdder_FieldInfo_,
	_SerialVersionUIDAdder_MethodInfo_,
	nullptr,
	nullptr,
	_SerialVersionUIDAdder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.org.objectweb.asm.commons.SerialVersionUIDAdder$Item"
};

$Object* allocate$SerialVersionUIDAdder($Class* clazz) {
	return $of($alloc(SerialVersionUIDAdder));
}

$String* SerialVersionUIDAdder::CLINIT = nullptr;

void SerialVersionUIDAdder::init$($ClassVisitor* classVisitor) {
	SerialVersionUIDAdder::init$($Opcodes::ASM8, classVisitor);
	if ($of(this)->getClass() != SerialVersionUIDAdder::class$) {
		$throwNew($IllegalStateException);
	}
}

void SerialVersionUIDAdder::init$(int32_t api, $ClassVisitor* classVisitor) {
	$ClassVisitor::init$(api, classVisitor);
}

void SerialVersionUIDAdder::visit(int32_t version, int32_t access, $String* name, $String* signature, $String* superName, $StringArray* interfaces) {
	this->computeSvuid = ((int32_t)(access & (uint32_t)$Opcodes::ACC_ENUM)) == 0;
	if (this->computeSvuid) {
		$set(this, name, name);
		this->access = access;
		$set(this, interfaces, $cast($StringArray, $nc(interfaces)->clone()));
		$set(this, svuidFields, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList)))));
		$set(this, svuidConstructors, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList)))));
		$set(this, svuidMethods, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>($new($ArrayList)))));
	}
	$ClassVisitor::visit(version, access, name, signature, superName, interfaces);
}

$MethodVisitor* SerialVersionUIDAdder::visitMethod(int32_t access, $String* name, $String* descriptor, $String* signature, $StringArray* exceptions) {
	$useLocalCurrentObjectStackCache();
	if (this->computeSvuid) {
		if ($nc(SerialVersionUIDAdder::CLINIT)->equals(name)) {
			this->hasStaticInitializer = true;
		}
		int32_t mods = (int32_t)(access & (uint32_t)(((((((($Opcodes::ACC_PUBLIC | $Opcodes::ACC_PRIVATE) | $Opcodes::ACC_PROTECTED) | $Opcodes::ACC_STATIC) | $Opcodes::ACC_FINAL) | $Opcodes::ACC_SYNCHRONIZED) | $Opcodes::ACC_NATIVE) | $Opcodes::ACC_ABSTRACT) | $Opcodes::ACC_STRICT));
		if (((int32_t)(access & (uint32_t)$Opcodes::ACC_PRIVATE)) == 0) {
			if ("<init>"_s->equals(name)) {
				$nc(this->svuidConstructors)->add($$new($SerialVersionUIDAdder$Item, name, mods, descriptor));
			} else if (!$nc(SerialVersionUIDAdder::CLINIT)->equals(name)) {
				$nc(this->svuidMethods)->add($$new($SerialVersionUIDAdder$Item, name, mods, descriptor));
			}
		}
	}
	return $ClassVisitor::visitMethod(access, name, descriptor, signature, exceptions);
}

$FieldVisitor* SerialVersionUIDAdder::visitField(int32_t access, $String* name, $String* desc, $String* signature, Object$* value) {
	if (this->computeSvuid) {
		if ("serialVersionUID"_s->equals(name)) {
			this->computeSvuid = false;
			this->hasSvuid = true;
		}
		if (((int32_t)(access & (uint32_t)$Opcodes::ACC_PRIVATE)) == 0 || ((int32_t)(access & (uint32_t)($Opcodes::ACC_STATIC | $Opcodes::ACC_TRANSIENT))) == 0) {
			int32_t mods = (int32_t)(access & (uint32_t)(((((($Opcodes::ACC_PUBLIC | $Opcodes::ACC_PRIVATE) | $Opcodes::ACC_PROTECTED) | $Opcodes::ACC_STATIC) | $Opcodes::ACC_FINAL) | $Opcodes::ACC_VOLATILE) | $Opcodes::ACC_TRANSIENT));
			$nc(this->svuidFields)->add($$new($SerialVersionUIDAdder$Item, name, mods, desc));
		}
	}
	return $ClassVisitor::visitField(access, name, desc, signature, value);
}

void SerialVersionUIDAdder::visitInnerClass($String* innerClassName, $String* outerName, $String* innerName, int32_t innerClassAccess) {
	if ((this->name != nullptr) && $nc(this->name)->equals(innerClassName)) {
		this->access = innerClassAccess;
	}
	$ClassVisitor::visitInnerClass(innerClassName, outerName, innerName, innerClassAccess);
}

void SerialVersionUIDAdder::visitEnd() {
	if (this->computeSvuid && !this->hasSvuid) {
		try {
			addSVUID(computeSVUID());
		} catch ($IOException& e) {
			$throwNew($IllegalStateException, $$str({"Error while computing SVUID for "_s, this->name}), e);
		}
	}
	$ClassVisitor::visitEnd();
}

bool SerialVersionUIDAdder::hasSVUID() {
	return this->hasSvuid;
}

void SerialVersionUIDAdder::addSVUID(int64_t svuid) {
	$useLocalCurrentObjectStackCache();
	$var($FieldVisitor, fieldVisitor, $ClassVisitor::visitField($Opcodes::ACC_FINAL + $Opcodes::ACC_STATIC, "serialVersionUID"_s, "J"_s, nullptr, $($Long::valueOf(svuid))));
	if (fieldVisitor != nullptr) {
		fieldVisitor->visitEnd();
	}
}

int64_t SerialVersionUIDAdder::computeSVUID() {
	$useLocalCurrentObjectStackCache();
	int64_t svuid = 0;
	{
		$var($ByteArrayOutputStream, byteArrayOutputStream, $new($ByteArrayOutputStream));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($DataOutputStream, dataOutputStream, $new($DataOutputStream, byteArrayOutputStream));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								dataOutputStream->writeUTF($($nc(this->name)->replace(u'/', u'.')));
								int32_t mods = this->access;
								if (((int32_t)(mods & (uint32_t)$Opcodes::ACC_INTERFACE)) != 0) {
									mods = $nc(this->svuidMethods)->isEmpty() ? ((int32_t)(mods & (uint32_t)~$Opcodes::ACC_ABSTRACT)) : (mods | $Opcodes::ACC_ABSTRACT);
								}
								dataOutputStream->writeInt((int32_t)(mods & (uint32_t)((($Opcodes::ACC_PUBLIC | $Opcodes::ACC_FINAL) | $Opcodes::ACC_INTERFACE) | $Opcodes::ACC_ABSTRACT)));
								$Arrays::sort(this->interfaces);
								{
									$var($StringArray, arr$, this->interfaces);
									int32_t len$ = $nc(arr$)->length;
									int32_t i$ = 0;
									for (; i$ < len$; ++i$) {
										$var($String, interfaceName, arr$->get(i$));
										{
											dataOutputStream->writeUTF($($nc(interfaceName)->replace(u'/', u'.')));
										}
									}
								}
								writeItems(this->svuidFields, dataOutputStream, false);
								if (this->hasStaticInitializer) {
									dataOutputStream->writeUTF(SerialVersionUIDAdder::CLINIT);
									dataOutputStream->writeInt($Opcodes::ACC_STATIC);
									dataOutputStream->writeUTF("()V"_s);
								}
								writeItems(this->svuidConstructors, dataOutputStream, true);
								writeItems(this->svuidMethods, dataOutputStream, true);
								dataOutputStream->flush();
								$var($bytes, hashBytes, computeSHAdigest($(byteArrayOutputStream->toByteArray())));
								for (int32_t i = $Math::min($nc(hashBytes)->length, 8) - 1; i >= 0; --i) {
									svuid = (svuid << 8) | ((int32_t)($nc(hashBytes)->get(i) & (uint32_t)255));
								}
							} catch ($Throwable& t$) {
								try {
									dataOutputStream->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$2) {
							$assign(var$1, var$2);
						} /*finally*/ {
							dataOutputStream->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					try {
						byteArrayOutputStream->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				byteArrayOutputStream->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	return svuid;
}

$bytes* SerialVersionUIDAdder::computeSHAdigest($bytes* value) {
	try {
		return $nc($($MessageDigest::getInstance("SHA"_s)))->digest(value);
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($UnsupportedOperationException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void SerialVersionUIDAdder::writeItems($Collection* itemCollection, $DataOutput* dataOutputStream, bool dotted) {
	$init(SerialVersionUIDAdder);
	$useLocalCurrentObjectStackCache();
	$var($SerialVersionUIDAdder$ItemArray, items, $fcast($SerialVersionUIDAdder$ItemArray, $nc(itemCollection)->toArray($$new($SerialVersionUIDAdder$ItemArray, 0))));
	$Arrays::sort(items);
	{
		$var($SerialVersionUIDAdder$ItemArray, arr$, items);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($SerialVersionUIDAdder$Item, item, arr$->get(i$));
			{
				$nc(dataOutputStream)->writeUTF($nc(item)->name);
				dataOutputStream->writeInt($nc(item)->access);
				dataOutputStream->writeUTF(dotted ? $($nc($nc(item)->descriptor)->replace(u'/', u'.')) : item->descriptor);
			}
		}
	}
}

SerialVersionUIDAdder::SerialVersionUIDAdder() {
}

void clinit$SerialVersionUIDAdder($Class* class$) {
	$assignStatic(SerialVersionUIDAdder::CLINIT, "<clinit>"_s);
}

$Class* SerialVersionUIDAdder::load$($String* name, bool initialize) {
	$loadClass(SerialVersionUIDAdder, name, initialize, &_SerialVersionUIDAdder_ClassInfo_, clinit$SerialVersionUIDAdder, allocate$SerialVersionUIDAdder);
	return class$;
}

$Class* SerialVersionUIDAdder::class$ = nullptr;

					} // commons
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk
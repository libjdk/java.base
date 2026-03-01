#include <jdk/internal/org/objectweb/asm/tree/ModuleNode.h>

#include <java/lang/IllegalStateException.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <jdk/internal/org/objectweb/asm/ClassVisitor.h>
#include <jdk/internal/org/objectweb/asm/ModuleVisitor.h>
#include <jdk/internal/org/objectweb/asm/Opcodes.h>
#include <jdk/internal/org/objectweb/asm/tree/ModuleExportNode.h>
#include <jdk/internal/org/objectweb/asm/tree/ModuleOpenNode.h>
#include <jdk/internal/org/objectweb/asm/tree/ModuleProvideNode.h>
#include <jdk/internal/org/objectweb/asm/tree/ModuleRequireNode.h>
#include <jdk/internal/org/objectweb/asm/tree/Util.h>
#include <jcpp.h>

#undef ASM8

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $ClassVisitor = ::jdk::internal::org::objectweb::asm$::ClassVisitor;
using $ModuleVisitor = ::jdk::internal::org::objectweb::asm$::ModuleVisitor;
using $Opcodes = ::jdk::internal::org::objectweb::asm$::Opcodes;
using $ModuleExportNode = ::jdk::internal::org::objectweb::asm$::tree::ModuleExportNode;
using $ModuleOpenNode = ::jdk::internal::org::objectweb::asm$::tree::ModuleOpenNode;
using $ModuleProvideNode = ::jdk::internal::org::objectweb::asm$::tree::ModuleProvideNode;
using $ModuleRequireNode = ::jdk::internal::org::objectweb::asm$::tree::ModuleRequireNode;
using $Util = ::jdk::internal::org::objectweb::asm$::tree::Util;

namespace jdk {
	namespace internal {
		namespace org {
			namespace objectweb {
				namespace asm$ {
					namespace tree {

$FieldInfo _ModuleNode_FieldInfo_[] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ModuleNode, name)},
	{"access", "I", nullptr, $PUBLIC, $field(ModuleNode, access)},
	{"version", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ModuleNode, version)},
	{"mainClass", "Ljava/lang/String;", nullptr, $PUBLIC, $field(ModuleNode, mainClass)},
	{"packages", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $field(ModuleNode, packages)},
	{"requires", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/ModuleRequireNode;>;", $PUBLIC, $field(ModuleNode, requires)},
	{"exports", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/ModuleExportNode;>;", $PUBLIC, $field(ModuleNode, exports)},
	{"opens", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/ModuleOpenNode;>;", $PUBLIC, $field(ModuleNode, opens)},
	{"uses", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $field(ModuleNode, uses)},
	{"provides", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/ModuleProvideNode;>;", $PUBLIC, $field(ModuleNode, provides)},
	{}
};

$MethodInfo _ModuleNode_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PUBLIC, $method(ModuleNode, init$, void, $String*, int32_t, $String*)},
	{"<init>", "(ILjava/lang/String;ILjava/lang/String;Ljava/util/List;Ljava/util/List;Ljava/util/List;Ljava/util/List;Ljava/util/List;)V", "(ILjava/lang/String;ILjava/lang/String;Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/ModuleRequireNode;>;Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/ModuleExportNode;>;Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/ModuleOpenNode;>;Ljava/util/List<Ljava/lang/String;>;Ljava/util/List<Ljdk/internal/org/objectweb/asm/tree/ModuleProvideNode;>;)V", $PUBLIC, $method(ModuleNode, init$, void, int32_t, $String*, int32_t, $String*, $List*, $List*, $List*, $List*, $List*)},
	{"accept", "(Ljdk/internal/org/objectweb/asm/ClassVisitor;)V", nullptr, $PUBLIC, $virtualMethod(ModuleNode, accept, void, $ClassVisitor*)},
	{"visitEnd", "()V", nullptr, $PUBLIC, $virtualMethod(ModuleNode, visitEnd, void)},
	{"visitExport", "(Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ModuleNode, visitExport, void, $String*, int32_t, $StringArray*)},
	{"visitMainClass", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ModuleNode, visitMainClass, void, $String*)},
	{"visitOpen", "(Ljava/lang/String;I[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ModuleNode, visitOpen, void, $String*, int32_t, $StringArray*)},
	{"visitPackage", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ModuleNode, visitPackage, void, $String*)},
	{"visitProvide", "(Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PUBLIC | $TRANSIENT, $virtualMethod(ModuleNode, visitProvide, void, $String*, $StringArray*)},
	{"visitRequire", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ModuleNode, visitRequire, void, $String*, int32_t, $String*)},
	{"visitUse", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(ModuleNode, visitUse, void, $String*)},
	{}
};

$ClassInfo _ModuleNode_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.org.objectweb.asm.tree.ModuleNode",
	"jdk.internal.org.objectweb.asm.ModuleVisitor",
	nullptr,
	_ModuleNode_FieldInfo_,
	_ModuleNode_MethodInfo_
};

$Object* allocate$ModuleNode($Class* clazz) {
	return $of($alloc(ModuleNode));
}

void ModuleNode::init$($String* name, int32_t access, $String* version) {
	$ModuleVisitor::init$($Opcodes::ASM8);
	if ($of(this)->getClass() != ModuleNode::class$) {
		$throwNew($IllegalStateException);
	}
	$set(this, name, name);
	this->access = access;
	$set(this, version, version);
}

void ModuleNode::init$(int32_t api, $String* name, int32_t access, $String* version, $List* requires, $List* exports, $List* opens, $List* uses, $List* provides) {
	$ModuleVisitor::init$(api);
	$set(this, name, name);
	this->access = access;
	$set(this, version, version);
	$set(this, requires, requires);
	$set(this, exports, exports);
	$set(this, opens, opens);
	$set(this, uses, uses);
	$set(this, provides, provides);
}

void ModuleNode::visitMainClass($String* mainClass) {
	$set(this, mainClass, mainClass);
}

void ModuleNode::visitPackage($String* packaze) {
	if (this->packages == nullptr) {
		$set(this, packages, $new($ArrayList, 5));
	}
	$nc(this->packages)->add(packaze);
}

void ModuleNode::visitRequire($String* module, int32_t access, $String* version) {
	if (this->requires == nullptr) {
		$set(this, requires, $new($ArrayList, 5));
	}
	$nc(this->requires)->add($$new($ModuleRequireNode, module, access, version));
}

void ModuleNode::visitExport($String* packaze, int32_t access, $StringArray* modules) {
	$useLocalCurrentObjectStackCache();
	if (this->exports == nullptr) {
		$set(this, exports, $new($ArrayList, 5));
	}
	$nc(this->exports)->add($$new($ModuleExportNode, packaze, access, $($Util::asArrayList(modules))));
}

void ModuleNode::visitOpen($String* packaze, int32_t access, $StringArray* modules) {
	$useLocalCurrentObjectStackCache();
	if (this->opens == nullptr) {
		$set(this, opens, $new($ArrayList, 5));
	}
	$nc(this->opens)->add($$new($ModuleOpenNode, packaze, access, $($Util::asArrayList(modules))));
}

void ModuleNode::visitUse($String* service) {
	if (this->uses == nullptr) {
		$set(this, uses, $new($ArrayList, 5));
	}
	$nc(this->uses)->add(service);
}

void ModuleNode::visitProvide($String* service, $StringArray* providers) {
	$useLocalCurrentObjectStackCache();
	if (this->provides == nullptr) {
		$set(this, provides, $new($ArrayList, 5));
	}
	$nc(this->provides)->add($$new($ModuleProvideNode, service, $($Util::asArrayList(providers))));
}

void ModuleNode::visitEnd() {
}

void ModuleNode::accept($ClassVisitor* classVisitor) {
	$useLocalCurrentObjectStackCache();
	$var($ModuleVisitor, moduleVisitor, $nc(classVisitor)->visitModule(this->name, this->access, this->version));
	if (moduleVisitor == nullptr) {
		return;
	}
	if (this->mainClass != nullptr) {
		$nc(moduleVisitor)->visitMainClass(this->mainClass);
	}
	if (this->packages != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->packages)->size();
			for (; i < n; ++i) {
				$nc(moduleVisitor)->visitPackage($cast($String, $($nc(this->packages)->get(i))));
			}
		}
	}
	if (this->requires != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->requires)->size();
			for (; i < n; ++i) {
				$nc(($cast($ModuleRequireNode, $($nc(this->requires)->get(i)))))->accept(moduleVisitor);
			}
		}
	}
	if (this->exports != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->exports)->size();
			for (; i < n; ++i) {
				$nc(($cast($ModuleExportNode, $($nc(this->exports)->get(i)))))->accept(moduleVisitor);
			}
		}
	}
	if (this->opens != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->opens)->size();
			for (; i < n; ++i) {
				$nc(($cast($ModuleOpenNode, $($nc(this->opens)->get(i)))))->accept(moduleVisitor);
			}
		}
	}
	if (this->uses != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->uses)->size();
			for (; i < n; ++i) {
				$nc(moduleVisitor)->visitUse($cast($String, $($nc(this->uses)->get(i))));
			}
		}
	}
	if (this->provides != nullptr) {
		{
			int32_t i = 0;
			int32_t n = $nc(this->provides)->size();
			for (; i < n; ++i) {
				$nc(($cast($ModuleProvideNode, $($nc(this->provides)->get(i)))))->accept(moduleVisitor);
			}
		}
	}
}

ModuleNode::ModuleNode() {
}

$Class* ModuleNode::load$($String* name, bool initialize) {
	$loadClass(ModuleNode, name, initialize, &_ModuleNode_ClassInfo_, allocate$ModuleNode);
	return class$;
}

$Class* ModuleNode::class$ = nullptr;

					} // tree
				} // asm$
			} // objectweb
		} // org
	} // internal
} // jdk
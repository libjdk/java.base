#include <indify/Indify$Logic.h>

#include <indify/Indify$Attr.h>
#include <indify/Indify$ClassFile.h>
#include <indify/Indify$Constant.h>
#include <indify/Indify$CountedList.h>
#include <indify/Indify$Instruction.h>
#include <indify/Indify$Logic$JVMState.h>
#include <indify/Indify$Member.h>
#include <indify/Indify$Method.h>
#include <indify/Indify$Outer.h>
#include <indify/Indify$Pool.h>
#include <indify/Indify.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/DataInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <java/lang/Number.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Modifier.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <jcpp.h>

#undef EMPTY_SLOT
#undef INSTRUCTION_CONSTANTS
#undef INSTRUCTION_POPS
#undef UNKNOWN_CON

using $ShortArray = $Array<::java::lang::Short>;
using $Indify = ::indify::Indify;
using $Indify$Attr = ::indify::Indify$Attr;
using $Indify$ClassFile = ::indify::Indify$ClassFile;
using $Indify$Constant = ::indify::Indify$Constant;
using $Indify$CountedList = ::indify::Indify$CountedList;
using $Indify$Instruction = ::indify::Indify$Instruction;
using $Indify$Logic$JVMState = ::indify::Indify$Logic$JVMState;
using $Indify$Method = ::indify::Indify$Method;
using $Indify$Outer = ::indify::Indify$Outer;
using $Indify$Pool = ::indify::Indify$Pool;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $DataInputStream = ::java::io::DataInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $Byte = ::java::lang::Byte;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Number = ::java::lang::Number;
using $Short = ::java::lang::Short;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;

namespace indify {

$FieldInfo _Indify$Logic_FieldInfo_[] = {
	{"this$0", "Lindify/Indify;", nullptr, $FINAL | $SYNTHETIC, $field(Indify$Logic, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Indify$Logic, $assertionsDisabled)},
	{"cf", "Lindify/Indify$ClassFile;", nullptr, 0, $field(Indify$Logic, cf)},
	{"poolMarks", "[C", nullptr, $FINAL, $field(Indify$Logic, poolMarks)},
	{"constants", "Ljava/util/Map;", "Ljava/util/Map<Lindify/Indify$Method;Lindify/Indify$Constant;>;", $FINAL, $field(Indify$Logic, constants)},
	{"indySignatures", "Ljava/util/Map;", "Ljava/util/Map<Lindify/Indify$Method;Ljava/lang/String;>;", $FINAL, $field(Indify$Logic, indySignatures)},
	{"EMPTY_SLOT", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Indify$Logic, EMPTY_SLOT)},
	{"UNKNOWN_CON", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Indify$Logic, UNKNOWN_CON)},
	{}
};

$MethodInfo _Indify$Logic_MethodInfo_[] = {
	{"<init>", "(Lindify/Indify;Lindify/Indify$ClassFile;)V", nullptr, 0, $method(Indify$Logic, init$, void, $Indify*, $Indify$ClassFile*)},
	{"bootstrapMethodSpecifiers", "(Z)Ljava/util/List;", "(Z)Ljava/util/List<[Ljava/lang/Object;>;", 0, $virtualMethod(Indify$Logic, bootstrapMethodSpecifiers, $List*, bool)},
	{"findPatternMethods", "()Z", nullptr, 0, $virtualMethod(Indify$Logic, findPatternMethods, bool)},
	{"findPop", "(Lindify/Indify$Instruction;)Lindify/Indify$Instruction;", nullptr, 0, $virtualMethod(Indify$Logic, findPop, $Indify$Instruction*, $Indify$Instruction*)},
	{"flattenVarargs", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/lang/Object;>;)V", $PRIVATE, $method(Indify$Logic, flattenVarargs, void, $List*)},
	{"initializeMarks", "()Z", nullptr, 0, $virtualMethod(Indify$Logic, initializeMarks, bool)},
	{"isConstant", "(Ljava/lang/Object;I)Z", nullptr, $PRIVATE, $method(Indify$Logic, isConstant, bool, Object$*, int32_t)},
	{"makeInvokeDynamicCon", "(Ljava/util/List;)Lindify/Indify$Constant;", "(Ljava/util/List<Ljava/lang/Object;>;)Lindify/Indify$Constant;", $PRIVATE, $method(Indify$Logic, makeInvokeDynamicCon, $Indify$Constant*, $List*)},
	{"makeMethodTypeCon", "(Ljava/lang/Object;)Lindify/Indify$Constant;", nullptr, $PRIVATE, $method(Indify$Logic, makeMethodTypeCon, $Indify$Constant*, Object$*)},
	{"matchType", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, 0, $virtualMethod(Indify$Logic, matchType, bool, $String*, $String*)},
	{"nameAndTypeMark", "([Ljava/lang/Short;)C", nullptr, 0, $virtualMethod(Indify$Logic, nameAndTypeMark, char16_t, $ShortArray*)},
	{"nameAndTypeMark", "(SS)C", nullptr, 0, $virtualMethod(Indify$Logic, nameAndTypeMark, char16_t, int16_t, int16_t)},
	{"nameMark", "(Ljava/lang/String;)C", nullptr, 0, $virtualMethod(Indify$Logic, nameMark, char16_t, $String*)},
	{"parseMemberLookup", "(BLjava/util/List;)Lindify/Indify$Constant;", "(BLjava/util/List<Ljava/lang/Object;>;)Lindify/Indify$Constant;", $PRIVATE, $method(Indify$Logic, parseMemberLookup, $Indify$Constant*, int8_t, $List*)},
	{"removeEmptyJVMSlots", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/lang/Object;>;)V", $PRIVATE, $method(Indify$Logic, removeEmptyJVMSlots, void, $List*)},
	{"reportPatternMethods", "(ZZ)V", nullptr, 0, $virtualMethod(Indify$Logic, reportPatternMethods, void, bool, bool)},
	{"scanPattern", "(Lindify/Indify$Method;C)Lindify/Indify$Constant;", nullptr, $PRIVATE, $method(Indify$Logic, scanPattern, $Indify$Constant*, $Indify$Method*, char16_t)},
	{"transform", "()Z", nullptr, 0, $virtualMethod(Indify$Logic, transform, bool)},
	{}
};

$InnerClassInfo _Indify$Logic_InnerClassesInfo_[] = {
	{"indify.Indify$Logic", "indify.Indify", "Logic", $PRIVATE},
	{"indify.Indify$Logic$JVMState", "indify.Indify$Logic", "JVMState", $PRIVATE},
	{}
};

$ClassInfo _Indify$Logic_ClassInfo_ = {
	$ACC_SUPER,
	"indify.Indify$Logic",
	"java.lang.Object",
	nullptr,
	_Indify$Logic_FieldInfo_,
	_Indify$Logic_MethodInfo_,
	nullptr,
	nullptr,
	_Indify$Logic_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"indify.Indify"
};

$Object* allocate$Indify$Logic($Class* clazz) {
	return $of($alloc(Indify$Logic));
}

bool Indify$Logic::$assertionsDisabled = false;

void Indify$Logic::init$($Indify* this$0, $Indify$ClassFile* cf) {
	$set(this, this$0, this$0);
	$set(this, constants, $new($HashMap));
	$set(this, indySignatures, $new($HashMap));
	$set(this, EMPTY_SLOT, "_"_s);
	$set(this, UNKNOWN_CON, "<unknown>"_s);
	$set(this, cf, cf);
	$set(this, poolMarks, $new($chars, $nc($nc(cf)->pool)->size()));
}

bool Indify$Logic::transform() {
	$useLocalCurrentObjectStackCache();
	if (!initializeMarks()) {
		return false;
	}
	if (!findPatternMethods()) {
		return false;
	}
	$var($Indify$Pool, pool, $nc(this->cf)->pool);
	{
		$var($Iterator, i$, $nc($nc(this->cf)->methods)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Indify$Method, m, $cast($Indify$Method, i$->next()));
			{
				if ($nc(this->constants)->containsKey(m)) {
					continue;
				}
				int32_t blab = 0;
				{
					$var($Indify$Instruction, i, $nc(m)->instructions());
					for (; i != nullptr; $assign(i, $nc(i)->next())) {
						if (i->bc != 184) {
							continue;
						}
						int32_t methi = i->u2At(1);
						if ($nc(this->poolMarks)->get(methi) == 0) {
							continue;
						}
						$var($ShortArray, ref, $nc(pool)->getMemberRef((int16_t)methi));
						$var($List, var$0, $nc(this->cf)->methods);
						int32_t var$1 = (int32_t)$nc($nc(ref)->get(1))->shortValue();
						$var($Indify$Method, conm, $cast($Indify$Method, $Indify::findMember(var$0, var$1, $nc(ref->get(2))->shortValue())));
						if (conm == nullptr) {
							continue;
						}
						$var($Indify$Constant, con, $cast($Indify$Constant, $nc(this->constants)->get(conm)));
						if (con == nullptr) {
							continue;
						}
						if (blab++ == 0 && !this->this$0->quiet) {
							$nc($System::err)->println($$str({"patching "_s, $($nc(this->cf)->nameString()), "."_s, m}));
						}
						if ($nc(con)->tag == (int8_t)18) {
							$var($Indify$Instruction, i2, findPop(i));
							$var($ShortArray, ref2, nullptr);
							int16_t ref2i = (int16_t)0;
							if (i2 != nullptr && i2->bc == 182 && $nc(this->poolMarks)->get((char16_t)(ref2i = (int16_t)i2->u2At(1))) == u'D') {
								$assign(ref2, pool->getMemberRef(ref2i));
							}
							if (ref2 == nullptr || !"invokeExact"_s->equals($(pool->getString($nc($nc(ref2)->get(1))->shortValue())))) {
								$nc($System::err)->println($$str({m, ": failed to create invokedynamic at "_s, $$str(i->pc)}));
								continue;
							}
							$var($String, invType, pool->getString($nc($nc(ref2)->get(2))->shortValue()));
							$var($String, bsmType, $cast($String, $nc(this->indySignatures)->get(conm)));
							if (!$nc(invType)->equals(bsmType)) {
								$nc($System::err)->println($$str({m, ": warning: "_s, conm, " call type and local invoke type differ: "_s, bsmType, ", "_s, invType}));
							}
							if (!Indify$Logic::$assertionsDisabled && !(i->len == 3 || $nc(i2)->len == 3)) {
								$throwNew($AssertionError);
							}
							if (!this->this$0->quiet) {
								$nc($System::err)->println($$str({i, " "_s, conm, ";...; "_s, i2, " => invokedynamic "_s, con}));
							}
							int32_t start = i->pc + 3;
							int32_t end = $nc(i2)->pc;
							$System::arraycopy(i->codeBase, start, i->codeBase, i->pc, end - start);
							i->forceNext(0);
							i2->u1AtPut(-3, 186);
							i2->u2AtPut(-2, con->index);
							i2->u2AtPut(0, (int16_t)0);
							i2->u1AtPut(2, 0);
						} else {
							if (!this->this$0->quiet) {
								$nc($System::err)->println($$str({i, " "_s, conm, " => ldc "_s, con}));
							}
							if (!Indify$Logic::$assertionsDisabled && !(i->len == 3)) {
								$throwNew($AssertionError);
							}
							i->u1AtPut(0, 19);
							i->u2AtPut(1, con->index);
						}
					}
				}
			}
		}
	}
	$nc($nc(this->cf)->methods)->removeAll($($nc(this->constants)->keySet()));
	return true;
}

$Indify$Instruction* Indify$Logic::findPop($Indify$Instruction* i$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Indify$Instruction, i, i$renamed);
	$var($Indify$Pool, pool, $nc(this->cf)->pool);
	$var($Indify$Logic$JVMState, jvm, $new($Indify$Logic$JVMState, this));
	bool decode$continue = false;
	bool decode$break = false;
	for ($assign(i, $nc($($nc(i)->clone()))->next()); i != nullptr; $assign(i, i->next())) {
		$init($Indify);
		$var($String, pops, $nc($Indify::INSTRUCTION_POPS)->get(i->bc));
		if (pops == nullptr) {
			break;
		}
		if (jvm->stackMotion(i->bc)) {
			continue;
		}
		if ($nc(pops)->indexOf((int32_t)u'Q') >= 0) {
			$var($ShortArray, ref, $nc(pool)->getMemberRef((int16_t)i->u2At(1)));
			$var($String, type, $Indify::simplifyType($(pool->getString((int8_t)1, $nc($nc(ref)->get(2))->shortValue()))));
			switch (i->bc) {
			case 178:
				{}
			case 180:
				{}
			case 179:
				{}
			case 181:
				{
					$assign(pops, pops->replace(static_cast<$CharSequence*>("Q"_s), static_cast<$CharSequence*>(type)));
					break;
				}
			default:
				{
					if (!$nc(type)->startsWith("("_s)) {
						$throwNew($InternalError, $(i->toString()));
					}
					$assign(pops, pops->replace(static_cast<$CharSequence*>("Q$Q"_s), $(static_cast<$CharSequence*>($($nc(type)->substring(1))->replace(static_cast<$CharSequence*>(")"_s), static_cast<$CharSequence*>("$"_s))))));
					break;
				}
			}
		}
		int32_t npops = $nc(pops)->indexOf((int32_t)u'$');
		if (npops < 0) {
			$throwNew($InternalError);
		}
		if (npops > jvm->sp()) {
			return i;
		}
		$var($List, args, jvm->args(npops));
		int32_t k = 0;
		{
			$var($Iterator, i$, $nc(args)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Object, x, i$->next());
				{
					char16_t have = $nc(($cast($Character, x)))->charValue();
					char16_t want = pops->charAt(k++);
					if (have == u'X' || want == u'X') {
						continue;
					}
					if (have != want) {
						decode$break = true;
						break;
					}
				}
			}
			if (decode$break) {
				break;
			}
		}
		if (pops->charAt(k++) != u'$') {
			decode$break = true;
			break;
		}
		args->clear();
		while (k < pops->length()) {
			args->add($($Character::valueOf(pops->charAt(k++))));
		}
	}
	$nc($System::err)->println($$str({"*** bailout on jvm: "_s, jvm->stack, " "_s, i}));
	return nullptr;
}

bool Indify$Logic::findPatternMethods() {
	$useLocalCurrentObjectStackCache();
	bool found = false;
	{
		$var($chars, arr$, "THI"_s->toCharArray());
		int32_t len$ = arr$->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			char16_t mark = arr$->get(i$);
			{
				{
					$var($Iterator, i$, $nc($nc(this->cf)->methods)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Indify$Method, m, $cast($Indify$Method, i$->next()));
						{
							if (!$Modifier::isPrivate($nc(m)->access)) {
								continue;
							}
							if (!$Modifier::isStatic($nc(m)->access)) {
								continue;
							}
							if (nameAndTypeMark($nc(m)->name, m->type) == mark) {
								$var($Indify$Constant, con, scanPattern(m, mark));
								if (con == nullptr) {
									continue;
								}
								$nc(this->constants)->put(m, con);
								found = true;
							}
						}
					}
				}
			}
		}
	}
	return found;
}

void Indify$Logic::reportPatternMethods(bool quietly, bool allowMatchFailure) {
	$useLocalCurrentObjectStackCache();
	if (!quietly && !$nc($($nc(this->constants)->keySet()))->isEmpty()) {
		$nc($System::err)->println($$str({"pattern methods removed: "_s, $($nc(this->constants)->keySet())}));
	}
	{
		$var($Iterator, i$, $nc($nc(this->cf)->methods)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Indify$Method, m, $cast($Indify$Method, i$->next()));
			{
				bool var$0 = nameMark($($nc($nc(this->cf)->pool)->getString($nc(m)->name))) != 0;
				if (var$0 && $nc(this->constants)->get(m) == nullptr) {
					$var($String, failure, $str({"method has special name but fails to match pattern: "_s, m}));
					if (!allowMatchFailure) {
						$throwNew($IllegalArgumentException, failure);
					} else if (!quietly) {
						$nc($System::err)->println($$str({"warning: "_s, failure}));
					}
				}
			}
		}
	}
	if (this->this$0->verifySpecifierCount >= 0) {
		$var($List, specs, bootstrapMethodSpecifiers(false));
		int32_t specsLen = (specs == nullptr ? 0 : $nc(specs)->size());
		if (specsLen == 0) {
			specsLen = this->this$0->verifySpecifierCount;
		}
		if (specsLen != this->this$0->verifySpecifierCount) {
			$throwNew($IllegalArgumentException, $$str({"BootstrapMethods length is "_s, $$str(specsLen), " but should be "_s, $$str(this->this$0->verifySpecifierCount)}));
		}
	}
	if (!this->this$0->quiet) {
		$nc($System::err)->flush();
	}
}

bool Indify$Logic::initializeMarks() {
	$useLocalCurrentObjectStackCache();
	bool changed = false;
	for (;;) {
		bool changed1 = false;
		int32_t cpindex = -1;
		{
			$var($Iterator, i$, $nc($nc(this->cf)->pool)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Indify$Constant, e, $cast($Indify$Constant, i$->next()));
				{
					++cpindex;
					if (e == nullptr) {
						continue;
					}
					char16_t mark = $nc(this->poolMarks)->get(cpindex);
					if (mark != 0) {
						continue;
					}
					switch ($nc(e)->tag) {
					case 1:
						{
							mark = nameMark($(e->itemString()));
							break;
						}
					case 12:
						{
							mark = nameAndTypeMark($(e->itemIndexes()));
							break;
						}
					case 7:
						{
							{
								int32_t n1 = $nc($(e->itemIndex()))->shortValue();
								char16_t nmark = $nc(this->poolMarks)->get((char16_t)n1);
								if ("DJ"_s->indexOf((int32_t)nmark) >= 0) {
									mark = nmark;
								}
								break;
							}
						}
					case 9:
						{}
					case 10:
						{
							{
								$var($ShortArray, n12, e->itemIndexes());
								int16_t cl = $nc($nc(n12)->get(0))->shortValue();
								int16_t nt = $nc(n12->get(1))->shortValue();
								char16_t cmark = $nc(this->poolMarks)->get((char16_t)cl);
								if (cmark != 0) {
									mark = cmark;
									break;
								}
								$var($String, cls, $nc($nc(this->cf)->pool)->getString((int8_t)7, cl));
								if ($nc(cls)->equals($($nc(this->cf)->nameString()))) {
									switch ($nc(this->poolMarks)->get((char16_t)nt)) {
									case u'T':
										{}
									case u'H':
										{}
									case u'I':
										{
											mark = $nc(this->poolMarks)->get((char16_t)nt);
											break;
										}
									}
								}
								break;
							}
						}
					default:
						{
							break;
						}
					}
					if (mark != 0) {
						$nc(this->poolMarks)->set(cpindex, mark);
						changed1 = true;
					}
				}
			}
		}
		if (!changed1) {
			break;
		}
		changed = true;
	}
	return changed;
}

char16_t Indify$Logic::nameMark($String* s) {
	if ($nc(s)->startsWith("MT_"_s)) {
		return u'T';
	} else if (s->startsWith("MH_"_s)) {
		return u'H';
	} else if (s->startsWith("INDY_"_s)) {
		return u'I';
	} else if (s->startsWith("java/lang/invoke/"_s)) {
		return u'D';
	} else if (s->startsWith("java/lang/"_s)) {
		return u'J';
	}
	return (char16_t)0;
}

char16_t Indify$Logic::nameAndTypeMark($ShortArray* n12) {
	int16_t var$0 = $nc($nc(n12)->get(0))->shortValue();
	return nameAndTypeMark(var$0, $nc(n12->get(1))->shortValue());
}

char16_t Indify$Logic::nameAndTypeMark(int16_t n1, int16_t n2) {
	$useLocalCurrentObjectStackCache();
	char16_t mark = $nc(this->poolMarks)->get((char16_t)n1);
	if (mark == 0) {
		return (char16_t)0;
	}
	$var($String, descr, $nc($nc(this->cf)->pool)->getString((int8_t)1, n2));
	$var($String, requiredType, nullptr);
	switch ($nc(this->poolMarks)->get((char16_t)n1)) {
	case u'H':
		{
			$assign(requiredType, "()Ljava/lang/invoke/MethodHandle;"_s);
			break;
		}
	case u'T':
		{
			$assign(requiredType, "()Ljava/lang/invoke/MethodType;"_s);
			break;
		}
	case u'I':
		{
			$assign(requiredType, "()Ljava/lang/invoke/MethodHandle;"_s);
			break;
		}
	default:
		{
			return (char16_t)0;
		}
	}
	if (matchType(descr, requiredType)) {
		return mark;
	}
	return (char16_t)0;
}

bool Indify$Logic::matchType($String* descr, $String* requiredType) {
	if ($nc(descr)->equals(requiredType)) {
		return true;
	}
	return false;
}

void Indify$Logic::removeEmptyJVMSlots($List* args) {
	$useLocalCurrentObjectStackCache();
	for (;;) {
		int32_t i = $nc(args)->indexOf(this->EMPTY_SLOT);
		bool var$0 = i >= 0 && i + 1 < args->size();
		if (var$0) {
			bool var$1 = isConstant($(args->get(i + 1)), 5);
			var$0 = (var$1 || isConstant($(args->get(i + 1)), 6));
		}
		if (var$0) {
			args->remove(i);
		} else {
			break;
		}
	}
}

$Indify$Constant* Indify$Logic::scanPattern($Indify$Method* m, char16_t patternMark) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->this$0->verbose) {
		$nc($System::err)->println($$str({"scan "_s, m, " for pattern="_s, $$str(patternMark)}));
	}
	int32_t wantTag = 0;
	switch (patternMark) {
	case u'T':
		{
			wantTag = 16;
			break;
		}
	case u'H':
		{
			wantTag = 15;
			break;
		}
	case u'I':
		{
			wantTag = 18;
			break;
		}
	default:
		{
			$throwNew($InternalError);
		}
	}
	$var($Indify$Instruction, i, $nc(m)->instructions());
	$var($Indify$Logic$JVMState, jvm, $new($Indify$Logic$JVMState, this));
	$var($Indify$Pool, pool, $nc(this->cf)->pool);
	int32_t branchCount = 0;
	$var($Object, arg, nullptr);
	$var($List, args, nullptr);
	$var($List, bsmArgs, nullptr);
	bool decode$continue = false;
	bool decode$break = false;
	for (; i != nullptr; $assign(i, $nc(i)->next())) {
		int32_t bc = i->bc;
		switch (bc) {
		case 18:
			{
				jvm->push($($nc(pool)->get(i->u1At(1))));
				break;
			}
		case 19:
			{
				jvm->push($($nc(pool)->get(i->u2At(1))));
				break;
			}
		case 20:
			{
				jvm->push2($($nc(pool)->get(i->u2At(1))));
				break;
			}
		case 1:
			{
				jvm->push(nullptr);
				break;
			}
		case 16:
			{
				jvm->push($($Integer::valueOf((int32_t)(int8_t)i->u1At(1))));
				break;
			}
		case 17:
			{
				jvm->push($($Integer::valueOf((int32_t)(int16_t)i->u2At(1))));
				break;
			}
		case 189:
			{
				$assign(arg, jvm->pop());
				if (!($instanceOf($Integer, arg))) {
					decode$break = true;
					break;
				}
				$assign(arg, $Arrays::asList($$new($ObjectArray, $nc(($cast($Integer, arg)))->intValue())));
				jvm->push(arg);
				break;
			}
		case 89:
			{
				jvm->push($(jvm->top()));
				break;
			}
		case 83:
			{
				$assign(args, jvm->args(3));
				bool var$0 = $instanceOf($List, $($nc(args)->get(0)));
				if (var$0 && $instanceOf($Integer, $(args->get(1)))) {
					$var($List, arg0, $cast($List, args->get(0)));
					int32_t var$1 = $nc(($cast($Integer, $(args->get(1)))))->intValue();
					$nc(arg0)->set(var$1, $(args->get(2)));
				}
				$nc(args)->clear();
				break;
			}
		case 187:
			{
				{
					$var($String, type, $nc(pool)->getString((int8_t)7, (int16_t)i->u2At(1)));
					{
						$var($String, s32102$, type);
						int32_t tmp32102$ = -1;
						switch ($nc(s32102$)->hashCode()) {
						case 0x52D470D6:
							{
								if (s32102$->equals("java/lang/StringBuilder"_s)) {
									tmp32102$ = 0;
								}
								break;
							}
						}
						switch (tmp32102$) {
						case 0:
							{
								jvm->push("StringBuilder"_s);
								continue;
							}
						}

						if (decode$continue) {
							decode$continue = false;
							continue;
						}					}
					decode$break = true;
					break;
				}
			}
		case 178:
			{
				{
					int32_t fieldi = i->u2At(1);
					char16_t mark = $nc(this->poolMarks)->get(fieldi);
					if (mark == u'J') {
						$var($ShortArray, ref, $nc(pool)->getMemberRef((int16_t)fieldi));
						$var($String, name, pool->getString((int8_t)1, $nc($nc(ref)->get(1))->shortValue()));
						if ("TYPE"_s->equals(name)) {
							$var($String, wrapperName, $nc($(pool->getString((int8_t)7, $nc($nc(ref)->get(0))->shortValue())))->replace(u'/', u'.'));
							$Class* primClass = nullptr;
							try {
								primClass = $cast($Class, $nc($($Class::forName(wrapperName)->getField(name)))->get(nullptr));
							} catch ($Exception& ex) {
								$throwNew($InternalError, $$str({"cannot load "_s, wrapperName, "."_s, name}));
							}
							jvm->push(primClass);
							break;
						}
					}
					jvm->push(this->UNKNOWN_CON);
					break;
				}
			}
		case 179:
			{
				{
					if (patternMark != u'I') {
						decode$break = true;
						break;
					}
					jvm->pop();
					break;
				}
			}
		case 184:
			{}
		case 182:
			{}
		case 183:
			{
				{
					bool hasRecv = (bc != 184);
					int32_t methi = i->u2At(1);
					char16_t mark = $nc(this->poolMarks)->get(methi);
					$var($ShortArray, ref, $nc(pool)->getMemberRef((int16_t)methi));
					$var($String, type, pool->getString((int8_t)1, $nc($nc(ref)->get(2))->shortValue()));
					$assign(args, jvm->args(hasRecv, type));
					$var($String, intrinsic, nullptr);
					$var($Indify$Constant, con, nullptr);
					if (mark == u'D' || mark == u'J') {
						$assign(intrinsic, pool->getString((int8_t)1, $nc($nc(ref)->get(1))->shortValue()));
						if (mark == u'J') {
							$var($String, cls, pool->getString((int8_t)7, $nc($nc(ref)->get(0))->shortValue()));
							$assign(cls, $nc(cls)->substring(1 + cls->lastIndexOf((int32_t)u'/')));
							$assign(intrinsic, $str({cls, "."_s, intrinsic}));
						}
						int8_t refKind = (int8_t)-1;
						{
							$var($String, s35263$, intrinsic);
							int32_t tmp35263$ = -1;
							switch ($nc(s35263$)->hashCode()) {
							case (int32_t)0xF0F2DC24:
								{
									if (s35263$->equals("findGetter"_s)) {
										tmp35263$ = 0;
									}
									break;
								}
							case 0x37FA1572:
								{
									if (s35263$->equals("findStaticGetter"_s)) {
										tmp35263$ = 1;
									}
									break;
								}
							case 0x056D0398:
								{
									if (s35263$->equals("findSetter"_s)) {
										tmp35263$ = 2;
									}
									break;
								}
							case 0x4C743CE6:
								{
									if (s35263$->equals("findStaticSetter"_s)) {
										tmp35263$ = 3;
									}
									break;
								}
							case 0x4D9D8F12:
								{
									if (s35263$->equals("findVirtual"_s)) {
										tmp35263$ = 4;
									}
									break;
								}
							case 0x0637C187:
								{
									if (s35263$->equals("findStatic"_s)) {
										tmp35263$ = 5;
									}
									break;
								}
							case (int32_t)0xBA1DB0C0:
								{
									if (s35263$->equals("findSpecial"_s)) {
										tmp35263$ = 6;
									}
									break;
								}
							case (int32_t)0xF3D1EC81:
								{
									if (s35263$->equals("findConstructor"_s)) {
										tmp35263$ = 7;
									}
									break;
								}
							}
							switch (tmp35263$) {
							case 0:
								{
									refKind = (int8_t)1;
									break;
								}
							case 1:
								{
									refKind = (int8_t)2;
									break;
								}
							case 2:
								{
									refKind = (int8_t)3;
									break;
								}
							case 3:
								{
									refKind = (int8_t)4;
									break;
								}
							case 4:
								{
									refKind = (int8_t)5;
									break;
								}
							case 5:
								{
									refKind = (int8_t)6;
									break;
								}
							case 6:
								{
									refKind = (int8_t)7;
									break;
								}
							case 7:
								{
									refKind = (int8_t)8;
									break;
								}
							}
						}
						if (refKind >= 0 && ($assign(con, parseMemberLookup(refKind, args))) != nullptr) {
							$nc(args)->clear();
							args->add(con);
							continue;
						}
					}
					$var($Indify$Method, ownMethod, nullptr);
					if (mark == u'T' || mark == u'H' || mark == u'I') {
						$var($List, var$2, $nc(this->cf)->methods);
						int32_t var$3 = (int32_t)$nc($nc(ref)->get(1))->shortValue();
						$assign(ownMethod, $cast($Indify$Method, $Indify::findMember(var$2, var$3, $nc(ref->get(2))->shortValue())));
					}
					{
						$var($String, s36601$, intrinsic == nullptr ? ""_s : intrinsic);
						int32_t tmp36601$ = -1;
						switch ($nc(s36601$)->hashCode()) {
						case (int32_t)0xF1AC0BAB:
							{
								if (s36601$->equals("fromMethodDescriptorString"_s)) {
									tmp36601$ = 0;
								}
								break;
							}
						case (int32_t)0xD4E87BBB:
							{
								if (s36601$->equals("methodType"_s)) {
									tmp36601$ = 1;
								}
								break;
							}
						case (int32_t)0xBE9BA97A:
							{
								if (s36601$->equals("lookup"_s)) {
									tmp36601$ = 2;
								}
								break;
							}
						case (int32_t)0x87078DBB:
							{
								if (s36601$->equals("dynamicInvoker"_s)) {
									tmp36601$ = 3;
								}
								break;
							}
						case 0x6157EC1E:
							{
								if (s36601$->equals("lookupClass"_s)) {
									tmp36601$ = 4;
								}
								break;
							}
						case (int32_t)0xB9724478:
							{
								if (s36601$->equals("invoke"_s)) {
									tmp36601$ = 5;
								}
								break;
							}
						case 0x0237E63F:
							{
								if (s36601$->equals("invokeGeneric"_s)) {
									tmp36601$ = 6;
								}
								break;
							}
						case 0x634C5598:
							{
								if (s36601$->equals("invokeWithArguments"_s)) {
									tmp36601$ = 7;
								}
								break;
							}
						case (int32_t)0xD10E2E58:
							{
								if (s36601$->equals("Integer.valueOf"_s)) {
									tmp36601$ = 8;
								}
								break;
							}
						case 0x7D094976:
							{
								if (s36601$->equals("Float.valueOf"_s)) {
									tmp36601$ = 9;
								}
								break;
							}
						case 0x2F41F1D6:
							{
								if (s36601$->equals("Long.valueOf"_s)) {
									tmp36601$ = 10;
								}
								break;
							}
						case 0x33B5FA2B:
							{
								if (s36601$->equals("Double.valueOf"_s)) {
									tmp36601$ = 11;
								}
								break;
							}
						case (int32_t)0x8DE63F5E:
							{
								if (s36601$->equals("StringBuilder.append"_s)) {
									tmp36601$ = 12;
								}
								break;
							}
						case (int32_t)0xFD7CC1B0:
							{
								if (s36601$->equals("StringBuilder.toString"_s)) {
									tmp36601$ = 13;
								}
								break;
							}
						}
						switch (tmp36601$) {
						case 0:
							{
								$assign(con, makeMethodTypeCon($($nc(args)->get(0))));
								$nc(args)->clear();
								$nc(args)->add(con);
								continue;
							}
						case 1:
							{
								{
									flattenVarargs(args);
									$var($StringBuilder, buf, $new($StringBuilder));
									$var($String, rtype, nullptr);
									{
										$var($Iterator, i$, $nc(args)->iterator());
										for (; $nc(i$)->hasNext();) {
											$var($Object, typeArg, i$->next());
											{
												if ($instanceOf($Class, typeArg)) {
													$Class* argClass = $cast($Class, typeArg);
													if ($nc(argClass)->isPrimitive()) {
														char16_t tchar = 0;
														{
															$var($String, s37434$, argClass->getName());
															int32_t tmp37434$ = -1;
															switch ($nc(s37434$)->hashCode()) {
															case 0x00375194:
																{
																	if (s37434$->equals("void"_s)) {
																		tmp37434$ = 0;
																	}
																	break;
																}
															case 0x03DB6C28:
																{
																	if (s37434$->equals("boolean"_s)) {
																		tmp37434$ = 1;
																	}
																	break;
																}
															case 0x002E6108:
																{
																	if (s37434$->equals("byte"_s)) {
																		tmp37434$ = 2;
																	}
																	break;
																}
															case 0x002E9356:
																{
																	if (s37434$->equals("char"_s)) {
																		tmp37434$ = 3;
																	}
																	break;
																}
															case 0x0685847C:
																{
																	if (s37434$->equals("short"_s)) {
																		tmp37434$ = 4;
																	}
																	break;
																}
															case 0x000197EF:
																{
																	if (s37434$->equals("int"_s)) {
																		tmp37434$ = 5;
																	}
																	break;
																}
															case 0x0032C67C:
																{
																	if (s37434$->equals("long"_s)) {
																		tmp37434$ = 6;
																	}
																	break;
																}
															case 0x05D0225C:
																{
																	if (s37434$->equals("float"_s)) {
																		tmp37434$ = 7;
																	}
																	break;
																}
															case (int32_t)0xB0F77BD1:
																{
																	if (s37434$->equals("double"_s)) {
																		tmp37434$ = 8;
																	}
																	break;
																}
															}
															switch (tmp37434$) {
															case 0:
																{
																	tchar = u'V';
																	break;
																}
															case 1:
																{
																	tchar = u'Z';
																	break;
																}
															case 2:
																{
																	tchar = u'B';
																	break;
																}
															case 3:
																{
																	tchar = u'C';
																	break;
																}
															case 4:
																{
																	tchar = u'S';
																	break;
																}
															case 5:
																{
																	tchar = u'I';
																	break;
																}
															case 6:
																{
																	tchar = u'J';
																	break;
																}
															case 7:
																{
																	tchar = u'F';
																	break;
																}
															case 8:
																{
																	tchar = u'D';
																	break;
																}
															default:
																{
																	$throwNew($InternalError, $(argClass->toString()));
																}
															}
														}
														buf->append(tchar);
													} else {
														buf->append(u'L')->append($($nc($(argClass->getName()))->replace(u'.', u'/')))->append(u';');
													}
												} else if ($instanceOf($Indify$Constant, typeArg)) {
													$var($Indify$Constant, argCon, $cast($Indify$Constant, typeArg));
													if ($nc(argCon)->tag == (int8_t)7) {
														$var($String, cn, $nc($($cast($Indify$Constant, pool->get($nc($(argCon->itemIndex()))->shortValue()))))->itemString());
														if ($nc(cn)->endsWith(";"_s)) {
															buf->append(cn);
														} else {
															buf->append(u'L')->append(cn)->append(u';');
														}
													} else {
														decode$break = true;
														break;
													}
												} else {
													decode$break = true;
													break;
												}
												if (rtype == nullptr) {
													$assign(rtype, buf->toString());
													buf->setLength(0);
													buf->append(u'(');
												}
											}
										}
										if (decode$break) {
											break;
										}
									}
									buf->append(u')')->append(rtype);
									$assign(con, ($assign(con, makeMethodTypeCon($(buf->toString())))));
									args->clear();
									args->add(con);
									continue;
								}
							}
						case 2:
							{}
						case 3:
							{
								$nc(args)->clear();
								$nc(args)->add(intrinsic);
								continue;
							}
						case 4:
							{
								if ($nc(args)->equals($($Arrays::asList($$new($StringArray, {"lookup"_s}))))) {
									args->clear();
									args->add($(pool->get($nc(this->cf)->thisc)));
									continue;
								}
								break;
							}
						case 5:
							{}
						case 6:
							{}
						case 7:
							{
								if (patternMark != u'I') {
									decode$break = true;
									break;
								}
								if ("invokeWithArguments"_s->equals(intrinsic)) {
									flattenVarargs(args);
								}
								$assign(bsmArgs, $new($ArrayList, static_cast<$Collection*>(args)));
								$nc(args)->clear();
								$nc(args)->add("invokeGeneric"_s);
								continue;
							}
						case 8:
							{}
						case 9:
							{}
						case 10:
							{}
						case 11:
							{
								removeEmptyJVMSlots(args);
								if ($nc(args)->size() == 1) {
									$assign(arg, args->remove(0));
									if (isConstant(arg, (int8_t)3 + "IFLD"_s->indexOf((int32_t)$nc(intrinsic)->charAt(0))) || $instanceOf($Number, arg)) {
										args->add(arg);
										continue;
									}
								}
								decode$break = true;
								break;
							}
						case 12:
							{
								removeEmptyJVMSlots(args);
								$nc($($nc(args)->subList(1, args->size())))->clear();
								continue;
							}
						case 13:
							{
								$nc(args)->clear();
								$nc(args)->add(intrinsic);
								continue;
							}
						}

						if (decode$break) {
							break;
						}					}
					if (!hasRecv && ownMethod != nullptr && patternMark != 0) {
						$assign(con, $cast($Indify$Constant, $nc(this->constants)->get(ownMethod)));
						if (con == nullptr) {
							decode$break = true;
							break;
						}
						$nc(args)->clear();
						args->add(con);
						continue;
					} else if ($nc(type)->endsWith(")V"_s)) {
						$nc(args)->clear();
						continue;
					}
					decode$break = true;
					break;
				}
			}
		case 176:
			{
				{
					++branchCount;
					if (bsmArgs != nullptr) {
						$var($Indify$Constant, indyCon, makeInvokeDynamicCon(bsmArgs));
						if (indyCon != nullptr) {
							$var($Indify$Constant, typeCon, $cast($Indify$Constant, bsmArgs->get(3)));
							$nc(this->indySignatures)->put(m, $($nc(pool)->getString($nc($($nc(typeCon)->itemIndex()))->shortValue())));
							return indyCon;
						}
						$nc($System::err)->println($$str({m, ": inscrutable bsm arguments: "_s, bsmArgs}));
						decode$break = true;
						break;
					}
					$assign(arg, jvm->pop());
					if (branchCount == 2 && $nc(this->UNKNOWN_CON)->equals(arg)) {
						break;
					}
					if (isConstant(arg, wantTag)) {
						return $cast($Indify$Constant, arg);
					}
					decode$break = true;
					break;
				}
			}
		default:
			{
				if (jvm->stackMotion(i->bc)) {
					break;
				}
				if (bc >= 2 && bc <= 15) {
					$init($Indify);
					jvm->push($nc($Indify::INSTRUCTION_CONSTANTS)->get(bc - 2));
					break;
				}
				if (patternMark == u'I') {
					if (bc == 25 || bc >= 42 && bc <= 45) {
						jvm->push(this->UNKNOWN_CON);
						break;
					}
					if (bc == 58 || bc >= 75 && bc <= 78) {
						jvm->pop();
						break;
					}
					switch (bc) {
					case 180:
						{}
					case 50:
						{
							jvm->push(this->UNKNOWN_CON);
							break;
						}
					case 198:
						{}
					case 199:
						{
							if (++branchCount != 1) {
								decode$break = true;
								break;
							}
							jvm->pop();
							break;
						}
					case 192:
						{
							$assign(arg, jvm->top());
							bool var$4 = "invokeWithArguments"_s->equals(arg);
							if (var$4 || "invokeGeneric"_s->equals(arg)) {
								break;
							}
							decode$break = true;
							break;
						}
					default:
						{
							decode$break = true;
							break;
						}
					}

					if (decode$break) {
						break;
					}					continue;
				}
				decode$break = true;
				break;
			}
		}

		if (decode$continue) {
			decode$continue = false;
			continue;
		}
		if (decode$break) {
			break;
		}	}
	$nc($System::err)->println($$str({m, ": bailout on "_s, i, " jvm stack: "_s, jvm->stack}));
	return nullptr;
}

void Indify$Logic::flattenVarargs($List* args) {
	$useLocalCurrentObjectStackCache();
	int32_t size = $nc(args)->size();
	if (size > 0 && $instanceOf($List, $(args->get(size - 1)))) {
		$var($List, removedArg, $cast($List, args->remove(size - 1)));
		args->addAll(removedArg);
	}
}

bool Indify$Logic::isConstant(Object$* x, int32_t tag) {
	return $instanceOf($Indify$Constant, x) && $nc(($cast($Indify$Constant, x)))->tag == tag;
}

$Indify$Constant* Indify$Logic::makeMethodTypeCon(Object$* x) {
	$useLocalCurrentObjectStackCache();
	int16_t utfIndex = 0;
	if ($instanceOf($String, x)) {
		utfIndex = (int16_t)$nc($($nc($nc(this->cf)->pool)->addConstant((int8_t)1, x)))->index;
	} else if (isConstant(x, 8)) {
		utfIndex = $nc($($nc(($cast($Indify$Constant, x)))->itemIndex()))->shortValue();
	} else {
		return nullptr;
	}
	return $nc($nc(this->cf)->pool)->addConstant((int8_t)16, $($Short::valueOf(utfIndex)));
}

$Indify$Constant* Indify$Logic::parseMemberLookup(int8_t refKind, $List* args) {
	$useLocalCurrentObjectStackCache();
	if ($nc(args)->size() != 4) {
		return nullptr;
	}
	int32_t argi = 0;
	if (!"lookup"_s->equals($($nc(args)->get(argi++)))) {
		return nullptr;
	}
	int16_t refindex = 0;
	int16_t cindex = 0;
	int16_t ntindex = 0;
	int16_t nindex = 0;
	int16_t tindex = 0;
	$var($Object, con, nullptr);
	if (!isConstant($assign(con, $nc(args)->get(argi++)), 7)) {
		return nullptr;
	}
	cindex = (int16_t)$nc(($cast($Indify$Constant, con)))->index;
	if (!isConstant($assign(con, $nc(args)->get(argi++)), 8)) {
		return nullptr;
	}
	nindex = $nc($($nc(($cast($Indify$Constant, con)))->itemIndex()))->shortValue();
	bool var$0 = isConstant($assign(con, $nc(args)->get(argi++)), 16);
	if (var$0 || isConstant(con, 7)) {
		tindex = $nc($($nc(($cast($Indify$Constant, con)))->itemIndex()))->shortValue();
	} else {
		return nullptr;
	}
	ntindex = (int16_t)$nc($($nc($nc(this->cf)->pool)->addConstant((int8_t)12, $$new($ShortArray, {
		$($Short::valueOf(nindex)),
		$($Short::valueOf(tindex))
	}))))->index;
	int8_t reftag = (int8_t)10;
	if (refKind <= (int8_t)4) {
		reftag = (int8_t)9;
	} else if (refKind == (int8_t)9) {
		reftag = (int8_t)11;
	}
	$var($Indify$Constant, ref, $nc($nc(this->cf)->pool)->addConstant(reftag, $$new($ShortArray, {
		$($Short::valueOf(cindex)),
		$($Short::valueOf(ntindex))
	})));
	return $nc($nc(this->cf)->pool)->addConstant((int8_t)15, $$new($ObjectArray, {
		$($of($Byte::valueOf(refKind))),
		$($of($Short::valueOf((int16_t)$nc(ref)->index)))
	}));
}

$Indify$Constant* Indify$Logic::makeInvokeDynamicCon($List* args) {
	$useLocalCurrentObjectStackCache();
	removeEmptyJVMSlots(args);
	if ($nc(args)->size() < 4) {
		return nullptr;
	}
	int32_t argi = 0;
	int16_t nindex = 0;
	int16_t tindex = 0;
	int16_t ntindex = 0;
	int16_t bsmindex = 0;
	$var($Object, con, nullptr);
	if (!isConstant($assign(con, $nc(args)->get(argi++)), 15)) {
		return nullptr;
	}
	bsmindex = (int16_t)$nc(($cast($Indify$Constant, con)))->index;
	if (!"lookup"_s->equals($($nc(args)->get(argi++)))) {
		return nullptr;
	}
	if (!isConstant($assign(con, $nc(args)->get(argi++)), 8)) {
		return nullptr;
	}
	nindex = $nc($($nc(($cast($Indify$Constant, con)))->itemIndex()))->shortValue();
	if (!isConstant($assign(con, $nc(args)->get(argi++)), 16)) {
		return nullptr;
	}
	tindex = $nc($($nc(($cast($Indify$Constant, con)))->itemIndex()))->shortValue();
	ntindex = (int16_t)$nc($($nc($nc(this->cf)->pool)->addConstant((int8_t)12, $$new($ShortArray, {
		$($Short::valueOf(nindex)),
		$($Short::valueOf(tindex))
	}))))->index;
	$var($List, extraArgs, $new($ArrayList));
	if (argi < $nc(args)->size()) {
		extraArgs->addAll($(args->subList(argi, args->size() - 1)));
		$var($Object, lastArg, args->get(args->size() - 1));
		if ($instanceOf($List, lastArg)) {
			$var($List, lastArgs, $cast($List, lastArg));
			removeEmptyJVMSlots(lastArgs);
			extraArgs->addAll(lastArgs);
		} else {
			extraArgs->add(lastArg);
		}
	}
	$var($List, extraArgIndexes, $new($Indify$CountedList, $Short::class$));
	{
		$var($Iterator, i$, extraArgs->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Object, x, i$->next());
			{
				if ($instanceOf($Number, x)) {
					$var($Object, num, nullptr);
					int8_t numTag = (int8_t)0;
					if ($instanceOf($Integer, x)) {
						$assign(num, x);
						numTag = (int8_t)3;
					}
					if ($instanceOf($Float, x)) {
						$assign(num, $Integer::valueOf($Float::floatToRawIntBits($nc(($cast($Float, x)))->floatValue())));
						numTag = (int8_t)4;
					}
					if ($instanceOf($Long, x)) {
						$assign(num, x);
						numTag = (int8_t)5;
					}
					if ($instanceOf($Double, x)) {
						$assign(num, $Long::valueOf($Double::doubleToRawLongBits($nc(($cast($Double, x)))->doubleValue())));
						numTag = (int8_t)6;
					}
					if (num != nullptr) {
						$assign(x, $nc($nc(this->cf)->pool)->addConstant(numTag, x));
					}
				}
				if (!($instanceOf($Indify$Constant, x))) {
					$nc($System::err)->println($$str({"warning: unrecognized BSM argument "_s, x}));
					return nullptr;
				}
				extraArgIndexes->add($($Short::valueOf((int16_t)$nc(($cast($Indify$Constant, x)))->index)));
			}
		}
	}
	$var($List, specs, bootstrapMethodSpecifiers(true));
	int32_t specindex = -1;
	$var($ObjectArray, spec, $new($ObjectArray, {
		$($of($Short::valueOf(bsmindex))),
		$of(extraArgIndexes)
	}));
	{
		$var($Iterator, i$, $nc(specs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ObjectArray, spec1, $cast($ObjectArray, i$->next()));
			{
				if ($Arrays::equals(spec1, spec)) {
					specindex = specs->indexOf(spec1);
					if (this->this$0->verbose) {
						$nc($System::err)->println($$str({"reusing BSM specifier: "_s, $nc(spec1)->get(0), spec1->get(1)}));
					}
					break;
				}
			}
		}
	}
	if (specindex == -1) {
		specindex = (int16_t)specs->size();
		specs->add(spec);
		if (this->this$0->verbose) {
			$nc($System::err)->println($$str({"adding BSM specifier: "_s, spec->get(0), spec->get(1)}));
		}
	}
	return $nc($nc(this->cf)->pool)->addConstant((int8_t)18, $$new($ShortArray, {
		$($Short::valueOf((int16_t)specindex)),
		$($Short::valueOf(ntindex))
	}));
}

$List* Indify$Logic::bootstrapMethodSpecifiers(bool createIfNotFound) {
	$useLocalCurrentObjectStackCache();
	$var($Indify$Attr, bsms, $nc(this->cf)->findAttr("BootstrapMethods"_s));
	if (bsms == nullptr) {
		if (!createIfNotFound) {
			return nullptr;
		}
		$assign(bsms, $new($Indify$Attr, this->cf, "BootstrapMethods"_s, $$new($bytes, {
			(int8_t)0,
			(int8_t)0
		})));
		if (!Indify$Logic::$assertionsDisabled && !(bsms == $nc(this->cf)->findAttr("BootstrapMethods"_s))) {
			$throwNew($AssertionError);
		}
	}
	if ($instanceOf($bytes, $nc(bsms)->item)) {
		$load($ObjectArray);
		$var($List, specs, $new($Indify$CountedList, $getClass($ObjectArray)));
		$var($DataInputStream, in, $new($DataInputStream, $$new($ByteArrayInputStream, $cast($bytes, bsms->item))));
		try {
			int32_t len = (char16_t)in->readShort();
			for (int32_t i = 0; i < len; ++i) {
				int16_t bsm = in->readShort();
				int32_t argc = (char16_t)in->readShort();
				$load($Short);
				$var($List, argv, $new($Indify$CountedList, $Short::class$));
				for (int32_t j = 0; j < argc; ++j) {
					argv->add($($Short::valueOf(in->readShort())));
				}
				specs->add($$new($ObjectArray, {
					$($of($Short::valueOf(bsm))),
					$of(argv)
				}));
			}
		} catch ($IOException& ex) {
			$throwNew($InternalError);
		}
		$set(bsms, item, specs);
	}
	$var($List, specs, $cast($List, $nc(bsms)->item));
	return specs;
}

void clinit$Indify$Logic($Class* class$) {
	$load($Indify);
	Indify$Logic::$assertionsDisabled = !$Indify::class$->desiredAssertionStatus();
}

Indify$Logic::Indify$Logic() {
}

$Class* Indify$Logic::load$($String* name, bool initialize) {
	$loadClass(Indify$Logic, name, initialize, &_Indify$Logic_ClassInfo_, clinit$Indify$Logic, allocate$Indify$Logic);
	return class$;
}

$Class* Indify$Logic::class$ = nullptr;

} // indify
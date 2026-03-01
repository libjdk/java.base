#include <sun/reflect/generics/parser/SignatureParser.h>

#include <java/lang/AssertionError.h>
#include <java/lang/Error.h>
#include <java/lang/reflect/GenericSignatureFormatError.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <sun/reflect/generics/tree/ArrayTypeSignature.h>
#include <sun/reflect/generics/tree/BaseType.h>
#include <sun/reflect/generics/tree/BooleanSignature.h>
#include <sun/reflect/generics/tree/BottomSignature.h>
#include <sun/reflect/generics/tree/ByteSignature.h>
#include <sun/reflect/generics/tree/CharSignature.h>
#include <sun/reflect/generics/tree/ClassSignature.h>
#include <sun/reflect/generics/tree/ClassTypeSignature.h>
#include <sun/reflect/generics/tree/DoubleSignature.h>
#include <sun/reflect/generics/tree/FieldTypeSignature.h>
#include <sun/reflect/generics/tree/FloatSignature.h>
#include <sun/reflect/generics/tree/FormalTypeParameter.h>
#include <sun/reflect/generics/tree/IntSignature.h>
#include <sun/reflect/generics/tree/LongSignature.h>
#include <sun/reflect/generics/tree/MethodTypeSignature.h>
#include <sun/reflect/generics/tree/ReturnType.h>
#include <sun/reflect/generics/tree/ShortSignature.h>
#include <sun/reflect/generics/tree/SimpleClassTypeSignature.h>
#include <sun/reflect/generics/tree/TypeArgument.h>
#include <sun/reflect/generics/tree/TypeSignature.h>
#include <sun/reflect/generics/tree/TypeVariableSignature.h>
#include <sun/reflect/generics/tree/VoidDescriptor.h>
#include <sun/reflect/generics/tree/Wildcard.h>
#include <jcpp.h>

#undef DEBUG
#undef EOI

using $ClassTypeSignatureArray = $Array<::sun::reflect::generics::tree::ClassTypeSignature>;
using $FieldTypeSignatureArray = $Array<::sun::reflect::generics::tree::FieldTypeSignature>;
using $FormalTypeParameterArray = $Array<::sun::reflect::generics::tree::FormalTypeParameter>;
using $TypeArgumentArray = $Array<::sun::reflect::generics::tree::TypeArgument>;
using $TypeSignatureArray = $Array<::sun::reflect::generics::tree::TypeSignature>;
using $AssertionError = ::java::lang::AssertionError;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $GenericSignatureFormatError = ::java::lang::reflect::GenericSignatureFormatError;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $ArrayTypeSignature = ::sun::reflect::generics::tree::ArrayTypeSignature;
using $BaseType = ::sun::reflect::generics::tree::BaseType;
using $BooleanSignature = ::sun::reflect::generics::tree::BooleanSignature;
using $BottomSignature = ::sun::reflect::generics::tree::BottomSignature;
using $ByteSignature = ::sun::reflect::generics::tree::ByteSignature;
using $CharSignature = ::sun::reflect::generics::tree::CharSignature;
using $ClassSignature = ::sun::reflect::generics::tree::ClassSignature;
using $ClassTypeSignature = ::sun::reflect::generics::tree::ClassTypeSignature;
using $DoubleSignature = ::sun::reflect::generics::tree::DoubleSignature;
using $FieldTypeSignature = ::sun::reflect::generics::tree::FieldTypeSignature;
using $FloatSignature = ::sun::reflect::generics::tree::FloatSignature;
using $FormalTypeParameter = ::sun::reflect::generics::tree::FormalTypeParameter;
using $IntSignature = ::sun::reflect::generics::tree::IntSignature;
using $LongSignature = ::sun::reflect::generics::tree::LongSignature;
using $MethodTypeSignature = ::sun::reflect::generics::tree::MethodTypeSignature;
using $ReturnType = ::sun::reflect::generics::tree::ReturnType;
using $ShortSignature = ::sun::reflect::generics::tree::ShortSignature;
using $SimpleClassTypeSignature = ::sun::reflect::generics::tree::SimpleClassTypeSignature;
using $TypeArgument = ::sun::reflect::generics::tree::TypeArgument;
using $TypeSignature = ::sun::reflect::generics::tree::TypeSignature;
using $TypeVariableSignature = ::sun::reflect::generics::tree::TypeVariableSignature;
using $VoidDescriptor = ::sun::reflect::generics::tree::VoidDescriptor;
using $Wildcard = ::sun::reflect::generics::tree::Wildcard;

namespace sun {
	namespace reflect {
		namespace generics {
			namespace parser {

$FieldInfo _SignatureParser_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SignatureParser, $assertionsDisabled)},
	{"input", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SignatureParser, input)},
	{"index", "I", nullptr, $PRIVATE, $field(SignatureParser, index)},
	{"mark", "I", nullptr, $PRIVATE, $field(SignatureParser, mark$)},
	{"EOI", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SignatureParser, EOI)},
	{"DEBUG", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SignatureParser, DEBUG)},
	{}
};

$MethodInfo _SignatureParser_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(SignatureParser, init$, void)},
	{"advance", "()V", nullptr, $PRIVATE, $method(SignatureParser, advance, void)},
	{"current", "()C", nullptr, $PRIVATE, $method(SignatureParser, current, char16_t)},
	{"error", "(Ljava/lang/String;)Ljava/lang/Error;", nullptr, $PRIVATE, $method(SignatureParser, error, $Error*, $String*)},
	{"init", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(SignatureParser, init, void, $String*)},
	{"make", "()Lsun/reflect/generics/parser/SignatureParser;", nullptr, $PUBLIC | $STATIC, $staticMethod(SignatureParser, make, SignatureParser*)},
	{"mark", "()V", nullptr, $PRIVATE, $method(SignatureParser, mark, void)},
	{"markToCurrent", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(SignatureParser, markToCurrent, $String*)},
	{"parseArrayTypeSignature", "()Lsun/reflect/generics/tree/ArrayTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseArrayTypeSignature, $ArrayTypeSignature*)},
	{"parseBaseType", "()Lsun/reflect/generics/tree/BaseType;", nullptr, $PRIVATE, $method(SignatureParser, parseBaseType, $BaseType*)},
	{"parseBounds", "()[Lsun/reflect/generics/tree/FieldTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseBounds, $FieldTypeSignatureArray*)},
	{"parseClassSig", "(Ljava/lang/String;)Lsun/reflect/generics/tree/ClassSignature;", nullptr, $PUBLIC, $virtualMethod(SignatureParser, parseClassSig, $ClassSignature*, $String*)},
	{"parseClassSignature", "()Lsun/reflect/generics/tree/ClassSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseClassSignature, $ClassSignature*)},
	{"parseClassTypeSignature", "()Lsun/reflect/generics/tree/ClassTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseClassTypeSignature, $ClassTypeSignature*)},
	{"parseClassTypeSignatureSuffix", "(Ljava/util/List;)V", "(Ljava/util/List<Lsun/reflect/generics/tree/SimpleClassTypeSignature;>;)V", $PRIVATE, $method(SignatureParser, parseClassTypeSignatureSuffix, void, $List*)},
	{"parseFieldTypeSignature", "()Lsun/reflect/generics/tree/FieldTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseFieldTypeSignature, $FieldTypeSignature*)},
	{"parseFieldTypeSignature", "(Z)Lsun/reflect/generics/tree/FieldTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseFieldTypeSignature, $FieldTypeSignature*, bool)},
	{"parseFormalParameters", "()[Lsun/reflect/generics/tree/TypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseFormalParameters, $TypeSignatureArray*)},
	{"parseFormalTypeParameter", "()Lsun/reflect/generics/tree/FormalTypeParameter;", nullptr, $PRIVATE, $method(SignatureParser, parseFormalTypeParameter, $FormalTypeParameter*)},
	{"parseFormalTypeParameters", "()[Lsun/reflect/generics/tree/FormalTypeParameter;", nullptr, $PRIVATE, $method(SignatureParser, parseFormalTypeParameters, $FormalTypeParameterArray*)},
	{"parseIdentifier", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(SignatureParser, parseIdentifier, $String*)},
	{"parseMethodSig", "(Ljava/lang/String;)Lsun/reflect/generics/tree/MethodTypeSignature;", nullptr, $PUBLIC, $virtualMethod(SignatureParser, parseMethodSig, $MethodTypeSignature*, $String*)},
	{"parseMethodTypeSignature", "()Lsun/reflect/generics/tree/MethodTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseMethodTypeSignature, $MethodTypeSignature*)},
	{"parsePackageNameAndSimpleClassTypeSignature", "()Lsun/reflect/generics/tree/SimpleClassTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parsePackageNameAndSimpleClassTypeSignature, $SimpleClassTypeSignature*)},
	{"parseReturnType", "()Lsun/reflect/generics/tree/ReturnType;", nullptr, $PRIVATE, $method(SignatureParser, parseReturnType, $ReturnType*)},
	{"parseSimpleClassTypeSignature", "(Z)Lsun/reflect/generics/tree/SimpleClassTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseSimpleClassTypeSignature, $SimpleClassTypeSignature*, bool)},
	{"parseSuperInterfaces", "()[Lsun/reflect/generics/tree/ClassTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseSuperInterfaces, $ClassTypeSignatureArray*)},
	{"parseThrowsSignature", "()Lsun/reflect/generics/tree/FieldTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseThrowsSignature, $FieldTypeSignature*)},
	{"parseTypeArgument", "()Lsun/reflect/generics/tree/TypeArgument;", nullptr, $PRIVATE, $method(SignatureParser, parseTypeArgument, $TypeArgument*)},
	{"parseTypeArguments", "()[Lsun/reflect/generics/tree/TypeArgument;", nullptr, $PRIVATE, $method(SignatureParser, parseTypeArguments, $TypeArgumentArray*)},
	{"parseTypeSig", "(Ljava/lang/String;)Lsun/reflect/generics/tree/TypeSignature;", nullptr, $PUBLIC, $virtualMethod(SignatureParser, parseTypeSig, $TypeSignature*, $String*)},
	{"parseTypeSignature", "()Lsun/reflect/generics/tree/TypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseTypeSignature, $TypeSignature*)},
	{"parseTypeVariableSignature", "()Lsun/reflect/generics/tree/TypeVariableSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseTypeVariableSignature, $TypeVariableSignature*)},
	{"parseZeroOrMoreFormalTypeParameters", "()[Lsun/reflect/generics/tree/FormalTypeParameter;", nullptr, $PRIVATE, $method(SignatureParser, parseZeroOrMoreFormalTypeParameters, $FormalTypeParameterArray*)},
	{"parseZeroOrMoreThrowsSignatures", "()[Lsun/reflect/generics/tree/FieldTypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseZeroOrMoreThrowsSignatures, $FieldTypeSignatureArray*)},
	{"parseZeroOrMoreTypeSignatures", "()[Lsun/reflect/generics/tree/TypeSignature;", nullptr, $PRIVATE, $method(SignatureParser, parseZeroOrMoreTypeSignatures, $TypeSignatureArray*)},
	{"progress", "(I)V", nullptr, $PRIVATE, $method(SignatureParser, progress, void, int32_t)},
	{"remainder", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(SignatureParser, remainder, $String*)},
	{"skipIdentifier", "()V", nullptr, $PRIVATE, $method(SignatureParser, skipIdentifier, void)},
	{}
};

$ClassInfo _SignatureParser_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.reflect.generics.parser.SignatureParser",
	"java.lang.Object",
	nullptr,
	_SignatureParser_FieldInfo_,
	_SignatureParser_MethodInfo_
};

$Object* allocate$SignatureParser($Class* clazz) {
	return $of($alloc(SignatureParser));
}

bool SignatureParser::$assertionsDisabled = false;

void SignatureParser::init$() {
}

void SignatureParser::init($String* s) {
	$set(this, input, s);
	this->mark$ = (this->index = 0);
}

char16_t SignatureParser::current() {
	if (!SignatureParser::$assertionsDisabled && !(this->index <= $nc(this->input)->length())) {
		$throwNew($AssertionError);
	}
	return this->index < $nc(this->input)->length() ? $nc(this->input)->charAt(this->index) : SignatureParser::EOI;
}

void SignatureParser::advance() {
	if (!SignatureParser::$assertionsDisabled && !(this->index <= $nc(this->input)->length())) {
		$throwNew($AssertionError);
	}
	if (this->index < $nc(this->input)->length()) {
		++this->index;
	}
}

void SignatureParser::mark() {
	this->mark$ = this->index;
}

$String* SignatureParser::remainder() {
	return $nc(this->input)->substring(this->index);
}

$String* SignatureParser::markToCurrent() {
	return $nc(this->input)->substring(this->mark$, this->index);
}

$Error* SignatureParser::error($String* errorMsg) {
	$useLocalCurrentObjectStackCache();
	return $new($GenericSignatureFormatError, $$str({"Signature Parse error: "_s, errorMsg, "\n\tRemaining input: "_s, $(remainder())}));
}

void SignatureParser::progress(int32_t startingPosition) {
	if (this->index <= startingPosition) {
		$throw($(error("Failure to make progress!"_s)));
	}
}

SignatureParser* SignatureParser::make() {
	$init(SignatureParser);
	return $new(SignatureParser);
}

$ClassSignature* SignatureParser::parseClassSig($String* s) {
	init(s);
	return parseClassSignature();
}

$MethodTypeSignature* SignatureParser::parseMethodSig($String* s) {
	init(s);
	return parseMethodTypeSignature();
}

$TypeSignature* SignatureParser::parseTypeSig($String* s) {
	init(s);
	return parseTypeSignature();
}

$ClassSignature* SignatureParser::parseClassSignature() {
	$useLocalCurrentObjectStackCache();
	if (!SignatureParser::$assertionsDisabled && !(this->index == 0)) {
		$throwNew($AssertionError);
	}
	$var($FormalTypeParameterArray, var$0, parseZeroOrMoreFormalTypeParameters());
	$var($ClassTypeSignature, var$1, parseClassTypeSignature());
	return $ClassSignature::make(var$0, var$1, $(parseSuperInterfaces()));
}

$FormalTypeParameterArray* SignatureParser::parseZeroOrMoreFormalTypeParameters() {
	if (current() == u'<') {
		return parseFormalTypeParameters();
	} else {
		return $new($FormalTypeParameterArray, 0);
	}
}

$FormalTypeParameterArray* SignatureParser::parseFormalTypeParameters() {
	$useLocalCurrentObjectStackCache();
	$var($List, ftps, $new($ArrayList, 3));
	if (!SignatureParser::$assertionsDisabled && !(current() == u'<')) {
		$throwNew($AssertionError);
	}
	if (current() != u'<') {
		$throw($(error("expected \'<\'"_s)));
	}
	advance();
	ftps->add($(parseFormalTypeParameter()));
	while (current() != u'>') {
		int32_t startingPosition = this->index;
		ftps->add($(parseFormalTypeParameter()));
		progress(startingPosition);
	}
	advance();
	return $fcast($FormalTypeParameterArray, ftps->toArray($$new($FormalTypeParameterArray, ftps->size())));
}

$FormalTypeParameter* SignatureParser::parseFormalTypeParameter() {
	$useLocalCurrentObjectStackCache();
	$var($String, id, parseIdentifier());
	$var($FieldTypeSignatureArray, bs, parseBounds());
	return $FormalTypeParameter::make(id, bs);
}

$String* SignatureParser::parseIdentifier() {
	mark();
	skipIdentifier();
	return markToCurrent();
}

void SignatureParser::skipIdentifier() {
	char16_t c = current();
	while (c != u';' && c != u'.' && c != u'/' && c != u'[' && c != u':' && c != u'>' && c != u'<' && !$Character::isWhitespace(c)) {
		advance();
		c = current();
	}
}

$FieldTypeSignature* SignatureParser::parseFieldTypeSignature() {
	return parseFieldTypeSignature(true);
}

$FieldTypeSignature* SignatureParser::parseFieldTypeSignature(bool allowArrays) {
	$useLocalCurrentObjectStackCache();
	switch (current()) {
	case u'L':
		{
			return parseClassTypeSignature();
		}
	case u'T':
		{
			return parseTypeVariableSignature();
		}
	case u'[':
		{
			if (allowArrays) {
				return parseArrayTypeSignature();
			} else {
				$throw($(error("Array signature not allowed here."_s)));
			}
		}
	default:
		{
			$throw($(error("Expected Field Type Signature"_s)));
		}
	}
}

$ClassTypeSignature* SignatureParser::parseClassTypeSignature() {
	$useLocalCurrentObjectStackCache();
	if (!SignatureParser::$assertionsDisabled && !(current() == u'L')) {
		$throwNew($AssertionError);
	}
	if (current() != u'L') {
		$throw($(error("expected a class type"_s)));
	}
	advance();
	$var($List, scts, $new($ArrayList, 5));
	scts->add($(parsePackageNameAndSimpleClassTypeSignature()));
	parseClassTypeSignatureSuffix(scts);
	if (current() != u';') {
		$throw($(error($$str({"expected \';\' got \'"_s, $$str(current()), "\'"_s}))));
	}
	advance();
	return $ClassTypeSignature::make(scts);
}

$SimpleClassTypeSignature* SignatureParser::parsePackageNameAndSimpleClassTypeSignature() {
	$useLocalCurrentObjectStackCache();
	mark();
	skipIdentifier();
	while (current() == u'/') {
		advance();
		skipIdentifier();
	}
	$var($String, id, $nc($(markToCurrent()))->replace(u'/', u'.'));
	switch (current()) {
	case u';':
		{
			return $SimpleClassTypeSignature::make(id, false, $$new($TypeArgumentArray, 0));
		}
	case u'<':
		{
			return $SimpleClassTypeSignature::make(id, false, $(parseTypeArguments()));
		}
	default:
		{
			$throw($(error($$str({"expected \'<\' or \';\' but got "_s, $$str(current())}))));
		}
	}
}

$SimpleClassTypeSignature* SignatureParser::parseSimpleClassTypeSignature(bool dollar) {
	$useLocalCurrentObjectStackCache();
	$var($String, id, parseIdentifier());
	char16_t c = current();
	switch (c) {
	case u';':
		{}
	case u'.':
		{
			return $SimpleClassTypeSignature::make(id, dollar, $$new($TypeArgumentArray, 0));
		}
	case u'<':
		{
			return $SimpleClassTypeSignature::make(id, dollar, $(parseTypeArguments()));
		}
	default:
		{
			$throw($(error($$str({"expected \'<\' or \';\' or \'.\', got \'"_s, $$str(c), "\'."_s}))));
		}
	}
}

void SignatureParser::parseClassTypeSignatureSuffix($List* scts) {
	$useLocalCurrentObjectStackCache();
	while (current() == u'.') {
		advance();
		$nc(scts)->add($(parseSimpleClassTypeSignature(true)));
	}
}

$TypeArgumentArray* SignatureParser::parseTypeArguments() {
	$useLocalCurrentObjectStackCache();
	$var($List, tas, $new($ArrayList, 3));
	if (!SignatureParser::$assertionsDisabled && !(current() == u'<')) {
		$throwNew($AssertionError);
	}
	if (current() != u'<') {
		$throw($(error("expected \'<\'"_s)));
	}
	advance();
	tas->add($(parseTypeArgument()));
	while (current() != u'>') {
		tas->add($(parseTypeArgument()));
	}
	advance();
	return $fcast($TypeArgumentArray, tas->toArray($$new($TypeArgumentArray, tas->size())));
}

$TypeArgument* SignatureParser::parseTypeArgument() {
	$useLocalCurrentObjectStackCache();
	$var($FieldTypeSignatureArray, ub, nullptr);
	$var($FieldTypeSignatureArray, lb, nullptr);
	$assign(ub, $new($FieldTypeSignatureArray, 1));
	$assign(lb, $new($FieldTypeSignatureArray, 1));
	$var($TypeArgumentArray, ta, $new($TypeArgumentArray, 0));
	char16_t c = current();
	switch (c) {
	case u'+':
		{
			{
				advance();
				ub->set(0, $(parseFieldTypeSignature()));
				lb->set(0, $($BottomSignature::make()));
				return $Wildcard::make(ub, lb);
			}
		}
	case u'*':
		{
			{
				advance();
				ub->set(0, $($SimpleClassTypeSignature::make("java.lang.Object"_s, false, ta)));
				lb->set(0, $($BottomSignature::make()));
				return $Wildcard::make(ub, lb);
			}
		}
	case u'-':
		{
			{
				advance();
				lb->set(0, $(parseFieldTypeSignature()));
				ub->set(0, $($SimpleClassTypeSignature::make("java.lang.Object"_s, false, ta)));
				return $Wildcard::make(ub, lb);
			}
		}
	default:
		{
			return parseFieldTypeSignature();
		}
	}
}

$TypeVariableSignature* SignatureParser::parseTypeVariableSignature() {
	$useLocalCurrentObjectStackCache();
	if (!SignatureParser::$assertionsDisabled && !(current() == u'T')) {
		$throwNew($AssertionError);
	}
	if (current() != u'T') {
		$throw($(error("expected a type variable usage"_s)));
	}
	advance();
	$var($TypeVariableSignature, ts, $TypeVariableSignature::make($(parseIdentifier())));
	if (current() != u';') {
		$throw($(error($$str({"; expected in signature of type variable named"_s, $($nc(ts)->getIdentifier())}))));
	}
	advance();
	return ts;
}

$ArrayTypeSignature* SignatureParser::parseArrayTypeSignature() {
	$useLocalCurrentObjectStackCache();
	if (current() != u'[') {
		$throw($(error("expected array type signature"_s)));
	}
	advance();
	return $ArrayTypeSignature::make($(parseTypeSignature()));
}

$TypeSignature* SignatureParser::parseTypeSignature() {
	switch (current()) {
	case u'B':
		{}
	case u'C':
		{}
	case u'D':
		{}
	case u'F':
		{}
	case u'I':
		{}
	case u'J':
		{}
	case u'S':
		{}
	case u'Z':
		{
			return parseBaseType();
		}
	default:
		{
			return parseFieldTypeSignature();
		}
	}
}

$BaseType* SignatureParser::parseBaseType() {
	switch (current()) {
	case u'B':
		{
			advance();
			return $ByteSignature::make();
		}
	case u'C':
		{
			advance();
			return $CharSignature::make();
		}
	case u'D':
		{
			advance();
			return $DoubleSignature::make();
		}
	case u'F':
		{
			advance();
			return $FloatSignature::make();
		}
	case u'I':
		{
			advance();
			return $IntSignature::make();
		}
	case u'J':
		{
			advance();
			return $LongSignature::make();
		}
	case u'S':
		{
			advance();
			return $ShortSignature::make();
		}
	case u'Z':
		{
			advance();
			return $BooleanSignature::make();
		}
	default:
		{
			{
				if (!SignatureParser::$assertionsDisabled) {
					$throwNew($AssertionError);
				}
				$throw($(error("expected primitive type"_s)));
			}
		}
	}
}

$FieldTypeSignatureArray* SignatureParser::parseBounds() {
	$useLocalCurrentObjectStackCache();
	$var($List, fts, $new($ArrayList, 3));
	if (current() == u':') {
		advance();
		switch (current()) {
		case u':':
			{
				break;
			}
		default:
			{
				fts->add($(parseFieldTypeSignature()));
			}
		}
		while (current() == u':') {
			advance();
			fts->add($(parseFieldTypeSignature()));
		}
	} else {
		error("Bound expected"_s);
	}
	return $fcast($FieldTypeSignatureArray, fts->toArray($$new($FieldTypeSignatureArray, fts->size())));
}

$ClassTypeSignatureArray* SignatureParser::parseSuperInterfaces() {
	$useLocalCurrentObjectStackCache();
	$var($List, cts, $new($ArrayList, 5));
	while (current() == u'L') {
		cts->add($(parseClassTypeSignature()));
	}
	return $fcast($ClassTypeSignatureArray, cts->toArray($$new($ClassTypeSignatureArray, cts->size())));
}

$MethodTypeSignature* SignatureParser::parseMethodTypeSignature() {
	$useLocalCurrentObjectStackCache();
	$var($FieldTypeSignatureArray, ets, nullptr);
	if (!SignatureParser::$assertionsDisabled && !(this->index == 0)) {
		$throwNew($AssertionError);
	}
	$var($FormalTypeParameterArray, var$0, parseZeroOrMoreFormalTypeParameters());
	$var($TypeSignatureArray, var$1, parseFormalParameters());
	$var($ReturnType, var$2, parseReturnType());
	return $MethodTypeSignature::make(var$0, var$1, var$2, $(parseZeroOrMoreThrowsSignatures()));
}

$TypeSignatureArray* SignatureParser::parseFormalParameters() {
	$useLocalCurrentObjectStackCache();
	if (current() != u'(') {
		$throw($(error("expected \'(\'"_s)));
	}
	advance();
	$var($TypeSignatureArray, pts, parseZeroOrMoreTypeSignatures());
	if (current() != u')') {
		$throw($(error("expected \')\'"_s)));
	}
	advance();
	return pts;
}

$TypeSignatureArray* SignatureParser::parseZeroOrMoreTypeSignatures() {
	$useLocalCurrentObjectStackCache();
	$var($List, ts, $new($ArrayList));
	bool stop = false;
	while (!stop) {
		switch (current()) {
		case u'B':
			{}
		case u'C':
			{}
		case u'D':
			{}
		case u'F':
			{}
		case u'I':
			{}
		case u'J':
			{}
		case u'S':
			{}
		case u'Z':
			{}
		case u'L':
			{}
		case u'T':
			{}
		case u'[':
			{
				{
					ts->add($(parseTypeSignature()));
					break;
				}
			}
		default:
			{
				stop = true;
			}
		}
	}
	return $fcast($TypeSignatureArray, ts->toArray($$new($TypeSignatureArray, ts->size())));
}

$ReturnType* SignatureParser::parseReturnType() {
	if (current() == u'V') {
		advance();
		return $VoidDescriptor::make();
	} else {
		return parseTypeSignature();
	}
}

$FieldTypeSignatureArray* SignatureParser::parseZeroOrMoreThrowsSignatures() {
	$useLocalCurrentObjectStackCache();
	$var($List, ets, $new($ArrayList, 3));
	while (current() == u'^') {
		ets->add($(parseThrowsSignature()));
	}
	return $fcast($FieldTypeSignatureArray, ets->toArray($$new($FieldTypeSignatureArray, ets->size())));
}

$FieldTypeSignature* SignatureParser::parseThrowsSignature() {
	if (!SignatureParser::$assertionsDisabled && !(current() == u'^')) {
		$throwNew($AssertionError);
	}
	if (current() != u'^') {
		$throw($(error("expected throws signature"_s)));
	}
	advance();
	return parseFieldTypeSignature(false);
}

void clinit$SignatureParser($Class* class$) {
	SignatureParser::$assertionsDisabled = !SignatureParser::class$->desiredAssertionStatus();
}

SignatureParser::SignatureParser() {
}

$Class* SignatureParser::load$($String* name, bool initialize) {
	$loadClass(SignatureParser, name, initialize, &_SignatureParser_ClassInfo_, clinit$SignatureParser, allocate$SignatureParser);
	return class$;
}

$Class* SignatureParser::class$ = nullptr;

			} // parser
		} // generics
	} // reflect
} // sun
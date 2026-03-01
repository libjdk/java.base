#include <jdk/internal/icu/impl/NormalizerImpl.h>

#include <java/io/IOException.h>
#include <java/lang/Appendable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/icu/impl/ICUBinary$Authenticate.h>
#include <jdk/internal/icu/impl/ICUBinary.h>
#include <jdk/internal/icu/impl/NormalizerImpl$Hangul.h>
#include <jdk/internal/icu/impl/NormalizerImpl$IsAcceptable.h>
#include <jdk/internal/icu/impl/NormalizerImpl$NextCCArgs.h>
#include <jdk/internal/icu/impl/NormalizerImpl$PrevArgs.h>
#include <jdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer.h>
#include <jdk/internal/icu/impl/NormalizerImpl$UTF16Plus.h>
#include <jdk/internal/icu/lang/UCharacter.h>
#include <jdk/internal/icu/text/Normalizer2.h>
#include <jdk/internal/icu/text/UTF16.h>
#include <jdk/internal/icu/util/CodePointTrie$Fast16.h>
#include <jdk/internal/icu/util/VersionInfo.h>
#include <jcpp.h>

#undef COMP_1_LAST_TUPLE
#undef COMP_1_TRAIL_LIMIT
#undef COMP_1_TRAIL_MASK
#undef COMP_1_TRAIL_SHIFT
#undef COMP_1_TRIPLE
#undef COMP_2_TRAIL_MASK
#undef COMP_2_TRAIL_SHIFT
#undef DATA_FORMAT
#undef DELTA_SHIFT
#undef DELTA_TCCC_0
#undef DELTA_TCCC_1
#undef DELTA_TCCC_GT_1
#undef DELTA_TCCC_MASK
#undef HANGUL_BASE
#undef HAS_COMP_BOUNDARY_AFTER
#undef INERT
#undef IS_ACCEPTABLE
#undef IX_COUNT
#undef IX_EXTRA_DATA_OFFSET
#undef IX_LIMIT_NO_NO
#undef IX_MIN_COMP_NO_MAYBE_CP
#undef IX_MIN_DECOMP_NO_CP
#undef IX_MIN_LCCC_CP
#undef IX_MIN_MAYBE_YES
#undef IX_MIN_NO_NO
#undef IX_MIN_NO_NO_COMP_BOUNDARY_BEFORE
#undef IX_MIN_NO_NO_COMP_NO_MAYBE_CC
#undef IX_MIN_NO_NO_EMPTY
#undef IX_MIN_YES_NO
#undef IX_MIN_YES_NO_MAPPINGS_ONLY
#undef IX_NORM_TRIE_OFFSET
#undef IX_RESERVED3_OFFSET
#undef IX_SMALL_FCD_OFFSET
#undef IX_TOTAL_SIZE
#undef JAMO_L
#undef JAMO_L_BASE
#undef JAMO_L_COUNT
#undef JAMO_T_BASE
#undef JAMO_T_COUNT
#undef JAMO_VT
#undef JAMO_V_BASE
#undef JAMO_V_COUNT
#undef MAPPING_HAS_CCC_LCCC_WORD
#undef MAPPING_HAS_RAW_MAPPING
#undef MAPPING_LENGTH_MASK
#undef MAX_DELTA
#undef MIN_CCC_LCCC_CP
#undef MIN_NORMAL_MAYBE_YES
#undef MIN_SUPPLEMENTARY_CODE_POINT
#undef MIN_YES_YES_WITH_CC
#undef OFFSET_SHIFT

using $IOException = ::java::io::IOException;
using $Appendable = ::java::lang::Appendable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $ICUBinary = ::jdk::internal::icu::impl::ICUBinary;
using $ICUBinary$Authenticate = ::jdk::internal::icu::impl::ICUBinary$Authenticate;
using $NormalizerImpl$Hangul = ::jdk::internal::icu::impl::NormalizerImpl$Hangul;
using $NormalizerImpl$IsAcceptable = ::jdk::internal::icu::impl::NormalizerImpl$IsAcceptable;
using $NormalizerImpl$NextCCArgs = ::jdk::internal::icu::impl::NormalizerImpl$NextCCArgs;
using $NormalizerImpl$PrevArgs = ::jdk::internal::icu::impl::NormalizerImpl$PrevArgs;
using $NormalizerImpl$ReorderingBuffer = ::jdk::internal::icu::impl::NormalizerImpl$ReorderingBuffer;
using $NormalizerImpl$UTF16Plus = ::jdk::internal::icu::impl::NormalizerImpl$UTF16Plus;
using $UCharacter = ::jdk::internal::icu::lang::UCharacter;
using $Normalizer2 = ::jdk::internal::icu::text::Normalizer2;
using $UTF16 = ::jdk::internal::icu::text::UTF16;
using $CodePointTrie$Fast16 = ::jdk::internal::icu::util::CodePointTrie$Fast16;

namespace jdk {
	namespace internal {
		namespace icu {
			namespace impl {

$FieldInfo _NormalizerImpl_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(NormalizerImpl, $assertionsDisabled)},
	{"IS_ACCEPTABLE", "Ljdk/internal/icu/impl/NormalizerImpl$IsAcceptable;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(NormalizerImpl, IS_ACCEPTABLE)},
	{"DATA_FORMAT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(NormalizerImpl, DATA_FORMAT)},
	{"MIN_YES_YES_WITH_CC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, MIN_YES_YES_WITH_CC)},
	{"JAMO_VT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, JAMO_VT)},
	{"MIN_NORMAL_MAYBE_YES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, MIN_NORMAL_MAYBE_YES)},
	{"JAMO_L", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, JAMO_L)},
	{"INERT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, INERT)},
	{"HAS_COMP_BOUNDARY_AFTER", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, HAS_COMP_BOUNDARY_AFTER)},
	{"OFFSET_SHIFT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, OFFSET_SHIFT)},
	{"DELTA_TCCC_0", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, DELTA_TCCC_0)},
	{"DELTA_TCCC_1", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, DELTA_TCCC_1)},
	{"DELTA_TCCC_GT_1", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, DELTA_TCCC_GT_1)},
	{"DELTA_TCCC_MASK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, DELTA_TCCC_MASK)},
	{"DELTA_SHIFT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, DELTA_SHIFT)},
	{"MAX_DELTA", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, MAX_DELTA)},
	{"IX_NORM_TRIE_OFFSET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_NORM_TRIE_OFFSET)},
	{"IX_EXTRA_DATA_OFFSET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_EXTRA_DATA_OFFSET)},
	{"IX_SMALL_FCD_OFFSET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_SMALL_FCD_OFFSET)},
	{"IX_RESERVED3_OFFSET", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_RESERVED3_OFFSET)},
	{"IX_TOTAL_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_TOTAL_SIZE)},
	{"MIN_CCC_LCCC_CP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, MIN_CCC_LCCC_CP)},
	{"IX_MIN_DECOMP_NO_CP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_DECOMP_NO_CP)},
	{"IX_MIN_COMP_NO_MAYBE_CP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_COMP_NO_MAYBE_CP)},
	{"IX_MIN_YES_NO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_YES_NO)},
	{"IX_MIN_NO_NO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_NO_NO)},
	{"IX_LIMIT_NO_NO", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_LIMIT_NO_NO)},
	{"IX_MIN_MAYBE_YES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_MAYBE_YES)},
	{"IX_MIN_YES_NO_MAPPINGS_ONLY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_YES_NO_MAPPINGS_ONLY)},
	{"IX_MIN_NO_NO_COMP_BOUNDARY_BEFORE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_NO_NO_COMP_BOUNDARY_BEFORE)},
	{"IX_MIN_NO_NO_COMP_NO_MAYBE_CC", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_NO_NO_COMP_NO_MAYBE_CC)},
	{"IX_MIN_NO_NO_EMPTY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_NO_NO_EMPTY)},
	{"IX_MIN_LCCC_CP", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_MIN_LCCC_CP)},
	{"IX_COUNT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, IX_COUNT)},
	{"MAPPING_HAS_CCC_LCCC_WORD", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, MAPPING_HAS_CCC_LCCC_WORD)},
	{"MAPPING_HAS_RAW_MAPPING", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, MAPPING_HAS_RAW_MAPPING)},
	{"MAPPING_LENGTH_MASK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, MAPPING_LENGTH_MASK)},
	{"COMP_1_LAST_TUPLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, COMP_1_LAST_TUPLE)},
	{"COMP_1_TRIPLE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, COMP_1_TRIPLE)},
	{"COMP_1_TRAIL_LIMIT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, COMP_1_TRAIL_LIMIT)},
	{"COMP_1_TRAIL_MASK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, COMP_1_TRAIL_MASK)},
	{"COMP_1_TRAIL_SHIFT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, COMP_1_TRAIL_SHIFT)},
	{"COMP_2_TRAIL_SHIFT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, COMP_2_TRAIL_SHIFT)},
	{"COMP_2_TRAIL_MASK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(NormalizerImpl, COMP_2_TRAIL_MASK)},
	{"dataVersion", "Ljdk/internal/icu/util/VersionInfo;", nullptr, $PRIVATE, $field(NormalizerImpl, dataVersion)},
	{"minDecompNoCP", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minDecompNoCP)},
	{"minCompNoMaybeCP", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minCompNoMaybeCP)},
	{"minLcccCP", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minLcccCP)},
	{"minYesNo", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minYesNo)},
	{"minYesNoMappingsOnly", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minYesNoMappingsOnly)},
	{"minNoNo", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minNoNo)},
	{"minNoNoCompBoundaryBefore", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minNoNoCompBoundaryBefore)},
	{"minNoNoCompNoMaybeCC", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minNoNoCompNoMaybeCC)},
	{"minNoNoEmpty", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minNoNoEmpty)},
	{"limitNoNo", "I", nullptr, $PRIVATE, $field(NormalizerImpl, limitNoNo)},
	{"centerNoNoDelta", "I", nullptr, $PRIVATE, $field(NormalizerImpl, centerNoNoDelta)},
	{"minMaybeYes", "I", nullptr, $PRIVATE, $field(NormalizerImpl, minMaybeYes)},
	{"normTrie", "Ljdk/internal/icu/util/CodePointTrie$Fast16;", nullptr, $PRIVATE, $field(NormalizerImpl, normTrie)},
	{"maybeYesCompositions", "Ljava/lang/String;", nullptr, $PRIVATE, $field(NormalizerImpl, maybeYesCompositions)},
	{"extraData", "Ljava/lang/String;", nullptr, $PRIVATE, $field(NormalizerImpl, extraData)},
	{"smallFCD", "[B", nullptr, $PRIVATE, $field(NormalizerImpl, smallFCD)},
	{}
};

$MethodInfo _NormalizerImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(NormalizerImpl, init$, void)},
	{"canonicalDecomposeWithSingleQuotation", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerImpl, canonicalDecomposeWithSingleQuotation, $String*, $String*)},
	{"combine", "(Ljava/lang/String;II)I", nullptr, $PRIVATE | $STATIC, $staticMethod(NormalizerImpl, combine, int32_t, $String*, int32_t, int32_t)},
	{"compose", "(Ljava/lang/CharSequence;IIZZLjdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;)Z", nullptr, $PUBLIC, $method(NormalizerImpl, compose, bool, $CharSequence*, int32_t, int32_t, bool, bool, $NormalizerImpl$ReorderingBuffer*)},
	{"composeAndAppend", "(Ljava/lang/CharSequence;ZZLjdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;)V", nullptr, $PUBLIC, $method(NormalizerImpl, composeAndAppend, void, $CharSequence*, bool, bool, $NormalizerImpl$ReorderingBuffer*)},
	{"composeQuickCheck", "(Ljava/lang/CharSequence;IIZZ)I", nullptr, $PUBLIC, $method(NormalizerImpl, composeQuickCheck, int32_t, $CharSequence*, int32_t, int32_t, bool, bool)},
	{"decompose", "(Ljava/lang/CharSequence;IILjava/lang/StringBuilder;I)V", nullptr, $PUBLIC, $method(NormalizerImpl, decompose, void, $CharSequence*, int32_t, int32_t, $StringBuilder*, int32_t)},
	{"decompose", "(Ljava/lang/CharSequence;IILjdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;)I", nullptr, $PUBLIC, $method(NormalizerImpl, decompose, int32_t, $CharSequence*, int32_t, int32_t, $NormalizerImpl$ReorderingBuffer*)},
	{"decompose", "(IILjdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;)V", nullptr, $PRIVATE, $method(NormalizerImpl, decompose, void, int32_t, int32_t, $NormalizerImpl$ReorderingBuffer*)},
	{"decomposeAndAppend", "(Ljava/lang/CharSequence;ZLjdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;)V", nullptr, $PUBLIC, $method(NormalizerImpl, decomposeAndAppend, void, $CharSequence*, bool, $NormalizerImpl$ReorderingBuffer*)},
	{"decomposeShort", "(Ljava/lang/CharSequence;IIZZLjdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;)I", nullptr, $PRIVATE, $method(NormalizerImpl, decomposeShort, int32_t, $CharSequence*, int32_t, int32_t, bool, bool, $NormalizerImpl$ReorderingBuffer*)},
	{"findNextCompBoundary", "(Ljava/lang/CharSequence;IIZ)I", nullptr, $PRIVATE, $method(NormalizerImpl, findNextCompBoundary, int32_t, $CharSequence*, int32_t, int32_t, bool)},
	{"findNextFCDBoundary", "(Ljava/lang/CharSequence;II)I", nullptr, $PRIVATE, $method(NormalizerImpl, findNextFCDBoundary, int32_t, $CharSequence*, int32_t, int32_t)},
	{"findPreviousCompBoundary", "(Ljava/lang/CharSequence;IZ)I", nullptr, $PRIVATE, $method(NormalizerImpl, findPreviousCompBoundary, int32_t, $CharSequence*, int32_t, bool)},
	{"getCC", "(I)I", nullptr, $PUBLIC, $method(NormalizerImpl, getCC, int32_t, int32_t)},
	{"getCCFromNoNo", "(I)I", nullptr, $PRIVATE, $method(NormalizerImpl, getCCFromNoNo, int32_t, int32_t)},
	{"getCCFromNormalYesOrMaybe", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerImpl, getCCFromNormalYesOrMaybe, int32_t, int32_t)},
	{"getCCFromYesOrMaybe", "(I)I", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerImpl, getCCFromYesOrMaybe, int32_t, int32_t)},
	{"getCCFromYesOrMaybeCP", "(I)I", nullptr, $PUBLIC, $method(NormalizerImpl, getCCFromYesOrMaybeCP, int32_t, int32_t)},
	{"getCompositionsListForComposite", "(I)I", nullptr, $PRIVATE, $method(NormalizerImpl, getCompositionsListForComposite, int32_t, int32_t)},
	{"getCompositionsListForDecompYes", "(I)I", nullptr, $PRIVATE, $method(NormalizerImpl, getCompositionsListForDecompYes, int32_t, int32_t)},
	{"getDecompose", "([I[Ljava/lang/String;)I", nullptr, $PUBLIC | $STATIC, $staticMethod(NormalizerImpl, getDecompose, int32_t, $ints*, $StringArray*)},
	{"getDecomposition", "(I)Ljava/lang/String;", nullptr, $PUBLIC, $method(NormalizerImpl, getDecomposition, $String*, int32_t)},
	{"getFCD16", "(I)I", nullptr, $PUBLIC, $method(NormalizerImpl, getFCD16, int32_t, int32_t)},
	{"getFCD16FromNormData", "(I)I", nullptr, $PUBLIC, $method(NormalizerImpl, getFCD16FromNormData, int32_t, int32_t)},
	{"getNextCC", "(Ljdk/internal/icu/impl/NormalizerImpl$NextCCArgs;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(NormalizerImpl, getNextCC, int32_t, $NormalizerImpl$NextCCArgs*)},
	{"getNorm16", "(I)I", nullptr, $PUBLIC, $method(NormalizerImpl, getNorm16, int32_t, int32_t)},
	{"getPrevCC", "(Ljdk/internal/icu/impl/NormalizerImpl$PrevArgs;)I", nullptr, $PRIVATE | $STATIC, $staticMethod(NormalizerImpl, getPrevCC, int32_t, $NormalizerImpl$PrevArgs*)},
	{"getPreviousTrailCC", "(Ljava/lang/CharSequence;II)I", nullptr, $PRIVATE, $method(NormalizerImpl, getPreviousTrailCC, int32_t, $CharSequence*, int32_t, int32_t)},
	{"getRawNorm16", "(I)I", nullptr, $PUBLIC, $method(NormalizerImpl, getRawNorm16, int32_t, int32_t)},
	{"getTrailCCFromCompYesAndZeroCC", "(I)I", nullptr, 0, $method(NormalizerImpl, getTrailCCFromCompYesAndZeroCC, int32_t, int32_t)},
	{"hangulLVT", "()I", nullptr, $PRIVATE, $method(NormalizerImpl, hangulLVT, int32_t)},
	{"hasCompBoundaryAfter", "(IZ)Z", nullptr, $PUBLIC, $method(NormalizerImpl, hasCompBoundaryAfter, bool, int32_t, bool)},
	{"hasCompBoundaryAfter", "(Ljava/lang/CharSequence;IIZ)Z", nullptr, $PRIVATE, $method(NormalizerImpl, hasCompBoundaryAfter, bool, $CharSequence*, int32_t, int32_t, bool)},
	{"hasCompBoundaryBefore", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, hasCompBoundaryBefore, bool, int32_t)},
	{"hasCompBoundaryBefore", "(II)Z", nullptr, $PRIVATE, $method(NormalizerImpl, hasCompBoundaryBefore, bool, int32_t, int32_t)},
	{"hasCompBoundaryBefore", "(Ljava/lang/CharSequence;II)Z", nullptr, $PRIVATE, $method(NormalizerImpl, hasCompBoundaryBefore, bool, $CharSequence*, int32_t, int32_t)},
	{"hasDecompBoundaryAfter", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, hasDecompBoundaryAfter, bool, int32_t)},
	{"hasDecompBoundaryBefore", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, hasDecompBoundaryBefore, bool, int32_t)},
	{"insertOrdered", "([CIIICCI)I", nullptr, $PRIVATE | $STATIC, $staticMethod(NormalizerImpl, insertOrdered, int32_t, $chars*, int32_t, int32_t, int32_t, char16_t, char16_t, int32_t)},
	{"isAlgorithmicNoNo", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, isAlgorithmicNoNo, bool, int32_t)},
	{"isCompNo", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, isCompNo, bool, int32_t)},
	{"isCompYesAndZeroCC", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, isCompYesAndZeroCC, bool, int32_t)},
	{"isDecompInert", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, isDecompInert, bool, int32_t)},
	{"isDecompNoAlgorithmic", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, isDecompNoAlgorithmic, bool, int32_t)},
	{"isDecompYes", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, isDecompYes, bool, int32_t)},
	{"isDecompYesAndZeroCC", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, isDecompYesAndZeroCC, bool, int32_t)},
	{"isHangulLV", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, isHangulLV, bool, int32_t)},
	{"isHangulLVT", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, isHangulLVT, bool, int32_t)},
	{"isInert", "(I)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(NormalizerImpl, isInert, bool, int32_t)},
	{"isJamoVT", "(I)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(NormalizerImpl, isJamoVT, bool, int32_t)},
	{"isMaybe", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, isMaybe, bool, int32_t)},
	{"isMaybeOrNonZeroCC", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, isMaybeOrNonZeroCC, bool, int32_t)},
	{"isMostDecompYesAndZeroCC", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, isMostDecompYesAndZeroCC, bool, int32_t)},
	{"isTrailCC01ForCompBoundaryAfter", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, isTrailCC01ForCompBoundaryAfter, bool, int32_t)},
	{"load", "(Ljava/nio/ByteBuffer;)Ljdk/internal/icu/impl/NormalizerImpl;", nullptr, $PUBLIC, $method(NormalizerImpl, load, NormalizerImpl*, $ByteBuffer*)},
	{"load", "(Ljava/lang/String;)Ljdk/internal/icu/impl/NormalizerImpl;", nullptr, $PUBLIC, $method(NormalizerImpl, load, NormalizerImpl*, $String*)},
	{"makeFCD", "(Ljava/lang/CharSequence;IILjdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;)I", nullptr, $PUBLIC, $method(NormalizerImpl, makeFCD, int32_t, $CharSequence*, int32_t, int32_t, $NormalizerImpl$ReorderingBuffer*)},
	{"mapAlgorithmic", "(II)I", nullptr, $PRIVATE, $method(NormalizerImpl, mapAlgorithmic, int32_t, int32_t, int32_t)},
	{"mergeOrdered", "([CII[CII)I", nullptr, $PRIVATE | $STATIC, $staticMethod(NormalizerImpl, mergeOrdered, int32_t, $chars*, int32_t, int32_t, $chars*, int32_t, int32_t)},
	{"needSingleQuotation", "(C)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(NormalizerImpl, needSingleQuotation, bool, char16_t)},
	{"norm16HasCompBoundaryAfter", "(IZ)Z", nullptr, $PRIVATE, $method(NormalizerImpl, norm16HasCompBoundaryAfter, bool, int32_t, bool)},
	{"norm16HasCompBoundaryBefore", "(I)Z", nullptr, $PRIVATE, $method(NormalizerImpl, norm16HasCompBoundaryBefore, bool, int32_t)},
	{"norm16HasDecompBoundaryAfter", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, norm16HasDecompBoundaryAfter, bool, int32_t)},
	{"norm16HasDecompBoundaryBefore", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, norm16HasDecompBoundaryBefore, bool, int32_t)},
	{"recompose", "(Ljdk/internal/icu/impl/NormalizerImpl$ReorderingBuffer;IZ)V", nullptr, $PRIVATE, $method(NormalizerImpl, recompose, void, $NormalizerImpl$ReorderingBuffer*, int32_t, bool)},
	{"singleLeadMightHaveNonZeroFCD16", "(I)Z", nullptr, $PUBLIC, $method(NormalizerImpl, singleLeadMightHaveNonZeroFCD16, bool, int32_t)},
	{}
};

$InnerClassInfo _NormalizerImpl_InnerClassesInfo_[] = {
	{"jdk.internal.icu.impl.NormalizerImpl$NextCCArgs", "jdk.internal.icu.impl.NormalizerImpl", "NextCCArgs", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.impl.NormalizerImpl$PrevArgs", "jdk.internal.icu.impl.NormalizerImpl", "PrevArgs", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.impl.NormalizerImpl$IsAcceptable", "jdk.internal.icu.impl.NormalizerImpl", "IsAcceptable", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.icu.impl.NormalizerImpl$UTF16Plus", "jdk.internal.icu.impl.NormalizerImpl", "UTF16Plus", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.icu.impl.NormalizerImpl$ReorderingBuffer", "jdk.internal.icu.impl.NormalizerImpl", "ReorderingBuffer", $PUBLIC | $STATIC | $FINAL},
	{"jdk.internal.icu.impl.NormalizerImpl$Hangul", "jdk.internal.icu.impl.NormalizerImpl", "Hangul", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _NormalizerImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.icu.impl.NormalizerImpl",
	"java.lang.Object",
	nullptr,
	_NormalizerImpl_FieldInfo_,
	_NormalizerImpl_MethodInfo_,
	nullptr,
	nullptr,
	_NormalizerImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.icu.impl.NormalizerImpl$NextCCArgs,jdk.internal.icu.impl.NormalizerImpl$PrevArgs,jdk.internal.icu.impl.NormalizerImpl$IsAcceptable,jdk.internal.icu.impl.NormalizerImpl$UTF16Plus,jdk.internal.icu.impl.NormalizerImpl$ReorderingBuffer,jdk.internal.icu.impl.NormalizerImpl$Hangul"
};

$Object* allocate$NormalizerImpl($Class* clazz) {
	return $of($alloc(NormalizerImpl));
}

bool NormalizerImpl::$assertionsDisabled = false;
$NormalizerImpl$IsAcceptable* NormalizerImpl::IS_ACCEPTABLE = nullptr;

void NormalizerImpl::init$() {
}

NormalizerImpl* NormalizerImpl::load($ByteBuffer* bytes) {
	try {
		$set(this, dataVersion, $ICUBinary::readHeaderAndDataVersion(bytes, NormalizerImpl::DATA_FORMAT, NormalizerImpl::IS_ACCEPTABLE));
		int32_t indexesLength = $nc(bytes)->getInt() / 4;
		if (indexesLength <= NormalizerImpl::IX_MIN_LCCC_CP) {
			$throwNew($InternalError, "Normalizer2 data: not enough indexes"_s);
		}
		$var($ints, inIndexes, $new($ints, indexesLength));
		inIndexes->set(0, indexesLength * 4);
		for (int32_t i = 1; i < indexesLength; ++i) {
			inIndexes->set(i, bytes->getInt());
		}
		this->minDecompNoCP = inIndexes->get(NormalizerImpl::IX_MIN_DECOMP_NO_CP);
		this->minCompNoMaybeCP = inIndexes->get(NormalizerImpl::IX_MIN_COMP_NO_MAYBE_CP);
		this->minLcccCP = inIndexes->get(NormalizerImpl::IX_MIN_LCCC_CP);
		this->minYesNo = inIndexes->get(NormalizerImpl::IX_MIN_YES_NO);
		this->minYesNoMappingsOnly = inIndexes->get(NormalizerImpl::IX_MIN_YES_NO_MAPPINGS_ONLY);
		this->minNoNo = inIndexes->get(NormalizerImpl::IX_MIN_NO_NO);
		this->minNoNoCompBoundaryBefore = inIndexes->get(NormalizerImpl::IX_MIN_NO_NO_COMP_BOUNDARY_BEFORE);
		this->minNoNoCompNoMaybeCC = inIndexes->get(NormalizerImpl::IX_MIN_NO_NO_COMP_NO_MAYBE_CC);
		this->minNoNoEmpty = inIndexes->get(NormalizerImpl::IX_MIN_NO_NO_EMPTY);
		this->limitNoNo = inIndexes->get(NormalizerImpl::IX_LIMIT_NO_NO);
		this->minMaybeYes = inIndexes->get(NormalizerImpl::IX_MIN_MAYBE_YES);
		if (!NormalizerImpl::$assertionsDisabled && !(((int32_t)(this->minMaybeYes & (uint32_t)7)) == 0)) {
			$throwNew($AssertionError);
		}
		this->centerNoNoDelta = ($sr(this->minMaybeYes, NormalizerImpl::DELTA_SHIFT)) - NormalizerImpl::MAX_DELTA - 1;
		int32_t offset = inIndexes->get(NormalizerImpl::IX_NORM_TRIE_OFFSET);
		int32_t nextOffset = inIndexes->get(NormalizerImpl::IX_EXTRA_DATA_OFFSET);
		int32_t triePosition = bytes->position();
		$set(this, normTrie, $CodePointTrie$Fast16::fromBinary(bytes));
		int32_t trieLength = bytes->position() - triePosition;
		if (trieLength > (nextOffset - offset)) {
			$throwNew($InternalError, "Normalizer2 data: not enough bytes for normTrie"_s);
		}
		$ICUBinary::skipBytes(bytes, (nextOffset - offset) - trieLength);
		offset = nextOffset;
		nextOffset = inIndexes->get(NormalizerImpl::IX_SMALL_FCD_OFFSET);
		int32_t numChars = (nextOffset - offset) / 2;
		if (numChars != 0) {
			$set(this, maybeYesCompositions, $ICUBinary::getString(bytes, numChars, 0));
			$set(this, extraData, $nc(this->maybeYesCompositions)->substring($sr(NormalizerImpl::MIN_NORMAL_MAYBE_YES - this->minMaybeYes, NormalizerImpl::OFFSET_SHIFT)));
		}
		offset = nextOffset;
		$set(this, smallFCD, $new($bytes, 256));
		bytes->get(this->smallFCD);
		return this;
	} catch ($IOException& e) {
		$throwNew($InternalError, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

NormalizerImpl* NormalizerImpl::load($String* name) {
	return load($($ICUBinary::getRequiredData(name)));
}

int32_t NormalizerImpl::getNorm16(int32_t c) {
	return $NormalizerImpl$UTF16Plus::isLeadSurrogate(c) ? NormalizerImpl::INERT : $nc(this->normTrie)->get(c);
}

int32_t NormalizerImpl::getRawNorm16(int32_t c) {
	return $nc(this->normTrie)->get(c);
}

bool NormalizerImpl::isAlgorithmicNoNo(int32_t norm16) {
	return this->limitNoNo <= norm16 && norm16 < this->minMaybeYes;
}

bool NormalizerImpl::isCompNo(int32_t norm16) {
	return this->minNoNo <= norm16 && norm16 < this->minMaybeYes;
}

bool NormalizerImpl::isDecompYes(int32_t norm16) {
	return norm16 < this->minYesNo || this->minMaybeYes <= norm16;
}

int32_t NormalizerImpl::getCC(int32_t norm16) {
	if (norm16 >= NormalizerImpl::MIN_NORMAL_MAYBE_YES) {
		return getCCFromNormalYesOrMaybe(norm16);
	}
	if (norm16 < this->minNoNo || this->limitNoNo <= norm16) {
		return 0;
	}
	return getCCFromNoNo(norm16);
}

int32_t NormalizerImpl::getCCFromNormalYesOrMaybe(int32_t norm16) {
	$init(NormalizerImpl);
	return (int32_t)(($sr(norm16, NormalizerImpl::OFFSET_SHIFT)) & (uint32_t)255);
}

int32_t NormalizerImpl::getCCFromYesOrMaybe(int32_t norm16) {
	$init(NormalizerImpl);
	return norm16 >= NormalizerImpl::MIN_NORMAL_MAYBE_YES ? getCCFromNormalYesOrMaybe(norm16) : 0;
}

int32_t NormalizerImpl::getCCFromYesOrMaybeCP(int32_t c) {
	if (c < this->minCompNoMaybeCP) {
		return 0;
	}
	return getCCFromYesOrMaybe(getNorm16(c));
}

int32_t NormalizerImpl::getFCD16(int32_t c) {
	if (c < this->minDecompNoCP) {
		return 0;
	} else if (c <= 0x0000FFFF) {
		if (!singleLeadMightHaveNonZeroFCD16(c)) {
			return 0;
		}
	}
	return getFCD16FromNormData(c);
}

bool NormalizerImpl::singleLeadMightHaveNonZeroFCD16(int32_t lead) {
	int8_t bits = $nc(this->smallFCD)->get(lead >> 8);
	if (bits == 0) {
		return false;
	}
	return ((int32_t)(($sr((int32_t)bits, (int32_t)((lead >> 5) & (uint32_t)7))) & (uint32_t)1)) != 0;
}

int32_t NormalizerImpl::getFCD16FromNormData(int32_t c) {
	int32_t norm16 = getNorm16(c);
	if (norm16 >= this->limitNoNo) {
		if (norm16 >= NormalizerImpl::MIN_NORMAL_MAYBE_YES) {
			norm16 = getCCFromNormalYesOrMaybe(norm16);
			return norm16 | (norm16 << 8);
		} else if (norm16 >= this->minMaybeYes) {
			return 0;
		} else {
			int32_t deltaTrailCC = (int32_t)(norm16 & (uint32_t)NormalizerImpl::DELTA_TCCC_MASK);
			if (deltaTrailCC <= NormalizerImpl::DELTA_TCCC_1) {
				return $sr(deltaTrailCC, NormalizerImpl::OFFSET_SHIFT);
			}
			c = mapAlgorithmic(c, norm16);
			norm16 = getRawNorm16(c);
		}
	}
	if (norm16 <= this->minYesNo || isHangulLVT(norm16)) {
		return 0;
	}
	int32_t mapping = $sr(norm16, NormalizerImpl::OFFSET_SHIFT);
	int32_t firstUnit = $nc(this->extraData)->charAt(mapping);
	int32_t fcd16 = firstUnit >> 8;
	if (((int32_t)(firstUnit & (uint32_t)NormalizerImpl::MAPPING_HAS_CCC_LCCC_WORD)) != 0) {
		fcd16 |= (int32_t)($nc(this->extraData)->charAt(mapping - 1) & (uint32_t)0x0000FF00);
	}
	return fcd16;
}

$String* NormalizerImpl::getDecomposition(int32_t c) {
	int32_t norm16 = 0;
	if (c < this->minDecompNoCP || isMaybeOrNonZeroCC(norm16 = getNorm16(c))) {
		return nullptr;
	}
	int32_t decomp = -1;
	if (isDecompNoAlgorithmic(norm16)) {
		decomp = (c = mapAlgorithmic(c, norm16));
		norm16 = getRawNorm16(c);
	}
	if (norm16 < this->minYesNo) {
		if (decomp < 0) {
			return nullptr;
		} else {
			return $UTF16::valueOf(decomp);
		}
	} else {
		bool var$1 = isHangulLV(norm16);
		if (var$1 || isHangulLVT(norm16)) {
			$var($StringBuilder, buffer, $new($StringBuilder));
			$NormalizerImpl$Hangul::decompose(c, buffer);
			return buffer->toString();
		}
	}
	int32_t mapping = $sr(norm16, NormalizerImpl::OFFSET_SHIFT);
	int32_t length = (int32_t)($nc(this->extraData)->charAt(mapping++) & (uint32_t)NormalizerImpl::MAPPING_LENGTH_MASK);
	return $nc(this->extraData)->substring(mapping, mapping + length);
}

void NormalizerImpl::decompose($CharSequence* s, int32_t src, int32_t limit, $StringBuilder* dest, int32_t destLengthEstimate) {
	if (destLengthEstimate < 0) {
		destLengthEstimate = limit - src;
	}
	$nc(dest)->setLength(0);
	$var($NormalizerImpl$ReorderingBuffer, buffer, $new($NormalizerImpl$ReorderingBuffer, this, dest, destLengthEstimate));
	decompose(s, src, limit, buffer);
}

int32_t NormalizerImpl::decompose($CharSequence* s, int32_t src, int32_t limit, $NormalizerImpl$ReorderingBuffer* buffer) {
	int32_t minNoCP = this->minDecompNoCP;
	int32_t prevSrc = 0;
	int32_t c = 0;
	int32_t norm16 = 0;
	int32_t prevBoundary = src;
	int32_t prevCC = 0;
	for (;;) {
		for (prevSrc = src; src != limit;) {
			bool var$0 = (c = $nc(s)->charAt(src)) < minNoCP;
			if (var$0 || isMostDecompYesAndZeroCC(norm16 = $nc(this->normTrie)->bmpGet(c))) {
				++src;
			} else if (!$NormalizerImpl$UTF16Plus::isLeadSurrogate(c)) {
				break;
			} else {
				char16_t c2 = 0;
				if ((src + 1) != limit && $Character::isLowSurrogate(c2 = $nc(s)->charAt(src + 1))) {
					c = $Character::toCodePoint((char16_t)c, c2);
					norm16 = $nc(this->normTrie)->suppGet(c);
					if (isMostDecompYesAndZeroCC(norm16)) {
						src += 2;
					} else {
						break;
					}
				} else {
					++src;
				}
			}
		}
		if (src != prevSrc) {
			if (buffer != nullptr) {
				buffer->flushAndAppendZeroCC(s, prevSrc, src);
			} else {
				prevCC = 0;
				prevBoundary = src;
			}
		}
		if (src == limit) {
			break;
		}
		src += $Character::charCount(c);
		if (buffer != nullptr) {
			decompose(c, norm16, buffer);
		} else {
			if (isDecompYes(norm16)) {
				int32_t cc = getCCFromYesOrMaybe(norm16);
				if (prevCC <= cc || cc == 0) {
					prevCC = cc;
					if (cc <= 1) {
						prevBoundary = src;
					}
					continue;
				}
			}
			return prevBoundary;
		}
	}
	return src;
}

void NormalizerImpl::decomposeAndAppend($CharSequence* s, bool doDecompose, $NormalizerImpl$ReorderingBuffer* buffer) {
	int32_t limit = $nc(s)->length();
	if (limit == 0) {
		return;
	}
	if (doDecompose) {
		decompose(s, 0, limit, buffer);
		return;
	}
	int32_t c = $Character::codePointAt(s, 0);
	int32_t src = 0;
	int32_t firstCC = 0;
	int32_t prevCC = 0;
	int32_t cc = 0;
	firstCC = (prevCC = (cc = getCC(getNorm16(c))));
	while (cc != 0) {
		prevCC = cc;
		src += $Character::charCount(c);
		if (src >= limit) {
			break;
		}
		c = $Character::codePointAt(s, src);
		cc = getCC(getNorm16(c));
	}
	$nc(buffer)->append(s, 0, src, false, firstCC, prevCC);
	buffer->append(s, src, limit);
}

bool NormalizerImpl::compose($CharSequence* s, int32_t src, int32_t limit, bool onlyContiguous, bool doCompose, $NormalizerImpl$ReorderingBuffer* buffer) {
	int32_t prevBoundary = src;
	int32_t minNoMaybeCP = this->minCompNoMaybeCP;
	for (;;) {
		int32_t prevSrc = 0;
		int32_t c = 0;
		int32_t norm16 = 0;
		for (;;) {
			if (src == limit) {
				if (prevBoundary != limit && doCompose) {
					$nc(buffer)->append(s, prevBoundary, limit);
				}
				return true;
			}
			bool var$0 = (c = $nc(s)->charAt(src)) < minNoMaybeCP;
			if (var$0 || isCompYesAndZeroCC(norm16 = $nc(this->normTrie)->bmpGet(c))) {
				++src;
			} else {
				prevSrc = src++;
				if (!$NormalizerImpl$UTF16Plus::isLeadSurrogate(c)) {
					break;
				} else {
					char16_t c2 = 0;
					if (src != limit && $Character::isLowSurrogate(c2 = $nc(s)->charAt(src))) {
						++src;
						c = $Character::toCodePoint((char16_t)c, c2);
						norm16 = $nc(this->normTrie)->suppGet(c);
						if (!isCompYesAndZeroCC(norm16)) {
							break;
						}
					}
				}
			}
		}
		if (!isMaybeOrNonZeroCC(norm16)) {
			if (!doCompose) {
				return false;
			}
			if (isDecompNoAlgorithmic(norm16)) {
				bool var$1 = norm16HasCompBoundaryAfter(norm16, onlyContiguous);
				if (var$1 || hasCompBoundaryBefore(s, src, limit)) {
					if (prevBoundary != prevSrc) {
						$nc(buffer)->append(s, prevBoundary, prevSrc);
					}
					$nc(buffer)->append(mapAlgorithmic(c, norm16), 0);
					prevBoundary = src;
					continue;
				}
			} else if (norm16 < this->minNoNoCompBoundaryBefore) {
				bool var$2 = norm16HasCompBoundaryAfter(norm16, onlyContiguous);
				if (var$2 || hasCompBoundaryBefore(s, src, limit)) {
					if (prevBoundary != prevSrc) {
						$nc(buffer)->append(s, prevBoundary, prevSrc);
					}
					int32_t mapping = $sr(norm16, NormalizerImpl::OFFSET_SHIFT);
					int32_t length = (int32_t)($nc(this->extraData)->charAt(mapping++) & (uint32_t)NormalizerImpl::MAPPING_LENGTH_MASK);
					$nc(buffer)->append(this->extraData, mapping, mapping + length);
					prevBoundary = src;
					continue;
				}
			} else if (norm16 >= this->minNoNoEmpty) {
				bool var$3 = hasCompBoundaryBefore(s, src, limit);
				if (var$3 || hasCompBoundaryAfter(s, prevBoundary, prevSrc, onlyContiguous)) {
					if (prevBoundary != prevSrc) {
						$nc(buffer)->append(s, prevBoundary, prevSrc);
					}
					prevBoundary = src;
					continue;
				}
			}
		} else if (isJamoVT(norm16) && prevBoundary != prevSrc) {
			char16_t prev = $nc(s)->charAt(prevSrc - 1);
			if (c < $NormalizerImpl$Hangul::JAMO_T_BASE) {
				char16_t l = (char16_t)(prev - $NormalizerImpl$Hangul::JAMO_L_BASE);
				if (l < $NormalizerImpl$Hangul::JAMO_L_COUNT) {
					if (!doCompose) {
						return false;
					}
					int32_t t = 0;
					bool var$4 = src != limit && 0 < (t = (s->charAt(src) - $NormalizerImpl$Hangul::JAMO_T_BASE));
					if (var$4 && t < $NormalizerImpl$Hangul::JAMO_T_COUNT) {
						++src;
					} else if (hasCompBoundaryBefore(s, src, limit)) {
						t = 0;
					} else {
						t = -1;
					}
					if (t >= 0) {
						int32_t syllable = $NormalizerImpl$Hangul::HANGUL_BASE + (l * $NormalizerImpl$Hangul::JAMO_V_COUNT + (c - $NormalizerImpl$Hangul::JAMO_V_BASE)) * $NormalizerImpl$Hangul::JAMO_T_COUNT + t;
						--prevSrc;
						if (prevBoundary != prevSrc) {
							$nc(buffer)->append(s, prevBoundary, prevSrc);
						}
						$nc(buffer)->append((char16_t)syllable);
						prevBoundary = src;
						continue;
					}
				}
			} else if ($NormalizerImpl$Hangul::isHangulLV(prev)) {
				if (!doCompose) {
					return false;
				}
				int32_t syllable = prev + c - $NormalizerImpl$Hangul::JAMO_T_BASE;
				--prevSrc;
				if (prevBoundary != prevSrc) {
					$nc(buffer)->append(s, prevBoundary, prevSrc);
				}
				$nc(buffer)->append((char16_t)syllable);
				prevBoundary = src;
				continue;
			}
		} else if (norm16 > NormalizerImpl::JAMO_VT) {
			int32_t cc = getCCFromNormalYesOrMaybe(norm16);
			if (onlyContiguous && getPreviousTrailCC(s, prevBoundary, prevSrc) > cc) {
				if (!doCompose) {
					return false;
				}
			} else {
				int32_t n16 = 0;
				for (;;) {
					if (src == limit) {
						if (doCompose) {
							$nc(buffer)->append(s, prevBoundary, limit);
						}
						return true;
					}
					int32_t prevCC = cc;
					c = $Character::codePointAt(s, src);
					n16 = $nc(this->normTrie)->get(c);
					if (n16 >= NormalizerImpl::MIN_YES_YES_WITH_CC) {
						cc = getCCFromNormalYesOrMaybe(n16);
						if (prevCC > cc) {
							if (!doCompose) {
								return false;
							}
							break;
						}
					} else {
						break;
					}
					src += $Character::charCount(c);
				}
				if (norm16HasCompBoundaryBefore(n16)) {
					if (isCompYesAndZeroCC(n16)) {
						src += $Character::charCount(c);
					}
					continue;
				}
			}
		}
		if (prevBoundary != prevSrc && !norm16HasCompBoundaryBefore(norm16)) {
			c = $Character::codePointBefore(s, prevSrc);
			norm16 = $nc(this->normTrie)->get(c);
			if (!norm16HasCompBoundaryAfter(norm16, onlyContiguous)) {
				prevSrc -= $Character::charCount(c);
			}
		}
		if (doCompose && prevBoundary != prevSrc) {
			$nc(buffer)->append(s, prevBoundary, prevSrc);
		}
		int32_t recomposeStartIndex = $nc(buffer)->length();
		decomposeShort(s, prevSrc, src, false, onlyContiguous, buffer);
		src = decomposeShort(s, src, limit, true, onlyContiguous, buffer);
		recompose(buffer, recomposeStartIndex, onlyContiguous);
		if (!doCompose) {
			if (!buffer->equals(s, prevSrc, src)) {
				return false;
			}
			buffer->remove();
		}
		prevBoundary = src;
	}
}

int32_t NormalizerImpl::composeQuickCheck($CharSequence* s, int32_t src, int32_t limit, bool onlyContiguous, bool doSpan) {
	int32_t qcResult = 0;
	int32_t prevBoundary = src;
	int32_t minNoMaybeCP = this->minCompNoMaybeCP;
	for (;;) {
		int32_t prevSrc = 0;
		int32_t c = 0;
		int32_t norm16 = 0;
		for (;;) {
			if (src == limit) {
				return (src << 1) | qcResult;
			}
			bool var$0 = (c = $nc(s)->charAt(src)) < minNoMaybeCP;
			if (var$0 || isCompYesAndZeroCC(norm16 = $nc(this->normTrie)->bmpGet(c))) {
				++src;
			} else {
				prevSrc = src++;
				if (!$NormalizerImpl$UTF16Plus::isLeadSurrogate(c)) {
					break;
				} else {
					char16_t c2 = 0;
					if (src != limit && $Character::isLowSurrogate(c2 = $nc(s)->charAt(src))) {
						++src;
						c = $Character::toCodePoint((char16_t)c, c2);
						norm16 = $nc(this->normTrie)->suppGet(c);
						if (!isCompYesAndZeroCC(norm16)) {
							break;
						}
					}
				}
			}
		}
		int32_t prevNorm16 = NormalizerImpl::INERT;
		if (prevBoundary != prevSrc) {
			prevBoundary = prevSrc;
			if (!norm16HasCompBoundaryBefore(norm16)) {
				c = $Character::codePointBefore(s, prevSrc);
				int32_t n16 = getNorm16(c);
				if (!norm16HasCompBoundaryAfter(n16, onlyContiguous)) {
					prevBoundary -= $Character::charCount(c);
					prevNorm16 = n16;
				}
			}
		}
		if (isMaybeOrNonZeroCC(norm16)) {
			int32_t cc = getCCFromYesOrMaybe(norm16);
			if (onlyContiguous && cc != 0 && getTrailCCFromCompYesAndZeroCC(prevNorm16) > cc) {
			} else {
				for (;;) {
					if (norm16 < NormalizerImpl::MIN_YES_YES_WITH_CC) {
						if (!doSpan) {
							qcResult = 1;
						} else {
							return prevBoundary << 1;
						}
					}
					if (src == limit) {
						return (src << 1) | qcResult;
					}
					int32_t prevCC = cc;
					c = $Character::codePointAt(s, src);
					norm16 = getNorm16(c);
					if (isMaybeOrNonZeroCC(norm16)) {
						cc = getCCFromYesOrMaybe(norm16);
						if (!(prevCC <= cc || cc == 0)) {
							break;
						}
					} else {
						break;
					}
					src += $Character::charCount(c);
				}
				if (isCompYesAndZeroCC(norm16)) {
					prevBoundary = src;
					src += $Character::charCount(c);
					continue;
				}
			}
		}
		return prevBoundary << 1;
	}
}

void NormalizerImpl::composeAndAppend($CharSequence* s, bool doCompose, bool onlyContiguous, $NormalizerImpl$ReorderingBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	int32_t src = 0;
	int32_t limit = $nc(s)->length();
	if (!$nc(buffer)->isEmpty()) {
		int32_t firstStarterInSrc = findNextCompBoundary(s, 0, limit, onlyContiguous);
		if (0 != firstStarterInSrc) {
			$var($CharSequence, var$0, static_cast<$CharSequence*>(buffer->getStringBuilder()));
			int32_t lastStarterInDest = findPreviousCompBoundary(var$0, buffer->length(), onlyContiguous);
			$var($StringBuilder, middle, $new($StringBuilder, (buffer->length() - lastStarterInDest) + firstStarterInSrc + 16));
			$var($CharSequence, var$1, static_cast<$CharSequence*>(buffer->getStringBuilder()));
			int32_t var$2 = lastStarterInDest;
			middle->append(var$1, var$2, buffer->length());
			buffer->removeSuffix(buffer->length() - lastStarterInDest);
			middle->append(s, 0, firstStarterInSrc);
			compose(middle, 0, middle->length(), onlyContiguous, true, buffer);
			src = firstStarterInSrc;
		}
	}
	if (doCompose) {
		compose(s, src, limit, onlyContiguous, true, buffer);
	} else {
		$nc(buffer)->append(s, src, limit);
	}
}

int32_t NormalizerImpl::makeFCD($CharSequence* s, int32_t src, int32_t limit, $NormalizerImpl$ReorderingBuffer* buffer) {
	int32_t prevBoundary = src;
	int32_t prevSrc = 0;
	int32_t c = 0;
	int32_t prevFCD16 = 0;
	int32_t fcd16 = 0;
	for (;;) {
		for (prevSrc = src; src != limit;) {
			if ((c = $nc(s)->charAt(src)) < this->minLcccCP) {
				prevFCD16 = ~c;
				++src;
			} else if (!singleLeadMightHaveNonZeroFCD16(c)) {
				prevFCD16 = 0;
				++src;
			} else {
				if ($NormalizerImpl$UTF16Plus::isLeadSurrogate(c)) {
					char16_t c2 = 0;
					if ((src + 1) != limit && $Character::isLowSurrogate(c2 = s->charAt(src + 1))) {
						c = $Character::toCodePoint((char16_t)c, c2);
					}
				}
				if ((fcd16 = getFCD16FromNormData(c)) <= 255) {
					prevFCD16 = fcd16;
					src += $Character::charCount(c);
				} else {
					break;
				}
			}
		}
		if (src != prevSrc) {
			if (src == limit) {
				if (buffer != nullptr) {
					buffer->flushAndAppendZeroCC(s, prevSrc, src);
				}
				break;
			}
			prevBoundary = src;
			if (prevFCD16 < 0) {
				int32_t prev = ~prevFCD16;
				if (prev < this->minDecompNoCP) {
					prevFCD16 = 0;
				} else {
					prevFCD16 = getFCD16FromNormData(prev);
					if (prevFCD16 > 1) {
						--prevBoundary;
					}
				}
			} else {
				int32_t p = src - 1;
				bool var$0 = $Character::isLowSurrogate($nc(s)->charAt(p)) && prevSrc < p;
				if (var$0 && $Character::isHighSurrogate($nc(s)->charAt(p - 1))) {
					--p;
					char16_t var$1 = $nc(s)->charAt(p);
					prevFCD16 = getFCD16FromNormData($Character::toCodePoint(var$1, s->charAt(p + 1)));
				}
				if (prevFCD16 > 1) {
					prevBoundary = p;
				}
			}
			if (buffer != nullptr) {
				buffer->flushAndAppendZeroCC(s, prevSrc, prevBoundary);
				buffer->append(s, prevBoundary, src);
			}
			prevSrc = src;
		} else if (src == limit) {
			break;
		}
		src += $Character::charCount(c);
		if (((int32_t)(prevFCD16 & (uint32_t)255)) <= (fcd16 >> 8)) {
			if (((int32_t)(fcd16 & (uint32_t)255)) <= 1) {
				prevBoundary = src;
			}
			if (buffer != nullptr) {
				buffer->appendZeroCC(c);
			}
			prevFCD16 = fcd16;
			continue;
		} else if (buffer == nullptr) {
			return prevBoundary;
		} else {
			$nc(buffer)->removeSuffix(prevSrc - prevBoundary);
			src = findNextFCDBoundary(s, src, limit);
			decomposeShort(s, prevBoundary, src, false, false, buffer);
			prevBoundary = src;
			prevFCD16 = 0;
		}
	}
	return src;
}

bool NormalizerImpl::hasDecompBoundaryBefore(int32_t c) {
	bool var$0 = c < this->minLcccCP || (c <= 0x0000FFFF && !singleLeadMightHaveNonZeroFCD16(c));
	return var$0 || norm16HasDecompBoundaryBefore(getNorm16(c));
}

bool NormalizerImpl::norm16HasDecompBoundaryBefore(int32_t norm16) {
	if (norm16 < this->minNoNoCompNoMaybeCC) {
		return true;
	}
	if (norm16 >= this->limitNoNo) {
		return norm16 <= NormalizerImpl::MIN_NORMAL_MAYBE_YES || norm16 == NormalizerImpl::JAMO_VT;
	}
	int32_t mapping = $sr(norm16, NormalizerImpl::OFFSET_SHIFT);
	int32_t firstUnit = $nc(this->extraData)->charAt(mapping);
	return ((int32_t)(firstUnit & (uint32_t)NormalizerImpl::MAPPING_HAS_CCC_LCCC_WORD)) == 0 || ((int32_t)($nc(this->extraData)->charAt(mapping - 1) & (uint32_t)0x0000FF00)) == 0;
}

bool NormalizerImpl::hasDecompBoundaryAfter(int32_t c) {
	if (c < this->minDecompNoCP) {
		return true;
	}
	if (c <= 0x0000FFFF && !singleLeadMightHaveNonZeroFCD16(c)) {
		return true;
	}
	return norm16HasDecompBoundaryAfter(getNorm16(c));
}

bool NormalizerImpl::norm16HasDecompBoundaryAfter(int32_t norm16) {
	if (norm16 <= this->minYesNo || isHangulLVT(norm16)) {
		return true;
	}
	if (norm16 >= this->limitNoNo) {
		if (isMaybeOrNonZeroCC(norm16)) {
			return norm16 <= NormalizerImpl::MIN_NORMAL_MAYBE_YES || norm16 == NormalizerImpl::JAMO_VT;
		}
		return ((int32_t)(norm16 & (uint32_t)NormalizerImpl::DELTA_TCCC_MASK)) <= NormalizerImpl::DELTA_TCCC_1;
	}
	int32_t mapping = $sr(norm16, NormalizerImpl::OFFSET_SHIFT);
	int32_t firstUnit = $nc(this->extraData)->charAt(mapping);
	if (firstUnit > 511) {
		return false;
	}
	if (firstUnit <= 255) {
		return true;
	}
	return ((int32_t)(firstUnit & (uint32_t)NormalizerImpl::MAPPING_HAS_CCC_LCCC_WORD)) == 0 || ((int32_t)($nc(this->extraData)->charAt(mapping - 1) & (uint32_t)0x0000FF00)) == 0;
}

bool NormalizerImpl::isDecompInert(int32_t c) {
	return isDecompYesAndZeroCC(getNorm16(c));
}

bool NormalizerImpl::hasCompBoundaryBefore(int32_t c) {
	return c < this->minCompNoMaybeCP || norm16HasCompBoundaryBefore(getNorm16(c));
}

bool NormalizerImpl::hasCompBoundaryAfter(int32_t c, bool onlyContiguous) {
	return norm16HasCompBoundaryAfter(getNorm16(c), onlyContiguous);
}

bool NormalizerImpl::isMaybe(int32_t norm16) {
	return this->minMaybeYes <= norm16 && norm16 <= NormalizerImpl::JAMO_VT;
}

bool NormalizerImpl::isMaybeOrNonZeroCC(int32_t norm16) {
	return norm16 >= this->minMaybeYes;
}

bool NormalizerImpl::isInert(int32_t norm16) {
	$init(NormalizerImpl);
	return norm16 == NormalizerImpl::INERT;
}

bool NormalizerImpl::isJamoVT(int32_t norm16) {
	$init(NormalizerImpl);
	return norm16 == NormalizerImpl::JAMO_VT;
}

int32_t NormalizerImpl::hangulLVT() {
	return this->minYesNoMappingsOnly | NormalizerImpl::HAS_COMP_BOUNDARY_AFTER;
}

bool NormalizerImpl::isHangulLV(int32_t norm16) {
	return norm16 == this->minYesNo;
}

bool NormalizerImpl::isHangulLVT(int32_t norm16) {
	return norm16 == hangulLVT();
}

bool NormalizerImpl::isCompYesAndZeroCC(int32_t norm16) {
	return norm16 < this->minNoNo;
}

bool NormalizerImpl::isDecompYesAndZeroCC(int32_t norm16) {
	return norm16 < this->minYesNo || norm16 == NormalizerImpl::JAMO_VT || (this->minMaybeYes <= norm16 && norm16 <= NormalizerImpl::MIN_NORMAL_MAYBE_YES);
}

bool NormalizerImpl::isMostDecompYesAndZeroCC(int32_t norm16) {
	return norm16 < this->minYesNo || norm16 == NormalizerImpl::MIN_NORMAL_MAYBE_YES || norm16 == NormalizerImpl::JAMO_VT;
}

bool NormalizerImpl::isDecompNoAlgorithmic(int32_t norm16) {
	return norm16 >= this->limitNoNo;
}

int32_t NormalizerImpl::getCCFromNoNo(int32_t norm16) {
	int32_t mapping = $sr(norm16, NormalizerImpl::OFFSET_SHIFT);
	if (((int32_t)($nc(this->extraData)->charAt(mapping) & (uint32_t)NormalizerImpl::MAPPING_HAS_CCC_LCCC_WORD)) != 0) {
		return (int32_t)($nc(this->extraData)->charAt(mapping - 1) & (uint32_t)255);
	} else {
		return 0;
	}
}

int32_t NormalizerImpl::getTrailCCFromCompYesAndZeroCC(int32_t norm16) {
	if (norm16 <= this->minYesNo) {
		return 0;
	} else {
		return $nc(this->extraData)->charAt($sr(norm16, NormalizerImpl::OFFSET_SHIFT)) >> 8;
	}
}

int32_t NormalizerImpl::mapAlgorithmic(int32_t c, int32_t norm16) {
	return c + ($sr(norm16, NormalizerImpl::DELTA_SHIFT)) - this->centerNoNoDelta;
}

int32_t NormalizerImpl::getCompositionsListForDecompYes(int32_t norm16) {
	if (norm16 < NormalizerImpl::JAMO_L || NormalizerImpl::MIN_NORMAL_MAYBE_YES <= norm16) {
		return -1;
	} else {
		if ((norm16 -= this->minMaybeYes) < 0) {
			norm16 += NormalizerImpl::MIN_NORMAL_MAYBE_YES;
		}
		return $sr(norm16, NormalizerImpl::OFFSET_SHIFT);
	}
}

int32_t NormalizerImpl::getCompositionsListForComposite(int32_t norm16) {
	int32_t list = $sr((NormalizerImpl::MIN_NORMAL_MAYBE_YES - this->minMaybeYes) + norm16, NormalizerImpl::OFFSET_SHIFT);
	int32_t firstUnit = $nc(this->maybeYesCompositions)->charAt(list);
	return list + 1 + ((int32_t)(firstUnit & (uint32_t)NormalizerImpl::MAPPING_LENGTH_MASK));
}

int32_t NormalizerImpl::decomposeShort($CharSequence* s, int32_t src, int32_t limit, bool stopAtCompBoundary, bool onlyContiguous, $NormalizerImpl$ReorderingBuffer* buffer) {
	while (src < limit) {
		int32_t c = $Character::codePointAt(s, src);
		if (stopAtCompBoundary && c < this->minCompNoMaybeCP) {
			return src;
		}
		int32_t norm16 = getNorm16(c);
		if (stopAtCompBoundary && norm16HasCompBoundaryBefore(norm16)) {
			return src;
		}
		src += $Character::charCount(c);
		decompose(c, norm16, buffer);
		if (stopAtCompBoundary && norm16HasCompBoundaryAfter(norm16, onlyContiguous)) {
			return src;
		}
	}
	return src;
}

void NormalizerImpl::decompose(int32_t c, int32_t norm16, $NormalizerImpl$ReorderingBuffer* buffer) {
	if (norm16 >= this->limitNoNo) {
		if (isMaybeOrNonZeroCC(norm16)) {
			$nc(buffer)->append(c, getCCFromYesOrMaybe(norm16));
			return;
		}
		c = mapAlgorithmic(c, norm16);
		norm16 = getRawNorm16(c);
	}
	if (norm16 < this->minYesNo) {
		$nc(buffer)->append(c, 0);
	} else {
		bool var$1 = isHangulLV(norm16);
		if (var$1 || isHangulLVT(norm16)) {
			$NormalizerImpl$Hangul::decompose(c, buffer);
		} else {
			int32_t mapping = $sr(norm16, NormalizerImpl::OFFSET_SHIFT);
			int32_t firstUnit = $nc(this->extraData)->charAt(mapping);
			int32_t length = (int32_t)(firstUnit & (uint32_t)NormalizerImpl::MAPPING_LENGTH_MASK);
			int32_t leadCC = 0;
			int32_t trailCC = 0;
			trailCC = firstUnit >> 8;
			if (((int32_t)(firstUnit & (uint32_t)NormalizerImpl::MAPPING_HAS_CCC_LCCC_WORD)) != 0) {
				leadCC = $nc(this->extraData)->charAt(mapping - 1) >> 8;
			} else {
				leadCC = 0;
			}
			++mapping;
			$nc(buffer)->append(this->extraData, mapping, mapping + length, true, leadCC, trailCC);
		}
	}
}

int32_t NormalizerImpl::combine($String* compositions, int32_t list, int32_t trail) {
	$init(NormalizerImpl);
	int32_t key1 = 0;
	int32_t firstUnit = 0;
	if (trail < NormalizerImpl::COMP_1_TRAIL_LIMIT) {
		key1 = (trail << 1);
		while (key1 > (firstUnit = $nc(compositions)->charAt(list))) {
			list += 2 + ((int32_t)(firstUnit & (uint32_t)NormalizerImpl::COMP_1_TRIPLE));
		}
		if (key1 == ((int32_t)(firstUnit & (uint32_t)NormalizerImpl::COMP_1_TRAIL_MASK))) {
			if (((int32_t)(firstUnit & (uint32_t)NormalizerImpl::COMP_1_TRIPLE)) != 0) {
				int32_t var$0 = ($nc(compositions)->charAt(list + 1) << 16);
				return var$0 | compositions->charAt(list + 2);
			} else {
				return $nc(compositions)->charAt(list + 1);
			}
		}
	} else {
		key1 = NormalizerImpl::COMP_1_TRAIL_LIMIT + ((int32_t)(($sr(trail, NormalizerImpl::COMP_1_TRAIL_SHIFT)) & (uint32_t)~NormalizerImpl::COMP_1_TRIPLE));
		int32_t key2 = (int32_t)(($sl(trail, NormalizerImpl::COMP_2_TRAIL_SHIFT)) & (uint32_t)0x0000FFFF);
		int32_t secondUnit = 0;
		for (;;) {
			if (key1 > (firstUnit = $nc(compositions)->charAt(list))) {
				list += 2 + ((int32_t)(firstUnit & (uint32_t)NormalizerImpl::COMP_1_TRIPLE));
			} else if (key1 == ((int32_t)(firstUnit & (uint32_t)NormalizerImpl::COMP_1_TRAIL_MASK))) {
				if (key2 > (secondUnit = compositions->charAt(list + 1))) {
					if (((int32_t)(firstUnit & (uint32_t)NormalizerImpl::COMP_1_LAST_TUPLE)) != 0) {
						break;
					} else {
						list += 3;
					}
				} else if (key2 == ((int32_t)(secondUnit & (uint32_t)NormalizerImpl::COMP_2_TRAIL_MASK))) {
					return (((int32_t)(secondUnit & (uint32_t)~NormalizerImpl::COMP_2_TRAIL_MASK)) << 16) | compositions->charAt(list + 2);
				} else {
					break;
				}
			} else {
				break;
			}
		}
	}
	return -1;
}

void NormalizerImpl::recompose($NormalizerImpl$ReorderingBuffer* buffer, int32_t recomposeStartIndex, bool onlyContiguous) {
	$var($StringBuilder, sb, $nc(buffer)->getStringBuilder());
	int32_t p = recomposeStartIndex;
	if (p == $nc(sb)->length()) {
		return;
	}
	int32_t starter = 0;
	int32_t pRemove = 0;
	int32_t compositionsList = 0;
	int32_t c = 0;
	int32_t compositeAndFwd = 0;
	int32_t norm16 = 0;
	int32_t cc = 0;
	int32_t prevCC = 0;
	bool starterIsSupplementary = false;
	compositionsList = -1;
	starter = -1;
	starterIsSupplementary = false;
	prevCC = 0;
	for (;;) {
		c = $nc(sb)->codePointAt(p);
		p += $Character::charCount(c);
		norm16 = getNorm16(c);
		cc = getCCFromYesOrMaybe(norm16);
		if (isMaybe(norm16) && compositionsList >= 0 && (prevCC < cc || prevCC == 0)) {
			if (isJamoVT(norm16)) {
				if (c < $NormalizerImpl$Hangul::JAMO_T_BASE) {
					char16_t prev = (char16_t)(sb->charAt(starter) - $NormalizerImpl$Hangul::JAMO_L_BASE);
					if (prev < $NormalizerImpl$Hangul::JAMO_L_COUNT) {
						pRemove = p - 1;
						char16_t syllable = (char16_t)($NormalizerImpl$Hangul::HANGUL_BASE + (prev * $NormalizerImpl$Hangul::JAMO_V_COUNT + (c - $NormalizerImpl$Hangul::JAMO_V_BASE)) * $NormalizerImpl$Hangul::JAMO_T_COUNT);
						char16_t t = 0;
						bool var$0 = p != sb->length();
						if (var$0 && (t = (char16_t)(sb->charAt(p) - $NormalizerImpl$Hangul::JAMO_T_BASE)) < $NormalizerImpl$Hangul::JAMO_T_COUNT) {
							++p;
							syllable += t;
						}
						sb->setCharAt(starter, syllable);
						sb->delete$(pRemove, p);
						p = pRemove;
					}
				}
				if (p == sb->length()) {
					break;
				}
				compositionsList = -1;
				continue;
			} else if ((compositeAndFwd = combine(this->maybeYesCompositions, compositionsList, c)) >= 0) {
				int32_t composite = compositeAndFwd >> 1;
				pRemove = p - $Character::charCount(c);
				sb->delete$(pRemove, p);
				p = pRemove;
				if (starterIsSupplementary) {
					if (composite > 0x0000FFFF) {
						sb->setCharAt(starter, $UTF16::getLeadSurrogate(composite));
						sb->setCharAt(starter + 1, $UTF16::getTrailSurrogate(composite));
					} else {
						sb->setCharAt(starter, (char16_t)c);
						sb->deleteCharAt(starter + 1);
						starterIsSupplementary = false;
						--p;
					}
				} else if (composite > 0x0000FFFF) {
					starterIsSupplementary = true;
					sb->setCharAt(starter, $UTF16::getLeadSurrogate(composite));
					sb->insert(starter + 1, $UTF16::getTrailSurrogate(composite));
					++p;
				} else {
					sb->setCharAt(starter, (char16_t)composite);
				}
				if (p == sb->length()) {
					break;
				}
				if (((int32_t)(compositeAndFwd & (uint32_t)1)) != 0) {
					compositionsList = getCompositionsListForComposite(getRawNorm16(composite));
				} else {
					compositionsList = -1;
				}
				continue;
			}
		}
		prevCC = cc;
		if (p == sb->length()) {
			break;
		}
		if (cc == 0) {
			if ((compositionsList = getCompositionsListForDecompYes(norm16)) >= 0) {
				if (c <= 0x0000FFFF) {
					starterIsSupplementary = false;
					starter = p - 1;
				} else {
					starterIsSupplementary = true;
					starter = p - 2;
				}
			}
		} else if (onlyContiguous) {
			compositionsList = -1;
		}
	}
	buffer->flush();
}

bool NormalizerImpl::hasCompBoundaryBefore(int32_t c, int32_t norm16) {
	return c < this->minCompNoMaybeCP || norm16HasCompBoundaryBefore(norm16);
}

bool NormalizerImpl::norm16HasCompBoundaryBefore(int32_t norm16) {
	return norm16 < this->minNoNoCompNoMaybeCC || isAlgorithmicNoNo(norm16);
}

bool NormalizerImpl::hasCompBoundaryBefore($CharSequence* s, int32_t src, int32_t limit) {
	return src == limit || hasCompBoundaryBefore($Character::codePointAt(s, src));
}

bool NormalizerImpl::norm16HasCompBoundaryAfter(int32_t norm16, bool onlyContiguous) {
	return ((int32_t)(norm16 & (uint32_t)NormalizerImpl::HAS_COMP_BOUNDARY_AFTER)) != 0 && (!onlyContiguous || isTrailCC01ForCompBoundaryAfter(norm16));
}

bool NormalizerImpl::hasCompBoundaryAfter($CharSequence* s, int32_t start, int32_t p, bool onlyContiguous) {
	return start == p || hasCompBoundaryAfter($Character::codePointBefore(s, p), onlyContiguous);
}

bool NormalizerImpl::isTrailCC01ForCompBoundaryAfter(int32_t norm16) {
	bool var$0 = isInert(norm16);
	return var$0 || (isDecompNoAlgorithmic(norm16) ? ((int32_t)(norm16 & (uint32_t)NormalizerImpl::DELTA_TCCC_MASK)) <= NormalizerImpl::DELTA_TCCC_1 : $nc(this->extraData)->charAt($sr(norm16, NormalizerImpl::OFFSET_SHIFT)) <= 511);
}

int32_t NormalizerImpl::findPreviousCompBoundary($CharSequence* s, int32_t p, bool onlyContiguous) {
	while (p > 0) {
		int32_t c = $Character::codePointBefore(s, p);
		int32_t norm16 = getNorm16(c);
		if (norm16HasCompBoundaryAfter(norm16, onlyContiguous)) {
			break;
		}
		p -= $Character::charCount(c);
		if (hasCompBoundaryBefore(c, norm16)) {
			break;
		}
	}
	return p;
}

int32_t NormalizerImpl::findNextCompBoundary($CharSequence* s, int32_t p, int32_t limit, bool onlyContiguous) {
	while (p < limit) {
		int32_t c = $Character::codePointAt(s, p);
		int32_t norm16 = $nc(this->normTrie)->get(c);
		if (hasCompBoundaryBefore(c, norm16)) {
			break;
		}
		p += $Character::charCount(c);
		if (norm16HasCompBoundaryAfter(norm16, onlyContiguous)) {
			break;
		}
	}
	return p;
}

int32_t NormalizerImpl::findNextFCDBoundary($CharSequence* s, int32_t p, int32_t limit) {
	while (p < limit) {
		int32_t c = $Character::codePointAt(s, p);
		int32_t norm16 = 0;
		if (c < this->minLcccCP || norm16HasDecompBoundaryBefore(norm16 = getNorm16(c))) {
			break;
		}
		p += $Character::charCount(c);
		if (norm16HasDecompBoundaryAfter(norm16)) {
			break;
		}
	}
	return p;
}

int32_t NormalizerImpl::getDecompose($ints* chars, $StringArray* decomps) {
	$init(NormalizerImpl);
	$useLocalCurrentObjectStackCache();
	$var($Normalizer2, impl, $Normalizer2::getNFDInstance());
	int32_t length = 0;
	int32_t norm16 = 0;
	int32_t ch = -1;
	int32_t i = 0;
	while (++ch < 0x0002FA1E) {
		if (ch == 12543) {
			ch = 0x0000F900;
		} else if (ch == 0x000115BC) {
			ch = 0x0001D15E;
		} else if (ch == 0x0001D1C1) {
			ch = 0x0002F800;
		}
		$var($String, s, $nc(impl)->getDecomposition(ch));
		if (s != nullptr && i < $nc(chars)->length) {
			chars->set(i, ch);
			$nc(decomps)->set(i++, s);
		}
	}
	return i;
}

bool NormalizerImpl::needSingleQuotation(char16_t c) {
	$init(NormalizerImpl);
	return (c >= 9 && c <= 13) || (c >= 32 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126);
}

$String* NormalizerImpl::canonicalDecomposeWithSingleQuotation($String* string) {
	$init(NormalizerImpl);
	$useLocalCurrentObjectStackCache();
	$var($Normalizer2, impl, $Normalizer2::getNFDInstance());
	$var($chars, src, $nc(string)->toCharArray());
	int32_t srcIndex = 0;
	int32_t srcLimit = src->length;
	$var($chars, dest, $new($chars, src->length * 3));
	int32_t destIndex = 0;
	int32_t destLimit = dest->length;
	int32_t prevSrc = 0;
	$var($String, norm, nullptr);
	int32_t reorderStartIndex = 0;
	int32_t length = 0;
	char16_t c1 = 0;
	char16_t c2 = 0;
	int32_t cp = 0;
	int32_t minNoMaybe = 192;
	int32_t cc = 0;
	int32_t prevCC = 0;
	int32_t trailCC = 0;
	$var($chars, p, nullptr);
	int32_t pStart = 0;
	reorderStartIndex = 0;
	prevCC = 0;
	$assign(norm, nullptr);
	cp = 0;
	pStart = 0;
	cc = (trailCC = -1);
	c1 = (char16_t)0;
	for (;;) {
		prevSrc = srcIndex;
		while (srcIndex != srcLimit && ((c1 = src->get(srcIndex)) < minNoMaybe || ($assign(norm, $nc(impl)->getDecomposition(cp = string->codePointAt(srcIndex)))) == nullptr || (c1 >= (char16_t)0xAC00 && c1 <= (char16_t)0xD7A3))) {
			prevCC = 0;
			srcIndex += (cp < 0x00010000) ? 1 : 2;
		}
		if (srcIndex != prevSrc) {
			length = srcIndex - prevSrc;
			if ((destIndex + length) <= destLimit) {
				$System::arraycopy(src, prevSrc, dest, destIndex, length);
			}
			destIndex += length;
			reorderStartIndex = destIndex;
		}
		if (srcIndex == srcLimit) {
			break;
		}
		srcIndex += (cp < 0x00010000) ? 1 : 2;
		if (cp < $Character::MIN_SUPPLEMENTARY_CODE_POINT) {
			c2 = (char16_t)0;
			length = 1;
			bool var$0 = $Character::isHighSurrogate(c1);
			if (var$0 || $Character::isLowSurrogate(c1)) {
				$assign(norm, nullptr);
			}
		} else {
			length = 2;
			c2 = src->get(srcIndex - 1);
		}
		if (norm == nullptr) {
			cc = (trailCC = $UCharacter::getCombiningClass(cp));
			$assign(p, nullptr);
			pStart = -1;
		} else {
			pStart = 0;
			$assign(p, $nc(norm)->toCharArray());
			length = p->length;
			int32_t cpNum = norm->codePointCount(0, length);
			cc = $UCharacter::getCombiningClass(norm->codePointAt(0));
			trailCC = $UCharacter::getCombiningClass(norm->codePointAt(cpNum - 1));
			if (length == 1) {
				c1 = p->get(pStart);
				c2 = (char16_t)0;
				$assign(p, nullptr);
				pStart = -1;
			}
		}
		if ((destIndex + length * 3) >= destLimit) {
			$var($chars, tmpBuf, $new($chars, destLimit * 2));
			$System::arraycopy(dest, 0, tmpBuf, 0, destIndex);
			$assign(dest, tmpBuf);
			destLimit = dest->length;
		}
		{
			int32_t reorderSplit = destIndex;
			if (p == nullptr) {
				if (needSingleQuotation(c1)) {
					dest->set(destIndex++, u'\'');
					dest->set(destIndex++, c1);
					dest->set(destIndex++, u'\'');
					trailCC = 0;
				} else if (cc != 0 && cc < prevCC) {
					destIndex += length;
					trailCC = insertOrdered(dest, reorderStartIndex, reorderSplit, destIndex, c1, c2, cc);
				} else {
					dest->set(destIndex++, c1);
					if (c2 != 0) {
						dest->set(destIndex++, c2);
					}
				}
			} else if (needSingleQuotation($nc(p)->get(pStart))) {
				dest->set(destIndex++, u'\'');
				dest->set(destIndex++, $nc(p)->get(pStart++));
				dest->set(destIndex++, u'\'');
				--length;
				do {
					dest->set(destIndex++, p->get(pStart++));
				} while (--length > 0);
			} else if (cc != 0 && cc < prevCC) {
				destIndex += length;
				trailCC = mergeOrdered(dest, reorderStartIndex, reorderSplit, p, pStart, pStart + length);
			} else {
				do {
					dest->set(destIndex++, $nc(p)->get(pStart++));
				} while (--length > 0);
			}
		}
		prevCC = trailCC;
		if (prevCC == 0) {
			reorderStartIndex = destIndex;
		}
	}
	return $new($String, dest, 0, destIndex);
}

int32_t NormalizerImpl::insertOrdered($chars* source, int32_t start, int32_t current, int32_t p, char16_t c1, char16_t c2, int32_t cc) {
	$init(NormalizerImpl);
	int32_t back = 0;
	int32_t preBack = 0;
	int32_t r = 0;
	int32_t prevCC = 0;
	int32_t trailCC = cc;
	if (start < current && cc != 0) {
		preBack = (back = current);
		$var($NormalizerImpl$PrevArgs, prevArgs, $new($NormalizerImpl$PrevArgs));
		prevArgs->current = current;
		prevArgs->start = start;
		$set(prevArgs, src, source);
		prevArgs->c1 = c1;
		prevArgs->c2 = c2;
		prevCC = getPrevCC(prevArgs);
		preBack = prevArgs->current;
		if (cc < prevCC) {
			trailCC = prevCC;
			back = preBack;
			while (start < preBack) {
				prevCC = getPrevCC(prevArgs);
				preBack = prevArgs->current;
				if (cc >= prevCC) {
					break;
				}
				back = preBack;
			}
			r = p;
			do {
				$nc(source)->set(--r, source->get(--current));
			} while (back != current);
		}
	}
	$nc(source)->set(current, c1);
	if (c2 != 0) {
		source->set(current + 1, c2);
	}
	return trailCC;
}

int32_t NormalizerImpl::mergeOrdered($chars* source, int32_t start, int32_t current, $chars* data, int32_t next, int32_t limit) {
	$init(NormalizerImpl);
	$useLocalCurrentObjectStackCache();
	int32_t r = 0;
	int32_t cc = 0;
	int32_t trailCC = 0;
	bool adjacent = false;
	adjacent = current == next;
	$var($NormalizerImpl$NextCCArgs, ncArgs, $new($NormalizerImpl$NextCCArgs));
	$set(ncArgs, source, data);
	ncArgs->next = next;
	ncArgs->limit = limit;
	if (start != current) {
		while (ncArgs->next < ncArgs->limit) {
			cc = getNextCC(ncArgs);
			if (cc == 0) {
				trailCC = 0;
				if (adjacent) {
					current = ncArgs->next;
				} else {
					$nc(data)->set(current++, ncArgs->c1);
					if (ncArgs->c2 != 0) {
						data->set(current++, ncArgs->c2);
					}
				}
				break;
			} else {
				r = current + (ncArgs->c2 == 0 ? 1 : 2);
				trailCC = insertOrdered(source, start, current, r, ncArgs->c1, ncArgs->c2, cc);
				current = r;
			}
		}
	}
	if (ncArgs->next == ncArgs->limit) {
		return trailCC;
	} else {
		if (!adjacent) {
			do {
				$nc(source)->set(current++, $nc(data)->get(ncArgs->next++));
			} while (ncArgs->next != ncArgs->limit);
			ncArgs->limit = current;
		}
		$var($NormalizerImpl$PrevArgs, prevArgs, $new($NormalizerImpl$PrevArgs));
		$set(prevArgs, src, data);
		prevArgs->start = start;
		prevArgs->current = ncArgs->limit;
		return getPrevCC(prevArgs);
	}
}

int32_t NormalizerImpl::getNextCC($NormalizerImpl$NextCCArgs* args) {
	$init(NormalizerImpl);
	$nc(args)->c1 = $nc(args->source)->get(args->next++);
	args->c2 = (char16_t)0;
	if ($UTF16::isTrailSurrogate(args->c1)) {
		return 0;
	} else if (!$UTF16::isLeadSurrogate(args->c1)) {
		return $UCharacter::getCombiningClass(args->c1);
	} else if (args->next != args->limit && $UTF16::isTrailSurrogate(args->c2 = $nc(args->source)->get(args->next))) {
		++args->next;
		return $UCharacter::getCombiningClass($Character::toCodePoint(args->c1, args->c2));
	} else {
		args->c2 = (char16_t)0;
		return 0;
	}
}

int32_t NormalizerImpl::getPrevCC($NormalizerImpl$PrevArgs* args) {
	$init(NormalizerImpl);
	$nc(args)->c1 = $nc(args->src)->get(--args->current);
	args->c2 = (char16_t)0;
	if (args->c1 < NormalizerImpl::MIN_CCC_LCCC_CP) {
		return 0;
	} else if ($UTF16::isLeadSurrogate(args->c1)) {
		return 0;
	} else if (!$UTF16::isTrailSurrogate(args->c1)) {
		return $UCharacter::getCombiningClass(args->c1);
	} else if (args->current != args->start && $UTF16::isLeadSurrogate(args->c2 = $nc(args->src)->get(args->current - 1))) {
		--args->current;
		return $UCharacter::getCombiningClass($Character::toCodePoint(args->c2, args->c1));
	} else {
		args->c2 = (char16_t)0;
		return 0;
	}
}

int32_t NormalizerImpl::getPreviousTrailCC($CharSequence* s, int32_t start, int32_t p) {
	if (start == p) {
		return 0;
	}
	return getFCD16($Character::codePointBefore(s, p));
}

void clinit$NormalizerImpl($Class* class$) {
	NormalizerImpl::$assertionsDisabled = !NormalizerImpl::class$->desiredAssertionStatus();
	$assignStatic(NormalizerImpl::IS_ACCEPTABLE, $new($NormalizerImpl$IsAcceptable));
}

NormalizerImpl::NormalizerImpl() {
}

$Class* NormalizerImpl::load$($String* name, bool initialize) {
	$loadClass(NormalizerImpl, name, initialize, &_NormalizerImpl_ClassInfo_, clinit$NormalizerImpl, allocate$NormalizerImpl);
	return class$;
}

$Class* NormalizerImpl::class$ = nullptr;

			} // impl
		} // icu
	} // internal
} // jdk
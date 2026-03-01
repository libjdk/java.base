#include <java/lang/Character$UnicodeBlock.h>

#include <java/lang/Character$Subset.h>
#include <java/util/HashMap.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <jcpp.h>

#undef ADLAM
#undef AEGEAN_NUMBERS
#undef AHOM
#undef ALCHEMICAL_SYMBOLS
#undef ALPHABETIC_PRESENTATION_FORMS
#undef ANATOLIAN_HIEROGLYPHS
#undef ANCIENT_GREEK_MUSICAL_NOTATION
#undef ANCIENT_GREEK_NUMBERS
#undef ANCIENT_SYMBOLS
#undef ARABIC
#undef ARABIC_EXTENDED_A
#undef ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS
#undef ARABIC_PRESENTATION_FORMS_A
#undef ARABIC_PRESENTATION_FORMS_B
#undef ARABIC_SUPPLEMENT
#undef ARMENIAN
#undef ARROWS
#undef AVESTAN
#undef BALINESE
#undef BAMUM
#undef BAMUM_SUPPLEMENT
#undef BASIC_LATIN
#undef BASSA_VAH
#undef BATAK
#undef BENGALI
#undef BHAIKSUKI
#undef BLOCK_ELEMENTS
#undef BOPOMOFO
#undef BOPOMOFO_EXTENDED
#undef BOX_DRAWING
#undef BRAHMI
#undef BRAILLE_PATTERNS
#undef BUGINESE
#undef BUHID
#undef BYZANTINE_MUSICAL_SYMBOLS
#undef CARIAN
#undef CAUCASIAN_ALBANIAN
#undef CHAKMA
#undef CHAM
#undef CHEROKEE
#undef CHEROKEE_SUPPLEMENT
#undef CHESS_SYMBOLS
#undef CHORASMIAN
#undef CJK_COMPATIBILITY
#undef CJK_COMPATIBILITY_FORMS
#undef CJK_COMPATIBILITY_IDEOGRAPHS
#undef CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT
#undef CJK_RADICALS_SUPPLEMENT
#undef CJK_STROKES
#undef CJK_SYMBOLS_AND_PUNCTUATION
#undef CJK_UNIFIED_IDEOGRAPHS
#undef CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A
#undef CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B
#undef CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C
#undef CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D
#undef CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E
#undef CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F
#undef CJK_UNIFIED_IDEOGRAPHS_EXTENSION_G
#undef COMBINING_DIACRITICAL_MARKS
#undef COMBINING_DIACRITICAL_MARKS_EXTENDED
#undef COMBINING_DIACRITICAL_MARKS_SUPPLEMENT
#undef COMBINING_HALF_MARKS
#undef COMBINING_MARKS_FOR_SYMBOLS
#undef COMMON_INDIC_NUMBER_FORMS
#undef CONTROL_PICTURES
#undef COPTIC
#undef COPTIC_EPACT_NUMBERS
#undef COUNTING_ROD_NUMERALS
#undef CUNEIFORM
#undef CUNEIFORM_NUMBERS_AND_PUNCTUATION
#undef CURRENCY_SYMBOLS
#undef CYPRIOT_SYLLABARY
#undef CYRILLIC
#undef CYRILLIC_EXTENDED_A
#undef CYRILLIC_EXTENDED_B
#undef CYRILLIC_EXTENDED_C
#undef CYRILLIC_SUPPLEMENTARY
#undef DESERET
#undef DEVANAGARI
#undef DEVANAGARI_EXTENDED
#undef DINGBATS
#undef DIVES_AKURU
#undef DOGRA
#undef DOMINO_TILES
#undef DUPLOYAN
#undef EARLY_DYNASTIC_CUNEIFORM
#undef EGYPTIAN_HIEROGLYPHS
#undef EGYPTIAN_HIEROGLYPH_FORMAT_CONTROLS
#undef ELBASAN
#undef ELYMAIC
#undef EMOTICONS
#undef ENCLOSED_ALPHANUMERICS
#undef ENCLOSED_ALPHANUMERIC_SUPPLEMENT
#undef ENCLOSED_CJK_LETTERS_AND_MONTHS
#undef ENCLOSED_IDEOGRAPHIC_SUPPLEMENT
#undef ETHIOPIC
#undef ETHIOPIC_EXTENDED
#undef ETHIOPIC_EXTENDED_A
#undef ETHIOPIC_SUPPLEMENT
#undef GENERAL_PUNCTUATION
#undef GEOMETRIC_SHAPES
#undef GEOMETRIC_SHAPES_EXTENDED
#undef GEORGIAN
#undef GEORGIAN_EXTENDED
#undef GEORGIAN_SUPPLEMENT
#undef GLAGOLITIC
#undef GLAGOLITIC_SUPPLEMENT
#undef GOTHIC
#undef GRANTHA
#undef GREEK
#undef GREEK_EXTENDED
#undef GUJARATI
#undef GUNJALA_GONDI
#undef GURMUKHI
#undef HALFWIDTH_AND_FULLWIDTH_FORMS
#undef HANGUL_COMPATIBILITY_JAMO
#undef HANGUL_JAMO
#undef HANGUL_JAMO_EXTENDED_A
#undef HANGUL_JAMO_EXTENDED_B
#undef HANGUL_SYLLABLES
#undef HANIFI_ROHINGYA
#undef HANUNOO
#undef HATRAN
#undef HEBREW
#undef HIGH_PRIVATE_USE_SURROGATES
#undef HIGH_SURROGATES
#undef HIRAGANA
#undef IDEOGRAPHIC_DESCRIPTION_CHARACTERS
#undef IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION
#undef IMPERIAL_ARAMAIC
#undef INDIC_SIYAQ_NUMBERS
#undef INSCRIPTIONAL_PAHLAVI
#undef INSCRIPTIONAL_PARTHIAN
#undef IPA_EXTENSIONS
#undef JAVANESE
#undef KAITHI
#undef KANA_EXTENDED_A
#undef KANA_SUPPLEMENT
#undef KANBUN
#undef KANGXI_RADICALS
#undef KANNADA
#undef KATAKANA
#undef KATAKANA_PHONETIC_EXTENSIONS
#undef KAYAH_LI
#undef KHAROSHTHI
#undef KHITAN_SMALL_SCRIPT
#undef KHMER
#undef KHMER_SYMBOLS
#undef KHOJKI
#undef KHUDAWADI
#undef LAO
#undef LATIN_1_SUPPLEMENT
#undef LATIN_EXTENDED_A
#undef LATIN_EXTENDED_ADDITIONAL
#undef LATIN_EXTENDED_B
#undef LATIN_EXTENDED_C
#undef LATIN_EXTENDED_D
#undef LATIN_EXTENDED_E
#undef LEPCHA
#undef LETTERLIKE_SYMBOLS
#undef LIMBU
#undef LINEAR_A
#undef LINEAR_B_IDEOGRAMS
#undef LINEAR_B_SYLLABARY
#undef LISU
#undef LISU_SUPPLEMENT
#undef LOW_SURROGATES
#undef LYCIAN
#undef LYDIAN
#undef MAHAJANI
#undef MAHJONG_TILES
#undef MAKASAR
#undef MALAYALAM
#undef MANDAIC
#undef MANICHAEAN
#undef MARCHEN
#undef MASARAM_GONDI
#undef MATHEMATICAL_ALPHANUMERIC_SYMBOLS
#undef MATHEMATICAL_OPERATORS
#undef MAYAN_NUMERALS
#undef MEDEFAIDRIN
#undef MEETEI_MAYEK
#undef MEETEI_MAYEK_EXTENSIONS
#undef MENDE_KIKAKUI
#undef MEROITIC_CURSIVE
#undef MEROITIC_HIEROGLYPHS
#undef MIAO
#undef MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A
#undef MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B
#undef MISCELLANEOUS_SYMBOLS
#undef MISCELLANEOUS_SYMBOLS_AND_ARROWS
#undef MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS
#undef MISCELLANEOUS_TECHNICAL
#undef MODI
#undef MODIFIER_TONE_LETTERS
#undef MONGOLIAN
#undef MONGOLIAN_SUPPLEMENT
#undef MRO
#undef MULTANI
#undef MUSICAL_SYMBOLS
#undef MYANMAR
#undef MYANMAR_EXTENDED_A
#undef MYANMAR_EXTENDED_B
#undef NABATAEAN
#undef NANDINAGARI
#undef NEWA
#undef NEW_TAI_LUE
#undef NKO
#undef NUMBER_FORMS
#undef NUM_ENTITIES
#undef NUSHU
#undef NYIAKENG_PUACHUE_HMONG
#undef OGHAM
#undef OLD_HUNGARIAN
#undef OLD_ITALIC
#undef OLD_NORTH_ARABIAN
#undef OLD_PERMIC
#undef OLD_PERSIAN
#undef OLD_SOGDIAN
#undef OLD_SOUTH_ARABIAN
#undef OLD_TURKIC
#undef OL_CHIKI
#undef OPTICAL_CHARACTER_RECOGNITION
#undef ORIYA
#undef ORNAMENTAL_DINGBATS
#undef OSAGE
#undef OSMANYA
#undef OTTOMAN_SIYAQ_NUMBERS
#undef PAHAWH_HMONG
#undef PALMYRENE
#undef PAU_CIN_HAU
#undef PHAGS_PA
#undef PHAISTOS_DISC
#undef PHOENICIAN
#undef PHONETIC_EXTENSIONS
#undef PHONETIC_EXTENSIONS_SUPPLEMENT
#undef PLAYING_CARDS
#undef PRIVATE_USE_AREA
#undef PSALTER_PAHLAVI
#undef REJANG
#undef RUMI_NUMERAL_SYMBOLS
#undef RUNIC
#undef SAMARITAN
#undef SAURASHTRA
#undef SHARADA
#undef SHAVIAN
#undef SHORTHAND_FORMAT_CONTROLS
#undef SIDDHAM
#undef SINHALA
#undef SINHALA_ARCHAIC_NUMBERS
#undef SMALL_FORM_VARIANTS
#undef SMALL_KANA_EXTENSION
#undef SOGDIAN
#undef SORA_SOMPENG
#undef SOYOMBO
#undef SPACING_MODIFIER_LETTERS
#undef SPECIALS
#undef SUNDANESE
#undef SUNDANESE_SUPPLEMENT
#undef SUPERSCRIPTS_AND_SUBSCRIPTS
#undef SUPPLEMENTAL_ARROWS_A
#undef SUPPLEMENTAL_ARROWS_B
#undef SUPPLEMENTAL_ARROWS_C
#undef SUPPLEMENTAL_MATHEMATICAL_OPERATORS
#undef SUPPLEMENTAL_PUNCTUATION
#undef SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS
#undef SUPPLEMENTARY_PRIVATE_USE_AREA_A
#undef SUPPLEMENTARY_PRIVATE_USE_AREA_B
#undef SURROGATES_AREA
#undef SUTTON_SIGNWRITING
#undef SYLOTI_NAGRI
#undef SYMBOLS_AND_PICTOGRAPHS_EXTENDED_A
#undef SYMBOLS_FOR_LEGACY_COMPUTING
#undef SYRIAC
#undef SYRIAC_SUPPLEMENT
#undef TAGALOG
#undef TAGBANWA
#undef TAGS
#undef TAI_LE
#undef TAI_THAM
#undef TAI_VIET
#undef TAI_XUAN_JING_SYMBOLS
#undef TAKRI
#undef TAMIL
#undef TAMIL_SUPPLEMENT
#undef TANGUT
#undef TANGUT_COMPONENTS
#undef TANGUT_SUPPLEMENT
#undef TELUGU
#undef THAANA
#undef THAI
#undef TIBETAN
#undef TIFINAGH
#undef TIRHUTA
#undef TRANSPORT_AND_MAP_SYMBOLS
#undef UGARITIC
#undef UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS
#undef UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED
#undef US
#undef VAI
#undef VARIATION_SELECTORS
#undef VARIATION_SELECTORS_SUPPLEMENT
#undef VEDIC_EXTENSIONS
#undef VERTICAL_FORMS
#undef WANCHO
#undef WARANG_CITI
#undef YEZIDI
#undef YIJING_HEXAGRAM_SYMBOLS
#undef YI_RADICALS
#undef YI_SYLLABLES
#undef ZANABAZAR_SQUARE

using $Character$UnicodeBlockArray = $Array<::java::lang::Character$UnicodeBlock>;
using $Character = ::java::lang::Character;
using $Character$Subset = ::java::lang::Character$Subset;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $HashMap = ::java::util::HashMap;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;

namespace java {
	namespace lang {

$NamedAttribute Character$UnicodeBlock_Attribute_var$0[] = {
	{"since", 's', "1.5"},
	{}
};

$CompoundAttribute _Character$UnicodeBlock_FieldAnnotations_SURROGATES_AREA[] = {
	{"Ljava/lang/Deprecated;", Character$UnicodeBlock_Attribute_var$0},
	{}
};

$FieldInfo _Character$UnicodeBlock_FieldInfo_[] = {
	{"NUM_ENTITIES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Character$UnicodeBlock, NUM_ENTITIES)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Character$UnicodeBlock;>;", $PRIVATE | $STATIC, $staticField(Character$UnicodeBlock, map)},
	{"BASIC_LATIN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BASIC_LATIN)},
	{"LATIN_1_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LATIN_1_SUPPLEMENT)},
	{"LATIN_EXTENDED_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LATIN_EXTENDED_A)},
	{"LATIN_EXTENDED_B", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LATIN_EXTENDED_B)},
	{"IPA_EXTENSIONS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, IPA_EXTENSIONS)},
	{"SPACING_MODIFIER_LETTERS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SPACING_MODIFIER_LETTERS)},
	{"COMBINING_DIACRITICAL_MARKS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, COMBINING_DIACRITICAL_MARKS)},
	{"GREEK", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GREEK)},
	{"CYRILLIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CYRILLIC)},
	{"ARMENIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ARMENIAN)},
	{"HEBREW", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HEBREW)},
	{"ARABIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ARABIC)},
	{"DEVANAGARI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, DEVANAGARI)},
	{"BENGALI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BENGALI)},
	{"GURMUKHI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GURMUKHI)},
	{"GUJARATI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GUJARATI)},
	{"ORIYA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ORIYA)},
	{"TAMIL", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAMIL)},
	{"TELUGU", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TELUGU)},
	{"KANNADA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KANNADA)},
	{"MALAYALAM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MALAYALAM)},
	{"THAI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, THAI)},
	{"LAO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LAO)},
	{"TIBETAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TIBETAN)},
	{"GEORGIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GEORGIAN)},
	{"HANGUL_JAMO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HANGUL_JAMO)},
	{"LATIN_EXTENDED_ADDITIONAL", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LATIN_EXTENDED_ADDITIONAL)},
	{"GREEK_EXTENDED", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GREEK_EXTENDED)},
	{"GENERAL_PUNCTUATION", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GENERAL_PUNCTUATION)},
	{"SUPERSCRIPTS_AND_SUBSCRIPTS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUPERSCRIPTS_AND_SUBSCRIPTS)},
	{"CURRENCY_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CURRENCY_SYMBOLS)},
	{"COMBINING_MARKS_FOR_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, COMBINING_MARKS_FOR_SYMBOLS)},
	{"LETTERLIKE_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LETTERLIKE_SYMBOLS)},
	{"NUMBER_FORMS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, NUMBER_FORMS)},
	{"ARROWS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ARROWS)},
	{"MATHEMATICAL_OPERATORS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MATHEMATICAL_OPERATORS)},
	{"MISCELLANEOUS_TECHNICAL", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MISCELLANEOUS_TECHNICAL)},
	{"CONTROL_PICTURES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CONTROL_PICTURES)},
	{"OPTICAL_CHARACTER_RECOGNITION", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OPTICAL_CHARACTER_RECOGNITION)},
	{"ENCLOSED_ALPHANUMERICS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ENCLOSED_ALPHANUMERICS)},
	{"BOX_DRAWING", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BOX_DRAWING)},
	{"BLOCK_ELEMENTS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BLOCK_ELEMENTS)},
	{"GEOMETRIC_SHAPES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GEOMETRIC_SHAPES)},
	{"MISCELLANEOUS_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MISCELLANEOUS_SYMBOLS)},
	{"DINGBATS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, DINGBATS)},
	{"CJK_SYMBOLS_AND_PUNCTUATION", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_SYMBOLS_AND_PUNCTUATION)},
	{"HIRAGANA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HIRAGANA)},
	{"KATAKANA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KATAKANA)},
	{"BOPOMOFO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BOPOMOFO)},
	{"HANGUL_COMPATIBILITY_JAMO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HANGUL_COMPATIBILITY_JAMO)},
	{"KANBUN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KANBUN)},
	{"ENCLOSED_CJK_LETTERS_AND_MONTHS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ENCLOSED_CJK_LETTERS_AND_MONTHS)},
	{"CJK_COMPATIBILITY", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_COMPATIBILITY)},
	{"CJK_UNIFIED_IDEOGRAPHS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_UNIFIED_IDEOGRAPHS)},
	{"HANGUL_SYLLABLES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HANGUL_SYLLABLES)},
	{"PRIVATE_USE_AREA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PRIVATE_USE_AREA)},
	{"CJK_COMPATIBILITY_IDEOGRAPHS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_COMPATIBILITY_IDEOGRAPHS)},
	{"ALPHABETIC_PRESENTATION_FORMS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ALPHABETIC_PRESENTATION_FORMS)},
	{"ARABIC_PRESENTATION_FORMS_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ARABIC_PRESENTATION_FORMS_A)},
	{"COMBINING_HALF_MARKS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, COMBINING_HALF_MARKS)},
	{"CJK_COMPATIBILITY_FORMS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_COMPATIBILITY_FORMS)},
	{"SMALL_FORM_VARIANTS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SMALL_FORM_VARIANTS)},
	{"ARABIC_PRESENTATION_FORMS_B", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ARABIC_PRESENTATION_FORMS_B)},
	{"HALFWIDTH_AND_FULLWIDTH_FORMS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HALFWIDTH_AND_FULLWIDTH_FORMS)},
	{"SPECIALS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SPECIALS)},
	{"SURROGATES_AREA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $staticField(Character$UnicodeBlock, SURROGATES_AREA), _Character$UnicodeBlock_FieldAnnotations_SURROGATES_AREA},
	{"SYRIAC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SYRIAC)},
	{"THAANA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, THAANA)},
	{"SINHALA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SINHALA)},
	{"MYANMAR", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MYANMAR)},
	{"ETHIOPIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ETHIOPIC)},
	{"CHEROKEE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CHEROKEE)},
	{"UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS)},
	{"OGHAM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OGHAM)},
	{"RUNIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, RUNIC)},
	{"KHMER", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KHMER)},
	{"MONGOLIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MONGOLIAN)},
	{"BRAILLE_PATTERNS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BRAILLE_PATTERNS)},
	{"CJK_RADICALS_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_RADICALS_SUPPLEMENT)},
	{"KANGXI_RADICALS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KANGXI_RADICALS)},
	{"IDEOGRAPHIC_DESCRIPTION_CHARACTERS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, IDEOGRAPHIC_DESCRIPTION_CHARACTERS)},
	{"BOPOMOFO_EXTENDED", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BOPOMOFO_EXTENDED)},
	{"CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A)},
	{"YI_SYLLABLES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, YI_SYLLABLES)},
	{"YI_RADICALS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, YI_RADICALS)},
	{"CYRILLIC_SUPPLEMENTARY", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CYRILLIC_SUPPLEMENTARY)},
	{"TAGALOG", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAGALOG)},
	{"HANUNOO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HANUNOO)},
	{"BUHID", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BUHID)},
	{"TAGBANWA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAGBANWA)},
	{"LIMBU", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LIMBU)},
	{"TAI_LE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAI_LE)},
	{"KHMER_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KHMER_SYMBOLS)},
	{"PHONETIC_EXTENSIONS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PHONETIC_EXTENSIONS)},
	{"MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A)},
	{"SUPPLEMENTAL_ARROWS_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUPPLEMENTAL_ARROWS_A)},
	{"SUPPLEMENTAL_ARROWS_B", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUPPLEMENTAL_ARROWS_B)},
	{"MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B)},
	{"SUPPLEMENTAL_MATHEMATICAL_OPERATORS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUPPLEMENTAL_MATHEMATICAL_OPERATORS)},
	{"MISCELLANEOUS_SYMBOLS_AND_ARROWS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MISCELLANEOUS_SYMBOLS_AND_ARROWS)},
	{"KATAKANA_PHONETIC_EXTENSIONS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KATAKANA_PHONETIC_EXTENSIONS)},
	{"YIJING_HEXAGRAM_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, YIJING_HEXAGRAM_SYMBOLS)},
	{"VARIATION_SELECTORS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, VARIATION_SELECTORS)},
	{"LINEAR_B_SYLLABARY", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LINEAR_B_SYLLABARY)},
	{"LINEAR_B_IDEOGRAMS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LINEAR_B_IDEOGRAMS)},
	{"AEGEAN_NUMBERS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, AEGEAN_NUMBERS)},
	{"OLD_ITALIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OLD_ITALIC)},
	{"GOTHIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GOTHIC)},
	{"UGARITIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, UGARITIC)},
	{"DESERET", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, DESERET)},
	{"SHAVIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SHAVIAN)},
	{"OSMANYA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OSMANYA)},
	{"CYPRIOT_SYLLABARY", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CYPRIOT_SYLLABARY)},
	{"BYZANTINE_MUSICAL_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BYZANTINE_MUSICAL_SYMBOLS)},
	{"MUSICAL_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MUSICAL_SYMBOLS)},
	{"TAI_XUAN_JING_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAI_XUAN_JING_SYMBOLS)},
	{"MATHEMATICAL_ALPHANUMERIC_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MATHEMATICAL_ALPHANUMERIC_SYMBOLS)},
	{"CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B)},
	{"CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT)},
	{"TAGS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAGS)},
	{"VARIATION_SELECTORS_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, VARIATION_SELECTORS_SUPPLEMENT)},
	{"SUPPLEMENTARY_PRIVATE_USE_AREA_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUPPLEMENTARY_PRIVATE_USE_AREA_A)},
	{"SUPPLEMENTARY_PRIVATE_USE_AREA_B", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUPPLEMENTARY_PRIVATE_USE_AREA_B)},
	{"HIGH_SURROGATES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HIGH_SURROGATES)},
	{"HIGH_PRIVATE_USE_SURROGATES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HIGH_PRIVATE_USE_SURROGATES)},
	{"LOW_SURROGATES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LOW_SURROGATES)},
	{"ARABIC_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ARABIC_SUPPLEMENT)},
	{"NKO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, NKO)},
	{"SAMARITAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SAMARITAN)},
	{"MANDAIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MANDAIC)},
	{"ETHIOPIC_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ETHIOPIC_SUPPLEMENT)},
	{"UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED)},
	{"NEW_TAI_LUE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, NEW_TAI_LUE)},
	{"BUGINESE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BUGINESE)},
	{"TAI_THAM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAI_THAM)},
	{"BALINESE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BALINESE)},
	{"SUNDANESE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUNDANESE)},
	{"BATAK", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BATAK)},
	{"LEPCHA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LEPCHA)},
	{"OL_CHIKI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OL_CHIKI)},
	{"VEDIC_EXTENSIONS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, VEDIC_EXTENSIONS)},
	{"PHONETIC_EXTENSIONS_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PHONETIC_EXTENSIONS_SUPPLEMENT)},
	{"COMBINING_DIACRITICAL_MARKS_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, COMBINING_DIACRITICAL_MARKS_SUPPLEMENT)},
	{"GLAGOLITIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GLAGOLITIC)},
	{"LATIN_EXTENDED_C", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LATIN_EXTENDED_C)},
	{"COPTIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, COPTIC)},
	{"GEORGIAN_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GEORGIAN_SUPPLEMENT)},
	{"TIFINAGH", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TIFINAGH)},
	{"ETHIOPIC_EXTENDED", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ETHIOPIC_EXTENDED)},
	{"CYRILLIC_EXTENDED_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CYRILLIC_EXTENDED_A)},
	{"SUPPLEMENTAL_PUNCTUATION", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUPPLEMENTAL_PUNCTUATION)},
	{"CJK_STROKES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_STROKES)},
	{"LISU", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LISU)},
	{"VAI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, VAI)},
	{"CYRILLIC_EXTENDED_B", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CYRILLIC_EXTENDED_B)},
	{"BAMUM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BAMUM)},
	{"MODIFIER_TONE_LETTERS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MODIFIER_TONE_LETTERS)},
	{"LATIN_EXTENDED_D", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LATIN_EXTENDED_D)},
	{"SYLOTI_NAGRI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SYLOTI_NAGRI)},
	{"COMMON_INDIC_NUMBER_FORMS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, COMMON_INDIC_NUMBER_FORMS)},
	{"PHAGS_PA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PHAGS_PA)},
	{"SAURASHTRA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SAURASHTRA)},
	{"DEVANAGARI_EXTENDED", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, DEVANAGARI_EXTENDED)},
	{"KAYAH_LI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KAYAH_LI)},
	{"REJANG", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, REJANG)},
	{"HANGUL_JAMO_EXTENDED_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HANGUL_JAMO_EXTENDED_A)},
	{"JAVANESE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, JAVANESE)},
	{"CHAM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CHAM)},
	{"MYANMAR_EXTENDED_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MYANMAR_EXTENDED_A)},
	{"TAI_VIET", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAI_VIET)},
	{"ETHIOPIC_EXTENDED_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ETHIOPIC_EXTENDED_A)},
	{"MEETEI_MAYEK", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MEETEI_MAYEK)},
	{"HANGUL_JAMO_EXTENDED_B", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HANGUL_JAMO_EXTENDED_B)},
	{"VERTICAL_FORMS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, VERTICAL_FORMS)},
	{"ANCIENT_GREEK_NUMBERS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ANCIENT_GREEK_NUMBERS)},
	{"ANCIENT_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ANCIENT_SYMBOLS)},
	{"PHAISTOS_DISC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PHAISTOS_DISC)},
	{"LYCIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LYCIAN)},
	{"CARIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CARIAN)},
	{"OLD_PERSIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OLD_PERSIAN)},
	{"IMPERIAL_ARAMAIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, IMPERIAL_ARAMAIC)},
	{"PHOENICIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PHOENICIAN)},
	{"LYDIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LYDIAN)},
	{"KHAROSHTHI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KHAROSHTHI)},
	{"OLD_SOUTH_ARABIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OLD_SOUTH_ARABIAN)},
	{"AVESTAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, AVESTAN)},
	{"INSCRIPTIONAL_PARTHIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, INSCRIPTIONAL_PARTHIAN)},
	{"INSCRIPTIONAL_PAHLAVI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, INSCRIPTIONAL_PAHLAVI)},
	{"OLD_TURKIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OLD_TURKIC)},
	{"RUMI_NUMERAL_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, RUMI_NUMERAL_SYMBOLS)},
	{"BRAHMI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BRAHMI)},
	{"KAITHI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KAITHI)},
	{"CUNEIFORM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CUNEIFORM)},
	{"CUNEIFORM_NUMBERS_AND_PUNCTUATION", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CUNEIFORM_NUMBERS_AND_PUNCTUATION)},
	{"EGYPTIAN_HIEROGLYPHS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, EGYPTIAN_HIEROGLYPHS)},
	{"BAMUM_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BAMUM_SUPPLEMENT)},
	{"KANA_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KANA_SUPPLEMENT)},
	{"ANCIENT_GREEK_MUSICAL_NOTATION", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ANCIENT_GREEK_MUSICAL_NOTATION)},
	{"COUNTING_ROD_NUMERALS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, COUNTING_ROD_NUMERALS)},
	{"MAHJONG_TILES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MAHJONG_TILES)},
	{"DOMINO_TILES", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, DOMINO_TILES)},
	{"PLAYING_CARDS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PLAYING_CARDS)},
	{"ENCLOSED_ALPHANUMERIC_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ENCLOSED_ALPHANUMERIC_SUPPLEMENT)},
	{"ENCLOSED_IDEOGRAPHIC_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ENCLOSED_IDEOGRAPHIC_SUPPLEMENT)},
	{"MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS)},
	{"EMOTICONS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, EMOTICONS)},
	{"TRANSPORT_AND_MAP_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TRANSPORT_AND_MAP_SYMBOLS)},
	{"ALCHEMICAL_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ALCHEMICAL_SYMBOLS)},
	{"CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C)},
	{"CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D)},
	{"ARABIC_EXTENDED_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ARABIC_EXTENDED_A)},
	{"SUNDANESE_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUNDANESE_SUPPLEMENT)},
	{"MEETEI_MAYEK_EXTENSIONS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MEETEI_MAYEK_EXTENSIONS)},
	{"MEROITIC_HIEROGLYPHS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MEROITIC_HIEROGLYPHS)},
	{"MEROITIC_CURSIVE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MEROITIC_CURSIVE)},
	{"SORA_SOMPENG", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SORA_SOMPENG)},
	{"CHAKMA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CHAKMA)},
	{"SHARADA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SHARADA)},
	{"TAKRI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAKRI)},
	{"MIAO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MIAO)},
	{"ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS)},
	{"COMBINING_DIACRITICAL_MARKS_EXTENDED", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, COMBINING_DIACRITICAL_MARKS_EXTENDED)},
	{"MYANMAR_EXTENDED_B", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MYANMAR_EXTENDED_B)},
	{"LATIN_EXTENDED_E", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LATIN_EXTENDED_E)},
	{"COPTIC_EPACT_NUMBERS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, COPTIC_EPACT_NUMBERS)},
	{"OLD_PERMIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OLD_PERMIC)},
	{"ELBASAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ELBASAN)},
	{"CAUCASIAN_ALBANIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CAUCASIAN_ALBANIAN)},
	{"LINEAR_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LINEAR_A)},
	{"PALMYRENE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PALMYRENE)},
	{"NABATAEAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, NABATAEAN)},
	{"OLD_NORTH_ARABIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OLD_NORTH_ARABIAN)},
	{"MANICHAEAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MANICHAEAN)},
	{"PSALTER_PAHLAVI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PSALTER_PAHLAVI)},
	{"MAHAJANI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MAHAJANI)},
	{"SINHALA_ARCHAIC_NUMBERS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SINHALA_ARCHAIC_NUMBERS)},
	{"KHOJKI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KHOJKI)},
	{"KHUDAWADI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KHUDAWADI)},
	{"GRANTHA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GRANTHA)},
	{"TIRHUTA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TIRHUTA)},
	{"SIDDHAM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SIDDHAM)},
	{"MODI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MODI)},
	{"WARANG_CITI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, WARANG_CITI)},
	{"PAU_CIN_HAU", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PAU_CIN_HAU)},
	{"MRO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MRO)},
	{"BASSA_VAH", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BASSA_VAH)},
	{"PAHAWH_HMONG", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, PAHAWH_HMONG)},
	{"DUPLOYAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, DUPLOYAN)},
	{"SHORTHAND_FORMAT_CONTROLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SHORTHAND_FORMAT_CONTROLS)},
	{"MENDE_KIKAKUI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MENDE_KIKAKUI)},
	{"ORNAMENTAL_DINGBATS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ORNAMENTAL_DINGBATS)},
	{"GEOMETRIC_SHAPES_EXTENDED", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GEOMETRIC_SHAPES_EXTENDED)},
	{"SUPPLEMENTAL_ARROWS_C", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUPPLEMENTAL_ARROWS_C)},
	{"CHEROKEE_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CHEROKEE_SUPPLEMENT)},
	{"HATRAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HATRAN)},
	{"OLD_HUNGARIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OLD_HUNGARIAN)},
	{"MULTANI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MULTANI)},
	{"AHOM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, AHOM)},
	{"EARLY_DYNASTIC_CUNEIFORM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, EARLY_DYNASTIC_CUNEIFORM)},
	{"ANATOLIAN_HIEROGLYPHS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ANATOLIAN_HIEROGLYPHS)},
	{"SUTTON_SIGNWRITING", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUTTON_SIGNWRITING)},
	{"SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS)},
	{"CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E)},
	{"SYRIAC_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SYRIAC_SUPPLEMENT)},
	{"CYRILLIC_EXTENDED_C", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CYRILLIC_EXTENDED_C)},
	{"OSAGE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OSAGE)},
	{"NEWA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, NEWA)},
	{"MONGOLIAN_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MONGOLIAN_SUPPLEMENT)},
	{"MARCHEN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MARCHEN)},
	{"IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION)},
	{"TANGUT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TANGUT)},
	{"TANGUT_COMPONENTS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TANGUT_COMPONENTS)},
	{"KANA_EXTENDED_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KANA_EXTENDED_A)},
	{"GLAGOLITIC_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GLAGOLITIC_SUPPLEMENT)},
	{"ADLAM", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ADLAM)},
	{"MASARAM_GONDI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MASARAM_GONDI)},
	{"ZANABAZAR_SQUARE", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ZANABAZAR_SQUARE)},
	{"NUSHU", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, NUSHU)},
	{"SOYOMBO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SOYOMBO)},
	{"BHAIKSUKI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, BHAIKSUKI)},
	{"CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F)},
	{"GEORGIAN_EXTENDED", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GEORGIAN_EXTENDED)},
	{"HANIFI_ROHINGYA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, HANIFI_ROHINGYA)},
	{"OLD_SOGDIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OLD_SOGDIAN)},
	{"SOGDIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SOGDIAN)},
	{"DOGRA", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, DOGRA)},
	{"GUNJALA_GONDI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, GUNJALA_GONDI)},
	{"MAKASAR", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MAKASAR)},
	{"MEDEFAIDRIN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MEDEFAIDRIN)},
	{"MAYAN_NUMERALS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, MAYAN_NUMERALS)},
	{"INDIC_SIYAQ_NUMBERS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, INDIC_SIYAQ_NUMBERS)},
	{"CHESS_SYMBOLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CHESS_SYMBOLS)},
	{"ELYMAIC", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, ELYMAIC)},
	{"NANDINAGARI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, NANDINAGARI)},
	{"TAMIL_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TAMIL_SUPPLEMENT)},
	{"EGYPTIAN_HIEROGLYPH_FORMAT_CONTROLS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, EGYPTIAN_HIEROGLYPH_FORMAT_CONTROLS)},
	{"SMALL_KANA_EXTENSION", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SMALL_KANA_EXTENSION)},
	{"NYIAKENG_PUACHUE_HMONG", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, NYIAKENG_PUACHUE_HMONG)},
	{"WANCHO", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, WANCHO)},
	{"OTTOMAN_SIYAQ_NUMBERS", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, OTTOMAN_SIYAQ_NUMBERS)},
	{"SYMBOLS_AND_PICTOGRAPHS_EXTENDED_A", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SYMBOLS_AND_PICTOGRAPHS_EXTENDED_A)},
	{"YEZIDI", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, YEZIDI)},
	{"CHORASMIAN", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CHORASMIAN)},
	{"DIVES_AKURU", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, DIVES_AKURU)},
	{"LISU_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, LISU_SUPPLEMENT)},
	{"KHITAN_SMALL_SCRIPT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, KHITAN_SMALL_SCRIPT)},
	{"TANGUT_SUPPLEMENT", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, TANGUT_SUPPLEMENT)},
	{"SYMBOLS_FOR_LEGACY_COMPUTING", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, SYMBOLS_FOR_LEGACY_COMPUTING)},
	{"CJK_UNIFIED_IDEOGRAPHS_EXTENSION_G", "Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, CJK_UNIFIED_IDEOGRAPHS_EXTENSION_G)},
	{"blockStarts", "[I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, blockStarts)},
	{"blocks", "[Ljava/lang/Character$UnicodeBlock;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Character$UnicodeBlock, blocks)},
	{}
};

$MethodInfo _Character$UnicodeBlock_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Character$UnicodeBlock, init$, void, $String*)},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(Character$UnicodeBlock, init$, void, $String*, $String*)},
	{"<init>", "(Ljava/lang/String;[Ljava/lang/String;)V", nullptr, $PRIVATE | $TRANSIENT, $method(Character$UnicodeBlock, init$, void, $String*, $StringArray*)},
	{"forName", "(Ljava/lang/String;)Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticMethod(Character$UnicodeBlock, forName, Character$UnicodeBlock*, $String*)},
	{"of", "(C)Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC, $staticMethod(Character$UnicodeBlock, of, Character$UnicodeBlock*, char16_t)},
	{"of", "(I)Ljava/lang/Character$UnicodeBlock;", nullptr, $PUBLIC | $STATIC, $staticMethod(Character$UnicodeBlock, of, Character$UnicodeBlock*, int32_t)},
	{}
};

$InnerClassInfo _Character$UnicodeBlock_InnerClassesInfo_[] = {
	{"java.lang.Character$UnicodeBlock", "java.lang.Character", "UnicodeBlock", $PUBLIC | $STATIC | $FINAL},
	{"java.lang.Character$Subset", "java.lang.Character", "Subset", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _Character$UnicodeBlock_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.Character$UnicodeBlock",
	"java.lang.Character$Subset",
	nullptr,
	_Character$UnicodeBlock_FieldInfo_,
	_Character$UnicodeBlock_MethodInfo_,
	nullptr,
	nullptr,
	_Character$UnicodeBlock_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.lang.Character"
};

$Object* allocate$Character$UnicodeBlock($Class* clazz) {
	return $of($alloc(Character$UnicodeBlock));
}

$Map* Character$UnicodeBlock::map = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BASIC_LATIN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LATIN_1_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LATIN_EXTENDED_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LATIN_EXTENDED_B = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::IPA_EXTENSIONS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SPACING_MODIFIER_LETTERS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::COMBINING_DIACRITICAL_MARKS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GREEK = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CYRILLIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ARMENIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HEBREW = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ARABIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::DEVANAGARI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BENGALI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GURMUKHI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GUJARATI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ORIYA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAMIL = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TELUGU = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KANNADA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MALAYALAM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::THAI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LAO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TIBETAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GEORGIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HANGUL_JAMO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LATIN_EXTENDED_ADDITIONAL = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GREEK_EXTENDED = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GENERAL_PUNCTUATION = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUPERSCRIPTS_AND_SUBSCRIPTS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CURRENCY_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::COMBINING_MARKS_FOR_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LETTERLIKE_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::NUMBER_FORMS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ARROWS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MATHEMATICAL_OPERATORS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MISCELLANEOUS_TECHNICAL = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CONTROL_PICTURES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OPTICAL_CHARACTER_RECOGNITION = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ENCLOSED_ALPHANUMERICS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BOX_DRAWING = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BLOCK_ELEMENTS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GEOMETRIC_SHAPES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MISCELLANEOUS_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::DINGBATS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_SYMBOLS_AND_PUNCTUATION = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HIRAGANA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KATAKANA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BOPOMOFO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HANGUL_COMPATIBILITY_JAMO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KANBUN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ENCLOSED_CJK_LETTERS_AND_MONTHS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_COMPATIBILITY = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HANGUL_SYLLABLES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PRIVATE_USE_AREA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_COMPATIBILITY_IDEOGRAPHS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ALPHABETIC_PRESENTATION_FORMS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ARABIC_PRESENTATION_FORMS_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::COMBINING_HALF_MARKS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_COMPATIBILITY_FORMS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SMALL_FORM_VARIANTS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ARABIC_PRESENTATION_FORMS_B = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HALFWIDTH_AND_FULLWIDTH_FORMS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SPECIALS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SURROGATES_AREA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SYRIAC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::THAANA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SINHALA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MYANMAR = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ETHIOPIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CHEROKEE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OGHAM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::RUNIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KHMER = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MONGOLIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BRAILLE_PATTERNS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_RADICALS_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KANGXI_RADICALS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::IDEOGRAPHIC_DESCRIPTION_CHARACTERS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BOPOMOFO_EXTENDED = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::YI_SYLLABLES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::YI_RADICALS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CYRILLIC_SUPPLEMENTARY = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAGALOG = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HANUNOO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BUHID = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAGBANWA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LIMBU = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAI_LE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KHMER_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PHONETIC_EXTENSIONS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUPPLEMENTAL_ARROWS_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUPPLEMENTAL_ARROWS_B = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUPPLEMENTAL_MATHEMATICAL_OPERATORS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MISCELLANEOUS_SYMBOLS_AND_ARROWS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KATAKANA_PHONETIC_EXTENSIONS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::YIJING_HEXAGRAM_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::VARIATION_SELECTORS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LINEAR_B_SYLLABARY = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LINEAR_B_IDEOGRAMS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::AEGEAN_NUMBERS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OLD_ITALIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GOTHIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::UGARITIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::DESERET = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SHAVIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OSMANYA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CYPRIOT_SYLLABARY = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BYZANTINE_MUSICAL_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MUSICAL_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAI_XUAN_JING_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MATHEMATICAL_ALPHANUMERIC_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAGS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::VARIATION_SELECTORS_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUPPLEMENTARY_PRIVATE_USE_AREA_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUPPLEMENTARY_PRIVATE_USE_AREA_B = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HIGH_SURROGATES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HIGH_PRIVATE_USE_SURROGATES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LOW_SURROGATES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ARABIC_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::NKO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SAMARITAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MANDAIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ETHIOPIC_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::NEW_TAI_LUE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BUGINESE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAI_THAM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BALINESE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUNDANESE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BATAK = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LEPCHA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OL_CHIKI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::VEDIC_EXTENSIONS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PHONETIC_EXTENSIONS_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::COMBINING_DIACRITICAL_MARKS_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GLAGOLITIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LATIN_EXTENDED_C = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::COPTIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GEORGIAN_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TIFINAGH = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ETHIOPIC_EXTENDED = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CYRILLIC_EXTENDED_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUPPLEMENTAL_PUNCTUATION = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_STROKES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LISU = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::VAI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CYRILLIC_EXTENDED_B = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BAMUM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MODIFIER_TONE_LETTERS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LATIN_EXTENDED_D = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SYLOTI_NAGRI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::COMMON_INDIC_NUMBER_FORMS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PHAGS_PA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SAURASHTRA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::DEVANAGARI_EXTENDED = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KAYAH_LI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::REJANG = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HANGUL_JAMO_EXTENDED_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::JAVANESE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CHAM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MYANMAR_EXTENDED_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAI_VIET = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ETHIOPIC_EXTENDED_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MEETEI_MAYEK = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HANGUL_JAMO_EXTENDED_B = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::VERTICAL_FORMS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ANCIENT_GREEK_NUMBERS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ANCIENT_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PHAISTOS_DISC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LYCIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CARIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OLD_PERSIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::IMPERIAL_ARAMAIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PHOENICIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LYDIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KHAROSHTHI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OLD_SOUTH_ARABIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::AVESTAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::INSCRIPTIONAL_PARTHIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::INSCRIPTIONAL_PAHLAVI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OLD_TURKIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::RUMI_NUMERAL_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BRAHMI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KAITHI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CUNEIFORM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CUNEIFORM_NUMBERS_AND_PUNCTUATION = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::EGYPTIAN_HIEROGLYPHS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BAMUM_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KANA_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ANCIENT_GREEK_MUSICAL_NOTATION = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::COUNTING_ROD_NUMERALS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MAHJONG_TILES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::DOMINO_TILES = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PLAYING_CARDS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ENCLOSED_ALPHANUMERIC_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ENCLOSED_IDEOGRAPHIC_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::EMOTICONS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TRANSPORT_AND_MAP_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ALCHEMICAL_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ARABIC_EXTENDED_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUNDANESE_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MEETEI_MAYEK_EXTENSIONS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MEROITIC_HIEROGLYPHS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MEROITIC_CURSIVE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SORA_SOMPENG = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CHAKMA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SHARADA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAKRI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MIAO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::COMBINING_DIACRITICAL_MARKS_EXTENDED = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MYANMAR_EXTENDED_B = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LATIN_EXTENDED_E = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::COPTIC_EPACT_NUMBERS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OLD_PERMIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ELBASAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CAUCASIAN_ALBANIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LINEAR_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PALMYRENE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::NABATAEAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OLD_NORTH_ARABIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MANICHAEAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PSALTER_PAHLAVI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MAHAJANI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SINHALA_ARCHAIC_NUMBERS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KHOJKI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KHUDAWADI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GRANTHA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TIRHUTA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SIDDHAM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MODI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::WARANG_CITI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PAU_CIN_HAU = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MRO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BASSA_VAH = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::PAHAWH_HMONG = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::DUPLOYAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SHORTHAND_FORMAT_CONTROLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MENDE_KIKAKUI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ORNAMENTAL_DINGBATS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GEOMETRIC_SHAPES_EXTENDED = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUPPLEMENTAL_ARROWS_C = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CHEROKEE_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HATRAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OLD_HUNGARIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MULTANI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::AHOM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::EARLY_DYNASTIC_CUNEIFORM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ANATOLIAN_HIEROGLYPHS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUTTON_SIGNWRITING = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SYRIAC_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CYRILLIC_EXTENDED_C = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OSAGE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::NEWA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MONGOLIAN_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MARCHEN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TANGUT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TANGUT_COMPONENTS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KANA_EXTENDED_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GLAGOLITIC_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ADLAM = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MASARAM_GONDI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ZANABAZAR_SQUARE = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::NUSHU = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SOYOMBO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::BHAIKSUKI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GEORGIAN_EXTENDED = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::HANIFI_ROHINGYA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OLD_SOGDIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SOGDIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::DOGRA = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::GUNJALA_GONDI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MAKASAR = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MEDEFAIDRIN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::MAYAN_NUMERALS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::INDIC_SIYAQ_NUMBERS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CHESS_SYMBOLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::ELYMAIC = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::NANDINAGARI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TAMIL_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::EGYPTIAN_HIEROGLYPH_FORMAT_CONTROLS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SMALL_KANA_EXTENSION = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::NYIAKENG_PUACHUE_HMONG = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::WANCHO = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::OTTOMAN_SIYAQ_NUMBERS = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SYMBOLS_AND_PICTOGRAPHS_EXTENDED_A = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::YEZIDI = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CHORASMIAN = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::DIVES_AKURU = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::LISU_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::KHITAN_SMALL_SCRIPT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::TANGUT_SUPPLEMENT = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::SYMBOLS_FOR_LEGACY_COMPUTING = nullptr;
Character$UnicodeBlock* Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_G = nullptr;
$ints* Character$UnicodeBlock::blockStarts = nullptr;
$Character$UnicodeBlockArray* Character$UnicodeBlock::blocks = nullptr;

void Character$UnicodeBlock::init$($String* idName) {
	$Character$Subset::init$(idName);
	$nc(Character$UnicodeBlock::map)->put(idName, this);
}

void Character$UnicodeBlock::init$($String* idName, $String* alias) {
	Character$UnicodeBlock::init$(idName);
	$nc(Character$UnicodeBlock::map)->put(alias, this);
}

void Character$UnicodeBlock::init$($String* idName, $StringArray* aliases) {
	$useLocalCurrentObjectStackCache();
	Character$UnicodeBlock::init$(idName);
	{
		$var($StringArray, arr$, aliases);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, alias, arr$->get(i$));
			$nc(Character$UnicodeBlock::map)->put(alias, this);
		}
	}
}

Character$UnicodeBlock* Character$UnicodeBlock::of(char16_t c) {
	$init(Character$UnicodeBlock);
	return of((int32_t)c);
}

Character$UnicodeBlock* Character$UnicodeBlock::of(int32_t codePoint) {
	$init(Character$UnicodeBlock);
	$useLocalCurrentObjectStackCache();
	if (!$Character::isValidCodePoint(codePoint)) {
		$throwNew($IllegalArgumentException, $($String::format("Not a valid Unicode code point: 0x%X"_s, $$new($ObjectArray, {$($of($Integer::valueOf(codePoint)))}))));
	}
	int32_t top = 0;
	int32_t bottom = 0;
	int32_t current = 0;
	bottom = 0;
	top = $nc(Character$UnicodeBlock::blockStarts)->length;
	current = top / 2;
	while (top - bottom > 1) {
		if (codePoint >= $nc(Character$UnicodeBlock::blockStarts)->get(current)) {
			bottom = current;
		} else {
			top = current;
		}
		current = (top + bottom) / 2;
	}
	return $nc(Character$UnicodeBlock::blocks)->get(current);
}

Character$UnicodeBlock* Character$UnicodeBlock::forName($String* blockName) {
	$init(Character$UnicodeBlock);
	$useLocalCurrentObjectStackCache();
	$init($Locale);
	$var(Character$UnicodeBlock, block, $cast(Character$UnicodeBlock, $nc(Character$UnicodeBlock::map)->get($($nc(blockName)->toUpperCase($Locale::US)))));
	if (block == nullptr) {
		$throwNew($IllegalArgumentException, $$str({"Not a valid block name: "_s, blockName}));
	}
	return block;
}

void clinit$Character$UnicodeBlock($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Character$UnicodeBlock::map, $new($HashMap, $cast(int32_t, (Character$UnicodeBlock::NUM_ENTITIES / 0.75f + 1.0f))));
	$assignStatic(Character$UnicodeBlock::BASIC_LATIN, $new(Character$UnicodeBlock, "BASIC_LATIN"_s, $$new($StringArray, {
		"BASIC LATIN"_s,
		"BASICLATIN"_s
	})));
	$assignStatic(Character$UnicodeBlock::LATIN_1_SUPPLEMENT, $new(Character$UnicodeBlock, "LATIN_1_SUPPLEMENT"_s, $$new($StringArray, {
		"LATIN-1 SUPPLEMENT"_s,
		"LATIN-1SUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::LATIN_EXTENDED_A, $new(Character$UnicodeBlock, "LATIN_EXTENDED_A"_s, $$new($StringArray, {
		"LATIN EXTENDED-A"_s,
		"LATINEXTENDED-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::LATIN_EXTENDED_B, $new(Character$UnicodeBlock, "LATIN_EXTENDED_B"_s, $$new($StringArray, {
		"LATIN EXTENDED-B"_s,
		"LATINEXTENDED-B"_s
	})));
	$assignStatic(Character$UnicodeBlock::IPA_EXTENSIONS, $new(Character$UnicodeBlock, "IPA_EXTENSIONS"_s, $$new($StringArray, {
		"IPA EXTENSIONS"_s,
		"IPAEXTENSIONS"_s
	})));
	$assignStatic(Character$UnicodeBlock::SPACING_MODIFIER_LETTERS, $new(Character$UnicodeBlock, "SPACING_MODIFIER_LETTERS"_s, $$new($StringArray, {
		"SPACING MODIFIER LETTERS"_s,
		"SPACINGMODIFIERLETTERS"_s
	})));
	$assignStatic(Character$UnicodeBlock::COMBINING_DIACRITICAL_MARKS, $new(Character$UnicodeBlock, "COMBINING_DIACRITICAL_MARKS"_s, $$new($StringArray, {
		"COMBINING DIACRITICAL MARKS"_s,
		"COMBININGDIACRITICALMARKS"_s
	})));
	$assignStatic(Character$UnicodeBlock::GREEK, $new(Character$UnicodeBlock, "GREEK"_s, $$new($StringArray, {
		"GREEK AND COPTIC"_s,
		"GREEKANDCOPTIC"_s
	})));
	$assignStatic(Character$UnicodeBlock::CYRILLIC, $new(Character$UnicodeBlock, "CYRILLIC"_s));
	$assignStatic(Character$UnicodeBlock::ARMENIAN, $new(Character$UnicodeBlock, "ARMENIAN"_s));
	$assignStatic(Character$UnicodeBlock::HEBREW, $new(Character$UnicodeBlock, "HEBREW"_s));
	$assignStatic(Character$UnicodeBlock::ARABIC, $new(Character$UnicodeBlock, "ARABIC"_s));
	$assignStatic(Character$UnicodeBlock::DEVANAGARI, $new(Character$UnicodeBlock, "DEVANAGARI"_s));
	$assignStatic(Character$UnicodeBlock::BENGALI, $new(Character$UnicodeBlock, "BENGALI"_s));
	$assignStatic(Character$UnicodeBlock::GURMUKHI, $new(Character$UnicodeBlock, "GURMUKHI"_s));
	$assignStatic(Character$UnicodeBlock::GUJARATI, $new(Character$UnicodeBlock, "GUJARATI"_s));
	$assignStatic(Character$UnicodeBlock::ORIYA, $new(Character$UnicodeBlock, "ORIYA"_s));
	$assignStatic(Character$UnicodeBlock::TAMIL, $new(Character$UnicodeBlock, "TAMIL"_s));
	$assignStatic(Character$UnicodeBlock::TELUGU, $new(Character$UnicodeBlock, "TELUGU"_s));
	$assignStatic(Character$UnicodeBlock::KANNADA, $new(Character$UnicodeBlock, "KANNADA"_s));
	$assignStatic(Character$UnicodeBlock::MALAYALAM, $new(Character$UnicodeBlock, "MALAYALAM"_s));
	$assignStatic(Character$UnicodeBlock::THAI, $new(Character$UnicodeBlock, "THAI"_s));
	$assignStatic(Character$UnicodeBlock::LAO, $new(Character$UnicodeBlock, "LAO"_s));
	$assignStatic(Character$UnicodeBlock::TIBETAN, $new(Character$UnicodeBlock, "TIBETAN"_s));
	$assignStatic(Character$UnicodeBlock::GEORGIAN, $new(Character$UnicodeBlock, "GEORGIAN"_s));
	$assignStatic(Character$UnicodeBlock::HANGUL_JAMO, $new(Character$UnicodeBlock, "HANGUL_JAMO"_s, $$new($StringArray, {
		"HANGUL JAMO"_s,
		"HANGULJAMO"_s
	})));
	$assignStatic(Character$UnicodeBlock::LATIN_EXTENDED_ADDITIONAL, $new(Character$UnicodeBlock, "LATIN_EXTENDED_ADDITIONAL"_s, $$new($StringArray, {
		"LATIN EXTENDED ADDITIONAL"_s,
		"LATINEXTENDEDADDITIONAL"_s
	})));
	$assignStatic(Character$UnicodeBlock::GREEK_EXTENDED, $new(Character$UnicodeBlock, "GREEK_EXTENDED"_s, $$new($StringArray, {
		"GREEK EXTENDED"_s,
		"GREEKEXTENDED"_s
	})));
	$assignStatic(Character$UnicodeBlock::GENERAL_PUNCTUATION, $new(Character$UnicodeBlock, "GENERAL_PUNCTUATION"_s, $$new($StringArray, {
		"GENERAL PUNCTUATION"_s,
		"GENERALPUNCTUATION"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUPERSCRIPTS_AND_SUBSCRIPTS, $new(Character$UnicodeBlock, "SUPERSCRIPTS_AND_SUBSCRIPTS"_s, $$new($StringArray, {
		"SUPERSCRIPTS AND SUBSCRIPTS"_s,
		"SUPERSCRIPTSANDSUBSCRIPTS"_s
	})));
	$assignStatic(Character$UnicodeBlock::CURRENCY_SYMBOLS, $new(Character$UnicodeBlock, "CURRENCY_SYMBOLS"_s, $$new($StringArray, {
		"CURRENCY SYMBOLS"_s,
		"CURRENCYSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::COMBINING_MARKS_FOR_SYMBOLS, $new(Character$UnicodeBlock, "COMBINING_MARKS_FOR_SYMBOLS"_s, $$new($StringArray, {
		"COMBINING DIACRITICAL MARKS FOR SYMBOLS"_s,
		"COMBININGDIACRITICALMARKSFORSYMBOLS"_s,
		"COMBINING MARKS FOR SYMBOLS"_s,
		"COMBININGMARKSFORSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::LETTERLIKE_SYMBOLS, $new(Character$UnicodeBlock, "LETTERLIKE_SYMBOLS"_s, $$new($StringArray, {
		"LETTERLIKE SYMBOLS"_s,
		"LETTERLIKESYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::NUMBER_FORMS, $new(Character$UnicodeBlock, "NUMBER_FORMS"_s, $$new($StringArray, {
		"NUMBER FORMS"_s,
		"NUMBERFORMS"_s
	})));
	$assignStatic(Character$UnicodeBlock::ARROWS, $new(Character$UnicodeBlock, "ARROWS"_s));
	$assignStatic(Character$UnicodeBlock::MATHEMATICAL_OPERATORS, $new(Character$UnicodeBlock, "MATHEMATICAL_OPERATORS"_s, $$new($StringArray, {
		"MATHEMATICAL OPERATORS"_s,
		"MATHEMATICALOPERATORS"_s
	})));
	$assignStatic(Character$UnicodeBlock::MISCELLANEOUS_TECHNICAL, $new(Character$UnicodeBlock, "MISCELLANEOUS_TECHNICAL"_s, $$new($StringArray, {
		"MISCELLANEOUS TECHNICAL"_s,
		"MISCELLANEOUSTECHNICAL"_s
	})));
	$assignStatic(Character$UnicodeBlock::CONTROL_PICTURES, $new(Character$UnicodeBlock, "CONTROL_PICTURES"_s, $$new($StringArray, {
		"CONTROL PICTURES"_s,
		"CONTROLPICTURES"_s
	})));
	$assignStatic(Character$UnicodeBlock::OPTICAL_CHARACTER_RECOGNITION, $new(Character$UnicodeBlock, "OPTICAL_CHARACTER_RECOGNITION"_s, $$new($StringArray, {
		"OPTICAL CHARACTER RECOGNITION"_s,
		"OPTICALCHARACTERRECOGNITION"_s
	})));
	$assignStatic(Character$UnicodeBlock::ENCLOSED_ALPHANUMERICS, $new(Character$UnicodeBlock, "ENCLOSED_ALPHANUMERICS"_s, $$new($StringArray, {
		"ENCLOSED ALPHANUMERICS"_s,
		"ENCLOSEDALPHANUMERICS"_s
	})));
	$assignStatic(Character$UnicodeBlock::BOX_DRAWING, $new(Character$UnicodeBlock, "BOX_DRAWING"_s, $$new($StringArray, {
		"BOX DRAWING"_s,
		"BOXDRAWING"_s
	})));
	$assignStatic(Character$UnicodeBlock::BLOCK_ELEMENTS, $new(Character$UnicodeBlock, "BLOCK_ELEMENTS"_s, $$new($StringArray, {
		"BLOCK ELEMENTS"_s,
		"BLOCKELEMENTS"_s
	})));
	$assignStatic(Character$UnicodeBlock::GEOMETRIC_SHAPES, $new(Character$UnicodeBlock, "GEOMETRIC_SHAPES"_s, $$new($StringArray, {
		"GEOMETRIC SHAPES"_s,
		"GEOMETRICSHAPES"_s
	})));
	$assignStatic(Character$UnicodeBlock::MISCELLANEOUS_SYMBOLS, $new(Character$UnicodeBlock, "MISCELLANEOUS_SYMBOLS"_s, $$new($StringArray, {
		"MISCELLANEOUS SYMBOLS"_s,
		"MISCELLANEOUSSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::DINGBATS, $new(Character$UnicodeBlock, "DINGBATS"_s));
	$assignStatic(Character$UnicodeBlock::CJK_SYMBOLS_AND_PUNCTUATION, $new(Character$UnicodeBlock, "CJK_SYMBOLS_AND_PUNCTUATION"_s, $$new($StringArray, {
		"CJK SYMBOLS AND PUNCTUATION"_s,
		"CJKSYMBOLSANDPUNCTUATION"_s
	})));
	$assignStatic(Character$UnicodeBlock::HIRAGANA, $new(Character$UnicodeBlock, "HIRAGANA"_s));
	$assignStatic(Character$UnicodeBlock::KATAKANA, $new(Character$UnicodeBlock, "KATAKANA"_s));
	$assignStatic(Character$UnicodeBlock::BOPOMOFO, $new(Character$UnicodeBlock, "BOPOMOFO"_s));
	$assignStatic(Character$UnicodeBlock::HANGUL_COMPATIBILITY_JAMO, $new(Character$UnicodeBlock, "HANGUL_COMPATIBILITY_JAMO"_s, $$new($StringArray, {
		"HANGUL COMPATIBILITY JAMO"_s,
		"HANGULCOMPATIBILITYJAMO"_s
	})));
	$assignStatic(Character$UnicodeBlock::KANBUN, $new(Character$UnicodeBlock, "KANBUN"_s));
	$assignStatic(Character$UnicodeBlock::ENCLOSED_CJK_LETTERS_AND_MONTHS, $new(Character$UnicodeBlock, "ENCLOSED_CJK_LETTERS_AND_MONTHS"_s, $$new($StringArray, {
		"ENCLOSED CJK LETTERS AND MONTHS"_s,
		"ENCLOSEDCJKLETTERSANDMONTHS"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_COMPATIBILITY, $new(Character$UnicodeBlock, "CJK_COMPATIBILITY"_s, $$new($StringArray, {
		"CJK COMPATIBILITY"_s,
		"CJKCOMPATIBILITY"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS, $new(Character$UnicodeBlock, "CJK_UNIFIED_IDEOGRAPHS"_s, $$new($StringArray, {
		"CJK UNIFIED IDEOGRAPHS"_s,
		"CJKUNIFIEDIDEOGRAPHS"_s
	})));
	$assignStatic(Character$UnicodeBlock::HANGUL_SYLLABLES, $new(Character$UnicodeBlock, "HANGUL_SYLLABLES"_s, $$new($StringArray, {
		"HANGUL SYLLABLES"_s,
		"HANGULSYLLABLES"_s
	})));
	$assignStatic(Character$UnicodeBlock::PRIVATE_USE_AREA, $new(Character$UnicodeBlock, "PRIVATE_USE_AREA"_s, $$new($StringArray, {
		"PRIVATE USE AREA"_s,
		"PRIVATEUSEAREA"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_COMPATIBILITY_IDEOGRAPHS, $new(Character$UnicodeBlock, "CJK_COMPATIBILITY_IDEOGRAPHS"_s, $$new($StringArray, {
		"CJK COMPATIBILITY IDEOGRAPHS"_s,
		"CJKCOMPATIBILITYIDEOGRAPHS"_s
	})));
	$assignStatic(Character$UnicodeBlock::ALPHABETIC_PRESENTATION_FORMS, $new(Character$UnicodeBlock, "ALPHABETIC_PRESENTATION_FORMS"_s, $$new($StringArray, {
		"ALPHABETIC PRESENTATION FORMS"_s,
		"ALPHABETICPRESENTATIONFORMS"_s
	})));
	$assignStatic(Character$UnicodeBlock::ARABIC_PRESENTATION_FORMS_A, $new(Character$UnicodeBlock, "ARABIC_PRESENTATION_FORMS_A"_s, $$new($StringArray, {
		"ARABIC PRESENTATION FORMS-A"_s,
		"ARABICPRESENTATIONFORMS-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::COMBINING_HALF_MARKS, $new(Character$UnicodeBlock, "COMBINING_HALF_MARKS"_s, $$new($StringArray, {
		"COMBINING HALF MARKS"_s,
		"COMBININGHALFMARKS"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_COMPATIBILITY_FORMS, $new(Character$UnicodeBlock, "CJK_COMPATIBILITY_FORMS"_s, $$new($StringArray, {
		"CJK COMPATIBILITY FORMS"_s,
		"CJKCOMPATIBILITYFORMS"_s
	})));
	$assignStatic(Character$UnicodeBlock::SMALL_FORM_VARIANTS, $new(Character$UnicodeBlock, "SMALL_FORM_VARIANTS"_s, $$new($StringArray, {
		"SMALL FORM VARIANTS"_s,
		"SMALLFORMVARIANTS"_s
	})));
	$assignStatic(Character$UnicodeBlock::ARABIC_PRESENTATION_FORMS_B, $new(Character$UnicodeBlock, "ARABIC_PRESENTATION_FORMS_B"_s, $$new($StringArray, {
		"ARABIC PRESENTATION FORMS-B"_s,
		"ARABICPRESENTATIONFORMS-B"_s
	})));
	$assignStatic(Character$UnicodeBlock::HALFWIDTH_AND_FULLWIDTH_FORMS, $new(Character$UnicodeBlock, "HALFWIDTH_AND_FULLWIDTH_FORMS"_s, $$new($StringArray, {
		"HALFWIDTH AND FULLWIDTH FORMS"_s,
		"HALFWIDTHANDFULLWIDTHFORMS"_s
	})));
	$assignStatic(Character$UnicodeBlock::SPECIALS, $new(Character$UnicodeBlock, "SPECIALS"_s));
	$assignStatic(Character$UnicodeBlock::SURROGATES_AREA, $new(Character$UnicodeBlock, "SURROGATES_AREA"_s));
	$assignStatic(Character$UnicodeBlock::SYRIAC, $new(Character$UnicodeBlock, "SYRIAC"_s));
	$assignStatic(Character$UnicodeBlock::THAANA, $new(Character$UnicodeBlock, "THAANA"_s));
	$assignStatic(Character$UnicodeBlock::SINHALA, $new(Character$UnicodeBlock, "SINHALA"_s));
	$assignStatic(Character$UnicodeBlock::MYANMAR, $new(Character$UnicodeBlock, "MYANMAR"_s));
	$assignStatic(Character$UnicodeBlock::ETHIOPIC, $new(Character$UnicodeBlock, "ETHIOPIC"_s));
	$assignStatic(Character$UnicodeBlock::CHEROKEE, $new(Character$UnicodeBlock, "CHEROKEE"_s));
	$assignStatic(Character$UnicodeBlock::UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS, $new(Character$UnicodeBlock, "UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS"_s, $$new($StringArray, {
		"UNIFIED CANADIAN ABORIGINAL SYLLABICS"_s,
		"UNIFIEDCANADIANABORIGINALSYLLABICS"_s
	})));
	$assignStatic(Character$UnicodeBlock::OGHAM, $new(Character$UnicodeBlock, "OGHAM"_s));
	$assignStatic(Character$UnicodeBlock::RUNIC, $new(Character$UnicodeBlock, "RUNIC"_s));
	$assignStatic(Character$UnicodeBlock::KHMER, $new(Character$UnicodeBlock, "KHMER"_s));
	$assignStatic(Character$UnicodeBlock::MONGOLIAN, $new(Character$UnicodeBlock, "MONGOLIAN"_s));
	$assignStatic(Character$UnicodeBlock::BRAILLE_PATTERNS, $new(Character$UnicodeBlock, "BRAILLE_PATTERNS"_s, $$new($StringArray, {
		"BRAILLE PATTERNS"_s,
		"BRAILLEPATTERNS"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_RADICALS_SUPPLEMENT, $new(Character$UnicodeBlock, "CJK_RADICALS_SUPPLEMENT"_s, $$new($StringArray, {
		"CJK RADICALS SUPPLEMENT"_s,
		"CJKRADICALSSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::KANGXI_RADICALS, $new(Character$UnicodeBlock, "KANGXI_RADICALS"_s, $$new($StringArray, {
		"KANGXI RADICALS"_s,
		"KANGXIRADICALS"_s
	})));
	$assignStatic(Character$UnicodeBlock::IDEOGRAPHIC_DESCRIPTION_CHARACTERS, $new(Character$UnicodeBlock, "IDEOGRAPHIC_DESCRIPTION_CHARACTERS"_s, $$new($StringArray, {
		"IDEOGRAPHIC DESCRIPTION CHARACTERS"_s,
		"IDEOGRAPHICDESCRIPTIONCHARACTERS"_s
	})));
	$assignStatic(Character$UnicodeBlock::BOPOMOFO_EXTENDED, $new(Character$UnicodeBlock, "BOPOMOFO_EXTENDED"_s, $$new($StringArray, {
		"BOPOMOFO EXTENDED"_s,
		"BOPOMOFOEXTENDED"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A, $new(Character$UnicodeBlock, "CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A"_s, $$new($StringArray, {
		"CJK UNIFIED IDEOGRAPHS EXTENSION A"_s,
		"CJKUNIFIEDIDEOGRAPHSEXTENSIONA"_s
	})));
	$assignStatic(Character$UnicodeBlock::YI_SYLLABLES, $new(Character$UnicodeBlock, "YI_SYLLABLES"_s, $$new($StringArray, {
		"YI SYLLABLES"_s,
		"YISYLLABLES"_s
	})));
	$assignStatic(Character$UnicodeBlock::YI_RADICALS, $new(Character$UnicodeBlock, "YI_RADICALS"_s, $$new($StringArray, {
		"YI RADICALS"_s,
		"YIRADICALS"_s
	})));
	$assignStatic(Character$UnicodeBlock::CYRILLIC_SUPPLEMENTARY, $new(Character$UnicodeBlock, "CYRILLIC_SUPPLEMENTARY"_s, $$new($StringArray, {
		"CYRILLIC SUPPLEMENTARY"_s,
		"CYRILLICSUPPLEMENTARY"_s,
		"CYRILLIC SUPPLEMENT"_s,
		"CYRILLICSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::TAGALOG, $new(Character$UnicodeBlock, "TAGALOG"_s));
	$assignStatic(Character$UnicodeBlock::HANUNOO, $new(Character$UnicodeBlock, "HANUNOO"_s));
	$assignStatic(Character$UnicodeBlock::BUHID, $new(Character$UnicodeBlock, "BUHID"_s));
	$assignStatic(Character$UnicodeBlock::TAGBANWA, $new(Character$UnicodeBlock, "TAGBANWA"_s));
	$assignStatic(Character$UnicodeBlock::LIMBU, $new(Character$UnicodeBlock, "LIMBU"_s));
	$assignStatic(Character$UnicodeBlock::TAI_LE, $new(Character$UnicodeBlock, "TAI_LE"_s, $$new($StringArray, {
		"TAI LE"_s,
		"TAILE"_s
	})));
	$assignStatic(Character$UnicodeBlock::KHMER_SYMBOLS, $new(Character$UnicodeBlock, "KHMER_SYMBOLS"_s, $$new($StringArray, {
		"KHMER SYMBOLS"_s,
		"KHMERSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::PHONETIC_EXTENSIONS, $new(Character$UnicodeBlock, "PHONETIC_EXTENSIONS"_s, $$new($StringArray, {
		"PHONETIC EXTENSIONS"_s,
		"PHONETICEXTENSIONS"_s
	})));
	$assignStatic(Character$UnicodeBlock::MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A, $new(Character$UnicodeBlock, "MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A"_s, $$new($StringArray, {
		"MISCELLANEOUS MATHEMATICAL SYMBOLS-A"_s,
		"MISCELLANEOUSMATHEMATICALSYMBOLS-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUPPLEMENTAL_ARROWS_A, $new(Character$UnicodeBlock, "SUPPLEMENTAL_ARROWS_A"_s, $$new($StringArray, {
		"SUPPLEMENTAL ARROWS-A"_s,
		"SUPPLEMENTALARROWS-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUPPLEMENTAL_ARROWS_B, $new(Character$UnicodeBlock, "SUPPLEMENTAL_ARROWS_B"_s, $$new($StringArray, {
		"SUPPLEMENTAL ARROWS-B"_s,
		"SUPPLEMENTALARROWS-B"_s
	})));
	$assignStatic(Character$UnicodeBlock::MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B, $new(Character$UnicodeBlock, "MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B"_s, $$new($StringArray, {
		"MISCELLANEOUS MATHEMATICAL SYMBOLS-B"_s,
		"MISCELLANEOUSMATHEMATICALSYMBOLS-B"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUPPLEMENTAL_MATHEMATICAL_OPERATORS, $new(Character$UnicodeBlock, "SUPPLEMENTAL_MATHEMATICAL_OPERATORS"_s, $$new($StringArray, {
		"SUPPLEMENTAL MATHEMATICAL OPERATORS"_s,
		"SUPPLEMENTALMATHEMATICALOPERATORS"_s
	})));
	$assignStatic(Character$UnicodeBlock::MISCELLANEOUS_SYMBOLS_AND_ARROWS, $new(Character$UnicodeBlock, "MISCELLANEOUS_SYMBOLS_AND_ARROWS"_s, $$new($StringArray, {
		"MISCELLANEOUS SYMBOLS AND ARROWS"_s,
		"MISCELLANEOUSSYMBOLSANDARROWS"_s
	})));
	$assignStatic(Character$UnicodeBlock::KATAKANA_PHONETIC_EXTENSIONS, $new(Character$UnicodeBlock, "KATAKANA_PHONETIC_EXTENSIONS"_s, $$new($StringArray, {
		"KATAKANA PHONETIC EXTENSIONS"_s,
		"KATAKANAPHONETICEXTENSIONS"_s
	})));
	$assignStatic(Character$UnicodeBlock::YIJING_HEXAGRAM_SYMBOLS, $new(Character$UnicodeBlock, "YIJING_HEXAGRAM_SYMBOLS"_s, $$new($StringArray, {
		"YIJING HEXAGRAM SYMBOLS"_s,
		"YIJINGHEXAGRAMSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::VARIATION_SELECTORS, $new(Character$UnicodeBlock, "VARIATION_SELECTORS"_s, $$new($StringArray, {
		"VARIATION SELECTORS"_s,
		"VARIATIONSELECTORS"_s
	})));
	$assignStatic(Character$UnicodeBlock::LINEAR_B_SYLLABARY, $new(Character$UnicodeBlock, "LINEAR_B_SYLLABARY"_s, $$new($StringArray, {
		"LINEAR B SYLLABARY"_s,
		"LINEARBSYLLABARY"_s
	})));
	$assignStatic(Character$UnicodeBlock::LINEAR_B_IDEOGRAMS, $new(Character$UnicodeBlock, "LINEAR_B_IDEOGRAMS"_s, $$new($StringArray, {
		"LINEAR B IDEOGRAMS"_s,
		"LINEARBIDEOGRAMS"_s
	})));
	$assignStatic(Character$UnicodeBlock::AEGEAN_NUMBERS, $new(Character$UnicodeBlock, "AEGEAN_NUMBERS"_s, $$new($StringArray, {
		"AEGEAN NUMBERS"_s,
		"AEGEANNUMBERS"_s
	})));
	$assignStatic(Character$UnicodeBlock::OLD_ITALIC, $new(Character$UnicodeBlock, "OLD_ITALIC"_s, $$new($StringArray, {
		"OLD ITALIC"_s,
		"OLDITALIC"_s
	})));
	$assignStatic(Character$UnicodeBlock::GOTHIC, $new(Character$UnicodeBlock, "GOTHIC"_s));
	$assignStatic(Character$UnicodeBlock::UGARITIC, $new(Character$UnicodeBlock, "UGARITIC"_s));
	$assignStatic(Character$UnicodeBlock::DESERET, $new(Character$UnicodeBlock, "DESERET"_s));
	$assignStatic(Character$UnicodeBlock::SHAVIAN, $new(Character$UnicodeBlock, "SHAVIAN"_s));
	$assignStatic(Character$UnicodeBlock::OSMANYA, $new(Character$UnicodeBlock, "OSMANYA"_s));
	$assignStatic(Character$UnicodeBlock::CYPRIOT_SYLLABARY, $new(Character$UnicodeBlock, "CYPRIOT_SYLLABARY"_s, $$new($StringArray, {
		"CYPRIOT SYLLABARY"_s,
		"CYPRIOTSYLLABARY"_s
	})));
	$assignStatic(Character$UnicodeBlock::BYZANTINE_MUSICAL_SYMBOLS, $new(Character$UnicodeBlock, "BYZANTINE_MUSICAL_SYMBOLS"_s, $$new($StringArray, {
		"BYZANTINE MUSICAL SYMBOLS"_s,
		"BYZANTINEMUSICALSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::MUSICAL_SYMBOLS, $new(Character$UnicodeBlock, "MUSICAL_SYMBOLS"_s, $$new($StringArray, {
		"MUSICAL SYMBOLS"_s,
		"MUSICALSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::TAI_XUAN_JING_SYMBOLS, $new(Character$UnicodeBlock, "TAI_XUAN_JING_SYMBOLS"_s, $$new($StringArray, {
		"TAI XUAN JING SYMBOLS"_s,
		"TAIXUANJINGSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::MATHEMATICAL_ALPHANUMERIC_SYMBOLS, $new(Character$UnicodeBlock, "MATHEMATICAL_ALPHANUMERIC_SYMBOLS"_s, $$new($StringArray, {
		"MATHEMATICAL ALPHANUMERIC SYMBOLS"_s,
		"MATHEMATICALALPHANUMERICSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B, $new(Character$UnicodeBlock, "CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B"_s, $$new($StringArray, {
		"CJK UNIFIED IDEOGRAPHS EXTENSION B"_s,
		"CJKUNIFIEDIDEOGRAPHSEXTENSIONB"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT, $new(Character$UnicodeBlock, "CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT"_s, $$new($StringArray, {
		"CJK COMPATIBILITY IDEOGRAPHS SUPPLEMENT"_s,
		"CJKCOMPATIBILITYIDEOGRAPHSSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::TAGS, $new(Character$UnicodeBlock, "TAGS"_s));
	$assignStatic(Character$UnicodeBlock::VARIATION_SELECTORS_SUPPLEMENT, $new(Character$UnicodeBlock, "VARIATION_SELECTORS_SUPPLEMENT"_s, $$new($StringArray, {
		"VARIATION SELECTORS SUPPLEMENT"_s,
		"VARIATIONSELECTORSSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUPPLEMENTARY_PRIVATE_USE_AREA_A, $new(Character$UnicodeBlock, "SUPPLEMENTARY_PRIVATE_USE_AREA_A"_s, $$new($StringArray, {
		"SUPPLEMENTARY PRIVATE USE AREA-A"_s,
		"SUPPLEMENTARYPRIVATEUSEAREA-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUPPLEMENTARY_PRIVATE_USE_AREA_B, $new(Character$UnicodeBlock, "SUPPLEMENTARY_PRIVATE_USE_AREA_B"_s, $$new($StringArray, {
		"SUPPLEMENTARY PRIVATE USE AREA-B"_s,
		"SUPPLEMENTARYPRIVATEUSEAREA-B"_s
	})));
	$assignStatic(Character$UnicodeBlock::HIGH_SURROGATES, $new(Character$UnicodeBlock, "HIGH_SURROGATES"_s, $$new($StringArray, {
		"HIGH SURROGATES"_s,
		"HIGHSURROGATES"_s
	})));
	$assignStatic(Character$UnicodeBlock::HIGH_PRIVATE_USE_SURROGATES, $new(Character$UnicodeBlock, "HIGH_PRIVATE_USE_SURROGATES"_s, $$new($StringArray, {
		"HIGH PRIVATE USE SURROGATES"_s,
		"HIGHPRIVATEUSESURROGATES"_s
	})));
	$assignStatic(Character$UnicodeBlock::LOW_SURROGATES, $new(Character$UnicodeBlock, "LOW_SURROGATES"_s, $$new($StringArray, {
		"LOW SURROGATES"_s,
		"LOWSURROGATES"_s
	})));
	$assignStatic(Character$UnicodeBlock::ARABIC_SUPPLEMENT, $new(Character$UnicodeBlock, "ARABIC_SUPPLEMENT"_s, $$new($StringArray, {
		"ARABIC SUPPLEMENT"_s,
		"ARABICSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::NKO, $new(Character$UnicodeBlock, "NKO"_s));
	$assignStatic(Character$UnicodeBlock::SAMARITAN, $new(Character$UnicodeBlock, "SAMARITAN"_s));
	$assignStatic(Character$UnicodeBlock::MANDAIC, $new(Character$UnicodeBlock, "MANDAIC"_s));
	$assignStatic(Character$UnicodeBlock::ETHIOPIC_SUPPLEMENT, $new(Character$UnicodeBlock, "ETHIOPIC_SUPPLEMENT"_s, $$new($StringArray, {
		"ETHIOPIC SUPPLEMENT"_s,
		"ETHIOPICSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED, $new(Character$UnicodeBlock, "UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED"_s, $$new($StringArray, {
		"UNIFIED CANADIAN ABORIGINAL SYLLABICS EXTENDED"_s,
		"UNIFIEDCANADIANABORIGINALSYLLABICSEXTENDED"_s
	})));
	$assignStatic(Character$UnicodeBlock::NEW_TAI_LUE, $new(Character$UnicodeBlock, "NEW_TAI_LUE"_s, $$new($StringArray, {
		"NEW TAI LUE"_s,
		"NEWTAILUE"_s
	})));
	$assignStatic(Character$UnicodeBlock::BUGINESE, $new(Character$UnicodeBlock, "BUGINESE"_s));
	$assignStatic(Character$UnicodeBlock::TAI_THAM, $new(Character$UnicodeBlock, "TAI_THAM"_s, $$new($StringArray, {
		"TAI THAM"_s,
		"TAITHAM"_s
	})));
	$assignStatic(Character$UnicodeBlock::BALINESE, $new(Character$UnicodeBlock, "BALINESE"_s));
	$assignStatic(Character$UnicodeBlock::SUNDANESE, $new(Character$UnicodeBlock, "SUNDANESE"_s));
	$assignStatic(Character$UnicodeBlock::BATAK, $new(Character$UnicodeBlock, "BATAK"_s));
	$assignStatic(Character$UnicodeBlock::LEPCHA, $new(Character$UnicodeBlock, "LEPCHA"_s));
	$assignStatic(Character$UnicodeBlock::OL_CHIKI, $new(Character$UnicodeBlock, "OL_CHIKI"_s, $$new($StringArray, {
		"OL CHIKI"_s,
		"OLCHIKI"_s
	})));
	$assignStatic(Character$UnicodeBlock::VEDIC_EXTENSIONS, $new(Character$UnicodeBlock, "VEDIC_EXTENSIONS"_s, $$new($StringArray, {
		"VEDIC EXTENSIONS"_s,
		"VEDICEXTENSIONS"_s
	})));
	$assignStatic(Character$UnicodeBlock::PHONETIC_EXTENSIONS_SUPPLEMENT, $new(Character$UnicodeBlock, "PHONETIC_EXTENSIONS_SUPPLEMENT"_s, $$new($StringArray, {
		"PHONETIC EXTENSIONS SUPPLEMENT"_s,
		"PHONETICEXTENSIONSSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::COMBINING_DIACRITICAL_MARKS_SUPPLEMENT, $new(Character$UnicodeBlock, "COMBINING_DIACRITICAL_MARKS_SUPPLEMENT"_s, $$new($StringArray, {
		"COMBINING DIACRITICAL MARKS SUPPLEMENT"_s,
		"COMBININGDIACRITICALMARKSSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::GLAGOLITIC, $new(Character$UnicodeBlock, "GLAGOLITIC"_s));
	$assignStatic(Character$UnicodeBlock::LATIN_EXTENDED_C, $new(Character$UnicodeBlock, "LATIN_EXTENDED_C"_s, $$new($StringArray, {
		"LATIN EXTENDED-C"_s,
		"LATINEXTENDED-C"_s
	})));
	$assignStatic(Character$UnicodeBlock::COPTIC, $new(Character$UnicodeBlock, "COPTIC"_s));
	$assignStatic(Character$UnicodeBlock::GEORGIAN_SUPPLEMENT, $new(Character$UnicodeBlock, "GEORGIAN_SUPPLEMENT"_s, $$new($StringArray, {
		"GEORGIAN SUPPLEMENT"_s,
		"GEORGIANSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::TIFINAGH, $new(Character$UnicodeBlock, "TIFINAGH"_s));
	$assignStatic(Character$UnicodeBlock::ETHIOPIC_EXTENDED, $new(Character$UnicodeBlock, "ETHIOPIC_EXTENDED"_s, $$new($StringArray, {
		"ETHIOPIC EXTENDED"_s,
		"ETHIOPICEXTENDED"_s
	})));
	$assignStatic(Character$UnicodeBlock::CYRILLIC_EXTENDED_A, $new(Character$UnicodeBlock, "CYRILLIC_EXTENDED_A"_s, $$new($StringArray, {
		"CYRILLIC EXTENDED-A"_s,
		"CYRILLICEXTENDED-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUPPLEMENTAL_PUNCTUATION, $new(Character$UnicodeBlock, "SUPPLEMENTAL_PUNCTUATION"_s, $$new($StringArray, {
		"SUPPLEMENTAL PUNCTUATION"_s,
		"SUPPLEMENTALPUNCTUATION"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_STROKES, $new(Character$UnicodeBlock, "CJK_STROKES"_s, $$new($StringArray, {
		"CJK STROKES"_s,
		"CJKSTROKES"_s
	})));
	$assignStatic(Character$UnicodeBlock::LISU, $new(Character$UnicodeBlock, "LISU"_s));
	$assignStatic(Character$UnicodeBlock::VAI, $new(Character$UnicodeBlock, "VAI"_s));
	$assignStatic(Character$UnicodeBlock::CYRILLIC_EXTENDED_B, $new(Character$UnicodeBlock, "CYRILLIC_EXTENDED_B"_s, $$new($StringArray, {
		"CYRILLIC EXTENDED-B"_s,
		"CYRILLICEXTENDED-B"_s
	})));
	$assignStatic(Character$UnicodeBlock::BAMUM, $new(Character$UnicodeBlock, "BAMUM"_s));
	$assignStatic(Character$UnicodeBlock::MODIFIER_TONE_LETTERS, $new(Character$UnicodeBlock, "MODIFIER_TONE_LETTERS"_s, $$new($StringArray, {
		"MODIFIER TONE LETTERS"_s,
		"MODIFIERTONELETTERS"_s
	})));
	$assignStatic(Character$UnicodeBlock::LATIN_EXTENDED_D, $new(Character$UnicodeBlock, "LATIN_EXTENDED_D"_s, $$new($StringArray, {
		"LATIN EXTENDED-D"_s,
		"LATINEXTENDED-D"_s
	})));
	$assignStatic(Character$UnicodeBlock::SYLOTI_NAGRI, $new(Character$UnicodeBlock, "SYLOTI_NAGRI"_s, $$new($StringArray, {
		"SYLOTI NAGRI"_s,
		"SYLOTINAGRI"_s
	})));
	$assignStatic(Character$UnicodeBlock::COMMON_INDIC_NUMBER_FORMS, $new(Character$UnicodeBlock, "COMMON_INDIC_NUMBER_FORMS"_s, $$new($StringArray, {
		"COMMON INDIC NUMBER FORMS"_s,
		"COMMONINDICNUMBERFORMS"_s
	})));
	$assignStatic(Character$UnicodeBlock::PHAGS_PA, $new(Character$UnicodeBlock, "PHAGS_PA"_s, "PHAGS-PA"_s));
	$assignStatic(Character$UnicodeBlock::SAURASHTRA, $new(Character$UnicodeBlock, "SAURASHTRA"_s));
	$assignStatic(Character$UnicodeBlock::DEVANAGARI_EXTENDED, $new(Character$UnicodeBlock, "DEVANAGARI_EXTENDED"_s, $$new($StringArray, {
		"DEVANAGARI EXTENDED"_s,
		"DEVANAGARIEXTENDED"_s
	})));
	$assignStatic(Character$UnicodeBlock::KAYAH_LI, $new(Character$UnicodeBlock, "KAYAH_LI"_s, $$new($StringArray, {
		"KAYAH LI"_s,
		"KAYAHLI"_s
	})));
	$assignStatic(Character$UnicodeBlock::REJANG, $new(Character$UnicodeBlock, "REJANG"_s));
	$assignStatic(Character$UnicodeBlock::HANGUL_JAMO_EXTENDED_A, $new(Character$UnicodeBlock, "HANGUL_JAMO_EXTENDED_A"_s, $$new($StringArray, {
		"HANGUL JAMO EXTENDED-A"_s,
		"HANGULJAMOEXTENDED-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::JAVANESE, $new(Character$UnicodeBlock, "JAVANESE"_s));
	$assignStatic(Character$UnicodeBlock::CHAM, $new(Character$UnicodeBlock, "CHAM"_s));
	$assignStatic(Character$UnicodeBlock::MYANMAR_EXTENDED_A, $new(Character$UnicodeBlock, "MYANMAR_EXTENDED_A"_s, $$new($StringArray, {
		"MYANMAR EXTENDED-A"_s,
		"MYANMAREXTENDED-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::TAI_VIET, $new(Character$UnicodeBlock, "TAI_VIET"_s, $$new($StringArray, {
		"TAI VIET"_s,
		"TAIVIET"_s
	})));
	$assignStatic(Character$UnicodeBlock::ETHIOPIC_EXTENDED_A, $new(Character$UnicodeBlock, "ETHIOPIC_EXTENDED_A"_s, $$new($StringArray, {
		"ETHIOPIC EXTENDED-A"_s,
		"ETHIOPICEXTENDED-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::MEETEI_MAYEK, $new(Character$UnicodeBlock, "MEETEI_MAYEK"_s, $$new($StringArray, {
		"MEETEI MAYEK"_s,
		"MEETEIMAYEK"_s
	})));
	$assignStatic(Character$UnicodeBlock::HANGUL_JAMO_EXTENDED_B, $new(Character$UnicodeBlock, "HANGUL_JAMO_EXTENDED_B"_s, $$new($StringArray, {
		"HANGUL JAMO EXTENDED-B"_s,
		"HANGULJAMOEXTENDED-B"_s
	})));
	$assignStatic(Character$UnicodeBlock::VERTICAL_FORMS, $new(Character$UnicodeBlock, "VERTICAL_FORMS"_s, $$new($StringArray, {
		"VERTICAL FORMS"_s,
		"VERTICALFORMS"_s
	})));
	$assignStatic(Character$UnicodeBlock::ANCIENT_GREEK_NUMBERS, $new(Character$UnicodeBlock, "ANCIENT_GREEK_NUMBERS"_s, $$new($StringArray, {
		"ANCIENT GREEK NUMBERS"_s,
		"ANCIENTGREEKNUMBERS"_s
	})));
	$assignStatic(Character$UnicodeBlock::ANCIENT_SYMBOLS, $new(Character$UnicodeBlock, "ANCIENT_SYMBOLS"_s, $$new($StringArray, {
		"ANCIENT SYMBOLS"_s,
		"ANCIENTSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::PHAISTOS_DISC, $new(Character$UnicodeBlock, "PHAISTOS_DISC"_s, $$new($StringArray, {
		"PHAISTOS DISC"_s,
		"PHAISTOSDISC"_s
	})));
	$assignStatic(Character$UnicodeBlock::LYCIAN, $new(Character$UnicodeBlock, "LYCIAN"_s));
	$assignStatic(Character$UnicodeBlock::CARIAN, $new(Character$UnicodeBlock, "CARIAN"_s));
	$assignStatic(Character$UnicodeBlock::OLD_PERSIAN, $new(Character$UnicodeBlock, "OLD_PERSIAN"_s, $$new($StringArray, {
		"OLD PERSIAN"_s,
		"OLDPERSIAN"_s
	})));
	$assignStatic(Character$UnicodeBlock::IMPERIAL_ARAMAIC, $new(Character$UnicodeBlock, "IMPERIAL_ARAMAIC"_s, $$new($StringArray, {
		"IMPERIAL ARAMAIC"_s,
		"IMPERIALARAMAIC"_s
	})));
	$assignStatic(Character$UnicodeBlock::PHOENICIAN, $new(Character$UnicodeBlock, "PHOENICIAN"_s));
	$assignStatic(Character$UnicodeBlock::LYDIAN, $new(Character$UnicodeBlock, "LYDIAN"_s));
	$assignStatic(Character$UnicodeBlock::KHAROSHTHI, $new(Character$UnicodeBlock, "KHAROSHTHI"_s));
	$assignStatic(Character$UnicodeBlock::OLD_SOUTH_ARABIAN, $new(Character$UnicodeBlock, "OLD_SOUTH_ARABIAN"_s, $$new($StringArray, {
		"OLD SOUTH ARABIAN"_s,
		"OLDSOUTHARABIAN"_s
	})));
	$assignStatic(Character$UnicodeBlock::AVESTAN, $new(Character$UnicodeBlock, "AVESTAN"_s));
	$assignStatic(Character$UnicodeBlock::INSCRIPTIONAL_PARTHIAN, $new(Character$UnicodeBlock, "INSCRIPTIONAL_PARTHIAN"_s, $$new($StringArray, {
		"INSCRIPTIONAL PARTHIAN"_s,
		"INSCRIPTIONALPARTHIAN"_s
	})));
	$assignStatic(Character$UnicodeBlock::INSCRIPTIONAL_PAHLAVI, $new(Character$UnicodeBlock, "INSCRIPTIONAL_PAHLAVI"_s, $$new($StringArray, {
		"INSCRIPTIONAL PAHLAVI"_s,
		"INSCRIPTIONALPAHLAVI"_s
	})));
	$assignStatic(Character$UnicodeBlock::OLD_TURKIC, $new(Character$UnicodeBlock, "OLD_TURKIC"_s, $$new($StringArray, {
		"OLD TURKIC"_s,
		"OLDTURKIC"_s
	})));
	$assignStatic(Character$UnicodeBlock::RUMI_NUMERAL_SYMBOLS, $new(Character$UnicodeBlock, "RUMI_NUMERAL_SYMBOLS"_s, $$new($StringArray, {
		"RUMI NUMERAL SYMBOLS"_s,
		"RUMINUMERALSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::BRAHMI, $new(Character$UnicodeBlock, "BRAHMI"_s));
	$assignStatic(Character$UnicodeBlock::KAITHI, $new(Character$UnicodeBlock, "KAITHI"_s));
	$assignStatic(Character$UnicodeBlock::CUNEIFORM, $new(Character$UnicodeBlock, "CUNEIFORM"_s));
	$assignStatic(Character$UnicodeBlock::CUNEIFORM_NUMBERS_AND_PUNCTUATION, $new(Character$UnicodeBlock, "CUNEIFORM_NUMBERS_AND_PUNCTUATION"_s, $$new($StringArray, {
		"CUNEIFORM NUMBERS AND PUNCTUATION"_s,
		"CUNEIFORMNUMBERSANDPUNCTUATION"_s
	})));
	$assignStatic(Character$UnicodeBlock::EGYPTIAN_HIEROGLYPHS, $new(Character$UnicodeBlock, "EGYPTIAN_HIEROGLYPHS"_s, $$new($StringArray, {
		"EGYPTIAN HIEROGLYPHS"_s,
		"EGYPTIANHIEROGLYPHS"_s
	})));
	$assignStatic(Character$UnicodeBlock::BAMUM_SUPPLEMENT, $new(Character$UnicodeBlock, "BAMUM_SUPPLEMENT"_s, $$new($StringArray, {
		"BAMUM SUPPLEMENT"_s,
		"BAMUMSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::KANA_SUPPLEMENT, $new(Character$UnicodeBlock, "KANA_SUPPLEMENT"_s, $$new($StringArray, {
		"KANA SUPPLEMENT"_s,
		"KANASUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::ANCIENT_GREEK_MUSICAL_NOTATION, $new(Character$UnicodeBlock, "ANCIENT_GREEK_MUSICAL_NOTATION"_s, $$new($StringArray, {
		"ANCIENT GREEK MUSICAL NOTATION"_s,
		"ANCIENTGREEKMUSICALNOTATION"_s
	})));
	$assignStatic(Character$UnicodeBlock::COUNTING_ROD_NUMERALS, $new(Character$UnicodeBlock, "COUNTING_ROD_NUMERALS"_s, $$new($StringArray, {
		"COUNTING ROD NUMERALS"_s,
		"COUNTINGRODNUMERALS"_s
	})));
	$assignStatic(Character$UnicodeBlock::MAHJONG_TILES, $new(Character$UnicodeBlock, "MAHJONG_TILES"_s, $$new($StringArray, {
		"MAHJONG TILES"_s,
		"MAHJONGTILES"_s
	})));
	$assignStatic(Character$UnicodeBlock::DOMINO_TILES, $new(Character$UnicodeBlock, "DOMINO_TILES"_s, $$new($StringArray, {
		"DOMINO TILES"_s,
		"DOMINOTILES"_s
	})));
	$assignStatic(Character$UnicodeBlock::PLAYING_CARDS, $new(Character$UnicodeBlock, "PLAYING_CARDS"_s, $$new($StringArray, {
		"PLAYING CARDS"_s,
		"PLAYINGCARDS"_s
	})));
	$assignStatic(Character$UnicodeBlock::ENCLOSED_ALPHANUMERIC_SUPPLEMENT, $new(Character$UnicodeBlock, "ENCLOSED_ALPHANUMERIC_SUPPLEMENT"_s, $$new($StringArray, {
		"ENCLOSED ALPHANUMERIC SUPPLEMENT"_s,
		"ENCLOSEDALPHANUMERICSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::ENCLOSED_IDEOGRAPHIC_SUPPLEMENT, $new(Character$UnicodeBlock, "ENCLOSED_IDEOGRAPHIC_SUPPLEMENT"_s, $$new($StringArray, {
		"ENCLOSED IDEOGRAPHIC SUPPLEMENT"_s,
		"ENCLOSEDIDEOGRAPHICSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS, $new(Character$UnicodeBlock, "MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS"_s, $$new($StringArray, {
		"MISCELLANEOUS SYMBOLS AND PICTOGRAPHS"_s,
		"MISCELLANEOUSSYMBOLSANDPICTOGRAPHS"_s
	})));
	$assignStatic(Character$UnicodeBlock::EMOTICONS, $new(Character$UnicodeBlock, "EMOTICONS"_s));
	$assignStatic(Character$UnicodeBlock::TRANSPORT_AND_MAP_SYMBOLS, $new(Character$UnicodeBlock, "TRANSPORT_AND_MAP_SYMBOLS"_s, $$new($StringArray, {
		"TRANSPORT AND MAP SYMBOLS"_s,
		"TRANSPORTANDMAPSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::ALCHEMICAL_SYMBOLS, $new(Character$UnicodeBlock, "ALCHEMICAL_SYMBOLS"_s, $$new($StringArray, {
		"ALCHEMICAL SYMBOLS"_s,
		"ALCHEMICALSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C, $new(Character$UnicodeBlock, "CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C"_s, $$new($StringArray, {
		"CJK UNIFIED IDEOGRAPHS EXTENSION C"_s,
		"CJKUNIFIEDIDEOGRAPHSEXTENSIONC"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D, $new(Character$UnicodeBlock, "CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D"_s, $$new($StringArray, {
		"CJK UNIFIED IDEOGRAPHS EXTENSION D"_s,
		"CJKUNIFIEDIDEOGRAPHSEXTENSIOND"_s
	})));
	$assignStatic(Character$UnicodeBlock::ARABIC_EXTENDED_A, $new(Character$UnicodeBlock, "ARABIC_EXTENDED_A"_s, $$new($StringArray, {
		"ARABIC EXTENDED-A"_s,
		"ARABICEXTENDED-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUNDANESE_SUPPLEMENT, $new(Character$UnicodeBlock, "SUNDANESE_SUPPLEMENT"_s, $$new($StringArray, {
		"SUNDANESE SUPPLEMENT"_s,
		"SUNDANESESUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::MEETEI_MAYEK_EXTENSIONS, $new(Character$UnicodeBlock, "MEETEI_MAYEK_EXTENSIONS"_s, $$new($StringArray, {
		"MEETEI MAYEK EXTENSIONS"_s,
		"MEETEIMAYEKEXTENSIONS"_s
	})));
	$assignStatic(Character$UnicodeBlock::MEROITIC_HIEROGLYPHS, $new(Character$UnicodeBlock, "MEROITIC_HIEROGLYPHS"_s, $$new($StringArray, {
		"MEROITIC HIEROGLYPHS"_s,
		"MEROITICHIEROGLYPHS"_s
	})));
	$assignStatic(Character$UnicodeBlock::MEROITIC_CURSIVE, $new(Character$UnicodeBlock, "MEROITIC_CURSIVE"_s, $$new($StringArray, {
		"MEROITIC CURSIVE"_s,
		"MEROITICCURSIVE"_s
	})));
	$assignStatic(Character$UnicodeBlock::SORA_SOMPENG, $new(Character$UnicodeBlock, "SORA_SOMPENG"_s, $$new($StringArray, {
		"SORA SOMPENG"_s,
		"SORASOMPENG"_s
	})));
	$assignStatic(Character$UnicodeBlock::CHAKMA, $new(Character$UnicodeBlock, "CHAKMA"_s));
	$assignStatic(Character$UnicodeBlock::SHARADA, $new(Character$UnicodeBlock, "SHARADA"_s));
	$assignStatic(Character$UnicodeBlock::TAKRI, $new(Character$UnicodeBlock, "TAKRI"_s));
	$assignStatic(Character$UnicodeBlock::MIAO, $new(Character$UnicodeBlock, "MIAO"_s));
	$assignStatic(Character$UnicodeBlock::ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS, $new(Character$UnicodeBlock, "ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS"_s, $$new($StringArray, {
		"ARABIC MATHEMATICAL ALPHABETIC SYMBOLS"_s,
		"ARABICMATHEMATICALALPHABETICSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::COMBINING_DIACRITICAL_MARKS_EXTENDED, $new(Character$UnicodeBlock, "COMBINING_DIACRITICAL_MARKS_EXTENDED"_s, $$new($StringArray, {
		"COMBINING DIACRITICAL MARKS EXTENDED"_s,
		"COMBININGDIACRITICALMARKSEXTENDED"_s
	})));
	$assignStatic(Character$UnicodeBlock::MYANMAR_EXTENDED_B, $new(Character$UnicodeBlock, "MYANMAR_EXTENDED_B"_s, $$new($StringArray, {
		"MYANMAR EXTENDED-B"_s,
		"MYANMAREXTENDED-B"_s
	})));
	$assignStatic(Character$UnicodeBlock::LATIN_EXTENDED_E, $new(Character$UnicodeBlock, "LATIN_EXTENDED_E"_s, $$new($StringArray, {
		"LATIN EXTENDED-E"_s,
		"LATINEXTENDED-E"_s
	})));
	$assignStatic(Character$UnicodeBlock::COPTIC_EPACT_NUMBERS, $new(Character$UnicodeBlock, "COPTIC_EPACT_NUMBERS"_s, $$new($StringArray, {
		"COPTIC EPACT NUMBERS"_s,
		"COPTICEPACTNUMBERS"_s
	})));
	$assignStatic(Character$UnicodeBlock::OLD_PERMIC, $new(Character$UnicodeBlock, "OLD_PERMIC"_s, $$new($StringArray, {
		"OLD PERMIC"_s,
		"OLDPERMIC"_s
	})));
	$assignStatic(Character$UnicodeBlock::ELBASAN, $new(Character$UnicodeBlock, "ELBASAN"_s));
	$assignStatic(Character$UnicodeBlock::CAUCASIAN_ALBANIAN, $new(Character$UnicodeBlock, "CAUCASIAN_ALBANIAN"_s, $$new($StringArray, {
		"CAUCASIAN ALBANIAN"_s,
		"CAUCASIANALBANIAN"_s
	})));
	$assignStatic(Character$UnicodeBlock::LINEAR_A, $new(Character$UnicodeBlock, "LINEAR_A"_s, $$new($StringArray, {
		"LINEAR A"_s,
		"LINEARA"_s
	})));
	$assignStatic(Character$UnicodeBlock::PALMYRENE, $new(Character$UnicodeBlock, "PALMYRENE"_s));
	$assignStatic(Character$UnicodeBlock::NABATAEAN, $new(Character$UnicodeBlock, "NABATAEAN"_s));
	$assignStatic(Character$UnicodeBlock::OLD_NORTH_ARABIAN, $new(Character$UnicodeBlock, "OLD_NORTH_ARABIAN"_s, $$new($StringArray, {
		"OLD NORTH ARABIAN"_s,
		"OLDNORTHARABIAN"_s
	})));
	$assignStatic(Character$UnicodeBlock::MANICHAEAN, $new(Character$UnicodeBlock, "MANICHAEAN"_s));
	$assignStatic(Character$UnicodeBlock::PSALTER_PAHLAVI, $new(Character$UnicodeBlock, "PSALTER_PAHLAVI"_s, $$new($StringArray, {
		"PSALTER PAHLAVI"_s,
		"PSALTERPAHLAVI"_s
	})));
	$assignStatic(Character$UnicodeBlock::MAHAJANI, $new(Character$UnicodeBlock, "MAHAJANI"_s));
	$assignStatic(Character$UnicodeBlock::SINHALA_ARCHAIC_NUMBERS, $new(Character$UnicodeBlock, "SINHALA_ARCHAIC_NUMBERS"_s, $$new($StringArray, {
		"SINHALA ARCHAIC NUMBERS"_s,
		"SINHALAARCHAICNUMBERS"_s
	})));
	$assignStatic(Character$UnicodeBlock::KHOJKI, $new(Character$UnicodeBlock, "KHOJKI"_s));
	$assignStatic(Character$UnicodeBlock::KHUDAWADI, $new(Character$UnicodeBlock, "KHUDAWADI"_s));
	$assignStatic(Character$UnicodeBlock::GRANTHA, $new(Character$UnicodeBlock, "GRANTHA"_s));
	$assignStatic(Character$UnicodeBlock::TIRHUTA, $new(Character$UnicodeBlock, "TIRHUTA"_s));
	$assignStatic(Character$UnicodeBlock::SIDDHAM, $new(Character$UnicodeBlock, "SIDDHAM"_s));
	$assignStatic(Character$UnicodeBlock::MODI, $new(Character$UnicodeBlock, "MODI"_s));
	$assignStatic(Character$UnicodeBlock::WARANG_CITI, $new(Character$UnicodeBlock, "WARANG_CITI"_s, $$new($StringArray, {
		"WARANG CITI"_s,
		"WARANGCITI"_s
	})));
	$assignStatic(Character$UnicodeBlock::PAU_CIN_HAU, $new(Character$UnicodeBlock, "PAU_CIN_HAU"_s, $$new($StringArray, {
		"PAU CIN HAU"_s,
		"PAUCINHAU"_s
	})));
	$assignStatic(Character$UnicodeBlock::MRO, $new(Character$UnicodeBlock, "MRO"_s));
	$assignStatic(Character$UnicodeBlock::BASSA_VAH, $new(Character$UnicodeBlock, "BASSA_VAH"_s, $$new($StringArray, {
		"BASSA VAH"_s,
		"BASSAVAH"_s
	})));
	$assignStatic(Character$UnicodeBlock::PAHAWH_HMONG, $new(Character$UnicodeBlock, "PAHAWH_HMONG"_s, $$new($StringArray, {
		"PAHAWH HMONG"_s,
		"PAHAWHHMONG"_s
	})));
	$assignStatic(Character$UnicodeBlock::DUPLOYAN, $new(Character$UnicodeBlock, "DUPLOYAN"_s));
	$assignStatic(Character$UnicodeBlock::SHORTHAND_FORMAT_CONTROLS, $new(Character$UnicodeBlock, "SHORTHAND_FORMAT_CONTROLS"_s, $$new($StringArray, {
		"SHORTHAND FORMAT CONTROLS"_s,
		"SHORTHANDFORMATCONTROLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::MENDE_KIKAKUI, $new(Character$UnicodeBlock, "MENDE_KIKAKUI"_s, $$new($StringArray, {
		"MENDE KIKAKUI"_s,
		"MENDEKIKAKUI"_s
	})));
	$assignStatic(Character$UnicodeBlock::ORNAMENTAL_DINGBATS, $new(Character$UnicodeBlock, "ORNAMENTAL_DINGBATS"_s, $$new($StringArray, {
		"ORNAMENTAL DINGBATS"_s,
		"ORNAMENTALDINGBATS"_s
	})));
	$assignStatic(Character$UnicodeBlock::GEOMETRIC_SHAPES_EXTENDED, $new(Character$UnicodeBlock, "GEOMETRIC_SHAPES_EXTENDED"_s, $$new($StringArray, {
		"GEOMETRIC SHAPES EXTENDED"_s,
		"GEOMETRICSHAPESEXTENDED"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUPPLEMENTAL_ARROWS_C, $new(Character$UnicodeBlock, "SUPPLEMENTAL_ARROWS_C"_s, $$new($StringArray, {
		"SUPPLEMENTAL ARROWS-C"_s,
		"SUPPLEMENTALARROWS-C"_s
	})));
	$assignStatic(Character$UnicodeBlock::CHEROKEE_SUPPLEMENT, $new(Character$UnicodeBlock, "CHEROKEE_SUPPLEMENT"_s, $$new($StringArray, {
		"CHEROKEE SUPPLEMENT"_s,
		"CHEROKEESUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::HATRAN, $new(Character$UnicodeBlock, "HATRAN"_s));
	$assignStatic(Character$UnicodeBlock::OLD_HUNGARIAN, $new(Character$UnicodeBlock, "OLD_HUNGARIAN"_s, $$new($StringArray, {
		"OLD HUNGARIAN"_s,
		"OLDHUNGARIAN"_s
	})));
	$assignStatic(Character$UnicodeBlock::MULTANI, $new(Character$UnicodeBlock, "MULTANI"_s));
	$assignStatic(Character$UnicodeBlock::AHOM, $new(Character$UnicodeBlock, "AHOM"_s));
	$assignStatic(Character$UnicodeBlock::EARLY_DYNASTIC_CUNEIFORM, $new(Character$UnicodeBlock, "EARLY_DYNASTIC_CUNEIFORM"_s, $$new($StringArray, {
		"EARLY DYNASTIC CUNEIFORM"_s,
		"EARLYDYNASTICCUNEIFORM"_s
	})));
	$assignStatic(Character$UnicodeBlock::ANATOLIAN_HIEROGLYPHS, $new(Character$UnicodeBlock, "ANATOLIAN_HIEROGLYPHS"_s, $$new($StringArray, {
		"ANATOLIAN HIEROGLYPHS"_s,
		"ANATOLIANHIEROGLYPHS"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUTTON_SIGNWRITING, $new(Character$UnicodeBlock, "SUTTON_SIGNWRITING"_s, $$new($StringArray, {
		"SUTTON SIGNWRITING"_s,
		"SUTTONSIGNWRITING"_s
	})));
	$assignStatic(Character$UnicodeBlock::SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS, $new(Character$UnicodeBlock, "SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS"_s, $$new($StringArray, {
		"SUPPLEMENTAL SYMBOLS AND PICTOGRAPHS"_s,
		"SUPPLEMENTALSYMBOLSANDPICTOGRAPHS"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E, $new(Character$UnicodeBlock, "CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E"_s, $$new($StringArray, {
		"CJK UNIFIED IDEOGRAPHS EXTENSION E"_s,
		"CJKUNIFIEDIDEOGRAPHSEXTENSIONE"_s
	})));
	$assignStatic(Character$UnicodeBlock::SYRIAC_SUPPLEMENT, $new(Character$UnicodeBlock, "SYRIAC_SUPPLEMENT"_s, $$new($StringArray, {
		"SYRIAC SUPPLEMENT"_s,
		"SYRIACSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::CYRILLIC_EXTENDED_C, $new(Character$UnicodeBlock, "CYRILLIC_EXTENDED_C"_s, $$new($StringArray, {
		"CYRILLIC EXTENDED-C"_s,
		"CYRILLICEXTENDED-C"_s
	})));
	$assignStatic(Character$UnicodeBlock::OSAGE, $new(Character$UnicodeBlock, "OSAGE"_s));
	$assignStatic(Character$UnicodeBlock::NEWA, $new(Character$UnicodeBlock, "NEWA"_s));
	$assignStatic(Character$UnicodeBlock::MONGOLIAN_SUPPLEMENT, $new(Character$UnicodeBlock, "MONGOLIAN_SUPPLEMENT"_s, $$new($StringArray, {
		"MONGOLIAN SUPPLEMENT"_s,
		"MONGOLIANSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::MARCHEN, $new(Character$UnicodeBlock, "MARCHEN"_s));
	$assignStatic(Character$UnicodeBlock::IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION, $new(Character$UnicodeBlock, "IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION"_s, $$new($StringArray, {
		"IDEOGRAPHIC SYMBOLS AND PUNCTUATION"_s,
		"IDEOGRAPHICSYMBOLSANDPUNCTUATION"_s
	})));
	$assignStatic(Character$UnicodeBlock::TANGUT, $new(Character$UnicodeBlock, "TANGUT"_s));
	$assignStatic(Character$UnicodeBlock::TANGUT_COMPONENTS, $new(Character$UnicodeBlock, "TANGUT_COMPONENTS"_s, $$new($StringArray, {
		"TANGUT COMPONENTS"_s,
		"TANGUTCOMPONENTS"_s
	})));
	$assignStatic(Character$UnicodeBlock::KANA_EXTENDED_A, $new(Character$UnicodeBlock, "KANA_EXTENDED_A"_s, $$new($StringArray, {
		"KANA EXTENDED-A"_s,
		"KANAEXTENDED-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::GLAGOLITIC_SUPPLEMENT, $new(Character$UnicodeBlock, "GLAGOLITIC_SUPPLEMENT"_s, $$new($StringArray, {
		"GLAGOLITIC SUPPLEMENT"_s,
		"GLAGOLITICSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::ADLAM, $new(Character$UnicodeBlock, "ADLAM"_s));
	$assignStatic(Character$UnicodeBlock::MASARAM_GONDI, $new(Character$UnicodeBlock, "MASARAM_GONDI"_s, $$new($StringArray, {
		"MASARAM GONDI"_s,
		"MASARAMGONDI"_s
	})));
	$assignStatic(Character$UnicodeBlock::ZANABAZAR_SQUARE, $new(Character$UnicodeBlock, "ZANABAZAR_SQUARE"_s, $$new($StringArray, {
		"ZANABAZAR SQUARE"_s,
		"ZANABAZARSQUARE"_s
	})));
	$assignStatic(Character$UnicodeBlock::NUSHU, $new(Character$UnicodeBlock, "NUSHU"_s));
	$assignStatic(Character$UnicodeBlock::SOYOMBO, $new(Character$UnicodeBlock, "SOYOMBO"_s));
	$assignStatic(Character$UnicodeBlock::BHAIKSUKI, $new(Character$UnicodeBlock, "BHAIKSUKI"_s));
	$assignStatic(Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F, $new(Character$UnicodeBlock, "CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F"_s, $$new($StringArray, {
		"CJK UNIFIED IDEOGRAPHS EXTENSION F"_s,
		"CJKUNIFIEDIDEOGRAPHSEXTENSIONF"_s
	})));
	$assignStatic(Character$UnicodeBlock::GEORGIAN_EXTENDED, $new(Character$UnicodeBlock, "GEORGIAN_EXTENDED"_s, $$new($StringArray, {
		"GEORGIAN EXTENDED"_s,
		"GEORGIANEXTENDED"_s
	})));
	$assignStatic(Character$UnicodeBlock::HANIFI_ROHINGYA, $new(Character$UnicodeBlock, "HANIFI_ROHINGYA"_s, $$new($StringArray, {
		"HANIFI ROHINGYA"_s,
		"HANIFIROHINGYA"_s
	})));
	$assignStatic(Character$UnicodeBlock::OLD_SOGDIAN, $new(Character$UnicodeBlock, "OLD_SOGDIAN"_s, $$new($StringArray, {
		"OLD SOGDIAN"_s,
		"OLDSOGDIAN"_s
	})));
	$assignStatic(Character$UnicodeBlock::SOGDIAN, $new(Character$UnicodeBlock, "SOGDIAN"_s));
	$assignStatic(Character$UnicodeBlock::DOGRA, $new(Character$UnicodeBlock, "DOGRA"_s));
	$assignStatic(Character$UnicodeBlock::GUNJALA_GONDI, $new(Character$UnicodeBlock, "GUNJALA_GONDI"_s, $$new($StringArray, {
		"GUNJALA GONDI"_s,
		"GUNJALAGONDI"_s
	})));
	$assignStatic(Character$UnicodeBlock::MAKASAR, $new(Character$UnicodeBlock, "MAKASAR"_s));
	$assignStatic(Character$UnicodeBlock::MEDEFAIDRIN, $new(Character$UnicodeBlock, "MEDEFAIDRIN"_s));
	$assignStatic(Character$UnicodeBlock::MAYAN_NUMERALS, $new(Character$UnicodeBlock, "MAYAN_NUMERALS"_s, $$new($StringArray, {
		"MAYAN NUMERALS"_s,
		"MAYANNUMERALS"_s
	})));
	$assignStatic(Character$UnicodeBlock::INDIC_SIYAQ_NUMBERS, $new(Character$UnicodeBlock, "INDIC_SIYAQ_NUMBERS"_s, $$new($StringArray, {
		"INDIC SIYAQ NUMBERS"_s,
		"INDICSIYAQNUMBERS"_s
	})));
	$assignStatic(Character$UnicodeBlock::CHESS_SYMBOLS, $new(Character$UnicodeBlock, "CHESS_SYMBOLS"_s, $$new($StringArray, {
		"CHESS SYMBOLS"_s,
		"CHESSSYMBOLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::ELYMAIC, $new(Character$UnicodeBlock, "ELYMAIC"_s));
	$assignStatic(Character$UnicodeBlock::NANDINAGARI, $new(Character$UnicodeBlock, "NANDINAGARI"_s));
	$assignStatic(Character$UnicodeBlock::TAMIL_SUPPLEMENT, $new(Character$UnicodeBlock, "TAMIL_SUPPLEMENT"_s, $$new($StringArray, {
		"TAMIL SUPPLEMENT"_s,
		"TAMILSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::EGYPTIAN_HIEROGLYPH_FORMAT_CONTROLS, $new(Character$UnicodeBlock, "EGYPTIAN_HIEROGLYPH_FORMAT_CONTROLS"_s, $$new($StringArray, {
		"EGYPTIAN HIEROGLYPH FORMAT CONTROLS"_s,
		"EGYPTIANHIEROGLYPHFORMATCONTROLS"_s
	})));
	$assignStatic(Character$UnicodeBlock::SMALL_KANA_EXTENSION, $new(Character$UnicodeBlock, "SMALL_KANA_EXTENSION"_s, $$new($StringArray, {
		"SMALL KANA EXTENSION"_s,
		"SMALLKANAEXTENSION"_s
	})));
	$assignStatic(Character$UnicodeBlock::NYIAKENG_PUACHUE_HMONG, $new(Character$UnicodeBlock, "NYIAKENG_PUACHUE_HMONG"_s, $$new($StringArray, {
		"NYIAKENG PUACHUE HMONG"_s,
		"NYIAKENGPUACHUEHMONG"_s
	})));
	$assignStatic(Character$UnicodeBlock::WANCHO, $new(Character$UnicodeBlock, "WANCHO"_s));
	$assignStatic(Character$UnicodeBlock::OTTOMAN_SIYAQ_NUMBERS, $new(Character$UnicodeBlock, "OTTOMAN_SIYAQ_NUMBERS"_s, $$new($StringArray, {
		"OTTOMAN SIYAQ NUMBERS"_s,
		"OTTOMANSIYAQNUMBERS"_s
	})));
	$assignStatic(Character$UnicodeBlock::SYMBOLS_AND_PICTOGRAPHS_EXTENDED_A, $new(Character$UnicodeBlock, "SYMBOLS_AND_PICTOGRAPHS_EXTENDED_A"_s, $$new($StringArray, {
		"SYMBOLS AND PICTOGRAPHS EXTENDED-A"_s,
		"SYMBOLSANDPICTOGRAPHSEXTENDED-A"_s
	})));
	$assignStatic(Character$UnicodeBlock::YEZIDI, $new(Character$UnicodeBlock, "YEZIDI"_s));
	$assignStatic(Character$UnicodeBlock::CHORASMIAN, $new(Character$UnicodeBlock, "CHORASMIAN"_s));
	$assignStatic(Character$UnicodeBlock::DIVES_AKURU, $new(Character$UnicodeBlock, "DIVES_AKURU"_s, $$new($StringArray, {
		"DIVES AKURU"_s,
		"DIVESAKURU"_s
	})));
	$assignStatic(Character$UnicodeBlock::LISU_SUPPLEMENT, $new(Character$UnicodeBlock, "LISU_SUPPLEMENT"_s, $$new($StringArray, {
		"LISU SUPPLEMENT"_s,
		"LISUSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::KHITAN_SMALL_SCRIPT, $new(Character$UnicodeBlock, "KHITAN_SMALL_SCRIPT"_s, $$new($StringArray, {
		"KHITAN SMALL SCRIPT"_s,
		"KHITANSMALLSCRIPT"_s
	})));
	$assignStatic(Character$UnicodeBlock::TANGUT_SUPPLEMENT, $new(Character$UnicodeBlock, "TANGUT_SUPPLEMENT"_s, $$new($StringArray, {
		"TANGUT SUPPLEMENT"_s,
		"TANGUTSUPPLEMENT"_s
	})));
	$assignStatic(Character$UnicodeBlock::SYMBOLS_FOR_LEGACY_COMPUTING, $new(Character$UnicodeBlock, "SYMBOLS_FOR_LEGACY_COMPUTING"_s, $$new($StringArray, {
		"SYMBOLS FOR LEGACY COMPUTING"_s,
		"SYMBOLSFORLEGACYCOMPUTING"_s
	})));
	$assignStatic(Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_G, $new(Character$UnicodeBlock, "CJK_UNIFIED_IDEOGRAPHS_EXTENSION_G"_s, $$new($StringArray, {
		"CJK UNIFIED IDEOGRAPHS EXTENSION G"_s,
		"CJKUNIFIEDIDEOGRAPHSEXTENSIONG"_s
	})));
	$assignStatic(Character$UnicodeBlock::blockStarts, $new($ints, {
		0,
		128,
		256,
		384,
		592,
		688,
		768,
		880,
		1024,
		1280,
		1328,
		1424,
		1536,
		1792,
		1872,
		1920,
		1984,
		2048,
		2112,
		2144,
		2160,
		2208,
		2304,
		2432,
		2560,
		2688,
		2816,
		2944,
		3072,
		3200,
		3328,
		3456,
		3584,
		3712,
		3840,
		4096,
		4256,
		4352,
		4608,
		4992,
		5024,
		5120,
		5760,
		5792,
		5888,
		5920,
		5952,
		5984,
		6016,
		6144,
		6320,
		6400,
		6480,
		6528,
		6624,
		6656,
		6688,
		6832,
		6912,
		7040,
		7104,
		7168,
		7248,
		7296,
		7312,
		7360,
		7376,
		7424,
		7552,
		7616,
		7680,
		7936,
		8192,
		8304,
		8352,
		8400,
		8448,
		8528,
		8592,
		8704,
		8960,
		9216,
		9280,
		9312,
		9472,
		9600,
		9632,
		9728,
		9984,
		10176,
		10224,
		10240,
		10496,
		10624,
		10752,
		11008,
		11264,
		11360,
		11392,
		11520,
		11568,
		11648,
		11744,
		11776,
		11904,
		12032,
		12256,
		12272,
		12288,
		12352,
		12448,
		12544,
		12592,
		12688,
		12704,
		12736,
		12784,
		12800,
		13056,
		13312,
		19904,
		19968,
		0x0000A000,
		0x0000A490,
		0x0000A4D0,
		0x0000A500,
		0x0000A640,
		0x0000A6A0,
		0x0000A700,
		0x0000A720,
		0x0000A800,
		0x0000A830,
		0x0000A840,
		0x0000A880,
		0x0000A8E0,
		0x0000A900,
		0x0000A930,
		0x0000A960,
		0x0000A980,
		0x0000A9E0,
		0x0000AA00,
		0x0000AA60,
		0x0000AA80,
		0x0000AAE0,
		0x0000AB00,
		0x0000AB30,
		0x0000AB70,
		0x0000ABC0,
		0x0000AC00,
		0x0000D7B0,
		0x0000D800,
		0x0000DB80,
		0x0000DC00,
		0x0000E000,
		0x0000F900,
		0x0000FB00,
		0x0000FB50,
		0x0000FE00,
		0x0000FE10,
		0x0000FE20,
		0x0000FE30,
		0x0000FE50,
		0x0000FE70,
		0x0000FF00,
		0x0000FFF0,
		0x00010000,
		0x00010080,
		0x00010100,
		0x00010140,
		0x00010190,
		0x000101D0,
		0x00010200,
		0x00010280,
		0x000102A0,
		0x000102E0,
		0x00010300,
		0x00010330,
		0x00010350,
		0x00010380,
		0x000103A0,
		0x000103E0,
		0x00010400,
		0x00010450,
		0x00010480,
		0x000104B0,
		0x00010500,
		0x00010530,
		0x00010570,
		0x00010600,
		0x00010780,
		0x00010800,
		0x00010840,
		0x00010860,
		0x00010880,
		0x000108B0,
		0x000108E0,
		0x00010900,
		0x00010920,
		0x00010940,
		0x00010980,
		0x000109A0,
		0x00010A00,
		0x00010A60,
		0x00010A80,
		0x00010AA0,
		0x00010AC0,
		0x00010B00,
		0x00010B40,
		0x00010B60,
		0x00010B80,
		0x00010BB0,
		0x00010C00,
		0x00010C50,
		0x00010C80,
		0x00010D00,
		0x00010D40,
		0x00010E60,
		0x00010E80,
		0x00010EC0,
		0x00010F00,
		0x00010F30,
		0x00010F70,
		0x00010FB0,
		0x00010FE0,
		0x00011000,
		0x00011080,
		0x000110D0,
		0x00011100,
		0x00011150,
		0x00011180,
		0x000111E0,
		0x00011200,
		0x00011250,
		0x00011280,
		0x000112B0,
		0x00011300,
		0x00011380,
		0x00011400,
		0x00011480,
		0x000114E0,
		0x00011580,
		0x00011600,
		0x00011660,
		0x00011680,
		0x000116D0,
		0x00011700,
		0x00011740,
		0x00011800,
		0x00011850,
		0x000118A0,
		0x00011900,
		0x00011960,
		0x000119A0,
		0x00011A00,
		0x00011A50,
		0x00011AB0,
		0x00011AC0,
		0x00011B00,
		0x00011C00,
		0x00011C70,
		0x00011CC0,
		0x00011D00,
		0x00011D60,
		0x00011DB0,
		0x00011EE0,
		0x00011F00,
		0x00011FB0,
		0x00011FC0,
		0x00012000,
		0x00012400,
		0x00012480,
		0x00012550,
		0x00013000,
		0x00013430,
		0x00013440,
		0x00014400,
		0x00014680,
		0x00016800,
		0x00016A40,
		0x00016A70,
		0x00016AD0,
		0x00016B00,
		0x00016B90,
		0x00016E40,
		0x00016EA0,
		0x00016F00,
		0x00016FA0,
		0x00016FE0,
		0x00017000,
		0x00018800,
		0x00018B00,
		0x00018D00,
		0x00018D90,
		0x0001B000,
		0x0001B100,
		0x0001B130,
		0x0001B170,
		0x0001B300,
		0x0001BC00,
		0x0001BCA0,
		0x0001BCB0,
		0x0001D000,
		0x0001D100,
		0x0001D200,
		0x0001D250,
		0x0001D2E0,
		0x0001D300,
		0x0001D360,
		0x0001D380,
		0x0001D400,
		0x0001D800,
		0x0001DAB0,
		0x0001E000,
		0x0001E030,
		0x0001E100,
		0x0001E150,
		0x0001E2C0,
		0x0001E300,
		0x0001E800,
		0x0001E8E0,
		0x0001E900,
		0x0001E960,
		0x0001EC70,
		0x0001ECC0,
		0x0001ED00,
		0x0001ED50,
		0x0001EE00,
		0x0001EF00,
		0x0001F000,
		0x0001F030,
		0x0001F0A0,
		0x0001F100,
		0x0001F200,
		0x0001F300,
		0x0001F600,
		0x0001F650,
		0x0001F680,
		0x0001F700,
		0x0001F780,
		0x0001F800,
		0x0001F900,
		0x0001FA00,
		0x0001FA70,
		0x0001FB00,
		0x0001FC00,
		0x00020000,
		0x0002A6E0,
		0x0002A700,
		0x0002B740,
		0x0002B820,
		0x0002CEB0,
		0x0002EBF0,
		0x0002F800,
		0x0002FA20,
		0x00030000,
		0x00031350,
		0x000E0000,
		0x000E0080,
		0x000E0100,
		0x000E01F0,
		0x000F0000,
		0x00100000
	}));
	$assignStatic(Character$UnicodeBlock::blocks, $new($Character$UnicodeBlockArray, {
		Character$UnicodeBlock::BASIC_LATIN,
		Character$UnicodeBlock::LATIN_1_SUPPLEMENT,
		Character$UnicodeBlock::LATIN_EXTENDED_A,
		Character$UnicodeBlock::LATIN_EXTENDED_B,
		Character$UnicodeBlock::IPA_EXTENSIONS,
		Character$UnicodeBlock::SPACING_MODIFIER_LETTERS,
		Character$UnicodeBlock::COMBINING_DIACRITICAL_MARKS,
		Character$UnicodeBlock::GREEK,
		Character$UnicodeBlock::CYRILLIC,
		Character$UnicodeBlock::CYRILLIC_SUPPLEMENTARY,
		Character$UnicodeBlock::ARMENIAN,
		Character$UnicodeBlock::HEBREW,
		Character$UnicodeBlock::ARABIC,
		Character$UnicodeBlock::SYRIAC,
		Character$UnicodeBlock::ARABIC_SUPPLEMENT,
		Character$UnicodeBlock::THAANA,
		Character$UnicodeBlock::NKO,
		Character$UnicodeBlock::SAMARITAN,
		Character$UnicodeBlock::MANDAIC,
		Character$UnicodeBlock::SYRIAC_SUPPLEMENT,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::ARABIC_EXTENDED_A,
		Character$UnicodeBlock::DEVANAGARI,
		Character$UnicodeBlock::BENGALI,
		Character$UnicodeBlock::GURMUKHI,
		Character$UnicodeBlock::GUJARATI,
		Character$UnicodeBlock::ORIYA,
		Character$UnicodeBlock::TAMIL,
		Character$UnicodeBlock::TELUGU,
		Character$UnicodeBlock::KANNADA,
		Character$UnicodeBlock::MALAYALAM,
		Character$UnicodeBlock::SINHALA,
		Character$UnicodeBlock::THAI,
		Character$UnicodeBlock::LAO,
		Character$UnicodeBlock::TIBETAN,
		Character$UnicodeBlock::MYANMAR,
		Character$UnicodeBlock::GEORGIAN,
		Character$UnicodeBlock::HANGUL_JAMO,
		Character$UnicodeBlock::ETHIOPIC,
		Character$UnicodeBlock::ETHIOPIC_SUPPLEMENT,
		Character$UnicodeBlock::CHEROKEE,
		Character$UnicodeBlock::UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS,
		Character$UnicodeBlock::OGHAM,
		Character$UnicodeBlock::RUNIC,
		Character$UnicodeBlock::TAGALOG,
		Character$UnicodeBlock::HANUNOO,
		Character$UnicodeBlock::BUHID,
		Character$UnicodeBlock::TAGBANWA,
		Character$UnicodeBlock::KHMER,
		Character$UnicodeBlock::MONGOLIAN,
		Character$UnicodeBlock::UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED,
		Character$UnicodeBlock::LIMBU,
		Character$UnicodeBlock::TAI_LE,
		Character$UnicodeBlock::NEW_TAI_LUE,
		Character$UnicodeBlock::KHMER_SYMBOLS,
		Character$UnicodeBlock::BUGINESE,
		Character$UnicodeBlock::TAI_THAM,
		Character$UnicodeBlock::COMBINING_DIACRITICAL_MARKS_EXTENDED,
		Character$UnicodeBlock::BALINESE,
		Character$UnicodeBlock::SUNDANESE,
		Character$UnicodeBlock::BATAK,
		Character$UnicodeBlock::LEPCHA,
		Character$UnicodeBlock::OL_CHIKI,
		Character$UnicodeBlock::CYRILLIC_EXTENDED_C,
		Character$UnicodeBlock::GEORGIAN_EXTENDED,
		Character$UnicodeBlock::SUNDANESE_SUPPLEMENT,
		Character$UnicodeBlock::VEDIC_EXTENSIONS,
		Character$UnicodeBlock::PHONETIC_EXTENSIONS,
		Character$UnicodeBlock::PHONETIC_EXTENSIONS_SUPPLEMENT,
		Character$UnicodeBlock::COMBINING_DIACRITICAL_MARKS_SUPPLEMENT,
		Character$UnicodeBlock::LATIN_EXTENDED_ADDITIONAL,
		Character$UnicodeBlock::GREEK_EXTENDED,
		Character$UnicodeBlock::GENERAL_PUNCTUATION,
		Character$UnicodeBlock::SUPERSCRIPTS_AND_SUBSCRIPTS,
		Character$UnicodeBlock::CURRENCY_SYMBOLS,
		Character$UnicodeBlock::COMBINING_MARKS_FOR_SYMBOLS,
		Character$UnicodeBlock::LETTERLIKE_SYMBOLS,
		Character$UnicodeBlock::NUMBER_FORMS,
		Character$UnicodeBlock::ARROWS,
		Character$UnicodeBlock::MATHEMATICAL_OPERATORS,
		Character$UnicodeBlock::MISCELLANEOUS_TECHNICAL,
		Character$UnicodeBlock::CONTROL_PICTURES,
		Character$UnicodeBlock::OPTICAL_CHARACTER_RECOGNITION,
		Character$UnicodeBlock::ENCLOSED_ALPHANUMERICS,
		Character$UnicodeBlock::BOX_DRAWING,
		Character$UnicodeBlock::BLOCK_ELEMENTS,
		Character$UnicodeBlock::GEOMETRIC_SHAPES,
		Character$UnicodeBlock::MISCELLANEOUS_SYMBOLS,
		Character$UnicodeBlock::DINGBATS,
		Character$UnicodeBlock::MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A,
		Character$UnicodeBlock::SUPPLEMENTAL_ARROWS_A,
		Character$UnicodeBlock::BRAILLE_PATTERNS,
		Character$UnicodeBlock::SUPPLEMENTAL_ARROWS_B,
		Character$UnicodeBlock::MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B,
		Character$UnicodeBlock::SUPPLEMENTAL_MATHEMATICAL_OPERATORS,
		Character$UnicodeBlock::MISCELLANEOUS_SYMBOLS_AND_ARROWS,
		Character$UnicodeBlock::GLAGOLITIC,
		Character$UnicodeBlock::LATIN_EXTENDED_C,
		Character$UnicodeBlock::COPTIC,
		Character$UnicodeBlock::GEORGIAN_SUPPLEMENT,
		Character$UnicodeBlock::TIFINAGH,
		Character$UnicodeBlock::ETHIOPIC_EXTENDED,
		Character$UnicodeBlock::CYRILLIC_EXTENDED_A,
		Character$UnicodeBlock::SUPPLEMENTAL_PUNCTUATION,
		Character$UnicodeBlock::CJK_RADICALS_SUPPLEMENT,
		Character$UnicodeBlock::KANGXI_RADICALS,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::IDEOGRAPHIC_DESCRIPTION_CHARACTERS,
		Character$UnicodeBlock::CJK_SYMBOLS_AND_PUNCTUATION,
		Character$UnicodeBlock::HIRAGANA,
		Character$UnicodeBlock::KATAKANA,
		Character$UnicodeBlock::BOPOMOFO,
		Character$UnicodeBlock::HANGUL_COMPATIBILITY_JAMO,
		Character$UnicodeBlock::KANBUN,
		Character$UnicodeBlock::BOPOMOFO_EXTENDED,
		Character$UnicodeBlock::CJK_STROKES,
		Character$UnicodeBlock::KATAKANA_PHONETIC_EXTENSIONS,
		Character$UnicodeBlock::ENCLOSED_CJK_LETTERS_AND_MONTHS,
		Character$UnicodeBlock::CJK_COMPATIBILITY,
		Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A,
		Character$UnicodeBlock::YIJING_HEXAGRAM_SYMBOLS,
		Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS,
		Character$UnicodeBlock::YI_SYLLABLES,
		Character$UnicodeBlock::YI_RADICALS,
		Character$UnicodeBlock::LISU,
		Character$UnicodeBlock::VAI,
		Character$UnicodeBlock::CYRILLIC_EXTENDED_B,
		Character$UnicodeBlock::BAMUM,
		Character$UnicodeBlock::MODIFIER_TONE_LETTERS,
		Character$UnicodeBlock::LATIN_EXTENDED_D,
		Character$UnicodeBlock::SYLOTI_NAGRI,
		Character$UnicodeBlock::COMMON_INDIC_NUMBER_FORMS,
		Character$UnicodeBlock::PHAGS_PA,
		Character$UnicodeBlock::SAURASHTRA,
		Character$UnicodeBlock::DEVANAGARI_EXTENDED,
		Character$UnicodeBlock::KAYAH_LI,
		Character$UnicodeBlock::REJANG,
		Character$UnicodeBlock::HANGUL_JAMO_EXTENDED_A,
		Character$UnicodeBlock::JAVANESE,
		Character$UnicodeBlock::MYANMAR_EXTENDED_B,
		Character$UnicodeBlock::CHAM,
		Character$UnicodeBlock::MYANMAR_EXTENDED_A,
		Character$UnicodeBlock::TAI_VIET,
		Character$UnicodeBlock::MEETEI_MAYEK_EXTENSIONS,
		Character$UnicodeBlock::ETHIOPIC_EXTENDED_A,
		Character$UnicodeBlock::LATIN_EXTENDED_E,
		Character$UnicodeBlock::CHEROKEE_SUPPLEMENT,
		Character$UnicodeBlock::MEETEI_MAYEK,
		Character$UnicodeBlock::HANGUL_SYLLABLES,
		Character$UnicodeBlock::HANGUL_JAMO_EXTENDED_B,
		Character$UnicodeBlock::HIGH_SURROGATES,
		Character$UnicodeBlock::HIGH_PRIVATE_USE_SURROGATES,
		Character$UnicodeBlock::LOW_SURROGATES,
		Character$UnicodeBlock::PRIVATE_USE_AREA,
		Character$UnicodeBlock::CJK_COMPATIBILITY_IDEOGRAPHS,
		Character$UnicodeBlock::ALPHABETIC_PRESENTATION_FORMS,
		Character$UnicodeBlock::ARABIC_PRESENTATION_FORMS_A,
		Character$UnicodeBlock::VARIATION_SELECTORS,
		Character$UnicodeBlock::VERTICAL_FORMS,
		Character$UnicodeBlock::COMBINING_HALF_MARKS,
		Character$UnicodeBlock::CJK_COMPATIBILITY_FORMS,
		Character$UnicodeBlock::SMALL_FORM_VARIANTS,
		Character$UnicodeBlock::ARABIC_PRESENTATION_FORMS_B,
		Character$UnicodeBlock::HALFWIDTH_AND_FULLWIDTH_FORMS,
		Character$UnicodeBlock::SPECIALS,
		Character$UnicodeBlock::LINEAR_B_SYLLABARY,
		Character$UnicodeBlock::LINEAR_B_IDEOGRAMS,
		Character$UnicodeBlock::AEGEAN_NUMBERS,
		Character$UnicodeBlock::ANCIENT_GREEK_NUMBERS,
		Character$UnicodeBlock::ANCIENT_SYMBOLS,
		Character$UnicodeBlock::PHAISTOS_DISC,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::LYCIAN,
		Character$UnicodeBlock::CARIAN,
		Character$UnicodeBlock::COPTIC_EPACT_NUMBERS,
		Character$UnicodeBlock::OLD_ITALIC,
		Character$UnicodeBlock::GOTHIC,
		Character$UnicodeBlock::OLD_PERMIC,
		Character$UnicodeBlock::UGARITIC,
		Character$UnicodeBlock::OLD_PERSIAN,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::DESERET,
		Character$UnicodeBlock::SHAVIAN,
		Character$UnicodeBlock::OSMANYA,
		Character$UnicodeBlock::OSAGE,
		Character$UnicodeBlock::ELBASAN,
		Character$UnicodeBlock::CAUCASIAN_ALBANIAN,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::LINEAR_A,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::CYPRIOT_SYLLABARY,
		Character$UnicodeBlock::IMPERIAL_ARAMAIC,
		Character$UnicodeBlock::PALMYRENE,
		Character$UnicodeBlock::NABATAEAN,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::HATRAN,
		Character$UnicodeBlock::PHOENICIAN,
		Character$UnicodeBlock::LYDIAN,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MEROITIC_HIEROGLYPHS,
		Character$UnicodeBlock::MEROITIC_CURSIVE,
		Character$UnicodeBlock::KHAROSHTHI,
		Character$UnicodeBlock::OLD_SOUTH_ARABIAN,
		Character$UnicodeBlock::OLD_NORTH_ARABIAN,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MANICHAEAN,
		Character$UnicodeBlock::AVESTAN,
		Character$UnicodeBlock::INSCRIPTIONAL_PARTHIAN,
		Character$UnicodeBlock::INSCRIPTIONAL_PAHLAVI,
		Character$UnicodeBlock::PSALTER_PAHLAVI,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::OLD_TURKIC,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::OLD_HUNGARIAN,
		Character$UnicodeBlock::HANIFI_ROHINGYA,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::RUMI_NUMERAL_SYMBOLS,
		Character$UnicodeBlock::YEZIDI,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::OLD_SOGDIAN,
		Character$UnicodeBlock::SOGDIAN,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::CHORASMIAN,
		Character$UnicodeBlock::ELYMAIC,
		Character$UnicodeBlock::BRAHMI,
		Character$UnicodeBlock::KAITHI,
		Character$UnicodeBlock::SORA_SOMPENG,
		Character$UnicodeBlock::CHAKMA,
		Character$UnicodeBlock::MAHAJANI,
		Character$UnicodeBlock::SHARADA,
		Character$UnicodeBlock::SINHALA_ARCHAIC_NUMBERS,
		Character$UnicodeBlock::KHOJKI,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MULTANI,
		Character$UnicodeBlock::KHUDAWADI,
		Character$UnicodeBlock::GRANTHA,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::NEWA,
		Character$UnicodeBlock::TIRHUTA,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::SIDDHAM,
		Character$UnicodeBlock::MODI,
		Character$UnicodeBlock::MONGOLIAN_SUPPLEMENT,
		Character$UnicodeBlock::TAKRI,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::AHOM,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::DOGRA,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::WARANG_CITI,
		Character$UnicodeBlock::DIVES_AKURU,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::NANDINAGARI,
		Character$UnicodeBlock::ZANABAZAR_SQUARE,
		Character$UnicodeBlock::SOYOMBO,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::PAU_CIN_HAU,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::BHAIKSUKI,
		Character$UnicodeBlock::MARCHEN,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MASARAM_GONDI,
		Character$UnicodeBlock::GUNJALA_GONDI,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MAKASAR,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::LISU_SUPPLEMENT,
		Character$UnicodeBlock::TAMIL_SUPPLEMENT,
		Character$UnicodeBlock::CUNEIFORM,
		Character$UnicodeBlock::CUNEIFORM_NUMBERS_AND_PUNCTUATION,
		Character$UnicodeBlock::EARLY_DYNASTIC_CUNEIFORM,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::EGYPTIAN_HIEROGLYPHS,
		Character$UnicodeBlock::EGYPTIAN_HIEROGLYPH_FORMAT_CONTROLS,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::ANATOLIAN_HIEROGLYPHS,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::BAMUM_SUPPLEMENT,
		Character$UnicodeBlock::MRO,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::BASSA_VAH,
		Character$UnicodeBlock::PAHAWH_HMONG,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MEDEFAIDRIN,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MIAO,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION,
		Character$UnicodeBlock::TANGUT,
		Character$UnicodeBlock::TANGUT_COMPONENTS,
		Character$UnicodeBlock::KHITAN_SMALL_SCRIPT,
		Character$UnicodeBlock::TANGUT_SUPPLEMENT,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::KANA_SUPPLEMENT,
		Character$UnicodeBlock::KANA_EXTENDED_A,
		Character$UnicodeBlock::SMALL_KANA_EXTENSION,
		Character$UnicodeBlock::NUSHU,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::DUPLOYAN,
		Character$UnicodeBlock::SHORTHAND_FORMAT_CONTROLS,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::BYZANTINE_MUSICAL_SYMBOLS,
		Character$UnicodeBlock::MUSICAL_SYMBOLS,
		Character$UnicodeBlock::ANCIENT_GREEK_MUSICAL_NOTATION,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MAYAN_NUMERALS,
		Character$UnicodeBlock::TAI_XUAN_JING_SYMBOLS,
		Character$UnicodeBlock::COUNTING_ROD_NUMERALS,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MATHEMATICAL_ALPHANUMERIC_SYMBOLS,
		Character$UnicodeBlock::SUTTON_SIGNWRITING,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::GLAGOLITIC_SUPPLEMENT,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::NYIAKENG_PUACHUE_HMONG,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::WANCHO,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MENDE_KIKAKUI,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::ADLAM,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::INDIC_SIYAQ_NUMBERS,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::OTTOMAN_SIYAQ_NUMBERS,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::MAHJONG_TILES,
		Character$UnicodeBlock::DOMINO_TILES,
		Character$UnicodeBlock::PLAYING_CARDS,
		Character$UnicodeBlock::ENCLOSED_ALPHANUMERIC_SUPPLEMENT,
		Character$UnicodeBlock::ENCLOSED_IDEOGRAPHIC_SUPPLEMENT,
		Character$UnicodeBlock::MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS,
		Character$UnicodeBlock::EMOTICONS,
		Character$UnicodeBlock::ORNAMENTAL_DINGBATS,
		Character$UnicodeBlock::TRANSPORT_AND_MAP_SYMBOLS,
		Character$UnicodeBlock::ALCHEMICAL_SYMBOLS,
		Character$UnicodeBlock::GEOMETRIC_SHAPES_EXTENDED,
		Character$UnicodeBlock::SUPPLEMENTAL_ARROWS_C,
		Character$UnicodeBlock::SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS,
		Character$UnicodeBlock::CHESS_SYMBOLS,
		Character$UnicodeBlock::SYMBOLS_AND_PICTOGRAPHS_EXTENDED_A,
		Character$UnicodeBlock::SYMBOLS_FOR_LEGACY_COMPUTING,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C,
		Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D,
		Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E,
		Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::CJK_UNIFIED_IDEOGRAPHS_EXTENSION_G,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::TAGS,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::VARIATION_SELECTORS_SUPPLEMENT,
		(Character$UnicodeBlock*)nullptr,
		Character$UnicodeBlock::SUPPLEMENTARY_PRIVATE_USE_AREA_A,
		Character$UnicodeBlock::SUPPLEMENTARY_PRIVATE_USE_AREA_B
	}));
}

Character$UnicodeBlock::Character$UnicodeBlock() {
}

$Class* Character$UnicodeBlock::load$($String* name, bool initialize) {
	$loadClass(Character$UnicodeBlock, name, initialize, &_Character$UnicodeBlock_ClassInfo_, clinit$Character$UnicodeBlock, allocate$Character$UnicodeBlock);
	return class$;
}

$Class* Character$UnicodeBlock::class$ = nullptr;

	} // lang
} // java
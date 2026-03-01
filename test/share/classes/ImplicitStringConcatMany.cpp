#include <ImplicitStringConcatMany.h>

#include <java/lang/IllegalAccessException.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Modifier.h>
#include <jcpp.h>

using $FieldArray = $Array<::java::lang::reflect::Field>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;

$FieldInfo _ImplicitStringConcatMany_FieldInfo_[] = {
	{"s000", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s000)},
	{"s001", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s001)},
	{"s002", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s002)},
	{"s003", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s003)},
	{"s004", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s004)},
	{"s005", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s005)},
	{"s006", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s006)},
	{"s007", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s007)},
	{"s008", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s008)},
	{"s009", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s009)},
	{"s010", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s010)},
	{"s011", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s011)},
	{"s012", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s012)},
	{"s013", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s013)},
	{"s014", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s014)},
	{"s015", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s015)},
	{"s016", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s016)},
	{"s017", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s017)},
	{"s018", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s018)},
	{"s019", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s019)},
	{"s020", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s020)},
	{"s021", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s021)},
	{"s022", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s022)},
	{"s023", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s023)},
	{"s024", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s024)},
	{"s025", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s025)},
	{"s026", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s026)},
	{"s027", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s027)},
	{"s028", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s028)},
	{"s029", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s029)},
	{"s030", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s030)},
	{"s031", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s031)},
	{"s032", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s032)},
	{"s033", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s033)},
	{"s034", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s034)},
	{"s035", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s035)},
	{"s036", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s036)},
	{"s037", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s037)},
	{"s038", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s038)},
	{"s039", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s039)},
	{"s040", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s040)},
	{"s041", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s041)},
	{"s042", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s042)},
	{"s043", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s043)},
	{"s044", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s044)},
	{"s045", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s045)},
	{"s046", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s046)},
	{"s047", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s047)},
	{"s048", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s048)},
	{"s049", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s049)},
	{"s050", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s050)},
	{"s051", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s051)},
	{"s052", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s052)},
	{"s053", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s053)},
	{"s054", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s054)},
	{"s055", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s055)},
	{"s056", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s056)},
	{"s057", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s057)},
	{"s058", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s058)},
	{"s059", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s059)},
	{"s060", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s060)},
	{"s061", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s061)},
	{"s062", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s062)},
	{"s063", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s063)},
	{"s064", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s064)},
	{"s065", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s065)},
	{"s066", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s066)},
	{"s067", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s067)},
	{"s068", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s068)},
	{"s069", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s069)},
	{"s070", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s070)},
	{"s071", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s071)},
	{"s072", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s072)},
	{"s073", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s073)},
	{"s074", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s074)},
	{"s075", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s075)},
	{"s076", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s076)},
	{"s077", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s077)},
	{"s078", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s078)},
	{"s079", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s079)},
	{"s080", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s080)},
	{"s081", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s081)},
	{"s082", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s082)},
	{"s083", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s083)},
	{"s084", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s084)},
	{"s085", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s085)},
	{"s086", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s086)},
	{"s087", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s087)},
	{"s088", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s088)},
	{"s089", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s089)},
	{"s090", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s090)},
	{"s091", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s091)},
	{"s092", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s092)},
	{"s093", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s093)},
	{"s094", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s094)},
	{"s095", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s095)},
	{"s096", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s096)},
	{"s097", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s097)},
	{"s098", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s098)},
	{"s099", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s099)},
	{"s100", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s100)},
	{"s101", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s101)},
	{"s102", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s102)},
	{"s103", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s103)},
	{"s104", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s104)},
	{"s105", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s105)},
	{"s106", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s106)},
	{"s107", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s107)},
	{"s108", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s108)},
	{"s109", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s109)},
	{"s110", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s110)},
	{"s111", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s111)},
	{"s112", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s112)},
	{"s113", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s113)},
	{"s114", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s114)},
	{"s115", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s115)},
	{"s116", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s116)},
	{"s117", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s117)},
	{"s118", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s118)},
	{"s119", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s119)},
	{"s120", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s120)},
	{"s121", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s121)},
	{"s122", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s122)},
	{"s123", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s123)},
	{"s124", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s124)},
	{"s125", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s125)},
	{"s126", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s126)},
	{"s127", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s127)},
	{"s128", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s128)},
	{"s129", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s129)},
	{"s130", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s130)},
	{"s131", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s131)},
	{"s132", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s132)},
	{"s133", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s133)},
	{"s134", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s134)},
	{"s135", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s135)},
	{"s136", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s136)},
	{"s137", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s137)},
	{"s138", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s138)},
	{"s139", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s139)},
	{"s140", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s140)},
	{"s141", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s141)},
	{"s142", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s142)},
	{"s143", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s143)},
	{"s144", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s144)},
	{"s145", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s145)},
	{"s146", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s146)},
	{"s147", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s147)},
	{"s148", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s148)},
	{"s149", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s149)},
	{"s150", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s150)},
	{"s151", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s151)},
	{"s152", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s152)},
	{"s153", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s153)},
	{"s154", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s154)},
	{"s155", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s155)},
	{"s156", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s156)},
	{"s157", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s157)},
	{"s158", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s158)},
	{"s159", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s159)},
	{"s160", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s160)},
	{"s161", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s161)},
	{"s162", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s162)},
	{"s163", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s163)},
	{"s164", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s164)},
	{"s165", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s165)},
	{"s166", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s166)},
	{"s167", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s167)},
	{"s168", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s168)},
	{"s169", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s169)},
	{"s170", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s170)},
	{"s171", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s171)},
	{"s172", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s172)},
	{"s173", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s173)},
	{"s174", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s174)},
	{"s175", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s175)},
	{"s176", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s176)},
	{"s177", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s177)},
	{"s178", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s178)},
	{"s179", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s179)},
	{"s180", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s180)},
	{"s181", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s181)},
	{"s182", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s182)},
	{"s183", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s183)},
	{"s184", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s184)},
	{"s185", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s185)},
	{"s186", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s186)},
	{"s187", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s187)},
	{"s188", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s188)},
	{"s189", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s189)},
	{"s190", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s190)},
	{"s191", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s191)},
	{"s192", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s192)},
	{"s193", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s193)},
	{"s194", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s194)},
	{"s195", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s195)},
	{"s196", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s196)},
	{"s197", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s197)},
	{"s198", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s198)},
	{"s199", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s199)},
	{"s200", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s200)},
	{"s201", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s201)},
	{"s202", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s202)},
	{"s203", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s203)},
	{"s204", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s204)},
	{"s205", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s205)},
	{"s206", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s206)},
	{"s207", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s207)},
	{"s208", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s208)},
	{"s209", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s209)},
	{"s210", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s210)},
	{"s211", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s211)},
	{"s212", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s212)},
	{"s213", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s213)},
	{"s214", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s214)},
	{"s215", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s215)},
	{"s216", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s216)},
	{"s217", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s217)},
	{"s218", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s218)},
	{"s219", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s219)},
	{"s220", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s220)},
	{"s221", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s221)},
	{"s222", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s222)},
	{"s223", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s223)},
	{"s224", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s224)},
	{"s225", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s225)},
	{"s226", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s226)},
	{"s227", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s227)},
	{"s228", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s228)},
	{"s229", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s229)},
	{"s230", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s230)},
	{"s231", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s231)},
	{"s232", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s232)},
	{"s233", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s233)},
	{"s234", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s234)},
	{"s235", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s235)},
	{"s236", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s236)},
	{"s237", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s237)},
	{"s238", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s238)},
	{"s239", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s239)},
	{"s240", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s240)},
	{"s241", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s241)},
	{"s242", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s242)},
	{"s243", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s243)},
	{"s244", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s244)},
	{"s245", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s245)},
	{"s246", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s246)},
	{"s247", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s247)},
	{"s248", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s248)},
	{"s249", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s249)},
	{"s250", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s250)},
	{"s251", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s251)},
	{"s252", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s252)},
	{"s253", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s253)},
	{"s254", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s254)},
	{"s255", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s255)},
	{"s256", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s256)},
	{"s257", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s257)},
	{"s258", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s258)},
	{"s259", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s259)},
	{"s260", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s260)},
	{"s261", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s261)},
	{"s262", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s262)},
	{"s263", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s263)},
	{"s264", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s264)},
	{"s265", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s265)},
	{"s266", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s266)},
	{"s267", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s267)},
	{"s268", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s268)},
	{"s269", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s269)},
	{"s270", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s270)},
	{"s271", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s271)},
	{"s272", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s272)},
	{"s273", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s273)},
	{"s274", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s274)},
	{"s275", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s275)},
	{"s276", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s276)},
	{"s277", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s277)},
	{"s278", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s278)},
	{"s279", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s279)},
	{"s280", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s280)},
	{"s281", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s281)},
	{"s282", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s282)},
	{"s283", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s283)},
	{"s284", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s284)},
	{"s285", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s285)},
	{"s286", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s286)},
	{"s287", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s287)},
	{"s288", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s288)},
	{"s289", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s289)},
	{"s290", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s290)},
	{"s291", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s291)},
	{"s292", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s292)},
	{"s293", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s293)},
	{"s294", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s294)},
	{"s295", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s295)},
	{"s296", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s296)},
	{"s297", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s297)},
	{"s298", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s298)},
	{"s299", "Ljava/lang/String;", nullptr, $STATIC, $staticField(ImplicitStringConcatMany, s299)},
	{}
};

$MethodInfo _ImplicitStringConcatMany_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ImplicitStringConcatMany, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ImplicitStringConcatMany, main, void, $StringArray*), "java.lang.Exception"},
	{"test", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ImplicitStringConcatMany, test, void, $String*, $String*)},
	{}
};

$ClassInfo _ImplicitStringConcatMany_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ImplicitStringConcatMany",
	"java.lang.Object",
	nullptr,
	_ImplicitStringConcatMany_FieldInfo_,
	_ImplicitStringConcatMany_MethodInfo_
};

$Object* allocate$ImplicitStringConcatMany($Class* clazz) {
	return $of($alloc(ImplicitStringConcatMany));
}

$String* ImplicitStringConcatMany::s000 = nullptr;
$String* ImplicitStringConcatMany::s001 = nullptr;
$String* ImplicitStringConcatMany::s002 = nullptr;
$String* ImplicitStringConcatMany::s003 = nullptr;
$String* ImplicitStringConcatMany::s004 = nullptr;
$String* ImplicitStringConcatMany::s005 = nullptr;
$String* ImplicitStringConcatMany::s006 = nullptr;
$String* ImplicitStringConcatMany::s007 = nullptr;
$String* ImplicitStringConcatMany::s008 = nullptr;
$String* ImplicitStringConcatMany::s009 = nullptr;
$String* ImplicitStringConcatMany::s010 = nullptr;
$String* ImplicitStringConcatMany::s011 = nullptr;
$String* ImplicitStringConcatMany::s012 = nullptr;
$String* ImplicitStringConcatMany::s013 = nullptr;
$String* ImplicitStringConcatMany::s014 = nullptr;
$String* ImplicitStringConcatMany::s015 = nullptr;
$String* ImplicitStringConcatMany::s016 = nullptr;
$String* ImplicitStringConcatMany::s017 = nullptr;
$String* ImplicitStringConcatMany::s018 = nullptr;
$String* ImplicitStringConcatMany::s019 = nullptr;
$String* ImplicitStringConcatMany::s020 = nullptr;
$String* ImplicitStringConcatMany::s021 = nullptr;
$String* ImplicitStringConcatMany::s022 = nullptr;
$String* ImplicitStringConcatMany::s023 = nullptr;
$String* ImplicitStringConcatMany::s024 = nullptr;
$String* ImplicitStringConcatMany::s025 = nullptr;
$String* ImplicitStringConcatMany::s026 = nullptr;
$String* ImplicitStringConcatMany::s027 = nullptr;
$String* ImplicitStringConcatMany::s028 = nullptr;
$String* ImplicitStringConcatMany::s029 = nullptr;
$String* ImplicitStringConcatMany::s030 = nullptr;
$String* ImplicitStringConcatMany::s031 = nullptr;
$String* ImplicitStringConcatMany::s032 = nullptr;
$String* ImplicitStringConcatMany::s033 = nullptr;
$String* ImplicitStringConcatMany::s034 = nullptr;
$String* ImplicitStringConcatMany::s035 = nullptr;
$String* ImplicitStringConcatMany::s036 = nullptr;
$String* ImplicitStringConcatMany::s037 = nullptr;
$String* ImplicitStringConcatMany::s038 = nullptr;
$String* ImplicitStringConcatMany::s039 = nullptr;
$String* ImplicitStringConcatMany::s040 = nullptr;
$String* ImplicitStringConcatMany::s041 = nullptr;
$String* ImplicitStringConcatMany::s042 = nullptr;
$String* ImplicitStringConcatMany::s043 = nullptr;
$String* ImplicitStringConcatMany::s044 = nullptr;
$String* ImplicitStringConcatMany::s045 = nullptr;
$String* ImplicitStringConcatMany::s046 = nullptr;
$String* ImplicitStringConcatMany::s047 = nullptr;
$String* ImplicitStringConcatMany::s048 = nullptr;
$String* ImplicitStringConcatMany::s049 = nullptr;
$String* ImplicitStringConcatMany::s050 = nullptr;
$String* ImplicitStringConcatMany::s051 = nullptr;
$String* ImplicitStringConcatMany::s052 = nullptr;
$String* ImplicitStringConcatMany::s053 = nullptr;
$String* ImplicitStringConcatMany::s054 = nullptr;
$String* ImplicitStringConcatMany::s055 = nullptr;
$String* ImplicitStringConcatMany::s056 = nullptr;
$String* ImplicitStringConcatMany::s057 = nullptr;
$String* ImplicitStringConcatMany::s058 = nullptr;
$String* ImplicitStringConcatMany::s059 = nullptr;
$String* ImplicitStringConcatMany::s060 = nullptr;
$String* ImplicitStringConcatMany::s061 = nullptr;
$String* ImplicitStringConcatMany::s062 = nullptr;
$String* ImplicitStringConcatMany::s063 = nullptr;
$String* ImplicitStringConcatMany::s064 = nullptr;
$String* ImplicitStringConcatMany::s065 = nullptr;
$String* ImplicitStringConcatMany::s066 = nullptr;
$String* ImplicitStringConcatMany::s067 = nullptr;
$String* ImplicitStringConcatMany::s068 = nullptr;
$String* ImplicitStringConcatMany::s069 = nullptr;
$String* ImplicitStringConcatMany::s070 = nullptr;
$String* ImplicitStringConcatMany::s071 = nullptr;
$String* ImplicitStringConcatMany::s072 = nullptr;
$String* ImplicitStringConcatMany::s073 = nullptr;
$String* ImplicitStringConcatMany::s074 = nullptr;
$String* ImplicitStringConcatMany::s075 = nullptr;
$String* ImplicitStringConcatMany::s076 = nullptr;
$String* ImplicitStringConcatMany::s077 = nullptr;
$String* ImplicitStringConcatMany::s078 = nullptr;
$String* ImplicitStringConcatMany::s079 = nullptr;
$String* ImplicitStringConcatMany::s080 = nullptr;
$String* ImplicitStringConcatMany::s081 = nullptr;
$String* ImplicitStringConcatMany::s082 = nullptr;
$String* ImplicitStringConcatMany::s083 = nullptr;
$String* ImplicitStringConcatMany::s084 = nullptr;
$String* ImplicitStringConcatMany::s085 = nullptr;
$String* ImplicitStringConcatMany::s086 = nullptr;
$String* ImplicitStringConcatMany::s087 = nullptr;
$String* ImplicitStringConcatMany::s088 = nullptr;
$String* ImplicitStringConcatMany::s089 = nullptr;
$String* ImplicitStringConcatMany::s090 = nullptr;
$String* ImplicitStringConcatMany::s091 = nullptr;
$String* ImplicitStringConcatMany::s092 = nullptr;
$String* ImplicitStringConcatMany::s093 = nullptr;
$String* ImplicitStringConcatMany::s094 = nullptr;
$String* ImplicitStringConcatMany::s095 = nullptr;
$String* ImplicitStringConcatMany::s096 = nullptr;
$String* ImplicitStringConcatMany::s097 = nullptr;
$String* ImplicitStringConcatMany::s098 = nullptr;
$String* ImplicitStringConcatMany::s099 = nullptr;
$String* ImplicitStringConcatMany::s100 = nullptr;
$String* ImplicitStringConcatMany::s101 = nullptr;
$String* ImplicitStringConcatMany::s102 = nullptr;
$String* ImplicitStringConcatMany::s103 = nullptr;
$String* ImplicitStringConcatMany::s104 = nullptr;
$String* ImplicitStringConcatMany::s105 = nullptr;
$String* ImplicitStringConcatMany::s106 = nullptr;
$String* ImplicitStringConcatMany::s107 = nullptr;
$String* ImplicitStringConcatMany::s108 = nullptr;
$String* ImplicitStringConcatMany::s109 = nullptr;
$String* ImplicitStringConcatMany::s110 = nullptr;
$String* ImplicitStringConcatMany::s111 = nullptr;
$String* ImplicitStringConcatMany::s112 = nullptr;
$String* ImplicitStringConcatMany::s113 = nullptr;
$String* ImplicitStringConcatMany::s114 = nullptr;
$String* ImplicitStringConcatMany::s115 = nullptr;
$String* ImplicitStringConcatMany::s116 = nullptr;
$String* ImplicitStringConcatMany::s117 = nullptr;
$String* ImplicitStringConcatMany::s118 = nullptr;
$String* ImplicitStringConcatMany::s119 = nullptr;
$String* ImplicitStringConcatMany::s120 = nullptr;
$String* ImplicitStringConcatMany::s121 = nullptr;
$String* ImplicitStringConcatMany::s122 = nullptr;
$String* ImplicitStringConcatMany::s123 = nullptr;
$String* ImplicitStringConcatMany::s124 = nullptr;
$String* ImplicitStringConcatMany::s125 = nullptr;
$String* ImplicitStringConcatMany::s126 = nullptr;
$String* ImplicitStringConcatMany::s127 = nullptr;
$String* ImplicitStringConcatMany::s128 = nullptr;
$String* ImplicitStringConcatMany::s129 = nullptr;
$String* ImplicitStringConcatMany::s130 = nullptr;
$String* ImplicitStringConcatMany::s131 = nullptr;
$String* ImplicitStringConcatMany::s132 = nullptr;
$String* ImplicitStringConcatMany::s133 = nullptr;
$String* ImplicitStringConcatMany::s134 = nullptr;
$String* ImplicitStringConcatMany::s135 = nullptr;
$String* ImplicitStringConcatMany::s136 = nullptr;
$String* ImplicitStringConcatMany::s137 = nullptr;
$String* ImplicitStringConcatMany::s138 = nullptr;
$String* ImplicitStringConcatMany::s139 = nullptr;
$String* ImplicitStringConcatMany::s140 = nullptr;
$String* ImplicitStringConcatMany::s141 = nullptr;
$String* ImplicitStringConcatMany::s142 = nullptr;
$String* ImplicitStringConcatMany::s143 = nullptr;
$String* ImplicitStringConcatMany::s144 = nullptr;
$String* ImplicitStringConcatMany::s145 = nullptr;
$String* ImplicitStringConcatMany::s146 = nullptr;
$String* ImplicitStringConcatMany::s147 = nullptr;
$String* ImplicitStringConcatMany::s148 = nullptr;
$String* ImplicitStringConcatMany::s149 = nullptr;
$String* ImplicitStringConcatMany::s150 = nullptr;
$String* ImplicitStringConcatMany::s151 = nullptr;
$String* ImplicitStringConcatMany::s152 = nullptr;
$String* ImplicitStringConcatMany::s153 = nullptr;
$String* ImplicitStringConcatMany::s154 = nullptr;
$String* ImplicitStringConcatMany::s155 = nullptr;
$String* ImplicitStringConcatMany::s156 = nullptr;
$String* ImplicitStringConcatMany::s157 = nullptr;
$String* ImplicitStringConcatMany::s158 = nullptr;
$String* ImplicitStringConcatMany::s159 = nullptr;
$String* ImplicitStringConcatMany::s160 = nullptr;
$String* ImplicitStringConcatMany::s161 = nullptr;
$String* ImplicitStringConcatMany::s162 = nullptr;
$String* ImplicitStringConcatMany::s163 = nullptr;
$String* ImplicitStringConcatMany::s164 = nullptr;
$String* ImplicitStringConcatMany::s165 = nullptr;
$String* ImplicitStringConcatMany::s166 = nullptr;
$String* ImplicitStringConcatMany::s167 = nullptr;
$String* ImplicitStringConcatMany::s168 = nullptr;
$String* ImplicitStringConcatMany::s169 = nullptr;
$String* ImplicitStringConcatMany::s170 = nullptr;
$String* ImplicitStringConcatMany::s171 = nullptr;
$String* ImplicitStringConcatMany::s172 = nullptr;
$String* ImplicitStringConcatMany::s173 = nullptr;
$String* ImplicitStringConcatMany::s174 = nullptr;
$String* ImplicitStringConcatMany::s175 = nullptr;
$String* ImplicitStringConcatMany::s176 = nullptr;
$String* ImplicitStringConcatMany::s177 = nullptr;
$String* ImplicitStringConcatMany::s178 = nullptr;
$String* ImplicitStringConcatMany::s179 = nullptr;
$String* ImplicitStringConcatMany::s180 = nullptr;
$String* ImplicitStringConcatMany::s181 = nullptr;
$String* ImplicitStringConcatMany::s182 = nullptr;
$String* ImplicitStringConcatMany::s183 = nullptr;
$String* ImplicitStringConcatMany::s184 = nullptr;
$String* ImplicitStringConcatMany::s185 = nullptr;
$String* ImplicitStringConcatMany::s186 = nullptr;
$String* ImplicitStringConcatMany::s187 = nullptr;
$String* ImplicitStringConcatMany::s188 = nullptr;
$String* ImplicitStringConcatMany::s189 = nullptr;
$String* ImplicitStringConcatMany::s190 = nullptr;
$String* ImplicitStringConcatMany::s191 = nullptr;
$String* ImplicitStringConcatMany::s192 = nullptr;
$String* ImplicitStringConcatMany::s193 = nullptr;
$String* ImplicitStringConcatMany::s194 = nullptr;
$String* ImplicitStringConcatMany::s195 = nullptr;
$String* ImplicitStringConcatMany::s196 = nullptr;
$String* ImplicitStringConcatMany::s197 = nullptr;
$String* ImplicitStringConcatMany::s198 = nullptr;
$String* ImplicitStringConcatMany::s199 = nullptr;
$String* ImplicitStringConcatMany::s200 = nullptr;
$String* ImplicitStringConcatMany::s201 = nullptr;
$String* ImplicitStringConcatMany::s202 = nullptr;
$String* ImplicitStringConcatMany::s203 = nullptr;
$String* ImplicitStringConcatMany::s204 = nullptr;
$String* ImplicitStringConcatMany::s205 = nullptr;
$String* ImplicitStringConcatMany::s206 = nullptr;
$String* ImplicitStringConcatMany::s207 = nullptr;
$String* ImplicitStringConcatMany::s208 = nullptr;
$String* ImplicitStringConcatMany::s209 = nullptr;
$String* ImplicitStringConcatMany::s210 = nullptr;
$String* ImplicitStringConcatMany::s211 = nullptr;
$String* ImplicitStringConcatMany::s212 = nullptr;
$String* ImplicitStringConcatMany::s213 = nullptr;
$String* ImplicitStringConcatMany::s214 = nullptr;
$String* ImplicitStringConcatMany::s215 = nullptr;
$String* ImplicitStringConcatMany::s216 = nullptr;
$String* ImplicitStringConcatMany::s217 = nullptr;
$String* ImplicitStringConcatMany::s218 = nullptr;
$String* ImplicitStringConcatMany::s219 = nullptr;
$String* ImplicitStringConcatMany::s220 = nullptr;
$String* ImplicitStringConcatMany::s221 = nullptr;
$String* ImplicitStringConcatMany::s222 = nullptr;
$String* ImplicitStringConcatMany::s223 = nullptr;
$String* ImplicitStringConcatMany::s224 = nullptr;
$String* ImplicitStringConcatMany::s225 = nullptr;
$String* ImplicitStringConcatMany::s226 = nullptr;
$String* ImplicitStringConcatMany::s227 = nullptr;
$String* ImplicitStringConcatMany::s228 = nullptr;
$String* ImplicitStringConcatMany::s229 = nullptr;
$String* ImplicitStringConcatMany::s230 = nullptr;
$String* ImplicitStringConcatMany::s231 = nullptr;
$String* ImplicitStringConcatMany::s232 = nullptr;
$String* ImplicitStringConcatMany::s233 = nullptr;
$String* ImplicitStringConcatMany::s234 = nullptr;
$String* ImplicitStringConcatMany::s235 = nullptr;
$String* ImplicitStringConcatMany::s236 = nullptr;
$String* ImplicitStringConcatMany::s237 = nullptr;
$String* ImplicitStringConcatMany::s238 = nullptr;
$String* ImplicitStringConcatMany::s239 = nullptr;
$String* ImplicitStringConcatMany::s240 = nullptr;
$String* ImplicitStringConcatMany::s241 = nullptr;
$String* ImplicitStringConcatMany::s242 = nullptr;
$String* ImplicitStringConcatMany::s243 = nullptr;
$String* ImplicitStringConcatMany::s244 = nullptr;
$String* ImplicitStringConcatMany::s245 = nullptr;
$String* ImplicitStringConcatMany::s246 = nullptr;
$String* ImplicitStringConcatMany::s247 = nullptr;
$String* ImplicitStringConcatMany::s248 = nullptr;
$String* ImplicitStringConcatMany::s249 = nullptr;
$String* ImplicitStringConcatMany::s250 = nullptr;
$String* ImplicitStringConcatMany::s251 = nullptr;
$String* ImplicitStringConcatMany::s252 = nullptr;
$String* ImplicitStringConcatMany::s253 = nullptr;
$String* ImplicitStringConcatMany::s254 = nullptr;
$String* ImplicitStringConcatMany::s255 = nullptr;
$String* ImplicitStringConcatMany::s256 = nullptr;
$String* ImplicitStringConcatMany::s257 = nullptr;
$String* ImplicitStringConcatMany::s258 = nullptr;
$String* ImplicitStringConcatMany::s259 = nullptr;
$String* ImplicitStringConcatMany::s260 = nullptr;
$String* ImplicitStringConcatMany::s261 = nullptr;
$String* ImplicitStringConcatMany::s262 = nullptr;
$String* ImplicitStringConcatMany::s263 = nullptr;
$String* ImplicitStringConcatMany::s264 = nullptr;
$String* ImplicitStringConcatMany::s265 = nullptr;
$String* ImplicitStringConcatMany::s266 = nullptr;
$String* ImplicitStringConcatMany::s267 = nullptr;
$String* ImplicitStringConcatMany::s268 = nullptr;
$String* ImplicitStringConcatMany::s269 = nullptr;
$String* ImplicitStringConcatMany::s270 = nullptr;
$String* ImplicitStringConcatMany::s271 = nullptr;
$String* ImplicitStringConcatMany::s272 = nullptr;
$String* ImplicitStringConcatMany::s273 = nullptr;
$String* ImplicitStringConcatMany::s274 = nullptr;
$String* ImplicitStringConcatMany::s275 = nullptr;
$String* ImplicitStringConcatMany::s276 = nullptr;
$String* ImplicitStringConcatMany::s277 = nullptr;
$String* ImplicitStringConcatMany::s278 = nullptr;
$String* ImplicitStringConcatMany::s279 = nullptr;
$String* ImplicitStringConcatMany::s280 = nullptr;
$String* ImplicitStringConcatMany::s281 = nullptr;
$String* ImplicitStringConcatMany::s282 = nullptr;
$String* ImplicitStringConcatMany::s283 = nullptr;
$String* ImplicitStringConcatMany::s284 = nullptr;
$String* ImplicitStringConcatMany::s285 = nullptr;
$String* ImplicitStringConcatMany::s286 = nullptr;
$String* ImplicitStringConcatMany::s287 = nullptr;
$String* ImplicitStringConcatMany::s288 = nullptr;
$String* ImplicitStringConcatMany::s289 = nullptr;
$String* ImplicitStringConcatMany::s290 = nullptr;
$String* ImplicitStringConcatMany::s291 = nullptr;
$String* ImplicitStringConcatMany::s292 = nullptr;
$String* ImplicitStringConcatMany::s293 = nullptr;
$String* ImplicitStringConcatMany::s294 = nullptr;
$String* ImplicitStringConcatMany::s295 = nullptr;
$String* ImplicitStringConcatMany::s296 = nullptr;
$String* ImplicitStringConcatMany::s297 = nullptr;
$String* ImplicitStringConcatMany::s298 = nullptr;
$String* ImplicitStringConcatMany::s299 = nullptr;

void ImplicitStringConcatMany::init$() {
}

void ImplicitStringConcatMany::main($StringArray* args) {
	$init(ImplicitStringConcatMany);
	$useLocalCurrentObjectStackCache();
	$var($String, res, $str({ImplicitStringConcatMany::s000, ImplicitStringConcatMany::s001, ImplicitStringConcatMany::s002, ImplicitStringConcatMany::s003, ImplicitStringConcatMany::s004, ImplicitStringConcatMany::s005, ImplicitStringConcatMany::s006, ImplicitStringConcatMany::s007, ImplicitStringConcatMany::s008, ImplicitStringConcatMany::s009, ImplicitStringConcatMany::s010, ImplicitStringConcatMany::s011, ImplicitStringConcatMany::s012, ImplicitStringConcatMany::s013, ImplicitStringConcatMany::s014, ImplicitStringConcatMany::s015, 
	ImplicitStringConcatMany::s016, ImplicitStringConcatMany::s017, ImplicitStringConcatMany::s018, ImplicitStringConcatMany::s019, ImplicitStringConcatMany::s020, ImplicitStringConcatMany::s021, ImplicitStringConcatMany::s022, ImplicitStringConcatMany::s023, ImplicitStringConcatMany::s024, ImplicitStringConcatMany::s025, ImplicitStringConcatMany::s026, ImplicitStringConcatMany::s027, ImplicitStringConcatMany::s028, ImplicitStringConcatMany::s029, ImplicitStringConcatMany::s030, ImplicitStringConcatMany::s031, 
	ImplicitStringConcatMany::s032, ImplicitStringConcatMany::s033, ImplicitStringConcatMany::s034, ImplicitStringConcatMany::s035, ImplicitStringConcatMany::s036, ImplicitStringConcatMany::s037, ImplicitStringConcatMany::s038, ImplicitStringConcatMany::s039, ImplicitStringConcatMany::s040, ImplicitStringConcatMany::s041, ImplicitStringConcatMany::s042, ImplicitStringConcatMany::s043, ImplicitStringConcatMany::s044, ImplicitStringConcatMany::s045, ImplicitStringConcatMany::s046, ImplicitStringConcatMany::s047, 
	ImplicitStringConcatMany::s048, ImplicitStringConcatMany::s049, ImplicitStringConcatMany::s050, ImplicitStringConcatMany::s051, ImplicitStringConcatMany::s052, ImplicitStringConcatMany::s053, ImplicitStringConcatMany::s054, ImplicitStringConcatMany::s055, ImplicitStringConcatMany::s056, ImplicitStringConcatMany::s057, ImplicitStringConcatMany::s058, ImplicitStringConcatMany::s059, ImplicitStringConcatMany::s060, ImplicitStringConcatMany::s061, ImplicitStringConcatMany::s062, ImplicitStringConcatMany::s063, 
	ImplicitStringConcatMany::s064, ImplicitStringConcatMany::s065, ImplicitStringConcatMany::s066, ImplicitStringConcatMany::s067, ImplicitStringConcatMany::s068, ImplicitStringConcatMany::s069, ImplicitStringConcatMany::s070, ImplicitStringConcatMany::s071, ImplicitStringConcatMany::s072, ImplicitStringConcatMany::s073, ImplicitStringConcatMany::s074, ImplicitStringConcatMany::s075, ImplicitStringConcatMany::s076, ImplicitStringConcatMany::s077, ImplicitStringConcatMany::s078, ImplicitStringConcatMany::s079, 
	ImplicitStringConcatMany::s080, ImplicitStringConcatMany::s081, ImplicitStringConcatMany::s082, ImplicitStringConcatMany::s083, ImplicitStringConcatMany::s084, ImplicitStringConcatMany::s085, ImplicitStringConcatMany::s086, ImplicitStringConcatMany::s087, ImplicitStringConcatMany::s088, ImplicitStringConcatMany::s089, ImplicitStringConcatMany::s090, ImplicitStringConcatMany::s091, ImplicitStringConcatMany::s092, ImplicitStringConcatMany::s093, ImplicitStringConcatMany::s094, ImplicitStringConcatMany::s095, 
	ImplicitStringConcatMany::s096, ImplicitStringConcatMany::s097, ImplicitStringConcatMany::s098, ImplicitStringConcatMany::s099, ImplicitStringConcatMany::s100, ImplicitStringConcatMany::s101, ImplicitStringConcatMany::s102, ImplicitStringConcatMany::s103, ImplicitStringConcatMany::s104, ImplicitStringConcatMany::s105, ImplicitStringConcatMany::s106, ImplicitStringConcatMany::s107, ImplicitStringConcatMany::s108, ImplicitStringConcatMany::s109, ImplicitStringConcatMany::s110, ImplicitStringConcatMany::s111, 
	ImplicitStringConcatMany::s112, ImplicitStringConcatMany::s113, ImplicitStringConcatMany::s114, ImplicitStringConcatMany::s115, ImplicitStringConcatMany::s116, ImplicitStringConcatMany::s117, ImplicitStringConcatMany::s118, ImplicitStringConcatMany::s119, ImplicitStringConcatMany::s120, ImplicitStringConcatMany::s121, ImplicitStringConcatMany::s122, ImplicitStringConcatMany::s123, ImplicitStringConcatMany::s124, ImplicitStringConcatMany::s125, ImplicitStringConcatMany::s126, ImplicitStringConcatMany::s127, 
	ImplicitStringConcatMany::s128, ImplicitStringConcatMany::s129, ImplicitStringConcatMany::s130, ImplicitStringConcatMany::s131, ImplicitStringConcatMany::s132, ImplicitStringConcatMany::s133, ImplicitStringConcatMany::s134, ImplicitStringConcatMany::s135, ImplicitStringConcatMany::s136, ImplicitStringConcatMany::s137, ImplicitStringConcatMany::s138, ImplicitStringConcatMany::s139, ImplicitStringConcatMany::s140, ImplicitStringConcatMany::s141, ImplicitStringConcatMany::s142, ImplicitStringConcatMany::s143, 
	ImplicitStringConcatMany::s144, ImplicitStringConcatMany::s145, ImplicitStringConcatMany::s146, ImplicitStringConcatMany::s147, ImplicitStringConcatMany::s148, ImplicitStringConcatMany::s149, ImplicitStringConcatMany::s150, ImplicitStringConcatMany::s151, ImplicitStringConcatMany::s152, ImplicitStringConcatMany::s153, ImplicitStringConcatMany::s154, ImplicitStringConcatMany::s155, ImplicitStringConcatMany::s156, ImplicitStringConcatMany::s157, ImplicitStringConcatMany::s158, ImplicitStringConcatMany::s159, 
	ImplicitStringConcatMany::s160, ImplicitStringConcatMany::s161, ImplicitStringConcatMany::s162, ImplicitStringConcatMany::s163, ImplicitStringConcatMany::s164, ImplicitStringConcatMany::s165, ImplicitStringConcatMany::s166, ImplicitStringConcatMany::s167, ImplicitStringConcatMany::s168, ImplicitStringConcatMany::s169, ImplicitStringConcatMany::s170, ImplicitStringConcatMany::s171, ImplicitStringConcatMany::s172, ImplicitStringConcatMany::s173, ImplicitStringConcatMany::s174, ImplicitStringConcatMany::s175, 
	ImplicitStringConcatMany::s176, ImplicitStringConcatMany::s177, ImplicitStringConcatMany::s178, ImplicitStringConcatMany::s179, ImplicitStringConcatMany::s180, ImplicitStringConcatMany::s181, ImplicitStringConcatMany::s182, ImplicitStringConcatMany::s183, ImplicitStringConcatMany::s184, ImplicitStringConcatMany::s185, ImplicitStringConcatMany::s186, ImplicitStringConcatMany::s187, ImplicitStringConcatMany::s188, ImplicitStringConcatMany::s189, ImplicitStringConcatMany::s190, ImplicitStringConcatMany::s191, 
	ImplicitStringConcatMany::s192, ImplicitStringConcatMany::s193, ImplicitStringConcatMany::s194, ImplicitStringConcatMany::s195, ImplicitStringConcatMany::s196, ImplicitStringConcatMany::s197, ImplicitStringConcatMany::s198, ImplicitStringConcatMany::s199, ImplicitStringConcatMany::s200, ImplicitStringConcatMany::s201, ImplicitStringConcatMany::s202, ImplicitStringConcatMany::s203, ImplicitStringConcatMany::s204, ImplicitStringConcatMany::s205, ImplicitStringConcatMany::s206, ImplicitStringConcatMany::s207, 
	ImplicitStringConcatMany::s208, ImplicitStringConcatMany::s209, ImplicitStringConcatMany::s210, ImplicitStringConcatMany::s211, ImplicitStringConcatMany::s212, ImplicitStringConcatMany::s213, ImplicitStringConcatMany::s214, ImplicitStringConcatMany::s215, ImplicitStringConcatMany::s216, ImplicitStringConcatMany::s217, ImplicitStringConcatMany::s218, ImplicitStringConcatMany::s219, ImplicitStringConcatMany::s220, ImplicitStringConcatMany::s221, ImplicitStringConcatMany::s222, ImplicitStringConcatMany::s223, 
	ImplicitStringConcatMany::s224, ImplicitStringConcatMany::s225, ImplicitStringConcatMany::s226, ImplicitStringConcatMany::s227, ImplicitStringConcatMany::s228, ImplicitStringConcatMany::s229, ImplicitStringConcatMany::s230, ImplicitStringConcatMany::s231, ImplicitStringConcatMany::s232, ImplicitStringConcatMany::s233, ImplicitStringConcatMany::s234, ImplicitStringConcatMany::s235, ImplicitStringConcatMany::s236, ImplicitStringConcatMany::s237, ImplicitStringConcatMany::s238, ImplicitStringConcatMany::s239, 
	ImplicitStringConcatMany::s240, ImplicitStringConcatMany::s241, ImplicitStringConcatMany::s242, ImplicitStringConcatMany::s243, ImplicitStringConcatMany::s244, ImplicitStringConcatMany::s245, ImplicitStringConcatMany::s246, ImplicitStringConcatMany::s247, ImplicitStringConcatMany::s248, ImplicitStringConcatMany::s249, ImplicitStringConcatMany::s250, ImplicitStringConcatMany::s251, ImplicitStringConcatMany::s252, ImplicitStringConcatMany::s253, ImplicitStringConcatMany::s254, ImplicitStringConcatMany::s255, 
	ImplicitStringConcatMany::s256, ImplicitStringConcatMany::s257, ImplicitStringConcatMany::s258, ImplicitStringConcatMany::s259, ImplicitStringConcatMany::s260, ImplicitStringConcatMany::s261, ImplicitStringConcatMany::s262, ImplicitStringConcatMany::s263, ImplicitStringConcatMany::s264, ImplicitStringConcatMany::s265, ImplicitStringConcatMany::s266, ImplicitStringConcatMany::s267, ImplicitStringConcatMany::s268, ImplicitStringConcatMany::s269, ImplicitStringConcatMany::s270, ImplicitStringConcatMany::s271, 
	ImplicitStringConcatMany::s272, ImplicitStringConcatMany::s273, ImplicitStringConcatMany::s274, ImplicitStringConcatMany::s275, ImplicitStringConcatMany::s276, ImplicitStringConcatMany::s277, ImplicitStringConcatMany::s278, ImplicitStringConcatMany::s279, ImplicitStringConcatMany::s280, ImplicitStringConcatMany::s281, ImplicitStringConcatMany::s282, ImplicitStringConcatMany::s283, ImplicitStringConcatMany::s284, ImplicitStringConcatMany::s285, ImplicitStringConcatMany::s286, ImplicitStringConcatMany::s287, 
	ImplicitStringConcatMany::s288, ImplicitStringConcatMany::s289, ImplicitStringConcatMany::s290, ImplicitStringConcatMany::s291, ImplicitStringConcatMany::s292, ImplicitStringConcatMany::s293, ImplicitStringConcatMany::s294, ImplicitStringConcatMany::s295, ImplicitStringConcatMany::s296, ImplicitStringConcatMany::s297, ImplicitStringConcatMany::s298, ImplicitStringConcatMany::s299}));
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t c = 0; c < 300; ++c) {
		sb->append($($String::format("s%03d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(c)))}))));
	}
	test($(sb->toString()), res);
}

void ImplicitStringConcatMany::test($String* expected, $String* actual) {
	$init(ImplicitStringConcatMany);
	if (!$nc(expected)->equals(actual)) {
		$throwNew($IllegalStateException, $$str({"Expected = "_s, expected, ", actual = "_s, actual}));
	}
}

void clinit$ImplicitStringConcatMany($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		{
			$var($FieldArray, arr$, ImplicitStringConcatMany::class$->getDeclaredFields());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Field, f, arr$->get(i$));
				{
					if ($Modifier::isStatic($nc(f)->getModifiers())) {
						$var($String, name, $nc(f)->getName());
						try {
							f->set(nullptr, name);
						} catch ($IllegalAccessException& e) {
							$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
						}
					}
				}
			}
		}
	}
}

ImplicitStringConcatMany::ImplicitStringConcatMany() {
}

$Class* ImplicitStringConcatMany::load$($String* name, bool initialize) {
	$loadClass(ImplicitStringConcatMany, name, initialize, &_ImplicitStringConcatMany_ClassInfo_, clinit$ImplicitStringConcatMany, allocate$ImplicitStringConcatMany);
	return class$;
}

$Class* ImplicitStringConcatMany::class$ = nullptr;
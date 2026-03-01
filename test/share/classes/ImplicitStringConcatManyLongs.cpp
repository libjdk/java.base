#include <ImplicitStringConcatManyLongs.h>

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
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;

$FieldInfo _ImplicitStringConcatManyLongs_FieldInfo_[] = {
	{"s000", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s000)},
	{"s001", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s001)},
	{"s002", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s002)},
	{"s003", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s003)},
	{"s004", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s004)},
	{"s005", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s005)},
	{"s006", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s006)},
	{"s007", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s007)},
	{"s008", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s008)},
	{"s009", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s009)},
	{"s010", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s010)},
	{"s011", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s011)},
	{"s012", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s012)},
	{"s013", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s013)},
	{"s014", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s014)},
	{"s015", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s015)},
	{"s016", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s016)},
	{"s017", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s017)},
	{"s018", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s018)},
	{"s019", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s019)},
	{"s020", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s020)},
	{"s021", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s021)},
	{"s022", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s022)},
	{"s023", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s023)},
	{"s024", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s024)},
	{"s025", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s025)},
	{"s026", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s026)},
	{"s027", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s027)},
	{"s028", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s028)},
	{"s029", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s029)},
	{"s030", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s030)},
	{"s031", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s031)},
	{"s032", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s032)},
	{"s033", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s033)},
	{"s034", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s034)},
	{"s035", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s035)},
	{"s036", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s036)},
	{"s037", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s037)},
	{"s038", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s038)},
	{"s039", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s039)},
	{"s040", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s040)},
	{"s041", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s041)},
	{"s042", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s042)},
	{"s043", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s043)},
	{"s044", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s044)},
	{"s045", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s045)},
	{"s046", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s046)},
	{"s047", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s047)},
	{"s048", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s048)},
	{"s049", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s049)},
	{"s050", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s050)},
	{"s051", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s051)},
	{"s052", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s052)},
	{"s053", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s053)},
	{"s054", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s054)},
	{"s055", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s055)},
	{"s056", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s056)},
	{"s057", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s057)},
	{"s058", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s058)},
	{"s059", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s059)},
	{"s060", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s060)},
	{"s061", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s061)},
	{"s062", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s062)},
	{"s063", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s063)},
	{"s064", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s064)},
	{"s065", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s065)},
	{"s066", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s066)},
	{"s067", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s067)},
	{"s068", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s068)},
	{"s069", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s069)},
	{"s070", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s070)},
	{"s071", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s071)},
	{"s072", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s072)},
	{"s073", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s073)},
	{"s074", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s074)},
	{"s075", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s075)},
	{"s076", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s076)},
	{"s077", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s077)},
	{"s078", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s078)},
	{"s079", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s079)},
	{"s080", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s080)},
	{"s081", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s081)},
	{"s082", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s082)},
	{"s083", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s083)},
	{"s084", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s084)},
	{"s085", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s085)},
	{"s086", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s086)},
	{"s087", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s087)},
	{"s088", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s088)},
	{"s089", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s089)},
	{"s090", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s090)},
	{"s091", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s091)},
	{"s092", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s092)},
	{"s093", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s093)},
	{"s094", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s094)},
	{"s095", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s095)},
	{"s096", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s096)},
	{"s097", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s097)},
	{"s098", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s098)},
	{"s099", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s099)},
	{"s100", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s100)},
	{"s101", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s101)},
	{"s102", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s102)},
	{"s103", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s103)},
	{"s104", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s104)},
	{"s105", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s105)},
	{"s106", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s106)},
	{"s107", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s107)},
	{"s108", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s108)},
	{"s109", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s109)},
	{"s110", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s110)},
	{"s111", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s111)},
	{"s112", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s112)},
	{"s113", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s113)},
	{"s114", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s114)},
	{"s115", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s115)},
	{"s116", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s116)},
	{"s117", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s117)},
	{"s118", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s118)},
	{"s119", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s119)},
	{"s120", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s120)},
	{"s121", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s121)},
	{"s122", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s122)},
	{"s123", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s123)},
	{"s124", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s124)},
	{"s125", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s125)},
	{"s126", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s126)},
	{"s127", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s127)},
	{"s128", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s128)},
	{"s129", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s129)},
	{"s130", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s130)},
	{"s131", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s131)},
	{"s132", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s132)},
	{"s133", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s133)},
	{"s134", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s134)},
	{"s135", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s135)},
	{"s136", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s136)},
	{"s137", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s137)},
	{"s138", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s138)},
	{"s139", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s139)},
	{"s140", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s140)},
	{"s141", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s141)},
	{"s142", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s142)},
	{"s143", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s143)},
	{"s144", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s144)},
	{"s145", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s145)},
	{"s146", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s146)},
	{"s147", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s147)},
	{"s148", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s148)},
	{"s149", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s149)},
	{"s150", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s150)},
	{"s151", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s151)},
	{"s152", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s152)},
	{"s153", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s153)},
	{"s154", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s154)},
	{"s155", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s155)},
	{"s156", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s156)},
	{"s157", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s157)},
	{"s158", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s158)},
	{"s159", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s159)},
	{"s160", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s160)},
	{"s161", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s161)},
	{"s162", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s162)},
	{"s163", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s163)},
	{"s164", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s164)},
	{"s165", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s165)},
	{"s166", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s166)},
	{"s167", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s167)},
	{"s168", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s168)},
	{"s169", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s169)},
	{"s170", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s170)},
	{"s171", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s171)},
	{"s172", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s172)},
	{"s173", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s173)},
	{"s174", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s174)},
	{"s175", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s175)},
	{"s176", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s176)},
	{"s177", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s177)},
	{"s178", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s178)},
	{"s179", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s179)},
	{"s180", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s180)},
	{"s181", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s181)},
	{"s182", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s182)},
	{"s183", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s183)},
	{"s184", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s184)},
	{"s185", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s185)},
	{"s186", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s186)},
	{"s187", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s187)},
	{"s188", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s188)},
	{"s189", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s189)},
	{"s190", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s190)},
	{"s191", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s191)},
	{"s192", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s192)},
	{"s193", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s193)},
	{"s194", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s194)},
	{"s195", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s195)},
	{"s196", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s196)},
	{"s197", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s197)},
	{"s198", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s198)},
	{"s199", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s199)},
	{"s200", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s200)},
	{"s201", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s201)},
	{"s202", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s202)},
	{"s203", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s203)},
	{"s204", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s204)},
	{"s205", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s205)},
	{"s206", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s206)},
	{"s207", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s207)},
	{"s208", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s208)},
	{"s209", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s209)},
	{"s210", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s210)},
	{"s211", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s211)},
	{"s212", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s212)},
	{"s213", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s213)},
	{"s214", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s214)},
	{"s215", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s215)},
	{"s216", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s216)},
	{"s217", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s217)},
	{"s218", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s218)},
	{"s219", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s219)},
	{"s220", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s220)},
	{"s221", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s221)},
	{"s222", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s222)},
	{"s223", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s223)},
	{"s224", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s224)},
	{"s225", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s225)},
	{"s226", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s226)},
	{"s227", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s227)},
	{"s228", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s228)},
	{"s229", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s229)},
	{"s230", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s230)},
	{"s231", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s231)},
	{"s232", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s232)},
	{"s233", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s233)},
	{"s234", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s234)},
	{"s235", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s235)},
	{"s236", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s236)},
	{"s237", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s237)},
	{"s238", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s238)},
	{"s239", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s239)},
	{"s240", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s240)},
	{"s241", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s241)},
	{"s242", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s242)},
	{"s243", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s243)},
	{"s244", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s244)},
	{"s245", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s245)},
	{"s246", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s246)},
	{"s247", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s247)},
	{"s248", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s248)},
	{"s249", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s249)},
	{"s250", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s250)},
	{"s251", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s251)},
	{"s252", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s252)},
	{"s253", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s253)},
	{"s254", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s254)},
	{"s255", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s255)},
	{"s256", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s256)},
	{"s257", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s257)},
	{"s258", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s258)},
	{"s259", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s259)},
	{"s260", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s260)},
	{"s261", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s261)},
	{"s262", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s262)},
	{"s263", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s263)},
	{"s264", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s264)},
	{"s265", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s265)},
	{"s266", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s266)},
	{"s267", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s267)},
	{"s268", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s268)},
	{"s269", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s269)},
	{"s270", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s270)},
	{"s271", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s271)},
	{"s272", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s272)},
	{"s273", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s273)},
	{"s274", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s274)},
	{"s275", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s275)},
	{"s276", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s276)},
	{"s277", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s277)},
	{"s278", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s278)},
	{"s279", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s279)},
	{"s280", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s280)},
	{"s281", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s281)},
	{"s282", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s282)},
	{"s283", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s283)},
	{"s284", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s284)},
	{"s285", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s285)},
	{"s286", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s286)},
	{"s287", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s287)},
	{"s288", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s288)},
	{"s289", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s289)},
	{"s290", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s290)},
	{"s291", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s291)},
	{"s292", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s292)},
	{"s293", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s293)},
	{"s294", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s294)},
	{"s295", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s295)},
	{"s296", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s296)},
	{"s297", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s297)},
	{"s298", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s298)},
	{"s299", "J", nullptr, $STATIC, $staticField(ImplicitStringConcatManyLongs, s299)},
	{}
};

$MethodInfo _ImplicitStringConcatManyLongs_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(ImplicitStringConcatManyLongs, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ImplicitStringConcatManyLongs, main, void, $StringArray*), "java.lang.Exception"},
	{"test", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(ImplicitStringConcatManyLongs, test, void, $String*, $String*)},
	{}
};

$ClassInfo _ImplicitStringConcatManyLongs_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"ImplicitStringConcatManyLongs",
	"java.lang.Object",
	nullptr,
	_ImplicitStringConcatManyLongs_FieldInfo_,
	_ImplicitStringConcatManyLongs_MethodInfo_
};

$Object* allocate$ImplicitStringConcatManyLongs($Class* clazz) {
	return $of($alloc(ImplicitStringConcatManyLongs));
}

int64_t ImplicitStringConcatManyLongs::s000 = 0;
int64_t ImplicitStringConcatManyLongs::s001 = 0;
int64_t ImplicitStringConcatManyLongs::s002 = 0;
int64_t ImplicitStringConcatManyLongs::s003 = 0;
int64_t ImplicitStringConcatManyLongs::s004 = 0;
int64_t ImplicitStringConcatManyLongs::s005 = 0;
int64_t ImplicitStringConcatManyLongs::s006 = 0;
int64_t ImplicitStringConcatManyLongs::s007 = 0;
int64_t ImplicitStringConcatManyLongs::s008 = 0;
int64_t ImplicitStringConcatManyLongs::s009 = 0;
int64_t ImplicitStringConcatManyLongs::s010 = 0;
int64_t ImplicitStringConcatManyLongs::s011 = 0;
int64_t ImplicitStringConcatManyLongs::s012 = 0;
int64_t ImplicitStringConcatManyLongs::s013 = 0;
int64_t ImplicitStringConcatManyLongs::s014 = 0;
int64_t ImplicitStringConcatManyLongs::s015 = 0;
int64_t ImplicitStringConcatManyLongs::s016 = 0;
int64_t ImplicitStringConcatManyLongs::s017 = 0;
int64_t ImplicitStringConcatManyLongs::s018 = 0;
int64_t ImplicitStringConcatManyLongs::s019 = 0;
int64_t ImplicitStringConcatManyLongs::s020 = 0;
int64_t ImplicitStringConcatManyLongs::s021 = 0;
int64_t ImplicitStringConcatManyLongs::s022 = 0;
int64_t ImplicitStringConcatManyLongs::s023 = 0;
int64_t ImplicitStringConcatManyLongs::s024 = 0;
int64_t ImplicitStringConcatManyLongs::s025 = 0;
int64_t ImplicitStringConcatManyLongs::s026 = 0;
int64_t ImplicitStringConcatManyLongs::s027 = 0;
int64_t ImplicitStringConcatManyLongs::s028 = 0;
int64_t ImplicitStringConcatManyLongs::s029 = 0;
int64_t ImplicitStringConcatManyLongs::s030 = 0;
int64_t ImplicitStringConcatManyLongs::s031 = 0;
int64_t ImplicitStringConcatManyLongs::s032 = 0;
int64_t ImplicitStringConcatManyLongs::s033 = 0;
int64_t ImplicitStringConcatManyLongs::s034 = 0;
int64_t ImplicitStringConcatManyLongs::s035 = 0;
int64_t ImplicitStringConcatManyLongs::s036 = 0;
int64_t ImplicitStringConcatManyLongs::s037 = 0;
int64_t ImplicitStringConcatManyLongs::s038 = 0;
int64_t ImplicitStringConcatManyLongs::s039 = 0;
int64_t ImplicitStringConcatManyLongs::s040 = 0;
int64_t ImplicitStringConcatManyLongs::s041 = 0;
int64_t ImplicitStringConcatManyLongs::s042 = 0;
int64_t ImplicitStringConcatManyLongs::s043 = 0;
int64_t ImplicitStringConcatManyLongs::s044 = 0;
int64_t ImplicitStringConcatManyLongs::s045 = 0;
int64_t ImplicitStringConcatManyLongs::s046 = 0;
int64_t ImplicitStringConcatManyLongs::s047 = 0;
int64_t ImplicitStringConcatManyLongs::s048 = 0;
int64_t ImplicitStringConcatManyLongs::s049 = 0;
int64_t ImplicitStringConcatManyLongs::s050 = 0;
int64_t ImplicitStringConcatManyLongs::s051 = 0;
int64_t ImplicitStringConcatManyLongs::s052 = 0;
int64_t ImplicitStringConcatManyLongs::s053 = 0;
int64_t ImplicitStringConcatManyLongs::s054 = 0;
int64_t ImplicitStringConcatManyLongs::s055 = 0;
int64_t ImplicitStringConcatManyLongs::s056 = 0;
int64_t ImplicitStringConcatManyLongs::s057 = 0;
int64_t ImplicitStringConcatManyLongs::s058 = 0;
int64_t ImplicitStringConcatManyLongs::s059 = 0;
int64_t ImplicitStringConcatManyLongs::s060 = 0;
int64_t ImplicitStringConcatManyLongs::s061 = 0;
int64_t ImplicitStringConcatManyLongs::s062 = 0;
int64_t ImplicitStringConcatManyLongs::s063 = 0;
int64_t ImplicitStringConcatManyLongs::s064 = 0;
int64_t ImplicitStringConcatManyLongs::s065 = 0;
int64_t ImplicitStringConcatManyLongs::s066 = 0;
int64_t ImplicitStringConcatManyLongs::s067 = 0;
int64_t ImplicitStringConcatManyLongs::s068 = 0;
int64_t ImplicitStringConcatManyLongs::s069 = 0;
int64_t ImplicitStringConcatManyLongs::s070 = 0;
int64_t ImplicitStringConcatManyLongs::s071 = 0;
int64_t ImplicitStringConcatManyLongs::s072 = 0;
int64_t ImplicitStringConcatManyLongs::s073 = 0;
int64_t ImplicitStringConcatManyLongs::s074 = 0;
int64_t ImplicitStringConcatManyLongs::s075 = 0;
int64_t ImplicitStringConcatManyLongs::s076 = 0;
int64_t ImplicitStringConcatManyLongs::s077 = 0;
int64_t ImplicitStringConcatManyLongs::s078 = 0;
int64_t ImplicitStringConcatManyLongs::s079 = 0;
int64_t ImplicitStringConcatManyLongs::s080 = 0;
int64_t ImplicitStringConcatManyLongs::s081 = 0;
int64_t ImplicitStringConcatManyLongs::s082 = 0;
int64_t ImplicitStringConcatManyLongs::s083 = 0;
int64_t ImplicitStringConcatManyLongs::s084 = 0;
int64_t ImplicitStringConcatManyLongs::s085 = 0;
int64_t ImplicitStringConcatManyLongs::s086 = 0;
int64_t ImplicitStringConcatManyLongs::s087 = 0;
int64_t ImplicitStringConcatManyLongs::s088 = 0;
int64_t ImplicitStringConcatManyLongs::s089 = 0;
int64_t ImplicitStringConcatManyLongs::s090 = 0;
int64_t ImplicitStringConcatManyLongs::s091 = 0;
int64_t ImplicitStringConcatManyLongs::s092 = 0;
int64_t ImplicitStringConcatManyLongs::s093 = 0;
int64_t ImplicitStringConcatManyLongs::s094 = 0;
int64_t ImplicitStringConcatManyLongs::s095 = 0;
int64_t ImplicitStringConcatManyLongs::s096 = 0;
int64_t ImplicitStringConcatManyLongs::s097 = 0;
int64_t ImplicitStringConcatManyLongs::s098 = 0;
int64_t ImplicitStringConcatManyLongs::s099 = 0;
int64_t ImplicitStringConcatManyLongs::s100 = 0;
int64_t ImplicitStringConcatManyLongs::s101 = 0;
int64_t ImplicitStringConcatManyLongs::s102 = 0;
int64_t ImplicitStringConcatManyLongs::s103 = 0;
int64_t ImplicitStringConcatManyLongs::s104 = 0;
int64_t ImplicitStringConcatManyLongs::s105 = 0;
int64_t ImplicitStringConcatManyLongs::s106 = 0;
int64_t ImplicitStringConcatManyLongs::s107 = 0;
int64_t ImplicitStringConcatManyLongs::s108 = 0;
int64_t ImplicitStringConcatManyLongs::s109 = 0;
int64_t ImplicitStringConcatManyLongs::s110 = 0;
int64_t ImplicitStringConcatManyLongs::s111 = 0;
int64_t ImplicitStringConcatManyLongs::s112 = 0;
int64_t ImplicitStringConcatManyLongs::s113 = 0;
int64_t ImplicitStringConcatManyLongs::s114 = 0;
int64_t ImplicitStringConcatManyLongs::s115 = 0;
int64_t ImplicitStringConcatManyLongs::s116 = 0;
int64_t ImplicitStringConcatManyLongs::s117 = 0;
int64_t ImplicitStringConcatManyLongs::s118 = 0;
int64_t ImplicitStringConcatManyLongs::s119 = 0;
int64_t ImplicitStringConcatManyLongs::s120 = 0;
int64_t ImplicitStringConcatManyLongs::s121 = 0;
int64_t ImplicitStringConcatManyLongs::s122 = 0;
int64_t ImplicitStringConcatManyLongs::s123 = 0;
int64_t ImplicitStringConcatManyLongs::s124 = 0;
int64_t ImplicitStringConcatManyLongs::s125 = 0;
int64_t ImplicitStringConcatManyLongs::s126 = 0;
int64_t ImplicitStringConcatManyLongs::s127 = 0;
int64_t ImplicitStringConcatManyLongs::s128 = 0;
int64_t ImplicitStringConcatManyLongs::s129 = 0;
int64_t ImplicitStringConcatManyLongs::s130 = 0;
int64_t ImplicitStringConcatManyLongs::s131 = 0;
int64_t ImplicitStringConcatManyLongs::s132 = 0;
int64_t ImplicitStringConcatManyLongs::s133 = 0;
int64_t ImplicitStringConcatManyLongs::s134 = 0;
int64_t ImplicitStringConcatManyLongs::s135 = 0;
int64_t ImplicitStringConcatManyLongs::s136 = 0;
int64_t ImplicitStringConcatManyLongs::s137 = 0;
int64_t ImplicitStringConcatManyLongs::s138 = 0;
int64_t ImplicitStringConcatManyLongs::s139 = 0;
int64_t ImplicitStringConcatManyLongs::s140 = 0;
int64_t ImplicitStringConcatManyLongs::s141 = 0;
int64_t ImplicitStringConcatManyLongs::s142 = 0;
int64_t ImplicitStringConcatManyLongs::s143 = 0;
int64_t ImplicitStringConcatManyLongs::s144 = 0;
int64_t ImplicitStringConcatManyLongs::s145 = 0;
int64_t ImplicitStringConcatManyLongs::s146 = 0;
int64_t ImplicitStringConcatManyLongs::s147 = 0;
int64_t ImplicitStringConcatManyLongs::s148 = 0;
int64_t ImplicitStringConcatManyLongs::s149 = 0;
int64_t ImplicitStringConcatManyLongs::s150 = 0;
int64_t ImplicitStringConcatManyLongs::s151 = 0;
int64_t ImplicitStringConcatManyLongs::s152 = 0;
int64_t ImplicitStringConcatManyLongs::s153 = 0;
int64_t ImplicitStringConcatManyLongs::s154 = 0;
int64_t ImplicitStringConcatManyLongs::s155 = 0;
int64_t ImplicitStringConcatManyLongs::s156 = 0;
int64_t ImplicitStringConcatManyLongs::s157 = 0;
int64_t ImplicitStringConcatManyLongs::s158 = 0;
int64_t ImplicitStringConcatManyLongs::s159 = 0;
int64_t ImplicitStringConcatManyLongs::s160 = 0;
int64_t ImplicitStringConcatManyLongs::s161 = 0;
int64_t ImplicitStringConcatManyLongs::s162 = 0;
int64_t ImplicitStringConcatManyLongs::s163 = 0;
int64_t ImplicitStringConcatManyLongs::s164 = 0;
int64_t ImplicitStringConcatManyLongs::s165 = 0;
int64_t ImplicitStringConcatManyLongs::s166 = 0;
int64_t ImplicitStringConcatManyLongs::s167 = 0;
int64_t ImplicitStringConcatManyLongs::s168 = 0;
int64_t ImplicitStringConcatManyLongs::s169 = 0;
int64_t ImplicitStringConcatManyLongs::s170 = 0;
int64_t ImplicitStringConcatManyLongs::s171 = 0;
int64_t ImplicitStringConcatManyLongs::s172 = 0;
int64_t ImplicitStringConcatManyLongs::s173 = 0;
int64_t ImplicitStringConcatManyLongs::s174 = 0;
int64_t ImplicitStringConcatManyLongs::s175 = 0;
int64_t ImplicitStringConcatManyLongs::s176 = 0;
int64_t ImplicitStringConcatManyLongs::s177 = 0;
int64_t ImplicitStringConcatManyLongs::s178 = 0;
int64_t ImplicitStringConcatManyLongs::s179 = 0;
int64_t ImplicitStringConcatManyLongs::s180 = 0;
int64_t ImplicitStringConcatManyLongs::s181 = 0;
int64_t ImplicitStringConcatManyLongs::s182 = 0;
int64_t ImplicitStringConcatManyLongs::s183 = 0;
int64_t ImplicitStringConcatManyLongs::s184 = 0;
int64_t ImplicitStringConcatManyLongs::s185 = 0;
int64_t ImplicitStringConcatManyLongs::s186 = 0;
int64_t ImplicitStringConcatManyLongs::s187 = 0;
int64_t ImplicitStringConcatManyLongs::s188 = 0;
int64_t ImplicitStringConcatManyLongs::s189 = 0;
int64_t ImplicitStringConcatManyLongs::s190 = 0;
int64_t ImplicitStringConcatManyLongs::s191 = 0;
int64_t ImplicitStringConcatManyLongs::s192 = 0;
int64_t ImplicitStringConcatManyLongs::s193 = 0;
int64_t ImplicitStringConcatManyLongs::s194 = 0;
int64_t ImplicitStringConcatManyLongs::s195 = 0;
int64_t ImplicitStringConcatManyLongs::s196 = 0;
int64_t ImplicitStringConcatManyLongs::s197 = 0;
int64_t ImplicitStringConcatManyLongs::s198 = 0;
int64_t ImplicitStringConcatManyLongs::s199 = 0;
int64_t ImplicitStringConcatManyLongs::s200 = 0;
int64_t ImplicitStringConcatManyLongs::s201 = 0;
int64_t ImplicitStringConcatManyLongs::s202 = 0;
int64_t ImplicitStringConcatManyLongs::s203 = 0;
int64_t ImplicitStringConcatManyLongs::s204 = 0;
int64_t ImplicitStringConcatManyLongs::s205 = 0;
int64_t ImplicitStringConcatManyLongs::s206 = 0;
int64_t ImplicitStringConcatManyLongs::s207 = 0;
int64_t ImplicitStringConcatManyLongs::s208 = 0;
int64_t ImplicitStringConcatManyLongs::s209 = 0;
int64_t ImplicitStringConcatManyLongs::s210 = 0;
int64_t ImplicitStringConcatManyLongs::s211 = 0;
int64_t ImplicitStringConcatManyLongs::s212 = 0;
int64_t ImplicitStringConcatManyLongs::s213 = 0;
int64_t ImplicitStringConcatManyLongs::s214 = 0;
int64_t ImplicitStringConcatManyLongs::s215 = 0;
int64_t ImplicitStringConcatManyLongs::s216 = 0;
int64_t ImplicitStringConcatManyLongs::s217 = 0;
int64_t ImplicitStringConcatManyLongs::s218 = 0;
int64_t ImplicitStringConcatManyLongs::s219 = 0;
int64_t ImplicitStringConcatManyLongs::s220 = 0;
int64_t ImplicitStringConcatManyLongs::s221 = 0;
int64_t ImplicitStringConcatManyLongs::s222 = 0;
int64_t ImplicitStringConcatManyLongs::s223 = 0;
int64_t ImplicitStringConcatManyLongs::s224 = 0;
int64_t ImplicitStringConcatManyLongs::s225 = 0;
int64_t ImplicitStringConcatManyLongs::s226 = 0;
int64_t ImplicitStringConcatManyLongs::s227 = 0;
int64_t ImplicitStringConcatManyLongs::s228 = 0;
int64_t ImplicitStringConcatManyLongs::s229 = 0;
int64_t ImplicitStringConcatManyLongs::s230 = 0;
int64_t ImplicitStringConcatManyLongs::s231 = 0;
int64_t ImplicitStringConcatManyLongs::s232 = 0;
int64_t ImplicitStringConcatManyLongs::s233 = 0;
int64_t ImplicitStringConcatManyLongs::s234 = 0;
int64_t ImplicitStringConcatManyLongs::s235 = 0;
int64_t ImplicitStringConcatManyLongs::s236 = 0;
int64_t ImplicitStringConcatManyLongs::s237 = 0;
int64_t ImplicitStringConcatManyLongs::s238 = 0;
int64_t ImplicitStringConcatManyLongs::s239 = 0;
int64_t ImplicitStringConcatManyLongs::s240 = 0;
int64_t ImplicitStringConcatManyLongs::s241 = 0;
int64_t ImplicitStringConcatManyLongs::s242 = 0;
int64_t ImplicitStringConcatManyLongs::s243 = 0;
int64_t ImplicitStringConcatManyLongs::s244 = 0;
int64_t ImplicitStringConcatManyLongs::s245 = 0;
int64_t ImplicitStringConcatManyLongs::s246 = 0;
int64_t ImplicitStringConcatManyLongs::s247 = 0;
int64_t ImplicitStringConcatManyLongs::s248 = 0;
int64_t ImplicitStringConcatManyLongs::s249 = 0;
int64_t ImplicitStringConcatManyLongs::s250 = 0;
int64_t ImplicitStringConcatManyLongs::s251 = 0;
int64_t ImplicitStringConcatManyLongs::s252 = 0;
int64_t ImplicitStringConcatManyLongs::s253 = 0;
int64_t ImplicitStringConcatManyLongs::s254 = 0;
int64_t ImplicitStringConcatManyLongs::s255 = 0;
int64_t ImplicitStringConcatManyLongs::s256 = 0;
int64_t ImplicitStringConcatManyLongs::s257 = 0;
int64_t ImplicitStringConcatManyLongs::s258 = 0;
int64_t ImplicitStringConcatManyLongs::s259 = 0;
int64_t ImplicitStringConcatManyLongs::s260 = 0;
int64_t ImplicitStringConcatManyLongs::s261 = 0;
int64_t ImplicitStringConcatManyLongs::s262 = 0;
int64_t ImplicitStringConcatManyLongs::s263 = 0;
int64_t ImplicitStringConcatManyLongs::s264 = 0;
int64_t ImplicitStringConcatManyLongs::s265 = 0;
int64_t ImplicitStringConcatManyLongs::s266 = 0;
int64_t ImplicitStringConcatManyLongs::s267 = 0;
int64_t ImplicitStringConcatManyLongs::s268 = 0;
int64_t ImplicitStringConcatManyLongs::s269 = 0;
int64_t ImplicitStringConcatManyLongs::s270 = 0;
int64_t ImplicitStringConcatManyLongs::s271 = 0;
int64_t ImplicitStringConcatManyLongs::s272 = 0;
int64_t ImplicitStringConcatManyLongs::s273 = 0;
int64_t ImplicitStringConcatManyLongs::s274 = 0;
int64_t ImplicitStringConcatManyLongs::s275 = 0;
int64_t ImplicitStringConcatManyLongs::s276 = 0;
int64_t ImplicitStringConcatManyLongs::s277 = 0;
int64_t ImplicitStringConcatManyLongs::s278 = 0;
int64_t ImplicitStringConcatManyLongs::s279 = 0;
int64_t ImplicitStringConcatManyLongs::s280 = 0;
int64_t ImplicitStringConcatManyLongs::s281 = 0;
int64_t ImplicitStringConcatManyLongs::s282 = 0;
int64_t ImplicitStringConcatManyLongs::s283 = 0;
int64_t ImplicitStringConcatManyLongs::s284 = 0;
int64_t ImplicitStringConcatManyLongs::s285 = 0;
int64_t ImplicitStringConcatManyLongs::s286 = 0;
int64_t ImplicitStringConcatManyLongs::s287 = 0;
int64_t ImplicitStringConcatManyLongs::s288 = 0;
int64_t ImplicitStringConcatManyLongs::s289 = 0;
int64_t ImplicitStringConcatManyLongs::s290 = 0;
int64_t ImplicitStringConcatManyLongs::s291 = 0;
int64_t ImplicitStringConcatManyLongs::s292 = 0;
int64_t ImplicitStringConcatManyLongs::s293 = 0;
int64_t ImplicitStringConcatManyLongs::s294 = 0;
int64_t ImplicitStringConcatManyLongs::s295 = 0;
int64_t ImplicitStringConcatManyLongs::s296 = 0;
int64_t ImplicitStringConcatManyLongs::s297 = 0;
int64_t ImplicitStringConcatManyLongs::s298 = 0;
int64_t ImplicitStringConcatManyLongs::s299 = 0;

void ImplicitStringConcatManyLongs::init$() {
}

void ImplicitStringConcatManyLongs::main($StringArray* args) {
	$init(ImplicitStringConcatManyLongs);
	$useLocalCurrentObjectStackCache();
	$var($String, res, $str({""_s, $$str(ImplicitStringConcatManyLongs::s000), $$str(ImplicitStringConcatManyLongs::s001), $$str(ImplicitStringConcatManyLongs::s002), $$str(ImplicitStringConcatManyLongs::s003), $$str(ImplicitStringConcatManyLongs::s004), $$str(ImplicitStringConcatManyLongs::s005), $$str(ImplicitStringConcatManyLongs::s006), $$str(ImplicitStringConcatManyLongs::s007), $$str(ImplicitStringConcatManyLongs::s008), $$str(ImplicitStringConcatManyLongs::s009), $$str(ImplicitStringConcatManyLongs::s010), $$str(ImplicitStringConcatManyLongs::s011), $$str(ImplicitStringConcatManyLongs::s012), $$str(ImplicitStringConcatManyLongs::s013), $$str(ImplicitStringConcatManyLongs::s014), 
	$$str(ImplicitStringConcatManyLongs::s015), $$str(ImplicitStringConcatManyLongs::s016), $$str(ImplicitStringConcatManyLongs::s017), $$str(ImplicitStringConcatManyLongs::s018), $$str(ImplicitStringConcatManyLongs::s019), $$str(ImplicitStringConcatManyLongs::s020), $$str(ImplicitStringConcatManyLongs::s021), $$str(ImplicitStringConcatManyLongs::s022), $$str(ImplicitStringConcatManyLongs::s023), $$str(ImplicitStringConcatManyLongs::s024), $$str(ImplicitStringConcatManyLongs::s025), $$str(ImplicitStringConcatManyLongs::s026), $$str(ImplicitStringConcatManyLongs::s027), $$str(ImplicitStringConcatManyLongs::s028), $$str(ImplicitStringConcatManyLongs::s029), $$str(ImplicitStringConcatManyLongs::s030), 
	$$str(ImplicitStringConcatManyLongs::s031), $$str(ImplicitStringConcatManyLongs::s032), $$str(ImplicitStringConcatManyLongs::s033), $$str(ImplicitStringConcatManyLongs::s034), $$str(ImplicitStringConcatManyLongs::s035), $$str(ImplicitStringConcatManyLongs::s036), $$str(ImplicitStringConcatManyLongs::s037), $$str(ImplicitStringConcatManyLongs::s038), $$str(ImplicitStringConcatManyLongs::s039), $$str(ImplicitStringConcatManyLongs::s040), $$str(ImplicitStringConcatManyLongs::s041), $$str(ImplicitStringConcatManyLongs::s042), $$str(ImplicitStringConcatManyLongs::s043), $$str(ImplicitStringConcatManyLongs::s044), $$str(ImplicitStringConcatManyLongs::s045), $$str(ImplicitStringConcatManyLongs::s046), 
	$$str(ImplicitStringConcatManyLongs::s047), $$str(ImplicitStringConcatManyLongs::s048), $$str(ImplicitStringConcatManyLongs::s049), $$str(ImplicitStringConcatManyLongs::s050), $$str(ImplicitStringConcatManyLongs::s051), $$str(ImplicitStringConcatManyLongs::s052), $$str(ImplicitStringConcatManyLongs::s053), $$str(ImplicitStringConcatManyLongs::s054), $$str(ImplicitStringConcatManyLongs::s055), $$str(ImplicitStringConcatManyLongs::s056), $$str(ImplicitStringConcatManyLongs::s057), $$str(ImplicitStringConcatManyLongs::s058), $$str(ImplicitStringConcatManyLongs::s059), $$str(ImplicitStringConcatManyLongs::s060), $$str(ImplicitStringConcatManyLongs::s061), $$str(ImplicitStringConcatManyLongs::s062), 
	$$str(ImplicitStringConcatManyLongs::s063), $$str(ImplicitStringConcatManyLongs::s064), $$str(ImplicitStringConcatManyLongs::s065), $$str(ImplicitStringConcatManyLongs::s066), $$str(ImplicitStringConcatManyLongs::s067), $$str(ImplicitStringConcatManyLongs::s068), $$str(ImplicitStringConcatManyLongs::s069), $$str(ImplicitStringConcatManyLongs::s070), $$str(ImplicitStringConcatManyLongs::s071), $$str(ImplicitStringConcatManyLongs::s072), $$str(ImplicitStringConcatManyLongs::s073), $$str(ImplicitStringConcatManyLongs::s074), $$str(ImplicitStringConcatManyLongs::s075), $$str(ImplicitStringConcatManyLongs::s076), $$str(ImplicitStringConcatManyLongs::s077), $$str(ImplicitStringConcatManyLongs::s078), 
	$$str(ImplicitStringConcatManyLongs::s079), $$str(ImplicitStringConcatManyLongs::s080), $$str(ImplicitStringConcatManyLongs::s081), $$str(ImplicitStringConcatManyLongs::s082), $$str(ImplicitStringConcatManyLongs::s083), $$str(ImplicitStringConcatManyLongs::s084), $$str(ImplicitStringConcatManyLongs::s085), $$str(ImplicitStringConcatManyLongs::s086), $$str(ImplicitStringConcatManyLongs::s087), $$str(ImplicitStringConcatManyLongs::s088), $$str(ImplicitStringConcatManyLongs::s089), $$str(ImplicitStringConcatManyLongs::s090), $$str(ImplicitStringConcatManyLongs::s091), $$str(ImplicitStringConcatManyLongs::s092), $$str(ImplicitStringConcatManyLongs::s093), $$str(ImplicitStringConcatManyLongs::s094), 
	$$str(ImplicitStringConcatManyLongs::s095), $$str(ImplicitStringConcatManyLongs::s096), $$str(ImplicitStringConcatManyLongs::s097), $$str(ImplicitStringConcatManyLongs::s098), $$str(ImplicitStringConcatManyLongs::s099), $$str(ImplicitStringConcatManyLongs::s100), $$str(ImplicitStringConcatManyLongs::s101), $$str(ImplicitStringConcatManyLongs::s102), $$str(ImplicitStringConcatManyLongs::s103), $$str(ImplicitStringConcatManyLongs::s104), $$str(ImplicitStringConcatManyLongs::s105), $$str(ImplicitStringConcatManyLongs::s106), $$str(ImplicitStringConcatManyLongs::s107), $$str(ImplicitStringConcatManyLongs::s108), $$str(ImplicitStringConcatManyLongs::s109), $$str(ImplicitStringConcatManyLongs::s110), 
	$$str(ImplicitStringConcatManyLongs::s111), $$str(ImplicitStringConcatManyLongs::s112), $$str(ImplicitStringConcatManyLongs::s113), $$str(ImplicitStringConcatManyLongs::s114), $$str(ImplicitStringConcatManyLongs::s115), $$str(ImplicitStringConcatManyLongs::s116), $$str(ImplicitStringConcatManyLongs::s117), $$str(ImplicitStringConcatManyLongs::s118), $$str(ImplicitStringConcatManyLongs::s119), $$str(ImplicitStringConcatManyLongs::s120), $$str(ImplicitStringConcatManyLongs::s121), $$str(ImplicitStringConcatManyLongs::s122), $$str(ImplicitStringConcatManyLongs::s123), $$str(ImplicitStringConcatManyLongs::s124), $$str(ImplicitStringConcatManyLongs::s125), $$str(ImplicitStringConcatManyLongs::s126), 
	$$str(ImplicitStringConcatManyLongs::s127), $$str(ImplicitStringConcatManyLongs::s128), $$str(ImplicitStringConcatManyLongs::s129), $$str(ImplicitStringConcatManyLongs::s130), $$str(ImplicitStringConcatManyLongs::s131), $$str(ImplicitStringConcatManyLongs::s132), $$str(ImplicitStringConcatManyLongs::s133), $$str(ImplicitStringConcatManyLongs::s134), $$str(ImplicitStringConcatManyLongs::s135), $$str(ImplicitStringConcatManyLongs::s136), $$str(ImplicitStringConcatManyLongs::s137), $$str(ImplicitStringConcatManyLongs::s138), $$str(ImplicitStringConcatManyLongs::s139), $$str(ImplicitStringConcatManyLongs::s140), $$str(ImplicitStringConcatManyLongs::s141), $$str(ImplicitStringConcatManyLongs::s142), 
	$$str(ImplicitStringConcatManyLongs::s143), $$str(ImplicitStringConcatManyLongs::s144), $$str(ImplicitStringConcatManyLongs::s145), $$str(ImplicitStringConcatManyLongs::s146), $$str(ImplicitStringConcatManyLongs::s147), $$str(ImplicitStringConcatManyLongs::s148), $$str(ImplicitStringConcatManyLongs::s149), $$str(ImplicitStringConcatManyLongs::s150), $$str(ImplicitStringConcatManyLongs::s151), $$str(ImplicitStringConcatManyLongs::s152), $$str(ImplicitStringConcatManyLongs::s153), $$str(ImplicitStringConcatManyLongs::s154), $$str(ImplicitStringConcatManyLongs::s155), $$str(ImplicitStringConcatManyLongs::s156), $$str(ImplicitStringConcatManyLongs::s157), $$str(ImplicitStringConcatManyLongs::s158), 
	$$str(ImplicitStringConcatManyLongs::s159), $$str(ImplicitStringConcatManyLongs::s160), $$str(ImplicitStringConcatManyLongs::s161), $$str(ImplicitStringConcatManyLongs::s162), $$str(ImplicitStringConcatManyLongs::s163), $$str(ImplicitStringConcatManyLongs::s164), $$str(ImplicitStringConcatManyLongs::s165), $$str(ImplicitStringConcatManyLongs::s166), $$str(ImplicitStringConcatManyLongs::s167), $$str(ImplicitStringConcatManyLongs::s168), $$str(ImplicitStringConcatManyLongs::s169), $$str(ImplicitStringConcatManyLongs::s170), $$str(ImplicitStringConcatManyLongs::s171), $$str(ImplicitStringConcatManyLongs::s172), $$str(ImplicitStringConcatManyLongs::s173), $$str(ImplicitStringConcatManyLongs::s174), 
	$$str(ImplicitStringConcatManyLongs::s175), $$str(ImplicitStringConcatManyLongs::s176), $$str(ImplicitStringConcatManyLongs::s177), $$str(ImplicitStringConcatManyLongs::s178), $$str(ImplicitStringConcatManyLongs::s179), $$str(ImplicitStringConcatManyLongs::s180), $$str(ImplicitStringConcatManyLongs::s181), $$str(ImplicitStringConcatManyLongs::s182), $$str(ImplicitStringConcatManyLongs::s183), $$str(ImplicitStringConcatManyLongs::s184), $$str(ImplicitStringConcatManyLongs::s185), $$str(ImplicitStringConcatManyLongs::s186), $$str(ImplicitStringConcatManyLongs::s187), $$str(ImplicitStringConcatManyLongs::s188), $$str(ImplicitStringConcatManyLongs::s189), $$str(ImplicitStringConcatManyLongs::s190), 
	$$str(ImplicitStringConcatManyLongs::s191), $$str(ImplicitStringConcatManyLongs::s192), $$str(ImplicitStringConcatManyLongs::s193), $$str(ImplicitStringConcatManyLongs::s194), $$str(ImplicitStringConcatManyLongs::s195), $$str(ImplicitStringConcatManyLongs::s196), $$str(ImplicitStringConcatManyLongs::s197), $$str(ImplicitStringConcatManyLongs::s198), $$str(ImplicitStringConcatManyLongs::s199), $$str(ImplicitStringConcatManyLongs::s200), $$str(ImplicitStringConcatManyLongs::s201), $$str(ImplicitStringConcatManyLongs::s202), $$str(ImplicitStringConcatManyLongs::s203), $$str(ImplicitStringConcatManyLongs::s204), $$str(ImplicitStringConcatManyLongs::s205), $$str(ImplicitStringConcatManyLongs::s206), 
	$$str(ImplicitStringConcatManyLongs::s207), $$str(ImplicitStringConcatManyLongs::s208), $$str(ImplicitStringConcatManyLongs::s209), $$str(ImplicitStringConcatManyLongs::s210), $$str(ImplicitStringConcatManyLongs::s211), $$str(ImplicitStringConcatManyLongs::s212), $$str(ImplicitStringConcatManyLongs::s213), $$str(ImplicitStringConcatManyLongs::s214), $$str(ImplicitStringConcatManyLongs::s215), $$str(ImplicitStringConcatManyLongs::s216), $$str(ImplicitStringConcatManyLongs::s217), $$str(ImplicitStringConcatManyLongs::s218), $$str(ImplicitStringConcatManyLongs::s219), $$str(ImplicitStringConcatManyLongs::s220), $$str(ImplicitStringConcatManyLongs::s221), $$str(ImplicitStringConcatManyLongs::s222), 
	$$str(ImplicitStringConcatManyLongs::s223), $$str(ImplicitStringConcatManyLongs::s224), $$str(ImplicitStringConcatManyLongs::s225), $$str(ImplicitStringConcatManyLongs::s226), $$str(ImplicitStringConcatManyLongs::s227), $$str(ImplicitStringConcatManyLongs::s228), $$str(ImplicitStringConcatManyLongs::s229), $$str(ImplicitStringConcatManyLongs::s230), $$str(ImplicitStringConcatManyLongs::s231), $$str(ImplicitStringConcatManyLongs::s232), $$str(ImplicitStringConcatManyLongs::s233), $$str(ImplicitStringConcatManyLongs::s234), $$str(ImplicitStringConcatManyLongs::s235), $$str(ImplicitStringConcatManyLongs::s236), $$str(ImplicitStringConcatManyLongs::s237), $$str(ImplicitStringConcatManyLongs::s238), 
	$$str(ImplicitStringConcatManyLongs::s239), $$str(ImplicitStringConcatManyLongs::s240), $$str(ImplicitStringConcatManyLongs::s241), $$str(ImplicitStringConcatManyLongs::s242), $$str(ImplicitStringConcatManyLongs::s243), $$str(ImplicitStringConcatManyLongs::s244), $$str(ImplicitStringConcatManyLongs::s245), $$str(ImplicitStringConcatManyLongs::s246), $$str(ImplicitStringConcatManyLongs::s247), $$str(ImplicitStringConcatManyLongs::s248), $$str(ImplicitStringConcatManyLongs::s249), $$str(ImplicitStringConcatManyLongs::s250), $$str(ImplicitStringConcatManyLongs::s251), $$str(ImplicitStringConcatManyLongs::s252), $$str(ImplicitStringConcatManyLongs::s253), $$str(ImplicitStringConcatManyLongs::s254), 
	$$str(ImplicitStringConcatManyLongs::s255), $$str(ImplicitStringConcatManyLongs::s256), $$str(ImplicitStringConcatManyLongs::s257), $$str(ImplicitStringConcatManyLongs::s258), $$str(ImplicitStringConcatManyLongs::s259), $$str(ImplicitStringConcatManyLongs::s260), $$str(ImplicitStringConcatManyLongs::s261), $$str(ImplicitStringConcatManyLongs::s262), $$str(ImplicitStringConcatManyLongs::s263), $$str(ImplicitStringConcatManyLongs::s264), $$str(ImplicitStringConcatManyLongs::s265), $$str(ImplicitStringConcatManyLongs::s266), $$str(ImplicitStringConcatManyLongs::s267), $$str(ImplicitStringConcatManyLongs::s268), $$str(ImplicitStringConcatManyLongs::s269), $$str(ImplicitStringConcatManyLongs::s270), 
	$$str(ImplicitStringConcatManyLongs::s271), $$str(ImplicitStringConcatManyLongs::s272), $$str(ImplicitStringConcatManyLongs::s273), $$str(ImplicitStringConcatManyLongs::s274), $$str(ImplicitStringConcatManyLongs::s275), $$str(ImplicitStringConcatManyLongs::s276), $$str(ImplicitStringConcatManyLongs::s277), $$str(ImplicitStringConcatManyLongs::s278), $$str(ImplicitStringConcatManyLongs::s279), $$str(ImplicitStringConcatManyLongs::s280), $$str(ImplicitStringConcatManyLongs::s281), $$str(ImplicitStringConcatManyLongs::s282), $$str(ImplicitStringConcatManyLongs::s283), $$str(ImplicitStringConcatManyLongs::s284), $$str(ImplicitStringConcatManyLongs::s285), $$str(ImplicitStringConcatManyLongs::s286), 
	$$str(ImplicitStringConcatManyLongs::s287), $$str(ImplicitStringConcatManyLongs::s288), $$str(ImplicitStringConcatManyLongs::s289), $$str(ImplicitStringConcatManyLongs::s290), $$str(ImplicitStringConcatManyLongs::s291), $$str(ImplicitStringConcatManyLongs::s292), $$str(ImplicitStringConcatManyLongs::s293), $$str(ImplicitStringConcatManyLongs::s294), $$str(ImplicitStringConcatManyLongs::s295), $$str(ImplicitStringConcatManyLongs::s296), $$str(ImplicitStringConcatManyLongs::s297), $$str(ImplicitStringConcatManyLongs::s298), $$str(ImplicitStringConcatManyLongs::s299)}));
	$var($StringBuilder, sb, $new($StringBuilder));
	for (int32_t c = 0; c < 300; ++c) {
		sb->append(c);
	}
	test($(sb->toString()), res);
}

void ImplicitStringConcatManyLongs::test($String* expected, $String* actual) {
	$init(ImplicitStringConcatManyLongs);
	if (!$nc(expected)->equals(actual)) {
		$throwNew($IllegalStateException, $$str({"Expected = "_s, expected, ", actual = "_s, actual}));
	}
}

void clinit$ImplicitStringConcatManyLongs($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	{
		{
			$var($FieldArray, arr$, ImplicitStringConcatManyLongs::class$->getDeclaredFields());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Field, f, arr$->get(i$));
				{
					if ($Modifier::isStatic($nc(f)->getModifiers())) {
						$var($String, name, $nc(f)->getName());
						try {
							f->set(nullptr, $($Long::valueOf($($nc(name)->substring(1)))));
						} catch ($IllegalAccessException& e) {
							$throwNew($IllegalStateException, static_cast<$Throwable*>(e));
						}
					}
				}
			}
		}
	}
}

ImplicitStringConcatManyLongs::ImplicitStringConcatManyLongs() {
}

$Class* ImplicitStringConcatManyLongs::load$($String* name, bool initialize) {
	$loadClass(ImplicitStringConcatManyLongs, name, initialize, &_ImplicitStringConcatManyLongs_ClassInfo_, clinit$ImplicitStringConcatManyLongs, allocate$ImplicitStringConcatManyLongs);
	return class$;
}

$Class* ImplicitStringConcatManyLongs::class$ = nullptr;
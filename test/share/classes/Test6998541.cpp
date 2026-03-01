#include <Test6998541.h>

#include <java/lang/AssertionError.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/Math.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodHandles.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/invoke/TypeDescriptor$OfField.h>
#include <java/lang/invoke/WrongMethodTypeException.h>
#include <jcpp.h>

#undef BITS
#undef CLASS
#undef D
#undef DO_CASTS
#undef KIND
#undef MAX_VALUE
#undef MIN_VALUE
#undef N
#undef NAME
#undef NUMERIC_TYPE_WIDENING_ORDER
#undef TYPE

using $PrintStream = ::java::io::PrintStream;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassCastException = ::java::lang::ClassCastException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Short = ::java::lang::Short;
using $Void = ::java::lang::Void;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles = ::java::lang::invoke::MethodHandles;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $WrongMethodTypeException = ::java::lang::invoke::WrongMethodTypeException;

$FieldInfo _Test6998541_FieldInfo_[] = {
	{"CLASS", "Ljava/lang/Class;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, CLASS)},
	{"NAME", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, NAME)},
	{"N", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, N)},
	{"KIND", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, KIND)},
	{"BITS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Test6998541, BITS)},
	{"DO_CASTS", "Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, DO_CASTS)},
	{"lookup", "Ljava/lang/invoke/MethodHandles$Lookup;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, lookup)},
	{"NUMERIC_TYPE_WIDENING_ORDER", "[Ljava/lang/Class;", "[Ljava/lang/Class<*>;", $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, NUMERIC_TYPE_WIDENING_ORDER)},
	{"mh_zz", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_zz)},
	{"mh_bz", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_bz)},
	{"mh_cz", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_cz)},
	{"mh_sz", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_sz)},
	{"mh_iz", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_iz)},
	{"mh_jz", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_jz)},
	{"mh_fz", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_fz)},
	{"mh_dz", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_dz)},
	{"mh_zb", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_zb)},
	{"mh_bb", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_bb)},
	{"mh_cb", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_cb)},
	{"mh_sb", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_sb)},
	{"mh_ib", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_ib)},
	{"mh_jb", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_jb)},
	{"mh_fb", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_fb)},
	{"mh_db", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_db)},
	{"mh_zc", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_zc)},
	{"mh_bc", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_bc)},
	{"mh_cc", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_cc)},
	{"mh_sc", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_sc)},
	{"mh_ic", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_ic)},
	{"mh_jc", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_jc)},
	{"mh_fc", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_fc)},
	{"mh_dc", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_dc)},
	{"mh_zs", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_zs)},
	{"mh_bs", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_bs)},
	{"mh_cs", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_cs)},
	{"mh_ss", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_ss)},
	{"mh_is", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_is)},
	{"mh_js", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_js)},
	{"mh_fs", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_fs)},
	{"mh_ds", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_ds)},
	{"mh_zi", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_zi)},
	{"mh_bi", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_bi)},
	{"mh_ci", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_ci)},
	{"mh_si", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_si)},
	{"mh_ii", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_ii)},
	{"mh_ji", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_ji)},
	{"mh_fi", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_fi)},
	{"mh_di", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_di)},
	{"mh_zj", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_zj)},
	{"mh_bj", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_bj)},
	{"mh_cj", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_cj)},
	{"mh_sj", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_sj)},
	{"mh_ij", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_ij)},
	{"mh_jj", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_jj)},
	{"mh_fj", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_fj)},
	{"mh_dj", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_dj)},
	{"mh_zf", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_zf)},
	{"mh_bf", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_bf)},
	{"mh_cf", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_cf)},
	{"mh_sf", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_sf)},
	{"mh_if", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_if)},
	{"mh_jf", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_jf)},
	{"mh_ff", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_ff)},
	{"mh_df", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_df)},
	{"mh_zd", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_zd)},
	{"mh_bd", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_bd)},
	{"mh_cd", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_cd)},
	{"mh_sd", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_sd)},
	{"mh_id", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_id)},
	{"mh_jd", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_jd)},
	{"mh_fd", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_fd)},
	{"mh_dd", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_dd)},
	{"mh_zv", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_zv)},
	{"mh_bv", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_bv)},
	{"mh_cv", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_cv)},
	{"mh_sv", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_sv)},
	{"mh_iv", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_iv)},
	{"mh_jv", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_jv)},
	{"mh_fv", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_fv)},
	{"mh_dv", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_dv)},
	{"mh_vz", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_vz)},
	{"mh_vb", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_vb)},
	{"mh_vc", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_vc)},
	{"mh_vs", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_vs)},
	{"mh_vi", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_vi)},
	{"mh_vj", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_vj)},
	{"mh_vf", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_vf)},
	{"mh_vd", "Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Test6998541, mh_vd)},
	{}
};

$MethodInfo _Test6998541_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Test6998541, init$, void)},
	{"assertEquals", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, assertEquals, void, Object$*, Object$*)},
	{"boolean2prim", "(Z)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, boolean2prim, void, bool), "java.lang.Throwable"},
	{"boolean2prim_invalid", "(Z)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, boolean2prim_invalid, void, bool), "java.lang.Throwable"},
	{"byte2prim", "(B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, byte2prim, void, int8_t), "java.lang.Throwable"},
	{"byte2prim_invalid", "(B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, byte2prim_invalid, void, int8_t), "java.lang.Throwable"},
	{"canDoAsType", "(Ljava/lang/Class;Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;Ljava/lang/Class<*>;)Z", $PRIVATE | $STATIC, $staticMethod(Test6998541, canDoAsType, bool, $Class*, $Class*)},
	{"canDoAsType", "(Ljava/lang/invoke/MethodType;Ljava/lang/invoke/MethodType;)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, canDoAsType, bool, $MethodType*, $MethodType*)},
	{"char2prim", "(C)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, char2prim, void, char16_t), "java.lang.Throwable"},
	{"char2prim_invalid", "(C)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, char2prim_invalid, void, char16_t), "java.lang.Throwable"},
	{"doboolean", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, doboolean, void), "java.lang.Throwable"},
	{"dobyte", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, dobyte, void), "java.lang.Throwable"},
	{"dochar", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, dochar, void), "java.lang.Throwable"},
	{"dodouble", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, dodouble, void), "java.lang.Throwable"},
	{"dofloat", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, dofloat, void), "java.lang.Throwable"},
	{"doint", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, doint, void), "java.lang.Throwable"},
	{"dolong", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, dolong, void), "java.lang.Throwable"},
	{"doshort", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, doshort, void), "java.lang.Throwable"},
	{"double2prim", "(D)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, double2prim, void, double), "java.lang.Throwable"},
	{"double2prim_invalid", "(D)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, double2prim_invalid, void, double), "java.lang.Throwable"},
	{"dovoid", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, dovoid, void), "java.lang.Throwable"},
	{"fail", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, fail, void)},
	{"float2prim", "(F)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, float2prim, void, float), "java.lang.Throwable"},
	{"float2prim_invalid", "(F)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, float2prim_invalid, void, float), "java.lang.Throwable"},
	{"identity", "(Z)Z", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, identity, bool, bool)},
	{"identity", "(B)B", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, identity, int8_t, int8_t)},
	{"identity", "(C)C", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, identity, char16_t, char16_t)},
	{"identity", "(S)S", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, identity, int16_t, int16_t)},
	{"identity", "(I)I", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, identity, int32_t, int32_t)},
	{"identity", "(J)J", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, identity, int64_t, int64_t)},
	{"identity", "(F)F", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, identity, float, float)},
	{"identity", "(D)D", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, identity, double, double)},
	{"identity", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, identity, void)},
	{"int2prim", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, int2prim, void, int32_t), "java.lang.Throwable"},
	{"int2prim_invalid", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, int2prim_invalid, void, int32_t), "java.lang.Throwable"},
	{"long2prim", "(J)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, long2prim, void, int64_t), "java.lang.Throwable"},
	{"long2prim_invalid", "(J)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, long2prim_invalid, void, int64_t), "java.lang.Throwable"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Test6998541, main, void, $StringArray*), "java.lang.Throwable"},
	{"mh", "(Ljava/lang/Class;[Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(Test6998541, mh, $MethodHandle*, $Class*, $ClassArray*)},
	{"mh_b", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, mh_b, $MethodHandle*, $Class*)},
	{"mh_c", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, mh_c, $MethodHandle*, $Class*)},
	{"mh_d", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, mh_d, $MethodHandle*, $Class*)},
	{"mh_f", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, mh_f, $MethodHandle*, $Class*)},
	{"mh_i", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, mh_i, $MethodHandle*, $Class*)},
	{"mh_j", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, mh_j, $MethodHandle*, $Class*)},
	{"mh_s", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, mh_s, $MethodHandle*, $Class*)},
	{"mh_v", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, mh_v, $MethodHandle*, $Class*)},
	{"mh_z", "(Ljava/lang/Class;)Ljava/lang/invoke/MethodHandle;", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, mh_z, $MethodHandle*, $Class*)},
	{"prim2void", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, prim2void, void, int32_t), "java.lang.Throwable"},
	{"prim2void_invalid", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, prim2void_invalid, void, int32_t), "java.lang.Throwable"},
	{"short2prim", "(S)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, short2prim, void, int16_t), "java.lang.Throwable"},
	{"short2prim_invalid", "(S)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, short2prim_invalid, void, int16_t), "java.lang.Throwable"},
	{"void2prim", "(I)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, void2prim, void, int32_t), "java.lang.Throwable"},
	{"void2prim_invalid", "(D)V", nullptr, $PRIVATE | $STATIC, $staticMethod(Test6998541, void2prim_invalid, void, double), "java.lang.Throwable"},
	{}
};

$ClassInfo _Test6998541_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Test6998541",
	"java.lang.Object",
	nullptr,
	_Test6998541_FieldInfo_,
	_Test6998541_MethodInfo_
};

$Object* allocate$Test6998541($Class* clazz) {
	return $of($alloc(Test6998541));
}

$Class* Test6998541::CLASS = nullptr;
$String* Test6998541::NAME = nullptr;
int32_t Test6998541::N = 0;
$String* Test6998541::KIND = nullptr;
bool Test6998541::DO_CASTS = false;
$MethodHandles$Lookup* Test6998541::lookup = nullptr;
$ClassArray* Test6998541::NUMERIC_TYPE_WIDENING_ORDER = nullptr;
$MethodHandle* Test6998541::mh_zz = nullptr;
$MethodHandle* Test6998541::mh_bz = nullptr;
$MethodHandle* Test6998541::mh_cz = nullptr;
$MethodHandle* Test6998541::mh_sz = nullptr;
$MethodHandle* Test6998541::mh_iz = nullptr;
$MethodHandle* Test6998541::mh_jz = nullptr;
$MethodHandle* Test6998541::mh_fz = nullptr;
$MethodHandle* Test6998541::mh_dz = nullptr;
$MethodHandle* Test6998541::mh_zb = nullptr;
$MethodHandle* Test6998541::mh_bb = nullptr;
$MethodHandle* Test6998541::mh_cb = nullptr;
$MethodHandle* Test6998541::mh_sb = nullptr;
$MethodHandle* Test6998541::mh_ib = nullptr;
$MethodHandle* Test6998541::mh_jb = nullptr;
$MethodHandle* Test6998541::mh_fb = nullptr;
$MethodHandle* Test6998541::mh_db = nullptr;
$MethodHandle* Test6998541::mh_zc = nullptr;
$MethodHandle* Test6998541::mh_bc = nullptr;
$MethodHandle* Test6998541::mh_cc = nullptr;
$MethodHandle* Test6998541::mh_sc = nullptr;
$MethodHandle* Test6998541::mh_ic = nullptr;
$MethodHandle* Test6998541::mh_jc = nullptr;
$MethodHandle* Test6998541::mh_fc = nullptr;
$MethodHandle* Test6998541::mh_dc = nullptr;
$MethodHandle* Test6998541::mh_zs = nullptr;
$MethodHandle* Test6998541::mh_bs = nullptr;
$MethodHandle* Test6998541::mh_cs = nullptr;
$MethodHandle* Test6998541::mh_ss = nullptr;
$MethodHandle* Test6998541::mh_is = nullptr;
$MethodHandle* Test6998541::mh_js = nullptr;
$MethodHandle* Test6998541::mh_fs = nullptr;
$MethodHandle* Test6998541::mh_ds = nullptr;
$MethodHandle* Test6998541::mh_zi = nullptr;
$MethodHandle* Test6998541::mh_bi = nullptr;
$MethodHandle* Test6998541::mh_ci = nullptr;
$MethodHandle* Test6998541::mh_si = nullptr;
$MethodHandle* Test6998541::mh_ii = nullptr;
$MethodHandle* Test6998541::mh_ji = nullptr;
$MethodHandle* Test6998541::mh_fi = nullptr;
$MethodHandle* Test6998541::mh_di = nullptr;
$MethodHandle* Test6998541::mh_zj = nullptr;
$MethodHandle* Test6998541::mh_bj = nullptr;
$MethodHandle* Test6998541::mh_cj = nullptr;
$MethodHandle* Test6998541::mh_sj = nullptr;
$MethodHandle* Test6998541::mh_ij = nullptr;
$MethodHandle* Test6998541::mh_jj = nullptr;
$MethodHandle* Test6998541::mh_fj = nullptr;
$MethodHandle* Test6998541::mh_dj = nullptr;
$MethodHandle* Test6998541::mh_zf = nullptr;
$MethodHandle* Test6998541::mh_bf = nullptr;
$MethodHandle* Test6998541::mh_cf = nullptr;
$MethodHandle* Test6998541::mh_sf = nullptr;
$MethodHandle* Test6998541::mh_if = nullptr;
$MethodHandle* Test6998541::mh_jf = nullptr;
$MethodHandle* Test6998541::mh_ff = nullptr;
$MethodHandle* Test6998541::mh_df = nullptr;
$MethodHandle* Test6998541::mh_zd = nullptr;
$MethodHandle* Test6998541::mh_bd = nullptr;
$MethodHandle* Test6998541::mh_cd = nullptr;
$MethodHandle* Test6998541::mh_sd = nullptr;
$MethodHandle* Test6998541::mh_id = nullptr;
$MethodHandle* Test6998541::mh_jd = nullptr;
$MethodHandle* Test6998541::mh_fd = nullptr;
$MethodHandle* Test6998541::mh_dd = nullptr;
$MethodHandle* Test6998541::mh_zv = nullptr;
$MethodHandle* Test6998541::mh_bv = nullptr;
$MethodHandle* Test6998541::mh_cv = nullptr;
$MethodHandle* Test6998541::mh_sv = nullptr;
$MethodHandle* Test6998541::mh_iv = nullptr;
$MethodHandle* Test6998541::mh_jv = nullptr;
$MethodHandle* Test6998541::mh_fv = nullptr;
$MethodHandle* Test6998541::mh_dv = nullptr;
$MethodHandle* Test6998541::mh_vz = nullptr;
$MethodHandle* Test6998541::mh_vb = nullptr;
$MethodHandle* Test6998541::mh_vc = nullptr;
$MethodHandle* Test6998541::mh_vs = nullptr;
$MethodHandle* Test6998541::mh_vi = nullptr;
$MethodHandle* Test6998541::mh_vj = nullptr;
$MethodHandle* Test6998541::mh_vf = nullptr;
$MethodHandle* Test6998541::mh_vd = nullptr;

void Test6998541::init$() {
}

void Test6998541::main($StringArray* args) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({"KIND="_s, Test6998541::KIND, " DO_CASTS="_s, $$str(Test6998541::DO_CASTS), " N="_s, $$str(Test6998541::N)}));
	doboolean();
	dobyte();
	dochar();
	doshort();
	doint();
	dolong();
	dofloat();
	dodouble();
	dovoid();
}

void Test6998541::doboolean() {
	$init(Test6998541);
	for (int32_t i = 0; i < Test6998541::N; ++i) {
		boolean2prim(false);
		boolean2prim(true);
	}
	boolean2prim_invalid(true);
}

void Test6998541::dobyte() {
	$init(Test6998541);
	int8_t x = $Byte::MIN_VALUE;
	for (int32_t i = 0; i < Test6998541::N; ++i, ++x) {
		byte2prim(x);
	}
	byte2prim_invalid(x);
}

void Test6998541::dochar() {
	$init(Test6998541);
	char16_t x = $Character::MIN_VALUE;
	for (int32_t i = 0; i < Test6998541::N; ++i, ++x) {
		char2prim(x);
	}
	char2prim_invalid(x);
}

void Test6998541::doshort() {
	$init(Test6998541);
	int16_t x = $Short::MIN_VALUE;
	for (int32_t i = 0; i < Test6998541::N; ++i, ++x) {
		short2prim(x);
	}
	short2prim_invalid(x);
}

void Test6998541::doint() {
	$init(Test6998541);
	int32_t x = $Integer::MIN_VALUE;
	int32_t D = ($div($Integer::MAX_VALUE, (Test6998541::N / 2))) | Test6998541::BITS;
	for (int32_t i = 0; i < Test6998541::N; ++i, x += D) {
		int2prim(x);
	}
	int2prim_invalid(x);
}

void Test6998541::dolong() {
	$init(Test6998541);
	int64_t x = $Long::MIN_VALUE;
	int64_t D = ($div($Long::MAX_VALUE, ((int64_t)(Test6998541::N / 2)))) | Test6998541::BITS;
	for (int32_t i = 0; i < Test6998541::N; ++i, x += D) {
		long2prim(x);
	}
	long2prim_invalid(x);
}

void Test6998541::dofloat() {
	$init(Test6998541);
	$init($Float);
	float x = $Float::MIN_VALUE;
	float D = $Float::MAX_VALUE / ((float)(Test6998541::N / 2));
	for (int32_t i = 0; i < Test6998541::N; ++i, x += D) {
		float2prim(x);
	}
	float2prim_invalid(x);
}

void Test6998541::dodouble() {
	$init(Test6998541);
	$init($Double);
	double x = $Double::MIN_VALUE;
	double D = $Double::MAX_VALUE / ((double)(Test6998541::N / 2));
	for (int32_t i = 0; i < Test6998541::N; ++i, x += D) {
		double2prim(x);
	}
	double2prim_invalid(x);
}

void Test6998541::dovoid() {
	$init(Test6998541);
	for (int32_t i = 0; i < Test6998541::N; ++i) {
		void2prim(i);
	}
	void2prim_invalid((double)0);
	for (int32_t i = 0; i < Test6998541::N; ++i) {
		prim2void(i);
	}
	prim2void_invalid(0);
}

void Test6998541::assertEquals(Object$* o, Object$* o2) {
	$init(Test6998541);
	if (!$nc($of(o))->equals(o2)) {
		$throwNew($AssertionError, $of($$str({"expected: "_s, o, ", found: "_s, o2})));
	}
}

void Test6998541::fail() {
	$init(Test6998541);
	$throwNew($AssertionError);
}

$MethodHandle* Test6998541::mh($Class* ret, $ClassArray* args) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	try {
		$var($MethodType, mt, $MethodType::methodType(ret, args));
		$init($Void);
		$Class* lookupRet = ($nc(args)->length == 0 ? $Void::TYPE : $nc(args)->get(0));
		$var($MethodHandle, mh, $nc(Test6998541::lookup)->findStatic(Test6998541::CLASS, Test6998541::NAME, $($nc(mt)->changeReturnType(lookupRet))));
		if (Test6998541::DO_CASTS) {
			return $MethodHandles::explicitCastArguments(mh, mt);
		}
		if (canDoAsType($($nc(mh)->type()), mt)) {
			return $nc(mh)->asType(mt);
		}
		try {
			$nc(mh)->asType(mt);
			$throwNew($AssertionError, $of($$str({"asType should not succeed: "_s, mh, " => "_s, mt})));
		} catch ($WrongMethodTypeException& ex) {
			return $nc($($nc(mh)->asType($($nc(mt)->generic()))))->asType(mt);
		}
	} catch ($ReflectiveOperationException& e) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

bool Test6998541::canDoAsType($Class* src, $Class* dst) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	if (src == dst) {
		return true;
	}
	$init($Void);
	if (dst == $Void::TYPE) {
		return true;
	}
	if (src == $Void::TYPE) {
		return true;
	}
	bool var$0 = !$nc(src)->isPrimitive();
	if (var$0 || !$nc(dst)->isPrimitive()) {
		return true;
	}
	$init($Boolean);
	if (src == $Boolean::TYPE || dst == $Boolean::TYPE) {
		return false;
	}
	$init($Character);
	if (dst == $Character::TYPE) {
		return false;
	}
	if (src == $Character::TYPE) {
		$init($Integer);
		src = $Integer::TYPE;
	}
	{
		$var($ClassArray, arr$, Test6998541::NUMERIC_TYPE_WIDENING_ORDER);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$Class* ntype = arr$->get(i$);
			{
				if (src == ntype) {
					return true;
				}
				if (dst == ntype) {
					return false;
				}
			}
		}
	}
	$throwNew($AssertionError, $of($$str({"should not reach here: "_s, src, ", "_s, dst})));
}

bool Test6998541::canDoAsType($MethodType* mt0, $MethodType* mt1) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$Class* rt0 = $cast($Class, $nc(mt0)->returnType());
	$Class* rt1 = $cast($Class, $nc(mt1)->returnType());
	if (!canDoAsType(rt0, rt1)) {
		return false;
	}
	int32_t argc = mt0->parameterCount();
	if (argc != mt1->parameterCount()) {
		return false;
	}
	for (int32_t i = 0; i < argc; ++i) {
		$Class* var$0 = $cast($Class, mt1->parameterType(i));
		if (!canDoAsType(var$0, $($cast($Class, mt0->parameterType(i))))) {
			return false;
		}
	}
	return true;
}

$MethodHandle* Test6998541::mh_z($Class* ret) {
	$init(Test6998541);
	$init($Boolean);
	return mh(ret, $$new($ClassArray, {$Boolean::TYPE}));
}

void Test6998541::boolean2prim(bool x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	int32_t i = x ? 1 : 0;
	$var($Object, var$0, $of($Boolean::valueOf(x)));
	assertEquals(var$0, $($Boolean::valueOf($booleanValue($nc(Test6998541::mh_zz)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	if (!Test6998541::DO_CASTS) {
		return;
	}
	$var($Object, var$1, $of($Byte::valueOf((int8_t)i)));
	assertEquals(var$1, $($Byte::valueOf($byteValue($nc(Test6998541::mh_bz)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$2, $of($Character::valueOf((char16_t)i)));
	assertEquals(var$2, $($Character::valueOf($charValue($nc(Test6998541::mh_cz)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$3, $of($Short::valueOf((int16_t)i)));
	assertEquals(var$3, $($Short::valueOf($shortValue($nc(Test6998541::mh_sz)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$4, $of($Integer::valueOf(i)));
	assertEquals(var$4, $($Integer::valueOf($intValue($nc(Test6998541::mh_iz)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$5, $of($Long::valueOf((int64_t)i)));
	assertEquals(var$5, $($Long::valueOf($longValue($nc(Test6998541::mh_jz)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$6, $of($Float::valueOf((float)i)));
	assertEquals(var$6, $($Float::valueOf($floatValue($nc(Test6998541::mh_fz)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$7, $of($Double::valueOf((double)i)));
	assertEquals(var$7, $($Double::valueOf($doubleValue($nc(Test6998541::mh_dz)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
}

void Test6998541::boolean2prim_invalid(bool x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	if (Test6998541::DO_CASTS) {
		return;
	}
	try {
		int8_t y = $byteValue($nc(Test6998541::mh_bz)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		char16_t y = $charValue($nc(Test6998541::mh_cz)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int16_t y = $shortValue($nc(Test6998541::mh_sz)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int32_t y = $intValue($nc(Test6998541::mh_iz)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int64_t y = $longValue($nc(Test6998541::mh_jz)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		float y = $floatValue($nc(Test6998541::mh_fz)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		double y = $doubleValue($nc(Test6998541::mh_dz)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
}

$MethodHandle* Test6998541::mh_b($Class* ret) {
	$init(Test6998541);
	$init($Byte);
	return mh(ret, $$new($ClassArray, {$Byte::TYPE}));
}

void Test6998541::byte2prim(int8_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of($Byte::valueOf(x)));
	assertEquals(var$0, $($Byte::valueOf($byteValue($nc(Test6998541::mh_bb)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$1, $of($Short::valueOf((int16_t)x)));
	assertEquals(var$1, $($Short::valueOf($shortValue($nc(Test6998541::mh_sb)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$2, $of($Integer::valueOf((int32_t)x)));
	assertEquals(var$2, $($Integer::valueOf($intValue($nc(Test6998541::mh_ib)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$3, $of($Long::valueOf((int64_t)x)));
	assertEquals(var$3, $($Long::valueOf($longValue($nc(Test6998541::mh_jb)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$4, $of($Float::valueOf((float)x)));
	assertEquals(var$4, $($Float::valueOf($floatValue($nc(Test6998541::mh_fb)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$5, $of($Double::valueOf((double)x)));
	assertEquals(var$5, $($Double::valueOf($doubleValue($nc(Test6998541::mh_db)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	if (!Test6998541::DO_CASTS) {
		return;
	}
	bool z = (((int32_t)(x & (uint32_t)1)) != 0);
	$var($Object, var$6, $of($Character::valueOf((char16_t)x)));
	assertEquals(var$6, $($Character::valueOf($charValue($nc(Test6998541::mh_cb)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$7, $of($Boolean::valueOf(z)));
	assertEquals(var$7, $($Boolean::valueOf($booleanValue($nc(Test6998541::mh_zb)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
}

void Test6998541::byte2prim_invalid(int8_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	if (Test6998541::DO_CASTS) {
		return;
	}
	try {
		char16_t y = $charValue($nc(Test6998541::mh_cb)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		bool y = $booleanValue($nc(Test6998541::mh_zb)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
}

$MethodHandle* Test6998541::mh_c($Class* ret) {
	$init(Test6998541);
	$init($Character);
	return mh(ret, $$new($ClassArray, {$Character::TYPE}));
}

void Test6998541::char2prim(char16_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of($Character::valueOf(x)));
	assertEquals(var$0, $($Character::valueOf($charValue($nc(Test6998541::mh_cc)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$1, $of($Integer::valueOf((int32_t)x)));
	assertEquals(var$1, $($Integer::valueOf($intValue($nc(Test6998541::mh_ic)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$2, $of($Long::valueOf((int64_t)x)));
	assertEquals(var$2, $($Long::valueOf($longValue($nc(Test6998541::mh_jc)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$3, $of($Float::valueOf((float)x)));
	assertEquals(var$3, $($Float::valueOf($floatValue($nc(Test6998541::mh_fc)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$4, $of($Double::valueOf((double)x)));
	assertEquals(var$4, $($Double::valueOf($doubleValue($nc(Test6998541::mh_dc)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	if (!Test6998541::DO_CASTS) {
		return;
	}
	bool z = (((int32_t)(x & (uint32_t)1)) != 0);
	$var($Object, var$5, $of($Boolean::valueOf(z)));
	assertEquals(var$5, $($Boolean::valueOf($booleanValue($nc(Test6998541::mh_zc)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$6, $of($Byte::valueOf((int8_t)x)));
	assertEquals(var$6, $($Byte::valueOf($byteValue($nc(Test6998541::mh_bc)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$7, $of($Short::valueOf((int16_t)x)));
	assertEquals(var$7, $($Short::valueOf($shortValue($nc(Test6998541::mh_sc)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
}

void Test6998541::char2prim_invalid(char16_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	if (Test6998541::DO_CASTS) {
		return;
	}
	try {
		bool y = $booleanValue($nc(Test6998541::mh_zc)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int8_t y = $byteValue($nc(Test6998541::mh_bc)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int16_t y = $shortValue($nc(Test6998541::mh_sc)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
}

$MethodHandle* Test6998541::mh_s($Class* ret) {
	$init(Test6998541);
	$init($Short);
	return mh(ret, $$new($ClassArray, {$Short::TYPE}));
}

void Test6998541::short2prim(int16_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of($Short::valueOf(x)));
	assertEquals(var$0, $($Short::valueOf($shortValue($nc(Test6998541::mh_ss)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$1, $of($Integer::valueOf((int32_t)x)));
	assertEquals(var$1, $($Integer::valueOf($intValue($nc(Test6998541::mh_is)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$2, $of($Long::valueOf((int64_t)x)));
	assertEquals(var$2, $($Long::valueOf($longValue($nc(Test6998541::mh_js)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$3, $of($Float::valueOf((float)x)));
	assertEquals(var$3, $($Float::valueOf($floatValue($nc(Test6998541::mh_fs)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$4, $of($Double::valueOf((double)x)));
	assertEquals(var$4, $($Double::valueOf($doubleValue($nc(Test6998541::mh_ds)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	if (!Test6998541::DO_CASTS) {
		return;
	}
	bool z = (((int32_t)(x & (uint32_t)1)) != 0);
	$var($Object, var$5, $of($Boolean::valueOf(z)));
	assertEquals(var$5, $($Boolean::valueOf($booleanValue($nc(Test6998541::mh_zs)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$6, $of($Byte::valueOf((int8_t)x)));
	assertEquals(var$6, $($Byte::valueOf($byteValue($nc(Test6998541::mh_bs)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$7, $of($Character::valueOf((char16_t)x)));
	assertEquals(var$7, $($Character::valueOf($charValue($nc(Test6998541::mh_cs)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
}

void Test6998541::short2prim_invalid(int16_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	if (Test6998541::DO_CASTS) {
		return;
	}
	try {
		bool y = $booleanValue($nc(Test6998541::mh_zs)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int8_t y = $byteValue($nc(Test6998541::mh_bs)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		char16_t y = $charValue($nc(Test6998541::mh_cs)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
}

$MethodHandle* Test6998541::mh_i($Class* ret) {
	$init(Test6998541);
	$init($Integer);
	return mh(ret, $$new($ClassArray, {$Integer::TYPE}));
}

void Test6998541::int2prim(int32_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of($Integer::valueOf(x)));
	assertEquals(var$0, $($Integer::valueOf($intValue($nc(Test6998541::mh_ii)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$1, $of($Long::valueOf((int64_t)x)));
	assertEquals(var$1, $($Long::valueOf($longValue($nc(Test6998541::mh_ji)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$2, $of($Float::valueOf((float)x)));
	assertEquals(var$2, $($Float::valueOf($floatValue($nc(Test6998541::mh_fi)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$3, $of($Double::valueOf((double)x)));
	assertEquals(var$3, $($Double::valueOf($doubleValue($nc(Test6998541::mh_di)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	if (!Test6998541::DO_CASTS) {
		return;
	}
	bool z = (((int32_t)(x & (uint32_t)1)) != 0);
	$var($Object, var$4, $of($Boolean::valueOf(z)));
	assertEquals(var$4, $($Boolean::valueOf($booleanValue($nc(Test6998541::mh_zi)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$5, $of($Byte::valueOf((int8_t)x)));
	assertEquals(var$5, $($Byte::valueOf($byteValue($nc(Test6998541::mh_bi)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$6, $of($Character::valueOf((char16_t)x)));
	assertEquals(var$6, $($Character::valueOf($charValue($nc(Test6998541::mh_ci)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$7, $of($Short::valueOf((int16_t)x)));
	assertEquals(var$7, $($Short::valueOf($shortValue($nc(Test6998541::mh_si)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
}

void Test6998541::int2prim_invalid(int32_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	if (Test6998541::DO_CASTS) {
		return;
	}
	try {
		bool y = $booleanValue($nc(Test6998541::mh_zi)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int8_t y = $byteValue($nc(Test6998541::mh_bi)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		char16_t y = $charValue($nc(Test6998541::mh_ci)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int16_t y = $shortValue($nc(Test6998541::mh_si)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
}

$MethodHandle* Test6998541::mh_j($Class* ret) {
	$init(Test6998541);
	$init($Long);
	return mh(ret, $$new($ClassArray, {$Long::TYPE}));
}

void Test6998541::long2prim(int64_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of($Long::valueOf(x)));
	assertEquals(var$0, $($Long::valueOf($longValue($nc(Test6998541::mh_jj)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$1, $of($Float::valueOf((float)x)));
	assertEquals(var$1, $($Float::valueOf($floatValue($nc(Test6998541::mh_fj)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$2, $of($Double::valueOf((double)x)));
	assertEquals(var$2, $($Double::valueOf($doubleValue($nc(Test6998541::mh_dj)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	if (!Test6998541::DO_CASTS) {
		return;
	}
	bool z = (((int64_t)(x & (uint64_t)(int64_t)1)) != 0);
	$var($Object, var$3, $of($Boolean::valueOf(z)));
	assertEquals(var$3, $($Boolean::valueOf($booleanValue($nc(Test6998541::mh_zj)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$4, $of($Byte::valueOf((int8_t)x)));
	assertEquals(var$4, $($Byte::valueOf($byteValue($nc(Test6998541::mh_bj)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$5, $of($Character::valueOf((char16_t)x)));
	assertEquals(var$5, $($Character::valueOf($charValue($nc(Test6998541::mh_cj)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$6, $of($Short::valueOf((int16_t)x)));
	assertEquals(var$6, $($Short::valueOf($shortValue($nc(Test6998541::mh_sj)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$7, $of($Integer::valueOf((int32_t)x)));
	assertEquals(var$7, $($Integer::valueOf($intValue($nc(Test6998541::mh_ij)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
}

void Test6998541::long2prim_invalid(int64_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	if (Test6998541::DO_CASTS) {
		return;
	}
	try {
		bool y = $booleanValue($nc(Test6998541::mh_zj)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int8_t y = $byteValue($nc(Test6998541::mh_bj)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		char16_t y = $charValue($nc(Test6998541::mh_cj)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int16_t y = $shortValue($nc(Test6998541::mh_sj)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int32_t y = $intValue($nc(Test6998541::mh_ij)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
}

$MethodHandle* Test6998541::mh_f($Class* ret) {
	$init(Test6998541);
	$init($Float);
	return mh(ret, $$new($ClassArray, {$Float::TYPE}));
}

void Test6998541::float2prim(float x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of($Float::valueOf(x)));
	assertEquals(var$0, $($Float::valueOf($floatValue($nc(Test6998541::mh_ff)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$1, $of($Double::valueOf((double)x)));
	assertEquals(var$1, $($Double::valueOf($doubleValue($nc(Test6998541::mh_df)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	if (!Test6998541::DO_CASTS) {
		return;
	}
	bool z = (((int32_t)($cast(int8_t, x) & (uint32_t)1)) != 0);
	$var($Object, var$2, $of($Boolean::valueOf(z)));
	assertEquals(var$2, $($Boolean::valueOf($booleanValue($nc(Test6998541::mh_zf)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$3, $of($Byte::valueOf($cast(int8_t, x))));
	assertEquals(var$3, $($Byte::valueOf($byteValue($nc(Test6998541::mh_bf)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$4, $of($Character::valueOf((char16_t)x)));
	assertEquals(var$4, $($Character::valueOf($charValue($nc(Test6998541::mh_cf)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$5, $of($Short::valueOf($cast(int16_t, x))));
	assertEquals(var$5, $($Short::valueOf($shortValue($nc(Test6998541::mh_sf)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$6, $of($Integer::valueOf($cast(int32_t, x))));
	assertEquals(var$6, $($Integer::valueOf($intValue($nc(Test6998541::mh_if)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$7, $of($Long::valueOf($cast(int64_t, x))));
	assertEquals(var$7, $($Long::valueOf($longValue($nc(Test6998541::mh_jf)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
}

void Test6998541::float2prim_invalid(float x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	if (Test6998541::DO_CASTS) {
		return;
	}
	try {
		bool y = $booleanValue($nc(Test6998541::mh_zf)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int8_t y = $byteValue($nc(Test6998541::mh_bf)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		char16_t y = $charValue($nc(Test6998541::mh_cf)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int16_t y = $shortValue($nc(Test6998541::mh_sf)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int32_t y = $intValue($nc(Test6998541::mh_if)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int64_t y = $longValue($nc(Test6998541::mh_jf)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
}

$MethodHandle* Test6998541::mh_d($Class* ret) {
	$init(Test6998541);
	$init($Double);
	return mh(ret, $$new($ClassArray, {$Double::TYPE}));
}

void Test6998541::double2prim(double x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of($Double::valueOf(x)));
	assertEquals(var$0, $($Double::valueOf($doubleValue($nc(Test6998541::mh_dd)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	if (!Test6998541::DO_CASTS) {
		return;
	}
	bool z = (((int32_t)($cast(int8_t, x) & (uint32_t)1)) != 0);
	$var($Object, var$1, $of($Boolean::valueOf(z)));
	assertEquals(var$1, $($Boolean::valueOf($booleanValue($nc(Test6998541::mh_zd)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$2, $of($Byte::valueOf($cast(int8_t, x))));
	assertEquals(var$2, $($Byte::valueOf($byteValue($nc(Test6998541::mh_bd)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$3, $of($Character::valueOf((char16_t)x)));
	assertEquals(var$3, $($Character::valueOf($charValue($nc(Test6998541::mh_cd)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$4, $of($Short::valueOf($cast(int16_t, x))));
	assertEquals(var$4, $($Short::valueOf($shortValue($nc(Test6998541::mh_sd)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$5, $of($Integer::valueOf($cast(int32_t, x))));
	assertEquals(var$5, $($Integer::valueOf($intValue($nc(Test6998541::mh_id)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$6, $of($Long::valueOf($cast(int64_t, x))));
	assertEquals(var$6, $($Long::valueOf($longValue($nc(Test6998541::mh_jd)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
	$var($Object, var$7, $of($Float::valueOf((float)x)));
	assertEquals(var$7, $($Float::valueOf($floatValue($nc(Test6998541::mh_fd)->invokeExact($$new($ObjectArray, {$$of(x)}))))));
}

void Test6998541::double2prim_invalid(double x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	if (Test6998541::DO_CASTS) {
		return;
	}
	try {
		bool y = $booleanValue($nc(Test6998541::mh_zd)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int8_t y = $byteValue($nc(Test6998541::mh_bd)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		char16_t y = $charValue($nc(Test6998541::mh_cd)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int16_t y = $shortValue($nc(Test6998541::mh_sd)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int32_t y = $intValue($nc(Test6998541::mh_id)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		int64_t y = $longValue($nc(Test6998541::mh_jd)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
	try {
		float y = $floatValue($nc(Test6998541::mh_fd)->invokeExact($$new($ObjectArray, {$$of(x)})));
		fail();
	} catch ($ClassCastException& expected) {
	}
}

void Test6998541::void2prim(int32_t i) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	$var($Object, var$0, $of($Boolean::valueOf(false)));
	assertEquals(var$0, $($Boolean::valueOf($booleanValue($nc(Test6998541::mh_zv)->invokeExact($$new($ObjectArray, 0))))));
	$var($Object, var$1, $of($Byte::valueOf((int8_t)0)));
	assertEquals(var$1, $($Byte::valueOf($byteValue($nc(Test6998541::mh_bv)->invokeExact($$new($ObjectArray, 0))))));
	$var($Object, var$2, $of($Character::valueOf((char16_t)0)));
	assertEquals(var$2, $($Character::valueOf($charValue($nc(Test6998541::mh_cv)->invokeExact($$new($ObjectArray, 0))))));
	$var($Object, var$3, $of($Short::valueOf((int16_t)0)));
	assertEquals(var$3, $($Short::valueOf($shortValue($nc(Test6998541::mh_sv)->invokeExact($$new($ObjectArray, 0))))));
	$var($Object, var$4, $of($Integer::valueOf(0)));
	assertEquals(var$4, $($Integer::valueOf($intValue($nc(Test6998541::mh_iv)->invokeExact($$new($ObjectArray, 0))))));
	$var($Object, var$5, $of($Long::valueOf((int64_t)0)));
	assertEquals(var$5, $($Long::valueOf($longValue($nc(Test6998541::mh_jv)->invokeExact($$new($ObjectArray, 0))))));
	$var($Object, var$6, $of($Float::valueOf(0.0f)));
	assertEquals(var$6, $($Float::valueOf($floatValue($nc(Test6998541::mh_fv)->invokeExact($$new($ObjectArray, 0))))));
	$var($Object, var$7, $of($Double::valueOf(0.0)));
	assertEquals(var$7, $($Double::valueOf($doubleValue($nc(Test6998541::mh_dv)->invokeExact($$new($ObjectArray, 0))))));
}

void Test6998541::void2prim_invalid(double x) {
	$init(Test6998541);
}

$MethodHandle* Test6998541::mh_v($Class* arg) {
	$init(Test6998541);
	$init($Void);
	return mh($Void::TYPE, $$new($ClassArray, {arg}));
}

void Test6998541::prim2void(int32_t x) {
	$init(Test6998541);
	$useLocalCurrentObjectStackCache();
	bool z = (((int32_t)(x & (uint32_t)1)) != 0);
	$nc(Test6998541::mh_vz)->invokeExact($$new($ObjectArray, {$$of(z)}));
	$nc(Test6998541::mh_vb)->invokeExact($$new($ObjectArray, {$$of((int8_t)x)}));
	$nc(Test6998541::mh_vc)->invokeExact($$new($ObjectArray, {$$of((char16_t)x)}));
	$nc(Test6998541::mh_vs)->invokeExact($$new($ObjectArray, {$$of((int16_t)x)}));
	$nc(Test6998541::mh_vi)->invokeExact($$new($ObjectArray, {$$of(x)}));
	$nc(Test6998541::mh_vj)->invokeExact($$new($ObjectArray, {$$of((int64_t)x)}));
	$nc(Test6998541::mh_vf)->invokeExact($$new($ObjectArray, {$$of((float)x)}));
	$nc(Test6998541::mh_vd)->invokeExact($$new($ObjectArray, {$$of((double)x)}));
}

void Test6998541::prim2void_invalid(int32_t x) {
	$init(Test6998541);
}

bool Test6998541::identity(bool v) {
	$init(Test6998541);
	return v;
}

int8_t Test6998541::identity(int8_t v) {
	$init(Test6998541);
	return v;
}

char16_t Test6998541::identity(char16_t v) {
	$init(Test6998541);
	return v;
}

int16_t Test6998541::identity(int16_t v) {
	$init(Test6998541);
	return v;
}

int32_t Test6998541::identity(int32_t v) {
	$init(Test6998541);
	return v;
}

int64_t Test6998541::identity(int64_t v) {
	$init(Test6998541);
	return v;
}

float Test6998541::identity(float v) {
	$init(Test6998541);
	return v;
}

double Test6998541::identity(double v) {
	$init(Test6998541);
	return v;
}

void Test6998541::identity() {
	$init(Test6998541);
}

void clinit$Test6998541($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Test6998541::NAME, "identity"_s);
	$beforeCallerSensitive();
	$assignStatic(Test6998541::CLASS, Test6998541::class$);
	Test6998541::N = $Math::max(2, $nc($($Integer::getInteger($$str({$($nc(Test6998541::CLASS)->getSimpleName()), ".N"_s}), 10000)))->intValue());
	$assignStatic(Test6998541::KIND, $System::getProperty($$str({$($nc(Test6998541::CLASS)->getSimpleName()), ".KIND"_s}), "cast"_s));
	Test6998541::DO_CASTS = !$nc(Test6998541::KIND)->equals("normal"_s);
	$assignStatic(Test6998541::lookup, $MethodHandles::lookup());
	$init($Byte);
	$init($Short);
	$init($Long);
	$init($Float);
	$init($Double);
	$assignStatic(Test6998541::NUMERIC_TYPE_WIDENING_ORDER, $new($ClassArray, {
		$Byte::TYPE,
		$Short::TYPE,
		$Integer::TYPE,
		$Long::TYPE,
		$Float::TYPE,
		$Double::TYPE
	}));
	$init($Boolean);
	$assignStatic(Test6998541::mh_zz, Test6998541::mh_z($Boolean::TYPE));
	$assignStatic(Test6998541::mh_bz, Test6998541::mh_z($Byte::TYPE));
	$init($Character);
	$assignStatic(Test6998541::mh_cz, Test6998541::mh_z($Character::TYPE));
	$assignStatic(Test6998541::mh_sz, Test6998541::mh_z($Short::TYPE));
	$assignStatic(Test6998541::mh_iz, Test6998541::mh_z($Integer::TYPE));
	$assignStatic(Test6998541::mh_jz, Test6998541::mh_z($Long::TYPE));
	$assignStatic(Test6998541::mh_fz, Test6998541::mh_z($Float::TYPE));
	$assignStatic(Test6998541::mh_dz, Test6998541::mh_z($Double::TYPE));
	$assignStatic(Test6998541::mh_zb, Test6998541::mh_b($Boolean::TYPE));
	$assignStatic(Test6998541::mh_bb, Test6998541::mh_b($Byte::TYPE));
	$assignStatic(Test6998541::mh_cb, Test6998541::mh_b($Character::TYPE));
	$assignStatic(Test6998541::mh_sb, Test6998541::mh_b($Short::TYPE));
	$assignStatic(Test6998541::mh_ib, Test6998541::mh_b($Integer::TYPE));
	$assignStatic(Test6998541::mh_jb, Test6998541::mh_b($Long::TYPE));
	$assignStatic(Test6998541::mh_fb, Test6998541::mh_b($Float::TYPE));
	$assignStatic(Test6998541::mh_db, Test6998541::mh_b($Double::TYPE));
	$assignStatic(Test6998541::mh_zc, Test6998541::mh_c($Boolean::TYPE));
	$assignStatic(Test6998541::mh_bc, Test6998541::mh_c($Byte::TYPE));
	$assignStatic(Test6998541::mh_cc, Test6998541::mh_c($Character::TYPE));
	$assignStatic(Test6998541::mh_sc, Test6998541::mh_c($Short::TYPE));
	$assignStatic(Test6998541::mh_ic, Test6998541::mh_c($Integer::TYPE));
	$assignStatic(Test6998541::mh_jc, Test6998541::mh_c($Long::TYPE));
	$assignStatic(Test6998541::mh_fc, Test6998541::mh_c($Float::TYPE));
	$assignStatic(Test6998541::mh_dc, Test6998541::mh_c($Double::TYPE));
	$assignStatic(Test6998541::mh_zs, Test6998541::mh_s($Boolean::TYPE));
	$assignStatic(Test6998541::mh_bs, Test6998541::mh_s($Byte::TYPE));
	$assignStatic(Test6998541::mh_cs, Test6998541::mh_s($Character::TYPE));
	$assignStatic(Test6998541::mh_ss, Test6998541::mh_s($Short::TYPE));
	$assignStatic(Test6998541::mh_is, Test6998541::mh_s($Integer::TYPE));
	$assignStatic(Test6998541::mh_js, Test6998541::mh_s($Long::TYPE));
	$assignStatic(Test6998541::mh_fs, Test6998541::mh_s($Float::TYPE));
	$assignStatic(Test6998541::mh_ds, Test6998541::mh_s($Double::TYPE));
	$assignStatic(Test6998541::mh_zi, Test6998541::mh_i($Boolean::TYPE));
	$assignStatic(Test6998541::mh_bi, Test6998541::mh_i($Byte::TYPE));
	$assignStatic(Test6998541::mh_ci, Test6998541::mh_i($Character::TYPE));
	$assignStatic(Test6998541::mh_si, Test6998541::mh_i($Short::TYPE));
	$assignStatic(Test6998541::mh_ii, Test6998541::mh_i($Integer::TYPE));
	$assignStatic(Test6998541::mh_ji, Test6998541::mh_i($Long::TYPE));
	$assignStatic(Test6998541::mh_fi, Test6998541::mh_i($Float::TYPE));
	$assignStatic(Test6998541::mh_di, Test6998541::mh_i($Double::TYPE));
	$assignStatic(Test6998541::mh_zj, Test6998541::mh_j($Boolean::TYPE));
	$assignStatic(Test6998541::mh_bj, Test6998541::mh_j($Byte::TYPE));
	$assignStatic(Test6998541::mh_cj, Test6998541::mh_j($Character::TYPE));
	$assignStatic(Test6998541::mh_sj, Test6998541::mh_j($Short::TYPE));
	$assignStatic(Test6998541::mh_ij, Test6998541::mh_j($Integer::TYPE));
	$assignStatic(Test6998541::mh_jj, Test6998541::mh_j($Long::TYPE));
	$assignStatic(Test6998541::mh_fj, Test6998541::mh_j($Float::TYPE));
	$assignStatic(Test6998541::mh_dj, Test6998541::mh_j($Double::TYPE));
	$assignStatic(Test6998541::mh_zf, Test6998541::mh_f($Boolean::TYPE));
	$assignStatic(Test6998541::mh_bf, Test6998541::mh_f($Byte::TYPE));
	$assignStatic(Test6998541::mh_cf, Test6998541::mh_f($Character::TYPE));
	$assignStatic(Test6998541::mh_sf, Test6998541::mh_f($Short::TYPE));
	$assignStatic(Test6998541::mh_if, Test6998541::mh_f($Integer::TYPE));
	$assignStatic(Test6998541::mh_jf, Test6998541::mh_f($Long::TYPE));
	$assignStatic(Test6998541::mh_ff, Test6998541::mh_f($Float::TYPE));
	$assignStatic(Test6998541::mh_df, Test6998541::mh_f($Double::TYPE));
	$assignStatic(Test6998541::mh_zd, Test6998541::mh_d($Boolean::TYPE));
	$assignStatic(Test6998541::mh_bd, Test6998541::mh_d($Byte::TYPE));
	$assignStatic(Test6998541::mh_cd, Test6998541::mh_d($Character::TYPE));
	$assignStatic(Test6998541::mh_sd, Test6998541::mh_d($Short::TYPE));
	$assignStatic(Test6998541::mh_id, Test6998541::mh_d($Integer::TYPE));
	$assignStatic(Test6998541::mh_jd, Test6998541::mh_d($Long::TYPE));
	$assignStatic(Test6998541::mh_fd, Test6998541::mh_d($Float::TYPE));
	$assignStatic(Test6998541::mh_dd, Test6998541::mh_d($Double::TYPE));
	$assignStatic(Test6998541::mh_zv, Test6998541::mh($Boolean::TYPE, $$new($ClassArray, 0)));
	$assignStatic(Test6998541::mh_bv, Test6998541::mh($Byte::TYPE, $$new($ClassArray, 0)));
	$assignStatic(Test6998541::mh_cv, Test6998541::mh($Character::TYPE, $$new($ClassArray, 0)));
	$assignStatic(Test6998541::mh_sv, Test6998541::mh($Short::TYPE, $$new($ClassArray, 0)));
	$assignStatic(Test6998541::mh_iv, Test6998541::mh($Integer::TYPE, $$new($ClassArray, 0)));
	$assignStatic(Test6998541::mh_jv, Test6998541::mh($Long::TYPE, $$new($ClassArray, 0)));
	$assignStatic(Test6998541::mh_fv, Test6998541::mh($Float::TYPE, $$new($ClassArray, 0)));
	$assignStatic(Test6998541::mh_dv, Test6998541::mh($Double::TYPE, $$new($ClassArray, 0)));
	$assignStatic(Test6998541::mh_vz, Test6998541::mh_v($Boolean::TYPE));
	$assignStatic(Test6998541::mh_vb, Test6998541::mh_v($Byte::TYPE));
	$assignStatic(Test6998541::mh_vc, Test6998541::mh_v($Character::TYPE));
	$assignStatic(Test6998541::mh_vs, Test6998541::mh_v($Short::TYPE));
	$assignStatic(Test6998541::mh_vi, Test6998541::mh_v($Integer::TYPE));
	$assignStatic(Test6998541::mh_vj, Test6998541::mh_v($Long::TYPE));
	$assignStatic(Test6998541::mh_vf, Test6998541::mh_v($Float::TYPE));
	$assignStatic(Test6998541::mh_vd, Test6998541::mh_v($Double::TYPE));
}

Test6998541::Test6998541() {
}

$Class* Test6998541::load$($String* name, bool initialize) {
	$loadClass(Test6998541, name, initialize, &_Test6998541_ClassInfo_, clinit$Test6998541, allocate$Test6998541);
	return class$;
}

$Class* Test6998541::class$ = nullptr;
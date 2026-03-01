#include <jdk/internal/reflect/UnsafeFieldAccessorFactory.h>

#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Modifier.h>
#include <jdk/internal/misc/Unsafe.h>
#include <jdk/internal/reflect/FieldAccessor.h>
#include <jdk/internal/reflect/UnsafeBooleanFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeByteFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeCharacterFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeDoubleFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeFloatFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeIntegerFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeLongFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeObjectFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedBooleanFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedByteFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedCharacterFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedDoubleFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedFloatFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedIntegerFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedLongFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedObjectFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedShortFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedStaticBooleanFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedStaticByteFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedStaticCharacterFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedStaticDoubleFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedStaticFloatFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedStaticIntegerFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedStaticLongFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedStaticObjectFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeQualifiedStaticShortFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeShortFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeStaticBooleanFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeStaticByteFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeStaticCharacterFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeStaticDoubleFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeStaticFloatFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeStaticIntegerFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeStaticLongFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeStaticObjectFieldAccessorImpl.h>
#include <jdk/internal/reflect/UnsafeStaticShortFieldAccessorImpl.h>
#include <jcpp.h>

#undef TYPE

using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Float = ::java::lang::Float;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;
using $Unsafe = ::jdk::internal::misc::Unsafe;
using $FieldAccessor = ::jdk::internal::reflect::FieldAccessor;
using $UnsafeBooleanFieldAccessorImpl = ::jdk::internal::reflect::UnsafeBooleanFieldAccessorImpl;
using $UnsafeByteFieldAccessorImpl = ::jdk::internal::reflect::UnsafeByteFieldAccessorImpl;
using $UnsafeCharacterFieldAccessorImpl = ::jdk::internal::reflect::UnsafeCharacterFieldAccessorImpl;
using $UnsafeDoubleFieldAccessorImpl = ::jdk::internal::reflect::UnsafeDoubleFieldAccessorImpl;
using $UnsafeFieldAccessorImpl = ::jdk::internal::reflect::UnsafeFieldAccessorImpl;
using $UnsafeFloatFieldAccessorImpl = ::jdk::internal::reflect::UnsafeFloatFieldAccessorImpl;
using $UnsafeIntegerFieldAccessorImpl = ::jdk::internal::reflect::UnsafeIntegerFieldAccessorImpl;
using $UnsafeLongFieldAccessorImpl = ::jdk::internal::reflect::UnsafeLongFieldAccessorImpl;
using $UnsafeObjectFieldAccessorImpl = ::jdk::internal::reflect::UnsafeObjectFieldAccessorImpl;
using $UnsafeQualifiedBooleanFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedBooleanFieldAccessorImpl;
using $UnsafeQualifiedByteFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedByteFieldAccessorImpl;
using $UnsafeQualifiedCharacterFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedCharacterFieldAccessorImpl;
using $UnsafeQualifiedDoubleFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedDoubleFieldAccessorImpl;
using $UnsafeQualifiedFloatFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedFloatFieldAccessorImpl;
using $UnsafeQualifiedIntegerFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedIntegerFieldAccessorImpl;
using $UnsafeQualifiedLongFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedLongFieldAccessorImpl;
using $UnsafeQualifiedObjectFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedObjectFieldAccessorImpl;
using $UnsafeQualifiedShortFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedShortFieldAccessorImpl;
using $UnsafeQualifiedStaticBooleanFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedStaticBooleanFieldAccessorImpl;
using $UnsafeQualifiedStaticByteFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedStaticByteFieldAccessorImpl;
using $UnsafeQualifiedStaticCharacterFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedStaticCharacterFieldAccessorImpl;
using $UnsafeQualifiedStaticDoubleFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedStaticDoubleFieldAccessorImpl;
using $UnsafeQualifiedStaticFloatFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedStaticFloatFieldAccessorImpl;
using $UnsafeQualifiedStaticIntegerFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedStaticIntegerFieldAccessorImpl;
using $UnsafeQualifiedStaticLongFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedStaticLongFieldAccessorImpl;
using $UnsafeQualifiedStaticObjectFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedStaticObjectFieldAccessorImpl;
using $UnsafeQualifiedStaticShortFieldAccessorImpl = ::jdk::internal::reflect::UnsafeQualifiedStaticShortFieldAccessorImpl;
using $UnsafeShortFieldAccessorImpl = ::jdk::internal::reflect::UnsafeShortFieldAccessorImpl;
using $UnsafeStaticBooleanFieldAccessorImpl = ::jdk::internal::reflect::UnsafeStaticBooleanFieldAccessorImpl;
using $UnsafeStaticByteFieldAccessorImpl = ::jdk::internal::reflect::UnsafeStaticByteFieldAccessorImpl;
using $UnsafeStaticCharacterFieldAccessorImpl = ::jdk::internal::reflect::UnsafeStaticCharacterFieldAccessorImpl;
using $UnsafeStaticDoubleFieldAccessorImpl = ::jdk::internal::reflect::UnsafeStaticDoubleFieldAccessorImpl;
using $UnsafeStaticFloatFieldAccessorImpl = ::jdk::internal::reflect::UnsafeStaticFloatFieldAccessorImpl;
using $UnsafeStaticIntegerFieldAccessorImpl = ::jdk::internal::reflect::UnsafeStaticIntegerFieldAccessorImpl;
using $UnsafeStaticLongFieldAccessorImpl = ::jdk::internal::reflect::UnsafeStaticLongFieldAccessorImpl;
using $UnsafeStaticObjectFieldAccessorImpl = ::jdk::internal::reflect::UnsafeStaticObjectFieldAccessorImpl;
using $UnsafeStaticShortFieldAccessorImpl = ::jdk::internal::reflect::UnsafeStaticShortFieldAccessorImpl;

namespace jdk {
	namespace internal {
		namespace reflect {

$MethodInfo _UnsafeFieldAccessorFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(UnsafeFieldAccessorFactory, init$, void)},
	{"newFieldAccessor", "(Ljava/lang/reflect/Field;Z)Ljdk/internal/reflect/FieldAccessor;", nullptr, $STATIC, $staticMethod(UnsafeFieldAccessorFactory, newFieldAccessor, $FieldAccessor*, $Field*, bool)},
	{}
};

$ClassInfo _UnsafeFieldAccessorFactory_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.reflect.UnsafeFieldAccessorFactory",
	"java.lang.Object",
	nullptr,
	nullptr,
	_UnsafeFieldAccessorFactory_MethodInfo_
};

$Object* allocate$UnsafeFieldAccessorFactory($Class* clazz) {
	return $of($alloc(UnsafeFieldAccessorFactory));
}

void UnsafeFieldAccessorFactory::init$() {
}

$FieldAccessor* UnsafeFieldAccessorFactory::newFieldAccessor($Field* field, bool isReadOnly) {
	$Class* type = $nc(field)->getType();
	bool isStatic = $Modifier::isStatic(field->getModifiers());
	bool isFinal = $Modifier::isFinal(field->getModifiers());
	bool isVolatile = $Modifier::isVolatile(field->getModifiers());
	bool isQualified = isFinal || isVolatile;
	if (isStatic) {
		$init($UnsafeFieldAccessorImpl);
		$nc($UnsafeFieldAccessorImpl::unsafe)->ensureClassInitialized(field->getDeclaringClass());
		if (!isQualified) {
			$init($Boolean);
			if (type == $Boolean::TYPE) {
				return $new($UnsafeStaticBooleanFieldAccessorImpl, field);
			} else {
				$init($Byte);
				if (type == $Byte::TYPE) {
					return $new($UnsafeStaticByteFieldAccessorImpl, field);
				} else {
					$init($Short);
					if (type == $Short::TYPE) {
						return $new($UnsafeStaticShortFieldAccessorImpl, field);
					} else {
						$init($Character);
						if (type == $Character::TYPE) {
							return $new($UnsafeStaticCharacterFieldAccessorImpl, field);
						} else {
							$init($Integer);
							if (type == $Integer::TYPE) {
								return $new($UnsafeStaticIntegerFieldAccessorImpl, field);
							} else {
								$init($Long);
								if (type == $Long::TYPE) {
									return $new($UnsafeStaticLongFieldAccessorImpl, field);
								} else {
									$init($Float);
									if (type == $Float::TYPE) {
										return $new($UnsafeStaticFloatFieldAccessorImpl, field);
									} else {
										$init($Double);
										if (type == $Double::TYPE) {
											return $new($UnsafeStaticDoubleFieldAccessorImpl, field);
										} else {
											return $new($UnsafeStaticObjectFieldAccessorImpl, field);
										}
									}
								}
							}
						}
					}
				}
			}
		} else {
			$init($Boolean);
			if (type == $Boolean::TYPE) {
				return $new($UnsafeQualifiedStaticBooleanFieldAccessorImpl, field, isReadOnly);
			} else {
				$init($Byte);
				if (type == $Byte::TYPE) {
					return $new($UnsafeQualifiedStaticByteFieldAccessorImpl, field, isReadOnly);
				} else {
					$init($Short);
					if (type == $Short::TYPE) {
						return $new($UnsafeQualifiedStaticShortFieldAccessorImpl, field, isReadOnly);
					} else {
						$init($Character);
						if (type == $Character::TYPE) {
							return $new($UnsafeQualifiedStaticCharacterFieldAccessorImpl, field, isReadOnly);
						} else {
							$init($Integer);
							if (type == $Integer::TYPE) {
								return $new($UnsafeQualifiedStaticIntegerFieldAccessorImpl, field, isReadOnly);
							} else {
								$init($Long);
								if (type == $Long::TYPE) {
									return $new($UnsafeQualifiedStaticLongFieldAccessorImpl, field, isReadOnly);
								} else {
									$init($Float);
									if (type == $Float::TYPE) {
										return $new($UnsafeQualifiedStaticFloatFieldAccessorImpl, field, isReadOnly);
									} else {
										$init($Double);
										if (type == $Double::TYPE) {
											return $new($UnsafeQualifiedStaticDoubleFieldAccessorImpl, field, isReadOnly);
										} else {
											return $new($UnsafeQualifiedStaticObjectFieldAccessorImpl, field, isReadOnly);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} else if (!isQualified) {
		$init($Boolean);
		if (type == $Boolean::TYPE) {
			return $new($UnsafeBooleanFieldAccessorImpl, field);
		} else {
			$init($Byte);
			if (type == $Byte::TYPE) {
				return $new($UnsafeByteFieldAccessorImpl, field);
			} else {
				$init($Short);
				if (type == $Short::TYPE) {
					return $new($UnsafeShortFieldAccessorImpl, field);
				} else {
					$init($Character);
					if (type == $Character::TYPE) {
						return $new($UnsafeCharacterFieldAccessorImpl, field);
					} else {
						$init($Integer);
						if (type == $Integer::TYPE) {
							return $new($UnsafeIntegerFieldAccessorImpl, field);
						} else {
							$init($Long);
							if (type == $Long::TYPE) {
								return $new($UnsafeLongFieldAccessorImpl, field);
							} else {
								$init($Float);
								if (type == $Float::TYPE) {
									return $new($UnsafeFloatFieldAccessorImpl, field);
								} else {
									$init($Double);
									if (type == $Double::TYPE) {
										return $new($UnsafeDoubleFieldAccessorImpl, field);
									} else {
										return $new($UnsafeObjectFieldAccessorImpl, field);
									}
								}
							}
						}
					}
				}
			}
		}
	} else {
		$init($Boolean);
		if (type == $Boolean::TYPE) {
			return $new($UnsafeQualifiedBooleanFieldAccessorImpl, field, isReadOnly);
		} else {
			$init($Byte);
			if (type == $Byte::TYPE) {
				return $new($UnsafeQualifiedByteFieldAccessorImpl, field, isReadOnly);
			} else {
				$init($Short);
				if (type == $Short::TYPE) {
					return $new($UnsafeQualifiedShortFieldAccessorImpl, field, isReadOnly);
				} else {
					$init($Character);
					if (type == $Character::TYPE) {
						return $new($UnsafeQualifiedCharacterFieldAccessorImpl, field, isReadOnly);
					} else {
						$init($Integer);
						if (type == $Integer::TYPE) {
							return $new($UnsafeQualifiedIntegerFieldAccessorImpl, field, isReadOnly);
						} else {
							$init($Long);
							if (type == $Long::TYPE) {
								return $new($UnsafeQualifiedLongFieldAccessorImpl, field, isReadOnly);
							} else {
								$init($Float);
								if (type == $Float::TYPE) {
									return $new($UnsafeQualifiedFloatFieldAccessorImpl, field, isReadOnly);
								} else {
									$init($Double);
									if (type == $Double::TYPE) {
										return $new($UnsafeQualifiedDoubleFieldAccessorImpl, field, isReadOnly);
									} else {
										return $new($UnsafeQualifiedObjectFieldAccessorImpl, field, isReadOnly);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

UnsafeFieldAccessorFactory::UnsafeFieldAccessorFactory() {
}

$Class* UnsafeFieldAccessorFactory::load$($String* name, bool initialize) {
	$loadClass(UnsafeFieldAccessorFactory, name, initialize, &_UnsafeFieldAccessorFactory_ClassInfo_, allocate$UnsafeFieldAccessorFactory);
	return class$;
}

$Class* UnsafeFieldAccessorFactory::class$ = nullptr;

		} // reflect
	} // internal
} // jdk
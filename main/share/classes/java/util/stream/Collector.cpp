#include <java/util/stream/Collector.h>

#include <java/lang/Enum.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/EnumSet.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BinaryOperator.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Collector$Characteristics.h>
#include <java/util/stream/Collectors$CollectorImpl.h>
#include <java/util/stream/Collectors.h>
#include <jcpp.h>

#undef CH_ID
#undef CH_NOID
#undef IDENTITY_FINISH

using $EnumArray = $Array<::java::lang::Enum>;
using $Collector$CharacteristicsArray = $Array<::java::util::stream::Collector$Characteristics>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $EnumSet = ::java::util::EnumSet;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BinaryOperator = ::java::util::function::BinaryOperator;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $Collector$Characteristics = ::java::util::stream::Collector$Characteristics;
using $Collectors = ::java::util::stream::Collectors;
using $Collectors$CollectorImpl = ::java::util::stream::Collectors$CollectorImpl;

namespace java {
	namespace util {
		namespace stream {

$MethodInfo _Collector_MethodInfo_[] = {
	{"accumulator", "()Ljava/util/function/BiConsumer;", "()Ljava/util/function/BiConsumer<TA;TT;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Collector, accumulator, $BiConsumer*)},
	{"characteristics", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/util/stream/Collector$Characteristics;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Collector, characteristics, $Set*)},
	{"combiner", "()Ljava/util/function/BinaryOperator;", "()Ljava/util/function/BinaryOperator<TA;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Collector, combiner, $BinaryOperator*)},
	{"finisher", "()Ljava/util/function/Function;", "()Ljava/util/function/Function<TA;TR;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Collector, finisher, $Function*)},
	{"of", "(Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/function/BinaryOperator;[Ljava/util/stream/Collector$Characteristics;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TR;>;Ljava/util/function/BiConsumer<TR;TT;>;Ljava/util/function/BinaryOperator<TR;>;[Ljava/util/stream/Collector$Characteristics;)Ljava/util/stream/Collector<TT;TR;TR;>;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(Collector, of, Collector*, $Supplier*, $BiConsumer*, $BinaryOperator*, $Collector$CharacteristicsArray*)},
	{"of", "(Ljava/util/function/Supplier;Ljava/util/function/BiConsumer;Ljava/util/function/BinaryOperator;Ljava/util/function/Function;[Ljava/util/stream/Collector$Characteristics;)Ljava/util/stream/Collector;", "<T:Ljava/lang/Object;A:Ljava/lang/Object;R:Ljava/lang/Object;>(Ljava/util/function/Supplier<TA;>;Ljava/util/function/BiConsumer<TA;TT;>;Ljava/util/function/BinaryOperator<TA;>;Ljava/util/function/Function<TA;TR;>;[Ljava/util/stream/Collector$Characteristics;)Ljava/util/stream/Collector<TT;TA;TR;>;", $PUBLIC | $STATIC | $TRANSIENT, $staticMethod(Collector, of, Collector*, $Supplier*, $BiConsumer*, $BinaryOperator*, $Function*, $Collector$CharacteristicsArray*)},
	{"supplier", "()Ljava/util/function/Supplier;", "()Ljava/util/function/Supplier<TA;>;", $PUBLIC | $ABSTRACT, $virtualMethod(Collector, supplier, $Supplier*)},
	{}
};

$InnerClassInfo _Collector_InnerClassesInfo_[] = {
	{"java.util.stream.Collector$Characteristics", "java.util.stream.Collector", "Characteristics", $PUBLIC | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Collector_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.stream.Collector",
	nullptr,
	nullptr,
	nullptr,
	_Collector_MethodInfo_,
	"<T:Ljava/lang/Object;A:Ljava/lang/Object;R:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_Collector_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.stream.Collector$Characteristics"
};

$Object* allocate$Collector($Class* clazz) {
	return $of($alloc(Collector));
}

Collector* Collector::of($Supplier* supplier, $BiConsumer* accumulator, $BinaryOperator* combiner, $Collector$CharacteristicsArray* characteristics) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(supplier);
	$Objects::requireNonNull(accumulator);
	$Objects::requireNonNull(combiner);
	$Objects::requireNonNull(characteristics);
	$init($Collectors);
	$init($Collector$Characteristics);
	$var($Set, cs, (characteristics->length == 0) ? $Collectors::CH_ID : $Collections::unmodifiableSet($($EnumSet::of(static_cast<$Enum*>($Collector$Characteristics::IDENTITY_FINISH), $fcast($EnumArray, characteristics)))));
	return $new($Collectors$CollectorImpl, supplier, accumulator, combiner, cs);
}

Collector* Collector::of($Supplier* supplier, $BiConsumer* accumulator, $BinaryOperator* combiner, $Function* finisher, $Collector$CharacteristicsArray* characteristics) {
	$Objects::requireNonNull(supplier);
	$Objects::requireNonNull(accumulator);
	$Objects::requireNonNull(combiner);
	$Objects::requireNonNull(finisher);
	$Objects::requireNonNull(characteristics);
	$init($Collectors);
	$var($Set, cs, $Collectors::CH_NOID);
	if (characteristics->length > 0) {
		$load($Collector$Characteristics);
		$assign(cs, $EnumSet::noneOf($Collector$Characteristics::class$));
		$Collections::addAll(cs, characteristics);
		$assign(cs, $Collections::unmodifiableSet(cs));
	}
	return $new($Collectors$CollectorImpl, supplier, accumulator, combiner, finisher, cs);
}

$Class* Collector::load$($String* name, bool initialize) {
	$loadClass(Collector, name, initialize, &_Collector_ClassInfo_, allocate$Collector);
	return class$;
}

$Class* Collector::class$ = nullptr;

		} // stream
	} // util
} // java
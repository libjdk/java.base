#include <Bug7104012.h>

#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/text/BreakIterator.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <jcpp.h>

#undef DONE

using $LocaleArray = $Array<::java::util::Locale>;
using $PrintStream = ::java::io::PrintStream;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $BreakIterator = ::java::text::BreakIterator;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;

$MethodInfo _Bug7104012_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Bug7104012, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Bug7104012, main, void, $StringArray*)},
	{}
};

$ClassInfo _Bug7104012_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Bug7104012",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Bug7104012_MethodInfo_
};

$Object* allocate$Bug7104012($Class* clazz) {
	return $of($alloc(Bug7104012));
}

void Bug7104012::init$() {
}

void Bug7104012::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	bool err = false;
	$var($List, data, $new($ArrayList));
	data->add($cstr({0xDB40}));
	data->add($cstr({' ', 0xDB40}));
	data->add($cstr({0xDC53}));
	data->add($cstr({' ', 0xDC53}));
	data->add($cstr({' ', 0xE0053}));
	data->add($cstr({0xE0053}));
	data->add($cstr({'A', 'B', 'C', ' ', 0xE0053, ' ', '1', '2', '3'}));
	data->add($cstr({0xE0053, ' ', 'A', 'B', 'C', ' ', 0xE0053}));
	{
		$var($LocaleArray, arr$, $Locale::getAvailableLocales());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Locale, locale, arr$->get(i$));
			{
				$var($List, breakIterators, $new($ArrayList));
				breakIterators->add($($BreakIterator::getCharacterInstance(locale)));
				breakIterators->add($($BreakIterator::getLineInstance(locale)));
				breakIterators->add($($BreakIterator::getSentenceInstance(locale)));
				breakIterators->add($($BreakIterator::getWordInstance(locale)));
				{
					$var($Iterator, i$, breakIterators->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($BreakIterator, bi, $cast($BreakIterator, i$->next()));
						{
							{
								$var($Iterator, i$, data->iterator());
								for (; $nc(i$)->hasNext();) {
									$var($String, str, $cast($String, i$->next()));
									{
										try {
											$nc(bi)->setText(str);
											bi->first();
											while (bi->next() != $BreakIterator::DONE) {
											}
											bi->last();
											while (bi->previous() != $BreakIterator::DONE) {
											}
										} catch ($ArrayIndexOutOfBoundsException& ex) {
											$nc($System::out)->println($$str({"    "_s, $$str(data->indexOf(str)), ": BreakIterator("_s, locale, ") threw AIOBE."_s}));
											err = true;
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
	if (err) {
		$throwNew($RuntimeException, "Unexpected exeption."_s);
	}
}

Bug7104012::Bug7104012() {
}

$Class* Bug7104012::load$($String* name, bool initialize) {
	$loadClass(Bug7104012, name, initialize, &_Bug7104012_ClassInfo_, allocate$Bug7104012);
	return class$;
}

$Class* Bug7104012::class$ = nullptr;
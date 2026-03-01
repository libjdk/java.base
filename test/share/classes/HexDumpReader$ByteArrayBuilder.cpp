#include <HexDumpReader$ByteArrayBuilder.h>

#include <HexDumpReader.h>
#include <java/lang/AssertionError.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef BUFFER_SIZE

using $HexDumpReader = ::HexDumpReader;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$FieldInfo _HexDumpReader$ByteArrayBuilder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HexDumpReader$ByteArrayBuilder, $assertionsDisabled)},
	{"BUFFER_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HexDumpReader$ByteArrayBuilder, BUFFER_SIZE)},
	{"size", "I", nullptr, $PRIVATE, $field(HexDumpReader$ByteArrayBuilder, size)},
	{"bytes", "Ljava/util/List;", "Ljava/util/List<[B>;", $PRIVATE, $field(HexDumpReader$ByteArrayBuilder, bytes)},
	{"current", "[B", nullptr, $PRIVATE, $field(HexDumpReader$ByteArrayBuilder, current)},
	{"offset", "I", nullptr, $PRIVATE, $field(HexDumpReader$ByteArrayBuilder, offset)},
	{}
};

$MethodInfo _HexDumpReader$ByteArrayBuilder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(HexDumpReader$ByteArrayBuilder, init$, void)},
	{"put", "(B)V", nullptr, 0, $virtualMethod(HexDumpReader$ByteArrayBuilder, put, void, int8_t)},
	{"toArray", "()[B", nullptr, 0, $virtualMethod(HexDumpReader$ByteArrayBuilder, toArray, $bytes*)},
	{}
};

$InnerClassInfo _HexDumpReader$ByteArrayBuilder_InnerClassesInfo_[] = {
	{"HexDumpReader$ByteArrayBuilder", "HexDumpReader", "ByteArrayBuilder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _HexDumpReader$ByteArrayBuilder_ClassInfo_ = {
	$ACC_SUPER,
	"HexDumpReader$ByteArrayBuilder",
	"java.lang.Object",
	nullptr,
	_HexDumpReader$ByteArrayBuilder_FieldInfo_,
	_HexDumpReader$ByteArrayBuilder_MethodInfo_,
	nullptr,
	nullptr,
	_HexDumpReader$ByteArrayBuilder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"HexDumpReader"
};

$Object* allocate$HexDumpReader$ByteArrayBuilder($Class* clazz) {
	return $of($alloc(HexDumpReader$ByteArrayBuilder));
}

bool HexDumpReader$ByteArrayBuilder::$assertionsDisabled = false;

void HexDumpReader$ByteArrayBuilder::init$() {
	$set(this, bytes, $new($ArrayList));
	$set(this, current, $new($bytes, HexDumpReader$ByteArrayBuilder::BUFFER_SIZE));
}

void HexDumpReader$ByteArrayBuilder::put(int8_t b) {
	if (this->offset == HexDumpReader$ByteArrayBuilder::BUFFER_SIZE) {
		$nc(this->bytes)->add(this->current);
		$set(this, current, $new($bytes, HexDumpReader$ByteArrayBuilder::BUFFER_SIZE));
		this->offset = 0;
	}
	$nc(this->current)->set(this->offset++, b);
	++this->size;
}

$bytes* HexDumpReader$ByteArrayBuilder::toArray() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, buf, $new($bytes, this->size));
	int32_t ptr = 0;
	{
		$var($Iterator, i$, $nc(this->bytes)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($bytes, ba, $cast($bytes, i$->next()));
			{
				$System::arraycopy(ba, 0, buf, ptr, $nc(ba)->length);
				ptr += $nc(ba)->length;
			}
		}
	}
	$System::arraycopy(this->current, 0, buf, ptr, this->offset);
	if (!HexDumpReader$ByteArrayBuilder::$assertionsDisabled && !(ptr + this->offset == this->size)) {
		$throwNew($AssertionError);
	}
	return buf;
}

void clinit$HexDumpReader$ByteArrayBuilder($Class* class$) {
	$load($HexDumpReader);
	HexDumpReader$ByteArrayBuilder::$assertionsDisabled = !$HexDumpReader::class$->desiredAssertionStatus();
}

HexDumpReader$ByteArrayBuilder::HexDumpReader$ByteArrayBuilder() {
}

$Class* HexDumpReader$ByteArrayBuilder::load$($String* name, bool initialize) {
	$loadClass(HexDumpReader$ByteArrayBuilder, name, initialize, &_HexDumpReader$ByteArrayBuilder_ClassInfo_, clinit$HexDumpReader$ByteArrayBuilder, allocate$HexDumpReader$ByteArrayBuilder);
	return class$;
}

$Class* HexDumpReader$ByteArrayBuilder::class$ = nullptr;
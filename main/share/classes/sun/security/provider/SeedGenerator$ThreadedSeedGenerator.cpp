#include <sun/security/provider/SeedGenerator$ThreadedSeedGenerator.h>

#include <java/lang/InternalError.h>
#include <java/lang/Runnable.h>
#include <java/lang/ThreadGroup.h>
#include <java/security/AccessController.h>
#include <java/security/MessageDigest.h>
#include <java/security/NoSuchAlgorithmException.h>
#include <java/security/PrivilegedAction.h>
#include <sun/security/provider/SeedGenerator$ThreadedSeedGenerator$1.h>
#include <sun/security/provider/SeedGenerator$ThreadedSeedGenerator$BogusThread.h>
#include <sun/security/provider/SeedGenerator.h>
#include <jcpp.h>

using $ThreadGroupArray = $Array<::java::lang::ThreadGroup>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $AccessController = ::java::security::AccessController;
using $MessageDigest = ::java::security::MessageDigest;
using $NoSuchAlgorithmException = ::java::security::NoSuchAlgorithmException;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $SeedGenerator = ::sun::security::provider::SeedGenerator;
using $SeedGenerator$ThreadedSeedGenerator$1 = ::sun::security::provider::SeedGenerator$ThreadedSeedGenerator$1;
using $SeedGenerator$ThreadedSeedGenerator$BogusThread = ::sun::security::provider::SeedGenerator$ThreadedSeedGenerator$BogusThread;

namespace sun {
	namespace security {
		namespace provider {

$FieldInfo _SeedGenerator$ThreadedSeedGenerator_FieldInfo_[] = {
	{"pool", "[B", nullptr, $PRIVATE, $field(SeedGenerator$ThreadedSeedGenerator, pool)},
	{"start", "I", nullptr, $PRIVATE, $field(SeedGenerator$ThreadedSeedGenerator, start)},
	{"end", "I", nullptr, $PRIVATE, $field(SeedGenerator$ThreadedSeedGenerator, end)},
	{"count", "I", nullptr, $PRIVATE, $field(SeedGenerator$ThreadedSeedGenerator, count)},
	{"seedGroup", "Ljava/lang/ThreadGroup;", nullptr, 0, $field(SeedGenerator$ThreadedSeedGenerator, seedGroup)},
	{"rndTab", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SeedGenerator$ThreadedSeedGenerator, rndTab)},
	{}
};

$MethodInfo _SeedGenerator$ThreadedSeedGenerator_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, 0, $method(SeedGenerator$ThreadedSeedGenerator, init$, void)},
	{"getSeedByte", "()B", nullptr, 0, $virtualMethod(SeedGenerator$ThreadedSeedGenerator, getSeedByte, int8_t)},
	{"getSeedBytes", "([B)V", nullptr, 0, $virtualMethod(SeedGenerator$ThreadedSeedGenerator, getSeedBytes, void, $bytes*)},
	{"run", "()V", nullptr, $PUBLIC | $FINAL, $virtualMethod(SeedGenerator$ThreadedSeedGenerator, run, void)},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SeedGenerator$ThreadedSeedGenerator_InnerClassesInfo_[] = {
	{"sun.security.provider.SeedGenerator$ThreadedSeedGenerator", "sun.security.provider.SeedGenerator", "ThreadedSeedGenerator", $PRIVATE | $STATIC},
	{"sun.security.provider.SeedGenerator$ThreadedSeedGenerator$BogusThread", "sun.security.provider.SeedGenerator$ThreadedSeedGenerator", "BogusThread", $PRIVATE | $STATIC},
	{"sun.security.provider.SeedGenerator$ThreadedSeedGenerator$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SeedGenerator$ThreadedSeedGenerator_ClassInfo_ = {
	$ACC_SUPER,
	"sun.security.provider.SeedGenerator$ThreadedSeedGenerator",
	"sun.security.provider.SeedGenerator",
	"java.lang.Runnable",
	_SeedGenerator$ThreadedSeedGenerator_FieldInfo_,
	_SeedGenerator$ThreadedSeedGenerator_MethodInfo_,
	nullptr,
	nullptr,
	_SeedGenerator$ThreadedSeedGenerator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.security.provider.SeedGenerator"
};

$Object* allocate$SeedGenerator$ThreadedSeedGenerator($Class* clazz) {
	return $of($alloc(SeedGenerator$ThreadedSeedGenerator));
}

int32_t SeedGenerator$ThreadedSeedGenerator::hashCode() {
	 return this->$SeedGenerator::hashCode();
}

bool SeedGenerator$ThreadedSeedGenerator::equals(Object$* obj) {
	 return this->$SeedGenerator::equals(obj);
}

$Object* SeedGenerator$ThreadedSeedGenerator::clone() {
	 return this->$SeedGenerator::clone();
}

$String* SeedGenerator$ThreadedSeedGenerator::toString() {
	 return this->$SeedGenerator::toString();
}

void SeedGenerator$ThreadedSeedGenerator::finalize() {
	this->$SeedGenerator::finalize();
}

$bytes* SeedGenerator$ThreadedSeedGenerator::rndTab = nullptr;

void SeedGenerator$ThreadedSeedGenerator::init$() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$SeedGenerator::init$();
	$set(this, pool, $new($bytes, 20));
	this->start = (this->end = 0);
	$var($MessageDigest, digest, nullptr);
	try {
		$assign(digest, $MessageDigest::getInstance("SHA"_s));
	} catch ($NoSuchAlgorithmException& e) {
		$throwNew($InternalError, "internal error: SHA-1 not available."_s, e);
	}
	$var($ThreadGroupArray, finalsg, $new($ThreadGroupArray, 1));
	$var($Thread, t, $cast($Thread, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($SeedGenerator$ThreadedSeedGenerator$1, this, finalsg)))));
	$set(this, seedGroup, finalsg->get(0));
	$nc(t)->start();
}

void SeedGenerator$ThreadedSeedGenerator::run() {
	$useLocalCurrentObjectStackCache();
	try {
		while (true) {
			$synchronized(this) {
				while (this->count >= $nc(this->pool)->length) {
					$of(this)->wait();
				}
			}
			int32_t counter = 0;
			int32_t quanta = 0;
			int8_t v = (int8_t)0;
			for (counter = (quanta = 0); (counter < 0x0000FA00) && (quanta < 6); ++quanta) {
				try {
					$var($SeedGenerator$ThreadedSeedGenerator$BogusThread, bt, $new($SeedGenerator$ThreadedSeedGenerator$BogusThread));
					$var($Thread, t, $new($Thread, this->seedGroup, bt, "SeedGenerator Thread"_s, 0, false));
					t->start();
				} catch ($Exception& e) {
					$throwNew($InternalError, "internal error: SeedGenerator thread creation error."_s, e);
				}
				int32_t latch = 0;
				int64_t startTime = $System::nanoTime();
				while ($System::nanoTime() - startTime < 0x0EE6B280) {
					$synchronized(this) {
					}
					latch = (int32_t)((latch + 1) & (uint32_t)0x1FFFFFFF);
				}
				v ^= $nc(SeedGenerator$ThreadedSeedGenerator::rndTab)->get(latch % 255);
				counter += latch;
			}
			$synchronized(this) {
				$nc(this->pool)->set(this->end, v);
				++this->end;
				++this->count;
				if (this->end >= $nc(this->pool)->length) {
					this->end = 0;
				}
				$of(this)->notifyAll();
			}
		}
	} catch ($Exception& e) {
		$throwNew($InternalError, "internal error: SeedGenerator thread generated an exception."_s, e);
	}
}

void SeedGenerator$ThreadedSeedGenerator::getSeedBytes($bytes* result) {
	for (int32_t i = 0; i < $nc(result)->length; ++i) {
		result->set(i, getSeedByte());
	}
}

int8_t SeedGenerator$ThreadedSeedGenerator::getSeedByte() {
	int8_t b = 0;
	try {
		$synchronized(this) {
			while (this->count <= 0) {
				$of(this)->wait();
			}
		}
	} catch ($Exception& e) {
		if (this->count <= 0) {
			$throwNew($InternalError, "internal error: SeedGenerator thread generated an exception."_s, e);
		}
	}
	$synchronized(this) {
		b = $nc(this->pool)->get(this->start);
		$nc(this->pool)->set(this->start, (int8_t)0);
		++this->start;
		--this->count;
		if (this->start == $nc(this->pool)->length) {
			this->start = 0;
		}
		$of(this)->notifyAll();
	}
	return b;
}

void clinit$SeedGenerator$ThreadedSeedGenerator($Class* class$) {
	$assignStatic(SeedGenerator$ThreadedSeedGenerator::rndTab, $new($bytes, {
		(int8_t)56,
		(int8_t)30,
		(int8_t)-107,
		(int8_t)-6,
		(int8_t)-86,
		(int8_t)25,
		(int8_t)-83,
		(int8_t)75,
		(int8_t)-12,
		(int8_t)-64,
		(int8_t)5,
		(int8_t)-128,
		(int8_t)78,
		(int8_t)21,
		(int8_t)16,
		(int8_t)32,
		(int8_t)70,
		(int8_t)-81,
		(int8_t)37,
		(int8_t)-51,
		(int8_t)-43,
		(int8_t)-46,
		(int8_t)-108,
		(int8_t)87,
		(int8_t)29,
		(int8_t)17,
		(int8_t)-55,
		(int8_t)22,
		(int8_t)-11,
		(int8_t)-111,
		(int8_t)-115,
		(int8_t)84,
		(int8_t)-100,
		(int8_t)108,
		(int8_t)-45,
		(int8_t)-15,
		(int8_t)-98,
		(int8_t)72,
		(int8_t)-33,
		(int8_t)-28,
		(int8_t)31,
		(int8_t)-52,
		(int8_t)-37,
		(int8_t)-117,
		(int8_t)-97,
		(int8_t)-27,
		(int8_t)93,
		(int8_t)-123,
		(int8_t)47,
		(int8_t)126,
		(int8_t)-80,
		(int8_t)-62,
		(int8_t)-93,
		(int8_t)-79,
		(int8_t)61,
		(int8_t)-96,
		(int8_t)-65,
		(int8_t)-5,
		(int8_t)-47,
		(int8_t)-119,
		(int8_t)14,
		(int8_t)89,
		(int8_t)81,
		(int8_t)-118,
		(int8_t)-88,
		(int8_t)20,
		(int8_t)67,
		(int8_t)-126,
		(int8_t)-113,
		(int8_t)60,
		(int8_t)-102,
		(int8_t)55,
		(int8_t)110,
		(int8_t)28,
		(int8_t)85,
		(int8_t)121,
		(int8_t)122,
		(int8_t)-58,
		(int8_t)2,
		(int8_t)45,
		(int8_t)43,
		(int8_t)24,
		(int8_t)-9,
		(int8_t)103,
		(int8_t)-13,
		(int8_t)102,
		(int8_t)-68,
		(int8_t)-54,
		(int8_t)-101,
		(int8_t)-104,
		(int8_t)19,
		(int8_t)13,
		(int8_t)-39,
		(int8_t)-26,
		(int8_t)-103,
		(int8_t)62,
		(int8_t)77,
		(int8_t)51,
		(int8_t)44,
		(int8_t)111,
		(int8_t)73,
		(int8_t)18,
		(int8_t)-127,
		(int8_t)-82,
		(int8_t)4,
		(int8_t)-30,
		(int8_t)11,
		(int8_t)-99,
		(int8_t)-74,
		(int8_t)40,
		(int8_t)-89,
		(int8_t)42,
		(int8_t)-76,
		(int8_t)-77,
		(int8_t)-94,
		(int8_t)-35,
		(int8_t)-69,
		(int8_t)35,
		(int8_t)120,
		(int8_t)76,
		(int8_t)33,
		(int8_t)-73,
		(int8_t)-7,
		(int8_t)82,
		(int8_t)-25,
		(int8_t)-10,
		(int8_t)88,
		(int8_t)125,
		(int8_t)-112,
		(int8_t)58,
		(int8_t)83,
		(int8_t)95,
		(int8_t)6,
		(int8_t)10,
		(int8_t)98,
		(int8_t)-34,
		(int8_t)80,
		(int8_t)15,
		(int8_t)-91,
		(int8_t)86,
		(int8_t)-19,
		(int8_t)52,
		(int8_t)-17,
		(int8_t)117,
		(int8_t)49,
		(int8_t)-63,
		(int8_t)118,
		(int8_t)-90,
		(int8_t)36,
		(int8_t)-116,
		(int8_t)-40,
		(int8_t)-71,
		(int8_t)97,
		(int8_t)-53,
		(int8_t)-109,
		(int8_t)-85,
		(int8_t)109,
		(int8_t)-16,
		(int8_t)-3,
		(int8_t)104,
		(int8_t)-95,
		(int8_t)68,
		(int8_t)54,
		(int8_t)34,
		(int8_t)26,
		(int8_t)114,
		(int8_t)-1,
		(int8_t)106,
		(int8_t)-121,
		(int8_t)3,
		(int8_t)66,
		(int8_t)0,
		(int8_t)100,
		(int8_t)-84,
		(int8_t)57,
		(int8_t)107,
		(int8_t)119,
		(int8_t)-42,
		(int8_t)112,
		(int8_t)-61,
		(int8_t)1,
		(int8_t)48,
		(int8_t)38,
		(int8_t)12,
		(int8_t)-56,
		(int8_t)-57,
		(int8_t)39,
		(int8_t)-106,
		(int8_t)-72,
		(int8_t)41,
		(int8_t)7,
		(int8_t)71,
		(int8_t)-29,
		(int8_t)-59,
		(int8_t)-8,
		(int8_t)-38,
		(int8_t)79,
		(int8_t)-31,
		(int8_t)124,
		(int8_t)-124,
		(int8_t)8,
		(int8_t)91,
		(int8_t)116,
		(int8_t)99,
		(int8_t)-4,
		(int8_t)9,
		(int8_t)-36,
		(int8_t)-78,
		(int8_t)63,
		(int8_t)-49,
		(int8_t)-67,
		(int8_t)-87,
		(int8_t)59,
		(int8_t)101,
		(int8_t)-32,
		(int8_t)92,
		(int8_t)94,
		(int8_t)53,
		(int8_t)-41,
		(int8_t)115,
		(int8_t)-66,
		(int8_t)-70,
		(int8_t)-122,
		(int8_t)50,
		(int8_t)-50,
		(int8_t)-22,
		(int8_t)-20,
		(int8_t)-18,
		(int8_t)-21,
		(int8_t)23,
		(int8_t)-2,
		(int8_t)-48,
		(int8_t)96,
		(int8_t)65,
		(int8_t)-105,
		(int8_t)123,
		(int8_t)-14,
		(int8_t)-110,
		(int8_t)69,
		(int8_t)-24,
		(int8_t)-120,
		(int8_t)-75,
		(int8_t)74,
		(int8_t)127,
		(int8_t)-60,
		(int8_t)113,
		(int8_t)90,
		(int8_t)-114,
		(int8_t)105,
		(int8_t)46,
		(int8_t)27,
		(int8_t)-125,
		(int8_t)-23,
		(int8_t)-44,
		(int8_t)64
	}));
}

SeedGenerator$ThreadedSeedGenerator::SeedGenerator$ThreadedSeedGenerator() {
}

$Class* SeedGenerator$ThreadedSeedGenerator::load$($String* name, bool initialize) {
	$loadClass(SeedGenerator$ThreadedSeedGenerator, name, initialize, &_SeedGenerator$ThreadedSeedGenerator_ClassInfo_, clinit$SeedGenerator$ThreadedSeedGenerator, allocate$SeedGenerator$ThreadedSeedGenerator);
	return class$;
}

$Class* SeedGenerator$ThreadedSeedGenerator::class$ = nullptr;

		} // provider
	} // security
} // sun
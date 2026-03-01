#include <TransferTo.h>

#include <TransferTo$1.h>
#include <TransferTo$2.h>
#include <TransferTo$CloseLoggingInputStream.h>
#include <TransferTo$CloseLoggingOutputStream.h>
#include <TransferTo$Thrower.h>
#include <TransferTo$ThrowingInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Arrays.h>
#include <java/util/Random.h>
#include <jcpp.h>

using $TransferTo$1 = ::TransferTo$1;
using $TransferTo$2 = ::TransferTo$2;
using $TransferTo$CloseLoggingInputStream = ::TransferTo$CloseLoggingInputStream;
using $TransferTo$CloseLoggingOutputStream = ::TransferTo$CloseLoggingOutputStream;
using $TransferTo$Thrower = ::TransferTo$Thrower;
using $TransferTo$ThrowingInputStream = ::TransferTo$ThrowingInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $Arrays = ::java::util::Arrays;
using $Random = ::java::util::Random;

class TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0 : public $TransferTo$Thrower {
	$class(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0, $NO_CLASS_INIT, $TransferTo$Thrower)
public:
	void init$($InputStream* in) {
		$set(this, in, in);
	}
	virtual void run() override {
		TransferTo::lambda$ifOutIsNullThenNpeIsThrown$0(in);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0>());
	}
	$InputStream* in = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0::fieldInfos[2] = {
	{"in", "Ljava/io/InputStream;", nullptr, $PUBLIC, $field(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0, in)},
	{}
};
$MethodInfo TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0::methodInfos[3] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0, init$, void, $InputStream*)},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0, run, void)},
	{}
};
$ClassInfo TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0",
	"java.lang.Object",
	"TransferTo$Thrower",
	fieldInfos,
	methodInfos
};
$Class* TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0::load$($String* name, bool initialize) {
	$loadClass(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0::class$ = nullptr;

$MethodInfo _TransferTo_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(TransferTo, init$, void)},
	{"assertThrows", "(LTransferTo$Thrower;Ljava/lang/Class;Ljava/lang/String;)V", "<T:Ljava/lang/Throwable;>(LTransferTo$Thrower;Ljava/lang/Class<TT;>;Ljava/lang/String;)V", $PUBLIC | $STATIC, $staticMethod(TransferTo, assertThrows, void, $TransferTo$Thrower*, $Class*, $String*)},
	{"assertThrowsNPE", "(LTransferTo$Thrower;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(TransferTo, assertThrowsNPE, void, $TransferTo$Thrower*, $String*)},
	{"checkTransferredContents", "([B)V", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, checkTransferredContents, void, $bytes*), "java.io.IOException"},
	{"contents", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, contents, void), "java.io.IOException"},
	{"createRandomBytes", "(II)[B", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, createRandomBytes, $bytes*, int32_t, int32_t)},
	{"ifExceptionInInputNeitherStreamIsClosed", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, ifExceptionInInputNeitherStreamIsClosed, void), "java.io.IOException"},
	{"ifExceptionInOutputNeitherStreamIsClosed", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, ifExceptionInOutputNeitherStreamIsClosed, void), "java.io.IOException"},
	{"ifOutIsNullThenNpeIsThrown", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, ifOutIsNullThenNpeIsThrown, void), "java.io.IOException"},
	{"input", "([B)Ljava/io/InputStream;", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(TransferTo, input, $InputStream*, $bytes*)},
	{"input", "(I[B)Ljava/io/InputStream;", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(TransferTo, input, $InputStream*, int32_t, $bytes*)},
	{"lambda$ifOutIsNullThenNpeIsThrown$0", "(Ljava/io/InputStream;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $staticMethod(TransferTo, lambda$ifOutIsNullThenNpeIsThrown$0, void, $InputStream*), "java.lang.Throwable"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(TransferTo, main, void, $StringArray*), "java.io.IOException"},
	{"onReturnInputIsAtEnd", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, onReturnInputIsAtEnd, void), "java.io.IOException"},
	{"onReturnNeitherStreamIsClosed", "()V", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, onReturnNeitherStreamIsClosed, void), "java.io.IOException"},
	{"output", "()Ljava/io/OutputStream;", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, output, $OutputStream*)},
	{"output", "(I)Ljava/io/OutputStream;", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, output, $OutputStream*, int32_t)},
	{"transferToThenCheckIfAnyClosed", "(Ljava/io/InputStream;Ljava/io/OutputStream;)V", nullptr, $PRIVATE | $STATIC, $staticMethod(TransferTo, transferToThenCheckIfAnyClosed, void, $InputStream*, $OutputStream*), "java.io.IOException"},
	{}
};

$InnerClassInfo _TransferTo_InnerClassesInfo_[] = {
	{"TransferTo$Thrower", "TransferTo", "Thrower", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"TransferTo$CloseLoggingOutputStream", "TransferTo", "CloseLoggingOutputStream", $PRIVATE | $STATIC},
	{"TransferTo$CloseLoggingInputStream", "TransferTo", "CloseLoggingInputStream", $PRIVATE | $STATIC},
	{"TransferTo$ThrowingInputStream", "TransferTo", "ThrowingInputStream", $PRIVATE | $STATIC},
	{"TransferTo$2", nullptr, nullptr, 0},
	{"TransferTo$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _TransferTo_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"TransferTo",
	"java.lang.Object",
	nullptr,
	nullptr,
	_TransferTo_MethodInfo_,
	nullptr,
	nullptr,
	_TransferTo_InnerClassesInfo_,
	nullptr,
	nullptr,
	"TransferTo$Thrower,TransferTo$CloseLoggingOutputStream,TransferTo$CloseLoggingInputStream,TransferTo$ThrowingInputStream,TransferTo$2,TransferTo$1"
};

$Object* allocate$TransferTo($Class* clazz) {
	return $of($alloc(TransferTo));
}

void TransferTo::init$() {
}

void TransferTo::main($StringArray* args) {
	ifOutIsNullThenNpeIsThrown();
	ifExceptionInInputNeitherStreamIsClosed();
	ifExceptionInOutputNeitherStreamIsClosed();
	onReturnNeitherStreamIsClosed();
	onReturnInputIsAtEnd();
	contents();
}

void TransferTo::ifOutIsNullThenNpeIsThrown() {
	$useLocalCurrentObjectStackCache();
	{
		$var($InputStream, in, input($$new($bytes, 0)));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					assertThrowsNPE(static_cast<$TransferTo$Thrower*>($$new(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0, in)), "out"_s);
				} catch ($Throwable& t$) {
					if (in != nullptr) {
						try {
							in->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (in != nullptr) {
					in->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	{
		$var($InputStream, in, input($$new($bytes, {(int8_t)1})));
		{
			$var($Throwable, var$2, nullptr);
			try {
				try {
					assertThrowsNPE(static_cast<$TransferTo$Thrower*>($$new(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0, in)), "out"_s);
				} catch ($Throwable& t$) {
					if (in != nullptr) {
						try {
							in->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$2, var$3);
			} /*finally*/ {
				if (in != nullptr) {
					in->close();
				}
			}
			if (var$2 != nullptr) {
				$throw(var$2);
			}
		}
	}
	{
		$var($InputStream, in, input($$new($bytes, {
			(int8_t)1,
			(int8_t)2
		})));
		{
			$var($Throwable, var$4, nullptr);
			try {
				try {
					assertThrowsNPE(static_cast<$TransferTo$Thrower*>($$new(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0, in)), "out"_s);
				} catch ($Throwable& t$) {
					if (in != nullptr) {
						try {
							in->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$5) {
				$assign(var$4, var$5);
			} /*finally*/ {
				if (in != nullptr) {
					in->close();
				}
			}
			if (var$4 != nullptr) {
				$throw(var$4);
			}
		}
	}
	$var($InputStream, in, nullptr);
	{
		$var($Throwable, var$6, nullptr);
		try {
			$var($InputStream, fin, $assign(in, $new($TransferTo$ThrowingInputStream)));
			assertThrowsNPE(static_cast<$TransferTo$Thrower*>($$new(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0, fin)), "out"_s);
		} catch ($Throwable& var$7) {
			$assign(var$6, var$7);
		} /*finally*/ {
			if (in != nullptr) {
				try {
					in->close();
				} catch ($IOException& ignored) {
				}
			}
		}
		if (var$6 != nullptr) {
			$throw(var$6);
		}
	}
}

void TransferTo::ifExceptionInInputNeitherStreamIsClosed() {
	$useLocalCurrentObjectStackCache();
	$var($InputStream, var$0, input(0, $$new($bytes, {
		(int8_t)1,
		(int8_t)2,
		(int8_t)3
	})));
	transferToThenCheckIfAnyClosed(var$0, $(output()));
	$var($InputStream, var$1, input(1, $$new($bytes, {
		(int8_t)1,
		(int8_t)2,
		(int8_t)3
	})));
	transferToThenCheckIfAnyClosed(var$1, $(output()));
	$var($InputStream, var$2, input(2, $$new($bytes, {
		(int8_t)1,
		(int8_t)2,
		(int8_t)3
	})));
	transferToThenCheckIfAnyClosed(var$2, $(output()));
}

void TransferTo::ifExceptionInOutputNeitherStreamIsClosed() {
	$useLocalCurrentObjectStackCache();
	$var($InputStream, var$0, input($$new($bytes, {
		(int8_t)1,
		(int8_t)2,
		(int8_t)3
	})));
	transferToThenCheckIfAnyClosed(var$0, $(output(0)));
	$var($InputStream, var$1, input($$new($bytes, {
		(int8_t)1,
		(int8_t)2,
		(int8_t)3
	})));
	transferToThenCheckIfAnyClosed(var$1, $(output(1)));
	$var($InputStream, var$2, input($$new($bytes, {
		(int8_t)1,
		(int8_t)2,
		(int8_t)3
	})));
	transferToThenCheckIfAnyClosed(var$2, $(output(2)));
}

void TransferTo::transferToThenCheckIfAnyClosed($InputStream* input, $OutputStream* output) {
	$useLocalCurrentObjectStackCache();
	{
		$var($TransferTo$CloseLoggingInputStream, in, $new($TransferTo$CloseLoggingInputStream, input));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($TransferTo$CloseLoggingOutputStream, out, $new($TransferTo$CloseLoggingOutputStream, output));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								bool thrown = false;
								try {
									in->transferTo(out);
								} catch ($IOException& ignored) {
									thrown = true;
								}
								if (!thrown) {
									$throwNew($AssertionError);
								}
								bool var$2 = in->wasClosed();
								if (var$2 || out->wasClosed()) {
									$throwNew($AssertionError);
								}
							} catch ($Throwable& t$) {
								try {
									out->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$3) {
							$assign(var$1, var$3);
						} /*finally*/ {
							out->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					try {
						in->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$4) {
				$assign(var$0, var$4);
			} /*finally*/ {
				in->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void TransferTo::onReturnNeitherStreamIsClosed() {
	$useLocalCurrentObjectStackCache();
	{
		$var($TransferTo$CloseLoggingInputStream, in, $new($TransferTo$CloseLoggingInputStream, $(input($$new($bytes, {
			(int8_t)1,
			(int8_t)2,
			(int8_t)3
		})))));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($TransferTo$CloseLoggingOutputStream, out, $new($TransferTo$CloseLoggingOutputStream, $(output())));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								in->transferTo(out);
								bool var$2 = in->wasClosed();
								if (var$2 || out->wasClosed()) {
									$throwNew($AssertionError);
								}
							} catch ($Throwable& t$) {
								try {
									out->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$3) {
							$assign(var$1, var$3);
						} /*finally*/ {
							out->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					try {
						in->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$4) {
				$assign(var$0, var$4);
			} /*finally*/ {
				in->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void TransferTo::onReturnInputIsAtEnd() {
	$useLocalCurrentObjectStackCache();
	{
		$var($InputStream, in, input($$new($bytes, {
			(int8_t)1,
			(int8_t)2,
			(int8_t)3
		})));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($OutputStream, out, output());
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								$nc(in)->transferTo(out);
								if (in->read() != -1) {
									$throwNew($AssertionError);
								}
							} catch ($Throwable& t$) {
								if (out != nullptr) {
									try {
										out->close();
									} catch ($Throwable& x2) {
										t$->addSuppressed(x2);
									}
								}
								$throw(t$);
							}
						} catch ($Throwable& var$2) {
							$assign(var$1, var$2);
						} /*finally*/ {
							if (out != nullptr) {
								out->close();
							}
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					if (in != nullptr) {
						try {
							in->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				if (in != nullptr) {
					in->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void TransferTo::contents() {
	$useLocalCurrentObjectStackCache();
	checkTransferredContents($$new($bytes, 0));
	checkTransferredContents($(createRandomBytes(1024, 4096)));
	checkTransferredContents($(createRandomBytes(16384, 16384)));
}

void TransferTo::checkTransferredContents($bytes* bytes) {
	$useLocalCurrentObjectStackCache();
	{
		$var($InputStream, in, input(bytes));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($ByteArrayOutputStream, out, $new($ByteArrayOutputStream));
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								$nc(in)->transferTo(out);
								$var($bytes, outBytes, out->toByteArray());
								if (!$Arrays::equals(bytes, outBytes)) {
									$throwNew($AssertionError, $($of($String::format("bytes.length=%s, outBytes.length=%s"_s, $$new($ObjectArray, {
										$($of($Integer::valueOf($nc(bytes)->length))),
										$($of($Integer::valueOf($nc(outBytes)->length)))
									})))));
								}
							} catch ($Throwable& t$) {
								try {
									out->close();
								} catch ($Throwable& x2) {
									t$->addSuppressed(x2);
								}
								$throw(t$);
							}
						} catch ($Throwable& var$2) {
							$assign(var$1, var$2);
						} /*finally*/ {
							out->close();
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					if (in != nullptr) {
						try {
							in->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$3) {
				$assign(var$0, var$3);
			} /*finally*/ {
				if (in != nullptr) {
					in->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

$bytes* TransferTo::createRandomBytes(int32_t min, int32_t maxRandomAdditive) {
	$useLocalCurrentObjectStackCache();
	$var($Random, rnd, $new($Random));
	$var($bytes, bytes, $new($bytes, min + rnd->nextInt(maxRandomAdditive)));
	rnd->nextBytes(bytes);
	return bytes;
}

$OutputStream* TransferTo::output() {
	return output(-1);
}

$OutputStream* TransferTo::output(int32_t exceptionPosition) {
	return $new($TransferTo$1, exceptionPosition);
}

$InputStream* TransferTo::input($bytes* bytes) {
	return input(-1, bytes);
}

$InputStream* TransferTo::input(int32_t exceptionPosition, $bytes* bytes) {
	return $new($TransferTo$2, exceptionPosition, bytes);
}

void TransferTo::assertThrowsNPE($TransferTo$Thrower* thrower, $String* message) {
	$load($NullPointerException);
	assertThrows(thrower, $NullPointerException::class$, message);
}

void TransferTo::assertThrows($TransferTo$Thrower* thrower, $Class* throwable, $String* message) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, thrown, nullptr);
	try {
		$nc(thrower)->run();
		$assign(thrown, nullptr);
	} catch ($Throwable& caught) {
		$assign(thrown, caught);
	}
	if (!$nc(throwable)->isInstance(thrown)) {
		$var($String, caught, thrown == nullptr ? "nothing"_s : $nc($of(thrown))->getClass()->getCanonicalName());
		$throwNew($AssertionError, $($String::format("Expected to catch %s, but caught %s"_s, $$new($ObjectArray, {
			$of(throwable),
			$of(caught)
		}))), thrown);
	}
	if (thrown != nullptr && !$nc(message)->equals($(thrown->getMessage()))) {
		$throwNew($AssertionError, $($of($String::format("Expected exception message to be \'%s\', but it\'s \'%s\'"_s, $$new($ObjectArray, {
			$of(message),
			$($of(thrown->getMessage()))
		})))));
	}
}

void TransferTo::lambda$ifOutIsNullThenNpeIsThrown$0($InputStream* in) {
	$nc(in)->transferTo(nullptr);
}

TransferTo::TransferTo() {
}

$Class* TransferTo::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0::classInfo$.name)) {
			return TransferTo$$Lambda$lambda$ifOutIsNullThenNpeIsThrown$0::load$(name, initialize);
		}
	}
	$loadClass(TransferTo, name, initialize, &_TransferTo_ClassInfo_, allocate$TransferTo);
	return class$;
}

$Class* TransferTo::class$ = nullptr;
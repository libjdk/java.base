#include <Encode.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/BufferedReader.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/lang/Runnable.h>
#include <java/net/HttpURLConnection.h>
#include <java/net/ServerSocket.h>
#include <java/net/Socket.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/URLEncoder.h>
#include <jcpp.h>

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $BufferedReader = ::java::io::BufferedReader;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $HttpURLConnection = ::java::net::HttpURLConnection;
using $ServerSocket = ::java::net::ServerSocket;
using $Socket = ::java::net::Socket;
using $URL = ::java::net::URL;
using $URLEncoder = ::java::net::URLEncoder;

$FieldInfo _Encode_FieldInfo_[] = {
	{"ss", "Ljava/net/ServerSocket;", nullptr, $FINAL, $field(Encode, ss)},
	{}
};

$MethodInfo _Encode_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(Encode, init$, void), "java.lang.Exception"},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Encode, main, void, $StringArray*), "java.lang.Exception"},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(Encode, run, void)},
	{}
};

$ClassInfo _Encode_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Encode",
	"java.lang.Object",
	"java.lang.Runnable",
	_Encode_FieldInfo_,
	_Encode_MethodInfo_
};

$Object* allocate$Encode($Class* clazz) {
	return $of($alloc(Encode));
}

void Encode::main($StringArray* args) {
	$init(Encode);
	$new(Encode);
}

void Encode::init$() {
	$useLocalCurrentObjectStackCache();
	$set(this, ss, $new($ServerSocket, 0));
	($$new($Thread, static_cast<$Runnable*>(this)))->start();
	$var($String, toEncode, $cstr({0x10000, ' ', 0x10401, ' '}));
	$var($String, enc1, $URLEncoder::encode(toEncode, "UTF-8"_s));
	$var($bytes, bytes, $new($bytes, 0));
	$var($ByteArrayInputStream, bais, $new($ByteArrayInputStream, bytes));
	$var($InputStreamReader, reader, $new($InputStreamReader, static_cast<$InputStream*>(bais), "8859_1"_s));
	$var($String, url, $str({"http://localhost:"_s, $($Integer::toString($nc(this->ss)->getLocalPort())), "/missing.nothtml"_s}));
	$var($HttpURLConnection, uc, $cast($HttpURLConnection, $$new($URL, url)->openConnection()));
	$nc(uc)->connect();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($String, enc2, $URLEncoder::encode(toEncode, "UTF-8"_s));
			if (!$nc(enc1)->equals(enc2)) {
				$nc($System::out)->println("test failed"_s);
				$throwNew($RuntimeException, "test failed"_s);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			uc->disconnect();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Encode::run() {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ServerSocket, serv, this->ss);
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($Socket, s, $nc(serv)->accept());
					{
						$var($Throwable, var$1, nullptr);
						try {
							try {
								$var($BufferedReader, in, $new($BufferedReader, $$new($InputStreamReader, $($nc(s)->getInputStream()))));
								{
									$var($Throwable, var$2, nullptr);
									try {
										try {
											$var($String, req, in->readLine());
											{
												$var($OutputStream, os, $nc(s)->getOutputStream());
												{
													$var($Throwable, var$3, nullptr);
													try {
														try {
															$var($BufferedOutputStream, bos, $new($BufferedOutputStream, os));
															{
																$var($Throwable, var$4, nullptr);
																try {
																	try {
																		$var($PrintStream, out, $new($PrintStream, static_cast<$OutputStream*>(bos)));
																		{
																			$var($Throwable, var$5, nullptr);
																			try {
																				try {
																					out->print("HTTP/1.1 403 Forbidden\r\n"_s);
																					out->print("\r\n"_s);
																				} catch ($Throwable& t$) {
																					try {
																						out->close();
																					} catch ($Throwable& x2) {
																						t$->addSuppressed(x2);
																					}
																					$throw(t$);
																				}
																			} catch ($Throwable& var$6) {
																				$assign(var$5, var$6);
																			} /*finally*/ {
																				out->close();
																			}
																			if (var$5 != nullptr) {
																				$throw(var$5);
																			}
																		}
																	} catch ($Throwable& t$) {
																		try {
																			bos->close();
																		} catch ($Throwable& x2) {
																			t$->addSuppressed(x2);
																		}
																		$throw(t$);
																	}
																} catch ($Throwable& var$7) {
																	$assign(var$4, var$7);
																} /*finally*/ {
																	bos->close();
																}
																if (var$4 != nullptr) {
																	$throw(var$4);
																}
															}
														} catch ($Throwable& t$) {
															if (os != nullptr) {
																try {
																	os->close();
																} catch ($Throwable& x2) {
																	t$->addSuppressed(x2);
																}
															}
															$throw(t$);
														}
													} catch ($Throwable& var$8) {
														$assign(var$3, var$8);
													} /*finally*/ {
														if (os != nullptr) {
															os->close();
														}
													}
													if (var$3 != nullptr) {
														$throw(var$3);
													}
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
									} catch ($Throwable& var$9) {
										$assign(var$2, var$9);
									} /*finally*/ {
										in->close();
									}
									if (var$2 != nullptr) {
										$throw(var$2);
									}
								}
							} catch ($Throwable& t$) {
								if (s != nullptr) {
									try {
										s->close();
									} catch ($Throwable& x2) {
										t$->addSuppressed(x2);
									}
								}
								$throw(t$);
							}
						} catch ($Throwable& var$10) {
							$assign(var$1, var$10);
						} /*finally*/ {
							if (s != nullptr) {
								s->close();
							}
						}
						if (var$1 != nullptr) {
							$throw(var$1);
						}
					}
				} catch ($Throwable& t$) {
					if (serv != nullptr) {
						try {
							serv->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$11) {
				$assign(var$0, var$11);
			} /*finally*/ {
				if (serv != nullptr) {
					serv->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($Exception& e) {
		e->printStackTrace();
	}
}

Encode::Encode() {
}

$Class* Encode::load$($String* name, bool initialize) {
	$loadClass(Encode, name, initialize, &_Encode_ClassInfo_, allocate$Encode);
	return class$;
}

$Class* Encode::class$ = nullptr;
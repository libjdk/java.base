#include <SocksServer$ClientHandler.h>

#include <SocksServer$ClientHandler$Tunnel.h>
#include <SocksServer.h>
#include <java/io/BufferedInputStream.h>
#include <java/io/BufferedOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/net/ConnectException.h>
#include <java/net/Inet4Address.h>
#include <java/net/Inet6Address.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/ServerSocket.h>
#include <java/net/Socket.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/SocketTimeoutException.h>
#include <java/util/HashMap.h>
#include <jcpp.h>

using $SocksServer = ::SocksServer;
using $SocksServer$ClientHandler$Tunnel = ::SocksServer$ClientHandler$Tunnel;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ConnectException = ::java::net::ConnectException;
using $Inet4Address = ::java::net::Inet4Address;
using $Inet6Address = ::java::net::Inet6Address;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ServerSocket = ::java::net::ServerSocket;
using $Socket = ::java::net::Socket;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketException = ::java::net::SocketException;
using $SocketTimeoutException = ::java::net::SocketTimeoutException;
using $HashMap = ::java::util::HashMap;

$FieldInfo _SocksServer$ClientHandler_FieldInfo_[] = {
	{"this$0", "LSocksServer;", nullptr, $FINAL | $SYNTHETIC, $field(SocksServer$ClientHandler, this$0)},
	{"in", "Ljava/io/InputStream;", nullptr, $PRIVATE, $field(SocksServer$ClientHandler, in)},
	{"out", "Ljava/io/OutputStream;", nullptr, $PRIVATE, $field(SocksServer$ClientHandler, out)},
	{"client", "Ljava/net/Socket;", nullptr, $PRIVATE, $field(SocksServer$ClientHandler, client)},
	{"dest", "Ljava/net/Socket;", nullptr, $PRIVATE, $field(SocksServer$ClientHandler, dest)},
	{}
};

$MethodInfo _SocksServer$ClientHandler_MethodInfo_[] = {
	{"<init>", "(LSocksServer;Ljava/net/Socket;)V", nullptr, 0, $method(SocksServer$ClientHandler, init$, void, $SocksServer*, $Socket*), "java.io.IOException"},
	{"doBind", "(Ljava/net/InetSocketAddress;)V", nullptr, $PRIVATE, $method(SocksServer$ClientHandler, doBind, void, $InetSocketAddress*), "java.io.IOException"},
	{"doConnect", "(Ljava/net/InetSocketAddress;)V", nullptr, $PRIVATE, $method(SocksServer$ClientHandler, doConnect, void, $InetSocketAddress*), "java.io.IOException"},
	{"getRequest", "()V", nullptr, $PRIVATE, $method(SocksServer$ClientHandler, getRequest, void), "java.io.IOException"},
	{"getRequestV4", "()V", nullptr, $PRIVATE, $method(SocksServer$ClientHandler, getRequestV4, void), "java.io.IOException"},
	{"negociate", "()V", nullptr, $PRIVATE, $method(SocksServer$ClientHandler, negociate, void), "java.io.IOException"},
	{"purge", "()V", nullptr, $PRIVATE, $method(SocksServer$ClientHandler, purge, void), "java.io.IOException"},
	{"readBuf", "(Ljava/io/InputStream;[B)V", nullptr, $PRIVATE, $method(SocksServer$ClientHandler, readBuf, void, $InputStream*, $bytes*), "java.io.IOException"},
	{"run", "()V", nullptr, $PUBLIC, $virtualMethod(SocksServer$ClientHandler, run, void)},
	{"sendError", "(I)V", nullptr, $PRIVATE, $method(SocksServer$ClientHandler, sendError, void, int32_t)},
	{"userPassAuth", "()Z", nullptr, $PRIVATE, $method(SocksServer$ClientHandler, userPassAuth, bool), "java.io.IOException"},
	{}
};

$InnerClassInfo _SocksServer$ClientHandler_InnerClassesInfo_[] = {
	{"SocksServer$ClientHandler", "SocksServer", "ClientHandler", 0},
	{"SocksServer$ClientHandler$Tunnel", "SocksServer$ClientHandler", "Tunnel", 0},
	{}
};

$ClassInfo _SocksServer$ClientHandler_ClassInfo_ = {
	$ACC_SUPER,
	"SocksServer$ClientHandler",
	"java.lang.Thread",
	nullptr,
	_SocksServer$ClientHandler_FieldInfo_,
	_SocksServer$ClientHandler_MethodInfo_,
	nullptr,
	nullptr,
	_SocksServer$ClientHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"SocksServer"
};

$Object* allocate$SocksServer$ClientHandler($Class* clazz) {
	return $of($alloc(SocksServer$ClientHandler));
}

void SocksServer$ClientHandler::init$($SocksServer* this$0, $Socket* s) {
	$useLocalCurrentObjectStackCache();
	$set(this, this$0, this$0);
	$Thread::init$();
	$set(this, client, s);
	$set(this, in, $new($BufferedInputStream, $($nc(this->client)->getInputStream())));
	$set(this, out, $new($BufferedOutputStream, $($nc(this->client)->getOutputStream())));
}

void SocksServer$ClientHandler::readBuf($InputStream* is, $bytes* buf) {
	int32_t l = $nc(buf)->length;
	int32_t count = 0;
	int32_t i = 0;
	do {
		i = $nc(is)->read(buf, count, l - count);
		if (i == -1) {
			$throwNew($IOException, "unexpected EOF"_s);
		}
		count += i;
	} while (count < l);
}

bool SocksServer$ClientHandler::userPassAuth() {
	$useLocalCurrentObjectStackCache();
	int32_t ver = $nc(this->in)->read();
	int32_t ulen = $nc(this->in)->read();
	if (ulen <= 0) {
		$throwNew($SocketException, "SOCKS protocol error"_s);
	}
	$var($bytes, buf, $new($bytes, ulen));
	readBuf(this->in, buf);
	$var($String, uname, $new($String, buf));
	$var($String, password, nullptr);
	ulen = $nc(this->in)->read();
	if (ulen < 0) {
		$throwNew($SocketException, "SOCKS protocol error"_s);
	}
	if (ulen > 0) {
		$assign(buf, $new($bytes, ulen));
		readBuf(this->in, buf);
		$assign(password, $new($String, buf));
	}
	$nc($System::err)->println($$str({"User: \'"_s, uname}));
	$nc($System::err)->println($$str({"PSWD: \'"_s, password}));
	if ($nc(this->this$0->users)->containsKey(uname)) {
		$var($String, p1, $cast($String, $nc(this->this$0->users)->get(uname)));
		$nc($System::err)->println($$str({"p1 = "_s, p1}));
		if ($nc(p1)->equals(password)) {
			$nc(this->out)->write(5);
			$nc(this->out)->write(0);
			$nc(this->out)->flush();
			return true;
		}
	}
	$nc(this->out)->write(5);
	$nc(this->out)->write(2);
	$nc(this->out)->flush();
	return false;
}

void SocksServer$ClientHandler::purge() {
	bool done = false;
	int32_t i = 0;
	$nc(this->client)->setSoTimeout(1000);
	while (!done && i != -1) {
		try {
			i = $nc(this->in)->read();
		} catch ($IOException& e) {
			done = true;
		}
	}
}

void SocksServer$ClientHandler::getRequestV4() {
	$useLocalCurrentObjectStackCache();
	int32_t ver = $nc(this->in)->read();
	int32_t cmd = $nc(this->in)->read();
	if (ver == -1 || cmd == -1) {
		$nc(this->in)->close();
		$nc(this->out)->close();
		return;
	}
	if (ver != 0 && ver != 4) {
		$nc(this->out)->write(4);
		$nc(this->out)->write(91);
		$nc(this->out)->write(0);
		$nc(this->out)->write(0);
		$nc(this->out)->write(0);
		$nc(this->out)->write(0);
		$nc(this->out)->write(0);
		$nc(this->out)->write(0);
		$nc(this->out)->write(0);
		$nc(this->out)->flush();
		purge();
		$nc(this->out)->close();
		$nc(this->in)->close();
		return;
	}
	if (cmd == 1) {
		int32_t port = (((int32_t)($nc(this->in)->read() & (uint32_t)255)) << 8);
		port += ((int32_t)($nc(this->in)->read() & (uint32_t)255));
		$var($bytes, buf, $new($bytes, 4));
		readBuf(this->in, buf);
		$var($InetAddress, addr, $InetAddress::getByAddress(buf));
		int32_t c = 0;
		do {
			c = ((int32_t)($nc(this->in)->read() & (uint32_t)255));
		} while (c != 0);
		bool ok = true;
		try {
			$set(this, dest, $new($Socket, addr, port));
		} catch ($IOException& e) {
			ok = false;
		}
		if (!ok) {
			$nc(this->out)->write(4);
			$nc(this->out)->write(91);
			$nc(this->out)->write(0);
			$nc(this->out)->write(0);
			$nc(this->out)->write(buf);
			$nc(this->out)->flush();
			purge();
			$nc(this->out)->close();
			$nc(this->in)->close();
			return;
		}
		$nc(this->out)->write(4);
		$nc(this->out)->write(90);
		$nc(this->out)->write((int32_t)((port >> 8) & (uint32_t)255));
		$nc(this->out)->write((int32_t)(port & (uint32_t)255));
		$nc(this->out)->write(buf);
		$nc(this->out)->flush();
		$var($InputStream, in2, $new($BufferedInputStream, $($nc(this->dest)->getInputStream())));
		$var($OutputStream, out2, $new($BufferedOutputStream, $($nc(this->dest)->getOutputStream())));
		$var($SocksServer$ClientHandler$Tunnel, tunnel, $new($SocksServer$ClientHandler$Tunnel, this, in2, this->out));
		tunnel->start();
		int32_t b = 0;
		do {
			try {
				b = $nc(this->in)->read();
				if (b == -1) {
					$nc(this->in)->close();
					out2->close();
					return;
				}
				out2->write(b);
				out2->flush();
			} catch ($IOException& ex) {
			}
		} while (!$nc(this->client)->isClosed());
	}
}

void SocksServer$ClientHandler::negociate() {
	int32_t ver = $nc(this->in)->read();
	int32_t n = $nc(this->in)->read();
	$var($bytes, buf, nullptr);
	if (n > 0) {
		$assign(buf, $new($bytes, n));
		readBuf(this->in, buf);
	}
	int32_t scheme = 0;
	for (int32_t i = 0; i < n; ++i) {
		if ($nc(buf)->get(i) == 2) {
			scheme = 2;
		}
	}
	$nc(this->out)->write(5);
	$nc(this->out)->write(scheme);
	$nc(this->out)->flush();
	if (scheme == 2) {
		userPassAuth();
	}
}

void SocksServer$ClientHandler::sendError(int32_t code) {
	try {
		$nc(this->out)->write(5);
		$nc(this->out)->write(code);
		$nc(this->out)->write(0);
		$nc(this->out)->write(1);
		for (int32_t i = 0; i < 6; ++i) {
			$nc(this->out)->write(0);
		}
		$nc(this->out)->flush();
		$nc(this->out)->close();
	} catch ($IOException& ex) {
	}
}

void SocksServer$ClientHandler::doConnect($InetSocketAddress* addr) {
	$useLocalCurrentObjectStackCache();
	$set(this, dest, $new($Socket));
	try {
		$nc(this->dest)->connect(addr, 10000);
	} catch ($SocketTimeoutException& ex) {
		sendError(4);
		return;
	} catch ($ConnectException& cex) {
		sendError(5);
		return;
	}
	$var($InetAddress, iadd, $nc(addr)->getAddress());
	if ($instanceOf($Inet4Address, iadd)) {
		$nc(this->out)->write(5);
		$nc(this->out)->write(0);
		$nc(this->out)->write(0);
		$nc(this->out)->write(1);
		$nc(this->out)->write($($nc(iadd)->getAddress()));
	} else if ($instanceOf($Inet6Address, iadd)) {
		$nc(this->out)->write(5);
		$nc(this->out)->write(0);
		$nc(this->out)->write(0);
		$nc(this->out)->write(4);
		$nc(this->out)->write($($nc(iadd)->getAddress()));
	} else {
		sendError(1);
		return;
	}
	$nc(this->out)->write((int32_t)((addr->getPort() >> 8) & (uint32_t)255));
	$nc(this->out)->write((int32_t)((addr->getPort() >> 0) & (uint32_t)255));
	$nc(this->out)->flush();
	$var($InputStream, in2, $new($BufferedInputStream, $($nc(this->dest)->getInputStream())));
	$var($OutputStream, out2, $new($BufferedOutputStream, $($nc(this->dest)->getOutputStream())));
	$var($SocksServer$ClientHandler$Tunnel, tunnel, $new($SocksServer$ClientHandler$Tunnel, this, in2, this->out));
	tunnel->start();
	int32_t b = 0;
	do {
		try {
			b = $nc(this->in)->read();
			if (b == -1) {
				$nc(this->in)->close();
				out2->close();
				return;
			}
			out2->write(b);
			out2->flush();
		} catch ($IOException& ioe) {
		}
	} while (!$nc(this->client)->isClosed());
}

void SocksServer$ClientHandler::doBind($InetSocketAddress* addr) {
	$useLocalCurrentObjectStackCache();
	$var($ServerSocket, svr, $new($ServerSocket));
	svr->bind(nullptr);
	$var($InetSocketAddress, bad, $cast($InetSocketAddress, svr->getLocalSocketAddress()));
	$nc(this->out)->write(5);
	$nc(this->out)->write(0);
	$nc(this->out)->write(0);
	$nc(this->out)->write(1);
	$nc(this->out)->write($($nc($($nc(bad)->getAddress()))->getAddress()));
	$nc(this->out)->write((int32_t)(($nc(bad)->getPort() >> 8) & (uint32_t)255));
	$nc(this->out)->write(((int32_t)($nc(bad)->getPort() & (uint32_t)255)));
	$nc(this->out)->flush();
	$set(this, dest, svr->accept());
	$assign(bad, $cast($InetSocketAddress, $nc(this->dest)->getRemoteSocketAddress()));
	$nc(this->out)->write(5);
	$nc(this->out)->write(0);
	$nc(this->out)->write(0);
	$nc(this->out)->write(1);
	$nc(this->out)->write($($nc($($nc(bad)->getAddress()))->getAddress()));
	$nc(this->out)->write((int32_t)(($nc(bad)->getPort() >> 8) & (uint32_t)255));
	$nc(this->out)->write(((int32_t)($nc(bad)->getPort() & (uint32_t)255)));
	$nc(this->out)->flush();
	$var($InputStream, in2, $nc(this->dest)->getInputStream());
	$var($OutputStream, out2, $nc(this->dest)->getOutputStream());
	$var($SocksServer$ClientHandler$Tunnel, tunnel, $new($SocksServer$ClientHandler$Tunnel, this, in2, this->out));
	tunnel->start();
	int32_t b = 0;
	do {
		try {
			b = $nc(this->in)->read();
			if (b == -1) {
				$nc(this->in)->close();
				$nc(out2)->close();
				return;
			}
			$nc(out2)->write(b);
			out2->flush();
		} catch ($IOException& ioe) {
		}
	} while (!$nc(this->client)->isClosed());
}

void SocksServer$ClientHandler::getRequest() {
	$useLocalCurrentObjectStackCache();
	int32_t ver = $nc(this->in)->read();
	int32_t cmd = $nc(this->in)->read();
	if (ver == -1 || cmd == -1) {
		$nc(this->in)->close();
		$nc(this->out)->close();
		return;
	}
	int32_t rsv = $nc(this->in)->read();
	int32_t atyp = $nc(this->in)->read();
	$var($String, addr, nullptr);
	int32_t port = 0;
	switch (atyp) {
	case 1:
		{
			{
				$var($bytes, buf, $new($bytes, 4));
				readBuf(this->in, buf);
				$assign(addr, $nc($($InetAddress::getByAddress(buf)))->getHostAddress());
			}
			break;
		}
	case 3:
		{
			{
				int32_t i = $nc(this->in)->read();
				$var($bytes, buf, $new($bytes, i));
				readBuf(this->in, buf);
				$assign(addr, $new($String, buf));
			}
			break;
		}
	case 4:
		{
			{
				$var($bytes, buf, $new($bytes, 16));
				readBuf(this->in, buf);
				$assign(addr, $nc($($InetAddress::getByAddress(buf)))->getHostAddress());
			}
			break;
		}
	}
	port = (((int32_t)($nc(this->in)->read() & (uint32_t)255)) << 8);
	port += ((int32_t)($nc(this->in)->read() & (uint32_t)255));
	$var($InetSocketAddress, socAddr, $new($InetSocketAddress, addr, port));
	switch (cmd) {
	case 1:
		{
			doConnect(socAddr);
			break;
		}
	case 2:
		{
			doBind(socAddr);
			break;
		}
	case 3:
		{
			break;
		}
	}
}

void SocksServer$ClientHandler::run() {
	$useLocalCurrentObjectStackCache();
	$var($String, line, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				if (this->this$0->useV4) {
					getRequestV4();
				} else {
					negociate();
					getRequest();
				}
			} catch ($IOException& ex) {
				try {
					sendError(1);
				} catch ($Exception& e) {
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			try {
				$nc(this->client)->close();
			} catch ($IOException& e2) {
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

SocksServer$ClientHandler::SocksServer$ClientHandler() {
}

$Class* SocksServer$ClientHandler::load$($String* name, bool initialize) {
	$loadClass(SocksServer$ClientHandler, name, initialize, &_SocksServer$ClientHandler_ClassInfo_, allocate$SocksServer$ClientHandler);
	return class$;
}

$Class* SocksServer$ClientHandler::class$ = nullptr;
#include <sun/net/www/protocol/mailto/MailToURLConnection.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/lang/SecurityManager.h>
#include <java/net/InetAddress.h>
#include <java/net/SocketPermission.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/UnknownHostException.h>
#include <java/security/Permission.h>
#include <jdk/internal/util/StaticProperty.h>
#include <sun/net/NetworkClient.h>
#include <sun/net/smtp/SmtpClient.h>
#include <sun/net/www/MessageHeader.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/net/www/URLConnection.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $InetAddress = ::java::net::InetAddress;
using $SocketPermission = ::java::net::SocketPermission;
using $URL = ::java::net::URL;
using $UnknownHostException = ::java::net::UnknownHostException;
using $Permission = ::java::security::Permission;
using $StaticProperty = ::jdk::internal::util::StaticProperty;
using $SmtpClient = ::sun::net::smtp::SmtpClient;
using $MessageHeader = ::sun::net::www::MessageHeader;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $URLConnection = ::sun::net::www::URLConnection;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace mailto {

$FieldInfo _MailToURLConnection_FieldInfo_[] = {
	{"is", "Ljava/io/InputStream;", nullptr, 0, $field(MailToURLConnection, is)},
	{"os", "Ljava/io/OutputStream;", nullptr, 0, $field(MailToURLConnection, os)},
	{"client", "Lsun/net/smtp/SmtpClient;", nullptr, 0, $field(MailToURLConnection, client)},
	{"permission", "Ljava/security/Permission;", nullptr, 0, $field(MailToURLConnection, permission)},
	{"connectTimeout", "I", nullptr, $PRIVATE, $field(MailToURLConnection, connectTimeout)},
	{"readTimeout", "I", nullptr, $PRIVATE, $field(MailToURLConnection, readTimeout)},
	{}
};

$MethodInfo _MailToURLConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URL;)V", nullptr, 0, $method(MailToURLConnection, init$, void, $URL*)},
	{"connect", "()V", nullptr, $PUBLIC, $virtualMethod(MailToURLConnection, connect, void), "java.io.IOException"},
	{"getConnectTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(MailToURLConnection, getConnectTimeout, int32_t)},
	{"getFromAddress", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(MailToURLConnection, getFromAddress, $String*)},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(MailToURLConnection, getOutputStream, $OutputStream*), "java.io.IOException"},
	{"getPermission", "()Ljava/security/Permission;", nullptr, $PUBLIC, $virtualMethod(MailToURLConnection, getPermission, $Permission*), "java.io.IOException"},
	{"getReadTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(MailToURLConnection, getReadTimeout, int32_t)},
	{"setConnectTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(MailToURLConnection, setConnectTimeout, void, int32_t)},
	{"setReadTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(MailToURLConnection, setReadTimeout, void, int32_t)},
	{}
};

$ClassInfo _MailToURLConnection_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.mailto.MailToURLConnection",
	"sun.net.www.URLConnection",
	nullptr,
	_MailToURLConnection_FieldInfo_,
	_MailToURLConnection_MethodInfo_
};

$Object* allocate$MailToURLConnection($Class* clazz) {
	return $of($alloc(MailToURLConnection));
}

void MailToURLConnection::init$($URL* u) {
	$URLConnection::init$(u);
	$set(this, is, nullptr);
	$set(this, os, nullptr);
	this->connectTimeout = -1;
	this->readTimeout = -1;
	$var($MessageHeader, props, $new($MessageHeader));
	props->add("content-type"_s, "text/html"_s);
	setProperties(props);
}

$String* MailToURLConnection::getFromAddress() {
	$useLocalCurrentObjectStackCache();
	$var($String, str, $System::getProperty("user.fromaddr"_s));
	if (str == nullptr) {
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			sm->checkPropertyAccess("user.name"_s);
		}
		$assign(str, $StaticProperty::userName());
		if (str != nullptr) {
			$var($String, host, $System::getProperty("mail.host"_s));
			if (host == nullptr) {
				try {
					$assign(host, $nc($($InetAddress::getLocalHost()))->getHostName());
				} catch ($UnknownHostException& e) {
				}
			}
			$plusAssign(str, $$str({"@"_s, host}));
		} else {
			$assign(str, ""_s);
		}
	}
	return str;
}

void MailToURLConnection::connect() {
	$set(this, client, $new($SmtpClient, this->connectTimeout));
	$nc(this->client)->setReadTimeout(this->readTimeout);
}

$OutputStream* MailToURLConnection::getOutputStream() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->os != nullptr) {
			return this->os;
		} else if (this->is != nullptr) {
			$throwNew($IOException, "Cannot write output after reading input."_s);
		}
		connect();
		$var($String, to, $ParseUtil::decode($($nc(this->url)->getPath())));
		$nc(this->client)->from($(getFromAddress()));
		$nc(this->client)->to(to);
		$set(this, os, $nc(this->client)->startMessage());
		return this->os;
	}
}

$Permission* MailToURLConnection::getPermission() {
	$useLocalCurrentObjectStackCache();
	if (this->permission == nullptr) {
		connect();
		$var($String, host, $str({$($nc(this->client)->getMailHost()), ":"_s, $$str(25)}));
		$set(this, permission, $new($SocketPermission, host, "connect"_s));
	}
	return this->permission;
}

void MailToURLConnection::setConnectTimeout(int32_t timeout) {
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "timeouts can\'t be negative"_s);
	}
	this->connectTimeout = timeout;
}

int32_t MailToURLConnection::getConnectTimeout() {
	return (this->connectTimeout < 0 ? 0 : this->connectTimeout);
}

void MailToURLConnection::setReadTimeout(int32_t timeout) {
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "timeouts can\'t be negative"_s);
	}
	this->readTimeout = timeout;
}

int32_t MailToURLConnection::getReadTimeout() {
	return this->readTimeout < 0 ? 0 : this->readTimeout;
}

MailToURLConnection::MailToURLConnection() {
}

$Class* MailToURLConnection::load$($String* name, bool initialize) {
	$loadClass(MailToURLConnection, name, initialize, &_MailToURLConnection_ClassInfo_, allocate$MailToURLConnection);
	return class$;
}

$Class* MailToURLConnection::class$ = nullptr;

				} // mailto
			} // protocol
		} // www
	} // net
} // sun
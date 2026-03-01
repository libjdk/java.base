#include <sun/net/www/protocol/ftp/FtpURLConnection.h>

#include <java/io/FileNotFoundException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/MalformedURLException.h>
#include <java/net/Proxy$Type.h>
#include <java/net/Proxy.h>
#include <java/net/ProxySelector.h>
#include <java/net/SocketAddress.h>
#include <java/net/SocketPermission.h>
#include <java/net/URI.h>
#include <java/net/URL.h>
#include <java/net/URLConnection.h>
#include <java/net/UnknownHostException.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Properties.h>
#include <java/util/StringTokenizer.h>
#include <sun/net/NetworkClient.h>
#include <sun/net/ProgressMonitor.h>
#include <sun/net/ProgressSource.h>
#include <sun/net/ftp/FtpClient.h>
#include <sun/net/ftp/FtpLoginException.h>
#include <sun/net/ftp/FtpProtocolException.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/net/www/MessageHeader.h>
#include <sun/net/www/MeteredStream.h>
#include <sun/net/www/ParseUtil.h>
#include <sun/net/www/URLConnection.h>
#include <sun/net/www/protocol/ftp/FtpURLConnection$1.h>
#include <sun/net/www/protocol/ftp/FtpURLConnection$FtpInputStream.h>
#include <sun/net/www/protocol/ftp/FtpURLConnection$FtpOutputStream.h>
#include <sun/net/www/protocol/http/HttpURLConnection.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef ASCII
#undef BIN
#undef DEFAULT_CONNECT_TIMEOUT
#undef DEFAULT_READ_TIMEOUT
#undef DIR
#undef HTTP
#undef NONE
#undef NO_PROXY
#undef SOCKS

using $FileNotFoundException = ::java::io::FileNotFoundException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $MalformedURLException = ::java::net::MalformedURLException;
using $Proxy = ::java::net::Proxy;
using $Proxy$Type = ::java::net::Proxy$Type;
using $ProxySelector = ::java::net::ProxySelector;
using $SocketAddress = ::java::net::SocketAddress;
using $SocketPermission = ::java::net::SocketPermission;
using $URI = ::java::net::URI;
using $URL = ::java::net::URL;
using $UnknownHostException = ::java::net::UnknownHostException;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Properties = ::java::util::Properties;
using $StringTokenizer = ::java::util::StringTokenizer;
using $NetworkClient = ::sun::net::NetworkClient;
using $ProgressMonitor = ::sun::net::ProgressMonitor;
using $ProgressSource = ::sun::net::ProgressSource;
using $FtpClient = ::sun::net::ftp::FtpClient;
using $FtpLoginException = ::sun::net::ftp::FtpLoginException;
using $FtpProtocolException = ::sun::net::ftp::FtpProtocolException;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $MessageHeader = ::sun::net::www::MessageHeader;
using $MeteredStream = ::sun::net::www::MeteredStream;
using $ParseUtil = ::sun::net::www::ParseUtil;
using $URLConnection = ::sun::net::www::URLConnection;
using $FtpURLConnection$1 = ::sun::net::www::protocol::ftp::FtpURLConnection$1;
using $FtpURLConnection$FtpInputStream = ::sun::net::www::protocol::ftp::FtpURLConnection$FtpInputStream;
using $FtpURLConnection$FtpOutputStream = ::sun::net::www::protocol::ftp::FtpURLConnection$FtpOutputStream;
using $HttpURLConnection = ::sun::net::www::protocol::http::HttpURLConnection;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace ftp {

$FieldInfo _FtpURLConnection_FieldInfo_[] = {
	{"http", "Lsun/net/www/protocol/http/HttpURLConnection;", nullptr, 0, $field(FtpURLConnection, http)},
	{"instProxy", "Ljava/net/Proxy;", nullptr, $PRIVATE, $field(FtpURLConnection, instProxy)},
	{"is", "Ljava/io/InputStream;", nullptr, 0, $field(FtpURLConnection, is)},
	{"os", "Ljava/io/OutputStream;", nullptr, 0, $field(FtpURLConnection, os)},
	{"ftp", "Lsun/net/ftp/FtpClient;", nullptr, 0, $field(FtpURLConnection, ftp)},
	{"permission", "Ljava/security/Permission;", nullptr, 0, $field(FtpURLConnection, permission)},
	{"password", "Ljava/lang/String;", nullptr, 0, $field(FtpURLConnection, password)},
	{"user", "Ljava/lang/String;", nullptr, 0, $field(FtpURLConnection, user)},
	{"host", "Ljava/lang/String;", nullptr, 0, $field(FtpURLConnection, host)},
	{"pathname", "Ljava/lang/String;", nullptr, 0, $field(FtpURLConnection, pathname)},
	{"filename", "Ljava/lang/String;", nullptr, 0, $field(FtpURLConnection, filename)},
	{"fullpath", "Ljava/lang/String;", nullptr, 0, $field(FtpURLConnection, fullpath)},
	{"port", "I", nullptr, 0, $field(FtpURLConnection, port)},
	{"NONE", "I", nullptr, $STATIC | $FINAL, $constField(FtpURLConnection, NONE)},
	{"ASCII", "I", nullptr, $STATIC | $FINAL, $constField(FtpURLConnection, ASCII)},
	{"BIN", "I", nullptr, $STATIC | $FINAL, $constField(FtpURLConnection, BIN)},
	{"DIR", "I", nullptr, $STATIC | $FINAL, $constField(FtpURLConnection, DIR)},
	{"type", "I", nullptr, 0, $field(FtpURLConnection, type)},
	{"connectTimeout", "I", nullptr, $PRIVATE, $field(FtpURLConnection, connectTimeout)},
	{"readTimeout", "I", nullptr, $PRIVATE, $field(FtpURLConnection, readTimeout)},
	{}
};

$MethodInfo _FtpURLConnection_MethodInfo_[] = {
	{"<init>", "(Ljava/net/URL;)V", nullptr, $PUBLIC, $method(FtpURLConnection, init$, void, $URL*)},
	{"<init>", "(Ljava/net/URL;Ljava/net/Proxy;)V", nullptr, 0, $method(FtpURLConnection, init$, void, $URL*, $Proxy*)},
	{"cd", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(FtpURLConnection, cd, void, $String*), "sun.net.ftp.FtpProtocolException,java.io.IOException"},
	{"checkURL", "(Ljava/net/URL;)Ljava/net/URL;", nullptr, $STATIC, $staticMethod(FtpURLConnection, checkURL, $URL*, $URL*), "java.lang.IllegalArgumentException"},
	{"connect", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, $virtualMethod(FtpURLConnection, connect, void), "java.io.IOException"},
	{"decodePath", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(FtpURLConnection, decodePath, void, $String*)},
	{"getConnectTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(FtpURLConnection, getConnectTimeout, int32_t)},
	{"getInputStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, $virtualMethod(FtpURLConnection, getInputStream, $InputStream*), "java.io.IOException"},
	{"getOutputStream", "()Ljava/io/OutputStream;", nullptr, $PUBLIC, $virtualMethod(FtpURLConnection, getOutputStream, $OutputStream*), "java.io.IOException"},
	{"getPermission", "()Ljava/security/Permission;", nullptr, $PUBLIC, $virtualMethod(FtpURLConnection, getPermission, $Permission*)},
	{"getReadTimeout", "()I", nullptr, $PUBLIC, $virtualMethod(FtpURLConnection, getReadTimeout, int32_t)},
	{"getRequestProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(FtpURLConnection, getRequestProperty, $String*, $String*)},
	{"guessContentTypeFromFilename", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, 0, $virtualMethod(FtpURLConnection, guessContentTypeFromFilename, $String*, $String*)},
	{"setConnectTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(FtpURLConnection, setConnectTimeout, void, int32_t)},
	{"setReadTimeout", "(I)V", nullptr, $PUBLIC, $virtualMethod(FtpURLConnection, setReadTimeout, void, int32_t)},
	{"setRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(FtpURLConnection, setRequestProperty, void, $String*, $String*)},
	{"setTimeouts", "()V", nullptr, $PRIVATE, $method(FtpURLConnection, setTimeouts, void)},
	{}
};

$InnerClassInfo _FtpURLConnection_InnerClassesInfo_[] = {
	{"sun.net.www.protocol.ftp.FtpURLConnection$FtpOutputStream", "sun.net.www.protocol.ftp.FtpURLConnection", "FtpOutputStream", $PROTECTED | $STATIC},
	{"sun.net.www.protocol.ftp.FtpURLConnection$FtpInputStream", "sun.net.www.protocol.ftp.FtpURLConnection", "FtpInputStream", $PROTECTED | $STATIC},
	{"sun.net.www.protocol.ftp.FtpURLConnection$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FtpURLConnection_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.ftp.FtpURLConnection",
	"sun.net.www.URLConnection",
	nullptr,
	_FtpURLConnection_FieldInfo_,
	_FtpURLConnection_MethodInfo_,
	nullptr,
	nullptr,
	_FtpURLConnection_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.net.www.protocol.ftp.FtpURLConnection$FtpOutputStream,sun.net.www.protocol.ftp.FtpURLConnection$FtpInputStream,sun.net.www.protocol.ftp.FtpURLConnection$1"
};

$Object* allocate$FtpURLConnection($Class* clazz) {
	return $of($alloc(FtpURLConnection));
}

$URL* FtpURLConnection::checkURL($URL* u) {
	$init(FtpURLConnection);
	$useLocalCurrentObjectStackCache();
	if (u != nullptr) {
		if ($nc($(u->toExternalForm()))->indexOf((int32_t)u'\n') > -1) {
			$var($Exception, mfue, $new($MalformedURLException, "Illegal character in URL"_s));
			$throwNew($IllegalArgumentException, $(mfue->getMessage()), mfue);
		}
	}
	$var($String, s, $IPAddressUtil::checkAuthority(u));
	if (s != nullptr) {
		$var($Exception, mfue, $new($MalformedURLException, s));
		$throwNew($IllegalArgumentException, $(mfue->getMessage()), mfue);
	}
	return u;
}

void FtpURLConnection::init$($URL* url) {
	FtpURLConnection::init$(url, nullptr);
}

void FtpURLConnection::init$($URL* url, $Proxy* p) {
	$useLocalCurrentObjectStackCache();
	$URLConnection::init$($(checkURL(url)));
	$set(this, http, nullptr);
	$set(this, is, nullptr);
	$set(this, os, nullptr);
	$set(this, ftp, nullptr);
	this->type = FtpURLConnection::NONE;
	this->connectTimeout = $NetworkClient::DEFAULT_CONNECT_TIMEOUT;
	this->readTimeout = $NetworkClient::DEFAULT_READ_TIMEOUT;
	$set(this, instProxy, p);
	$set(this, host, $nc(url)->getHost());
	this->port = url->getPort();
	$var($String, userInfo, url->getUserInfo());
	if (userInfo != nullptr) {
		int32_t delimiter = userInfo->indexOf((int32_t)u':');
		if (delimiter == -1) {
			$set(this, user, $ParseUtil::decode(userInfo));
			$set(this, password, nullptr);
		} else {
			$set(this, user, $ParseUtil::decode($(userInfo->substring(0, delimiter++))));
			$set(this, password, $ParseUtil::decode($(userInfo->substring(delimiter))));
		}
	}
}

void FtpURLConnection::setTimeouts() {
	if (this->ftp != nullptr) {
		if (this->connectTimeout >= 0) {
			$nc(this->ftp)->setConnectTimeout(this->connectTimeout);
		}
		if (this->readTimeout >= 0) {
			$nc(this->ftp)->setReadTimeout(this->readTimeout);
		}
	}
}

void FtpURLConnection::connect() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		if (this->connected) {
			return;
		}
		$var($Proxy, p, nullptr);
		if (this->instProxy == nullptr) {
			$var($ProxySelector, sel, $cast($ProxySelector, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($FtpURLConnection$1, this)))));
			if (sel != nullptr) {
				$var($URI, uri, $ParseUtil::toURI(this->url));
				$var($List, proxies, nullptr);
				try {
					$assign(proxies, sel->select(uri));
				} catch ($IllegalArgumentException& iae) {
					$throwNew($IOException, "Failed to select a proxy"_s, iae);
				}
				$var($Iterator, it, $nc(proxies)->iterator());
				while ($nc(it)->hasNext()) {
					$assign(p, $cast($Proxy, it->next()));
					$init($Proxy);
					$init($Proxy$Type);
					if (p == nullptr || p == $Proxy::NO_PROXY || $nc(p)->type() == $Proxy$Type::SOCKS) {
						break;
					}
					bool var$0 = $nc(p)->type() != $Proxy$Type::HTTP;
					if (var$0 || !($instanceOf($InetSocketAddress, $($nc(p)->address())))) {
						$var($URI, var$1, uri);
						$var($SocketAddress, var$2, p->address());
						sel->connectFailed(var$1, var$2, $$new($IOException, "Wrong proxy type"_s));
						continue;
					}
					$var($InetSocketAddress, paddr, $cast($InetSocketAddress, $nc(p)->address()));
					try {
						$set(this, http, $new($HttpURLConnection, this->url, p));
						$nc(this->http)->setDoInput(getDoInput());
						$nc(this->http)->setDoOutput(getDoOutput());
						if (this->connectTimeout >= 0) {
							$nc(this->http)->setConnectTimeout(this->connectTimeout);
						}
						if (this->readTimeout >= 0) {
							$nc(this->http)->setReadTimeout(this->readTimeout);
						}
						$nc(this->http)->connect();
						this->connected = true;
						return;
					} catch ($IOException& ioe) {
						sel->connectFailed(uri, paddr, ioe);
						$set(this, http, nullptr);
					}
				}
			}
		} else {
			$assign(p, this->instProxy);
			$init($Proxy$Type);
			if ($nc(p)->type() == $Proxy$Type::HTTP) {
				$set(this, http, $new($HttpURLConnection, this->url, this->instProxy));
				$nc(this->http)->setDoInput(getDoInput());
				$nc(this->http)->setDoOutput(getDoOutput());
				if (this->connectTimeout >= 0) {
					$nc(this->http)->setConnectTimeout(this->connectTimeout);
				}
				if (this->readTimeout >= 0) {
					$nc(this->http)->setReadTimeout(this->readTimeout);
				}
				$nc(this->http)->connect();
				this->connected = true;
				return;
			}
		}
		if (this->user == nullptr) {
			$set(this, user, "anonymous"_s);
			$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
			$var($String, vers, $nc(props)->getProperty("java.version"_s));
			$set(this, password, props->getProperty("ftp.protocol.user"_s, $$str({"Java"_s, vers, "@"_s})));
		}
		try {
			$set(this, ftp, $FtpClient::create());
			if (p != nullptr) {
				$nc(this->ftp)->setProxy(p);
			}
			setTimeouts();
			if (this->port != -1) {
				$nc(this->ftp)->connect($$new($InetSocketAddress, this->host, this->port));
			} else {
				$nc(this->ftp)->connect($$new($InetSocketAddress, this->host, $FtpClient::defaultPort()));
			}
		} catch ($UnknownHostException& e) {
			$throw(e);
		} catch ($FtpProtocolException& fe) {
			if (this->ftp != nullptr) {
				try {
					$nc(this->ftp)->close();
				} catch ($IOException& ioe) {
					fe->addSuppressed(ioe);
				}
			}
			$throwNew($IOException, static_cast<$Throwable*>(fe));
		}
		try {
			$nc(this->ftp)->login(this->user, this->password == nullptr ? ($chars*)nullptr : $($nc(this->password)->toCharArray()));
		} catch ($FtpProtocolException& e) {
			$nc(this->ftp)->close();
			$throwNew($FtpLoginException, "Invalid username/password"_s);
		}
		this->connected = true;
	}
}

void FtpURLConnection::decodePath($String* path$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, path, path$renamed);
	int32_t i = $nc(path)->indexOf(";type="_s);
	if (i >= 0) {
		$var($String, s1, path->substring(i + 6, path->length()));
		if ("i"_s->equalsIgnoreCase(s1)) {
			this->type = FtpURLConnection::BIN;
		}
		if ("a"_s->equalsIgnoreCase(s1)) {
			this->type = FtpURLConnection::ASCII;
		}
		if ("d"_s->equalsIgnoreCase(s1)) {
			this->type = FtpURLConnection::DIR;
		}
		$assign(path, path->substring(0, i));
	}
	bool var$0 = path != nullptr && path->length() > 1;
	if (var$0 && path->charAt(0) == u'/') {
		$assign(path, path->substring(1));
	}
	if (path == nullptr || path->isEmpty()) {
		$assign(path, "./"_s);
	}
	if (!path->endsWith("/"_s)) {
		i = path->lastIndexOf((int32_t)u'/');
		if (i > 0) {
			$set(this, filename, path->substring(i + 1, path->length()));
			$set(this, filename, $ParseUtil::decode(this->filename));
			$set(this, pathname, path->substring(0, i));
		} else {
			$set(this, filename, $ParseUtil::decode(path));
			$set(this, pathname, nullptr);
		}
	} else {
		$set(this, pathname, path->substring(0, path->length() - 1));
		$set(this, filename, nullptr);
	}
	if (this->pathname != nullptr) {
		$set(this, fullpath, $str({this->pathname, "/"_s, (this->filename != nullptr ? this->filename : ""_s)}));
	} else {
		$set(this, fullpath, this->filename);
	}
}

void FtpURLConnection::cd($String* path) {
	$useLocalCurrentObjectStackCache();
	if (path == nullptr || $nc(path)->isEmpty()) {
		return;
	}
	if ($nc(path)->indexOf((int32_t)u'/') == -1) {
		$nc(this->ftp)->changeDirectory($($ParseUtil::decode(path)));
		return;
	}
	$var($StringTokenizer, token, $new($StringTokenizer, path, "/"_s));
	while (token->hasMoreTokens()) {
		$nc(this->ftp)->changeDirectory($($ParseUtil::decode($(token->nextToken()))));
	}
}

$InputStream* FtpURLConnection::getInputStream() {
	$useLocalCurrentObjectStackCache();
	if (!this->connected) {
		connect();
	}
	if (this->http != nullptr) {
		return $nc(this->http)->getInputStream();
	}
	if (this->os != nullptr) {
		$throwNew($IOException, "Already opened for output"_s);
	}
	if (this->is != nullptr) {
		return this->is;
	}
	$var($MessageHeader, msgh, $new($MessageHeader));
	bool isAdir = false;
	try {
		decodePath($($nc(this->url)->getPath()));
		if (this->filename == nullptr || this->type == FtpURLConnection::DIR) {
			$nc(this->ftp)->setAsciiType();
			cd(this->pathname);
			if (this->filename == nullptr) {
				$set(this, is, $new($FtpURLConnection$FtpInputStream, this->ftp, $($nc(this->ftp)->list(nullptr))));
			} else {
				$set(this, is, $new($FtpURLConnection$FtpInputStream, this->ftp, $($nc(this->ftp)->nameList(this->filename))));
			}
		} else {
			if (this->type == FtpURLConnection::ASCII) {
				$nc(this->ftp)->setAsciiType();
			} else {
				$nc(this->ftp)->setBinaryType();
			}
			cd(this->pathname);
			$set(this, is, $new($FtpURLConnection$FtpInputStream, this->ftp, $($nc(this->ftp)->getFileStream(this->filename))));
		}
		try {
			int64_t l = $nc(this->ftp)->getLastTransferSize();
			msgh->add("content-length"_s, $($Long::toString(l)));
			if (l > 0) {
				bool meteredInput = $nc($($ProgressMonitor::getDefault()))->shouldMeterInput(this->url, "GET"_s);
				$var($ProgressSource, pi, nullptr);
				if (meteredInput) {
					$assign(pi, $new($ProgressSource, this->url, "GET"_s, l));
					pi->beginTracking();
				}
				$set(this, is, $new($MeteredStream, this->is, pi, l));
			}
		} catch ($Exception& e) {
			e->printStackTrace();
		}
		if (isAdir) {
			msgh->add("content-type"_s, "text/plain"_s);
			msgh->add("access-type"_s, "directory"_s);
		} else {
			msgh->add("access-type"_s, "file"_s);
			$var($String, ftype, guessContentTypeFromName(this->fullpath));
			if (ftype == nullptr && $nc(this->is)->markSupported()) {
				$assign(ftype, guessContentTypeFromStream(this->is));
			}
			if (ftype != nullptr) {
				msgh->add("content-type"_s, ftype);
			}
		}
	} catch ($FileNotFoundException& e) {
		try {
			cd(this->fullpath);
			$nc(this->ftp)->setAsciiType();
			$set(this, is, $new($FtpURLConnection$FtpInputStream, this->ftp, $($nc(this->ftp)->list(nullptr))));
			msgh->add("content-type"_s, "text/plain"_s);
			msgh->add("access-type"_s, "directory"_s);
		} catch ($IOException& ex) {
			$var($FileNotFoundException, fnfe, $new($FileNotFoundException, this->fullpath));
			if (this->ftp != nullptr) {
				try {
					$nc(this->ftp)->close();
				} catch ($IOException& ioe) {
					fnfe->addSuppressed(ioe);
				}
			}
			$throw(fnfe);
		} catch ($FtpProtocolException& ex2) {
			$var($FileNotFoundException, fnfe, $new($FileNotFoundException, this->fullpath));
			if (this->ftp != nullptr) {
				try {
					$nc(this->ftp)->close();
				} catch ($IOException& ioe) {
					fnfe->addSuppressed(ioe);
				}
			}
			$throw(fnfe);
		}
	} catch ($FtpProtocolException& ftpe) {
		if (this->ftp != nullptr) {
			try {
				$nc(this->ftp)->close();
			} catch ($IOException& ioe) {
				ftpe->addSuppressed(ioe);
			}
		}
		$throwNew($IOException, static_cast<$Throwable*>(ftpe));
	}
	setProperties(msgh);
	return this->is;
}

$OutputStream* FtpURLConnection::getOutputStream() {
	$useLocalCurrentObjectStackCache();
	if (!this->connected) {
		connect();
	}
	if (this->http != nullptr) {
		$var($OutputStream, out, $nc(this->http)->getOutputStream());
		$nc(this->http)->getInputStream();
		return out;
	}
	if (this->is != nullptr) {
		$throwNew($IOException, "Already opened for input"_s);
	}
	if (this->os != nullptr) {
		return this->os;
	}
	decodePath($($nc(this->url)->getPath()));
	if (this->filename == nullptr || $nc(this->filename)->isEmpty()) {
		$throwNew($IOException, "illegal filename for a PUT"_s);
	}
	try {
		if (this->pathname != nullptr) {
			cd(this->pathname);
		}
		if (this->type == FtpURLConnection::ASCII) {
			$nc(this->ftp)->setAsciiType();
		} else {
			$nc(this->ftp)->setBinaryType();
		}
		$set(this, os, $new($FtpURLConnection$FtpOutputStream, this->ftp, $($nc(this->ftp)->putFileStream(this->filename, false))));
	} catch ($FtpProtocolException& e) {
		$throwNew($IOException, static_cast<$Throwable*>(e));
	}
	return this->os;
}

$String* FtpURLConnection::guessContentTypeFromFilename($String* fname) {
	return guessContentTypeFromName(fname);
}

$Permission* FtpURLConnection::getPermission() {
	$useLocalCurrentObjectStackCache();
	if (this->permission == nullptr) {
		int32_t urlport = $nc(this->url)->getPort();
		urlport = urlport < 0 ? $FtpClient::defaultPort() : urlport;
		$var($String, urlhost, $str({this->host, ":"_s, $$str(urlport)}));
		$set(this, permission, $new($SocketPermission, urlhost, "connect"_s));
	}
	return this->permission;
}

void FtpURLConnection::setRequestProperty($String* key, $String* value) {
	$URLConnection::setRequestProperty(key, value);
	if ("type"_s->equals(key)) {
		if ("i"_s->equalsIgnoreCase(value)) {
			this->type = FtpURLConnection::BIN;
		} else if ("a"_s->equalsIgnoreCase(value)) {
			this->type = FtpURLConnection::ASCII;
		} else if ("d"_s->equalsIgnoreCase(value)) {
			this->type = FtpURLConnection::DIR;
		} else {
			$throwNew($IllegalArgumentException, $$str({"Value of \'"_s, key, "\' request property was \'"_s, value, "\' when it must be either \'i\', \'a\' or \'d\'"_s}));
		}
	}
}

$String* FtpURLConnection::getRequestProperty($String* key) {
	$var($String, value, $URLConnection::getRequestProperty(key));
	if (value == nullptr) {
		if ("type"_s->equals(key)) {
			$assign(value, this->type == FtpURLConnection::ASCII ? "a"_s : this->type == FtpURLConnection::DIR ? "d"_s : "i"_s);
		}
	}
	return value;
}

void FtpURLConnection::setConnectTimeout(int32_t timeout) {
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "timeouts can\'t be negative"_s);
	}
	this->connectTimeout = timeout;
}

int32_t FtpURLConnection::getConnectTimeout() {
	return (this->connectTimeout < 0 ? 0 : this->connectTimeout);
}

void FtpURLConnection::setReadTimeout(int32_t timeout) {
	if (timeout < 0) {
		$throwNew($IllegalArgumentException, "timeouts can\'t be negative"_s);
	}
	this->readTimeout = timeout;
}

int32_t FtpURLConnection::getReadTimeout() {
	return this->readTimeout < 0 ? 0 : this->readTimeout;
}

FtpURLConnection::FtpURLConnection() {
}

$Class* FtpURLConnection::load$($String* name, bool initialize) {
	$loadClass(FtpURLConnection, name, initialize, &_FtpURLConnection_ClassInfo_, allocate$FtpURLConnection);
	return class$;
}

$Class* FtpURLConnection::class$ = nullptr;

				} // ftp
			} // protocol
		} // www
	} // net
} // sun
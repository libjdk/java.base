#include <sun/net/smtp/SmtpClient.h>

#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/InternalError.h>
#include <java/net/InetAddress.h>
#include <sun/net/NetworkClient.h>
#include <sun/net/TransferProtocolClient.h>
#include <sun/net/smtp/SmtpPrintStream.h>
#include <sun/net/smtp/SmtpProtocolException.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef DEFAULT_SMTP_PORT

using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $NetworkClient = ::sun::net::NetworkClient;
using $TransferProtocolClient = ::sun::net::TransferProtocolClient;
using $SmtpPrintStream = ::sun::net::smtp::SmtpPrintStream;
using $SmtpProtocolException = ::sun::net::smtp::SmtpProtocolException;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace net {
		namespace smtp {

$FieldInfo _SmtpClient_FieldInfo_[] = {
	{"DEFAULT_SMTP_PORT", "I", nullptr, $PRIVATE | $STATIC, $staticField(SmtpClient, DEFAULT_SMTP_PORT)},
	{"mailhost", "Ljava/lang/String;", nullptr, 0, $field(SmtpClient, mailhost)},
	{"message", "Lsun/net/smtp/SmtpPrintStream;", nullptr, 0, $field(SmtpClient, message)},
	{}
};

$MethodInfo _SmtpClient_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(SmtpClient, init$, void, $String*), "java.io.IOException"},
	{"<init>", "()V", nullptr, $PUBLIC, $method(SmtpClient, init$, void), "java.io.IOException"},
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(SmtpClient, init$, void, int32_t), "java.io.IOException"},
	{"closeMessage", "()V", nullptr, 0, $virtualMethod(SmtpClient, closeMessage, void), "java.io.IOException"},
	{"closeServer", "()V", nullptr, $PUBLIC, $virtualMethod(SmtpClient, closeServer, void), "java.io.IOException"},
	{"from", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SmtpClient, from, void, $String*), "java.io.IOException"},
	{"getEncoding", "()Ljava/lang/String;", nullptr, 0, $virtualMethod(SmtpClient, getEncoding, $String*)},
	{"getMailHost", "()Ljava/lang/String;", nullptr, $PUBLIC, $virtualMethod(SmtpClient, getMailHost, $String*)},
	{"issueCommand", "(Ljava/lang/String;I)V", nullptr, 0, $virtualMethod(SmtpClient, issueCommand, void, $String*, int32_t), "java.io.IOException"},
	{"openServer", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(SmtpClient, openServer, void, $String*), "java.io.IOException"},
	{"startMessage", "()Ljava/io/PrintStream;", nullptr, $PUBLIC, $virtualMethod(SmtpClient, startMessage, $PrintStream*), "java.io.IOException"},
	{"to", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $virtualMethod(SmtpClient, to, void, $String*), "java.io.IOException"},
	{"toCanonical", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(SmtpClient, toCanonical, void, $String*), "java.io.IOException"},
	{}
};

$ClassInfo _SmtpClient_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.smtp.SmtpClient",
	"sun.net.TransferProtocolClient",
	nullptr,
	_SmtpClient_FieldInfo_,
	_SmtpClient_MethodInfo_
};

$Object* allocate$SmtpClient($Class* clazz) {
	return $of($alloc(SmtpClient));
}

int32_t SmtpClient::DEFAULT_SMTP_PORT = 0;

void SmtpClient::closeServer() {
	if (serverIsOpen()) {
		closeMessage();
		issueCommand("QUIT\r\n"_s, 221);
		$TransferProtocolClient::closeServer();
	}
}

void SmtpClient::issueCommand($String* cmd, int32_t expect) {
	$useLocalCurrentObjectStackCache();
	sendServer(cmd);
	int32_t reply = 0;
	while ((reply = readServerResponse()) != expect) {
		if (reply != 220) {
			$throwNew($SmtpProtocolException, $(getResponseString()));
		}
	}
}

void SmtpClient::toCanonical($String* s) {
	$useLocalCurrentObjectStackCache();
	if ($nc(s)->startsWith("<"_s)) {
		issueCommand($$str({"rcpt to: "_s, s, "\r\n"_s}), 250);
	} else {
		issueCommand($$str({"rcpt to: <"_s, s, ">\r\n"_s}), 250);
	}
}

void SmtpClient::to($String* s) {
	$useLocalCurrentObjectStackCache();
	if ($nc(s)->indexOf((int32_t)u'\n') != -1) {
		$throwNew($IOException, "Illegal SMTP command"_s, $$new($IllegalArgumentException, "Illegal carriage return"_s));
	}
	int32_t st = 0;
	int32_t limit = $nc(s)->length();
	int32_t pos = 0;
	int32_t lastnonsp = 0;
	int32_t parendepth = 0;
	bool ignore = false;
	while (pos < limit) {
		int32_t c = s->charAt(pos);
		if (parendepth > 0) {
			if (c == u'(') {
				++parendepth;
			} else if (c == u')') {
				--parendepth;
			}
			if (parendepth == 0) {
				if (lastnonsp > st) {
					ignore = true;
				} else {
					st = pos + 1;
				}
			}
		} else if (c == u'(') {
			++parendepth;
		} else if (c == u'<') {
			st = (lastnonsp = pos + 1);
		} else if (c == u'>') {
			ignore = true;
		} else if (c == u',') {
			if (lastnonsp > st) {
				toCanonical($(s->substring(st, lastnonsp)));
			}
			st = pos + 1;
			ignore = false;
		} else if (c > u' ' && !ignore) {
			lastnonsp = pos + 1;
		} else if (st == pos) {
			++st;
		}
		++pos;
	}
	if (lastnonsp > st) {
		toCanonical($(s->substring(st, lastnonsp)));
	}
}

void SmtpClient::from($String* s) {
	$useLocalCurrentObjectStackCache();
	if ($nc(s)->indexOf((int32_t)u'\n') != -1) {
		$throwNew($IOException, "Illegal SMTP command"_s, $$new($IllegalArgumentException, "Illegal carriage return"_s));
	}
	if ($nc(s)->startsWith("<"_s)) {
		issueCommand($$str({"mail from: "_s, s, "\r\n"_s}), 250);
	} else {
		issueCommand($$str({"mail from: <"_s, s, ">\r\n"_s}), 250);
	}
}

void SmtpClient::openServer($String* host) {
	$useLocalCurrentObjectStackCache();
	$set(this, mailhost, host);
	openServer(this->mailhost, SmtpClient::DEFAULT_SMTP_PORT);
	issueCommand($$str({"helo "_s, $($nc($($InetAddress::getLocalHost()))->getHostName()), "\r\n"_s}), 250);
}

$PrintStream* SmtpClient::startMessage() {
	issueCommand("data\r\n"_s, 354);
	try {
		$set(this, message, $new($SmtpPrintStream, this->serverOutput, this));
	} catch ($UnsupportedEncodingException& e) {
		$init($NetworkClient);
		$throwNew($InternalError, $$str({$NetworkClient::encoding, " encoding not found"_s}), e);
	}
	return this->message;
}

void SmtpClient::closeMessage() {
	if (this->message != nullptr) {
		$nc(this->message)->close();
	}
}

void SmtpClient::init$($String* host) {
	$TransferProtocolClient::init$();
	if (host != nullptr) {
		try {
			openServer(host);
			$set(this, mailhost, host);
			return;
		} catch ($Exception& e) {
		}
	}
	try {
		$var($String, s, nullptr);
		$set(this, mailhost, $GetPropertyAction::privilegedGetProperty("mail.host"_s));
		if (this->mailhost != nullptr) {
			openServer(this->mailhost);
			return;
		}
	} catch ($Exception& e) {
	}
	try {
		$set(this, mailhost, "localhost"_s);
		openServer(this->mailhost);
	} catch ($Exception& e) {
		$set(this, mailhost, "mailhost"_s);
		openServer(this->mailhost);
	}
}

void SmtpClient::init$() {
	SmtpClient::init$(($String*)nullptr);
}

void SmtpClient::init$(int32_t to) {
	$TransferProtocolClient::init$();
	setConnectTimeout(to);
	try {
		$var($String, s, nullptr);
		$set(this, mailhost, $GetPropertyAction::privilegedGetProperty("mail.host"_s));
		if (this->mailhost != nullptr) {
			openServer(this->mailhost);
			return;
		}
	} catch ($Exception& e) {
	}
	try {
		$set(this, mailhost, "localhost"_s);
		openServer(this->mailhost);
	} catch ($Exception& e) {
		$set(this, mailhost, "mailhost"_s);
		openServer(this->mailhost);
	}
}

$String* SmtpClient::getMailHost() {
	return this->mailhost;
}

$String* SmtpClient::getEncoding() {
	$init($NetworkClient);
	return $NetworkClient::encoding;
}

void clinit$SmtpClient($Class* class$) {
	SmtpClient::DEFAULT_SMTP_PORT = 25;
}

SmtpClient::SmtpClient() {
}

$Class* SmtpClient::load$($String* name, bool initialize) {
	$loadClass(SmtpClient, name, initialize, &_SmtpClient_ClassInfo_, clinit$SmtpClient, allocate$SmtpClient);
	return class$;
}

$Class* SmtpClient::class$ = nullptr;

		} // smtp
	} // net
} // sun
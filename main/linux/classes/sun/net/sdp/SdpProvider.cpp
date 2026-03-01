#include <sun/net/sdp/SdpProvider.h>

#include <java/io/File.h>
#include <java/io/FileDescriptor.h>
#include <java/io/IOException.h>
#include <java/lang/Appendable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/NumberFormatException.h>
#include <java/net/Inet4Address.h>
#include <java/net/InetAddress.h>
#include <java/net/UnknownHostException.h>
#include <java/util/ArrayList.h>
#include <java/util/Formatter.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Properties.h>
#include <java/util/Scanner.h>
#include <sun/net/NetHooks$Provider.h>
#include <sun/net/sdp/SdpProvider$Action.h>
#include <sun/net/sdp/SdpProvider$AddressPortRangeRule.h>
#include <sun/net/sdp/SdpProvider$PortRangeRule.h>
#include <sun/net/sdp/SdpProvider$Rule.h>
#include <sun/net/sdp/SdpSupport.h>
#include <sun/security/action/GetPropertyAction.h>
#include <jcpp.h>

#undef BIND
#undef CONNECT
#undef MAX_PORT

using $InetAddressArray = $Array<::java::net::InetAddress>;
using $SdpProvider$ActionArray = $Array<::sun::net::sdp::SdpProvider$Action>;
using $File = ::java::io::File;
using $FileDescriptor = ::java::io::FileDescriptor;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Appendable = ::java::lang::Appendable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Inet4Address = ::java::net::Inet4Address;
using $InetAddress = ::java::net::InetAddress;
using $UnknownHostException = ::java::net::UnknownHostException;
using $ArrayList = ::java::util::ArrayList;
using $Formatter = ::java::util::Formatter;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Properties = ::java::util::Properties;
using $Scanner = ::java::util::Scanner;
using $NetHooks$Provider = ::sun::net::NetHooks$Provider;
using $SdpProvider$Action = ::sun::net::sdp::SdpProvider$Action;
using $SdpProvider$AddressPortRangeRule = ::sun::net::sdp::SdpProvider$AddressPortRangeRule;
using $SdpProvider$PortRangeRule = ::sun::net::sdp::SdpProvider$PortRangeRule;
using $SdpProvider$Rule = ::sun::net::sdp::SdpProvider$Rule;
using $SdpSupport = ::sun::net::sdp::SdpSupport;
using $GetPropertyAction = ::sun::security::action::GetPropertyAction;

namespace sun {
	namespace net {
		namespace sdp {

$FieldInfo _SdpProvider_FieldInfo_[] = {
	{"MAX_PORT", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SdpProvider, MAX_PORT)},
	{"enabled", "Z", nullptr, $PRIVATE | $FINAL, $field(SdpProvider, enabled)},
	{"rules", "Ljava/util/List;", "Ljava/util/List<Lsun/net/sdp/SdpProvider$Rule;>;", $PRIVATE | $FINAL, $field(SdpProvider, rules)},
	{"log", "Ljava/io/PrintStream;", nullptr, $PRIVATE, $field(SdpProvider, log)},
	{}
};

$MethodInfo _SdpProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(SdpProvider, init$, void)},
	{"convertTcpToSdpIfMatch", "(Ljava/io/FileDescriptor;Lsun/net/sdp/SdpProvider$Action;Ljava/net/InetAddress;I)V", nullptr, $PRIVATE, $method(SdpProvider, convertTcpToSdpIfMatch, void, $FileDescriptor*, $SdpProvider$Action*, $InetAddress*, int32_t), "java.io.IOException"},
	{"fail", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PRIVATE | $STATIC | $TRANSIENT, $staticMethod(SdpProvider, fail, void, $String*, $ObjectArray*)},
	{"implBeforeTcpBind", "(Ljava/io/FileDescriptor;Ljava/net/InetAddress;I)V", nullptr, $PUBLIC, $virtualMethod(SdpProvider, implBeforeTcpBind, void, $FileDescriptor*, $InetAddress*, int32_t), "java.io.IOException"},
	{"implBeforeTcpConnect", "(Ljava/io/FileDescriptor;Ljava/net/InetAddress;I)V", nullptr, $PUBLIC, $virtualMethod(SdpProvider, implBeforeTcpConnect, void, $FileDescriptor*, $InetAddress*, int32_t), "java.io.IOException"},
	{"loadRulesFromFile", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Lsun/net/sdp/SdpProvider$Rule;>;", $PRIVATE | $STATIC, $staticMethod(SdpProvider, loadRulesFromFile, $List*, $String*), "java.io.IOException"},
	{"parsePortRange", "(Ljava/lang/String;)[I", nullptr, $PRIVATE | $STATIC, $staticMethod(SdpProvider, parsePortRange, $ints*, $String*)},
	{}
};

$InnerClassInfo _SdpProvider_InnerClassesInfo_[] = {
	{"sun.net.NetHooks$Provider", "sun.net.NetHooks", "Provider", $PUBLIC | $STATIC | $ABSTRACT},
	{"sun.net.sdp.SdpProvider$AddressPortRangeRule", "sun.net.sdp.SdpProvider", "AddressPortRangeRule", $PRIVATE | $STATIC},
	{"sun.net.sdp.SdpProvider$PortRangeRule", "sun.net.sdp.SdpProvider", "PortRangeRule", $PRIVATE | $STATIC},
	{"sun.net.sdp.SdpProvider$Rule", "sun.net.sdp.SdpProvider", "Rule", $PRIVATE | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.net.sdp.SdpProvider$Action", "sun.net.sdp.SdpProvider", "Action", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _SdpProvider_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.sdp.SdpProvider",
	"sun.net.NetHooks$Provider",
	nullptr,
	_SdpProvider_FieldInfo_,
	_SdpProvider_MethodInfo_,
	nullptr,
	nullptr,
	_SdpProvider_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.net.sdp.SdpProvider$AddressPortRangeRule,sun.net.sdp.SdpProvider$PortRangeRule,sun.net.sdp.SdpProvider$Rule,sun.net.sdp.SdpProvider$Action"
};

$Object* allocate$SdpProvider($Class* clazz) {
	return $of($alloc(SdpProvider));
}

void SdpProvider::init$() {
	$useLocalCurrentObjectStackCache();
	$NetHooks$Provider::init$();
	$var($Properties, props, $GetPropertyAction::privilegedGetProperties());
	$var($String, file, $nc(props)->getProperty("com.sun.sdp.conf"_s));
	if (file == nullptr) {
		this->enabled = false;
		$set(this, rules, nullptr);
		return;
	}
	$var($List, list, nullptr);
	try {
		$assign(list, loadRulesFromFile(file));
	} catch ($IOException& e) {
		fail("Error reading %s: %s"_s, $$new($ObjectArray, {
			$of(file),
			$($of(e->getMessage()))
		}));
	}
	$var($PrintStream, out, nullptr);
	$var($String, logfile, props->getProperty("com.sun.sdp.debug"_s));
	if (logfile != nullptr) {
		$assign(out, $System::out);
		if (!logfile->isEmpty()) {
			try {
				$assign(out, $new($PrintStream, logfile));
			} catch ($IOException& ignore) {
			}
		}
	}
	this->enabled = !$nc(list)->isEmpty();
	$set(this, rules, list);
	$set(this, log, out);
}

$ints* SdpProvider::parsePortRange($String* s) {
	$init(SdpProvider);
	$useLocalCurrentObjectStackCache();
	int32_t pos = $nc(s)->indexOf((int32_t)u'-');
	try {
		$var($ints, result, $new($ints, 2));
		if (pos < 0) {
			bool all = s->equals("*"_s);
			result->set(0, all ? 0 : $Integer::parseInt(s));
			result->set(1, all ? SdpProvider::MAX_PORT : result->get(0));
		} else {
			$var($String, low, s->substring(0, pos));
			if (low->isEmpty()) {
				$assign(low, "*"_s);
			}
			$var($String, high, s->substring(pos + 1));
			if (high->isEmpty()) {
				$assign(high, "*"_s);
			}
			result->set(0, low->equals("*"_s) ? 0 : $Integer::parseInt(low));
			result->set(1, high->equals("*"_s) ? SdpProvider::MAX_PORT : $Integer::parseInt(high));
		}
		return result;
	} catch ($NumberFormatException& e) {
		return $new($ints, 0);
	}
	$shouldNotReachHere();
}

void SdpProvider::fail($String* msg, $ObjectArray* args) {
	$init(SdpProvider);
	$useLocalCurrentObjectStackCache();
	$var($Formatter, f, $new($Formatter));
	f->format(msg, args);
	$throwNew($RuntimeException, $($nc($of($(f->out())))->toString()));
}

$List* SdpProvider::loadRulesFromFile($String* file) {
	$init(SdpProvider);
	$useLocalCurrentObjectStackCache();
	$var($Scanner, scanner, $new($Scanner, $$new($File, file)));
	{
		$var($Throwable, var$0, nullptr);
		$var($List, var$2, nullptr);
		bool return$1 = false;
		try {
			$var($List, result, $new($ArrayList));
			while (scanner->hasNextLine()) {
				$var($String, line, $nc($(scanner->nextLine()))->trim());
				bool var$3 = line->isEmpty();
				if (var$3 || line->charAt(0) == u'#') {
					continue;
				}
				$var($StringArray, s, line->split("\\s+"_s));
				if (s->length != 3) {
					fail("Malformed line \'%s\'"_s, $$new($ObjectArray, {$of(line)}));
					continue;
				}
				$SdpProvider$Action* action = nullptr;
				{
					$var($SdpProvider$ActionArray, arr$, $SdpProvider$Action::values());
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$SdpProvider$Action* a = arr$->get(i$);
						{
							if ($nc(s->get(0))->equalsIgnoreCase($($nc(a)->name()))) {
								action = a;
								break;
							}
						}
					}
				}
				if (action == nullptr) {
					fail("Action \'%s\' not recognized"_s, $$new($ObjectArray, {$of(s->get(0))}));
					continue;
				}
				$var($ints, ports, parsePortRange(s->get(2)));
				if ($nc(ports)->length == 0) {
					fail("Malformed port range \'%s\'"_s, $$new($ObjectArray, {$of(s->get(2))}));
					continue;
				}
				if ($nc(s->get(1))->equals("*"_s)) {
					result->add($$new($SdpProvider$PortRangeRule, action, $nc(ports)->get(0), ports->get(1)));
					continue;
				}
				int32_t pos = $nc(s->get(1))->indexOf((int32_t)u'/');
				try {
					if (pos < 0) {
						$var($InetAddressArray, addresses, $InetAddress::getAllByName(s->get(1)));
						{
							$var($InetAddressArray, arr$, addresses);
							int32_t len$ = $nc(arr$)->length;
							int32_t i$ = 0;
							for (; i$ < len$; ++i$) {
								$var($InetAddress, address, arr$->get(i$));
								{
									int32_t prefix = ($instanceOf($Inet4Address, address)) ? 32 : 128;
									result->add($$new($SdpProvider$AddressPortRangeRule, action, address, prefix, $nc(ports)->get(0), ports->get(1)));
								}
							}
						}
					} else {
						$var($InetAddress, address, $InetAddress::getByName($($nc(s->get(1))->substring(0, pos))));
						int32_t prefix = -1;
						try {
							prefix = $Integer::parseInt(s->get(1), pos + 1, $nc(s->get(1))->length(), 10);
							if ($instanceOf($Inet4Address, address)) {
								if (prefix < 0 || prefix > 32) {
									prefix = -1;
								}
							} else if (prefix < 0 || prefix > 128) {
								prefix = -1;
							}
						} catch ($NumberFormatException& e) {
						}
						if (prefix > 0) {
							result->add($$new($SdpProvider$AddressPortRangeRule, action, address, prefix, $nc(ports)->get(0), ports->get(1)));
						} else {
							fail("Malformed prefix \'%s\'"_s, $$new($ObjectArray, {$of(s->get(1))}));
							continue;
						}
					}
				} catch ($UnknownHostException& uhe) {
					fail("Unknown host or malformed IP address \'%s\'"_s, $$new($ObjectArray, {$of(s->get(1))}));
					continue;
				}
			}
			$assign(var$2, result);
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			scanner->close();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void SdpProvider::convertTcpToSdpIfMatch($FileDescriptor* fdObj, $SdpProvider$Action* action, $InetAddress* address, int32_t port) {
	$useLocalCurrentObjectStackCache();
	bool matched = false;
	{
		$var($Iterator, i$, $nc(this->rules)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SdpProvider$Rule, rule, $cast($SdpProvider$Rule, i$->next()));
			{
				if ($nc(rule)->match(action, address, port)) {
					$SdpSupport::convertSocket(fdObj);
					matched = true;
					break;
				}
			}
		}
	}
	if (this->log != nullptr) {
		$var($String, addr, ($instanceOf($Inet4Address, address)) ? $nc(address)->getHostAddress() : $str({"["_s, $(address->getHostAddress()), "]"_s}));
		if (matched) {
			$nc(this->log)->format("%s to %s:%d (socket converted to SDP protocol)\n"_s, $$new($ObjectArray, {
				$of(action),
				$of(addr),
				$($of($Integer::valueOf(port)))
			}));
		} else {
			$nc(this->log)->format("%s to %s:%d (no match)\n"_s, $$new($ObjectArray, {
				$of(action),
				$of(addr),
				$($of($Integer::valueOf(port)))
			}));
		}
	}
}

void SdpProvider::implBeforeTcpBind($FileDescriptor* fdObj, $InetAddress* address, int32_t port) {
	if (this->enabled) {
		$init($SdpProvider$Action);
		convertTcpToSdpIfMatch(fdObj, $SdpProvider$Action::BIND, address, port);
	}
}

void SdpProvider::implBeforeTcpConnect($FileDescriptor* fdObj, $InetAddress* address, int32_t port) {
	if (this->enabled) {
		$init($SdpProvider$Action);
		convertTcpToSdpIfMatch(fdObj, $SdpProvider$Action::CONNECT, address, port);
	}
}

SdpProvider::SdpProvider() {
}

$Class* SdpProvider::load$($String* name, bool initialize) {
	$loadClass(SdpProvider, name, initialize, &_SdpProvider_ClassInfo_, allocate$SdpProvider);
	return class$;
}

$Class* SdpProvider::class$ = nullptr;

		} // sdp
	} // net
} // sun
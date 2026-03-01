#include <LotsOfCancels.h>

#include <LotsOfCancels$ClientThread.h>
#include <java/net/InetAddress.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/ServerSocket.h>
#include <java/net/SocketAddress.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/SelectionKey.h>
#include <java/nio/channels/Selector.h>
#include <java/nio/channels/ServerSocketChannel.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <jcpp.h>

#undef OP_ACCEPT
#undef OP_READ
#undef OP_WRITE

using $LotsOfCancels$ClientThread = ::LotsOfCancels$ClientThread;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $InetAddress = ::java::net::InetAddress;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $ServerSocket = ::java::net::ServerSocket;
using $SocketAddress = ::java::net::SocketAddress;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $Selector = ::java::nio::channels::Selector;
using $ServerSocketChannel = ::java::nio::channels::ServerSocketChannel;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;

$FieldInfo _LotsOfCancels_FieldInfo_[] = {
	{"testStartTime", "J", nullptr, $STATIC, $staticField(LotsOfCancels, testStartTime)},
	{}
};

$MethodInfo _LotsOfCancels_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(LotsOfCancels, init$, void)},
	{"acceptAndAddAll", "(Ljava/nio/channels/Selector;Ljava/nio/channels/ServerSocketChannel;I)Ljava/util/List;", "(Ljava/nio/channels/Selector;Ljava/nio/channels/ServerSocketChannel;I)Ljava/util/List<Ljava/nio/channels/SocketChannel;>;", $STATIC, $staticMethod(LotsOfCancels, acceptAndAddAll, $List*, $Selector*, $ServerSocketChannel*, int32_t), "java.lang.Exception"},
	{"closeAll", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/channels/SocketChannel;>;)V", $STATIC, $staticMethod(LotsOfCancels, closeAll, void, $List*), "java.lang.Exception"},
	{"durationMillis", "(J)J", nullptr, $STATIC, $staticMethod(LotsOfCancels, durationMillis, int64_t, int64_t)},
	{"getLogPrefix", "()Ljava/lang/String;", nullptr, $STATIC, $staticMethod(LotsOfCancels, getLogPrefix, $String*)},
	{"log", "(Ljava/lang/String;)V", nullptr, $STATIC, $staticMethod(LotsOfCancels, log, void, $String*)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(LotsOfCancels, main, void, $StringArray*), "java.lang.Exception"},
	{"runTest", "(III)V", nullptr, $STATIC, $staticMethod(LotsOfCancels, runTest, void, int32_t, int32_t, int32_t), "java.lang.Exception"},
	{}
};

$InnerClassInfo _LotsOfCancels_InnerClassesInfo_[] = {
	{"LotsOfCancels$ClientThread", "LotsOfCancels", "ClientThread", $STATIC},
	{}
};

$ClassInfo _LotsOfCancels_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"LotsOfCancels",
	"java.lang.Object",
	nullptr,
	_LotsOfCancels_FieldInfo_,
	_LotsOfCancels_MethodInfo_,
	nullptr,
	nullptr,
	_LotsOfCancels_InnerClassesInfo_,
	nullptr,
	nullptr,
	"LotsOfCancels$ClientThread"
};

$Object* allocate$LotsOfCancels($Class* clazz) {
	return $of($alloc(LotsOfCancels));
}

int64_t LotsOfCancels::testStartTime = 0;

void LotsOfCancels::init$() {
}

void LotsOfCancels::main($StringArray* args) {
	runTest(500, 2700, 1000);
}

void LotsOfCancels::log($String* msg) {
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println($$str({$(getLogPrefix()), msg}));
}

$String* LotsOfCancels::getLogPrefix() {
	$init(LotsOfCancels);
	return $str({$$str(durationMillis(LotsOfCancels::testStartTime)), ": "_s});
}

int64_t LotsOfCancels::durationMillis(int64_t startNanos) {
	return $div(($System::nanoTime() - startNanos), ((int64_t)1000 * (int64_t)1000));
}

void LotsOfCancels::runTest(int32_t initCount, int32_t massCount, int32_t maxSelectTime) {
	$useLocalCurrentObjectStackCache();
	$init(LotsOfCancels);
	LotsOfCancels::testStartTime = $System::nanoTime();
	$var($InetSocketAddress, address, $new($InetSocketAddress, $($InetAddress::getLoopbackAddress()), 7359));
	log("Setting up server"_s);
	$var($Selector, serverSelector, $Selector::open());
	$var($ServerSocketChannel, server, $ServerSocketChannel::open());
	$nc(server)->configureBlocking(false);
	$nc($(server->socket()))->bind(address, 5000);
	server->register$(serverSelector, $SelectionKey::OP_ACCEPT);
	$nc(serverSelector)->selectNow();
	log("Setting up client"_s);
	$var($LotsOfCancels$ClientThread, client, $new($LotsOfCancels$ClientThread, address));
	client->start();
	$Thread::sleep(100);
	log("Starting initial client connections"_s);
	client->connectClients(initCount);
	$Thread::sleep(500);
	log("Accepting initial connections"_s);
	$var($List, serverChannels1, acceptAndAddAll(serverSelector, server, initCount));
	if ($nc(serverChannels1)->size() != initCount) {
		$throwNew($Exception, $$str({"Accepted "_s, $$str(serverChannels1->size()), " instead of "_s, $$str(initCount)}));
	}
	serverSelector->selectNow();
	log("Requesting mass client connections"_s);
	client->connectClients(massCount);
	$Thread::sleep(500);
	log("Accepting mass connections"_s);
	$var($List, serverChannels2, acceptAndAddAll(serverSelector, server, massCount));
	if ($nc(serverChannels2)->size() != massCount) {
		$throwNew($Exception, $$str({"Accepted "_s, $$str(serverChannels2->size()), " instead of "_s, $$str(massCount)}));
	}
	log("Closing initial connections"_s);
	closeAll(serverChannels1);
	log("Running the final select call"_s);
	int64_t startTime = $System::nanoTime();
	serverSelector->selectNow();
	int64_t duration = durationMillis(startTime);
	log($$str({"Init count = "_s, $$str(initCount), ", mass count = "_s, $$str(massCount), ", duration = "_s, $$str(duration), "ms"_s}));
	if (duration > maxSelectTime) {
		$nc($System::out)->println($$str({"\n\n\n\n\nFAILURE: The final selectNow() took "_s, $$str(duration), "ms - seems like O(N^2) bug is still here\n\n"_s}));
		$System::exit(1);
	}
}

$List* LotsOfCancels::acceptAndAddAll($Selector* selector, $ServerSocketChannel* server, int32_t expected) {
	$useLocalCurrentObjectStackCache();
	int32_t retryCount = 0;
	int32_t acceptCount = 0;
	$var($List, channels, $new($ArrayList));
	while (channels->size() < expected) {
		$var($SocketChannel, channel, $nc(server)->accept());
		if (channel == nullptr) {
			log($$str({"accept() returned null after accepting "_s, $$str(acceptCount), " more connections"_s}));
			acceptCount = 0;
			if (retryCount < 10) {
				++retryCount;
				$Thread::sleep(500);
				continue;
			}
			break;
		}
		retryCount = 0;
		++acceptCount;
		$nc(channel)->configureBlocking(false);
		channel->register$(selector, $SelectionKey::OP_READ);
		channels->add(channel);
	}
	{
		$var($Iterator, i$, channels->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SocketChannel, channel, $cast($SocketChannel, i$->next()));
			{
				$nc(channel)->register$(selector, $SelectionKey::OP_WRITE);
			}
		}
	}
	return channels;
}

void LotsOfCancels::closeAll($List* channels) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(channels)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($SocketChannel, channel, $cast($SocketChannel, i$->next()));
			{
				$nc(channel)->close();
			}
		}
	}
}

LotsOfCancels::LotsOfCancels() {
}

$Class* LotsOfCancels::load$($String* name, bool initialize) {
	$loadClass(LotsOfCancels, name, initialize, &_LotsOfCancels_ClassInfo_, allocate$LotsOfCancels);
	return class$;
}

$Class* LotsOfCancels::class$ = nullptr;
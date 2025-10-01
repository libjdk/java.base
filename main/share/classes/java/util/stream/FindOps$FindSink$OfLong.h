#ifndef _java_util_stream_FindOps$FindSink$OfLong_h_
#define _java_util_stream_FindOps$FindSink$OfLong_h_
//$ class java.util.stream.FindOps$FindSink$OfLong
//$ extends java.util.stream.FindOps$FindSink
//$ implements java.util.stream.Sink$OfLong

#include <java/util/stream/FindOps$FindSink.h>
#include <java/util/stream/Sink$OfLong.h>

#pragma push_macro("OP_FIND_ANY")
#undef OP_FIND_ANY
#pragma push_macro("OP_FIND_FIRST")
#undef OP_FIND_FIRST

namespace java {
	namespace lang {
		class Long;
	}
}
namespace java {
	namespace util {
		namespace stream {
			class TerminalOp;
		}
	}
}

namespace java {
	namespace util {
		namespace stream {

class FindOps$FindSink$OfLong : public ::java::util::stream::FindOps$FindSink, public ::java::util::stream::Sink$OfLong {
	$class(FindOps$FindSink$OfLong, 0, ::java::util::stream::FindOps$FindSink, ::java::util::stream::Sink$OfLong)
public:
	FindOps$FindSink$OfLong();
	virtual ::java::lang::Object0* toObject0$() const override {return (::java::lang::Object0*)(void*)this;}
	using ::java::util::stream::Sink$OfLong::andThen;
	virtual void accept(Object$* value) override;
	virtual void accept(int32_t value) override;
	virtual void accept(double value) override;
	virtual ::java::util::function::Consumer* andThen(::java::util::function::Consumer* after) override;
	virtual void begin(int64_t size) override;
	virtual bool cancellationRequested() override;
	virtual $Object* clone() override;
	virtual void end() override;
	virtual bool equals(Object$* obj) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	virtual void accept(int64_t value) override;
	virtual void accept(::java::lang::Long* value) override;
	virtual $Object* get() override;
	virtual $String* toString() override;
	static ::java::util::stream::TerminalOp* OP_FIND_FIRST;
	static ::java::util::stream::TerminalOp* OP_FIND_ANY;
};

		} // stream
	} // util
} // java

#pragma pop_macro("OP_FIND_ANY")
#pragma pop_macro("OP_FIND_FIRST")

#endif // _java_util_stream_FindOps$FindSink$OfLong_h_
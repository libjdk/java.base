#include <Comment.h>

#include <java/io/File.h>
#include <java/io/FileReader.h>
#include <java/io/Reader.h>
#include <java/io/StreamTokenizer.h>
#include <jcpp.h>

#undef TT_EOF

using $File = ::java::io::File;
using $FileReader = ::java::io::FileReader;
using $Reader = ::java::io::Reader;
using $StreamTokenizer = ::java::io::StreamTokenizer;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;

$MethodInfo _Comment_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(Comment, init$, void)},
	{"main", "([Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $staticMethod(Comment, main, void, $StringArray*), "java.lang.Exception"},
	{}
};

$ClassInfo _Comment_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"Comment",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Comment_MethodInfo_
};

$Object* allocate$Comment($Class* clazz) {
	return $of($alloc(Comment));
}

void Comment::init$() {
}

void Comment::main($StringArray* args) {
	$useLocalCurrentObjectStackCache();
	$var($File, f, $new($File, $($System::getProperty("test.src"_s, "."_s)), "input.txt"_s));
	int32_t slashIsCommentStart = 1;
	int32_t slashSlashComment = 2;
	int32_t slashStarComment = 4;
	for (int32_t i = 0; i < 8; ++i) {
		$var($FileReader, reader, $new($FileReader, f));
		{
			$var($Throwable, var$0, nullptr);
			try {
				$var($StreamTokenizer, st, $new($StreamTokenizer, static_cast<$Reader*>(reader)));
				bool slashCommentFlag = (((int32_t)(i & (uint32_t)slashIsCommentStart)) != 0);
				bool slashSlashCommentFlag = (((int32_t)(i & (uint32_t)slashSlashComment)) != 0);
				bool slashStarCommentFlag = (((int32_t)(i & (uint32_t)slashStarComment)) != 0);
				if (!slashCommentFlag) {
					st->ordinaryChar(u'/');
				}
				st->slashSlashComments(slashSlashCommentFlag);
				st->slashStarComments(slashStarCommentFlag);
				while (st->nextToken() != $StreamTokenizer::TT_EOF) {
					$var($String, token, st->sval);
					if (token == nullptr) {
						continue;
					} else {
						if (($nc(token)->compareTo("Error1"_s) == 0) && slashStarCommentFlag) {
							$throwNew($Exception, "Failed to pass one line C comments!"_s);
						}
						if (($nc(token)->compareTo("Error2"_s) == 0) && slashStarCommentFlag) {
							$throwNew($Exception, "Failed to pass multi line C comments!"_s);
						}
						if (($nc(token)->compareTo("Error3"_s) == 0) && slashSlashCommentFlag) {
							$throwNew($Exception, "Failed to pass C++ comments!"_s);
						}
						if (($nc(token)->compareTo("Error4"_s) == 0) && slashCommentFlag) {
							$throwNew($Exception, "Failed to pass / comments!"_s);
						}
					}
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				reader->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

Comment::Comment() {
}

$Class* Comment::load$($String* name, bool initialize) {
	$loadClass(Comment, name, initialize, &_Comment_ClassInfo_, allocate$Comment);
	return class$;
}

$Class* Comment::class$ = nullptr;
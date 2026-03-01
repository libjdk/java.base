#include <jdk/internal/util/xml/impl/Parser.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/lang/NumberFormatException.h>
#include <java/util/HashMap.h>
#include <java/util/Map.h>
#include <jdk/internal/org/xml/sax/InputSource.h>
#include <jdk/internal/util/xml/impl/Attrs.h>
#include <jdk/internal/util/xml/impl/Input.h>
#include <jdk/internal/util/xml/impl/Pair.h>
#include <jdk/internal/util/xml/impl/ReaderUTF16.h>
#include <jdk/internal/util/xml/impl/ReaderUTF8.h>
#include <jcpp.h>

#undef BUFFSIZE_PARSER
#undef BUFFSIZE_READER
#undef EOS
#undef EV_CDAT
#undef EV_COMM
#undef EV_DTD
#undef EV_ELM
#undef EV_ELME
#undef EV_ELMS
#undef EV_ENT
#undef EV_NULL
#undef EV_PI
#undef EV_TEXT
#undef EV_WSPC
#undef FAULT
#undef NONS
#undef PH_AFTER_DOC
#undef PH_BEFORE_DOC
#undef PH_DOCELM
#undef PH_DOCELM_MISC
#undef PH_DOC_START
#undef PH_DTD
#undef PH_DTD_MISC
#undef PH_MISC_DTD
#undef XML
#undef XMLNS

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $Reader = ::java::io::Reader;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $HashMap = ::java::util::HashMap;
using $Map = ::java::util::Map;
using $InputSource = ::jdk::internal::org::xml::sax::InputSource;
using $Attrs = ::jdk::internal::util::xml::impl::Attrs;
using $Input = ::jdk::internal::util::xml::impl::Input;
using $Pair = ::jdk::internal::util::xml::impl::Pair;
using $ReaderUTF16 = ::jdk::internal::util::xml::impl::ReaderUTF16;
using $ReaderUTF8 = ::jdk::internal::util::xml::impl::ReaderUTF8;

namespace jdk {
	namespace internal {
		namespace util {
			namespace xml {
				namespace impl {

$FieldInfo _Parser_FieldInfo_[] = {
	{"FAULT", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Parser, FAULT)},
	{"BUFFSIZE_READER", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, BUFFSIZE_READER)},
	{"BUFFSIZE_PARSER", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, BUFFSIZE_PARSER)},
	{"EOS", "C", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Parser, EOS)},
	{"mNoNS", "Ljdk/internal/util/xml/impl/Pair;", nullptr, $PRIVATE, $field(Parser, mNoNS)},
	{"mXml", "Ljdk/internal/util/xml/impl/Pair;", nullptr, $PRIVATE, $field(Parser, mXml)},
	{"mEnt", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljdk/internal/util/xml/impl/Input;>;", $PRIVATE, $field(Parser, mEnt)},
	{"mPEnt", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljdk/internal/util/xml/impl/Input;>;", $PRIVATE, $field(Parser, mPEnt)},
	{"mIsSAlone", "Z", nullptr, $PROTECTED, $field(Parser, mIsSAlone)},
	{"mIsSAloneSet", "Z", nullptr, $PROTECTED, $field(Parser, mIsSAloneSet)},
	{"mIsNSAware", "Z", nullptr, $PROTECTED, $field(Parser, mIsNSAware)},
	{"mPh", "I", nullptr, $PROTECTED, $field(Parser, mPh)},
	{"PH_BEFORE_DOC", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, PH_BEFORE_DOC)},
	{"PH_DOC_START", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, PH_DOC_START)},
	{"PH_MISC_DTD", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, PH_MISC_DTD)},
	{"PH_DTD", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, PH_DTD)},
	{"PH_DTD_MISC", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, PH_DTD_MISC)},
	{"PH_DOCELM", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, PH_DOCELM)},
	{"PH_DOCELM_MISC", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, PH_DOCELM_MISC)},
	{"PH_AFTER_DOC", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, PH_AFTER_DOC)},
	{"mEvt", "I", nullptr, $PROTECTED, $field(Parser, mEvt)},
	{"EV_NULL", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_NULL)},
	{"EV_ELM", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_ELM)},
	{"EV_ELMS", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_ELMS)},
	{"EV_ELME", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_ELME)},
	{"EV_TEXT", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_TEXT)},
	{"EV_WSPC", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_WSPC)},
	{"EV_PI", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_PI)},
	{"EV_CDAT", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_CDAT)},
	{"EV_COMM", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_COMM)},
	{"EV_DTD", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_DTD)},
	{"EV_ENT", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(Parser, EV_ENT)},
	{"mESt", "C", nullptr, $PRIVATE, $field(Parser, mESt)},
	{"mBuff", "[C", nullptr, $PROTECTED, $field(Parser, mBuff)},
	{"mBuffIdx", "I", nullptr, $PROTECTED, $field(Parser, mBuffIdx)},
	{"mPref", "Ljdk/internal/util/xml/impl/Pair;", nullptr, $PROTECTED, $field(Parser, mPref)},
	{"mElm", "Ljdk/internal/util/xml/impl/Pair;", nullptr, $PROTECTED, $field(Parser, mElm)},
	{"mAttL", "Ljdk/internal/util/xml/impl/Pair;", nullptr, $PROTECTED, $field(Parser, mAttL)},
	{"mDoc", "Ljdk/internal/util/xml/impl/Input;", nullptr, $PROTECTED, $field(Parser, mDoc)},
	{"mInp", "Ljdk/internal/util/xml/impl/Input;", nullptr, $PROTECTED, $field(Parser, mInp)},
	{"mChars", "[C", nullptr, $PRIVATE, $field(Parser, mChars)},
	{"mChLen", "I", nullptr, $PRIVATE, $field(Parser, mChLen)},
	{"mChIdx", "I", nullptr, $PRIVATE, $field(Parser, mChIdx)},
	{"mAttrs", "Ljdk/internal/util/xml/impl/Attrs;", nullptr, $PROTECTED, $field(Parser, mAttrs)},
	{"mItems", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(Parser, mItems)},
	{"mAttrIdx", "C", nullptr, $PRIVATE, $field(Parser, mAttrIdx)},
	{"mUnent", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Parser, mUnent)},
	{"mDltd", "Ljdk/internal/util/xml/impl/Pair;", nullptr, $PRIVATE, $field(Parser, mDltd)},
	{"NONS", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Parser, NONS)},
	{"XML", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Parser, XML)},
	{"XMLNS", "[C", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Parser, XMLNS)},
	{"asctyp", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Parser, asctyp)},
	{"nmttyp", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Parser, nmttyp)},
	{}
};

$MethodInfo _Parser_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(Parser, init$, void)},
	{"attr", "(Ljdk/internal/util/xml/impl/Pair;)V", nullptr, $PRIVATE, $method(Parser, attr, void, $Pair*), "java.lang.Exception"},
	{"atype", "(Ljdk/internal/util/xml/impl/Pair;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Parser, atype, $String*, $Pair*), "java.lang.Exception"},
	{"bappend", "(CC)V", nullptr, $PRIVATE, $method(Parser, bappend, void, char16_t, char16_t)},
	{"bappend", "(C)V", nullptr, $PRIVATE, $method(Parser, bappend, void, char16_t)},
	{"bcopy", "(II)V", nullptr, $PRIVATE, $method(Parser, bcopy, void, int32_t, int32_t)},
	{"bflash", "()V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, bflash, void), "java.lang.Exception"},
	{"bflash_ws", "()V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, bflash_ws, void), "java.lang.Exception"},
	{"bkch", "()V", nullptr, $PROTECTED, $virtualMethod(Parser, bkch, void), "java.lang.Exception"},
	{"bkeyword", "()C", nullptr, $PRIVATE, $method(Parser, bkeyword, char16_t), "java.lang.Exception"},
	{"bname", "(Z)V", nullptr, $PRIVATE, $method(Parser, bname, void, bool), "java.lang.Exception"},
	{"bntok", "()V", nullptr, $PRIVATE, $method(Parser, bntok, void), "java.lang.Exception"},
	{"bom", "(Ljava/io/InputStream;C)Ljava/io/Reader;", nullptr, $PRIVATE, $method(Parser, bom, $Reader*, $InputStream*, char16_t), "java.lang.Exception"},
	{"bqstr", "(C)V", nullptr, $PRIVATE, $method(Parser, bqstr, void, char16_t), "java.lang.Exception"},
	{"cdat", "()V", nullptr, $PRIVATE, $method(Parser, cdat, void), "java.lang.Exception"},
	{"chtyp", "(C)C", nullptr, $PROTECTED, $virtualMethod(Parser, chtyp, char16_t, char16_t)},
	{"cleanup", "()V", nullptr, $PROTECTED, $virtualMethod(Parser, cleanup, void)},
	{"comm", "()V", nullptr, $PRIVATE, $method(Parser, comm, void), "java.lang.Exception"},
	{"comm", "([CI)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, comm, void, $chars*, int32_t)},
	{"del", "(Ljdk/internal/util/xml/impl/Pair;)Ljdk/internal/util/xml/impl/Pair;", nullptr, $PROTECTED, $virtualMethod(Parser, del, $Pair*, $Pair*)},
	{"docType", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, docType, void, $String*, $String*, $String*), "jdk.internal.org.xml.sax.SAXException"},
	{"dtd", "()V", nullptr, $PRIVATE, $method(Parser, dtd, void), "java.lang.Exception"},
	{"dtdatt", "(Ljdk/internal/util/xml/impl/Pair;)V", nullptr, $PRIVATE, $method(Parser, dtdatt, void, $Pair*), "java.lang.Exception"},
	{"dtdattl", "()V", nullptr, $PRIVATE, $method(Parser, dtdattl, void), "java.lang.Exception"},
	{"dtdelm", "()V", nullptr, $PRIVATE, $method(Parser, dtdelm, void), "java.lang.Exception"},
	{"dtdent", "()V", nullptr, $PRIVATE, $method(Parser, dtdent, void), "java.lang.Exception"},
	{"dtdnot", "()V", nullptr, $PRIVATE, $method(Parser, dtdnot, void), "java.lang.Exception"},
	{"dtdsub", "()V", nullptr, $PRIVATE, $method(Parser, dtdsub, void), "java.lang.Exception"},
	{"eappend", "(C)V", nullptr, $PRIVATE, $method(Parser, eappend, void, char16_t)},
	{"enc", "(Ljava/lang/String;Ljava/io/InputStream;)Ljava/io/Reader;", nullptr, $PRIVATE, $method(Parser, enc, $Reader*, $String*, $InputStream*), "java.io.UnsupportedEncodingException"},
	{"ent", "(C)Ljava/lang/String;", nullptr, $PRIVATE, $method(Parser, ent, $String*, char16_t), "java.lang.Exception"},
	{"eqstr", "(C)Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(Parser, eqstr, $String*, char16_t), "java.lang.Exception"},
	{"find", "(Ljdk/internal/util/xml/impl/Pair;[C)Ljdk/internal/util/xml/impl/Pair;", nullptr, $PROTECTED, $virtualMethod(Parser, find, $Pair*, $Pair*, $chars*)},
	{"getch", "()C", nullptr, $PROTECTED, $virtualMethod(Parser, getch, char16_t), "java.io.IOException"},
	{"init", "()V", nullptr, $PROTECTED, $virtualMethod(Parser, init, void)},
	{"isdecl", "(Ljdk/internal/util/xml/impl/Pair;Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(Parser, isdecl, bool, $Pair*, $String*)},
	{"name", "(Z)Ljava/lang/String;", nullptr, $PROTECTED, $virtualMethod(Parser, name, $String*, bool), "java.lang.Exception"},
	{"newPrefix", "()V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, newPrefix, void), "java.lang.Exception"},
	{"notDecl", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, notDecl, void, $String*, $String*, $String*), "java.lang.Exception"},
	{"pair", "(Ljdk/internal/util/xml/impl/Pair;)Ljdk/internal/util/xml/impl/Pair;", nullptr, $PROTECTED, $virtualMethod(Parser, pair, $Pair*, $Pair*)},
	{"panic", "(Ljava/lang/String;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, panic, void, $String*), "java.lang.Exception"},
	{"pent", "(C)V", nullptr, $PRIVATE, $method(Parser, pent, void, char16_t), "java.lang.Exception"},
	{"pi", "()V", nullptr, $PRIVATE, $method(Parser, pi, void), "java.lang.Exception"},
	{"pi", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, pi, void, $String*, $String*), "java.lang.Exception"},
	{"pop", "()V", nullptr, $PROTECTED, $virtualMethod(Parser, pop, void)},
	{"pubsys", "(Ljdk/internal/util/xml/impl/Input;)V", nullptr, $PRIVATE, $method(Parser, pubsys, void, $Input*), "java.lang.Exception"},
	{"pubsys", "(C)Ljdk/internal/util/xml/impl/Pair;", nullptr, $PRIVATE, $method(Parser, pubsys, $Pair*, char16_t), "java.lang.Exception"},
	{"push", "(Ljdk/internal/util/xml/impl/Input;)V", nullptr, $PROTECTED, $virtualMethod(Parser, push, void, $Input*)},
	{"qname", "(Z)[C", nullptr, $PROTECTED, $virtualMethod(Parser, qname, $chars*, bool), "java.lang.Exception"},
	{"resolveEnt", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljdk/internal/org/xml/sax/InputSource;", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, resolveEnt, $InputSource*, $String*, $String*, $String*), "java.lang.Exception"},
	{"rslv", "([C)Ljava/lang/String;", nullptr, $PRIVATE, $method(Parser, rslv, $String*, $chars*), "java.lang.Exception"},
	{"setch", "(C)V", nullptr, $PROTECTED, $virtualMethod(Parser, setch, void, char16_t)},
	{"setinp", "(Ljdk/internal/org/xml/sax/InputSource;)V", nullptr, $PROTECTED, $virtualMethod(Parser, setinp, void, $InputSource*), "java.lang.Exception"},
	{"skippedEnt", "(Ljava/lang/String;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, skippedEnt, void, $String*), "java.lang.Exception"},
	{"startInternalSub", "()V", nullptr, $PUBLIC | $ABSTRACT, $virtualMethod(Parser, startInternalSub, void), "jdk.internal.org.xml.sax.SAXException"},
	{"step", "()I", nullptr, $PROTECTED, $virtualMethod(Parser, step, int32_t), "java.lang.Exception"},
	{"unparsedEntDecl", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PROTECTED | $ABSTRACT, $virtualMethod(Parser, unparsedEntDecl, void, $String*, $String*, $String*, $String*), "java.lang.Exception"},
	{"utf16", "(Ljava/io/InputStream;)Ljava/io/Reader;", nullptr, $PRIVATE, $method(Parser, utf16, $Reader*, $InputStream*), "java.lang.Exception"},
	{"wsskip", "()C", nullptr, $PROTECTED, $virtualMethod(Parser, wsskip, char16_t), "java.io.IOException"},
	{"xml", "(Ljava/io/Reader;)Ljava/lang/String;", nullptr, $PRIVATE, $method(Parser, xml, $String*, $Reader*), "java.lang.Exception"},
	{}
};

$ClassInfo _Parser_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.util.xml.impl.Parser",
	"java.lang.Object",
	nullptr,
	_Parser_FieldInfo_,
	_Parser_MethodInfo_
};

$Object* allocate$Parser($Class* clazz) {
	return $of($alloc(Parser));
}

$String* Parser::FAULT = nullptr;
$chars* Parser::NONS = nullptr;
$chars* Parser::XML = nullptr;
$chars* Parser::XMLNS = nullptr;
$bytes* Parser::asctyp = nullptr;
$bytes* Parser::nmttyp = nullptr;

void Parser::init$() {
	this->mPh = Parser::PH_BEFORE_DOC;
	$set(this, mBuff, $new($chars, Parser::BUFFSIZE_PARSER));
	$set(this, mAttrs, $new($Attrs));
	$set(this, mPref, pair(this->mPref));
	$set($nc(this->mPref), name, ""_s);
	$set($nc(this->mPref), value, ""_s);
	$set($nc(this->mPref), chars, Parser::NONS);
	$set(this, mNoNS, this->mPref);
	$set(this, mPref, pair(this->mPref));
	$set($nc(this->mPref), name, "xml"_s);
	$set($nc(this->mPref), value, "http://www.w3.org/XML/1998/namespace"_s);
	$set($nc(this->mPref), chars, Parser::XML);
	$set(this, mXml, this->mPref);
}

void Parser::init() {
	$set(this, mUnent, nullptr);
	$set(this, mElm, nullptr);
	$set(this, mPref, this->mXml);
	$set(this, mAttL, nullptr);
	$set(this, mPEnt, $new($HashMap));
	$set(this, mEnt, $new($HashMap));
	$set(this, mDoc, this->mInp);
	$set(this, mChars, $nc(this->mInp)->chars);
	this->mPh = Parser::PH_DOC_START;
}

void Parser::cleanup() {
	while (this->mAttL != nullptr) {
		while ($nc(this->mAttL)->list != nullptr) {
			if ($nc($nc(this->mAttL)->list)->list != nullptr) {
				del($nc($nc(this->mAttL)->list)->list);
			}
			$set($nc(this->mAttL), list, del($nc(this->mAttL)->list));
		}
		$set(this, mAttL, del(this->mAttL));
	}
	while (this->mElm != nullptr) {
		$set(this, mElm, del(this->mElm));
	}
	while (this->mPref != this->mXml) {
		$set(this, mPref, del(this->mPref));
	}
	while (this->mInp != nullptr) {
		pop();
	}
	if ((this->mDoc != nullptr) && ($nc(this->mDoc)->src != nullptr)) {
		try {
			$nc($nc(this->mDoc)->src)->close();
		} catch ($IOException& ioe) {
		}
	}
	$set(this, mPEnt, nullptr);
	$set(this, mEnt, nullptr);
	$set(this, mDoc, nullptr);
	this->mPh = Parser::PH_AFTER_DOC;
}

int32_t Parser::step() {
	$useLocalCurrentObjectStackCache();
	this->mEvt = Parser::EV_NULL;
	int32_t st = 0;
	while (this->mEvt == Parser::EV_NULL) {
		char16_t ch = (this->mChIdx < this->mChLen) ? $nc(this->mChars)->get(this->mChIdx++) : getch();
		switch (st) {
		case 0:
			{
				if (ch != u'<') {
					bkch();
					this->mBuffIdx = -1;
					st = 1;
					break;
				}
				{
					$var($chars, chars, nullptr)
					$var($Pair, elm, nullptr)
					$var($Pair, att, nullptr)
					switch (getch()) {
					case u'/':
						{
							this->mEvt = Parser::EV_ELME;
							if (this->mElm == nullptr) {
								panic(Parser::FAULT);
							}
							this->mBuffIdx = -1;
							bname(this->mIsNSAware);
							$assign(chars, $nc(this->mElm)->chars);
							if ($nc(chars)->length == (this->mBuffIdx + 1)) {
								for (char16_t i = (char16_t)1; i <= this->mBuffIdx; i += 1) {
									if (chars->get(i) != $nc(this->mBuff)->get(i)) {
										panic(Parser::FAULT);
									}
								}
							} else {
								panic(Parser::FAULT);
							}
							if (wsskip() != u'>') {
								panic(Parser::FAULT);
							}
							getch();
							break;
						}
					case u'!':
						{
							ch = getch();
							bkch();
							switch (ch) {
							case u'-':
								{
									this->mEvt = Parser::EV_COMM;
									comm();
									break;
								}
							case u'[':
								{
									this->mEvt = Parser::EV_CDAT;
									cdat();
									break;
								}
							default:
								{
									this->mEvt = Parser::EV_DTD;
									dtd();
									break;
								}
							}
							break;
						}
					case u'?':
						{
							this->mEvt = Parser::EV_PI;
							pi();
							break;
						}
					default:
						{
							bkch();
							$set(this, mElm, pair(this->mElm));
							$set($nc(this->mElm), chars, qname(this->mIsNSAware));
							$set($nc(this->mElm), name, $nc(this->mElm)->local());
							$nc(this->mElm)->id = ($nc(this->mElm)->next != nullptr) ? $nc($nc(this->mElm)->next)->id : 0;
							$nc(this->mElm)->num = 0;
							$assign(elm, find(this->mAttL, $nc(this->mElm)->chars));
							$set($nc(this->mElm), list, (elm != nullptr) ? $nc(elm)->list : ($Pair*)nullptr);
							this->mAttrIdx = (char16_t)0;
							$assign(att, pair(nullptr));
							$nc(att)->num = 0;
							attr(att);
							del(att);
							$set($nc(this->mElm), value, (this->mIsNSAware) ? rslv($nc(this->mElm)->chars) : ($String*)nullptr);
							switch (wsskip()) {
							case u'>':
								{
									getch();
									this->mEvt = Parser::EV_ELMS;
									break;
								}
							case u'/':
								{
									getch();
									if (getch() != u'>') {
										panic(Parser::FAULT);
									}
									this->mEvt = Parser::EV_ELM;
									break;
								}
							default:
								{
									panic(Parser::FAULT);
								}
							}
							break;
						}
					}
				}
				break;
			}
		case 1:
			{
				switch (ch) {
				case u' ':
					{}
				case u'\t':
					{}
				case u'\n':
					{
						bappend(ch);
						break;
					}
				case u'\r':
					{
						if (getch() != u'\n') {
							bkch();
						}
						bappend(u'\n');
						break;
					}
				case u'<':
					{
						this->mEvt = Parser::EV_WSPC;
						bkch();
						bflash_ws();
						break;
					}
				default:
					{
						bkch();
						st = 2;
						break;
					}
				}
				break;
			}
		case 2:
			{
				switch (ch) {
				case u'&':
					{
						if (this->mUnent == nullptr) {
							if (($set(this, mUnent, ent(u'x'))) != nullptr) {
								this->mEvt = Parser::EV_TEXT;
								bkch();
								setch(u'&');
								bflash();
							}
						} else {
							this->mEvt = Parser::EV_ENT;
							skippedEnt(this->mUnent);
							$set(this, mUnent, nullptr);
						}
						break;
					}
				case u'<':
					{
						this->mEvt = Parser::EV_TEXT;
						bkch();
						bflash();
						break;
					}
				case u'\r':
					{
						if (getch() != u'\n') {
							bkch();
						}
						bappend(u'\n');
						break;
					}
				case Parser::EOS:
					{
						panic(Parser::FAULT);
					}
				default:
					{
						bappend(ch);
						break;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
	return this->mEvt;
}

void Parser::dtd() {
	$useLocalCurrentObjectStackCache();
	char16_t ch = 0;
	$var($String, str, nullptr);
	$var($String, name, nullptr);
	$var($Pair, psid, nullptr);
	if ("DOCTYPE"_s->equals($(this->name(false))) != true) {
		panic(Parser::FAULT);
	}
	this->mPh = Parser::PH_DTD;
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = getch();
		switch (st) {
		case 0:
			{
				if (chtyp(ch) != u' ') {
					bkch();
					$assign(name, this->name(this->mIsNSAware));
					wsskip();
					st = (int16_t)1;
				}
				break;
			}
		case 1:
			{
				switch (chtyp(ch)) {
				case u'A':
					{
						bkch();
						$assign(psid, pubsys(u' '));
						st = (int16_t)2;
						docType(name, $nc(psid)->name, psid->value);
						break;
					}
				case u'[':
					{
						bkch();
						st = (int16_t)2;
						docType(name, nullptr, nullptr);
						break;
					}
				case u'>':
					{
						bkch();
						st = (int16_t)3;
						docType(name, nullptr, nullptr);
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		case 2:
			{
				switch (chtyp(ch)) {
				case u'[':
					{
						dtdsub();
						st = (int16_t)3;
						break;
					}
				case u'>':
					{
						bkch();
						st = (int16_t)3;
						break;
					}
				case u' ':
					{
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		case 3:
			{
				switch (chtyp(ch)) {
				case u'>':
					{
						if (psid != nullptr) {
							$var($InputSource, is, resolveEnt(name, psid->name, psid->value));
							if (is != nullptr) {
								if (this->mIsSAlone == false) {
									bkch();
									setch(u']');
									push($$new($Input, Parser::BUFFSIZE_READER));
									setinp(is);
									$set($nc(this->mInp), pubid, psid->name);
									$set($nc(this->mInp), sysid, psid->value);
									dtdsub();
								} else {
									skippedEnt("[dtd]"_s);
									if (is->getCharacterStream() != nullptr) {
										try {
											$nc($(is->getCharacterStream()))->close();
										} catch ($IOException& ioe) {
										}
									}
									if (is->getByteStream() != nullptr) {
										try {
											$nc($(is->getByteStream()))->close();
										} catch ($IOException& ioe) {
										}
									}
								}
							} else {
								skippedEnt("[dtd]"_s);
							}
							del(psid);
						}
						st = (int16_t)-1;
						break;
					}
				case u' ':
					{
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
}

void Parser::dtdsub() {
	startInternalSub();
	char16_t ch = 0;
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = getch();
		switch (st) {
		case 0:
			{
				switch (chtyp(ch)) {
				case u'<':
					{
						ch = getch();
						switch (ch) {
						case u'?':
							{
								pi();
								break;
							}
						case u'!':
							{
								ch = getch();
								bkch();
								if (ch == u'-') {
									comm();
									break;
								}
								bntok();
								switch (bkeyword()) {
								case u'n':
									{
										dtdent();
										break;
									}
								case u'a':
									{
										dtdattl();
										break;
									}
								case u'e':
									{
										dtdelm();
										break;
									}
								case u'o':
									{
										dtdnot();
										break;
									}
								default:
									{
										panic(Parser::FAULT);
										break;
									}
								}
								st = (int16_t)1;
								break;
							}
						default:
							{
								panic(Parser::FAULT);
								break;
							}
						}
						break;
					}
				case u'%':
					{
						pent(u' ');
						break;
					}
				case u']':
					{
						st = (int16_t)-1;
						break;
					}
				case u' ':
					{
						break;
					}
				case u'Z':
					{
						if (getch() != u']') {
							panic(Parser::FAULT);
						}
						st = (int16_t)-1;
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		case 1:
			{
				switch (ch) {
				case u'>':
					{
						st = (int16_t)0;
						break;
					}
				case u' ':
					{}
				case u'\n':
					{}
				case u'\r':
					{}
				case u'\t':
					{
						break;
					}
				default:
					{
						panic(Parser::FAULT);
						break;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
}

void Parser::dtdent() {
	$useLocalCurrentObjectStackCache();
	$var($String, str, nullptr);
	$var($chars, val, nullptr);
	$var($Input, inp, nullptr);
	$var($Pair, ids, nullptr);
	char16_t ch = 0;
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = getch();
		switch (st) {
		case 0:
			{
				switch (chtyp(ch)) {
				case u' ':
					{
						break;
					}
				case u'%':
					{
						ch = getch();
						bkch();
						if (chtyp(ch) == u' ') {
							wsskip();
							$assign(str, name(false));
							switch (chtyp(wsskip())) {
							case u'A':
								{
									$assign(ids, pubsys(u' '));
									if (wsskip() == u'>') {
										if ($nc(this->mPEnt)->containsKey(str) == false) {
											$assign(inp, $new($Input));
											$set(inp, pubid, $nc(ids)->name);
											$set(inp, sysid, ids->value);
											$nc(this->mPEnt)->put(str, inp);
										}
									} else {
										panic(Parser::FAULT);
									}
									del(ids);
									st = (int16_t)-1;
									break;
								}
							case u'\"':
								{}
							case u'\'':
								{
									bqstr(u'd');
									$assign(val, $new($chars, this->mBuffIdx + 1));
									$System::arraycopy(this->mBuff, 1, val, 1, $nc(val)->length - 1);
									$nc(val)->set(0, u' ');
									if ($nc(this->mPEnt)->containsKey(str) == false) {
										$assign(inp, $new($Input, val));
										$set(inp, pubid, $nc(this->mInp)->pubid);
										$set(inp, sysid, $nc(this->mInp)->sysid);
										$set(inp, xmlenc, $nc(this->mInp)->xmlenc);
										inp->xmlver = $nc(this->mInp)->xmlver;
										$nc(this->mPEnt)->put(str, inp);
									}
									st = (int16_t)-1;
									break;
								}
							default:
								{
									panic(Parser::FAULT);
									break;
								}
							}
						} else {
							pent(u' ');
						}
						break;
					}
				default:
					{
						bkch();
						$assign(str, name(false));
						st = (int16_t)1;
						break;
					}
				}
				break;
			}
		case 1:
			{
				switch (chtyp(ch)) {
				case u'\"':
					{}
				case u'\'':
					{
						bkch();
						bqstr(u'd');
						if ($nc(this->mEnt)->get(str) == nullptr) {
							$assign(val, $new($chars, this->mBuffIdx));
							$System::arraycopy(this->mBuff, 1, val, 0, val->length);
							if ($nc(this->mEnt)->containsKey(str) == false) {
								$assign(inp, $new($Input, val));
								$set(inp, pubid, $nc(this->mInp)->pubid);
								$set(inp, sysid, $nc(this->mInp)->sysid);
								$set(inp, xmlenc, $nc(this->mInp)->xmlenc);
								inp->xmlver = $nc(this->mInp)->xmlver;
								$nc(this->mEnt)->put(str, inp);
							}
						}
						st = (int16_t)-1;
						break;
					}
				case u'A':
					{
						bkch();
						$assign(ids, pubsys(u' '));
						switch (wsskip()) {
						case u'>':
							{
								if ($nc(this->mEnt)->containsKey(str) == false) {
									$assign(inp, $new($Input));
									$set(inp, pubid, $nc(ids)->name);
									$set(inp, sysid, ids->value);
									$nc(this->mEnt)->put(str, inp);
								}
								break;
							}
						case u'N':
							{
								if ("NDATA"_s->equals($(name(false))) == true) {
									wsskip();
									unparsedEntDecl(str, $nc(ids)->name, ids->value, $(name(false)));
									break;
								}
							}
						default:
							{
								panic(Parser::FAULT);
								break;
							}
						}
						del(ids);
						st = (int16_t)-1;
						break;
					}
				case u' ':
					{
						break;
					}
				default:
					{
						panic(Parser::FAULT);
						break;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
}

void Parser::dtdelm() {
	wsskip();
	name(this->mIsNSAware);
	char16_t ch = 0;
	while (true) {
		ch = getch();
		switch (ch) {
		case u'>':
			{
				bkch();
				return;
			}
		case Parser::EOS:
			{
				panic(Parser::FAULT);
			}
		default:
			{
				break;
			}
		}
	}
}

void Parser::dtdattl() {
	$useLocalCurrentObjectStackCache();
	$var($chars, elmqn, nullptr);
	$var($Pair, elm, nullptr);
	char16_t ch = 0;
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = getch();
		switch (st) {
		case 0:
			{
				switch (chtyp(ch)) {
				case u'a':
					{}
				case u'A':
					{}
				case u'_':
					{}
				case u'X':
					{}
				case u':':
					{
						bkch();
						$assign(elmqn, qname(this->mIsNSAware));
						$assign(elm, find(this->mAttL, elmqn));
						if (elm == nullptr) {
							$assign(elm, pair(this->mAttL));
							$set($nc(elm), chars, elmqn);
							$set(this, mAttL, elm);
						}
						st = (int16_t)1;
						break;
					}
				case u' ':
					{
						break;
					}
				case u'%':
					{
						pent(u' ');
						break;
					}
				default:
					{
						panic(Parser::FAULT);
						break;
					}
				}
				break;
			}
		case 1:
			{
				switch (chtyp(ch)) {
				case u'a':
					{}
				case u'A':
					{}
				case u'_':
					{}
				case u'X':
					{}
				case u':':
					{
						bkch();
						dtdatt(elm);
						if (wsskip() == u'>') {
							return;
						}
						break;
					}
				case u' ':
					{
						break;
					}
				case u'%':
					{
						pent(u' ');
						break;
					}
				default:
					{
						panic(Parser::FAULT);
						break;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
				break;
			}
		}
	}
}

void Parser::dtdatt($Pair* elm) {
	$useLocalCurrentObjectStackCache();
	$var($chars, attqn, nullptr);
	$var($Pair, att, nullptr);
	char16_t ch = 0;
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = getch();
		switch (st) {
		case 0:
			{
				switch (chtyp(ch)) {
				case u'a':
					{}
				case u'A':
					{}
				case u'_':
					{}
				case u'X':
					{}
				case u':':
					{
						bkch();
						$assign(attqn, qname(this->mIsNSAware));
						$assign(att, find($nc(elm)->list, attqn));
						if (att == nullptr) {
							$assign(att, pair($nc(elm)->list));
							$set($nc(att), chars, attqn);
							$set($nc(elm), list, att);
						} else {
							$assign(att, pair(nullptr));
							$set($nc(att), chars, attqn);
							att->id = u'c';
						}
						wsskip();
						st = (int16_t)1;
						break;
					}
				case u'%':
					{
						pent(u' ');
						break;
					}
				case u' ':
					{
						break;
					}
				default:
					{
						panic(Parser::FAULT);
						break;
					}
				}
				break;
			}
		case 1:
			{
				switch (chtyp(ch)) {
				case u'(':
					{
						$nc(att)->id = u'u';
						st = (int16_t)2;
						break;
					}
				case u'%':
					{
						pent(u' ');
						break;
					}
				case u' ':
					{
						break;
					}
				default:
					{
						bkch();
						bntok();
						$nc(att)->id = bkeyword();
						switch ($nc(att)->id) {
						case u'o':
							{
								if (wsskip() != u'(') {
									panic(Parser::FAULT);
								}
								ch = getch();
								st = (int16_t)2;
								break;
							}
						case u'i':
							{}
						case u'r':
							{}
						case u'R':
							{}
						case u'n':
							{}
						case u'N':
							{}
						case u't':
							{}
						case u'T':
							{}
						case u'c':
							{
								wsskip();
								st = (int16_t)4;
								break;
							}
						default:
							{
								panic(Parser::FAULT);
								break;
							}
						}
						break;
					}
				}
				break;
			}
		case 2:
			{
				switch (chtyp(ch)) {
				case u'a':
					{}
				case u'A':
					{}
				case u'd':
					{}
				case u'.':
					{}
				case u':':
					{}
				case u'-':
					{}
				case u'_':
					{}
				case u'X':
					{
						bkch();
						switch ($nc(att)->id) {
						case u'u':
							{
								bntok();
								break;
							}
						case u'o':
							{
								this->mBuffIdx = -1;
								bname(false);
								break;
							}
						default:
							{
								panic(Parser::FAULT);
								break;
							}
						}
						wsskip();
						st = (int16_t)3;
						break;
					}
				case u'%':
					{
						pent(u' ');
						break;
					}
				case u' ':
					{
						break;
					}
				default:
					{
						panic(Parser::FAULT);
						break;
					}
				}
				break;
			}
		case 3:
			{
				switch (ch) {
				case u')':
					{
						wsskip();
						st = (int16_t)4;
						break;
					}
				case u'|':
					{
						wsskip();
						switch ($nc(att)->id) {
						case u'u':
							{
								bntok();
								break;
							}
						case u'o':
							{
								this->mBuffIdx = -1;
								bname(false);
								break;
							}
						default:
							{
								panic(Parser::FAULT);
								break;
							}
						}
						wsskip();
						break;
					}
				case u'%':
					{
						pent(u' ');
						break;
					}
				default:
					{
						panic(Parser::FAULT);
						break;
					}
				}
				break;
			}
		case 4:
			{
				switch (ch) {
				case u'#':
					{
						bntok();
						switch (bkeyword()) {
						case u'F':
							{
								switch (wsskip()) {
								case u'\"':
									{}
								case u'\'':
									{
										st = (int16_t)5;
										break;
									}
								case Parser::EOS:
									{
										panic(Parser::FAULT);
									}
								default:
									{
										st = (int16_t)-1;
										break;
									}
								}
								break;
							}
						case u'Q':
							{}
						case u'I':
							{
								st = (int16_t)-1;
								break;
							}
						default:
							{
								panic(Parser::FAULT);
								break;
							}
						}
						break;
					}
				case u'\"':
					{}
				case u'\'':
					{
						bkch();
						st = (int16_t)5;
						break;
					}
				case u' ':
					{}
				case u'\n':
					{}
				case u'\r':
					{}
				case u'\t':
					{
						break;
					}
				case u'%':
					{
						pent(u' ');
						break;
					}
				default:
					{
						bkch();
						st = (int16_t)-1;
						break;
					}
				}
				break;
			}
		case 5:
			{
				switch (ch) {
				case u'\"':
					{}
				case u'\'':
					{
						bkch();
						bqstr(u'd');
						$set($nc(att), list, pair(nullptr));
						$set($nc($nc(att)->list), chars, $new($chars, $nc(att->chars)->length + this->mBuffIdx + 3));
						$System::arraycopy($nc(att)->chars, 1, $nc(att->list)->chars, 0, $nc(att->chars)->length - 1);
						$nc($nc($nc(att)->list)->chars)->set($nc(att->chars)->length - 1, u'=');
						$nc($nc($nc(att)->list)->chars)->set($nc(att->chars)->length, ch);
						$System::arraycopy(this->mBuff, 1, $nc($nc(att)->list)->chars, $nc(att->chars)->length + 1, this->mBuffIdx);
						$nc($nc($nc(att)->list)->chars)->set($nc(att->chars)->length + this->mBuffIdx + 1, ch);
						$nc($nc($nc(att)->list)->chars)->set($nc(att->chars)->length + this->mBuffIdx + 2, u' ');
						st = (int16_t)-1;
						break;
					}
				default:
					{
						panic(Parser::FAULT);
						break;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
				break;
			}
		}
	}
}

void Parser::dtdnot() {
	$useLocalCurrentObjectStackCache();
	wsskip();
	$var($String, name, this->name(false));
	wsskip();
	$var($Pair, ids, pubsys(u'N'));
	notDecl(name, $nc(ids)->name, ids->value);
	del(ids);
}

void Parser::attr($Pair* att) {
	$useLocalCurrentObjectStackCache();
	{
		$var($String, type, nullptr)
		$var($String, val, nullptr)
		$var($Pair, next, nullptr)
		switch (wsskip()) {
		case u'/':
			{}
		case u'>':
			{
				if (((int32_t)($nc(att)->num & (uint32_t)2)) == 0) {
					att->num |= 2;
					$var($Input, inp, this->mInp);
					{
						$var($Pair, def, $nc(this->mElm)->list);
						for (; def != nullptr; $assign(def, $nc(def)->next)) {
							if (def->list == nullptr) {
								continue;
							}
							$var($Pair, act, find(att->next, def->chars));
							if (act == nullptr) {
								push($$new($Input, $nc(def->list)->chars));
							}
						}
					}
					if (this->mInp != inp) {
						attr(att);
						return;
					}
				}
				$nc(this->mAttrs)->setLength(this->mAttrIdx);
				$set(this, mItems, $nc(this->mAttrs)->mItems);
				return;
			}
		case Parser::EOS:
			{
				panic(Parser::FAULT);
			}
		default:
			{
				$set($nc(att), chars, qname(this->mIsNSAware));
				$set($nc(att), name, att->local());
				$assign(type, atype(att));
				wsskip();
				if (getch() != u'=') {
					panic(Parser::FAULT);
				}
				bqstr((char16_t)$nc(att)->id);
				$assign(val, $new($String, this->mBuff, 1, this->mBuffIdx));
				$assign(next, pair(att));
				$nc(next)->num = ((int32_t)($nc(att)->num & (uint32_t)~1));
				if ((this->mIsNSAware == false) || (isdecl(att, val) == false)) {
					++this->mAttrIdx;
					attr(next);
					--this->mAttrIdx;
					char16_t idx = (char16_t)(this->mAttrIdx << 3);
					$nc(this->mItems)->set(idx + 1, $($nc(att)->qname()));
					$nc(this->mItems)->set(idx + 2, (this->mIsNSAware) ? att->name : ""_s);
					$nc(this->mItems)->set(idx + 3, val);
					$nc(this->mItems)->set(idx + 4, type);
					switch ((int32_t)(att->num & (uint32_t)3)) {
					case 0:
						{
							$nc(this->mItems)->set(idx + 5, nullptr);
							break;
						}
					case 1:
						{
							$nc(this->mItems)->set(idx + 5, "d"_s);
							break;
						}
					default:
						{
							$nc(this->mItems)->set(idx + 5, "D"_s);
							break;
						}
					}
					$nc(this->mItems)->set(idx + 0, ($nc(att->chars)->get(0) != 0) ? $(rslv(att->chars)) : ""_s);
				} else {
					newPrefix();
					attr(next);
				}
				del(next);
				break;
			}
		}
	}
}

$String* Parser::atype($Pair* att) {
	$var($Pair, attr, nullptr);
	$nc(att)->id = u'c';
	if ($nc(this->mElm)->list == nullptr || ($assign(attr, find($nc(this->mElm)->list, att->chars))) == nullptr) {
		return "CDATA"_s;
	}
	att->num |= 1;
	att->id = u'i';
	switch ($nc(attr)->id) {
	case u'i':
		{
			return "ID"_s;
		}
	case u'r':
		{
			return "IDREF"_s;
		}
	case u'R':
		{
			return "IDREFS"_s;
		}
	case u'n':
		{
			return "ENTITY"_s;
		}
	case u'N':
		{
			return "ENTITIES"_s;
		}
	case u't':
		{
			return "NMTOKEN"_s;
		}
	case u'T':
		{
			return "NMTOKENS"_s;
		}
	case u'u':
		{
			return "NMTOKEN"_s;
		}
	case u'o':
		{
			return "NOTATION"_s;
		}
	case u'c':
		{
			att->id = u'c';
			return "CDATA"_s;
		}
	default:
		{
			panic(Parser::FAULT);
		}
	}
	return nullptr;
}

void Parser::comm() {
	if (this->mPh == Parser::PH_DOC_START) {
		this->mPh = Parser::PH_MISC_DTD;
	}
	char16_t ch = 0;
	this->mBuffIdx = -1;
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = (this->mChIdx < this->mChLen) ? $nc(this->mChars)->get(this->mChIdx++) : getch();
		if (ch == Parser::EOS) {
			panic(Parser::FAULT);
		}
		switch (st) {
		case 0:
			{
				if (ch == u'-') {
					st = (int16_t)1;
				} else {
					panic(Parser::FAULT);
				}
				break;
			}
		case 1:
			{
				if (ch == u'-') {
					st = (int16_t)2;
				} else {
					panic(Parser::FAULT);
				}
				break;
			}
		case 2:
			{
				switch (ch) {
				case u'-':
					{
						st = (int16_t)3;
						break;
					}
				default:
					{
						bappend(ch);
						break;
					}
				}
				break;
			}
		case 3:
			{
				switch (ch) {
				case u'-':
					{
						st = (int16_t)4;
						break;
					}
				default:
					{
						bappend(u'-');
						bappend(ch);
						st = (int16_t)2;
						break;
					}
				}
				break;
			}
		case 4:
			{
				if (ch == u'>') {
					comm(this->mBuff, this->mBuffIdx + 1);
					st = (int16_t)-1;
					break;
				}
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
}

void Parser::pi() {
	$useLocalCurrentObjectStackCache();
	char16_t ch = 0;
	$var($String, str, nullptr);
	this->mBuffIdx = -1;
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = getch();
		if (ch == Parser::EOS) {
			panic(Parser::FAULT);
		}
		switch (st) {
		case 0:
			{
				switch (chtyp(ch)) {
				case u'a':
					{}
				case u'A':
					{}
				case u'_':
					{}
				case u':':
					{}
				case u'X':
					{
						bkch();
						$assign(str, name(false));
						bool var$0 = ($nc(str)->isEmpty());
						if (var$0 || ($nc($nc(this->mXml)->name)->equals($($nc(str)->toLowerCase())) == true)) {
							panic(Parser::FAULT);
						}
						if (this->mPh == Parser::PH_DOC_START) {
							this->mPh = Parser::PH_MISC_DTD;
						}
						wsskip();
						st = (int16_t)1;
						this->mBuffIdx = -1;
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		case 1:
			{
				switch (ch) {
				case u'?':
					{
						st = (int16_t)2;
						break;
					}
				default:
					{
						bappend(ch);
						break;
					}
				}
				break;
			}
		case 2:
			{
				switch (ch) {
				case u'>':
					{
						pi(str, $$new($String, this->mBuff, 0, this->mBuffIdx + 1));
						st = (int16_t)-1;
						break;
					}
				case u'?':
					{
						bappend(u'?');
						break;
					}
				default:
					{
						bappend(u'?');
						bappend(ch);
						st = (int16_t)1;
						break;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
}

void Parser::cdat() {
	$useLocalCurrentObjectStackCache();
	char16_t ch = 0;
	this->mBuffIdx = -1;
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = getch();
		switch (st) {
		case 0:
			{
				if (ch == u'[') {
					st = (int16_t)1;
				} else {
					panic(Parser::FAULT);
				}
				break;
			}
		case 1:
			{
				if (chtyp(ch) == u'A') {
					bappend(ch);
				} else {
					if ("CDATA"_s->equals($$new($String, this->mBuff, 0, this->mBuffIdx + 1)) != true) {
						panic(Parser::FAULT);
					}
					bkch();
					st = (int16_t)2;
				}
				break;
			}
		case 2:
			{
				if (ch != u'[') {
					panic(Parser::FAULT);
				}
				this->mBuffIdx = -1;
				st = (int16_t)3;
				break;
			}
		case 3:
			{
				if (ch != u']') {
					bappend(ch);
				} else {
					st = (int16_t)4;
				}
				break;
			}
		case 4:
			{
				if (ch != u']') {
					bappend(u']');
					bappend(ch);
					st = (int16_t)3;
				} else {
					st = (int16_t)5;
				}
				break;
			}
		case 5:
			{
				switch (ch) {
				case u']':
					{
						bappend(u']');
						break;
					}
				case u'>':
					{
						bflash();
						st = (int16_t)-1;
						break;
					}
				default:
					{
						bappend(u']');
						bappend(u']');
						bappend(ch);
						st = (int16_t)3;
						break;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
}

$String* Parser::name(bool ns) {
	this->mBuffIdx = -1;
	bname(ns);
	return $new($String, this->mBuff, 1, this->mBuffIdx);
}

$chars* Parser::qname(bool ns) {
	this->mBuffIdx = -1;
	bname(ns);
	$var($chars, chars, $new($chars, this->mBuffIdx + 1));
	$System::arraycopy(this->mBuff, 0, chars, 0, this->mBuffIdx + 1);
	return chars;
}

void Parser::pubsys($Input* inp) {
	$var($Pair, pair, pubsys(u' '));
	$set($nc(inp), pubid, $nc(pair)->name);
	$set(inp, sysid, pair->value);
	del(pair);
}

$Pair* Parser::pubsys(char16_t flag) {
	$useLocalCurrentObjectStackCache();
	$var($Pair, ids, pair(nullptr));
	$var($String, str, name(false));
	if ("PUBLIC"_s->equals(str) == true) {
		bqstr(u'i');
		$set($nc(ids), name, $new($String, this->mBuff, 1, this->mBuffIdx));
		switch (wsskip()) {
		case u'\"':
			{}
		case u'\'':
			{
				bqstr(u' ');
				$set(ids, value, $new($String, this->mBuff, 1, this->mBuffIdx));
				break;
			}
		case Parser::EOS:
			{
				panic(Parser::FAULT);
			}
		default:
			{
				if (flag != u'N') {
					panic(Parser::FAULT);
				}
				$set(ids, value, nullptr);
				break;
			}
		}
		return ids;
	} else if ("SYSTEM"_s->equals(str) == true) {
		$set($nc(ids), name, nullptr);
		bqstr(u' ');
		$set(ids, value, $new($String, this->mBuff, 1, this->mBuffIdx));
		return ids;
	}
	panic(Parser::FAULT);
	return nullptr;
}

$String* Parser::eqstr(char16_t flag) {
	if (flag == u'=') {
		wsskip();
		if (getch() != u'=') {
			panic(Parser::FAULT);
		}
	}
	bqstr((flag == u'=') ? u'-' : flag);
	return $new($String, this->mBuff, 1, this->mBuffIdx);
}

$String* Parser::ent(char16_t flag) {
	$useLocalCurrentObjectStackCache();
	char16_t ch = 0;
	int32_t idx = this->mBuffIdx + 1;
	$var($Input, inp, nullptr);
	$var($String, str, nullptr);
	this->mESt = (char16_t)256;
	bappend(u'&');
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = (this->mChIdx < this->mChLen) ? $nc(this->mChars)->get(this->mChIdx++) : getch();
		switch (st) {
		case 0:
			{}
		case 1:
			{
				switch (chtyp(ch)) {
				case u'd':
					{}
				case u'.':
					{}
				case u'-':
					{
						if (st != 1) {
							panic(Parser::FAULT);
						}
					}
				case u'a':
					{}
				case u'A':
					{}
				case u'_':
					{}
				case u'X':
					{
						bappend(ch);
						eappend(ch);
						st = (int16_t)1;
						break;
					}
				case u':':
					{
						if (this->mIsNSAware != false) {
							panic(Parser::FAULT);
						}
						bappend(ch);
						eappend(ch);
						st = (int16_t)1;
						break;
					}
				case u';':
					{
						if (this->mESt < 256) {
							this->mBuffIdx = idx - 1;
							bappend(this->mESt);
							st = (int16_t)-1;
							break;
						} else if (this->mPh == Parser::PH_DTD) {
							bappend(u';');
							st = (int16_t)-1;
							break;
						}
						$assign(str, $new($String, this->mBuff, idx + 1, this->mBuffIdx - idx));
						$assign(inp, $cast($Input, $nc(this->mEnt)->get(str)));
						this->mBuffIdx = idx - 1;
						if (inp != nullptr) {
							if (inp->chars == nullptr) {
								$var($InputSource, is, resolveEnt(str, inp->pubid, inp->sysid));
								if (is != nullptr) {
									push($$new($Input, Parser::BUFFSIZE_READER));
									setinp(is);
									$set($nc(this->mInp), pubid, inp->pubid);
									$set($nc(this->mInp), sysid, inp->sysid);
									$assign(str, nullptr);
								} else if (flag != u'x') {
									panic(Parser::FAULT);
								}
							} else {
								push(inp);
								$assign(str, nullptr);
							}
						} else if (flag != u'x') {
							panic(Parser::FAULT);
						}
						st = (int16_t)-1;
						break;
					}
				case u'#':
					{
						if (st != 0) {
							panic(Parser::FAULT);
						}
						st = (int16_t)2;
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		case 2:
			{
				switch (chtyp(ch)) {
				case u'd':
					{
						bappend(ch);
						break;
					}
				case u';':
					{
						try {
							int32_t i = $Integer::parseInt($$new($String, this->mBuff, idx + 1, this->mBuffIdx - idx), 10);
							if (i >= 0x0000FFFF) {
								panic(Parser::FAULT);
							}
							ch = (char16_t)i;
						} catch ($NumberFormatException& nfe) {
							panic(Parser::FAULT);
						}
						this->mBuffIdx = idx - 1;
						if (ch == u' ' || $nc(this->mInp)->next != nullptr) {
							bappend(ch, flag);
						} else {
							bappend(ch);
						}
						st = (int16_t)-1;
						break;
					}
				case u'a':
					{
						if ((this->mBuffIdx == idx) && (ch == u'x')) {
							st = (int16_t)3;
							break;
						}
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		case 3:
			{
				switch (chtyp(ch)) {
				case u'A':
					{}
				case u'a':
					{}
				case u'd':
					{
						bappend(ch);
						break;
					}
				case u';':
					{
						try {
							int32_t i = $Integer::parseInt($$new($String, this->mBuff, idx + 1, this->mBuffIdx - idx), 16);
							if (i >= 0x0000FFFF) {
								panic(Parser::FAULT);
							}
							ch = (char16_t)i;
						} catch ($NumberFormatException& nfe) {
							panic(Parser::FAULT);
						}
						this->mBuffIdx = idx - 1;
						if (ch == u' ' || $nc(this->mInp)->next != nullptr) {
							bappend(ch, flag);
						} else {
							bappend(ch);
						}
						st = (int16_t)-1;
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
	return str;
}

void Parser::pent(char16_t flag) {
	$useLocalCurrentObjectStackCache();
	char16_t ch = 0;
	int32_t idx = this->mBuffIdx + 1;
	$var($Input, inp, nullptr);
	$var($String, str, nullptr);
	bappend(u'%');
	if (this->mPh != Parser::PH_DTD) {
		return;
	}
	bname(false);
	$assign(str, $new($String, this->mBuff, idx + 2, this->mBuffIdx - idx - 1));
	if (getch() != u';') {
		panic(Parser::FAULT);
	}
	$assign(inp, $cast($Input, $nc(this->mPEnt)->get(str)));
	this->mBuffIdx = idx - 1;
	if (inp != nullptr) {
		if (inp->chars == nullptr) {
			$var($InputSource, is, resolveEnt(str, inp->pubid, inp->sysid));
			if (is != nullptr) {
				if (flag != u'-') {
					bappend(u' ');
				}
				push($$new($Input, Parser::BUFFSIZE_READER));
				setinp(is);
				$set($nc(this->mInp), pubid, inp->pubid);
				$set($nc(this->mInp), sysid, inp->sysid);
			} else {
				skippedEnt($$str({"%"_s, str}));
			}
		} else {
			if (flag == u'-') {
				inp->chIdx = 1;
			} else {
				bappend(u' ');
				inp->chIdx = 0;
			}
			push(inp);
		}
	} else {
		skippedEnt($$str({"%"_s, str}));
	}
}

bool Parser::isdecl($Pair* name, $String* value) {
	if ($nc($nc(name)->chars)->get(0) == 0) {
		if ("xmlns"_s->equals(name->name) == true) {
			$set(this, mPref, pair(this->mPref));
			$set($nc(this->mPref), list, this->mElm);
			$set($nc(this->mPref), value, value);
			$set($nc(this->mPref), name, ""_s);
			$set($nc(this->mPref), chars, Parser::NONS);
			++$nc(this->mElm)->num;
			return true;
		}
	} else if (name->eqpref(Parser::XMLNS) == true) {
		int32_t len = $nc(name->name)->length();
		$set(this, mPref, pair(this->mPref));
		$set($nc(this->mPref), list, this->mElm);
		$set($nc(this->mPref), value, value);
		$set($nc(this->mPref), name, name->name);
		$set($nc(this->mPref), chars, $new($chars, len + 1));
		$nc($nc(this->mPref)->chars)->set(0, (char16_t)(len + 1));
		$nc(name->name)->getChars(0, len, $nc(this->mPref)->chars, 1);
		++$nc(this->mElm)->num;
		return true;
	}
	return false;
}

$String* Parser::rslv($chars* qname) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Pair, pref, this->mPref);
		for (; pref != nullptr; $assign(pref, $nc(pref)->next)) {
			if (pref->eqpref(qname) == true) {
				return pref->value;
			}
		}
	}
	if ($nc(qname)->get(0) == 1) {
		{
			$var($Pair, pref, this->mPref);
			for (; pref != nullptr; $assign(pref, $nc(pref)->next)) {
				if ($nc(pref->chars)->get(0) == 0) {
					return pref->value;
				}
			}
		}
	}
	panic(Parser::FAULT);
	return nullptr;
}

char16_t Parser::wsskip() {
	char16_t ch = 0;
	while (true) {
		ch = (this->mChIdx < this->mChLen) ? $nc(this->mChars)->get(this->mChIdx++) : getch();
		if (ch < 128) {
			if ($nc(Parser::nmttyp)->get(ch) != 3) {
				break;
			}
		} else {
			break;
		}
	}
	--this->mChIdx;
	return ch;
}

void Parser::bname(bool ns) {
	char16_t ch = 0;
	char16_t type = 0;
	++this->mBuffIdx;
	int32_t bqname = this->mBuffIdx;
	int32_t bcolon = bqname;
	int32_t bchidx = bqname + 1;
	int32_t bstart = bchidx;
	int32_t cstart = this->mChIdx;
	int16_t st = (int16_t)((ns == true) ? 0 : 2);
	while (true) {
		if (this->mChIdx >= this->mChLen) {
			bcopy(cstart, bstart);
			getch();
			--this->mChIdx;
			cstart = this->mChIdx;
			bstart = bchidx;
		}
		ch = $nc(this->mChars)->get(this->mChIdx++);
		type = (char16_t)0;
		if (ch < 128) {
			type = (char16_t)$nc(Parser::nmttyp)->get(ch);
		} else if (ch == Parser::EOS) {
			panic(Parser::FAULT);
		}
		switch (st) {
		case 0:
			{}
		case 2:
			{
				switch (type) {
				case 0:
					{
						++bchidx;
						++st;
						break;
					}
				case 1:
					{
						--this->mChIdx;
						++st;
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		case 1:
			{}
		case 3:
			{
				switch (type) {
				case 0:
					{}
				case 2:
					{
						++bchidx;
						break;
					}
				case 1:
					{
						++bchidx;
						if (ns == true) {
							if (bcolon != bqname) {
								panic(Parser::FAULT);
							}
							bcolon = bchidx - 1;
							if (st == 1) {
								st = (int16_t)2;
							}
						}
						break;
					}
				default:
					{
						--this->mChIdx;
						bcopy(cstart, bstart);
						$nc(this->mBuff)->set(bqname, (char16_t)(bcolon - bqname));
						return;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
}

void Parser::bntok() {
	char16_t ch = 0;
	this->mBuffIdx = -1;
	bappend((char16_t)0);
	while (true) {
		ch = getch();
		switch (chtyp(ch)) {
		case u'a':
			{}
		case u'A':
			{}
		case u'd':
			{}
		case u'.':
			{}
		case u':':
			{}
		case u'-':
			{}
		case u'_':
			{}
		case u'X':
			{
				bappend(ch);
				break;
			}
		case u'Z':
			{
				panic(Parser::FAULT);
			}
		default:
			{
				bkch();
				return;
			}
		}
	}
}

char16_t Parser::bkeyword() {
	$var($String, str, $new($String, this->mBuff, 1, this->mBuffIdx));
	switch (str->length()) {
	case 2:
		{
			return ("ID"_s->equals(str) == true) ? u'i' : u'?';
		}
	case 5:
		{
			switch ($nc(this->mBuff)->get(1)) {
			case u'I':
				{
					return ("IDREF"_s->equals(str) == true) ? u'r' : u'?';
				}
			case u'C':
				{
					return ("CDATA"_s->equals(str) == true) ? u'c' : u'?';
				}
			case u'F':
				{
					return ("FIXED"_s->equals(str) == true) ? u'F' : u'?';
				}
			default:
				{
					break;
				}
			}
			break;
		}
	case 6:
		{
			switch ($nc(this->mBuff)->get(1)) {
			case u'I':
				{
					return ("IDREFS"_s->equals(str) == true) ? u'R' : u'?';
				}
			case u'E':
				{
					return ("ENTITY"_s->equals(str) == true) ? u'n' : u'?';
				}
			default:
				{
					break;
				}
			}
			break;
		}
	case 7:
		{
			switch ($nc(this->mBuff)->get(1)) {
			case u'I':
				{
					return ("IMPLIED"_s->equals(str) == true) ? u'I' : u'?';
				}
			case u'N':
				{
					return ("NMTOKEN"_s->equals(str) == true) ? u't' : u'?';
				}
			case u'A':
				{
					return ("ATTLIST"_s->equals(str) == true) ? u'a' : u'?';
				}
			case u'E':
				{
					return ("ELEMENT"_s->equals(str) == true) ? u'e' : u'?';
				}
			default:
				{
					break;
				}
			}
			break;
		}
	case 8:
		{
			switch ($nc(this->mBuff)->get(2)) {
			case u'N':
				{
					return ("ENTITIES"_s->equals(str) == true) ? u'N' : u'?';
				}
			case u'M':
				{
					return ("NMTOKENS"_s->equals(str) == true) ? u'T' : u'?';
				}
			case u'O':
				{
					return ("NOTATION"_s->equals(str) == true) ? u'o' : u'?';
				}
			case u'E':
				{
					return ("REQUIRED"_s->equals(str) == true) ? u'Q' : u'?';
				}
			default:
				{
					break;
				}
			}
			break;
		}
	default:
		{
			break;
		}
	}
	return u'?';
}

void Parser::bqstr(char16_t flag) {
	$var($Input, inp, this->mInp);
	this->mBuffIdx = -1;
	bappend((char16_t)0);
	char16_t ch = 0;
	for (int16_t st = (int16_t)0; st >= 0;) {
		ch = (this->mChIdx < this->mChLen) ? $nc(this->mChars)->get(this->mChIdx++) : getch();
		switch (st) {
		case 0:
			{
				switch (ch) {
				case u' ':
					{}
				case u'\n':
					{}
				case u'\r':
					{}
				case u'\t':
					{
						break;
					}
				case u'\'':
					{
						st = (int16_t)2;
						break;
					}
				case u'\"':
					{
						st = (int16_t)3;
						break;
					}
				default:
					{
						panic(Parser::FAULT);
						break;
					}
				}
				break;
			}
		case 2:
			{}
		case 3:
			{
				switch (ch) {
				case u'\'':
					{
						if ((st == 2) && (this->mInp == inp)) {
							st = (int16_t)-1;
						} else {
							bappend(ch);
						}
						break;
					}
				case u'\"':
					{
						if ((st == 3) && (this->mInp == inp)) {
							st = (int16_t)-1;
						} else {
							bappend(ch);
						}
						break;
					}
				case u'&':
					{
						if (flag != u'd') {
							ent(flag);
						} else {
							bappend(ch);
						}
						break;
					}
				case u'%':
					{
						if (flag == u'd') {
							pent(u'-');
						} else {
							bappend(ch);
						}
						break;
					}
				case u'<':
					{
						if ((flag == u'-') || (flag == u'd')) {
							bappend(ch);
						} else {
							panic(Parser::FAULT);
						}
						break;
					}
				case Parser::EOS:
					{
						panic(Parser::FAULT);
					}
				case u'\r':
					{
						if (flag != u' ' && $nc(this->mInp)->next == nullptr) {
							if (getch() != u'\n') {
								bkch();
							}
							ch = u'\n';
						}
					}
				default:
					{
						bappend(ch, flag);
						break;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
	if ((flag == u'i') && ($nc(this->mBuff)->get(this->mBuffIdx) == u' ')) {
		this->mBuffIdx -= 1;
	}
}

void Parser::bappend(char16_t ch, char16_t mode) {
	switch (mode) {
	case u'i':
		{
			switch (ch) {
			case u' ':
				{}
			case u'\n':
				{}
			case u'\r':
				{}
			case u'\t':
				{
					if ((this->mBuffIdx > 0) && ($nc(this->mBuff)->get(this->mBuffIdx) != u' ')) {
						bappend(u' ');
					}
					return;
				}
			default:
				{
					break;
				}
			}
			break;
		}
	case u'c':
		{
			switch (ch) {
			case u'\n':
				{}
			case u'\r':
				{}
			case u'\t':
				{
					ch = u' ';
					break;
				}
			default:
				{
					break;
				}
			}
			break;
		}
	default:
		{
			break;
		}
	}
	++this->mBuffIdx;
	if (this->mBuffIdx < $nc(this->mBuff)->length) {
		$nc(this->mBuff)->set(this->mBuffIdx, ch);
	} else {
		--this->mBuffIdx;
		bappend(ch);
	}
}

void Parser::bappend(char16_t ch) {
	try {
		$nc(this->mBuff)->set(++this->mBuffIdx, ch);
	} catch ($Exception& exp) {
		$var($chars, buff, $new($chars, $nc(this->mBuff)->length << 1));
		$System::arraycopy(this->mBuff, 0, buff, 0, $nc(this->mBuff)->length);
		$set(this, mBuff, buff);
		$nc(this->mBuff)->set(this->mBuffIdx, ch);
	}
}

void Parser::bcopy(int32_t cidx, int32_t bidx) {
	int32_t length = this->mChIdx - cidx;
	if ((bidx + length + 1) >= $nc(this->mBuff)->length) {
		$var($chars, buff, $new($chars, $nc(this->mBuff)->length + length));
		$System::arraycopy(this->mBuff, 0, buff, 0, $nc(this->mBuff)->length);
		$set(this, mBuff, buff);
	}
	$System::arraycopy(this->mChars, cidx, this->mBuff, bidx, length);
	this->mBuffIdx += length;
}

void Parser::eappend(char16_t ch) {
	switch (this->mESt) {
	case 256:
		{
			switch (ch) {
			case u'l':
				{
					this->mESt = (char16_t)257;
					break;
				}
			case u'g':
				{
					this->mESt = (char16_t)258;
					break;
				}
			case u'a':
				{
					this->mESt = (char16_t)259;
					break;
				}
			case u'q':
				{
					this->mESt = (char16_t)263;
					break;
				}
			default:
				{
					this->mESt = (char16_t)512;
					break;
				}
			}
			break;
		}
	case 257:
		{
			this->mESt = (ch == u't') ? u'<' : (char16_t)512;
			break;
		}
	case 258:
		{
			this->mESt = (ch == u't') ? u'>' : (char16_t)512;
			break;
		}
	case 259:
		{
			switch (ch) {
			case u'm':
				{
					this->mESt = (char16_t)260;
					break;
				}
			case u'p':
				{
					this->mESt = (char16_t)261;
					break;
				}
			default:
				{
					this->mESt = (char16_t)512;
					break;
				}
			}
			break;
		}
	case 260:
		{
			this->mESt = (ch == u'p') ? u'&' : (char16_t)512;
			break;
		}
	case 261:
		{
			this->mESt = (ch == u'o') ? (char16_t)262 : (char16_t)512;
			break;
		}
	case 262:
		{
			this->mESt = (ch == u's') ? u'\'' : (char16_t)512;
			break;
		}
	case 263:
		{
			this->mESt = (ch == u'u') ? (char16_t)264 : (char16_t)512;
			break;
		}
	case 264:
		{
			this->mESt = (ch == u'o') ? (char16_t)265 : (char16_t)512;
			break;
		}
	case 265:
		{
			this->mESt = (ch == u't') ? u'\"' : (char16_t)512;
			break;
		}
	case u'<':
		{}
	case u'>':
		{}
	case u'&':
		{}
	case u'\'':
		{}
	case u'\"':
		{
			this->mESt = (char16_t)512;
		}
	default:
		{
			break;
		}
	}
}

void Parser::setinp($InputSource* is) {
	$useLocalCurrentObjectStackCache();
	$var($Reader, reader, nullptr);
	this->mChIdx = 0;
	this->mChLen = 0;
	$set(this, mChars, $nc(this->mInp)->chars);
	$set($nc(this->mInp), src, nullptr);
	if (this->mPh < Parser::PH_DOC_START) {
		this->mIsSAlone = false;
	}
	this->mIsSAloneSet = false;
	if ($nc(is)->getCharacterStream() != nullptr) {
		$assign(reader, is->getCharacterStream());
		xml(reader);
	} else if (is->getByteStream() != nullptr) {
		$var($String, expenc, nullptr);
		if (is->getEncoding() != nullptr) {
			$assign(expenc, $nc($(is->getEncoding()))->toUpperCase());
			if (expenc->equals("UTF-16"_s)) {
				$assign(reader, bom($(is->getByteStream()), u'U'));
			} else {
				$assign(reader, enc(expenc, $(is->getByteStream())));
			}
			xml(reader);
		} else {
			$assign(reader, bom($(is->getByteStream()), u' '));
			if (reader == nullptr) {
				$assign(reader, utf16($(is->getByteStream())));
			}
			if (reader == nullptr) {
				$assign(reader, enc("UTF-8"_s, $(is->getByteStream())));
				$assign(expenc, xml(reader));
				if (!$nc(expenc)->equals("UTF-8"_s)) {
					if (expenc->startsWith("UTF-16"_s)) {
						panic(Parser::FAULT);
					}
					$assign(reader, enc(expenc, $(is->getByteStream())));
				}
			} else {
				xml(reader);
			}
		}
	} else {
		panic(Parser::FAULT);
	}
	$set($nc(this->mInp), src, reader);
	$set($nc(this->mInp), pubid, $nc(is)->getPublicId());
	$set($nc(this->mInp), sysid, is->getSystemId());
}

$Reader* Parser::bom($InputStream* is, char16_t hint) {
	int32_t val = $nc(is)->read();
	switch (val) {
	case 239:
		{
			if (hint == u'U') {
				panic(Parser::FAULT);
			}
			if (is->read() != 187) {
				panic(Parser::FAULT);
			}
			if (is->read() != 191) {
				panic(Parser::FAULT);
			}
			return $new($ReaderUTF8, is);
		}
	case 254:
		{
			if (is->read() != 255) {
				panic(Parser::FAULT);
			}
			return $new($ReaderUTF16, is, u'b');
		}
	case 255:
		{
			if (is->read() != 254) {
				panic(Parser::FAULT);
			}
			return $new($ReaderUTF16, is, u'l');
		}
	case -1:
		{
			$nc(this->mChars)->set(this->mChIdx++, Parser::EOS);
			return $new($ReaderUTF8, is);
		}
	default:
		{
			if (hint == u'U') {
				panic(Parser::FAULT);
			}
			switch ((int32_t)(val & (uint32_t)240)) {
			case 192:
				{}
			case 208:
				{
					$nc(this->mChars)->set(this->mChIdx++, (char16_t)((((int32_t)(val & (uint32_t)31)) << 6) | ((int32_t)(is->read() & (uint32_t)63))));
					break;
				}
			case 224:
				{
					int32_t var$0 = (((int32_t)(val & (uint32_t)15)) << 12) | (((int32_t)(is->read() & (uint32_t)63)) << 6);
					$nc(this->mChars)->set(this->mChIdx++, (char16_t)(var$0 | ((int32_t)(is->read() & (uint32_t)63))));
					break;
				}
			case 240:
				{
					$throwNew($UnsupportedEncodingException);
				}
			default:
				{
					$nc(this->mChars)->set(this->mChIdx++, (char16_t)val);
					break;
				}
			}
			return nullptr;
		}
	}
}

$Reader* Parser::utf16($InputStream* is) {
	if (this->mChIdx != 0) {
		int8_t b0 = (int8_t)$nc(this->mChars)->get(0);
		if (b0 == 0 || b0 == 60) {
			int32_t b1 = $nc(is)->read();
			int32_t b2 = is->read();
			int32_t b3 = is->read();
			if (b0 == 0 && b1 == 60 && b2 == 0 && b3 == 63) {
				$nc(this->mChars)->set(0, (char16_t)(b1));
				$nc(this->mChars)->set(this->mChIdx++, (char16_t)(b3));
				return $new($ReaderUTF16, is, u'b');
			} else if (b0 == 60 && b1 == 0 && b2 == 63 && b3 == 0) {
				$nc(this->mChars)->set(0, (char16_t)(b0));
				$nc(this->mChars)->set(this->mChIdx++, (char16_t)(b2));
				return $new($ReaderUTF16, is, u'l');
			} else {
				$nc(this->mChars)->set(0, (char16_t)(b0));
				$nc(this->mChars)->set(this->mChIdx++, (char16_t)(b1));
				$nc(this->mChars)->set(this->mChIdx++, (char16_t)(b2));
				$nc(this->mChars)->set(this->mChIdx++, (char16_t)(b3));
			}
		}
	}
	return nullptr;
}

$String* Parser::xml($Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$var($String, str, nullptr);
	$var($String, enc, "UTF-8"_s);
	char16_t ch = 0;
	int32_t val = 0;
	int16_t st = (int16_t)0;
	int32_t byteRead = this->mChIdx;
	while (st >= 0 && this->mChIdx < $nc(this->mChars)->length) {
		if (st < byteRead) {
			ch = $nc(this->mChars)->get(st);
		} else {
			ch = ((val = $nc(reader)->read()) >= 0) ? (char16_t)val : Parser::EOS;
			$nc(this->mChars)->set(this->mChIdx++, ch);
		}
		switch (st) {
		case 0:
			{
				switch (ch) {
				case u'<':
					{
						st = (int16_t)1;
						break;
					}
				case 0x0000FEFF:
					{
						ch = ((val = $nc(reader)->read()) >= 0) ? (char16_t)val : Parser::EOS;
						$nc(this->mChars)->set(this->mChIdx - 1, ch);
						st = (int16_t)((ch == u'<') ? 1 : -1);
						break;
					}
				default:
					{
						st = (int16_t)-1;
						break;
					}
				}
				break;
			}
		case 1:
			{
				st = (int16_t)((ch == u'?') ? 2 : -1);
				break;
			}
		case 2:
			{
				st = (int16_t)((ch == u'x') ? 3 : -1);
				break;
			}
		case 3:
			{
				st = (int16_t)((ch == u'm') ? 4 : -1);
				break;
			}
		case 4:
			{
				st = (int16_t)((ch == u'l') ? 5 : -1);
				break;
			}
		case 5:
			{
				switch (ch) {
				case u' ':
					{}
				case u'\t':
					{}
				case u'\r':
					{}
				case u'\n':
					{
						st = (int16_t)6;
						break;
					}
				default:
					{
						st = (int16_t)-1;
						break;
					}
				}
				break;
			}
		case 6:
			{
				switch (ch) {
				case u'?':
					{
						st = (int16_t)7;
						break;
					}
				case Parser::EOS:
					{
						st = (int16_t)-2;
						break;
					}
				default:
					{
						break;
					}
				}
				break;
			}
		case 7:
			{
				switch (ch) {
				case u'>':
					{}
				case Parser::EOS:
					{
						st = (int16_t)-2;
						break;
					}
				default:
					{
						st = (int16_t)6;
						break;
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
				break;
			}
		}
	}
	this->mChLen = this->mChIdx;
	this->mChIdx = 0;
	if (st == -1) {
		return enc;
	}
	this->mChIdx = 5;
	for (st = (int16_t)0; st >= 0;) {
		ch = getch();
		switch (st) {
		case 0:
			{
				if (chtyp(ch) != u' ') {
					bkch();
					st = (int16_t)1;
				}
				break;
			}
		case 1:
			{}
		case 2:
			{}
		case 3:
			{
				switch (chtyp(ch)) {
				case u'a':
					{}
				case u'A':
					{}
				case u'_':
					{
						bkch();
						$assign(str, $nc($(name(false)))->toLowerCase());
						if ("version"_s->equals(str) == true) {
							if (st != 1) {
								panic(Parser::FAULT);
							}
							if ("1.0"_s->equals($(eqstr(u'='))) != true) {
								panic(Parser::FAULT);
							}
							$nc(this->mInp)->xmlver = (char16_t)256;
							st = (int16_t)2;
						} else if ("encoding"_s->equals(str) == true) {
							if (st != 2) {
								panic(Parser::FAULT);
							}
							$set($nc(this->mInp), xmlenc, $nc($(eqstr(u'=')))->toUpperCase());
							$assign(enc, $nc(this->mInp)->xmlenc);
							st = (int16_t)3;
						} else if ("standalone"_s->equals(str) == true) {
							if ((st == 1) || (this->mPh >= Parser::PH_DOC_START)) {
								panic(Parser::FAULT);
							}
							$assign(str, $nc($(eqstr(u'=')))->toLowerCase());
							if (str->equals("yes"_s) == true) {
								this->mIsSAlone = true;
							} else if (str->equals("no"_s) == true) {
								this->mIsSAlone = false;
							} else {
								panic(Parser::FAULT);
							}
							this->mIsSAloneSet = true;
							st = (int16_t)4;
						} else {
							panic(Parser::FAULT);
						}
						break;
					}
				case u' ':
					{
						break;
					}
				case u'?':
					{
						if (st == 1) {
							panic(Parser::FAULT);
						}
						bkch();
						st = (int16_t)4;
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		case 4:
			{
				switch (chtyp(ch)) {
				case u'?':
					{
						if (getch() != u'>') {
							panic(Parser::FAULT);
						}
						if (this->mPh <= Parser::PH_DOC_START) {
							this->mPh = Parser::PH_MISC_DTD;
						}
						st = (int16_t)-1;
						break;
					}
				case u' ':
					{
						break;
					}
				default:
					{
						panic(Parser::FAULT);
					}
				}
				break;
			}
		default:
			{
				panic(Parser::FAULT);
			}
		}
	}
	return enc;
}

$Reader* Parser::enc($String* name, $InputStream* is) {
	if ($nc(name)->equals("UTF-8"_s)) {
		return $new($ReaderUTF8, is);
	} else if (name->equals("UTF-16LE"_s)) {
		return $new($ReaderUTF16, is, u'l');
	} else if (name->equals("UTF-16BE"_s)) {
		return $new($ReaderUTF16, is, u'b');
	} else {
		return $new($InputStreamReader, is, name);
	}
}

void Parser::push($Input* inp) {
	$nc(this->mInp)->chLen = this->mChLen;
	$nc(this->mInp)->chIdx = this->mChIdx;
	$set($nc(inp), next, this->mInp);
	$set(this, mInp, inp);
	$set(this, mChars, inp->chars);
	this->mChLen = inp->chLen;
	this->mChIdx = inp->chIdx;
}

void Parser::pop() {
	if ($nc(this->mInp)->src != nullptr) {
		try {
			$nc($nc(this->mInp)->src)->close();
		} catch ($IOException& ioe) {
		}
		$set($nc(this->mInp), src, nullptr);
	}
	$set(this, mInp, $nc(this->mInp)->next);
	if (this->mInp != nullptr) {
		$set(this, mChars, $nc(this->mInp)->chars);
		this->mChLen = $nc(this->mInp)->chLen;
		this->mChIdx = $nc(this->mInp)->chIdx;
	} else {
		$set(this, mChars, nullptr);
		this->mChLen = 0;
		this->mChIdx = 0;
	}
}

char16_t Parser::chtyp(char16_t ch) {
	if (ch < 128) {
		return (char16_t)$nc(Parser::asctyp)->get(ch);
	}
	return (ch != Parser::EOS) ? u'X' : u'Z';
}

char16_t Parser::getch() {
	if (this->mChIdx >= this->mChLen) {
		if ($nc(this->mInp)->src == nullptr) {
			pop();
			return getch();
		}
		int32_t Num = $nc($nc(this->mInp)->src)->read(this->mChars, 0, $nc(this->mChars)->length);
		if (Num < 0) {
			if (this->mInp != this->mDoc) {
				pop();
				return getch();
			} else {
				$nc(this->mChars)->set(0, Parser::EOS);
				this->mChLen = 1;
			}
		} else {
			this->mChLen = Num;
		}
		this->mChIdx = 0;
	}
	return $nc(this->mChars)->get(this->mChIdx++);
}

void Parser::bkch() {
	if (this->mChIdx <= 0) {
		panic(Parser::FAULT);
	}
	--this->mChIdx;
}

void Parser::setch(char16_t ch) {
	$nc(this->mChars)->set(this->mChIdx, ch);
}

$Pair* Parser::find($Pair* chain, $chars* qname) {
	{
		$var($Pair, pair, chain);
		for (; pair != nullptr; $assign(pair, $nc(pair)->next)) {
			if (pair->eqname(qname) == true) {
				return pair;
			}
		}
	}
	return nullptr;
}

$Pair* Parser::pair($Pair* next) {
	$var($Pair, pair, nullptr);
	if (this->mDltd != nullptr) {
		$assign(pair, this->mDltd);
		$set(this, mDltd, $nc(pair)->next);
	} else {
		$assign(pair, $new($Pair));
	}
	$set($nc(pair), next, next);
	return pair;
}

$Pair* Parser::del($Pair* pair) {
	$var($Pair, next, $nc(pair)->next);
	$set(pair, name, nullptr);
	$set(pair, value, nullptr);
	$set(pair, chars, nullptr);
	$set(pair, list, nullptr);
	$set(pair, next, this->mDltd);
	$set(this, mDltd, pair);
	return next;
}

void clinit$Parser($Class* class$) {
	$assignStatic(Parser::FAULT, ""_s);
	{
		$assignStatic(Parser::NONS, $new($chars, 1));
		$nc(Parser::NONS)->set(0, (char16_t)0);
		$assignStatic(Parser::XML, $new($chars, 4));
		$nc(Parser::XML)->set(0, (char16_t)4);
		$nc(Parser::XML)->set(1, u'x');
		$nc(Parser::XML)->set(2, u'm');
		$nc(Parser::XML)->set(3, u'l');
		$assignStatic(Parser::XMLNS, $new($chars, 6));
		$nc(Parser::XMLNS)->set(0, (char16_t)6);
		$nc(Parser::XMLNS)->set(1, u'x');
		$nc(Parser::XMLNS)->set(2, u'm');
		$nc(Parser::XMLNS)->set(3, u'l');
		$nc(Parser::XMLNS)->set(4, u'n');
		$nc(Parser::XMLNS)->set(5, u's');
	}
	{
		int16_t i = (int16_t)0;
		$assignStatic(Parser::asctyp, $new($bytes, 128));
		while (i < u' ') {
			$nc(Parser::asctyp)->set(i++, (int8_t)u'z');
		}
		$nc(Parser::asctyp)->set(u'\t', (int8_t)u' ');
		$nc(Parser::asctyp)->set(u'\r', (int8_t)u' ');
		$nc(Parser::asctyp)->set(u'\n', (int8_t)u' ');
		while (i < u'0') {
			int16_t var$0 = i;
			$nc(Parser::asctyp)->set(var$0, (int8_t)i++);
		}
		while (i <= u'9') {
			$nc(Parser::asctyp)->set(i++, (int8_t)u'd');
		}
		while (i < u'A') {
			int16_t var$1 = i;
			$nc(Parser::asctyp)->set(var$1, (int8_t)i++);
		}
		while (i <= u'Z') {
			$nc(Parser::asctyp)->set(i++, (int8_t)u'A');
		}
		while (i < u'a') {
			int16_t var$2 = i;
			$nc(Parser::asctyp)->set(var$2, (int8_t)i++);
		}
		while (i <= u'z') {
			$nc(Parser::asctyp)->set(i++, (int8_t)u'a');
		}
		while (i < 128) {
			int16_t var$3 = i;
			$nc(Parser::asctyp)->set(var$3, (int8_t)i++);
		}
		$assignStatic(Parser::nmttyp, $new($bytes, 128));
		for (i = (int16_t)0; i < u'0'; ++i) {
			$nc(Parser::nmttyp)->set(i, (int8_t)255);
		}
		while (i <= u'9') {
			$nc(Parser::nmttyp)->set(i++, (int8_t)2);
		}
		while (i < u'A') {
			$nc(Parser::nmttyp)->set(i++, (int8_t)255);
		}
		for (i = u'['; i < u'a'; ++i) {
			$nc(Parser::nmttyp)->set(i, (int8_t)255);
		}
		for (i = u'{'; i < 128; ++i) {
			$nc(Parser::nmttyp)->set(i, (int8_t)255);
		}
		$nc(Parser::nmttyp)->set(u'_', (int8_t)0);
		$nc(Parser::nmttyp)->set(u':', (int8_t)1);
		$nc(Parser::nmttyp)->set(u'.', (int8_t)2);
		$nc(Parser::nmttyp)->set(u'-', (int8_t)2);
		$nc(Parser::nmttyp)->set(u' ', (int8_t)3);
		$nc(Parser::nmttyp)->set(u'\t', (int8_t)3);
		$nc(Parser::nmttyp)->set(u'\r', (int8_t)3);
		$nc(Parser::nmttyp)->set(u'\n', (int8_t)3);
	}
}

Parser::Parser() {
}

$Class* Parser::load$($String* name, bool initialize) {
	$loadClass(Parser, name, initialize, &_Parser_ClassInfo_, clinit$Parser, allocate$Parser);
	return class$;
}

$Class* Parser::class$ = nullptr;

				} // impl
			} // xml
		} // util
	} // internal
} // jdk
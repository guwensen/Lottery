#ifndef _HTMLPARSER_H_
#define _HTMLPARSER_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class HTMLParser
{
protected:
	string openDate;
	string number;
	string openTime;
	string result;

	string html;
	string parseFormat;
public:
	HTMLParser(const string& html, const string& parseFormat) {
		this->parseFormat = parseFormat;
		this->html = html;
	}
	virtual ~HTMLParser(void) {
	}

	bool parse(void);
	virtual bool parseResult(ifstream& in);

	const string& getOpenDate(void) {
		return openDate;
	}
	const string& getNumber(void) {
		return number;
	}
	const string& getOpenTime(void) {
		return openTime;
	}
	const string& getResult(void) {
		return result;
	}
};

class GDKL10FParser : public HTMLParser
{
public:
	GDKL10FParser(const string& html) : HTMLParser(html, "\t<div class='blue-ball  red-blue-ball'>%2d</div>") {
	}
	bool parseResult(ifstream& in);
};

class CQSSCParser : public HTMLParser
{
public:
	CQSSCParser(const string& html) : HTMLParser(html, "\t<div class=\"red-blue-ball\">%d</div>") {
	}
};

class JSK3Parser : public HTMLParser
{
public:
	JSK3Parser(const string& html) : HTMLParser(html, "\t<div class=\"jsk3-ball jsk3-no%d\"></div>") {
	}
};

class XYNCParser : public HTMLParser
{
public:
	XYNCParser(const string& html) : HTMLParser(html, "\t<div class=\"xync-ball xync-ball-no%2d\"></div>") {
	}
};

class PK10Parser : public HTMLParser
{
public:
	PK10Parser(const string& html) : HTMLParser(html, "\t<span class=\"pk-no%d\"></span>") {
	}
};

#endif // _HTMLPARSER_H_

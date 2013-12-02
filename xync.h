#ifndef _XYNC_H_
#define _XYNC_H_

#include "lottery.h"

using namespace std;

class XYNC : public Lottery
{
public:
	XYNC(const string& file, const string& url)
		: Lottery("xinyunnongchang", file, url)
	{
		parser = new XYNCParser(file);
	}
	virtual string getNumber(void)
	{
		return parser->getOpenDate() + "0" + parser->getNumber();
	}
	/*
	virtual string getOpenTime(void)
	{
		string openTime(parser->getOpenTime());
		openTime = openTime.substr(0, 4) + "-" + openTime.substr(4, 2) + "-" + openTime.substr(6, 2) + openTime.substr(8);
		openTime.replace(10, 1, "%20");
		return openTime;
		//return parser->getOpenDate() + "0" + parser->getNumber();
	}
	*/
	bool doParse(void);
};

#endif // _XYNC_H_

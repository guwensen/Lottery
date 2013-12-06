#ifndef _PK10_H_
#define _PK10_H_

#include "lottery.h"

using namespace std;

class PK10 : public Lottery
{
public:
	PK10(const string& file, const string& url)
		: Lottery("pk10", file, url) {
		parser = new PK10Parser(file);
	}
	virtual string getNumber(void) {
		return parser->getNumber();
	}
	bool doParse(void);
};

#endif // _PK10_H_

#ifndef _CQSSC_H_
#define _CQSSC_H_

#include "lottery.h"

using namespace std;

class CQSSC : public Lottery
{
public:
	CQSSC(const string& file, const string& url)
		: Lottery("cqssc", file, url) {
		parser = new CQSSCParser(file);
	}

	bool doParse(void);
};

#endif // _CQSSC_H_

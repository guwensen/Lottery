#ifndef _JSK3_H_
#define _JSK3_H_

#include "lottery.h"

using namespace std;

class JSK3 : public Lottery
{
public:
	JSK3(const string& file, const string& url)
		: Lottery("jsk3", file, url) {
		parser = new JSK3Parser(file);
	}
	bool doParse(void);
};

#endif // _JSK3_H_

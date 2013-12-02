#ifndef _GDKL10F_H_
#define _GDKL10F_H_

#include "lottery.h"

using namespace std;

class GDKL10F : public Lottery
{
public:
	GDKL10F(const string& file, const string& url)
		: Lottery("gdkl10f", file, url)
	{
		parser = new GDKL10FParser(file);
	}
	bool doParse(void);
};

#endif // _GDKL10F_H_

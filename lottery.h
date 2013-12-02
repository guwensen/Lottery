#ifndef _LOTTERY_H_
#define _LOTTERY_H_

#include <iostream>

#include "htmlparser.h"

using namespace std;

class Lottery
{
protected:
	string game;		// 游戏类型 
	string result;		// 开奖结果 
	string openTime;	// 开奖时间 
	string number;		// 期数
	
	string file;		// 请求所存放的文件 
	string url;			// 向何处请求 
	string request;		// 请求 
	
	HTMLParser* parser;	// 解析器 

public:
	Lottery(const string& game, const string& file, const string& url);
	virtual ~Lottery(void) { };
	
	const string& getGame(void);
	const string& getResult(void);
	const string& getOpenTime(void);
	virtual string getNumber(void);
	
	virtual int doRequest(void);		// 发起请求 ，返回状态码
	//virtual bool doParse(void) = 0;		// 对请求进行解析 ，子类具体实现
	virtual bool lottery(void);			// 开奖
};

#endif // _LOTTERY_H_

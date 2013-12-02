#ifndef _LOTTERY_H_
#define _LOTTERY_H_

#include <iostream>

#include "htmlparser.h"

using namespace std;

class Lottery
{
protected:
	string game;		// ��Ϸ���� 
	string result;		// ������� 
	string openTime;	// ����ʱ�� 
	string number;		// ����
	
	string file;		// ��������ŵ��ļ� 
	string url;			// ��δ����� 
	string request;		// ���� 
	
	HTMLParser* parser;	// ������ 

public:
	Lottery(const string& game, const string& file, const string& url);
	virtual ~Lottery(void) { };
	
	const string& getGame(void);
	const string& getResult(void);
	const string& getOpenTime(void);
	virtual string getNumber(void);
	
	virtual int doRequest(void);		// �������� ������״̬��
	//virtual bool doParse(void) = 0;		// ��������н��� ���������ʵ��
	virtual bool lottery(void);			// ����
};

#endif // _LOTTERY_H_

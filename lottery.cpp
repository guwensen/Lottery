#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include "lottery.h"

using namespace std;

Lottery::Lottery(const string& game, const string& file, const string& url)
{
	this->game = game;
	this->file = file;
	this->url = url;
	
	string tool = ".\\curl\\bin\\curl.exe";
	//string options = "--user-agent \"Chrome/31.0.1650.57\" -e http://localhost -o ";
	string options = " -s -o ";
	this->request = tool + options + file + " " + url;
}


const string& Lottery::getGame(void)
{
	return game;
}

string Lottery::getNumber(void)
{
	return parser->getOpenDate() + parser->getNumber();
}

const string& Lottery::getResult(void)
{
	return parser->getResult();
}

const string& Lottery::getOpenTime(void)
{
	return parser->getOpenTime();
}

int Lottery::doRequest(void)
{
	return system(request.c_str());
}

bool Lottery::lottery(void)
{
	if (doRequest() == 0) {
		//return doParse();
		return parser->parse();
	} else {
		return false;
	}
}

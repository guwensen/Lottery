#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include "utilities.h"
#include "gdkl10f.h"



/*
bool GDKL10F::doParse(void)
{
	string keyword("\\u9009\",\"default_prize\":\"320\",\"usable\":1,\"static_prize\":0,\"notify\":0,\"bet\":0,\"prize\":0}},\"result\":{\"red\":[\"");
	string sub(rfindInFile(this->file, keyword));
	if (sub.empty()) {
		return false;
	}
	// 开始解析
	string ball = sub.substr(sub.find("["), 41);
	string open_time = sub.substr(sub.find("\"open_time\":\""), 33);
	string number = sub.substr(sub.find("var phase_key = '"), 28);
	// 整理格式 ，存储
	number = number.substr(17, 10);
	if (0 == number.compare(this->number)) {
		return false;
	}
	ball = ball.substr(1, ball.length() - 2);
	remove_char(ball, '"');
	this->result = ball;
	this->openTime = open_time.substr(13, 19);
	this->number = number;

	return true;
}
*/

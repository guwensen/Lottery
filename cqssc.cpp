#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

#include "utilities.h"
#include "cqssc.h"


/*
bool CQSSC::doParse(void)
{
	string keyword("\"default_prize\":\"4\",\"usable\":1,\"static_prize\":0,\"notify\":0,\"bet\":0,\"prize\":0}},\"result\":{\"red\":[\"");
	string sub(rfindInFile(this->file, keyword));
	if (sub.empty()) {
		return false;
	}
	// 开始解析
	string ball = sub.substr(sub.find("["), 21);
	string open_time = sub.substr(sub.find("\"open_time\":\""), 33);
	string number = sub.substr(sub.find("var phase_key = '"), 29);
	// 整理格式 ，存储
	number = number.substr(17, 11);
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

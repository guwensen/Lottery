#include "htmlparser.h"

bool HTMLParser::parse(void)
{
	char line[256];
	int lineNumber = 0;
	// 打开文件 
	ifstream in(html.c_str());
	if (!in.is_open()) {
		cout << "error to open file " << html << endl;
		return false;
	}
    while(!in.eof())
    {
		lineNumber++;
        in.getline(line, sizeof line, '\n');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
        if (lineNumber == 3) {
			char date[64], number[64], time[64];
			sscanf(line, "\t<span>%8s-%s\t%5s</span>", date, number, time);
			if (this->number.compare(number) == 0)
			{
				// 已经开过奖了 
				return false;
			}
			this->openDate = date;
			//this->openTime = date;
			this->number = number;
			this->openTime = this->openDate + " " + time + ":00";
			//cout << "Date: " << date << endl << "Number: " << this->number << endl << "OpenTime: " << this->openTime<< endl;
			break;
		}
        //cout << line << endl;
    }
    this->parseResult(in);
    in.close();
	return true;
}

bool HTMLParser::parseResult(ifstream& in)
{
	char line[256];
	int lineNumber = 3;
	vector<int> arr;
    while(!in.eof())
    {
		lineNumber++;
        in.getline(line, sizeof line, '\n');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
        //string str = line;
        int ball;
        if (0 != sscanf(line, parseFormat.c_str(), &ball)) {
			//cout << ball << endl;
			arr.push_back(ball);
		}
        //cout << ball << endl;
        //cout << line << endl;
    }
    if (!arr.empty()) {
		result.clear();
	    for (int i = 0; i < arr.size(); ++i) {
			char str[8];
			//cout << arr[i] << endl;
			itoa(arr[i], str, 10);
			if (strlen(str) == 1) {
				str[1] = str[0];
				str[0] = '0';
			}
			str[2] = '\0';
			result = result + str;
			if (i != arr.size() - 1) {
				result += ",";
			}
		}
	}
	//cout << "Result: " << result << endl;
	return true;
}


bool GDKL10FParser::parseResult(ifstream& in)
{
	char line[256];
	int lineNumber = 3;
	vector<int> arr;
    while(!in.eof())
    {
		lineNumber++;
        in.getline(line, sizeof line, '\n');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
        //string str = line;
        int ball;
        if (0 != sscanf(line, "\t<div class='blue-ball  red-blue-ball'>%2d</div>", &ball)
			|| 0 != sscanf(line, "\t<div class='red-ball  red-blue-ball'>%2d</div>", &ball)) {
			//cout << ball << endl;
			arr.push_back(ball);
		}
        //cout << ball << endl;
        //cout << line << endl;
    }
    if (!arr.empty()) {
		result.clear();
	    for (int i = 0; i < arr.size(); ++i) {
			char str[8];
			//cout << arr[i] << endl;
			itoa(arr[i], str, 10);
			if (strlen(str) == 1) {
				str[1] = str[0];
				str[0] = '0';
			}
			str[2] = '\0';
			result = result + str;
			if (i != arr.size() - 1) {
				result += ",";
			}
		}
	}
	//cout << "Result: " << result << endl;
	return true;
}


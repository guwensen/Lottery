#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

extern string rfindInFile(const string& fileName, const string& keyword);
extern void remove_char(string& str, char c);
extern bool initCurl(void);
extern void exitCurl(void);
extern int curlDownload(const char* url, const char* fileName = NULL);


#endif // _UTILITIES_H_

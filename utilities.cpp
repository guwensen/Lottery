#include "utilities.h"

string rfindInFile(const string& fileName, const string& keyword)
{
	// ���ļ� 
	ifstream in(fileName.c_str());
	if (!in.is_open()) {
		cout << "error to open file " << fileName << endl;
		return "";
	}
	ostringstream os;
	os << in.rdbuf();
	string content(os.str());
	// �Ӻ�����ǰ�ҵ���һ�� 
	size_t fpos = content.rfind(keyword);
	if (string::npos == fpos) {
		return "";
	}
	return content.substr(fpos);
}

void remove_char(string& str, char c)
{
	string::iterator new_end = remove_if(str.begin(), str.end(), bind2nd(equal_to<char>(), c));
	str.erase(new_end, str.end());
}

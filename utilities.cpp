#include <algorithm>

#include "utilities.h"
#include "curl\include\curl\curl.h"

string rfindInFile(const string& fileName, const string& keyword)
{
	// 打开文件
	ifstream in(fileName.c_str());
	if (!in.is_open()) {
		cout << "error to open file " << fileName << endl;
		return "";
	}
	ostringstream os;
	os << in.rdbuf();
	string content(os.str());
	// 从后面往前找到这一行
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


/**
 *	@brief libcurl接收到数据时的回调函数
 *
 *	将接收到的数据保存到本地文件中，同时显示在控制台上。
 *
 *	@param [in] buffer 接收到的数据所在缓冲区
 *	@param [in] size 数据长度
 *	@param [in] nmemb 数据片数量
 *	@param [in/out] 用户自定义指针
 *	@return 获取的数据长度
 */
size_t process_data(void *buffer, size_t size, size_t nmemb, void *user_p)
{
	FILE *fp = (FILE *)user_p;
	size_t return_size = fwrite(buffer, size, nmemb, fp);
	//cout << (char *)buffer << endl;
	return return_size;
}

int curlDownload(const char* url, const char* fileName)
{
	// 初始化libcurl
	CURLcode return_code;
	return_code = curl_global_init(CURL_GLOBAL_WIN32);
	if (CURLE_OK != return_code)
	{
		cerr << "init libcurl failed." << endl;
		return -1;
	}

	// 获取easy handle
	CURL *easy_handle = curl_easy_init();
	if (NULL == easy_handle)
	{
		cerr << "get a easy handle failed." << endl;
                  curl_global_cleanup();
		return -1;
	}
	FILE *fp = NULL;
	if (NULL != fileName) {
		fp = fopen(fileName, "wb+");	//
		if (NULL == fp) {
			cerr << "error to open file: " << fileName << endl;
			return -1;
		}
		// 设置easy handle属性
		curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, &process_data);
		curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, fp);
	}
	curl_easy_setopt(easy_handle, CURLOPT_URL, url);
	// 执行数据请求
	curl_easy_perform(easy_handle);

	// 释放资源
	if (NULL != fp) {
		fclose(fp);
	}
	curl_easy_cleanup(easy_handle);
	curl_global_cleanup();

	return 0;
}

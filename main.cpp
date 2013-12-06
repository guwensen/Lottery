#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include"windows.h"

#include "utilities.h"
#include "SimpleIni.h"
#include "gdkl10f.h"
#include "cqssc.h"
#include "jsk3.h"
#include "xync.h"
#include "pk10.h"

using namespace std;

static string* g_jieshuiURL = NULL;
static UINT g_timer = 10;
static vector<Lottery*> lotterys;

void showDebugInfo(Lottery* lottery)
{
	cout << "Game: " << lottery->getGame() << endl
		 << "Result:   " << lottery->getResult() << endl
		 << "OpenTime: " << lottery->getOpenTime() << endl
		 << "Number:   " << lottery->getNumber() << endl;
}

int submitLottery(Lottery* lottery)
{
	string tool(".\\curl\\bin\\curl.exe ");
	//string url("http://hy.bk86.us/jieshui.php");
	string openTime(lottery->getOpenTime());
	openTime = openTime.substr(0, 4) + "-" + openTime.substr(4, 2) + "-" + openTime.substr(6, 2) + openTime.substr(8);
	openTime.replace(10, 1, "%20");
	string params("?bclass_wd=");
	params += lottery->getGame() + "^&expect=";
	params += lottery->getNumber() + "^&opencode=" + lottery->getResult() + "^&enddt=" + openTime;
	string request(tool + *g_jieshuiURL + params);
	// 去掉request中的空格
	remove_char(request, '\n');
	cout << request << endl;

	return system(request.c_str());
}
/*
int main(int argc, char *argv[])
{
	//Lottery lottery;
	//lottery.getLottery();
	Lottery* gd = new GDKL10F("gdkl10f.txt", "http://baidu.lecai.com/lottery/draw/view/544?agentId=5555");
	gd->lottery();
	showDebugInfo(gd);
	delete gd;

	system("PAUSE");
	return EXIT_SUCCESS;
}
*/


VOID CALLBACK TimerProc(HWND hwnd,UINT uMsg,UINT idEvent,DWORD dwTime);

VOID CALLBACK TimerProc(HWND hwnd,UINT uMsg,UINT idEvent,DWORD dwTime)
{
#if 0
	if (gd->lottery()) {
		submitLottery(gd);
		//showDebugInfo(gd);
	}

	if (ssc->lottery()) {
		submitLottery(ssc);
		//showDebugInfo(ssc);
	}
#endif
	for (unsigned int i = 0; i < lotterys.size(); ++i) {
		Lottery* lottery = lotterys[i];
		if (lottery->lottery()) {
			//showDebugInfo(lotterys[i]);
			submitLottery(lotterys[i]);
		}
	}
}

bool loadConfig(void)
{
	CSimpleIniA ini;
	ini.SetUnicode();
	ini.LoadFile("config.ini");
	const char* url = ini.GetValue("config", "url", "http://127.0.0.1/jieshui.php");
	if (NULL == url) {
		return false;
	}
	const char* timer = ini.GetValue("config", "timer", "10");
	if (NULL == timer) {
		return false;
	}
	g_jieshuiURL = new string(url);
	g_timer = atoi(timer);
	g_timer *= 1000;
	//cout << *g_jieshuiURL << endl << g_timer << endl;
	return true;
}

int main()
{
	//HTMLParser parser("pk10", "\t<span class=\"pk-no%d\"></span>");
	//HTMLParser parser("gdkl10", "\t<div class='red-ball  red-blue-ball'>20</div>");
	//HTMLParser parser("xync", "\t<div class=\"xync-ball xync-ball-no%2d\"></div>");
	//HTMLParser parser("jsk3", "\t<div class=\"jsk3-ball jsk3-no%d\"></div>");
	//HTMLParser parser("ssc", "\t<div class=\"red-blue-ball\">%d</div>");

	int timer1 = 1;
	//HWND hwndTimer;
	MSG msg;

	if (!loadConfig()) {
		cout << "error to load config" << endl;
		return EXIT_FAILURE;
	}

	lotterys.push_back(new GDKL10F("gdkl10f.txt", "http://www.1396me.com/gdkl10/currentaward"));
	lotterys.push_back(new CQSSC("cqssc.txt", "http://www.1396me.com/shishicai/currentaward"));
	lotterys.push_back(new JSK3("jsk3.txt", "http://www.1396me.com/jsk3/currentaward"));
	lotterys.push_back(new XYNC("sync.txt", "http://www.1396me.com/xync/currentaward"));
	lotterys.push_back(new PK10("pk10.txt", "http://www.1396me.com/pk10/currentaward"));

#if 0
	TimerProc(0,0,0,0);
	system("PAUSE");
	return EXIT_SUCCESS;
#endif

	SetTimer(NULL,timer1,g_timer,TimerProc);
	while (GetMessage(&msg, NULL, 0, 0) != 0
			&& GetMessage(&msg, NULL, 0, 0) != -1) {
		if (msg.message == WM_TIMER) {
			//std::cout << "i got the message" << std::endl;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	//system("PAUSE");
	return EXIT_SUCCESS;
}

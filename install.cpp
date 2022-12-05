#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <fstream>
using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::current_path;
using namespace std;
long long i;
void proc() {
	int i = 0;
	char buf[102];
	memset(buf, '\0', sizeof(buf));
	const char* lable = "|/-\\";
	while (i <= 100) {
		printf("[%-101s][%d%%][%c]\r", buf, i, lable[i % 4]);
		fflush(stdout);
		buf[i] = '=';
		i++;
		Sleep(50);
	}
	printf("\n");
}
void install() {
	//开始安装
	// --- 驱动安装以及path设置 --- //
	system("python checkPath.py");
	system("python3 checkPath.py");
	system("python checkNetwork.py");
	system("python3 checkNetwork.py");
	// ---  佛祖保佑 永无bug    --- //
	char tmp[256];
	getcwd(tmp, 256);
	fin.open("run.txt", ios::in);
	fout << tmp << endl;
	fout.close();
	if (!fin)
	{
		std::cerr << "无法打开文件,请检查您的权限.[Error 无法打开文件 Code:E001]";
		return;
	}
	proc();
	cout << "安装完成." << endl;
	while(1){}
}
void getPython(){
	cout << "请前往 python.org 安装python![Error Python未安装 Code:E000]" << endl;
}
void main() {
	if (!system("python")) {
		
		if (system("python3")) {
			//安装py了的，但是好像不是Windows的
			install();
		}
		else {
			//没安装py的
			getPython();
			return;
		}
		return;
	}
	else {
		install()
	}
	
}

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
	//��ʼ��װ
	// --- ������װ�Լ�path���� --- //
	system("python checkPath.py");
	system("python3 checkPath.py");
	system("python checkNetwork.py");
	system("python3 checkNetwork.py");
	// ---  ���汣�� ����bug    --- //
	char tmp[256];
	getcwd(tmp, 256);
	fin.open("run.txt", ios::in);
	fout << tmp << endl;
	fout.close();
	if (!fin)
	{
		std::cerr << "�޷����ļ�,��������Ȩ��.[Error �޷����ļ� Code:E001]";
		return;
	}
	proc();
	cout << "��װ���." << endl;
	while(1){}
}
void getPython(){
	cout << "��ǰ�� python.org ��װpython![Error Pythonδ��װ Code:E000]" << endl;
}
void main() {
	if (!system("python")) {
		
		if (system("python3")) {
			//��װpy�˵ģ����Ǻ�����Windows��
			install();
		}
		else {
			//û��װpy��
			getPython();
			return;
		}
		return;
	}
	else {
		install()
	}
	
}

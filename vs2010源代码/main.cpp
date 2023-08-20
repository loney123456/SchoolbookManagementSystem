#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "book.h"
#include "menu.h"
#include"function.h"
//#include"sunday.h"

//刚进入系统时的选择用户的界面
void select_User()
{
	system("cls");
	cout << "高校图书管理系统(登录)" << endl;
	cout << "  请选择你的登录方式  " << endl<<endl;
	cout << "   1.管理员方式登录     " << endl;
	cout << "   2.读者方式登录       " << endl;
	cout << "   0.退出系统        " << endl;
	cout << endl << "请输入对应的数字，以进入功能！(0-2)" << endl;

	int choice1 = -1;//记录进入选择界面之后输入的选项

	while (choice1 < 0 || choice1>2)
	{
		cin >> choice1;
		switch (choice1)
		{
		case 1:Manager_Login(); break;
		case 2:cout << "2" << endl; break;
		case 0:Exit_System(); break;
		default:cout << "您的输入有误，请重新输入！" << endl;
		}
	}
}

int main(void)
{	
	select_User();
	return 0;
}
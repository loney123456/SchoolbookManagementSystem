#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "book.h"
#include "menu.h"
#include"function.h"
//#include"sunday.h"

//�ս���ϵͳʱ��ѡ���û��Ľ���
void select_User()
{
	system("cls");
	cout << "��Уͼ�����ϵͳ(��¼)" << endl;
	cout << "  ��ѡ����ĵ�¼��ʽ  " << endl<<endl;
	cout << "   1.����Ա��ʽ��¼     " << endl;
	cout << "   2.���߷�ʽ��¼       " << endl;
	cout << "   0.�˳�ϵͳ        " << endl;
	cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-2)" << endl;

	int choice1 = -1;//��¼����ѡ�����֮�������ѡ��

	while (choice1 < 0 || choice1>2)
	{
		cin >> choice1;
		switch (choice1)
		{
		case 1:Manager_Login(); break;
		case 2:cout << "2" << endl; break;
		case 0:Exit_System(); break;
		default:cout << "���������������������룡" << endl;
		}
	}
}

int main(void)
{	
	select_User();
	return 0;
}
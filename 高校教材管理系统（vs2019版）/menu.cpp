#include "base.h"
#include "menu.h"
#include "function.h"
#define password '0' //����Աϵͳ�ĵ�¼����

/*********************************�˵����û�����Ŀ��*********************************/

void Manager_Login()//����Ա��¼�Ľ���
{
	system("cls");//����
	char c = '1';//�洢����ı���
	int num = 5;//����Ա��¼�����Դ����
	bool flag = 1;
	cout << "���������ϵͳ�����룬�Խ���ϵͳ" << "  (һ�ν�������һ������)" << endl;
	while (c != password)
	{
		cin >> c;
		if (flag)
		{
			if (c == password)
			{
				{ Main_Menu(); break;}
			}
			else num--;
			if (num != 0)
			{
				cout << "�����������������" << endl;
				cout << " (����" << num << "�λ��ᣡ����)" << endl;
				flag = 1;
			}
			else if (num == 0)
			{
				cout << "�������ϵͳ�˳�" << endl;
				flag = 0;
				exit(0);
			}
		}
	}
}

void Main_Menu()//ϵͳ��ҳ��ҳ��
{
	system("cls");
	cout << "��Уͼ�����ϵͳ(����Ա��ҳ)" << endl<<endl;
	cout << "	1.�����Ŀ		     " << endl;
	cout << "	2.ɾ����Ŀ			 " << endl;
	cout << "	3.�޸���Ŀ			 " << endl;
	cout << "	4.������Ŀ			 " << endl;
	cout << "	5.�����Ŀ			 " << endl;
	cout << "	6.��Ŀ����			 " << endl;
	cout << "	7.չʾ��Ŀ			 " << endl;
	cout << "	0.�˳�ϵͳ			 " << endl;
	cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-7)" << endl;

	char Main_Menu_choice = 'A';//��¼�������˵�֮�������ѡ��
	while (Main_Menu_choice < 0 + '0' || Main_Menu_choice>7 + '0')
	{
		cin >> Main_Menu_choice;
		switch (Main_Menu_choice)
		{
		case 1 + '0': Add_Menu(); break;
		case 2 + '0':Delete_Menu(); break;
		case 3 + '0': Modify_Menu(); break;
		case 4 + '0':Seek_Menu(); break;
		case 5 + '0':Clear_Menu(); break;
		case 6 + '0':Sort_Menu(); break;
		case 7 + '0':Display_Menu(); break;
		case 0 + '0':Exit_System();
		default:cout << "���������������������룡" << endl; break;
		}
	}
}

void Add_Menu()//�����Ŀ��ҳ��
{
	system("cls");
	cout << "��Уͼ�����ϵͳ(�����Ŀ)" << endl << endl;
	cout << "  1.�����Ŀ        " << endl;
	cout << "  0.������һ��        " << endl;
	cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-1)" << endl;


	char Add_Menu_choice = -1;//��¼����˵�֮�������ѡ��

	while (Add_Menu_choice < 0+'0' || Add_Menu_choice>2+'0')
	{
		cin >> Add_Menu_choice;
		switch (Add_Menu_choice)
		{
		case 1 + '0':Add_bookCategory(); break;
		case 0 + '0':Main_Menu(); break;
		default:cout << "���������������������룡"  << endl;
		}
	}
}

void Delete_Menu()//ɾ���鱾��ҳ��
{
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "�������û����Ŀ��" << endl;
		retreat_AddBookCategory();
	}
	else
	{

		cout << "��Уͼ�����ϵͳ(ɾ����Ŀ)" << endl << endl;
		cout << "    1.ɾ��������Ŀ        " << endl;
		cout << "    2.ɾ��������Ŀ        " << endl;
		cout << "     0.������һ��      " << endl;
		cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-2)" << endl;

		char Delete_Menu_choice = 'A';//��¼����˵�֮�������ѡ��

		while (Delete_Menu_choice < 0+'0' || Delete_Menu_choice>2 + '0')
		{
			cin >> Delete_Menu_choice;
			switch (Delete_Menu_choice)
			{
			case 1 + '0':Delete_AllBook(); retreat_MainMenu(); break;
			case 2 + '0':Delete_PartBook(); retreat_DeleteMenu(); break;
			case 0 + '0':Main_Menu(); break;
			default:cout << "���������������������룡"  << endl;
			}
		}
	}
}

int pos;
void Modify_Menu()
{
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "�������û����Ŀ��" << endl;
		retreat_AddBookCategory();
	}
	else
	{

		cout << "��Уͼ�����ϵͳ(�޸���Ŀ1)" << endl << endl;
		cout << "�޸���Ŀ֮ǰ��Ҫ�Ƚ�������";
		pos = Find_Function();
		{
			if (pos >= 0)
			{
				cout << "�޸ı������Ϣ?( Y/y )" << endl;
				cout << "������һ��? ( N/n )" << endl;
				cout << "�������������ص����˵�" << endl;
				char ch;
				cin >> ch;
				if (ch == 'Y' || ch == 'y') Modify_SubMenu();
				else if (ch == 'N' || ch == 'n') Modify_Menu();
				else Main_Menu();
			}
			else
			{
				cout << "������һ��? ( Y/y )" << endl;
				cout << "���ص����˵���( N/n )" << endl;
				cout << "���������������س��˳�ϵͳ" << endl;
				char ch;
				cin >> ch;
				if (ch == 'Y' || ch == 'y') Modify_Menu();
				else if (ch == 'N' || ch == 'n') Main_Menu();
				else Exit_System();
			}
		}
	}
}

char Modify_Choice;
void Modify_SubMenu()
{
	system("cls");
	cout << "��Уͼ�����ϵͳ(�޸���Ŀ2)" << endl << endl;
	cout << "    "; Display_BookName(pos); cout << endl;
	cout << "  ��ѡ������Ҫ�޸ĵ�����  " << endl << endl;
	cout << "    1.�޸��鼮ISBN     " << endl;
	cout << "    2.�޸��鼮����     " << endl;
	cout << "    3.�޸��鼮������   " << endl;
	cout << "    4.�޸ĳ�������     " << endl;
	cout << "    5.�޸ĳ������     " << endl;
	cout << "    6.�޸��鼮�۸�     " << endl;
	cout << "    7.�޸��鼮���     " << endl;
	cout << "    0.�������˵�       " << endl;
	cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-7)" << endl;

	Modify_Choice = 'A';//��¼�������˵�֮�������ѡ��
	while (Modify_Choice < 0+'0' || Modify_Choice>7 + '0')
	{
		cin >> Modify_Choice;
		if (Modify_Choice >= (1 + '0') && Modify_Choice <= (7 + '0'))
		{
			Modify_Function(Modify_Choice-'0', pos);
		}
		else if (Modify_Choice == 0+'0')Main_Menu();
		else cout << "���������������������룡" << endl;
	}
}

char Seek_Menu_choice;
void Seek_Menu()
{	
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "�������û����Ŀ��" << endl;
		retreat_AddBookCategory();
	}
	else
	{
		cout << "��Уͼ�����ϵͳ(������Ŀ)" << endl << endl;
		cout << "  1.�����鼮״̬����     " << endl;
		cout << "  2.�����鼮ISBN����     " << endl;
		cout << "  3.�����鱾������       " << endl;
		cout << "  4.��������������       " << endl;
		cout << "  5.���ݳ�����������     " << endl;
		cout << "  6.���ݳ�����ݲ���     " << endl;
		cout << "  7.�����鼮�۸����     " << endl;
		cout << "  8.�����鼮�Ƿ��ڹݲ��� " << endl;
		cout << "  9.�����鼮��Ų��� " << endl;
		cout << "  0.������һ��       " << endl;
		cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-8)" << endl;

		Seek_Menu_choice = 'A';//��¼�������˵�֮�������ѡ��
		while (Seek_Menu_choice < 0+'0' || Seek_Menu_choice>9 + '0')
		{
			cin >> Seek_Menu_choice;
			switch (Seek_Menu_choice)
			{
			case 1 + '0':Seek_BookLabel(); break;
			case 2 + '0':Seek_ISBN();/*retreat_Seek_ISBN();*/ break;
			case 3 + '0':Seek_BookName();  break;
			case 4 + '0':Seek_AuthorName(); break;
			case 5 + '0':Seek_PressName(); break;
			case 6 + '0':Seek_PublicationTime(); break;
			case 7 + '0':Seek_BookPrice(); break;
			case 8 + '0':Seek_Shelf(); break;
			case 9 + '0':Seek_BookID();break; //retreat_Seek_BookID();
			case 0 + '0':Main_Menu(); break;
			default:cout << "���������������������룡" << endl; break;
			}
		}
		while (Seek_Menu_choice == '2' || Seek_Menu_choice == '9')
		{
			if (Seek_Menu_choice == '2') retreat_Seek_ISBN();
			else if (Seek_Menu_choice == '9') retreat_Seek_BookID();
		}
	}
}

void Seek_BookLabel()
{
	system("cls");
	cout << "��Уͼ�����ϵͳ(�����鼮״̬)" << endl << endl;
	cout << "  1.��������δɾ�����鱾     " << endl;
	cout << "  2.����������ɾ�����鱾     " << endl;
	cout << "     0.������һ��          " << endl;
	cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-2)" << endl;

	char choice6 = -1;//��¼����˵�֮�������ѡ��

	while (choice6 < 0 + '0' || choice6 > 2 + '0')
	{
		cin >> choice6;
		switch (choice6)
		{
		case 1 + '0':Seek_unDelete(); break;
		case 2 + '0':Seek_isDelete(); break;
		case 0 + '0':Main_Menu(); break;
		default:cout << "���������������������룡"  << endl;
		}
	}
}

void Seek_Shelf()
{
	system("cls");
	cout << "��Уͼ�����ϵͳ(�����鼮�Ƿ��ڼ�)" << endl << endl;
	cout << "      1.���������ڹݵ��鱾      " << endl;
	cout << "    2.��������ȫ��������鱾  " << endl;
	cout << "	 0.������һ��         " << endl;
	cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-2)" << endl;

	char choice6 = -1;//��¼����˵�֮�������ѡ��

	while (choice6 < 0+'0' || choice6>2 + '0')
	{
		cin >> choice6;
		switch (choice6)
		{
		case 1 + '0':Seek_OnShelf(); break;
		case 2 + '0':Seek_NotOnShelf(); break;
		case 0 + '0':Seek_Menu(); break;
		default:cout << "���������������������룡" << endl ;
		}
	}
}

void Clear_Menu()
{
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "�������û����Ŀ��" << endl;
		retreat_AddBookCategory();
	}
	else
	{

		cout << "��Уͼ�����ϵͳ(�����Ŀ)" << endl << endl;
		if (Record_BookNumber > 0)
		{
			cout << "���ڹ���" << Record_BookNumber << "�ֲ�ͬ���͵��� " << endl << endl;
			cout << "Ҫɾ������?(����Y/y) " << endl;
			cout << "��������(N/n) ���ص����˵�" << endl;
			cout << "�������������˳�ϵͳ" << endl;
			char ch;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				Clear_Book(); retreat_MainMenu();
			}
			else if (ch == 'n' || ch == 'N')
			{
				Main_Menu();
			}
			else  Exit_System();
		}
		/*else
		{
			cout << "����û����Ŀ��" << endl;
			retreat_MainMenu();
		}*/
	}
}

int Sort_Menu_choice;
void Sort_Menu()//��Ŀ���ҵ�ҳ��
{
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "�������û����Ŀ��" << endl;
		retreat_AddBookCategory();
	}
	else
	{
		cout << "��Уͼ�����ϵͳ(��Ŀ����)" << endl << endl;
		cout << "  1.�����鼮״̬����     " << endl;
		cout << "  2.�����鼮ISBN����     " << endl;
		cout << "  3.�����鱾������       " << endl;
		cout << "  4.��������������       " << endl;
		cout << "  5.���ݳ�����������     " << endl;
		cout << "  6.���ݳ����������     " << endl;
		cout << "  7.�����鼮�۸�����     " << endl;
		cout << "  8.�����鼮�ڹ��������� " << endl;
		cout << "  9.�����鼮������� " << endl;
		cout << "  0.������һ��       " << endl;
		cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-9)" << endl;

		char temp_choice = 'A';
		while (temp_choice < 0+'0' || temp_choice>9 + '0')
		{
			cin >> temp_choice;
			switch (temp_choice)
			{
			case 1 + '0':Sort_Menu_choice = temp_choice - '0'; Sort_SubMenu(); retreat_SortMenu(); break;
			case 2 + '0':Sort_Menu_choice = temp_choice - '0'; Sort_SubMenu(); retreat_SortMenu(); break;
			case 3 + '0':Sort_Menu_choice = temp_choice - '0'; Sort_SubMenu(); retreat_SortMenu(); break;
			case 4 + '0':Sort_Menu_choice = temp_choice - '0'; Sort_SubMenu(); retreat_SortMenu(); break;
			case 5 + '0':Sort_Menu_choice = temp_choice - '0'; Sort_SubMenu(); retreat_SortMenu(); break;
			case 6 + '0':Sort_Menu_choice = temp_choice - '0'; Sort_SubMenu(); retreat_SortMenu(); break;
			case 7 + '0':Sort_Menu_choice = temp_choice - '0'; Sort_SubMenu(); retreat_SortMenu(); break;
			case 8 + '0':Sort_Menu_choice = temp_choice - '0'; Sort_SubMenu(); retreat_SortMenu(); break;
			case 9 + '0':Sort_Menu_choice = temp_choice - '0'; Sort_SubMenu(); retreat_SortMenu(); break;
			case 0 + '0':Main_Menu();
			default:cout << "���������������������룡" << endl;
			}
		}
	}
}

int Sort_SubMenu_choice;//��¼������������Ӳ˵�֮�������ѡ��
void Sort_SubMenu()
{
	system("cls");
	cout << "     ��Уͼ�����ϵͳ(��Ŀ����)        " << endl << endl;
	if (Sort_Menu_choice == 1)
	{
		cout << "  1.������δɾ������ɾ���ķ�ʽ����     " << endl;
		cout << "  2.��������ɾ����δɾ���ķ�ʽ����     " << endl;
	}
	else
	{
		cout << "  1.���մ�С�������򣩵ķ�ʽ����     " << endl;
		cout << "  2.���մӴ�С�����򣩵ķ�ʽ����     " << endl;
	}
	cout << "  0.������һ��             " << endl;
	cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-2)" << endl;

	char temp_choice2 = 'A';
	while (temp_choice2 < 0+'0' || temp_choice2>2 + '0')
	{
		cin >> temp_choice2;
		if (temp_choice2 == 1 + '0' || temp_choice2 == 2 + '0')
		{
			Sort_SubMenu_choice = temp_choice2 - '0';
			Sort_Function(2 * (Sort_Menu_choice - 1) + Sort_SubMenu_choice); Display_ALLBook();
		}
		else if (temp_choice2 == 0 + '0') Sort_Menu();
		else cout << "���������������������룡" << endl ;
	}
}

void Display_Menu()//չʾ��Ŀ��ҳ��
{
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "�������û����Ŀ��" << endl;
		retreat_AddBookCategory();
	}
	else
	{

		cout << "��Уͼ�����ϵͳ(չʾ��Ŀ)" << endl << endl;
		cout << "  1.չʾ������Ŀ��������Ϣ     " << endl;
		cout << "  2.չʾ������Ŀ��������Ϣ     " << endl;
		cout << "     0.������һ��          " << endl;
		cout << endl << "�������Ӧ�����֣��Խ��빦�ܣ�(0-2)" << endl;

		char Display_Menu_choice = 'A';//��¼����˵�֮�������ѡ��

		while (Display_Menu_choice < 0+'0' || Display_Menu_choice>2 + '0')
		{
			cin >> Display_Menu_choice;
			switch (Display_Menu_choice)
			{
			case 1 + '0':Display_ALLBook(); retreat_MainMenu(); break;
			case 2 + '0':Display_PartBook(); retreat_DisplayMenu(); break;
			case 0 + '0':Main_Menu(); break;
			default: cout << "���������������������룡" << endl; break;
			}
		}
	}
}

void Exit_System()
{
	cout << "�����˳�ϵͳ...." << endl
		<< "  ��ӭ�´�ʹ��  " << endl << endl;
	exit(0);
}

/*********************************�˵����û�����Ŀ��*********************************/

/*********������һ���ĺ���*********/

void retreat_MainMenu()
{
	char temp1;
	cout << "���ص����˵�? ( Y/y )" << endl;
	cout << "�����������������س����˳�" << endl;
	cin >> temp1;
	if (temp1 == 'y' || temp1 == 'Y') Main_Menu();
	else Exit_System();
}

void retreat_DisplayMenu()
{
	char temp1;
	cout << "���ص�չʾ�˵�? ( Y/y )" << endl;
	cout << "���ص����˵�( N/n )" << endl;
	cout << "(�������������س����˳�)" << endl;
	cin >> temp1;
	if (temp1 == 'y' || temp1 == 'Y') Display_Menu();
	else if (temp1 == 'n' || temp1 == 'N') Main_Menu();
	else Exit_System();
}


void retreat_AddBookCategory()
{
	char temp1;
	cout << "�����Ŀ����? ( Y/y )" << endl;
	cout << "���ص����˵�( N/n )" << endl;
	cout << "(�������������س����˳�)" << endl;
	cin >> temp1;
	if (temp1 == 'y' || temp1 == 'Y') Add_bookCategory();
	else if (temp1 == 'n' || temp1 == 'N') Main_Menu();
	else Exit_System();
}

void retreat_Modify_Menu()
{
	cout << "�����޸ı�����Ϣ? ( Y/y )" << endl;
	cout << "�޸����������Ϣ? ( N/n )" << endl;
	cout << "  ���ص����˵�?   (����0)" << endl;
	cout << "(�������������س����˳�)" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y') Modify_SubMenu();
	else if (ch == 'N' || ch == 'n') Modify_Menu();
	else if (ch == '0') Main_Menu();
	else Exit_System();
}

void retreat_AddMenu()
{
	cout << "��Ҫ�����Ŀ? ( Y/y )" << endl;
	cout << "���ص����˵�? ( N/n )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Add_Menu();
	else if (temp == 'n' || temp == 'N') Main_Menu();
	else Exit_System();
}

void retreat_DeleteMenu()
{
	char temp1;
	cout << "��Ҫɾ����Ŀ? ( Y/y )"<< endl ;
	cout << "���ص����˵�? ( N/n )" << endl;
	cout << "(�������������س����˳�)" << endl;
	cin >> temp1;
	if (temp1 == 'y' || temp1 == 'Y') Delete_Menu();
	else if (temp1 == 'n' || temp1 == 'N') Main_Menu();
	else Exit_System();
}
/*
void Back_To_Seek(char option)
{
	switch (option)
	{
	case 1 + '0':	cout << "����������Ŀ��״̬? ( Y/y )" << endl; break;
	case 2 + '0':	cout << "����������ĿISBN? ( Y/y )" << endl; break;
	case 3 + '0':	cout << "����������Ŀ����?( Y/y ) " << endl; break;
	case 4 + '0':	cout << "����������Ŀ������? ( Y/y )" << endl; break;
	case 5 + '0':	cout << "����������Ŀ�ĳ�����? ( Y/y )" << endl; break;
	case 6 + '0':	cout << "����������Ŀ�ĳ���ʱ��?  ( Y/y )" << endl; break;
	case 7 + '0':	cout << "����������Ŀ�ļ۸�? ( Y/y )" << endl; break;
	case 8 + '0':	cout << "����������Ŀ�Ƿ��ڼ�?( Y/y )" << endl; break;
	case 9 + '0':	cout << "����������Ŀ���?( Y/y ) " << endl; break;
	}
	char temp;
	cin >> temp;
	switch (option)
	{
	case 1 + '0':	if (temp == 'y' || temp == 'Y') Seek_BookLabel();break;
	case 2 + '0':	if (temp == 'y' || temp == 'Y') Seek_ISBN();break;
	case 3 + '0':	if (temp == 'y' || temp == 'Y') Seek_BookName();break;
	case 4 + '0':	if (temp == 'y' || temp == 'Y') Seek_AuthorName();break;
	case 5 + '0':	if (temp == 'y' || temp == 'Y') Seek_PressName();break;
	case 6 + '0':	if (temp == 'y' || temp == 'Y') Seek_PublicationTime();break;
	case 7 + '0':	if (temp == 'y' || temp == 'Y') Seek_BookPrice();break;
	case 8 + '0':	if (temp == 'y' || temp == 'Y') Seek_Shelf();break;
	case 9 + '0':	if (temp == 'y' || temp == 'Y') Seek_BookID();break;
	}
	if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}
*/

void retreat_Seek_ISBN()
{
	cout << "����������ĿISBN? ( Y/y )" << endl;
	cout << "���ص����Ҳ˵�? ( N/n )" << endl;
	cout << "���ص����˵�?( ����0 )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp='A';
	cin >> temp; 
	if (temp == 'y' || temp == 'Y') Seek_ISBN();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_BookName()
{
	cout << "����������Ŀ����?( Y/y ) " << endl;
	cout << "���ص����Ҳ˵�? ( N/n )" << endl;
	cout << "���ص����˵�?( ����0 )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_BookName();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_BookLabel()
{
	cout << "����������Ŀ��״̬? ( Y/y )" << endl;
	cout << "���ص����Ҳ˵�? ( N/n )" << endl;
	cout << "���ص����˵�?( ����0 )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_BookLabel();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_AuthorName()
{
	cout << "����������Ŀ������? ( Y/y )" << endl;
	cout << "���ص����Ҳ˵�? ( N/n )" << endl;
	cout << "���ص����˵�?( ����0 )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_AuthorName();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_PressName()
{
	cout << "����������Ŀ�ĳ�����? ( Y/y )" << endl;
	cout << "���ص����Ҳ˵�? ( N/n )" << endl;
	cout << "���ص����˵�?( ����0 )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_PressName();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_PublicationTime()
{
	cout << "����������Ŀ�ĳ���ʱ��?  ( Y/y )" << endl;
	cout << "���ص����Ҳ˵�? ( N/n )" << endl;
	cout << "���ص����˵�?( ����0 )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_PublicationTime();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_Shelf()
{
	cout << "����������Ŀ�Ƿ��ڼ�?( Y/y )" << endl;
	cout << "���ص����Ҳ˵�? ( N/n )" << endl;
	cout << "���ص����˵�?( ����0 )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_Shelf();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}


void retreat_Seek_Book_Price()
{
	cout << "����������Ŀ�ļ۸�? ( Y/y )" << endl;
	cout << "���ص����Ҳ˵�? ( N/n )" << endl;
	cout << "���ص����˵�?( ����0 )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_BookPrice();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_BookID()
{
	cout << "����������Ŀ���?( Y/y ) " << endl;
	cout << "���ص����Ҳ˵�? ( N/n )" << endl;
	cout << "���ص����˵�?( ����0 )" << endl;
	cout << "(�������������س����˳�)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_BookID();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_SortMenu()
{
	char temp1;
	cout << "���ص�����˵�? ( Y/y )" << endl;
	cout << "���ص����˵�( N/n )" << endl;
	cout << "(�������������س����˳�)" << endl;
	cin >> temp1;
	if (temp1 == 'y' || temp1 == 'Y') Sort_Menu();
	else if (temp1 == 'n' || temp1 == 'N') Main_Menu();
	else Exit_System();
}

/*********������һ���ĺ���*********/

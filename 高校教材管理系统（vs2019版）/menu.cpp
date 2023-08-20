#include "base.h"
#include "menu.h"
#include "function.h"
#define password '0' //管理员系统的登录密码

/*********************************菜单的用户界面的框架*********************************/

void Manager_Login()//管理员登录的界面
{
	system("cls");//清屏
	char c = '1';//存储密码的变量
	int num = 5;//管理员登录密码试错次数
	bool flag = 1;
	cout << "请输入管理系统的密码，以进入系统" << "  (一次仅可输入一个数字)" << endl;
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
				cout << "密码错误，请重新输入" << endl;
				cout << " (还有" << num << "次机会！！！)" << endl;
				flag = 1;
			}
			else if (num == 0)
			{
				cout << "输入错误，系统退出" << endl;
				flag = 0;
				exit(0);
			}
		}
	}
}

void Main_Menu()//系统首页的页面
{
	system("cls");
	cout << "高校图书管理系统(管理员首页)" << endl<<endl;
	cout << "	1.添加书目		     " << endl;
	cout << "	2.删除书目			 " << endl;
	cout << "	3.修改书目			 " << endl;
	cout << "	4.查找书目			 " << endl;
	cout << "	5.清空书目			 " << endl;
	cout << "	6.书目排序			 " << endl;
	cout << "	7.展示书目			 " << endl;
	cout << "	0.退出系统			 " << endl;
	cout << endl << "请输入对应的数字，以进入功能！(0-7)" << endl;

	char Main_Menu_choice = 'A';//记录进入主菜单之后输入的选项
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
		default:cout << "您的输入有误，请重新输入！" << endl; break;
		}
	}
}

void Add_Menu()//添加书目的页面
{
	system("cls");
	cout << "高校图书管理系统(添加书目)" << endl << endl;
	cout << "  1.添加书目        " << endl;
	cout << "  0.返回上一级        " << endl;
	cout << endl << "请输入对应的数字，以进入功能！(0-1)" << endl;


	char Add_Menu_choice = -1;//记录进入菜单之后输入的选项

	while (Add_Menu_choice < 0+'0' || Add_Menu_choice>2+'0')
	{
		cin >> Add_Menu_choice;
		switch (Add_Menu_choice)
		{
		case 1 + '0':Add_bookCategory(); break;
		case 0 + '0':Main_Menu(); break;
		default:cout << "您的输入有误，请重新输入！"  << endl;
		}
	}
}

void Delete_Menu()//删除书本的页面
{
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "本书库中没有书目！" << endl;
		retreat_AddBookCategory();
	}
	else
	{

		cout << "高校图书管理系统(删除书目)" << endl << endl;
		cout << "    1.删除所有书目        " << endl;
		cout << "    2.删除部分书目        " << endl;
		cout << "     0.返回上一级      " << endl;
		cout << endl << "请输入对应的数字，以进入功能！(0-2)" << endl;

		char Delete_Menu_choice = 'A';//记录进入菜单之后输入的选项

		while (Delete_Menu_choice < 0+'0' || Delete_Menu_choice>2 + '0')
		{
			cin >> Delete_Menu_choice;
			switch (Delete_Menu_choice)
			{
			case 1 + '0':Delete_AllBook(); retreat_MainMenu(); break;
			case 2 + '0':Delete_PartBook(); retreat_DeleteMenu(); break;
			case 0 + '0':Main_Menu(); break;
			default:cout << "您的输入有误，请重新输入！"  << endl;
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
		cout << "本书库中没有书目！" << endl;
		retreat_AddBookCategory();
	}
	else
	{

		cout << "高校图书管理系统(修改书目1)" << endl << endl;
		cout << "修改书目之前需要先进行搜索";
		pos = Find_Function();
		{
			if (pos >= 0)
			{
				cout << "修改本书的信息?( Y/y )" << endl;
				cout << "返回上一级? ( N/n )" << endl;
				cout << "输入其他按键回到主菜单" << endl;
				char ch;
				cin >> ch;
				if (ch == 'Y' || ch == 'y') Modify_SubMenu();
				else if (ch == 'N' || ch == 'n') Modify_Menu();
				else Main_Menu();
			}
			else
			{
				cout << "返回上一级? ( Y/y )" << endl;
				cout << "返回到主菜单？( N/n )" << endl;
				cout << "输入其他按键并回车退出系统" << endl;
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
	cout << "高校图书管理系统(修改书目2)" << endl << endl;
	cout << "    "; Display_BookName(pos); cout << endl;
	cout << "  请选择你需要修改的类型  " << endl << endl;
	cout << "    1.修改书籍ISBN     " << endl;
	cout << "    2.修改书籍名称     " << endl;
	cout << "    3.修改书籍作者名   " << endl;
	cout << "    4.修改出版社名     " << endl;
	cout << "    5.修改出版年份     " << endl;
	cout << "    6.修改书籍价格     " << endl;
	cout << "    7.修改书籍编号     " << endl;
	cout << "    0.返回主菜单       " << endl;
	cout << endl << "请输入对应的数字，以进入功能！(0-7)" << endl;

	Modify_Choice = 'A';//记录进入主菜单之后输入的选项
	while (Modify_Choice < 0+'0' || Modify_Choice>7 + '0')
	{
		cin >> Modify_Choice;
		if (Modify_Choice >= (1 + '0') && Modify_Choice <= (7 + '0'))
		{
			Modify_Function(Modify_Choice-'0', pos);
		}
		else if (Modify_Choice == 0+'0')Main_Menu();
		else cout << "您的输入有误，请重新输入！" << endl;
	}
}

char Seek_Menu_choice;
void Seek_Menu()
{	
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "本书库中没有书目！" << endl;
		retreat_AddBookCategory();
	}
	else
	{
		cout << "高校图书管理系统(查找书目)" << endl << endl;
		cout << "  1.依据书籍状态查找     " << endl;
		cout << "  2.依据书籍ISBN查找     " << endl;
		cout << "  3.依据书本名查找       " << endl;
		cout << "  4.依据作者名查找       " << endl;
		cout << "  5.依据出版社名查找     " << endl;
		cout << "  6.依据出版年份查找     " << endl;
		cout << "  7.依据书籍价格查找     " << endl;
		cout << "  8.依据书籍是否在馆查找 " << endl;
		cout << "  9.依据书籍编号查找 " << endl;
		cout << "  0.返回上一级       " << endl;
		cout << endl << "请输入对应的数字，以进入功能！(0-8)" << endl;

		Seek_Menu_choice = 'A';//记录进入主菜单之后输入的选项
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
			default:cout << "您的输入有误，请重新输入！" << endl; break;
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
	cout << "高校图书管理系统(查找书籍状态)" << endl << endl;
	cout << "  1.查找所有未删除的书本     " << endl;
	cout << "  2.查找所有已删除的书本     " << endl;
	cout << "     0.返回上一级          " << endl;
	cout << endl << "请输入对应的数字，以进入功能！(0-2)" << endl;

	char choice6 = -1;//记录进入菜单之后输入的选项

	while (choice6 < 0 + '0' || choice6 > 2 + '0')
	{
		cin >> choice6;
		switch (choice6)
		{
		case 1 + '0':Seek_unDelete(); break;
		case 2 + '0':Seek_isDelete(); break;
		case 0 + '0':Main_Menu(); break;
		default:cout << "您的输入有误，请重新输入！"  << endl;
		}
	}
}

void Seek_Shelf()
{
	system("cls");
	cout << "高校图书管理系统(查找书籍是否在架)" << endl << endl;
	cout << "      1.查找所有在馆的书本      " << endl;
	cout << "    2.查找所有全部借出的书本  " << endl;
	cout << "	 0.返回上一级         " << endl;
	cout << endl << "请输入对应的数字，以进入功能！(0-2)" << endl;

	char choice6 = -1;//记录进入菜单之后输入的选项

	while (choice6 < 0+'0' || choice6>2 + '0')
	{
		cin >> choice6;
		switch (choice6)
		{
		case 1 + '0':Seek_OnShelf(); break;
		case 2 + '0':Seek_NotOnShelf(); break;
		case 0 + '0':Seek_Menu(); break;
		default:cout << "您的输入有误，请重新输入！" << endl ;
		}
	}
}

void Clear_Menu()
{
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "本书库中没有书目！" << endl;
		retreat_AddBookCategory();
	}
	else
	{

		cout << "高校图书管理系统(清空书目)" << endl << endl;
		if (Record_BookNumber > 0)
		{
			cout << "现在共有" << Record_BookNumber << "种不同类型的书 " << endl << endl;
			cout << "要删除它们?(输入Y/y) " << endl;
			cout << "否则输入(N/n) 返回到主菜单" << endl;
			cout << "输入其他键可退出系统" << endl;
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
			cout << "现在没有书目！" << endl;
			retreat_MainMenu();
		}*/
	}
}

int Sort_Menu_choice;
void Sort_Menu()//书目查找的页面
{
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "本书库中没有书目！" << endl;
		retreat_AddBookCategory();
	}
	else
	{
		cout << "高校图书管理系统(书目排序)" << endl << endl;
		cout << "  1.依据书籍状态排序     " << endl;
		cout << "  2.依据书籍ISBN排序     " << endl;
		cout << "  3.依据书本名排序       " << endl;
		cout << "  4.依据作者名排序       " << endl;
		cout << "  5.依据出版社名排序     " << endl;
		cout << "  6.依据出版年份排序     " << endl;
		cout << "  7.依据书籍价格排序     " << endl;
		cout << "  8.依据书籍在馆数量排序 " << endl;
		cout << "  9.依据书籍编号排序 " << endl;
		cout << "  0.返回上一级       " << endl;
		cout << endl << "请输入对应的数字，以进入功能！(0-9)" << endl;

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
			default:cout << "您的输入有误，请重新输入！" << endl;
			}
		}
	}
}

int Sort_SubMenu_choice;//记录进入排序二级子菜单之后输入的选项
void Sort_SubMenu()
{
	system("cls");
	cout << "     高校图书管理系统(书目排序)        " << endl << endl;
	if (Sort_Menu_choice == 1)
	{
		cout << "  1.按照先未删除后已删除的方式排序     " << endl;
		cout << "  2.按照先已删除后未删除的方式排序     " << endl;
	}
	else
	{
		cout << "  1.按照从小到大（升序）的方式排序     " << endl;
		cout << "  2.按照从大到小（降序）的方式排序     " << endl;
	}
	cout << "  0.返回上一级             " << endl;
	cout << endl << "请输入对应的数字，以进入功能！(0-2)" << endl;

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
		else cout << "您的输入有误，请重新输入！" << endl ;
	}
}

void Display_Menu()//展示书目的页面
{
	system("cls");
	if (Record_BookNumber == 0)
	{
		cout << "本书库中没有书目！" << endl;
		retreat_AddBookCategory();
	}
	else
	{

		cout << "高校图书管理系统(展示书目)" << endl << endl;
		cout << "  1.展示所有书目的所有信息     " << endl;
		cout << "  2.展示部分书目的所有信息     " << endl;
		cout << "     0.返回上一级          " << endl;
		cout << endl << "请输入对应的数字，以进入功能！(0-2)" << endl;

		char Display_Menu_choice = 'A';//记录进入菜单之后输入的选项

		while (Display_Menu_choice < 0+'0' || Display_Menu_choice>2 + '0')
		{
			cin >> Display_Menu_choice;
			switch (Display_Menu_choice)
			{
			case 1 + '0':Display_ALLBook(); retreat_MainMenu(); break;
			case 2 + '0':Display_PartBook(); retreat_DisplayMenu(); break;
			case 0 + '0':Main_Menu(); break;
			default: cout << "您的输入有误，请重新输入！" << endl; break;
			}
		}
	}
}

void Exit_System()
{
	cout << "正在退出系统...." << endl
		<< "  欢迎下次使用  " << endl << endl;
	exit(0);
}

/*********************************菜单的用户界面的框架*********************************/

/*********返回上一级的函数*********/

void retreat_MainMenu()
{
	char temp1;
	cout << "返回到主菜单? ( Y/y )" << endl;
	cout << "否则输入其他键并回车可退出" << endl;
	cin >> temp1;
	if (temp1 == 'y' || temp1 == 'Y') Main_Menu();
	else Exit_System();
}

void retreat_DisplayMenu()
{
	char temp1;
	cout << "返回到展示菜单? ( Y/y )" << endl;
	cout << "返回到主菜单( N/n )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	cin >> temp1;
	if (temp1 == 'y' || temp1 == 'Y') Display_Menu();
	else if (temp1 == 'n' || temp1 == 'N') Main_Menu();
	else Exit_System();
}


void retreat_AddBookCategory()
{
	char temp1;
	cout << "添加书目类型? ( Y/y )" << endl;
	cout << "返回到主菜单( N/n )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	cin >> temp1;
	if (temp1 == 'y' || temp1 == 'Y') Add_bookCategory();
	else if (temp1 == 'n' || temp1 == 'N') Main_Menu();
	else Exit_System();
}

void retreat_Modify_Menu()
{
	cout << "继续修改本书信息? ( Y/y )" << endl;
	cout << "修改其他书的信息? ( N/n )" << endl;
	cout << "  返回到主菜单?   (数字0)" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y') Modify_SubMenu();
	else if (ch == 'N' || ch == 'n') Modify_Menu();
	else if (ch == '0') Main_Menu();
	else Exit_System();
}

void retreat_AddMenu()
{
	cout << "需要添加书目? ( Y/y )" << endl;
	cout << "返回到主菜单? ( N/n )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Add_Menu();
	else if (temp == 'n' || temp == 'N') Main_Menu();
	else Exit_System();
}

void retreat_DeleteMenu()
{
	char temp1;
	cout << "需要删除书目? ( Y/y )"<< endl ;
	cout << "返回到主菜单? ( N/n )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
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
	case 1 + '0':	cout << "继续查找书目的状态? ( Y/y )" << endl; break;
	case 2 + '0':	cout << "继续查找书目ISBN? ( Y/y )" << endl; break;
	case 3 + '0':	cout << "继续查找书目名称?( Y/y ) " << endl; break;
	case 4 + '0':	cout << "继续查找书目的作者? ( Y/y )" << endl; break;
	case 5 + '0':	cout << "继续查找书目的出版社? ( Y/y )" << endl; break;
	case 6 + '0':	cout << "继续查找书目的出版时间?  ( Y/y )" << endl; break;
	case 7 + '0':	cout << "继续查找书目的价格? ( Y/y )" << endl; break;
	case 8 + '0':	cout << "继续查找书目是否在架?( Y/y )" << endl; break;
	case 9 + '0':	cout << "继续查找书目编号?( Y/y ) " << endl; break;
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
	cout << "继续查找书目ISBN? ( Y/y )" << endl;
	cout << "返回到查找菜单? ( N/n )" << endl;
	cout << "返回到主菜单?( 数字0 )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char temp='A';
	cin >> temp; 
	if (temp == 'y' || temp == 'Y') Seek_ISBN();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_BookName()
{
	cout << "继续查找书目名称?( Y/y ) " << endl;
	cout << "返回到查找菜单? ( N/n )" << endl;
	cout << "返回到主菜单?( 数字0 )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_BookName();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_BookLabel()
{
	cout << "继续查找书目的状态? ( Y/y )" << endl;
	cout << "返回到查找菜单? ( N/n )" << endl;
	cout << "返回到主菜单?( 数字0 )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_BookLabel();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_AuthorName()
{
	cout << "继续查找书目的作者? ( Y/y )" << endl;
	cout << "返回到查找菜单? ( N/n )" << endl;
	cout << "返回到主菜单?( 数字0 )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_AuthorName();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_PressName()
{
	cout << "继续查找书目的出版社? ( Y/y )" << endl;
	cout << "返回到查找菜单? ( N/n )" << endl;
	cout << "返回到主菜单?( 数字0 )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_PressName();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_PublicationTime()
{
	cout << "继续查找书目的出版时间?  ( Y/y )" << endl;
	cout << "返回到查找菜单? ( N/n )" << endl;
	cout << "返回到主菜单?( 数字0 )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_PublicationTime();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_Shelf()
{
	cout << "继续查找书目是否在架?( Y/y )" << endl;
	cout << "返回到查找菜单? ( N/n )" << endl;
	cout << "返回到主菜单?( 数字0 )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_Shelf();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}


void retreat_Seek_Book_Price()
{
	cout << "继续查找书目的价格? ( Y/y )" << endl;
	cout << "返回到查找菜单? ( N/n )" << endl;
	cout << "返回到主菜单?( 数字0 )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	char temp;
	cin >> temp;

	if (temp == 'y' || temp == 'Y') Seek_BookPrice();
	else if (temp == 'n' || temp == 'N') Seek_Menu();
	else if (temp == '0') Main_Menu();
	else Exit_System();
}

void retreat_Seek_BookID()
{
	cout << "继续查找书目编号?( Y/y ) " << endl;
	cout << "返回到查找菜单? ( N/n )" << endl;
	cout << "返回到主菜单?( 数字0 )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
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
	cout << "返回到排序菜单? ( Y/y )" << endl;
	cout << "返回到主菜单( N/n )" << endl;
	cout << "(输入其他键并回车可退出)" << endl;
	cin >> temp1;
	if (temp1 == 'y' || temp1 == 'Y') Sort_Menu();
	else if (temp1 == 'n' || temp1 == 'N') Main_Menu();
	else Exit_System();
}

/*********返回上一级的函数*********/

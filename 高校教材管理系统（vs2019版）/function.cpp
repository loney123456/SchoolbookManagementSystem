#include"base.h"
#include"menu.h"
#include"function.h"
#include"book.h"
#include"main.h"
#include "sunday.h"

#define MAXSIZE 65536
using namespace std;

/*********************************�˵��ľ��幦�ܵ�ʵ��*********************************/

void Add_bookCategory()//���ã�����鱾������
{
	system("cls");
	cout << "Ŀǰ�������" << Max_BookCategory - Record_BookNumber << "����" << endl<<endl;
	cout << "��������Ҫ����鱾���͵ĸ�����";
	int num;
	cin >> num;
	cout << endl;
	if (Record_BookNumber + num > Max_BookCategory)
	{
		cout << "����Ѿ����ˣ��޷�����鱾����" << endl
			<< "��ɾ��������Ŀ֮���ٽ������" << endl << endl;
		retreat_DeleteMenu();
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			cout << "�������" << i + 1 << "�������Ϣ" << endl;
			book[Record_BookNumber++].Add_Book2();
		}
		cout << "   " << num << "����������" << endl << endl;
		retreat_AddBookCategory();
	}
}

//�����鱾���ͣ�ͳ��δɾ�����鱾����
int Record_BookLabel_unDelete()
{
	int unDelete = 0;
	for (int i = 0; i < Record_BookNumber; i++)
	{
		if (book[i].GetBookLabel() == 0)
			unDelete++;

	}
	return unDelete;
}

void Delete_AllBook()
{
	int flag2 = Record_BookLabel_unDelete();
	if (flag2 == 0)
	{
		cout << "���������û��ͼ��!" << endl << endl;
	}
	else if (flag2 > 0)
	{
		for (int i = 0; i < Record_BookNumber; i++)
		{
			book[i].SetLabel(1);
		}
		cout << endl << "ɾ��" << flag2 << "��������ɣ�" << endl << endl;
	}
}

void Delete_PartBook()
{
	int flag3 = Record_BookLabel_unDelete();
	if (flag3 == 0)
	{
		cout << "���������û��ͼ��!" << endl << endl;
		retreat_AddBookCategory();
	}
	else if (flag3 > 0)
	{

		int sign;
		if ((sign=Find_Function()) >= 0)
		{
			cout << endl 
				 << "�Ƿ�ɾ�����飿(Y/y)" ;
			cout << "  ������һ��  (N/n)" << endl;
			char ch;
			ch = 'A';
			while (ch != 'Y' && ch != 'y' && ch != 'n' && ch != 'N')
			{
				cin >> ch;
				if (ch == 'Y' || ch == 'y') 
				{
					book[sign].SetLabel(1); 
					cout << endl<<"ɾ�����Ϊ" << book[sign].GetBookID() << "���������" << endl << endl;
					break;
				}
				else if (ch == 'n' || ch == 'N') Delete_Menu();
				else cout << "�����������������" << endl;
			}
		}
	}
}


void Modify_Function(int num,int index)
{
	switch (num)
	{
	case 1:Modify_ISBN(index); break;
	case 2:Modify_BookName(index); break;
	case 3:Modify_Author(index); break;
	case 4:Modify_Press(index); break;
	case 5:Modify_PublicationTime(index); break;
	case 6:Modify_BookPrice(index); break;
	case 7:Modify_BookID(index); break;
	}
	system("cls");
	cout << endl << "�޸ĺ����Ϣ���£�" << endl;
	book[index].Display_Info();
	retreat_Modify_Menu();
}

void Modify_ISBN(int index)
{
	cout << "�������޸ĺ��ISBN(Ҫ��ԭ���Ĳ�һ��):";
	char isbn2[20];
	bool isExist;
	do
	{
		isExist = 0;
		cin >> isbn2;
		for (int i = 0; i < Record_BookNumber; i++)
		{
			if (isbn2 == book[i].GetISBN()) isExist = 1;
		}
		if (isExist == 1) cout << "��������Ѿ����ڴ�ISBN�����������룡" << endl;
		else book[index].SetISBN(isbn2);
	} while (isExist == 1);
}

void Modify_BookName(int index)
{
	
	cout << "�������޸ĺ������:";
	char bookname1[60];
	cin >> bookname1;
	book[index].SetBookName(bookname1);
}

void Modify_Author(int index)
{
	cout << "�������޸ĺ��������:";
	char author2[20];
	cin >> author2;
	book[index].SetAuthor(author2);
}

void Modify_Press(int index)
{
	cout << "�������޸ĺ�ĳ�������:";
	char press2[20];
	cin >> press2;
	book[index].SetPress(press2);
}

void Modify_PublicationTime(int index)
{
	cout << "�������޸ĺ�ĳ���ʱ�䣨��ݣ�:";
	int publicationtime2;
	cin >> publicationtime2;
	book[index].SetPublicationTime(publicationtime2);
}

void Modify_On_Shelf(int index)
{
	cout << "�������޸ĺ���鱾�ڼ�����:";
	int on_shelf2;
	cin >> on_shelf2;
	book[index].SetOn_Shelf(on_shelf2);
}

void Modify_BookPrice(int index)
{
	cout << "�������޸ĺ���鱾�۸�:";
	int price2;
	cin >> price2;
	book[index].SetBookPrice(price2);
}

void Modify_BookID(int index)
{
	cout << "�������޸ĺ���鱾���(Ҫ��ԭ���Ĳ�һ��):" << endl;
	int bookid2;
	bool isExist;
	do
	{
		isExist = 0;
		cin >> bookid2;
		for (int i = 0; i < Record_BookNumber; i++)
		{
			if (bookid2 == book[i].GetBookID()) isExist = 1;
		}
		if (isExist == 1) cout << "��������Ѿ����ڴ˱�ţ����������룡" << endl;
		else book[index].SetBookID(bookid2);
	} while (isExist == 1);
}

int Find_Function()
{
	char temp;
	cout << endl << "��ѡ�����������ʽ��1.����ISBN����  2.���ձ������" << endl;
	do
	{
		cin >> temp;
		if (temp == 1+'0')
		{
			int flag;
			return (flag = Seek_ISBN()) >= 0 ? flag : -1;
		}
		else if (temp == 2 + '0')
		{
			int flag2;
			return (flag2 = Seek_BookID()) >= 0 ? flag2 : -1;
		}
		else cout << "����������������룡" << endl;
	} while (temp != (1 + '0') && temp != (2 + '0'));
}

void Seek_unDelete()
{
	int flag2 = 0;
	system("cls");
	for (int i = 0; i < Record_BookNumber; i++)
		if (book[i].GetBookLabel() == 0)
		{
			book[i].Display_Info();
			flag2++;
		}
	if (!flag2) cout << "�������û��δɾ�����鱾����" << endl << endl;
	retreat_Seek_BookLabel();
}

void Seek_isDelete()
{
	int flag = 0;
	system("cls");
	for (int i = 0; i < Record_BookNumber; i++)
		if (book[i].GetBookLabel() == 1)
		{
			book[i].Display_Info();
			flag ++;
		}
	if (!flag) cout << endl << "�������û����ɾ�����鱾����" << endl << endl;
	retreat_Seek_BookLabel();
}

int Seek_ISBN()//ֻ����ҷ��������ĵ�һ���鼮������Ĳ������
{
	system("cls");
	char isbn[20];
	char* p;
	int flag;

	int num = 0;
	do
	{
		flag = 1;
		cout << "�������鼮��ISBN��(������)[���Խ���ģ������]:" << endl;
		cin >> isbn;
		int length = strlen(isbn);
		p = isbn;

		while (*p != '\0')
		{
			if (*p < '0' || *p>'9')
			{
				flag = 0; break;
			}
			p++;
		}

		if (!flag) cout << "���벻����Ҫ��,����������!" << endl << endl;
	} while (!flag);
	cout << endl;

	for (int i = 0; i < Record_BookNumber; i++)
	{
		//if (strcmp(book[i].GetISBN(), isbn) == 0)
		if (String_Matching(book[i].GetISBN(), isbn) == 1)
		{
			book[i].Display_Info();
			num++;
			return i;
		}
	}
	if (!num) 
	{
		cout << "û���ҵ���Ӧ����Ŀ" << endl;
		return -1;
	}
}

void Seek_BookName()
{
	system("cls");
	char bookname[60];
	int num = 0;
	cout << "��������Ҫ���ҵ��鼮������:" << endl;
	cin >> bookname;
	cout << endl;
	for (int i = 0; i < Record_BookNumber; i++)
	{
		if (strcmp(book[i].GetBookName(), bookname) == 0)
		{
			book[i].Display_Info();
			num++;
		}
	}
	if (num) cout << "�����ҵ�" << num << "����" << endl << endl;
	else if (!num) cout << "û���ҵ���Ӧ����Ŀ" << endl << endl;
	retreat_Seek_BookName();
}

void Seek_AuthorName()
{
	system("cls");
	char author[30];
	int num = 0;
	cout << "��������Ҫ�����鼮������:" << endl;
	cin >> author;
	cout << endl;
	for (int i = 0; i < Record_BookNumber; i++)
	{
		if (strcmp(book[i].GetAuthor(), author) == 0)
		{
			book[i].Display_Info();
			num++;
		}
	}
	if (num) cout << "�����ҵ�" << num << "����" << endl << endl;
	else if (!num) cout << "û���ҵ���Ӧ����Ŀ" << endl << endl;
	retreat_Seek_AuthorName();
}

void Seek_PressName()
{
	system("cls");
	char press[30];
	int num = 0;
	cout << "��������Ҫ�����鼮�ĳ�����:" << endl;
	cin >> press;
	cout << endl;
	for (int i = 0; i < Record_BookNumber; i++)
	{
		if (strcmp(book[i].GetPress(), press) == 0)
		{
			book[i].Display_Info();
			num++;
		}
	}
	if (num) cout << "�����ҵ�" << num << "����" << endl << endl;
	else if (!num) cout << "û���ҵ���Ӧ����Ŀ" << endl << endl;
	retreat_Seek_PressName();
}

void Seek_PublicationTime()
{
	system("cls");
	char year[20];
	char* p;
	int sum = 0;
	int flag;

	int publication_time=-1;
	int num = 0;
	do 
	{
		flag = 1;
		//system("cls");
		cout << "��������Ҫ�����鼮�ĳ���ʱ�䣨��ݣ�:" << endl;
		cin >> year;
		int string_len = strlen(year);
		
		p = year;
		while (*p != '\0')
		{
			if (*p < '0' || *p>'9')
			{
				flag = 0; break;
			}
			p++;
		}
		if (string_len > 4)flag = 0;
		if (flag)
		{
			p = year;
			for (int i = 0; i < string_len; i++)
			{
				sum += (*p++ - '0') * (int)pow(10, string_len-i-1);
			}
			publication_time = sum;
		}
		else cout << endl << "���벻����Ҫ������������!" << endl << endl;

	} while (!flag);
	
	cout << endl;
	if (publication_time < 0) cout << endl << "���벻����Ҫ������������!" << endl << endl;
	else 
	{
		for (int i = 0; i < Record_BookNumber; i++)
		{
			if (book[i].GetPublicationTime() == publication_time)
			{
				book[i].Display_Info();
				num++;
			}
		}
		if (num) cout << "  �����ҵ�" << num << "����" << endl << endl;
		else if (!num) cout << "û���ҵ���Ӧ����Ŀ" << endl << endl;
	}
	retreat_Seek_PublicationTime();
}

void Seek_OnShelf()
{
	int num = 0;
	for (int i = 0; i < Record_BookNumber; i++)
		if (book[i].GetOn_Shelf() > 0)
		{
			if (num == 0) system("cls");
			book[i].Display_Info();
			num++;
		}

	if (num) cout << "  �����ҵ�" << num << "����" << endl << endl;
	else if (!num) cout << "�������û���ڹݵ��鱾����" << endl << endl;
	retreat_Seek_Shelf();
}

void Seek_NotOnShelf()
{
	int num = 0;
	for (int i = 0; i < Record_BookNumber; i++)
		if (book[i].GetOn_Shelf() == 0)
		{
			if (num == 0) system("cls");
			book[i].Display_Info();
			num++;
		}

	if (num) cout << "  �����ҵ�" << num << "����" << endl << endl;
	else if (!num) cout << "�������û�в��ڹݵ��鱾����" << endl << endl;
	retreat_Seek_Shelf();
}

void Seek_BookPrice()
{
	system("cls");
	double price;//¼��������鱾�۸�

	char price_str[30];
	char* p;
	char* p2 = price_str;
	int flag;
	double price1 = 0.0;
	do 
	{
		flag = 1;
		cout << "��������Ҫ�����鼮�ļ۸�:" << endl;
		cin >> price_str;
		p = price_str;
		int temp = strlen(price_str);
		while (*p != '\0')
		{
			if (*p < '0' || *p>'9')
			{
				if (*p != '.')
				{
					flag = 0; break;
				}
			}
			if (*p == '.') p2 = p;
			p++;
		}

		if (flag)
		{
			int index = (p2 - price_str) / sizeof(char);
			for (int i = 0; i < index; i++)
			{
				price1 += ((double)price_str[index - 1 - i] - '0') * pow(10, i);
			}
			int exponent = -1;
			for (int j = index + 1; j < temp; j++)
			{
				price1 += ((double)price_str[j] - '0') * pow(10, exponent--);
			}
			price = price1;
		}
		else cout << "�����������,���������룡" << endl << endl;

	} while (!flag);

	int num = 0;

	cout << endl;
	for (int i = 0; i < Record_BookNumber; i++)
	{
		if (book[i].GetBookPrice() == price)
		{
			book[i].Display_Info();
			num++;
		}
	}
	if (num) cout << "  �����ҵ�" << num << "����" << endl << endl;
	else if (!num) cout << "û���ҵ���Ӧ����Ŀ" << endl << endl;
	retreat_Seek_Book_Price();
}

//int String_Handling()
//{
//	int sum=0,string_length;
//	char str[30];
//	char* p;
//	int flag=1;
//
//	cin >> str;
//	string_length = strlen(str);
//
//	p = str;
//	while (*p != '\0')
//	{
//		if (*p < '0' || *p>'9')
//		{
//			flag = 0; break;
//		}
//	}
//	if (flag)
//	{
//		for (int i = 0; i < string_length; i++)
//			sum =sum+ (*(p++) - '0') * (int)pow(10, string_length - i - 1);
//		return sum;
//	}
//	else
//	{
//		return -1;
//	}
//}

int Seek_BookID()
{
	system("cls");
	char str[30];
	char* p;
	int sum = 0;
	int flag;

	int bookid=-1;
	int num = 0;

	do 
	{
		flag = 1;
		cout << "��������Ҫ�����鼮�ı�ţ������֣�:" << endl;
		cin>>str;
		int string_length = strlen(str);
		p = str;
		while (*p != '\0')
		{
			if (*p < '0' || *p>'9')
			{
				flag = 0;
				break;
			}
			p++;
		}
		if (flag)
		{
			p = str;
			for (int i = 0; i < string_length; i++)
				sum = sum + (*p++ - '0') * (int)pow(10, string_length - i - 1);
			bookid = sum;
		}
		else 
			cout << endl<<"���벻���Ϲ淶������������!" << endl << endl;
	} while (!flag);


	if(bookid<=0) cout << "���벻���Ϲ淶������������!!" << endl;
	else 
	{
		for (int i = 0; i < Record_BookNumber; i++)
		{
			if (book[i].GetBookID() == bookid)
			{
				book[i].Display_Info();
				num++;
				return i;
			}
		}
		if (!num)
		{
			cout <<endl<< "û���ҵ���Ӧ����Ŀ" << endl << endl;
			return -1;
		}
	}
}

void Clear_Book()
{
	int temp = Record_BookNumber;
	for (int i = 0; i < temp; i++)
	{
		book[i].SetLabel(1);
		book[i].SetISBN((char*)"0");
		book[i].SetBookID(0);
		book[i].SetBookName((char*)"0");
		book[i].SetAuthor((char*)"0");
		book[i].SetPress((char*)"0");
		book[i].SetPublicationTime(0);
		book[i].SetOn_Shelf(0);
		book[i].SetBookPrice(0);
	}
	cout << "�����Ŀ�����" << endl;
	Record_BookNumber = 0;
}
/*
void Copy_Book(Book* target, Book* source)
{
	target->SetLabel(source->GetBookLabel());
	target->SetISBN(source->GetISBN());
	target->SetBookID(source->GetBookID());
	target->SetBookName(source->GetBookName());
	target->SetAuthor(source->GetAuthor());
	target->SetPress(source->GetPress());
	target->SetPublicationTime(source->GetPublicationTime());
	target->SetOn_Shelf(source->GetOn_Shelf());
	target->SetBookPrice(source->GetBookPrice());
}
*/

void swap1(Book* p, Book* q)
{
	Book temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void Sort_Function(int choice)
{
	switch (choice)//ѡ������
	{
		case 1:
		{
			int i, j;
			int flag;
			for (i = 0; i < Record_BookNumber - 1; i++)
			{
				flag = i;
				for (j = i + 1; j < Record_BookNumber; j++)
				{
					if (book[i].GetBookLabel() == 1 && book[j].GetBookLabel() == 0) flag = j;
				}
				if (flag != i) swap1(&book[i], &book[flag]);
			}
			break;
		}
		case 2:
		{
			int m, n;
			int flag2 = -1;
			for (m = 0; m < Record_BookNumber - 1; m++)
			{
				flag2 = m;
				for (n = m + 1; n < Record_BookNumber; n++)
				{
					if (book[m].GetBookLabel() == 0 && book[n].GetBookLabel() == 1) flag2 = n;
				}break;
			}
			if (flag2 != m) swap1(&book[m], &book[flag2]);
			break;
		}
			
	}

	int i, j;
	for(i=0;i<Record_BookNumber;i++)
		for(j=0;j<Record_BookNumber;j++)
		switch (choice)//ð������
		{
		case 3: if (strcmp(book[j].GetISBN(), book[i].GetISBN()) >= 0) swap1(&book[i],&book[j]); break;
		case 4: if (strcmp(book[j].GetISBN(), book[i].GetISBN()) <= 0) swap1(&book[i], &book[j]); break;
		case 5: if (strcmp(book[j].GetBookName(), book[i].GetBookName()) >= 0) swap1(&book[i], &book[j]); break;
		case 6: if (strcmp(book[j].GetBookName(), book[i].GetBookName()) <= 0)swap1(&book[i], &book[j]); break;
		case 7: if (strcmp(book[j].GetAuthor(), book[i].GetAuthor()) >= 0)swap1(&book[i], &book[j]);  break;
		case 8: if (strcmp(book[j].GetAuthor(), book[i].GetAuthor()) <= 0) swap1(&book[i], &book[j]); break;
		case 9: if (strcmp(book[j].GetPress(), book[i].GetPress())>= 0) swap1(&book[i], &book[j]); break;
		case 10:if (strcmp(book[j].GetPress(), book[i].GetPress())<= 0) swap1(&book[i], &book[j]);  break;
		case 11:if (book[j].GetPublicationTime()>=book[i].GetPublicationTime()) swap1(&book[i], &book[j]);  break;
		case 12:if (book[j].GetPublicationTime() <= book[i].GetPublicationTime())swap1(&book[i], &book[j]);  break;
		case 13:if (book[j].GetBookPrice() >= book[i].GetBookPrice())swap1(&book[i], &book[j]);  break;
		case 14:if (book[j].GetBookPrice()<= book[i].GetBookPrice())swap1(&book[i], &book[j]); break;
		case 15:if (book[j].GetOn_Shelf() >= book[i].GetOn_Shelf()) swap1(&book[i], &book[j]); break;
		case 16:if (book[j].GetOn_Shelf() <= book[i].GetOn_Shelf())swap1(&book[i], &book[j]);  break;
		case 17:if (book[j].GetBookID() >= book[i].GetBookID()) swap1(&book[i], &book[j]);  break;
		case 18:if (book[j].GetBookID() <= book[i].GetBookID())swap1(&book[i], &book[j]); break;
		}
}

void Display_ALLBook()//չʾ������Ŀ��Ϣ�Ĺ���
{
	cout << endl;
	if (Record_BookNumber == 0)
	{
		cout << "�������û����Ŀ��" << endl << endl;
		retreat_AddMenu();
	}
	else
	{
		system("cls");

		for (int i = 0; i < Record_BookNumber; i++)
		{ 
			cout << " ���" << i + 1 << endl;
			book[i].Display_Info();
		}
	}
}

void Display_PartBook()
{
	if (Record_BookNumber == 0)
	{
		cout << "�������û����Ŀ��" << endl << endl;
		retreat_AddMenu();
	}
	else 
	{
		int flag = 0;
		int from=-1, to=-1;
		int print_count=0;

		/*****************/
		char begin[30];
		char* p1;
		int sum1 = 0;
		int _flag1;
		do 
		{
			_flag1 = 1;
			cout << "��������Ҫ���ҵ���Ŀ��ŷ�Χ�Ŀ�ʼ(������)��" << endl;
			cin >> begin;
			int string_len1 = strlen(begin);
			p1 = begin;
			while (*p1 != '\0')
			{
				if (*p1 < '0' || *p1>'9')
				{
					_flag1 = 0; break;
				}
				p1++;
			}
			if (_flag1)
			{
				p1 = begin;
				for (int i = 0; i < string_len1; i++)
					sum1 += (*p1++ - '0') * (int)pow(10, string_len1 - i - 1);
				from = sum1;
			}
			else cout << endl << "���벻���Ϲ淶������������!" << endl << endl;
		} while (!_flag1);
		/*****************/

		/*****************/
		char end[30];
		char* p2;
		int sum2 = 0;
		int _flag2;
		do 
		{
			_flag2 = 1;
			cout << "��������Ҫ���ҵ���Ŀ��ŷ�Χ�Ľ���(������)��" << endl;
			cin >> end;
			int string_len2 = strlen(end);
			p2 = end;
			while (*p2 != '\0')
			{
				if (*p2 < '0' || *p2>'9')
				{
					_flag2 = 0;break;
				}
				p2++;
			}
			if (_flag2)
			{
				p2 = end;
				for (int i = 0; i < string_len2; i++)
					sum2 += (*p2++ - '0') * (int)pow(10, string_len2 - i - 1);
				to = sum2;
			}
			else
				cout << endl << "���벻���Ϲ淶������������!" << endl << endl;
		} while (!_flag2);

		/*****************/

		cout << endl<<"����Χ�ڱ�����û�е��鱾���Ϊ:" <<endl;
		for (int i = from; i <= to; i++)
		{
			int isExist2 = 0;
			for (int j = 0; j < Record_BookNumber; j++)
			{
				if (book[j].GetBookID() == i)
					isExist2 = 1;
			}
			if (!isExist2) 
			{
				if (!(print_count % 5))cout <<"   ";
				cout << ((!(print_count%5)) ? "" : ",") << i;
				print_count++;
				if (!(print_count % 5))cout << endl;
			}
		}
		cout << endl<< endl;
		for (int i = from ; i < to ; i++)
			for (int j = 0; j < Record_BookNumber; j++)
			if (book[j].GetBookID() ==i)
			{
				cout << "  ���Ϊ" << i << "�������Ϣ���£�" << endl;
				book[j].Display_Info();
			}
	}
}

void Display_BookName(int num)
{
	cout << book[num].GetBookName() << endl;
}

/*********************************�˵��ľ��幦�ܵ�ʵ��*********************************/
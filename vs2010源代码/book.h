#pragma once
#include"base.h"
const int Max_BookCategory = 30;//�鱾������������	

class Book
{
private:
	bool Label;//1 ��ɾ�� 0δɾ��
	char ISBN[20];//�鱾��ISBN��
	int BookID;//�鱾���
	char BookName[60];//����
	char Author[30];//������
	char Press[30];//������
	int PublicationTime;//����ʱ��(���)
	int On_Shelf;//�Ƿ��ڼ� >0 �ڹ�  =0 ȫ�����
	double BookPrice;//�鱾�۸�

public:

	Book(void)
	{
		Label = 1;
		strcpy(ISBN, "000");
		BookID = -1;
		strcpy(BookName, "000");
		strcpy(Author, "000");
		strcpy(Press, "000");
		PublicationTime = -1;
		On_Shelf = -1;
		BookPrice = -1;

	}

	Book(const char* isbn, int bookid, const char* bookname,const char* author,const char* press, int publicationtime, int on_shelf, double bookprice, bool label = 0)
	{
		Label = label;
		strcpy(ISBN, isbn);
		BookID = bookid;
		strcpy(BookName, bookname);
		strcpy(Author, author);
		strcpy(Press, press);
		PublicationTime = publicationtime;
		On_Shelf = on_shelf;
		BookPrice = bookprice;
	}

	//Book��ĸ��ƹ��캯��
	Book(const Book& copybook)
	{
		Label=copybook.Label;
		strcpy(ISBN, copybook.ISBN);
		BookID = copybook.BookID;
		strcpy(BookName, copybook.BookName);
		strcpy(Author, copybook.BookName);
		strcpy(Press, copybook.Press);
		PublicationTime = copybook.PublicationTime;
		On_Shelf = copybook.On_Shelf;
		BookPrice = copybook.BookPrice;
	}
	
	void Add_Book(char *isbn, int bookid, char* bookname, char* author, char* press, int publicationtime, int on_shelf, double bookprice)
	{
		Label = 0;
		strcpy(ISBN, isbn);
		BookID = bookid;
		strcpy(BookName, bookname);
		strcpy(Author, author);
		strcpy(Press, press);
		PublicationTime = publicationtime;
		On_Shelf = on_shelf;
		BookPrice = bookprice;
	}

	void Add_Book2()//�����ķ�ʽ����鱾����
	{
		Label = 0;

		cout << "�������鱾��ISBN:";
		char isbn[20];
		cin >> isbn;
		strcpy(ISBN, isbn);

		cout << "�������鱾�ı��:";
		int	bookID;
		cin >> bookID;
		BookID = bookID;

		cout << "�������鱾������:";
		char bookname[60];
		cin >> bookname;
		strcpy(BookName, bookname);

		cout << "�������鱾������:";
		char author[30];
		cin >> author;
		strcpy(Author, author);

		cout << "�������鱾�ĳ�����:";
		char press[30];
		cin >> press;
		strcpy(Press, press);

		cout << "�������鱾���ڹ�����:";
		int	on_shelf;
		cin >> on_shelf;
		On_Shelf = on_shelf;

		cout << "�������鱾�ļ۸�:";
		double	price;
		cin >> price;
		BookPrice = price;
		cout << endl;
	}

	void DeleteBook()//ѯ���Ƿ�ɾ������
	{
		cout << "��ȷ��Ҫɾ�������� (Y/y��N/n)" << endl;
		char temp;
		cin >> temp;
		if (temp == 'y' || temp == 'Y')
			Label = 1;
	}

	void SetLabel(bool label)//�����鼮����ɾ������δɾ���ı�ǩ
	{
		Label=label;//LabelΪ1��ʾ�鱾��ɾ����Ϊ0��ʾ�鱾δɾ��
	}

	void SetISBN(char* isbn)//�����鼮��ISBN
	{
		strcpy((char*)ISBN, isbn);
	}

	void SetBookID(int bookID)//�����鼮�ı����
	{
		BookID = bookID;
	}

	void SetBookName(char* bookname)//�����鼮������
	{
		strcpy((char*)BookName, bookname);
	}

	void SetAuthor(char* author)//�����鼮��������
	{
		strcpy(Author, author);
	}

	void SetPress(char* press)//�����鼮�ĳ�������
	{
		strcpy((char*)Press, press);
	}

	void SetPublicationTime(int time)//�����鼮�ĳ������
	{
		PublicationTime = time;
	}

	void SetOn_Shelf(int on_shelf)//�����鼮���ڼ�����
	{
		On_Shelf = on_shelf;
	}
	void SetBookPrice(double price)//�����鼮�ļ۸�
	{
		BookPrice = price;
	}

	bool GetBookLabel()//�����鼮�ı�ǩ����ɾ������δɾ����
	{
		return Label;
	}

	char * GetISBN()//�����鼮��ISBN
	{
		return ISBN;
	}

	int GetBookID()//�����鼮�ı��
	{
		return BookID;
	}

	char* GetBookName()//�����鼮������
	{
		return BookName;
	}

	char* GetAuthor()//�����鼮��������
	{
		return Author;
	}

	char* GetPress()//�����鼮�ĳ�������
	{
		return Press;
	}

	int GetPublicationTime()//�����鼮�ĳ���ʱ��
	{
		return PublicationTime;
	}

	int GetOn_Shelf()//�����鼮���ڼ�����
	{
		return On_Shelf;
	}

	double GetBookPrice()//�����鼮�ļ۸�
	{
		return BookPrice;
	}

	void Display_Info()//��������������Ϣ
	{
		cout << "�鱾ISBN��     " << ISBN << endl;
		cout << "�鱾���:      " << BookID << endl;
		cout << "�鱾����:      " << BookName << endl;
		cout << "�鱾״̬:      ";
		if (Label) cout<<  "��ɾ��" << endl;
		else cout << "δɾ��" << endl;
		cout << "�������ƣ�     " << Author << endl;
		cout << "����������:    " << Press << endl;
		cout << "�������:      " << PublicationTime << endl;
		cout << "�鱾�ڹ�����:  " << On_Shelf << endl;
		cout << "�鱾�۸�     " << BookPrice << endl;
		cout << endl;
	}

	~Book(void){}
};
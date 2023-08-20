#pragma once
#include"base.h"
const int Max_BookCategory = 30;//书本最大的类型数量	

class Book
{
private:
	bool Label;//1 已删除 0未删除
	char ISBN[20];//书本的ISBN号
	int BookID;//书本编号
	char BookName[60];//书名
	char Author[30];//作者名
	char Press[30];//出版社
	int PublicationTime;//出版时间(年份)
	int On_Shelf;//是否在架 >0 在馆  =0 全部借出
	double BookPrice;//书本价格

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

	//Book类的复制构造函数
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

	void Add_Book2()//交互的方式添加书本类型
	{
		Label = 0;

		cout << "请输入书本的ISBN:";
		char isbn[20];
		cin >> isbn;
		strcpy(ISBN, isbn);

		cout << "请输入书本的编号:";
		int	bookID;
		cin >> bookID;
		BookID = bookID;

		cout << "请输入书本的书名:";
		char bookname[60];
		cin >> bookname;
		strcpy(BookName, bookname);

		cout << "请输入书本的作者:";
		char author[30];
		cin >> author;
		strcpy(Author, author);

		cout << "请输入书本的出版社:";
		char press[30];
		cin >> press;
		strcpy(Press, press);

		cout << "请输入书本的在馆数量:";
		int	on_shelf;
		cin >> on_shelf;
		On_Shelf = on_shelf;

		cout << "请输入书本的价格:";
		double	price;
		cin >> price;
		BookPrice = price;
		cout << endl;
	}

	void DeleteBook()//询问是否删除本书
	{
		cout << "你确定要删除本书吗？ (Y/y或N/n)" << endl;
		char temp;
		cin >> temp;
		if (temp == 'y' || temp == 'Y')
			Label = 1;
	}

	void SetLabel(bool label)//设置书籍的已删除或者未删除的标签
	{
		Label=label;//Label为1表示书本已删除，为0表示书本未删除
	}

	void SetISBN(char* isbn)//设置书籍的ISBN
	{
		strcpy((char*)ISBN, isbn);
	}

	void SetBookID(int bookID)//设置书籍的本编号
	{
		BookID = bookID;
	}

	void SetBookName(char* bookname)//设置书籍的书名
	{
		strcpy((char*)BookName, bookname);
	}

	void SetAuthor(char* author)//设置书籍的作者名
	{
		strcpy(Author, author);
	}

	void SetPress(char* press)//设置书籍的出版社名
	{
		strcpy((char*)Press, press);
	}

	void SetPublicationTime(int time)//设置书籍的出版年份
	{
		PublicationTime = time;
	}

	void SetOn_Shelf(int on_shelf)//设置书籍的在架数量
	{
		On_Shelf = on_shelf;
	}
	void SetBookPrice(double price)//设置书籍的价格
	{
		BookPrice = price;
	}

	bool GetBookLabel()//返回书籍的标签（已删除或者未删除）
	{
		return Label;
	}

	char * GetISBN()//返回书籍的ISBN
	{
		return ISBN;
	}

	int GetBookID()//返回书籍的编号
	{
		return BookID;
	}

	char* GetBookName()//返回书籍的书名
	{
		return BookName;
	}

	char* GetAuthor()//返回书籍的作者名
	{
		return Author;
	}

	char* GetPress()//返回书籍的出版社名
	{
		return Press;
	}

	int GetPublicationTime()//返回书籍的出版时间
	{
		return PublicationTime;
	}

	int GetOn_Shelf()//返回书籍的在架数量
	{
		return On_Shelf;
	}

	double GetBookPrice()//返回书籍的价格
	{
		return BookPrice;
	}

	void Display_Info()//输出本书的所有信息
	{
		cout << "书本ISBN：     " << ISBN << endl;
		cout << "书本编号:      " << BookID << endl;
		cout << "书本名称:      " << BookName << endl;
		cout << "书本状态:      ";
		if (Label) cout<<  "已删除" << endl;
		else cout << "未删除" << endl;
		cout << "作者名称：     " << Author << endl;
		cout << "出版社名称:    " << Press << endl;
		cout << "出版年份:      " << PublicationTime << endl;
		cout << "书本在馆数量:  " << On_Shelf << endl;
		cout << "书本价格：     " << BookPrice << endl;
		cout << endl;
	}

	~Book(void){}
};
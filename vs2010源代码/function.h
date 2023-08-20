#pragma once
#include "book.h"
extern const int Max_BookCategory;//外部变量，书本最大的类型数量(定义在book.h)
extern int Record_BookNumber;//外部变量，书本最大的类型数量(定义在main.h)

//增加
void Add_bookCategory();//添加书本种类功能的函数

//删除
int Record_BookLabel_unDelete();//遍历书本类型，统计未删除的书本类型
void Delete_AllBook();//删除所有书目功能的函数
void Delete_PartBook();//删除部分书目功能的函数

//修改
void Modify_Function(int num, int index);
void Modify_ISBN(int index);//修改下标为index的书目的ISBN
void Modify_BookName(int index);
void Modify_Author(int index);
void Modify_Press(int index);
void Modify_PublicationTime(int index);
void Modify_BookPrice(int index);
void Modify_BookID(int index);

//查找
void Seek_unDelete();//查找所有标签为未删除的书目的函数
void Seek_isDelete();//查找所有标签为已删除的书目的函数
int Seek_ISBN();//查找书本的ISBN函数
int Find_Function();//根据编号或者ISBN查找书的信息
void Seek_BookName();//查找书本的名称的函数
void Seek_AuthorName();//查找书本的作者名的函数
void Seek_PressName();//查找书本的出版社名的函数
void Seek_PublicationTime();//查找书本的出版年份的函数
void Seek_OnShelf();//查找书本中在馆的书籍的函数
void Seek_NotOnShelf();//查找书本中不在馆的书籍的函数
void Seek_BookPrice();//查找书本价格的函数
int  Seek_BookID();//查找书本编号的函数

//清空
void Clear_Book();//清除所有书目的函数

//排序
void swap1(Book* p, Book* q);
void Sort_Function(int choice);//查找函数

//查找
void Display_ALLBook();//展示所有书籍种类的全部信息
void Display_PartBook();//展示查找范围内的书籍种类的全部信息
void Display_BookName(int num);//展示书库第num个书本类型的书名

//特殊的辅助函数
int String_Handling();//字符串处理函数，以字符的形式输入数字，再将字符转换为int型数字
#pragma once
#include "book.h"
extern const int Max_BookCategory;//�ⲿ�������鱾������������(������book.h)
extern int Record_BookNumber;//�ⲿ�������鱾������������(������main.h)

//����
void Add_bookCategory();//����鱾���๦�ܵĺ���

//ɾ��
int Record_BookLabel_unDelete();//�����鱾���ͣ�ͳ��δɾ�����鱾����
void Delete_AllBook();//ɾ��������Ŀ���ܵĺ���
void Delete_PartBook();//ɾ��������Ŀ���ܵĺ���

//�޸�
void Modify_Function(int num, int index);
void Modify_ISBN(int index);//�޸��±�Ϊindex����Ŀ��ISBN
void Modify_BookName(int index);
void Modify_Author(int index);
void Modify_Press(int index);
void Modify_PublicationTime(int index);
void Modify_BookPrice(int index);
void Modify_BookID(int index);

//����
void Seek_unDelete();//�������б�ǩΪδɾ������Ŀ�ĺ���
void Seek_isDelete();//�������б�ǩΪ��ɾ������Ŀ�ĺ���
int Seek_ISBN();//�����鱾��ISBN����
int Find_Function();//���ݱ�Ż���ISBN���������Ϣ
void Seek_BookName();//�����鱾�����Ƶĺ���
void Seek_AuthorName();//�����鱾���������ĺ���
void Seek_PressName();//�����鱾�ĳ��������ĺ���
void Seek_PublicationTime();//�����鱾�ĳ�����ݵĺ���
void Seek_OnShelf();//�����鱾���ڹݵ��鼮�ĺ���
void Seek_NotOnShelf();//�����鱾�в��ڹݵ��鼮�ĺ���
void Seek_BookPrice();//�����鱾�۸�ĺ���
int  Seek_BookID();//�����鱾��ŵĺ���

//���
void Clear_Book();//���������Ŀ�ĺ���

//����
void swap1(Book* p, Book* q);
void Sort_Function(int choice);//���Һ���

//����
void Display_ALLBook();//չʾ�����鼮�����ȫ����Ϣ
void Display_PartBook();//չʾ���ҷ�Χ�ڵ��鼮�����ȫ����Ϣ
void Display_BookName(int num);//չʾ����num���鱾���͵�����

//����ĸ�������
int String_Handling();//�ַ��������������ַ�����ʽ�������֣��ٽ��ַ�ת��Ϊint������
#pragma once

/**********************/
//չʾ����˵��Ŀ��
void Manager_Login();//����Ա��¼�Ľ���
void Main_Menu();//ϵͳ��ҳ��ҳ��
void Add_Menu();//�����Ŀ���͵�ҳ��
void Delete_Menu();//ɾ���鱾��ҳ��
void Modify_Menu();//�޸��鱾��Ϣ��ҳ��
void Modify_SubMenu();//�޸��鱾��Ϣ����ҳ��
void Seek_Menu();//�����鱾��ҳ��
void Seek_BookLabel();//�����鱾��ǩ��ҳ��
void Seek_Shelf();//�����鱾�Ƿ��ڹݵ�ҳ��
void Clear_Menu();//���������Ŀ���͵�ҳ��
void Sort_Menu();//��Ŀ���ҵ�ҳ��
void Sort_SubMenu();//��Ŀ���ҵĶ�����ҳ��
void Display_Menu();//չʾ��Ŀ���͵�ҳ��
void Exit_System();//�˳�ϵͳ
/**********************/

/**������һ���ĺ���**/
void retreat_MainMenu();//ѯ���Ƿ�Ҫ���ص����˵��ĺ���
void retreat_AddMenu();//ѯ���Ƿ�Ҫ���ص���Ӳ˵��ĺ���
void retreat_AddBookCategory();//ѯ���Ƿ�Ҫ���뵽�����Ŀ���͹��ܵĺ���
//void Seek_BookLabel(); //ѯ���Ƿ�Ҫ���ص���ѯ��Ŀ״̬�Ĺ��ܵĺ���
void retreat_DeleteMenu(); //ѯ���Ƿ�Ҫ���ص�ɾ���˵��ĺ���
//void Back_To_Seek(int option);//����ѡ��ȥ������Ҳ˵�����ĳ��ܵĺ�������δʹ�ã�
void retreat_Seek_BookLabel();//ѯ���Ƿ�Ҫ���ص���ѯ��Ŀ״̬���ܵĺ���
void retreat_Seek_ISBN(); //ѯ���Ƿ�Ҫ���ص���ѯ��ĿISBN���ܵĺ���
void retreat_Seek_BookName();//ѯ���Ƿ�Ҫ���ص���ѯ��Ŀ���ƹ��ܵĺ���
void retreat_Seek_AuthorName();//ѯ���Ƿ�Ҫ���ص���ѯ��Ŀ���������ܵĺ���
void retreat_Seek_PressName();//ѯ���Ƿ�Ҫ���ص���ѯ��Ŀ�����������ܵĺ���
void retreat_Seek_PublicationTime();//ѯ���Ƿ�Ҫ���ص���ѯ��Ŀ����ʱ�书�ܵĺ���
void retreat_Seek_Shelf();//ѯ���Ƿ�Ҫ���ص���ѯ��Ŀ�Ƿ��ڼܵĹ��ܵĺ���
void retreat_Seek_Book_Price();//ѯ���Ƿ�Ҫ���ص���ѯ��Ŀ�۸��ܵĺ���
void retreat_Seek_BookID();//ѯ���Ƿ�Ҫ���ص���ѯ��Ŀ��Ź��ܵĺ���

void retreat_SortMenu();//ѯ���Ƿ�Ҫ���ص�����˵��ĺ���
void retreat_Modify_Menu();//ѯ���Ƿ�Ҫ���ص��޸Ĳ˵��ĺ���
void retreat_DisplayMenu();//ѯ���Ƿ�Ҫ���ص�չʾ�˵��ĺ���
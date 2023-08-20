#pragma once

/**********************/
//展示界面菜单的框架
void Manager_Login();//管理员登录的界面
void Main_Menu();//系统首页的页面
void Add_Menu();//添加书目类型的页面
void Delete_Menu();//删除书本的页面
void Modify_Menu();//修改书本信息的页面
void Modify_SubMenu();//修改书本信息的子页面
void Seek_Menu();//查找书本的页面
void Seek_BookLabel();//查找书本标签的页面
void Seek_Shelf();//查找书本是否在馆的页面
void Clear_Menu();//清空所有书目类型的页面
void Sort_Menu();//书目查找的页面
void Sort_SubMenu();//书目查找的二级子页面
void Display_Menu();//展示书目类型的页面
void Exit_System();//退出系统
/**********************/

/**返回上一级的函数**/
void retreat_MainMenu();//询问是否要返回到主菜单的函数
void retreat_AddMenu();//询问是否要返回到添加菜单的函数
void retreat_AddBookCategory();//询问是否要进入到添加书目类型功能的函数
//void Seek_BookLabel(); //询问是否要返回到查询书目状态的功能的函数
void retreat_DeleteMenu(); //询问是否要返回到删除菜单的函数
//void Back_To_Seek(int option);//根据选项去进入查找菜单里面某项功能的函数（暂未使用）
void retreat_Seek_BookLabel();//询问是否要返回到查询书目状态功能的函数
void retreat_Seek_ISBN(); //询问是否要返回到查询书目ISBN功能的函数
void retreat_Seek_BookName();//询问是否要返回到查询书目名称功能的函数
void retreat_Seek_AuthorName();//询问是否要返回到查询书目作者名功能的函数
void retreat_Seek_PressName();//询问是否要返回到查询书目出版社名功能的函数
void retreat_Seek_PublicationTime();//询问是否要返回到查询书目出版时间功能的函数
void retreat_Seek_Shelf();//询问是否要返回到查询书目是否在架的功能的函数
void retreat_Seek_Book_Price();//询问是否要返回到查询书目价格功能的函数
void retreat_Seek_BookID();//询问是否要返回到查询书目编号功能的函数

void retreat_SortMenu();//询问是否要返回到排序菜单的函数
void retreat_Modify_Menu();//询问是否要返回到修改菜单的函数
void retreat_DisplayMenu();//询问是否要返回到展示菜单的函数
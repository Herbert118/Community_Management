#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED
#include "service.h"
///会员管理+++++++++++++++++++++++++++++++++++++++++++++
//会员系统会员系统会员系统会员系统会员系统会员系统会员系统会员系统会员系统

void setmember(MEMBER **memberptr, HOUSE *househead);
//建立会员链表，完成会员姓名 id 房间号码的录入，并对相应房间状态（used_or_not）进行更改
void memberManagement(MEMBER **memberhead, HOUSE *househead);
//会员系统功能菜单
void storesmember(MEMBER *p);
//读取本地文件中的会员信息并将其添加至链表中
void houselist(HOUSE *househead);
//列出能够购买的房屋
void searchmember(MEMBER *memberhead);
//查找会员，包括按姓名和id两种方式查找
void modifymember(MEMBER *memberhead, HOUSE *househead);
//修改会员信息
void deletemember(MEMBER **memberhead, HOUSE *househead);
//删除会员信息
void localmember(MEMBER **memberhead);
//将setmember中录入的会员信息储存到本地文件中
void printmember(MEMBER *p);
//显示所有的会员信息
void searchid(MEMBER *p);
//按id查找会员
void searchname(MEMBER *p);
//按姓名查找会员
//会员系统会员系统会员系统会员系统会员系统会员系统会员系统会员系统会员系统
///房屋管理++++++++++++++++++++++++++++++++++++++++++++
void houseManagement(HOUSE *head);
//房屋管理系统总管理
void housemenu();
//菜单
void buildhouse(HOUSE *head);
//新建房屋，输入id和价格
void deletehouse(HOUSE *head);
//删除房屋
void printhouse(HOUSE *head);
//显示单个房屋
void Load_house(HOUSE *head);
//从文件加载房屋到链表
void savehouse(HOUSE *head);
//保存链表信息到文件
void printhousesall(HOUSE *head);
//显示所有房屋
void printhousesused(HOUSE *head);
//显示已用房屋
void printhousesempty(HOUSE *head);
//显示空置房屋
void storeshouse(HOUSE *p);
//读取本地文件中的会员信息并将其添加至链表中
void searchhouse(HOUSE *head);
//查找房屋
void modifyhouse(HOUSE *head);
//修改房屋信息
void localhouse(HOUSE *head);
//将sethouse中录入的信息储存到本地文件中
void search(HOUSE*p);
//搜索房屋


#endif // MEMBER_H_INCLUDED

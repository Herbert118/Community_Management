#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include "house.h"
#include <stdio.h>
void service();

typedef struct SERVICE
{
    int serviceId;
    int finished;
    int payed;
    struct SERVICE *next;
} SERVICE;

typedef struct member
{
    char name[20];
    int id;
    int house_number;
    SERVICE *servicehead;
    struct member *next;
} MEMBER;



///函数原型+++++++++++++++++++++++++++++++++++++++++++
void menu();
//显示总菜单，进行函数调用

///设施管理+++++++++++++++++++++++++++++++++++++
void entertainment_menu();
//显示设施菜单
void entertainment_1(int enter_number[4], int entertainment_id[1000][2], int entertainment_fix[4]);
//进入场馆，记录预约人数，和预约号
void entertainment_2(int enter_number[4], int entertainment_id[1000][2]);
//退出场馆，输入预约号
void entertainment_3(int entertainment_fix[4], int enter_number[4], int entertainment_id[1000][2]);
//维修场馆，同时请出馆内人员
void entertainment();
//设施总管理系统，进行选择，和文件读写
///服务管理+++++++++++++++++++++++++++++++++++++++
void serviceManagement(MEMBER *memberhead);
//显示服务菜单，用户可预约服务，付款，工作人员可查看预约，完成服务
///包含下列函数
void reserveService(MEMBER *memberChoose);
//用户预定服务
void payForService(MEMBER *memberChoose);
//用户为已完成的服务付款，输入id或名字，选择要付款的服务，并付款
void checkService(MEMBER *memberhead);
//工作人员输入服务对象，列出已预约的服务
void finishService(MEMBER *memberChoose);
//工作人员完成服务后，输入服务对象，并选择完成的服务
SERVICE *createServiceNode(int servId, MEMBER *memberChoose);
//创建服务节点，通过拿到的用户节点，在用户的预定服务链表里增添节点
//在reserveService()中被调用
MEMBER *searchForMember(MEMBER *memberhead, char *name);
//通过用户id得到member节点
char *getServiceName(int serviceId);
//通过serviceid返回服务名
int getServicePrice(int serviceId);
//通过serviceId返回价格
void saveService(MEMBER *memberhead);
//将服务信息储存在文件中
void loadService(MEMBER *memberhead);
//加载文件中的服务信息
///+++++++++++++++++++++++++++++++++++++++++++++++serviceManagement()包含上述函数
///+++++++++++++++++++++++++++++++++++++++++++++++函数原型


#endif // SERVICE_H_INCLUDED

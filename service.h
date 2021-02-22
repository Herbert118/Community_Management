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



///����ԭ��+++++++++++++++++++++++++++++++++++++++++++
void menu();
//��ʾ�ܲ˵������к�������

///��ʩ����+++++++++++++++++++++++++++++++++++++
void entertainment_menu();
//��ʾ��ʩ�˵�
void entertainment_1(int enter_number[4], int entertainment_id[1000][2], int entertainment_fix[4]);
//���볡�ݣ���¼ԤԼ��������ԤԼ��
void entertainment_2(int enter_number[4], int entertainment_id[1000][2]);
//�˳����ݣ�����ԤԼ��
void entertainment_3(int entertainment_fix[4], int enter_number[4], int entertainment_id[1000][2]);
//ά�޳��ݣ�ͬʱ���������Ա
void entertainment();
//��ʩ�ܹ���ϵͳ������ѡ�񣬺��ļ���д
///�������+++++++++++++++++++++++++++++++++++++++
void serviceManagement(MEMBER *memberhead);
//��ʾ����˵����û���ԤԼ���񣬸��������Ա�ɲ鿴ԤԼ����ɷ���
///�������к���
void reserveService(MEMBER *memberChoose);
//�û�Ԥ������
void payForService(MEMBER *memberChoose);
//�û�Ϊ����ɵķ��񸶿����id�����֣�ѡ��Ҫ����ķ��񣬲�����
void checkService(MEMBER *memberhead);
//������Ա�����������г���ԤԼ�ķ���
void finishService(MEMBER *memberChoose);
//������Ա��ɷ�������������󣬲�ѡ����ɵķ���
SERVICE *createServiceNode(int servId, MEMBER *memberChoose);
//��������ڵ㣬ͨ���õ����û��ڵ㣬���û���Ԥ����������������ڵ�
//��reserveService()�б�����
MEMBER *searchForMember(MEMBER *memberhead, char *name);
//ͨ���û�id�õ�member�ڵ�
char *getServiceName(int serviceId);
//ͨ��serviceid���ط�����
int getServicePrice(int serviceId);
//ͨ��serviceId���ؼ۸�
void saveService(MEMBER *memberhead);
//��������Ϣ�������ļ���
void loadService(MEMBER *memberhead);
//�����ļ��еķ�����Ϣ
///+++++++++++++++++++++++++++++++++++++++++++++++serviceManagement()������������
///+++++++++++++++++++++++++++++++++++++++++++++++����ԭ��


#endif // SERVICE_H_INCLUDED

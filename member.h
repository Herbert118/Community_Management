#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED
#include "service.h"
///��Ա����+++++++++++++++++++++++++++++++++++++++++++++
//��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ

void setmember(MEMBER **memberptr, HOUSE *househead);
//������Ա������ɻ�Ա���� id ��������¼�룬������Ӧ����״̬��used_or_not�����и���
void memberManagement(MEMBER **memberhead, HOUSE *househead);
//��Աϵͳ���ܲ˵�
void storesmember(MEMBER *p);
//��ȡ�����ļ��еĻ�Ա��Ϣ�����������������
void houselist(HOUSE *househead);
//�г��ܹ�����ķ���
void searchmember(MEMBER *memberhead);
//���һ�Ա��������������id���ַ�ʽ����
void modifymember(MEMBER *memberhead, HOUSE *househead);
//�޸Ļ�Ա��Ϣ
void deletemember(MEMBER **memberhead, HOUSE *househead);
//ɾ����Ա��Ϣ
void localmember(MEMBER **memberhead);
//��setmember��¼��Ļ�Ա��Ϣ���浽�����ļ���
void printmember(MEMBER *p);
//��ʾ���еĻ�Ա��Ϣ
void searchid(MEMBER *p);
//��id���һ�Ա
void searchname(MEMBER *p);
//���������һ�Ա
//��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ
///���ݹ���++++++++++++++++++++++++++++++++++++++++++++
void houseManagement(HOUSE *head);
//���ݹ���ϵͳ�ܹ���
void housemenu();
//�˵�
void buildhouse(HOUSE *head);
//�½����ݣ�����id�ͼ۸�
void deletehouse(HOUSE *head);
//ɾ������
void printhouse(HOUSE *head);
//��ʾ��������
void Load_house(HOUSE *head);
//���ļ����ط��ݵ�����
void savehouse(HOUSE *head);
//����������Ϣ���ļ�
void printhousesall(HOUSE *head);
//��ʾ���з���
void printhousesused(HOUSE *head);
//��ʾ���÷���
void printhousesempty(HOUSE *head);
//��ʾ���÷���
void storeshouse(HOUSE *p);
//��ȡ�����ļ��еĻ�Ա��Ϣ�����������������
void searchhouse(HOUSE *head);
//���ҷ���
void modifyhouse(HOUSE *head);
//�޸ķ�����Ϣ
void localhouse(HOUSE *head);
//��sethouse��¼�����Ϣ���浽�����ļ���
void search(HOUSE*p);
//��������


#endif // MEMBER_H_INCLUDED

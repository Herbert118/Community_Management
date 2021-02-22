#include "service.h"
void service()
{
    printf("you are being serviced!");

}
//��ʾ����˵����û���ԤԼ���񣬸��������Ա�ɲ鿴ԤԼ����ɷ���
void serviceManagement(MEMBER *memberhead)
{
    char name[30];
    int iden;
    int choice = 1;
    SERVICE *memberChoose;
AGAIN2:
    printf("\t ����:\n\n");
    printf("\t 1 �û�\n\n");
    printf("\t 2 ������Ա\n\n");
    printf("%s\t", "����������ѡ��:");
    scanf("%d", &iden);
    scanf("%*[^\n]");
    scanf("%*c");
    system("cls");
    if (iden == 1)
    {
        printf("\t%s\t", "��������������");
        scanf("%s", name);

        if ((memberChoose = searchForMember(memberhead, name)) == NULL)
        {
            printf("%s\n\n", "���û�������!");
            return;
        }
        while (choice)
        {
            system("cls");
            printf("\t 0�˳�\n\n");
            printf("\t 1 ԤԼ����\n\n");
            printf("\t 2 ֧������\n\n");
            printf("%s\t", "����������ѡ��:");
            scanf("%*[^\n]");
            scanf("%*c"); ///I don't know why the problem suddenly occured(-:
            scanf("%d", &choice);
            switch (choice)
            {
            case 0:
                break;
            case 1:
                reserveService(memberChoose);
                saveService(memberhead);
                break;
            case 2:
                payForService(memberChoose);
                saveService(memberhead);
                break;
            default:
                printf("û�д�ѡ�������ѡ��\n\n");
                system("pause");
            }
        }
    }
    else if (iden == 2)
    {
        while (choice)
        {
            printf("\t 0 �˳��������ϵͳ\n\n");
            printf("\t 1 �鿴����δ��ɵ�ԤԼ����\n\n");
            printf("\t 2 ����û���ԤԼ����\n\n");
            printf("%s\t", "����������ѡ��:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 0:
                break;
            case 1:
                checkService(memberhead);
                break;
            case 2:
                finishService(memberhead);
                saveService(memberhead);
            default:
                printf("%s\n", "û�д�ѡ�������ѡ��");
                system("pause");
            }
        }
    }
    else
    {
        printf("%s\n\n", "û�д�ѡ�������ѡ��\n\n");
        system("pause");
        goto AGAIN2;
    }
}

//�û�Ԥ������
void reserveService(MEMBER *memberChoose)
{
    int serviceId;
    int i;
    int chooseagain = 0;
    do
    {
        printf("\t%-10s%-20s%-30s\n\n", "ѡ��", "��ѡ����", "����۸�");
        for (i = 0; i < 5; i++)
        {
            printf("\t%-5d%-25s%-25d\n\n", i + 1, getServiceName(i + 1), getServicePrice(i + 1));
        }
        printf("%s\t", "����������ѡ��:");
        scanf("%d", &serviceId);
        if (serviceId > 5 || serviceId < 0)
        {
            chooseagain = 1;
            printf("%s\n\n", "û�д�ѡ�������ѡ��");
        }
        else
        {
            chooseagain = 0;
        }
    } while (chooseagain);
    createServiceNode(serviceId, memberChoose);
    printf("'\t ���ɹ�ԤԼ��%s", getServiceName(serviceId));
    system("pause");
}

MEMBER *searchForMember(MEMBER *memberhead, char *name)
{
    if (memberhead == NULL)
    {
        return NULL;
    } ///here for test
    MEMBER *memberChoose = memberhead;
    while (strcmp(memberChoose->name,name)!=0 )
    {
        memberChoose = memberChoose->next;
        if (memberChoose == NULL)
        {
            return NULL;
        }
    }
    return memberChoose;
}

//��������ڵ㣬ͨ���õ����û��ڵ㣬���û���Ԥ����������������ڵ�
SERVICE *createServiceNode(int servId, MEMBER *memberChoose)
{
    SERVICE **head = &memberChoose->servicehead;
    SERVICE *cur = NULL;
    SERVICE *newp;
    newp = (SERVICE *)malloc(sizeof(SERVICE));
    if (newp != NULL)
    {
        if (*head == NULL)
        {
            *head = newp;
        }
        else
        {
            cur=*head;
            while(cur->next!=NULL)
            {
            cur=cur->next;
            }
            cur->next = newp;
        }
    }
    else
    {
        printf("%s\n\n", "ԤԼʧ��");
        return -1;
    }

    newp->serviceId = servId;
    newp->payed = 0;
    newp->finished = 0;
    newp->next = NULL; //a statement with too much blood and pain
    return newp;
}
//�û�Ϊ����ɵķ��񸶿����id�����֣�ѡ��Ҫ����ķ��񣬲�����
void payForService(MEMBER *memberChoose)
{
    int j = 0;
    int sernum;
    SERVICE *curserv = memberChoose->servicehead;
    for (curserv = memberChoose->servicehead; curserv != NULL; curserv = curserv->next)
    {
        if (curserv->finished == 1 && curserv->payed == 0)
        {
            j++;
            printf("%-10d%-30s\n\n", j, getServiceName(curserv->serviceId));
        }
    }
    if (j == 0)
    {
        printf("%s\n", "������֧���κη���");
        system("pause");
        return;
    }
    j = 0; //again
    printf("%s\t", "��������Ҫ֧���ķ����Ӧ�����:");
    scanf("%d", &sernum);
    for (curserv = memberChoose->servicehead; curserv != NULL; curserv = curserv->next)
    {
        if (curserv->finished == 1 && curserv->payed == 0)
        {
            j++;
            if (j == sernum)
            {
                curserv->payed = 1;
                printf("���Ѿ�Ϊ%-10d%-30s֧����%-5dԪ", j, getServiceName(curserv->serviceId), getServicePrice(curserv->serviceId));
                system("pause");
            }
        }
    }
}
//������Ա�����������г���ԤԼ�ķ���
void checkService(MEMBER *memberhead)
{
    MEMBER *curmem = memberhead;
    SERVICE *curserv = NULL;
    int i = 0, j = 0;
    if (curmem == NULL)
    {
        printf("%s\n\n", "���ڻ�û�л�Ա!");
        return;
    }
    for (curmem = memberhead; curmem != NULL; curmem = curmem->next)
    {
        i++;
        printf("%5d%10s%-20s\n\n", i, "", curmem->name); //maybe more information should be added;
        for (curserv = curmem->servicehead; curserv != NULL; curserv = curserv->next)
        {
            if (curserv->finished == 1)
            {
                continue;
            } //and I tried another way
            j++;
            printf("%10d%10s%-30s\n\n", j, "", getServiceName(curserv->serviceId));
        }
        j=0;
    }
    return;
}

//������Ա��ɷ�������������󣬲�ѡ����ɵķ���
void finishService(MEMBER *memberhead)
{
    char name[30];
    MEMBER *memberChoose;
    printf("%s\t", "��������������û�������:");
    scanf("%s", name);
    if ((memberChoose = searchForMember(memberhead, name)) == NULL)
    {
        printf("%s\n\n", "���û������ڣ�");
        return;
    }
    int j = 0;
    int sernum;
    SERVICE *curserv = memberChoose->servicehead;
    for (curserv = memberChoose->servicehead; curserv != NULL; curserv = curserv->next)
    {
        if (curserv->finished == 0)
        {
            j++;
            printf("%-10d%-30s\n\n", j, getServiceName(curserv->serviceId));
        }
    }
    j = 0; //don't forget this
    printf("%s\n\n", "����������ɵķ����Ӧ�����");
    scanf("%d", &sernum);
    for (curserv = memberChoose->servicehead; curserv != NULL; curserv = curserv->next)
    {
        if (curserv->finished == 0)
        {
            j++;
            if (j == sernum)
            {
                curserv->finished = 1;
                printf("%-10d%-30s ����ɹ��ˣ�\n\n", j, getServiceName(curserv->serviceId));
            }
        }
    }
}
//ͨ��serviceid���ط�����
char *getServiceName(int serviceid)
{
    static char serviceName[30];
    switch (serviceid)
    {
    case 1:
        strncpy(serviceName, "psychological talk            ", 30);
        break;
    case 2:
        strncpy(serviceName, "clean the house               ", 30);
        break;
    case 3:
        strncpy(serviceName, "body check                    ", 30);
        break;
    case 4:
        strncpy(serviceName, "send daily goods              ", 30);
        break;
    case 5:
        strncpy(serviceName, "to be continued", 30);
        break;
    case 6:
        strncpy(serviceName, "", 30);
        break;
    case 7:
        strncpy(serviceName, "", 30);
        break;
    default:
        printf("%s\n\n", "something went wrong;");
    }
    return serviceName;
}
//ͨ��serviceId����price
int getServicePrice(int serviceid)
{
    int price;
    switch (serviceid)
    {
    case 1:
        price = 1;
        break;
    case 2:
        price = 2;
        break;
    case 3:
        price = 3;
        break;
    case 4:
        price = 4;
        break;
    case 5:
        price = 5;
        break;
    case 6:
        price = 6;
        break;
    case 7:
        price = 7;
        break;
    default:
        printf("%s\n\n", "something went wrong with price;");
        return -1;
    }
    return price;
}

void loadService(MEMBER *memberhead)
{
    FILE *fp;
    MEMBER *curmem = NULL;
    SERVICE *curserv = NULL;
    int getServiceId(char *serviceName); //here I declare two functions in this function because they are only used in this function
    int judgeYesAndNo(char *yesOrNO);
    int i = 0;
    char ch;
    char serviceName[30];
    char ifFinished[10];
    char ifPayed[10];
    if ((fp = fopen("service.txt", "r")) == NULL)
    {
        printf("%s\n", "����û�з�����Ϣ");
    }
    else
    {
        for (curmem = memberhead; curmem != NULL; curmem = curmem->next)
        {
            fscanf(fp, "%*[^\n]");
            fscanf(fp, "%*\n");
            while (1)
            {
                fscanf(fp, "%*7[\x01-\x7F]");
                ch = getc(fp); //be careful, a small bug can make the debug very complex
                if (ch == 32 && !feof(fp))
                {
                    fscanf(fp, "%*[ ]%30[a-z ]%s%s", serviceName, ifFinished, ifPayed);
                    fscanf(fp, "%*\n");
                    curserv = createServiceNode(getServiceId(serviceName), curmem);
                    curserv->finished = judgeYesAndNo(ifFinished);
                    curserv->payed = judgeYesAndNo(ifPayed);
                }
                else
                {
                    break;
                }
            }
        }
        fclose(fp);
        printf("%s\n", "���ط�����Ϣ��ȡ���");
    } //end if for file
}

int getServiceId(char *serviceName) //I used a small function here
{
    int i;
    for (i = 1; i <= 7; i++)
    {
        if (strcmp(serviceName, getServiceName(i)) == 0)
        {
            return i;
        }
    }
}

int judgeYesAndNo(char *yesOrNo)
{
    if (strcmp(yesOrNo, "yes") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//it is the end of the two functions

void saveService(MEMBER *memberhead)
{
    FILE *fp;
    MEMBER *curmem;
    SERVICE *curserv;
    int i = 0;
    if ((fp = fopen("service.txt", "w+")) == NULL)
    {
        printf("%s\n", "file open failed");
    }
    else
    {
        for (curmem = memberhead; curmem != NULL; curmem = curmem->next)
        {
            i = 0;
            if (curmem->servicehead == NULL)
            {
                continue;
            }
            fprintf(fp, "%8d%5s%-15s%-25s%-40s%-50s\n", curmem->id, "", curmem->name, "service booked", "finished", "payed");
            for (curserv = curmem->servicehead; curserv != NULL; curserv = curserv->next)
            {
                i++;
                fprintf(fp, "%10d%25s%-30s%-40s%-50s\n", i, "", getServiceName(curserv->serviceId), curserv->finished ? "yes" : "no", curserv->finished ? "yes" : "no");
            }
        }
        fclose(fp);
    } //end if for file
    return;
}

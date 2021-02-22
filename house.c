#include "service.h"
#include "house.h"


///FOX'part+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//���ݹ���ϵͳ�ܹ���
void houseManagement(HOUSE *head)
{
    int choice;
    do
    {
        housemenu();
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 0:
            printf("�����˳�...\n");
            break;
        case 1:
            printf("�½����ݣ�\n");
            buildhouse(head);
            savehouse(head);
            break;
        case 2:
            printf("ɾ�����ݣ�\n");
            deletehouse(head);
            break;
        case 3:
            printf("��ʾ���з��� \n");
            printhousesall(head->next);
            break;
        case 4:
            printf("��ʾ���÷��� \n");
            printhousesused(head->next);
            break;
        case 5:
            printf("��ʾ���з��� \n");
            printhousesempty(head->next);
            break;
        case 6:
            printf("��ʾָ������ \n");
            search(head->next);
            break;

        default:
            printf("No such choice. Please enter a right choice (0-5)!\n");
        }
        if (choice)
            printf("\n\nPress any key to continue.");
        getch();
    } while (choice);
    savehouse(head);
}
//*********************************************************************************************
//�˵�
void housemenu()
{

    system("cls");
    printf("\t\t _________________________________________________\n");
    printf("\t\t|-------------House management system-------------|\n");
    printf("\t\t|                                                 |\n");
    printf("\t\t|           0  - �˳�                             |\n");
    printf("\t\t|           1  - �½�����                         |\n");
    printf("\t\t|           2  - ɾ������                         |\n");
    printf("\t\t|           3  - ��ʾ���з���                     |\n");
    printf("\t\t|           4  - ��ʾ���÷���                     |\n");
    printf("\t\t|           5  - ��ʾ���з���                     |\n");
    printf("\t\t|           6  - ��ʾָ������                     |\n");
    printf("\t\t|_________________________________________________|\n");
    printf("\n\t\tPlease enter your choice (0-5): ");
    printf("please enter your choice");
}
//*******************************************************************************************

//*******************************************************************************************
//�½����ݣ����뷿��id�ͼ۸�
void buildhouse(HOUSE *p)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = (HOUSE *)malloc(sizeof(HOUSE));
    p = p->next;
    printf("�������·���ID");
    scanf("%d", &p->number);
    p->used_or_not = 0;
    printf("�������·��ݼ۸�");
    scanf("%f", &p->price);
    p->next = NULL;

    return;
}
//*******************************************************************************************
//ɾ������
void deletehouse(HOUSE *p)
{
    int id;
    int i;
    HOUSE *half;
    printf("�������ɾ������ID");
    scanf("%d", &id);
    while (p->next != NULL)
    {
        if (id == p->next->number)
        {
            printhouse(p->next);
            if (p->next->used_or_not == 0)
            {
                printf("ȷ��ɾ����1\nȡ�������������\n");
                scanf("%d", &i);
                if (i == 1)
                {
                    half = p->next->next;
                    free(p->next);
                    p->next = half;
                    printf("��ɾ��\n");
                    return;
                }
                else
                {
                    printf("��ȡ��\n");
                    return;
                }
            }
            else
            {
                printf("����ʹ���У��޷�ɾ����\n");
                return;
            }
        }
        else
        {
            p = p->next;
        }
    }
    printf("����ID�����ڣ��޷�ɾ����\n");
}
//*******************************************************************************************
//��ʾ��������
void printhouse(HOUSE *p)
{
    printf("����ID��%d\n", p->number);
    printf("ʹ��״̬��%d\n", p->used_or_not);
    printf("�۸�%.2f\n", p->price);
}
//*******************************************************************************************
//��ʾ���з���
void printhousesall(HOUSE *p)
{
    while (p != NULL)
    {
        printhouse(p);
        p = p->next;
    }
}
//*******************************************************************************************
//��ʾ���÷���
void printhousesused(HOUSE *p)
{
    while (p != NULL)
    {
        if (p->used_or_not != 0)
        {
            printhouse(p);
        }
        p = p->next;
    }
}
//*******************************************************************************************
////��ʾ���÷���
void printhousesempty(HOUSE *p)
{
    while (p != NULL)
    {
        if (p->used_or_not == 0)
        {
            printhouse(p);
        }
        p = p->next;
    }
}
//*******************************************************************************************
//��������
void search(HOUSE *p)
{
    int id;
    printf("���������������ID");
    scanf("%d", &id);
    while (p != NULL)
    {
        if (id == p->number)
        {
            printhouse(p);
            return;
        }
        else
        {
            p = p->next;
        }
    }
    printf("����ID�����ڣ�\n");
}
//�ļ�������*******************************************************************************************
void Load_house(HOUSE *p)
{
    FILE *fp;
    HOUSE *q = NULL;

    if ((fp = fopen("house.txt", "r")) == NULL)
    {
        printf("%s\n", "�������޷�����Ϣ");
    }
    else
    {
        for (q = p; !feof(fp); q = q->next)
        {
            q->next = (HOUSE *)malloc(sizeof(HOUSE));
            fscanf(fp, "\n%d\t%d\t%f\n", &q->next->number, &q->next->used_or_not, &q->next->price);
        }
        q->next = NULL;
        puts("���ط��ݼ�¼��ȡ�ɹ�");
        fclose(fp);
    } //end if for file
}

//--------------------------------------------------------------------

//�������ļ�*******************************************************************************************
void savehouse(HOUSE *p)
{
    FILE *x;
    x = fopen("house.txt", "w");
    p = p->next;
    while (p != NULL)
    {
        fprintf(x, "\n%d\t%d\t%f\n", p->number, p->used_or_not, p->price);
        p = p->next;
    }
    fclose(x);
    puts("���ݼ�¼����ɹ�");
}

#include "facility.h"
///��ʩ����Yaksha's part+++++++++++++++++++++++++++
//��ʾ��ʩ�˵�
void entertainment_menu()
{
    system("cls");
    puts("**********��ӭ�������ֳ��ݹ���ϵͳ**********");
    puts("*               1.ԤԼ����                 *");
    puts("*               2.�˳�����                 *");
    puts("*               3.ά�޳���                 *");
    puts("*               4.�˳�ϵͳ                 *");
    puts("********************************************");
    puts("��ѡ�����");
}
//���볡�ݣ���¼ԤԼ��������ԤԼ��
void entertainment_1(int enter_number[4], int entertainment_id[1000][2], int entertainment_fix[4])
{
    while (1)
    {
        system("cls");
        puts("**********��ӭ�������ֳ���ԤԼϵͳ**********");
        puts("*               1.��Ӿ��ԤԼ               *");
        puts("*               2.���ԤԼ                 *");
        puts("*               3.�黭���ԤԼ           *");
        puts("*               4.�糡ԤԼ                 *");
        puts("*               5.����                     *");
        puts("********************************************");
        printf("���ֳ�������\t\t��Ӿ��\t\t���\t\t�黭���\t�糡\nĿǰ��ԤԼ����\t\t%d\t\t%d\t\t%d\t\t%d\n", enter_number[0], enter_number[1], enter_number[2], enter_number[3]);
        puts("��ѡ��");
        int choose = 0;
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            if (entertainment_fix[0] == 1)
            {
                puts("��Ǹ���ó�������ά�ޣ��޷�ԤԼ��");
                system("pause");
                break;
            }
            if (enter_number[0] != 0)
            {
                puts("������ԤԼ������");
                int num;
                scanf("%d", &num);
                if (num <= enter_number[0])
                {
                    int i = 0;
                    for (i = 0; i < 1000; ++i)
                    {
                        if (entertainment_id[i][1] == 0)
                        {
                            entertainment_id[i][2] = num;
                            entertainment_id[i][1] = 1;
                            break;
                        }
                    }
                    printf("ԤԼ�ɹ�������ԤԼ����%d\n���ڼ��ɽ��볡�ݣ��������˳�ʱ��ƾ�Ž������˳���ף�������죡\n", i);
                    system("pause");
                    enter_number[0] -= num;
                }
                else
                {
                    printf("��Ǹ���ó���Ŀǰ������ԤԼ%d�ˣ�\n", num);
                    system("pause");
                }
            }
            else
            {
                puts("��Ǹ���ó���ĿǰԤԼ����������");
                system("pause");
            }
            break;
        case 2:
            if (entertainment_fix[1] == 1)
            {
                puts("��Ǹ���ó�������ά�ޣ��޷�ԤԼ��");
                system("pause");
                break;
            }
            if (enter_number[1] != 0)
            {
                puts("������ԤԼ������");
                int num;
                scanf("%d", &num);
                if (num <= enter_number[1])
                {
                    int i = 0;
                    for (i = 0; i < 1000; ++i)
                    {
                        if (entertainment_id[i][1] == 0)
                        {
                            entertainment_id[i][2] = num;
                            entertainment_id[i][1] = 2;
                            break;
                        }
                    }
                    printf("ԤԼ�ɹ�������ԤԼ����%d\n���ڼ��ɽ��볡�ݣ��������˳�ʱ��ƾ�Ž������˳���ף�������죡\n", i);
                    system("pause");
                    enter_number[1] -= num;
                }
                else
                {
                    printf("��Ǹ���ó���Ŀǰ������ԤԼ%d�ˣ�\n", num);
                    system("pause");
                }
            }
            else
            {
                puts("��Ǹ���ó���ĿǰԤԼ����������");
                system("pause");
            }
            break;
        case 3:
            if (entertainment_fix[2] == 1)
            {
                puts("��Ǹ���ó�������ά�ޣ��޷�ԤԼ��");
                system("pause");
                break;
            }
            if (enter_number[2] != 0)
            {
                puts("������ԤԼ������");
                int num;
                scanf("%d", &num);
                if (num <= enter_number[2])
                {
                    int i = 0;
                    for (i = 0; i < 1000; ++i)
                    {
                        if (entertainment_id[i][1] == 0)
                        {
                            entertainment_id[i][2] = num;
                            entertainment_id[i][1] = 3;
                            break;
                        }
                    }
                    printf("ԤԼ�ɹ�������ԤԼ����%d\n���ڼ��ɽ��볡�ݣ��������˳�ʱ��ƾ�Ž������˳���ף�������죡\n", i);
                    system("pause");
                    enter_number[2] -= num;
                }
                else
                {
                    printf("��Ǹ���ó���Ŀǰ������ԤԼ%d�ˣ�\n", num);
                    system("pause");
                }
            }
            else
            {
                puts("��Ǹ���ó���ĿǰԤԼ����������");
                system("pause");
            }
            break;
        case 4:
            if (entertainment_fix[3] == 1)
            {
                puts("��Ǹ���ó�������ά�ޣ��޷�ԤԼ��");
                system("pause");
                break;
            }
            if (enter_number[3] != 0)
            {
                puts("������ԤԼ������");
                int num;
                scanf("%d", &num);
                if (num <= enter_number[3])
                {
                    int i = 0;
                    for (i = 0; i < 1000; ++i)
                    {
                        if (entertainment_id[i][1] == 0)
                        {
                            entertainment_id[i][2] = num;
                            entertainment_id[i][1] = 4;
                            break;
                        }
                    }
                    printf("ԤԼ�ɹ�������ԤԼ����%d\n���ڼ��ɽ��볡�ݣ��������˳�ʱ��ƾ�Ž������˳���ף�������죡\n", i);
                    system("pause");
                    enter_number[3] -= num;
                }
                else
                {
                    printf("��Ǹ���ó���Ŀǰ������ԤԼ%d�ˣ�\n", num);
                    system("pause");
                }
            }
            else
            {
                puts("��Ǹ���ó���ĿǰԤԼ����������");
                system("pause");
            }
            break;
        case 5:
            return;
        default:
            puts("����������������룡");
            system("color 40");
            system("color 07");
            system("color 40");
            system("color 07");
            system("color 40");
            system("color 07");
            system("pause");
        }
    }
}
//�˳����ݣ�����ԤԼ��
void entertainment_2(int enter_number[4], int entertainment_id[1000][2])
{
    system("cls");
    puts("**********��ӭ�������ֳ����˳�ϵͳ**********");
    puts("���������ԤԼ�ţ�");
    int Eid = 0, temp = 0;
    scanf("%d", &Eid);

   if(Eid>1000||Eid<0)
    {
        puts("�������");
        system("color 40");
        system("color 07");
        system("color 40");
        system("color 07");
        system("color 40");
        system("color 07");
        system("pause");
    }
    else if (entertainment_id[Eid][1] == 0)
    {
        puts("����δԤԼ�κγ��ݣ������˳���");
        system("pause");
    }
    else
    {
        temp = entertainment_id[Eid][1];
        enter_number[temp - 1] += entertainment_id[Eid][2];
        entertainment_id[Eid][1] = 0;
        entertainment_id[Eid][2] = 0;
        puts("�����ɹ������˳���");
        system("pause");
    }
}
////ά�޳��ݣ�ͬʱ���������Ա
void entertainment_3(int entertainment_fix[4], int enter_number[4], int entertainment_id[1000][2])
{
    while (1)
    {
        system("cls");
        puts("**********��ӭ�������ֳ���ά�޹���ϵͳ**********");
        puts("*                 1.��Ӿ��                     *");
        puts("*                 2.���                       *");
        puts("*                 3.�黭���                 *");
        puts("*                 4.�糡                       *");
        puts("*                 5.����                       *");
        puts("************************************************");
        puts("��ѡ��");
        int choose = 0;
        int fix = 0;
        scanf("%d", &choose);
        if (choose == 5)
            return;
        else if (choose > 5)
        {
            puts("�������룡���������룡");
            system("color 40");
            system("color 07");
            system("color 40");
            system("color 07");
            system("color 40");
            system("color 07");
            system("pause");
        }
        else if (entertainment_fix[choose - 1] == 0)
        {
        error1:
            system("cls");
            puts("�ó��������ڿ����У��Ƿ�Ҫ����ά��\n1.��\n2.��");
            printf("�����룺");
            scanf("%d", &fix);
            if (fix == 1)
            {
                entertainment_fix[choose - 1] = 1;
                int i = 0;
                for (i = 0; i < 1000; i++)
                {
                    if (entertainment_id[i][1] == choose)
                    {
                        enter_number[choose - 1] += entertainment_id[i][2];
                        entertainment_id[i][1] = 0;
                        entertainment_id[i][2] = 0;
                    }
                }
                puts("�����ɹ����ó�������������û�����ά��״̬��");
                system("pause");
            }
            else if (fix == 2)
            {
                puts("�ó��ݽ��������ţ�");
                system("pause");
            }
            else
            {
                puts("�������룡���������룡");
                system("color 40");
                system("color 07");
                system("color 40");
                system("color 07");
                system("color 40");
                system("color 07");
                system("pause");
                goto error1;
            }
        }
        else if (entertainment_fix[choose - 1] == 1)
        {
        error2:
            system("cls");
            puts("�ó���������ά���У��Ƿ�Ҫ���п���\n1.��\n2.��");
            printf("�����룺");
            scanf("%d", &fix);
            if (fix == 1)
            {
                entertainment_fix[choose - 1] = 0;
                puts("�����ɹ����ó����ѽ��뿪��״̬��");
                system("pause");
            }
            else if (fix == 2)
            {
                puts("�ó��ݽ�����ά�ޣ�");
                system("pause");
            }
            else
            {
                puts("�������룡���������룡");
                system("color 40");
                system("color 07");
                system("color 40");
                system("color 07");
                system("color 40");
                system("color 07");
                system("pause");
                goto error2;
            }
        }
    }
}
//��ʩ�ܹ���ϵͳ������ѡ�񣬺��ļ���д
void entertainment()
{
    int enter_number[4] = {200, 160, 50, 500};
    int entertainment_fix[4] = {0, 0, 0, 0};
    int entertainment_id[1000][2] = {{0}};
    int i;
    FILE *Enter_number;
    if ((Enter_number = fopen("enter_number.txt", "r+")) == NULL)
    {
        fclose(Enter_number);
        if ((Enter_number = fopen("enter_number.txt", "w")) != NULL)
        {
            fprintf(Enter_number, "������ʩ����\t\t��Ӿ��\t\t���\t\t�黭���\t�糡\nĿǰ��ԤԼ����\t\t%d\t\t%d\t\t%d\t\t%d", enter_number[0], enter_number[1], enter_number[2], enter_number[3]);
        }
        fclose(Enter_number);
    }
    else
    {
        fscanf(Enter_number, "������ʩ����\t\t��Ӿ��\t\t���\t\t�黭���\t�糡\nĿǰ��ԤԼ����\t\t%d\t\t%d\t\t%d\t\t%d", &enter_number[0], &enter_number[1], &enter_number[2], &enter_number[3]);
        fclose(Enter_number);
    }
    FILE *Entertainment_id;
    if ((Entertainment_id = fopen("entertainment_id.txt", "r+")) == NULL)
    {
        fclose(Entertainment_id);
        if ((Entertainment_id = fopen("entertainment_id.txt", "w")) != NULL)
        {
            fprintf(Entertainment_id, "ԤԼ��\t\tԤԼ����(01234)\tԤԼ����\n");
            for (i = 0; i < 1000; i++)
            {
                fprintf(Entertainment_id, "%d\t\t%d\t\t%d\n", i, entertainment_id[i][1], entertainment_id[i][2]);
            }
        }
        fclose(Entertainment_id);
    }
    else
    {
        fscanf(Entertainment_id, "ԤԼ��\t\tԤԼ����(01234)\tԤԼ����\n%d\t\t%d\t\t%d\n", &i, &entertainment_id[0][1], &entertainment_id[0][2]);
        for (i = 1; i < 1000; i++)
        {
            fscanf(Entertainment_id, "%d\t\t%d\t\t%d\n", &i, &entertainment_id[i][1], &entertainment_id[i][2]);
        }
        fclose(Entertainment_id);
    }
    FILE *Entertainment_fix;
    if ((Entertainment_fix = fopen("entertainment_fix.txt", "r+")) == NULL)
    {
        fclose(Entertainment_fix);
        if ((Entertainment_fix = fopen("entertainment_fix.txt", "w")) != NULL)
        {
            fprintf(Entertainment_fix, "������ʩ����\t\t��Ӿ��\t\t���\t\t�黭���\t�糡\nĿǰ�Ƿ�ά��(01)\t\t%d\t\t%d\t\t%d\t\t%d", entertainment_fix[0], entertainment_fix[1], entertainment_fix[2], entertainment_fix[3]);
        }
        fclose(Entertainment_fix);
    }
    else
    {
        fscanf(Entertainment_fix, "������ʩ����\t\t��Ӿ��\t\t���\t\t�黭���\t�糡\nĿǰ�Ƿ�ά��(01)\t\t%d\t\t%d\t\t%d\t\t%d", &entertainment_fix[0], &entertainment_fix[1], &entertainment_fix[2], &entertainment_fix[3]);
        fclose(Entertainment_fix);
    }
    int choose = 0;
    while (choose != 4)
    {
        entertainment_menu();
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            entertainment_1(enter_number, entertainment_id, entertainment_fix);
            break;
        case 2:
            entertainment_2(enter_number, entertainment_id);
            break;
        case 3:
            entertainment_3(entertainment_fix, enter_number, entertainment_id);
            break;
        case 4:
            break;
        default:
            puts("����������������룡");
            system("color 40");
            system("color 07");
            system("color 40");
            system("color 07");
            system("color 40");
            system("color 07");
            system("pause");
            break;
        }
    }
    if ((Enter_number = fopen("enter_number.txt", "w")) != NULL)
    {
        fprintf(Enter_number, "������ʩ����\t\t��Ӿ��\t\t���\t\t�黭���\t�糡\nĿǰ��ԤԼ����\t\t%d\t\t%d\t\t%d\t\t%d", enter_number[0], enter_number[1], enter_number[2], enter_number[3]);
    }
    fclose(Enter_number);
    if ((Entertainment_id = fopen("entertainment_id.txt", "w")) != NULL)
    {
        fprintf(Entertainment_id, "ԤԼ��\t\tԤԼ����(01234)\tԤԼ����\n");
        for (i = 0; i < 1000; i++)
        {
            fprintf(Entertainment_id, "%d\t\t%d\t\t%d\n", i, entertainment_id[i][1], entertainment_id[i][2]);
        }
    }
    fclose(Entertainment_id);
    if ((Entertainment_fix = fopen("entertainment_fix.txt", "w")) != NULL)
    {
        fprintf(Entertainment_fix, "������ʩ����\t\t��Ӿ��\t\t���\t\t�黭���\t�糡\nĿǰ�Ƿ�ά��(01)\t\t%d\t\t%d\t\t%d\t\t%d", entertainment_fix[0], entertainment_fix[1], entertainment_fix[2], entertainment_fix[3]);
    }
    fclose(Entertainment_fix);
    return;
}

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

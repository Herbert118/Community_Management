#include <stdio.h>
#include <stdlib.h>
#include "service.h"


int main()
{
    MEMBER *memberhead = NULL;
    HOUSE house1 = {1, 0, 1, NULL}; ///for test
    HOUSE *househead = (HOUSE *)malloc(sizeof(HOUSE));
    househead->next = NULL;
    localmember(&memberhead);
    loadService(memberhead);
    Load_house(househead);
         service();
    system("pause");
    int choice;
    do
    {
        menu();
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 0:
            printf("��л����ʹ�ã���������˳�\n");
            break;
        case 1:
            memberManagement(&memberhead, househead);
            break;
        case 2:
            houseManagement(househead);
            break;
        case 3:
            entertainment();
            break;
        case 4:
            serviceManagement(memberhead);
            break;
        default:
            printf("û�д�ѡ�����������\n");
        }
        if (choice)
            printf("\n\n�����������.");
        getch();
    } while (choice);
    return 0;
}
void menu()
{

    system("cls");
    printf("\t\t%s", "|-------------����������������ϵͳ-------------|\n");
    printf("\t\t%s", "|        0   �˳�                              |\n");
    printf("\t\t%s", "|        1   ��Ա����ϵͳ                      |\n");
    printf("\t\t%s", "|        2   ���ݹ���ϵͳ                      |\n");
    printf("\t\t%s", "|        3   ��ʩ����ϵͳ                      |\n");
    printf("\t\t%s", "|        4   �������ϵͳ                      |\n");
    printf("\t\t%s", "|----------------------------------------------|\n");
    printf("\n\t\t����������ѡ��0-4�����س������� : ");
}

///______________________________________________________________________________________________________________________________________________________________





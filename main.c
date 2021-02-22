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
            printf("感谢您的使用，按任意键退出\n");
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
            printf("没有此选项，请重新输入\n");
        }
        if (choice)
            printf("\n\n按任意键继续.");
        getch();
    } while (choice);
    return 0;
}
void menu()
{

    system("cls");
    printf("\t\t%s", "|-------------活力长者社区管理系统-------------|\n");
    printf("\t\t%s", "|        0   退出                              |\n");
    printf("\t\t%s", "|        1   会员管理系统                      |\n");
    printf("\t\t%s", "|        2   房屋管理系统                      |\n");
    printf("\t\t%s", "|        3   设施管理系统                      |\n");
    printf("\t\t%s", "|        4   服务管理系统                      |\n");
    printf("\t\t%s", "|----------------------------------------------|\n");
    printf("\n\t\t请输入您的选择（0-4）按回车键继续 : ");
}

///______________________________________________________________________________________________________________________________________________________________





#include "facility.h"
///设施管理Yaksha's part+++++++++++++++++++++++++++
//显示设施菜单
void entertainment_menu()
{
    system("cls");
    puts("**********欢迎来到娱乐场馆管理系统**********");
    puts("*               1.预约场馆                 *");
    puts("*               2.退出场馆                 *");
    puts("*               3.维修场馆                 *");
    puts("*               4.退出系统                 *");
    puts("********************************************");
    puts("请选择服务：");
}
//进入场馆，记录预约人数，和预约号
void entertainment_1(int enter_number[4], int entertainment_id[1000][2], int entertainment_fix[4])
{
    while (1)
    {
        system("cls");
        puts("**********欢迎来到娱乐场馆预约系统**********");
        puts("*               1.游泳馆预约               *");
        puts("*               2.茶馆预约                 *");
        puts("*               3.书画活动室预约           *");
        puts("*               4.剧场预约                 *");
        puts("*               5.返回                     *");
        puts("********************************************");
        printf("娱乐场馆名称\t\t游泳馆\t\t茶馆\t\t书画活动室\t剧场\n目前可预约人数\t\t%d\t\t%d\t\t%d\t\t%d\n", enter_number[0], enter_number[1], enter_number[2], enter_number[3]);
        puts("请选择：");
        int choose = 0;
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            if (entertainment_fix[0] == 1)
            {
                puts("抱歉，该场馆正在维修，无法预约！");
                system("pause");
                break;
            }
            if (enter_number[0] != 0)
            {
                puts("请输入预约人数：");
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
                    printf("预约成功！您的预约号是%d\n现在即可进入场馆，进入与退出时请凭号进入与退出！祝您玩的愉快！\n", i);
                    system("pause");
                    enter_number[0] -= num;
                }
                else
                {
                    printf("抱歉，该场馆目前不可再预约%d人！\n", num);
                    system("pause");
                }
            }
            else
            {
                puts("抱歉，该场馆目前预约人数已满！");
                system("pause");
            }
            break;
        case 2:
            if (entertainment_fix[1] == 1)
            {
                puts("抱歉，该场馆正在维修，无法预约！");
                system("pause");
                break;
            }
            if (enter_number[1] != 0)
            {
                puts("请输入预约人数：");
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
                    printf("预约成功！您的预约号是%d\n现在即可进入场馆，进入与退出时请凭号进入与退出！祝您玩的愉快！\n", i);
                    system("pause");
                    enter_number[1] -= num;
                }
                else
                {
                    printf("抱歉，该场馆目前不可再预约%d人！\n", num);
                    system("pause");
                }
            }
            else
            {
                puts("抱歉，该场馆目前预约人数已满！");
                system("pause");
            }
            break;
        case 3:
            if (entertainment_fix[2] == 1)
            {
                puts("抱歉，该场馆正在维修，无法预约！");
                system("pause");
                break;
            }
            if (enter_number[2] != 0)
            {
                puts("请输入预约人数：");
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
                    printf("预约成功！您的预约号是%d\n现在即可进入场馆，进入与退出时请凭号进入与退出！祝您玩的愉快！\n", i);
                    system("pause");
                    enter_number[2] -= num;
                }
                else
                {
                    printf("抱歉，该场馆目前不可再预约%d人！\n", num);
                    system("pause");
                }
            }
            else
            {
                puts("抱歉，该场馆目前预约人数已满！");
                system("pause");
            }
            break;
        case 4:
            if (entertainment_fix[3] == 1)
            {
                puts("抱歉，该场馆正在维修，无法预约！");
                system("pause");
                break;
            }
            if (enter_number[3] != 0)
            {
                puts("请输入预约人数：");
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
                    printf("预约成功！您的预约号是%d\n现在即可进入场馆，进入与退出时请凭号进入与退出！祝您玩的愉快！\n", i);
                    system("pause");
                    enter_number[3] -= num;
                }
                else
                {
                    printf("抱歉，该场馆目前不可再预约%d人！\n", num);
                    system("pause");
                }
            }
            else
            {
                puts("抱歉，该场馆目前预约人数已满！");
                system("pause");
            }
            break;
        case 5:
            return;
        default:
            puts("输入错误，请重新输入！");
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
//退出场馆，输入预约号
void entertainment_2(int enter_number[4], int entertainment_id[1000][2])
{
    system("cls");
    puts("**********欢迎来到娱乐场馆退出系统**********");
    puts("请输入你的预约号：");
    int Eid = 0, temp = 0;
    scanf("%d", &Eid);

   if(Eid>1000||Eid<0)
    {
        puts("输入错误！");
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
        puts("您尚未预约任何场馆！无需退出！");
        system("pause");
    }
    else
    {
        temp = entertainment_id[Eid][1];
        enter_number[temp - 1] += entertainment_id[Eid][2];
        entertainment_id[Eid][1] = 0;
        entertainment_id[Eid][2] = 0;
        puts("操作成功，已退出！");
        system("pause");
    }
}
////维修场馆，同时请出馆内人员
void entertainment_3(int entertainment_fix[4], int enter_number[4], int entertainment_id[1000][2])
{
    while (1)
    {
        system("cls");
        puts("**********欢迎来到娱乐场馆维修管理系统**********");
        puts("*                 1.游泳馆                     *");
        puts("*                 2.茶馆                       *");
        puts("*                 3.书画活动室                 *");
        puts("*                 4.剧场                       *");
        puts("*                 5.返回                       *");
        puts("************************************************");
        puts("请选择：");
        int choose = 0;
        int fix = 0;
        scanf("%d", &choose);
        if (choose == 5)
            return;
        else if (choose > 5)
        {
            puts("错误输入！请重新输入！");
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
            puts("该场馆正处于开放中，是否要进行维修\n1.是\n2.否");
            printf("请输入：");
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
                puts("操作成功，该场馆已请回所有用户进入维修状态！");
                system("pause");
            }
            else if (fix == 2)
            {
                puts("该场馆将继续开放！");
                system("pause");
            }
            else
            {
                puts("错误输入！请重新输入！");
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
            puts("该场馆正处于维修中，是否要进行开放\n1.是\n2.否");
            printf("请输入：");
            scanf("%d", &fix);
            if (fix == 1)
            {
                entertainment_fix[choose - 1] = 0;
                puts("操作成功，该场馆已进入开放状态！");
                system("pause");
            }
            else if (fix == 2)
            {
                puts("该场馆将继续维修！");
                system("pause");
            }
            else
            {
                puts("错误输入！请重新输入！");
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
//设施总管理系统，进行选择，和文件读写
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
            fprintf(Enter_number, "娱乐设施名称\t\t游泳馆\t\t茶馆\t\t书画活动室\t剧场\n目前可预约人数\t\t%d\t\t%d\t\t%d\t\t%d", enter_number[0], enter_number[1], enter_number[2], enter_number[3]);
        }
        fclose(Enter_number);
    }
    else
    {
        fscanf(Enter_number, "娱乐设施名称\t\t游泳馆\t\t茶馆\t\t书画活动室\t剧场\n目前可预约人数\t\t%d\t\t%d\t\t%d\t\t%d", &enter_number[0], &enter_number[1], &enter_number[2], &enter_number[3]);
        fclose(Enter_number);
    }
    FILE *Entertainment_id;
    if ((Entertainment_id = fopen("entertainment_id.txt", "r+")) == NULL)
    {
        fclose(Entertainment_id);
        if ((Entertainment_id = fopen("entertainment_id.txt", "w")) != NULL)
        {
            fprintf(Entertainment_id, "预约号\t\t预约场馆(01234)\t预约人数\n");
            for (i = 0; i < 1000; i++)
            {
                fprintf(Entertainment_id, "%d\t\t%d\t\t%d\n", i, entertainment_id[i][1], entertainment_id[i][2]);
            }
        }
        fclose(Entertainment_id);
    }
    else
    {
        fscanf(Entertainment_id, "预约号\t\t预约场馆(01234)\t预约人数\n%d\t\t%d\t\t%d\n", &i, &entertainment_id[0][1], &entertainment_id[0][2]);
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
            fprintf(Entertainment_fix, "娱乐设施名称\t\t游泳馆\t\t茶馆\t\t书画活动室\t剧场\n目前是否维修(01)\t\t%d\t\t%d\t\t%d\t\t%d", entertainment_fix[0], entertainment_fix[1], entertainment_fix[2], entertainment_fix[3]);
        }
        fclose(Entertainment_fix);
    }
    else
    {
        fscanf(Entertainment_fix, "娱乐设施名称\t\t游泳馆\t\t茶馆\t\t书画活动室\t剧场\n目前是否维修(01)\t\t%d\t\t%d\t\t%d\t\t%d", &entertainment_fix[0], &entertainment_fix[1], &entertainment_fix[2], &entertainment_fix[3]);
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
            puts("输入错误，请重新输入！");
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
        fprintf(Enter_number, "娱乐设施名称\t\t游泳馆\t\t茶馆\t\t书画活动室\t剧场\n目前可预约人数\t\t%d\t\t%d\t\t%d\t\t%d", enter_number[0], enter_number[1], enter_number[2], enter_number[3]);
    }
    fclose(Enter_number);
    if ((Entertainment_id = fopen("entertainment_id.txt", "w")) != NULL)
    {
        fprintf(Entertainment_id, "预约号\t\t预约场馆(01234)\t预约人数\n");
        for (i = 0; i < 1000; i++)
        {
            fprintf(Entertainment_id, "%d\t\t%d\t\t%d\n", i, entertainment_id[i][1], entertainment_id[i][2]);
        }
    }
    fclose(Entertainment_id);
    if ((Entertainment_fix = fopen("entertainment_fix.txt", "w")) != NULL)
    {
        fprintf(Entertainment_fix, "娱乐设施名称\t\t游泳馆\t\t茶馆\t\t书画活动室\t剧场\n目前是否维修(01)\t\t%d\t\t%d\t\t%d\t\t%d", entertainment_fix[0], entertainment_fix[1], entertainment_fix[2], entertainment_fix[3]);
    }
    fclose(Entertainment_fix);
    return;
}

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

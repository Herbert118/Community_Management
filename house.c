#include "service.h"
#include "house.h"


///FOX'part+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//房屋管理系统总管理
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
            printf("正在退出...\n");
            break;
        case 1:
            printf("新建房屋：\n");
            buildhouse(head);
            savehouse(head);
            break;
        case 2:
            printf("删除房屋：\n");
            deletehouse(head);
            break;
        case 3:
            printf("显示所有房屋 \n");
            printhousesall(head->next);
            break;
        case 4:
            printf("显示已用房屋 \n");
            printhousesused(head->next);
            break;
        case 5:
            printf("显示空闲房屋 \n");
            printhousesempty(head->next);
            break;
        case 6:
            printf("显示指定房屋 \n");
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
//菜单
void housemenu()
{

    system("cls");
    printf("\t\t _________________________________________________\n");
    printf("\t\t|-------------House management system-------------|\n");
    printf("\t\t|                                                 |\n");
    printf("\t\t|           0  - 退出                             |\n");
    printf("\t\t|           1  - 新建房屋                         |\n");
    printf("\t\t|           2  - 删除房屋                         |\n");
    printf("\t\t|           3  - 显示所有房屋                     |\n");
    printf("\t\t|           4  - 显示已用房屋                     |\n");
    printf("\t\t|           5  - 显示空闲房屋                     |\n");
    printf("\t\t|           6  - 显示指定房屋                     |\n");
    printf("\t\t|_________________________________________________|\n");
    printf("\n\t\tPlease enter your choice (0-5): ");
    printf("please enter your choice");
}
//*******************************************************************************************

//*******************************************************************************************
//新建房屋，输入房屋id和价格
void buildhouse(HOUSE *p)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = (HOUSE *)malloc(sizeof(HOUSE));
    p = p->next;
    printf("请输入新房屋ID");
    scanf("%d", &p->number);
    p->used_or_not = 0;
    printf("请输入新房屋价格");
    scanf("%f", &p->price);
    p->next = NULL;

    return;
}
//*******************************************************************************************
//删除房屋
void deletehouse(HOUSE *p)
{
    int id;
    int i;
    HOUSE *half;
    printf("请输入待删除房屋ID");
    scanf("%d", &id);
    while (p->next != NULL)
    {
        if (id == p->next->number)
        {
            printhouse(p->next);
            if (p->next->used_or_not == 0)
            {
                printf("确认删除：1\n取消：其他任意键\n");
                scanf("%d", &i);
                if (i == 1)
                {
                    half = p->next->next;
                    free(p->next);
                    p->next = half;
                    printf("已删除\n");
                    return;
                }
                else
                {
                    printf("已取消\n");
                    return;
                }
            }
            else
            {
                printf("房屋使用中，无法删除！\n");
                return;
            }
        }
        else
        {
            p = p->next;
        }
    }
    printf("房屋ID不存在，无法删除！\n");
}
//*******************************************************************************************
//显示单个房屋
void printhouse(HOUSE *p)
{
    printf("房屋ID：%d\n", p->number);
    printf("使用状态：%d\n", p->used_or_not);
    printf("价格：%.2f\n", p->price);
}
//*******************************************************************************************
//显示所有房屋
void printhousesall(HOUSE *p)
{
    while (p != NULL)
    {
        printhouse(p);
        p = p->next;
    }
}
//*******************************************************************************************
//显示已用房屋
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
////显示空置房屋
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
//搜索房屋
void search(HOUSE *p)
{
    int id;
    printf("请输入待搜索房屋ID");
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
    printf("房屋ID不存在！\n");
}
//文件到链表*******************************************************************************************
void Load_house(HOUSE *p)
{
    FILE *fp;
    HOUSE *q = NULL;

    if ((fp = fopen("house.txt", "r")) == NULL)
    {
        printf("%s\n", "本地暂无房屋信息");
    }
    else
    {
        for (q = p; !feof(fp); q = q->next)
        {
            q->next = (HOUSE *)malloc(sizeof(HOUSE));
            fscanf(fp, "\n%d\t%d\t%f\n", &q->next->number, &q->next->used_or_not, &q->next->price);
        }
        q->next = NULL;
        puts("本地房屋记录读取成功");
        fclose(fp);
    } //end if for file
}

//--------------------------------------------------------------------

//保存至文件*******************************************************************************************
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
    puts("房屋记录保存成功");
}

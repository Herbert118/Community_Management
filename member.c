#include "member.h"

///Obb's Part+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//会员系统会员系统会员系统会员系统会员系统会员系统会员系统会员系统会员系统
//会员系统功能菜单
void memberManagement(MEMBER **memberhead, HOUSE *househead)
{
    int a;
    puts("欢迎进入会员管理系统");
    localmember(memberhead);
    do
    {
        printf("1 创建会员并入住\n2 查询会员\n3 修改会员\n4 删除会员\n5 退出会员管理系统\n");
        puts("请选择操作");
        rewind(stdin);
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            setmember(memberhead, househead);
            break;
        case 2:
            searchmember(*memberhead);
            break;
        case 3:
            modifymember(*memberhead, househead);
            break;
        case 4:
            deletemember(memberhead, househead);
            break;
        case 5:
            return;
        default:
            puts("请输入正确数字");
            break;
        }
    } while (1);
}
//建立会员链表，完成会员姓名 id 房间号码的录入，并对相应房间状态（used_or_not）进行更改
void setmember(MEMBER **memberptr, HOUSE *househead)
{
    if (househead->next == NULL)
    {
        puts("抱歉，目前暂无房屋数据，请先创建房屋");
        return;
    }
    MEMBER *p = NULL, *pr = *memberptr;
    int a;
    HOUSE *hp = househead;
    p = malloc(sizeof(MEMBER));
    if (*memberptr == NULL)
        *memberptr = p;
    else
    {
        while (pr->next != NULL)
            pr = pr->next;
        pr->next = p;
    }
    puts("请输入会员姓名");
    scanf("%s", p->name);
    puts("请输入会员编号");
    rewind(stdin);
    srand(time(NULL));
    p->id = 20200000 + rand() % 9999;
    printf("为您生成的会员编号是%d\n", p->id);
    puts("请选择需要购买的房屋");
    houselist(househead);
    do
    {
        puts("请输入需要购买的房屋编号");
        rewind(stdin);
        scanf("%d", &a);
        while (hp->number != a && hp->next != NULL)
            hp = hp->next;
        if (hp->number != a)
        {
            puts("抱歉，无该编号对应的房屋，请输入正确编号");
            continue;
        }
        if (hp->used_or_not != 0)
        {
            puts("抱歉，该房屋无法购买，请输入正确编号");
            continue;
        }
        else
            break;
    } while (1);
    p->house_number = a;
    hp->used_or_not = p->id;
    printf("the house's used is %d",hp->used_or_not);
    p->servicehead = NULL; //Herbert added this for debug
    p->next = NULL;
    puts("购买成功");
    storesmember(p);
    savehouse(househead);
}
//列出能够购买的房屋
void houselist(HOUSE *househead)
{
    HOUSE *p = househead->next; //Herbert change it for debug
    printf("房屋编号\t房屋价格\n");
    while (p != NULL)
    {
        if (p->used_or_not != 0)
        {
            p = p->next;
            continue;
        }
        printf("%d\t%f\n", p->number, p->price);
        p = p->next;
    }
}
//读取本地文件中的会员信息并将其添加至链表中
void storesmember(MEMBER *p)
{
    FILE *x;
    x = fopen("member.txt", "a");
    fprintf(x, "\n%d\t%s\t%d\n", p->id, p->name, p->house_number);
    fclose(x);
    puts("会员记录保存成功");
}
//查找会员，包括按姓名和id两种方式查找
void searchmember(MEMBER *p)
{
    while (1)
    {
        puts("请选择查询方式");
        printf("0 显示所有会员信息\n 1 按会员姓名查询\n 2 按会员id查询\n 3 退出会员查询系统\n");
        int a;
        scanf("%d", &a);
        switch (a)
        {
        case 0:
            printmember(p);
            break;

        case 1:
            searchname(p);
            break;

        case 2:
            searchid(p);
            break;

        case 3:
            return;
        default:
            puts("请输入正确编号");
            break;
        }
    }
}
//显示所有的会员信息
void printmember(MEMBER *p)
{
    if (p == NULL)
    {
        puts("抱歉，目前还没有会员");
        return;
    }
    printf("查询成功\nid\t\t姓名\t房屋号\n");
    while (p != NULL)
    {
        printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
        p = p->next;
    }
}
//按姓名搜索会员
void searchname(MEMBER *p)
{
    puts("请输入会员姓名");
    char c[20];
    scanf("%s", c);
    while (p != NULL)
    {
        if (!strcmp(p->name, c))
        {
            printf("查询成功\nid\t姓名\t房屋号\n");
            printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
            return;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        puts("无此会员");
        return;
    }
}
//按id搜索会员
void searchid(MEMBER *p)
{
    puts("请输入会员id");
    int c;
    scanf("%d", &c);
    while (p != NULL)
    {
        if (p->id == c)
        {
            printf("查询成功\nid\t姓名\t房屋号\n");
            printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
            return;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        puts("无此会员");
        return;
    }
}
//修改会员信息
void modifymember(MEMBER *memberhead, HOUSE *househead)
{
    if (memberhead == NULL)
    {
        puts("抱歉，目前暂未录入任何会员信息");
        return;
    }
    MEMBER *p = memberhead;
    HOUSE *hp = househead;
    HOUSE *hpp = househead;
    int a;
    int b = 0;
    printf("id\t姓名\t房屋号\n");
    while (p != NULL)
    {
        printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
        p = p->next;
    }
    while (1)
    {
        int x = 0;
        puts("请输入需要修改的会员对应的id 按0退出");
        int c;
        scanf("%d", &c);
        if (c == 0)
            return;
        p = memberhead;
        while (p != NULL)
        {
            if (p->id == c)
            {
                puts("请核对会员信息 按0确认修改 按任意键取消");
                printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
                scanf("%d", &x);
                switch (x)
                {
                case 0:
                    break;
                default:
                    puts("取消成功");
                    ++x;
                    break;
                }
                if (x != 0)
                    break;
                puts("请输入新的会员名字");
                scanf("%s", p->name);
                while (1)
                {
                    puts("请输入新的房屋编号");
                    rewind(stdin);
                    scanf("%d", &a);
                    while (hp->number != a && hp->next != NULL)
                        hp = hp->next;
                    if (hp->number != a)
                    {
                        puts("抱歉，无该编号对应的房屋，请输入正确编号");
                        continue;
                    }
                    if (hp->used_or_not != 0 && hp->used_or_not != p->id)
                    {
                        puts("抱歉，该房屋已被他人购买，请输入正确编号");
                        continue;
                    }
                    else
                    {
                        ++b;
                        break;
                    }
                }
                while (hpp->number != p->house_number)
                    hpp = hpp->next;
                hpp->used_or_not = 0;
                p->house_number = a;
                hp->used_or_not = p->id;
                puts("修改成功");
                break;
            }
            p = p->next;
        }
        if (b != 0 || x != 0)
            break;
        if (p == NULL)
        {
            puts("请输入正确的会员id");
            continue;
        }
    }

    FILE *x;
    p = memberhead;
    x = fopen("member.txt", "w");
    while (p != NULL)
    {
        fprintf(x, "%d\t%s\t%d\n", p->id, p->name, p->house_number);
        p = p->next;
    }
    fclose(x);
    puts("会员记录保存成功");
}
//删除会员信息
void deletemember(MEMBER **memberhead, HOUSE *househead)
{
    if (*memberhead == NULL)
    {
        puts("抱歉，目前暂未录入任何会员信息");
        return;
    }
    int a;
    MEMBER *pq = *memberhead;
    HOUSE *hp = househead;
    printf("id\t姓名\t房屋号\n");
    while (pq != NULL)
    {
        printf("%d\t%s\t%d\n", pq->id, pq->name, pq->house_number);
        pq = pq->next;
    }
    while (1)
    {
        MEMBER *p = *memberhead;
        MEMBER *pr;
        puts("请输入需要删除的会员对应的id 按0退出");
        scanf("%d", &a);
        if (a == NULL)
            return;
        if (p->id == a)
        {
            puts("请核对该会员信息，按0确认删除，按任意键取消");
            int x;
            printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
            scanf("%d", &x);
            switch (x)
            {
            case 0:
                while (hp->number != (*memberhead)->house_number)
                    hp = hp->next;
                hp->used_or_not = 0;
                *memberhead = (*memberhead)->next;
                free(p);
                puts("会员删除成功");
                break;
            default:
                puts("取消成功");
                break;
            }
            if (x == 0)
                break;
            else
                continue;
        }
        while (p->next != NULL && p->next->id != a)
            p = p->next;
        if (p->next == NULL)
        {
            puts("无该会员，请输入正确的会员id");
            continue;
        }
        if (p->next->id == a)
        {
            puts("请核对该会员信息，按0确认删除，按任意键取消");
            int x;
            printf("%d\t%s\t%d\n", p->next->id, p->next->name, p->next->house_number);
            scanf("%d", &x);
            switch (x)
            {
            case 0:
                while (hp->number != p->next->house_number)
                    hp = hp->next;
                hp->used_or_not = 0;
                pr = p->next;
                p->next = p->next->next;
                free(pr);
                puts("会员删除成功");
                break;
            default:
                puts("取消成功");
                break;
            }
            if (x == 0)
                break;
            else
                continue;
        }
    }

    FILE *x;
    MEMBER *p = *memberhead;
    x = fopen("member.txt", "w");
    while (p != NULL)
    {
        fprintf(x, "%d\t%s\t%d\n", p->id, p->name, p->house_number);
        p = p->next;
    }
    fclose(x);
    puts("会员记录保存成功");
}
////将setmember中录入的会员信息储存到本地文件中
void localmember(MEMBER **p)
{
    FILE *x;
    MEMBER *pr;
    char c;
    x = fopen("member.txt", "r");
    c = fgetc(x);
    if (c == EOF)
    {
        puts("本地暂无会员记录");
        return;
    }
    else
        rewind(x);
    *p = malloc(sizeof(MEMBER));
    if (!feof(x))
    {
        fscanf(x, "%d\t%s\t%d\n", &(*p)->id, (*p)->name, &(*p)->house_number);
        (*p)->next = NULL;
        (*p)->servicehead = NULL;
    }
    if (!feof(x))
        pr = *p;
    else
    {
        fclose(x);
        puts("本地会员记录读取成功");
        return;
    }
    while (!feof(x))
    {
        pr->next = malloc(sizeof(MEMBER));
        pr = pr->next;
        fscanf(x, "%d\t%s\t%d\n", &pr->id, pr->name, &pr->house_number);
    }
    pr->next = NULL;
    fclose(x);
    puts("本地会员记录读取成功");
}

//会员系统会员系统会员系统会员系统会员系统会员系统会员系统会员系统会员系统

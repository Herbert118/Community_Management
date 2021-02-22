#include "member.h"

///Obb's Part+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ
//��Աϵͳ���ܲ˵�
void memberManagement(MEMBER **memberhead, HOUSE *househead)
{
    int a;
    puts("��ӭ�����Ա����ϵͳ");
    localmember(memberhead);
    do
    {
        printf("1 ������Ա����ס\n2 ��ѯ��Ա\n3 �޸Ļ�Ա\n4 ɾ����Ա\n5 �˳���Ա����ϵͳ\n");
        puts("��ѡ�����");
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
            puts("��������ȷ����");
            break;
        }
    } while (1);
}
//������Ա������ɻ�Ա���� id ��������¼�룬������Ӧ����״̬��used_or_not�����и���
void setmember(MEMBER **memberptr, HOUSE *househead)
{
    if (househead->next == NULL)
    {
        puts("��Ǹ��Ŀǰ���޷������ݣ����ȴ�������");
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
    puts("�������Ա����");
    scanf("%s", p->name);
    puts("�������Ա���");
    rewind(stdin);
    srand(time(NULL));
    p->id = 20200000 + rand() % 9999;
    printf("Ϊ�����ɵĻ�Ա�����%d\n", p->id);
    puts("��ѡ����Ҫ����ķ���");
    houselist(househead);
    do
    {
        puts("��������Ҫ����ķ��ݱ��");
        rewind(stdin);
        scanf("%d", &a);
        while (hp->number != a && hp->next != NULL)
            hp = hp->next;
        if (hp->number != a)
        {
            puts("��Ǹ���޸ñ�Ŷ�Ӧ�ķ��ݣ���������ȷ���");
            continue;
        }
        if (hp->used_or_not != 0)
        {
            puts("��Ǹ���÷����޷�������������ȷ���");
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
    puts("����ɹ�");
    storesmember(p);
    savehouse(househead);
}
//�г��ܹ�����ķ���
void houselist(HOUSE *househead)
{
    HOUSE *p = househead->next; //Herbert change it for debug
    printf("���ݱ��\t���ݼ۸�\n");
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
//��ȡ�����ļ��еĻ�Ա��Ϣ�����������������
void storesmember(MEMBER *p)
{
    FILE *x;
    x = fopen("member.txt", "a");
    fprintf(x, "\n%d\t%s\t%d\n", p->id, p->name, p->house_number);
    fclose(x);
    puts("��Ա��¼����ɹ�");
}
//���һ�Ա��������������id���ַ�ʽ����
void searchmember(MEMBER *p)
{
    while (1)
    {
        puts("��ѡ���ѯ��ʽ");
        printf("0 ��ʾ���л�Ա��Ϣ\n 1 ����Ա������ѯ\n 2 ����Աid��ѯ\n 3 �˳���Ա��ѯϵͳ\n");
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
            puts("��������ȷ���");
            break;
        }
    }
}
//��ʾ���еĻ�Ա��Ϣ
void printmember(MEMBER *p)
{
    if (p == NULL)
    {
        puts("��Ǹ��Ŀǰ��û�л�Ա");
        return;
    }
    printf("��ѯ�ɹ�\nid\t\t����\t���ݺ�\n");
    while (p != NULL)
    {
        printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
        p = p->next;
    }
}
//������������Ա
void searchname(MEMBER *p)
{
    puts("�������Ա����");
    char c[20];
    scanf("%s", c);
    while (p != NULL)
    {
        if (!strcmp(p->name, c))
        {
            printf("��ѯ�ɹ�\nid\t����\t���ݺ�\n");
            printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
            return;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        puts("�޴˻�Ա");
        return;
    }
}
//��id������Ա
void searchid(MEMBER *p)
{
    puts("�������Աid");
    int c;
    scanf("%d", &c);
    while (p != NULL)
    {
        if (p->id == c)
        {
            printf("��ѯ�ɹ�\nid\t����\t���ݺ�\n");
            printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
            return;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        puts("�޴˻�Ա");
        return;
    }
}
//�޸Ļ�Ա��Ϣ
void modifymember(MEMBER *memberhead, HOUSE *househead)
{
    if (memberhead == NULL)
    {
        puts("��Ǹ��Ŀǰ��δ¼���κλ�Ա��Ϣ");
        return;
    }
    MEMBER *p = memberhead;
    HOUSE *hp = househead;
    HOUSE *hpp = househead;
    int a;
    int b = 0;
    printf("id\t����\t���ݺ�\n");
    while (p != NULL)
    {
        printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
        p = p->next;
    }
    while (1)
    {
        int x = 0;
        puts("��������Ҫ�޸ĵĻ�Ա��Ӧ��id ��0�˳�");
        int c;
        scanf("%d", &c);
        if (c == 0)
            return;
        p = memberhead;
        while (p != NULL)
        {
            if (p->id == c)
            {
                puts("��˶Ի�Ա��Ϣ ��0ȷ���޸� �������ȡ��");
                printf("%d\t%s\t%d\n", p->id, p->name, p->house_number);
                scanf("%d", &x);
                switch (x)
                {
                case 0:
                    break;
                default:
                    puts("ȡ���ɹ�");
                    ++x;
                    break;
                }
                if (x != 0)
                    break;
                puts("�������µĻ�Ա����");
                scanf("%s", p->name);
                while (1)
                {
                    puts("�������µķ��ݱ��");
                    rewind(stdin);
                    scanf("%d", &a);
                    while (hp->number != a && hp->next != NULL)
                        hp = hp->next;
                    if (hp->number != a)
                    {
                        puts("��Ǹ���޸ñ�Ŷ�Ӧ�ķ��ݣ���������ȷ���");
                        continue;
                    }
                    if (hp->used_or_not != 0 && hp->used_or_not != p->id)
                    {
                        puts("��Ǹ���÷����ѱ����˹�����������ȷ���");
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
                puts("�޸ĳɹ�");
                break;
            }
            p = p->next;
        }
        if (b != 0 || x != 0)
            break;
        if (p == NULL)
        {
            puts("��������ȷ�Ļ�Աid");
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
    puts("��Ա��¼����ɹ�");
}
//ɾ����Ա��Ϣ
void deletemember(MEMBER **memberhead, HOUSE *househead)
{
    if (*memberhead == NULL)
    {
        puts("��Ǹ��Ŀǰ��δ¼���κλ�Ա��Ϣ");
        return;
    }
    int a;
    MEMBER *pq = *memberhead;
    HOUSE *hp = househead;
    printf("id\t����\t���ݺ�\n");
    while (pq != NULL)
    {
        printf("%d\t%s\t%d\n", pq->id, pq->name, pq->house_number);
        pq = pq->next;
    }
    while (1)
    {
        MEMBER *p = *memberhead;
        MEMBER *pr;
        puts("��������Ҫɾ���Ļ�Ա��Ӧ��id ��0�˳�");
        scanf("%d", &a);
        if (a == NULL)
            return;
        if (p->id == a)
        {
            puts("��˶Ըû�Ա��Ϣ����0ȷ��ɾ�����������ȡ��");
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
                puts("��Աɾ���ɹ�");
                break;
            default:
                puts("ȡ���ɹ�");
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
            puts("�޸û�Ա����������ȷ�Ļ�Աid");
            continue;
        }
        if (p->next->id == a)
        {
            puts("��˶Ըû�Ա��Ϣ����0ȷ��ɾ�����������ȡ��");
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
                puts("��Աɾ���ɹ�");
                break;
            default:
                puts("ȡ���ɹ�");
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
    puts("��Ա��¼����ɹ�");
}
////��setmember��¼��Ļ�Ա��Ϣ���浽�����ļ���
void localmember(MEMBER **p)
{
    FILE *x;
    MEMBER *pr;
    char c;
    x = fopen("member.txt", "r");
    c = fgetc(x);
    if (c == EOF)
    {
        puts("�������޻�Ա��¼");
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
        puts("���ػ�Ա��¼��ȡ�ɹ�");
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
    puts("���ػ�Ա��¼��ȡ�ɹ�");
}

//��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ��Աϵͳ

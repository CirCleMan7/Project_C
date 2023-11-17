#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_itoa.c"
#include "time.c"
#include "ft_atoi.c"

// #include <conio.h>ls

// char	*strrev(char *number);
// char	*max_num(char *number);
// char	*negative(char *number, int *n);

int graph()
{
    printf("                           XXX\n");
    printf("                           XXX\n");
    printf("        XXX                XXX\n");
    printf("        XXX                XXX\n");
    printf("        XXX        XXX     XXX\n");
    printf("        XXX        XXX     XXX\n");
    printf("        XXX        XXX     XXX\n");
    printf("XXX     XXX        XXX     XXX\n");
    printf("XXX     XXX        XXX     XXX\n");
    printf("food  something   cloth   food\n");
    return (0);
}

void    lock_space(char *str, int len)
{
    int i;

    i = 0;
    while (str[i] && --len)
        i++;
    while (--len)
        str[i++] = ' ';
    str[i] = '\0';
}

void Date(char date[], char result[])
{
    char    day[3];
    char    month[3];
    char    year[10];

    system("clear");
    while (1)
    {
        currentDate();
        while (1)
        {
            printf("Input date(1-31)  : ");  
            scanf("%s", day);
            if (ft_atoi(day) < 1 || ft_atoi(day) > 31 || strlen(day) > 2)
                printf("Error!!!\n");
            else
                break;
        }
        printf("Day = %s\n", day);
        while (1)
        {
            printf("Input month(1-12) : ");  
            scanf("%s", month);
            if (ft_atoi(month) < 1 || ft_atoi(month) > 12 || strlen(month) > 2)
            {
                printf("Error!!!\n");
            }
            else
                break;
        }
        printf("Input year        : ");
        scanf("%s", year);
        strcat(date, day);
        strcat(date, "/");
        strcat(date, month);
        strcat(date, "/");
        strcat(date, year);
        strcat(date, "\n");
        break;
    }
}

void   deposit(char result[], int *sum)
{
    char    topic[100];
    char    money[100];
    char    moneyToA[100];

    system("clear");
    printf("Topic of money : ");
    scanf("%s", topic);
    while (1)
    {
        printf("Input money    : ");
        scanf("%s", money);
        if (ft_atoi(money) > 0)
            break;
    }
    *sum += ft_atoi(money);
    lock_space(topic, 20);
    lock_space(money, 10);
    strcat(topic, money);
    strcat(topic, "   baht\n");
    strcat(result, topic);
}


void finish(char result[], char  *select, char name[])
{
    FILE *pF;

    system("clear");
    if ((pF = fopen(name, "r")) == NULL)
        pF = fopen(name, "w");
    else
        pF = fopen(name, "a");
    fprintf(pF, "%s\n--------------------------------------\n", result);
    *select = '0';
    fclose(pF);
}

void   withdraw(char result[], int *sum)
{
    char    topic[100];
    char    money[100];

    system("clear");
    printf("Topic of money : ");
    scanf("%s", topic);
    while (1)
    {
        printf("Input money    : ");
        scanf("%s", money);
        if (ft_atoi(money) > 0)
            break;
    }
    *sum -= ft_atoi(money);
    lock_space(topic, 19);
    lock_space(money, 10);
    strcat(topic, "-");
    strcat(topic, money);
    strcat(topic, "   baht\n");
    strcat(result, topic);
}

void pocket(char name[])
{
    char    date[30] = "@Date ";
    char    result[10000];
    char    Psum[30] = "#Result = ";
    char    select;
    int     sum = 0;

    strcpy(result, "");
    Date(date, result);
    system("clear");
    strcat(result, date);
    while (1)
    {
        printf("1. deposit\n");
        printf("2. withdraw\n");
        printf("3. result\n");
        printf("4. finish\n");
        printf("0. cancel\n");
        printf("input option : ");
        scanf(" %c", &select);
        printf("\n-------------------------------------------------------------\n");
        system("clear");
        if (select == '1')
            deposit(result, &sum);
        if (select == '2')
            withdraw(result, &sum);
        if (select == '3')
        {
            printf("%s\n", result);
            printf("#Result = %d\n", sum);
        }
        if (select == '4')
        {
            strcat(Psum, ft_itoa(sum));
            strcat(result, Psum);
            finish(result, &select, name);
        }
        if (select == '0')
            return ;
        if (!(select == '1' || select == '2' || select == '3' || select == '4' || select == '5' || select == '0'))
            printf("Error: Please enter a number 1 - 4\n");
    }
}

void CreateAcc()
{
    FILE *Fname;
    char name[100];

    while (1)
    {
        system("clear");
        printf("Input your username : ");
        scanf("%s", name);
        strcat(name, ".txt");
        if ((Fname = fopen(name, "r")) == NULL)
        {
            printf("Create successfully\n");
            Fname = fopen(name, "w");
            fclose(Fname);
            break;
        }
        else
        {
            printf("Account already exist\n");
            break;
        }
    }
}

void menu(char name[])
{
    char    select;

    while (1)
    {
        printf("1. pocket\n");
        printf("2. graph\n");
        printf("3. pacee\n");
        printf("4. analysis\n");
        printf("0. exit\n");
        printf("input option : ");
        scanf(" %c", &select);
        printf("\n-------------------------------------------------------------\n");
        system("clear");
        if (select == '1')
            pocket(name);
        else if (select == '2')
            graph();
        else if (select == '0')
            break;
        if (!(select == '1' || select == '2' || select == '3' || select == '4' || select == '5' || select == '0'))
            printf("Error: Please enter a number 1 - 4\n");
    }
}

void loginAcc()
{
    FILE *Fname;
    char name[100];

    while (1)
    {
        printf("Input your username : ");
        scanf ("%s", name);
        system("clear");
        strcat(name, ".txt");
        if ((Fname = fopen(name, "r")) == NULL)
        {
            printf("Account dose not exist\n");
            break;
        }
        else
        {
            printf("Login successfully\n");
            menu(name);
            break;
        }
    }
}

int main()
{
    FILE *Fname;
    char select = -1;

    while (1)
    {
        printf("1. Create account\n");
        printf("2. login  account\n");
        printf("Input option : ");
        fflush(stdin);
        scanf("%c", &select);
        system("clear");
        if (select == '1')
        {
            CreateAcc();
        }
        if (select == '2')
        {
            loginAcc();
        }
        if (select == '0')
            break;
    }

    printf("End ^-^");
    // printf(" ____   |\\      |   |)\n");
    // printf("|       | \\     |   | )\n");
    // printf("|       |  \\    |   |  )\n");
    // printf("|____   |   \\   |   |  )\n");
    // printf("|       |    \\  |   |  )\n");
    // printf("|       |     \\ |   | )\n");
    // printf("|____   |      \\|   |)\n");
}
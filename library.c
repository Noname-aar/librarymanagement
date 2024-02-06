#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
FILE *f;
typedef struct
{
    int id;
    char name[100];
    char author[100];
} book;

typedef struct
{
    char name[100];
    char username[100];
    char password[150];
} user;

typedef struct
{
    int sn;
    char name[100];
    char book[100];
    char author[100];
    int id;
} renters;

void menu()
{

    printf("\n\n");
    printf("\n\t\t|-----------------------------------------------------------------------|");
    printf("\n\t\t|\t:::::::::::::::::::::::::::::::\t|");
    printf("\n\t\t|\t:::::::::    Aayush Library     :::::::::::::|");
    printf("\n\t\t|\t:::::::::::::::::::::::::::::::\t|");
    printf("\n\t\t|\t:::::::::* WELCOME TO Menu :::::::::::::\t|");
    printf("\n\t\t|\t:::::::: How can I help you? :::::::::::*:\t|");
    printf("\n\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t|\t1. Books List \t\t\t\t\t\t\t|");
    printf("\n\t\t|\t2. LOGIN \t\t\t\t\t\t\t| ");
    printf("\n\t\t|\t3. EXIT \t\t\t\t\t\t\t|");
    printf("\n\t\t|-----------------------------------------------------------------------|");
    printf("\n\t\t|:::::::::::::::::::::::::::::::::::*:|");
    printf("\n\t\t|-----------------------------------------------------------------------|");
    printf("\n\t\tEnter your choice(1-3):");
}

void signup()
{
    user u;
    int c = 0;
    char confirm[150];
    f = fopen("user.txt", "r");
    if (f == NULL)
    {
        fclose(f);

        f = fopen("user.txt", "w");
        printf("\t|-----------------------------------------------------------------------|");
        printf("\n\t Enter your Name:");
        scanf("%s", &u.name);
        printf("\t|-----------------------------------------------------------------------|");
        printf("\n\t Enter Username:");
        scanf("%s", &u.username);
        do
        {
            if (c > 0)
            {
                printf("\n\t|-----------------------------------------------------------------------|");
                printf("\n\n\t !!!Password did not match please try again!!!\n");
                printf("\n\t|-----------------------------------------------------------------------|\n");
            }
            printf("\t|-----------------------------------------------------------------------|");
            printf("\n\t Enter Password:");
            scanf("%s", &u.password);
            printf("\t|-----------------------------------------------------------------------|");
            printf("\n\t Enter your Password Again:");
            scanf("%s", &confirm);
            printf("\t|-----------------------------------------------------------------------|");
            c++;
        } while (strcmp(u.password, confirm) != 0);

        if (strcmp(u.password, confirm) == 0)
        {
            fwrite(&u, sizeof(u), 1, f);
            printf("\n\t|-----------------------------------------------------------------------|");
            printf("\n\t|-----------------------------------------------------------------------|");
            printf("\n\tUser registered! Please wait");
            printf("\n\t|-----------------------------------------------------------------------|");
            printf("\n\t|-----------------------------------------------------------------------|");
            Sleep(2000);
            system("cls");

            fclose(f);
        }
    }
    else
    {
        fclose(f);
    }
}

void printbooks()
{
    book b;
    f = fopen("book.txt", "r");

    if (f == NULL)
    {
        printf("\t\t!!!File not found!!!");
    }
    else
    {
        printf("\n|-------------------------------------------------------|");
        printf("\n|I.D.|\tNAME\t\t|\tAuthor\t\t\t   |");
        while ((fread(&b, sizeof(b), 1, f) == 1))
        {
            printf("\n|---|-------------------|-------------------------------|");
            printf("\n|%d.|\t%s\t\t|%s\t\t\t\t|", b.id, b.name, b.author);
        }

        printf("\n|-------------------------------------------------------|");
    }
    fclose(f);
}

void create()
{
    book b;
    int i, j;
    int z;
    f = fopen("book.txt", "a+");
    printf("Enter the number of new books you want to add:");
    scanf("%d", &j);
    for (i = 1; i <= j; i++)
    {
        printf("\nEnter I.D.:");
        scanf("%d", &b.id);
        printf("\nEnter name:");
        scanf("%s", &b.name);
        printf("\nEnter author:");
        scanf("%s", &b.author);

        fwrite(&b, sizeof(b), 1, f);
    }

    printf("\nData added successfully");
    fclose(f);
}
void renterlist()
{
    renters r;
    f = fopen("renters.txt", "r");

    if (f == NULL)
    {
        printf("\t\t!!!File not found!!!");
    }
    else
    {
        printf("\n|--------------------------------------------------------------------------------------------------|");
        printf("\n|S.N.|\tNAME\t\t|\tBook\t\t|\tAuthor\t\t|\tID\t\t   |");
        while ((fread(&r, sizeof(r), 1, f) == 1))
        {
            printf("\n|--------------------------------------------------------------------------------------------------|");
            printf("\n|%d.|\t%s\t\t|\t%s\t\t|%s\t\t|\t%d\t\t|", r.sn, r.name, r.book, r.author, r.id);
        }

        printf("\n|--------------------------------------------------------------------------------------------------|");
    }
    fclose(f);
}

void addrenters()
{
    renters r;
    int i, j;
    int z;
    f = fopen("renters.txt", "a+");
    printf("Enter the number of person renting a book each:");
    scanf("%d", &j);
    for (i = 1; i <= j; i++)
    {
        printf("\nEnter S.N.:");
        scanf("%d", &r.sn);
        printf("\nEnter name:");
        scanf("%s", &r.name);
        printf("\nEnter book name:");
        scanf("%s", &r.book);
        printf("\nEnter author:");
        scanf("%s", &r.author);
        printf("\nEnter I.D.:");
        scanf("%d", &r.id);

        fwrite(&r, sizeof(r), 1, f);
    }

    printf("\nData added successfully");
    fclose(f);
}

void usermenu()
{
    user u;
    int lchoice;
    f = fopen("user.txt", "r");

    while ((fread(&u, sizeof(u), 1, f) == 1))
    {
        printf("\n\n");
        printf("\n\t\t|-----------------------------------------------------------------------|");
        printf("\n\t\t|\t:::::::::::::::::::::::::::::::\t|");
        printf("\n\t\t|\t:::::::* WELCOME TO Admin  :::::::::::::*:\t|");
        printf("\n\t\t|\t:::::::::::::::::::::::::::::::\t|");
        printf("\n\t\t|\t:::::::::   %s     :::::::::::::\t|", u.name);
        printf("\n\t\t|\t:::::::: How may I help you? :::::::::::*:\t|");
        printf("\n\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t|\t1. Book List \t\t\t\t\t\t\t|");
        printf("\n\t\t|\t2. Add new book \t\t\t\t\t\t| ");
        printf("\n\t\t|\t3. Renters List  \t\t\t\t\t\t|");
        printf("\n\t\t|\t4. Add Renters  \t\t\t\t\t\t|");
        printf("\n\t\t|\t5. Exit  \t\t\t\t\t\t\t|");
        printf("\n\t\t|-----------------------------------------------------------------------|");
        printf("\n\t\t|:::::::::::::::::::::::::::::::::::*:|");
        printf("\n\t\t|-----------------------------------------------------------------------|");
        printf("\n\t\tEnter your choice(1-5):");
    }
    scanf("%d", &lchoice);
    switch (lchoice)
    {
    case 1:
        printbooks();
        usermenu();
        break;
    case 2:
        create();
        usermenu();
        break;
    case 3:
        renterlist();
        usermenu();
        break;
    case 4:
        addrenters();
        usermenu();
        break;
    case 5:
        exit(0);
        menu();
        break;
    default:
        printf("!!!INVALID INPUT!!!");
        usermenu;
        break;
    }
    fclose(f);
}

void login()
{
    user u;
    char pass[150], name[100], ch;
    int i;
    f = fopen("user.txt", "r");
    printf("\n\t|-----------------------------------------------------------------------|");
    printf("\n\tUsername:");
    scanf("%s", &name);
    printf("\n\tPassword:");
    while ((ch = getch()) != 13)
    {
        if (ch == 8 && i > 0)
        {
            printf("\b \b");
            i--;
        }
        else if (i >= 0)
        {
            pass[i] = ch;
            printf("*");
            i++;
        }
    }
    pass[i] = '\0';
    while ((fread(&u, sizeof(u), 1, f) == 1))
    {
        if ((strcmp(u.username, name) == 0) && (strcmp(u.password, pass) == 0))
        {
            printf("\n\n\tLogin Successful, Please Wait ");
            fclose(f);
            Sleep(2000);
            system("cls");
            usermenu();
            break;
        }
        else
        {
            printf("!!!Invalid username or password, Please try again!!!");
            login();
            break;
        }
    }
    fclose(f);
}

int main()
{ // main block of code to execute respective task from the general menu
    int choice;
    signup();
    menu();
    scanf("%d", &choice);
    while (1)
    { //
        switch (choice)
        {
        case 1:
            printbooks();
            main();
            break;
        case 2:
            login();
            break;
        case 3:
            printf("\n\tTHANK YOU FOR USING THE PROGRAM");
            printf("\n\tPress ENTER key to exit program");
            exit(0);
            break;
        default:
            printf("!!!INVALID INPUT!!!");
            main();
            break;
        }
         
    }
    return (0);
}
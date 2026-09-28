#include <stdio.h>
#include <stdio_ext.h>

#include "contact.h"

struct CONTACT *db = NULL;
int cnt=0;

void printMenu(void)
{
        printf("\n---------------MENU------------------\n");
        printf("--------------------------------------\n");
        printf("i:input\np:print\nq:quit\n");
        printf("f:find\ns:sort\nd:delete\n");
        printf("Enter your choice:");
}

int main()
{
        char choice;
        while(1)
        {
                printMenu();
                __fpurge(stdin);
                scanf("%c",&choice);
                switch(choice)
                {
                        case 'i':db=input(db); 
                                break;
                        case 'd':db=delete(db);
                                break;
                        case 'q':return 0;
                        case 'p':print(db);
                                break;
                        case 'f':find(db);
                                break;
                        case 's':sort(db);
                                break;
                        default: printf("Error:invalid entry\n");
                }
        }
}


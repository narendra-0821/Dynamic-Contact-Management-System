#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "contact.h"

struct CONTACT *input(struct CONTACT *p)
{
        p=realloc(p,(cnt+1)*sizeof(struct CONTACT));
        char temp[100];
        __fpurge(stdin);
        printf("Enter name:");
        scanf("%[^\n]",temp);
        p[cnt].name=malloc(strlen(temp)+1);
        strcpy(p[cnt].name,temp);
               __fpurge(stdin);
        printf("Enter contact no:");
        scanf("%[^\n]",temp);
        p[cnt].contactNo=malloc(strlen(temp)+1);
        strcpy(p[cnt].contactNo,temp);
           __fpurge(stdin);
        printf("Enter email id:");
        scanf("%[^\n]",temp);
        p[cnt].emailId=malloc(strlen(temp)+1);
        strcpy(p[cnt].emailId,temp);

        cnt++;
        return p;
}

struct CONTACT *delete(struct CONTACT *p)
{
        int i;
        if(cnt==0){
            printf("no records\n");
            return NULL;
        }
            
        printf("Enter index to remove:");
        scanf("%d",&i);
        if(i<0 || i>=cnt){
            printf("invalid index\n");
            return NULL;
        }
        memmove(p+i,p+i+1,(cnt-1-i)*sizeof(struct CONTACT));
        --cnt;
        p=realloc(p,cnt*sizeof(struct CONTACT));
        return p;
}


void print(struct CONTACT *db)
{
        int i;
        printf("\n<-*****************Current records**************************->\n");
        printf("-------------------------------------------------------------\n");
        for(i=0;i<cnt;i++)
                printf("record %d: %-20s %-20s %-20s\n",i,db[i].name,db[i].contactNo,db[i].emailId);
        
        printf("\n----------------------------------------------------------\n");

}

void find(struct CONTACT *p)
{
        char name[50];
        int i;
        printf("enter the name to be searched :");
        scanf("%s",name);
        for(i=0;i<cnt;i++)
        {
                if(!strcmp(name,p[i].name))
                {
                        printf("-----find the details you have searched for------\n");                    
                        printf("->name :%s\n",p[i].name);
                        printf("->emailid :%s\n",p[i].emailId);
                        printf("->mobile : %s\n",p[i].contactNo);
                        return;
                }
        }
        printf("%s is not found\n",name);
}
void *sort(struct CONTACT *p)
{
        int i,j;
        struct CONTACT temp;

        for(i=1;i<cnt;i++)
        {
                for(j=0;j<cnt-i;j++)
                {
                        if(strcmp(p[j].name,p[j+1].name)>0)
                        {
                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
}


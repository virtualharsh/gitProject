#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char str[40];

void append(char appendString[],char str[]){
    int c=0,countStr=0,i=0;

    while (str[i]!='\0'){
        countStr++;
        i++;
    }

    i=0;
    while (appendString[i]!='\0')
    {
        str[countStr] = appendString[c];
        countStr++;
        c++;
        i++;
    }    
    while(countStr<=40){
        str[countStr] = '\0';
        countStr++;
    }
}

void clearString(){
    int i=0;
    while(i<=40){
        str[i] = '\0';
        i++;
    }
}


int main(){
    int choice,errorCode;
    char msg[20],username[15],repositoryName[15];

    do{
        printf("\n1.INITIALISE GIT REPOSITORY\n");
        printf("\n2.ADD CHANGES\n");
        printf("\n3.COMMIT WITH MESSAGE\n");
        printf("\n4.PUSH TO REMOTE GITHUB REPOSITORY\n");
        printf("\n5.SET GITHUB REPOSITORY\n");
        printf("\n\t\tEnter Your Choice:");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            errorCode = system("git init");
            printf("REPOSITORY INITIALISED SUCCESSFULLY");
            break;
        case 2:
            errorCode = system("git add .");
            break;
        case 3:
            append("git commit -m '",str);
            printf("\nEnter your message:");
            scanf("%s", &msg);
            puts(msg);
            append(msg,str);
            append("'",str);
            puts(str);
            errorCode = system(str);
            clearString(str);
            break;
        case 4:
            errorCode = system("git push -u origin master");
            break;
        case 5:
            printf("\nEnter your GITHUB Username:");
            scanf("%s", &username);
            printf("\nEnter your GITHUB Repository Name:");
            scanf("%s", &repositoryName);
            append("git remote add origin https://github.com/",str);
            append(username,str);
            append("/",str);
            append(repositoryName,str);
            append(".git",str);
            puts(str);
            errorCode = system(str);
            clearString(str);
            break;
        }
        
    } while (choice!=0);
}
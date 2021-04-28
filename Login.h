#include<stdio.h>
#include"BST.h"
#include<string.h>
treeType read = NULL; // cây BST lưu trữ dữ liệu
void importdata(){
    elementType temp;
    char tmp[100];
    FILE* data = fopen("database.txt","r+");
    fgets(tmp,100,data);
    while(fscanf(data,"%s %s\n",temp.Username,temp.Password)!= EOF){
    insertNode(temp,&read);
    }
    
};  
elementType login()
{
    int time = 1;
    elementType tmp;
    elementType checkpass;
    printf("Enter Username :_____");
    scanf("%s",tmp.Username);
    if(search(tmp.Username,read) == NULL){
        printf("Valid Username ! Please press 1 and try again !\n");
        strcpy(tmp.Username,"Guest");
        return tmp;
        
    }
    else{
       checkpass  = search(tmp.Username,read)->element;
        printf("Enter password for %s :____",tmp.Username);
        scanf("%s",tmp.Password);
        while(strcmp(tmp.Password,checkpass.Password)!= 0) {
            if(time == 3){
                printf("Too much time ! \n");
                strcpy(tmp.Username,"Guest");
                break;
            }
            printf("Valid password ! Please try again !\n");
            scanf("%s",tmp.Password);
            time ++;
        }
        if(strcmp(tmp.Password,checkpass.Password)== 0)
        return tmp;
    }
    return tmp;
}
elementType signup()
{
    elementType Newbie;
    printf("\nEnter your Username :___");
    scanf("%s",Newbie.Username);
    while(search(Newbie.Username,read) != NULL){
        printf("This Username has already exits ! Plese try a new one :\n");
        scanf("%s",Newbie.Username);
    }
    printf("\nEnter your Password :___");
    scanf("%s",Newbie.Password);
    while(strlen(Newbie.Password)>=10){
        printf("Too long ! Shorter please !___\n");
        scanf("%s",Newbie.Password);
    }
    printf("\nYour account is ready to use !\n");
    insertNode(Newbie,&read);
    return Newbie;
}
int Menu()
{
    char choice;
    while(choice != '1'&& choice !='2'&& choice !='3')
    {
        printf("\n\n\n");
        printf("\t|%-30s|\n","1. Login ");
        printf("\t|%-30s|\n","2. Sign Up");
        printf("\t|%-30s|\n","3. Main Menu");
        printf("\n\nEnter your choice :___");
        fflush(stdin);
        scanf("%c",&choice);
        system("cls");
        switch(choice)
        {
            case '1' :  
            return 1;
            break;
            case '2' : 
            return 2;
            break;
        }
    }
}
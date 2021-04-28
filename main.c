#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Login.h"

elementType User;

int main(){
    strcpy(User.Username,"Guest");
    strcpy(User.Password,"0");
    char choice;
    int num ;
    importdata(); // doc database luu taikhoan mat khau nguoi dung da co
    while(choice != '5')
    {
        if(strcmp(User.Username,"admin") != 0){
        printf("\n\n\t|%-15s%-15s|\n","Menu for",User.Username);
        printf("\t|%-30s|\n","1. Login or Sign Up");
        printf("\t|%-30s|\n","2. Request");
        printf("\t|%-30s|\n","3. Check my Request :");
        printf("\t|%-30s|\n","4. Log Out");
        printf("\t|%-30s|\n","5. Exit");
        printf("\nEnter your choice :___");
        fflush(stdin);
        scanf("%c",&choice);
        system("cls");
        switch(choice)
        {
            case '1' : 
            if(strcmp(User.Username,"Guest")== 0){
            //inOrderPrint(read);
            num =  Menu();
            if(num == 1) 
            User = login();
            if(num == 2) 
            User = signup();
            if(num ==3) continue;
            }
            else printf("\nU have already logged in !\n");
            break;
            case '2' :  break;
            case '3' :  break;
            case '4' : strcpy(User.Username,"Guest");
            case '5' : freeTree(read);
        }
    }
    else{
        printf("\n\n\t|%-15s%-15s|\n","Menu for",User.Username);
        printf("\t|%-30s|\n","1. Checking Requests");
        printf("\t|%-30s|\n","2. Manage the infrastructure :");
        printf("\t|%-30s|\n","3. Log Out");
        printf("\t|%-30s|\n","4. Exit");
        printf("\nEnter your choice :___");
        fflush(stdin);
        scanf("%c",&choice);
        system("cls");
        switch(choice)
        {
            case '1' : break;
            case '2' : break;
            case '3' : strcpy(User.Username,"Guest");
                       strcpy(User.Password,"0");
                       break;
            case '4' : freeTree(read);
        }
    }
    }
}
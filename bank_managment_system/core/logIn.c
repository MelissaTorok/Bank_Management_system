
#include "headers/logIn.h"

#include<string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>



#include "headers/structs.h"
#include "headers/singUp.h"





/**
 * The function `readStructFromFile` reads data from a file and assigns it to a struct in C.
 * 
 * @param filename The function `readStructFromFile` reads data from a file specified by the `filename`
 * parameter. 
 */
void readStructFromFile(char filename[100]){

    person *user ;


    user = (struct person *) malloc(sizeof(struct person));

    account *detailsaccount;

    detailsaccount = (struct account *) malloc(sizeof(struct account));

    char variable[100];
    FILE *fptr;

    fptr = fopen(filename, "rt");


    int ok=1;
    while (fscanf(fptr, "%s ",variable)== 1) {

        if(ok == 1) {
            strcpy(user->password, variable);
            printf("Password: %s",user->password);

        }

        if(ok == 2) {
            strcpy(detailsaccount->Iban, variable);
            printf("\nIban: %s",detailsaccount->Iban);
            // int summm;
            //fscanf(fptr, "%d ",summm);
            //detailsaccount->sum = summm;
            //ok++;

        }
        if(ok == 3)
            strcpy (detailsaccount->sum,variable);

        //printf("aaaaaaa");

        if(ok==4) {
            strcpy(detailsaccount->currency, variable);
            //printf("\nSum of your account and the currency: %d %s ", detailsaccount->sum, detailsaccount->currency);
            printf("\nSum of your account and the currency: %s %s ",detailsaccount->sum, detailsaccount->currency);

        }
        ok++;

    }
    fclose(fptr);


}







/**
 * The function `get_account_from_file` reads account details from a file and returns the account
 * information.
 * 
 * @param filename The function takes a filename as a parameter to read the account
 * information from.
 * 
 * @return The function `get_account_from_file` is returning a structure of type `account` which
 * contains the details read from the file specified by the `filename` parameter.
 */
account get_account_from_file(char filename[100]){

    person *user ;

    user = (struct person *) malloc(sizeof(struct person));

    account *detailsaccount;

    detailsaccount = (struct account *) malloc(sizeof(struct account));

    char variable[100];
    FILE *fptr;

    fptr = fopen(filename, "rt");


    int ok=1;
    while (fscanf(fptr, "%s ",variable)== 1 && ok<=5) {

        if (ok == 1) {
            strcpy(user->password, variable);
            //printf("Password: %s",user->password);

        }

        if (ok == 2) {
            strcpy(detailsaccount->Iban, variable);
            //printf("\nIban: %s",detailsaccount->Iban);

        }
        if (ok == 3)
            strcpy(detailsaccount->sum, variable);
//            detailsaccount->sum = (int)(variable);


        if (ok == 4) {
            strcpy(detailsaccount->currency, variable);

        }
        ok++;


    }



    fclose(fptr);

    return *detailsaccount;

}






/**
 * The function compares the input password with the password stored in a file and prompts the user to
 * re-enter the password if they do not match.
 * 
 * @param filename The `filename` parameter is a string that represents the name of the file where the
 * account password is stored. 
 * @param inputpassword The `inputpassword` parameter represents the password entered by the
 * user trying to log in.
 */
void loginComparingInputpasswordAndFileAccountPassword(char filename[100], char inputpassword[100]){
    FILE *fptr;
    int ok=1;
    fptr = fopen(filename, "r");

    char passwordFromFile[100];

    fgets(passwordFromFile, 100, fptr);

    fclose(fptr);
    if (passwordFromFile[strlen(passwordFromFile) - 1] == '\n')
        passwordFromFile[strlen(passwordFromFile) - 1] = '\0';

    if(!strcmp(passwordFromFile, inputpassword)){
        printf("-------Welcome to your account!-------\n");
    }else{
        while (ok) {
            printf("PASSWORD INCCORECCT");

            printf("\nEnter Your password again:\t");
            scanf("%s",inputpassword);


            if (!strcmp(inputpassword, passwordFromFile)) {
                ok = 0;
            }

        }
    }
}




/**
 * The LoGIn function allows a user to log in, access their account, make various actions such as
 * editing account details, viewing data, or deleting the account.
 * 
 * @param loginusername The `loginusername` parameter is a character array that stores the
 * username of the user trying to log in.
 */
void LoGIn(char loginusername[100]){

    person *user;
    struct account *detailsaccount ;

    detailsaccount = (struct account *) malloc(sizeof(struct account));


    char NameOfTheFile[100], IbanFromTheFile[100], NewIban[100], lastnameOfTheRecipient[100], firstnameOfTheRecipient[100], nameOfTheRecipient[100];

    user = (struct person *) malloc(sizeof(struct person));

    int choosenoption;

    if (strcmp(loginusername, "") == 0)
    {
        printf("Enter your username (lastname_firstname): ");
        scanf("%s", loginusername);
    }

    strcpy(NameOfTheFile, loginusername);

    strcat(loginusername, ".txt");
    //printf("ACCOUNT:[%s]", loginusername);

    if (access(loginusername, F_OK) == 0) {

        printf("ENTER YOUR ACCOUNT PASSWORD: ");
        scanf("%s",user->password);

        loginComparingInputpasswordAndFileAccountPassword(loginusername, user->password);

        printf("\n What action do you want to make in your account?\n 1 for Edit account \n 2 for View the account data \n 3 for Deleting the account\n 4 for making a transaction");
        printf("\nPress 1, 2, 3 or 4: ");
        scanf("%d", &choosenoption);

        switch (choosenoption) {

            char theSum[30];
            int theDeposit, theFileSum;
            char iban[30];
            account sender_account, recipient_account;

            case 1:
                printf("What do you want to modify at your account?");
                printf("\nPress 1 for modifying the Iban\nPress 2 for adding money"
                       "\nPress 3 to withdrawing money\nPress 4 to change your account coin\nPress the number: ");
                scanf("%d", &choosenoption);

                switch (choosenoption) {

                    case 1:
                        *detailsaccount = get_account_from_file(loginusername);

                        printf("The present Iban: %s", detailsaccount->Iban);
                        int i;
                        for(i=0; i<5; i++) {
                            NewIban[i] = detailsaccount->Iban[i];
                        }
                        printf("\nYour new Iban will start mandatory with: %s\n", NewIban );
                        strcpy(detailsaccount->Iban, NewIban);

                        printf("Please enter your new numbers for the Iban:");
                        scanf("%s", NewIban);

                        strcat(detailsaccount->Iban, NewIban);

                        printf("The Iban after you change it is: %s", detailsaccount->Iban);
                        strcpy(detailsaccount->Iban, detailsaccount->Iban);
                        //write_struct_to_file(loginusername, *user, IbanFromTheFile, detailsaccount->currency );
                        write_struct_to_file(loginusername, *user, *detailsaccount );

                        break;

                    case 2:

                        *detailsaccount = get_account_from_file(loginusername);


                        printf("The present sum in your account: %s", detailsaccount->sum);
                        printf("\nPlease enter the sum for the deposit:");
                        scanf("%s", theSum);
                        sscanf(theSum, "%d", &theDeposit);

                        sscanf(detailsaccount->sum, "%d", &theFileSum);
                        theFileSum += theDeposit;

                        sprintf(theSum, "%d", theFileSum);
                        printf("\nthe current sum in the account is %s:", theSum);

                        strcpy(detailsaccount->sum, theSum);

                        printf("sum%s:", detailsaccount->sum);

                        write_struct_to_file(loginusername, *user, *detailsaccount );

                        break;

                    case 3:
                        *detailsaccount = get_account_from_file(loginusername);

                        printf("The present sum in your account: %s", detailsaccount->sum);
                        printf("\nPlease enter the sum for the withdrawing:");
                        scanf("%s", theSum);

                        sscanf(theSum, "%d", &theDeposit);

                        sscanf(detailsaccount->sum, "%d", &theFileSum);

                        if(theDeposit > theFileSum){
                            printf("You don't have enough money in your account");
                        }
                        else{
                            theFileSum-= theDeposit;



                            sprintf(theSum, "%d", theFileSum);
                            printf("\nthe current sum in the account is %s:", theSum);

                            strcpy(detailsaccount->sum, theSum);

                            write_struct_to_file(loginusername, *user, *detailsaccount );

                        }

                        break;


                    case 4:
                        *detailsaccount = get_account_from_file(loginusername);
                        //char *new_coin = NULL;
                        int new_coin;
                        printf("The present Coin: %s", detailsaccount->currency);

                        printf("\nPlease press\n1 for EURO\n2 for RON\n3 for DOLAR\n");
                        scanf("%d", &new_coin);

                        switch (new_coin) {
                            case 1:
                                    if(strcmp(detailsaccount->currency, "RON")==0){


                                        sscanf(detailsaccount->sum, "%d", &theFileSum);

                                        theFileSum =theFileSum * 5;

                                        sprintf(theSum, "%d", theFileSum);


                                        strcpy(detailsaccount->sum, theSum);

                                        strcpy(detailsaccount->currency, "EURO");


                                        write_struct_to_file(loginusername, *user, *detailsaccount );

                                    }

                                    if(strcmp(detailsaccount->currency, "DOLAR")==0){


                                        sscanf(detailsaccount->sum, "%d", &theFileSum);

                                        theFileSum =theFileSum * 5;

                                        sprintf(theSum, "%d", theFileSum);


                                        strcpy(detailsaccount->sum, theSum);

                                        strcpy(detailsaccount->currency, "EURO");


                                        write_struct_to_file(loginusername, *user, *detailsaccount );

                                    }

                                    break;
                            case 2:

                                if(strcmp(detailsaccount->currency, "EURO")==0){


                                    sscanf(detailsaccount->sum, "%d", &theFileSum);

                                    theFileSum =theFileSum / 5;

                                    sprintf(theSum, "%d", theFileSum);


                                    strcpy(detailsaccount->sum, theSum);

                                    strcpy(detailsaccount->currency, "EURO");


                                    write_struct_to_file(loginusername, *user, *detailsaccount );

                                }





                                break;

                        }

                        //strcpy(detailsaccount->currency, new_coin);
                        write_struct_to_file(loginusername, *user, *detailsaccount );

                        break;

                    default:
                        break;


                }

                break;
            case 2:
                scanf("Welcome to your account:");
                readStructFromFile(loginusername);

                break;
            case 3:
                printf("Are you sure that do you want to delete your account? Press 1 for YES and 2 for NO:\t");
                scanf("%d", &choosenoption);
                if(choosenoption==1)
                    remove(loginusername);
                break;

            case 4:



                printf("\nWrite the last name of the recipient:");
                scanf("%s",lastnameOfTheRecipient);

                //lastnameOfTheRecipient[strlen(lastnameOfTheRecipient)] = '_';

                printf("\nWrite the first name of the recipient:");
                scanf("%s", firstnameOfTheRecipient);

                strcpy(nameOfTheRecipient, lastnameOfTheRecipient);

                nameOfTheRecipient[strlen(nameOfTheRecipient)] = '_';

                strcat(nameOfTheRecipient, firstnameOfTheRecipient);

                strcat(nameOfTheRecipient, ".txt");

                printf("%s", nameOfTheRecipient);

                if (access(nameOfTheRecipient, F_OK) == 0) {

                    printf("Write the Iban of the account:");
                    scanf("%s", iban);

                    recipient_account = get_account_from_file(nameOfTheRecipient);

//                     sender_account = get_account_from_file(loginusername);

                    *detailsaccount = get_account_from_file(loginusername);

                    if (strcmp(iban, recipient_account.Iban) == 0) {
                        printf("The present sum in your account: %s", detailsaccount->sum);
                        printf("\nPlease enter the sum for the withdrawing:");
                        scanf("%s", theSum);

                        sscanf(theSum, "%d", &theDeposit);

                        sscanf(detailsaccount->sum, "%d", &theFileSum);

                        if (theDeposit > theFileSum) {
                            printf("You don't have enough money in your account");
                        } else {
                            theFileSum -= theDeposit;

                            sprintf(theSum, "%d", theFileSum);
                            printf("\nthe current sum in your account is %s:", theSum);
                            strcpy(detailsaccount->sum, theSum);
                            write_struct_to_file(loginusername, *user, *detailsaccount);


                            sscanf(recipient_account.sum, "%d", &theFileSum);


                            theFileSum += theDeposit;

                            sprintf(theSum, "%d", theFileSum);
                            printf("\nthe current sum in the recipient  account is %s:", theSum);
                            strcpy(recipient_account.sum, theSum);
                            write_struct_to_file(nameOfTheRecipient, *user, recipient_account);


                        }
                    }
                    else {
                        printf("The iban doesnt match the account");
                    }

                    } else
                        printf("The name and surname does not match any of the bank users");




                break;


        }


    } else{
        printf("You don't have an account\n");
        printf("Press 1 if you want to create one:");
        scanf("%d", &choosenoption);
        if(choosenoption == 1)
            case1SingUp();


    }

}

















#include "headers/singUp.h"
#include<string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>


#include "headers/structs.h"
#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif

#define PASSWORD_LENGTH 12




/**
 * The function `write_struct_to_file` writes the data from a struct `person` and a struct `account` to
 * a file specified by the `namesurname` parameter.
 * 
 * @param namesurname The `namesurname` parameter is a character array that represents the name of the
 * file where the data will be written.
 * @param person1 
 * @param detailsaccount 
 */
void write_struct_to_file( char namesurname[100], struct person person1, struct account detailsaccount )
{
    FILE* outfile;

//    strcpy(detailsaccount.sum, "0");
//    //printf("curr:%s", currency);
    outfile = fopen(namesurname, "wb");

    if (outfile == NULL) {
        fprintf(stderr, "\nError opened file\n");
        exit(1);
    }

    fprintf(outfile,"%s", person1.password);
    //fprintf(outfile,"%s %s ",firstname, lastname);
    fprintf(outfile,"\n%s\n",detailsaccount.Iban);
    fprintf(outfile,"%s\n", detailsaccount.sum );
    fprintf(outfile,"%s\n", detailsaccount.currency);


    fclose(outfile);

}



/**
 * The function `case1SingUp` allows a user to sign up by providing personal details and creating an
 * account with specified currency.
 */
void case1SingUp(){
    struct person *user ;
    struct account *detailsaccount;

    detailsaccount =(struct account*) malloc(sizeof (struct account));

    user = (struct person *) malloc(sizeof(struct person*));

    char passwordConfirmation[100], Iban[100] = {"BNR"}, IbanNumberchar[100], currency[100], loginusername[100];

    int IbanNumbers, inputOptionswitch;



    printf("\nEnter Your first name :\t");
    scanf("%s", user -> firstName);

    printf("\nEnter Your last name :\t");
    scanf("%s",user->lastName);

    printf("\nEnter Your password:\t");
    scanf("%s",user->password);


    printf("\nConfirm your password:\t");
    scanf("%s",passwordConfirmation);


    int ok=1;

    //verify if user.passowrd and passwordConfirmation are the same thing
    if(!strcmp(user->password, passwordConfirmation)){
        printf("\nYour password matched\n");
    }else {
        printf("\n   **Password didn't match**");
        while (ok) {
            printf("\nEnter Your password again:\t");
            scanf("%s",user->password);
            printf("\nConfirm your password:\t");
            scanf("%s",passwordConfirmation);

            if (!strcmp(user->password, passwordConfirmation)) {
                ok = 0;
                printf("PASSWORD MATCHED");
            }

        }
    }

    char s[100] ;
    strcpy(s , user->lastName);
    strcat(s, "_");
    strcat(s, user->firstName);
    strcat(s, ".txt");
    strcat(user->lastName, " ");

    //making the Iban
    strcpy(Iban, "BNR");

    //making the first letter from the lastName and from the first name upper

    if(user->lastName[0] >= 'a' && user->lastName[0] <='z')
        user->lastName[0] = user->lastName[0] - 32;

    if(user->firstName[0] >= 'a' && user->firstName[0] <='z')
        user->firstName[0] = user->firstName[0] - 32;


    //IbanNumbers = rand();
    //printf("random:%d", IbanNumbers);
    srand ( time(NULL) );
    //printf ("Random Number: %d\n", rand() % 1000*10230);
    IbanNumbers = rand() % 1000*10230;

    itoa(IbanNumbers, IbanNumberchar, 10);

    Iban[strlen(Iban)] = user->lastName[0];
    Iban[strlen(Iban)] = user->firstName[0];
    strcat(Iban,IbanNumberchar);

    printf("In what currency do you want to be your account?");
    printf("\n 4 for RON");
    printf("\n 5 for EURO");
    printf("\n 6 for DOLAR");
    printf("\nPress the number:\t");
    scanf("%d", &inputOptionswitch);

    switch (inputOptionswitch) {

        case 4:
            strcpy(currency, "RON");
            break;

        case 5:
            strcpy(currency, "EURO");
            break;

        case 6:
            strcpy(currency, "DOLAR");
            break;



    }


    printf("%s", currency);

    strcpy(detailsaccount -> sum, "0");


    strcpy(detailsaccount -> Iban , Iban);
    strcpy(detailsaccount ->currency, currency);


    //write_struct_to_file(s, *user, Iban, currency);
    write_struct_to_file(s, *user, *detailsaccount);


}



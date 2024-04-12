
#include<string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>



#include "headers/structs.h"
#include "headers/singUp.h"
#include "headers/logIn.h"

#ifdef WIN32

#include <io.h>
#define F_OK 0
#define access _access

#endif

#include "headers/runner.h"



/**
 * The main_runner function handles user authentication and menu options based on command-line
 * arguments or user input.
 * 
 * @param argc The `argc` parameter represents the number of arguments
 * passed to the program when it is executed.
 * @param argv argv is an array of strings 
 */
void main_runner( int argc, char *argv[] )
{
    system("color b");


    int choosenoption;


    char loginusername[100] = "";

    if (argc != 4) {
        printf("\n\t\t\t---------Welcome to the BMS---------\n\n");
        printf("\nIf you don't have an account choose , press 1,SingUp, if you already have choose Login, press2");
        printf("\n1.SingUp");

        // replaced by the CLI arguments
        printf("\n2.Login");
        printf("\n3.Exit\n");

        printf("Press the number:\t");
        scanf("%d", &choosenoption);
        fgetc(stdin);
    }
    else{
        if ( strcmp(argv[1], "login" ) == 0 )
        {

                strcat(loginusername, argv[2]);
            strcat(loginusername, "_");
            strcat(loginusername, argv[3]);

            choosenoption = 2;
        }
        else
        {
            printf("Only 'login name surname' are accepted as arguments! \n Program will exit!");

            choosenoption = 3;
        }
    }

    switch (choosenoption) {

        case 1:
            case1SingUp();

            break;

        case 2:

            LoGIn(loginusername);

            break;
        case 3:
            printf("Goodbye, hope to see you again!");
            exit(0);


    }


}

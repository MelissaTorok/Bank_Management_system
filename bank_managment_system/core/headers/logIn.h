//
// Created by MelissaAsus on 3/31/2024.
//

#ifndef UNTITLED_LOGIN_H
#define UNTITLED_LOGIN_H


// aici definesti functiile

#include "structs.h"


account get_account_from_file(char filename[100]);

void loginComparingInputpasswordAndFileAccountPassword(char filename[100], char inputpassword[100]);


void LoGIn(char loginusername[100]);



#endif //UNTITLED_LOGIN_H

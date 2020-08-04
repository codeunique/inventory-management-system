#pragma once
#include<iostream>
#include"./Article.h"

 class Admin
{
   private:
       char password[11];
       char storedPass[11]="asdzxc@321";


  public:
    void storeAdminMenu(Article a);

    void getPassword();
    int verifyPassword();

};






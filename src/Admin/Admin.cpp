#include<iostream>
#include<cstring>
#include<windows.h>
#include"../Admin.h"
#include"../Article.h"
using namespace std;
void Admin::getPassword()
    {
        std::cout<<"\nEnter Password"<<endl;
        std::cin>>password;

    }


int Admin::verifyPassword()
    {
        if(strcmp(password,storedPass)==0)
        {
              std::cout<<"\nAccess Authorized\n";
              return 1;}

            else
            {
                std::cout<<"wrong password!! Try Again.\n";
                this->getPassword();

                return 0;

            }


    }

  void Admin:: storeAdminMenu(Article a)
   {    int choice=0;
        system("cls");
        this->getPassword();
        if(this->verifyPassword())
        {

     while(choice!= 7)
    {

        cout<<"    1. Add New Article\n";
        cout<<"    2. Remove Article\n";
        cout<<"    3. Update Article\n";
        cout<<"    4. Show Leather Articles\n";
        cout<<"    5. Show Plastic Articles\n";
        cout<<"    6. Show Glass Articles\n";
        cout<<"    7. Back to Main Menu\n";
        cout<<"    8. invalid choice\n";
      std::cout<<"\n Enter your choice:"<<endl;
      std::cin>>choice;
      switch(choice)
      {
      case 1: a.addArticle();
                  break;
          case 2: a.removeArticle();
                       cout<<"working fine"<<endl;
                   break;
          case 3:  a.updateArticle();
                   cout<<"working fine"<<endl;
                   break;
          case 4:  a.getAllArticles('L');
                   break;
          case 5:  a.getAllArticles('P');
                   break;
          case 6:  a.getAllArticles('G');break;

          case 7: showMainMenu();break;

          default: std::cout<<"invalid choice!! enter from given choices:\n";
                        break;
      }
    }}
    }

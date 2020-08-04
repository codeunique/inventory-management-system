#include<fstream>
#include<iostream>
#include<cstring>
#include"./Article.h"
#include"./Admin.h"
#include<windows.h>
 using namespace std;
Article::Article()// constructor
  {
      aType = '\0';
      strcpy(aName,"");
      aPrice = 0;
      aQuantAvail=0;
  }

void Article:: updateArticle()
{
    char ch='0';
     ofstream fout;
     ifstream fin;
     int index =0;
     char ch1='9';
     int i;
     fout.open("temp.dat",ios::out|ios::binary);
     while(ch1!='n'){
    cout<<"select type of articles(L/P/G)"<<endl;
    cin>>ch;
    if(ch=='L')getAllArticles('L');
    else if(ch=='P')getAllArticles('P');
    else if(ch=='G')getAllArticles('G');
    else cout<<"entered wrong choice/halted"<<endl;
    cout<<"enter index of article you want to modify:";
    cin>>index;
    switch(ch)
    {
        case 'L':fin.open("checkL.dat",ios::in|ios::binary);
                  i=0;
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof()){
                 if(i!=index){fout.write((char*)this,sizeof(*this));}
                 else {setArticle('L');fout.write((char*)this,sizeof(*this));}
                 fin.read((char*)this,sizeof(*this));
                 i++;
                }
                  fin.close();
                  fout.close();
                  remove("checkL.dat");
                  rename("temp.dat","checkL.dat");
                  break;
        case 'P':fin.open("checkP.dat",ios::in|ios::binary);
                  i=0;
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof()){
                 if(i!=index){fout.write((char*)this,sizeof(*this));}
                 else {setArticle('P');fout.write((char*)this,sizeof(*this));}
                 fin.read((char*)this,sizeof(*this));
                 i++;
                  }
                  fin.close();
                  fout.close();
                  remove("checkP.dat");
                  rename("temp.dat","checkP.dat");
                  break;
        case 'G':fin.open("checkG.dat",ios::in|ios::binary);
                  i=0;
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof()){
                 if(i!=index){fout.write((char*)this,sizeof(*this));}
                 else {setArticle('P');fout.write((char*)this,sizeof(*this));}
                  fin.read((char*)this,sizeof(*this));
                    i++;
                  }
                  fin.close();
                  fout.close();
                  remove("checkG.dat");
                  rename("temp.dat","checkG.dat");
                  break;
    }

    cout<<"modify more items(y/n)"<<endl;
    cin>>ch1;}
}

void Article::removeArticle()
{   char ch='0';
     ofstream fout;
     ifstream fin;
     int index =0;
     char ch1='9';
     int i;
     fout.open("temp.dat",ios::out|ios::app|ios::binary);
     while(ch1!='n'){
    cout<<"select type of articles(L/P/G)"<<endl;
    cin>>ch;
    if(ch=='L')getAllArticles('L');
    else if(ch=='P')getAllArticles('P');
    else if(ch=='G')getAllArticles('G');
    else cout<<"entered wrong choice/halted"<<endl;
    cout<<"enter index of article you want to delete:";
    cin>>index;
    switch(ch)
    {
        case 'L':fin.open("checkL.dat",ios::in|ios::binary);
                  i=0;
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof()){
                 if(i!=index){fout.write((char*)this,sizeof(*this));}
                 fin.read((char*)this,sizeof(*this));
                 i++;
                }
                  fin.close();
                  fout.close();
                  remove("checkL.dat");
                  rename("temp.dat","checkL.dat");
                  break;
        case 'P':fin.open("checkP.dat",ios::in|ios::binary);
                  i=0;
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof()){
                 if(i!=index){fout.write((char*)this,sizeof(*this));}
                 fin.read((char*)this,sizeof(*this));
                 i++;
                  }
                  fin.close();
                  fout.close();
                  remove("checkP.dat");
                  rename("temp.dat","checkP.dat");
                  break;
        case 'G':fin.open("checkG.dat",ios::in|ios::binary);
                  i=0;
                  fin.read((char*)this,sizeof(*this));
                  while(!fin.eof()){
                 if(i!=index){fout.write((char*)this,sizeof(*this));}
                  fin.read((char*)this,sizeof(*this));
                    i++;
                  }
                  fin.close();
                  fout.close();
                  remove("checkG.dat");
                  rename("temp.dat","checkG.dat");
                  break;
    }

    cout<<"delete more items(y/n)"<<endl;
    cin>>ch1;}
     system("cls");
}

 void Article ::displayArticle()
  {
      cout<<"    "<<this->aPrice<<"          "<<this->aQuantAvail<<"      "<<this->aName<<endl;
  }

void Article::setArticle(char type)
  {

    cout<<"\nenter article name:\n";
    cin>>aName;
    cout<<"\nenter price of article:\n";
    cin>>aPrice;
    cout<<"\nenter quantity of article available:";
    cin>>aQuantAvail;

  }

  void Article::addArticle()
  {
    ofstream fout;
    setArticle('L');
    if(this->aType=='L')
    {
       fout.open("checkL.dat",ios::app|ios::binary);
       fout.write((char*)this,sizeof(*this));
       fout.close();

    }
    else if(this->aType=='P')
        {
          fout.open("checkP.dat",ios::app|ios::binary);
          fout.write((char*)this,sizeof(*this));
          fout.close();

        }
    else if(this->aType=='G')
{
    fout.open("checkG.dat",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    }
    system("cls");
  }


 void Article::getAllArticles(char aType)
  {  int i=0;
     ifstream fin;
     //system("cls");
     if(aType=='L')
      {
         fin.open("checkL.dat",ios::in|ios::binary);
     if(!fin)
       cout<<"Data File doesn't exist\n";

     else
      {
       fin.read((char*)this,sizeof(*this));
             while(!fin.eof())
             {   cout<<i<<" ";
                 this->displayArticle();
                 fin.read((char*)this,sizeof(*this));
                 i++;
             }
       }
       }
     else if(aType=='P')//retrieving all plastic items.
     {
         fin.open("checkP.dat",ios::in|ios::binary);
     if(!fin)
       cout<<"Data File doesn't exist\n";

     else
      {
       fin.read((char*)this,sizeof(*this));
             while(!fin.eof())
             {   cout<<i<<" ";
                 this->displayArticle();
                 fin.read((char*)this,sizeof(*this));
                 i++;
             }
       }
     }
     else if(aType=='G')
     {
         fin.open("checkG.dat",ios::in|ios::binary);
         if(!fin)
            cout<<"Data File doesn't exist\n";
         else
         {
             fin.read((char*)this,sizeof(*this));
             while(!fin.eof())
             {   cout<<i<<" ";
                 this->displayArticle();
                 fin.read((char*)this,sizeof(*this));
                 i++;
             }
         }
     }

  }

void Article:: purchase(Article a)
{
    char ch,ch2='y';
   int i=0;
   int j;
   ofstream fout;
   fstream file;
   int qty =0;
   fout.open("bill.dat",ios::out|ios::binary);
    while(ch2!='n')
  {
  cout<<"select items to purchase"<<endl;
  showList(a);
  cout<<"enter items from list by index"<<endl;
  cin>>ch>>i;
  cout<<"enter quantity of item selected:"<<endl;
  cin>>qty;

      switch (ch)
      {
          case 'L':file.open("checkL.dat",ios::in|ios::out|ios::binary);
                   j=0;
                   file.read((char*)this,sizeof(*this));
                   while(!file.eof())
                   {
                      if(j==i){
                        this->aQuantAvail-=qty;
                        file.seekg(i*sizeof(*this),ios::beg);
                        file.write((char*)this,sizeof(*this));
                        this->aQuantAvail = qty;
                        fout.write((char*)this,sizeof(*this));
                        break;
                      }
                      file.read((char*)this,sizeof(*this));
                      j++;
                   }
                   file.close();break;
          case 'P':file.open("checkP.dat",ios::in|ios::out|ios::binary);
                   j=0;
                   file.read((char*)this,sizeof(*this));
                   while(!file.eof())
                   {
                      if(j==i){
                        this->aQuantAvail-=qty;
                        file.seekg(i*sizeof(*this),ios::beg);
                        file.write((char*)this,sizeof(*this));
                        this->aQuantAvail = qty;
                        fout.write((char*)this,sizeof(*this));
                        break;
                      }
                      file.read((char*)this,sizeof(*this));
                      j++;
                   }
                   file.close();break;
        case 'G':file.open("checkG.dat",ios::in|ios::out|ios::binary);
                   j=0;
                   file.read((char*)this,sizeof(*this));
                   while(!file.eof())
                   {
                      if(j==i){
                        this->aQuantAvail-=qty;
                        file.seekg(i*sizeof(*this),ios::beg);
                        file.write((char*)this,sizeof(*this));
                        this->aQuantAvail = qty;
                        fout.write((char*)this,sizeof(*this));
                        break;
                      }
                      file.read((char*)this,sizeof(*this));
                      j++;
                   }
                   file.close();break;

      }
      cout<<"you want to continue purchasing:"<<endl;
      cin>>ch2;
  }
  fout.close();
system("cls");
}

void Article::showBill()
{
    ifstream fin;
    float total=0;
    float totalvat=0;
    fin.open("bill.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
        this->displayArticle();
        //cout<<this->aQuantAvail*this->aPrice<<endl;
        total= total + (this->aQuantAvail*this->aPrice);
        fin.read((char*)this,sizeof(*this));
    }
    totalvat= (total +(total*12)/100);
    cout<<" total amount :"<<total<<endl;
    cout<<" total amount with vat69 :"<<totalvat<<endl;
    fin.close();
}

void showList(Article a)
{
    //system("cls");
    cout<<"Leather items:"<<endl;
    a.getAllArticles('L');
    cout<<"plastic items:"<<endl;
    a.getAllArticles('P');
    cout<<"Glass items:"<<endl;
    a.getAllArticles('G');

}
void showSubMenu()
{
   cout<<"working fine!!\n";
}
void showSalesTaxReport()
{
  cout<<"working fine!!\n";
}


void showMainMenu()
{  Article a;
//system("cls");
    int choice=0;

    while(choice!= 7)
    { cout<<"    1. Purchase of Different Articles\n";
          cout<<"    2. Articles availability chart\n";
          cout<<"    3. Selling of Articles\n";
          cout<<"    4. Different Types of Displays\n";
          cout<<"    5. Sales Tax Payment\n";
          cout<<"    6. Store administrator\n";
          cout<<"    7. Exit Program\n";

      cout<<"\n Enter your choice:"<<endl;
      cin>>choice;
      system("cls");
      switch(choice)
      {
          case 1: a.purchase(a);
                  break;
          case 2: showList(a);
                   break;
          case 3: a.showBill();
                   break;
          case 4:  showSubMenu();
                   break;
          case 5:  showSalesTaxReport();
                   break;
          case 6:{
                   Admin A;
                   A.storeAdminMenu(a);
                   break;
                   }


          case 7: break;

          default: cout<<"invalid choice!! enter from given choices:\n";
                        break;
      }
    }}



#pragma once

 class Article
{
  private:
      char aType; // type of the article
      char aName [20];  // name of the article
      float aPrice;  // price of the article
      int aQuantAvail;// Available quantity of article
public:
  Article();
  void setArticle();

  void addArticle();

  void removeArticle();

  void updateArticle();

  void getAllArticles(char aType);
  void setArticle(char type);
  void displayArticle();
  void purchase(Article a);
  void showBill();


};
void showList(Article a);
void showSubMenu();
void showSalesTaxReport();
void showMainMenu();



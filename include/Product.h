//include guards
//#ifndef PRODUCT_H
//#define PRODUCT_H

#pragma once
#include <string>

class Product
{
private: //cannot be edited
  int proID;
  string proName;
  int proQuantity;
  double proPrice;

public: //product creation
  Product(int proID, string proName, int proQuantity, double proPrice);

  //system function
  void display();

  int getID();
  string getName();
  int getQuantity();
  double getPrice();

#endif

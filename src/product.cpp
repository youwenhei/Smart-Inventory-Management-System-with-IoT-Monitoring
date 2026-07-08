#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(
	int product_ID, 
	int product_Barcode, 
	string product_Name, 
	string product_Description, 
	string product_Category,
	int product_Quantity, 
	double product_Price,
	string product_Supplier, 
	string product_ExpiryDate, 
	string product_ManufactureDate
)

{
	this->product_ID = product_ID;
	this->product_Barcode = product_Barcode;
	this->product_Name = product_Name;
	this->product_Description = product_Description;
	this->product_Category = product_Category;
	this->product_Quantity = product_Quantity;
	this->product_Price = product_Price;
	this->product_Supplier = product_Supplier;
	this->product_ExpiryDate = product_ExpiryDate;
	this->product_ManufactureDate = product_ManufactureDate;
}

void Product::display()
{
	cout << "Plese Key In the Following Product Details:" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Product ID: " << product_ID << endl;
	cout << "Product Barcode: " << product_Barcode << endl;
	cout << "Product Name: " << product_Name << endl;
	cout << "Product Description: " << product_Description << endl;
	cout << "Product Category: " << product_Category << endl;
	cout << "Product Quantity: " << product_Quantity << endl;
	cout << "Product Price: RM" << product_Price << endl;
	cout << "Product Supplier: " << product_Supplier << endl;
	cout << "Product Expiry Date: " << product_ExpiryDate << endl;
	cout << "Product Manufacture Date: " << product_ManufactureDate << endl;
	cout << "-----------------------------------------" << endl;
}

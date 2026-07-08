#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
	newProductID = 1;
}

void Inventory::addProduct()
{
	int quantity;
	double price;
	std::string barcode, name, description, category, supplier, expiryDate, manufactureDate;

	std::cout << "\n===============================Add Product===============================\n";
	std::cout << "Enter Product Barcode: ";
	std::getline(std::cin, barcode);

	std::cout << "Enter Product Name: ";
	std::getline(std::cin, name);

	std::cout << "Enter Product Description: ";
	std::getline(std::cin, description);

	std::cout << "Enter Product Category: ";
	std::getline(std::cin, category);

	std::cout << "Enter Product Quantity: ";
	std::cin >> quantity;

	std::cout << "Enter Product Price: RM ";
	std::cin >> price;

	std::cin.ignore();

	std::cout << "Enter Product Supplier: ";
	std::getline(std::cin, supplier);

	std::cout << "Enter Product Expiry Date (YYYY-MM-DD): ";
	std::getline(std::cin, expiryDate);

	std::cout << "Enter Product Manufacture Date (YYYY-MM-DD): ";
	std::getline(std::cin, manufactureDate);

	Product newProduct(
		newProductID,
		barcode,
		name,
		description,
		category,
		quantity,
		price,
		supplier,
		expiryDate,
		manufactureDate
	);

	addProduct(newProduct);
	newProductID++;

	std::cout << "=======================================================================\n";
	std::cout << "Product is added successfully!\n";
}

void Inventory::addProduct(const Product& product) 
{
	products.push_back(product); //to add the product to the vector 
	//(products(empty)) become (products(1)) after adding the product
}

void Inventory::displayProducts() const 
{
	//take each product in the vector and display it
	for (const auto& product : products) {
		product.display();
	}
}

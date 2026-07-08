#include "Inventory.h"
#include <iostream>

void Inventory::addProduct(const Product& product) {
	products.push_back(product); //to add the product to the vector 
	//(products(empty)) become (products(1)) after adding the product
}

void Inventory::displayProducts() const {
	//take each product in the vector and display it
	for (const auto& product : products) {
		product.display();
	}
}

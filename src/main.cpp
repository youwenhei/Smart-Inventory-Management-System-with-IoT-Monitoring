#include "Inventory.h"
#include "Product.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8); // Set console output to UTF-8)

	cout << "Welcome to YouExpress Inventory Management System!" << endl;

	Inventory inventory; // Create an instance of Inventory
	
	//Sample product data
	Product product1(
		1,
		123456789,
		"I LOVE MEE",
		"With flavoring powder and seasoning oil",
		"Instant Noodles",
		50,
		4.90,
		"My Company",
		"2026-12-31",
		"2025-01-01"
	);

	inventory.addProduct(product1);
	inventory.displayProducts();

	return 0;

}

#include "Inventory.h"
#include <iostream>
#include <cctype>

Inventory::Inventory()
{
	newProductID = 1;
}

//date validation function
bool isValidDate(const std::string& date)
{
	if (date.empty())
		return true; //for specific product

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		return false;
	}

	for (int i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7) 
			continue;
		if (!isdigit(date[i])) 
			return false;

		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		if (month < 1 || month > 12)
		{
			return false;
		}

		int daysInMonth;

		switch (month)
		{
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				daysInMonth = 29; // Leap year
			else
				daysInMonth = 28;
			break;

		case 4: case 6: case 9: case 11:
			daysInMonth = 30;
			break;

		default:
			daysInMonth = 31;
		}

		if (day < 1 || day > daysInMonth)
		{
			return false;
		}
	}

	return true;
}

//barcode validation function
bool isValidBarcode(const std::string& barcode)
{
	if (barcode.length() != 9)
	{
		return false;
	}

	for (char c : barcode)
	{
		if (!isdigit(c))
		{
			return false;
		}
	}

	return true;
}

//quantity validation function
bool isValidQuantity(int quantity)
{
	return quantity >= 0;
}

//price validation function
bool isValidPrice(double price)
{
	return price >= 0.0;
}

void Inventory::addProduct()
{
	int quantity;
	double price;
	std::string barcode, name, description, category, supplier, expiryDate, manufactureDate;

	std::cout << "\n===============================Add Product===============================\n";
	do
	{
		std::cout << "Enter Product Barcode (9 digits): ";
		std::getline(std::cin, barcode);

		if (!isValidBarcode(barcode))
		{
			std::cout << "The barcode format is invalid. Please re-enter the barcode with 9 digits." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}

		else if (isBarcodeExist(barcode))
		{
			std::cout << "The barcode is already in use. Please enter a unique barcode." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}

	} while (!isValidBarcode(barcode) || isBarcodeExist(barcode));

	std::cout << "Enter Product Name: ";
	std::getline(std::cin, name);

	std::cout << "Enter Product Description: ";
	std::getline(std::cin, description);

	std::cout << "Enter Product Category: ";
	std::getline(std::cin, category);

	do
	{
		std::cout << "Enter Product Quantity: ";
		std::cin >> quantity;

		if (!isValidQuantity(quantity))
		{
			std::cout << "The quantity format is invalid. Please re-enter the quantity with a non-negative integer." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}
	} while (!isValidQuantity(quantity));

	do
	{
		std::cout << "Enter Product Price: RM ";
		std::cin >> price;

		if (!isValidPrice(price))
		{
			std::cout << "The price format is invalid. Please re-enter the price with a non-negative number." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}
	} while (!isValidPrice(price));

	std::cin.ignore();

	std::cout << "Enter Product Supplier: ";
	std::getline(std::cin, supplier);

	do
	{
		std::cout << "Enter Product Expiry Date (YYYY-MM-DD, press Enter if none): ";
		std::getline(std::cin, expiryDate);

		if (!isValidDate(expiryDate))
		{
			std::cout << "The date format is invalid. Please re-enter the date in YYYY-MM-DD format." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}
	} while (!isValidDate(expiryDate));

	do
	{
		std::cout << "Enter Product Manufacture Date (YYYY-MM-DD, press Enter if none): ";
		std::getline(std::cin, manufactureDate);

		if (!isValidDate(manufactureDate))
		{
			std::cout << "The date format is invalid. Please re-enter the date in YYYY-MM-DD format." << std::endl;
			std::cout << "Thank you for your understanding." << std::endl;
		}
	} while (!isValidDate(manufactureDate));

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

bool Inventory::isBarcodeExist(const std::string& barcode) const
{
	for (const auto& product : products)
	{
		if (product.getBarcode() == barcode)
		{
			return true;
		}
	}
	return false;
}

void Inventory::addProduct(const Product& product)
{
	products.push_back(product); //to add the product to the vector 
	//(products(empty)) become (products(1)) after adding the product
}

void Inventory::displayProducts() const
{
	if (products.empty())
	{
		std::cout << "No products available in the inventory. Please try again!" << std::endl;
		return;
	}

	for (const auto& product : products)
	{
		product.display();
	}
}

void Inventory::searchProduct() const
{
	int option;
	std::cout << "=======================================================================\n";
	std::cout << "Search Product by:\n";
	std::cout << "=======================================================================\n";
	std::cout << "1. Search by Product ID" << std::endl;
	std::cout << "2. Search by Product Barcode" << std::endl;
	std::cout << "3. Search by Product Name" << std::endl;
	std::cout << "4. Search by Product Category" << std::endl;
	std::cout << "=======================================================================\n";
	std::cout << "Please select an option: ";
	std::cin >> option;
	std::cout << "=======================================================================\n";
	std::cout << "The page is loading, please wait..." << std::endl;

	bool found = false;

	if (option == 1)
	{
		int id;

		std::cout << "Please Enter the Product ID to Search: ";
		std::cin >> id;

		for (const auto& product : products)
		{
			if (product.getID() == id)
			{
				product.display();
				found = true;
				break;
			}
		}

		if (!found)
		{
			std::cout << "Sorry! The product with ID " << id << " is not found.Please enter again." << std::endl;
		}
	}

	if (option == 2)
	{
		std::string barcode;
		std::cout << "Please Enter the Product Barcode to Search: ";
		std::cin >> barcode;
		for (const auto& product : products)
		{
			if (product.getBarcode() == barcode)
			{
				product.display();
				found = true;
				break;
			}
		}
		if (!found)
		{
			std::cout << "Sorry! The product with Barcode " << barcode << " is not found.Please enter again." << std::endl;
		}
	}

	if (option == 3)
	{
		std::string name;
		std::cout << "Please Enter the Product Name to Search: ";
		std::cin.ignore();
		std::getline(std::cin, name);
		for (const auto& product : products)
		{
			if (product.getName() == name)
			{
				product.display();
				found = true;
				break;
			}
		}
		if (!found)
		{
			std::cout << "Sorry! The product with Name " << name << " is not found.Please enter again." << std::endl;
		}
	}
	
	if (option == 4)
	{
		std::string category;
		std::cout << "Please Enter the Product Category to Search: ";
		std::cin.ignore();
		std::getline(std::cin, category);
		for (const auto& product : products)
		{
			if (product.getCategory() == category)
			{
				product.display();
				found = true;
			}
		}
		if (!found)
		{
			std::cout << "Sorry! The product with Category " << category << " is not found.Please enter again." << std::endl;
		}
	}

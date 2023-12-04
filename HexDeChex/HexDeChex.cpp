// HexDeChex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

bool IsDecimal(const std::string &value)
{
	return std::all_of(value.begin(), value.end(), ::isdigit);
}

bool IsHexadecimal(const std::string &value)
{
	return std::all_of(value.begin(), value.end(), [](char c)
		{
			return std::isdigit(c) || (std::toupper(c) >= 'A' && std::toupper(c) <= 'F');
		});
}


std::string DecimalToHex(int decimal)
{
	std::stringstream ss;
	ss << std::hex << decimal;
	return ss.str();
}


int HexToDecimal(const std::string &hex)
{
	int decimal;
	std::stringstream ss;
	ss << std::hex << hex;
	ss >> decimal;
	return decimal;
}



// MAIN below



int main() {
	std::string inputValue;

	while (true) {
		std::cout << "Enter a decimal or hexadecimal number (or type 'exit' to quit): ";
		std::getline(std::cin, inputValue);

		if (inputValue == "exit") {
			break;
		}

		std::string outputValue;

		if (IsDecimal(inputValue)) {
			int decimalValue = std::stoi(inputValue);
			outputValue = "Hex: " + DecimalToHex(decimalValue);
		}
		else if (IsHexadecimal(inputValue)) {
			int decimalValue = HexToDecimal(inputValue);
			outputValue = "Decimal: " + std::to_string(decimalValue);
		}
		else {
			outputValue = "Invalid input.";
		}

		std::cout << outputValue << std::endl;
	}

	std::cout << "Program exited. Press any key to close." << std::endl;
	std::cin.get();
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

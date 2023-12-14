// HexDeChex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

bool IsHexadecimal(const std::string& value) {
    // Check for "0x" or "0X" prefix for hexadecimal
    if (value.size() > 2 && (value[0] == '0' && (value[1] == 'x' || value[1] == 'X'))) {
        // Check the rest of the string
        return std::all_of(value.begin() + 2, value.end(), [](char c) {
            return std::isdigit(c) || (std::toupper(c) >= 'A' && std::toupper(c) <= 'F');
            });
    }
    return false;
}

std::string DecimalToHex(long long decimal) {
    std::stringstream ss;
    ss << std::hex << decimal;
    return ss.str();
}

long long HexToDecimal(const std::string& hex) {
    long long decimal;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> decimal;
    return decimal;
}

int main() {
    std::string inputValue;

    while (true) {
        std::cout << "Enter a decimal or hexadecimal number (prefix hex with '0x'; type 'exit' to quit): ";
        std::getline(std::cin, inputValue);

        if (inputValue == "exit") {
            break;
        }

        std::string outputValue;

        if (IsHexadecimal(inputValue)) {
            // Extract the actual hex part (excluding "0x" or "0X")
            std::string hexPart = inputValue.substr(2);
            long long decimalValue = HexToDecimal(hexPart);
            outputValue = "Decimal: " + std::to_string(decimalValue);
        }
        else {
            try {
                long long decimalValue = std::stoll(inputValue);
                outputValue = "Hex: 0x" + DecimalToHex(decimalValue);
            }
            catch (const std::exception& e) {
                outputValue = "Invalid input.";
            }
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

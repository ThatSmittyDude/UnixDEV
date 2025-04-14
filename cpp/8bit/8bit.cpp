#include <iostream>
#include <bitset>
#include <string>

int main(){
	std::string dec_value;
	std::cout << "Enter Decimal value: ";
	std::cin >> dec_value;

	int decimal = std::stoi(dec_value, nullptr, 10);

	std::bitset<8> binary(decimal);
	std::cout << "Binary: 0b" << binary << std::endl;

	return 0;
}

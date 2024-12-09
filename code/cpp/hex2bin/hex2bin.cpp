#include <iostream>
#include <bitset>
#include <string>

int main(){
	std::string hex_value;
	std::cout << "Enter your hexadecimal value: ";
	std::cin >> hex_value;

	int dec_value = std::stoi(hex_value, nullptr, 8);

	std::bitset<8> binary(dec_value);
	std::cout << "Binary: " << binary << std::endl;

	return 0;
}

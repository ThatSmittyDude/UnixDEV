
//UNIX Timestamp: 1720152945

#include <iostream>
#include <bitset>
#include <string>

int main(){
	std::string hex_value;
	std::cout <<"\n" << "Enter hex value: ";
	std::cin >> hex_value;

	int dec_value = std::stoi(hex_value, nullptr, 16);

	std::cout << "Decimal: " << dec_value << "\n" << std::endl;
	return 0;
}

#include <iostream>
#include <string>

int main(){
	std::string bin;

	std::cout << "Enter your binary number: ";
	std::cin >> bin;

	int dec = std::stoi(bin, nullptr, 2);

	std::cout << "Decimal: " << dec << std::endl;
	return 0;
}

#include <iostream>
#include <iomanip>

int main(){
	int dec_value;

	std::cout << "Enter your decimal number: ";
	std::cin >> dec_value;

	std::cout << "hex: 0x" << std::hex << std::uppercase << dec_value << std::endl;
	return 0;
}

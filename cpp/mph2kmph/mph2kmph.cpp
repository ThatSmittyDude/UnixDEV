#include <iostream>

int main(){
	double kmph, mph;

	std::cout << "\n" << "Enter mph value: ";
	std::cin >> mph;

	kmph = mph * 1.612903;

	std::cout << "Km/h: " << kmph << "\n" << std::endl;
	return 0;
}

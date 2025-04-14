#include <iostream>

int main(){
	double fahrenheit, celsius;

	std::cout << "\n" << "Enter fahrenheit value: ";
	std::cin >> fahrenheit;

	celsius = (fahrenheit - 32) / 1.8;

	std::cout << "Celsius: " << celsius << "\n" << std::endl;
	return 0;
}

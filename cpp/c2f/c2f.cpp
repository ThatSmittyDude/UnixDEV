#include <iostream>

int main(){
	double celsius, fahrenheit;

	std::cout << "\n" << "Enter Celsius temperature: ";
	std::cin >> celsius;

	fahrenheit = ( celsius * 9 /5 ) + 32 ;

	std::cout << "Fahrenheit: " << fahrenheit << "\n" << std::endl;
	return 0;
}

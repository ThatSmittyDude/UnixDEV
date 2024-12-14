#include <iostream>

int main(){
	double kmph, mph;

	std::cout << "\n" << "Enter Km/h value: ";
	std::cin >> kmph;

	mph = kmph * 0.621371;

	std::cout << "Mph: " << mph << "\n" << std::endl;
	return 0;
}

#include <iostream>

int main(){
	float hr, min;

	std::cout << "---- ---- ---- ----\n";
	std::cout << "hr2min\n";
	std::cout << "---- ---- ---- ----\n";
	std::cout << "\n";

	std::cout << "Enter hours: ";
	std::cin >> hr;

	min = hr * 60;

	std::cout << "Minutes: " << min << std::endl;
	return 0;
}

#include <iostream>
int main(){
	std::cout << "\n";
	std::cout << "10th\n";
	std::cout << "---- ---- ---- ----\n";
	std::cout << "\n";
	std::cout << "Enter minutes to convert to hours: ";
	double minutes, hours;
	std::cin >> minutes;

	hours = minutes / 60;

	std::cout << "Hours:	" << hours << "\n";
	return 0;
	}

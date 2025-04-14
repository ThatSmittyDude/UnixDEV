#include <iostream>

float pressure_hpa, pressure_hg;

void get_hpa(){
	std::cout << "\n---- ---- ---- ----\n";
	std::cout << "hpa2hg\n";
	std::cout << "---- ---- ---- ----\n\n";
	std::cout << "Enter pressure in hPa: ";
	std::cin >> pressure_hpa;
}

void find_inHg(){
	pressure_hg = pressure_hpa * 0.02953;
	std::cout << "\nBarometric pressure: " << pressure_hg << " Hg\n";
}

int main(){
	get_hpa();
	find_inHg();
	return 0;
}

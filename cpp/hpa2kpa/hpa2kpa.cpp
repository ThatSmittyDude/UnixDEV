#include <iostream>

float hpa, kpa;
float conversion = 0.1;

void get_hpa(){
	std::cout << "\n---- ---- ---- ----\n";
	std::cout << "hpa2kpa\n";
	std::cout << "---- ---- ---- ----\n\n";
	std::cout << "Enter pressure in hpa: ";
	std::cin >> hpa;
}

void find_kpa(){
	kpa = hpa * conversion;
	std::cout << "kpa: " << kpa << "\n";
}

int main(){
	get_hpa();
	find_kpa();
	return 0;
}

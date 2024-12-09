#include <iostream>
int main(){
	int opt;
	float i, r, v;

	//v = i * r;	1 find voltage
	//i = v / r;	2 find amperage
	//r = v / i;	3 find resistance

	std::cout << "Enter operation: \n";
	std::cout << "	1. Voltage\n";
	std::cout << "	2. Amperage\n";
	std::cout << "	3. Resistance\n";
	std::cout << "Choose 1-3\n";
	std::cin >> opt;

	if(opt == 1){
		std::cout << "Enter Amperage: ";
		std::cin >> i;
		std::cout << "Enter Resistance: ";
		std::cin >> r;
		v = i * r;
		std::cout << "Volatage: " << v << std::endl;
		return 0;
	}if(opt == 2){
		std::cout << "Enter Voltage: ";
		std::cin >> v;
		std::cout << "Enter Resistance: ";
		std::cin >> r;
		i = v / r;
		std::cout << "Amperage: " << i << std::endl;
		return 0;
	}if(opt == 3){
		std::cout << "Enter Voltage: ";
		std::cin >> v;
		std::cout << "Enter Amperage: ";
		std::cin >> i;
		r = v / i;
		std::cout << "Resistance: " << r << std::endl;
		return 0;
	}else{
		std::cout << "Invalid operation\n";
		return 0;
	}
}	
		

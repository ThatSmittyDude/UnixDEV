#include <iostream>
int main(){
	double w, v, a;
	int choice;
	std::cout << "\n";
	std::cout << "==== ==== ==== ====\n";
	std::cout << "Watts\n";
	std::cout << "==== ==== ==== ====\n";
	std::cout << "\n";
	std::cout << "Solve for:\n";
	std::cout << "	1. Watts\n";
	std::cout << "	2. Volts\n";
	std::cout << "	3. Amps\n";
	std::cout << "\n";
	std::cout << "Choose (1-3)\n";
	std::cin >> choice;

	while(choice == 1){
		std::cout << "Voltage: ";
		std::cin >> v;
		std::cout << "Amperage: ";
		std::cin >> a;
		w = v * a;
		std::cout << "Watts: " << w << std::endl;
		return 0;
	}while(choice == 2){
		std::cout << "Wattage: ";
		std::cin >> w;
		std::cout << "Amperage: ";
		std::cin >> a;
		v = w / a;
		std::cout << "Voltage: " << v << std::endl;
		return 0;
	}while(choice == 3){
		std::cout << "Wattage: ";
		std::cin >> w;
		std::cout << "Voltage: ";
		std::cin >> v;
		a = w / v;
		std::cout << "Amperage: " << a << std::endl;
		return 0;
	}
}

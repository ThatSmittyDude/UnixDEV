#include <iostream>
int main(){
	double f, m, a;
	int choice;

	std::cout << "fma\n";
	std::cout << "====_====_====_====\n";
	std::cout << "1. Force\n";
	std::cout << "2. Mass\n";
	std::cout << "3. Acceleration\n";
	std::cout << "\n";
	std::cout << "Solve for: (1-3)\n";
	std::cin >> choice;

	while(choice == 1){
		std::cout << "Mass: ";
		std::cin >> m;
		std::cout << "Acceleration: ";
		std::cin >> a;
		f = m * a;
		std::cout << "Force: " << f << std::endl;
		return 0;
	}while(choice == 2){
		std::cout << "Force: ";
		std::cin >> f;
		std::cout << "Acceleration: ";
		std::cin >> a;
		m = f / a;
		std::cout << "Mass: " << m << std::endl;
		return 0;
	}while(choice == 3){
		std::cout << "Force: ";
		std::cin >> f;
		std::cout << "Mass: ";
		std::cin >> m;
		a = f / m;
		std::cout << "Acceleration: " << a << std::endl;
		return 0;
	}
}

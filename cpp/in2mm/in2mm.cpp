#include <iostream>

float conversion, inches, millimeters;
int choice;

void get_operation(){
	std::cout << "\n---- ---- ---- ----\n";
	std::cout << "in2mm\n";
	std::cout << "---- ---- ---- ----\n";
	std::cout << "Choose operation: \n";
	std::cout << "1.	inches to millimeters\n";
	std::cout << "2.	millimeters to inches\n";
	std::cout << "Operation: ";
	std::cin >> choice;
}

void get_inches(){
	std::cout << "Enter inches: ";
	std::cin >> inches;
}

void get_millimeters(){
	std::cout << "Enter millimeters: ";
	std::cin >> millimeters;
}

void conversion_inches_per_millimeter(){
	conversion = 0.03937008;		// inches per millimeter
}

void conversion_millimeters_per_inch(){
	conversion = 25.4;			// millimeteres per inch	
}

void find_inches(){
	inches = millimeters * conversion;
	std::cout << "inches: " << inches << std::endl;
}

void find_millimeters(){
	millimeters = inches * conversion;
	std::cout << "millimeters: " << millimeters << std::endl;
}

int main(){
	get_operation();
	if(choice == 1){
		get_inches();
		conversion_millimeters_per_inch();
		find_millimeters();
	
	}else if(choice == 2){
		get_millimeters();
		conversion_inches_per_millimeter();
		find_inches();
	}else{
		std::cout << "	**** Invalid operation ****";
	}
	return 0;
}

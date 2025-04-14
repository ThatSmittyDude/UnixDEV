#include <iostream>

int choice;
float voltage, amperage, resistance;

void findVoltage(){
	voltage = amperage * resistance;
	std::cout << "Voltage: " << voltage << std::endl;
	}

void findAmperage(){
	amperage = voltage / resistance;
	std::cout << "Amperage: " << amperage << std::endl;
	}

void findResistance(){
	resistance = voltage / amperage;
	std::cout << "Resistance: " << resistance << std::endl;
	}

void getVoltage(){
	std::cout << "Enter voltage: ";
	std::cin >> voltage;
	}

void getAmperage(){
	std::cout << "Enter amperage: ";
	std::cin >> amperage;
	}

void getResistance(){
	std::cout << "Enter resistance: ";
	std::cin >> resistance;
	}

void getChoice(){
	std::cout << "\n";
	std::cout << "---- ---- ---- ----\n";
	std::cout << "ohms\n";
	std::cout << "---- ---- ---- ----\n";
	std::cout << "\n";
	std::cout << "Enter operation: \n";
	std::cout << "	1. Find voltage\n";
	std::cout << "	2. Find amperage\n";
	std::cout << "	3. Find resistance\n";
	std::cout << "\n";
	std::cout << "Operation (1-3): ";
	std::cin >> choice;
	}

void zeroError(){
	std::cout << "\n**** Divide by zero error ****\n\n";
}

void choiceError(){
	std::cout << "\n**** Invalid choice ****\n\n";
}

int main(){
	getChoice();
	if (choice == 1){
		getAmperage();
		getResistance();
		findVoltage();
		return 0;
	}else if(choice == 2){
		getVoltage();
		getResistance();
			if (resistance == 0){
				//std::cout << "Divide by zero error\n";
				zeroError();
				return 0;
			}else{
				findAmperage();
				return 0;
				}
	}else if(choice == 3){
		getVoltage();
		getAmperage();
			if (amperage == 0){
				//std::cout << "Divide by zero error\n";
				zeroError();
				return 0;
			}else{
				findResistance();
				return 0;
				}
	}else{
		//std::cout << "Invalid choice. Please choose 1, 2, or 3\n";
		choiceError();
	}
		return 0;
}

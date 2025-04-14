#include <iostream>

using namespace std;

float watts, voltage, amperage;
int choice;

// watts = voltage * amperage
// voltage = watts / amperage
// amperage = watts / voltage

void getWatts(){
	cout << "Enter watts: ";
	cin >> watts;
	}

void getVoltage(){
	cout << "Enter voltage: ";
	cin >> voltage;
	}

void getAmperage(){
	cout << "Enter amperage: ";
	cin >> amperage;
	}

void findWatts(){
	watts = voltage * amperage;
	cout << "Watts: " << watts << endl;
	}

void findVoltage(){
	if (amperage == 0){
		cerr << "\n****Divide by zero error****\n\n";
		return;
		}else{
			voltage = watts / amperage;
			cout << "Voltage: " << voltage << endl;
			}
	}

void findAmperage(){
	if (voltage == 0){
		cerr << "\n****Divide by zero error****\n\n";
		return;
		}else{
			amperage = watts / voltage;
			cout << "Amperage: " << amperage << endl;
			}
	}

void getChoice(){
	cout << "\n";
	cout << "---- ---- ---- ----\n";
	cout << "watts\n";
	cout << "---- ---- ---- ----\n";
	cout << "\n";
	cout << "Enter operation: \n";
	cout << "	1. Watts\n";
	cout << "	2. Voltage\n";
	cout << "	3. Amperage\n";
	cout << "Choose (1-3):";
	cin >> choice;
	}

int main(){
	getChoice();

	if(choice == 1){
		getVoltage();
		getAmperage();
		findWatts();

	}else if(choice == 2){
		getWatts();
		getAmperage();
		if(amperage == 0){
			cout << "Divide by zero error\n";
			return 0;
		}else{
			findVoltage();
			return 0;
		}
	}else if(choice == 3){
		getWatts();
		getVoltage();
		if(voltage == 0){
			cout << "Divide by zero error\n";
		}else{

			findAmperage();
		}

	}else{
		cout << "\n****Invalid operation. Choose 1, 2, or 3****\n\n";
		return 0;
		}

	return 0;
}

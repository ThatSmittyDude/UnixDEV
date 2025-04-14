#include <iostream>

using namespace std;

float force, mass, acceleration;
int choice;

void get_choice(){
	cout << "\n";
	cout << "---- ---- ---- ----\n";
	cout << "fma\n";
	cout << "---- ---- ---- ----\n";
	cout << "\n";
	cout << "Select operation: \n";
	cout << "	1. Force\n";
	cout << "	2. Mass\n";
	cout << "	3. Acceleration\n";
	cout << "Choose (1-3): ";
	cin >> choice;
}

void get_force(){
	cout << "Enter force: ";
	cin >> force;
}

void get_mass(){
	cout << "Enter mass: ";
	cin >> mass;
}

void get_acceleration(){
	cout << "Enter acceleration: ";
	cin >> acceleration;
}

void find_force(){
	force = mass * acceleration;
	cout << "Force: " << force << endl;
}

void find_mass(){
	if (acceleration == 0){
		cout << "	****Divide by zero error****\n\n";
	}else{
		mass = force / acceleration;
		cout << "Mass: " << mass << endl;
	}
}

void find_acceleration(){
	if (mass == 0){
		cout << "	****Divide by zero error****\n\n";
	}else{
		acceleration = force / mass;
		cout << "Acceleration: " << acceleration << endl;
	}
}

int main(){
	get_choice();
	if (choice == 1){
		get_mass();
		get_acceleration();
		find_force();
	}else if (choice == 2){
		get_force();
		get_acceleration();
		find_mass();
	}else if (choice == 3){
		get_force();
		get_mass();
		find_acceleration();
	}else{
		cout << "	****Invalid operation****\n\n";
	}
return 0;
}

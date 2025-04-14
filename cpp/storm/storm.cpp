#include <iostream>
#include <cmath>
float elevation_feet, elevation_meters, pressure, normal_temperature_pressure, kpa, inHg;

void get_elevation_feet(){
	std::cout << "\n---- ---- ---- ----\n";
	std::cout << "storm\n";
	std::cout << "---- ---- ---- ----\n";
	std::cout << "Enter elevation in feet: ";
	std::cin >> elevation_feet;
}

void get_normal_temperature_pressure(){
	normal_temperature_pressure = 101325;
}

void find_elevation_meters(){
	elevation_meters = elevation_feet * 0.3048;
}


void find_pressure(){
	pressure = (normal_temperature_pressure * pow((1 - 2.25577 * pow(10, -5) * elevation_meters),  5.25588));
}

void find_kpa(){
	kpa = pressure * 0.001;
}

void find_inHg(){
	inHg = kpa * 0.2953;
}

int main(){
	get_elevation_feet();
	find_elevation_meters();
	get_normal_temperature_pressure();
	find_pressure();
	find_kpa();
	std::cout << kpa << " kPa\n";
	find_inHg();
	std::cout << inHg << " inHg\n\n";
	return 0;
}


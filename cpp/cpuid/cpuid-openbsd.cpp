#include <iostream>
#include <fstream>
#include <string>

void printCPUInfo(){
	std::ifstream cpuinfo("/var/run/dmesg.boot");
	if (!cpuinfo.is_open()){
		std::cerr << "Error: Could not open /var/run/dmesg.boot" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(cpuinfo, line)){
		if	(line.find("cpu0") != std::string::npos		||
			 line.find("Origin") != std::string::npos	||
			 line.find("Features") != std::string::npos	||
			 line.find("Features2") != std::string::npos){
			 std::cout << line << "\n" << std::endl;
			 }
		}
		cpuinfo.close();
	}

	int main(){
		std::cout << "\n";
		std::cout << "---- ---- ---- ----\n";
		std::cout << "cpuid\n";
		std::cout << "---- ---- ---- ----\n";
		std::cout << "\n";
		printCPUInfo();
		std::cout << "\n";
		return 0;
}

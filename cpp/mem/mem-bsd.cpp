#include <iostream>
#include <fstream>
#include <string>
void printMEMInfo(){
	std::ifstream meminfo("/var/run/dmesg.boot");
	if (!meminfo.is_open()){
		std::cerr << "Error: Could not open /var/run/dmesg.boot" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(meminfo, line)){
		if	(line.find("memory") != std::string::npos){
			 std::cout << line << "\n" << std::endl;
			 }
		}
		meminfo.close();
	}

	int main(){
		std::cout << "\n";
		std::cout << "---- ---- ---- ----\n";
		std::cout << "mem\n";
		std::cout << "---- ---- ---- ----\n";
		std::cout << "\n";
		printMEMInfo();
		std::cout << "\n";
		return 0;
}


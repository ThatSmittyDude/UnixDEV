#include <iostream>
#include <fstream>
#include <string>

void printMEMinfo(){
	std::ifstream meminfo("/proc/meminfo");
	if (!meminfo.is_open()){
		std::cerr << "Error could not open /proc/meminfo" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(meminfo, line)){
		if 	(line.find("MemTotal") != std::string::npos ||
			 line.find("MemFree") != std::string::npos ||
			 line.find("KernelStack") != std::string::npos){
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
	printMEMinfo();
	std::cout << "\n";
	return 0;
}

#include <iostream>
#include <fstream>
#include <string>

void printCPUInfo(){
	std::ifstream cpuinfo("/proc/cpuinfo");
	if (!cpuinfo.is_open()){
		std::cerr << "Error: Could not open /proc/cpuinfo" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(cpuinfo, line)){
		if  	(line.find("processor") != std::string::npos ||
			 line.find("cache size") != std::string::npos ||
			 line.find("model name") != std::string::npos ||
			 line.find("vendor_id") != std::string::npos ||
			 line.find("microcode") != std::string::npos  ||
			 line.find("flags") != std::string::npos ||
			 line.find("address sizes") != std::string::npos) {
			 std::cout << line << "\n" <<std::endl;
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

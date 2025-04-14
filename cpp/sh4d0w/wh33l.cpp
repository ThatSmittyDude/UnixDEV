#include <iostream>
#include <fstream>
#include <string>

void printWheelinfo(){
	std::ifstream wheelinfo("/etc/group");
	if (!wheelinfo.is_open()){
		std::cerr << "Error: Could not open /etc/group" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(wheelinfo, line)){
		if	(line.find("wheel") != std::string::npos){
				std::cout << line << "\n" << std::endl;
			}
		}
		wheelinfo.close();
	}

	int main(){
		printWheelinfo();
		return 0;
}

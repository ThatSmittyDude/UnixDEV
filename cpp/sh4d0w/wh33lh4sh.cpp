#include <iostream>
#include <fstream>
#include <string>

std::string wheel;

void printHashinfo(){
        std::ifstream hashinfo("/etc/shadow");
        if (!hashinfo.is_open()){
                std::cerr << "Error: Could not open /etc/shadow" << std::endl;
                return;
        }

        std::string line;
        while (std::getline(hashinfo, line)){
                if      (line.find("root") != std::string::npos ||
			 line.find(wheel) != std::string::npos){
                          std::cout << line << "\n" <<std::endl;
                        }
                }

                hashinfo.close();
        }

        int main(){
		std::cout << "Wheel user:" << std::endl;
                std::cin >> wheel;
		printHashinfo();
                return 0;
}


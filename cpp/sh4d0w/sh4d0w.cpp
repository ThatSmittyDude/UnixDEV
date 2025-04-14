#include <iostream>
#include <fstream>
#include <string>

void printHashinfo(){
        std::ifstream hashinfo("/etc/shadow");
        if (!hashinfo.is_open()){
                std::cerr << "Error: Could not open /etc/shadow" << std::endl;
                return;
        }

        std::string line;
        while (std::getline(hashinfo, line)){
                if      (line.find("root") != std::string::npos){
                          std::cout << line << "\n" <<std::endl;
                        }
                }

                hashinfo.close();
        }

        int main(){
                printHashinfo();
                return 0;
}


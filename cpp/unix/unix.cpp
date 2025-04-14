#include <iostream>
#include <ctime>

int main(){
	std::time_t result = std::time(nullptr);
	std::cout << "\n" << "UNIX Timestamp: " << result << "\n" << std::endl;
	return 0;
}


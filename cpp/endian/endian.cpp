#include <iostream>
int main(){
	char arr[4];

	std::cout << "\n";
	std::cout << "Endian\n";
	std::cout << "---- ---- ---- ----\n";
	std::cout << "\n";
	std::cout << "Enter 4 bits \n";
	std::cout << "1st: ";
	std::cin >> arr[0];

	std::cout << "2nd: ";
	std::cin >> arr[1];

	std::cout << "3rd: ";
	std::cin >> arr[2];

	std::cout << "4th: ";
	std::cin >> arr[3];

	std::cout << "Returned value: " << arr[3] << arr[2] << arr[1] << arr[0] << std::endl;
	return 0;
}

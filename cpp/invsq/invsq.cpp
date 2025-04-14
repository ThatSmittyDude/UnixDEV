#include <iostream>
#include <cmath>
int main(){
	double unit, invsq, sq;

	std::cout << "What is the distance?: ";
	std::cin >> unit;

	sq = 2;
	invsq = 1 / pow(unit, sq);

	std::cout << "Inverse square: " << invsq << "\n";
	return 0;
}

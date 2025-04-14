#include <iostream>
#include <cmath>

float result, num1, num2, only, pwr;
int func;

void get_function(){
	std::cout << "---- ---- ---- ----\n";
	std::cout << "calc\n";
	std::cout << "---- ---- ---- ----\n";
	std::cout << "\n";
	std::cout << " 1.Addition\n";
	std::cout << " 2.Subtraction\n";
	std::cout << " 3.Multiplication\n";
	std::cout << " 4.Division\n";
	std::cout << " 5.Exponents\n";
	std::cout << " 6.Square Root\n";
	std::cout << "\n";
	std::cout << "---- ---- ---- ----\n";
	std::cout << "Choose a function: ";
	std::cin >> func;
	std::cout << "\n";
	}

void get_both_inputs(){
	std::cout << "First number: 	";
	std::cin >> num1;
	std::cout << "Second number: 	";
	std::cin >> num2;
	std::cout << "\n";
	}

void get_only_input(){
	std::cout << "Enter number: 	";
	std::cin >> only;
	std::cout << "\n\n";
	}		

void pwr_of(){
	std::cout << "Enter power:	";
	std::cin >> pwr;
	std::cout << "\n\n";
	}

void addition(){
	result = num1 + num2;
	std::cout << "Result:		" << result;
	std::cout << "\n\n";
	}

void subtraction(){
	result = num1 - num2;
	std::cout << "Result:		"  << result;
	std::cout << "\n\n";
	}

void multiplication(){
	result = num1 * num2;
	std::cout << "Result:		"  << result;
	std::cout << "\n\n";
	}	

void division(){
	result = num1 / num2;
	std::cout << "Result:		"  << result;
	std::cout << "\n\n";
	}
		
void powers(){
	result = pow(only, pwr); 
	std::cout << "Result:		"  << result;
	std::cout << "\n\n";
	}

void square_root(){
	result = sqrt(only);
	std::cout << "Result:		"  << result;
	std::cout << "\n\n";
	}

int main(){
	get_function();
	while(func == 1 || func == 2 || func == 3 || func == 4){
		get_both_inputs();
		if(func == 1){
			addition();
			break;
		}else if(func == 2){
			subtraction();
			break;
		}else if(func == 3){
			multiplication();
			break;
		}else if(func == 4){
			if(num2 == 0){
				std::cout << "Divide by 0 error\n";
				break;
			}else{
				division();
				break;
				}
		}
	}
	while(func == 5 || func == 6){
		get_only_input();
		if(func == 5){
			pwr_of();
			powers();
			break;
		}else if(func == 6){
			if (only < 0){
				std::cout << "Imaginary number error\n";
				break;
			}else{
				square_root();
				break;
				}
			}
	}
	return 0;
}
		
	

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int octal, bit_0, bit_1, bit_2, bit_3, bit_4, bit_5, bit_6, decimal;

// Functions to calculate the value for each bit of the octal number
void find_bit_0(int octal_bit_0){
    bit_0  = (octal_bit_0 * pow(8, 0));
}

void find_bit_1(int octal_bit_1){
    bit_1 = (octal_bit_1 * pow(8, 1));
}

void find_bit_2(int octal_bit_2){
    bit_2 = (octal_bit_2 * pow(8, 2));
}

void find_bit_3(int octal_bit_3){
    bit_3 = (octal_bit_3 * pow(8, 3));
}

void find_bit_4(int octal_bit_4){
    bit_4 = (octal_bit_4 * pow(8, 4));
}

void find_bit_5(int octal_bit_5){
    bit_5 = (octal_bit_5 * pow(8, 5));
}

void find_bit_6(int octal_bit_6){
    bit_6 = (octal_bit_6 * pow(8, 6));
}

// Function to sum the bits and print the decimal value
void find_decimal(){
    decimal = bit_0 + bit_1 + bit_2 + bit_3 + bit_4 + bit_5 + bit_6;
    cout << "Decimal: " << decimal << "\n" << endl;
}

// Function to get the octal number from user input and process each digit
void get_octal(){
    cout << "\n---- ---- ---- ----\n";
    cout << "oct2dec\n";
    cout << "---- ---- ---- ----\n\n";
    cout << "Enter octal number: "; 
    cin >> octal;

    // Breaking the octal number into individual digits (max 7 digits for octal)
    int digits[7];
    for (int i = 0; i < 7; ++i) {
        digits[i] = octal % 10;  // Extract the rightmost digit
        octal /= 10;             // Remove the rightmost digit
    }

    // Now, find the decimal equivalent by calculating each bit
    find_bit_0(digits[0]);
    find_bit_1(digits[1]);
    find_bit_2(digits[2]);
    find_bit_3(digits[3]);
    find_bit_4(digits[4]);
    find_bit_5(digits[5]);
    find_bit_6(digits[6]);

    find_decimal();
}

int main(){
    get_octal();
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to convert a decimal number to octal
void decimal_to_octal(int decimal) {
    // Create a vector to store the octal digits
    vector<int> octal_digits;

    // Divide the decimal number by 8 and store the remainder
    while (decimal > 0) {
        octal_digits.push_back(decimal % 8);
        decimal /= 8;
    }

    // Output the octal number
    cout << "Octal: ";
    // Print the digits in reverse order since we collected them from the least significant to most significant
    for (int i = octal_digits.size() - 1; i >= 0; --i) {
        cout << octal_digits[i];
    }
    cout << "\n" << endl;
}

int main() {
    int decimal;

    cout << "\n---- ---- ---- ----\n";
    cout << "dec2oct\n";
    cout << "---- ---- ---- ----\n\n";
    cout << "Enter decimal number: "; 
    cin >> decimal;

    decimal_to_octal(decimal);

    return 0;
}

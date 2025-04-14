#include <stdio.h>
#include <string.h>

// Function to convert a single byte to its binary representation
void byteToBinary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        // Print each bit of the byte
        putchar((byte & (1 << i)) ? '1' : '0');
    }
}

void textToBinary(const char *text) {
    while (*text) {
        // Convert each character to binary and print
        byteToBinary((unsigned char)*text);
        putchar(' '); // Space between binary values
        text++;
    }
    putchar('\n'); // Newline after printing all binary values
}

int main() {
    char input[1024]; // Buffer to hold the input text

    // Prompt the user for input
    printf("Enter text: ");
    
    // Read input from the user and remove newline character if present
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
        // Convert and print the text in binary format
        textToBinary(input);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}

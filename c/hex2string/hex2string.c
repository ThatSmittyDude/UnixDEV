#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to convert a single hex charactor to its decimal equivalent
int hexCharToDecimal(char hex){
	if (hex >= '0' && hex <= '9')
		return hex - '0';
	else if (hex >= 'A' && hex <= 'F')
		return hex - 'A' + 10;
	else if (hex >= 'a' && hex <= 'f')
		return hex - 'a' + 10;
	else
		return -1; //invalid hex charater
}

//function to conert a hex string (eg., "41") to its corrosponding charater "A"
char hexToChar(const char *hexStr) {
	int high = hexCharToDecimal(hexStr[0]);
	int low = hexCharToDecimal(hexStr[1]);
	return (high << 4) | low;
}

int main(int argc, char *argv[]) {
	if (argc !=3){
		printf("Usage: %s <inputfile> <outputfile>\n", argv[0]);
		return 1;
	}

	FILE *inputFile = fopen(argv[1], "r");
	if (inputFile == NULL) {
		perror("Error opening input file");
		return 1;
	}

	FILE *outputFile = fopen(argv[2], "w");
	if (outputFile == NULL) {
		perror("Error opening output file");
		fclose(inputFile);
		return 1;
	}

	char hexStr[3];
	hexStr[2] = '\0'; // Null terminate the string

	while (fscanf(inputFile, "%2s", hexStr) == 1){
		char ch = hexToChar(hexStr);
		fputc(ch, outputFile);
	}

	fclose(inputFile);
	fclose(outputFile);

	printf("Hex to plaintext conversion completed.\n");

	return 0;
}

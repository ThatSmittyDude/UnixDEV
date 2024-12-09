#include <stdio.h>
#include <string.h>

void textToHex(const char *text){
	//iterate over each character of the input text
	while (*text){
	//print the hexadecimal representation of the character
	printf("%02X ", (unsigned char)*text);
	text++;
	}
	printf("\n"); //newline after entire conversion
}

int main(){
	char input[1024]; //buffer to hold the input text

	//prompt the user for input
	printf("Enter text: ");
	if (fgets(input, sizeof(input), stdin) != NULL) {
	// remove new line chracter if present
	input[strcspn(input, "\n")] = '\0';
	//convert and print the text in hexadecimal format
	textToHex(input);
	}else{
		printf("Error reading input \n");
	}
	return 0;
}

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(){
	const char* filename = "output.txt";
	int fd = syscall(SYS_open, filename, O_WRONLY | O_CREAT | O_APPEND, 0644);	// Open file in append mode

	if (fd == -1){
		std::cerr << "	****Error opening file ****\n";
		return 1;
	}

	int value = 42;
	char buffer[32];
	int len = snprintf(buffer, sizeof(buffer), "%d\n", value);	// Convert to string with newline

	syscall(SYS_write, fd , buffer, len);	// Write to file
	syscall(SYS_close, fd);			// Close file

	std::cout << "Value written to file\n";
	return 0;
}

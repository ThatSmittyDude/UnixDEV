#include <iostream>
#include <ctime>
#include <sys/syscall.h>
#include <unistd.h>

int main(){
	struct timespec ts;
	syscall(SYS_clock_gettime, CLOCK_REALTIME, &ts);

	struct tm timeinfo;
	localtime_r(&ts.tv_sec, &timeinfo);

	char buffer[100];
	strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Z %Y", &timeinfo);

	std::cout << buffer << std::endl;

	return 0;
}

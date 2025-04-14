#include <stdio.h>
#include <time.h>

int main(){
	time_t result = time(NULL);
	printf("\nUnix Timestamp: %lld\n\n", result);
	return 0;
}

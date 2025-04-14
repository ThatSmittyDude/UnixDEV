#include <stdio.h>

int main() {
    int opt;
    float i, r, v;

    // Display operation options
    printf("Enter operation: \n");
    printf("    1. Voltage\n");
    printf("    2. Amperage\n");
    printf("    3. Resistance\n");
    printf("Choose 1-3\n");
    scanf("%d", &opt);

    if (opt == 1) {
        printf("Enter Amperage: ");
        scanf("%f", &i);
        printf("Enter Resistance: ");
        scanf("%f", &r);
        v = i * r;
        printf("Voltage: %.2f\n", v);
    } else if (opt == 2) {
        printf("Enter Voltage: ");
        scanf("%f", &v);
        printf("Enter Resistance: ");
        scanf("%f", &r);
	if(r > 0){
        	i = v / r;
        	printf("Amperage: %.2f\n", i);
	}else{
		printf("Divide by zero error\n");
		}
    } else if (opt == 3) {
        printf("Enter Voltage: ");
        scanf("%f", &v);
        printf("Enter Amperage: ");
        scanf("%f", &i);
        if(i > 0){
		r = v / i;
        	printf("Resistance: %.2f\n", r);
	}else{
		printf("Divide by zero error\n");
		}
    } else {
        printf("Invalid operation\n");
    }

    return 0;
}

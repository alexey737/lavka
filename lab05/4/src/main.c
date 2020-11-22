#include <stdio.h>
int main() {
	int num = 28;
	int num1 = num;
	int i;
	for (i = (num-1); i > 0; i--) {
		if (num % i == 0) {
			num1 = num1 - i;
			if (num1 <= 0) {
				if (i == 1) {
					printf("Число досконале");
					break;
				}

				else {
					printf("Число недосконале");
					break;
					
				}

			}

		}
	}
	return 0;
}

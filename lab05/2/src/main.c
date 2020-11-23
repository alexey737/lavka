#include <stdio.h>
int main() {
	int x = 97;
	int res;
	int del = 1;
		while (del <= x) {
		del++;
		res = x % del;
		if (res == 0) {
			if (x == del) {
				printf("Число просте");
				break;
			}
			else if (x != del) {
				printf("Число складне");
				break;
			}
		}
		else {
			//error
		}
	}
	
	 /*do {
	    res = x % del;
		del++;
			if (res == 0) {
				if (x == del) {
						printf("Число просте");
						break;

				}
				else if (x != del) {
				printf("Число складне");
				break;
				}
			}
			else {
				//error
			}
	} while (del <= x);*/
	
	/*for (del = 1; del++; del <= x){
	    res = x % del;
		if (res == 0) {
			if (x == del) {
				printf("Число просте");
				break;
			}
			else if (x != del) {
				printf("Число складне");
				break;
			}
		}
		else {
			//error
		}


	}*/

	return 0;
}

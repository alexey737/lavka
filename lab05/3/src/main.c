#include <stdio.h>
int main() {

	int num = 153054;
	int i;
	int first_part, second_part;

	for (i = 0; i <= num; i++) {
		first_part = ((num - (num % 100000)) / 100000) + (((num - (num % 10000)) / 10000) % 10) + (((num - (num % 1000)) / 1000) % 10);
		second_part = (((num % 1000) - (num % 100)) / 100) + (((num % 100) - (num % 10)) / 10) + (num % 10);
		if (first_part == second_part) {
			printf("Щасливий квиток");
			break;
		}
		else {
			printf("Нещасливий квиток");
			break;
		}

	}
      /* while (i <= num){
       i++;
       first_part = ((num - (num % 100000)) / 100000) + (((num - (num % 10000)) / 10000) % 10) + (((num - (num % 1000)) / 1000) % 10);
		second_part = (((num % 1000) - (num % 100)) / 100) + (((num % 100) - (num % 10)) / 10) + (num % 10);
		if (first_part == second_part) {
			printf("Щасливий квиток");
			break;
		}
		else {
			printf("Нещасливий квиток");
			break;
		}

	}
	
	do{
	i++;
	first_part = ((num - (num % 100000)) / 100000) + (((num - (num % 10000)) / 10000) % 10) + (((num - (num % 1000)) / 1000) % 10);
		second_part = (((num % 1000) - (num % 100)) / 100) + (((num % 100) - (num % 10)) / 10) + (num % 10);
		if (first_part == second_part) {
			printf("Щасливий квиток");
			break;
		}
		else {
			printf("Нещасливий квиток");
			break;
		}
	}while (i <= num);*/	
       
	return 0;
}

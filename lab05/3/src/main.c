#include <stdio.h>
int main() {
	const int n = 6;                     //кількість розрядів у числі
	int num = 723435;                    //задане число
	int del1 = 1, del2 = 10, del3 = 1;   //дільники
	int sum1 = 0, sum2 = 0;              //суми чисел першої та другої половини
        int a = num;                         //задане число
	int num1, num2;                      //перша та друга половини чисел
	

	for (int i = 0; i < n / 2; i++) {    //отримання першої половини чисел
		num = num / 10;
		num1 = num;
	}
	for (int i = 0; i < n / 2; i++) {    //отримання другої половини чисел
		del1 *= 10;
		num2 = a % del1;
	}

	for (int i = 0; i < n / 2; i++) {    //вирахування сум першої та другої половини 
		num1 = ((num % del2) / del3);
		num2 = ((a % del2) / del3);
		sum1 += num1;
		sum2 += num2;
		del2 *= 10;
		del3 *= 10;
	}

	if (sum1 == sum2) {
		printf("Щасливий квиток");
	}
	else {
		printf("Нещасливий квиток");
	}
	
		return 0;
}
	
		

	

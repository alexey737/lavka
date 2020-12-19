# Загальне завдання 
1. Без допомоги зовнішніх бібліотек, *отримати* корінь заданого числа.

**Виконання роботи** 
1. **Функціональне призначення** 
	Програма призначена для пошуку квадратного корня заданого числа без допоиоги злвнішніх бібліотек.

2. Написання коду програми
``` 
		#include <stdio.h>
		float result(float num); 
           
		int main() {
		float num = 10;<kjr
		result(num); 
		return 0;
		}


		float result(float num){
		float koren, x1, x2;
		for (float i = 1.0; i < num; i++) {
			if (num == i * i) {
			koren = i;
			printf("%.0f", koren);       
			break;	        
			}else if ((i*i) > num){
			x1 = (((num/(i-1)) + (i-1))/2);
			x2 = (num/(((num/(i-1)) + (i-1))/2));
			koren = ((x1 + x2)/2); 
			printf("%.4f", koren); 
				break; 
			}
		}	
		return koren;
		}
```
3. Компіляція програми та перевірка на правильність її роботи через nemiver

![text](file:///home/aleksey/lavka/lab08,09,10/cycle/5/doc/nemiver5.5.png)

4.Блок-схема

![text](file:///home/aleksey/lavka/lab08,09,10/cycle/5/doc/5.5.png)

**Висновок**
Я створив програму, яка знаходить квадратний корень заданого числа.





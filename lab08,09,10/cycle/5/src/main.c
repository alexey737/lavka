/**
* @mainpage
* # Загальне завдання
* 1. **Отримати** корінь заданого числа без допомоги зовнішніх бібліотек.
* @author Lavka O.
* @date 15-dec-2020
* @version 1.0
*/ 

/**
* @file main.c
* @brief Файл з демонстрацією роботи структури та методів
* оперування ним.
* @author Lavka O.
* @date 15-dec-2020
* @version 1.0
*/   

#include <stdio.h>
float result(float num); 

/**
* Головна функція.
*
* Послідовність дій:
* - оголошення змінних 
*      @param num початкове число
* - вивід результату роботи функції @function result
* @return успішний код повернення з програми (0)
*/
int main() {
float num = 10.0;
result(num); 
return 0;
}

/**
* @function result
* 
* Полсідовність дій:
* - оголошення змінних 
*      @param num вхідне число
*      @param koren змінна для квадратного корня числа
*      @param num вхідне число
*      @param x1 допоміжна змінна для отримання квадратного корня заданного числа 
*      @param x2 допоміжна змінна для отримання квадратного корня заданного числа
* - шукаємо квадратний корінь числа та заносимо в відповідну змінну 
* @return успішний код повернення результату роботи функції (koren) 
*/

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


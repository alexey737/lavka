/**
* @mainpage
* # Загальне завдання
* 1. У кожному рядку двовимірного масиву **знайти** парні додатні числа 
* та **записати** їх y результуючий одновимірний масив. 
* @author Lavka O.
* @date 20-dec-2020
* @version 1.0
*/

/**
* @file main.c
* 
* @brief Файл з демонстрацією роботи структури та методів
* оперування ним.
*
* @author Lavka O.
* @date 20-dec-2020
* @version 1.0
*/
#include <stdio.h>
#define size 3
void zap(int mas[size][size]);
void perebor(int mas[size][size], int res[size*size]);

/**
* Головна функція.
*
* Послідовність дій:
* - оголошення змінних
*	@param mas[size][size] масив цілих чисел
*	@param res[size*size] результуючий масив
* - вивід результату роботи @function zap
* - вивід результату роботи @function perebor
* @return успішний код повернення з програми (0)
*/
int main(){
int mas[size][size];
int res[size*size] = {0};
zap(mas);
perebor(mas, res);
return 0;
}

/**
* @fuction zap
*
* Послідовність дій:
* - цикл заповнення масиву випадковими числами використовуючи функцію rand()
*/
void zap(int mas[size][size]){
for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){
		*(*(mas+i)+j) = rand()%100;
	}
   }
}

/**
* @fuction perebor
*
* Послідовність дій:
* - оголошення змінних
*	@param a індекс результуючого масиву 
* - цикл перебору чисел масиву mas[size][size]:
*	- якщо число парне і додатнє, то воно записується у результуючий масив res[size*size]
*/
void perebor(int mas[size][size], int res[size*size]){
int a = 0;
for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){
		if( ((*(*(mas+i)+j))%2) == 0 && *(*(mas+i)+j) > 0){
		*(res+a) = *(*(mas+i)+j);
		a++;
		
		}
	}
   }
}

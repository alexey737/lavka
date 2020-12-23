/**
* @mainpage
* # Загальне завдання
* 1. **Знайти** кількіть слів у кожному рядку тексту
* @author Lavka O.
* @date 22-dec-2020
* @version 1.0
*/

/**
* @file main.c
*
* @brief Файл з демонстрацією роботи структури та методів
* оперування ним. 
*
* @author Lavka O.
* @date 22-dec-2020
* @version 1.0
*/
#include "stdio.h"
#include "string.h"
#define size 100

void schet_slov(char str[size]);

/**
* Головна функція.
*
* Послідовність дій:
* - оголошення змінних
*	@param str[size] заданий рядок
* - вивід результату роботи @fuction schet_slov
* - @return успішний код повернення з програми (0)
*/
int main(){	
char str[size] = "saasa sa dss dsdsa";
/*printf("Введіть рядок: ");
fgets(str, size, stdin);*/
schet_slov(str);
return 0;
}

/**
* @function schet_slov
* @brief функція підрахунку кількості слів у заданому рядку.
*
* Полідовність дій:
* - оголошення змінних
*	@param res кількість слів у заданому рядку.
* - шукаємо перший пробіл та кінець рядка
* - перевіряємо заданий рядок на те, що слово з рядка може бути без пробілів
* - якщо є пробіл, то перевіряємо чи є він 0 елементом рядку
* - цикл пошуку наступних пробілівf
* - запис кількості слів в res
* @return логічну відповідь у консоль
*/
void schet_slov(char str[size]){
char *point1 = strchr(str, ' ');	//шукаємо перший пробіл
char *end = strchr(str, '\0'); 	//шукаємо символ закінчення рядку
int res = 0;	

/*Якщо є слово без пробілів*/
if(point1 == NULL){
	res++;
	printf("Слів: %d", res);
	return 0;
	}
	
*point1 = '*'; 			//за адресом першого пробіла змінюємо його на будь-який символ

/*Якщо 0 елемент рядка не пробіл, то +1 слово*/		
if(point1 != str){
	res++;	
	}
		
char *point2 = strchr(str, ' ');      //шукаємо наступний пробіл 
int i = 0;
/*Цикл пошуку наступних пробілів*/
while(i < 1){ 
if(point2 == NULL && point1 != end){	
	res++;
	i++;
}else if(point2 - point1 == 1){
	point1 = point2;
	*point1 = '*';
	point2 = strchr(str, ' ');
	i++;

}else{
	point1 = point2;
	*point1 = '*';
	point2 = strchr(str, ' ');
	res++;
		}		
	}
printf("Слів: %d", res);    
}


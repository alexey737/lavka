/**
* @mainpage
* # Загальне завдання
* 1. **Знайти** кількіть слів у кожному рядку тексту
* @author Lavka O.
* @date 24-feb-2021
* @version 1.0
*/

/**
* @file main.c
*
* @brief Файл з демонстрацією роботи структури та методів
* оперування ним.
*
* @author Lavka O.
* @date 24-feb-2021
* @version 1.0
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100

void schet_slov(char str[size]);

/**
* Головна функція.
*
* Послідовність дій:
* - оголошення змінних
*	@param str[size] заданий рядок
*	@param *fp покажчик на файл
* - відкриття файлу str.txt для читання речення
*	- запис реченя з файлу str.txt в масив str
* - вивід результату роботи @fuction schet_slov
* - закінчення роботи з файлом str.txt
* - @return успішний код повернення з програми (0)
*/
int main(){

	char str[size];

	FILE *fp;
	fp = fopen("str.txt", "r");	//відкриваємо файл для читання
	fgets(str, size, fp);		//записуємо у масив str речення з файлу
	printf("\n");

	schet_slov(str);
	fclose(fp);
	return 0;
}

/**
* @function schet_slov
* @brief функція підрахунку кількості слів у заданому рядку.
*
* Полідовність дій:
* - оголошення змінних
*	@param res кількість слів у заданому рядку
* @param *fp1 покажчик на файл res.txt
* - відкриття файлу res.txt для запису
* - шукаємо перший пробіл та кінець рядка
* - перевіряємо заданий рядок на те, що слово з рядка може бути без пробілів
* - якщо є пробіл, то перевіряємо чи є він 0 елементом рядку
* - цикл пошуку наступних пробілівf
* - запис кількості слів в res
* - вивід кількості слів на екран
* - запис кількості слів у файл res.txt
* - закінчення роботи з файлом res.txt
*/
void schet_slov(char str[size]){
	FILE *fp1;
	fp1 = fopen("res.txt", "w");	//відкриваємо результуючий файл для запису в нього
char *point1 = strchr(str, ' ');	//шукаємо перший пробіл
char *end = strchr(str, '\0'); 	//шукаємо символ закінчення рядку
int res = 0;

/*Якщо є слово без пробілів*/
if(point1 == NULL){
	res++;
	printf("Слів: %d", res);
	return 0;
	}else{

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
	fprintf(fp1, "%d", res);	//записуємо кількість слів y реченні в результуючий файл

	fclose(fp1);
	}

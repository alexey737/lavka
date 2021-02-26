/**
* @mainpage
* # Загальне завдання
* 1. У кожному рядку двовимірного масиву **знайти** парні додатні числа
* та **записати** їх y результуючий одновимірний масив.
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
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#define size 3

void zap(int **mas);
void perebor(int **mas, int res[size*size]);
void inf(char numb[10], char theme[200], int author, char let);

/**
* Головна функція.
*
* Послідовність дій:
* - оголошення змінних
*	@param **mas масив цілих чисел
*	@param res[size*size] результуючий масив
*	@param numb[10] номер лабораторної роботи
*	@param theme[100] тема лабораторної роботи
*	@param author данні про автора
*	@param let літера групи студента
* - вивід результату роботи @function zap
* - вивід результату роботи @function perebor
* - вівід результату роботи @function inf
* @return успішний код повернення з програми (0)
*/
int main(){
int **mas = (int**)malloc(size*sizeof(int*));
for(int i = 0; i < size; i++){
	*(mas+i) = (int*)malloc(size*sizeof(int));
}
int res[size*size] = {0};
char numb[10] = {0};
char theme[200] = {0};
int author;
char let;

inf(numb, theme, author, let);
zap(mas);
perebor(mas, res);
	for(int i = 0; i < size; i++){
		free(*(mas+i));
	}
	return 0;
}

/**
* @function inf
*
*	Послідовність дій:
* - запис номеру лабораторної роботи у масив numb
* - запис теми лабораторної роботи у масив theme
* - запис літери групи студента у змінну let
* - вивід на екран номер та тему лабораторної роботи з масивів numb та theme відповідно
* - запис числа у змінну author
* - якщо число дорівнює 1, то вивести на екран дані про автора та продовження роботи програми
* - якщо число дорівнює 0, то не виводити дані про автора та продовжити роботу програми
* - якщо це будь-яке інше число - завершити програму
*/
void inf(char numb[10], char theme[200], int author, char let){

	printf("Введіть номер лабораторної роботи: ");
	gets(numb);

	printf("Введіть тему лабораторної роботи: ");
	gets(theme);

	printf("Введіть літеру вашої групи: ");
	let = getc(stdin);

printf("\n");

	printf("---------------------\n");
	putc('-', stdout);
	printf("Номер лабораторної роботи: ");
	puts(numb);

	putc('-', stdout);
	printf("Тема лабораторної роботи: ");
	puts(theme);
	printf("---------------------\n");

printf("Натисніть '1', щоб дізнатися дані про автора та продовжити;\n");
printf("Натисніть '0', щоб пропустити дані про автора та продовжити;\n");
printf("Натисніть будь-яке інше число, щоб завершити програму: \n");



read(0, &author, 1);
write(1, &author, 0);
printf("\n");

	if(author == 49){
		printf("Дані про автора: Лавка Олексій, група КІТ-120%c\n\n", let);
	}else if(author == 48){
		printf("Ви обрали пропустити дані про автора\n\n");
	}else{
		printf("Програма завершена\n");
		exit(0);
	}


}

/**
* @fuction zap
*
* Послідовність дій:
* - цикл заповнення масиву числами з клавіатури та їх вивід на екран
*/
void zap(int **mas){
for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){
		printf("Введіть число масива: ");
		scanf("%d", &*(*(mas+i)+j));
	}
   }
   printf("\n");
   printf("Заданий масив: ");
for(int i = 0; i < size; i++){
	printf("\n");
	for(int j = 0; j < size; j++){
		printf("%d ", *(*(mas+i)+j));
	}
   }
   printf("\n\n");
}

/**
* @fuction perebor
*
* Послідовність дій:
* - оголошення змінних
*	@param a індекс результуючого масиву
* - цикл перебору чисел масиву **mas:
*	- якщо число парне і додатнє, то воно записується у результуючий масив res[size*size]
*/
void perebor(int **mas, int res[size*size]){
int a = 0;

	printf("Парні додатні числа заданого масива: ");

for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){
		if( ((*(*(mas+i)+j))%2) == 0 && *(*(mas+i)+j) > 0){
		*(res+a) = *(*(mas+i)+j);
		printf("%d ", *(res+a));
		a++;
		}
	}
}
   printf("\n");
}

# Загальне завдання
1. Дано масив масивів з N x N цілих чисел, який заповнюється з клавіатури. У кожному рядку масиву **знайти** кількість парних додатніх чисел. Отримані результати **записати** в одновимірний масив та вивести результати на екран.

**Виконав: Лавка Олексій**

## Виконання роботи

**Мета:**
	Виконати завдання, номер якого визначили вище за формулою, на оцінку "добре".

**Функціональне призначення**
	Програма призначена для пошуку парних додатніх чисел у масиві, використовуючи показчики та функціїї введення/виведення.

## Написання коду програми
```
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#define size 3

void zap(int **mas);
void perebor(int **mas, int res[size*size]);
void inf(char numb[10], char theme[200], int author, char let);

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
```
## Компіляція програми та виведення результатів на екран

![text](file:///home/aleksey/lavka/lab12,14/12/doc/terminal12.png)

## Блок-схема

![text](file:///home/aleksey/lavka/lab12,14/12/doc/scheme12.png)

# Висновок
У ході цієї лабораторної роботи я ознайомився з функціями введення/виведення та переробив лабораторну роботу №11, використовуючи ці функції.

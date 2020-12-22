# Загальне завдання
1. Дано масив масивів з N x N цілих чисел. У кожному рядку масиву **знайти** кількість парних додатніх чисел. Отримані результати **записати** в одновимірний масив.

## Виконання роботи
**Визначення номеру завдння для звіту**
	((10-1)%4) + 1 = 2, тож звіт виконується за завданням під номером 2. 
	
**Функціональне призначення**
	Програма призначена для пошуку парних додатніх чисел у масиві, використовуючи показчики.

## Написання коду програми
```
#include <stdio.h>
#define size 3
void zap(int mas[size][size]);
void perebor(int mas[size][size], int res[size*size]);

int main(){
int mas[size][size];
int res[size*size] = {0};
zap(mas);
perebor(mas, res);
return 0;
}

void zap(int mas[size][size]){
for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){
		*(*(mas+i)+j) = rand()%100;
	}
   }
}

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
```
## Компіляція програми та перевірка на правильність її роботи через nemiver

![text](file:///home/aleksey/lavka/lab11/2/doc/nemiver11.2.png)

## Блок-схема

![text](file:///home/aleksey/lavka/lab11/2/doc/11.2.png)

# Висновок
У ході цієї лабораторної роботи я ознайомився з показчиками та виконав з ними 2 завдання на оцінку добре, одне з яких я описав у цьому звіті.

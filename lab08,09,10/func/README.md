#  Загальне завдання
1. *Реалізувати* функцію, що визначає, скільки серед заданої послідовності чисел таких пар, у котрих перше число менше наступного.

**Виконання роботи**
1. **Функціональне призначення** 
	Програма призначена для визначення кількості серед заданої послідовності чисел таких пар, у котрих перше число менше наступного.

2. Написання коду програми 
```
#include <stdio.h>
#include <stdarg.h>

int task(int size, ...); 

int main(){
int result = task(7, 2, 3, 4, 5, 6, 9, 8);
printf("%d ", result);
return 0;
}

int task(int size, ...){
int mas[size];
int kol = 0;
int i;
va_list ap; //початок роботи з варіативними аргументами
va_start(ap, size);
	for(i = 0; i < size; i++){
	mas[i] = va_arg(ap, int);
	printf("%d ", mas[i]);
	}
	printf("\n");
		for(i = 0; i < size; i++){
		if(i != size-1){
			if(mas[i] < mas[i+1]){		
			kol++;
			}
	}
}	
va_end(ap); //кінець роботи з варіативними аргументами 
return kol;
}

```

3. Компіяція програми та перевірка на правильність її роботи через nemiver

![text](file:///home/aleksey/lavka/lab08,09,10/func/doc/nemiver7.1.png)

4.Блок-схема

![text](file:///home/aleksey/lavka/lab08,09,10/func/doc/7.1.png)

**Висновок**
Я створив програму, яка призначена для визначення кількості серед заданої послідовності чисел таких пар, у котрих перше число менше наступного.


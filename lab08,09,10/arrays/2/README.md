#  Загальне завдання
1. 1. *Заповнити масив* із заданої кількості елеметів простими числами, що не повторюються.

**Виконання роботи**
1. **Функціональне призначення**
	Програма призначена для заповнення масивa із заданої кількості елеметів простими числами, що не повторюються.
	
2. Написання коду програми
```
#include <stdio.h>
#define size 10         // розмірність масиву
void zap(int mas[size]); 

int main(){     
int mas[size] = {0};
zap(mas);        
return 0;
} 

void zap(int mas[size]){     
int i, j;
int p = 0;             // перевірка числа на простоту
int a = 0;             // індекс елемента масиву
// цикл для перебору простих чисел
  for(i = 2; i < size; i++){      
    for(j = 2; j < i; j++){
      if(i % j != 0){ 
      p = 0;               // число просте
     }else{
      p = 1;               // число складне
      break;
    }      
}
  if(p == 0){
  mas[a] = i;

     a++;
   if(a == size){
      break;
      }
    }
  }
} 
```

3. Компіляція програми та перевірка на правильність її роботи через nemiver

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/2/doc/nemiver6.2.png)

4.Блок-схема 

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/2/doc/6.2.png)

**Висновок**
Я створив програму, яка заповняє масив із заданої кількості елеметів простими числами, що не повторюються.





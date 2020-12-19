#  Загальне завдання
1. *Центрувати* заданий рядок на площині із заданим заповнювачем

**Виконання роботи**
1. **Функціональне призначення**
	Програма призначена для того щоб центрувати слово і заповнити пробіли з двох його боків заповнювачем.

2. Написання коду програми 
```
#include <stdio.h> 
void result(char mas1[], char zap); 

int main() { 
#define size 15
char mas1[size] = { "Ivanov        " }; //заданий масив  
char zap = '_';                         //заповнювач
result(mas1, zap);                      //функція відцентрування масиву
printf("%s", mas1); 
return 0;
}

void result(char mas1[], char zap){       
char mas2[size];                         //допоміжний масив    
int i;
int l;                                  //довжина слова
int x;                                  //останній елемент масиву першої половини заповнювачів разом зі словом  
int probel = 0;
// знайдемо кількість пробілів у заданій строчці 
   for(i = 0; i < size; i++){
     if(mas1[i] == ' '){
         mas1[i] = zap;
         probel++;
         }
      }
      
l = (size - probel)-1; 
probel /= 2;        
x = (probel + l)-1; 
// занесемо у допоміжний масив слово без пробілів
   for(i = 0; i < l; i++){
     if(mas1[i] != zap){
     mas2[i] = mas1[i];
     }
   } 
   
// відцетруємо рядок заданного масивa
   for(i = 0; i < size-1; i++) {
     if(i >= probel && i <= x){        
     mas1[i] = mas2[i-probel];
     }else if(i < probel || (i > x && i < size)){
     mas1[i] = zap;
     
     }
  }
} 
```

3. Компіляція програми та перевірка на правильність її роботи через nemiver

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/1/doc/nemiver6.1.png)

4.Блок-схема

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/1/doc/6.1.png)

**Висновок**
Я створив програму, яка центрує слово і заповнює з двох його боків заповнювачем.




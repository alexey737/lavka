#  Загальне завдання
1. *Перетворити* число в рядок

**Виконання роботи**
1. **Функціональне призначення**
	Програма призначена для переведення числа з цифрового вида у словесний вид.
	
2. Написання коду програми
```
#include <stdio.h>
#define size 100
void zapis(int num); 

int main(){
int num = 2142; 
zapis(num);
return 0;
}


void zapis(int num){
char x[size];
int n1, n2, n3, n4;
if(num > 9999){    //досить велике число
return 0;

//перевірка на нуль
}else if(num == 0){ 
x[0] = 'z';
x[1] = 'e';
x[2] = 'r';
x[3] = 'o';
printf("%s", x);
}else{             //якщо число не дорівнює нулю, тоді:

//задаєм масиви запису цифр словами
const char mas1[10][10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char mas2[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char mas3[10][10] = {"", "", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
const char mas4[10][14] = {"", "one hundred ", "two hundred ", "three hundred ", "four hundred ", "five hundred ", "six hundred ", "seven hundred ", "eight hundred ", "nine hundred "};
const char mas5[10][15] = {"", "one thousand ", "two thousand ", "three thousand ", "four thousand ", "five thousand ", "six thousand ", "seven thousand ", "eight thousand ", "nine thousand "}; 
for(int i = 0; i < 100; i++){
x[i] = 0;
}

//цикл для запису тисяч в результуючий масив
for(int i = 0; i <= num/1000; i++){   
  n1 = 0;
for(int j = 0; j < 15; j++){
  x[n1++] = mas5[i][j];
  }
}
n2 = n1;

//цикл для запису сотен в результуючий масив
for(int i = 0; i <= ((num%1000)/100); i++){
  n1 = n2; 
for(int j = 0; j < 14; j++){
  x[n1++] = mas4[i][j];
  }
}
n3 = n1;

```

3. Компіляція програми та перевірка її роботи через nemiver

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/3/doc/nemiver6.3.png)

4.Блок-схема

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/3/doc/6.3.png)

**Висновок**
Я створив програму, яка переводить число з цифрового вида в словесний.

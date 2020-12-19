/**
* @mainpage
* # Загальне завдання
* 1. **Перетворити** числов в рядок. 
* @author Lavka O.
* @date 15-dec-2020
* @version 1.0
*/ 

/**
* @file main.c
* @brief Файл з демонстрацією роботи структури та методів
* оперування ним.
* @author Lavka O.
* @date 15-dec-2020
* @version 1.0
*/   

#include <stdio.h>
#define size 100
void zapis(int num); 

/**
* Головна функція.
*
* Послідовнсть дій: 
* - оголошення змінних
*      @param num задане число
* - вивід результату роботи @fuction zapis
* @return успішний код повернення з програми (0)
*/
int main(){
int num = 6489;         
zapis(num);
return 0;
}

/**
* @function zapis
* 
* Послідовність дій:
* - оголошення змінних 
*      @param num вхідне число
*      @param x результуючий масив
*      @param n1-n4 номер індекса результуючого масиву
*      @param mas1[]-mas5[] 
* - перевірка числа на максимальну клькість розрядів - 4 
* - перевірка числа на нуль
* - записуємо у результуючий масив слова відповідно розрядам числа  
*/
void zapis(int num){
int n1, n2, n3, n4; 
char x[size]; 
if(num > 9999){   
return 0;

}else if(num == 0){ 
x[0] = 'z';
x[1] = 'e';
x[2] = 'r';
x[3] = 'o';
printf("%s", x);
}else{            

const char mas1[10][10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char mas2[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char mas3[10][10] = {"", "", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
const char mas4[10][14] = {"", "one hundred ", "two hundred ", "three hundred ", "four hundred ", "five hundred ", "six hundred ", "seven hundred ", "eight hundred ", "nine hundred "};
const char mas5[10][15] = {"", "one thousand ", "two thousand ", "three thousand ", "four thousand ", "five thousand ", "six thousand ", "seven thousand ", "eight thousand ", "nine thousand "}; 
for(int i = 0; i < 100; i++){
x[i] = 0;
}

for(int i = 0; i <= num/1000; i++){   
  n1 = 0;
for(int j = 0; j < 15; j++){
  x[n1++] = mas5[i][j];
  }
}
n2 = n1;

for(int i = 0; i <= ((num%1000)/100); i++){
  n1 = n2; 
for(int j = 0; j < 14; j++){
  x[n1++] = mas4[i][j];
  }
}
n3 = n1;

if(((num%100)/10) == 1){                       
for(int i = 0; i <= num%10; i++){
  n1 = n3;
for(int j = 0; j < 10; j++){
  x[n1++] = mas2[i][j];
   }  
  }
}else if(((num%100)/10 != 1)){                 
for(int i = 0; i <= ((num%100)/10); i++){
  n1 = n3;
for(int j = 0; j < 10; j++){
  x[n1++] = mas3[i][j];
  }  
 }  
n4 = n1;

for(int i = 0; i <= num%10; i++){
  n1 = n4;
for(int j = 0; j < 10; j++){
  x[n1++] = mas1[i][j];
  }  
 }
}
for(int i = 0; i < n1; i++){
printf("%c", x[i]);
  }
 }
}

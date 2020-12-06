#include <stdio.h>
int main(){
int num = 7936;
int n1 = 0, n2 = 0, n3 = 0, n4 = 0; 
char x[100] = {0};       //результирующая строка
if(num > 9999){    //слишком большое число
return 0;
//проверка на ноль
}else if(num == 0){ 
x[0] = 'z';
x[1] = 'e';
x[2] = 'r';
x[3] = 'o';
printf("%s", x);
}else{             // если число не равно нулю, тогда:

//задаём массивы для хранения чисел в словах
const char mas1[10][10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char mas2[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char mas3[10][15] = {"", "", "twenty ", "thirty ", "fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
const char mas4[10][15] = {"", "one hundred ", "two hundred ", "three hundred ", "four hundred ", "five hundred ", "six hundred ", "seven hundred ", "eight hundred ", "nine hundred "};
const char mas5[10][15] = {"", "one thousand ", "two thousand ", "three thousand ", "four thousand ", "five thousand ", "six thousand ", "seven thousand ", "eight thousand ", "nine thousand "}; 

//цикл для записи тысяч в результрующую строку
for(int i = 0; i <= num/1000; i++){   
  n1 = 0;
for(int j = 0; j < 15; j++){
  x[n1++] = mas5[i][j];
  n2 = n1;
  }
}

//цикл для записи сотен в результирующую строку
for(int i = 0; i <= ((num%1000)/100); i++){
  n1 = n2; 
for(int j = 0; j <= 15; j++){
  x[n1++] = mas4[i][j];
  n3 = n1;
  }
}

//цикл для записи десятков в результирующую строку
if(((num%100)/10) == 1){                        // если число десятков равно 1
for(int i = 0; i <= num%10; i++){
  n1 = n3;
for(int j = 0; j < 10; j++){
  x[n1++] = mas2[i][j];
   }   
   break;
  }
}else if(((num%100)/10 != 1)){                  //если число десятков равно 2 и больше 
for(int i = 0; i <= ((num%100)/10); i++){
  n1 = n3-1;
for(int j = 0; j < 10; j++){
  x[n1++] = mas3[i][j];
  n4 = n1;  
  }  
 }  
}

//цикл для записи единиц в результирующую строку
for(int i = 0; i <= num%10; i++){
  n1 = n4;
for(int j = 0; j < 10; j++){
  x[n1++] = mas1[i][j];
  }  
 }
}
for(int i = 0; i <= 100; i++){
printf("%c", x[i]);
}
return 0;
}

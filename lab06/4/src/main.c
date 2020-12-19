#include <stdio.h>
int main(){
char text[] = {"Hello World"};             // заданый текст
int words = 0;                             // переменная для подсчёта слов в тексте      

//цикл для поиска количества слов в тексте
for(int i = 0; text[i] != '\0'; i++){
 if(text[i] != ' ' && text[i+1] <= ' ' && text[i] != ',' && text[i] != '.' && text[i] != '!' && text[i] != '?'){
  words++;
  }
 }   
printf("%d", words);
return 0;
}

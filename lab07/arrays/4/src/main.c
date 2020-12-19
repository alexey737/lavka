#include <stdio.h>
void poisk_slov(char text[]);      

int main(){
char text[] = {"Hello ,! ? . sasa    World"};     // заданый текст
poisk_slov(text);                  
return 0;
}

void poisk_slov(char text[]){
int words = 0;                     // переменная для подсчёта слов в тексте 
//цикл для поиска количества слов в тексте
for(int i = 0; text[i] != '\0'; i++){
 if(text[i] != ' ' && text[i+1] <= ' ' && text[i] != ',' && text[i] != '.' && text[i] != '!' && text[i] != '?'){
  words++;
 }
}   
printf("%d", words);
}

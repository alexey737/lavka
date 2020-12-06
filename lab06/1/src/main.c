#include <stdio.h>
int main() {
#define size 15                         //розмір масива
char mas1[size] = { "Ivanov        " }; //заданий масив  
char mas2[size];                        //допоміжний масив
int i;
int l;                                  //довжина слова
int x;                                  //останній елемент масиву першої половини заповнювачів разом зі словом 
char zap = '_';   
int probel = 0;
// знаєдомо кількість пробілів у заданій строчці 
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
      }else if(mas1[i] == zap){
      i--;
     break;
    
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
printf("%s", mas1); 
return 0;
}

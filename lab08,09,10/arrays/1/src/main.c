/**
* @mainpage
* # Загальне завдання
* 1. **Центрувати** заданий рядок на площині із заданим заповнювачем. 
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
void result(char mas1[], char zap);

/**
* Головна функція.
*
* Послідовнсть дій: 
* - оголошення змінних
*      @param mas1 масив із заданим рядком 
*      @param zap заповнювач
* - вивід результату роботи @fuction result
* @return успішний код повернення з програми (0)
*/
int main() { 
#define size 15
char mas1[size] = { "Ivanov        " };   
char zap = '_';                         
result(mas1, zap);                      
return 0;
}

/**
* @function result
* 
* Послідовність дій:
* - оголошення змінних 
*      @param mas2 допоміжний масив
*      @param l двожина слова
*      @param x індекс останнього елемента слова разом з половиною пробілів 
*      @param probel кількість пробілів в заданому рядку 
* - знайдемо кількість пробілів у заданому рядку 
* - занесемо у допоміжний масив слово без пробілів
* - відцентруємо рядок заданого масива
*/
void result(char mas1[], char zap){       
char mas2[size];                            
int i;
int l;                                  
int x;                                  
int probel = 0;
   for(i = 0; i < size; i++){
     if(mas1[i] == ' '){
         mas1[i] = zap;
         probel++;
         }
      }    
l = (size - probel)-1; 
probel /= 2;        
x = (probel + l)-1; 
   for(i = 0; i < l; i++){
     if(mas1[i] != zap){
     mas2[i] = mas1[i];
     }
   } 
   
   for(i = 0; i < size-1; i++) {
     if(i >= probel && i <= x){        
     mas1[i] = mas2[i-probel];
     }else if(i < probel || (i > x && i < size)){
     mas1[i] = zap;
     
     }
  }
} 

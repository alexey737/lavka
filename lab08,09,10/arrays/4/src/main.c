/**
* @mainpage
* # Загальне завдання
* 1. **Знайти** кількість слів у заданому тексті за умови, що між словами може бути будь-яка кількість пропусків.
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
void poisk_slov(char text[]);      

/**
* Головна функція.
*
* Послідовнсть дій: 
* - оголошення змінних
*      @param text[] заданий текст
* - вивід результату роботи @fuction poisk_slov
* @return успішний код повернення з програми (0)
*/
int main(){
char text[] = {"Hello World"};    
poisk_slov(text);                  
return 0;
}

/**
* @function poisk_slov
* 
* Послідовність дій:
* - оголошення змінних 
*      @param text[] вхідний текст
*      @param words кількість слів у тексті
* - пошук кількості слів у тексті незважаючи на пробіли та розділові знаки    
*/
void poisk_slov(char text[]){
int words = 0;                    
for(int i = 0; text[i] != '\0'; i++){
 if(text[i] != ' ' && text[i+1] <= ' ' && text[i] != ',' && text[i] != '.' && text[i] != '!' && text[i] != '?'){
  words++;
 }
}   
printf("%d", words);
}

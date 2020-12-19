/**
* @mainpage
* # Загальне завдання
* 1. **Заповнити** масив із заданої кількості елементів простими числами, що не повторюються. 
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
void zap(int mas[]);

/**
* Головна функція.
*
* Послідовнсть дій: 
* - оголошення змінних
*      @param mas заданий масив
* - вивід результату роботи @fuction zap
* @return успішний код повернення з програми (0)
*/
int main(){     
#define size 10         
int mas[size];
zap(mas);        
return 0;
} 

/**
* @function zap
* 
* Послідовність дій:
* - оголошення змінних 
*      @param mas вхідний масив 
*      @param p перевірка числа на простоту
*      @param a індекс елемента масива
* - цикл для перебору простих чисел
* - заповнення заданого масива простими числами
*/
void zap(int mas[size]){        
int i, j;
int p = 0;         
int a = 0;            
  for(i = 2; i < size; i++){      
    for(j = 2; j < i; j++){
      if(i % j != 0){ 
      p = 0;               
     }else{
      p = 1;               
      break;
    }      
}
  if(p == 0){
  mas[a] = i;
  printf("%d ", mas[a]); 
     a++;
   if(a == size){
      break;
      }
    }
  }
} 

/**
* @mainpage
* # Загальне завдання
* 1. **Помножити** дану матрицю саму на себе.
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
#define size 3           
void matr_v_kvadrate(int mas[size][size]);  

/**
* Головна функція.
*
* Послідовнсть дій: 
* - оголошення змінних
*      @param mas[] заданий масив
* - вивід результату роботи @fuction matr_v_kvadrate
* @return успішний код повернення з програми (0)
*/
int main(){
int mas[size][size] = {   
{2, 4 ,5},    
{1, 6, 7},
{3, 8, 1}     
};
matr_v_kvadrate(mas);              
return 0;
}

/**
* @function matr_v_kvadrate
* 
* Послідовність дій:
* - оголошення змінних 
*      @param mas[] вхідний масив
*      @param res[] результуючий масив возведення масиву в квадрат
* - множимо масив сам на себе за правилом множення матриць
* - заносимо матрицю в квадраті у результуючий масив   
*/
void matr_v_kvadrate(int mas[size][size]){
int res[size][size];
for(int i = 0; i < size; i++){
  for(int j = 0; j < size; j++){
    for(int k = 0; k < size; k++){
    res[i][j] += mas[i][k]*mas[k][j];
      }
    }
  }
}


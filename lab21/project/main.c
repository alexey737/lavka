/**
* @mainpage
* # Загальне завдання
* 1. **Робота з динамічними масивами**
* @author Lavka O.
* @date 19-apr-2021
* @version 1.0
*/

/**
* @file main.c
*
* @brief Файл з демонстрацією роботи структури та методів
* оперування ним.
*
* @author Lavka O.
* @date 19-apr-2021
* @version 1.0
*/

#include "../library/src/lib.h"

/**
* Головна функція.
* Послідовність дій:
* - оголошення змінних
* @param disc_arr динамічний масив структур
* @param check змінна для вибору роботи з динамічним масивом структур
* - вивід результату роботи @fuction insert
* - вивід результату роботи @fuction reduce
* - вивід результату роботи @fuction rand_fill
* - вивід результату роботи @fuction output
* - вивід результату роботи @fuction delete_element (якщо @param check = 1)
* - вивід результату роботи @fuction add_element (якщо @param check = 2)
* - @return успішний код повернення з програми (0)
*/
int main()
{

    printf("\n------------------------------------------ЗАВДАННЯ №1------------------------------------------");
    insert("abrakadabra", "TEXT2", 6);



    printf("\n\n------------------------------------------ЗАВДАННЯ №2------------------------------------------");
    reduce("abrakadabra", 6, 7);



    printf("\n\n------------------------------------------ЗАВДАННЯ №3------------------------------------------\n\n");
    discipline *disc_arr = NULL;
    disc_arr = (discipline*)malloc(N * sizeof(discipline));

    rand_fill(disc_arr, N);
    output(disc_arr, N);




    printf("\n\nЩо робити зі структурою?\n");
    printf("[1] Видалити структуру\n");
    printf("[2] Додати структуру\n");
    printf("[3] Вихід з програми\n");
    printf("Ваш варіант: ");

    int check;
    scanf("%d", &check);
    if(check == 1)
    {
      delete_element(disc_arr, N);
    }
    else if(check == 2)
    {
      add_element(disc_arr, N);
    }
    else if(check == 3)
    {
      exit(0);
    }

    free(disc_arr);
  return 0;

}

/**
* @mainpage
* # Загальне завдання
* 1. **Ознайомитися з динамічними списками**
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
#include "lib.h"


/**
* Головна функція.
* Послідовність дій:
* - оголошення змінних
* @param *head покажчик на 1 єлемент однозв'язного списку
* - перевірка *head на NULL
* - виклик макросу DATE
* - виклик макросу FUNC
* - вивід результату роботи @fuction read_from_file
* - вивід результату роботи @fuction write_to_file
* - вивід результату роботи @fuction print_list
* - вивід результату роботи @fuction search_discipline
* - вивід результату роботи @fuction delete_element
* - виклик макросу TIME
* - @return успішний код повернення з програми (0)
*/
int main()
{
  clock_t start = clock();

  list* head = NULL;
  head = (list*)malloc(sizeof(list));

  if(head == NULL)
  {
    return 1;
  }

  DATE();     //вывод текущей даты и времени
  FUNC();     //название текущей функции


  printf("---------------------ЗАДАНИЯ НА 3---------------------\n");
  read_from_file(head);
  print_list(head);
  write_to_file(head);
  search_discipline(head);
  push_end(head);
  print_list(head);
  delete_element(&head);
  print_list(head);

  clock_t end = clock();

  TIME();   //вывод времени работы программы

  return 0;
}

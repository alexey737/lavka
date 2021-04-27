#ifndef DEBUG
#define DEBUG
/**
* @file lib.h
*
* @brief Файл з об'явою прототипів функцій та структур
*
* @author Lavka O.
* @date 19-apr-2021
* @version 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>
#define MyTime __TIME__
#define MyDate __DATE__
#define MyFunc __func__
#define DATE(){ \
printf("\n\n——————————————————————————————————————————————————————————————————\n");\
printf("ТЕКУЩАЯ ДАТА: %s\n", MyDate);                                              \
printf("ТЕКУЩЕЕ ВРЕМЯ: %s\n", MyTime);                                             \
printf("——————————————————————————————————————————————————————————————————\n");    \
}
#define FUNC(){ \
printf("\nТЕКУЩАЯ ФУНКЦИЯ: %s\n", MyFunc);\
}
#define TIME(){ \
float time_spent = (float)(end - start) / CLOCKS_PER_SEC;\
printf("ВРЕМЯ РАБОТЫ ПРОГРАММЫ: %f секунд\n", time_spent);\
}


typedef struct {
	char name[100];
	char surname[100];
	char email[100];
} teacher;

typedef struct node{
	bool every_week;
	char predmet[100];
	int hours;
	enum place{ VK302, EK204, EK302, Karazina705 } audience;
	teacher myteacher;

  struct node *next;

} list;

/**
* @function read_from_file
*
*/
void read_from_file(list* head);

/**
* @function @write_to_file
*
*/
void print_list(list *head);

/**
* @function print_list
*
*/
void write_to_file(list *head);

/**
* @function print_list
*
*/
void search_discipline(list* head);

/**
* @function search_discipline
*
*/
void print_case(list* temp);

/**
* @function push_end
*
*/
void push_end(list* head);

/**
* @function delete_element
*
*/
void delete_element(list** head);

#endif

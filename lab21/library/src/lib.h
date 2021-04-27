#ifndef _LAVKA_21
#define _LAVKA_21

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
#define N 3


typedef struct {
	char name[100];
	char surname[100];
	char email[100];
} teacher;

typedef struct {
	bool every_week;
	char predmet[100];
	int hours;

	enum place{ NTU_VK_302, NTU_EK_204, NTU_EK_302, Karazina_705 } audience;

	teacher myteacher;

} discipline;

/**
*	@function insert
*
*/
char* insert(char* stroka1, char* stroka2, int index);

/**
*	@function reduce
*
*/
char* reduce(char* stroka, int index1, int index2);

/**
*	@function rand_fill
*
*/
void rand_fill(discipline* disc_arr, int n);

/**
*	@function output
*
*/
void output(discipline* disc_arr, int n);

/**
*	@function delete_element
*
*/
int delete_element(discipline* disc_arr, int n);

/**
*	@function add_element
*
*/
int add_element(discipline* disc_arr, int n);

#endif

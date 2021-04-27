/**
* @file lib.h
*
* @brief Файл з об'явою прототипів функцій та структур
*
* @author Lavka O.
* @date 17-apr-2021
* @version 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
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
* @function read_from_file
*
*/
void read_from_file(FILE* fread, discipline *disc_arr);

/**
*	@function write_to_file
*
*/
void write_to_file(FILE* fwrite, discipline *disc_arr);

/**
*	@function struct_output
*
*/
void struct_output(discipline *disc_arr);

/**
*	@function struct_sort
*
*/
void struct_sort(discipline* disc_arr);

/**
*	@function sort_case
*
*/
void sort_case(discipline* disc_arr, int n);

/**
*	@function search_discipline
*
*/
int search_discipline(discipline *disc_arr);

/**
*	@function rand_fill
*
*/
void rand_fill(discipline *disc_arr);

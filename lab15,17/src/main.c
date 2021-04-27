/**
* @mainpage
* # Загальне завдання
* 1. **Виконати завдання на оцінку добре**
* @author Lavka O.
* @date 17-apr-2021
* @version 1.0
*/

/**
* @file main.c
*
* @brief Файл з демонстрацією роботи структури та методів
* оперування ним.
*
* @author Lavka O.
* @date 17-apr-2021
* @version 1.0
*/


#include "lib.h"

int main()
{

	discipline disc_arr[N];						//масив структур discipline

	FILE *fread, *fwrite;
	fread = fopen("read.txt", "r");
	fwrite = fopen("write.txt", "w");

	read_from_file(fread, disc_arr);	//функція запису даних з файлу у масив структур
	struct_output(disc_arr);					//функція виводу масиву структур на екран
	write_to_file(fwrite, disc_arr);	//функція запису даних масиву структур в інший файл


	struct_sort(disc_arr);						//функція сортування массиву структур за обраним критерієм


	search_discipline(disc_arr);			//функція пошуку кількості предметів, які проводяться кожного тижня в аудиторії Каразіна 705
	rand_fill(disc_arr);							//функція рандомного завповнення массиву структур


	fclose(fread);
	fclose(fwrite);
	return 0;
}

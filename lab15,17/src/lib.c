/**
* @file lib.c
*
* @brief Файл з реалізацією функцій
*
* @author Lavka O.
* @date 17-apr-2021
* @version 1.0
*/

#include "lib.h"

void read_from_file(FILE *fread, discipline *disc_arr)
{
	char every_week[10];
	char audience[50];

	for (int i = 0; i < N; i++)
	{

		fscanf(fread, "%s", every_week);
		if (strcmp(every_week, "true") == 0)
		{
			disc_arr[i].every_week = true;
		}
		else if(strcmp(every_week, "false") == 0)
		{
			disc_arr[i].every_week = false;
		}

		fscanf(fread, "%s", &disc_arr[i].predmet);
		fscanf(fread, "%d", &disc_arr[i].hours);

		fscanf(fread, "%s", audience);
		if (strcmp(audience, "NTU_VK_302") == 0)
		{
			disc_arr[i].audience = 0;
		}
		else if (strcmp(audience, "NTU_EK_204") == 0)
		{
			disc_arr[i].audience = 1;
		}
		else if (strcmp(audience, "NTU_EK_302") == 0)
		{
			disc_arr[i].audience = 2;
		}
		else if (strcmp(audience, "Karazina_705") == 0)
		{
			disc_arr[i].audience = 3;
		}

		fscanf(fread, "%s", &disc_arr[i].myteacher.name);
		fscanf(fread, "%s", &disc_arr[i].myteacher.surname);
		fscanf(fread, "%s", &disc_arr[i].myteacher.email);
	}

}

void struct_output(discipline* disc_arr)
{
	for (int i = 0; i < N; i++)
	{
		printf("——————————————————————————————————————————————————————————————————\n");
		printf("Структура №%d:\n", i + 1);

		if (disc_arr[i].every_week == true)
		{
			printf("Чи проводиться кожного тижня: Так\n");
		}
		else
		{
			printf("Чи проводиться кожного тижня: Ні\n");
		}

		printf("Предмет: %s\n", disc_arr[i].predmet);
		printf("Кількість годин за семестр: %d\n", disc_arr[i].hours);

		if (disc_arr[i].audience == 0)
		{
			printf("Місце проведення занять: Аудиторія НТУ ХПІ ВК 302\n");
		}
		else if (disc_arr[i].audience == 1)
		{
			printf("Місце проведення занять: Аудиторія НТУ ХПІ EК 204\n");
		}
		else if (disc_arr[i].audience == 2)
		{
			printf("Місце проведення занять: Аудиторія НТУ ХПІ EК 204\n");
		}
		else if (disc_arr[i].audience == 3)
		{
			printf("Місце проведення занять: Аудиторія Каразіна 705\n");
		}

		printf("Викладач: %s %s\n", disc_arr[i].myteacher.name, disc_arr[i].myteacher.surname);
		printf("Електронна пошта викладача: %s\n", disc_arr[i].myteacher.email);
		printf("——————————————————————————————————————————————————————————————————\n\n");
	}
}

void write_to_file(FILE* fwrite, discipline* disc_arr)
{

	for (int i = 0; i < N; i++)
	{
		if (disc_arr[i].every_week == true)
		{
			fputs("true ", fwrite);
		}
		else if (disc_arr[i].every_week == false)
		{
			fputs("false ", fwrite);
		}

		fprintf(fwrite, "%s %d ", disc_arr[i].predmet, disc_arr[i].hours);

		if (disc_arr[i].audience == 0)
		{
			fputs("NTU_VK_302 ", fwrite);
		}
		else if (disc_arr[i].audience == 1)
		{
			fputs("NTU_EK_204 ", fwrite);
		}
		else if (disc_arr[i].audience == 2)
		{
			fputs("NTU_EK_302 ", fwrite);
		}
		else if (disc_arr[i].audience == 3)
		{
			fputs("Karazina_705 ", fwrite);
		}

		fprintf(fwrite, "%s %s %s", disc_arr[i].myteacher.name, disc_arr[i].myteacher.surname, disc_arr[i].myteacher.email);
		fputs("\n", fwrite);
	}

}

void struct_sort(discipline* disc_arr)
{
	printf("\n\n");
	printf("——————————————————————————————————————————————————————————————————\n");
	printf("Оберіть критерій для сортування:\n");
	printf("[1] Проведення предмету кожного тижня\n");
	printf("[2] Назва предмету\n");
	printf("[3] Кількість годин\n");
	printf("[4] Ім'я викладача\n");
	printf("[5] Прізвище викладача\n");
	printf("[6] Електронна пошта викладача\n");
	printf("——————————————————————————————————————————————————————————————————\n\n");


	int n;
	printf("Ваш критерій: ");
	scanf("%d", &n);


	switch (n)
	{
	case 1:
		sort_case(disc_arr, n);
		printf("\nВідсортований массив струтур:\n");
		struct_output(disc_arr);
		break;

	case 2:
		sort_case(disc_arr, n);
		printf("\nВідсортований массив струтур:\n");
		struct_output(disc_arr);
		break;

	case 3:
		sort_case(disc_arr, n);
		printf("\nВідсортований массив струтур:\n");
		struct_output(disc_arr);
		break;
	case 4:
		sort_case(disc_arr, n);
		printf("\nВідсортований массив струтур:\n");
		struct_output(disc_arr);
		break;

	case 5:
		sort_case(disc_arr, n);
		printf("\nВідсортований массив струтур:\n");
		struct_output(disc_arr);
		break;

	case 6:
		sort_case(disc_arr, n);
		printf("\nВідсортований массив струтур:\n");
		struct_output(disc_arr);
		break;

	default:
		break;
	}
}


void sort_case(discipline* disc_arr, int n)
{
	int temp1;			//тимчасова змінна для числових полів
	char temp2[100];	//тимчасова змінна для символьних полів
	bool temp3;			//тимчасова змінна для булевих полів

	if (n == 1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (disc_arr[j].every_week < disc_arr[j + 1].every_week)
				{
					strcpy(temp2, disc_arr[j + 1].predmet);
					strcpy(disc_arr[j + 1].predmet, disc_arr[j].predmet);
					strcpy(disc_arr[j].predmet, temp2);

					temp1 = disc_arr[j].hours;
					disc_arr[j].hours = disc_arr[j + 1].hours;
					disc_arr[j + 1].hours = temp1;

					strcpy(temp2, disc_arr[j + 1].myteacher.name);
					strcpy(disc_arr[j + 1].myteacher.name, disc_arr[j].myteacher.name);
					strcpy(disc_arr[j].myteacher.name, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.surname);
					strcpy(disc_arr[j + 1].myteacher.surname, disc_arr[j].myteacher.surname);
					strcpy(disc_arr[j].myteacher.surname, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.email);
					strcpy(disc_arr[j + 1].myteacher.email, disc_arr[j].myteacher.email);
					strcpy(disc_arr[j].myteacher.email, temp2);

					temp3 = disc_arr[j].every_week;
					disc_arr[j].every_week = disc_arr[j + 1].hours;
					disc_arr[j + 1].every_week = temp3;
				}
			}

		}
	}
	else if (n == 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (strcmp(disc_arr[j].predmet, disc_arr[j + 1].predmet) >= 0)
				{
					strcpy(temp2, disc_arr[j + 1].predmet);
					strcpy(disc_arr[j + 1].predmet, disc_arr[j].predmet);
					strcpy(disc_arr[j].predmet, temp2);

					temp1 = disc_arr[j].hours;
					disc_arr[j].hours = disc_arr[j + 1].hours;
					disc_arr[j + 1].hours = temp1;

					strcpy(temp2, disc_arr[j + 1].myteacher.name);
					strcpy(disc_arr[j + 1].myteacher.name, disc_arr[j].myteacher.name);
					strcpy(disc_arr[j].myteacher.name, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.surname);
					strcpy(disc_arr[j + 1].myteacher.surname, disc_arr[j].myteacher.surname);
					strcpy(disc_arr[j].myteacher.surname, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.email);
					strcpy(disc_arr[j + 1].myteacher.email, disc_arr[j].myteacher.email);
					strcpy(disc_arr[j].myteacher.email, temp2);

					temp3 = disc_arr[j].every_week;
					disc_arr[j].every_week = disc_arr[j + 1].hours;
					disc_arr[j + 1].every_week = temp3;
				}
			}

		}
	}


	else if (n == 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (disc_arr[j].hours < disc_arr[j+1].hours)
				{
					strcpy(temp2, disc_arr[j + 1].predmet);
					strcpy(disc_arr[j + 1].predmet, disc_arr[j].predmet);
					strcpy(disc_arr[j].predmet, temp2);

					temp1 = disc_arr[j].hours;
					disc_arr[j].hours = disc_arr[j + 1].hours;
					disc_arr[j + 1].hours = temp1;

					strcpy(temp2, disc_arr[j + 1].myteacher.name);
					strcpy(disc_arr[j + 1].myteacher.name, disc_arr[j].myteacher.name);
					strcpy(disc_arr[j].myteacher.name, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.surname);
					strcpy(disc_arr[j + 1].myteacher.surname, disc_arr[j].myteacher.surname);
					strcpy(disc_arr[j].myteacher.surname, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.email);
					strcpy(disc_arr[j + 1].myteacher.email, disc_arr[j].myteacher.email);
					strcpy(disc_arr[j].myteacher.email, temp2);

					temp3 = disc_arr[j].every_week;
					disc_arr[j].every_week = disc_arr[j + 1].hours;
					disc_arr[j + 1].every_week = temp3;
				}
			}

		}
	}

	else if (n == 4)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (strcmp(disc_arr[j].myteacher.name, disc_arr[j+1].myteacher.name) >= 0 )
				{
					strcpy(temp2, disc_arr[j + 1].predmet);
					strcpy(disc_arr[j + 1].predmet, disc_arr[j].predmet);
					strcpy(disc_arr[j].predmet, temp2);

					temp1 = disc_arr[j].hours;
					disc_arr[j].hours = disc_arr[j + 1].hours;
					disc_arr[j + 1].hours = temp1;

					strcpy(temp2, disc_arr[j + 1].myteacher.name);
					strcpy(disc_arr[j + 1].myteacher.name, disc_arr[j].myteacher.name);
					strcpy(disc_arr[j].myteacher.name, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.surname);
					strcpy(disc_arr[j + 1].myteacher.surname, disc_arr[j].myteacher.surname);
					strcpy(disc_arr[j].myteacher.surname, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.email);
					strcpy(disc_arr[j + 1].myteacher.email, disc_arr[j].myteacher.email);
					strcpy(disc_arr[j].myteacher.email, temp2);

					temp3 = disc_arr[j].every_week;
					disc_arr[j].every_week = disc_arr[j + 1].hours;
					disc_arr[j + 1].every_week = temp3;
				}
			}

		}
	}

	else if (n == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (strcmp(disc_arr[j].myteacher.surname, disc_arr[j + 1].myteacher.surname) >= 0)
				{
					strcpy(temp2, disc_arr[j + 1].predmet);
					strcpy(disc_arr[j + 1].predmet, disc_arr[j].predmet);
					strcpy(disc_arr[j].predmet, temp2);

					strcpy(temp2, disc_arr[j + 1].predmet);
					strcpy(disc_arr[j + 1].predmet, disc_arr[j].predmet);
					strcpy(disc_arr[j].predmet, temp2);

					temp1 = disc_arr[j].hours;
					disc_arr[j].hours = disc_arr[j + 1].hours;
					disc_arr[j + 1].hours = temp1;

					strcpy(temp2, disc_arr[j + 1].myteacher.name);
					strcpy(disc_arr[j + 1].myteacher.name, disc_arr[j].myteacher.name);
					strcpy(disc_arr[j].myteacher.name, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.surname);
					strcpy(disc_arr[j + 1].myteacher.surname, disc_arr[j].myteacher.surname);
					strcpy(disc_arr[j].myteacher.surname, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.email);
					strcpy(disc_arr[j + 1].myteacher.email, disc_arr[j].myteacher.email);
					strcpy(disc_arr[j].myteacher.email, temp2);

					temp3 = disc_arr[j].every_week;
					disc_arr[j].every_week = disc_arr[j + 1].hours;
					disc_arr[j + 1].every_week = temp3;
				}
			}

		}
	}
	else if (n == 6)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (strcmp(disc_arr[j].myteacher.email, disc_arr[j + 1].myteacher.email) >= 0)
				{
					strcpy(temp2, disc_arr[j + 1].predmet);
					strcpy(disc_arr[j + 1].predmet, disc_arr[j].predmet);
					strcpy(disc_arr[j].predmet, temp2);

					temp1 = disc_arr[j].hours;
					disc_arr[j].hours = disc_arr[j + 1].hours;
					disc_arr[j + 1].hours = temp1;

					strcpy(temp2, disc_arr[j + 1].myteacher.name);
					strcpy(disc_arr[j + 1].myteacher.name, disc_arr[j].myteacher.name);
					strcpy(disc_arr[j].myteacher.name, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.surname);
					strcpy(disc_arr[j + 1].myteacher.surname, disc_arr[j].myteacher.surname);
					strcpy(disc_arr[j].myteacher.surname, temp2);

					strcpy(temp2, disc_arr[j + 1].myteacher.email);
					strcpy(disc_arr[j + 1].myteacher.email, disc_arr[j].myteacher.email);
					strcpy(disc_arr[j].myteacher.email, temp2);

					temp3 = disc_arr[j].every_week;
					disc_arr[j].every_week = disc_arr[j + 1].hours;
					disc_arr[j + 1].every_week = temp3;
				}
			}

		}
	}
}

int search_discipline(discipline *disc_arr)
{
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		if ((disc_arr[i].audience == 3) && (disc_arr[i].every_week == true))
		{
			count++;
		}
	}

	printf("\n\n\nУсого я знайшов %d предметів, які проводяться кожного тижня в аудиторії Каразіна 705\n\n", count);

	return count;
}

void rand_fill(discipline *disc_arr)
{
	srand(time(NULL));
	for(int i = 0; i < N; i++)
	{
		disc_arr[i].every_week = rand() % 2;
		sprintf(disc_arr[i].predmet, "Предмет №%d", rand() % 15 + 10);
		disc_arr[i].hours = rand() % 12 + 11;
		sprintf(disc_arr[i].myteacher.name, "Викладач №%d", rand() % 14 + 12);
		sprintf(disc_arr[i].myteacher.email, "Електронна пошта викладача №%d", rand() % 13 + 15);
	}

	printf("\n\n——————————————————————————————————————————————————————————————————\n");
	printf("Рандомно заповнений масив структур\n");
	printf("——————————————————————————————————————————————————————————————————\n\n");


	for (int i = 0; i < N; i++)
	{
		printf("——————————————————————————————————————————————————————————————————\n");
		printf("Структура №%d:\n", i + 1);

		if (disc_arr[i].every_week == true)
		{
			printf("Чи проводиться кожного тижня: Так\n");
		}
		else
		{
			printf("Чи проводиться кожного тижня: Ні\n");
		}

		printf("%s\n", disc_arr[i].predmet);
		printf("Кількість годин за семестр: %d\n", disc_arr[i].hours);

		if (disc_arr[i].audience == 0)
		{
			printf("Місце проведення занять: Аудиторія НТУ ХПІ ВК 302\n");
		}
		else if (disc_arr[i].audience == 1)
		{
			printf("Місце проведення занять: Аудиторія НТУ ХПІ EК 204\n");
		}
		else if (disc_arr[i].audience == 2)
		{
			printf("Місце проведення занять: Аудиторія НТУ ХПІ EК 204\n");
		}
		else if (disc_arr[i].audience == 3)
		{
			printf("Місце проведення занять: Аудиторія Каразіна 705\n");
		}

		printf("%s\n", disc_arr[i].myteacher.name);
		printf("%s\n", disc_arr[i].myteacher.email);
		printf("——————————————————————————————————————————————————————————————————\n\n");
	}
}

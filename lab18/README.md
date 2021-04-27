# Загальне завдання
1. **Ознайомитися** з динамічними масивами та виконати всі завдання.

**Виконав: Лавка Олексій**

## Виконання роботи

**Мета:**
	Виконати завдання на оцінку "відмінно".

**Функціональне призначення**
	Програма призначена для роботи з динамічними масивами

## Написання коду програми

### Файл main.c
```
#include "lib.h"

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




    printf("\n\nЩо робити зі структурою:\n");
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


  return 0;

}

```

### Файл lib.h
```
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
```

### Файл lib.c

```
#include "lib.h"

char* insert(char* stroka1, char* stroka2, int index)
{

  int size = strlen(stroka1) + strlen(stroka2) + 1;


  char* str_res = NULL;
  str_res = (char*)malloc(size * sizeof(char));


  memcpy(str_res, stroka1, index);
  memcpy(str_res + index, stroka2, strlen(stroka2));
  memcpy(str_res + index + strlen(stroka2), stroka1 + index, strlen(stroka1) - index);


  printf("\n——————————————————————————————————————————————————————————————————\n");
  printf("Рядок №1: %s\n", stroka1);
  printf("Рядок №2: %s\n", stroka2);
  printf("Місце, куди вставляється другий рядок: символ за індексом %d\n", index);
  printf("Результат роботи функції: %s\n", str_res);
  printf("——————————————————————————————————————————————————————————————————\n\n\n");

  return str_res;
}

char* reduce(char* stroka, int index1, int index2)
{

  int size = strlen(stroka) - (index2 - index1);
  char* str_res = NULL;
  str_res = (char*)malloc(size * sizeof(char));


  memcpy(str_res, stroka, index1);
  memcpy(str_res + index1, stroka + index2 + 1, strlen(stroka) - index2);

  printf("\n——————————————————————————————————————————————————————————————————\n");
  printf("Заданий рядок: %s\n", stroka);
  printf("Видалення відбувається з %d символу по %d символ\n", index1, index2);
  printf("Pезультат роботи функції: %s\n", str_res);
  printf("——————————————————————————————————————————————————————————————————\n\n");


  return str_res;
}

void rand_fill(discipline *disc_arr, int n)
{

	for(int i = 0; i < n; i++)
	{
		disc_arr[i].every_week = rand() % 2;
		sprintf(disc_arr[i].predmet, "Предмет №%d", rand() % 14 + 10);
		disc_arr[i].hours = rand() % 12 + 11;
		sprintf(disc_arr[i].myteacher.name, "Викладач №%d", rand() % 14 + 12);
		sprintf(disc_arr[i].myteacher.email, "Електронна пошта викладача №%d", rand() % 13 + 15);
	}

}

void output(discipline* disc_arr, int n)
{
  for (int i = 0; i < n; i++)
	{
    printf("Структура №%d:\n", i + 1);
		printf("——————————————————————————————————————————————————————————————————\n");

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

    printf("Місце проведення занять: аудиторія №%d\n", rand()%100);

		printf("%s\n", disc_arr[i].myteacher.name);
		printf("%s\n", disc_arr[i].myteacher.email);
		printf("——————————————————————————————————————————————————————————————————\n\n");
	}
}

int delete_element(discipline* disc_arr, int n)
{

  if(n != 0)
  {

        printf("\nЯкий елемент структури видалити? (1 - %d)\n", n);
        printf("Ваш варіант: ");
        int index;
        scanf("%d", &index);
        index--;

        printf("\n");

        for(int i = index; i < n; i++)
        {
          memcpy((disc_arr + i), (disc_arr + i + 1), sizeof(discipline));
        }

        output(disc_arr, n-1);

        printf("\n\nВидалити структуру ще раз?\n");
        printf("[1] Так\n");
        printf("[2] Ні(вихід з програми)\n");
        printf("Ваш варіант: ");

        int check;
        scanf("%d", &check);

        if(check == 1)
        {
          delete_element(disc_arr, n-1);
        }else if(check == 2)
        {
          return n-1;
        }

    }else if(n == 0)
      {
        printf("\n\nМасив порожній\n");
        return n;
      }

}

int add_element(discipline* disc_arr, int n)
{
    discipline* new_element = NULL;
    new_element = (discipline*)malloc(1 * sizeof(discipline));

    rand_fill(new_element, 1);

    discipline *temp_arr = NULL;
    temp_arr = (discipline*)realloc(disc_arr, n * sizeof(discipline));


    free(disc_arr);
    disc_arr = (discipline*)malloc((n+1) * sizeof(discipline));

    for(int i = 0; i < n; i++)
    {
      memcpy((disc_arr + i), (temp_arr + i), sizeof(discipline));
    }


    memcpy((disc_arr + n), new_element, sizeof(discipline));

    output(disc_arr, n+1);

    printf("\n\nДодати ще одну структуру\n");
    printf("[1] Так\n");
    printf("[2] Ні(вихід з програми)\n");
    printf("Ваш варіант: ");

    int check;
    scanf("%d", &check);

    if(check == 1)
    {
      add_element(disc_arr, n+1);
    }
    else if(check == 2)
    {
      return n+1;
    }
}

```

## Блок-схема

![text](file:///home/aleksey/lavka/lab18/doc/lab18.jpg)

# Висновок
У ході цієї лабораторної роботи я ознайомився з динамічними масивами та виконав з ними завдання на оцінку відмінно та описав їх у цьому звіті.

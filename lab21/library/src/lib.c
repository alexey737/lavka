/**
* @file lib.c
*
* @brief Файл з реалізацією функцій
*
* @author Lavka O.
* @date 19-apr-2021
* @version 1.0
*/

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

        if(index >= 0 && index < n)
        {
          printf("\n");

          for(int i = index; i < n; i++)
          {
            memcpy((disc_arr + i), (disc_arr + i + 1), sizeof(discipline));
          }


            for (int i = 0; i < 3; i++)
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
        }
        else
        {
            printf("\n\nERROR! Елемента за таким індексом не існує!\nСпробуйте ще раз:\n\n");
            delete_element(disc_arr, n);
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
    else
    {
      printf("Немає такого варіанта!\nОберіть ще раз:\n\n");
      printf("\n\nДодати ще одну структуру\n");
      printf("[1] Так\n");
      printf("[2] Ні(вихід з програми)\n");
      printf("Ваш варіант: ");

      int check2;
      scanf("%d", &check2);

      if(check2 == 1)
      {
        add_element(disc_arr, n);
      }else if(check2 == 2)
      {
        return n+1;
      }
    }
}

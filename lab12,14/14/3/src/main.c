/**
* @mainpage
* # Загальне завдання
* 2. **Знайти** детермінант матриці, якщо він існує.
* @author Lavka O.
* @date 24-feb-2021
* @version 1.0
*/

/**
* @file main.c
*
* @brief Файл з демонстрацією роботи структури та методів
* оперування ним.
*
* @author Lavka O.
* @date 24-feb-2021
* @version 1.0
*/
#include <stdio.h>
#include <stdlib.h>
#define size 3

int determinant(int mas[size][size], int N, FILE *fp);

/**
* Головна функція
*
* Послідовність дій:
* - оголошення змінних
* @param fp покажчик на файл matr.txt
* @param num1 та @param num2 розмірність матриці mas
* @param mas задана матриця
* - відкриття файлу matr.txt для читання
* - запис у @param num1 та @param num2 кількість рядків та столбців матриці mas
* - якщо кількість рядків не доревнює кількості стовбців, тоді файл matr.txt закривається та програма завершується
* - якщо кількість рядків доревнює кількості стовбців, тоді виклик @fuction determinant
* - вивід результату роботи @function determinant
* - кінець роботи з файлом matr.txt
* - @return успішний код повернення з програми (0)
*/
int main()
{

  FILE *fp; //покажчик на файл
  fp = fopen("matr.txt", "r"); //відкриваємо файл для читання

  int num1 = 0; //кількість рядків матриці
  int num2 = 0; //кількість стовбців матриці
  fscanf(fp, "%d %d", &num1, &num2);

  /*якщо матриця не квадратна, тоді програма завершується*/
  if(num1 != num2)
  {

    fclose(fp); //завершуємо роботу з файлом
    printf("\nError: детермінант матриці знайти неможливо\n\n");
    exit(1);
  /*інакше знаходимо детермінант матриці*/
  }else{

    int N = num1;
    int mas[size][size] = {0};

    determinant(mas, N, fp);
    fclose(fp); //завершуємо роботу з файлом

  }

  return 0;

}

/**
* @function determinant
*
* Послідовність дій:
* - оголошення змінних
* @param det детермінант матриці
* @param temp тимчасова змінна
* - зчитування матриці з файлу та її запис у масив mas
* - вивід заданої матриці на екран
* - знаходження детермінанту матриці
* - @return логічну відповідь у консоль
*/
int determinant(int mas[size][size], int N, FILE *fp)
{
    float det = 0;  //детермінант матриці
    float temp = 0; //тимчасова змінна

    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < N; j++)
      {
        fscanf(fp, "%d", &*(*(mas+i)+j));
      }
    }

    printf("\n");
    printf("Задана матриця:");
    for(int i = 0; i < N; i++)
    {
      printf("\n");
      for(int j = 0; j < N; j++)
      {
      printf("%d ", *(*(mas+i)+j));
      }
    }

    printf("\n\n");

  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      if(j>i)
      {
      temp = *(*(mas+j)+i) / *(*(mas+i)+i);
      for(int k = 0; k < N; k++){
      *(*(mas+j)+k) -= temp * *(*(mas+i)+k);
    }
   }
  }
}
      det = 1;
      for(int i = 0; i < N; i++)
      {
        det *= *(*(mas+i)+i);
      }

  printf("Детермінат матриці: %.0f\n", det);

  return det;
}

#include "lib.h"


void test_insert();
void test_reduce();
void test_delete();
void test_add();
void menu();

int main()
{
  menu();

  return 0;
}


void menu()
{
  printf("\nЯкий тест ви бажаєте запустити?\n");
  printf("[1] Додання одного рядка в інший за індексом\n");
  printf("[2] Видалення елементів з рядка у заданому діапазоні\n");
  printf("[3] Видалення елементів з масиву\n");
  printf("[4] Додання елементів у масив\n");
  printf("[5] Вихід з тестів\n");
  printf("Ваш варіант: ");

  int choice;
  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      printf("\n----------------------------------Тест №1----------------------------------");
      test_insert();
      printf("---------------------------------------------------------------------------\n\n");
      break;

    case 2:
      printf("\n\n----------------------------------Тест №2----------------------------------");
      test_reduce();
      printf("-----------------------------------------------------------------------------\n\n");
      break;

    case 3:
      printf("\n\n----------------------------------Тест №3----------------------------------\n");
      test_delete();
      printf("\n-----------------------------------------------------------------------------\n\n");
      break;

    case 4:
      printf("\n\n----------------------------------Тест №4----------------------------------\n");
      test_add();
      printf("\n-----------------------------------------------------------------------------\n\n");
      break;

    case 5:
      printf("                  ТЕСТИ ЗАВЕРШЕНО!                  \n");
      exit(0);

    default:
      break;
  }

    printf("Бажаєье запустити тести ще раз?\n");
    printf("[1] Так\n");
    printf("[2] Ні (вихід з тестів)\n");
    printf("Ваш варіант: ");

    int check;
    scanf("%d", &check);

    switch (check)
    {
      case 1:
        menu();
        break;

      case 2:
      printf("                  ТЕСТИ ЗАВЕРШЕНО!                  \n");
      exit(0);
    }

}

void test_insert()
{
  char str1[] = "abrakadabra";
  char str2[] = "123";
  int index = 6;

  int size = strlen(str1) + strlen(str2);

  char* str_res = NULL;
  str_res = (char*)malloc(size * sizeof(char));

  strcpy(str_res, insert(str1, str2, index));

  if(strcmp(str_res, "abraka123dabra") == 0)
  {
    printf("Тест пройдено успішно!\n");
    printf("Функція повернула рядок %s\n", str_res);
  }
  else
  {
    printf("\nТест не пройдено!\n");
    printf("Функція повернула рядок %s\n", str_res);
  }
  free(str_res);
  str_res = NULL;
}

void test_reduce()
{
  char str[] = "abrakadabra";
  int index1 = 3;
  int index2 = 6;

  int size = strlen(str) - (index2 - index1);

  char* str_res = NULL;
  str_res = (char*)malloc(size * sizeof(char));

  strcpy(str_res, reduce(str, index1, index2));

  if(strcmp(str_res, "abrabra") == 0)
  {
    printf("\nТест пройдено успішно!\n");
  }
  else
  {
    printf("\nТест не пройдено!\n");
  }

  free(str_res);
  str_res = NULL;
}

void test_delete()
{
  int n = 3;

  discipline* test_arr;
  test_arr = (discipline*)malloc(n * sizeof(discipline));


  int bytes = sizeof(test_arr[0]); //Кількість потрібной пам'яті для 1 елементу массиву test_arr в байтах - 412

  rand_fill(test_arr, n);

  output(test_arr, n);

  int size = 0;
  for(int i = 0; i < n; i++)
  {
    size += sizeof(test_arr[i]); //розмір усього массиву в байтах
  }


  int cnt = delete_element(test_arr, n);


  if ( (cnt * bytes) == (size - ((n - cnt) * bytes)) )
  {
    printf("\nТест пройдено успішно!\nУ результаті функції з масиву test_arr повернулося: %d елемент(ів)\n", cnt);
  }
  else
  {
    printf("\nТест не пройдено!\nФункція повернула неправильну кількість елементів\n");
  }


  free(test_arr);
  test_arr = NULL;
}

void test_add()
{
  int n = 3;

  discipline* test_arr;
  test_arr = (discipline*)malloc(n * sizeof(discipline));


  int bytes = sizeof(test_arr[0]); //Кількість потрібной пам'яті для 1 елементу массиву test_arr в байтах - 412

  rand_fill(test_arr, n);


  int size = 0;
  for(int i = 0; i < n; i++)
  {
    size += sizeof(test_arr[i]); //розмір усього массиву в байтах
  }

  int cnt = add_element(test_arr, n);


  if ( (cnt * bytes) == (size + (bytes * (cnt - n))) )
  {
    printf("\nТест пройдено успішно!\nУ результаті функції з масиву test_arr повернулося: %d елемент(ів)\n", cnt);
  }
  else
  {
    printf("\nТест не пройдено!\nФункція повернула неправильну кількість елементів\n");
  }

  free(test_arr);
  test_arr = NULL;
}

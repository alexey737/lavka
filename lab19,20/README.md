# Загальне завдання
1. **Виконати** всі завдання на оцінку "задовільно" для списків та завдання на оцінку "добре" для макровизначень.

**Виконав: Лавка Олексій**

## Виконання роботи

**Мета:**
	Виконати завдання на оцінку "задовільно" та "добре".

**Функціональне призначення**
	Програма призначена для роботи з динамічними списками та макровизнаеннями

## Написання коду програми

### Файл main.c
```
#include "lib.h"

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

```

### Файл lib.h
```
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
	enum place{ NTU_VK_302, NTU_EK_204, NTU_EK_302, Karazina_705 } audience;
	teacher myteacher;

  struct node *next;

} list;


void read_from_file(list* head);

void print_list(list *head);

void write_to_file(list *head);

void search_discipline(list* head);

void print_case(list* temp);

void push_end(list* head);

void delete_element(list** head);

#endif
```

### Файл lib.c

```
#include "lib.h"


void read_from_file(list* head)
{

  FUNC(); //название текущей функции


  FILE* fread;
  fread = fopen("read.txt", "r");

  if(fread == NULL)
  {
    fprintf(stderr, "ERROR! Не удалось открыть файл с таким названием!\n");
    return 1;
  }

  size_t count = 0;
  while(!feof(fread))
  {
    if(fgetc(fread) == '\n')
    {
      count++;
    }
  }

  rewind(fread);
  list* current = head;

  char every_week[20];
  char audience[20];
  for(size_t i = 0; i < count; i++)
  {
    while(current->next != NULL)
    {
      current = current->next;
    }

    fscanf(fread, "%s", every_week);
    if(strcmp(every_week, "true") == 0)
    {
      current->every_week = true;
    }
    else
    {
      current->every_week = false;
    }

    fscanf(fread, "%s", current->predmet);
    fscanf(fread, "%d", &current->hours);
    fscanf(fread, "%s", audience);
    if (strcmp(audience, "NTU_VK_302") == 0)
    {
      current->audience = 0;
    }
    else if (strcmp(audience, "NTU_EK_204") == 0)
    {
      current->audience = 1;
    }
    else if (strcmp(audience, "NTU_EK_302") == 0)
    {
      current->audience = 2;
    }
    else if (strcmp(audience, "Karazina_705") == 0)
    {
      current->audience = 3;
    }

    fscanf(fread, "%s", current->myteacher.name);
    fscanf(fread, "%s", current->myteacher.surname);
    fscanf(fread, "%s", current->myteacher.email);

      if(count - i != 1)
      {
        current->next = (list*)malloc(sizeof(list));
      }
  }

  fclose(fread);
}


void write_to_file(list *head)
{

  FUNC(); //название текущей функции


  FILE *fwrite;
  fwrite = fopen("write.txt", "w");

    if(fwrite == NULL)
    {
      fprintf(stderr, "ERROR! Не удалось открыть файл с таким названием!\n");
      return 1;
    }

    list* temp = head;
    while(temp != NULL)
    {
      if (temp->every_week == true)
  		{
  			fprintf(fwrite, "%s ", "true");
  		}
  		else if (temp->every_week == false)
  		{
  			fprintf(fwrite, "%s ", "false");
  		}

  		fprintf(fwrite, "%s %d ", temp->predmet, temp->hours);

  		if (temp->audience == 0)
  		{
        fprintf(fwrite, "%s ", "НТУ_ВK_302");
  		}
  		else if (temp->audience == 1)
  		{
        fprintf(fwrite, "%s ", "НТУ_EK_204");
  		}
  		else if (temp->audience == 2)
  		{
        fprintf(fwrite, "%s ", "НТУ_EK_302");
  		}
  		else if (temp->audience == 3)
  		{
        fprintf(fwrite, "%s ", "Каразина_705");
  		}

  		fprintf(fwrite, "%s %s %s\n", temp->myteacher.name, temp->myteacher.surname, temp->myteacher.email);
      temp = temp->next;
    }


  fclose(fwrite);
}


void print_list(list *head)
{

  FUNC(); //название текущей функции


  list* temp = head;

  while(temp != NULL)
  {
    printf("——————————————————————————————————————————————————————————————————\n");
		if (temp->every_week == true)
		{
			printf("Чи проводиться кожного тижня: Так\n");
		}
		else
		{
			printf("Чи проводиться кожного тижня: Нет\n");
		}

		printf("Предмет: %s\n", temp->predmet);
		printf("Кількість годин за семестр: %d\n", temp->hours);

		if (temp->audience == 0)
		{
			printf("Місце проведення занять: Аудиторія НТУ ХПІ ВК 302\n");
		}
		else if (temp->audience == 1)
		{
			printf("Місце проведення занять: Аудиторія НТУ ХПІ EК 204\n");
		}
		else if (temp->audience  == 2)
		{
			printf("Місце проведення занять: Аудиторія НТУ ХПІ EК 302\n");
		}
		else if (temp->audience == 3)
		{
			printf("Місце проведення занять: Аудиторія Каразіна 705\n");
		}

		printf("Викладач: %s %s\n", temp->myteacher.name, temp->myteacher.surname);
		printf("Електронна пошта викладача: %s\n", temp->myteacher.email);
		printf("——————————————————————————————————————————————————————————————————\n\n");
    temp = temp->next;
  }
}


void print_case(list* temp)
{

  FUNC(); //название текущей функции


  printf("——————————————————————————————————————————————————————————————————\n");
  if (temp->every_week == true)
  {
    printf("Чи проводиться кожного тижня: Так\n");
  }
  else
  {
    printf("Чи проводиться кожного тижня: Ні\n");
  }

  printf("Предмет: %s\n", temp->predmet);
  printf("Кількість годин за семестр: %d\n", temp->hours);

  if (temp->audience == 0)
  {
    printf("Місце проведення занять: Аудиторія НТУ ХПІ ВК 302\n");
  }
  else if (temp->audience == 1)
  {
    printf("Місце проведення занять: Аудиторія НТУ ХПІ EК 204\n");
  }
  else if (temp->audience  == 2)
  {
    printf("Місце проведення занять: Аудиторія НТУ ХПІ EК 302\n");
  }
  else if (temp->audience == 3)
  {
    printf("Місце проведення занять: Аудиторія Каразіна 705\n");
  }

  printf("Викладач: %s %s\n", temp->myteacher.name, temp->myteacher.surname);
  printf("Електронна пошта викладача: %s\n", temp->myteacher.email);
  printf("——————————————————————————————————————————————————————————————————\n\n");
}


void search_discipline(list* head)
{

  FUNC(); //название текущей функции


  printf("Хотите найти предмет?\n[1] Да\n[2] Нет\n");
  printf("Ваш вариант: ");
  int check;
  scanf("%d", &check);
  if(check == 1)
  {
    printf("\n\nПо какому критерию искать дисциплину?\n");
    printf("[1] Проводится ли предмет каждую неделю\n");
    printf("[2] Название предмета\n");
    printf("[3] Количество часов дисциплины\n");
    printf("[4] Аудитория, где проводятся занятия\n");
    printf("[5] Имя преподователя\n");
    printf("[6] Фамилия преподователя\n");
    printf("[7] Електронная почта преподователя\n");
    printf("Ваш вариант: ");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
        printf("\nПроводится ли предмет каждую неделю?\n");
        printf("[1] Да\n");
        printf("[2] Нет\n");

        int check;
        scanf("%d", &check);

        list* temp = head;
        if(check == 1)
        {
          while(temp != NULL)
          {
            if(temp->every_week == true)
            {

              print_case(temp);
              temp = temp->next;
            }
            else if(temp->every_week != true)
            {
              temp = temp->next;
            }
          }
        }
        else if(check == 2)
        {
          while(temp != NULL)
          {
            if(temp->every_week == false)
            {

              print_case(temp);
              temp = temp->next;
            }
            else if(temp->every_week != false)
            {
              temp = temp->next;
            }
          }
        }
        break;

      case 2:
        printf("Введите название предмета: ");
        char predmet[50];
        scanf("%s", predmet);

        list* temp2 = head;
        while (temp2 != NULL)
        {
          if(strcmp(temp2->predmet, predmet) == NULL)
          {
            print_case(temp2);
            temp2 = temp2->next;
          }
          else if(strcmp(temp2->predmet, predmet) != NULL)
          {
            temp2 = temp2->next;
          }
        }
        break;

      case 3:
        printf("Введите количество часов дисциплины: ");
        int hours;
        scanf("%d", &hours);

        list* temp3 = head;
        while (temp3 != NULL)
        {
          if(temp3->hours == hours)
          {
            print_case(temp3);
            temp3 = temp3->next;
          }
          else if(temp3->hours != hours)
          {
            temp3 = temp3->next;
          }
        }
        break;

      case 4:
        printf("\nВыбирите аудиторию, где проводятся занятия\n");
        printf("[1] НТУ ВК 302\n");
        printf("[2] НТУ ЕК 204\n");
        printf("[3] НТУ ЕК 302\n");
        printf("[4] Каразина 705\n");
        printf("Ваш вариант: ");
        int check2;
        scanf("%d", &check2);

        list* temp4 = head;

        if(check2 == 1)
        {
          while (temp4 != NULL)
          {
            if(temp4->audience == 0)
            {
              print_case(temp4);
              temp4 = temp4->next;
            }
            else if(temp4->audience != 0)
            {
              temp4 = temp4->next;
            }
          }
        }
        else if(check2 == 2)
        {
          while (temp4 != NULL)
          {
            if(temp4->audience == 1)
            {
              print_case(temp4);
              temp4 = temp4->next;
            }
            else if(temp4->audience != 1)
            {
              temp4 = temp4->next;
            }
          }
        }
        else if(check2 == 3)
        {
          while (temp4 != NULL)
          {
            if(temp4->audience == 2)
            {
              print_case(temp4);
              temp4 = temp4->next;
            }
            else if(temp4->audience != 2)
            {
              temp4 = temp4->next;
            }
          }
        }
        else if(check2 == 4)
        {
          while (temp4 != NULL)
          {
            if(temp4->audience == 3)
            {
              print_case(temp4);
              temp4 = temp4->next;
            }
            else if(temp4->audience != 3)
            {
              temp4 = temp4->next;
            }
          }
        }
        break;

      case 5:
        printf("Введите имя преподователя: ");
        char name[50];
        scanf("%s", name);

        list* temp5 = head;
        while (temp5 != NULL)
        {
          if(strcmp(temp5->myteacher.name, name) == NULL)
          {
            print_case(temp5);
            temp5 = temp5->next;
          }
          else if(strcmp(temp5->myteacher.name, name) != NULL)
          {
            temp5 = temp5->next;
          }
        }
        break;

      case 6:
        printf("Введите фамилию преподователя: ");
        char surname[50];
        scanf("%s", surname);

        list* temp6 = head;
        while (temp6 != NULL)
        {
          if(strcmp(temp6->myteacher.surname, surname) == NULL)
          {
            print_case(temp6);
            temp6 = temp6->next;
          }
          else if(strcmp(temp6->myteacher.surname, surname) != NULL)
          {
            temp6 = temp6->next;
          }
        }
        break;

      case 7:
        printf("Введите электронную почту преподователя: ");
        char email[50];
        scanf("%s", email);

        list* temp7 = head;
        while (temp7 != NULL)
        {
          if(strcmp(temp7->myteacher.email, email) == NULL)
          {
            print_case(temp7);
            temp7 = temp7->next;
          }
          else if(strcmp(temp7->myteacher.email, email) != NULL)
          {
            temp7 = temp7->next;
          }
        }
        break;

      default:
        break;
     }
   }
   else if(check == 2)
   {
     return;
   }
}


void push_end(list* head)
{

  FUNC(); //название текущей функции


  printf("\nЖелаете добавить новый предмет?\n");
  printf("[1] Да\n");
  printf("[2] Нет\n");
  printf("Ваш вариант: ");
  int check;
  scanf("%d", &check);

  if(check == 1)
  {
    list* temp = head;
    list* new_element = (list*)malloc(sizeof(list));
    char every_week[10];
    char predmet[50];
    int hours;
    int audience;
    char name[50];
    char surname[50];
    char email[50];

    printf("Проводится ли ваш предмет каждую неделю (Да или Нет): ");
    scanf("%s", every_week);
    if(strcmp(every_week, "Да") == NULL)
    {
      new_element->every_week = true;
    }
    else if(strcmp(every_week, "Нет"))
    {
      new_element->every_week = false;
    }
    printf("Введите название предмета: ");
    scanf("%s", predmet);
    strcpy(new_element->predmet, predmet);
    printf("Введите количество часов вашей дисциплины: ");
    scanf("%d", &hours);
    new_element->hours = hours;
    printf("В какой аудитории проводятся занятия?\n");
    printf("[1]НТУ ВК 302\n[2]НТУ ЕК 204\n[3]НТУ ЕК 302\n[4]Каразина 705\n");
    printf("Ваш вариант: ");
    scanf("%d", &audience);
    if(audience == 1)
    {
      new_element->audience = 0;
    }
    else if(audience == 2)
    {
      new_element->audience = 1;
    }
    else if(audience == 3)
    {
      new_element->audience = 2;
    }
    else if(audience == 4)
    {
      new_element->audience = 4;
    }
    printf("Введите имя преподователя: ");
    scanf("%s", name);
    strcpy(new_element->myteacher.name, name);
    printf("Введите фамилию преподователя: ");
    scanf("%s", surname);
    strcpy(new_element->myteacher.surname, surname);
    printf("Введите электронную почту преподователя: ");
    scanf("%s", email);
    strcpy(new_element->myteacher.email, email);

    if(temp->next == NULL)
    {
      new_element->next = temp->next;
      temp->next = new_element;
    }
    else
    {
      while(temp->next != NULL)
      {
        temp = temp->next;
      }
      new_element->next = temp->next;
      temp->next = new_element;
    }
  }
  else if(check == 2)
  {
    return;
  }
}


void delete_element(list** head)
{

  FUNC(); //название текущей функции


  printf("Хотите удалить предмет?\n[1] Да\n[2] Нет\n");
  printf("Ваш вариант: ");
  int check;
  scanf("%d", &check);
  if(check == 1)
  {
    list* current = *head; //для поиска элемента, который мы удаляем
    list* temp = *head;    //для подсчета количества элементов в списке
    list* del = (list*)malloc(sizeof(list)); //место под элемент, который мы удаляем
    list* prev = (list*)malloc(sizeof(list)); //место под элемент, который стоит перед элементом удаления

    int count = 0;
    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }

    printf("Введите номер элемента, который хотите удалить (1-%d): ", count);
    int num;
    scanf("%d", &num);

    if(num == 1)
    {
      del = current;
      current = current->next;
      *head = current;
      free(del);
    }
    else if(num != 1)
    {
      for(int i = 1; i < num; i++)
      {
        if(i + 1 == num)
        {
          prev = current;
          current = current->next;
          del = current;

          prev->next = del->next;
          del->next = NULL;
          free(del);
        }
        else
        {
          current = current->next;
        }
      }
    }
  }
  else if(check == 2)
  {
    return;
  }
}
```

## Блок-схема

![text](file:///home/aleksey/lavka/lab19,20/doc/lab19,20.jpg)

# Висновок
У ході цієї лабораторної роботи я ознайомився з динамічними списками та макровизначеннями, виконав з ними завдання та описав їх у цьому звіті.

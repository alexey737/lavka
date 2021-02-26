#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#define size 100

int main()
{

  struct stat statbuf; //створення структури stat
  FILE *fp; //покажчик на файл

  char fname[size]; //масив, в який записується директорія росполження файлу
  printf("Введіть повне росположення файлу: ");
  scanf("%s", fname);

  fp = fopen(fname, "r"); //відкриваємо заданий файл для читання

  /*якщо файл неможливо відкрити, тоді програма завершується*/
  if(fp == NULL)
  {
    printf("\nError: неможливо відкрити файл, спробуйте ще раз.\n\n");
    return 1;
  }

  fstat(fileno(fp), &statbuf); //запис інформації про файл у структуру stat

  printf("\nАтрибути заданого файлу:\n");

  if(statbuf.st_mode & S_IFCHR)
    printf("Це пристрій\n");

  if(statbuf.st_mode & S_IFREG)
    printf("Це файл\n");

  if(statbuf.st_mode & S_IREAD)
    printf("Дозвіл на читання\n");

  if(statbuf.st_mode & S_IWRITE)
    printf("Дозвіл на запис\n");

  printf("Мітка диска: %c\n", 'A' + statbuf.st_dev);
  printf("Розмір запитаного файлу: %ld bytes\n", statbuf.st_size);
  printf("Час останнього відкриття: %s\n", ctime(&statbuf.st_ctime));

  fclose(fp); //завершуємо роботу з файлом

    return 0;
}

#include <lib.h>

void test_search();

int main()
{

  test_search();

  return 0;
}


void test_search()
{
  discipline test_arr[N];

  test_arr[0].audience = 3;
  test_arr[0].every_week = false;
  test_arr[1].audience = 3;
  test_arr[1].every_week = true;
  test_arr[2].audience = 1;
  test_arr[2].every_week = true;

  int cnt = search_discipline(test_arr);

  if(cnt == 1)
  {
    printf("\nТест пройдено успішно!\n");
  }
  else
  {
    printf("\nТест не пройдено!\n");
  }
}

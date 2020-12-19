#  Загальне завдання
1. *Помножити* матрицю саму на себе.

**Виконання роботи**
1. **Функціональне призначення**
	Програма призначена для знаходження квадрату матриці.
	
2. Написання коду програми
```
#define size 3            //размерность матрицы
void matr_v_kvadrate(int mas[size][size]);  

int main(){
int mas[size][size] = {   
{2, 4 ,5},    
{1, 6, 7},
{3, 8, 1}     
};
matr_v_kvadrate(mas);             
return 0;
}

void matr_v_kvadrate(int mas[size][size]){
int res[size][size] = {0};
//цикл для возведения матрицы в квадрат
for(int i = 0; i < size; i++){
  for(int j = 0; j < size; j++){
    for(int k = 0; k < size; k++){
    res[i][j] += mas[i][k]*mas[k][j];
      }
    }
  }
}

```
3. Компіляція програми та перевірка на правильність її роботи через nemiver 

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/6/doc/nemiver6.6.png)

4.Блок-схема

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/6/doc/6.6.png)

**Висновок**
Я створив програму, яка знаходить квадрат матриці.


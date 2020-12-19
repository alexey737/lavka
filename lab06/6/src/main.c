#include <stdio.h>
int main(){
#define size 3           //размерность матрицы
int mas[size][size] = {   
{2, 4 ,5},    
{1, 6, 7},
{3, 8, 1}     
};
int res[size][size] = {0};       //результат умножения матрицы самой на себя
//цикл для возведения матрицы в квадрат
for(int i = 0; i < size; i++){
  for(int j = 0; j < size; j++){
  res[i][j] = 0;
    for(int k = 0; k < size; k++){
    res[i][j] += mas[i][k]*mas[k][j];
   
    }
  }
}



return 0;
}

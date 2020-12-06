#include <stdio.h>
int main(){
#define N 3           //размерность матрицы
int mas[N][N] = {   
{2, 4 ,5},    
{1, 6, 7},
{3, 8, 1}     
};
int res[N][N];        //результат умножения матрицы самой на себя
//цикл для возведения матрицы в квадрат
for(int i = 0; i < N; i++){
  for(int j = 0; j < N; j++){
  res[i][j] = 0;
    for(int k = 0; k < N; k++){
    res[i][j] += mas[i][k]*mas[k][j];
   
    }
  }
}



return 0;
}

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


#include <stdio.h>
int main(){            
#define size 5         // размерность массива  
int n = size*10;       // число, чтобы заполнить простыми числами весь массив
int mas[size];        
int i, j, z;
int a = 0;             // индекс элемента массива
// цикл для перебора простых чисел
  for(i = 2; i < n; i++){
  z = 0;               // число простое
  for(j = 2; j < i; j++){
  if(i % j == 0){
  z = 1;               // число сложное
      break;
    }      
}
  if(z == 0){
  mas[a] = i;
  printf("%d ", mas[a]);
     a++;
   if(a == size){
      break;
    }
  }

} 

   return 0;
} 

#include <stdio.h>
int main(){            
#define size 5         // размерность массива  
int mas[size];        
int i, j;
int p = 0;             // проверка числа на простоту
int a = 0;             // индекс элемента массива
// цикл для перебора простых чисел
  for(i = 2; i < size; i++){      
    for(j = 2; j < i; j++){
      if(i % j != 0){ 
      p = 0;               // число простое
     }else{
      p = 1;               // число сложное
      break;
    }      
}
  if(p == 0){
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

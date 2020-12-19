#include <stdio.h>
#define size 10         // розмірність масиву
void zap(int mas[size]); 

int main(){     
int mas[size] = {0};
zap(mas);        
return 0;
} 

void zap(int mas[size]){     
int i, j;
int p = 0;             // перевірка числа на простоту
int a = 0;             // індекс елемента масиву
// цикл для перебору простих чисел
  for(i = 2; i < size; i++){      
    for(j = 2; j < i; j++){
      if(i % j != 0){ 
      p = 0;               // число просте
     }else{
      p = 1;               // число складне
      break;
    }      
}
  if(p == 0){
  mas[a] = i;

     a++;
   if(a == size){
      break;
      }
    }
  }
} 

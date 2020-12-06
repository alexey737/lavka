
int main(){
int n = 20;            // число, чтобы заполнить простыми числами весь массив
#define size 5         // размер массива
int mas[size];
int i, j, g, k = 0;
// цикл для перебора простых чисел
  for(i = 2; i <= n; i++){
      g = 0;
      for(j = 2; j < i; j++){
      if(i % j == 0){
      g = 1;
      break;
         }      
      }
      if(g == 0){
      mas[k] = i;
      k++;
        if(k == size){
        break;
        }
    }
  } 
   
   return 0;
} 

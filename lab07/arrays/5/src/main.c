#define size 3       //розмір масива
void zdvig(int mas1[size][size]);  

int main(){
int mas1[size][size] = {  //даний масив
{2, 5, 6},
{1, 7, 3},
{2, 5, 3}
};
zdvig(mas1);
return 0;
}

void zdvig(int mas1[size][size]){
int mas2[size][1];   //маисв для зберігання 1 стовбця даного масиву
int i;               //рядки масиву
int j;               //стовбці масиву
//цикл для перенесення 1 стовбця даного масиву в масив для його зберігання
for(i = 0; i < size; i++){
   mas2[i][0] = mas1[i][0];
   }
//цикл для циклічного зсуву у напряку справа наліво 
for(i = 0; i < size; i++){
  for(j = 0; j < size; j++){
  mas1[i][j] = mas1[i][j+1];
  }
}
//цикл для занесення 1 стовбця даного масиву на місто останнього
for(i = 0; i < size; i++){
mas1[i][size-1] = mas2[i][0];
 }
}

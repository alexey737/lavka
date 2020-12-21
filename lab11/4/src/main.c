#include <stdio.h>
#define size 4

int main(){
int mas[size][size];   //масив цілих чисел 
int a = 0;		//індекс елементу результуючого масиву 
int num;
int res[size] = {0};   //результуючий масив
int *pRes = res;       //показник на перший елемент результуючого масиву
/*цикл заповнення даного масиву випадковими цілими числами*/
for(int i = 0; i < size; i++){
	printf("\n");
	for(int j = 0; j < size; j++){
		*(*(mas+i)+j) = rand()%10;
		printf("%d ", mas[i][j]);
	}
}
printf("\n\n");
/*цикл перенесення чисел головної діагоналі масиву в результуючий масив*/
for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){
		if(i == j){
		pRes[a] = *(*(mas+i)+j);
		printf("%d ", res[a]);
		a++;
		} 
	}
}
/*цикл упорядкування чисел головної діагоналі масиву за зростанням*/
for(int i = 0; i < size-1; i++){
	for(int j = 0; j < size-i-1; j++){
		if( *(res+j) > *(res+j+1) ){
		num = *(res+j+1);
		*(res+j+1) = *(res+j);
		*(res+j) = num;
		}
	}
}

return 0;
}

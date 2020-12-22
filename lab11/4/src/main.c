#include <stdio.h>
#define size 6
void zap(int mas[size][size]);
void perenos(int mas[size][size], int res[size]);
void por(int res[size]);

int main(){
int mas[size][size];   //масив цілих чисел 
int res[size] = {0};   //результуючий масив
zap(mas);
perenos(mas, res);
por(res);
return 0;
}

/*функція заповнення даного масиву випадковими цілими числами*/
void zap(int mas[size][size]){
for(int i = 0; i < size; i++){
	printf("\n");
	for(int j = 0; j < size; j++){
		*(*(mas+i)+j) = rand()%10;
		printf("%d ", *(*(mas+i)+j));
	}
}
printf("\n\n");
}

/*функція перенесення чисел головної діагоналі масиву в результуючий масив*/
void perenos(int mas[size][size], int res[size]){
int a = 0;		//індекс елементу результуючого масиву 
for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){
		if(i == j){
		*(res+a) = *(*(mas+i)+j);
		printf("%d ", *(res+a));
		a++;
		} 
	  }
    }
    printf("\n\n");
}


/*функція упорядкування чисел головної діагоналі масиву за зростанням*/
void por(int res[size]){
int num;               //допоміжна змінна
for(int i = 0; i < size-1; i++){
	for(int j = 0; j < size-i-1; j++){
		if( *(res+j) > *(res+j+1) ){
		num = *(res+j+1);
		*(res+j+1) = *(res+j);
		*(res+j) = num;
		}
	}
    }
for(int i = 0; i < size; i++){
	printf("%d ", *(res+i));
}
}

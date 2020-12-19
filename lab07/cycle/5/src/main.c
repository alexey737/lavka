#include <stdio.h>
float result(float num);

int main() {
float num = 9;
result(num); 
return 0;
}


float result(float num){
float koren, x1, x2;
for (float i = 1.0; i < num; i++) {
	if (num == i * i) {
	koren = i;
	printf("%.0f", koren);       
	break;	        
	}else if ((i*i) > num){
	 x1 = (((num/(i-1)) + (i-1))/2);      
	 x2 = (num/(((num/(i-1)) + (i-1))/2));  
         koren = ((x1 + x2)/2); 
         printf("%.4f", koren); 
         break;    
        }
}	
return koren;
}


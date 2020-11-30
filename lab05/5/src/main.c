
int main() {
	float num = 16.0;
	int i;
	float x1, x2, koren;
	for (i = 1; i < num; i++) {
			if (num == i * i) {
			koren = i;       /* квадратний корінь числа */
			break;
		        
			}else if ((i*i) > num) { 
		            x1 = (((num/(i-1)) + (i-1))/2);        /* формула отримання квадратного корня */
		            x2 = (num/(((num/(i-1)) + (i-1))/2));  /* формула отримання квадратного корня */      
		            koren = ((x1 + x2)/2); /* квадратний корінь числа */
		            break;    
		}
	}
	
	/* i = 1; 
	while(i < num){
	i++;
	if (num == i * i) {
			koren = i; // квадратний корінь числа 
			break;
		        
			}else if ((i*i) > num) { 
		            x1 = (((num/(i-1)) + (i-1))/2);      
		            x2 = (num/(((num/(i-1)) + (i-1))/2));  
		            koren = ((x1 + x2)/2); //квадратний корінь числа 
		            break;    
		}
	}
	
	i = 1;
	do{
	i++;
	if (num == i * i) {
			koren = i; //квадратний корінь числа
			break;
		        
			}else if ((i*i) > num) { 
		            x1 = (((num/(i-1)) + (i-1))/2);       
		            x2 = (num/(((num/(i-1)) + (i-1))/2));  
		            koren = ((x1 + x2)/2); //квадратний корінь числа
		            break;    
		}
	}while (i < num); */
	
	return 0;
}

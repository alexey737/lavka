
int main() {
	float num = 16.0;
	int i;
	float x1, x2, koren;
	for (i = 1; i < num; i++) {
			if (num == i * i) {
			koren = i; //квадратний корінь числа
			break;
		        
			}else if ((i*i) > num) { 
		            x1 = (((num/(i-1)) + (i-1))/2);        //допоміжна дана для формули
		            x2 = (num/(((num/(i-1)) + (i-1))/2));  //допоміжна дана для формули
		            koren = ((x1 + x2)/2); //формула отримання квадратного корня числа
		            break;    
		}
	}
	
	return 0;
}

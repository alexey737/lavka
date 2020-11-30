#include <stdio.h>
int main() {
	int x = 6;                                /* задане число*/
	int res;                                  /* резултат ділення числа на дільник */
	int del = 1;                              /* дільник */
		while (del <= x) {                /* цикл while */ 
		del++;                            /* змінна del збільшується на 1 */
		res = x % del;                    /* рахуємо чому дорівнює змінна res */
		if (res == 0) {                   /* перевірка змінної res на рівність 0 */  
			if (x == del) {           /* перевірка на рівність змінних х та del */
				printf("Число просте");
				break;
			}
			else if (x != del) {      /* перевірка на нерівність змінних x та del*/
				printf("Число складне");
				break;
			}
		}
		
	}
	
	 /*do {
	    res = x % del;
		del++;
			if (res == 0) {
				if (x == del) {
						printf("Число просте");
						break;

				}
				else if (x != del) {
				printf("Число складне");
				break;
				}
			}
			
	} while (del <= x);*/
	
	/*for (del = 1; del++; del <= x){
	    res = x % del;
		if (res == 0) {
			if (x == del) {
				printf("Число просте");
				break;
			}
			else if (x != del) {
				printf("Число складне");
				break;
			}
		}
		

	}*/

	return 0;
}

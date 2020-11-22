#include <stdio.h>
int main(){
        int nod;
        int a = 126, b = 48;
        while(a != b) {
           if (a > b){
              a = a-b;   
              nod = a;                     
           }else{
              b = b-a;   
              nod = b;
          }
          
       }   
              
          printf("НОД = %d", nod);         
return 0;              
}

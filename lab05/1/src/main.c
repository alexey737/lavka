#include <stdio.h>
int main(){
        int nod;
        int a = 1400, b = 84;
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
       
    /*   do {
        if (a > b){
              a = a-b;   
              nod = a;                     
           }else{
              b = b-a;   
              nod = b;
          }
       }while(a != b);  
       printf("НОД = %d", nod);
 
         for(int i = a; i > 0; i--){
         if (a > b){
              a = a-b;   
              nod = a;                     
           }else{
              b = b-a;   
              nod = b;
          }
         
         } 
               printf("НОД = %d", nod);*/  
return 0;              
}

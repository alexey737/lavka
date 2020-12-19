#  Загальне завдання
1. *Визначити* кількість слів у заданому тексті

**Виконання роботи**
1. **Функціональне призначення**
	Програма призначена для рахунку кількості слів в тексті.
	
2. Написання коду програми 
```
#include <stdio.h>
void poisk_slov(char text[]);      

int main(){
char text[] = {"Hello ,! ? . sasa    World"};     // заданый текст
poisk_slov(text);                  
return 0;
}

void poisk_slov(char text[]){
int words = 0;                     // переменная для подсчёта слов в тексте 
//цикл для поиска количества слов в тексте
for(int i = 0; text[i] != '\0'; i++){
 if(text[i] != ' ' && text[i+1] <= ' ' && text[i] != ',' && text[i] != '.' && text[i] != '!' && text[i] != '?'){
  words++;
 }
}   
printf("%d", words);
}
```

3. Компіляція програми та перевірка на привильність її роботи через nemiver

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/4/doc/nemiver6.4.png)

4.Блок-схема

![text](file:///home/aleksey/lavka/lab08,09,10/arrays/4/doc/6.4.png)

**Висновок**
Я створив програму, яка рахує кількість слів в тексті.

#include <stdio.h>

int main (void){

 //inicialização da variavel 
    int num; 

 //pede um numero para ser digitado
    puts("digite um numero inteiro"); 
    scanf("%d", &num);

 //verifica se o numero é par
    if( num % 2 == 0 )
        printf("%d eh par", num);
    //end if
    else   
        printf("%d eh impar", num);
    //end else15
    return 0;
}
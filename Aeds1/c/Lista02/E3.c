#include <stdio.h>

int main (void){

 //inicialização da variavel 
    int num; 

 //pede um numero para ser digitado
    puts("digite um numero inteiro"); 
    scanf("%d", &num);

 //verifica se divisevel po 2, 5 e 10
    if( num % 2 == 0 && num % 5 == 0 )
        printf("%d eh divisivel por 2, 5 e 10", num);
    //end if
    else if( num % 2 == 0 ) 
        printf("%d eh divisivel por 2", num);
    //end else if
    else if( num % 5 == 0 ) 
        printf("%d eh divisivel por 5", num);
    //end else if
    else
        printf("%d nao eh divisivel por 2, 5 e 10", num);
    //end else
    
    return 0;
}
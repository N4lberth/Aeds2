#include <stdio.h>

int main (void){

 //inicialização da variavel 
    int num; 

 //pede um numero para ser digitado
    puts("digite um numero inteiro de 1 a 7"); 
    scanf("%d", &num);

 //verifica o caso que se encaixa o numero
    switch (num)
    {
    case 1:
        puts("domingo");
        break;
    
    case 2:
        puts("segunda");
        break;
    
    case 3:
        puts("terca");
        break;
    
    case 4:
        puts("quarta");
        break;
    case 5:
        puts("quinta");
        break;
    
    case 6:
        puts("sexta");
        break;
    
    case 7:
        puts("sabado");
        break;
    
    default:
        puts("numero invalido");
        break;
    }//end switch

    return 0;
}
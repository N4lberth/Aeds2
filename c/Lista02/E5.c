#include <stdio.h>

int main (void){

 //inicialização da variavel 
    int num1, num2, num3; 

 //pede tres numeros para ser digitado
    puts("digite tres numero inteiro"); 
    scanf("%d %d %d", &num1, &num2, &num3);

 //verifica qaul o maior e coloca em ordem
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }//end if
    if (num1 > num3) {
        int temp = num1;
        num1 = num3;
        num3 = temp;
    }//end if
    if (num2 > num3) {
        int temp = num2;
        num2 = num3;
        num3 = temp;
    }//end if
    
 // Imprime os valores em ordem crescente
    printf("Valores em ordem crescente: %d, %d, %d\n", num1, num2, num3);

    return 0;
}
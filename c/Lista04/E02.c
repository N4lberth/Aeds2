#include <stdio.h>

int main(void)
{
    int v[10], n, total=0;

 //extrutura de repetição para pedir ao usuario os numeros
    for(int i=0; i<10; i++){
        printf("digite o %d numero ", i+1);
        scanf("%d", &v[i]);
    }//end for

 //pede ao usuario um numero inteiro
    printf("digite um numero inteiro ");
    scanf("%d", &n);

 //testa quantos numeros iguais ao numero na variavel ( n ) tem no vetor
    for(int i=0; i<10; i++){
        if( n==v[i] )
        total++;
    }

 //printa o resultado na tela
    printf("%d aparece %d vezes no vetor", n, total);
    
    return 0;
}   
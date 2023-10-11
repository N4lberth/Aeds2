#include <stdio.h>

int main(void)
{
    int n=1, v[n];

    printf("digite um numero inteiro ");
    scanf("%d", &v[n]);
    
 //extrutura de repetição para printar todos os numeros do vetor na tela  
    for(int i=0; i<10; i++){
        printf("%d, ", v[i]);
    }//end for

    return 0;
}
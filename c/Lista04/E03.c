#include <stdio.h>

int main(void)
{
    int v[10];

 //extrutura de repetição para pedir ao usuario os numeros
    for(int i=0; i<10; i++){
        printf("digite o %d numero ", i);
        scanf("%d", &v[i]);
    }

 //extrutura de repetição para printar todos os numeros do vetor na tela  
    for(int i=0; i<10; i++){
        printf("%d, ", v[i]);
    }

    return 0;
}   
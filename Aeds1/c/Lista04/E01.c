#include <stdio.h>

int main(void)
{
    int V[10], n;

 //pede o primeiro numero ao usuario
    printf("digite o 1 numero ");
    scanf("%d", &V[0]);

 //salva o primeiro numero em uma variavel 
    n=V[0];

 //extruturra de repetição
    for(int i=1; i<10; i++){
     //pede os outros numeros ao usuario e testa qual o maior entre eles
        printf("digite o %d numero ", i+1);
        scanf("%d", &V[i]);

        if(n<V[i])
        {
            n=V[i];
        }//end if
    }//end for

    printf("%d eh o maior numero", n);

    return 0;
}
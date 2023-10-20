#include <stdio.h>

void imprimirTrianguloInverso(int n)
{
    if(n > 0)
    {
        for(int i=0; i < n ;i++){
            printf("*");
        }//end for
        printf("\n");
        imprimirTrianguloInverso(n-1);
    }//end if
}//end imprimirTrianguloInverso


int main(void)
{
 //teste função imprimirTrianguloInverso
    imprimirTrianguloInverso(5);
    return 0;
}
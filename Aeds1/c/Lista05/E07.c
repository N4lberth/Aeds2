#include <stdio.h>

void imprimirTriangulo(int n)
{
    if(n > 0)
    {
        imprimirTriangulo(n-1);
        for(int i=0; i < n ;i++){
            printf("*");
        }//end for
        printf("\n");
    }//end if
}//end imprimirTriangulo


int main(void)
{
 //teste função imprimirTriangulo
    imprimirTriangulo(5);
    return 0;
}
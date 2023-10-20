#include <stdio.h>

//função parImpar verifica se o numero é par ou impar
int parImpar(int num){
    if( num % 2 == 0 )
        return 1;
    else
        return 0;
}//end parImpar

int main(void)
{
 //teste função parImpar
    printf(" [1 = par] [0 = impar] 5 = %d\n", parImpar(5));
    printf(" [1 = par] [0 = impar] 4 = %d\n", parImpar(4));

    return 0;
}
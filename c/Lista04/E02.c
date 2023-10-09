#include <stdio.h>

int main(void)
{
    int v[10], n, total=0;

    for(int i=0; i<10; i++){
        printf("digite o %d numero ", i);
        scanf("%d", &v[i]);
    }

    printf("digite um numero inteiro ");
    scanf("%d", &n);

    for(int i=0; i<10; i++){
        if( n==v[i] )
        total++;
    }

    printf("%d aparece %d vezes no vetor", n, total);
    
    return 0;
}   
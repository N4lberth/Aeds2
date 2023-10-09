#include <stdio.h>

int main(void)
{
    int V[10], n;

    printf("digite o 1 numero ");
    scanf("%d", &V[0]);

    n=V[0];

    for(int i=1; i<10; i++){
        printf("digite o %d numero ", i);
        scanf("%d", &V[i]);

        if(n<V[i])
            n=V[i];
    }

    printf("%d eh o maior numero", n);

    return 0;
}
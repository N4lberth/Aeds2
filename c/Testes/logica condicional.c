#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Numero;
    printf("\nDigite um numer: ");
    scanf("%d", &Numero);

    if (Numero % 2==0){
        printf("%d=par\n",Numero);
    } else {
        printf("%d=impar\n",Numero);
    }
    return 0;
}

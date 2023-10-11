#include <stdio.h>
#include <string.h>

int main (void)
{
    char palavra[100];

 //salva a palavra digitada pelo usuario
    printf("digite a palavra a ser testada ");
    fgets(palavra, sizeof(palavra), stdin);

    return 0;
}
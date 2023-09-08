#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome[100];
    int tamanho;

    printf("Digite seu nome completo: ");
 //Salva o que é digitado até o enter
    fgets(nome, sizeof(nome), stdin);
 //função strlen da o numero de caracteres na variavel
    tamanho=strlen(nome);

    printf("ha %d caracteres no seu nome", tamanho);

    return 0;
}

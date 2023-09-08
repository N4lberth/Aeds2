#include <stdio.h>

int main(void)
{
    char hexadecimal[7];         // Variável para armazenar a entrada hexadecimal (6 dígitos + nulo)
    int vermelho, verde, azul;   // Variáveis das cores (RGB)

    // Entrada de dados
    printf("Digite o codigo de cor hexadecimal (RRGGBB): ");
    scanf("%6s", hexadecimal);   // %6s limita a leitura em 6 dígitos

    // Converte a string hexadecimal para números inteiros usando sscanf
    sscanf(hexadecimal, "%02X%02X%02X", &vermelho, &verde, &azul);

    // Verificar se os números estão dentro do intervalo de 0 a 255
    if (vermelho >= 0 && vermelho <= 255 && verde >= 0 && verde <= 255 && azul >= 0 && azul <= 255)
        printf("Cor RGB: R=%d, G=%d, B=%d\n", vermelho, verde, azul);
    else
        printf("Codigo de cor hexadecimal invalido.\n");

    return 0;
}

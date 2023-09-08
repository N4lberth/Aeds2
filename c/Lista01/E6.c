#include <stdio.h>

int main() {

    int vermelho, verde, azul;

 // Solicita ao usuário para inserir os valores das cores RGB
    printf("Digite os valores das cores RGB (0-255):\n");
    printf("Vermelho: ");
    scanf("%d", &vermelho);
    printf("Verde: ");
    scanf("%d", &verde);
    printf("Azul: ");
    scanf("%d", &azul);

 // Verifica se os valores estão dentro do intervalo de 0 a 255
    if (vermelho >= 0 && vermelho <= 255 && verde >= 0 && verde <= 255 && azul >= 0 && azul <= 255) {
 // Converte os valores em um código de cor hexadecimal
        printf("Codigo de cor hexadecimal: #%02X%02X%02X\n", vermelho, verde, azul);
    } else {
        printf("Valores de cor fora do intervalo permitido (0-255).\n");
    }

    return 0;
}

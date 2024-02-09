#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numero_secreto, palpite, tentativas = 0;
    srand(time(NULL)); // Semente para gerar número aleatório
    numero_secreto = rand() % 100 + 1; // Gera número aleatório entre 1 e 100

    printf("Adivinhe o número secreto entre 1 e 100!\n");

    do {
        printf("Digite um palpite: ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite > numero_secreto) {
            printf("Muito alto! Tente novamente.\n");
        } else if (palpite < numero_secreto) {
            printf("Muito baixo! Tente novamente.\n");
        } else {
            printf("Parabéns! Você adivinhou o número secreto em %d tentativas!\n", tentativas);
        }
    } while (palpite != numero_secreto);

    return 0;
}

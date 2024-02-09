#include <stdio.h>

int main() {
    int num1, num2, soma = 0;
    int i;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    for (i = 1; i <= num1; i++) {
        soma++;
    }

    for (i = 1; i <= num2; i++) {
        soma++;
    }

    printf("A soma dos numeros eh: %d\n", soma);

    return 0;
}

#include <stdio.h>

//função somaDoisVetores soma dois vetores e guarda o resultado em outro vetor
void somaDoisVetores(int vetor1[], int vetor2[], int resultado[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = vetor1[i] + vetor2[i];
    }//end for
}//end somaDoisVetores

int main() {
 //teste função somaDoisVetores

    int tamanho = 5; // Defina o tamanho dos vetores conforme sua necessidade
    int vetor1[] = {1, 2, 3, 4, 5};
    int vetor2[] = {5, 4, 3, 2, 1};
    int resultado[tamanho];

    somaDoisVetores(vetor1, vetor2, resultado, tamanho);

    printf("Resultado da soma:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", resultado[i]);
    }

    return 0;
}

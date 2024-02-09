#include <stdio.h>
#include <stdlib.h>

////função *somaDoisVetores soma dois vetores e guarda o resultado em outro vetor alocado dinamicamente
int *somaDoisVetores(int vetor1[], int vetor2[], int tamanho) {
    int *resultado = (int*)malloc(tamanho * sizeof(int));
    
    if (resultado == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1); // Encerra o programa em caso de falha na alocação
    }//end if

    for (int i = 0; i < tamanho; i++) {
        resultado[i] = vetor1[i] + vetor2[i];
    }//end for

    return resultado;
}//end somaDoisVetores

int main() {
 //teste função *somaDoisVetores
    int tamanho = 5; // Defina o tamanho dos vetores conforme sua necessidade

    int vetor1[] = {1, 2, 3, 4, 5};
    int vetor2[] = {5, 4, 3, 2, 1};

    int *resultado = somaDoisVetores(vetor1, vetor2, tamanho);

    printf("Resultado da soma:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", resultado[i]);
    }

    free(resultado); // Libera a memória alocada dinamicamente

    return 0;
}

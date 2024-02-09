#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para calcular a média
double calcularMedia(int numeros[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }
    return (double)soma / tamanho;
}//end calcularMedia

// Função para calcular a mediana
double calcularMediana(int numeros[], int tamanho) {
    // Ordenar o vetor
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (numeros[i] > numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }

    // Calcular a mediana
    if (tamanho % 2 == 0) {
        // Se o tamanho for par, médiana é a média dos dois valores do meio
        int meio1 = numeros[tamanho / 2 - 1];
        int meio2 = numeros[tamanho / 2];
        return (double)(meio1 + meio2) / 2.0;
    } else {
        // Se o tamanho for ímpar, médiana é o valor do meio
        return numeros[tamanho / 2];
    }
}//end calcularMediana

// Função para calcular a moda
int calcularModa(int numeros[], int tamanho) {
    int moda = 0; // Valor da moda
    int contagemModa = 0; // Contagem da moda atual
    int contagem = 0; // Contagem do número atual

    for (int i = 0; i < tamanho; i++) {
        int numeroAtual = numeros[i];

        if (i > 0 && numeroAtual == numeros[i - 1]) {
            // Continuar a contagem do mesmo número
            contagem++;
        } else {
            // Começar a contagem de um novo número
            contagem = 1;
        }

        if (contagem > contagemModa) {
            contagemModa = contagem;
            moda = numeroAtual;
        }
    }

    return moda;
}//end calcularModa

// Função para calcular o desvio padrão
double calcularDesvioPadrao(int numeros[], int tamanho, double media) {
    double somaQuadrados = 0.0;

    for (int i = 0; i < tamanho; i++) {
        double diferenca = numeros[i] - media;
        somaQuadrados += diferenca * diferenca;
    }

    return sqrt(somaQuadrados / tamanho);
}//calcularDesvioPadrao

int main() {
    int numeros[100]; // Vetor para armazenar os números (tamanho máximo de 100)
    int tamanho = 0, numero;

 // Leitura dos números até que seja digitado 0  
    do {
        printf("Digite um numero natural (0 para encerrar): ");
        scanf("%d", &numero);
        if (numero != 0) {
            numeros[tamanho] = numero;
            tamanho++;
        }//end if
    } while (numero != 0);//end do while

    if (tamanho == 0) {
        printf("Nenhum número foi inserido.\n");
        return 0;
    }//end if

 //chama as funções e passa os valores
    double media = calcularMedia(numeros, tamanho);
    double mediana = calcularMediana(numeros, tamanho);
    int moda = calcularModa(numeros, tamanho);
    double desvioPadrao = calcularDesvioPadrao(numeros, tamanho, media);

 //imprime o resultado na tela
    printf("Media: %.2lf\n", media);
    printf("Mediana: %.2lf\n", mediana);
    printf("Moda: %d\n", moda);
    printf("Desvio Padrao: %.2lf\n", desvioPadrao);

    return 0;
}

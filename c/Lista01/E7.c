#include <stdio.h>
#include <math.h>
#define PI 3.14159

// Função para calcular o produto escalar de dois vetores
double produtoEscalar(double x1, double y1, double x2, double y2) {
    return x1 * x2 + y1 * y2;
} 

// Função para calcular o comprimento (módulo) de um vetor
double comprimentoVetor(double x, double y) {
    return sqrt(x * x + y * y);
}

int main() {
    double x1, y1, x2, y2;

 // Leitura dos vetores
    printf("Digite as coordenadas do primeiro vetor (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Digite as coordenadas do segundo vetor (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

 // Cálculo do produto escalar
    double produtoEscalarResult = produtoEscalar(x1, y1, x2, y2);

 // Cálculo do comprimento (módulo) dos vetores
    double comprimento1 = comprimentoVetor(x1, y1);
    double comprimento2 = comprimentoVetor(x2, y2);

 // Cálculo do ângulo entre os vetores (em radianos)
    double anguloRad = acos(produtoEscalarResult / (comprimento1 * comprimento2));

 // Conversão do ângulo de radianos para graus
    double anguloGraus = anguloRad * (180.0 / PI);

 // Cálculo do produto vetorial (apenas para vetores bidimensionais, z=0)
    double produtoVetorial = x1 * y2 - x2 * y1;

 // Exibição dos resultados
    printf("Produto Escalar: %.2lf\n", produtoEscalarResult);
    printf("Ângulo entre os vetores (em graus): %.2lf\n", anguloGraus);
    printf("Produto Vetorial: %.2lf\n", produtoVetorial);

    return 0;
}

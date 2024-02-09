#include <stdio.h>
#include <math.h>
int main()
{
double n1, n2, soma, sub, div, potencia;
printf("Digite o primeiro numero: ");
scanf("%lf", &n1);

printf("Digite o segundo numero: ");
scanf("%lf", &n2);

soma = n1 + n2;
sub = n1 - n2;
potencia = pow(n1, n2);
if (n2 == 0) {
    printf("Impossivel dividir\n");
} else {
    div = n1 / n2;
    printf(" A divisao eh = %lf\n", div);

}
printf(" A soma eh = %lf\n", soma);
printf(" A subtracao eh = %lf\n", sub);
printf(" A potencia eh = %lf\n", potencia);
return 0;
}
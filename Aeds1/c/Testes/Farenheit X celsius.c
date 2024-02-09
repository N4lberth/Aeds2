#include <stdio.h>
#include <stdlib.h>

int main()
{
    int g;
    float F, C;

    printf("Escolha o resultado (1=c/2=f)");
    scanf("%d", &g);
    if(g == 1) {

        printf("Volor em Farenhei: ");
        scanf("%f", &F);
        C=(F-32)/1.8;
        printf("TEMPERATURE EM CELSIUS= %f", C);

    
    }
    if (g == 2) {

        printf("valor em celsius: ");
        scanf("%f", &C);
        F=(C*1.8)+32;
        printf("TEMPERATURE EM FARENHEIT= %f", F);
        
    }


    
    return 0;
}
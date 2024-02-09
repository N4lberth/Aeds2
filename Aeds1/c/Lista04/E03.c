#include <stdio.h>

int main(void)
{
    int v[10];

 //extrutura de repetição para pedir ao usuario os numeros
    for(int i=0; i<10; i++){
        printf("digite o %d numero ", i+1);
        scanf("%d", &v[i]);
    }//end if

 //ordena os numeros em ordem crescente
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(v[i]<v[j])
            {
                int tmp; //variavel temporaria

             //troca a posicao dos numeros
                tmp=v[i];
                v[i]=v[j];
                v[j]=tmp;
            }//end if
        }//end for
    }//end for

 //extrutura de repetição para printar todos os numeros do vetor na tela  
    for(int i=0; i<10; i++){
        printf("%d, ", v[i]);
    }//end for

    return 0;
}   
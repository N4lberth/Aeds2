#include <stdio.h>
#include <math.h>

//função pi retorna valor aprocimado de pi
double pi(int n)
{
    double pi;

    for(int i=1; i<=n; i++){
        pi=pi+pow((-1.0),(i-1.0))*(4.0/(2.0*i-1.0));
    }//end for
    return pi;
}//end pi

int main(void)
{
 //teste função pi
    printf("pi ~= %lf", pi(2000));

    return 0;
}
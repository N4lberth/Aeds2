#include "E2.cpp"

int main (void){

    Horario test1(30, 12, 12);
    Horario test2(20, 20, 20);
    Horario test3(20, 40, 40);

    test3=test1+test2;
    test2=test1-test2;

    cout << test3;
    cout << test2;

    return 0;
}
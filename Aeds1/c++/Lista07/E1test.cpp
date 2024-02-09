#include "E1.cpp"


int main(void){

    Data test1;
    Data test2(24, 10, 2004);
    Data test3(10, 10, 2004);

    int dias;
    int dias2;

    cout << test1;
    cout << test2;

    test1 = test2 + 4; 
    
    dias2 = test2 - test3;
    dias=test2.diferencaDeDias(test2, test3);

    cout << test1;
    cout << dias<< endl;
    cout << dias2<< endl;

    return 0;
}
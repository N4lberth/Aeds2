#include <stdio.h>

//struct Data(ano, mes, dia)
typedef struct Data
{
    int ano, mes, dia;
}Data;//end Data


typedef struct Horario
{
    int hora, minuto, segundo;
}Horario;//end Horario


typedef struct DataHora
{
    Horario horario;
    Data data;
}DataHora;//end DataHora

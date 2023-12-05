#include <iostream>
#include "E1.cpp"
#include "E2.cpp"

using namespace std;


class HorarioData: public Horario, public Data{
 public:
  //construtor padrão
    HorarioData(){
       Data();
       Horario();
    }//end HorarioData

  //construtor com parametro
    HorarioData(int ndia, int nmes, int nano, int nhora, int nminuto, int nsegundo){
        Data(ndia, nmes, nano);
        Horario(nhora, nminuto, nsegundo);
    }//end HorarioData


  //função retorna a direfença entre as datas em hora
    HorarioData diferencaDataHora(HorarioData x, HorarioData y){
        int dias;
        Horario hora;
        HorarioData total;

        dias = diferencaDeDias(x, y);
        hora = diferencaHora(x, y);

        total.hora = hora.getHora() + (dias * 24);


        return total;
    }//end diferencaDataHora
};

int main(void)
{
    HorarioData test1(2, 2, 2, 5, 2, 2);
    HorarioData test2(2, 2, 1, 0, 0, 0);
    HorarioData total;

    total = total.diferencaDataHora(test1, test2);

    cout << test1.getHora() <<":"<< total.getMinuto() <<":"<< total.getSegundo();

    return 0;
}
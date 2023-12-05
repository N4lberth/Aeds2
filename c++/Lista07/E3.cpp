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
    HorarioData(int ndia, int nmes, int nano, int nhora, int nminuto, int nsegundo) {
        Data::operator=(Data(ndia, nmes, nano));  // Inicialização da classe base Data
        Horario::operator=(Horario(nhora, nminuto, nsegundo));  // Inicialização da classe base Horario
    }//end HorarioData



  //função retorna a direfença entre as datas em hora
    HorarioData diferencaDataHora(HorarioData x, HorarioData y){
        int dias=0;
        Horario hora;
        HorarioData total;

        dias = diferencaDeDias(x, y);
        hora = diferencaHora(x, y);

        total.minuto=hora.getMinuto();
        total.segundo=hora.getSegundo();
        total.hora=hora.getHora() + dias * 24;


        return total;
    }//end diferencaDataHora

 
 //sobrecarga operador '-'
    HorarioData operator - (HorarioData y){ 
        HorarioData total=diferencaDataHora(*this, y);
        return total;
    }//end operator '-'
 


 // Método amigo para retornar uma stream de saída
    friend ostream& operator << (ostream& output, HorarioData HoDa);
};


 //função amiga ostream
    ostream& operator << (ostream& output, HorarioData HoDa){

        output << HoDa.dia <<"/"<< HoDa.mes <<"/"<< HoDa.ano <<" - "<< HoDa.hora <<":"<< HoDa.minuto <<":"<< HoDa.segundo << endl;
        return output;
    }//end ostream


int main(void)
{
    HorarioData test1(21, 10, 2004, 5, 2, 3);
    HorarioData test2(19, 10, 2004, 0, 1, 2);
    HorarioData total;

    total = test1 - test2;

    cout << total.getHora() <<":"<< total.getMinuto() <<":"<< total.getSegundo()<<endl;

    cout << test1;

    cout << test2;

    return 0;
}
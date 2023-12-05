#include <iostream>

using namespace std;


class Horario
{
 protected:
    int hora, minuto, segundo;

 public:
  //construtor padrão
    Horario(){
        hora = 0;
        minuto = 0;
        segundo = 0;
    }//end Horario
  
  //construtor com parametro
    Horario(int nhora, int nminuto, int nsegundo){
        if(nhora >= 0){
            hora = nhora;
        }//end if
        else{
            hora = 0;
            cout << "hora invalida definido valor para 1"<< endl;
        }//end else
        if(nminuto >= 0 && nminuto < 60){
            minuto = nminuto;
        }//end if
        else{
            minuto = 0;
            cout << "minuto invalido definido valor para 1"<< endl;
        }//end else
        if(nsegundo >= 0){
            segundo = nsegundo;
        }//end if
        else{
            segundo = 0;
            cout << "segundo invalido definido valor para 1"<< endl;
        }//end else
    }//end Horario


 //funções que retornam o valor das variaveis protefidas
    int getHora(void){
        return hora;
    }
    int getMinuto(void){
        return minuto;
    }
    int getSegundo(void){
        return segundo;
    }


 //função ajeitarHorario arruma a hora
    Horario ajeitarHorario(Horario total){
        if(total.segundo>=60){
            total.segundo-=60;
            total.minuto++;
        }//end if

        if(total.minuto>=60){
            total.minuto-=60;
            total.hora++;
        }//end if
        return total;
    }//end ajeitarHorario


 //função somaHorario
    Horario somaHorario(Horario x, Horario y){

        Horario total;

        total.segundo = x.segundo + y.segundo;
        total.minuto = x.minuto + y.minuto;
        total.hora = x.hora + y.hora;

        total = ajeitarHorario(total);

        return total;
    }//end somaHorario

 // sobrecarga operador '+'
    Horario operator + (Horario y){
        Horario resultado;
        resultado.segundo = this->segundo + y.segundo;
        resultado.minuto = this->minuto + y.minuto;
        resultado.hora = this->hora + y.hora;

        resultado = ajeitarHorario(resultado);

        return resultado;
    }//end operator '+'


 //função diferençaHora mostra a diferença entre dois horarios em segundos
    Horario diferencaHora(Horario x, Horario y){
        Horario temp;
        if(x.hora>=y.hora){
            if(x.segundo<y.segundo){
                x.segundo+=60;
                x.minuto--;
            }//end if

            if(x.minuto<y.minuto){
                x.minuto+=60;
                x.hora--;
            }//end if
        }//end if
        else{
            cout << "hora invalida"<<endl;
        }//end else

        temp.segundo=x.segundo-y.segundo;
        temp.minuto=x.minuto-y.minuto;
        temp.hora=x.hora-y.hora;

        return temp;
    }//end diferençaHora


 //sobrecarga operador '-'
    Horario operator - (Horario y){
        Horario temp;
        if(this->hora>=y.hora){
            if(this->segundo<y.segundo){
                this->segundo+=60;
                this->minuto--;
            }//end if

            if(this->minuto<y.minuto){
                this->minuto+=60;
                this->hora--;
            }//end if
        }//end if
        else{
            cout << "hora invalida"<<endl;
        }//end else

        temp.segundo=this->segundo-y.segundo;
        temp.minuto=this->minuto-y.minuto;
        temp.hora=this->hora-y.hora;

        return temp;
    }//end operator '-'


 // Método amigo para retornar uma stream de saída
    friend ostream& operator << (ostream& output, Horario Horario);


};//end class Horario


 //função amiga ostream
    ostream& operator << (ostream& output, Horario horario){
        output << horario.hora <<":"<< horario.minuto <<":"<< horario.segundo << endl;
        return output;
    }//end ostream


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
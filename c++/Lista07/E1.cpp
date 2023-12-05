#include <iostream>

using namespace std;

class Data
{
 protected:
    int dia, mes, ano;

 public:
  // construtor padrão
    Data()
    {
        dia = 1;
        mes = 1;
        ano = 1;
    } // end Data


  // construtor  com parametro
    Data(int newdia, int newmes, int newano)
    {
        if (newano > 0)
        {
            ano = newano;
        } // end if
        else
        {
            cout << "Ano inválido. Configurando para 1." << endl;
            ano = 1;
        } // end else

        if (newmes >= 1 && newmes <= 12)
        {
            mes = newmes;
        } // end if
        else
        {
            cout << "Mês inválido. Configurando para 1." << endl;
            mes = 1;
        } // end else
        if (newdia > 0)
        {
            if (newmes == 1 || newmes == 3 || newmes == 5 || newmes == 7 || newmes == 8 || newmes == 10 || newmes == 12)
            {
                if (newdia >= 1 && newdia <= 31)
                {
                    dia = newdia;
                } // end if
                else
                {
                    cout << "Dia inválido para o mês especificado. Configurando para 1." << endl;
                    dia = 1;
                } // end else
            }// end if
            else if (newmes == 4 || newmes == 6 || newmes == 9 || newmes == 11)
            {
                if (newdia >= 1 && newdia <= 30)
                {
                    dia = newdia;
                } // end if
                else
                {
                    cout << "Dia inválido para o mês especificado. Configurando para 1." << endl;
                    dia = 1;
                } // end else
            }// end else if
            else if (newmes == 2)
            {
                if ((newano % 400 == 0) || (newano % 4 == 0 && newano % 100 != 0))
                {
                    if (newdia >= 1 && newdia <= 29)
                    {
                        dia = newdia;
                    } // end if
                    else
                    {
                        cout << "Dia inválido para o mês especificado. Configurando para 1." << endl;
                        dia = 1;
                    } // end else
                }// end if
                else
                {
                    if (newdia >= 1 && newdia <= 28)
                    {
                        dia = newdia;
                    } // end if
                    else
                    {
                        cout << "Dia inválido para o mês especificado. Configurando para 1." << endl;
                        dia = 1;
                    } // end else
                }// end else
            } // end else if
            else
            {
                cout << "Mês inválido. Configurando para 1." << endl;
                mes = 1;
            } // end else
        }// end if
        else
        {
            cout << "Dia inválido. Configurando para 1." << endl;
            dia = 1;
        } // end else
    }// end Data


 // funções que retornam os valores das varieveis privadas
    int getDia(void)
    {
        return dia;
    } // end getDia

    int getMes(void)
    {
        return mes;
    } // end getMes

    int getAno(void)
    {
        return ano;
    } // end getAno


 // função que adiciona dias a data
    void adicionarDia(int nDias)
    {

        for (int i = 1; i <= nDias; i++)
        {
            switch (mes)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (dia < 31)
                {
                    dia++;
                } // end if
                else
                {
                    dia = 1;
                    mes++;
                } // end else
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (dia < 30)
                {
                    dia++;
                } // end if
                else
                {
                    dia = 1;
                    mes++;
                } // end else
                break;
            case 2:
                if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
                {
                    if (dia < 29)
                    {
                        dia++;
                    } // end if
                    else
                    {
                        dia = 1;
                        mes++;
                    } // end else
                }// end if
                else
                {
                    if (dia < 28)
                    {
                        dia++;
                    } // end if
                    else
                    {
                        dia = 1;
                        mes++;
                    } // end else
                }// end else
                break;
            default:
                mes = 1;
                ano++;
            } // end switch
        }// end for
    }// end adicionarDia


 //sobrecarga de operador '+'
    Data operator + (int nDias){
        Data resultado = *this;
        resultado.adicionarDia(nDias);
        return resultado;
    }//end operator '+'


 // Método amigo para retornar uma stream de saída
    friend ostream& operator << (ostream& output, Data data);


 //função diferencaDeDias entrega um numero inteiro q representa a diferença de dias entre duas datas
    int diferencaDeDias(Data x, Data y){
        Data tempx = x;
        Data tempy = y;

        int quntdias=0;

        while (tempx.dia != tempy.dia || tempx.mes != tempy.mes || tempx.ano != tempy.ano) 
        {
           tempy.adicionarDia(1);
           quntdias++;
        }//end while
        return quntdias;
    }//end diferencaDeDias


 //sobrecarga de operador '-'
    int operator - (Data y){
        int total=0;
        total=diferencaDeDias(*this, y);
        return total;
    }//end operator '-'
};//end class Data

 //função amiga ostream
    ostream& operator << (ostream& output, Data data){
        output << data.dia <<"/"<< data.mes <<"/"<< data.ano << endl;
        return output;
    }//end ostream



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
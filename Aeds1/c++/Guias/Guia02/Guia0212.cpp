/*
 Guia0212 
 Author: 1033726 - Nalberth
*/
// lista de dependencias
#include "karel.hpp"
#include "myKarel.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
 // colocar paredes no mundo
   world->set ( 3, 1, HWALL ); // parede horizontal
   world->set ( 4, 1, HWALL );
   world->set ( 6, 1, HWALL );
   world->set ( 7, 1, HWALL );
   world->set ( 3, 4, HWALL ); // parede horizontal
   world->set ( 4, 4, HWALL );
   world->set ( 6, 4, HWALL );
   world->set ( 7, 4, HWALL );
   world->set ( 3, 5, HWALL ); // parede horizontal
   world->set ( 4, 5, HWALL );
   world->set ( 6, 5, HWALL );
   world->set ( 7, 5, HWALL );
   world->set ( 3, 8, HWALL ); // parede horizontal
   world->set ( 4, 8, HWALL );
   world->set ( 6, 8, HWALL );
   world->set ( 7, 8, HWALL );
   world->set ( 5, 3, HWALL );
   world->set ( 5, 6, HWALL );
   world->set ( 2, 2, VWALL ); // parede vertical
   world->set ( 2, 3, VWALL );
   world->set ( 2, 4, VWALL );
   world->set ( 2, 6, VWALL );
   world->set ( 2, 7, VWALL );
   world->set ( 2, 8, VWALL );
   world->set ( 7, 2, VWALL ); // parede vertical
   world->set ( 7, 3, VWALL );
   world->set ( 7, 4, VWALL );
   world->set ( 7, 6, VWALL );
   world->set ( 7, 7, VWALL );
   world->set ( 7, 8, VWALL );
   world->set ( 4, 5, VWALL );
   world->set ( 5, 5, VWALL );
   world->set ( 4, 2, VWALL ); // parede vertical
   world->set ( 4, 3, VWALL );
   world->set ( 4, 7, VWALL );
   world->set ( 4, 8, VWALL );
   world->set ( 5, 2, VWALL ); // parede vertical
   world->set ( 5, 3, VWALL );
   world->set ( 5, 7, VWALL );
   world->set ( 5, 8, VWALL );
 // colocar um marcador no mundo
   world->set ( 5, 3, BEEPER );
   world->set ( 5, 7, BEEPER );
   world->set ( 4, 5, BEEPER );
   world->set ( 6, 5, BEEPER );
 // salvar a configuracao atual do mundo
   world->save( fileName );
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public robott
{
 public:
    /**
     turnRight - Procedimento para virar 'a direita.
    */
    void turnRight ( )
    {
     // definir dado local
        int step = 0;
     // testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
         // o agente que executar esse metodo
         // devera' virar tres vezes 'a esquerda
            for ( step = 1; step <= 3; step = step + 1 )
            {
                turnLeft( );
            } // end for
        } // end if
    } // end turnRight ( )
 /**
  doTask - Relacao de acoes para o robo executar.
 */
   void doTask( )
   {
     // especificar acoes da tarefa
      
      do
      {
         if( leftIsClear( ) )
         {
            turnLeft( );
            move( );
         } else if ( !rightIsClear ( ) && !leftIsClear( ) )
            {
            if ( nextToABeeper( ) )
            {
               pickBeeper( );
               turnLeft( );
               turnLeft( );
            } else
            {
               move();
            }
         } else 
         {
            move( );
         }
      }while ( !areYouHere(3,1) );
      
      
    // encerrar
      turnOff ( );
   } // end doTask( )
}; // end class MyRobot
// --------------------------- acao principal
/**
 Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
 // definir o contexto
 // criar o ambiente e decorar com objetos
 // OBS.: executar pelo menos uma vez,
 // antes de qualquer outra coisa
 // (depois de criado, podera' ser comentado)
    world->create ( "" ); // criar o mundo
    decorateWorld ( "Guia0212.txt" );
    world->show ( );
 // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0212.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 3 ); // definir velocidade padrao
 // criar robo
    MyRobot *robot = new MyRobot( );
 // posicionar robo no ambiente (situacao inicial):
 // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 3, 1, EAST, 0, "Karel" );
 // executar tarefa
    robot->doTask ( );
 // encerrar operacoes no ambiente
    world->close ( );
 // encerrar programa
    getchar ( );
    return ( 0 );
} // end main ( )
// -------------------------------------------- testes
/*
Versao Teste
 0.1    01. ( ok ) teste inicial
*/
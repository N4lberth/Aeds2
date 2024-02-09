/*
 Guia0211 
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
   world->set ( 2, 1, VWALL ); // parede vertical
   world->set ( 3, 1, HWALL ); // parede horizontal
   world->set ( 3, 2, VWALL );
   world->set ( 4, 2, HWALL );
   world->set ( 4, 3, VWALL );
   world->set ( 5, 3, HWALL );
   world->set ( 6, 3, HWALL );
   world->set ( 6, 3, VWALL );
   world->set ( 7, 2, HWALL );
   world->set ( 7, 2, VWALL );
   world->set ( 8, 1, HWALL );
   world->set ( 8, 1, VWALL );
 // colocar um marcador no mundo
   world->set ( 7, 3, BEEPER );
   world->set ( 7, 3, BEEPER );
   world->set ( 7, 3, BEEPER );
   world->set ( 8, 2, BEEPER );
   world->set ( 8, 2, BEEPER );
   world->set ( 9, 1, BEEPER );
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
   stepUpRight - Metodo para especificar parte de uma tarefa.
 */
    void stepUpRight( )
    {
     // especificar acoes dessa parte da tarefa
        faceNorth( );
        moveN( 1 );
        faceEast( );
        moveN( 1 );
    } // end  stepUpRight( )
    /**
   stepDownRight - Metodo para especificar parte de uma tarefa.
 */
    void stepDownRight( )
    {
     // especificar acoes dessa parte da tarefa
        faceEast( );
        moveN( 1 );
        faceSouth( );
        moveN( 1 );
    } // end  stepDownRight( )
    /**
   stepUpLeft - Metodo para especificar parte de uma tarefa.
 */
    void stepUpLeft( )
    {
     // especificar acoes dessa parte da tarefa
        faceNorth( );
        moveN( 1 );
        faceWest( );
        moveN( 1 );
    } // end  stepUpLeft( )
    /**
   stepDownLeft - Metodo para especificar parte de uma tarefa.
 */
    void stepDownLeft( )
    {
     // especificar acoes dessa parte da tarefa
        faceWest( );
        moveN( 1 );
        faceSouth( );
        moveN( 1 );
    } // end  stepDownLeft( )
 /**
  doTask - Relacao de acoes para o robo executar.
 */
   void doTask( )
   {
     // especificar acoes da tarefa
      moveN( 1 );
      stepUpRight( ); //subir escada direita
      stepUpRight( );
      stepUpRight( );
      moveN( 1 );
      stepDownRight( ); // descer escada direita
      pickBeepers( 3 ); // pegar beeper
      stepDownRight( );
      pickBeepers( 2 );
      stepDownRight( );
      pickBeepers( 1 );
      stepUpLeft( ); // subir escada esquerda
      stepUpLeft( );
      stepUpLeft( );
      moveN( 1 );
      stepDownLeft( ); // descer escada esquerda
      putBeepers( 3 ); // soltar beeper
      stepDownLeft( );
      putBeepers( 2 );
      stepDownLeft( );
      putBeepers( 1 );
      faceWest( );
      moveN( 1 );
      faceEast( );
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
    decorateWorld ( "Guia0211.txt" );
    world->show ( );
 // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0211.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 3 ); // definir velocidade padrao
 // criar robo
    MyRobot *robot = new MyRobot( );
 // posicionar robo no ambiente (situacao inicial):
 // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, EAST, 0, "Karel" );
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
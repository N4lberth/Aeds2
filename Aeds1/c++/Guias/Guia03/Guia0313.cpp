/*
 Guia0313 
 Author: 1033726 - Nalberth
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
 // colocar paredes no mundo
    world->set ( 1, 3, VWALL );
    world->set ( 1, 4, VWALL );
    world->set ( 1, 5, VWALL );
    world->set ( 1, 6, VWALL );
    world->set ( 1, 7, VWALL );
    world->set ( 1, 8, VWALL );
    world->set ( 2, 4, VWALL );
    world->set ( 2, 5, VWALL );
    world->set ( 2, 6, VWALL );
    world->set ( 2, 7, VWALL );
    world->set ( 3, 5, VWALL );
    world->set ( 3, 6, VWALL );
    world->set ( 4, 7, VWALL );
    world->set ( 6, 6, VWALL );
    world->set ( 6, 5, VWALL );
    world->set ( 7, 3, VWALL );
    world->set ( 7, 4, VWALL );
    world->set ( 7, 5, VWALL );
    world->set ( 7, 6, VWALL );
    world->set ( 7, 7, VWALL );
    world->set ( 5, 7, VWALL );

    world->set ( 2, 2, HWALL );
    world->set ( 7, 2, HWALL );
    world->set ( 3, 2, HWALL );
    world->set ( 4, 2, HWALL );
    world->set ( 5, 2, HWALL );
    world->set ( 6, 2, HWALL );
    world->set ( 5, 4, HWALL );
    world->set ( 6, 4, HWALL );
    world->set ( 4, 6, HWALL );
    world->set ( 6, 6, HWALL );
    world->set ( 3, 7, HWALL );
    world->set ( 4, 7, HWALL );
    world->set ( 5, 7, HWALL );
    world->set ( 6, 7, HWALL );
    world->set ( 7, 7, HWALL );
    world->set ( 2, 8, HWALL );
    world->set ( 7, 8, HWALL );
    world->set ( 3, 8, HWALL );
    world->set ( 4, 8, HWALL );
    world->set ( 5, 8, HWALL );
    world->set ( 6, 8, HWALL );
 // colocar um marcador no mundo
   world->set ( 4, 7, BEEPER );
   world->set ( 4, 7, BEEPER );
   world->set ( 4, 7, BEEPER );
   world->set ( 5, 7, BEEPER );
   world->set ( 5, 7, BEEPER );
   world->set ( 5, 7, BEEPER );
   world->set ( 6, 7, BEEPER );
 // salvar a configuracao atual do mundo
   world->save( fileName );
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
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
  moveN - Metodo para mover certa quantidade de passos.
  @param steps - passos a serem dados.
 */
    void moveN( int steps )
    {
     // definir dado local
        int step = 0;
     // testar se a quantidade de passos e' maior que zero
        for ( step = steps; step > 0; step = step - 1 )
        {
         // dar um passo
            move( );
        } // end if
    } // end moveN( )
    /**
    * pickBeepers - Funcao para coletar marcadores.
    * @return quantidade de marcadores coletados
   */
   int pickBeepers ( )
   {
    // definir dado local
      int n = 0;
    // repetir (com teste no inicio)
    // enquanto houver marcador proximo
      while ( nextToABeeper ( ) )
      {
       // coletar um marcador
         pickBeeper ( );
       // contar mais um marcador coletado
         n = n + 1;
      } // end while
    // retornar a quantidade de marcadores coletados
      return ( n );
   } // end pickBeepers( )
 /**
  * 
  doTask - Relacao de acoes para o robo executar.
 */
   void doTask( )
   {
     // especificar acoes da tarefa
      
      do
      {  
         if( !areYouHere(8,2))
         {
            if( areYouHere(1,1) )
            {
               turnLeft();
               moveN( 8 );
               turnRight( );
            } 
            if ( areYouHere(1,9) )
            {
               moveN( 7 );
               turnRight();
               move( );
               turnRight( );
               move( );
            }
            if ( rightIsClear( ) )
            {
               turnRight( );
               move( );
            } else if ( leftIsClear( ) )
            {
               turnLeft( );
               move( );
            }else if ( !rightIsClear ( ) && !leftIsClear( ) )
               {
               if ( nextToABeeper( ) )
               {
                  pickBeepers( );
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
         }if (areYouHere(8,2))
         {
            move( );
            turnLeft( );
            moveN( 8 );
            turnLeft( );
            turnLeft( );
         }
      } while ( !areYouHere(1,1) );
                
    // encerrar
      turnOff ( );
   } // end doTask( )

   /**
 * recordActions - Metodo para mover o robot interativamente
 * e guardar a descricao da tarefa em arquivo.
 * @param fileName - nome do arquivo
 */
 void recordActions (const char * fileName )
 {
 // definir dados
 int action;
 int x,y;
 // definir arquivo onde gravar comandos
 std::ofstream archive ( fileName );
 // ler acao
 action = pickBeepers ( );
 // repetir enquanto acao maior ou igual a zero
 while ( action >= 0 )
 {
 // testar se opcao valida
 if ( 0 <= action && action <= 9 )
 {
 // guardar o comando em arquivo
   x = xAvenue ( ); // obter posicao atual (avenue)
   y = yStreet ( ); // obter posicao atual ( street )
   archive << x << std::endl;
   archive << y << std::endl;
 } // end if
 // ler acao
 action = pickBeepers ( );
 } // end while
 // fechar o arquivo
 // INDISPENSAVEL para a gravacao
 archive.close ( );
 } // end recordActions ( )

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
    decorateWorld ( "Guia0313.txt" );
    world->show ( );
 // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0313.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 3 ); // definir velocidade padrao
 // criar robo
    MyRobot *robot = new MyRobot( );
 // posicionar robo no ambiente (situacao inicial):
 // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, EAST, 0, "Karel" );
 // executar tarefa
    robot->doTask ( );
    robot->recordActions ( "Tarefa0313.txt" );
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
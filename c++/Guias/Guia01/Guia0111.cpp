/*
 Guia0111 
 Author: 811197 - Nalberth
*/
// lista de dependencias
#include "karel.hpp" 
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
 // colocar paredes no mundo
    
 // colocar um marcador no mundo
    
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
     // testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
         // o agente que executar esse metodo
         // devera' virar tres vezes 'a esquerda
            turnLeft ( );
            turnLeft ( );
            turnLeft ( );
        } // end if
   } // end turnRight ( )
   /**
    moveN - Metodo para mover certa quantidade de passos.
    @param steps - passos a serem dados.
    */
   void moveN( int steps )
   {
    // repetir se a quantidade de passos e' maior que zero
      while ( steps > 0 ) // outra forma de repetir
      {
       // dar um passo por vez
         move( );
       // tentar fazer de novo, com menos um passo
         steps = steps - 1;
      } // end while
   } // end moveN( )
   /**
    doPartialTask - Metodo para descrever parte de uma tarefa.
   */
   void doPartialTask( )
   {
    // especificar acoes dessa parte da tarefa
      moveN( 2 );
      turnLeft( );
   } // end doPartialTask( 

     /**
     doTask - Relacao de acoes para qualquer robo executar.
     */
   void doTask ( )
   {

    // especificar acoes da tarefa
      doPartialTask( );
      doPartialTask( );

    // testar se carrega marcador antes ...
      if ( nbeepers( ) > 0 )
      {
       // ... de tentar descarrega-lo
         putBeeper( );
      } // end if

      turnRight ( );
      moveN ( 3 );

      // testar se carrega marcador antes ...
      if ( nbeepers( ) > 0 )
      {
       // ... de tentar descarrega-lo
         putBeeper( );
      } // end if

      turnRight( );
      moveN ( 3 );

      // testar se carrega marcador antes ...
      if ( nbeepers( ) > 0 )
      {
       // ... de tentar descarrega-lo
         putBeeper( );
      } // end if

      turnRight ( );
      moveN ( 5 );
      turnRight ( );
      moveN ( 5 );
      turnLeft ( );
      turnLeft ( );
     // encerrar
      turnOff ( ); // desligar-se
    }// end doTask ( )

}; // end class MyRobot

// --------------------------- acao principal
int main ( )
{
 // definir o contexto
 // criar o ambiente e decorar com objetos
 // OBS.: executar pelo menos uma vez,
 // antes de qualquer outra coisa
 // (depois de criado, podera' ser comentado)
    world->create ( "" ); // criar o mundo
    decorateWorld ( "Guia0111.txt" );
    world->show ( );
 // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0111.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 3 ); // definir velocidade padrao
 // criar robo
    MyRobot *robot = new MyRobot( );
 // posicionar robo no ambiente (situacao inicial):
 // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, EAST, 3, "Karel" );
 // executar tarefa
    robot->doTask( );
 // encerrar operacoes no ambiente
    world->close ( );
 // encerrar programa
 getchar ( );
    return ( 0 );
} // end main ( )
// ------------------------------------------- testes
/**
-
Versao Data Modificacao
 0.1 
---------------------------------------------- testes
Versao Teste
 1.1    01. ( ok )
*/
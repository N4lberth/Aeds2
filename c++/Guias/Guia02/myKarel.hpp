//Guia01E3
//811197 - Nalberth

#include "karel.hpp"

class robott : public Robot
{
    public:
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
    pickBeepers - pegar o beeper
   */
   void pickBeepers( int n )
   {
    // pegar beeper com repetição
      for(int i = 1; i <= n; i++) 
      {
       // testar se ha' marcador antes ...
         if ( nextToABeeper( ) )
         {
         // ... de tentar carrega-lo
            pickBeeper( );
         } // end if
      } // end for
   } // end pickBeepers( 

      /**
    putBeepers - soltar o beeper
   */
   void putBeepers( int n )
   {
      // soltar beeper com repetição
      for(int i = 1; i <= n; i++) 
      {
      // testar se carrega marcador antes ...
         if ( nbeepers( ) > 0 )
         {
         // ... de tentar descarrega-lo
            putBeeper( );
         } // end if]
      }// end for
   }// end putBeepers
};
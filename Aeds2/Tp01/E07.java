import java.io.*;
import java.net.*;
import java.util.Scanner;

public class E07 {
    public static void main ( String[] args ) {
        String html;
        char e1 = 225;
        char e2 = 233;
        char e3 = 237;
        char e4 = 243;
        char e5 = 250;
        char e6 = 224;
        char e7 = 232;
        char e8 = 236;
        char e9 = 242;
        char e10 = 249;
        char e11 = 227;
        char e12 = 245;
        char e13 = 226;
        char e14 = 234;
        char e15 = 238;
        char e16 = 244;
        char e17 = 251;
        Scanner leitor = new Scanner ( System.in );
        String nome;
        String endereco;
        int x1 = 0;
        int x2 = 0;
        int x3 = 0;
        int x4 = 0;
        int x5 = 0;
        int x6 = 0;
        int x7 = 0;
        int x8 = 0;
        int x9 = 0;
        int x10 = 0;
        int x11 = 0;
        int x12 = 0;
        int x13 = 0;
        int x14 = 0;
        int x15 = 0;
        int x16 = 0;
        int x17 = 0;
        int x18 = 0;
        int x19 = 0;
        int x20 = 0;
        int x21 = 0;
        int x22 = 0;
        int x23 = 0;
        int x24 = 0;
        int x25 = 0;
        do {
            nome = leitor.nextLine( );

            if ( !( isFIM( nome ) ) ) {
                x1 = 0;
                x2 = 0;
                x3 = 0;
                x4 = 0;
                x5 = 0;
                x6 = 0;
                x7 = 0;
                x8 = 0;
                x9 = 0;
                x10 = 0;
                x11 = 0;
                x12 = 0;
                x13 = 0;
                x14 = 0;
                x15 = 0;
                x16 = 0;
                x17 = 0;
                x18 = 0;
                x19 = 0;
                x20 = 0;
                x21 = 0;
                x22 = 0;
                x23 = 0;

                endereco = leitor.nextLine( );

                html = getHtml( endereco );

                for( int i = 0; i < html.length( ); i = i + 1 ) {
                    if ( html.charAt(i) == 'a' ) { 
                        x1 = x1 + 1;
                    } else if ( html.charAt(i) == 'e' ) { 
                        x2 = x2 + 1;
                    } else if ( html.charAt(i) == 'i' ) { 
                        x3 = x3 + 1;
                    } else if ( html.charAt(i) == 'o' ) { 
                        x4 = x4 + 1;
                    } else if ( html.charAt(i) == 'u' ) { 
                        x5 = x5 + 1;
                    } else if ( html.charAt(i) == e1 ) {                        x6 = x6 + 1;
                    } else if ( html.charAt(i) == e2 ) { 
                        x7 = x7 + 1;
                    } else if ( html.charAt(i) == e3 ) { 
                        x8 = x8 + 1;
                    } else if ( html.charAt(i) == e4 ) { 
                        x9 = x9 + 1;
                    } else if ( html.charAt(i) == e5 ) { 
                        x10 = x10 + 1;
                    } else if ( html.charAt(i) == e6 ) { 
                        x11 = x11 + 1;
                    } else if ( html.charAt(i) == e7 ) { 
                        x12 = x12 + 1;
                    } else if ( html.charAt(i) == e8 ) { 
                        x13 = x13 + 1;
                    } else if ( html.charAt(i) == e9 ) { 
                        x14 = x14 + 1;
                    } else if ( html.charAt(i) == e10 ) { 
                        x15 = x15 + 1;
                    } else if ( html.charAt(i) == e11 ) { 
                        x16 = x16 + 1;
                    } else if ( html.charAt(i) == e12 ) { 
                        x17 = x17 + 1;
                    } else if ( html.charAt(i) == e13 ) { 
                        x18 = x18 + 1;
                    } else if ( html.charAt(i) == e14 ) { 
                        x19 = x19 + 1;
                    } else if ( html.charAt(i) == e15 ) { 
                        x20 = x20 + 1;
                    } else if ( html.charAt(i) == e16 ) { 
                        x21 = x21 + 1;
                    } else if ( html.charAt(i) == e17 ) { 
                        x22 = x22 + 1;
                    } else if ( isConsoante( html.charAt(i) ) ) {
                        x23 = x23 + 1;
                    }
                }

                x24 = contaTagBr( html );
                x25 = contaTagTable( html );

            System.out.println( "a" + '(' + x1 + ')' + ' ' + "e" + '(' + x2 + ')' + ' ' + "i" + '(' + x3 + ')' + ' ' + "o" + '(' + x4 + ')' + ' ' + "u" + '(' + x5 + ')' + ' ' + e1 + '(' + x6 + ')' + ' ' + e2 + '(' + x7 + ')' + ' ' + e3 + '(' + x8 + ')' + ' ' + e4 + '(' + x9 + ')' + ' ' + e5 + '(' + x10 + ')' + ' ' + e6 + '(' + x11 + ')' + ' ' + e7 + '(' + x12 + ')' + ' ' + e8 + '(' + x13 + ')' + ' ' + e9 + '(' + x14 + ')' + ' ' + e10 + '(' + x15 + ')' + ' ' + e11 + '(' + x16 + ')' + ' ' + e12 + '(' + x17 + ')' + ' ' + e13 + '(' + x18 + ')' + ' ' + e14 + '(' + x19 + ')' + ' ' + e15 + '(' + x20 + ')' + ' ' + e16 + '(' + x21 + ')' + ' ' + e17 + '(' + x22 + ')' + ' ' + "consoante" + '(' + x23 + ')' + ' ' + "<br>" + '(' + x24 + ')' + ' ' + "<table>" + '(' + x25 + ')' + ' ' + nome );
            } 
        } while ( !( isFIM( nome ) ) );
        leitor.close();
    } 

    public static int contaTagBr ( String str ) {
        int contador = 0;

        for( int i = 0; i < str.length( ); i = i + 1 ) {
            if ( str.charAt(i) == '<' ) {
                if ( str.charAt(i + 1) == 'b' ) {
                    if ( str.charAt(i + 2) == 'r' ) {
                        if ( str.charAt(i + 3) == '>' ) {
                            contador = contador + 1;
                        }
                    }
                }
            }
        } 

        return ( contador );
    } 
 
    public static int contaTagTable ( String str ) {
        int contador = 0;

        for( int i = 0; i < str.length( ); i = i + 1 ) {
            if ( str.charAt(i) == '<' ) {
                if ( str.charAt(i + 1) == 't' ) {
                    if ( str.charAt(i + 2) == 'a' ) {
                        if ( str.charAt(i + 3) == 'b' ) {
                            if ( str.charAt(i + 4) == 'l' ) {
                                if ( str.charAt(i + 5) == 'e' ) {
                                    if ( str.charAt(i + 6) == '>' ) {
                                        contador = contador + 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } 
        return ( contador );
    } 

    public static boolean isConsoante( char caractere ) {
        boolean resp = false;
        char c = caractere;
        
        if ( isInString( c, "bcdfghjklmnpqrstvwxyz" ) ) {
            resp = true;
        }

        return ( resp );
    } 

    public static boolean isInString ( char caractere, String str) {
        boolean resultado = false;

        for ( int i = 0; i < str.length( ); i = i + 1 ) {
            if ( caractere == str.charAt(i) ) {
                resultado = true;
            } 
        } 

        return ( resultado );
    } 

    public static boolean isFIM ( String str ) {
        boolean resp = false;
        if( str.length( ) == 3 ) {
            if( str.charAt(0) == 'F') {
                if( str.charAt(1) == 'I' ) {
                    if( str.charAt(2) == 'M' ) {
                        resp = true;
                    }
                } 
            } 
        } 

        return ( resp );
    } 

    @SuppressWarnings("deprecation")
    public static String getHtml(String endereco){
      URL url;
      InputStream is = null;
      BufferedReader br;
      String resp = "", line;

      try {
         url = new URL(endereco);
         is = url.openStream(); 
         br = new BufferedReader(new InputStreamReader(is));

         while ((line = br.readLine()) != null) {
            resp += line + "\n";
         }
      } catch (MalformedURLException mue) {
         mue.printStackTrace();
      } catch (IOException ioe) {
         ioe.printStackTrace();
      } 

      try {
         is.close();
      } catch (IOException ioe) {

      }

      return resp;
   }
} 
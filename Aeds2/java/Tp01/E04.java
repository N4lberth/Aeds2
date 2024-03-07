import java.util.Random;

public class E04 {
    
    public static String alteracaoAleatoria(String texto){

        Random gerador = new Random();
        gerador.setSeed(4);

        char letra1 = (char) ('a' + gerador.nextInt(26));
        char letra2 = (char) ('a' + gerador.nextInt(26));

        texto = texto.replace(letra1,letra2);

        return texto;
    }

    public static void main(String[] args) {
        
        String texto;

        while (!(texto=MyIO.readLine()).equals("FIM")) {
            
            MyIO.println(alteracaoAleatoria(texto));
        }
       
    }

}

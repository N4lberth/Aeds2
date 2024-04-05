
public class E03 {

    public static String cifraDeCesar(String texto){

        StringBuilder builder = new StringBuilder(texto);

        for(int i=0; i < texto.length(); i++){

            char temp = texto.charAt(i);
            int ascii = (int) temp + 3;
            builder.setCharAt(i, (char) ascii);
        }

        String textocripto = builder.toString();

        return textocripto;
    }

    public static void main(String[] args) {
        
        String texto;

        while (!(texto=MyIO.readLine()).equals("FIM")) {
            
            MyIO.println(cifraDeCesar(texto));
        }
       
    }
}

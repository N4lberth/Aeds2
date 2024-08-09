public class E12 {

    public static String cifraDeCesar(String texto) {
        return cifraDeCesarRecursivo(texto, 0, new StringBuilder());
    }
    
    private static String cifraDeCesarRecursivo(String texto, int index, StringBuilder builder) {
        if (index >= texto.length()) {
            return builder.toString();
        } else {
            char temp = texto.charAt(index);
            int ascii = (int) temp + 3;
            builder.append((char) ascii);
            return cifraDeCesarRecursivo(texto, index + 1, builder);
        }
    }

    public static void main(String[] args) {
        
        String texto;

        while (!(texto=MyIO.readLine()).equals("FIM")) {
            
            MyIO.println(cifraDeCesar(texto));
        }
       
    }

}

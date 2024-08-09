public class E15 {
    
    public static boolean somenteVogal(String texto) {
        return somenteVogalRecursivo(texto, 0);
    }
    
    private static boolean somenteVogalRecursivo(String texto, int index) {
        if (index >= texto.length()) {
            return true;
        } else {
            char temp = texto.charAt(index);
            if (temp != 'a' && temp != 'e' && temp != 'i' && temp != 'o' && temp != 'u' && temp != 'A' && temp != 'E' && temp != 'I' && temp != 'O' && temp != 'U') {
                return false;
            }
            return somenteVogalRecursivo(texto, index + 1);
        }
    }
    
    public static boolean somenteConsoante(String texto) {
        return somenteConsoanteRecursivo(texto, 0);
    }
    
    private static boolean somenteConsoanteRecursivo(String texto, int index) {
        if (index >= texto.length()) {
            return true;
        } else {
            char temp = texto.charAt(index);
            if (!Character.isLetter(temp) || temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u' || temp == 'A' || temp == 'E' || temp == 'I' || temp == 'O' || temp == 'U') {
                return false;
            }
            return somenteConsoanteRecursivo(texto, index + 1);
        }
    }
    
    public static boolean numeroInteiro(String texto) {
        return texto.matches("\\d+");
    }
    
    public static boolean numeroReal(String texto) {
        return texto.matches("^[-+]?[0-9]*([.,][0-9]*+)?$") && !texto.matches("\\d+");
    }

    public static void main(String[] args) {
        
        String texto;

        while (!(texto=MyIO.readLine()).equals("FIM")) {
            
            if(somenteVogal(texto)){
                MyIO.print("SIM ");
            } else {
                MyIO.print("NAO ");
            }
            if(somenteConsoante(texto)){
                MyIO.print("SIM ");
            } else {
                MyIO.print("NAO ");
            }
            if(numeroInteiro(texto)){
                MyIO.print("SIM ");
            } else {
                MyIO.print("NAO ");
            }
            if(numeroReal(texto)){
                MyIO.println("SIM");
            } else {
                MyIO.println("NAO");
            }
        }
       
    }

}

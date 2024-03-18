public class E06 {
    
    public static boolean somenteVogal(String texto){
        for(int i = 0; i < texto.length(); i++){
            char temp = texto.charAt(i);
            if(temp != 'a' && temp != 'e' && temp != 'i' && temp != 'o' && temp != 'u' && temp != 'A' && temp != 'E' && temp != 'I' && temp != 'O' && temp != 'U'){
                return false;  
            }         
        }
        return true;
    }

    public static boolean somenteConsoante(String texto){
        for(int i = 0; i < texto.length(); i++){
            char temp = texto.charAt(i);
            if(!Character.isLetter(temp) || temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u' || temp == 'A' || temp == 'E' || temp == 'I' || temp == 'O' || temp == 'U'){
                return false;  
            }                  
        }
        return true;
    }

    public static boolean numeroInteiro(String texto){
        if(texto.matches("\\d+")){
            return true;
        } else {
            return false;
        }
    }

    public static boolean numeroReal(String texto){
        if(texto.matches("^[-+]?[0-9]*([.,][0-9]*+)?$") && !texto.matches("\\d+")){
            return true;
        } else {
            return false;
        }
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
import java.util.Scanner;

public class E10 {

    public static boolean palindromo(String texto) {
        if (texto.length() <= 1) {
            return true;
        } else {
            if (texto.charAt(0) == texto.charAt(texto.length() - 1)) {
                return palindromo(texto.substring(1, texto.length() - 1));
            } else {
                return false;
            }
        }
    }
    

    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        String texto;

        while (!(texto=scanner.nextLine()).equals("FIM")) {
            if(palindromo(texto)){
                System.out.println("SIM");
            }else{
                System.out.println("NAO");
            }
        }
        scanner.close();
    }
}

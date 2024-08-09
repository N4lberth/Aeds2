import java.util.Scanner;

public class E01 {

    public static Boolean palindromo(String texto){
        
        String temp = "";

        for(int i = texto.length() - 1; i >= 0 ; i--){
            temp = temp + texto.charAt(i);
        }
        if(texto.equals(temp)){
            return true;
        }else{
            return false;
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

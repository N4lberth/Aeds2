package Aquecimento;

import java.util.Scanner;

public class AquecimentoRecursivo {

    public static int contarMaiusculasRecursivo(String texto) {
        if (texto.isEmpty()) {
            return 0;
        }
        
        char primeiroCaractere = texto.charAt(0);
        int contador = Character.isUpperCase(primeiroCaractere) ? 1 : 0;
        
        return contador + contarMaiusculasRecursivo(texto.substring(1));
    }
    
    public static void main(String[] args) {
        String entrada;
        Scanner scanner = new Scanner(System.in);

        while (!(entrada = scanner.nextLine()).equals("FIM")) {
            int contador = contarMaiusculasRecursivo(entrada);
            System.out.println(contador);
        }
        scanner.close();
    }
}

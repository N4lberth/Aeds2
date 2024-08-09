package Aquecimento;

import java.util.Scanner;

public class Aquecimento {

    public static int contarMaiusculas(String texto){
        int contador = 0;
        for(int i = 0; i < texto.length(); i++){
            char caracter = texto.charAt(i);
            if(Character.isUpperCase(caracter)){
                contador++;
            }
        }
        return contador;
    }
    public static void main(String[] args) {
        String test;
        Scanner scanner = new Scanner(System.in);

        while (!(test=scanner.nextLine()).equals("FIM")) {
            int contador = contarMaiusculas(test);
            System.out.println(contador);
        }
        scanner.close();
    }
}

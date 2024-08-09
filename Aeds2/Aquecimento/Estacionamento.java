import java.util.Scanner;

public class Estacionamento {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int N = scanner.nextInt();
            int K = scanner.nextInt();

            if (N == 0 && K == 0) {
                break;
            }

            int[] chegadas = new int[N];
            int[] saidas = new int[N];

            for (int i = 0; i < N; i++) {
                chegadas[i] = scanner.nextInt();
                saidas[i] = scanner.nextInt();
            }

            boolean possivel = true;
            
            for(int i = 1; i < N; i++){
                if(saidas[0] < saidas[i]){
                    possivel = false;
                }else if(chegadas[i] < saidas[i-1] && i-1 != 0){
                    possivel = false;
                }
            }

            System.out.println(possivel ? "Sim" : "Nao");
        }
    }
}
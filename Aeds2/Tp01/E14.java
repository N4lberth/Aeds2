public class E14 {

    public static boolean and(String aux) { 
        boolean resultado = true;
        for (int i = 0; i < aux.length() && resultado; i++) {
            if (aux.charAt(i) == '0') { 
                resultado = false;
            }
        }
        return resultado;
    }

    public static boolean or(String aux) { 
        boolean resultado = false;
        for (int i = 0; i < aux.length() && !resultado; i++) {
            if (aux.charAt(i) == '1') { 
                resultado = true;
            }
        }
        return resultado;
    }

    public static boolean not(String aux) {
        boolean resultado = true;
        if (aux.charAt(0) == '1') {
            resultado = false;
        }
        return resultado;
    }

    public static boolean expressao(String s, int k, int qpa, int n) {

        boolean resultado = true, resultaux = false;
        int pa = 0, pf = 0;
        String aux = "";

        if (k < qpa) { 
            boolean exp = false;
            for (int i = 0; i < s.length() && !exp; i++) { 
                if (s.charAt(i) == '(') {
                    pa = i;
                } else if (s.charAt(i) == ')') {
                    pf = i;
                }
                if (pa < pf) {
                    exp = true;
                }
            }

            for (int j = pa + 1; j < pf; j++) { 
                aux += s.charAt(j);
            }
            switch (s.charAt(pa - 1)) { 
                case 'd': // and
                    resultaux = and(aux);
                    aux = "";
                    for (int j = 0; j < s.length(); j++) { 
                        if (j == (pa - 3)) {
                            if (resultaux) {
                                aux += '1';
                            } else {
                                aux += '0';
                            }
                        }
                        if (j < (pa - 3) || j > pf) {
                            aux += s.charAt(j);
                        }
                    }
                    break;
                case 'r': // or
                    resultaux = or(aux);
                    aux = "";
                    for (int j = 0; j < s.length(); j++) {
                        if (j == (pa - 2)) {
                            if (resultaux) {
                                aux += '1';
                            } else {
                                aux += '0';
                            }
                        }
                        if (j < (pa - 2) || j > pf) {
                            aux += s.charAt(j);
                        }
                    }
                    break;
                case 't': // not
                    resultaux = not(aux);
                    aux = "";
                    for (int j = 0; j < s.length(); j++) {
                        if (j == (pa - 3)) {
                            if (resultaux) {
                                aux += '1';
                            } else {
                                aux += '0';
                            }
                        }
                        if (j < (pa - 3) || j > pf) {
                            aux += s.charAt(j);
                        }
                    }
                    break;

                default:
                    break;
            }

            if (aux != "") { 
                s = aux;
            }

            resultado = expressao(s, k + 1, qpa, n);
        } else {
            if (s.charAt(n + 1) == '0') {
                resultado = false;
            }
        }

        return resultado;
    }

    public static boolean expressao(String s) { 
        String aux = "";
        int n = 0, qpa = 0;

        n = s.charAt(0) - '0';

        for (int i = 0; i < s.length(); i++) { 
            if (s.charAt(i) != ' ' && s.charAt(i) != ',') {
                aux += s.charAt(i);
            }
        }
        s = aux;
        aux = "";
        for (int i = 0; i < s.length(); i++) { 
            if ((s.charAt(i) >= 'A' && s.charAt(i) <= ('A' + n - 1))) {
                aux += s.charAt(s.charAt(i) - 'A' + 1);
            } else {
                aux += s.charAt(i);
            }
        }
        s = aux;

        for (int i = 0; i < s.length(); i++) { 
            if (s.charAt(i) == '(') {
                qpa++;
            }
        }

        return expressao(s, 0, qpa, n);

    }

    public static void main(String[] args) {
        String s = "";

        boolean continua = true, resultado = false;

        s = MyIO.readLine();

        if (s.charAt(0) == '0') { 
            continua = false;
        }

        while (continua) {

            resultado = expressao(s);

            if (resultado) {
                MyIO.println(1);
            } else {
                MyIO.println(0);
            }

            s = MyIO.readLine();

            if (s.charAt(0) == '0') { 
              continua = false;
            }

        }

    }
}

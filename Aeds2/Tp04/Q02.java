import java.io.File;
import java.util.Date;
import java.util.Scanner;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Q02 {

    public static void main(String[] args) throws Exception {
       
        String nomeArquivo = "/tmp/characters.csv";
        Scanner scanner = new Scanner(new File(nomeArquivo));
        scanner.nextLine(); 
        String input = "";
        Lista lista=new Lista();
        lista.inicio=new Celula();
        lista.fim=lista.inicio;
        lista.tam=0;
        Personagem[] arquivo=new Personagem[405];
        int a=0;
        while (scanner.hasNextLine()){
            String linha = scanner.nextLine();
            Personagem personagem=new Personagem();
            String[] dados = linha.split(";");
            personagem.setId(dados[0]);
            personagem.setName(dados[1]);
            ArrayList<String> alternateNames=new ArrayList<>();
            Pattern pattern = Pattern.compile("'(.*?)'");
            Matcher matcher = pattern.matcher(dados[2]);
            while (matcher.find()){
                alternateNames.add(matcher.group(1));
            }
            StringBuilder formattedAlternateNames = new StringBuilder("{");
            for (int x = 0; x < alternateNames.size(); x++) {
                formattedAlternateNames.append(alternateNames.get(x));
                if (x < alternateNames.size() - 1) {
                    formattedAlternateNames.append(", ");
                }
            }
            formattedAlternateNames.append("}");
            String formatado=formattedAlternateNames.toString();
            
            personagem.setAlternateNames(formatado);
            personagem.setHouse(dados[3]);
            personagem.setAncestry(dados[4]);
            personagem.setSpecies(dados[5]);
            personagem.setPatronus(dados[6]);
            personagem.setHogwartsStaff(dados[7]);
            personagem.setHogwartsStudent(dados[8]);
            personagem.setActorName(dados[9]);
            personagem.setAlive(dados[10]);
            personagem.setAlternateActors(dados[11]);
            personagem.setBirthDate(converterParaData(dados[12]));
            personagem.setBirthDateString(dados[12]);
            personagem.setYearOfBirth(Integer.parseInt(dados[13]));
            personagem.setEyeColour(dados[14]);
            personagem.setGender(dados[15]);
            personagem.setHairColour(dados[16]);
            personagem.setWizard(dados[17]);
            
            arquivo[a++]=personagem;
            
        }
        
        scanner.close();
        scanner = new Scanner(System.in);
        input=scanner.nextLine();
        Arvore arvore=new Arvore();
        arvore.inserir(7);
        arvore.inserir(3);
        arvore.inserir(11);
        arvore.inserir(1);
        arvore.inserir(5);
        arvore.inserir(9);
        arvore.inserir(13);
        arvore.inserir(0);
        arvore.inserir(2);
        arvore.inserir(4);
        arvore.inserir(6);
        arvore.inserir(8);
        arvore.inserir(10);
        arvore.inserir(12);
        arvore.inserir(14);

         while (!input.equals("FIM")) {
            for(int c=0;c<404;c++){
                if(input.equals(arquivo[c].getId())){
                    arvore.inserirInterno(arquivo[c].name,(arquivo[c].yearOfBirth%15));
                }
            }
            input=scanner.nextLine();
        }
       input="";
     while (!(input = scanner.nextLine()).equals("FIM")) {

   
    for (int c = 0; c < 404; c++) {
        
        if (input.equals(arquivo[c].getName())) {
           
            arvore.pesquisar(arquivo[c].getYearOfBirth() % 15, input);
            break; 
        }
    }
}
         
        scanner.close();
    }



    public static class Lista{
        Celula inicio;
        Celula fim;
        int tam;
        void print(){
            Celula pos=this.inicio;
            int i=0;
            while (pos!=null){
                if(pos.personagem!=null){
                    System.out.printf("[%d ",i++);
                    pos.personagem.imprimir();
                    pos=pos.prox;
                }else pos=null;
            }
        }
        int tamanho(Lista lista){
            int tam=0;
            Celula percorre=lista.inicio;
            while(percorre!=null){
                tam++;
                percorre=percorre.prox;
            }
            this.tam=tam;
            return tam;
        }
        void inserirInicio(Personagem personagemRecebido){
            Celula inicioNovo=new Celula();
            if(this.inicio!=null){
                this.inicio.ant=inicioNovo;
                inicioNovo.prox=this.inicio;
                inicioNovo.personagem=personagemRecebido;
                this.inicio=inicioNovo;
            }else {
                this.inicio=inicioNovo;
                this.inicio.personagem=personagemRecebido;
                this.fim=this.inicio;
            }
        }
        void inserirFim(Personagem personagemRecebido){
            Celula fimNovo=new Celula();
                this.fim.prox=fimNovo;
                fimNovo.ant=this.fim;
                fimNovo.personagem=personagemRecebido;
                this.fim=fimNovo;
      
        }
        void inserir(Personagem personagemRecebido,int pos){
            Celula inseirPos=new Celula();
            inseirPos.personagem=personagemRecebido;
            Celula caminhar=this.inicio;
            int i=0;
            while((i++)!=pos && caminhar!=null){
                caminhar=caminhar.prox;
            }
            if(caminhar==null){
                System.out.println("Posição de inserção inválida");
            }else{
                inseirPos.prox=caminhar;
                inseirPos.ant=caminhar.ant;
                caminhar.ant.prox=inseirPos;
                caminhar.ant=inseirPos;
            }
        }
        Celula removerInicio(){
            
            Celula retorno=new Celula();
            retorno.personagem=this.inicio.personagem;
            this.inicio.personagem=null;
            this.inicio=this.inicio.prox;
            return retorno;
         
        }
        Celula remover(int pos){
            Celula retorno=new Celula();
            Celula percorre=this.inicio;
            int i=0;
            if(pos==0&&this.inicio.prox!=null)this.inicio=this.inicio.prox;
            while(percorre!=null){
                if((i++) ==pos){
                    retorno.personagem=percorre.personagem;
                    percorre.personagem=null;
                    
                    if(percorre.prox!=null)percorre.prox.ant=percorre.ant;
                    percorre.ant.prox=percorre.prox;
                    percorre.prox=null;
                    percorre.ant=null;
                    percorre=null;
                    return retorno;
                }
                if(percorre!=null)percorre=percorre.prox;
            }
            return retorno;
        }
        Celula removerFim(){
            Celula retorno=new Celula();
            retorno.personagem=this.fim.personagem;
            this.fim.personagem=null;
            this.fim=this.fim.ant;
            this.fim.prox.ant=null;
            this.fim.prox=null;

            return retorno;
        }
    }
    
    public static class Celula{
        Celula prox;
        Celula ant;
        Personagem personagem;
    }
   
    public static class Personagem {
        private String id;
        private String name;
        private String alternateNames; 
        private String house;
        private String species;
        private String patronus;
        private boolean hogwartsStaff; 
        private boolean hogwartsStudent; 
        private String actorName;
        private boolean alive; 
        private Date birthDate;
        private String birthDateString;
        public String getBirthDateString() {
            return birthDateString;
        }
  
        public void setBirthDateString(String birthDateString) {
            this.birthDateString = birthDateString;
        }
        private int yearOfBirth;
        private String eyeColour;
        private String gender;
        private boolean wizard; 
        private String ancestry; 
        private String alternateActors; 
        private String hairColour; 
  
        public String getHairColour() {
            return hairColour;
        }
  
        public void setHairColour(String hairColour) {
            this.hairColour = hairColour;
        }
  
        public String getAlternateActors() {
            return alternateActors;
        }
  
        public void setAlternateActors(String alternateActors) {
            this.alternateActors = alternateActors;
        }
  
        public Personagem(String id, String name) {
            this.id = id;
            this.name = name;
        }
  
        public Personagem() {
            this.id = "0";
            this.name = "";
            this.species = "";
        }
        SimpleDateFormat formatoEntrada = new SimpleDateFormat("yyyy-MM-dd");
        public void imprimir() {
            System.out.printf("["+id + " ## " + name + " ## " + alternateNames + " ## " + house +" ## " + ancestry + " ## " + species + " ## " + patronus + " ## " +
                    hogwartsStaff + " ## " + hogwartsStudent + " ## " + actorName + " ## " + alive + " ## " + birthDateString +
                    " ## " + yearOfBirth + " ## " + eyeColour + " ## " + gender + " ## " + hairColour +" ## " + wizard +  ']'+'\n');
        }
        public String imprimirString() {
          return("[" + id + " ## " + name + " ## " + alternateNames + " ## " + house +" ## " + ancestry + " ## " + species + " ## " + patronus + " ## " +
                  hogwartsStaff + " ## " + hogwartsStudent + " ## " + actorName + " ## " + alive + " ## " + birthDateString +
                  " ## " + yearOfBirth + " ## " + eyeColour + " ## " + gender + " ## " + hairColour +" ## " + wizard +  ']');
      }
        
  
        public String getId() {
            return id;
        }
  
        public void setId(String id) {
            this.id = id;
        }
        public String getName() {
            return name;
        }
        public void setName(String name) {
            this.name = name;
        }
        public String getAlternateNames() {
            return alternateNames;
        }
  
        public void setAlternateNames(String alternateNames) {
            this.alternateNames = alternateNames;
        }
  
        public String getHouse() {
            return house;
        }
  
        public void setHouse(String house) {
            this.house = house;
        }
  
        public String getSpecies() {
            return species;
        }
  
        public void setSpecies(String species) {
            this.species = species;
        }
  
        public String getPatronus() {
            return patronus;
        }
  
        public void setPatronus(String patronus) {
            this.patronus = patronus;
        }
  
        public Boolean getHogwartsStaff() {
            return hogwartsStaff;
        }
  
        public void setHogwartsStaff(String dado) {
            if (dado != null && dado.equalsIgnoreCase("VERDADEIRO")) {
                this.hogwartsStaff = true;
            } else {
                this.hogwartsStaff = false;
            }
        }
  
        public Boolean getHogwartsStudent() {
            return hogwartsStudent;
        }
  
        public void setHogwartsStudent(String dado) {
            if (dado != null && dado.equalsIgnoreCase("VERDADEIRO")) {
                this.hogwartsStudent = true;
            } else {
                this.hogwartsStudent = false;
            }
        }
  
        public String getActorName() {
            return actorName;
        }
  
        public void setActorName(String actorName) {
            this.actorName = actorName;
        }
  
        public boolean getAlive() {
            return alive;
        }
  
        public void setAlive(String dado) {
            if (dado != null && dado.equalsIgnoreCase("VERDADEIRO")) {
                this.alive = true;
            } else {
                this.alive = false;
            }
        }
  
        public Date getBirthDate() {
            return birthDate;
        }
  
        public void setBirthDate(Date birthDate) {
            this.birthDate = birthDate;
        }
  
        public int getYearOfBirth() {
            return yearOfBirth;
        }
  
        public void setYearOfBirth(int yearOfBirth) {
            this.yearOfBirth = yearOfBirth;
        }
  
        public String getEyeColour() {
            return eyeColour;
        }
  
        public void setEyeColour(String eyeColour) {
            this.eyeColour = eyeColour;
        }
  
        public String getGender() {
            return gender;
        }
  
        public void setGender(String gender) {
            this.gender = gender;
        }
  
        public Boolean getWizard() {
            return wizard;
        }
  
        public void setWizard(String dado) {
            if (dado != null && dado.equalsIgnoreCase("VERDADEIRO")) {
                this.wizard = true;
            } else {
                this.wizard = false;
            }
        }
  
        public String getAncestry() {
            return ancestry;
        }
  
        public void setAncestry(String ancestry) {
            this.ancestry = ancestry;
        }
    }
    public static Date converterParaData(String dataString) throws ParseException {
        SimpleDateFormat formatoEntrada = new SimpleDateFormat("dd-MM-yyyy");
        return formatoEntrada.parse(dataString);
    }
    
    public static class Arvore {
        No raiz;
    
        public static class No {
            int elemento; 
            No esq, dir;  
            NoInterno raizInterna;
    
           
            public No(int elemento) {
                this(elemento, null, null);
            }
    
           
            public No(int elemento, No esq, No dir) {
                this.elemento = elemento;
                this.esq = esq;
                this.dir = dir;
                this.raizInterna = null; 
            }
        }
    
        public static class NoInterno {
            String nome;
            NoInterno esq, dir;
    
            public NoInterno(String nome) {
                this.nome = nome;
                this.esq = null;
                this.dir = null;
            }
        }
    
        
        public void inserir(int x) {
            raiz = inserir(x, raiz);
        }
    
       
        private No inserir(int x, No i) {
            if (i == null) {
                i = new No(x);
            } else if (x < i.elemento) {
                i.esq = inserir(x, i.esq);
            } else if (x > i.elemento) {
                i.dir = inserir(x, i.dir);
            } else {
               
            }
            return i;
        }
    
        public void inserirInterno(String nome, int elementoPrincipal) {
            No noPrincipal = buscarNo(elementoPrincipal, this.raiz);
            if (noPrincipal != null) {
                if (noPrincipal.raizInterna == null) {
                    noPrincipal.raizInterna = new NoInterno(nome);
                } else {
                    inserirInterno(nome, noPrincipal.raizInterna);
                }
            } else {
                System.out.println("Elemento principal não achou na árvore.");
            }
        }
    
       
        private void inserirInterno(String nome, NoInterno raizInterna) {
            if (nome.compareTo(raizInterna.nome) < 0) {
                if (raizInterna.esq == null) {
                    raizInterna.esq = new NoInterno(nome);
                } else {
                    inserirInterno(nome, raizInterna.esq);
                }
            } else if (nome.compareTo(raizInterna.nome) > 0) {
                if (raizInterna.dir == null) {
                    raizInterna.dir = new NoInterno(nome);
                } else {
                    inserirInterno(nome, raizInterna.dir);
                }
            } else {
                
            }
        }
    
        
        public void imprimir() {
            System.out.print("Elementos da árvore principal: ");
            imprimir(raiz);
            System.out.println();
        }
    
        
        private void imprimir(No i) {
            if (i != null) {
                imprimir(i.esq); 
                System.out.print(i.elemento + " "); 
        
               
                if (i.raizInterna != null) {
                    System.out.print("(" + i.elemento + ": ");
                    printDentro(i.raizInterna);
                    System.out.print(") ");
                }
        
                imprimir(i.dir); 
            }
        }
        private void printDentro(NoInterno raizInterna) {
            if (raizInterna != null) {
                printDentro(raizInterna.esq); 
                System.out.print(raizInterna.nome + " "); 
                printDentro(raizInterna.dir); 
            }
        }
        public void pesquisar(int chave, String nome) {
            System.out.printf("%s => raiz",nome);
            if (pesquisar(raiz, chave, nome)) {
                System.out.printf(" SIM\n");
            } else {
                System.out.printf(" NAO\n");
            }
        }
        
        private boolean pesquisar(No i, int chave, String nome) {
            if (i == null) {
                return false;
            }
        
            boolean achou = false;
        
          
            NoInterno pesquisa = i.raizInterna;
            while (pesquisa != null) {
                if (pesquisa.nome.compareTo(nome) == 0) {
                    return true;
                } else if (nome.compareTo(pesquisa.nome) < 0) {
                    System.out.print("->esq");
                    pesquisa = pesquisa.esq; 
                } else {
                    System.out.print("->dir");
                    pesquisa = pesquisa.dir; 
                }
            }
        
         
            if (!achou) {
                System.out.print(" ESQ");
                achou = pesquisar(i.esq, chave, nome);
            }
        
            
          
        
            if (!achou) {
                System.out.print(" DIR");
                achou = pesquisar(i.dir, chave, nome);
            }
        
            return achou;
        }
        
        
        

        private No buscarNo(int elemento, No i) {
            if (i == null || elemento == i.elemento) {
                return i;
            } else if (elemento < i.elemento) {
                return buscarNo(elemento, i.esq);
            } else {
                return buscarNo(elemento, i.dir);
            }
        }
    }
    
}
    
// bibliotecas
import java.util.*;
import java.io.*;
import java.text.*;

// classe Personagem
class Personagem {

    // Atributos
    private String id;
    private String name;
    private List <String> alternate_names;
    private String house;
    private String ancestry;
    private String species;
    private String patronus;
    private boolean hogwartsStaff;
    private String hogwartsStudent;
    private String actorName;
    private boolean alive;
    private Date dateOfBirth;
    private int yearOfBirth;
    private String eyeColour;
    private String gender;
    private String hairColour;
    private boolean wizard;
    DateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");

    // construtor primario
    Personagem( ) {
        id = "";
        name = "";
        alternate_names = null;
        house = "";
        ancestry = "";
        species = "";
        patronus = "";
        hogwartsStaff = false;
        hogwartsStudent = "";
        actorName = "";
        alive = false;
        dateOfBirth = new Date( );
        yearOfBirth = 0;
        eyeColour = "";
        gender = "";
        hairColour = "";
        wizard = false;
    }

    // construtor secundario
    Personagem( String id ) {
        this.id = id;
        name = "";
        alternate_names = null;
        house = "";
        ancestry = "";
        species = "";
        patronus = "";
        hogwartsStaff = false;
        hogwartsStudent = "";
        actorName = "";
        alive = false;
        dateOfBirth = new Date( );
        yearOfBirth = 0;
        eyeColour = "";
        gender = "";
        hairColour = "";
        wizard = false;
    }

    /*
        Metodos Set e Get
        set -> definir valor ao atributo
        get -> retornar valor que o atributo contem
    */
    public void setId( String id ) {
        this.id = id;
    }

    public String getId( ) {
        return this.id;
    }
    
    public void setName( String name ) {
        this.name = name;
    }

    public String getName( ) {
        return this.name;
    }

    public void setAlternate_names( List <String> alternate_names ) {
        this.alternate_names = alternate_names;
    }

    public List <String> getAlternate_names( ) {
        return this.alternate_names;
    }

    public void setHouse( String house ) {
        this.house = house;
    }

    public String getHouse( ) {
        return this.house;
    }

    public void setAncestry( String ancestry ) {
        this.ancestry = ancestry;
    }

    public String getAncestry( ) {
        return this.ancestry;
    }

    public void setSpecies( String species ) {
        this.species = species;
    }

    public String getSpecies( ) {
        return this.species;
    }

    public void setPatronus( String patronus ) {
        this.patronus = patronus;
    }

    public String getPatronus( ) {
        return this.patronus;
    }

    public void setHogwartsStaff( boolean hogwartsStaff ) {
        this.hogwartsStaff = hogwartsStaff;
    }

    public boolean getHogwartsStaff( ) {
        return this.hogwartsStaff;
    }

    public void setHogwartsStudent( String hogwartsStudent ) {
        this.hogwartsStudent = hogwartsStudent;
    }

    public String getHogwartsStudent( ) {
        return this.hogwartsStudent;
    }
    
    public void setActorName( String actorName ) {
        this.actorName = actorName;
    }

    public String getActorName( ) {
        return this.actorName;
    }

    public void setAlive( boolean alive ) {
        this.alive = alive;
    }

    public boolean getAlive( ) {
        return this.alive;
    }

    public void setDateOfBirth( Date dateOfBirth ) {
        this.dateOfBirth = dateOfBirth;
    }

    public Date getDateOfBirth( ) {
        return this.dateOfBirth;
    }

    public void setYearOfBirth( int yearOfBirth ) {
        this.yearOfBirth = yearOfBirth;
    }

    public int getYearOfBirth( ) {
        return this.yearOfBirth;
    }

    public void setEyeColour( String eyeColour ) {
        this.eyeColour = eyeColour;
    }

    public String getEyeColour( ) {
        return this.eyeColour;
    }

    public void setGender( String gender ) {
        this.gender = gender;
    }

    public String getGender( ) {
        return this.gender;
    }

    public void setHairColour( String hairColour ) {
        this.hairColour = hairColour;
    }

    public String getHairColour( ) {
        return this.hairColour;
    }

    public void setWizard( boolean wizard ) {
        this.wizard = wizard;
    }

    public boolean getWizard( ) {
        return this.wizard;
    }
    
    /*
        imprimir( ) - Funcao para mostrar na tela os atributos da classe
    */
    public void imprimir( ) {
        String alternateNamesString = "";
        if ( alternate_names != null ) {
            alternateNamesString = alternate_names.toString()
                                        .replace("'", "")
                                        .replace("[[", "{")
                                        .replace("]]", "}");
        }

        // mostrar na tela
        System.out.println( "[" + id + " ## " + name + " ## " + alternateNamesString + " ## " + house + " ## " + ancestry
        + " ## " + species + " ## " + patronus + " ## " + hogwartsStaff + " ## " + hogwartsStudent + " ## "
        + actorName + " ## " + alive + " ## " + dateFormat.format(dateOfBirth) + " ## " + yearOfBirth + " ## " + eyeColour + " ## "
        + gender + " ## " + hairColour + " ## " + wizard + "]" );
    }

    /*
        clone( ) - copiar atributos de uma variavel para outra
        @return - retorna uma variavel do tipo da classe para atribuir seus valores em uma variavel que deve ser igual a outra
    */
    public Personagem clone( ) {
        // definir dados
        Personagem clone = new Personagem( );

        // atribuir valores
        clone.setId(this.getId());
        clone.setName(this.getName());
        clone.setAlternate_names(this.getAlternate_names());
        clone.setHouse(this.getHouse());
        clone.setAncestry(this.getAncestry());
        clone.setSpecies(this.getSpecies());
        clone.setPatronus(this.getPatronus());
        clone.setHogwartsStaff(this.getHogwartsStaff());
        clone.setHogwartsStudent(this.getHogwartsStudent());
        clone.setActorName(this.getActorName());
        clone.setAlive(this.getAlive());
        clone.setDateOfBirth(this.getDateOfBirth());
        clone.setYearOfBirth(this.getYearOfBirth());
        clone.setEyeColour(this.getEyeColour());
        clone.setGender(this.getGender());
        clone.setHairColour(this.getHairColour());
        clone.setWizard(this.getWizard());

        // retornar valor
        return clone;
    }

    /*
        leitor( ) - funcao para ler base de dados e armazenar nos atriibutos da classe
    */
    public void leitor( String s ) throws ParseException {
        // definir dados
        String[] array = s.split(";");
        String mago;
        String vivo;
        String equipe;
        String estudante;

        // armazenar valores nos atributos
        id = array[0];
        name = array[1];
        alternate_names = Arrays.asList(array[2].split(",")); 
        house = array[3];
        ancestry = array[4];
        species = array[5];
        patronus = array[6];

        equipe = array[7];
        if(equipe.equals("VERDADEIRO")) {
            hogwartsStaff = true;
        } else {
            hogwartsStaff = false;
        }

        estudante = array[8];
        if(estudante.equals("VERDADEIRO")) {
            hogwartsStudent = "true";
        } else {
            hogwartsStudent = "false";
        }

        actorName = array[9];

        vivo = array[10];
        if(vivo.equals("VERDADEIRO")) {
            alive = true;
        } else {
            alive = false;
        }

        dateOfBirth = dateFormat.parse(array[12]);
        yearOfBirth = Integer.parseInt(array[13]);
        eyeColour = array[14];
        gender = array[15];
        hairColour = array[16];

        mago = array[17];

        if(mago.equals("VERDADEIRO")) {
            wizard = true;
        } else {
            wizard = false;
        }

    }
}

// classe No
class No {
    public Personagem elemento; // Conteudo do no.
    public No esq, dir;  // Filhos da esq e dir.

    public No(Personagem elemento) {
        this(elemento, null, null);
    }

    public No(Personagem elemento, No esq, No dir) {
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    }
}

// classe ArvoreBinaria
class ArvoreBinaria {
	private No raiz; // Raiz da arvore.

	public ArvoreBinaria() {
		raiz = null;
	}

	public boolean pesquisar(String x) {
        System.out.print(" => raiz");
		return pesquisar(x, raiz);
	}

	private boolean pesquisar(String x, No i) {
      boolean resp;
		if (i == null) {
         resp = false;

      } else if (x.equals(i.elemento.getName())) {
         resp = true;

      } else if (x.compareTo(i.elemento.getName()) < 0) {
         System.out.print(" esq");
         resp = pesquisar(x, i.esq);

      } else {
         System.out.print(" dir");
         resp = pesquisar(x, i.dir);
      }
      return resp;
	}

	public void caminharCentral() {
		caminharCentral(raiz);
	}

	private void caminharCentral(No i) {
		if (i != null) {
			caminharCentral(i.esq); // Elementos da esquerda.
			i.elemento.imprimir();
			caminharCentral(i.dir); // Elementos da direita.
		}
	}

	public void caminharPre() {
		caminharPre(raiz);
	}

	private void caminharPre(No i) {
		if (i != null) {
			i.elemento.imprimir();
			caminharPre(i.esq); // Elementos da esquerda.
			caminharPre(i.dir); // Elementos da direita.
		}
	}

	public void caminharPos() {
		caminharPos(raiz);
	}

	private void caminharPos(No i) {
		if (i != null) {
			caminharPos(i.esq); // Elementos da esquerda.
			caminharPos(i.dir); // Elementos da direita.
			i.elemento.imprimir();
		}
	}

	public void inserir(Personagem x) throws Exception {
		raiz = inserir(x, raiz);
	}

	private No inserir(Personagem x, No i) throws Exception {
		if (i == null) {
         i = new No(x);

      } else if (x.getName().compareTo(i.elemento.getName()) < 0) {
         i.esq = inserir(x, i.esq);

      } else if (x.getName().compareTo(i.elemento.getName()) > 0) {
         i.dir = inserir(x, i.dir);

      } else {
         throw new Exception("Erro ao inserir!");
      }

		return i;
	}

	public void inserirPai(Personagem x) throws Exception {
      if(raiz == null){
         raiz = new No(x);
      } else if(x.getName().compareTo(raiz.elemento.getName()) < 0){
		   inserirPai(x, raiz.esq, raiz);
      } else if(x.getName().compareTo(raiz.elemento.getName()) > 0){
		   inserirPai(x, raiz.dir, raiz);
      } else {
         throw new Exception("Erro ao inserirPai!");
      }
	}

	private void inserirPai(Personagem x, No i, No pai) throws Exception {
		if (i == null) {
         if(x.getName().compareTo(pai.elemento.getName()) < 0){
            pai.esq = new No(x);
         } else {
            pai.dir = new No(x);
         }
      } else if (x.getName().compareTo(i.elemento.getName()) < 0) {
         inserirPai(x, i.esq, i);
      } else if (x.getName().compareTo(i.elemento.getName()) > 0) {
         inserirPai(x, i.dir, i);
      } else {
         throw new Exception("Erro ao inserirPai!");
      }
	}


	/*
	public void remover(int x) throws Exception {
		raiz = remover(x, raiz);
	}

	private No remover(int x, No i) throws Exception {

		if (i == null) {
         throw new Exception("Erro ao remover!");

      } else if (x < i.elemento) {
         i.esq = remover(x, i.esq);

      } else if (x > i.elemento) {
         i.dir = remover(x, i.dir);

      // Sem no a direita.
      } else if (i.dir == null) {
         i = i.esq;

      // Sem no a esquerda.
      } else if (i.esq == null) {
         i = i.dir;

      // No a esquerda e no a direita.
      } else {
         i.esq = maiorEsq(i, i.esq);
		}

		return i;
	}*/

	private No maiorEsq(No i, No j) {

      // Encontrou o maximo da subarvore esquerda.
		if (j.dir == null) {
			i.elemento = j.elemento; // Substitui i por j.
			j = j.esq; // Substitui j por j.ESQ.

      // Existe no a direita.
		} else {
         // Caminha para direita.
			j.dir = maiorEsq(i, j.dir);
		}
		return j;
	}

   public int getAltura(){
      return getAltura(raiz, 0);
   }

   public int getAltura(No i, int altura){
      if(i == null){
         altura--;
      } else {
         int alturaEsq = getAltura(i.esq, altura + 1);
         int alturaDir = getAltura(i.dir, altura + 1);
         altura = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
      }
      return altura;
   }

	/*public void remover2(int x) throws Exception {
      if (raiz == null) {
         throw new Exception("Erro ao remover2!");
      } else if(x < raiz.elemento){
         remover2(x, raiz.esq, raiz);
      } else if (x > raiz.elemento){
         remover2(x, raiz.dir, raiz);
      } else if (raiz.dir == null) {
         raiz = raiz.esq;
      } else if (raiz.esq == null) {
         raiz = raiz.dir;
      } else {
         raiz.esq = maiorEsq(raiz, raiz.esq);
      }
   }

	private void remover2(int x, No i, No pai) throws Exception {
		if (i == null) {
         throw new Exception("Erro ao remover2!");
      } else if (x < i.elemento) {
         remover2(x, i.esq, i);
      } else if (x > i.elemento) {
         remover2(x, i.dir, i);
      } else if (i.dir == null) {
         pai = i.esq;
      } else if (i.esq == null) {
         pai = i.dir;
      } else {
         i.esq = maiorEsq(i, i.esq);
		}
	}*/

   public Personagem getRaiz() throws Exception {
      return raiz.elemento;
   }

}

class Q01 {
    public static void main( String args[] ) throws Exception {
        RandomAccessFile raf = new RandomAccessFile( "/tmp/characters.csv", "r" );
        String str = raf.readLine();
        Personagem[] personagens = new Personagem[500];
        for (int i = 0; i < personagens.length; i++) {
            personagens[i] = new Personagem();
        }

        int i = 0;
        String entrada;
        Scanner sc = new Scanner(System.in);

        while(!EOF(raf)) {
            str = raf.readLine();

            personagens[i].leitor( str );

            i = i + 1;
        }

        ArvoreBinaria arvore = new ArvoreBinaria();

        do {
            entrada = sc.nextLine();

            if( !entrada.equals("FIM") ) {

                for( int j = 0; j < personagens.length; j = j + 1 ) {

                    if( personagens[j].getId().equals( entrada ) ) {

                        arvore.inserir(personagens[j]);

                    }
                }

            }

        } while( !entrada.equals("FIM") );

        boolean resp;
        do {
            entrada = sc.nextLine();
            if( !entrada.equals("FIM") ) {
                System.out.print(entrada);
                if(arvore.pesquisar(entrada)) {
                    System.out.println( " SIM" );
                } else {
                    System.out.println( " NAO" );
                }
            }
        } while ( !entrada.equals("FIM") );

        sc.close();

    }

    public static boolean EOF( RandomAccessFile raf ) throws Exception {
        return( raf.getFilePointer() == raf.length() );
    }
}
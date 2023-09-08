#include <iostream>
#include <string>
using namespace std;



struct Veiculo {

    string placa, marca, modelo, tipo, observacao;
    int ano;
    double preco;
};



void ListaVeiculo(FILE* veiculos){

    fseek(veiculos, 0, SEEK_SET);
    int quant;
    fscanf(veiculos, "%d\n", &quant);
    cout << "Total de Veiculos:" << quant << endl;
    cout << "===========================" << endl;
    cout << "Veiculos cadastrados:" << endl;
    cout << "===========================" << endl;

    if (quant == 0) {
        cout << "===========================" << endl;
        cout << "Nenhum veiculo cadastrado." << endl;
        cout << "===========================" << endl;
        return;
    }

    for(int i=0; i<quant; i++){
        Veiculo car;
        car.placa.clear();
        car.marca.clear();
        car.modelo.clear();
        car.tipo.clear();
        car.observacao.clear();
        car.placa.resize(7);
        car.marca.resize(100);
        car.modelo.resize(100);
        car.tipo.resize(100);
        car.observacao.resize(100);

        fscanf(veiculos, "\n%[^;];%[^;];%[^;];%d;%lf;%[^;];%[^;]\n", &car.placa[0], &car.marca[0], &car.modelo[0],&car.ano, &car.preco, &car.tipo[0], &car.observacao[0]);
        cout << "===========================" << endl;
        cout << "Placa: " << car.placa << endl;
        cout << "Marca: " << car.marca << endl;
        cout << "Modelo: " << car.modelo << endl;
        cout << "Ano: " << car.ano << endl;
        cout << "Preco: R$" << car.preco <<".00"<< endl;
        cout << "Tipo: " << car.tipo << endl;
        cout << "Observacao: " << car.observacao << endl;
        cout << "===========================" << endl;
        fseek(veiculos, 1, SEEK_CUR);
    }
}



void CadastrarVeiculo(FILE* veiculos){

    Veiculo novocar;
    cout << "Digite a placa do veiculo:" << endl;
    cin.ignore();
    getline(cin, novocar.placa);

    fseek(veiculos, 0, SEEK_SET);

    int quant;
    fscanf(veiculos, "%d\n", &quant);

    for(int i=0; i<quant; i++){
        Veiculo car;
        car.placa.clear();
        car.marca.clear();
        car.modelo.clear();
        car.tipo.clear();
        car.observacao.clear();
        car.placa.resize(7);
        car.marca.resize(100);
        car.modelo.resize(100);
        car.tipo.resize(100);
        car.observacao.resize(100);

        fscanf(veiculos, "%[^;];%[^;];%[^;];%d;%lf;%[^;];%[^\n]\n", &car.placa[0], &car.marca[0], &car.modelo[0],&car.ano, &car.preco, &car.tipo[0], &car.observacao[0]);

        if(car.placa == novocar.placa){
            cout << "========================================================" << endl;
            cout << "Placa ja cadastrada. Nao e possivel cadastrar o veiculo." << endl;
            cout << "========================================================" << endl;
            return;
        }

        fseek(veiculos, 1, SEEK_CUR);
    }
    cout << "Digite a marca do veiculo: ";
    getline(cin, novocar.marca);
    cout << "Digite o modelo do veiculo: ";
    getline(cin, novocar.modelo);
    cout << "Digite o ano do veiculo: ";
    cin >> novocar.ano;
    cout << "Digite o preco do veiculo: ";
    cin >> novocar.preco;
    cout << "Digite o tipo do veiculo: ";
    cin.ignore();
    getline(cin, novocar.tipo);
    cout << "Digite uma observacao (opcional): ";
    getline(cin, novocar.observacao);

    quant++;
    fseek(veiculos, 0, SEEK_SET);
    fprintf(veiculos, "%d\n", quant);
    fseek(veiculos, 0, SEEK_END);
    fprintf(veiculos,"%s;%s;%s;%d;%lf;%s;%s;\n", &novocar.placa[0], &novocar.marca[0], &novocar.modelo[0], novocar.ano, novocar.preco, &novocar.tipo[0], &novocar.observacao[0]);

    cout << "Veiculo cadastrado com sucesso." << endl;
}



void PesquisarVeiculo(FILE* veiculos){

    int quant;
    fscanf(veiculos, "%d\n", &quant);
    if (quant == 0) {
        cout << "===========================" << endl;
        cout << "Nenhum veiculo cadastrado." << endl;
        cout << "===========================" << endl;
        return;
    }
    Veiculo car;
    string placa;
    int T=0;
    cout << "Digite a placa para buscar um veiculo" << endl;
    cin >> placa;

    fseek(veiculos, 1, SEEK_SET);
    for(int i=0; i<quant; i++){
        car.placa.clear();
        car.marca.clear();
        car.modelo.clear();
        car.tipo.clear();
        car.observacao.clear();
        car.placa.resize(7);
        car.marca.resize(100);
        car.modelo.resize(100);
        car.tipo.resize(100);
        car.observacao.resize(100);


        fscanf(veiculos, "\n%[^;];%[^;];%[^;];%d;%lf;%[^;];%[^\n]\n", &car.placa[0], &car.marca[0], &car.modelo[0],&car.ano, &car.preco, &car.tipo[0], &car.observacao[0]);

        if(car.placa==placa){
            T=1;
            break;
        }
    }

    if(T==1){
        cout << "===========================" << endl;
        cout << "Veiculo encontrado:" << endl;
        cout << "===========================" << endl;
        cout << "===========================" << endl;
        cout << "Placa: " << car.placa << endl;
        cout << "Marca: " << car.marca << endl;
        cout << "Modelo: " << car.modelo << endl;
        cout << "Ano: " << car.ano << endl;
        cout << "Preco: R$" << car.preco <<".00"<< endl;
        cout << "Tipo: " << car.tipo << endl;
        cout << "Observacao: " << car.observacao << endl;
        cout << "===========================" << endl;
    } else {
        cout << "===========================" << endl;
        cout << "Veiculo nao encontrado" << endl;
        cout << "===========================" << endl;
    }
}



void EditarVeiculo(FILE* veiculos){

    fseek(veiculos, 0, SEEK_SET);
    int quant;
    fscanf(veiculos, "%d\n", &quant);
    if (quant == 0) {
        cout << "===========================" << endl;
        cout << "Nenhum veiculo cadastrado." << endl;
        cout << "===========================" << endl;
        return;
    }
    Veiculo edtcar;
    Veiculo car;

    int T=0;
    cout << "Digite a placa para editar um veiculo" << endl;
    cin.ignore();
    getline(cin, edtcar.placa);

    long posicao = ftell(veiculos);
    fseek(veiculos, 0, SEEK_SET);
    for(int i=0; i<quant; i++){
        Veiculo car;
        car.placa.clear();
        car.marca.clear();
        car.modelo.clear();
        car.tipo.clear();
        car.observacao.clear();
        car.placa.resize(7);
        car.marca.resize(100);
        car.modelo.resize(100);
        car.tipo.resize(100);
        car.observacao.resize(100);

        fscanf(veiculos, "%[^;];%[^;];%[^;];%d;%lf;%[^;];%[^\n]\n", &car.placa[0], &car.marca[0], &car.modelo[0],&car.ano, &car.preco, &car.tipo[0], &car.observacao[0]);
        if(car.placa==edtcar.placa){
            T=1;
            cout << "===========================" << endl;
            cout << "Veiculo encontrado:" << endl;
            cout << "===========================" << endl;
            cout << "===========================" << endl;
            cout << "Placa: " << car.placa << endl;
            cout << "Marca: " << car.marca << endl;
            cout << "Modelo: " << car.modelo << endl;
            cout << "Ano: " << car.ano << endl;
            cout << "Preco: R$" << car.preco <<".00"<< endl;
            cout << "Tipo: " << car.tipo << endl;
            cout << "Observacao: " << car.observacao << endl;
            cout << "===========================" << endl;
            break;
        }
        posicao = ftell(veiculos);
    }

    if(T==1){
        cout << "=================================" << endl;
        cout << "Digite os novos dados do veiculo:" << endl;
        cout << "=================================" << endl;

        cout << "Digite a marca do veiculo: ";
        getline(cin, edtcar.marca);
        cout << "Digite o modelo do veiculo: ";
        getline(cin, edtcar.modelo);
        cout << "Digite o ano do veiculo: ";
        cin >> edtcar.ano;
        cout << "Digite o preco do veiculo: ";
        cin >> edtcar.preco;
        cout << "Digite o tipo do veiculo: ";
        cin.ignore();
        getline(cin, edtcar.tipo);
        cout << "Digite uma observacao (opcional): ";
        getline(cin, edtcar.observacao);

        fseek(veiculos, posicao, SEEK_SET);

        fprintf(veiculos,"%s;%s;%s;%d;%lf;%s;%s;\n", &edtcar.placa[0], &edtcar.marca[0], &edtcar.modelo[0], edtcar.ano, edtcar.preco, &edtcar.tipo[0], &edtcar.observacao[0]);

    }else {
        cout << "===========================" << endl;
        cout << "Veiculo nao encontrado" << endl;
        cout << "===========================" << endl;
    }
}



void ApagarVeiculo(FILE*& veiculos) {
    fseek(veiculos, 0, SEEK_SET);
    int quant;
    char conf;
    fscanf(veiculos, "%d\n", &quant);
    if (quant == 0) {
        cout << "Nenhum veiculo cadastrado." << endl;
        return;
    }

    string placa;
    cout << "Digite a placa para apagar um veiculo:" << endl;
    cin.ignore();
    getline(cin, placa);

    FILE* arquivoTemporario = fopen("veiculos_temp.txt", "w");
    int novaQuant = quant;

    for (int i = 0; i < quant; i++) {
        Veiculo car;
        car.placa.clear();
        car.marca.clear();
        car.modelo.clear();
        car.tipo.clear();
        car.observacao.clear();
        car.placa.resize(7);
        car.marca.resize(100);
        car.modelo.resize(100);
        car.tipo.resize(100);
        car.observacao.resize(100);

        fscanf(veiculos, "%[^;];%[^;];%[^;];%d;%lf;%[^;];%[^\n]\n", &car.placa[0], &car.marca[0], &car.modelo[0], &car.ano, &car.preco, &car.tipo[0], &car.observacao[0]);

        if (car.placa == placa) {
            cout << "===========================" << endl;
            cout << "Veiculo encontrado:" << endl;
            cout << "===========================" << endl;
            cout << "Placa: " << car.placa << endl;
            cout << "Marca: " << car.marca << endl;
            cout << "Modelo: " << car.modelo << endl;
            cout << "Ano: " << car.ano << endl;
            cout << "Preco: R$" << car.preco << ".00" << endl;
            cout << "Tipo: " << car.tipo << endl;
            cout << "Observacao: " << car.observacao << endl;
            cout << "===========================" << endl;
            cout << "===================================" << endl;
            cout << "Deseja excluir este veiculo? (S/N):" << endl;
            cout << "===================================" << endl;

            cin >> conf;
            if (conf == 'S' || conf == 's') {
                novaQuant--;
                continue;
            }
        }

        fprintf(arquivoTemporario, "\n\n\n%s;%s;%s;%d;%lf;%s;%s\n", car.placa.c_str(), car.marca.c_str(), car.modelo.c_str(), car.ano, car.preco, car.tipo.c_str(), car.observacao.c_str());
    }

    fclose(veiculos);
    fclose(arquivoTemporario);

    remove("veiculos.txt");
    rename("veiculos_temp.txt", "veiculos.txt");

    veiculos = fopen("veiculos.txt", "r+");
    fprintf(veiculos, "%d\n", novaQuant);

    if (novaQuant < quant) {
        cout << "===========================" << endl;
        cout << "Veiculo excluido." << endl;
        cout << "===========================" << endl;
    } else {
        cout << "=============================================" << endl;
        cout << "Exclusao cancelada ou veiculo nao encontrado." << endl;
        cout << "=============================================" << endl;
    }
}



int main()
{
    FILE* veiculos;
    veiculos=fopen("Veiculos.txt","r+");
    int opcao;
    while(true){
        cout << "===========================" << endl;
        cout << "      Menu prencipal" << endl;
        cout << "1. Listar todos os veiculos" << endl;
        cout << "2. Pesquisar um veiculo" << endl;
        cout << "3. Cadastrar um veiculo" << endl;
        cout << "4. Editar um veiculo" << endl;
        cout << "5. Excluir um veiculo" << endl;
        cout << "6. Sair do programa" << endl;
        cout << "===========================" << endl;

        cin >> opcao;

        if(opcao==1){
            ListaVeiculo(veiculos);
        }else if(opcao==2){
            PesquisarVeiculo(veiculos);
        }else if(opcao==3){
            CadastrarVeiculo(veiculos);
        }else if(opcao==4){
            EditarVeiculo(veiculos);
        }else if(opcao==5){
            ApagarVeiculo(veiculos);
        }else if(opcao==6){
            cout << "================================" << endl;
            cout << "Obrigado por usar o programa :D" << endl;
            cout << "================================" << endl;
            fclose(veiculos);
            return 0;
        } else {
            cout << "opcao invalida, por favor digite um numero de 1 a 6" << endl;
        }
    }
}

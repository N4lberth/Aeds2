#include <iostream>

using namespace std;


class Conta
{
 protected:
    int numero;
    float saldo;
 
 public:
    string PIX;

    Conta(int numero);
    float saldo();

    void sacar(float valor);
    void depositar(float valor);   

    int getConta();
};


class Corrente : public Conta
{
    //...
};


class Poupanca : public Conta
{
 private:
    int aniverssario;
    float valor;
 public:
    int getAniverssario();

    int aplicaJuros();
};


class Especial : public Conta
{
 public:
    float limite;

    Especial(float limite);
};


class Pessoa
{
 protected:
    string nome;
 public:
    Conta contas[];

    Pessoa (string, string CPF);

    string getNome();
};


class Fisica : public Pessoa
{
 protected:
    string CPF;

 public:
    Fisica(string CPF);

    string getCPF();
};


class Juridica : public Pessoa
{
 protected:
    string CNPJ;

 public:
    Juridica(string CPF);

    string getCNPJ();
};


class Hitorico
{
 private:
    int numero;
    float saldo,valor;

 public:
    void operar (Conta conta, int operacao, float valor);
};
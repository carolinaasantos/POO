#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
using namespace std;

namespace poo {
    //Criação classe Pessoa
    class Pessoa {
    public:
        Pessoa(string, string); //Construtor
        ~Pessoa(); //Destrutor
        //Métodos
        string getCPF() const;
        string getNome() const;
        virtual void imprime() const;
    private:
        //Atributos
        string nome;
        string cpf;
    };
}

#endif
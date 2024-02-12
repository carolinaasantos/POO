#ifndef COMPANHIA_H
#define COMPANHIA_H

#include <iostream>
using namespace std;

namespace poo {
    //Criação classe Companhia
    class Companhia {
    public:
        Companhia(string, string); //Construtor
        ~Companhia(); //Destrutor
        //Métodos
        string getCNPJ() const;
        string getNome() const;
        void imprime() const;
    private:
        //Atributos
        string nome;
        string cnpj;
    };
}

#endif
#ifndef VOO_H
#define VOO_H

#include "Pessoa.h"
#include "DataHorario.h"
#include "Companhia.h"

namespace poo {
    //Criação classe Voo
    class Voo {
    public:
        Voo(Companhia&, string, string, DataHorario&); //Construtor
        ~Voo(); //Destrutor
        //Métodos
        string proximoLivre();
        bool verifica(string);
        bool ocupa(string, Pessoa&);
        bool desocupa(string);
        int vagas();
        void imprime();
    private:
        //Atributos
        Companhia& companhia;
        string destino;
        string origem;
        DataHorario& data;
        Pessoa* poltrona[25][6];
        int numVagas;
    };
}

#endif
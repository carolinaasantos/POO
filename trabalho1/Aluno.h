#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

namespace poo {
    //Criação classe Aluno
    class Aluno : public Pessoa {
    public:
        Aluno(string, string, int, double, double, double, double, double); //Construtor
        ~Aluno(); //Destrutor
        //Métodos
        int getRA() const;
        void imprime() const;
        double media() const;
        bool aprovado() const;
        bool pac() const;
        double notaPAC() const;
    private:
        //Atributos
        int ra;
        double p1;
        double p2;
        double t1;
        double t2;
        double t3;
    };
}

#endif
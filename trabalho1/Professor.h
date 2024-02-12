#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"

namespace poo {
    //Criação classe Professor
    class Professor : public Pessoa {
    public:
        Professor(string, string, string); //Construtor
        ~Professor(); //Destrutor
        //Métodos
        string getUniversidade() const;
        void imprime() const;
    private:
        //Atributos
        string nomeUniversidade;
    };
}

#endif
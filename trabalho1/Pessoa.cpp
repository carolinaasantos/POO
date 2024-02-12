#include "Pessoa.h"

namespace poo {
    //Construtor
    Pessoa::Pessoa(string cpf, string nome) : nome(nome), cpf(cpf) {
    }

    //Destrutor
    Pessoa::~Pessoa() {
    }

    //Implementação dos métodos
    string Pessoa::getCPF() const {
        return cpf;
    }

    string Pessoa::getNome() const {
        return nome;
    }

    void Pessoa::imprime() const {
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << cpf << endl;
    }
}
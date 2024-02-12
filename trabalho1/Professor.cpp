#include "Professor.h"

namespace poo
{
    //Construtor
    Professor::Professor(string cpf, string nome, string nomeUniversidade) : Pessoa(cpf, nome), nomeUniversidade(nomeUniversidade) {
    }
    
    //Destrutor
    Professor::~Professor() {
    }
    
    //Implementação dos métodos
    string Professor::getUniversidade() const {
        return nomeUniversidade;
    }
    
    void Professor::imprime() const {
        Pessoa::imprime();
        cout << "Nome da universidade: " << nomeUniversidade << endl;       
    }
}
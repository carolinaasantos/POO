#include "Companhia.h"

namespace poo
{
    //Construtor
    Companhia::Companhia(string nome, string cnpj) : nome(nome), cnpj(cnpj) {   
    }
    
    //Destrutor
    Companhia::~Companhia() {
    }
    
    //Implementação dos métodos
    string Companhia::getCNPJ() const {
        return cnpj;
    }
    
    string Companhia::getNome() const {
        return nome;
    }
    
    void Companhia::imprime() const {
        cout << "Nome da companhia: " << nome << endl;
        cout << "CNPJ: " << cnpj << endl;
    }
}
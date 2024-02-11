#include "Pessoa.h"
#include "Veiculo.h"
#include <algorithm>
#include <cstring>

//Construtor
Pessoa::Pessoa(string nome, string cpf) : nome(nome), cpf(cpf) {
    qntdVeiculos = 0;
    qntdCarros = 0;
    qntdCaminhoes = 0;
}

//Destrutor
Pessoa::~Pessoa() {
}

// Retorna o nome da pessoa
string Pessoa::getNome() const {
    return nome;
}

// Estabelece um nome para a pessoa
void Pessoa::setNome(string nome) {
    this->nome = nome;
}

// Retorna o CPF da pessoa
string Pessoa::getCPF() const {
    return cpf;
}

// Estabelece um CPF para a pessoa
void Pessoa::setCPF(string cpf) {
    this->cpf = cpf;
}

// Adiciona veículos ao vector de veículos da pessoa
bool Pessoa::adicionaVeiculo(Veiculo& veiculo) {
    bool ehAdicionado = true;
    for (unsigned long int i = 0; i < veiculos.size(); i++) {
        // Caso já exista um veículo com essa placa, o novo veículo não é adicionado
        if (veiculos[i]->getPlaca() == veiculo.getPlaca()) {
            ehAdicionado = false;
        }
    }
    if (ehAdicionado) {
        veiculos.push_back(&veiculo);
        switch (veiculo.getCategoria()) {
            case CARRO: {
                qntdCarros++;
                break;
            }
            case CAMINHAO: {
                qntdCaminhoes++;
                break;
            }
        }
        qntdVeiculos++;
    }
    return ehAdicionado;
}

// Remove veículo a partir de sua placa
bool Pessoa::removeVeiculo(string placaVeiculo) {
    bool foiRemovido = false;
    vector<Veiculo*>::iterator indice;
    Veiculo* veiculoParaRemover;
    if (qntdVeiculos <= 0) {
        foiRemovido = false;
    }
    else {
        veiculoParaRemover = obtemVeiculo(placaVeiculo);
        if (veiculoParaRemover != NULL) {
            indice = find(veiculos.begin(), veiculos.end(), veiculoParaRemover);
            switch (veiculoParaRemover->getCategoria()) {
                    case CARRO: {
                        qntdCarros--;
                        break;
                    }
                    case CAMINHAO: {
                        qntdCaminhoes--;
                        break;
                    }  
            }
            veiculos.erase(indice);
            foiRemovido = true;
            qntdVeiculos--;
        }
    }
    return foiRemovido;
}

// Obtém um veículo a partir de sua placa
Veiculo* Pessoa::obtemVeiculo(string placa) {
    Veiculo* veiculoObtido = NULL;
    for (int i = 0; i < qntdVeiculos; i++) {
        if (veiculos[i]->getPlaca() == placa)
            veiculoObtido = veiculos[i];
    }
    return veiculoObtido;
}

// Retorna quantidade de veículos
int Pessoa::qtdeVeiculos() {
    return qntdVeiculos;
}

// Retorna quantidade de carros
int Pessoa::qtdeCarros() {
    return qntdCarros;
}

// Retorna quantidade de caminhoes
int Pessoa::qtdeCaminhoes() {
    return qntdCaminhoes;
}

// Método que facilita impressão dos veículos contidos em um vector
void Pessoa::imprimeVeiculos(vector <Veiculo*> a) {
    for (unsigned long int i = 0; i < a.size(); i++) {
        cout << "== Veiculo " << i+1 << " ==" << endl;
        a[i]->imprime();
        cout << endl;
    }
}

// Método imprime
void Pessoa::imprime(int criterio) {
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl << endl;
    vector<Veiculo*> copiaVeiculos = veiculos;
    // Impressão dos veículos dependendo da ordem escolhida
    switch (criterio) {
        case PLACA: {
            sort(copiaVeiculos.begin(), copiaVeiculos.end(), Veiculo::comparaPlaca);
            break;
        }
        case ANO: {
            sort(copiaVeiculos.begin(), copiaVeiculos.end(), Veiculo::comparaAno);
            break;
        }
        case CATEGORIA: {
            sort(copiaVeiculos.begin(), copiaVeiculos.end(), Veiculo::comparaCategoria);
            break;
        }
        default:
            break;
    }
    imprimeVeiculos(copiaVeiculos);
}

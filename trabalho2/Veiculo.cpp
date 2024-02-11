#include "Veiculo.h"
#include "Carro.h"

//Construtor
Veiculo::Veiculo(string placa, string marca, string cor, int ano) : placa(placa), marca(marca), cor(cor), ano(ano) {
}

//Destrutor
Veiculo::~Veiculo() {
}

// Retorna a placa do veíuculo
string Veiculo::getPlaca() const {
    return placa;
}

// Estabelece uma placa ao veículo
void Veiculo::setPlaca(string placa) {
    this->placa = placa;
}

// Retorna a marca do veículo
string Veiculo::getMarca() const {
    return marca;
}

// Estabelece uma marca ao veículo
void Veiculo::setMarca(string marca) {
    this->marca = marca;
}

// Retorna a cor do veículo
string Veiculo::getCor() const {
    return cor;
}

// Estabelece uma cor ao veículo
void Veiculo::setCor(string cor) {
    this->cor = cor;
}

// Retorna o ano do veículo
int Veiculo::getAno() const {
    return ano;
}

// Estabelece um ano ao veículo
void Veiculo::setAno(int ano) {
    this->ano = ano;
}

// Imprime as informações do veículo
void Veiculo::imprime() const {
    string categoria;
    cout << "Placa: " << placa << endl;
    cout << "Marca: " << marca << endl;
    cout << "Cor: " << cor << endl;
    cout << "Ano: " << ano << endl;
    
    // Imprime a categoria com base nas constantes CARRO (0) e CAMINHAO (1)
    switch (getCategoria()) {
        case CARRO: {
            categoria = "Carro";
            break;
        }
        case CAMINHAO: {
            categoria = "Caminhao";
            break;
        }
    }
    cout << "Categoria: " << categoria << endl;
}

// Método booleano de comparação entre a placa de dois veículos
bool Veiculo::comparaPlaca(const Veiculo* v1, const Veiculo* v2) {
    return v1->getPlaca() < v2->getPlaca();
}

// Método booleano de comparação entre o ano de dois veículos
bool Veiculo::comparaAno(const Veiculo* v1, const Veiculo* v2) {
    bool compara = v1->getAno() == v2->getAno();
    if (compara) {
        return comparaPlaca(v1,v2);
    }
    else
        return v1->getAno() < v2->getAno();
}

// Método booleano de comparação entre a categoria de dois veículos
bool Veiculo::comparaCategoria(const Veiculo* v1, const Veiculo* v2) {
    bool compara = v1->getCategoria() == v2->getCategoria();
    if (compara) {
        return comparaPlaca(v1, v2);
    }
    else {
        return v1->getCategoria() < v2->getCategoria();
    }
}

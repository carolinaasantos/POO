#include "Caminhao.h"

//Construtor
Caminhao::Caminhao(string placa, string marca, string cor, int ano, int num_eixos) : Veiculo(placa, marca, cor, ano), num_eixos(num_eixos) {
}

//Destrutor
Caminhao::~Caminhao() {
}

// Retorna o número de eixos do caminhão
int Caminhao::getNum_eixos() const {
    return num_eixos;
}

// Estabelece um número de eixos para o caminhão
void Caminhao::setNum_eixos(int num_eixos) {
    this->num_eixos = num_eixos;
}

// Retorna a categoria do cmainhão (2)
int Caminhao::getCategoria() const {
    return 2;
}

// Imprime as informações do caminhão
void Caminhao::imprime() const {
    Veiculo::imprime();
    cout << "Numero de eixos: " << num_eixos << endl;
}

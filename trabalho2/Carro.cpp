#include "Carro.h"

//Construtor
Carro::Carro(string placa, string marca, string cor, int ano, double volume) : Veiculo(placa, marca, cor, ano), volume(volume) {
}

//Destrutor
Carro::~Carro() {
}

// Retorna o volume do porta-malas do carro
double Carro::getVolume() const {
    return volume;
}

// Estabelece um volume para o porta-malas do carro
void Carro::setVolume(double volume) {
    this->volume = volume;   
}

// Retorna a categoria do carro (1)
int Carro::getCategoria() const {
    return 1;
}

// Imprime as informações do carro
void Carro::imprime() const {
    Veiculo::imprime();
    cout << "Volume: " << volume << endl;
}

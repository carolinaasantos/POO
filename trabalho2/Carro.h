#ifndef CARRO_H
#define CARRO_H

#include "Veiculo.h"

class Carro : public Veiculo {
public:
    Carro(string, string, string, int, double); // Construtor
    virtual ~Carro(); // Destrutor
    // Métodos getters e setters
    double getVolume() const;
    void setVolume(double);
    virtual int getCategoria() const;
    // Método imprime
    virtual void imprime() const;
private:
    //Declaração dos atributos privados da classe Carro
    double volume;
};

#endif
#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

class Caminhao : public Veiculo {
public:
    Caminhao(string, string, string, int, int); // Construtor
    virtual ~Caminhao(); // Destrutor
    // Métodos getters e setters
    int getNum_eixos() const;
    void setNum_eixos(int);
    int getCategoria() const;
    // Método imprime
    virtual void imprime() const;
private:
    //Declaração dos atributos privados da classe Carro
    int num_eixos;
};

#endif
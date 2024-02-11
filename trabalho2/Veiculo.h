#ifndef VEICULO_H
#define VEICULO_H

#include "Constantes.h"
#include <iostream>
using namespace std;

class Veiculo {
public:
    Veiculo(string, string, string, int); // Construtor
    virtual ~Veiculo(); // Destrutor
    // Métodos getters e setters
    string getPlaca() const;
    void setPlaca(string);
    string getMarca() const;
    void setMarca(string);
    string getCor() const;
    void setCor(string);
    int getAno() const;
    void setAno(int);
    virtual int getCategoria() const = 0; //Método abstrato
    // Método imprime
    virtual void imprime() const;

    //Declaração dos métodos booleanos de comparação dos atributos de dois veículos
    static bool comparaPlaca(const Veiculo* v1, const Veiculo* v2);
    static bool comparaAno(const Veiculo* v1, const Veiculo* v2);
    static bool comparaCategoria(const Veiculo* v1, const Veiculo* v2);

private:
    //Declaração dos atributos privados da classe Veículo
    string placa;
    string marca;
    string cor;
    int ano;
};

#endif
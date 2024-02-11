#ifndef PESSOA_H
#define PESSOA_H

#include "Constantes.h"
#include "Veiculo.h"
#include <vector>
#include <iostream>
using namespace std;

class Pessoa {
public:
    Pessoa(string, string); // Construtor
    virtual ~Pessoa(); // Destrutor
    // Métodos getters e setters
    string getNome() const;
    void setNome(string);
    string getCPF() const;
    void setCPF(string);
    // Métodos para adição e remoção de veículos de uma pessoa
    bool adicionaVeiculo(Veiculo& veiculo);
    bool removeVeiculo(string);
    Veiculo* obtemVeiculo(string);
    // Métodos que retornam quantidade de veiculos, carros e caminhoes
    int qtdeVeiculos();
    int qtdeCarros();
    int qtdeCaminhoes();
    // Métodos imprime
    void imprime(int); //Método que utiliza critérios constantes 1, 2, 3, 4
private:
    //Declaração dos atributos privados da classe Pessoa
    string nome;
    string cpf;
    vector <Veiculo*> veiculos;
    int qntdVeiculos;
    int qntdCarros;
    int qntdCaminhoes;
    void imprimeVeiculos(vector <Veiculo*> a); //Método criado para facilitar impressão dos veículos
};

#endif
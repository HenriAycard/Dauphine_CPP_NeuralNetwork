//
//  PerceptronCachee.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 30/05/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include "PerceptronCachee.hpp"

PerceptronCachee::PerceptronCachee()
{
}

PerceptronCachee::PerceptronCachee(int input_size, Fonction_activation * fnc_activation, char label, std::vector<Perceptron> & vect):Perceptron(input_size, fnc_activation, label)
{
    this->perceptrons = vect;
}


PerceptronCachee::~PerceptronCachee()
{
}

double PerceptronCachee::calcul_delta(Input & input)
{
    double value = 0;
    double somme_wx = this->get_poids(0);
    double somme_deltaw = 0;
    int i = 0;
    while (input[i] != -1) {
        somme_wx += input[i] * this->get_poids(i + 1);
        i = i + 1;
    }
    for (int i = 0; i < this->perceptrons.size(); i++) {
        somme_deltaw += this->perceptrons[i].get_delta() * this->perceptrons[i].get_poids(this->label - 48);
    }
    somme_wx = this->fonction_activation->prim(somme_wx);
    value = somme_wx * somme_deltaw;
    this->delta = value;
    return value;
}

void PerceptronCachee::backprop(Input & input, double mu)
{
    int i = 0;
    this->poids[0] = this->poids[0] - mu * this->get_delta();
    //std::cout << "-------------EVALUATE--------------" << std::endl;
    while (input[i] != -1) {
        //std::cout << poids[i + 1] << std::endl;
        this->poids[i + 1] = this->poids[i + 1] - mu * input[i] * this->get_delta();
        i = i + 1;
    }
    this->calcul_delta(input);
    //std::cout << "---------------------------" << std::endl;

}

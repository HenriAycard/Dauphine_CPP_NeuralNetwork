//
//  NN1.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include "NN1.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


NN1::NN1()
{
}

NN1::NN1(int taille_input, FonctionActivation * fnc_activation, int nbr_perceptron)
{
    if (taille_input != 4 && taille_input != 784) {
        throw string("Erreur size Input");
    }
    else {
        /*
         L'algorithme du perceptron permet de distinguer deux catégories uniquement.
         Dans les problèmes de classification, nous considerons plus de 2 catégories
         Donc 3 pour les fleurs et 10 pour les images
         */
        if (nbr_perceptron != 10 && nbr_perceptron != 3) {
            throw string("Erreur category name");
        }
        else {
            this->nbr_perceptron = nbr_perceptron;
            this->perceptron_list = new Perceptron[nbr_perceptron];
            for (int i = 0; i < nbr_perceptron; ++i) {
                Perceptron p = Perceptron(taille_input, fnc_activation, i);
                this->perceptron_list[i] = p;
            }
        }
    }
}


NN1::~NN1()
{
}

char NN1::evaluation(Input & input)
{
    double max = 0;
    int indice_max = 0;
    for (int i = 0; i < this->nbr_perceptron; ++i) {
        double valeur = this->perceptron_list[i].forward(input);
        if (valeur >= max) {
            max = valeur;
            indice_max = i;
        }
    }
    return(to_string(indice_max)[0]);
}

void NN1::apprentissage(Input & input, double mu)
{
    for (int i = 0; i < this->nbr_perceptron; ++i) {
        this->perceptron_list[i].backprop(input, mu);
    }
}

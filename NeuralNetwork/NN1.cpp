//
//  NN1.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021. All rights reserved.
//

#include "NN1.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


NN1::NN1()
{
}

/**
 @param inputSize : un entier correspondant à la taille des inputs (4 pour les fleurs et 784 pour les images)
 @param nbrPerceptron : un entier correspondant au nombre de catégories (donc le nombre de perceptrons compris entre 3 et 10)
 @param fonctionActivation :  une fonction d'activation (Tanh ou Sigmoide) pour initialiser les Perceptrons
 */
NN1::NN1(int inputSize, int nbrPerceptron, FonctionActivation * fonctionActivation)
{
    if (inputSize != 4 && inputSize != 784) {
        throw string("Erreur : Taille de l input");
    }
    else {
        /*
         L'algorithme du perceptron permet de distinguer deux catégories uniquement.
         Dans les problèmes de classification, nous considerons plus de 2 catégories
         Donc 3 pour les fleurs et 10 pour les images
         */
        if (nbrPerceptron != 3 && nbrPerceptron != 10) {
            throw string("Erreur : Nom de Categorie");
        }
        else {
            this->nbrPerceptron = nbrPerceptron;
            this->lstPerceptron = new Perceptron[nbrPerceptron];
            
            for (int index = 0; index < nbrPerceptron; ++index) {
                Perceptron p = Perceptron(inputSize, fonctionActivation, index);
                this->lstPerceptron[index] = p;
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
    for (int index = 0; index < this->nbrPerceptron; ++index) {
        double valeur = this->lstPerceptron[index].forward(input);
        if (valeur >= max) {
            max = valeur;
            indice_max = index;
        }
    }
    return(to_string(indice_max)[0]);
}

void NN1::apprentissage(Input & input, double mu)
{
    for (int i = 0; i < this->nbrPerceptron; ++i) {
        this->lstPerceptron[i].backprop(input, mu);
    }
}

//
//  Perceptron.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include "Perceptron.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

/**
 @param inputSize : correspond à la taille de l'input (par exemple, 4 pour les fleurs et 784 pour les images)
 @param fonctionActivation : un pointeur pour avoir une même fonction d'activation commune à tous les perceptrons
 @param label : correspond au label du perceptron
 @brief Le constructeur initialise les poids du perceptron de manière aléatoire (par exemple en choisissant des valeurs
 entières entre -1 et 1 aléatoirement.
 */
Perceptron::Perceptron(int inputSize, FonctionActivation * fonctionActivation, char label)
{
    this->fonctionActivation = fonctionActivation;
    this->label = label;
    this->delta = 0;
    // Une erreur peut etre déclenché lors du malloc : Incorrect checksum for freed object
    this->poids = (double *) malloc(inputSize * sizeof(double));
    for (int i=0; i<=inputSize; i++)
    {
        this->poids[i] = rand() % 2 - 1;
    }
}

Perceptron::Perceptron()
{
}

Perceptron::~Perceptron()
{
}

/**
 @param indice : prend en paramètre un indice (int)
 @return renvoie une valeur réelle (double) correspondant à la valeur du poids correspondant à l'indice
 */
double Perceptron::get_poids(int indice)
{
    return this->poids[indice];
}

/**
 @param input : prend un paramètre de type Input par référence
 @return renvoie une valeur réelle (double) correspondant à l'application de l'algo du perceptron
 à l'input en paramètre (correspond au calcul de A(x))
 @brief L'algorithme de classification prend en entrée le vecteur de caractéristiques d'un input (x = (x_1, ..., x_n))
 et renvoie un label correspondant à celui de l'input. L'objectif est d'avoir A(x) = y. Le perceptron est un algo de classification
 avec deux catégorie d'inputs). Il est décrit par un ensemble de poids w = (w_0, w_1, ... , w_n)
 L'algo de classification sera décrit par l'équation suivante : A(x)= 𝛿(w_0+∑_(i=1)^n〖w_i * x_i 〗
 */
double Perceptron::forward(Input & input)
{
    double somme=this->get_poids(0);
    int i = 0;
    while (input[i] != -1) {
        somme += this->get_poids(i+1) * input[i];
        i = i + 1;
    }
    return (*this->fonctionActivation)(somme);
}

double Perceptron::calcul_delta(Input & input)
{
    double delta = 0;
    int i = 0;
    double somme = this->poids[0];
    double a_x = this->forward(input);
    int y_char = input.get_label();
    string y_str = to_string(y_char);
    double y = stod(y_str);

    while (input[i] != -1) {
        somme += this->get_poids(i+1) * input[i];
        i = i + 1;
    }

    delta = (this->fonctionActivation->prim(somme)) * (a_x - y);
    this->delta = delta;
    return this->delta;
}

double Perceptron::get_delta()
{
    return this->delta;
}

char Perceptron::get_label()
{
    return this->label;
}

void Perceptron::backprop(Input & input, double mu)
{
    int i = 0;
    this->calcul_delta(input);
    this->poids[0] = this->poids[0] - mu * this->get_delta();
    while (input[i] != -1) {
        this->poids[i+1] = this->poids[i+1] - mu * input[i] * this->get_delta();
        i = i + 1;
    }
    
}

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
PerceptronCachee::~PerceptronCachee()
{
}

 /**
 @param input_size : correspond à la taille de l'input (par exemple, 4 pour les fleurs et 784 pour les images)
 @param fnc_activation : un pointeur pour avoir une même fonction d'activation commune à tous les perceptrons
 @param label : correspond au label du perceptron
 @param vect correspond au vecteur de pointeurs vers des Perceptrons
 @brief Un constructeur qui prend en paramètre un entier correspondant à la taille de l’input, une
 fonction d’activation (un pointeur), un char correspondant au label du
 perceptron, ainsi qu’un vecteur (une référence) de pointeurs vers des
 Perceptrons (les perceptrons de la couche de sortie).
 */
PerceptronCachee::PerceptronCachee(int input_size, FonctionActivation * fnc_activation, char label, std::vector<Perceptron> & vect):Perceptron(input_size, fnc_activation, label)
{
    this->perceptrons = vect;
}

/**
 @brief Prend en paramètre un Input ( par référence), et renvoie une valeur réelle (double) correspondant à l’évaluation de la valeur 𝛿𝑠
  sommeWX = (w_0+∑_(i=1)^n〖w_i * x_i 〗
  sommeDeltaW = ∑_(i=1)^n〖 𝛿𝑙 * w_l 〗
 */
double PerceptronCachee::calcul_delta(Input & input)
{
    // Valeur de retour
    double valueDelta = 0;
    
    // on initialise: w_0
    double sommeWX = this->get_poids(0);
    double sommeDeltaW = 0;
    double prim = 0;
    
    
    // sommeWX = ∑_(i=1)^n〖 w_i * x_i 〗
    int indice = 0;
    while (input[indice] != -1) {
        //         〖     w_i     *          x_i               〗
        sommeWX += input[indice] * this->get_poids(indice + 1);
        indice = indice + 1;
    }
    
    // sommeDeltaW = ∑_(i=1)^n〖 𝛿𝑙 * w_l 〗
    // Les valeurs 𝛿𝑙 est accessible par la fonction membre  get_delta
    // Les valeurs w_l est accessible par la fonction membre get_poids du perceptron de la couche de sortie correspondant.
    for (int i = 0; i < this->perceptrons.size(); i++) {
        sommeDeltaW += this->perceptrons[i].get_delta() * this->perceptrons[i].get_poids(this->label - 48);
    }
    
    // Calcule de la primitive
    prim = this->fonction_activation->prim(sommeWX);
    
    valueDelta = prim * sommeDeltaW;
    
    //  Cette fonction va également stocker cette valeur dans le champ delta.
    this->delta = valueDelta;
    return valueDelta;
}

/**
 @Brief Une fonction membre backprop qui prend en paramètre un Input (par
 référence), ainsi qu’une valeur réelle (double) appelé mu correspondant au pas de gradient 𝜇, et qui ne
 renvoie rien. Cette fonction va apprendre les poids à partir de l’input en paramètre en
 utilisant la formule donnée
 */
void PerceptronCachee::backprop(Input & input, double mu)
{
    int i = 0;
    this->poids[0] = this->poids[0] - mu * this->get_delta();
    while (input[i] != -1) {
        this->poids[i + 1] = this->poids[i + 1] - mu * input[i] * this->get_delta();
        i = i + 1;
    }
    this->calcul_delta(input);

}

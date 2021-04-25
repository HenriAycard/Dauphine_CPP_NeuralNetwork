//
//  Perceptron.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#ifndef Perceptron_hpp
#define Perceptron_hpp

#include <stdio.h>
#include "Input.hpp"
#include "Fonction_activation.h"

class Perceptron
{
    
/**
 @brief La classe Perceptron sert à représenter un perceptron, et devra donc stocker l'ensemble des poids ainsi que la
 fonction d'activation (cela correspondra à deux de ses champs). Un perceptron devra également posséder un champ réel
 (double) supplémentaire servant à stocker la valeur 𝛿𝑘−1 décrite précédemment. Enfin, un label indique pour quelle
 catégorie le perceptron devra renvoyer une valeur proche de 1
 */
protected:
    double * poids;
    Fonction_activation * fonction_activation;
    double delta; // stocke la valeur de 𝛿𝑘−1
    char label;

public:

        Perceptron(int input_size, Fonction_activation * fnc_activation, char label);
    
        Perceptron();
    
        ~Perceptron();

        double get_poids(int indice);

        double forward(Input & input);

        double calcul_delta(Input & input);

        double get_delta();

        char get_label();

        void backprop(Input & input, double mu);
};
#endif /* Perceptron_hpp */

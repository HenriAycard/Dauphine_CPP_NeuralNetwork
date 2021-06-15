//
//  NN1.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#ifndef NN1_hpp
#define NN1_hpp

#include <stdio.h>
#include "Input.hpp"
#include "Perceptron.hpp"



class NN1
{
    /*
        La classe NN1 sert à représenter un réseau de neurones.
        Cette classe a pour membre l’ensemble des perceptrons qui
        constituent le réseau de neurones.
    */
private:
    Perceptron * perceptron_list; // tab perceptron
    int nbr_perceptron;

public:
    // ajouter les paramètres
    NN1();

    NN1(int taille_input, FonctionActivation * fnc_activation, int nbr_perceptron);

    ~NN1();

    char evaluation(Input & input);

    void apprentissage(Input &input, double mu);

};

#endif /* NN1_hpp */

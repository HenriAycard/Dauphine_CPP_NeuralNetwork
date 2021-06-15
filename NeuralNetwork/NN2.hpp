//
//  NN2.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 30/05/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#ifndef NN2_hpp
#define NN2_hpp

#include <stdio.h>
#include "NN2.hpp"
#include "Perceptron.hpp"
#include "PerceptronCachee.hpp"
#include "Input.hpp"

/**
 @brief La classe NN2 sert à représenter un réseau de neurones avec une couche cachée. Cette classe a pour
 membre l’ensemble des perceptrons de la couche caché (chacun de la classe Perceptron_cachee),
 ainsi que l’ensemble des perceptrons de la couche de sortie (chacun de la classe Perceptron) qui
 constituent le réseau de neurones.
 */
class NN2
{
private:
    PerceptronCachee * lstPerceptronCachee;
    Perceptron * lstPerceptron;
    // Correspond au nombre d element dans la liste Perceptron (lstPerceptron)
    int nbrPerceptron;
    // Correspond au nombre d element dans la liste Perceptron Cachee (lstPerceptronCachee)
    int nbrPerceptroncachee;

public:
    NN2();
    
    ~NN2();

    NN2(int inputSize, int nbrCategorie, int nbrPerceptronC, FonctionActivation * f);

    char evaluation(Input & input);

    void apprentissage(Input & input, double mu);


};

#endif /* NN2_hpp */

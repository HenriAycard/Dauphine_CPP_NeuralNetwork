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
#include "Perceptron_cachee.hpp"
#include "Fonction_activation.hpp"
#include "Input.hpp"

class NN2
{
private:
    Perceptron * perceptron_list;
    Perceptron_cachee * perceptron_cachee_list;
    int nbr_perceptron;
    int nbr_perceptron_cachee;

public:
    NN2();

    NN2(int taille_input, int nbr_cat, int nbr_perceptron_c, Fonction_activation * f);

    ~NN2();

    char evaluation(Input & input);

    void apprentissage(Input & input, double mu);


};

#endif /* NN2_hpp */

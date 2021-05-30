//
//  PerceptronCachee.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 30/05/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#ifndef PerceptronCachee_hpp
#define PerceptronCachee_hpp

#include <stdio.h>
#include "Perceptron.hpp"
#include <vector>
#include <iostream>
#include "Fonction_activation.h"

class PerceptronCachee :
    public Perceptron
{
private:
    std::vector<Perceptron> perceptrons;

public:
    PerceptronCachee();
    PerceptronCachee(int input_size, Fonction_activation * fnc_activation, char label, std::vector<Perceptron> & vect);

    ~PerceptronCachee();

    double calcul_delta(Input & input);

    void backprop(Input & input, double mu);
};

#endif /* PerceptronCachee_hpp */

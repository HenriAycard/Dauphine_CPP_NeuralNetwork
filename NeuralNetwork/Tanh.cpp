//
//  Tanh.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include "Tanh.hpp"
#include <math.h>

Tanh::Tanh()
{
}

Tanh::~Tanh()
{
}

double Tanh::operator()(double nombre)
{
    return (exp(nombre) - exp(-nombre)) / (exp(nombre) + exp(-nombre));
}

double Tanh::prim(double nombre)
{
    return 1 - pow((*this)(nombre), 2);
}


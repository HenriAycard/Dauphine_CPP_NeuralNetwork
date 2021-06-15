//
//  Sigmoide.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include "Sigmoide.hpp"
#include <math.h>


Sigmoide::Sigmoide()
{
}

Sigmoide::~Sigmoide()
{
}

// sig(x) = 1 / (1 + exp(-x))
double Sigmoide::operator()(double nombre)
{
    return 1 / (1 + exp(-nombre));
}

//sig'(x) = (1 - sig(x))
double Sigmoide::prim(double nombre)
{
    return (*this)(nombre) * (1 - (*this)(nombre));
}

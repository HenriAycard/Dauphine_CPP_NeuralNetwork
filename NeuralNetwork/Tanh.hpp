//
//  Tanh.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//
#include "Fonction_Activation.h"

#ifndef Tanh_hpp
#define Tanh_hpp

#include <stdio.h>

/**
 La class Tanh descend de la classe Fonction_activation et correspond tout simplement à la tangente hyperbolique.
 Cette class surdéfinie naturellement l'opérateur () et la fonction prim
 */

class Tanh: public Fonction_activation {
public:
    Tanh();
    
    ~Tanh();
    
    //tanh(x) = (exp(x) - exp(-x))/ (exp(x) + exp(-x))
    double operator()(double nombre);
    
    //tanh'(x) = 1 - (tanh(x))^2)
    double prim(double nombre);
    
};
#endif /* Tanh_hpp */

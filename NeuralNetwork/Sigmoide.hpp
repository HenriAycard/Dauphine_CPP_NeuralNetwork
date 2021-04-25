//
//  Sigmoide.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//
#include "Fonction_Activation.h"
#ifndef Sigmoide_hpp
#define Sigmoide_hpp

#include <stdio.h>

/**
 La classe Sigmoide descend de la classe Fonction_activation et correspond tout simplement à la fonction sigmoide.
 Cette classe surdéfinie naturellement l'opérateur() et la fonction membre prim.
 */
class Sigmoide: public Fonction_activation {
public:
    Sigmoide();
    
    ~Sigmoide();
    
    // sig(x) = 1 / (1 + exp(-x))
    double operator()(double nombre);
    
    //sig'(x) = (1 - sig(x))
    double prim(double nombre);
};
#endif /* Sigmoide_hpp */

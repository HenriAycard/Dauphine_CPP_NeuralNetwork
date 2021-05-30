//
//  InputIntermediaire.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 30/05/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#ifndef InputIntermediaire_hpp
#define InputIntermediaire_hpp

#include <stdio.h>
#include "InputIntermediaire.hpp"
#include "Input.hpp"
#include <vector>
#include <iostream>

class InputIntermediaire : public Input
{
private :
    std::vector<double> valIntermediaires;
public:
    InputIntermediaire();

    InputIntermediaire(char  label);

    ~InputIntermediaire();

    void add(double value);

    double operator[](int indice);
};
#endif /* InputIntermediaire_hpp */

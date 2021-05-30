//
//  InputIntermediaire.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 30/05/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include "InputIntermediaire.hpp"


InputIntermediaire::InputIntermediaire()
{
}

InputIntermediaire::InputIntermediaire(char label)
{
    this->set_label(label + 48);
    this->valIntermediaires = std::vector<double>();
}


InputIntermediaire::~InputIntermediaire()
{
}

void InputIntermediaire::add(double value)
{
    this->valIntermediaires.push_back(value);
}

double InputIntermediaire::operator[](int indice)
{
    if (indice < this->valIntermediaires.size() && indice >=0) {
        return(this->valIntermediaires[indice]);
    }
    else {
        return(-1);
    }
}

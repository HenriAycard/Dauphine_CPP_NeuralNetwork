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
    /**
     @brief La classe Input_intermediaire va servir à stocker les valeurs intermédiaires
     𝒂(𝟏) = (𝑎1, … , 𝑎𝑡) à la sortie des perceptrons de la couche cachée. Elle descend de la classe Input. Elle possède un champ
     qui va contenir des valeurs réelles (double), qui sera de préférence un vecteur (vector).
     */
    std::vector<double> valeurIntermediaire;
public:
    InputIntermediaire();

    InputIntermediaire(char  label);

    ~InputIntermediaire();

    void add(double value);

    double operator[](int indice);
};
#endif /* InputIntermediaire_hpp */

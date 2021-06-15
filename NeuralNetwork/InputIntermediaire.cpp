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
InputIntermediaire::~InputIntermediaire()
{
}

/**
 @brief Un constructeur avec un paramètre de type char correspondant au label qui va initialiser le
 champ label et construire le vecteur
 */
InputIntermediaire::InputIntermediaire(char label)
{
    this->set_label(label + 48);
    this->valeurIntermediaire = std::vector<double>();
}

/**
 @brief Une fonction membre add qui prend en paramètre un réel (double) dont la valeur est
 ajoutée au vecteur. Cette fonction ne renvoie rien.
 */
void InputIntermediaire::add(double value)
{
    this->valeurIntermediaire.push_back(value);
}

/**
 @brief L’opérateur [ ] qui prend en paramètre un entier correspondant à l’indice d’une coordonnée
 du vecteur et qui renvoie sa valeur (double)
 */
double InputIntermediaire::operator[](int indice)
{
    if (indice >=0 && indice < this->valeurIntermediaire.size()) {
        return(this->valeurIntermediaire[indice]);
    }
    else {
        return(-1);
    }
}

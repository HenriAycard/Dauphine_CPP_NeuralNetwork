//
//  Iris.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//
#include "Input.hpp"

#ifndef Iris_hpp
#define Iris_hpp

#include <stdio.h>
#include <string>

using namespace std;

// La classe Iris descend de la classe Input
class Iris : public Input
{
    // La classe Iris a pour but de stocker la (courte) description de fleurs sous la forme d’un tableau de 4 réels
    // 3 types de fleurs : Iris setosa (label 0), Iris virginica (label 1) et Iris versicolor (label 2)
private:
    double description[4];
public:
    // Constructeur prenant en parametre un entier correspondant a l indice de la fleur (entier entre 0 et 149)
    Iris(int indiceFleur);

    Iris();

    ~Iris();

    // Prend en parametre un entier correspondant a l indice de la case et qui renvoie le double correspondant
    double operator[](int indice);
};
#endif /* Iris_hpp */

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
#include "FonctionActivation.h"

/**
@brief La classe Perceptron_cachee sert à représenter un perceptron de la couche cachée et descend de la classe Perceptron.
 Il hérite donc des champs correspondant au vecteur de poids et au label de la classe Perceptron. La différence avec un perceptron
 classique se trouve essentiellement au niveau du calcul de 𝛿𝑠 qui dépend des valeurs 𝛿𝑙 des perceptrons de la couche cachée.

*/
class PerceptronCachee :
    public Perceptron
{
private:
    /*
    un perceptron de la couche cachée possède un champ supplémentaire qui est un vecteur de
    pointeurs vers des Perceptrons (chaque pointeur pointe vers un des perceptrons de la couche de
    sortie).
    */
    std::vector<Perceptron> perceptrons;

public:
    PerceptronCachee();
    PerceptronCachee(int input_size, FonctionActivation * fnc_activation, char label, std::vector<Perceptron> & vect);

    ~PerceptronCachee();

    double calcul_delta(Input & input);

    void backprop(Input & input, double mu);
};

#endif /* PerceptronCachee_hpp */

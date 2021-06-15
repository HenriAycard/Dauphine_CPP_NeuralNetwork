//
//  Fonction_Activation.h
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#ifndef FonctionActivation_h
#define FonctionActivation_h

/**
@brief La class Fonction_activation est une classe abstraite dont les classes héritées représenterons les différentes fonctions
d'activation possibles. Cette classe possède les méthodes nécessaires à toute fonction d'activation pour être utilisée par l'algorithme
du perceptron.
*/
class FonctionActivation
{
    public:
        /**
         L'operateur() prend en paramètres une valeur réelle (double) et
         renvoie une valeur réelle (double) correspondant à l'application
         de la fonction d'activation au paramètre
        */
        virtual double operator()(double nombre)=0;
        /**
         prim prend en paramètres une valeur réelle (double) et
         renvoie une valeur réelle (double) correspondant à l'application
         de la dérivée de la fonction d'activation au paramètre
         */
        virtual double prim(double nombre)=0;
};

#endif /* Fonction_Activation_h */

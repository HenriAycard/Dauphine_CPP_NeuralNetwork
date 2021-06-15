//
//  Apprentissage.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#ifndef Apprentissage_hpp
#define Apprentissage_hpp

#include <stdio.h>
#include "Input.hpp"
#include "Iris.hpp"
#include "NN1.hpp"

template <class T, int size, class N>
class Apprentissage
{
private:
    N * neuralNetwork;
    
public:
    Apprentissage();

    Apprentissage(N * neural_Network);
    
    void apprendre_base(int K, double mu);

    int evaluer();
};

template<class T, int size, class N>
Apprentissage<T, size, N>::Apprentissage()
{
}

template<class T, int size, class N>
Apprentissage<T, size, N>::Apprentissage(N * neural_Network)
{
    this->neuralNetwork = neural_Network;
}

template<class T, int size, class N>
void Apprentissage<T, size, N>::apprendre_base(int K, double mu)
{
    if (K >= 1) {
        for (int i = 0; i < K; ++i) {
            int rand_number = rand() % size;
            T input = T(rand_number);
            (this->neuralNetwork)->apprentissage(input, mu);
        }
    }
    else {
        throw "Error: Paramètre K";
    }
}

/**
 @brief La fonction evaluer n'a pas de paramètre et retourne un entier correspondant au nombre d'inputs de
 la base pour lesquels le réseau de neurones a fait une bonne classification (c'est a dire, a retourné le label
 correspondant à l'inpu). Cette fonction devra évaluer le label de chaque input de la base (150 pour les fleurs et
 60 000 pour les images) et comparer ce label avec celui de l'input
 */
template<class T, int size, class N>
int Apprentissage<T, size, N>::evaluer()
{
    int nbrEvaluation = 0;
    for (int index = 0; index < size; ++index) {
        T input = T(index);
        
        char labelFile = input.get_label();
        char labelEvalue = (this->neuralNetwork)->evaluation(input) - 48;
        
        if (labelEvalue == labelFile) {
            nbrEvaluation += 1;
        }
    }
    return nbrEvaluation;
}
#endif /* Apprentissage_hpp */

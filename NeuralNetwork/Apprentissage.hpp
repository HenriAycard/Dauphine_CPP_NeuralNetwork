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

template <class T, int size, class N> class Apprentissage
{
private:
    N * neural_network;
public:
    Apprentissage();

    Apprentissage(N * neural_net);
    
    void apprendre_base(int K, double mu);

    int evaluer();
};

template<class T, int size, class N>
Apprentissage<T, size, N>::Apprentissage()
{
}

template<class T, int size, class N>
Apprentissage<T, size, N>::Apprentissage(N * neural_net)
{
    this->neural_network = neural_net;
}

template<class T, int size, class N>
void Apprentissage<T, size, N>::apprendre_base(int K, double mu)
{
    if (K >= 1) {
        for (int i = 0; i < K; i++) {
            int rand_number = rand() % size;
            T input = T(rand_number);
            (this->neural_network)->apprentissage(input, mu);
        }
    }
    else {
        throw "Paramètre K invalide.";
    }
}

template<class T, int size, class N>
int Apprentissage<T, size, N>::evaluer()
{
    int good_classif = 0;
    for (int i = 0; i < size; i++) {
        T input = T(i);
        char label_file = input.get_label();
        char label_evalue = (this->neural_network)->evaluation(input) - 48;
        if (label_evalue == label_file) {
            good_classif += 1;
        }
    }
    return good_classif;
}
#endif /* Apprentissage_hpp */

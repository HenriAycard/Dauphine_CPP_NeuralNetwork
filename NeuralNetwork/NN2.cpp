//
//  NN2.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 30/05/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//
#include "NN2.hpp"
#include "Input_intermediaire.hpp"
#include <iostream>
#include <string>


NN2::NN2()
{
}

NN2::NN2(int taille_input, int nbr_cat, int nbr_perceptron_c, Fonction_activation * f)
{
    if (taille_input != 4 && taille_input != 784) {
        throw std::string("Erreur dans la sélection de la taille d'input");
    }
    else {
        if (nbr_cat != 10 && nbr_cat != 3) {
            throw std::string("Erreur dans le nombre de catégorie");
        }
        else {
            this->nbr_perceptron = nbr_cat;
            this->nbr_perceptron_cachee = nbr_perceptron_c;
            this->perceptron_list = new Perceptron[nbr_perceptron];
            this->perceptron_cachee_list = new Perceptron_cachee[nbr_perceptron_c];
            for (int i = 0; i < nbr_perceptron; i++) {
                Perceptron p = Perceptron(taille_input, f, i);
                this->perceptron_list[i] = p;
            }
            for (int i = 0; i < nbr_perceptron_c; i++) {
                std::vector<Perceptron> couche_sortie =  std::vector<Perceptron>(); // on met quoi dedans ?
                Perceptron_cachee p = Perceptron_cachee(taille_input, f, i, couche_sortie);
                this->perceptron_cachee_list[i] = p;
            }
        }
    }
}


NN2::~NN2()
{
}

char NN2::evaluation(Input & input)
{
    double max = 0;
    int indice_max = 0;
    Input_intermediaire input_int(input.get_label());

    for (int i = 0; i < this->nbr_perceptron_cachee; i++) {
        double valeur = this->perceptron_cachee_list[i].forward(input);
        input_int.add(valeur);
    }
    for (int i = 0; i < this->nbr_perceptron; i++) {
        double valeur = this->perceptron_list[i].forward(input_int);
        if (valeur > max) {
            max = valeur;
            indice_max = i;
        }
    }
    return(std::to_string(indice_max)[0]);
}

void NN2::apprentissage(Input & input, double mu)
{
    Input_intermediaire input_int(input.get_label());
    for (int i = 0; i < this->nbr_perceptron; i++) {
        this->perceptron_list[i].calcul_delta(input_int);
    }
    for (int i = 0; i < this->nbr_perceptron_cachee; i++) {
        this->perceptron_cachee_list[i].calcul_delta(input);
        this->perceptron_cachee_list[i].backprop(input, mu);
    }
    for (int i = 0; i < this->nbr_perceptron; i++) {
        this->perceptron_list[i].backprop(input_int, mu);
    }
}

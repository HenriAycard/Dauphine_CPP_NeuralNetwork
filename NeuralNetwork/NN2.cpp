//
//  NN2.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 30/05/2021.
//  Copyright © 2021. All rights reserved.
//
#include "NN2.hpp"
#include "InputIntermediaire.hpp"
#include <iostream>
#include <string>
using namespace std;


NN2::NN2()
{
}

NN2::~NN2()
{
}

/**
 @param inputSize : un entier correspondant à la taille des inputs (par exemple 4 pour les fleurs et 784 pour les images)
 @param nbrCategorie : entier correspondant au nombre de catégories (et donc le nombre de perceptrons de la couche de sortie)
 @param nbrPerceptronC : entier correspondant au nombre de perceptrons dans la couche cachée
 */
NN2::NN2(int inputSize, int nbrCategorie, int nbrPerceptronC, FonctionActivation * f)
{
    if (inputSize != 4 && inputSize != 784) {
        throw string("Erreur : Taille de l input incorrect");
    }
    else {
        if (nbrCategorie != 10 && nbrCategorie != 3) {
            throw string("Erreur : Categorie nombre");
        }
        else {
            this->nbrPerceptron = nbrCategorie;
            this->nbrPerceptroncachee = nbrPerceptronC;
            
            this->lstPerceptron = new Perceptron[nbrPerceptron];
            this->lstPerceptronCachee = new PerceptronCachee[nbrPerceptronC];
            
            /* Initalise la liste des Perceptrons */
            for (int indice = 0; indice < nbrPerceptron; indice++) {
                Perceptron p = Perceptron(inputSize, f, indice);
                this->lstPerceptron[indice] = p;
            }
            
            /* Initalise la liste des Perceptrons Cachee
             Pour les perceptrons de la couche cachée, la label (qui n’aura pas vraiment le sens de catégorie)
             correspondra à l’indice du perceptron dans le vecteur.
            */
            for (int indice = 0; indice < nbrPerceptronC; indice++) {
                vector<Perceptron> couche_sortie =  vector<Perceptron>();
                PerceptronCachee p = PerceptronCachee(inputSize, f, indice, couche_sortie);
                this->lstPerceptronCachee[indice] = p;
            }
        }
    }
}

/**
 @param input : indice par référence
 @brief Une fonction evaluation qui prend en paramètre un Input (de préférence une référence), et
 qui renvoie son label (char dont la valeur est comprise entre 0 et 𝑟 − 1) évalué en
 recherchant la plus grande valeur retournée par un des perceptrons de la couche de sortie.
 L’évaluation des perceptrons de la couche cachée sera effectuée en premier, avec comme
 entrée l’input. Par la suite, l’input intermédiaire sera donné en entrée des perceptrons de la couche de sortie, et
 la catégorie retournée sera celle du perceptron de la couche de sortie qui a la plus grande valeur.
 */
char NN2::evaluation(Input & input)
{
    // Un InputIntermédiaire (correspondant à 𝒂(𝟏) = (𝑎1(1), … , 𝑎𝑡(1))) sera créé en
    // ajoutant la valeur de chaque perceptron de la couche cachée à cet input intermédiaire.
    InputIntermediaire inputInter(input.get_label());
    
    // l’input intermédiaire est donné en entrée des perceptrons de la couche de sortie grace a la fonction .forward()
    for (int i = 0; i < this->nbrPerceptroncachee; i++) {
        double valeur = this->lstPerceptronCachee[i].forward(inputInter);
        inputInter.add(valeur);
    }
    // la catégorie retournée est celle du perceptron de la couche de sortie qui a la plus grande valeur.
    double max = 0;
    int maxIndice = 0;
    double valeur = 0;
    for (int i = 0; i < this->nbrPerceptron; i++) {
        valeur = this->lstPerceptron[i].forward(inputInter);
        if (valeur > max) {
            max = valeur;
            maxIndice = i;
        }
    }
    return(to_string(maxIndice)[0]);
}

/**
@brief Une fonction apprentissage qui prend en paramètre un Input (qui correspond à (𝒙𝑗, 𝑦𝑗)) et un double (correspondant au pas de gradient 𝜇) et qui va appliquer l’algorithme d’apprentissage pour cet input. Il suffit d’appliquer l’algorithme d' "evaluation()".
Les valeurs 𝛿𝑙(2) et 𝛿𝑠(1) sont ensuite calculées (dans cet ordre) en faisant appel à la fonction membre calcul_delta des perceptrons de la couche de sortie (avec comme
paramètre l’input intermédiaire correspondant à 𝒂(𝟏) = (𝑎1(1), … , 𝑎𝑡(1))) et la fonction membre calcul_delta des perceptrons de la couche cachée (avec comme paramètre 𝒙𝑗).
Après cette étape, la fonction backprop de chaque perceptron de la couche cachée (avec comme paramètre 𝒙𝑗) et la fonction backprop de chaque perceptron de la couche de sortie (avec comme paramètre l’input intermédiaire correspondant à 𝒂(𝟏) = (𝑎1(1), … , 𝑎𝑡(1))) est appliquée pour mettre à jours les poids
*/
void NN2::apprentissage(Input & input, double mu)
{
    // Initialisation
    // Un input intermédiaire (correspondant à 𝒂(𝟏) = (𝑎1(1), … , 𝑎𝑡(1))) est créé de la même manière que dans la fonction membre evaluation.
    InputIntermediaire inputInter(input.get_label());
    
    
    
    for (int i = 0; i < this->nbrPerceptron; i++) {
        // Les valeurs 𝛿𝑙(2) et 𝛿𝑠(1) sont ensuite calculées en faisant appel à la fonction membre calcul_delta des perceptrons de la couche de sortie avec comme paramètre 𝒙𝑗
        this->lstPerceptron[i].calcul_delta(inputInter);
        // La fonction backprop de chaque perceptron de la couche cachée (avec comme paramètre 𝒙𝑗) et la fonction backprop de chaque perceptron de la couche de sortie (avec comme paramètre l’input intermédiaire correspondant à 𝒂(𝟏) = (𝑎1(1), … , 𝑎𝑡(1))) est appliquée pour mettre à jours les poids
        this->lstPerceptron[i].backprop(inputInter, mu);
    }
    
    for (int i = 0; i < this->nbrPerceptroncachee; i++) {
        this->lstPerceptronCachee[i].calcul_delta(input);
        this->lstPerceptronCachee[i].backprop(input, mu);
    }

}

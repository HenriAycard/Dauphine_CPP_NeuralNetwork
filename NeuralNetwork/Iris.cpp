//
//  Iris.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include "Iris.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <exception>

#define path_file "/Users/henriaycard/Downloads/iris_training/"
using namespace std;

Iris::Iris(int indiceFleur) :Input()
{
    // cout << "Path: " << path_file << " Pour modifier changer la variable path_file du fichier Iris.cpp" << endl;
    if (indiceFleur <= 149 && indiceFleur >= 0) {
        try {
            string pathFile = string(path_file) + "iris" + to_string(indiceFleur);
            ifstream inputFile(pathFile, ifstream::in);
            string descriptionString = "";
            string * desctabchar = new string[5];

            char delimiter = ',';

            if (inputFile) {
                inputFile >> descriptionString;
            }
            
            /*
               Format descriptionString : 5.1,3.5,1.4,0.2,Iris-setosa
               On veut spliter les données en un tableau de string
               Format desctabchar       : [5.9 ; 3 ; 5.1 ; 1.8 ; "Iris-setosa"]
            */
            for (int i = 0;i < 5; ++i) {
                desctabchar[i] = descriptionString.substr(0, descriptionString.find(delimiter));
                // On supprime le resultat trouvé (délimiteur inclus) pour procéder aux extractions suivantes
                descriptionString.erase(0, descriptionString.find(delimiter) + 1);
            }
            
            /*
               La variable desctabchar est composée de 5 valeurs dont la derniere valeur correspond au label de la fleur
               On récupère donc la derniere valeur du tableau
            */
            if (*(desctabchar+4) == "Iris-setosa") {
                this->set_label('0');
            }
            else if (*(desctabchar+4) == "Iris-virginica") {
                this->set_label('1');
            }
            else {
                this->set_label('2');
            }

            for (int i = 0; i < 4; i++) {
                this->description[i] = stod(desctabchar[i]);
            }
        }
        catch(exception& e){
            cout << e.what() << endl;
        }
    }
    else {
        throw "Error : Invalid parameter indiceFleur";
    }
}

Iris::Iris() {
}

Iris::~Iris()
{
}

double Iris::operator[](int indice)
{
    if (indice >= 0 && indice <= 3) {
        return(this->description[indice]);
    }
    else {
        return(-1);
    }
}


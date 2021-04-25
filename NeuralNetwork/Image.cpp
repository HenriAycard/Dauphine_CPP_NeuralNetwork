//
//  Image.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include "Image.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <exception>

#define path_file "/Users/henriaycard/Downloads/MNIST_training/"
using namespace std;


/**
 @brief Constructeur
 @param imageIndice  : un entier correspondant a l indice de l image (entier entre 0 et 59999)
 */
Image::Image(int imageIndice)
{
    if (imageIndice <= 59999 && imageIndice >= 0) {
        this->readLabel(imageIndice);
        this->readPixel(imageIndice);
    } else {
        throw "Invalid parameter : imageIndice";
    }
}

Image::Image() {

}

Image::~Image()
{
}

/**
 @brief Les  images ainsi que les labels, sont contenus dans un fichiers binaires.
 Chaque valeur de ces fichiers est codée sous la forme d'un octet (stockée dans un char).
 Pour les labels, les octets correspondant au tableau de labels se trouvent à partir de l'octet 8 dans
 le fichier de labels (le label de l'image d'indice i se trouve donc a l'octet 8+i).
 @param indice : entier correspondant a l indice de l image (entier entre 0 et 59999)
 */
void Image::readLabel(int indice) {
    char label = '\0';
    typedef char *octets;
    try {
        ifstream inputFile(path_file, ios::in | ios::binary);
        if (inputFile.is_open()) {

            inputFile.seekg((8 + indice) * sizeof(char));
            inputFile.read((char *)&label, sizeof(char));
            inputFile.close();
        }
        else {
            cout << "impossible d'ouvrir le fichier" << endl;
        }

        this->set_label(to_string(static_cast<unsigned>(label))[0]);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

/**
 @brief Les  images ainsi que les labels, sont contenus dans un fichiers binaires.
 Chaque valeur de ces fichiers est codée sous la forme d'un octet (stockée dans un char).
 Pour une images, les octets correspondant aux pixels de l'image se trouvent a partir de l'octet 1078
 du fichier d'extension bmp correspondant.
 @param indice : entier correspondant a l indice de l image (entier entre 0 et 59999)
 */
void Image::readPixel(int indice) {
    unsigned char grey_level;
    try {
        string pathFile = string(path_file) + "training" + to_string(indice);
        ifstream inputFile(pathFile, ios::in | ios::binary);
        int i = 0;
        if (inputFile.is_open()) {
            inputFile.seekg(1078 * sizeof(char));
            for (i = 0; i < 784; i++) {
                inputFile.read((char *)&grey_level, sizeof(unsigned char));
                string value = to_string(grey_level);
                this->pixel[i] = stod(value);
            }
            inputFile.close();
        }
        else {
            cout << "impossible d'ouvrir le fichier" << endl;
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

/**
 @brief operator []
 @param indice : entier correspondant a l indice du pixel
 @return double : renvoie son niveau de gris sous la forme d un double
 */
double Image::operator[](int indice)
{
    if (indice >= 0 && indice <= 784) {
        return(this->pixel[indice]);
    }
    else {
        return(-1);
    }
}

void Image::printPixel()
{
    cout << "Affichage des pixels" << endl;
    for (int i = 0; i < 784; i++) {
        cout << this->pixel[i] <<endl;
    }
}

void Image::setPixelIndice(int ind, double value)
{
    this->pixel[ind] = value;
}

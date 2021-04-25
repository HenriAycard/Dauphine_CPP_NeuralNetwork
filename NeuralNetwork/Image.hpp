//
//  Image.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 Aycard. All rights reserved.
//
#include "Input.hpp"

#ifndef Image_hpp
#define Image_hpp


#include <stdio.h>
//
class Image : public Input
{

    // La Classe Image a pour but de stocker des images en noir et blanc, comprenant 28x28 pixels.
    // Chaque pixel est décrit par son niveau de gris, qui est une valeur entre 0 et 255
private:
    double pixel[784]; // 28 * 28 pixels

public:
    /* Le constructeur charge l'image a partir du fichier bmp correspondant, ainsi que charger
     le label de l'image dans le champ label hérité de la classe Input
    */
    Image(int imageIndice);

    Image();

    ~Image();

    double operator[](int indice);

    void readLabel(int indice);
    
    void readPixel(int indice);

    void printPixel();

    void setPixelIndice(int ind, double value);
};
#endif /* Image_hpp */

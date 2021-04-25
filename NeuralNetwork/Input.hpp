//
//  Input.hpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>

class Input {
private:
    char label;
    
public:
    Input();
    
    ~Input();
    
    void set_label(char lab);
    
    // Fonction qui renvoit un char représentant le label de l'input
    char get_label();
    
    // L operateur [] permet d acceder a une valeur (double) du "tableau" en fonction de son indice (int)
    virtual double operator[](int indice) = 0;
};
#endif /* Input_hpp */

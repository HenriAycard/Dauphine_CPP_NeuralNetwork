//
//  Input.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include "Input.hpp"
using namespace std;

Input::Input()
{
}


Input::~Input()
{
}

char Input::get_label() {
    return(this->label - 48);
}

void Input::set_label(char lab) {
    this->label = lab;
}

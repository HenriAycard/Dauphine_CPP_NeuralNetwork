//
//  main.cpp
//  NeuralNetwork
//
//  Created by Henri Aycard on 05/03/2021.
//  Copyright © 2021 AiEtquart. All rights reserved.
//

#include <iostream>
#include <string>
#include "Image.hpp"
#include "Iris.hpp"
#include "Perceptron.hpp"
#include "Tanh.hpp"
#include "Sigmoide.hpp"
#include "NN1.hpp"
#include "Apprentissage.hpp"
#include "Fonction_Activation.h"
using namespace std;


static void testGetIrisInformations() {
    cout << "IRIS" << endl;
    for (int j = 0; j < 150;j++)
    {
        Iris i = Iris(j);
        cout << "Label name: " << to_string(i.get_label()) << endl;
        cout << "Description : ";
        for (int u = 0; u < 4; u++) {
            cout << i[u] << " | ";
        }
        cout << endl;
        cout << "---------------------------------------" << endl;
    }
}

static void testNeuralNetworkIris() {
    Sigmoide * f = new Sigmoide();
    NN1 * neural_network =  new NN1(4, f, 3);
    Apprentissage<Iris, 150, NN1> app(neural_network);
    int K = 10000;
    double mu = 0.1;
    app.apprendre_base(K, mu);
    int evaluation = app.evaluer();
    cout << "Evaluation : " << evaluation << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    testGetIrisInformations();
    testNeuralNetworkIris();
    return 0;
}

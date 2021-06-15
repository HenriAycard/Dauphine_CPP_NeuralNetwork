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
#include "FonctionActivation.h"
#include "NN2.hpp"

const int sizeIris = 150;
const int sizeImage = 10000;

using namespace std;


static void testIrisGetInformations() {
    cout << "IRIS" << endl;
    for (int j = 0; j < sizeIris;j++)
    {
        Iris i = Iris(j);
        cout << "Label name: " << to_string(i.get_label()) << endl;
        cout << "Description : ";
        for (int u = 0; u < 4; u++) {
            cout << i[u] << " | ";
        }
        cout << endl << "---------------------------------------" << endl;
    }
}

static void testIrisNeuralNetwork(FonctionActivation * fa) {
    NN1 * neural_Network =  new NN1(4, 3, fa);
    Apprentissage<Iris, sizeIris, NN1> app(neural_Network);
    app.apprendre_base(10000, 0.01);
    int evaluation = app.evaluer();
    cout << "Evaluation Iris NN1: " << evaluation << endl;
}

void testIrisNeuralNetwork2(FonctionActivation * fa) {
    NN2 * neural_Network = new NN2(4, 3, 3, fa);
    Apprentissage<Iris, sizeIris, NN2> app(neural_Network);
    app.apprendre_base(10000, 0.01);
    int evaluation = app.evaluer();

    cout << "Evaluation Iris NN2: " << evaluation << endl;
}

static void testImageGetInformations() {
    cout << "IMAGE" << endl;
    for (int j = 0; j < 60000;j++)
    {
        Image i = Image(j);
        //cout << "Label name: " << to_string(i.get_label()) << endl;
    }
    cout << "---------------------------------------" << endl;
}

static void testImageNeuralNetwork(FonctionActivation * fa) {
    NN1 * neural_Network = new NN1(784, 10, fa);
    Apprentissage<Image, sizeImage, NN1> app(neural_Network);
    app.apprendre_base(100000, 0.1);
    int evaluation = app.evaluer();

    cout << "Evaluation Image NN1: " << evaluation << endl;
}

static void testImageNeuralNetwork2(FonctionActivation * fa) {
    NN2 * neural_Network = new NN2(784, 10, 10, fa);
    Apprentissage<Image, sizeImage, NN2> app(neural_Network);
    app.apprendre_base(100000, 0.1);
    int evaluation = app.evaluer();

    cout << "Evaluation Image NN2: " << evaluation << endl;
}


int main(int argc, const char * argv[]) {
    int choix = 0;
    bool isExit = false;
    
    do {
        cout << "1 - Iris display informations" << endl;
        cout << "2 - Iris Neural NetWork NN1 with Sigmoide" << endl;
        cout << "3 - Iris Neural NetWork NN1 with Tanh" << endl;
        cout << "4 - Iris Neural NetWork NN2 with Sigmoide" << endl;
        cout << "5 - Iris Neural NetWork NN2 with Tanh" << endl;
        cout << "-------------------------------------" << endl;
        cout << "6 - Image display informations" << endl;
        cout << "7 - Image Neural NetWork NN1 with Sigmoide" << endl;
        cout << "8 - Image Neural NetWork NN1 with Tanh" << endl;
        cout << "9 - Image Neural NetWork NN2 with Sigmoide" << endl;
        cout << "10 - Image Neural NetWork NN2 with Tanh" << endl;
        cout << "-------------------------------------" << endl;
        cout << "-1 - Exit" << endl;

        cin >> choix;
        
        switch (choix) {
            case 1:
            {
                testIrisGetInformations();
            }
                break;
            case 2:
            {
                testIrisNeuralNetwork(new Sigmoide());
            }
                break;
            case 3:
            {
                testIrisNeuralNetwork(new Tanh());
            }
                break;
            case 4:
            {
                testIrisNeuralNetwork2(new Sigmoide());
            }
                break;
            case 5:
            {
                testIrisNeuralNetwork2(new Tanh());
            }
                break;
            case 6:
            {
                testImageGetInformations();
            }
                break;
            case 7:
            {
                testImageNeuralNetwork(new Sigmoide());
            }
                break;
            case 8:
            {
                testImageNeuralNetwork(new Tanh());
            }
                break;
            case 9:
            {
                testImageNeuralNetwork2(new Sigmoide());
            }
                break;
            case 10:
            {
                testImageNeuralNetwork2(new Tanh());
            }
                break;
            case -1:
            {
                isExit = true;
            }
                break;
            default:
            {
                isExit = true;
            }
                break;
        }
    }while(!isExit);
        
    return 0;
}

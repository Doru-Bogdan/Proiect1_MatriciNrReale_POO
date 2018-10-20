//
//  class_define.cpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//

#include "class_define.hpp"
#include <iostream>

void Matrice::alloc() {
    Matrix = new double * [mRows];
    for (int i = 0; i < mRows; i++) {
        Matrix[i] = new double [mCols];
    }
}

void Matrice::setRowsColws() {
    unsigned int Cols, Rows;
    std::cin >> Rows >> Cols;
    this->mCols = Cols;
    this->mRows = Rows;
}

void Matrice::getRowsColws() {
    std::cout << "Numarul de linii este:"<< mRows << std::endl << "Numarul de linii este:" << mCols;
}


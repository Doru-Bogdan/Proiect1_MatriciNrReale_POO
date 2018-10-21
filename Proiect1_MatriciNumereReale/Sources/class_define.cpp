//
//  class_define.cpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//

#include <iostream>
#include "class_define.hpp"

void Matrice::alloc() {
    Matrix.resize(mRows);
    for (int i = 0; i < mRows; i++)
        Matrix[i].resize(mCols);
}

void Matrice::setRowsColws(unsigned int Rows, unsigned int Cols) {
    mCols = Cols;
    mRows = Rows;
    alloc();
}

void Matrice::getRowsColws() {
    std::cout << "Numarul de linii este:"<< mRows << std::endl << "Numarul de linii este:" << mCols << std::endl;
}

Matrice::Matrice(unsigned int rows, unsigned int cols) {
    mRows = rows;
    mCols = cols;
    alloc();
    for (int i = 0; i < mRows; i++)
        for (int j = 0; j < mCols; j++)
            if (i == j)
                Matrix[i][j] = 1;
}

Matrice::~Matrice() {
   for (int i = 0; i < mRows; i++)
       Matrix[i].clear();
    Matrix.clear();
}

void Matrice::getElement(unsigned int i, unsigned int j) {
    std::cout << Matrix[i][j] << std::endl;
}

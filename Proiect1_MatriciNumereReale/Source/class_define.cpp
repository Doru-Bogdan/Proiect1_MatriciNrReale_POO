//
//  class_define.cpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "class_define.hpp"

void Matrix::alloc() {
    _matrix.resize(_rows);
    for (int i = 0; i < _rows; i++)
        _matrix[i].resize(_cols);
}

unsigned int Matrix::getRows() {
    return _rows;
}

unsigned int Matrix::getCols() {
    return _cols;
}

Matrix::Matrix(unsigned int rows, unsigned int cols) {
    _rows = rows;
    _cols = cols;
    alloc();
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (i == j)
                _matrix[i][j] = 1;
}

Matrix::~Matrix() {
   for (int i = 0; i < _rows; i++)
       _matrix[i].clear();
    _matrix.clear();
}

std::ifstream& operator >> (std::ifstream& f, Matrix &m){
    for (int i = 0; i < m._rows; i++) {
        for (int j = 0; j < m._cols; j++) {
            f >> m._matrix[i][j];
        }
    }
    return f;
}

std::istream& operator >> (std::istream& cin, Matrix &m){
    for (int i = 0; i < m._rows; i++) {
        for (int j = 0; j < m._cols; j++) {
            std::cin >> m._matrix[i][j];
        }
    }
    return cin;
}

std::ofstream& operator << (std::ofstream& f, Matrix &m){
    for (int i = 0; i < m._rows; i++) {
        for (int j = 0; j < m._cols; j++)
            f << m._matrix[i][j] << " ";
        f << "\n";
    }
    return f;
}

std::ostream& operator << (std::ostream& cout, Matrix &m){
    for (int i = 0; i < m._rows; i++) {
        for (int j = 0; j < m._cols; j++)
            std::cout << m._matrix[i][j] << " ";
        std::cout << "\n";
    }
    return cout;
}

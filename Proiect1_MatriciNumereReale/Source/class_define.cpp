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

double Matrix::getElem(unsigned int i, unsigned int j) {
    return _matrix[i][j];
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

Matrix::Matrix(Matrix &m) {
    _rows = m._rows;
    _cols = m._cols;
    alloc();
    _matrix = m._matrix;
}

Matrix::~Matrix() {
   for (int i = 0; i < _rows; i++)
       _matrix[i].clear();
    _matrix.clear();
}

Matrix Matrix::operator += (Matrix m) {
    if (_rows != m._rows || _cols != m._cols) {
        std::cout << "Number of rows or colums from the two matrix are not equal" << "\n";
        return *this;
    }
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] += m._matrix[i][j];
    return *this;
}

Matrix Matrix::operator += (double x) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] += x;
    return *this;
}

Matrix Matrix::operator -= (Matrix m) {
    if (_rows != m._rows || _cols != m._cols) {
        std::cout << "Number of rows or colums from the two matrix are not equal" << "\n";
        return *this;
    }
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] -= m._matrix[i][j];
    return *this;
}

Matrix Matrix::operator -= (double x) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] -= x;
    return *this;
}

Matrix Matrix::operator *= (Matrix m) {
    if (_cols != m._rows) {
        std::cout << "Number of colums from first matrix not equal with the rows from the second matrix" << "\n";
        return *this;
    }
    matrix n;
    n.resize(_rows);
    for (int i = 0; i < _rows; i++)
        n[i].resize(_cols);
    n = _matrix;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < m._cols; j++)
            for (int k = 0; k < _cols; k++)
                _matrix[i][j] = _matrix[i][j] + n[i][k] * m._matrix[k][j] ;
    return *this;
}

Matrix Matrix::operator *= (double x) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] *= x;
    return *this;
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

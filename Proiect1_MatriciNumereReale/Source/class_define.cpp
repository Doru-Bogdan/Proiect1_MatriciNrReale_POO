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

/// Composed overloaded operators

Matrix Matrix::operator += (Matrix& m) {
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

Matrix Matrix::operator -= (Matrix& m) {
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

Matrix Matrix::operator *= (Matrix& m) {
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

/// Unary overloaded operators

Matrix Matrix::operator + () {
    return *this;
}

Matrix Matrix::operator - () {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] *= -1;
    return *this;
}

/// Binary overloaded operators

Matrix operator + (Matrix& m1, Matrix& m2) {
    Matrix m3(m1);
    m3 += m2;
    return m3;
}

Matrix operator + (Matrix& m1, double x) {
    Matrix m2(m1);
    m2 += x;
    return m2;
}

Matrix operator + (double x, Matrix& m1) {
    Matrix m2(m1);
    m2 += x;
    return m2;
}

Matrix operator - (Matrix& m1, Matrix& m2) {
    Matrix m3(m1);
    m3 -= m2;
    return m3;
}

Matrix operator - (Matrix& m1, double x) {
    Matrix m2(m1);
    m2 -= x;
    return m2;
}

Matrix operator - (double x, Matrix& m1) {
    Matrix m2(m1);
    m2 -= x;
    return m2;
}

Matrix operator * (Matrix& m1, Matrix& m2) {
    Matrix m3(m1);
    m3 *= m2;
    return m3;
}

Matrix operator * (Matrix& m1, double x) {
    Matrix m2(m1);
    m2 *= x;
    return m2;
}

Matrix operator * (double x, Matrix& m1) {
    Matrix m2(m1);
    m2 *= x;
    return m2;
}

Matrix operator / (Matrix& m1, double x) {
    if (x == 0) {
        std::cout << "Impossible division" << "\n" ;
        int rows = m1.getRows();
        int cols = m1.getCols();
        Matrix m2(rows,cols);
        return m2;
    }
    Matrix m2(m1);
    for (int i = 0; i < m1._rows; i++)
        for (int j = 0; j < m1._cols; j++)
            m2._matrix[i][j] = m1._matrix[i][j] / x;
    return m2;
}

Matrix operator / (double x, Matrix& m1) {
    if (x == 0) {
        std::cout << "Impossible division" << "\n" ;
        int rows = m1.getRows();
        int cols = m1.getCols();
        Matrix m2(rows,cols);
        return m2;
    }
    Matrix m2(m1);
    for (int i = 0; i < m1._rows; i++)
        for (int j = 0; j < m1._cols; j++)
            m2._matrix[i][j] = m1._matrix[i][j] / x;
    return m2;
}

Matrix operator ^ (Matrix& m1, double x) {
    try {
    if (m1._rows != m1._cols)
        throw "Impossible operation";
    if (x != (unsigned int)x)
        throw "Impossible operation";
    } catch(const char* mes) {
        std::cout << mes << "\n";
        Matrix m2;
        return m2;
    }
    if (x == 0) {
        Matrix m2;
        return m2;
    }
    else if (x == 1)
        return m1;
    else {
        Matrix m2(m1);
        for (int i = 2; i <= x; i++) {
            m2 *= m1;
        }
        return m2;
    }
}

Matrix Matrix::operator[](unsigned int x) {
    try {
        if (x >= _rows || x < 0)
            throw "This row does not exists";
    } catch(const char* mes) {
        std::cout << mes << "\n";
        Matrix m;
        return m;
    }
    if(_rows == 1) {
        Matrix m;
        m._matrix[0][0] = _matrix[1][x];
        return m;
    }
    if(_cols == 1) {
        Matrix m;
        m._matrix[0][0] = _matrix[x][1];
        return m;
    }
    Matrix m(1,_cols);
    for (int j = 0; j < _cols; j++) {
        m._matrix[0][j] = _matrix[x][j];
    }
    return m;
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

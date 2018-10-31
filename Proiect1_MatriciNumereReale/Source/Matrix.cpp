//
//  class_define.cpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Matrix.hpp"

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

double Matrix::getElem(unsigned int rows, unsigned int cols) {
    return _matrix[rows][cols];
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

Matrix::Matrix(Matrix &object) {
    _rows = object._rows;
    _cols = object._cols;
    alloc();
    _matrix = object._matrix;
}

/// Composed overloaded operators

Matrix& Matrix::operator += (Matrix& object) {
    if (_rows != object._rows || _cols != object._cols)
        throw std::runtime_error("Number of rows or colums from the two matrix are not equal");
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] += object._matrix[i][j];
    return *this;
}

Matrix& Matrix::operator += (double number) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] += number;
    return *this;
}

Matrix& Matrix::operator -= (Matrix& object) {
    if (_rows != object._rows || _cols != object._cols)
        throw std::runtime_error("Number of rows or colums from the two matrix are not equal");
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] -= object._matrix[i][j];
    return *this;
}

Matrix& Matrix::operator -= (double number) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] -= number;
    return *this;
}

Matrix& Matrix::operator *= (Matrix& object) {
    if (_cols != object._rows)
        throw std::runtime_error("Number of colums from first matrix not equal with the rows from the second matrix");
    matrix newObject;
    newObject.resize(_rows);
    for (int i = 0; i < _rows; i++)
        newObject[i].resize(_cols);
    newObject = _matrix;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] = 0;
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < object._cols; j++)
            for (int k = 0; k < _cols; k++)
                _matrix[i][j] = _matrix[i][j] + newObject[i][k] * object._matrix[k][j] ;
    return *this;
}

Matrix& Matrix::operator *= (double number) {
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            _matrix[i][j] *= number;
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

Matrix operator + (Matrix& object1, Matrix& object2) {
    Matrix result(object1);
    try {
        result += object2;
    } catch (std::runtime_error) {
        throw std::runtime_error("Number of rows or colums from the two matrix are not equal");
    }
    return result;
}

Matrix operator + (Matrix& object, double number) {
    Matrix result(object);
    result += number;
    return result;
}

Matrix operator + (double number, Matrix& object) {
    Matrix result(object);
    result += number;
    return result;
}

Matrix operator - (Matrix& object1, Matrix& object2) {
    Matrix result(object1);
    try {
        result -= object2;
    } catch (std::runtime_error) {
        throw std::runtime_error("Number of rows or colums from the two matrix are not equal");
    }
    return result;
}

Matrix operator - (Matrix& object, double number) {
    Matrix result(object);
    result -= number;
    return result;
}

Matrix operator - (double number, Matrix& object) {
    Matrix result(object);
    result -= number;
    return result;
}

Matrix operator * (Matrix& object1, Matrix& object2) {
    Matrix result(object1);
    try {
        result *= object2;
    } catch (std::runtime_error) {
        throw std::runtime_error("Number of colums from first matrix not equal with the rows from the second matrix");
    }
    return result;
}

Matrix operator * (Matrix& object, double number) {
    Matrix result(object);
    result *= number;
    return result;
}

Matrix operator * (double number, Matrix& object) {
    Matrix result(object);
    result *= number;
    return result;
}

Matrix operator / (Matrix& object1, double number) {
    if (number == 0)
        throw std::runtime_error("Impossible division");
    Matrix result(object1);
    for (int i = 0; i < object1._rows; i++)
        for (int j = 0; j < object1._cols; j++)
            result._matrix[i][j] = object1._matrix[i][j] / number;
    return result;
}

Matrix operator / (double number, Matrix& object1) {
    if (number == 0)
        throw std::runtime_error("Impossible division");
    Matrix result(object1);
    for (int i = 0; i < object1._rows; i++)
        for (int j = 0; j < object1._cols; j++)
            result._matrix[i][j] = object1._matrix[i][j] / number;
    return result;
}

Matrix operator ^ (Matrix& object, int number) {
    if (object._rows != object._cols)
        throw std::exception();
    if (number < 0)
        throw std::exception();
    if (number == 0) {
        Matrix object2;
        return object2;
    }
    else if (number == 1)
        return object;
    else {
        Matrix result(object);
        for (int i = 2; i <= number; i++) {
            result *= object;
        }
        return result;
    }
}

/// Access overloaded operator

Matrix Matrix::operator[](unsigned int number) {
    if (number >= _rows || number < 0)
        throw std::runtime_error("jafajajsjd");
    if(_rows == 1) {
        Matrix result;
        result._matrix[0][0] = _matrix[0][number];
        return result;
    }
    if(_cols == 1) {
        Matrix result;
        result._matrix[0][0] = _matrix[number][0];
        return result;
    }
    Matrix result(1,_cols);
    for (int j = 0; j < _cols; j++) {
        result._matrix[0][j] = _matrix[number][j];
    }
    return result;
}

/// Relational overloaded operators

bool operator == (Matrix& object1, Matrix& object2) {
    if (object1._rows != object2._rows || object1._cols != object2._cols)
        return false;
    for (int i = 0; i < object1._rows; i++)
        for (int j = 0; j < object1._cols; j++)
            if (object1._matrix[i][j] != object2._matrix[i][j])
                return false;
    return true;
}

bool operator != (Matrix& object1, Matrix& object2) {
    if(object1 == object2)
        return not true;
    return not false;
}

/// Read and write overloaded operators


std::ifstream& operator >> (std::ifstream& stream, Matrix &object){
    for (int i = 0; i < object._rows; i++) {
        for (int j = 0; j < object._cols; j++) {
            stream >> object._matrix[i][j];
        }
    }
    return stream;
}

std::istream& operator >> (std::istream& stream, Matrix &object){
    for (int i = 0; i < object._rows; i++) {
        for (int j = 0; j < object._cols; j++) {
            stream >> object._matrix[i][j];
        }
    }
    return stream;
}

std::ofstream& operator << (std::ofstream& stream, Matrix &object){
    for (int i = 0; i < object._rows; i++) {
        for (int j = 0; j < object._cols; j++)
            stream << object._matrix[i][j] << " ";
        stream << "\n";
    }
    return stream;
}

std::ostream& operator << (std::ostream& stream, Matrix &object){
    for (int i = 0; i < object._rows; i++) {
        for (int j = 0; j < object._cols; j++)
            stream << object._matrix[i][j] << " ";
        stream << "\n";
    }
    return stream;
}

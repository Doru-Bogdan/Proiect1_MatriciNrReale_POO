//
//  class_define.hpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//
#include <vector>

typedef std::vector < std::vector <double> > matrix;

class Matrix {
public:
    Matrix(unsigned int rows = 1, unsigned int cols = 1);
    Matrix(Matrix&);
    ~Matrix();
    unsigned int getRows();
    unsigned int getCols();
    double getElem(unsigned int, unsigned int);
    Matrix operator += (Matrix);
    Matrix operator += (double);
    Matrix operator -= (Matrix);
    Matrix operator -= (double);
    Matrix operator *= (Matrix);
    Matrix operator *= (double);
    friend std::ifstream& operator >> (std::ifstream&, Matrix &);
    friend std::istream& operator >> (std::istream&, Matrix &);
    friend std::ofstream& operator << (std::ofstream& , Matrix &);
    friend std::ostream& operator << (std::ostream& , Matrix &);
private:
    unsigned int _rows;
    unsigned int _cols;
    matrix _matrix;
    void alloc();
};

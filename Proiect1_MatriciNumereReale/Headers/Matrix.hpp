//
//  class_define.hpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//
#include <vector>
class Matrix {
public:
    typedef std::vector < std::vector <double> > matrix;
    Matrix(unsigned int rows = 1, unsigned int cols = 1);
    Matrix(Matrix&);
    unsigned int getRows();
    unsigned int getCols();
    double getElem(unsigned int, unsigned int);
    Matrix& operator += (Matrix&);
    Matrix& operator += (double);
    Matrix& operator -= (Matrix&);
    Matrix& operator -= (double);
    Matrix& operator *= (Matrix&);
    Matrix& operator *= (double);
    Matrix& operator /= (double);
    Matrix operator + ();
    Matrix operator - ();
    Matrix operator [] (unsigned int);
    friend Matrix operator + (Matrix&, Matrix&);
    friend Matrix operator + (Matrix&, double);
    friend Matrix operator + (double, Matrix&);
    friend Matrix operator - (Matrix&, Matrix&);
    friend Matrix operator - (Matrix&, double);
    friend Matrix operator - (double, Matrix&);
    friend Matrix operator * (Matrix&, Matrix&);
    friend Matrix operator * (Matrix&, double);
    friend Matrix operator * (double, Matrix&);
    friend Matrix operator / (Matrix&, double);
    friend Matrix operator / (double, Matrix&);
    friend Matrix operator ^ (Matrix&, int);
    friend bool operator == (Matrix&, Matrix&);
    friend bool operator != (Matrix&, Matrix&);
    friend std::ifstream& operator >> (std::ifstream&, Matrix &);
    friend std::istream& operator >> (std::istream&, Matrix &);
    friend std::ofstream& operator << (std::ofstream& , Matrix &);
    friend std::ostream& operator << (std::ostream& , Matrix &);
    
private:
    void alloc();
    
    unsigned int _rows;
    unsigned int _cols;
    matrix _matrix;
};

//
//  class_define.hpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//
#include <vector>
typedef std::vector < std::vector <double> > matrix;

class Matrice {
public:
    Matrice(unsigned int rows = 1, unsigned int cols = 1);
    ~Matrice();
    void setRowsColws(unsigned int Rows, unsigned int Cols);
    void getRowsColws();
    void getElement(unsigned int i, unsigned int j);
private:
    unsigned int mRows;
    unsigned int mCols;
    matrix Matrix;
    void alloc();
};

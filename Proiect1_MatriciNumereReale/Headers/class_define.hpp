//
//  class_define.hpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//

class Matrice {
public:
    void setRowsColws();
    void getRowsColws();
private:
    unsigned int mRows;
    unsigned int mCols;
    double **Matrix;
    void alloc();
};

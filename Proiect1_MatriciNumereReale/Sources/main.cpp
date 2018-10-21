//
//  main.cpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//

#include <iostream>
#include "class_define.hpp"

int main() {
    Matrice m;
    m.getRowsColws();
    m.setRowsColws(3, 3);
    m.getElement(1,1);
    return 0;
}

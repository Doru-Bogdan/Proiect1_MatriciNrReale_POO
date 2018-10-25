//
//  main.cpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "class_define.hpp"

int main() {
    Matrix m(5,5);
    unsigned int i = m.getRows();
    std::cout << i << "\n";
    //m.afis();
    std::ifstream f("Source/data.in");
    f >> m;
    f.close();
    std::ofstream g("Source/data.out");
    std::cout << m;
    g << m;
    //m.afis();
    return 0;
}

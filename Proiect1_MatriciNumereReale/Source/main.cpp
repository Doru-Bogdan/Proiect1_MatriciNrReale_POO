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
    Matrix n(m);
    m -= n;
    std::cout << m;
    //unsigned int i = m.getRows();
    //std::cout << i << "\n";
    /*std::ifstream f("Source/data.in");
    f >> m;
    f.close();
    //std::ofstream g("Source/data.out");
    std::cout << m << "\n" << n;
    //g << m;*/
    return 0;
}

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
    Matrix a(3,3), b(3,3), c(3,3);
    std::ifstream f("Source/data.in");
    f >> a >> b;
    c = 2 * a;
    std::cout << c << "\n";
    //f.close();
    /*std::ofstream g("Source/data.out");
    g << c;
    g.close();*/
    return 0;
}

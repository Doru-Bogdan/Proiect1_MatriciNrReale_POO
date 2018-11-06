//
//  main.cpp
//  Proiect1_MatriciNumereReale
//
//  Created by Doru Mancila on 20/10/2018.
//  Copyright © 2018 Doru Mancila. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Matrix.hpp"

int main() {
    Matrix a(3,3), b(3,3), c;
    std::ifstream f("Source/data.in");
    std::ofstream g("Source/data.out");
    f >> a >> b;
    int rows = a.getRows();
    int cols = a.getCols();
    f.close();
    //std::cout << b;
    try {
       c = a[0];
    } catch (std::runtime_error const e) {
        std::cout << e.what() << "\n";
    }
    g << c << "\n";
    if (a != b) {
        std::cout << 1 << "\n";
    }
    std::cout << rows << " " << cols << "\n";
    return 0;
}

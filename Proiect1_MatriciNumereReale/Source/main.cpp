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
    Matrix a(1,3), b(3,2), c;
    std::ifstream f("Source/data.in");
    f >> a >> b;
    try {
        c = b * a;
    } catch (std::runtime_error const e) {
        std::cout << e.what() << "\n";
    }
    std::cout << c;
    
    return 0;
}

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
    Matrix a(3,3), b(2,3), c;
    std::ifstream f("Source/data.in");
    f >> a >> b;
    try {
        c = a + b;
    } catch (std::runtime_error const e) {
        std::cout << e.what() << "\n";
    }
    std::cout << c;
    
    return 0;
}

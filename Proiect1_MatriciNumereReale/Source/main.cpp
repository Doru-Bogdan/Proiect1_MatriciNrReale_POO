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

    /*try {
        c = a^2;
    } catch (std::exception) {
        std::cout << "Invalid operation" << "\n";
    }*/
    std::cout << c;
    /*if (a != b)
        std::cout << 1;
    f.close();
    //c = a[3];
    //std::cout << c << "\n";
    //f.close();
    std::ofstream g("Source/data.out");
    g << c;
    g.close();*/
    return 0;
}

//
//  Utils.cpp
//  CodingInverviews
//
//  Created by Suri on 5/23/15.
//  Copyright (c) 2015 Suri. All rights reserved.
//

#include "Utils.h"
#include <math.h>
#include <sstream>
#include <string>


void  Utils::timeFunction(FindTargetFunction func, std::vector<unsigned long> arr, std::unordered_map<unsigned long, unsigned long> map, unsigned long targetNumber, unsigned long numberOfNumbers,  std::string description) {
    
    clock_t t;
    t   = clock();
    std::vector<unsigned long> result = func(&arr, &map, targetNumber, numberOfNumbers);
    t   = clock() - t;
    std::string resultString = ("[");
    for( auto const& r : result) {
        std::string s = std::to_string((int)r);
        resultString.append(" " + s + ",");
    }
    
    resultString.append("]\n");
    description.append(resultString);
    print((float)t, description);
}

void Utils::PrintArrayIntegers(int*& a, int size, std::string description){
    
    std::cout << "\n" << description << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    
}

void Utils::print(float time, std::string description){
    std::cout << "********************************\n";
    std::cout << "*\n";
    std::cout << "* " << description << std::endl;
    std::cout << "* Computation time(s):" << time / CLOCKS_PER_SEC<< "\n";
    std::cout << "********************************\n";
}



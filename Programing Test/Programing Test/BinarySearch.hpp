//
//  BinarySearch.hpp
//  Programing Test
//
//  Created by Suri on 10/14/16.
//  Copyright © 2016 Suri. All rights reserved.
//

#ifndef BinarySearch_hpp
#define BinarySearch_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

typedef unsigned long data_c;

class BinarySearch{
private:
    std::vector<data_c> data_m;
    std::vector<std::vector<data_c>> data_double_m;
    data_c find_value_m;
    data_c length;
    static const data_c NULL_C = NULL;
    
public:
    BinarySearch(std::vector<data_c>, data_c);
    BinarySearch(std::vector<std::vector<data_c>>, data_c);
    bool searchOnDiagonal(int);
    void findIndex(data_c position, data_c startIndex, data_c endIndex);
    static std::vector<data_c>* transForm2Dto1DMatrix(std::vector<std::vector<data_c>>);
    static std::vector<data_c>* transForm2Dto1DMatrix(std::vector<std::vector<data_c>>, data_c, data_c);
    
};
#endif /* BinarySearch_hpp */

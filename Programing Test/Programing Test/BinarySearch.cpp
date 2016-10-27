//
//  BinarySearch.cpp
//  Programing Test
//
//  Created by Suri on 10/14/16.
//  Copyright © 2016 Suri. All rights reserved.
//

#include "BinarySearch.hpp"

BinarySearch::BinarySearch(std::vector<data_c> data, data_c value) {
    data_m = data;
    find_value_m = value;
    length = data_m.size()-1;
    
    BinarySearch::findIndex(NULL, 0, length);
}

BinarySearch::BinarySearch(std::vector<std::vector<data_c>> data, data_c value) {
    value = find_value_m;
    data_double_m = data;
    length = data.size() -1;
}

bool BinarySearch::searchOnDiagonal(int position) {
    
    
    if(data_double_m[position][position] == find_value_m)
        return true;

    if(data_double_m[position+1][position+1] > find_value_m)
        position = position + 1;

    if(data_double_m[position - 1][position - 1] < find_value_m)
        position = position - 1;
    
    BinarySearch::searchOnDiagonal(position);
    
    return false;
}

std::vector<data_c>* BinarySearch::transForm2Dto1DMatrix(std::vector<std::vector<data_c>> a) {
    std::vector<data_c>* newA = new std::vector<data_c>();
    for(int i = 0; i < a.size(); i++) {
        std::vector<data_c> temp = a[i];
        for(int j = 0; j < temp.size(); j++)
            newA->push_back((i*temp.size())+j);
    }
    
    return newA;
}

std::vector<data_c>* BinarySearch::transForm2Dto1DMatrix(std::vector<std::vector<data_c>> a, data_c m, data_c n) {
    std::vector<data_c>* newA = new std::vector<data_c>();
    newA->reserve(m*n);
    for(int i = 0; i < a.size(); i++) {
        std::vector<data_c> temp = a[i];
        for(int j = 0; j < temp.size(); j++)
            newA->push_back((i*temp.size())+j);
    }
    
    return newA;
}


void BinarySearch::findIndex(data_c position, data_c startIndex, data_c endIndex) {    
    
    if(position == NULL_C)
        position = endIndex;
    
    position = startIndex + (endIndex - startIndex)/2;
    
    if(data_m[position] == find_value_m) {
        std::cout << "Found at index:" << position << std::endl;
        return;
    }   
    
    if (position >= endIndex || position <= 0) {
        std::cout << "Value not in this array" << std::endl;
        return;
    }
    
    if((data_m[position-1]) >= find_value_m) {
        position--;
        endIndex = position;
        BinarySearch::findIndex(position, startIndex, endIndex);
    }
    
    if(data_m[(position+1)] <= find_value_m) {
        position++;
        startIndex = position;        
        BinarySearch::findIndex(position, startIndex, endIndex);
    }
}

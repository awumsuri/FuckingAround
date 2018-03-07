//
//  main.cpp
//  Recursive
//
//  Created by Suri on 3/7/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Utils.h"

int MAX = 1000;


void populateMap(std::unordered_map<unsigned long, unsigned long>* map, std::vector<unsigned long>* arr) {
    
    for(unsigned long i = 0; i < arr->size(); i++) {
        
        map->insert({i,i});
        
    }
}

std::vector<unsigned long> findTarget(std::vector<unsigned long>* arr, std::unordered_map<unsigned long, unsigned long>* map, unsigned long targetNumber, unsigned long numberOfNumbers) {
    
    for (int i = 0; i < arr->size(); i++) {
        
        unsigned long testNumber = arr->at(i);
        
        if (testNumber >= targetNumber) {
            return {};
        }
        
        unsigned long newTargetNumber = targetNumber  - testNumber;
        
        if (numberOfNumbers == 2) {
            
            if (map->find(newTargetNumber) != map->end() && newTargetNumber != testNumber) {
                
                return std::vector<unsigned long>{testNumber,  newTargetNumber};
                
            }
            continue;
            
        }
        
        std::vector<unsigned long> newResult =  findTarget(arr, map, newTargetNumber, (numberOfNumbers - 1));
        if (!newResult.empty() && !(std::find(newResult.begin(), newResult.end(), testNumber) != newResult.end())) {
            
            newResult.push_back(testNumber);
            return newResult;
            
        }
        
    }
    
    return {};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<unsigned long> arr;
    std::unordered_map<unsigned long, unsigned long> map = {};
    
    for( unsigned long i = 1; i <= MAX; i++) {
        arr.push_back(i);
    }
    
    populateMap(&map, &arr);
    FindTargetFunction target = findTarget;
    Utils::timeFunction(target, arr, map, 320, 10, "Find Target Number by Summing");
    
    return 0;
}

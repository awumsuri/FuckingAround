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

int MAX = 150;
unsigned long count = 0;

void populateMap(std::unordered_map<unsigned long, unsigned long>* map, std::vector<unsigned long>* arr) {
    
    for(unsigned long i = 0; i < arr->size(); i++) {
        
        map->insert({i,i});
        
    }
}

std::vector<unsigned long> findTarget(std::vector<unsigned long>* arr, std::unordered_map<unsigned long, unsigned long>* map, unsigned long targetNumber, unsigned long numberOfNumbers) {
    
    for (int i = 0; i < arr->size(); i++) {
        
        count++;
       
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

void printResult(std::vector<unsigned long> result) {
    std::string resultString = ("[");
    for( auto const& r : result) {
        std::string s = std::to_string((int)r);
        resultString.append(" " + s + ",");
    }
    
    resultString.append("]\n");
    std::cout << "result: " << resultString << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned long targetNumber = atol(argv[1]);
    unsigned long kNumber = atol(argv[2]);
    std::vector<unsigned long> arr;
    std::unordered_map<unsigned long, unsigned long> map = {};
    
    for( unsigned long i = 1; i <= MAX; i++) {
        arr.push_back(i);
    }
    
    populateMap(&map, &arr);
    
    clock_t t;
    t   = clock();
    std::vector<unsigned long> result = findTarget(&arr, &map, 100, 12);
    t   = clock() - t;
    //FindTargetFunction target = findTarget;
    //Utils::timeFunction(target, arr, map, 100, 11, "Find Target Number by Summing");
    std::cout << "count:" << count << "\nComputation time(s) "<< (float)t / CLOCKS_PER_SEC << std::endl;
    printResult(result);
    
    return 0;
}

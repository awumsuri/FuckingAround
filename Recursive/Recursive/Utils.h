//
//  Utils.h
//  CodingInverviews
//
//  Created by Suri on 5/23/15.
//  Copyright (c) 2015 Suri. All rights reserved.
//

#ifndef __CodingInverviews__Utils__
#define __CodingInverviews__Utils__

#include <stdio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

typedef std::vector<unsigned long> (*FindTargetFunction)(std::vector<unsigned long>*& arr, std::unordered_map<unsigned long, unsigned long>* map, unsigned long targetNumber, unsigned long numberOfNumbers);

class Utils{
public:

    static void timeFunction(FindTargetFunction, std::vector<unsigned long>* arr, std::unordered_map<unsigned long, unsigned long> map, unsigned long targetNumber, unsigned long numberOfNumbers, std::string description);
    
    static void PrintArrayIntegers(int*&, int, std::string);
    
private:
    static void print(float, std::string);
};

#endif /* defined(__CodingInverviews__Utils__) */

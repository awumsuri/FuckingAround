//
//  Fib.cpp
//  Test
//
//  Created by amtui on 6/7/16.
//  Copyright © 2016 amtui. All rights reserved.
//

#include "Fib.hpp"

int Fibonacci::dertimineFib(int n){
    
    int h = 1;
    int p = 0;
        
    for(int i = 0; i < n ; i ++){
        int temp = p + h;
        h = p;
        p = temp;
        sum += (h+p);
    }
    
    return (p + h);
}

int Fibonacci::getSum(){
    return sum;
}
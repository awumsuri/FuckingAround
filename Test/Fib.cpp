//
//  Fib.cpp
//  Test
//
//  Created by amtui on 6/7/16.
//  Copyright © 2016 amtui. All rights reserved.
//

#include "Fib.hpp"

long Fibonacci::dertimineFib(int n){
    
    long h = 1;
    long p = 0;
        
    for(int i = 0; i < n ; i ++){
        long temp = p + h;
        h = p;
        p = temp;
        sum += (h+p);
    }
    
    return (p + h);
}

long Fibonacci::getSum(){
    return sum;
}
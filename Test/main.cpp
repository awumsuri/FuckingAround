//
//  main.cpp
//  Test
//
//  Created by amtui on 6/7/16.
//  Copyright © 2016 amtui. All rights reserved.
//

#include <iostream>
#include "Fib.hpp"

int main(int argc, const char * argv[]) {
    Fibonacci fib;
    std::cout << "get fib number:" << fib.dertimineFib(100) << " get sum:" << fib.getSum() << std::endl;
    return 0;
}

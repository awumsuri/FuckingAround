//
//  StringReplace.hpp
//  Programing Test
//
//  Created by Suri on 10/20/16.
//  Copyright © 2016 Suri. All rights reserved.
//

#ifndef StringReplace_hpp
#define StringReplace_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class StringReplace {
private:
    std::string str_m;
public:
    StringReplace(std::string &str, std::string replace_str);
    void replaceString(std::string &str, std::string replace_str);
};

#endif /* StringReplace_hpp */

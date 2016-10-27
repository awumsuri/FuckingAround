//
//  AssignmentOperator.cpp
//  Test
//
//  Created by Suri on 7/12/16.
//  Copyright © 2016 amtui. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "AssignmentOperator.h"

CMYString& CMYString::operator =(const CMYString &str) {
    if(this == &str)
        return *this;
    delete []m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData, str.m_pData);
    
    return *this;
}

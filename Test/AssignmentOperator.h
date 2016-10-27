//
//  AssignmentOperator.h
//  Test
//
//  Created by Suri on 7/12/16.
//  Copyright © 2016 amtui. All rights reserved.
//

#ifndef AssignmentOperator_h
#define AssignmentOperator_h

class CMYString{
public:
    CMYString(char* pData = NULL);
    CMYString(const CMYString& str);
    CMYString& operator = (const CMYString &);
    ~CMYString(void);
private:
    char* m_pData;
};


#endif /* AssignmentOperator_h */

//
//  main.cpp
//  Programing Test
//
//  Created by Suri on 6/5/16.
//  Copyright © 2016 Suri. All rights reserved.
//

#include <iostream>
#include "LinkList.h"
#include "BinarySearch.hpp"
#include "StringReplace.hpp"
#define MAX 100

void Test2DSearchDiagonal() {
    //BinarySearch::BinarySearch(d1, 7);
}

void TestReplace() {
    std::string s("Suri is the greatest");
    
    StringReplace sl(s, "%20");    
}

void TestBinarySearch2Dto1DMatri() {
    
    data_c Max = 1000;
    
    std::vector<std::vector<data_c>> a;    
    
    for(int i = 0; i < Max; i++){
        std::vector<data_c>* temp = new std::vector<data_c>()   ;
        for(int j = 0; j < Max; j++){
            temp->push_back(i*Max + j);
        }
        a.push_back(*temp);
    }
    
    std::vector<data_c>* b = BinarySearch::transForm2Dto1DMatrix(a, Max, Max);
    
    BinarySearch c(*b, 89);
}

void TestBinarySearch() {
    std::vector<data_c> a;
    
    for(int i = 0; i < 1000000; i++){
        a.push_back(i);
    }
    
    BinarySearch c(a, 134);
}

void TestPrintReverse() {
    LinkList l;
    
    for(int i = 0; i < MAX; i++) {
        Node* n = new Node();
        n->data = i;
        l.insert(n);
    }
}

void TestLinkedList() {
    LinkList l;
    
    int i = 0;
    for(i = 0; i <= MAX; i++){
        Node* n = new Node();
        n->data = i;
        l.insert(n);
    }
    
    l.printNode();
    
    std::cout << "kth:" << l.FindKthNode(8)->data << std::endl;
}



int main(int argc, const char * argv[]) {
    TestBinarySearch();
    TestBinarySearch2Dto1DMatri();
    TestLinkedList();
    return 0;
}





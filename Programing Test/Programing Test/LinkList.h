//
//  LinkList.h
//  Programing Test
//
//  Created by Suri on 6/5/16.
//  Copyright © 2016 Suri. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

struct Node{
    int data;
    Node* next = nullptr;
    Node* previous;
};

class LinkList{
private:
    Node* root = nullptr;
public:
    LinkList(){}
    void insert(Node*&);
    void deleteNode(Node*&);
    void printNode();
    Node* FindKthNode(unsigned k);
    void PrintListReverse(Node*&);
    void preOrderTraverse(Node*&);
};


#endif /* LinkList_h */

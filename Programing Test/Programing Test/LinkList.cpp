//
//  LinkList.cpp
//  Programing Test
//
//  Created by Suri on 6/5/16.
//  Copyright © 2016 Suri. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "LinkList.h"

void LinkList::insert(Node*& n) {
    Node* temp;
    if(root == nullptr){
        root = new Node();
        root->data = n->data;
        root->next = nullptr;
        return;
    }
    temp = root;
    while(temp->next != nullptr){
        temp = temp->next;
    }
   // std::cout  << "insert-n" << &n << std::endl;
    temp->next = n;
}

void LinkList::printNode(){
    Node* temp = root;
    if(root == nullptr){
        std::cout << "Empty List" << std::endl;
        return;
    }
    while(temp->next != nullptr){
        std::cout << "data:" << temp->data << std::endl;
        temp = temp->next;
    }
}

void LinkList::PrintListReverse(Node *& root) {
    
}

void LinkList::preOrderTraverse(Node*& node) {
    if(node->next == NULL)
        return;
    
}

//Kth Node from End
Node* LinkList::FindKthNode(unsigned k){
    Node* kth = root;
    Node* head = root;
    int position = 0;
    
    while(head->next != nullptr){
        if(position > k){
            kth = kth->next;
        }
        position++;
        head = head->next;
    }
    
    return kth;    
}

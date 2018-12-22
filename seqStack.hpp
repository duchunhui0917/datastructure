//
//  seqStack.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/18.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef seqStack_hpp
#define seqStack_hpp

#include <stdio.h>
#include "stack.hpp"
template <class elemType>
class seqStack:public stack<elemType>
{
private:
    elemType* elem;
    int maxSize;
    int top_p;
    void doubleSpace();
public:
    seqStack(int initSize=10);
    ~seqStack();
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
    bool isEmpty() const;
};
template <class elemType>
seqStack<elemType>::seqStack(int initSize) {
    elem = new elemType[initSize];
    maxSize = initSize;
    top_p = -1;
    
}
template <class elemType>
seqStack<elemType>::~seqStack() {
    delete [] elem;
}

template <class elemType>
void seqStack<elemType>::doubleSpace() {
    elemType* tmp = elem;
    elem = new elemType[maxSize];
    for (int i=0; i<=maxSize; i++) {
        elem[i] = tmp[i];
    }
    maxSize *= 2;
    delete []tmp;
}

template <class elemType>
void seqStack<elemType>::push(const elemType &x) {
    if (top_p == maxSize-1) {
        doubleSpace();
    }
    elem[++top_p] = x;
}

template <class elemType>
elemType seqStack<elemType>::pop() {
    return elem[top_p--];
}

template <class elemType>
elemType seqStack<elemType>::top() const{
    return elem[top_p];
}

template <class elemType>
bool seqStack<elemType>::isEmpty() const{
    return top_p == -1;
}
#endif /* seqStack_hpp */

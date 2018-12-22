//
//  linkStack.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/18.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef linkStack_hpp
#define linkStack_hpp

#include <stdio.h>
#include "stack.hpp"
template <class elemType>
class linkStack:public stack<elemType>{
private:
    struct node{
        elemType data;
        node* next;
        node(const elemType &x,node* n=NULL):data(x),next(n){}
        node(node* n=NULL):next(n){}
        ~node(){}
    };
    node *top_p;
public:
    linkStack();
    ~linkStack();
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
    bool isEmpty() const;
};
template <class elemType>
linkStack<elemType>::linkStack(){
    top_p = NULL;
}

template <class elemType>
linkStack<elemType>::~linkStack(){
    node* tmp;
    while (top_p!=NULL) {
         tmp = top_p;
        top_p = top_p->next;
        delete tmp;
    }
}

template <class elemType>
void linkStack<elemType>::push(const elemType &x){
    top_p = new node(x,top_p);
}

template <class elemType>
elemType linkStack<elemType>::pop(){
    node* p = top_p;
    elemType x = p->data;
    delete p;
    top_p = top_p->next;
    return x;
}

template <class elemType>
elemType linkStack<elemType>::top() const{
    return top_p->data;
}

template <class elemType>
bool linkStack<elemType>::isEmpty() const{
    return top_p == NULL;
}
#endif /* linkStack_hpp */

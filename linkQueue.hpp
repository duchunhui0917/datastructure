//
//  linkQueue.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/19.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef linkQueue_hpp
#define linkQueue_hpp

#include <stdio.h>
#include "queue.hpp"
template <class elemType>
class linkQueue:public queue<elemType>{
private:
    struct node{
        elemType data;
        node* next;
        node(const elemType &x, node* n=NULL):data(x),next(n){}
        node(node* n=NULL){}
        ~node(){}
    };
    node* front;
    node* rear;
public:
    linkQueue();
    ~linkQueue();
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
    bool isEmpty() const;
};
template <class elemType>
linkQueue<elemType>::linkQueue(){
    front = rear = NULL;
}
template <class elemType>
linkQueue<elemType>::~linkQueue(){
    node* p;
    while (front != NULL) {
        p = front;
        front = front->next;
        delete p;
    }
}
template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x){
    if (rear == NULL) {
        front = rear = new node(x);
    }
    else
        rear = rear->next = new node(x);
}
template <class elemType>
elemType linkQueue<elemType>::deQueue(){
    node* p = front;
    elemType x = p->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete p;
    return x;
}
template <class elemType>
elemType linkQueue<elemType>::getHead() const{
    return front->data;
}
template <class elemType>
bool linkQueue<elemType>::isEmpty() const{
    return front == NULL;
}

#endif /* linkQueue_hpp */

//
//  seqQueue.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/19.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef seqQueue_hpp
#define seqQueue_hpp

#include <stdio.h>
#include "queue.hpp"
template <class elemType>
class seqQueue:public queue<elemType>{
private:
    elemType *elem;
    int maxSize;
    int front,rear;
    void doubleSpace();
public:
    seqQueue(int initSize=10);
    ~seqQueue();
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
    bool isEmpty() const;
};
template <class elemType>
seqQueue<elemType>::seqQueue(int initSize){
    elem = new elemType[initSize];
    maxSize = initSize;
    front = rear = 0;
}
template <class elemType>
seqQueue<elemType>::~seqQueue(){
    delete [] elem;
}
template <class elemType>
void seqQueue<elemType>::doubleSpace(){
    elemType* tmp = elem;
    elem = new elemType[2*maxSize];
    for (int i=1; i<maxSize; i++) {
        elem[i] = tmp[(front + i) % maxSize];
    }
    front = 0;
    rear = maxSize - 1;
    maxSize *= 2;
    delete tmp;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x){
    rear = (rear + 1) % maxSize;
    if (rear == front) {
        doubleSpace();
    }
    elem[rear] = x;
}
template <class elemType>
elemType seqQueue<elemType>::deQueue(){
    front = (front + 1) % maxSize;
    return elem[front];
}
template <class elemType>
elemType seqQueue<elemType>::getHead() const{
    return elem[(front + 1) % maxSize];
}
template <class elemType>
bool seqQueue<elemType>::isEmpty() const{
    return front == rear;
}
#endif /* seqQueue_hpp */

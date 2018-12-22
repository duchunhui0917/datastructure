//
//  priorityQueue.hpp
//  datastructure
//
//  Created by duchunhui on 2018/11/17.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef priorityQueue_hpp
#define priorityQueue_hpp

#include <stdio.h>
#include "queue.hpp"

template<class Type>
class priorityQueue:public queue<Type>{//min
public:
    priorityQueue(int capacity=100);
    priorityQueue(const Type data[], int size);
    ~priorityQueue();
    bool isEmpty() const;
    void enQueue(const Type &x);
    Type deQueue();
    Type getHead() const;
private:
    int currentSize;//length of queue
    Type *array;
    int maxSize;//capacity
    
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
};
template<class Type>
priorityQueue<Type>::priorityQueue(int capacity){
    array = new Type[capacity];
    currentSize = 0;
    maxSize = capacity;
}
template<class Type>
priorityQueue<Type>::~priorityQueue(){
    delete []array;
}
template<class Type>
bool priorityQueue<Type>::isEmpty() const{
    return currentSize==0;
}
template<class Type>
Type priorityQueue<Type>::getHead() const{
    return array[1];
}
template<class Type>
void priorityQueue<Type>::enQueue(const Type &x){
    if (currentSize==maxSize-1)
        doubleSpace();
    int hole;

    for (hole=++currentSize; hole>1&&array[hole]<array[hole/2]; hole /= 2)
        array[hole] = array[hole/2];
    array[hole] = x;
}

template<class Type>
void priorityQueue<Type>::percolateDown(int hole){//percolate down to maintain tree's order
    int child;
    Type tmp = array[hole];
    
    for (; 2*hole<=currentSize; hole=child) {
        child = 2 * hole;
        if (child!=currentSize&&array[child+1]<array[child])
            child++;
        if (array[child]<tmp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = tmp;
}

template<class Type>
Type priorityQueue<Type>::deQueue(){
    Type minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return minItem;
}

template<class Type>
void priorityQueue<Type>::buildHeap(){
    for (int i=currentSize/2; i>0; i--)
        percolateDown(i);
}

template<class Type>
priorityQueue<Type>::priorityQueue(const Type *items, int size):maxSize(size+10),currentSize(size){
    array = new Type[maxSize];
    for (int i=0; i<size; i++)
        array[i + 1] = items[i];
    buildHeap();
}
template<class Type>
void priorityQueue<Type>::doubleSpace(){
    Type *tmp = array;
    maxSize *= 2;
    array = new Type[maxSize];
    for (int i=0; i<=currentSize; ++i)
        array[i] = tmp[i];
    delete []tmp;
}


#endif /* priorityQueue_hpp */

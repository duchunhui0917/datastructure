//
//  seqList.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/10.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef seqList_hpp
#define seqList_hpp

#include "list.hpp"
#include "iostream"

template <class elemType>
class seqList:public list<elemType>
{
private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();
public:
    seqList(int initSize=10);
    ~seqList();
    void clear();
    int length() const;/*const represents function don't change members*/
    void insert(int i,const elemType &x);
    void remove(int i);
    int search(const elemType &x)const;
    elemType visit(int i)const;
    void traverse()const;
    void erase(int i);
    
    seqList<elemType>(const seqList<elemType> &other);
    seqList<elemType> &operator=(const seqList<elemType> &other);
    friend seqList<elemType> operator+(const seqList<elemType> &A, const seqList<elemType> &B);
    
};

template <class elemType>
seqList<elemType>::seqList(int initSize)
{
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}

template <class elemType>
seqList<elemType>::~seqList()
{
    delete [] data;
}

template <class elemType>
void seqList<elemType>::clear()
{
    currentLength = 0;
}

template <class elemType>
int seqList<elemType>::length() const
{
    return currentLength;
}

template <class elemType>
elemType seqList<elemType>::visit(int i) const
{
    return data[i];
}

template <class elemType>
void seqList<elemType>::traverse() const
{
    std::cout<<std::endl;
    for (int i=0; i<currentLength; ++i) {
        std::cout<<data[i]<<"";
    }
}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const
{
    int i;
    for (i=0; i<currentLength && data[i]!=x; ++i);
    if (i==currentLength) return -1;
    else return i;
}

template <class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType *tmp = data;
    
    maxSize *=2;
    data = new elemType[maxSize];
    for (int i=0; i<currentLength; ++i) {
        data[i] = tmp[i];
    }
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
    if (currentLength==maxSize) {
        doubleSpace();
    }
    for (int j=currentLength; j>i; j--) {
        data[j] = data[j-1];
    }
    data[i] = x;
    ++currentLength;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
    for (int j=i+1; i<currentLength; ++j) {
        data[j-1] = data[j];
    }
    currentLength--;
}

template <class elemType>
void seqList<elemType>::erase(int i)
{
    elemType x = data[i];
    int cnt=0;
    for (int j=0; j<currentLength; ++j) {
        if (data[j]==x) {
            ++cnt;
        }
        else {
            data[j-cnt] = data[j];
        }
    }
}
#endif /* seqList_hpp */


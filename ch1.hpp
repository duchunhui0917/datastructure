//
//  ch1.hpp
//  datastructure
//
//  Created by duchunhui on 2018/12/19.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef ch1_hpp
#define ch1_hpp

#include <stdio.h>
#include "seqList.hpp"
#include "sLinkList.hpp"
#include "dLinkList.hpp"

template<class elemType>
void sLinkList<elemType>::erase(const elemType &x, const elemType &y){
    node *p = head, *q;
    while (p->next!=NULL) {
        q = p->next;
        if (q->data>x && q->data<y) {
            p->next = q->next;
            delete q;
            currentlength--;
        }
        p = p->next;
    }
}

template<class elemType>
void dLinkList<elemType>::josephus(){
    
}
template<class elemType>
void sLinkList<elemType>::inverse(){//insert current to head->next
    node *cur, *cur_next;
    cur = head->next->next;
    
    while (cur!=NULL) {
        cur_next = cur->next;
        cur->next = head->next;
        head->next = cur;
        cur = cur_next;
    }
}
template<class elemType>
seqList<elemType>::seqList(const seqList<elemType> &other){
    currentLength = other.currentLength;
    maxSize = other.maxSize;
    data = new elemType[maxSize];
    for (int i=0; i<currentLength; ++i) {
        data[i] = other.data[i];
    }
}
template<class elemType>
seqList<elemType> &seqList<elemType>::operator=(const seqList<elemType> &other){
    if (this==&this)
        return * this;
    delete []
    
    currentLength = other.currentLength;
    maxSize = other.maxSize;
    data = new elemType[maxSize];
    for (int i=0; i<currentLength; ++i)
        data[i] = other.data[i];
    
    return *this;
}
template<class elemType>
seqList<elemType> operator+(const seqList<elemType> &A, const seqList<elemType> &B){
    seqList<elemType> C;
    int i,j;
    for (i=0; i<A.length(); ++i)
        C.insert(i, A.visit(i));
    for (j=0; j<B.length() ; ++j)
        C.insert(i, B.visit(j));
    return C;
}


template<class elemType>
int sLinkList<elemType>::findBack(int k){
    int len = 0;
    int i = 0;
    node *p = head;
    while (p->next!=NULL) {
        ++len;
        p = p->next;
    }
    if (len-k<0)
        return 0;
    p = head;
    while (i<len-k+1) {
        p = p->next;
        ++i;
    }
    return p->data;
}


#endif /* ch1_hpp */

//
//  dLinkList.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/12.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef dLinkList_hpp
#define dLinkList_hpp

#include <stdio.h>
#include "list.hpp"
#include "iostream"

template <class elemType>
class dLinkList:public list<elemType> {
private:
    struct node{
        elemType data;
        node *prev;
        node *next;
        node (const elemType &x,node *p=NULL,node *n=NULL):data(x),prev(p),next(n){}
        node():next(NULL),prev(NULL){}
        ~node(){};
    };
    node *head,*tail;
    int currentlength;
    node *move(int i)const;
    
    
public:
    dLinkList();
    ~dLinkList();
    void clear();
    int length() const;
    void insert(int i,const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
    void reverse();
    
    void josephus();
};
template <class elemType>
typename dLinkList<elemType>::node *dLinkList<elemType>::move(int i) const
{
    node *p = head;
    while (i-- >= 0)
        p = p->next;
    return p;
}

template <class elemType>
dLinkList<elemType>::dLinkList() {
    head = new node;
    tail = new node;
    head->next = tail;
    tail->prev = head;
    currentlength = 0;
}

template <class elemType>
dLinkList<elemType>::~dLinkList(){
    clear();
    delete head;
    delete tail;
}

template <class elemType>
void dLinkList<elemType>::clear() {
    node *p = head->next;
    head->next = tail;
    node *q;
    
    while (p != tail) {
        q = p->next;
        delete p;
        p = q;
    }
    currentlength = 0;
}

template <class elemType>
int dLinkList<elemType>::length() const{
    return currentlength;
}

template <class elemType>
void dLinkList<elemType>::insert(int i, const elemType &x) {
    node *pos = move(i);
    node *newNode = new node(x, pos->prev, pos);//set new node's prev is pos->prev and  next is pos
    pos->prev = newNode;
    pos->prev->next = newNode;
    ++currentlength;
}

template <class elemType>
void dLinkList<elemType>::remove(int i) {
    node *delp = move(i);
    delp->prev->next = delp->next;
    delp->next->prev = delp->prev;
    delete delp;
    currentlength--;
}

template <class elemType>
int dLinkList<elemType>::search(const elemType &x) const{
    node *p = head->next;
    int i=0;
    while (p !=tail && p->data != x){
        p = p->next;
        ++i;
    }
    if (p == tail)
        return -1;
    else
        return i;
}

template <class elemType>
elemType dLinkList<elemType>::visit(int i) const{
    node *p = move(i);
    return p->data;
}

template <class elemType>
void dLinkList<elemType>::traverse() const{
    node *p = head->next;
    while (p!=tail) {
        std::cout<< p->data << std::endl;
        p = p->next;
    }
}

template <class elemType>
void dLinkList<elemType>::reverse() {
    node* p;
    for (p = tail->prev; p!=head; p= p->prev) {
        std::cout<< p->data << std::endl;
    }
}
#endif /* dLinkList_hpp */

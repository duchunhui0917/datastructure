//
//  sLinkList.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/12.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef sLinkList_hpp
#define sLinkList_hpp

#include "list.hpp"
#include "iostream"

template <class elemType>
class sLinkList:public list<elemType> {
private:
    struct node {
        elemType data;
        node *next;
        node(const elemType &x,node *n=NULL)
        {
            data = x;
            next = n;
        }
        node():next(NULL){}
        ~node(){}
    };
    node *head;//dont store any data
    int currentlength;
    node *move(int i) const;//return ith node*
public:
    sLinkList();
    ~sLinkList();
    void clear();
    int length() const;
    void insert(int i,const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
    
    void erase(const elemType &x, const elemType &y);
    void inverse();
    int findBack(int k);
};

template <class elemType>
typename sLinkList<elemType>::node *sLinkList<elemType>::move(int i) const
{
    node *p = head;
    while (i-- >= 0)
        p = p->next;
    return p;
}

template <class elemType>
sLinkList<elemType>::sLinkList() {
    head = new node;
    currentlength = 0;
}

template <class elemType>
sLinkList<elemType>::~sLinkList(){
    clear();
    delete head;
}

template <class elemType>
void sLinkList<elemType>::clear() {
    node *p = head->next;
    node *q;
    head->next = NULL;
    
    while (p != NULL) {
        q = p->next;
        delete p;
        p = q;
    }
    currentlength = 0;
}

template <class elemType>
int sLinkList<elemType>::length() const{
    return currentlength;
}

template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x) {
    node *p = move(i-1);
    p->next = new node(x, p->next);
    ++currentlength;
}

template <class elemType>
void sLinkList<elemType>::remove(int i) {
    node *p = move(i-1);
    node *q;
    q = p->next;
    p->next = q->next;
    delete q;
    currentlength--;
}

template <class elemType>
int sLinkList<elemType>::search(const elemType &x) const{
    node *p = head;
    int i=0;
    while (p !=NULL && p->data != x){
        p = p->next;
        ++i;
    }
    if (p == NULL)
        return -1;
    else
        return i;
}

template <class elemType>
elemType sLinkList<elemType>::visit(int i) const{
    node *p = move(i);
    return p->data;
}

template <class elemType>
void sLinkList<elemType>::traverse() const{
    node *p = head->next;
    while (p!=NULL) {
        std::cout<< p->data << std::endl;
        p = p->next;
    }
}

#endif /* sLinkList_hpp */

//
//  list.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/8.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include <stdio.h>
template <class elemType>
class list //class with pure virtual function can't be initialization and only can be inhert
{
public:
    virtual void clear() = 0; //pure virtual function
    virtual int length() const = 0;
    virtual void insert(int i,const elemType &x) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const elemType &x) const = 0;
    virtual elemType visit(int i) const = 0;
    virtual void traverse() const = 0;
    virtual ~list(){};
};
#endif /* list_hpp */

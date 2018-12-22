//
//  stack.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/18.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
template <class elemType>
class stack{
public:
    virtual void push(const elemType &x) = 0;
    virtual elemType pop() = 0;
    virtual elemType top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~stack() {}
};
#endif /* stack_hpp */

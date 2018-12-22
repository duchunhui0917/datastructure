//
//  queue.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/19.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
template <class elemType>
class queue{
public:
    virtual bool isEmpty() const = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual elemType getHead() const = 0;
    virtual ~queue(){}
};
#endif /* queue_hpp */

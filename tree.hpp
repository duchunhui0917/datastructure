//
//  tree.hpp
//  datastructure
//
//  Created by duchunhui on 2018/11/6.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
template<class T>
class tree{
public:
    virtual void clear() =0;
    virtual bool isEmpty() const =0;
    virtual T Root(T flag) const =0;
    virtual T parent(T x, T flag) const =0;
    virtual T child(T x, int i, T flag) const =0;
    virtual void remove(T x, int i) =0;
    virtual void traverse() const =0;
};
#endif /* tree_hpp */

//
//  graph.hpp
//  datastructure
//
//  Created by duchunhui on 2018/12/16.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
template<class TypeOfVer, class TypeOfEdge>
class graph{
public:
    virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) = 0;
    virtual void remove(TypeOfVer x, TypeOfVer y) = 0;
    virtual bool exist(TypeOfVer x, TypeOfVer y) const = 0;
    int numOfVer() const {return Vers;}
    int numOfEdge() const {return Edges;}
protected:
    int Vers, Edges;
    
};
#endif /* graph_hpp */

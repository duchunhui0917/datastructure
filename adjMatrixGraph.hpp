//
//  adjMatrixGraph.hpp
//  datastructure
//
//  Created by duchunhui on 2018/12/16.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef adjMatrixGraph_hpp
#define adjMatrixGraph_hpp

#include <stdio.h>
#include "graph.hpp"

template<class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph:public graph<TypeOfVer, TypeOfEdge>{
public:
    adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag);
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y) const;
    ~adjMatrixGraph();
private:
    TypeOfEdge **edge;//adjoin matrix
    TypeOfVer *ver;
    TypeOfEdge noEdge;
    int find(TypeOfVer v) const{
        for (int i=0; i<this->Vers; ++i)
            if(ver[i]==v) return i;
    }
};

template<class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag) {
    int i,j;
    this->Vers = vSize;
    this->Edges = 0;
    noEdge = noEdgeFlag;
    
    //initialize ver
    ver = new TypeOfVer[this->Vers];
    for (i=0; i<this->Vers; ++i)
        ver[i] = d[i];
    
    //initialzie edge
    edge = new TypeOfEdge*[this->vers];
    for (i=0; i<this->Vers; ++i) {
        edge[i] = new TypeOfEdge[this->Vers];
        for (j=0; j<this->Vers; ++j)
            edge[i][j] = noEdgeFlag;
        edge[i][i] = 0;
    }
}

template<class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::~adjMatrixGraph(){
    delete ver;
    for(int i=0;i<this->Vers;++i)
        delete edge[i];
    delete edge;
}

template<class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w){
    int u = find(x), v = find(y);
    edge[u][v] = w;
    ++this->Edges;
}

template<class TypeOfVer, class TypeOfEdge>
void adjMatrixGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer x, TypeOfVer y){
    int u = find(x), v = find(y);
    edge[u][v] = noEdge;
    ++this->Edges;
}
template<class TypeOfVer, class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y) const{
    int u = find(x), v = find(y);
    return edge[u][v] != noEdge;
}

#endif /* adjMatrixGraph_hpp */

//
//  adjListGraph.hpp
//  datastructure
//
//  Created by duchunhui on 2018/12/16.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef adjListGraph_hpp
#define adjListGraph_hpp

#include <stdio.h>
#include <iostream>
#include "graph.hpp"
#include "linkQueue.hpp"
using namespace std;

template<class TypeOfVer, class TypeOfEdge>
class adjListGraph:public graph<TypeOfVer, TypeOfEdge>{
public:
    adjListGraph(int vSize, const TypeOfVer d[]);
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y) const;
    ~adjListGraph();
    void dfs() const;
    void bfs() const;
    void findPath(TypeOfVer start, int m) const;
private:
    struct edgeNode
    {
        int end;
        TypeOfEdge weight;
        edgeNode *next;
        
        edgeNode(int e, TypeOfEdge w, edgeNode *n=NULL):end(e), weight(w), next(n){}
    };
    struct verNode
    {
        TypeOfVer ver;
        edgeNode *head;
        
        verNode(edgeNode *h=NULL):head(h){}
    };
    
    verNode *verList;
    
    int find(TypeOfVer v) const{
        for(int i=0; i<this->Vers; ++i){
            if (verList[i].ver==v)
                return i;
        }
        return 0;
    }
    void dfs(int start, bool visited[]) const;
    void findPath(int start, int m, int &top, bool visited[], int st[]) const;
};
template<class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[]){
    this->Vers = vSize;
    this->Edges = 0;
    
    verList = new verNode[this->Vers];
    
    for(int i=0; i<this->Vers; ++i)
        verList[i].ver = d[i];
}
template<class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph<TypeOfVer, TypeOfEdge>(){
    edgeNode *p;
    for (int i=0; i<this->Vers; ++i) {
        while ((p=verList[i].head)!=NULL) {
            verList[i].head = p->next;
            delete p;
        }
    }
    delete [] verList;
}
template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w){
    int u = find(x), v = find(y);
    verList[u].head = new edgeNode(v, w, verList[u].head);
    ++this->Edges;
}
template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer x, TypeOfVer y){
    int u = find(x), v = find(y);
    edgeNode *p = verList[u].head, *q;
    if (p==NULL)
        return;
    if (p->end==v){//first node of list is to be deleted
        verList[u].head = p->next;
        delete p;
        --this->Edges;
        return;
    }
    while (p->next!=NULL&&p->next->end!=v)//judge p->next rather than p
        p = p->next;
    if (p->next!=NULL) {
        q = p->next;
        p->next = q->next;
        delete q;
        --this->Edges;
    }
    
}
template<class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y) const{
    int u = find(x), v = find(y);
    edgeNode *p = verList[u].head;
    
    while (p!=NULL&&p->end!=v)
        p = p->next;
    return p!=NULL;
}
template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const{
    int i;
    bool *visited = new bool[this->Vers];
    for(i=0; i<this->Vers; ++i) visited[i] = false;
    
    for (i=0; i<this->Vers; ++i) {
        if (visited[i]==false) {
            dfs(i, visited);
            cout << endl;
        }
    }
    
}
template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool *visited) const{
    edgeNode *p = verList[start].head;
    
    cout << verList[start].ver << '\t';
    visited[start] = true;
    
    while (p!=NULL) {
        if (visited[p->end]==false)
            dfs(p->end, visited);
            p = p->next;
    }
}
template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const{
    int currentNode;
    edgeNode *p;
    linkQueue<int> que;
    bool *visited = new bool[this->Vers];
    for (int i=0; i<this->Vers; ++i) visited[i] = false;
    
    cout << "bfs sequence is:" << endl;
    
    for (int j=0; j<this->Vers; ++j) {
        if (visited[j]==false){
            que.enQueue(j);
            visited[j] = true;
        }
        while (!que.isEmpty()) {
            currentNode = que.deQueue();
            cout << verList[currentNode].ver << '\t';
            p = verList[currentNode].head;
            
            while (p!=NULL) {
                if (visited[p->end]==false) {
                    que.enQueue(p->end);
                    visited[p->end] = true;
                }
                p = p->next;
            }
        }
        cout << endl;
    }
}
template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::findPath(TypeOfVer start, int m) const{
    bool *visited = new bool[this->Vers];
    int *stack = new int[m + 1], top = 0;
    int i;
    for (i=0; i<this->Vers; ++i) visited[i] = false;
    
    for (i=0; i<this->Vers; ++i) {
        if (verList[i].ver==start)
            break;
    }
    if (i==this->Vers){
        cout << "start is not exist" << endl;
        return;
    }
    
    findPath(i, m, top, visited, stack);
}
template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::findPath(int start, int m, int &top, bool *visited, int *st) const{
    edgeNode *p = verList[start].head;
    
    visited[start] = true;
    st[top++] = start;
    if (top==m+1) {
        cout << endl;
        for (int i=0; i<top; ++i)
            cout << verList[st[i]].ver << '\t';
        visited[start] = false;
        --top;
        return;
    }
    while (p!=NULL) {
        if (!visited[p->end])
            findPath(p->end, m, top, visited, st);
        p = p->next;
    }
    visited[start] = false;
    --top;
}
#endif /* adjListGraph_hpp */

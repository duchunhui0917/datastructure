//
//  childBrotherTree.hpp
//  datastructure
//
//  Created by duchunhui on 2018/11/11.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef childBrotherTree_hpp
#define childBrotherTree_hpp

#include <stdio.h>
#include <iostream>
#include "linkQueue.hpp"
template<class T>
class childBrotherTree{
    struct Node{
        Node *child;
        Node *brother;
        T data;
        Node(T x, Node *c=NULL, Node *b=NULL):data(x), child(c), brother(b){}
    };
    Node *root;
public:
    childBrotherTree():root(NULL){}
    childBrotherTree(T x){root = new Node(x);}
    void createTree();
    void preOrder() const;
    void postOrder() const;
    void levelOrder() const;
    int height() const;
    int size() const;
private:
    void preOrder(Node *t) const;
    void postOrder(Node *t) const;
    int height(Node *t) const;
    int size(Node *t) const;
};
template<class T>
void childBrotherTree<T>::createTree(){
    linkQueue<Node *> que;
    Node *tmp, *bro = NULL;
    T x;
    std::cout << "input root:";
    std::cin >> x;
    root = new Node(x);
    
    que.enQueue(root);
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        std::cout << "input " << tmp->data << "'s children(@ represents null node):";
        std::cin >> x;
        while (x!='@') {
            if (tmp->child==NULL){//Big brother
                bro = new Node(x);
                tmp->child = bro;
            }
            else{
                bro->brother = new Node(x);
                bro = bro->brother;
            }
            que.enQueue(bro);
            std::cin >> x;
        }
    }
}
template<class T>
void childBrotherTree<T>::preOrder(Node *t) const{
    if (t==NULL)
        return;
    std::cout << t->data << ' ';
    preOrder(t->child);
    preOrder(t->brother);
}
template<class T>
void childBrotherTree<T>::preOrder() const{
    std::cout << "\nPreorder\n";
    preOrder(root);
}
template<class T>
void childBrotherTree<T>::postOrder(Node *t) const{
    if (t==NULL)
        return;
    postOrder(t->child);
    std::cout << t->data << ' ';
    postOrder(t->brother);
}
template<class T>
void childBrotherTree<T>::postOrder() const{
    std::cout << "\nPostorder\n";
    postOrder(root);
}
template<class T>
void childBrotherTree<T>::levelOrder() const{
    std::cout << "\nLevelorder\n";
    linkQueue<Node *> que;
    Node *tmp;
    Node *child;
    
    que.enQueue(root);
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        std::cout << tmp->data << ' ';
        
        child = tmp->child;
        while (child!=NULL ) {
            que.enQueue(child);
            child = child->brother;
        }
    }
}
template<class T>
int childBrotherTree<T>::height(Node *t) const{
    int max = 0, cur;
    Node *child = t->child;
    
    while (child!=NULL) {
        cur = height(child);
        if (cur>max)
            max = cur;
        child = child->brother;
    }

    return max + 1;
}
template<class T>
int childBrotherTree<T>::height() const{
    return height(root);
}
template<class T>
int childBrotherTree<T>::size(Node *t) const{
    int s = 0;
    Node *child = t->child;
    
    while (child!=NULL) {
        s += size(child);
        child = child->brother;
    }
    
    return s + 1;
}
template<class T>
int childBrotherTree<T>::size() const{
    return size(root);
}

#endif /* childBrotherTree_hpp */

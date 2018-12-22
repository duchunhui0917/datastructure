//
//  binaryTree.hpp
//  datastructure
//
//  Created by duchunhui on 2018/11/6.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef binaryTree_hpp
#define binaryTree_hpp

#include <stdio.h>
#include "bTree.hpp"
#include <iostream>
#include "linkQueue.hpp"
#include "linkStack.hpp"
template<class T>
class binaryTree:public bTree<T>{
    friend void printTree(const binaryTree &t, T flag);// friend function
private:
    struct Node{
        T data;
        Node *left;
        Node *right;
        Node():left(NULL),right(NULL){}
        Node(T item, Node *L=NULL, Node *R=NULL):data(item),left(L),right(R){}
        ~Node(){}
    };
    Node *root;
public:
    binaryTree():root(NULL){}
    binaryTree(T x){root = new Node(x);}
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void createTree(T flag);
    T parent(T x, T flag) const {return flag;}//binaryTree can't find parent
    int size() const;
    int height() const;
    void preOrderStack() const;
    void midOrderStack() const;
    void postOrderStack() const;
    void exchangeChild();
    bool isComplete();
private:
    Node *find(T x, Node *t) const;//traversal subtree,find node of x
    void clear(Node *&t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;
    int size(Node *t) const;
    int height(Node *t) const;
    
};
template<class T>
void binaryTree<T>::clear(Node *&t){
    if (t==NULL)
        return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}
template<class T>
void binaryTree<T>::clear(){
    clear(root);
}
template<class T>
bool binaryTree<T>::isEmpty() const{
    return root == NULL;
}
template<class T>
binaryTree<T>::~binaryTree(){
    clear(root);
}
template<class T>
T binaryTree<T>::Root(T flag) const{
    if (root == NULL)
        return flag;
    else
        return root->data;
}
template<class T>
typename binaryTree<T>::Node *binaryTree<T>::find(T x, Node *t) const{
    Node *tmp;
    if (t==NULL)
        return NULL;
    if (t->data==x)
        return t;
    tmp = find(x, t->left);
    if (tmp!=NULL)
        return tmp;
    else
        return find(x, t->right);
}
template<class T>
T binaryTree<T>::lchild(T x, T flag) const{
    Node *tmp;
    tmp = find(x, root);
    if (tmp==NULL||tmp->left==NULL)
        return flag;
    else
        return tmp->left->data;
}
template<class T>
T binaryTree<T>::rchild(T x, T flag) const{
    Node *tmp;
    tmp = find(x, root);
    if (tmp==NULL||tmp->right==NULL)
        return flag;
    else
        return tmp->right->data;
}
template<class T>
void binaryTree<T>::delLeft(T x){
    Node *tmp = find(x, root);
    if (tmp==NULL)
        return;
    else
        clear(tmp->left);
}
template<class T>
void binaryTree<T>::delRight(T x){
    Node *tmp = find(x, root);
    if (tmp==NULL)
        return;
    else
        clear(tmp->right);
}
template<class T>
void binaryTree<T>::preOrder(Node *t) const{
    if (t==NULL)
        return;
    std::cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
    
}
template<class T>
void binaryTree<T>::midOrder(Node *t) const{
    if (t==NULL)
        return;
    midOrder(t->left);
    std::cout << t->data << ' ';
    midOrder(t->right);
}
template<class T>
void binaryTree<T>::postOrder(Node *t) const{
    if (t==NULL)
        return;
    postOrder(t->left);
    postOrder(t->right);
    std::cout << t->data << ' ';
}
template<class T>
void binaryTree<T>::preOrder() const{
    std::cout << "Preorder" << std::endl;
    preOrder(root);
    std::cout << std::endl;
}
template<class T>
void binaryTree<T>::midOrder() const{
    std::cout << "MidOrder" << std::endl;
    midOrder(root);
    std::cout << std::endl;
}
template<class T>
void binaryTree<T>::postOrder() const{
    std::cout << "PostOrder" << std::endl;
    postOrder(root);
    std::cout << std::endl;
}
template<class T>
void binaryTree<T>::levelOrder() const{
    std::cout << "LevelOrder" << std::endl;
    linkQueue<Node *> que;
    Node *top;
    que.enQueue(root);
    while (!que.isEmpty()) {
        top = que.deQueue();
        std::cout << top->data << ' ';
        if (top->left!=NULL)
            que.enQueue(top->left);
        if (top->right!=NULL)
            que.enQueue(top->right);
    }
    std::cout << std::endl;
    
}
template<class T>
void binaryTree<T>::createTree(T flag){
    linkQueue<Node *> que;
    Node *tmp;
    T x, ldata, rdata;
    
    std::cout << "\n input root:";
    std::cin >> x;
    root = new Node(x);
    que.enQueue(root);
    
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        std::cout << "\n input:" << tmp->data << "'s two sons(" << flag << "represents null node)";
        std::cin >> ldata >> rdata;
        if (ldata!=flag)
            que.enQueue(tmp->left = new Node(ldata));
        if (rdata!=flag)
            que.enQueue(tmp->right = new Node(rdata));
    }
    
    std::cout << "create complete\n";
    
    
}
template<class T>
int binaryTree<T>::size(Node *t) const{
    if (t==NULL)
        return 0;
    return 1 + size(t->left) + size(t->right);
}
template<class T>
int binaryTree<T>::size() const{
    return size(root);
}
template<class T>
int binaryTree<T>::height(Node *t) const{
    if (t==NULL)
        return 0;
    int lt = hight(t->left);
    int rt = hight(t->right);
    return 1 + ((lt>rt)?lt:rt);
}
template<class T>
int binaryTree<T>::height() const{
    height(root);
}
template<class T>
void binaryTree<T>::preOrderStack() const{
    std::cout << "Preorder using nonrecursion" << std::endl;
    linkStack<Node *> stack;
    Node *tmp;
    stack.push(root);
    while (!stack.isEmpty()) {
        tmp = stack.pop();
        std::cout << tmp->data << ' ';
        if (tmp->right!=NULL)
            stack.push(tmp->right);
        if (tmp->left!=NULL)
            stack.push(tmp->left);
    }
    std::cout << std::endl;
}
template<class T>
void binaryTree<T>::midOrderStack() const{
    struct StNode{
        Node *node;
        int TimesPop;
        
        StNode(Node *N=NULL):node(N),TimesPop(0){}
    };
    std::cout << "Midorder using nonrecursion" << std::endl;
    linkStack<StNode> stack;
    StNode tmp(root);
    
    stack.push(StNode(root));
    while (!stack.isEmpty()) {
        tmp = stack.pop();
        if (++tmp.TimesPop==2) {//root is second pop, can be vist and push right child
            std::cout << tmp.node->data << ' ';
            if (tmp.node->right!=NULL)
                stack.push(StNode(tmp.node->right));
        }
        else{//root is first pop, can't be visit and push left child
            stack.push(tmp);
            if (tmp.node->left!=NULL)
                stack.push(StNode(tmp.node->left));
        }
    }
    std::cout << std::endl;
    
}
template<class T>
void binaryTree<T>::postOrderStack() const{
    struct StNode{
        Node *node;
        int TimesPop;
        
        StNode(Node *N=NULL):node(N),TimesPop(0){}
    };
    std::cout << "Postorder using nonrecursion" << std::endl;
    linkStack<StNode> stack;
    StNode tmp(root);
    
    stack.push(StNode(root));
    while (!stack.isEmpty()) {
        tmp = stack.pop();
        if (++tmp.TimesPop==2)
            std::cout << tmp.node->data << ' ';
        else{
            stack.push(tmp);
            if (tmp.node->right!=NULL)
                stack.push(StNode(tmp.node->right));
            if (tmp.node->left!=NULL)
                stack.push(StNode(tmp.node->left));
        }
    }
    std::cout << std::endl;
}
template<class T>
void binaryTree<T>::exchangeChild(){
    linkQueue<Node *> que;
    Node *tmp;
    Node *swap;
    
    que.enQueue(root);
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        
        swap = tmp->left;
        tmp->left = tmp->right;
        tmp->right = swap;
        
        if (tmp->left!=NULL)
            que.enQueue(tmp->left);
        if (tmp->right!=NULL)
            que.enQueue(tmp->right);
    }
}
template<class T>
bool binaryTree<T>::isComplete(){
    linkQueue<Node *> que;
    Node *tmp, *l, *r;
    bool complete = true;
    
    que.enQueue(root);
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        l = tmp->left;
        r = tmp->right;
        if (complete==true) {
            if (l==NULL){
                complete = false;
                if (r!=NULL)
                    return complete;
            }
            if (r==NULL)
                complete = false;
            
        }
        else{
            if (l!=NULL||r!=NULL)
                return complete;
        }
        if (l!=NULL) que.enQueue(l);
        if (r!=NULL) que.enQueue(r);
    }
    return true;
}
template<class T>
void printTree(const binaryTree<T> &t, T flag){
    linkQueue<T> q;
    q.enQueue(t.root->data);
    std::cout << std::endl;
    while (!q.isEmpty()) {
        char p, l, r;
        p = q.deQueue();
        l = t.lchild(p, flag);
        r = t.rchild(p, flag);
        std::cout << p << ' ' << l << ' ' << 'r' << std::endl;
        if (l!='@')
            q.enQueue(l);
        if (r!='@')
            q.enQueue(r);
    }
}

#endif /* binaryTree_hpp */

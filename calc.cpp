//
//  calc.cpp
//  datastructure
//
//  Created by duchunhui on 2018/10/30.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#include "calc.hpp"
#include <iostream>
#include "math.h"

calc::calc(char *s){
    expression = new char[strlen(s) + 1];
    suffixExpression = new char[strlen(s) + 1];
    strcpy(expression, s);
}

calc::~calc(){
    delete expression;
}

void calc::BinaryOp(token op, seqStack<int> &dataStack)
{
    int num1, num2;
    if (dataStack.isEmpty()) {
        std::cerr<< "lost right operational number";
        exit(1);
    }
    else
        num2 = dataStack.pop();
    if (dataStack.isEmpty()) {
        std::cerr<< "lost left operational number";
        exit(1);
    }
    else
        num1 = dataStack.pop();
    switch (op) {
        case ADD:
            dataStack.push(num1 + num2);
            break;
        case SUB:
            dataStack.push(num1 - num2);
            break;
        case MULTI:
            dataStack.push(num1 * num2);
            break;
        case DIV:
            dataStack.push(num1 / num2);
            break;
        case EXP:
            dataStack.push(pow(num1, num2));
        default:
            break;
    }

}

calc::token calc::getOp(int &value){
    while (*expression&&*expression == ' ')
        ++expression;
    
    if (!*expression)
        return EOL;
    if (*expression<='9'&&*expression>='0'){//deal with value
        value = *expression - '0';
        ++expression;
        return VALUE;
    }
    switch (*expression) {//deal with opearional
        case '(':
            ++expression;
            return OPAREN;
        case ')':
            ++expression;
            return CPAREN;
        case '+':
            ++expression;
            return ADD;
        case '-':
            ++expression;
            return SUB;
        case '*':
            ++expression;
            return MULTI;
        case '/':
            ++expression;
            return DIV;
        case '^':
            ++expression;
            return EXP;
        default:
            return EOL;
    }
}

int calc::result(){
    token lastOp, topOp;
    int resultValue, currentValue;
    seqStack<token> opStack;
    seqStack<int> dataStack;
    char *str = expression;
    
    while ((lastOp=getOp(currentValue))!=EOL) {
        switch (lastOp) {
            case VALUE:
                dataStack.push(currentValue);
                break;
            case CPAREN:
                while (!opStack.isEmpty()&&((topOp=opStack.pop())!=OPAREN))
                    BinaryOp(topOp, dataStack);
                if (topOp!=OPAREN)
                    std::cerr<<"lost OPAREN"<<std::endl;
                break;
            case OPAREN:
                opStack.push(OPAREN);
                break;
            case EXP:
                opStack.push(EXP);
                break;
            case MULTI:
            case DIV:
                while (!opStack.isEmpty()&&opStack.top()>=MULTI)
                    BinaryOp(opStack.pop(), dataStack);
                opStack.push(lastOp);
                break;
            case ADD:
            case SUB:
                while (!opStack.isEmpty()&&opStack.top()!=OPAREN)
                    BinaryOp(opStack.pop(), dataStack);
                opStack.push(lastOp);
                break;
            default:
                break;
        }
    }
    while (!opStack.isEmpty())
        BinaryOp(opStack.pop(), dataStack);
    if (dataStack.isEmpty()) {
        std::cout<< "no result\n";
        return 0;
    }
    resultValue = dataStack.pop();
    if (!dataStack.isEmpty()) {
        std::cout<< "lost operator\n";
        return 0;
    }
    expression = str;
    return resultValue;
}

char* calc::convert(){
    seqStack<char> opStack;
    char *str = expression;
    char *tmp = suffixExpression;
    
    while (*str) {
        if (*str==' ')
            str++;
        if (*str>='0'&&*str<='9') {
            *tmp = *str;
            tmp++;
            str++;
        }
        switch (*str) {
            case '(':
                opStack.push(*str);
                str++;
                break;
            case ')':
                while (!opStack.isEmpty()&&opStack.top()!='(') {
                    *tmp = opStack.pop();
                    tmp++;
                }
                if (opStack.top()=='(') {
                    opStack.pop();
                }
                else
                    std::cerr<<"lost left operator";
                str++;
                break;
            case '^':
                opStack.push(*str);
                str++;
                break;
            case '*':
            case '/':
                while (!opStack.isEmpty()&&(opStack.top()=='*'||opStack.top()=='/'||opStack.top()=='^')) {
                    *tmp = opStack.pop();
                    tmp++;
                }
                opStack.push(*str);
                str++;
                break;
            case '+':
            case '-':
                while (!opStack.isEmpty()&&opStack.top()!='(') {
                    *tmp = opStack.pop();
                    tmp++;
                }
                opStack.push(*str);
                str++;
                break;
            default:
                break;
        }
    }
    if (opStack.isEmpty())
        std::cerr<<"lost operator";
    else
        *tmp = opStack.pop();
    return suffixExpression;
}

int calc::calcSuffix(){
    token lastOp;
    int currentValue;
    seqStack<int> dataStack;
    
    while ((lastOp=getOp(currentValue))!=EOL){
        if (lastOp==VALUE)
            dataStack.push(currentValue);
        else
            BinaryOp(lastOp, dataStack);
    }
    return dataStack.pop();
}



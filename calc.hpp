//
//  calc.hpp
//  datastructure
//
//  Created by duchunhui on 2018/10/30.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef calc_hpp
#define calc_hpp

#include <stdio.h>
#include <string.h>
#include "seqStack.hpp"

class calc{
private:
    char *expression;//infix expression to calculte
    char *suffixExpression;//suffix expression
    
    enum token{OPAREN, ADD, SUB, MULTI, DIV, EXP, CPAREN, VALUE, EOL};
    void BinaryOp(token op, seqStack<int> &dataStack);
    token getOp(int &value);
    
    
public:
    calc(char *s);
    ~calc();
    int result();
    char* convert();//convert midfix expression to suffix expression
    int calcSuffix();//calculte suffix expression
};

#endif /* calc_hpp */

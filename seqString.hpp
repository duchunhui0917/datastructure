//
//  seqString.hpp
//  datastructure
//
//  Created by duchunhui on 2018/11/4.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#ifndef seqString_hpp
#define seqString_hpp

#include <stdio.h>
#include <iostream>
class seqString{
    friend seqString operator+(const seqString &s1, const seqString &s2);
    friend bool operator==(const seqString &s1, const seqString &s2);
    friend bool operator!=(const seqString &s1, const seqString &s2);
    friend bool operator>(const seqString &s1, const seqString &s2);
    friend bool operator>=(const seqString &s1, const seqString &s2);
    friend bool operator<(const seqString &s1, const seqString &s2);
    friend bool operator<=(const seqString &s1, const seqString &s2);
    friend std::ostream &operator<<(std::ostream &os, const seqString &s);
    char *data;
    int len;
public:
    seqString(const char *s="");
    seqString(const seqString &other);
    ~seqString();
    int length() const;
    seqString &operator=(const seqString &other);
    seqString subStr(int start, int num) const;
    void insert(int start, const seqString &s);
    void remove(int start, int num);
};

#endif /* seqString_hpp */

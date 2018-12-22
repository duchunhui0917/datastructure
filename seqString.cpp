//
//  seqString.cpp
//  datastructure
//
//  Created by duchunhui on 2018/11/4.
//  Copyright © 2018 duchunhui. All rights reserved.
//

#include "seqString.hpp"

seqString::seqString(const char *s){//constructed function
    for (len=0; s[len]!='\0'; ++len);
    data = new char[len + 1];
    for (len=0; s[len]!='\0'; ++len)
        data[len] = s[len];
    data[len] = '\0';
}

seqString::seqString(const seqString &other){//copy constructed function
    data = new char[other.len + 1];
    for (len=0; len<=other.len; ++len)
        data[len] = other.data[len];
}

seqString::~seqString(){
    delete data;
}

int seqString::length() const{
    return len;
}

seqString &seqString::operator=(const seqString &other){
    if (this==&other)
        return *this;
    delete data;
    data = new char[other.len + 1];
    for (len=0; len<=other.len; ++len)
        data[len] = other.data[len];
    return *this;
}

seqString seqString::subStr(int start, int num) const
{
    if (start>len-1||start<0)
        return "";
    seqString tmp;
    tmp.len = (start + num > len)?len - start:num;
    delete tmp.data;
    tmp.data = new char[tmp.len + 1];
    int i;
    for (i=0; i<tmp.len; ++i)
        tmp.data[i] = data[start + i];
    tmp.data[i] = '\0';
    return tmp;
}

void seqString::insert(int start, const seqString &s){
    if (start>len-1||start<0)
        return;
    char *tmp = new char[len + s.len];
    int i;
    for (i=0; i<start; ++i)
        tmp[i] = data[i];
    for (i=0; i<s.len; ++i)
        tmp[i + start] = s.data[i];
    for (i=start; i<len; ++i)
        tmp[i + s.len] = data[i];
    tmp[i] = '\0';
    delete data;
    data = tmp;
}

void seqString::remove(int start, int num){
    if (start>len-1||start<0)
        return;
    if (start + num >= len) {
        data[start] = '\0';
        len = start;
    }
    else{
        for (len=start; data[len+num]!='\0'; ++len)
            data[len] = data[len + num];
        data[len] = '\0';
    }
}

seqString operator+(const seqString &s1, const seqString &s2){
    seqString tmp;
    delete tmp.data;
    tmp.data = new char(s1.len + s2.len + 1);
    int i;
    for (i=0; i<s1.len; ++i)
        tmp.data[i] = s1.data[i];
    for (i=0; i<s2.len; ++i)
        tmp.data[i + s1.len] = s2.data[i];
    tmp.data[s1.len + s2.len] = '\0';
    return tmp;
}

bool operator==(const seqString &s1, const seqString &s2){
    if (s1.len!=s2.len)
        return false;
    for (int i=0; i<s1.len; ++i) {
        if (s1.data[i]!=s2.data[i])
            return false;
    }
    return true;
}

bool operator!=(const seqString &s1, const seqString &s2){
    return !(s1==s2);
}

bool operator>(const seqString &s1, const seqString &s2){
    for (int i=0; i<s1.len; ++i) {
        if (s1.data[i]>s1.data[i])
            return true;
        else if (s1.data[i]<s1.data[i])
            return false;
    }
    return false;
}

bool operator>=(const seqString &s1, const seqString &s2){
    return (s1 > s2 || s1 == s2);
}

bool operator<=(const seqString &s1, const seqString &s2){
    return !(s1 > s2);
}

bool operator<(const seqString &s1, const seqString &s2){
    return !(s1 >= s2);
}




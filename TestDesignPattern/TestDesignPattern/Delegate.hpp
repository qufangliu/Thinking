//
//  Delegate.hpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/3.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

/*
 简要说明
 
    委托模式
 
    委托，可以理解为一个类通过其他的类来实现某个功能。委托和代理。。区分不出来了，晕。
    委托模式，有两种理解方式:
        1.正向理解为，类A需要实现功能operation(),所有它为其他类提供了一个包含operation()方法的虚基类D，然后类B可以实现operation()方法，所以B继承了虚基类D，然后将自己的指针传给A。对A来说，它获得了一个D类的指针，A仅仅使用虚基类D中的方法，D称为委托类。
        2.反向理解为，类B有很多功能，但是它只愿意将部分功能开放给用户，所以把B愿意开放的功能抽离出来，形成了一个虚基类D，然后B继承这个虚基类D，用户只能持有D类的指针，类B中的部分功能对用户进行了屏蔽，而虚基类D本事不能创建对象，所以D类开放给用户的功能并不是它自己实现的，而是委托其他的类实现的，D称为委托类。
 
    注意：
        1.委托模式达到了解耦合的效果，例如类B中持有类A的指针，但是A又需要使用B的功能，此时如果A持有B的指针就出现循环引用，所以可以使用委托类D来进行解耦。
        2.可扩展性强，因为委托对象是随时可以更换的。
        3.过度使用，可能导致功能分散和重复，维护起来非常麻烦。
        4.代理的多种实现方式:http://stackoverflow.com/questions/9568150/what-is-a-c-delegate
 */

#ifndef Delegate_hpp
#define Delegate_hpp

#include <stdio.h>

//委托类
class Delegate
{
public:
    virtual int add(int,int) = 0;
};

//功能实现类
class B : public Delegate
{
public:
    int add(int,int);
    int subtract(int,int);
};

//需要功能的类
class A
{
public:
    //如果A只需要一个Add方法，它可以委托B来实现
    void setDelegate(Delegate* d) {m_pDelegate = d;}    //设置委托
    
    int myAdd(int a,int b) { return m_pDelegate->add(a, b);}    //实现功能
    
private:
    Delegate* m_pDelegate;
};












#endif /* Delegate_hpp */







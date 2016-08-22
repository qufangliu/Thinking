//
//  Composite.hpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/2.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

/*
 简要说明
 
    组合模式
    
    组合模式，就是将对象组合成树形结构的设计模式。常用与设计程序框架。
 
    优缺点:
        1.使用一个composite来管理众多子对象，将数据结构分级，优化递归处理。
        2.所有子对象具有某些统一的方法（例如add,remove等），便于用户进行操作。
        3.缺点就是某些子类没有实现父类中的方法，用户调用时，可能比较麻烦。
 */

#ifndef Composite_hpp
#define Composite_hpp

#include <stdio.h>

//组合类
class Composite
{
public:
    virtual ~Composite();
    virtual void add(Composite*);
    virtual void remove(Composite*);
    virtual void operation() = 0;   //纯虚函数
    
protected:
    Composite();
};

//子类1
class Component : public Composite
{
public:
    virtual ~Component();
    virtual void add(Composite*);       //需要实现
    virtual void remove(Composite*);    //需要实现
    virtual void operation();           //需要实现
protected:
    Component();
};

//子类2
class Leaf : public Composite
{
public:
    virtual ~Leaf();
    virtual void operation();           //需要实现
    
protected:
    Leaf();
};

#endif /* Composite_hpp */

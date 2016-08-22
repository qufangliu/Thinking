//
//  TwoStage.hpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/1.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

/*
 简要说明
 
    二段构建模式
 
    二段构建模式是指:创建对象时，不直接通过构造函数来完成对象的创建，而是通过两个阶段来进行，阶段一是使用构造函数来分配内存，阶段二是使用独立的初始化方法来进行对象的初始化。
    
    优点或使用此模式的原因:
        1.构造函数的名称是固定的，虽然可以重载，但是可读性差。
        2.在c++构造函数执行时不能调用virtual函数（即使调用，也是使用静态调用机制），二段构建模式利于派生类的构造。
        3.构造函数中如果出现异常，需要使用try-catch进行捕捉，这样导致二进制文件变大。
        4.使用二段构建模式，可以对所有的类实现统一的工厂方法，便于派生出子类，也方便整体内存管理。
        5.使用二段构建模式，一个类可以有多个初始化函数，提高了可读性，而且可以在初始化函数中调用virtual函数，实现子类的特殊需求。
 */


#ifndef TwoStage_hpp
#define TwoStage_hpp

#include <stdio.h>

class TwoStage
{
public:
    static TwoStage* create();
    static TwoStage* create(int var);
    static TwoStage* createWithTwoParameter(float a, float b);
    
protected:
    virtual bool init();
    bool initWithParameter(int var);
    bool initWithTwoParameter(float a, float b);
};

#endif /* TwoStage_hpp */

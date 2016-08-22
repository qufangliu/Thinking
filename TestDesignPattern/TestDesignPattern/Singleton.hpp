//
//  Singleton.hpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/1.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

/*
 简要说明
 
    单例模式
 
    单例模式是指某个类只有唯一一个对象，所有的其它类只能通过这一个对象来访问该类的其他函数。单例模式的生命周期通常是从被创建开始，一直到应用结束。
 
    实现单例模式的要素:
        1.私有化的构造函数（不确定要不要私有化析构函数，但是在程序中，单例模式的生命周期从创建到应用结束，所以也用不着析构函数吧）
        2.定义一个本类型的静态变量指针
        3.提供一个可以访问本类的对象的静态方法
 
    注意:
        1.尽量少使用单例模式，因为单例模式是一种高耦合度的设计模式，十分不利于后期的扩展。
        2.单例模式本身就是一种内存泄露，因为在程序运行过程中，它所占用的内存不会被回收。
        3.本示例只是实现了最基本的单例，并没有考虑多线程中的线程安全。
 */


#ifndef Singleton_hpp
#define Singleton_hpp

#include <stdio.h>

class Singleton
{
public:
    static Singleton* getInstance();
    
private:
    Singleton();
    ~Singleton();
    
private:
    static Singleton* m_pInstance;
};

#endif /* Singleton_hpp */



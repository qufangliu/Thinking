//
//  Facade.hpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/1.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

/*
 简要说明
 
    外观模式
 
    外观模式一般通过单例来实现，向用户提供一个简单的工具类，其功能实现部分包涵了各个子系统的功能。
 
    注意:
        1.外观模式解除各个子系统与游戏逻辑的耦合，但是其本身就是一个高度耦合的类。
        2.对用户屏蔽子系统的基础组件，用户需要处理的工具类更少。
 
    这里的示例表示的是：
        例如一台电脑包含了CPU,Memory,HardDrive。用户启动电脑时，电脑提供的启动方法中包含了初始化cpu，内存加载从硬盘读取的启动参数，cpu执行启动命令等过程。对用户来说，电脑就是一个外观模式，因为它所提供的启动电脑的函数屏蔽了子系统的基础功能。
 */

#ifndef Facade_hpp
#define Facade_hpp

#include <stdio.h>

class CPU
{
public:
    void freeze() {}
    void jump(long position) {}
    void execute() {}
};

class Memory
{
public:
    void load(long position, char data) {}
};

class HardDrive
{
public:
    char read(long position, int size) { return 'a'; }
};

class Computer
{
public:
    Computer();
    
public:
    void starComputer();
    
private:
    CPU* cpu;
    Memory* memory;
    HardDrive* hardDrive;
};

#endif /* Facade_hpp */

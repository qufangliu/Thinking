//
//  Defense.cpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/2.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//



#include "Defense.hpp"

Defense* Defense::create()
{
    Defense* ptr = nullptr;
    do {
        if (!(ptr = new Defense())) {
            break;
        }
        else {
            return ptr;
        }
    } while (0);
    
    delete ptr;
    ptr = nullptr;
    return nullptr;
}


bool Defense::execute()
{
    //多个功能函数
    auto func1 = [=](){
        return false;
    };
    
    auto func2 = [=](){
        return true;
    };
    
    auto func3 = [=](){
        return false;
    };
    
    //原来的方式
    if (!func1()) {
        //执行失败，错误处理
        return false;
    }
    if (!func2()) {
        //执行失败，错误处理
        return false;
    }
    if (!func3()) {
        //执行失败，错误处理
        return false;
    }
    
    //使用do{...}while(0);
    do {
        if (!func1()) {
            break;
        }
        if (!func2()) {
            break;
        }
        if (!func3()) {
            break;
        }
    } while (0);
    //统一错误处理
    return false;
}


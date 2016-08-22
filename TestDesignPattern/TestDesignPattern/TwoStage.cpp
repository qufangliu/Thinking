//
//  TwoStage.cpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/1.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

#include "TwoStage.hpp"

TwoStage* TwoStage::create()
{
    //第一阶段:分配内存
    auto pInstance = new TwoStage();
    
    //第二阶段:初始化
    if (pInstance && pInstance->init()) {
        //这里可以进行内存管理
        
        return pInstance;
    }
    else {
        
        return nullptr;
    }
}

TwoStage* TwoStage::create(int var)
{
    auto pInstance = new TwoStage();
    
    if (pInstance && pInstance->initWithParameter(var)) {
        
        return pInstance;
    }
    
    return nullptr;
}

TwoStage* TwoStage::createWithTwoParameter(float a, float b)
{
    auto pInstance = new TwoStage();
    
    if (pInstance && pInstance->initWithTwoParameter(a, b)) {
        
        return pInstance;
    }
    
    return nullptr;
}

bool TwoStage::init()
{
    //进行基类初始化方法的调用
    //进行一些子类特殊的初始化操作
    return true;
}

bool TwoStage::initWithParameter(int var)
{
    //进行一些初始化操作
    return true;
}

bool TwoStage::initWithTwoParameter(float a, float b)
{
    //进行初始化操作
    return true;
}
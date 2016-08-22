//
//  Singleton.cpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/1.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

#include "Singleton.hpp"

Singleton::Singleton()
{
    
}

Singleton::~Singleton()
{
    
}

Singleton* Singleton::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new Singleton();
    }
    return m_pInstance;
}
//
//  Manager.cpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/1.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

#include "Manager.hpp"

Manager::Manager()
{
    
}

Manager::~Manager()
{
    
}

Manager* Manager::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new Manager();
    }
    return m_pInstance;
}

void Manager::pushObject(const std::string &strKey, int pObject)
{
    m_mapObjectList[strKey] = pObject;
}

int Manager::getObjectByKey(const std::string &strKey)
{
    if (m_mapObjectList.find(strKey) != m_mapObjectList.end()) {
        return m_mapObjectList[strKey];
    }
    else {
        return 0;
    }
}


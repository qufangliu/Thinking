//
//  QFLManager.cpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/25.
//
//

#include "QFLManager.hpp"

static QFLManager* m_pInstance = nullptr;

QFLManager::QFLManager()
{
    
}

QFLManager::~QFLManager()
{
    
}

QFLManager* QFLManager::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new (std::nothrow)QFLManager();
        m_pInstance->init();
    }
    else {}
    
    return m_pInstance;
}

void QFLManager::init()
{
    //一些工具的初始化
    m_pNotificationCenter = QFLNotificationCenter::getInstance();
    
    m_pQFLTools = QFLTools::getInstance();
}
//
//  QFLNotification.cpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/25.
//
//

#include "QFLNotification.hpp"

/*
 QFLNotificationCenter
 */

static QFLNotificationCenter *m_pInstance = nullptr;

QFLNotificationCenter::QFLNotificationCenter()
{
    
}

QFLNotificationCenter::~QFLNotificationCenter()
{
    
}

QFLNotificationCenter* QFLNotificationCenter::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new (std::nothrow)QFLNotificationCenter();
    }
    else {}
    return m_pInstance;
}

//添加监听
void QFLNotificationCenter::addNotificationListener(QFLNotificationListener *pListener)
{
    if (std::find(m_vectorListener.begin(), m_vectorListener.end(), pListener) == m_vectorListener.end()) {
        m_vectorListener.push_back(pListener);
    }
    else {}
}

void QFLNotificationCenter::removeNotificationListener(QFLNotificationListener *pListener)
{
    auto it = std::find(m_vectorListener.begin(), m_vectorListener.end(), pListener);
    
    if (it != m_vectorListener.end()) {
        m_vectorListener.erase(it);
    }
    else {}
}

//通知事件
void QFLNotificationCenter::notifyEvent(const std::string &strEvent)
{
    for (auto &it : m_vectorListener) {
        it->notifyEvent(strEvent);
    }
}


/*
 QFLNotificationListener
 */

QFLNotificationListener::QFLNotificationListener()
{
    
}

QFLNotificationListener::~QFLNotificationListener()
{
    
}

QFLNotificationListener* QFLNotificationListener::create()
{
    QFLNotificationListener *pListener = new (std::nothrow)QFLNotificationListener();
    
    if (pListener) {
        return pListener;
    }
    else {
        delete pListener;
        return nullptr;
    }
}

void QFLNotificationListener::addAttention(const std::string &strEvent, const std::function<void ()> &func)
{
    m_mapEventFunc[strEvent] = func;    //已有的事件会直接覆盖
}

void QFLNotificationListener::notifyEvent(const std::string &strEvent)
{
    if (m_mapEventFunc.find(strEvent) != m_mapEventFunc.end()) {
        (m_mapEventFunc[strEvent])();   //这个调用。。。。写的不直观
    }
    else {}
}

void QFLNotificationListener::removeAttention(const std::string &strEvent)
{
    if (m_mapEventFunc.find(strEvent) != m_mapEventFunc.end()) {
        m_mapEventFunc.erase(strEvent);
    }
    else {}
}

void QFLNotificationListener::removeAllAttention()
{
    m_mapEventFunc.clear();
}



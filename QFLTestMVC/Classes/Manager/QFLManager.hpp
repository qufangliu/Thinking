//
//  QFLManager.hpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/25.
//
//

#ifndef QFLManager_hpp
#define QFLManager_hpp

#include <stdio.h>

#include "QFLNotification.hpp"
#include "QFLTools.hpp"

class QFLManager
{
public:
    virtual ~QFLManager();
    static QFLManager* getInstance();
    
public:
    QFLNotificationCenter* getNotificationCenter() { return m_pNotificationCenter; };
    
    QFLTools* getTools() { return m_pQFLTools; };
    
private:
    QFLManager();
    void init();
    
private:
    QFLNotificationCenter *m_pNotificationCenter;  //持有一个Center指针
    
    QFLTools *m_pQFLTools;  //持有QFLTools的指针
};

#define QFL_MANAGER QFLManager::getInstance()

#endif /* QFLManager_hpp */

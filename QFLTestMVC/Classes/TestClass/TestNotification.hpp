//
//  TestNotification.hpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/26.
//
//

#ifndef TestNotification_hpp
#define TestNotification_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "QFLManager.hpp"

class TestNotification : public cocos2d::Layer
{
public:
    TestNotification();
    virtual ~TestNotification();
    virtual bool init();
    
    CREATE_FUNC(TestNotification);
    
private:
    void addUI();
    void addMenuItem(const std::string &strText, const std::function<void()> &funcCallback);
    
private:
    cocos2d::Menu *m_pMenu;
    int m_nItemCount;
    
    QFLNotificationListener *m_pListener1;
    QFLNotificationListener *m_pListener2;
};

#endif /* TestNotification_hpp */

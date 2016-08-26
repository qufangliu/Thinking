//
//  QFLNotification.hpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/25.
//
//

#ifndef QFLNotification_hpp
#define QFLNotification_hpp

#include <stdio.h>

//声明
class QFLNotificationListener;

//消息中心
class QFLNotificationCenter
{
public:
    //构造相关
    virtual ~QFLNotificationCenter();
    static QFLNotificationCenter* getInstance();
    
    //添加和移除监听
    void addNotificationListener(QFLNotificationListener *pListener);
    void removeNotificationListener(QFLNotificationListener *pListener);
    
    //通知事件
    void notifyEvent(const std::string &strEvent);
    
private:
    QFLNotificationCenter();
    
private:
    std::vector<QFLNotificationListener*> m_vectorListener;
    
};

//监听器
class QFLNotificationListener
{
public:
    //构造相关
    QFLNotificationListener();
    virtual ~QFLNotificationListener();
    static QFLNotificationListener* create();
    
    //添加对某个事件的监听
    void addAttention(const std::string &strEvent, const std::function<void()> &func);
    
    //通知某个事件，由Center来调用
    void notifyEvent(const std::string &strEvent);
    
    //取消对事件的监听
    void removeAttention(const std::string &strEvent);
    void removeAllAttention();
    
private:
    std::map<std::string, std::function<void()>> m_mapEventFunc;
};

#endif /* QFLNotification_hpp */

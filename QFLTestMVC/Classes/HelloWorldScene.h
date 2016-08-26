#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(HelloWorld);
    
private:
    void initData();
    void addUI();
    
    void addMenuItem(const std::string &strText, const std::function<void()> &funcCallback);
    
private:
    cocos2d::Menu *m_pMenu;
    int m_nItemCount;
};

#endif // __HELLOWORLD_SCENE_H__

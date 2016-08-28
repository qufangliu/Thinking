//
//  QFLView.hpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/29.
//
//

#ifndef QFLView_hpp
#define QFLView_hpp

#include <stdio.h>

//一般情况下，仅View部分与cocos2d-x引擎相关
#include "cocos2d.h"

class QFLView : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(QFLView);
    
    
    void showLine(float fHeight);   //显示地平线
    void updatePlayerPos(cocos2d::Vec2 vecPos); //显示Player位置
    
    void showPlayer() { m_pPlayer->setVisible(true); }
    void hidePlayer() { m_pPlayer->setVisible(false); }
    
private:
    void addUI();
    
private:
    cocos2d::Sprite *m_pPlayer;
};

#endif /* QFLView_hpp */

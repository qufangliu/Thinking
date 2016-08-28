//
//  QFLView.cpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/29.
//
//

#include "QFLView.hpp"

#include "QFLManager.hpp"

USING_NS_CC;

bool QFLView::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        return true;
    }
}

void QFLView::addUI()
{
    //添加灰色背景
    QFL_MANAGER->getTools()->addNoTouchLayerColor(this, Color4B::GRAY);
    
    //添加主角
    m_pPlayer = Sprite::create("CloseNormal.png");
    m_pPlayer->setPosition(Vec2::ZERO);
    this->addChild(m_pPlayer);
    
    this->hidePlayer();
    
}

void QFLView::showLine(float fHeight)
{
    DrawNode* pDraw = DrawNode::create();
    pDraw->setPosition(Vec2::ZERO);
    this->addChild(pDraw);
    
    float fWinWidth = Director::getInstance()->getVisibleSize().width;
    
    pDraw->drawLine(Vec2(0, fHeight), Vec2(fWinWidth, fHeight), Color4F::BLUE);
}

void QFLView::updatePlayerPos(cocos2d::Vec2 vecPos)
{
    m_pPlayer->setPosition(vecPos);
}

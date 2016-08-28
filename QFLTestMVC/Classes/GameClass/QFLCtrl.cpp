//
//  QFLCtrl.cpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/27.
//
//

#include "QFLCtrl.hpp"
#include "cocos2d.h"

USING_NS_CC;
using namespace QFLBase;

#define WORLD_RATIO     32
#define GROUND_HEIGHT   1.5

static QFLCtrl* m_pInstance = nullptr;

QFLCtrl::QFLCtrl()
{
    m_fGravity = 0.0f;
}

QFLCtrl::~QFLCtrl()
{
    
}

QFLCtrl* QFLCtrl::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new (std::nothrow)QFLCtrl();
    }
    else {}
    
    return m_pInstance;
}

void QFLCtrl::initWorld()
{
    m_fGravity = -9.8f;
    
    this->addView();
    this->addPlayer();
}

void QFLCtrl::addView()
{
    //创建显示层
    m_pView = QFLView::create();
    m_pView->showLine(GROUND_HEIGHT * WORLD_RATIO);
    m_pView->showPlayer();
    
    //添加显示层
    Director::getInstance()->getRunningScene()->addChild(m_pView);
}

void QFLCtrl::addPlayer()
{
    //生成Model
    m_pPlayers = new QFLPlayer();
    m_pPlayers->setPos(QFLVec(7, 15));
    m_pPlayers->setAcceleration(QFLVec(0, m_fGravity));
    m_pPlayers->setElasticity(0.75);
    m_pPlayers->setGroundHeight(GROUND_HEIGHT);
}

void QFLCtrl::update(float dt)
{
    //计算位置
    m_pPlayers->calcPos(dt);
    
    //显示位置
    QFLVec vecPos = m_pPlayers->getPos();   //这里要进行一个坐标转换（在Box2d中，物理世界变长10m以内动作计算有进行优化）
    cocos2d::Vec2 vecShowPos = Vec2(vecPos.fX * WORLD_RATIO, vecPos.fY * WORLD_RATIO);
    
    m_pView->updatePlayerPos(vecShowPos);
    
    //注意，其实更换一种显示方式（控制台log），我们不需要改变Mode
    //log("Pos:%f,%f \t Vel-Y:%f", it->getPos().fX, it->getPos().fY, it->getVelocity().fY);

}






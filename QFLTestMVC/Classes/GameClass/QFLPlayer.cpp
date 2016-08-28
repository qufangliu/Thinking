//
//  QFLPlayer.cpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/27.
//
//

#include "QFLPlayer.hpp"
#include "QFLCtrl.hpp"

#include <iostream>

#define DYNAMIC_VELO        0.05

using namespace QFLBase;

QFLPlayer::QFLPlayer()
{
    m_sPos = QFLVec::ZERO;
    m_sVelocity = QFLVec::ZERO;
    m_sAcceleration = QFLVec::ZERO;
    m_fElasticity = 1.0f;
    m_fGroundHeight = 0.0f;
}

QFLPlayer::~QFLPlayer()
{
    
}

void QFLPlayer::calcPos(float dt)
{
    //加速度不用管
    //计算当前帧速度
    QFLVec nowVel = m_sVelocity + m_sAcceleration * dt;
    //更新Pos
    m_sPos = m_sPos + (nowVel + m_sVelocity) * dt * 0.5;
    //保存速度
    m_sVelocity = nowVel;
    
    //向上反弹
    if (m_sPos.fY <= m_fGroundHeight) {
        if (m_sVelocity.fY < 0) {
            m_sVelocity.fY *= -1 * m_fElasticity;
        }
        else {}
    }
    else {}
}


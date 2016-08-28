//
//  QFLPlayer.hpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/27.
//
//

#ifndef QFLPlayer_hpp
#define QFLPlayer_hpp

#include <stdio.h>
#include "QFLBase.h"

//玩家类
class QFLPlayer
{
public:
    QFLPlayer();
    virtual ~QFLPlayer();
    
    //计算位置
    void calcPos(float dt);
    
    //位置
    SYNC_VALUE(QFLBase::QFLVec, m_sPos, Pos);
    //速度
    SYNC_VALUE(QFLBase::QFLVec, m_sVelocity, Velocity);
    //加速度
    SYNC_VALUE(QFLBase::QFLVec, m_sAcceleration, Acceleration);
    //弹力系数
    SYNC_VALUE(float, m_fElasticity, Elasticity);
    
    //地面高度
    SYNC_VALUE(float, m_fGroundHeight, GroundHeight);


private:
    
};

#endif /* QFLPlayer_hpp */

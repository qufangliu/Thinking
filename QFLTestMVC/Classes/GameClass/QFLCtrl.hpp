//
//  QFLCtrl.hpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/27.
//
//

#ifndef QFLCtrl_hpp
#define QFLCtrl_hpp

#include <stdio.h>
//基础工具
#include "QFLBase.h"

//Model
#include "QFLPlayer.hpp"

//View
#include "QFLView.hpp"

class QFLCtrl
{
public:
    virtual ~QFLCtrl();
    static QFLCtrl* getInstance();

public:
    //初始化操作，设定一些值，Controller入口
    void initWorld();
    
    //V和M的管理
    void addView();
    void addPlayer();
    
    //控制逻辑
    void update(float dt);
    
    //重力存取
    SYNC_VALUE(float, m_fGravity, Gravity);
    
private:
    QFLCtrl();
    
private:
    
    //Model
    QFLPlayer *m_pPlayers;
    
    //View
    QFLView *m_pView;
};

#endif /* QFLCtrl_hpp */

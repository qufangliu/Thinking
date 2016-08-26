//
//  QFLTools.hpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/26.
//
//

#ifndef QFLTools_hpp
#define QFLTools_hpp

#include <stdio.h>
#include "cocos2d.h"

class QFLTools
{
public:
    virtual ~QFLTools();
    static QFLTools* getInstance();
    
public:
    //添加不可触摸层
    void addNoTouchLayerColor(cocos2d::Node *pNode, const cocos2d::Color4B &color = cocos2d::Color4B::BLACK, int nZorder = 0);
    void removeNoTouchLayerColor(cocos2d::Node *pNode);
    
    //生成关闭菜单按钮
    cocos2d::MenuItemFont* getCloseMenuItem(cocos2d::Node *pNode);
    
private:
    QFLTools();
};

#endif /* QFLTools_hpp */

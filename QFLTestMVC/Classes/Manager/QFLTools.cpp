//
//  QFLTools.cpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/26.
//
//

#include "QFLTools.hpp"

USING_NS_CC;

#define NAME_NO_TOUCH_LAYER_COLOR   "NoTouchLayerColor" //触摸屏蔽颜色层的Name

static QFLTools *m_pInstance = nullptr;

QFLTools::QFLTools()
{
    
}

QFLTools::~QFLTools()
{
    
}

QFLTools* QFLTools::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new (std::nothrow)QFLTools();
    }
    else {}
    
    return m_pInstance;
}

void QFLTools::addNoTouchLayerColor(cocos2d::Node *pNode, const cocos2d::Color4B &color, int nZorder)
{
    //LayerColor
    auto pLayer = LayerColor::create(color);
    pLayer->setName(NAME_NO_TOUCH_LAYER_COLOR);
    pNode->addChild(pLayer, nZorder);
    
    //TouchListener
    auto pListener = EventListenerTouchOneByOne::create();
    pListener->setSwallowTouches(true);
    pListener->onTouchBegan = [=](cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
        return true;
    };
    
    //注意：这个触摸屏蔽监听是加载LayerColor上的
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pListener, pLayer);
}

void QFLTools::removeNoTouchLayerColor(cocos2d::Node *pNode)
{
    auto pLayer = pNode->getChildByName(NAME_NO_TOUCH_LAYER_COLOR);
    if (pLayer) {
        pLayer->removeFromParentAndCleanup(true);
    }
    else {}
}


cocos2d::MenuItemFont* QFLTools::getCloseMenuItem(cocos2d::Node *pNode)
{
    auto sizeScreen = Director::getInstance()->getVisibleSize();
    
    auto pItem = MenuItemFont::create("-Close-", [=](Ref *pRef){
        pNode->removeFromParentAndCleanup(true);
    });
    pItem->setPosition(Vec2(sizeScreen.width - pItem->getContentSize().width * 0.5 - 7, pItem->getContentSize().height * 0.5 + 7));
    
    return pItem;
}


//
//  Intermediary.cpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/2.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

#include "Intermediary.hpp"

SoundHelper::SoundHelper()
{
    
}

SoundHelper::~SoundHelper()
{
    
}

SoundHelper* SoundHelper::getInstance()
{
    if (!m_pInstanceSound) {
        m_pInstanceSound = new SoundHelper();
    }
    return m_pInstanceSound;
}

/*
 这里省略SoundHelper的部分方法的实现
 */



std::vector<std::string> StringTool::divideString(const std::string &strInfo, const std::string &strInterval)
{
    std::vector<std::string> vectorSubString;
    //省略实现部分
    return vectorSubString;
}



Intermediary::Intermediary()
{
    
}

Intermediary::~Intermediary()
{
    
}

Intermediary* Intermediary::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new Intermediary();
    }
    return m_pInstance;
}

std::vector<std::string> Intermediary::divideString(const std::string &strInfo, const std::string &strInterval)
{
    return StringTool::divideString(strInfo, strInterval);
}

SoundHelper* Intermediary::getSoundHelper()
{
    return SoundHelper::getInstance();
}


















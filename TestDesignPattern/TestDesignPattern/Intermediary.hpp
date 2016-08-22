//
//  Intermediary.hpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/2.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

/*
 简要说明
 
    中介模式
 
    中介模式就是对其他类进行封装，开放对应的功能接口，对用户屏蔽细节的模式。中介模式可以包含两种中介方式，一是直接提供功能对象，二是封装各个功能接口。
 
    注意:
        1.使用中介模式封装众多类，可能导致中介类变得庞大而且难以管理。
        2.中介模式屏蔽了接口实现细节，使得用户面对的接口来自于一个类，方便用户的管理。
        3.中介模式一般使用单例模式来实现。
        4.多个单例类，可以通过一个单例中介类来管理，减少了用户需要管理的单例数量。
 */

#ifndef Intermediary_hpp
#define Intermediary_hpp

#include <stdio.h>
#include <string>
#include <vector>

//音乐播放类
class SoundHelper
{
public:
    static SoundHelper* getInstance();
    
    void loadSound(const std::string &strFilePath);
    void removeSound(const std::string &strName);
    
    
    void playSound(const std::string &strName);
    void stopSound(const std::string &strName);
    
private:
    SoundHelper();
    ~SoundHelper();
    
private:
    static SoundHelper* m_pInstanceSound;
};

//工具类
class StringTool
{
public:
    static std::vector<std::string> divideString(const std::string &strInfo, const std::string &strInterval);

};

//中介类，集中交互和控制，用户只需要和这一个类打交道就行
class Intermediary
{
public:
    static Intermediary* getInstance();
    
    //封装接口的方式，这也是一种委托
    std::vector<std::string> divideString(const std::string &strInfo, const std::string &strInterval);
    
    //提供对象的方式
    SoundHelper* getSoundHelper();
    
private:
    Intermediary();
    ~Intermediary();
    
    bool init();
    
private:
    static Intermediary* m_pInstance;
};

#endif /* Intermediary_hpp */

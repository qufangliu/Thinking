//
//  Manager.hpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/1.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

/*
 简要说明
 
    管理者模式
 
    管理者模式一般通过单例模式来实现，它通常使用<key,value>的形式来管理其它对象。
 
    注意:
        1.尽量避免使用这个模式，因为它来自于单例模式，包涵了单例模式的优缺点。
        2.对于某些运行时创建开销非常大，而又经常需要重复使用时，可以预先创建这些对象，然后使用一个管理类来进行对象的管理。
        3.该模式包涵了单例模式、工厂模式、外观模式的思想。
 */


#ifndef Manager_hpp
#define Manager_hpp

#include <stdio.h>
#include <string>
#include <map>

class Manager
{
public:
    static Manager* getInstance();
    
    void pushObject(const std::string &strKey, int pObject);
    int getObjectByKey(const std::string &strKey);
    
private:
    Manager();
    ~Manager();
    
private:
    static Manager* m_pInstance;
    
    //这里需要一个所有类的父类，或者模板，这里用int来代替一下
    std::map<std::string, int> m_mapObjectList;
};

#endif /* Manager_hpp */

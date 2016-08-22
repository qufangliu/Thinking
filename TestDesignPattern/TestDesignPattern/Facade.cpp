//
//  Facade.cpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/1.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

#include "Facade.hpp"

Computer::Computer()
{
    cpu = new CPU();
    memory = new Memory();
    hardDrive = new HardDrive();
}

void Computer::starComputer()
{
    cpu->freeze();
    memory->load(1001, hardDrive->read(2, 1));
    cpu->jump(1001);
    cpu->execute();
}
//
//  Defense.hpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/2.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

/*
 简要说明
 
    防御式编程模式
 
    防御式编程模式是一种使用do{...}while(0);代码来提高程序质量的编程方式，不是真正意义上的模式。
 
    优缺点:
        1.如果一个函数中多处需要分配资源（可能异常），然后做其他处理。这里用do{...}while(0);可以简化try...catch()结构。
        2.在宏定义中，使用do{...}while(0);可以使得宏用起来就像一个普通的语句。避免了一些隐藏的bug。
        3.使用do{...}while(0);可以提高代码的稳定性健壮性。防止子程序收到非法数据时出现难以察觉的异常。
        4.在所有的地方检查参数，这种过度防御编程会使得程序缓慢。而且使用do{...}while{0};可能导致程序更加复杂。
 */

#ifndef Defense_hpp
#define Defense_hpp

#include <stdio.h>

class Defense
{
public:
    static Defense* create();
    
    bool execute();
};


#endif /* Defense_hpp */

//宏定义中的使用
#define TOOL(var) \
        var++;  \
        var *= -1;
/*
 如果使用了:
    if (a>1) TOOL(10);
    else TOOL(5);
 这样就会导致编译错误（这种情况在编写库文件的时候尤其要注意），因为宏TOOL不是一个单独的语句。
 */

#define TOOL2(var)  \
        do{         \
        var++;      \
        var *= -1;  \
        }while(0)   \
/*
    此时，宏TOOL2对于用户来说，相当于一条普通的语句，而且要求语句后必须加';'以防止错误。
*/





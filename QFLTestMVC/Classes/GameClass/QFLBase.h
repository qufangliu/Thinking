//
//  QFLBase.h
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/27.
//
//

#ifndef QFLBase_h
#define QFLBase_h

//MARK:宏定义

//getter setter
#define SYNC_VALUE(T,NAME,FUNC)                     \
protected: T NAME;                                  \
public: virtual T get##FUNC() { return NAME; }      \
public: virtual void set##FUNC(T X) { NAME = X; }

namespace QFLBase {

    //MARK:结构体
    
    //向量结构体
    struct QFLVec {
        float fX;
        float fY;
    public:
        QFLVec()
        {
            fX = 0.0f;
            fY = 0.0f;
        }
        
        QFLVec(float x, float y)
        {
            fX = x;
            fY = y;
        }
        
        //注意这里的友元函数
        friend QFLVec operator+(QFLVec v1, QFLVec v2)
        {
            QFLVec tmpV;
            tmpV.fX = v1.fX + v2.fX;
            tmpV.fY = v1.fY + v2.fY;
            return tmpV;
        }
        friend QFLVec operator-(QFLVec v1, QFLVec v2)
        {
            QFLVec tmpV;
            tmpV.fX = v1.fX - v2.fX;
            tmpV.fY = v1.fY - v2.fY;
            return tmpV;
        }
        friend QFLVec operator*(QFLVec v, float f)
        {
            QFLVec tmpV;
            tmpV.fX = v.fX * f;
            tmpV.fY = v.fY * f;
            return tmpV;
        }
        friend QFLVec operator*(float f, QFLVec v)
        {
            QFLVec tmpV;
            tmpV.fX = v.fX * f;
            tmpV.fY = v.fY * f;
            return tmpV;
        }
        friend QFLVec operator/(QFLVec v, float f)
        {
            QFLVec tmpV;
            tmpV.fX = v.fX / f;
            tmpV.fY = v.fY / f;
            return tmpV;
        }
        friend QFLVec operator/(float f, QFLVec v)
        {
            QFLVec tmpV;
            tmpV.fX = v.fX / f;
            tmpV.fY = v.fY / f;
            return tmpV;
        }

        friend bool operator==(QFLVec v1, QFLVec v2)
        {
            return (v1.fX == v2.fX && v1.fY == v2.fY);
        }
        
//        QFLVec& operator+(QFLVec v)
//        {
//            fX += v.fX;
//            fY += v.fY;
//            return *this;
//        }
//        QFLVec& operator-(QFLVec v)
//        {
//            fX -= v.fX;
//            fY -= v.fY;
//            return *this;
//        }
        QFLVec& operator=(QFLVec v)
        {
            fX = v.fX;
            fY = v.fY;
            return *this;
        }
//        QFLVec& operator*(float f)
//        {
//            fX = fX * f;
//            fY = fY * f;
//            return *this;
//        }
//        QFLVec& operator/(float f)
//        {
//            fX = fX / f;
//            fY = fY / f;
//            return *this;
//        }
        
        //static const member
        static const QFLVec ZERO;
    };
    
    
}


#endif /* QFLBase_h */

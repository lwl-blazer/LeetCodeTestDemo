//
//  main.cpp
//  TESTCPlus
//
//  Created by 开心粮票 on 2018/8/31.
//  Copyright © 2018年 eeee. All rights reserved.
//

#include <iostream>
#include <stdlib.h>


using namespace std;

class Father {
    public:
    void Face(){
        cout<<"father's face"<<endl;
    }

   virtual void Say(){
        cout << "father say hello" << endl;
    }
};


class Son: public Father{
    public:
    void Say(){
        cout << "Son say Hello" << endl;
    }
};

/**
 C++的多态:
  1. 在基类的函数加上virtural关键字， 在派生类中重写该函数，运行时将会根据对象的实际类型来调用相应的函数
  2. 存在虚函数的类都有一个一维的虚函数表叫虚表    类的对象有一个指向虚表开始的虚指针， 虚表是和类对应的，虚表指针是和对象对应的
 注意:
   C++编译器在编译的时候，要确定每个对象调用函数(非虚表函数)的地址，这称为早期绑定，

   C++在编译的时候如果发现类中存在虚函数，这个时候C++就会采用晚绑定技术(也就是说在编译的时并不确定具体调用的函数，而是在运行时，依据对象的类型来确认调用哪一个函数)
 继承的时候构造:
   构造Son类的对象时，首先要调用Father类的构造函数去构造Father类的对象，然后才调用Son类的构造函数完成自身的部分的构造
 */

int main(int argc, const char * argv[]) {

    Son son;
    Father *pFather = &son;   //没有加virtual的时候，进行了类型转换，pFather实际保存的是Father对象的地址
    pFather->Say();    //有虚函数 和没有的虚函数的区别

    return 0;
}

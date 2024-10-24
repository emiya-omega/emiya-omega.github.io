---
title : '构造函数－成员列表－析构函数－对象数组和对象指针'
date : 2024-04-18T16:06:55Z
tags: ["CPP"]
categories: ["学习笔记"]
draft : false
---
# 类的构造函数和析构函数
## 构造函数
- 构造函数的名字必须与类名相同，且不能有返回参数
```
class Complex{
Private:
    double real;
    double imag;
Public:
    Complex(double r,double i)
    {real=r;imag=i;}
};
```
- 定义对象时，编译系统会自动调用构造函数~~（初始化）~~
- 与普通成员函数一样，可以定义在体内也可以定义在体外
- 构造函数的**主要作用是对对象进行初始化**
- 构造函数一般声明为公有成员，但不能像其他成员一样被显式调用*它在定义对象的同时被调用，且只调用一次*
- 在实际应用中有通常要为每一个类定义构造函数
- 构造函数可以不带参数
- 构造函数可以重载
## 用成员初始化列表对数据成员初始化
- 一般表达形式
```
类名::构造函数名([参数表])[:(成员初始化列表)]
{//构造函数体}
```
- 成员初始化列表一般形式
> 数据成员1(初始值1),数据成员2(初始值2),.....
## 析构函数
1. 定义
    - 是一种特殊的成员函数，与构造函数功能相反，它用来释放对象，即当删除对象前，回收储存空间并进行一些清理工作
2. 性质
    - 析构函数名称与类名相同，但它名称前面必须要加一个～
    - 析构函数没有返回值，也没有参数
    - 当对象生命周期结束时，编译系统会自动调用析构函数
    - 析构函数不能重载
## 对象数组
- 指每一数组元素都是对象的数组
- 定义形式
```
类名 数组名 [下标表达式]
Complex com[10]
```
- 有几个数组元素就要调用几次构造函数
- 如果构造函数只有一个参数，在定义对象数组时可以直接在等号后面的花括号内提供实参
- 使用格式
```
数组名[下标].成员名
```
- 当类中有多个参数的构造函数时，则必须使用如下的形式进行对象数组的初始化
```
Complex com[3]={ //定义对象数组com
Complex(1.1,2.2),//为第一个对象数组元素提供实参
Complex(3.3,4,4),//为第二个对象数组元素提供实参
Complex(5.5,6.6)//为第三个对象数组元素提供实参
};
``` 
## 对象指针
- 在CPP中，可以直接引用对象，也可通过指向该对象的指针引用对象
```
exe ob; //定义类exe的对象ob
exe *p; //定义指向类exe的对象指针p
P=&ob;//将对象ob的地址赋给对象指针p
```
- 用对象指针访问对象数组
```
exe ob[2];//定义类exe的对象数组ob[2]
exe *p;//定义指向类exe的对象指针p
//数组名代表第一个元素的地址  
P=ob; //将对象数组ob的地址赋给对象指针p
```
## this指针
- 在每个对象的数据成员中都有一个系统隐含的指针this
- 这个指针this的类型为这个对象所属类的类型
- 这个指针this的值为包含它的那个对象的首地址

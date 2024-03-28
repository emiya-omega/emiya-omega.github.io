+++
title = 'CPP特点 输出长度与精度控制 指针与常量'
date = 2024-03-28T19:50:14+08:00
draft = true
+++
## 面向对象语言特点
- 抽象
1. 类 -> 抽象
2. 对象 -> 具体
- 封装
 1. 成员变量(私)
 2. 成员函数(公)
- 继承
- 多态
#### cpp向下兼容c语言
#### cpp中不允许/**/嵌套使用
#### `cout<<_LINE_<<~~;`
- 显示该语句位于源程序第几行
#### 通常只有规模很小(一般为1~5条语句)而频繁使用函数才定义为内联函数
### 输出长度与精度控制
```
#include <iomainip> //std::setw
cout<<setw(10);限制输出长度为10
cout<<setprecision(5)<<~;//限制输出精度
cout<<fixed;//用定点数表示法表示浮点数

```
#### cpp中函数可以重载.只要函数参数的类型不同,or参数的个数不同,或者二者兼而有之,两个or两个以上的函数可以使用相同的函数名
## 指针与常量
#### 指向常量的指针
`const char *name ="chen";`
1. *name 是常量(name不允许改变)
`name[3]='a' ;` is ERROR
2. name是指向常量的指针变量(指针name本身可以改变)
`name ="zhang";` is RIGHT
#### 指向字符串的常指针
`char* const name ="chen";`
1. name是常量(name不允许改变)
2. 指针的地址不允许改变
`name = "zhang"` is ERROR
#### 指向常量的常指针
`const char* const name ="chen";`

---
title : 'string类-向函数传递对象-对象赋值语句-拷贝构造函数'
date : 2024-04-24T02:17:46Z
tags: ["CPP"]
categories: ["学习笔记"]
draft : false
---
## string类
- string类的字符串对象的使用方法与其他对象一样，但必须先定义才可使用
- 定义格式
```
string str1,str2;
string
str3("china");
等价于
string str3="china";
```
## 向函数传递对象
### 使用对象作为函数参数
- 向函数传递对象时,是通过"传值调用"传递给函数
- 因此,函数中对对象任何修改均不影响调用该函数对象的本身
```
#include <iostream>
class Tr{
public:
	Tr(int n){
	i=n;
	}
	void set(int n){
	i=n;
	}
	int get(){
	return i;
	}
private:
	int i;
};
void sqr(Tr ob){
	ob.set(ob.get()*ob.get());
	cout <<"在函数sqr内,形参对象ob的数据成员i的值为"<<ob.get()<<endl;
}
int main(){
	Tr obj(10);
	cout<<"调用函数sqr前,实参i值为:"<<obj.get()<<endl;
	sqr(obj);
	cout<<"调用函数sqr后,实参i值为:"<<obj.get()<<endl;
	return 0;
}
```
> output:
        调用函数sqr前,实参i值为:10
	在函数sqr内,形参对象ob的数据成员i的值为100
	调用函数sqr后,实参i的值为:10
### 使用对象指针作为函数参数
- 使用对象指针作为函数参数可以实现"传址调用",即可在被调用函数中改变调用函数的参数对象的值
```
#include <iostream>
class Tr{
public:
	Tr(int n){
	i=n;
	}
	void set(int n){
	i=n;
	}
	int get(){
	return i;
	}
private:
	int i;
};
void sqr(Tr *ob){
	ob->set(ob->get()*ob->get());
	cout <<"在函数sqr内,形参对象ob的数据成员i的值为"<<ob->get()<<endl;
}
int main(){
	Tr obj(10);
	cout<<"调用函数sqr前,实参i值为:"<<obj.get()<<endl;
        sqr(obj);
	cout<<"调用函数sqr后,实参i值为:"<<obj.get()<<endl;
        return 0;
}
```
> output:
        调用函数sqr前,实参i值为:10
        在函数sqr内,形参对象ob的数据成员i的值为100
        调用函数sqr后,实参i的值为:100
### 使用对象引用作为函数参数
- 使用对象引用作为函数参数实现的也是"传址调用",但比对象指针更简单,更直接,建议使用引用
```
#include <iostream>
class Tr{
public:
	Tr(int n){
	i=n;
	}
	void set(int n){
	i=n;
	}
	int get(){
	return i;
	}
private:
	int i;
};
void sqr(Tr &ob){
	ob.set(ob.get()*ob.get());
	cout <<"在函数sqr内,形参对象ob的数据成员i的值为"<<ob.get()<<endl;
}
int main(){
	Tr obj(10);
	cout<<"调用函数sqr前,实参i值为:"<<obj.get()<<endl;
	sqr(obj);
	cout<<"调用函数sqr后,实参i值为:"<<obj.get()<<endl;
	return 0;
}
```
> output:
        调用函数sqr前,实参i值为:10
	在函数sqr内,形参对象ob的数据成员i的值为100
	调用函数sqr后,实参i的值为:100
## 对象赋值语句
- A和B是同一类的两个对象,那么下述对象赋值语句,就能把对象A的数据成员的值逐位复制给对象B
```
B=A;
```
## 拷贝构造函数
### 调用拷贝构造函数的形式
1. 代入法
```
类名 对象2(对象1)
如: Point p2(p1);
```
2. 赋值法
```
对象2=对象1;
如:Point p2=p1;
```
### 缺省拷贝构造函数
- 如果没有编写自定义的拷贝构造函数,C P P会自动地将一个已存在的对象复制给新对象
- 这种按成员逐一复制的过程是由缺省拷贝构造函数自动完成的
### 调用构造函数的3种情况
1. 当用类的一个对象去初始化该类的另一个对象时,拷贝构造函数将会被调用
```
如:
Point p2(p1);
Point p2=p1;
```
2. 当函数的形参是类的对象,在调用函数进行形参和实参结合时,拷贝函数将会被调用
```
void fun1(Point p)
{
	p.print();
}
int main()
{
	Point p1(10,20);
	fun1(p1);
	return 0;
}
```
3. 当函数的返回值是类的对象,在函数调用完毕将返回值(对象)带回函数调用处时,此时就会调用拷贝构造函数,将此对象复制给一个临时对象并传到该函数的调用处
```
Point fun2()
{
	Point p1(10,30);
	return p1;
}
int main()
{
	Point p2;
	p2 = fun2();
	return 0;
}
```



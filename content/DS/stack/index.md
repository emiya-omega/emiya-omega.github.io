---
title : '栈和队列'
date : 2024-10-21T08:51:59Z
tags: ["DS"]
categories: ["学习笔记"]
draft : false
---
# 栈

## 栈的介绍

栈是一种先进后出的数据结构，它只允许在一端进行插入和删除操作。栈的基本操作包括压栈（push）、弹栈（pop）和查看栈顶元素（top）。

## 栈的实现

栈可以使用数组或链表来实现。以下是使用数组实现栈的示例代码：

```cpp
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // 栈的最大容量

class Stack {
private:
    int data[MAX_SIZE]; // 存储栈元素的数组
    int top; // 栈顶指针
public:
    Stack() {
        top = -1; // 初始化栈顶指针为-1
    }

    bool isEmpty() {
        return top == -1; // 栈为空时，top为-1
    }

    bool isFull() {
        
        return top == MAX_SIZE - 1; // 栈满时，top等于MAX_SIZE-1
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push element." << endl;
            return;
        }
        data[++top] = value; // 将元素压入栈顶
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return -1;
        }
        return data[top--]; // 弹出栈顶元素
    }

    int topElement() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot get top element." << endl;
            return -1;
        }
        return data[top]; // 返回栈顶元素
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element: " << stack.topElement() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element: " << stack.topElement() << endl;
    return 0;

    }
```
## 栈的应用

栈在计算机科学中有很多应用，例如：

- 表达式求值：栈可以用来计算表达式的值。例如，对于表达式“3 + 4 * 2”，可以使用栈来存储操作数和运算符，然后按照运算符的优先级进行计算。
- 函数调用：在函数调用时，系统会将函数的返回地址、参数和局部变量等信息压入栈中，以便在函数返回时能够正确地恢复现场。
- 回溯算法：栈可以用来实现回溯算法，例如在迷宫问题中，可以使用栈来记录已经走过的路径，以便在遇到死路时能够回溯到上一个路口。
- 递归：递归函数的实现过程中，系统会将每次递归调用的返回地址和参数等信息压入栈中，以便在递归返回时能够正确地恢复现场。

# 队列
队列是一种先进先出的数据结构，它只允许在一端进行插入操作，在另一端进行删除操作。队列的基本操作包括入队（enqueue）、出队（dequeue）和查看队首元素（front）。

## 队列的实现

队列可以使用数组或链表来实现。以下是使用数组实现队列的示例代码：

```cpp
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // 队列的最大容量

class Queue {
private:
    int data[MAX_SIZE]; // 存储队列元素的数组
    int front; // 队首指针
    int rear; // 队尾指针
public:
    Queue() {
        front = -1; // 初始化队首指针为-1
        rear = -1; // 初始化队尾指针为-1
    }

    bool isEmpty() {
        
        return front == -1; // 队列为空时，front和rear都为-1
    }

    bool isFull() {
        return rear == MAX_SIZE - 1; // 队满时，rear等于MAX_SIZE-1
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue element." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // 队列为空时，将队首指针指向0
        }
    }
    rear++; // 队尾指针加1
        data[rear] = value; // 将元素插入队尾
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return -1;
        }
        int value = data[front]; // 获取队首元素
        if (front == rear) { // 队列中只有一个元素时，出队后队列为空
            front = -1; // 将队首指针和队尾指针都置为-1
        } else {
            front++; // 队首指针加1
        }
        return value;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot get front element." << endl;
            return -1;
        }
        return data[front]; // 返回队首元素
    }
};

int main() {
            
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << "Front element: " << queue.frontElement() << endl;
    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Front element: " << queue.frontElement() << endl;
    return 0;
}
```
## 循环队列
循环队列是一种特殊的队列，它的队首和队尾可以连接起来形成一个环。循环队列的基本操作包括入队（enqueue）、出队（dequeue）和查看队首元素（front）。

以下是使用数组实现循环队列的示例代码：

```cpp
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // 队列的最大容量

class CircularQueue {
private:
    int data[MAX_SIZE]; // 存储队列元素的数组
    int front; // 队首指针
    int rear; // 队尾指针
public:
    CircularQueue() {
        front = -1; // 初始化队首指针为-1
        rear = -1; // 初始化队尾指针为-1
    }

    bool isEmpty() {
        return front == -1; // 队列为空时，front和rear都为-1
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front; // 队满时，(rear+1)%MAX_SIZE等于front
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue element." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // 队列为空时，将队首指针指向0
        }
        rear = (rear + 1) % MAX_SIZE; // 队尾指针加1，并取模MAX_SIZE，形成循环
    }
    data[rear] = value; // 将元素插入队尾
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return -1;
        }
        int value = data[front]; // 获取队首元素
        if (front == rear) { // 队列中只有一个元素时，出队后队列为空
            front = -1; // 将队首指针和队尾指针都置为-1
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE; // 队首指针加1，并取模MAX_SIZE，形成循环
        }
        return value;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot get front element." << endl;
            return -1;
        }
        return data[front]; // 返回队首元素
    }
};

int main() {

    CircularQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << "Front element: " << queue.frontElement() << endl;
    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Front element: " << queue.frontElement() << endl;
    return 0;
}
```
## 链式队列
链式队列是一种使用链表实现的队列，它的基本操作包括入队（enqueue）、出队（dequeue）和查看队首元素（front）。

以下是使用链表实现链式队列的示例代码：

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedQueue {
private:
    Node* front; // 队首指针
    Node* rear; // 队尾指针
public:
    LinkedQueue() {
        front = nullptr; // 初始化队首指针为nullptr
        rear = nullptr; // 初始化队尾指针为nullptr
    }

    bool isEmpty() {
        return front == nullptr; // 队列为空时，front和rear都为nullptr
    }
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode; // 队列为空时，将队首指针指向新节点
        } else {
            rear->next = newNode; // 队列不为空时，将队尾指针的next指向新节点
        }
        rear = newNode; // 更新队尾指针为新节点
    }

    int dequeue() {
        if (isEmpty()) {
        
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return -1;
        }
        int value = front->data; // 获取队首元素
        Node* temp = front; // 保存队首节点
        front = front->next; // 更新队首指针为下一个节点
        delete temp; // 释放队首节点
        if (front == nullptr) {
            rear = nullptr; // 队列为空时，将队尾指针置为nullptr
        }
        return value;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot get front element." << endl;
            return -1;
        }
        return front->data; // 返回队首元素
    }
};

int main() {

    LinkedQueue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << "Front element: " << queue.frontElement() << endl;
    cout << "Dequeued element: " << queue.dequeue() << endl;
    cout << "Front element: " << queue.frontElement() << endl;
    return 0;
}

```        
        
#pragma once
// 栈的动态分配版本
#include <iostream>
#include <assert.h>

template <typename T>
class DynamicStack {
public:
    DynamicStack() : cur(-1) {}
    ~DynamicStack() { 
        // 析构时释放内存
        std::cout << "DynamicStack is destroyed" << std::endl;
        delete[] data; 
    }
    bool isEmpty() const { return cur < 0; }// 栈是否为空
    bool isFull() const { return cur == maxSize - 1; }// 栈是否已满
    void push(const T& x);
    void pop();
    const T& top() const;// 返回栈顶元素
    int size() const;// 栈大小
private:
    void resize(int newSize);
    int cur;
    int maxSize = 2;
    T* data = new T[maxSize];
};

template<typename T>
void DynamicStack<T>::push(const T& x) {
    if (isFull()) {
        resize(maxSize * 2);
    }
    data[++cur] = x;
}

template<typename T>
void DynamicStack<T>::pop() {
    if (isEmpty()) {
        std::cerr << "Stack is empty" << std::endl;
        //throw "Stack is empty";
        return;
    }
    --cur;
}

template<typename T>
const T& DynamicStack<T>::top() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty" << std::endl;
        //throw "Stack is empty";
        return T();
    }
    return data[cur];
}

template<typename T>
void DynamicStack<T>::resize(int newSize) {
    T* newData = new T[newSize];
    assert(newSize > cur);
    for (int i = 0; i <= cur; i++) {
        newData[i] = data[i];
    }
    delete[] data;// 释放原内存
    data = newData;
    maxSize = newSize;
}

template<typename T>
int DynamicStack<T>::size() const {
    return cur + 1;
}
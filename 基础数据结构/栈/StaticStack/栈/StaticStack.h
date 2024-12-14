#ifndef STATICSTACK_H
#define STATICSTACK_H

#include <iostream>

template <typename T>
class StaticStack {
public:
    StaticStack(int capacity);
    ~StaticStack();
    void push(T value);
    T pop();
    int size() const;
    bool isFull() const;
    bool isEmpty() const;
    T top() const;

private:
    T* data;
    int capacity;
    int currentSize;
};

// 成员函数定义
template <typename T>
StaticStack<T>::StaticStack(int capacity) : capacity(capacity), currentSize(0) {
    data = new T[capacity];
}

template <typename T>
StaticStack<T>::~StaticStack() {
    std::cout << "StaticStack is being destroyed" << std::endl;
    delete[] data;
}

template <typename T>
void StaticStack<T>::push(T value) {
    if (currentSize < capacity) {
        data[currentSize++] = value;
    }
    else {
        std::cerr << "栈已满，无法添加元素" << std::endl;
    }
}

template <typename T>
T StaticStack<T>::pop() {
    if (currentSize > 0) {
        return data[--currentSize];
    }
    else {
        std::cerr << "栈为空，无法弹出元素" << std::endl;
        return T(); // 返回默认值
    }
}

template <typename T>
int StaticStack<T>::size() const {
    return currentSize;
}

template <typename T>
bool StaticStack<T>::isFull() const {
    return currentSize == capacity;
}

template <typename T>
bool StaticStack<T>::isEmpty() const {
    return currentSize == 0;
}

template <typename T>
T StaticStack<T>::top() const {
    if (currentSize > 0) {
        return data[currentSize - 1];
    }
    else {
        std::cerr << "栈为空，没有栈顶元素" << std::endl;
        return T(); // 返回默认值
    }
}

#endif // STATICSTACK_H

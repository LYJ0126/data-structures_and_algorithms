#include <iostream>
#include "StaticStack.h"
using namespace std;

int main()
{
    StaticStack<int> stack(10); // 栈大小为10
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    //查看栈大小
    cout << "栈大小：" << stack.size() << std::endl;
    stack.push(8);
    stack.push(9);
    stack.push(10);
    //查看栈是否满
    cout << "栈是否满：" << stack.isFull() << std::endl;
    //查看栈是否空
    cout << "栈是否空：" << stack.isEmpty() << std::endl;
    //查看栈顶元素
    cout << "栈顶元素：" << stack.top() << std::endl;
    stack.push(11); // 栈满溢出
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    //查看栈大小
    cout << "栈大小：" << stack.size() << std::endl;
    stack.pop();
    stack.pop();
    //查看栈是否满
    cout << "栈是否满：" << stack.isFull() << std::endl;
    //查看栈是否空
    cout << "栈是否空：" << stack.isEmpty() << std::endl;
    //查看栈顶元素
    cout << "栈顶元素：" << stack.top() << std::endl;
    stack.pop(); // 栈空溢出
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    //查看栈大小
    cout << "栈大小：" << stack.size() << std::endl;
    stack.pop();
    //查看栈是否满
    cout << "栈是否满：" << stack.isFull() << std::endl;
    //查看栈是否空
    cout << "栈是否空：" << stack.isEmpty() << std::endl;
    //查看栈顶元素
    cout << "栈顶元素：" << stack.top() << std::endl;
    return 0;
}
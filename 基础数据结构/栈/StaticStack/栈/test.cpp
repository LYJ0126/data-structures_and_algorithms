#include <iostream>
#include "StaticStack.h"
using namespace std;

int main()
{
    StaticStack<int> stack(10); // ջ��СΪ10
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    //�鿴ջ��С
    cout << "ջ��С��" << stack.size() << std::endl;
    stack.push(8);
    stack.push(9);
    stack.push(10);
    //�鿴ջ�Ƿ���
    cout << "ջ�Ƿ�����" << stack.isFull() << std::endl;
    //�鿴ջ�Ƿ��
    cout << "ջ�Ƿ�գ�" << stack.isEmpty() << std::endl;
    //�鿴ջ��Ԫ��
    cout << "ջ��Ԫ�أ�" << stack.top() << std::endl;
    stack.push(11); // ջ�����
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    //�鿴ջ��С
    cout << "ջ��С��" << stack.size() << std::endl;
    stack.pop();
    stack.pop();
    //�鿴ջ�Ƿ���
    cout << "ջ�Ƿ�����" << stack.isFull() << std::endl;
    //�鿴ջ�Ƿ��
    cout << "ջ�Ƿ�գ�" << stack.isEmpty() << std::endl;
    //�鿴ջ��Ԫ��
    cout << "ջ��Ԫ�أ�" << stack.top() << std::endl;
    stack.pop(); // ջ�����
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    //�鿴ջ��С
    cout << "ջ��С��" << stack.size() << std::endl;
    stack.pop();
    //�鿴ջ�Ƿ���
    cout << "ջ�Ƿ�����" << stack.isFull() << std::endl;
    //�鿴ջ�Ƿ��
    cout << "ջ�Ƿ�գ�" << stack.isEmpty() << std::endl;
    //�鿴ջ��Ԫ��
    cout << "ջ��Ԫ�أ�" << stack.top() << std::endl;
    return 0;
}
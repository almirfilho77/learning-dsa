#include <iostream>

#include "SLNode.hpp"

template <class Ty>
class Stack
{
public:
    Stack(Ty value);
    ~Stack();

    void Push(Ty value);
    Ty Pop();

    inline int GetHeight() const { return m_height; }

    void Print();

private:
    SingleLinked::Node<Ty> *m_top = nullptr;
    int m_height;
};

template <class Ty>
Stack<Ty>::Stack(Ty value)
{
    m_top = new SingleLinked::Node<Ty>(value);
    m_height = 1;
}

template <class Ty>
Stack<Ty>::~Stack()
{
    auto temp = m_top;
    while(temp)
    {
        m_top = temp->next;
        delete temp;
        temp = m_top;
    }
}

template <class Ty>
void Stack<Ty>::Push(Ty value)
{
    auto newNode = new SingleLinked::Node<Ty>(value);
    newNode->next = m_top;
    m_top = newNode;
    m_height++;
}

template <class Ty>
Ty Stack<Ty>::Pop()
{
    if (m_height == 0)
    {
        throw std::runtime_error("The stack is empty");
    }
    auto temp = m_top;
    m_top = m_top->next;
    m_height--;
    return temp->value;
}

template <>
std::string Stack<std::string>::Pop()
{
    if (m_height == 0)
    {
        return "";
    }
    auto temp = m_top;
    m_top = m_top->next;
    m_height--;
    return temp->value;
}

template <>
int Stack<int>::Pop()
{
    if (m_height == 0)
    {
        return INT32_MIN;
    }
    auto temp = m_top;
    m_top = m_top->next;
    m_height--;
    return temp->value;
}

template <class Ty>
void Stack<Ty>::Print()
{
    auto temp = m_top;
    while(temp)
    {
        std::cout << temp->value << '\n';
        temp = temp->next;
    }
}
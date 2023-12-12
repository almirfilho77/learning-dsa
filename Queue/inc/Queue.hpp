#include <iostream>

#include "LinkedList.hpp"

template <class Ty>
class Queue
{
public:
    Queue(Ty value);
    ~Queue() {};

    void Enqueue(Ty value);
    Ty Dequeue();

    inline int GetLength() const { return m_length; }

    void Print();

private:
    SingleLinked::Node<Ty> *m_first = nullptr;
    SingleLinked::Node<Ty> *m_last = nullptr;
    int m_length;
};

template <class Ty>
Queue<Ty>::Queue(Ty value)
{
    m_first = m_last = new SingleLinked::Node<Ty>(value);
    m_length = 1;
}

template <class Ty>
void Queue<Ty>::Enqueue(Ty value)
{
    auto newNode = new SingleLinked::Node<Ty>(value);
    if(m_length == 0)
    {
        m_first = m_last = newNode;
    }
    else
    {
        m_last->next = newNode;
        m_last = newNode;
    }
    m_length++;
}

template <class Ty>
Ty Queue<Ty>::Dequeue()
{
    if (m_length == 0)
    {
        throw std::runtime_error("The queue is empty!");
    }

    auto temp = m_first;
    auto dequeue_val = m_first->value;
    if (m_length == 1)
    {
        m_first = m_last = nullptr;
    }
    else
    {
        m_first = m_first->next;
    }
    delete temp;
    m_length--;
    return dequeue_val;
}

template <class Ty>
void Queue<Ty>::Print()
{
    auto temp = m_first;
    while(temp)
    {
        std::cout << temp->value << '\n';
        temp = temp->next;
    }
}
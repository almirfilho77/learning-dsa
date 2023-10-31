#pragma once

#include <iostream>

#include "Node.hpp"

template <class Ty>
class DoubleLinkedList
{
private:
    Node<Ty> *m_head;
    Node<Ty> *m_tail;
    unsigned int m_length;

public:
    DoubleLinkedList(Ty value);
    ~DoubleLinkedList();

    void Append(Ty value);
    void Prepend(Ty value);
    void PopBack();
    void PopFront();
    void Reverse();
    void PrintList() const;

    bool Insert(Ty value, int index);
    bool Delete(int index);
    bool SetNode(int index, Ty value);

    Node<Ty> *GetNode(int index);
    inline Node<Ty> *GetHead() { return m_head; }

    inline unsigned int GetLength() const { return m_length; }
};

template <class Ty>
DoubleLinkedList<Ty>::DoubleLinkedList(Ty value)
{
    Node<Ty> *newNode = new Node(value);
    m_head = newNode;
    m_tail = newNode;
    m_length = 1;
}

template <class Ty>
DoubleLinkedList<Ty>::~DoubleLinkedList()
{
    Node<Ty> *temp = m_head;
    while (m_head)
    {
        m_head = m_head->next;
        delete temp;
        temp = m_head;
    }
}

template <class Ty>
void DoubleLinkedList<Ty>::Append(Ty value)
{
    Node<Ty> *newNode = new Node(value);
    if (m_length == 0)
    {
        m_head = newNode;
        m_tail = newNode;
    }
    else
    {
        m_tail->next = newNode;
        newNode->prev = m_tail;
        m_tail = newNode;
    }
    m_length++;
}

template <class Ty>
inline void DoubleLinkedList<Ty>::PopBack()
{
    if (m_length == 0)
    {
        std::cerr << "The list is empty!\n";
        return;
    }

    Node<Ty> *temp = m_tail;
    if (m_length == 1)
    {
        m_tail = nullptr;
        m_head = nullptr;
    }
    else
    {
        m_tail = m_tail->prev;
        m_tail->next = nullptr;
    }
    delete temp;
    m_length--;
}

template <class Ty>
void DoubleLinkedList<Ty>::PrintList() const
{
    if (m_length == 0)
    {
        std::cout << "The list is empty!\n";
        return;
    }

    Node<Ty> *it = m_head;
    while(it != nullptr)
    {
        std::cout << it->value << '\n';
        it = it->next;
    }
}

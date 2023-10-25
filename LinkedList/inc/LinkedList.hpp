#pragma once

#include <iostream>

#include "Node.hpp"

template <class Ty>
class LinkedList
{
private:
    Node<Ty> *m_head;
    Node<Ty> *m_tail;
    unsigned int m_length;

public:
    LinkedList(Ty value);
    ~LinkedList();
    void Append(Ty value);
    void Prepend(Ty value);
    bool Insert(Ty value, int index);
    void PopBack();
    void PopFront();

    inline Node<Ty> *GetHead() { return m_head; }
    inline unsigned int GetLength() const { return m_length; }

    void PrintList() const;
};

template <class Ty>
LinkedList<Ty>::LinkedList(Ty value)
{
    Node<Ty> *newNode = new Node(value);
    m_head = newNode;
    m_tail = newNode;
    m_length = 1;
}

template <class Ty>
LinkedList<Ty>::~LinkedList()
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
void LinkedList<Ty>::Append(Ty value)
{
    Node<Ty> *newNode = new Node(value);
    if (m_length == 0)
    {
        m_head = newNode;
        m_tail = newNode;
        m_length = 1;
    }
    else
    {
        m_tail->next = newNode;
        m_tail = newNode;
        m_length++;
    }

}

template <class Ty>
void LinkedList<Ty>::Prepend(Ty value)
{
    Node<Ty> *newNode = new Node(value);
    if (m_length == 0)
    {
        m_head = newNode;
        m_tail = newNode;
    }
    else
    {
        newNode->next = m_head;
        m_head = newNode;
    }
    m_length++;
}

template <class Ty>
bool LinkedList<Ty>::Insert(Ty value, int index)
{
    if (index < 0)
    {
        std::cerr << "Cannot insert a node at negative index\n";
        return false;
    }

    if (index >= m_length)
    {
        std::cerr << "Invalid index... biggest valid index to add nodes is " << m_length - 1 << '\n';
        return false;
    }

    if (index == 0)
    {
        Prepend(value);
        return true;
    }

    Node<Ty> *newNode = new Node(value);
    Node<Ty> *temp = m_head;
    for (unsigned int i = 1; i < index; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    m_length++;
    return true;
}

template <class Ty>
void LinkedList<Ty>::PopBack()
{
    if (m_length == 0)
    {
        return;
    }

    if (m_length == 1)
    {
        delete m_head;
        m_tail = nullptr;
        m_head = nullptr;
        m_length = 0;
        return;
    }

    Node<Ty> *temp = m_head;
    for (unsigned int i = 1; i < m_length - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
    m_tail = temp;
    m_length--;
}

template <class Ty>
void LinkedList<Ty>::PopFront()
{
    if (m_length == 0)
    {
        return;
    }

    if (m_length == 1)
    {
        delete m_head;
        m_tail = nullptr;
        m_head = nullptr;
        m_length = 0;
        return;
    }

    Node<Ty> *temp = m_head;
    m_head = temp->next;
    delete temp;
    m_length--;
}

template <class Ty>
void LinkedList<Ty>::PrintList() const
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

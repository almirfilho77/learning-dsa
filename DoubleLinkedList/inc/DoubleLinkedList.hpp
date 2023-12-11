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
void DoubleLinkedList<Ty>::PopBack()
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
void DoubleLinkedList<Ty>::Prepend(Ty value)
{
    Node<Ty> *newNode = new Node<Ty>(value);
    if (m_length == 0)
    {
        m_head = newNode;
        m_tail = newNode;
    }
    else
    {
        newNode->next = m_head;
        m_head->prev = newNode;
        m_head = newNode;
    }
    m_length++;
}

template <class Ty>
void DoubleLinkedList<Ty>::PopFront()
{
    if (m_length == 0)
    {
        return;
    }

    Node<Ty> *temp = m_head;
    if (m_length == 1)
    {
        m_head = nullptr;
        m_tail = nullptr;
    }
    else
    {
        m_head = m_head->next;
        m_head->prev = nullptr;
    }
    delete temp;
    m_length--;
}

template <class Ty>
Node<Ty> *DoubleLinkedList<Ty>::GetNode(int index)
{
    if (index < 0 || index >= m_length)
    {
        return nullptr;
    }

    Node<Ty> *temp;
    if (index < m_length/2)
    {
        temp = m_head;
        for (int i=0; i<index; i++)
        {
            temp = temp->next;
        }
    }
    else
    {
        temp = m_tail;
        for (int i=m_length-1; i>index; i--)
        {
            temp = temp->prev;
        }
    }
    return temp;
}

template <class Ty>
bool DoubleLinkedList<Ty>::SetNode(int index, Ty value)
{
    auto temp = GetNode(index);
    if (temp == nullptr)
    {
        std::cerr << "Invalid index!\n";
        return false;
    }
    temp->value = value;
    return true;
}

template <class Ty>
bool DoubleLinkedList<Ty>::Insert(Ty value, int index)
{
    if (index < 0 || index >= m_length)
    {
        return false;
    }

    if (index == 0)
    {
        Prepend(value);
        return true;
    }

    if (index == m_length)
    {
        Append(value);
        return true;
    }

    auto before = GetNode(index-1);
    auto after = before->next;
    auto newNode = new Node(value);
    before->next = newNode;
    after->prev = newNode;
    newNode->next = after;
    newNode->prev = before;
    m_length++;
    return true;
}

template <class Ty>
bool DoubleLinkedList<Ty>::Delete(int index)
{
    auto temp = GetNode(index);
    if (temp == nullptr)
    {
        return false;
    }

    if (m_length == 1)
    {
        m_head == nullptr;
        m_tail == nullptr;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    delete temp;
    m_length--;
    return true;
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

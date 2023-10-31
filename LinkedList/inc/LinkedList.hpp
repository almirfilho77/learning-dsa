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
    }
    else
    {
        m_tail->next = newNode;
        m_tail = newNode;
    }
    m_length++;

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
    if (index < 0 || index > m_length)
    {
        std::cerr << "Invalid index!\n";
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

    Node<Ty> *newNode = new Node(value);
    Node<Ty> *temp = GetNode(index - 1);
    newNode->next = temp->next;
    temp->next = newNode;
    m_length++;
    return true;
}

template <class Ty>
bool LinkedList<Ty>::Delete(int index)
{
    if (index < 0 || index >= m_length)
    {
        std::cerr << "Invalid index!\n";
        return false;
    }

    if (index == 0)
    {
        PopFront();
        return true;
    }

    if (index == m_length - 1)
    {
        PopBack();
        return true;
    }

    Node<Ty> *temp = GetNode(index - 1);
    Node<Ty> *deletingNode = temp->next;
    temp->next = deletingNode->next;
    delete deletingNode;
    m_length--;
    return true;
}

template <class Ty>
void LinkedList<Ty>::PopBack()
{
    if (m_length == 0)
    {
        std::cerr << "The list is empty!\n";
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
Node<Ty> *LinkedList<Ty>::GetNode(int index)
{
    if (index < 0 || index >= m_length)
    {
        std::cerr << "Invalid index!\n";
        return nullptr;
    }

    Node<Ty> *temp = m_head;
    for (unsigned int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;

    /*
        I thought about doing this:

        .
        .
        .
            return nullptr;
        }

        if (index == 0) return m_head;
        if (index == m_length - 1) return m_tail;
        Node<Ty> *temp = m_head->next;
        for (unsigned int i = 1; i < index; i++)
        .
        .
        .

        But I realized that the gains would only exist for the best case and worst case,
        but for all other cases it would represent one operation more than necessary.
    */
}

template <class Ty>
bool LinkedList<Ty>::SetNode(int index, Ty value)
{
    Node<Ty> *changingNode = GetNode(index);
    if (changingNode == nullptr)
    {
        std::cerr << "Failed to set value for the selected node!\n";
        return false;
    }
    changingNode->value = value;
    return true;
}

template <class Ty>
void LinkedList<Ty>::Reverse()
{
    if (m_length == 0)
    {
        std::cerr << "The list is empty!\n";
        return;
    }

    if (m_length == 1)
    {
        std::cout << "The list has only one element!\n";
        return;
    }

    Node<Ty> *temp = m_head;
    m_head = m_tail;
    m_tail = temp;

    temp = m_tail->next;
    Node<Ty> *prev = m_tail;
    m_tail->next = nullptr;
    Node<Ty> *next = temp;
    while (temp != nullptr)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
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

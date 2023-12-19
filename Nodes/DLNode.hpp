#pragma once

namespace DoubleLinked
{

    template <class Ty>
    class Node
    {
    public:
        Ty value;
        Node *next;
        Node *prev;

    public:
        Node(Ty value);
    };

    template <class Ty>
    Node<Ty>::Node(Ty value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }

}
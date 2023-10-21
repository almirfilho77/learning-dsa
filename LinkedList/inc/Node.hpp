#pragma once

template <class Ty>
class Node
{
public:
    Ty value;
    Node *next;

public:
    Node(Ty value);
};

template <class Ty>
Node<Ty>::Node(Ty value)
{
    this->value = value;
    this->next = nullptr;
}
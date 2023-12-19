#pragma once 
#include <string>

namespace SingleLinked
{

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
    
}

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

namespace Trees
{

    template <class Ty>
    class Node
    {
    public:
        Node(Ty value)
        {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }

        ~Node()
        {
            left = nullptr;
            right = nullptr;
        }

        Ty value;
        Node<Ty> *left;
        Node<Ty> *right;
    };

}

namespace Hash
{

    class Node
    {
    public:
        Node(const std::string &key, int value)
        {
            this->key = key;
            this->value = value;
            next = nullptr;
        }

        ~Node()
        {
            next = nullptr;
        }

        std::string key;
        int value;
        Node *next;
    };

}
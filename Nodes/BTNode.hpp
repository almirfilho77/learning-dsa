#pragma once 

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
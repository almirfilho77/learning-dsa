#pragma once
#include "BTNode.hpp"

namespace Trees
{

    template <class Ty>
    class BinarySearchTree
    {
    public:
        BinarySearchTree();
        BinarySearchTree(Ty value);
        ~BinarySearchTree() {}

        bool Insert(Ty value);
        bool Contains(Ty value);
    
    private:
        Trees::Node<Ty> *m_root;
    };

    template <class Ty>
    inline BinarySearchTree<Ty>::BinarySearchTree()
    {
        m_root = nullptr;
    }

    template <class Ty>
    inline BinarySearchTree<Ty>::BinarySearchTree(Ty value)
    {
        m_root = new Trees::Node<Ty>(value);
    }

    template <class Ty>
    bool BinarySearchTree<Ty>::Insert(Ty value)
    {
        throw std::runtime_error("Not yet implemented for this type");
    }

    template <>
    bool BinarySearchTree<int>::Insert(int value)
    {
        auto newNode = new Trees::Node<int>(value);
        if (m_root == nullptr)
        {
            m_root = newNode;
            return true;
        }

        auto temp = m_root;
        while(true)
        {
            if (temp->value == newNode->value)
            {
                delete newNode;
                return false;
            }

            if (newNode->value > temp->value)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }    
            else
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
        }
    }

    template <class Ty>
    bool BinarySearchTree<Ty>::Contains(Ty value)
    {
        auto temp = m_root;
        while(temp != nullptr)
        {
            if (value == temp->value) return true;

            if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        temp = nullptr;
        return false;
    }
}
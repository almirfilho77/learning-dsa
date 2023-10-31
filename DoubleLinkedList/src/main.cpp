#include <iostream>

#include "DoubleLinkedList.hpp"

int main(int argc, char **argv)
{
    std::cout << "Double Linked list!\n";
    std::cout << "Constructor!\n";
    DoubleLinkedList<int> dll(1);
    dll.PrintList();

    std::cout << "Append!\n";
    dll.Append(2);
    dll.PrintList();

    std::cout << "PopBack!\n";
    dll.PopBack();
    dll.PrintList();
    std::cout << "PopBack again!\n";
    dll.PopBack();
    dll.PrintList();
    std::cout << "PopBack again!\n";
    dll.PopBack();
    dll.PrintList();

    return 0;
}
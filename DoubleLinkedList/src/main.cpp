#include <iostream>

#include "DoubleLinkedList.hpp"

int main(int argc, char **argv)
{
    std::cout << "Double Linked list!\n";
    std::cout << "Constructor!\n";
    DoubleLinked::DoubleLinkedList<int> dll(1);
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

    std::cout << "Prepend!\n";
    dll.Prepend(2);
    dll.PrintList();
    std::cout << "Prepend again!\n";
    dll.Prepend(1);
    dll.PrintList();

    std::cout << "Pop Front!\n";
    dll.PopFront();
    dll.PrintList();
    std::cout << "Pop Front again!\n";
    dll.PopFront();
    dll.PrintList();
    std::cout << "Pop Front again!\n";
    dll.PopFront();
    dll.PrintList();

    std::cout << "New List:\n";
    dll.Append(1);
    dll.Append(2);
    dll.Append(3);
    dll.Append(4);
    dll.PrintList();
    std::cout << "Get at index 1: " << dll.GetNode(1)->value << '\n';
    std::cout << "Get at index 2: " << dll.GetNode(2)->value << '\n';

    std::cout << "Set value at index -1 to 97 (should give error) \n";
    dll.SetNode(-1, 97);
    std::cout << "Set value at index 0 to 98\n";
    dll.SetNode(0, 98);
    std::cout << "Set value at index 1 to 100\n";
    dll.SetNode(1, 100);
    std::cout << "Set value at index 2 to 101\n";
    dll.SetNode(2, 101);
    std::cout << "Set value at index 3 to 102\n";
    dll.SetNode(3, 103);
    std::cout << "Set value at index 4 to 104 (should give error) \n";
    dll.SetNode(4, 104);
    dll.PrintList();

    std::cout << "Insert 99 at index 1\n";
    dll.Insert(99, 1);
    std::cout << "Insert 102 at index 3\n";
    dll.Insert(102, 4);
    dll.PrintList();

    std::cout << "Delete at index 1\n";
    dll.Delete(1);
    std::cout << "Delete at index 3\n";
    dll.Delete(3);
    dll.PrintList();

    return 0;
}
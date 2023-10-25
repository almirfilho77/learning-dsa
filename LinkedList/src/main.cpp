#include <iostream>

#include "LinkedList.hpp"

int main(int argc, char **argv)
{
    std::cout << "Linked list!\n";

    LinkedList<int> ll(10);
    ll.Append(12);
    ll.Prepend(3);
    ll.Append(8);
    ll.Insert(6, 1);
    ll.Insert(100, 0);
    ll.Insert(101, ll.GetLength() - 1);
    ll.Insert(50, ll.GetLength() - 2);
    ll.PrintList();

    std::cout << "Popback 2x!\n";
    ll.PopBack();
    ll.PopBack();
    ll.PrintList();

    std::cout << "Popfront 2x!\n";
    ll.PopFront();
    ll.PopFront();
    ll.PrintList();

    return 0;
}
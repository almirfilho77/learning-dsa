#include <iostream>

#include "BinarySearchTree.hpp"

using namespace Trees;

int main(int argc, char **argv)
{
    Trees::BinarySearchTree<int> myTree;

    myTree.Insert(10);
    myTree.Insert(100);
    myTree.Insert(101);
    myTree.Insert(9);
    myTree.Insert(1);
    std::cout << (myTree.Contains(10) ? "Contains 10!" : "Sorry, no 10!") << '\n';
    std::cout << (myTree.Contains(11) ? "Contains 11!" : "Sorry, no 11!") << '\n';
    std::cout << (myTree.Contains(1) ? "Contains 1!" : "Sorry, no 1!") << '\n';
    return 0;
}
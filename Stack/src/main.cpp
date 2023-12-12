#include "Stack.hpp"

int main(int argc, char **argv)
{
    try{
        Stack stack(10);
        stack.Print();
        std::cout << "Stack height: " << stack.GetHeight() << '\n';
        stack.Push(20);
        stack.Print();
        std::cout << "Stack height: " << stack.GetHeight() << '\n';
        std::cout << "Pop stack: " << stack.Pop() << '\n';
        stack.Print();
        std::cout << "Pop stack: " << stack.Pop() << '\n';
        std::cout << "Pop stack: " << stack.Pop() << '\n';
    }
    catch(std::exception &ex)
    {
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }

    return 0;
}
#include "Queue.hpp"

#include <string>

int main(int argc, char **argv)
{
    try{
        Queue queue(std::string("Almir"));
        queue.Print();
        std::cout << "Queue length: " << queue.GetLength() << '\n';
        queue.Enqueue(std::string("Laynne"));
        queue.Print();
        std::cout << "Queue length: " << queue.GetLength() << '\n';
        std::cout << "Dequeue: " << queue.Dequeue() << '\n';
        queue.Print();
        std::cout << "Dequeue: " << queue.Dequeue() << '\n';
        std::cout << "Dequeue: " << queue.Dequeue() << '\n';
    }
    catch(std::exception &ex)
    {
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }

    return 0;
}
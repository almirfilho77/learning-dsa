#include "Queue.hpp"

#include <string>

int main(int argc, char **argv)
{
    try{
        std::cout << "String queue\n";
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

    std::cout << "\nInt queue\n";
    Queue int_queue(10);
    int_queue.Enqueue(11);
    int_queue.Print();
    std::cout << "Queue length: " << int_queue.GetLength() << '\n';

    std::cout << "Dequeue: " << int_queue.Dequeue() << '\n';
    std::cout << "Dequeue: " << int_queue.Dequeue() << '\n';
    std::cout << "Dequeue: " << int_queue.Dequeue() << '\n';
    return 0;
}
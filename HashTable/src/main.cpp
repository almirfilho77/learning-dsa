#include <iostream>

#include "HashTable.hpp"

int main(int argc, char **argv)
{
    HashTable myHashTable;
    myHashTable.Print();

    myHashTable.TestHash("Almir");
    myHashTable.TestHash("Laynne");
    myHashTable.TestHash("Ravi");
    myHashTable.TestHash("Gilmar");
    myHashTable.TestHash("Ilanna");
    myHashTable.TestHash("Sandra");
    myHashTable.TestHash("Inocência");
    myHashTable.TestHash("Daniel");
    myHashTable.TestHash("Naldo");

    myHashTable.Set("Marcos", 1);
    myHashTable.Set("Cafu", 2);
    myHashTable.Set("Lucio", 3);
    myHashTable.Set("Roque Jr", 4);
    myHashTable.Set("Gilberto Silva", 5);
    myHashTable.Set("Roberto Carlos", 6);
    myHashTable.Set("Ronaldo", 9);
    myHashTable.Set("Rivaldo", 10);
    myHashTable.Set("Ronaldinho", 11);
    myHashTable.Print();

    std::cout << "Get the number of Almir: " << myHashTable.Get("Almir") << '\n';
    std::cout << "Get the number of Ronaldo: " << myHashTable.Get("Ronaldo") << '\n';
    std::cout << "Get the number of Rivaldo: " << myHashTable.Get("Rivaldo") << '\n';

    std::vector<std::string> keys(myHashTable.Keys());
    for (auto &element : keys)
    {
        std::cout << "key: " << element << '\n';
    }

    return 0;
}
#pragma once

#include <iostream>
#include <vector>

#include "Node.hpp"

class HashTable
{
public:
    HashTable();
    ~HashTable() {}

    void Print();
    void Set(const std::string &key, int value);
    int Get(const std::string &key);
    std::vector<std::string> Keys();
    inline void TestHash(const std::string &key) { std::cout << "Hash of " << key << " = " << m_Hash(key) << '\n'; }

private:
    int m_Hash(const std::string &key);

private:
    static const int SIZE = 7;
    Hash::Node *m_dataMap[SIZE]; 
};

HashTable::HashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        m_dataMap[i] = nullptr;
    }
}

void HashTable::Set(const std::string &key, int value)
{
    Hash::Node *newNode = new Hash::Node(key, value);
    int address = m_Hash(key);
    // std::cout << "Address for " << key << " is: " << address << '\n';
    if (m_dataMap[address] == nullptr)
    {
        // std::cout << "Empty address! Creating a node with pair {" << key << ", " << value << "}\n";
        m_dataMap[address] = newNode;
    }
    else
    {
        // std::cout << "Non empty address! First node here is {" << key << ", " << value << "}\n";
        auto temp = m_dataMap[address];
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int HashTable::Get(const std::string &key)
{
    int address = m_Hash(key);
    auto temp = m_dataMap[address];
    while(temp != nullptr)
    {
        if (temp->key.compare(key) == 0)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    std::cerr << "The key is not in the hash table\n";
    return INT32_MIN;
}

std::vector<std::string> HashTable::Keys()
{
    std::vector<std::string> keys;
    for (int i = 0; i < SIZE; i++)
    {
        auto temp = m_dataMap[i];
        while (temp != nullptr)
        {
            keys.push_back(temp->key);
            temp = temp->next;
        }
    }
    return keys;
}

void HashTable::Print()
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << i << ":";
        if (m_dataMap[i])
        {
            auto temp = m_dataMap[i];
            while(temp != nullptr)
            {
                std::cout << " {" << temp->key << ", " << temp->value << "}";
                temp = temp->next;
            }
        }
        std::cout << '\n';
    }
}

int HashTable::m_Hash(const std::string &key)
{
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
    {
        int asciiValue = int(key[i]);
        hash = (hash + asciiValue * 23) % SIZE;
    }
    return hash;
}
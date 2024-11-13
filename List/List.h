#pragma once
#include <exception>
#include <stdexcept>

template <typename T>
class List
{
private:
    struct Node
    {
        Node(T value) noexcept
        {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
        T value;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;

public:
    List() noexcept
    {
        head = nullptr;
        tail = nullptr;
    }

    ~List()
    {
        while (head != nullptr)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    size_t size() const noexcept
    {
        size_t count = 0;
        Node* current = head;
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }
        return count;
    }

    void pushFront(T value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;
        head = newNode;
    }
};